	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81297AC
sub_81297AC: @ 81297AC
	push {r4-r6,lr}
	movs r2, 0
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	ldrb r1, [r0]
	cmp r2, r1
	bcs _081297F0
	adds r3, r0, 0
	ldr r5, [r3, 0x4]
	ldr r0, =gSpecialVar_0x8004
	ldrh r4, [r0]
	ldr r6, =gSpecialVar_0x8005
_081297C4:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r5
	ldrh r0, [r1, 0x14]
	cmp r0, r4
	bne _081297E4
	ldrb r0, [r1]
	strh r0, [r6]
	b _081297F0
	.pool
_081297E4:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r3]
	cmp r2, r0
	bcc _081297C4
_081297F0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81297AC

	thumb_func_start sub_81297F8
sub_81297F8: @ 81297F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r6, 0
	b _081298BE
_08129808:
	ldr r3, =gUnknown_0203AA44
	lsls r5, r6, 3
	adds r4, r5, r3
	ldrb r1, [r4]
	ldr r2, =gUnknown_0203A17C
	ldr r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 5
	ldr r7, =gDecorations
	adds r0, r7
	ldrb r2, [r0, 0x11]
	ldr r7, =gUnknown_0203A17C
	ldr r0, [r7, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	lsrs r1, r0, 4
	mov r8, r1
	movs r7, 0xF
	adds r1, r7, 0
	ands r1, r0
	str r1, [sp]
	adds r7, r5, 0
	adds r6, 0x1
	str r6, [sp, 0x4]
	cmp r2, 0x4
	beq _081298B8
	movs r6, 0
	ldrb r4, [r4, 0x2]
	cmp r6, r4
	bcs _081298AE
_08129846:
	movs r4, 0
	adds r0, r5, r3
	adds r2, r6, 0x1
	mov r10, r2
	ldrb r0, [r0, 0x1]
	cmp r4, r0
	bcs _0812989C
	ldr r3, =gUnknown_0203AA44
	adds r3, r7
	mov r9, r3
	subs r5, r6, 0x7
	str r5, [sp, 0x8]
_0812985E:
	adds r0, r4, 0x7
	add r0, r8
	ldr r1, =gMapHeader
	ldr r3, [r1]
	ldr r1, [sp]
	subs r2, r1, r6
	ldr r1, [r3]
	muls r2, r1
	mov r5, r8
	adds r1, r5, r4
	adds r1, r2
	ldr r2, [r3, 0xC]
	lsls r1, 1
	adds r1, r2
	ldrh r1, [r1]
	movs r3, 0xC0
	lsls r3, 6
	adds r2, r3, 0
	orrs r2, r1
	ldr r5, [sp]
	ldr r3, [sp, 0x8]
	subs r1, r5, r3
	bl MapGridSetMetatileEntryAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r5, r9
	ldrb r5, [r5, 0x1]
	cmp r4, r5
	bcc _0812985E
_0812989C:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r6, r0, 24
	ldr r3, =gUnknown_0203AA44
	adds r5, r7, 0
	adds r0, r7, r3
	ldrb r0, [r0, 0x2]
	cmp r6, r0
	bcc _08129846
_081298AE:
	ldr r2, =gUnknown_0203AA44
	adds r0, r7, r2
	ldrb r0, [r0]
	bl sub_81296EC
_081298B8:
	ldr r3, [sp, 0x4]
	lsls r0, r3, 24
	lsrs r6, r0, 24
_081298BE:
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08129808
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81297F8

	thumb_func_start sub_81298EC
sub_81298EC: @ 81298EC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08129928
	cmp r0, 0x1
	bgt _08129914
	cmp r0, 0
	beq _0812991E
	b _08129994
	.pool
_08129914:
	cmp r0, 0x2
	beq _08129954
	cmp r0, 0x3
	beq _08129968
	b _08129994
_0812991E:
	bl sub_81297F8
	movs r0, 0x1
	strh r0, [r4, 0xC]
	b _08129994
_08129928:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08129994
	bl DrawWholeMapView
	ldr r0, =gUnknown_08275D2E
	bl ScriptContext1_SetupScript
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	movs r0, 0x2
	strh r0, [r4, 0xC]
	b _08129994
	.pool
_08129954:
	bl ScriptContext2_Enable
	adds r0, r5, 0
	bl sub_8127814
	bl pal_fill_black
	movs r0, 0x3
	strh r0, [r4, 0xC]
	b _08129994
_08129968:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08129994
	ldr r4, =gStringVar4
	ldr r1, =gText_DecorationReturnedToPC
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8129D64
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	cmp r0, 0x56
	bne _08129994
	bl TV_PutSecretBaseVisitOnTheAir
_08129994:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81298EC

	thumb_func_start sub_81299AC
sub_81299AC: @ 81299AC
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r2, [r0, 0x8]
	cmp r1, r2
	bcs _081299D6
	ldr r3, [r0]
_081299BA:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081299CC
	movs r0, 0x1
	b _081299D8
	.pool
_081299CC:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bcc _081299BA
_081299D6:
	movs r0, 0
_081299D8:
	pop {r1}
	bx r1
	thumb_func_end sub_81299AC

	thumb_func_start SetUpPuttingAwayDecorationPlayerAvatar
SetUpPuttingAwayDecorationPlayerAvatar: @ 81299DC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	bl player_get_direction_lower_nybble
	ldr r3, =gUnknown_0203AA38
	ldr r2, =gSprites
	ldr r4, =gUnknown_03005DD0
	ldr r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x2E]
	strb r0, [r3]
	bl sub_812A39C
	ldr r0, =gUnknown_085A7404
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	str r0, [r4, 0x4]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08129A3C
	ldr r1, =SpriteCallbackDummy
	str r0, [sp]
	movs r0, 0xC1
	b _08129A44
	.pool
