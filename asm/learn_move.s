	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8160624
sub_8160624: @ 8160624
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8160624

	thumb_func_start sub_8160638
sub_8160638: @ 8160638
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_8160664
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
	thumb_func_end sub_8160638

	thumb_func_start sub_8160664
sub_8160664: @ 8160664
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08160688
	ldr r0, =sub_81606A0
	bl SetMainCallback2
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_08160688:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160664

	thumb_func_start sub_81606A0
sub_81606A0: @ 81606A0
	push {r4-r6,lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl clear_scheduled_bg_copies_to_vram
	ldr r6, =gUnknown_0203BC34
	movs r0, 0x8C
	lsls r0, 1
	bl AllocZeroed
	str r0, [r6]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	adds r0, 0x44
	movs r5, 0
	strb r1, [r0]
	ldr r0, =sub_8160624
	bl SetVBlankCallback
	bl sub_81607EC
	movs r0, 0
	bl sub_81D2824
	ldr r4, =gUnknown_0203BC38
	movs r0, 0
	strh r5, [r4]
	strh r5, [r4, 0x2]
	strb r0, [r4, 0x4]
	bl sub_8161280
	ldr r0, =gUnknown_085CEBB0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085CEBB8
	bl LoadSpritePalette
	bl sub_81610B8
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	ldr r1, [r6]
	movs r2, 0x89
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_816082C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81606A0

	thumb_func_start sub_8160740
sub_8160740: @ 8160740
	push {r4,r5,lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl clear_scheduled_bg_copies_to_vram
	ldr r5, =gUnknown_0203BC34
	movs r0, 0x8C
	lsls r0, 1
	bl AllocZeroed
	str r0, [r5]
	movs r1, 0x1C
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	adds r0, 0x44
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	adds r0, 0x45
	strb r1, [r0]
	ldr r0, =sub_8160624
	bl SetVBlankCallback
	bl sub_81607EC
	ldr r4, =gUnknown_0203BC38
	ldrb r0, [r4, 0x4]
	bl sub_81D2824
	bl sub_8161280
	ldr r0, =gUnknown_085CEBB0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085CEBB8
	bl LoadSpritePalette
	bl sub_81610B8
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	ldr r1, [r5]
	movs r2, 0x89
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_816082C
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160740

	thumb_func_start sub_81607EC
sub_81607EC: @ 81607EC
	push {lr}
	bl ResetVramOamAndBgCntRegs
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085CEC28
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	bl ResetAllBgsCoordinates
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81607EC

	thumb_func_start sub_816082C
sub_816082C: @ 816082C
	push {lr}
	bl sub_8160868
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_816082C

	thumb_func_start sub_816084C
sub_816084C: @ 816084C
	push {r4,lr}
	adds r1, r0, 0
	ldr r4, =gStringVar4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816084C

	thumb_func_start sub_8160868
sub_8160868: @ 8160868
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r1, =gUnknown_0203BC34
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0x21
	bls _0816087E
	b _08160E8A
_0816087E:
	lsls r0, 2
	ldr r1, =_08160890
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08160890:
	.4byte _08160918
	.4byte _08160932
	.4byte _0816094C
	.4byte _08160954
	.4byte _0816095C
	.4byte _08160964
	.4byte _08160980
	.4byte _08160E8A
	.4byte _08160988
	.4byte _081609A8
	.4byte _08160E8A
	.4byte _08160E8A
	.4byte _08160A44
	.4byte _08160A64
	.4byte _08160CB8
	.4byte _08160CD8
	.4byte _08160AB8
	.4byte _08160AD0
	.4byte _08160AEC
	.4byte _08160C1C
	.4byte _08160C48
	.4byte _08160C98
	.4byte _08160CA6
	.4byte _08160E8A
	.4byte _08160B2C
	.4byte _08160B60
	.4byte _08160B80
	.4byte _08160BDC
	.4byte _08160CFC
	.4byte _08160D48
	.4byte _08160E0C
	.4byte _08160E38
	.4byte _08160E58
	.4byte _08160E70
_08160918:
	ldr r1, [r7]
	ldrb r0, [r1]
	adds r0, 0x1
	movs r4, 0
	strb r0, [r1]
	movs r0, 0
	bl render_previous_quest_text
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	b _08160CAE
_08160932:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160940
	b _08160E8A
_08160940:
	ldr r1, [r7]
	movs r0, 0x4
	b _08160E88
	.pool
_0816094C:
	ldr r1, [r7]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
_08160954:
	movs r0, 0
	bl render_previous_quest_text
	b _0816096A
_0816095C:
	movs r0, 0
	bl sub_8160F50
	b _08160E8A
_08160964:
	movs r0, 0
	bl sub_8161074
_0816096A:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_81611AC
	b _08160E8A
	.pool
_08160980:
	movs r0, 0x1
	bl sub_8160F50
	b _08160E8A
_08160988:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160994
	b _08160E8A
_08160994:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_081609A8:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160A0A
	ldr r5, =gUnknown_0203BC34
	ldr r0, [r5]
	adds r0, 0x44
	ldrb r1, [r0]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	bl sub_8161054
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl GiveMoveToMon
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _08160A04
	ldr r0, =gText_PkmnLearnedMove4
	bl sub_816084C
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, [r5]
	movs r0, 0x1F
	b _08160E88
	.pool
_08160A04:
	ldr r1, [r5]
	movs r0, 0x10
	b _08160E88
_08160A0A:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160A18
	cmp r1, 0x1
	beq _08160A18
	b _08160E8A
_08160A18:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160A30
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160A30:
	cmp r0, 0x1
	beq _08160A36
	b _08160E8A
_08160A36:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160A44:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160A50
	b _08160E8A
_08160A50:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160A64:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160A7C
	ldr r0, =gSpecialVar_0x8004
	strh r1, [r0]
	b _08160E82
	.pool
_08160A7C:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160A8A
	cmp r1, 0x1
	beq _08160A8A
	b _08160E8A
_08160A8A:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160AA4
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160AA4:
	cmp r0, 0x1
	beq _08160AAA
	b _08160E8A
_08160AAA:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160AB8:
	ldr r0, =gText_PkmnTryingToLearnMove
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160AD0:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160ADC
	b _08160E8A
_08160ADC:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x12
	b _08160E88
	.pool
_08160AEC:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160B10
	ldr r0, =gText_WhichMoveToForget2
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x13
	b _08160E88
	.pool
_08160B10:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160B1E
	cmp r1, 0x1
	beq _08160B1E
	b _08160E8A
_08160B1E:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x18
	b _08160E88
	.pool
_08160B2C:
	ldr r4, =gStringVar2
	bl sub_8161054
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gText_StopTryingToTeachMove
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160B60:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160B6C
	b _08160E8A
_08160B6C:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160B80:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160B98
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x1B
	b _08160E88
	.pool
_08160B98:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160BA6
	cmp r1, 0x1
	beq _08160BA6
	b _08160E8A
_08160BA6:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160BC4
	ldr r2, =gUnknown_0203BC34
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1]
	adds r7, r2, 0
	b _08160BD0
	.pool
_08160BC4:
	ldr r7, =gUnknown_0203BC34
	cmp r0, 0x1
	bne _08160BD0
	ldr r1, [r7]
	movs r0, 0x5
	strb r0, [r1]
_08160BD0:
	ldr r1, [r7]
	movs r0, 0x10
	b _08160E88
	.pool
_08160BDC:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160BE8
	b _08160E8A
_08160BE8:
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160C08
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160C08:
	cmp r0, 0x1
	beq _08160C0E
	b _08160E8A
_08160C0E:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160C1C:
	bl sub_81D2C3C
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08160C2A
	b _08160E8A
_08160C2A:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x14
	strb r0, [r1]
	subs r0, 0x15
	str r2, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08160E8A
	.pool
_08160C48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160C56
	b _08160E8A
_08160C56:
	bl sub_8161054
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gPlayerParty
	ldr r1, =gUnknown_0203BC34
	ldr r1, [r1]
	adds r1, 0x44
	ldrb r1, [r1]
	ldr r2, =gPlayerPartyCount
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_8160740
	str r0, [sp]
	adds r0, r4, 0
	bl sub_81BFA38
	bl sub_8160EA0
	b _08160E8A
	.pool
_08160C98:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160CA4
	b _08160E8A
_08160CA4:
	b _08160E82
_08160CA6:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
_08160CAE:
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _08160E8A
_08160CB8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160CD8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160CE6
	b _08160E8A
_08160CE6:
	bl sub_8160EA0
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	b _08160E8A
	.pool
_08160CFC:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160D30
	movs r0, 0x1
	bl render_previous_quest_text
	b _08160D3A
	.pool
_08160D30:
	cmp r0, 0x1
	bne _08160D3A
	movs r0, 0x1
	bl sub_8161074
_08160D3A:
	bl sub_8161234
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	b _08160E8A
_08160D48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160D56
	b _08160E8A
_08160D56:
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0x45
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _08160D6C
	movs r0, 0x18
	b _08160E88
	.pool
_08160D6C:
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	movs r4, 0x64
	muls r0, r4
	ldr r5, =gPlayerParty
	adds r0, r5
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gStringVar3
	movs r1, 0xD
	mov r8, r1
	mov r1, r8
	muls r1, r0
	ldr r6, =gMoveNames
	adds r1, r6
	adds r0, r2, 0
	bl StringCopy
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	muls r0, r4
	adds r0, r5
	adds r1, 0x45
	ldrb r1, [r1]
	bl RemoveMonPPBonus
	ldr r0, [r7]
	adds r0, 0x44
	ldrb r0, [r0]
	muls r4, r0
	adds r4, r5
	bl sub_8161054
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [r7]
	adds r0, 0x45
	ldrb r2, [r0]
	adds r0, r4, 0
	bl SetMonMoveSlot
	ldr r4, =gStringVar2
	bl sub_8161054
	mov r1, r8
	muls r1, r0
	adds r1, r6
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gText_12AndPoof
	bl sub_816084C
	ldr r1, [r7]
	movs r0, 0x1E
	strb r0, [r1]
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x1
	strh r0, [r1]
	b _08160E8A
	.pool
_08160E0C:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	bne _08160E8A
	ldr r0, =gText_PkmnForgotMoveAndLearnedNew
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x1F
	strb r0, [r1]
	ldr r0, =0x0000016f
	bl PlayFanfare
	b _08160E8A
	.pool
_08160E38:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	bne _08160E8A
	ldr r0, =0x0000016f
	bl PlayFanfare
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x20
	b _08160E88
	.pool
_08160E58:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _08160E8A
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x21
	b _08160E88
	.pool
_08160E70:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08160E8A
	movs r0, 0x5
	bl PlaySE
_08160E82:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0xE
_08160E88:
	strb r0, [r1]
_08160E8A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160868

	thumb_func_start sub_8160EA0
sub_8160EA0: @ 8160EA0
	push {r4,lr}
	bl sub_8161234
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	movs r1, 0x89
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gUnknown_0203BC38
	adds r2, r1, 0x2
	bl sub_81AE6C8
	bl FreeAllWindowBuffers
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160EA0

	thumb_func_start render_previous_quest_text
render_previous_quest_text: @ 8160EE0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldr r6, =gSprites
	ldr r4, =gUnknown_0203BC34
	movs r3, 0x4
_08160EF0:
	ldr r0, [r4]
	adds r0, 0x1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xF
	ble _08160EF0
	cmp r5, 0
	bne _08160F38
	ldr r4, =gStringVar4
	ldr r1, =gText_TeachWhichMoveToPkmn
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
_08160F38:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end render_previous_quest_text

	thumb_func_start sub_8160F50
sub_8160F50: @ 8160F50
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r6, =gUnknown_0203BC34
	ldr r0, [r6]
	movs r4, 0x89
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	bl ListMenuHandleInputGetItemId
	adds r5, r0, 0
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ldr r4, =gUnknown_0203BC38
	adds r2, r4, 0x2
	adds r1, r4, 0
	bl sub_81AE860
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _08160FE4
	adds r0, 0x1
	cmp r5, r0
	bne _08161010
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _08160F9C
	bl GetLRKeysState
	lsls r0, 24
	cmp r0, 0
	beq _0816103E
_08160F9C:
	movs r0, 0x5
	bl PlaySE
	cmp r7, 0
	bne _08160FC4
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r1, 0x5
	strb r1, [r0]
	movs r0, 0x1
	strb r0, [r4, 0x4]
	b _08160FD4
	.pool
_08160FC4:
	movs r0, 0
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r2, 0
	movs r1, 0x3
	strb r1, [r0]
	strb r2, [r4, 0x4]
_08160FD4:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	bl sub_8161054
	bl sub_816137C
	b _0816103E
_08160FE4:
	movs r0, 0x5
	bl PlaySE
	bl sub_8161234
	ldr r1, [r6]
	movs r0, 0xC
	strb r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_GiveUpTeachingNewMove
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
	b _0816103E
	.pool
_08161010:
	movs r0, 0x5
	bl PlaySE
	bl sub_8161234
	ldr r1, [r6]
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r5
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_TeachX
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
_0816103E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160F50

	thumb_func_start sub_8161054
sub_8161054: @ 8161054
	ldr r0, =gUnknown_0203BC34
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BC38
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 3
	adds r2, 0x4C
	adds r2, r0
	ldr r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8161054

	thumb_func_start sub_8161074
sub_8161074: @ 8161074
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081610A6
	ldr r4, =gStringVar4
	ldr r1, =gText_TeachWhichMoveToPkmn
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
_081610A6:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161074

	thumb_func_start sub_81610B8
sub_81610B8: @ 81610B8
	push {r4-r7,lr}
	ldr r2, =gUnknown_0203BC34
	ldr r0, [r2]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x00000113
	adds r1, r0, r2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	bl sub_81611AC
	movs r4, 0
	ldr r5, =gUnknown_085CEC10
_081610DC:
	adds r2, r4, 0
	cmp r4, 0
	bge _081610E4
	adds r2, r4, 0x3
_081610E4:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r4, r1
	lsls r1, 19
	movs r0, 0xD0
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	lsls r2, 19
	movs r0, 0x90
	lsls r0, 14
	adds r2, r0
	asrs r2, 16
	adds r0, r5, 0
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_0203BC34
	ldr r1, [r2]
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x7
	ble _081610DC
	movs r4, 0
	ldr r7, =gUnknown_085CEC10
	adds r6, r2, 0
_0816111C:
	adds r2, r4, 0
	cmp r4, 0
	bge _08161124
	adds r2, r4, 0x3
_08161124:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r4, r1
	lsls r1, 19
	movs r0, 0xD0
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	lsls r2, 19
	movs r0, 0xD0
	lsls r0, 14
	adds r2, r0
	asrs r2, 16
	adds r0, r7, 0
	movs r3, 0
	bl CreateSprite
	ldr r1, [r6]
	adds r2, r4, 0
	adds r2, 0x8
	adds r1, 0x1
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x2
	bl StartSpriteAnim
	adds r4, 0x1
	cmp r4, 0x7
	ble _0816111C
	movs r4, 0
	ldr r3, =gUnknown_0203BC34
	movs r2, 0x4
_08161176:
	ldr r0, [r3]
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0xF
	ble _08161176
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81610B8

	thumb_func_start sub_81611AC
sub_81611AC: @ 81611AC
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BC34
	ldr r1, [r4]
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081611D4
	ldr r0, =gUnknown_085CEBC0
	movs r3, 0x8B
	lsls r3, 1
	adds r1, r3
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	movs r5, 0x8A
	lsls r5, 1
	adds r1, r5
	strb r0, [r1]
_081611D4:
	ldr r0, [r4]
	ldr r6, =0x00000113
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08161210
	ldr r0, =gUnknown_0203CE8C
	adds r2, r0, 0
	ldr r1, =gUnknown_085CEBD0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r1, [r1]
	str r1, [r2]
	ldr r2, [r4]
	movs r3, 0x88
	lsls r3, 1
	adds r1, r2, r3
	ldrb r1, [r1]
	ldr r5, =0x00000111
	adds r2, r5
	ldrb r2, [r2]
	subs r1, r2
	strh r1, [r0, 0x8]
	ldr r1, =gUnknown_0203BC38
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r6, =0x00000113
	adds r1, r6
	strb r0, [r1]
_08161210:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81611AC

	thumb_func_start sub_8161234
sub_8161234: @ 8161234
	push {r4,lr}
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	movs r2, 0x8A
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08161256
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_08161256:
	ldr r0, [r4]
	ldr r2, =0x00000113
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08161270
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x00000113
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
_08161270:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161234

	thumb_func_start sub_8161280
sub_8161280: @ 8161280
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r4, =gUnknown_0203BC34
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	adds r1, 0x12
	bl GetMoveRelearnerMoves
	ldr r1, [r4]
	movs r6, 0x88
	lsls r6, 1
	adds r1, r6
	strb r0, [r1]
	movs r5, 0
	ldr r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	bge _081612F6
	mov r8, r4
	movs r0, 0xD
	mov r12, r0
	ldr r2, =gMoveNames
	mov r9, r2
_081612C2:
	mov r7, r8
	ldr r4, [r7]
	lsls r3, r5, 3
	adds r2, r4, 0
	adds r2, 0x48
	adds r2, r3
	lsls r0, r5, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r1, r0
	ldrh r0, [r1]
	mov r7, r12
	muls r7, r0
	adds r0, r7, 0
	add r0, r9
	str r0, [r2]
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r3
	ldrh r1, [r1]
	str r1, [r0]
	adds r5, 0x1
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r5, r0
	blt _081612C2
_081612F6:
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	adds r0, 0x44
	ldrb r1, [r0]
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
	ldr r2, [r4]
	movs r5, 0x88
	lsls r5, 1
	adds r3, r2, r5
	ldrb r0, [r3]
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x48
	adds r1, r0
	ldr r0, =gText_Cancel
	str r0, [r1]
	ldrb r0, [r3]
	lsls r0, 3
	adds r2, 0x4C
	adds r2, r0
	movs r0, 0x2
	negs r0, r0
	str r0, [r2]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x48
	adds r1, r5
	ldrb r1, [r1]
	bl sub_81D28C8
	ldr r1, [r4]
	ldr r2, =0x00000111
	adds r1, r2
	strb r0, [r1]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161280

	thumb_func_start sub_816137C
sub_816137C: @ 816137C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08161394
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081613CC
_08161394:
	movs r5, 0
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203BC34
	movs r2, 0x4
_0816139C:
	ldr r0, [r3]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _0816139C
	b _081614FE
	.pool
_081613CC:
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	lsls r4, 3
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x1]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
	mov r8, r4
	cmp r6, 0xFF
	bne _081613EE
	movs r6, 0
_081613EE:
	movs r5, 0
	ldr r7, =gUnknown_0203BC34
	ldr r4, =gSprites
_081613F4:
	cmp r5, r6
	bcs _08161420
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	b _08161436
	.pool
_08161420:
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartSpriteAnim
_08161436:
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _081613F4
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	add r0, r8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xFF
	bne _0816147C
	movs r6, 0
_0816147C:
	movs r5, 0
	ldr r0, =gUnknown_0203BC34
	mov r8, r0
	ldr r7, =gSprites
_08161484:
	cmp r5, r6
	bcs _081614B8
	mov r1, r8
	ldr r0, [r1]
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x3
	bl StartSpriteAnim
	b _081614D4
	.pool
_081614B8:
	mov r3, r8
	ldr r0, [r3]
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x2
	bl StartSpriteAnim
_081614D4:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _08161484
_081614FE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816137C

	.align 2, 0 @ Don't pad with nop.
