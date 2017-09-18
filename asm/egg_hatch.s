	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start EggHatchSetMonNickname
EggHatchSetMonNickname: @ 80719FC
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r2, =gStringVar3
	movs r1, 0x2
	bl SetMonData
	bl sub_805F094
	ldr r0, =gEggHatchData
	ldr r0, [r0]
	bl Free
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end EggHatchSetMonNickname

	thumb_func_start Task_EggHatchPlayBGM
Task_EggHatchPlayBGM: @ 8071A3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08071A5C
	bl StopMapMusic
	bl play_some_sound
_08071A5C:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08071A6C
	movs r0, 0xBC
	lsls r0, 1
	bl PlayBGM
_08071A6C:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x3C
	ble _08071A80
	ldr r0, =0x00000179
	bl PlayBGM
	adds r0, r5, 0
	bl DestroyTask
_08071A80:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_EggHatchPlayBGM

	thumb_func_start CB2_EggHatch_1
CB2_EggHatch_1: @ 8071A94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r1, =gEggHatchData
	ldr r0, [r1]
	ldrb r0, [r0, 0x2]
	adds r5, r1, 0
	cmp r0, 0xC
	bls _08071AAC
	b _08071E06
_08071AAC:
	lsls r0, 2
	ldr r1, =_08071AC0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08071AC0:
	.4byte _08071AF4
	.4byte _08071B40
	.4byte _08071B68
	.4byte _08071BA0
	.4byte _08071BF8
	.4byte _08071C24
	.4byte _08071C88
	.4byte _08071C96
	.4byte _08071CA4
	.4byte _08071CE8
	.4byte _08071D1C
	.4byte _08071DB4
	.4byte _08071DD4
_08071AF4:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0832BFFC
	movs r1, 0x78
	movs r2, 0x4B
	movs r3, 0x5
	bl CreateSprite
	ldr r4, =gEggHatchData
	ldr r1, [r4]
	strb r0, [r1]
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	ldr r1, [r4]
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	ldr r0, =Task_EggHatchPlayBGM
	movs r1, 0x5
	bl CreateTask
	b _08071E06
	.pool
_08071B40:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08071B52
	b _08071E06
_08071B52:
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	strb r4, [r0, 0x3]
	ldr r1, [r5]
	b _08071DC8
	.pool
_08071B68:
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1E
	bhi _08071B7A
	b _08071E06
_08071B7A:
	ldr r1, [r5]
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	ldr r2, =gSprites
	ldr r0, [r5]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =SpriteCB_Egg_0
	str r1, [r0]
	b _08071E06
	.pool
_08071BA0:
	ldr r4, =gSprites
	ldr r2, [r5]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _08071BBC
	b _08071E06
_08071BBC:
	ldrb r1, [r2, 0x4]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, [r5]
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x1
	bl DoMonFrontSpriteAnimation
	ldr r1, [r5]
	b _08071DC8
	.pool
_08071BF8:
	ldr r2, =gSprites
	ldr r3, [r5]
	ldrb r1, [r3, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _08071C12
	b _08071E06
_08071C12:
	ldrb r0, [r3, 0x2]
	adds r0, 0x1
	strb r0, [r3, 0x2]
	b _08071E06
	.pool
_08071C24:
	ldr r0, [r5]
	ldrb r1, [r0, 0x4]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNick
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085ED5A5
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	movs r1, 0xFF
	str r1, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl sub_8072214
	ldr r0, =0x00000173
	bl PlayFanfare
	ldr r1, [r5]
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	b _08071E06
	.pool
_08071C88:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	bne _08071C94
	b _08071E06
_08071C94:
	b _08071DC4
_08071C96:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	bne _08071CA2
	b _08071E06
_08071CA2:
	b _08071DC4
_08071CA4:
	ldr r0, [r5]
	ldrb r1, [r0, 0x4]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNick
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085ED5BE
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	movs r1, 0x1
	str r1, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x2
	bl sub_8072214
	ldr r1, [r5]
	b _08071DC8
	.pool
_08071CE8:
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _08071CF8
	b _08071E06
_08071CF8:
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	movs r4, 0xA0
	lsls r4, 1
	adds r1, r4, 0
	movs r2, 0xE0
	bl sub_809882C
	ldr r0, =gUnknown_0832C07C
	adds r1, r4, 0
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	ldr r1, [r5]
	b _08071DC8
	.pool
_08071D1C:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _08071D3C
	cmp r1, 0
	bgt _08071D36
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08071DC4
	b _08071E06
_08071D36:
	cmp r1, 0x1
	beq _08071DC4
	b _08071E06
_08071D3C:
	ldr r0, =gEggHatchData
	mov r8, r0
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	ldr r1, =gStringVar3
	mov r9, r1
	bl GetMonNick
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x4]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x4]
	muls r0, r6
	adds r0, r5
	bl GetMonGender
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x4]
	muls r0, r6
	adds r0, r5
	movs r1, 0
	movs r2, 0
	bl GetMonData
	str r0, [sp]
	ldr r0, =EggHatchSetMonNickname
	str r0, [sp, 0x4]
	movs r0, 0x3
	mov r1, r9
	adds r2, r7, 0
	adds r3, r4, 0
	bl do_choose_name_or_words_screen
	b _08071E06
	.pool