_08129A3C:
	ldr r1, =SpriteCallbackDummy
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC2
_08129A44:
	movs r2, 0x88
	movs r3, 0x48
	bl AddPseudoFieldObject
	ldr r1, =gUnknown_0203AA39
	strb r0, [r1]
	ldr r6, =gSprites
	ldr r0, =gUnknown_0203AA39
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	movs r2, 0x4
	mov r8, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r5, =gUnknown_0203AA38
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	ldr r0, =gUnknown_03005DD0
	ldr r0, [r0, 0x4]
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x5]
	ands r4, r1
	mov r1, r8
	orrs r4, r1
	strb r4, [r0, 0x5]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpPuttingAwayDecorationPlayerAvatar

	thumb_func_start sub_8129ABC
sub_8129ABC: @ 8129ABC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08129B0C
	cmp r0, 0x1
	bgt _08129AE4
	cmp r0, 0
	beq _08129AEA
	b _08129B2E
	.pool
_08129AE4:
	cmp r0, 0x2
	beq _08129B1A
	b _08129B2E
_08129AEA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08129B2E
	adds r0, r5, 0
	bl sub_8127ACC
	movs r0, 0x1
	strh r0, [r4, 0x4]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xA]
	b _08129B2E
	.pool
_08129B0C:
	bl SetUpPuttingAwayDecorationPlayerAvatar
	bl pal_fill_black
	movs r0, 0x2
	strh r0, [r4, 0x4]
	b _08129B2E
_08129B1A:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08129B2E
	strh r0, [r4, 0x18]
	adds r0, r5, 0
	bl sub_8129B34
_08129B2E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8129ABC

	thumb_func_start sub_8129B34
sub_8129B34: @ 8129B34
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203AA38
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r6, 0
	strh r6, [r0, 0x3C]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_812A36C
	str r1, [r0]
	ldr r2, =gUnknown_0203AA39
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x88
	strh r1, [r0, 0x20]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x48
	strh r1, [r0, 0x22]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0x1C]
	ldr r1, =sub_8128E18
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129B34

	thumb_func_start sub_8129BCC
sub_8129BCC: @ 8129BCC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	bl sub_8128DE0
	adds r0, r4, 0
	bl sub_8129C74
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129BCC

	thumb_func_start sub_8129BF8
sub_8129BF8: @ 8129BF8
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	bl sub_8128DE0
	ldr r3, =gSprites
	ldr r5, =gUnknown_0203AA38
	ldrb r1, [r5]
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
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldr r5, =gStringVar4
	ldr r1, =gText_StopPuttingAwayDecorations
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A1F0
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129BF8

	thumb_func_start sub_8129C74
sub_8129C74: @ 8129C74
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_812A0E8
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08129CA8
	ldr r4, =gStringVar4
	ldr r1, =gText_ReturnDecorationToPC
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A1A0
	b _08129D14
	.pool
_08129CA8:
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBasePC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08129CDE
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_C5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08129D3C
_08129CDE:
	ldr r3, =gSprites
	ldr r4, =gUnknown_0203AA38
	ldrb r1, [r4]
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
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldr r4, =gStringVar4
	ldr r1, =gText_StopPuttingAwayDecorations
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A1F0
_08129D14:
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _08129D50
	.pool
_08129D3C:
	ldr r4, =gStringVar4
	ldr r1, =gText_NoDecorationHere
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8129D64
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_08129D50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129C74

	thumb_func_start sub_8129D64
sub_8129D64: @ 8129D64
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08129D7E
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08129D84
_08129D7E:
	adds r0, r2, 0
	bl sub_8129B34
_08129D84:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129D64

	thumb_func_start sub_8129D8C
sub_8129D8C: @ 8129D8C
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	ldr r1, =gDecorations
	lsrs r0, 19
	adds r0, r1
	ldrb r1, [r0, 0x12]
	cmp r1, 0
	bne _08129DA8
	movs r0, 0x1
	strb r0, [r2, 0x1]
	b _08129E06
	.pool
_08129DA8:
	cmp r1, 0x1
	bne _08129DB4
	movs r0, 0x2
	strb r0, [r2, 0x1]
	strb r1, [r2, 0x2]
	b _08129E08
_08129DB4:
	cmp r1, 0x2
	bne _08129DC0
	movs r0, 0x3
	strb r0, [r2, 0x1]
	movs r0, 0x1
	b _08129E06
_08129DC0:
	cmp r1, 0x3
	bne _08129DC8
	movs r0, 0x4
	b _08129E02
_08129DC8:
	cmp r1, 0x4
	bne _08129DD2
	movs r0, 0x2
	strb r0, [r2, 0x1]
	b _08129E06
_08129DD2:
	cmp r1, 0x5
	bne _08129DDA
	movs r0, 0x1
	b _08129E02
_08129DDA:
	cmp r1, 0x6
	bne _08129DE6
	movs r0, 0x1
	strb r0, [r2, 0x1]
	movs r0, 0x3
	b _08129E06
_08129DE6:
	cmp r1, 0x7
	bne _08129DF2
	movs r0, 0x2
	strb r0, [r2, 0x1]
	movs r0, 0x4
	b _08129E06
_08129DF2:
	cmp r1, 0x8
	bne _08129DFC
	movs r0, 0x3
	strb r0, [r2, 0x1]
	b _08129E06
_08129DFC:
	cmp r1, 0x9
	bne _08129E08
	movs r0, 0x3
_08129E02:
	strb r0, [r2, 0x1]
	movs r0, 0x2
_08129E06:
	strb r0, [r2, 0x2]
_08129E08:
	pop {r0}
	bx r0
	thumb_func_end sub_8129D8C

	thumb_func_start sub_8129E0C
sub_8129E0C: @ 8129E0C
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	ldr r5, =gSprites
	ldr r6, =gUnknown_0203AA38
	ldrb r3, [r6]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r5
	adds r2, 0x3E
	ldrb r3, [r2]
	movs r4, 0x4
	orrs r3, r4
	strb r3, [r2]
	ldrb r3, [r6]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r3, r5, 0
	adds r3, 0x1C
	adds r2, r3
	ldr r3, =SpriteCallbackDummy
	str r3, [r2]
	ldr r4, =gUnknown_0203AA39
	ldrb r3, [r4]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r5
	lsrs r0, 20
	adds r0, 0x88
	strh r0, [r2, 0x20]
	ldrb r2, [r4]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	lsrs r1, 20
	adds r1, 0x48
	strh r1, [r0, 0x22]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129E0C

	thumb_func_start sub_8129E74