_08071DB4:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_08071DC4:
	ldr r0, =gEggHatchData
	ldr r1, [r0]
_08071DC8:
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	b _08071E06
	.pool
_08071DD4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08071E06
	bl sub_805F094
	ldr r4, =gEggHatchData
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl RemoveWindow
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	ldr r0, [r4]
	bl Free
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
_08071E06:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_EggHatch_1

	thumb_func_start SpriteCB_Egg_0
SpriteCB_Egg_0: @ 8071E34
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08071E54
	ldr r0, =SpriteCB_Egg_1
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x2E]
	b _08071E84
	.pool
_08071E54:
	ldrh r0, [r4, 0x30]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	bne _08071E84
	movs r0, 0x17
	bl PlaySE
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	bl CreateRandomEggShardSprite
_08071E84:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SpriteCB_Egg_0

	thumb_func_start SpriteCB_Egg_1
SpriteCB_Egg_1: @ 8071E8C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _08071EE8
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08071EBC
	ldr r0, =SpriteCB_Egg_2
	str r0, [r4, 0x1C]
	strh r1, [r4, 0x2E]
	strh r1, [r4, 0x32]
	b _08071EE8
	.pool
_08071EBC:
	ldrh r0, [r4, 0x30]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x2
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	bne _08071EE8
	movs r0, 0x17
	bl PlaySE
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
_08071EE8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SpriteCB_Egg_1

	thumb_func_start SpriteCB_Egg_2
SpriteCB_Egg_2: @ 8071EF0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _08071F9E
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x26
	ble _08071F5C
	ldr r0, =SpriteCB_Egg_3
	str r0, [r4, 0x1C]
	strh r5, [r4, 0x2E]
	ldr r4, =gEggHatchData
	ldr r0, [r4]
	ldrb r1, [r0, 0x4]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	ldr r3, =gSprites
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r5, [r0, 0x24]
	ldrb r1, [r2, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r5, [r0, 0x26]
	b _08071F9E
	.pool
_08071F5C:
	ldrh r0, [r4, 0x30]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x2
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	bne _08071F90
	movs r0, 0x17
	bl PlaySE
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	bl CreateRandomEggShardSprite
	bl CreateRandomEggShardSprite
_08071F90:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1E
	bne _08071F9E
	movs r0, 0x17
	bl PlaySE
_08071F9E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end SpriteCB_Egg_2

	thumb_func_start SpriteCB_Egg_3
SpriteCB_Egg_3: @ 8071FA4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x32
	ble _08071FBE
	ldr r0, =SpriteCB_Egg_4
	str r0, [r1, 0x1C]
	movs r0, 0
	strh r0, [r1, 0x2E]
_08071FBE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpriteCB_Egg_3

	thumb_func_start SpriteCB_Egg_4
SpriteCB_Egg_4: @ 8071FC8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08071FE8
	movs r1, 0x1
	negs r1, r1
	ldr r0, =0x0000ffff
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_08071FE8:
	ldrh r0, [r5, 0x2E]
	cmp r0, 0x3
	bhi _08072004
	movs r4, 0
_08071FF0:
	bl CreateRandomEggShardSprite
	lsls r0, r4, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08071FF0
_08072004:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08072032
	movs r0, 0x71
	bl PlaySE
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =SpriteCB_Egg_5
	str r0, [r5, 0x1C]
	strh r4, [r5, 0x2E]
_08072032:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpriteCB_Egg_4

	thumb_func_start SpriteCB_Egg_5
SpriteCB_Egg_5: @ 8072048
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08072084
	ldr r4, =gSprites
	ldr r3, =gEggHatchData
	ldr r0, [r3]
	ldrb r1, [r0, 0x1]
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
	ldr r0, [r3]
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAffineAnim
_08072084:
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x8
	bne _0807209E
	movs r1, 0x1
	negs r1, r1
	ldr r0, =0x0000ffff
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_0807209E:
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x9
	bgt _080720BC
	ldr r2, =gSprites
	ldr r0, =gEggHatchData
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x1
	strh r1, [r0, 0x22]
_080720BC:
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x28
	ble _080720CA
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
_080720CA:
	adds r0, r1, 0x1
	strh r0, [r5, 0x2E]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpriteCB_Egg_5

	thumb_func_start SpriteCB_EggShard
SpriteCB_EggShard: @ 80720E8
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x36]
	adds r0, r1
	strh r0, [r2, 0x36]
	ldrh r1, [r2, 0x32]
	ldrh r3, [r2, 0x38]
	adds r0, r1, r3
	strh r0, [r2, 0x38]
	movs r4, 0x36
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bge _08072106
	adds r0, 0xFF