sub_8129E74: @ 8129E74
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r2
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	ldrb r0, [r2, 0x8]
	subs r0, 0x7
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r2, 0xA]
	subs r0, 0x7
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gUnknown_0203A17C
	ldr r0, [r2, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	lsrs r5, r0, 4
	movs r6, 0xF
	ands r6, r0
	mov r0, r9
	ldrb r4, [r0, 0x2]
	ldr r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x29
	bne _08129ED4
	adds r0, r5, 0x7
	adds r1, r6, 0x7
	bl MapGridGetMetatileIdAt
	movs r1, 0xA3
	lsls r1, 2
	cmp r0, r1
	bne _08129ED4
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_08129ED4:
	cmp r7, r5
	bcc _08129F10
	mov r0, r9
	ldrb r2, [r0, 0x1]
	adds r0, r5, r2
	cmp r7, r0
	bge _08129F10
	subs r0, r6, r4
	cmp r8, r0
	ble _08129F10
	cmp r8, r6
	bhi _08129F10
	subs r0, r7, r5
	adds r0, 0x1
	subs r0, r2, r0
	lsls r0, 24
	lsrs r0, 24
	mov r2, r8
	subs r1, r6, r2
	lsls r1, 24
	lsrs r1, 24
	bl sub_8129E0C
	movs r0, 0x1
	b _08129F12
	.pool
_08129F10:
	movs r0, 0
_08129F12:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8129E74

	thumb_func_start sub_8129F20
sub_8129F20: @ 8129F20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, =gUnknown_0203A17C
	ldr r3, =gUnknown_0203AA44
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r3
	ldrb r1, [r0]
	ldr r0, [r2, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	lsrs r1, r0, 4
	mov r8, r1
	movs r6, 0xF
	ands r6, r0
	movs r4, 0
	ldr r7, =gSaveBlock1Ptr
	mov r9, r3
_08129F4A:
	ldr r1, [r7]
	lsls r0, r4, 1
	adds r0, r4
	lsls r5, r0, 3
	adds r1, r5
	ldr r2, =0x00000c74
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r8
	bne _08129FB0
	ldr r2, =0x00000c76
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r6
	bne _08129FB0
	ldr r2, =0x00000c84
	adds r0, r1, r2
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08129FB0
	ldr r0, =gUnknown_0203AAC4
	ldrb r1, [r0]
	lsls r1, 3
	add r1, r9
	ldr r0, [r7]
	adds r0, r5
	ldr r2, =0x00000c84
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	b _08129FBA
	.pool
_08129FB0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3F
	bls _08129F4A
_08129FBA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8129F20

	thumb_func_start sub_8129FC8
sub_8129FC8: @ 8129FC8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	b _0812A02A
_08129FD2:
	ldr r0, [r0]
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0
	beq _0812A024
	ldr r0, =gDecorations
	ldrb r2, [r1]
	lsls r1, r2, 5
	adds r1, r0
	ldrb r0, [r1, 0x11]
	cmp r0, 0x4
	bne _0812A024
	ldr r5, =gUnknown_0203AA44
	adds r0, r2, 0
	adds r1, r5, 0
	bl sub_8129D8C
	lsls r1, r6, 24
	lsrs r1, 24
	adds r0, r7, 0
	adds r2, r5, 0
	bl sub_8129E74
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0812A024
	strb r6, [r5]
	bl sub_8129F20
	ldr r0, =gUnknown_0203AAC4
	strb r4, [r0]
	movs r0, 0x1
	b _0812A034
	.pool
_0812A024:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_0812A02A:
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r6, r1
	bcc _08129FD2
	movs r0, 0
_0812A034:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8129FC8

	thumb_func_start sub_812A040
sub_812A040: @ 812A040
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	movs r4, 0
	ldr r7, =gUnknown_0203A17C
	ldrb r0, [r7, 0x8]
	cmp r4, r0
	bcs _0812A0C6
	adds r6, r7, 0
	ldr r5, =gUnknown_0203AAC4
_0812A072:
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	ldr r0, [r6, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	lsrs r3, r0, 4
	movs r2, 0xF
	ands r2, r0
	cmp r1, 0
	beq _0812A0BA
	ldr r0, =gDecorations
	lsls r1, 5
	adds r1, r0
	ldrb r0, [r1, 0x11]
	cmp r0, 0x4
	bne _0812A0BA
	ldr r0, [sp]
	cmp r0, r3
	bhi _0812A0BA
	cmp r10, r2
	bhi _0812A0BA
	cmp r9, r3
	bcc _0812A0BA
	cmp r8, r2
	bcc _0812A0BA
	ldr r0, =gUnknown_0203AA44
	ldrb r1, [r5]
	lsls r1, 3
	adds r1, r0
	strb r4, [r1]
	bl sub_8129F20
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
_0812A0BA:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r7, 0x8]
	cmp r4, r0
	bcc _0812A072
_0812A0C6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A040

	thumb_func_start sub_812A0E8
sub_812A0E8: @ 812A0E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_0203AAC4
	movs r0, 0
	strb r0, [r4]
	adds r0, r6, 0
	bl sub_8129FC8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0812A18C
	movs r5, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r5, r1
	bcs _0812A15A
	adds r7, r4, 0
_0812A10E:
	ldr r0, [r0]
	adds r0, r5
	ldrb r1, [r0]
	cmp r1, 0
	beq _0812A14C
	ldr r4, =gUnknown_0203AA44
	adds r0, r1, 0
	adds r1, r4, 0
	bl sub_8129D8C
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8129E74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A14C
	strb r5, [r4]
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	b _0812A15A
	.pool
_0812A14C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r5, r1
	bcc _0812A10E
_0812A15A:
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812A18C
	ldr r0, =gUnknown_0203A17C
	ldr r2, =gUnknown_0203AA44
	ldrb r1, [r2]
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldrb r1, [r0]
	lsrs r0, r1, 4
	movs r3, 0xF
	ands r3, r1
	ldrb r1, [r2, 0x2]
	subs r1, r3, r1
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r2, 0x1]
	adds r2, r0
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	bl sub_812A040
_0812A18C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A0E8

	thumb_func_start sub_812A1A0
sub_812A1A0: @ 812A1A0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A7348
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1A0

	thumb_func_start sub_812A1C0
sub_812A1C0: @ 812A1C0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_81298EC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1C0

	thumb_func_start sub_812A1F0
sub_812A1F0: @ 812A1F0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A7350
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1F0

	thumb_func_start sub_812A210
sub_812A210: @ 812A210
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_812A22C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812A210

	thumb_func_start sub_812A22C
sub_812A22C: @ 812A22C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_812A25C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A22C

	thumb_func_start sub_812A25C
sub_812A25C: @ 812A25C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0812A280
	cmp r0, 0x1
	beq _0812A29C
	b _0812A2B2
	.pool
_0812A280:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812A2B2
	adds r0, r4, 0
	bl sub_8127B04
	movs r0, 0x1
	strh r0, [r5, 0xC]
	b _0812A2B2
	.pool
_0812A29C:
	bl sub_812A3C8
	ldr r0, =gFieldCallback
	ldr r1, =sub_812A334
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_0812A2B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A25C

	thumb_func_start sub_812A2C4
sub_812A2C4: @ 812A2C4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0812A2FC
	cmp r0, 0x1
	bgt _0812A2EC
	cmp r0, 0
	beq _0812A2F6
	b _0812A32A
	.pool
_0812A2EC:
	cmp r0, 0x2
	beq _0812A308
	cmp r0, 0x3
	beq _0812A314
	b _0812A32A
_0812A2F6:
	bl sub_80E9578
	b _0812A30C
_0812A2FC:
	ldr r0, =gUnknown_08275D0C
	bl ScriptContext1_SetupScript
	b _0812A30C
	.pool
_0812A308:
	bl ScriptContext2_Enable
_0812A30C:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	b _0812A32A
_0812A314:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A32A
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_8126B80
	str r1, [r0]
_0812A32A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A2C4

	thumb_func_start sub_812A334
sub_812A334: @ 812A334
	push {lr}
	bl pal_fill_black
	movs r0, 0
	movs r1, 0x1
	bl sub_81973C4
	bl sub_8126ABC
	ldr r0, =sub_812A2C4
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0xC]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A334

	thumb_func_start sub_812A36C
sub_812A36C: @ 812A36C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r2, 0x2E]
	cmp r0, 0xF
	ble _0812A38C
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _0812A398
_0812A38C:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0812A398:
	pop {r0}
	bx r0
	thumb_func_end sub_812A36C

	thumb_func_start sub_812A39C
sub_812A39C: @ 812A39C
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0812A3B8
	ldr r0, =gUnknown_085A73D8
	bl LoadSpritePalette
	b _0812A3BE
	.pool
_0812A3B8:
	ldr r0, =gUnknown_085A73E0
	bl LoadSpritePalette
_0812A3BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A39C

	thumb_func_start sub_812A3C8
sub_812A3C8: @ 812A3C8
	push {lr}
	movs r0, 0x8
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_812A3C8

	thumb_func_start sub_812A3D4
sub_812A3D4: @ 812A3D4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81279C4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A430
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_0203A172
	ldrb r2, [r1]
	ldr r1, =gUnknown_0203A14C
	ldr r1, [r1]
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_DecorationWillBeDiscarded
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A458
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _0812A444
	.pool
_0812A430:
	ldr r4, =gStringVar4
	ldr r1, =gText_CantThrowAwayInUse
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_0812A444:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A3D4

	thumb_func_start sub_812A458
sub_812A458: @ 812A458
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A741C
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A458

	thumb_func_start sub_812A478
sub_812A478: @ 812A478
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r5, =gUnknown_0203A173
	ldrb r0, [r5]
	bl CountDecorationCategoryN
	ldr r1, =gUnknown_0203A151
	strb r0, [r1]
	ldrb r0, [r5]
	bl CondenseDecorationCategoryN
	adds r0, r4, 0
	bl sub_8127814
	ldr r5, =gStringVar4
	ldr r1, =gText_DecorationThrownAway
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A478

	.align 2, 0 @ Don't pad with nop.