_08072106:
	asrs r0, 8
	strh r0, [r2, 0x24]
	movs r3, 0x38
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bge _08072114
	adds r0, 0xFF
_08072114:
	asrs r0, 8
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x34]
	adds r3, r1, r0
	strh r3, [r2, 0x32]
	movs r4, 0x22
	ldrsh r1, [r2, r4]
	movs r4, 0x26
	ldrsh r0, [r2, r4]
	adds r0, r1, r0
	adds r1, 0x14
	cmp r0, r1
	ble _0807213A
	lsls r0, r3, 16
	cmp r0, 0
	ble _0807213A
	adds r0, r2, 0
	bl DestroySprite
_0807213A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SpriteCB_EggShard

	thumb_func_start CreateRandomEggShardSprite
CreateRandomEggShardSprite: @ 8072140
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r2, =gUnknown_0832C084
	ldr r0, =gEggHatchData
	ldr r6, [r0]
	ldrb r3, [r6, 0x7]
	lsls r0, r3, 2
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, 0x2
	adds r0, r2
	ldrh r4, [r0]
	adds r3, 0x1
	strb r3, [r6, 0x7]
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x64
	str r0, [sp]
	lsrs r1, 16
	str r1, [sp, 0x4]
	movs r0, 0x78
	movs r1, 0x3C
	adds r2, r5, 0
	adds r3, r4, 0
	bl CreateEggShardSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateRandomEggShardSprite

	thumb_func_start CreateEggShardSprite
CreateEggShardSprite: @ 8072194
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x1C]
	mov r9, r0
	ldr r1, [sp, 0x20]
	mov r10, r1
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 16
	lsrs r6, 16
	mov r0, r8
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	mov r1, r9
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, =gUnknown_0832C04C
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x4
	bl CreateSprite
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r6, [r0, 0x30]
	mov r1, r8
	strh r1, [r0, 0x32]
	mov r1, r9
	strh r1, [r0, 0x34]
	mov r1, r10
	bl StartSpriteAnim
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateEggShardSprite

	thumb_func_start sub_8072214
sub_8072214: @ 8072214
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	adds r5, r0, 0
	mov r9, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x2C]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	ldr r3, =gEggHatchData
	ldr r0, [r3]
	movs r2, 0
	strb r2, [r0, 0xE]
	ldr r1, [r3]
	movs r0, 0x5
	strb r0, [r1, 0xF]
	ldr r1, [r3]
	movs r0, 0x6
	strb r0, [r1, 0x10]
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r0, [r3]
	adds r0, 0xE
	str r0, [sp, 0x8]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	mov r0, r9
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	mov r3, r8
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8072214

	thumb_func_start sub_807228C
sub_807228C: @ 807228C
	push {r4-r6,lr}
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	cmp r5, r6
	bcs _080722D6
_0807229C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _080722CC
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x28
	beq _080722C4
	cmp r0, 0x31
	bne _080722CC
_080722C4:
	movs r0, 0x2
	b _080722D8
	.pool
_080722CC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r6
	bcc _0807229C
_080722D6:
	movs r0, 0x1
_080722D8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_807228C

	thumb_func_start sub_80722E0
sub_80722E0: @ 80722E0
	push {r4,lr}
	bl sub_80D22D0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x6
	bl sub_80C7050
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80722E0

	.align 2, 0 @ Don't pad with nop.
