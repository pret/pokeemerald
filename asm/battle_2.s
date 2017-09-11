	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text
    
    
	thumb_func_start sub_8036760
sub_8036760: @ 8036760
	push {lr}
	bl MoveSaveBlocks_ResetHeap
	bl sub_8056F28
	bl dp11_init
	bl init_uns_table_pokemon_copy
	bl sub_8185F84
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080367CC
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	beq _08036798
	bl InitBattle
	b _080367BA
	.pool
_08036798:
	movs r0, 0x80
	lsls r0, 15
	ands r1, r0
	cmp r1, 0
	bne _080367B4
	bl battle_wireless_setup_if_required_maybe
	ldr r0, =sub_8037ADC
	bl SetMainCallback2
	b _080367BA
	.pool
_080367B4:
	ldr r0, =intro_end
	bl SetMainCallback2
_080367BA:
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1]
	b _080367D0
	.pool
_080367CC:
	bl InitBattle
_080367D0:
	pop {r0}
	bx r0
	thumb_func_end sub_8036760

	thumb_func_start InitBattle
InitBattle: @ 80367D4
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	str r0, [sp]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	mov r0, sp
	bl CpuSet
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r1, =0x00005051
	movs r0, 0x44
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_02022E24
	movs r2, 0xF0
	strh r2, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08036870
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	beq _08036870
	ldr r1, =gUnknown_02022E26
	movs r0, 0x9F
	strh r0, [r1]
	ldr r0, =gUnknown_02022E28
	strh r2, [r0]
	ldr r1, =gUnknown_02022E2A
	movs r0, 0x20
	strh r0, [r1]
	b _080368BE
	.pool
_08036870:
	ldr r0, =gUnknown_02022E26
	ldr r2, =0x00005051
	adds r1, r2, 0
	strh r1, [r0]
	bl dp12_8087EA4
	ldr r0, =gUnknown_02038C28
	movs r3, 0xF0
	movs r5, 0xF0
	lsls r5, 3
	adds r2, r0, r5
	movs r1, 0x4F
_08036888:
	strh r3, [r0]
	strh r3, [r2]
	adds r2, 0x2
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08036888
	movs r1, 0x50
	ldr r4, =gUnknown_0831AC70
	ldr r0, =gUnknown_02038C28
	ldr r3, =0x0000ff10
	movs r5, 0x82
	lsls r5, 4
	adds r2, r0, r5
	adds r0, 0xA0
_080368A6:
	strh r3, [r0]
	strh r3, [r2]
	adds r2, 0x2
	adds r0, 0x2
	adds r1, 0x1
	cmp r1, 0x9F
	ble _080368A6
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	bl sub_80BA038
_080368BE:
	bl ResetPaletteFade
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r0, =gUnknown_02022E18
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r1, [r0]
	ldr r0, =gUnknown_02022E20
	strh r1, [r0]
	ldr r0, =gUnknown_02022E22
	strh r1, [r0]
	bl sub_80B0BD0
	ldr r2, =gUnknown_02022FF0
	strb r0, [r2]
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _080368FE
	movs r0, 0x8
	strb r0, [r2]
_080368FE:
	bl c2_berry_program_update_menu
	bl sub_8035AA4
	bl ResetSpriteData
	bl ResetTasks
	bl sub_8036154
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, =vblank_cb_08078BB4
	bl SetVBlankCallback
	bl sub_803269C
	ldr r2, [r4]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	beq _0803693E
	ldr r1, =0x00400040
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	bne _08036994
_0803693E:
	ldr r0, =sub_8037458
	bl SetMainCallback2
	b _080369AE
	.pool
_08036994:
	movs r0, 0x40
	ands r2, r0
	cmp r2, 0
	beq _080369A8
	ldr r0, =sub_8037DF4
	bl SetMainCallback2
	b _080369AE
	.pool
_080369A8:
	ldr r0, =sub_8036FAC
	bl SetMainCallback2
_080369AE:
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	ldr r1, =0x01000002
	ands r0, r1
	cmp r0, 0
	bne _080369E8
	ldr r4, =gEnemyParty
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	adds r0, r4, 0
	movs r2, 0x1
	bl CreateNPCTrainerParty
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _080369E4
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, =gTrainerBattleOpponent_B
	ldrh r1, [r1]
	movs r2, 0
	bl CreateNPCTrainerParty
_080369E4:
	bl SetWildMonHeldItem
_080369E8:
	ldr r1, =gMain
	ldr r2, =0x00000439
	adds r1, r2
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r5, =0x00000ca9
	adds r1, r5
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r4, =gPlayerParty
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r4, r0
_08036A10:
	adds r0, r4, 0
	movs r1, 0x3
	bl AdjustFriendship
	adds r4, 0x64
	cmp r4, r5
	ble _08036A10
	movs r1, 0
	ldr r0, =gBattleCommunication
	strb r1, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitBattle

	thumb_func_start sub_8036A5C
sub_8036A5C: @ 8036A5C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r6, 0
	mov r9, r6
	movs r0, 0xCE
	lsls r0, 1
	mov r10, r0
	mov r8, r6
_08036A72:
	movs r0, 0x64
	mov r4, r9
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	adds r1, r0, 0
	cmp r5, 0
	beq _08036AEE
	cmp r5, r10
	beq _08036ABA
	cmp r7, 0
	beq _08036ABA
	cmp r1, 0
	bne _08036ABA
	movs r0, 0x1
	mov r2, r8
	lsls r0, r2
	orrs r6, r0
	lsls r0, r6, 16
	lsrs r6, r0, 16
_08036ABA:
	cmp r5, 0
	beq _08036AEE
	cmp r7, 0
	beq _08036AD6
	cmp r5, r10
	beq _08036ACA
	cmp r1, 0
	beq _08036AD6
_08036ACA:
	movs r0, 0x2
	mov r1, r8
	lsls r0, r1
	orrs r6, r0
	lsls r0, r6, 16
	lsrs r6, r0, 16
_08036AD6:
	cmp r5, 0
	beq _08036AEE
	cmp r5, r10
	beq _08036AEE
	cmp r7, 0
	bne _08036AEE
	movs r0, 0x3
	mov r2, r8
	lsls r0, r2
	orrs r6, r0
	lsls r0, r6, 16
	lsrs r6, r0, 16
_08036AEE:
	movs r0, 0x2
	add r8, r0
	movs r1, 0x1
	add r9, r1
	mov r2, r9
	cmp r2, 0x5
	ble _08036A72
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	movs r1, 0xC1
	lsls r1, 1
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r4]
	ldr r5, =0x00000183
	adds r0, r5
	lsrs r1, r6, 8
	strb r1, [r0]
	ldr r0, =0x000008d2
	bl FlagGet
	ldr r1, [r4]
	adds r1, r5
	lsls r0, 7
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8036A5C

	thumb_func_start sub_8036B44
sub_8036B44: @ 8036B44
	push {r4-r7,lr}
	ldr r0, =gBattleStruct
	ldr r5, [r0]
	movs r0, 0xC2
	lsls r0, 1
	adds r4, r5, r0
	bl sub_80E162C
	cmp r0, 0x1
	bne _08036BC0
	movs r2, 0
	ldr r7, =gSaveBlock1Ptr
	movs r1, 0xC6
	lsls r1, 1
	adds r5, r1
	adds r6, r7, 0
	ldr r3, =0x000031f8
_08036B66:
	adds r0, r4, r2
	ldr r1, [r6]
	adds r1, r3
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x5
	ble _08036B66
	adds r1, r4, r2
	movs r0, 0xFF
	strb r0, [r1]
	movs r2, 0
	adds r3, r5, 0
	ldr r6, =gSaveBlock1Ptr
	ldr r5, =0x00003214
_08036B86:
	adds r0, r3, r2
	ldr r1, [r6]
	adds r1, r5
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x11
	ble _08036B86
	ldr r0, [r7]
	ldr r1, =0x00003226
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4, 0x7]
	ldr r0, [r7]
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	b _08036C00
	.pool
_08036BC0:
	movs r0, 0xAF
	bl ItemIdToBerryType
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryInfo
	adds r3, r0, 0
	movs r2, 0
	movs r0, 0xC6
	lsls r0, 1
	adds r5, r0
_08036BD8:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x5
	ble _08036BD8
	adds r1, r4, r2
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r5, 0
	movs r2, 0
	adds r1, r0, 0
	adds r1, 0x11
_08036BF4:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, r0
	bge _08036BF4
	movs r0, 0
	strb r0, [r4, 0x7]
_08036C00:
	strb r0, [r4, 0x1A]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8036B44

	thumb_func_start berry_801017C
berry_801017C: @ 8036C08
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08036C20
	b _08036D4C
_08036C20:
	bl sub_80E162C
	cmp r0, 0x1
	bne _08036CDC
	movs r5, 0
	ldr r3, =gEnigmaBerries
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	adds r6, r3, 0
	mov r4, r8
	ldr r2, =0x000031f8
	adds r7, r3, 0
	adds r7, 0x38
_08036C3A:
	adds r1, r5, r6
	ldr r0, [r4]
	adds r0, r2
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, r7
	ldr r0, [r4]
	adds r0, r2
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x5
	ble _08036C3A
	adds r1, r5, r3
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r3, 0
	adds r0, 0x38
	adds r0, r5, r0
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	movs r5, 0
	adds r7, r3, 0
	adds r7, 0x8
	ldr r4, =gSaveBlock1Ptr
	ldr r2, =0x00003214
	adds r6, r3, 0
	adds r6, 0x40
_08036C78:
	adds r1, r5, r7
	ldr r0, [r4]
	adds r0, r2
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, r6
	ldr r0, [r4]
	adds r0, r2
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x11
	ble _08036C78
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00003226
	adds r0, r2
	ldrb r1, [r0]
	strb r1, [r3, 0x7]
	ldrb r0, [r0]
	adds r1, r3, 0
	adds r1, 0x3F
	strb r0, [r1]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, =0x00003227
	adds r0, r1
	ldrb r1, [r0]
	strb r1, [r3, 0x1A]
	ldrb r1, [r0]
	adds r0, r3, 0
	adds r0, 0x52
	strb r1, [r0]
	b _08036EA0
	.pool
_08036CDC:
	movs r0, 0xAF
	bl ItemIdToBerryType
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryInfo
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gEnigmaBerries
	adds r7, r4, 0
	adds r7, 0x38
	adds r3, r4, 0
_08036CF6:
	adds r1, r5, r4
	adds r2, r6, r5
	ldrb r0, [r2]
	strb r0, [r1]
	adds r1, r5, r7
	ldrb r0, [r2]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x5
	ble _08036CF6
	adds r1, r5, r3
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r3, 0
	adds r0, 0x38
	adds r0, r5, r0
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	movs r5, 0
	adds r4, r3, 0
	adds r4, 0x8
	movs r1, 0
	adds r2, r3, 0
	adds r2, 0x40
_08036D28:
	adds r0, r5, r4
	strb r1, [r0]
	adds r0, r5, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x11
	ble _08036D28
	movs r1, 0
	strb r1, [r3, 0x7]
	adds r0, r3, 0
	adds r0, 0x3F
	strb r1, [r0]
	strb r1, [r3, 0x1A]
	adds r0, 0x13
	strb r1, [r0]
	b _08036EA0
	.pool
_08036D4C:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08036DF0
	movs r0, 0x80
	lsls r0, 1
	ands r1, r0
	movs r2, 0x4
	mov r8, r2
	cmp r1, 0
	beq _08036D66
	movs r4, 0x2
	mov r8, r4
_08036D66:
	movs r5, 0
	cmp r5, r8
	blt _08036D6E
	b _08036EA0
_08036D6E:
	ldr r0, =gLinkPlayers
	mov r12, r0
	ldr r3, =gEnigmaBerries
	adds r6, r3, 0
	movs r1, 0x8
	adds r1, r6
	mov r9, r1
_08036D7C:
	lsls r1, r5, 8
	ldr r0, =gUnknown_020223C8
	adds r7, r1, r0
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r12
	ldrb r3, [r0, 0x18]
	movs r4, 0
	adds r5, 0x1
	mov r10, r5
	lsls r1, r3, 3
	subs r0, r1, r3
	adds r5, r1, 0
	lsls r0, 2
	adds r1, r0, r6
_08036D9C:
	adds r0, r7, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x5
	ble _08036D9C
	subs r0, r5, r3
	lsls r0, 2
	adds r1, r4, r0
	adds r1, r6
	movs r2, 0xFF
	strb r2, [r1]
	movs r4, 0
	mov r2, r9
	adds r1, r0, r2
	adds r2, r7, 0
	adds r2, 0x8
_08036DC0:
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x11
	ble _08036DC0
	subs r0, r5, r3
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r7, 0x7]
	strb r1, [r0, 0x7]
	ldrb r1, [r7, 0x1A]
	strb r1, [r0, 0x1A]
	mov r5, r10
	cmp r5, r8
	blt _08036D7C
	b _08036EA0
	.pool
_08036DF0:
	movs r5, 0
	ldr r4, =gEnigmaBerries
	mov r9, r4
_08036DF6:
	lsls r0, r5, 8
	ldr r1, =gUnknown_020223C8
	adds r7, r0, r1
	movs r4, 0
	adds r2, r5, 0x1
	mov r10, r2
	lsls r0, r5, 3
	mov r8, r0
	adds r1, r5, 0x2
	mov r12, r1
	subs r1, r0, r5
	mov r2, r12
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	mov r2, r9
	adds r3, r0, r2
	lsls r1, 2
	adds r2, r1, r2
_08036E1C:
	adds r0, r7, r4
	ldrb r1, [r0]
	strb r1, [r2]
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	adds r4, 0x1
	cmp r4, 0x5
	ble _08036E1C
	mov r0, r8
	subs r3, r0, r5
	lsls r3, 2
	adds r1, r4, r3
	add r1, r9
	ldrb r0, [r1]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r1]
	mov r0, r12
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r1, r4, r2
	add r1, r9
	ldrb r0, [r1]
	movs r4, 0xFF
	orrs r0, r4
	strb r0, [r1]
	movs r4, 0
	ldr r0, =gEnigmaBerries
	adds r0, 0x8
	adds r2, r0
	adds r3, r0
	adds r6, r7, 0
	adds r6, 0x8
_08036E64:
	adds r0, r6, r4
	ldrb r1, [r0]
	strb r1, [r3]
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, 0x1
	adds r3, 0x1
	adds r4, 0x1
	cmp r4, 0x11
	ble _08036E64
	mov r0, r8
	subs r2, r0, r5
	lsls r2, 2
	add r2, r9
	ldrb r0, [r7, 0x7]
	strb r0, [r2, 0x7]
	mov r1, r12
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r9
	ldrb r1, [r7, 0x7]
	strb r1, [r0, 0x7]
	ldrb r1, [r7, 0x1A]
	strb r1, [r2, 0x1A]
	ldrb r1, [r7, 0x1A]
	strb r1, [r0, 0x1A]
	mov r5, r10
	cmp r5, 0x1
	ble _08036DF6
_08036EA0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end berry_801017C

	thumb_func_start sub_8036EB8
sub_8036EB8: @ 8036EB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	movs r6, 0
	ldr r0, =gUnknown_020223C4
	ldrh r2, [r0]
	movs r1, 0x80
	lsls r1, 1
	mov r12, r0
	cmp r2, r1
	bne _08036EFC
	cmp r3, 0
	bne _08036EEC
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0xC
	b _08036EF2
	.pool
_08036EEC:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x8
_08036EF2:
	orrs r1, r2
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_08036EFC:
	cmp r6, 0
	bne _08036FA0
	movs r2, 0
	cmp r2, r4
	bge _08036F20
	ldr r1, =gUnknown_020223C4
	mov r8, r1
	movs r5, 0x80
	lsls r5, 1
_08036F0E:
	adds r1, r5
	adds r2, 0x1
	cmp r2, r4
	bge _08036F20
	mov r7, r8
	ldrh r0, [r7]
	ldrh r7, [r1]
	cmp r0, r7
	beq _08036F0E
_08036F20:
	cmp r2, r4
	bne _08036F48
	cmp r3, 0
	bne _08036F38
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0xC
	b _08036F3E
	.pool
_08036F38:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x8
_08036F3E:
	orrs r1, r2
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_08036F48:
	cmp r6, 0
	bne _08036FA0
	movs r2, 0
	ldr r5, =gBattleTypeFlags
	cmp r2, r4
	bge _08036F8A
	mov r0, r12
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _08036F82
_08036F60:
	lsls r0, r2, 8
	add r0, r12
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 2
	cmp r0, r1
	bls _08036F72
	cmp r2, r3
	bne _08036F8A
_08036F72:
	adds r2, 0x1
	cmp r2, r4
	bge _08036F8A
	lsls r0, r2, 8
	add r0, r12
	ldrh r0, [r0]
	cmp r0, r1
	bne _08036F60
_08036F82:
	cmp r2, r3
	beq _08036F60
	cmp r2, r3
	bge _08036F60
_08036F8A:
	cmp r2, r4
	bne _08036F98
	ldr r0, [r5]
	movs r1, 0xC
	b _08036F9C
	.pool
_08036F98:
	ldr r0, [r5]
	movs r1, 0x8
_08036F9C:
	orrs r0, r1
	str r0, [r5]
_08036FA0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8036EB8

	thumb_func_start sub_8036FAC
sub_8036FAC: @ 8036FAC
	push {r4-r6,lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gBattleScripting
	adds r0, 0x25
	strb r6, [r0]
	movs r0, 0x1
	adds r5, r6, 0
	eors r5, r0
	ldr r0, =gBattleCommunication
	ldrb r0, [r0]
	cmp r0, 0x12
	bls _08036FD8
	b _0803744C
_08036FD8:
	lsls r0, 2
	ldr r1, =_08036FF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08036FF0:
	.4byte _0803703C
	.4byte _08037080
	.4byte _08037144
	.4byte _080371D8
	.4byte _08037200
	.4byte _0803742C
	.4byte _08037438
	.4byte _08037230
	.4byte _08037258
	.4byte _0803742C
	.4byte _08037438
	.4byte _08037288
	.4byte _080372B0
	.4byte _0803742C
	.4byte _08037438
	.4byte _08037318
	.4byte _08037378
	.4byte _080373A0
	.4byte _080373E0
_0803703C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08037068
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl sub_805EF14
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1]
_08037068:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037072
	b _0803744C
_08037072:
	bl sub_800E0E8
	b _0803744C
	.pool
_08037080:
	ldr r2, =gBattleTypeFlags
	ldr r1, [r2]
	movs r6, 0x2
	adds r0, r1, 0
	ands r0, r6
	cmp r0, 0
	beq _08037124
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037098
	b _0803744C
_08037098:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080370EE
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, =0x00000181
	adds r1, r0, r2
	movs r0, 0x3
	strb r0, [r1]
	bl sub_8036A5C
	bl sub_8036B44
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	cmp r1, r0
	bne _080370D8
	ldr r0, =gLinkPlayers
	movs r1, 0
	strh r1, [r0, 0x18]
	movs r1, 0x1
	strh r1, [r0, 0x34]
_080370D8:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	adds r1, r5
	movs r2, 0x20
	bl link_0800A448
	ldr r0, =gBattleCommunication
	strb r6, [r0]
_080370EE:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080370F8
	b _0803744C
_080370F8:
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _0803744C
	.pool
_08037124:
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	bne _08037134
	movs r0, 0x4
	orrs r1, r0
	str r1, [r2]
_08037134:
	ldr r1, =gBattleCommunication
	movs r0, 0xF
	strb r0, [r1]
	bl berry_801017C
	b _0803744C
	.pool
_08037144:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _08037152
	b _0803744C
_08037152:
	bl sub_800A5B4
	movs r0, 0x2
	adds r1, r6, 0
	bl sub_8036EB8
	bl berry_801017C
	ldr r0, =task00_0800F6FC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	movs r1, 0
	movs r0, 0x87
	lsls r0, 1
	strh r0, [r2, 0xA]
	movs r0, 0x5A
	strh r0, [r2, 0xC]
	strh r1, [r2, 0x12]
	ldr r0, =gBattleStruct
	ldr r3, [r0]
	movs r4, 0xC1
	lsls r4, 1
	adds r0, r3, r4
	ldrb r1, [r0]
	adds r4, 0x1
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r2, 0xE]
	ldr r1, =gUnknown_020223C4
	lsls r4, r5, 8
	adds r1, 0x2
	adds r4, r1
	ldrh r0, [r4]
	strh r0, [r2, 0x10]
	lsls r0, r6, 8
	adds r0, r1
	ldrh r0, [r0]
	bl sub_8185F90
	ldrh r0, [r4]
	bl sub_8185F90
	bl sub_8068AA4
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_080371D8:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _080371E4
	b _0803744C
_080371E4:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty
	movs r2, 0xC8
	bl link_0800A448
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_08037200:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _0803720E
	b _0803744C
_0803720E:
	bl sub_800A5B4
	ldr r0, =gEnemyParty
	lsls r1, r5, 8
	ldr r2, =gUnknown_020223C4
	adds r1, r2
	movs r2, 0xC8
	bl memcpy
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_08037230:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _0803723C
	b _0803744C
_0803723C:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty + 200
	movs r2, 0xC8
	bl link_0800A448
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_08037258:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _08037266
	b _0803744C
_08037266:
	bl sub_800A5B4
	ldr r0, =gEnemyParty + 200
	lsls r1, r5, 8
	ldr r2, =gUnknown_020223C4
	adds r1, r2
	movs r2, 0xC8
	bl memcpy
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_08037288:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _08037294
	b _0803744C
_08037294:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty + 400
	movs r2, 0xC8
	bl link_0800A448
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_080372B0:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _080372BE
	b _0803744C
_080372BE:
	bl sub_800A5B4
	ldr r4, =gEnemyParty + 400
	lsls r1, r5, 8
	ldr r0, =gUnknown_020223C4
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0xC8
	bl memcpy
	ldr r1, =0xfffffe70
	adds r0, r4, r1
	bl shedinja_something
	ldr r2, =0xfffffed4
	adds r0, r4, r2
	bl shedinja_something
	adds r0, r4, 0
	subs r0, 0xC8
	bl shedinja_something
	adds r0, r4, 0
	subs r0, 0x64
	bl shedinja_something
	adds r0, r4, 0
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0x64
	bl shedinja_something
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_08037318:
	bl sub_8032768
	bl sub_8184E58
	ldr r2, =gBattleCommunication
	movs r0, 0
	strb r0, [r2, 0x1]
	strb r0, [r2, 0x2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08037372
	movs r3, 0
	ldr r1, =gLinkPlayers
	ldrb r0, [r1]
	adds r5, r2, 0
	cmp r0, 0x3
	bne _08037356
	movs r4, 0xFF
	adds r2, r1, 0
_08037344:
	adds r2, 0x1C
	adds r3, 0x1
	cmp r3, 0x1
	bgt _08037356
	ldrh r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x3
	beq _08037344
_08037356:
	cmp r3, 0x2
	bne _0803736C
	movs r0, 0x10
	strb r0, [r5]
	b _0803744C
	.pool
_0803736C:
	movs r0, 0x12
	strb r0, [r5]
	b _0803744C
_08037372:
	movs r0, 0x12
	strb r0, [r2]
	b _0803744C
_08037378:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0803744C
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203BD2C
	movs r2, 0x4
	bl link_0800A448
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_080373A0:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	bne _0803744C
	bl sub_800A5B4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080373CA
	ldr r0, =gUnknown_0203BD2C
	lsls r1, r5, 8
	ldr r2, =gUnknown_020223C4
	adds r1, r2
	movs r2, 0x4
	bl memcpy
_080373CA:
	ldr r1, =gBattleCommunication
	b _08037446
	.pool
_080373E0:
	ldr r0, =gUnknown_02024333
	adds r1, r0, 0x1
	bl battle_load_something
	lsls r0, 24
	cmp r0, 0
	beq _0803744C
	ldr r2, =gUnknown_03005D00
	ldr r1, =gMain
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, =sub_8039EF0
	str r0, [r1]
	ldr r0, =sub_8038420
	bl SetMainCallback2
	ldr r2, =gBattleTypeFlags
	ldr r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803744C
	movs r0, 0x20
	orrs r1, r0
	str r1, [r2]
	b _0803744C
	.pool
_0803742C:
	ldr r0, =gBattleCommunication
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	movs r1, 0x1
	strb r1, [r0, 0x1]
_08037438:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x1]
	subs r0, 0x1
	strb r0, [r1, 0x1]
	lsls r0, 24
	cmp r0, 0
	bne _0803744C
_08037446:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0803744C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8036FAC

	thumb_func_start sub_8037458
sub_8037458: @ 8037458
	push {r4-r7,lr}
	sub sp, 0x4
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gBattleScripting
	adds r0, 0x25
	strb r6, [r0]
	movs r0, 0x1
	adds r7, r6, 0
	eors r7, r0
	ldr r0, =gBattleCommunication
	ldrb r0, [r0]
	cmp r0, 0x10
	bls _08037486
	b _080379D6
_08037486:
	lsls r0, 2
	ldr r1, =_0803749C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803749C:
	.4byte _080374E0
	.4byte _08037518
	.4byte _0803761C
	.4byte _08037670
	.4byte _08037694
	.4byte _08037710
	.4byte _08037734
	.4byte _080377B0
	.4byte _080377CC
	.4byte _080377FC
	.4byte _08037818
	.4byte _08037848
	.4byte _08037864
	.4byte _08037908
	.4byte _0803793A
	.4byte _0803795C
	.4byte _080379A0
_080374E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0803750C
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl sub_805EF14
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1]
_0803750C:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _08037518
	bl sub_800E0E8
_08037518:
	ldr r2, =gBattleTypeFlags
	ldr r1, [r2]
	movs r3, 0x2
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _080375FC
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037530
	b _080379D6
_08037530:
	ldr r6, =gLinkPlayers
	movs r0, 0
	strh r0, [r6, 0x18]
	strh r3, [r6, 0x34]
	adds r1, r6, 0
	adds r1, 0x50
	movs r0, 0x1
	strh r0, [r1]
	adds r1, 0x1C
	movs r0, 0x3
	strh r0, [r1]
	adds r0, r6, 0
	adds r0, 0x40
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r1, [r4]
	bl GetFrontierTrainerName
	adds r0, r6, 0
	adds r0, 0x5C
	ldr r5, =gTrainerBattleOpponent_B
	ldrh r1, [r5]
	bl GetFrontierTrainerName
	ldrh r1, [r4]
	mov r0, sp
	bl sub_8165B88
	mov r0, sp
	ldrb r0, [r0]
	adds r1, r6, 0
	adds r1, 0x52
	strh r0, [r1]
	ldrh r1, [r5]
	mov r0, sp
	bl sub_8165B88
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r6, 0
	adds r0, 0x6E
	strh r1, [r0]
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080375C4
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, =0x00000181
	adds r1, r0, r2
	movs r0, 0x3
	strb r0, [r1]
	bl sub_8036A5C
	bl sub_8036B44
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	adds r1, r5
	movs r2, 0x20
	bl link_0800A448
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1]
_080375C4:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080375CE
	b _080379D6
_080375CE:
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _080379D6
	.pool
_080375FC:
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	bne _0803760C
	movs r0, 0x4
	orrs r1, r0
	str r1, [r2]
_0803760C:
	ldr r1, =gBattleCommunication
	movs r0, 0xD
	strb r0, [r1]
	bl berry_801017C
	b _080379D6
	.pool
_0803761C:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _0803762A
	b _080379D6
_0803762A:
	bl sub_800A5B4
	movs r0, 0x2
	adds r1, r6, 0
	bl sub_8036EB8
	bl berry_801017C
	ldr r0, =task00_0800F6FC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	movs r0, 0x87
	lsls r0, 1
	strh r0, [r1, 0xA]
	movs r0, 0x5A
	strh r0, [r1, 0xC]
	strh r2, [r1, 0x12]
	adds r0, 0xEB
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	b _08037986
	.pool
_08037670:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _0803767C
	b _080379D6
_0803767C:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty
_08037686:
	movs r2, 0xC8
	bl link_0800A448
	b _08037986
	.pool
_08037694:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _080376A2
	b _080379D6
_080376A2:
	bl sub_800A5B4
	ldr r0, =gLinkPlayers
	lsls r1, r6, 3
	subs r1, r6
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x18]
	cmp r0, 0
	beq _080376E8
	ldr r4, =gPlayerParty
	lsls r1, r7, 8
	ldr r5, =gUnknown_020223C4
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0xC8
	bl memcpy
	movs r0, 0x96
	lsls r0, 1
	adds r4, r0
	lsls r1, r6, 8
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0xC8
	bl memcpy
	b _08037986
	.pool
_080376E8:
	ldr r4, =gPlayerParty
	lsls r1, r6, 8
	ldr r5, =gUnknown_020223C4
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0xC8
	bl memcpy
	movs r1, 0x96
	lsls r1, 1
	adds r4, r1
	lsls r1, r7, 8
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0xC8
	b _08037982
	.pool
_08037710:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _0803771C
	b _080379D6
_0803771C:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty + 200
	movs r2, 0x64
	bl link_0800A448
	b _08037986
	.pool
_08037734:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _08037742
	b _080379D6
_08037742:
	bl sub_800A5B4
	ldr r0, =gLinkPlayers
	lsls r1, r6, 3
	subs r1, r6
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x18]
	cmp r0, 0
	beq _08037788
	ldr r4, =gPlayerParty + 200
	lsls r1, r7, 8
	ldr r5, =gUnknown_020223C4
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
	movs r2, 0x96
	lsls r2, 1
	adds r4, r2
	lsls r1, r6, 8
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
	b _08037986
	.pool
_08037788:
	ldr r4, =gPlayerParty + 200
	lsls r1, r6, 8
	ldr r5, =gUnknown_020223C4
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
	movs r0, 0x96
	lsls r0, 1
	adds r4, r0
	lsls r1, r7, 8
	adds r1, r5
	adds r0, r4, 0
	movs r2, 0x64
	b _08037982
	.pool
_080377B0:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _080377BC
	b _080379D6
_080377BC:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gEnemyParty
	b _08037686
	.pool
_080377CC:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _080377DA
	b _080379D6
_080377DA:
	bl sub_800A5B4
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _080377EA
	b _08037986
_080377EA:
	ldr r0, =gEnemyParty
	ldr r1, =gUnknown_020223C4
	movs r2, 0xC8
	b _08037982
	.pool
_080377FC:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _08037808
	b _080379D6
_08037808:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gEnemyParty + 200
	b _08037686
	.pool
_08037818:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _08037826
	b _080379D6
_08037826:
	bl sub_800A5B4
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _08037836
	b _08037986
_08037836:
	ldr r0, =gEnemyParty + 200
	ldr r1, =gUnknown_020223C4
	movs r2, 0xC8
	b _08037982
	.pool
_08037848:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _08037854
	b _080379D6
_08037854:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gEnemyParty + 400
	b _08037686
	.pool
_08037864:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _08037872
	b _080379D6
_08037872:
	bl sub_800A5B4
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0803788A
	ldr r0, =gEnemyParty + 400
	ldr r1, =gUnknown_020223C4
	movs r2, 0xC8
	bl memcpy
_0803788A:
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0x64
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0xC8
	bl shedinja_something
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	bl shedinja_something
	movs r2, 0xC8
	lsls r2, 1
	adds r0, r4, r2
	bl shedinja_something
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	bl shedinja_something
	ldr r4, =gEnemyParty
	adds r0, r4, 0
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0x64
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0xC8
	bl shedinja_something
	movs r2, 0x96
	lsls r2, 1
	adds r0, r4, r2
	bl shedinja_something
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	bl shedinja_something
	movs r2, 0xFA
	lsls r2, 1
	adds r0, r4, r2
	bl shedinja_something
	b _08037986
	.pool
_08037908:
	bl sub_8032768
	bl sub_8184E58
	ldr r2, =gBattleCommunication
	movs r0, 0
	strb r0, [r2, 0x1]
	strb r0, [r2, 0x2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08037934
	movs r0, 0xE
	strb r0, [r2]
	b _080379D6
	.pool
_08037934:
	movs r0, 0x10
	strb r0, [r2]
	b _080379D6
_0803793A:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080379D6
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203BD2C
	movs r2, 0x4
	bl link_0800A448
	b _08037986
	.pool
_0803795C:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	bne _080379D6
	bl sub_800A5B4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08037986
	ldr r0, =gUnknown_0203BD2C
	lsls r1, r7, 8
	ldr r2, =gUnknown_020223C4
	adds r1, r2
	movs r2, 0x4
_08037982:
	bl memcpy
_08037986:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080379D6
	.pool
_080379A0:
	ldr r0, =gUnknown_02024333
	adds r1, r0, 0x1
	bl battle_load_something
	lsls r0, 24
	cmp r0, 0
	beq _080379D6
	bl sub_8166188
	ldr r2, =gUnknown_03005D00
	ldr r1, =gMain
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, =sub_8039EF0
	str r0, [r1]
	ldr r0, =sub_8038420
	bl SetMainCallback2
	ldr r2, =gBattleTypeFlags
	ldr r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080379D6
	movs r0, 0x20
	orrs r1, r0
	str r1, [r2]
_080379D6:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8037458

	thumb_func_start sub_80379F8
sub_80379F8: @ 80379F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	mov r8, r0
	ldr r6, =gUnknown_02022FF8
	mov r10, r6
_08037A12:
	ldr r1, [sp]
	add r1, r8
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, r8
	lsls r5, r1, 5
	strh r0, [r6]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	strh r0, [r6, 0x2]
	movs r0, 0x4
	add r0, r10
	mov r9, r0
	adds r7, r5, r0
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r7, 0
	bl GetMonData
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	strb r0, [r6, 0xF]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r6, 0x10]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r6, 0x12]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	mov r1, r10
	adds r1, 0x14
	adds r5, r1
	str r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r6, 0x18]
	adds r0, r4, 0
	bl GetMonGender
	strb r0, [r6, 0x1C]
	adds r0, r7, 0
	bl StripExtCtrlCodes
	adds r0, r4, 0
	movs r1, 0x3
	bl GetMonData
	cmp r0, 0x1
	beq _08037AA4
	adds r0, r7, 0
	movs r1, 0
	bl sub_81DB4DC
_08037AA4:
	adds r6, 0x20
	movs r1, 0x1
	add r8, r1
	mov r0, r8
	cmp r0, 0x2
	ble _08037A12
	ldr r0, =gUnknown_02023058
	ldr r0, [r0]
	mov r1, r9
	subs r1, 0x4
	movs r2, 0x60
	bl memcpy
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80379F8

	thumb_func_start sub_8037ADC
sub_8037ADC: @ 8037ADC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0x4
	mov r9, r0
	movs r4, 0xF
	ldr r6, =gBattleTypeFlags
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _08037B02
	movs r1, 0x2
	mov r9, r1
	movs r4, 0x3
_08037B02:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gBattleScripting
	adds r0, 0x25
	movs r2, 0
	mov r8, r2
	strb r7, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xB4
	str r1, [sp]
	adds r0, 0xAC
	mov r10, r0
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	ldr r5, =gBattleCommunication
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _08037BA4
	cmp r0, 0x1
	bgt _08037B50
	cmp r0, 0
	beq _08037B5E
	b _08037D0A
	.pool
_08037B50:
	cmp r0, 0x2
	bne _08037B56
	b _08037C64
_08037B56:
	cmp r0, 0x3
	bne _08037B5C
	b _08037C9E
_08037B5C:
	b _08037D0A
_08037B5E:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037B68
	b _08037D0A
_08037B68:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _08037B74
	b _08037D0A
_08037B74:
	ldr r4, =gUnknown_02023058
	movs r0, 0x60
	bl Alloc
	str r0, [r4]
	movs r0, 0
	bl sub_80379F8
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	movs r2, 0x60
	bl link_0800A448
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _08037D0A
	.pool
_08037BA4:
	bl sub_800A550
	adds r1, r4, 0
	ands r1, r0
	cmp r1, r4
	beq _08037BB2
	b _08037D0A
_08037BB2:
	bl sub_800A5B4
	movs r5, 0
	cmp r8, r9
	bge _08037C2E
	lsls r0, r7, 3
	subs r0, r7
	lsls r6, r0, 2
	mov r8, r5
	ldr r4, =gUnknown_020223C4
_08037BC6:
	cmp r5, r7
	beq _08037C1E
	mov r2, r9
	cmp r2, 0x4
	bne _08037C14
	ldr r2, =gLinkPlayers
	mov r1, r8
	adds r0, r1, r2
	ldrh r1, [r0, 0x18]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08037BF8
	adds r0, r6, r2
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08037C04
	b _08037C1E
	.pool
_08037BF8:
	adds r0, r6, r2
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08037C1E
_08037C04:
	ldr r0, =gUnknown_02022FF8
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	b _08037C1E
	.pool
_08037C14:
	ldr r0, =gUnknown_02022FF8
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
_08037C1E:
	movs r2, 0x80
	lsls r2, 1
	adds r4, r2
	movs r0, 0x1C
	add r8, r0
	adds r5, 0x1
	cmp r5, r9
	blt _08037BC6
_08037C2E:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gMain
	ldr r0, [r1, 0x8]
	ldr r2, [sp]
	str r0, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	mov r2, r10
	str r0, [r2]
	ldr r0, =sub_8037ADC
	str r0, [r1, 0x8]
	bl sub_81B9150
	b _08037D0A
	.pool
_08037C64:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08037D0A
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08037D0A
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _08037C98
	bl sub_800ADF8
	b _08037D0A
	.pool
_08037C98:
	bl sub_800AC34
	b _08037D0A
_08037C9E:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _08037CE4
	bl sub_8010500
	lsls r0, 24
	cmp r0, 0
	beq _08037D0A
	mov r1, r10
	ldr r0, [r1]
	str r0, [r6]
	ldr r1, =gMain
	ldr r2, [sp]
	ldr r0, [r2]
	str r0, [r1, 0x8]
	ldr r0, =InitBattle
	bl SetMainCallback2
	ldr r4, =gUnknown_02023058
	ldr r0, [r4]
	bl Free
	mov r0, r8
	str r0, [r4]
	b _08037D0A
	.pool
_08037CE4:
	ldr r0, =gUnknown_03003124
	ldrb r5, [r0]
	cmp r5, 0
	bne _08037D0A
	mov r1, r10
	ldr r0, [r1]
	str r0, [r6]
	ldr r1, =gMain
	ldr r2, [sp]
	ldr r0, [r2]
	str r0, [r1, 0x8]
	ldr r0, =InitBattle
	bl SetMainCallback2
	ldr r4, =gUnknown_02023058
	ldr r0, [r4]
	bl Free
	str r5, [r4]
_08037D0A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8037ADC

	thumb_func_start intro_end
intro_end: @ 8037D2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	movs r1, 0xB4
	adds r1, r0
	mov r8, r1
	adds r7, r0, 0
	adds r7, 0xAC
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	ldr r5, =gBattleCommunication
	ldrb r0, [r5]
	cmp r0, 0
	beq _08037D64
	cmp r0, 0x1
	beq _08037DA4
	b _08037DD6
	.pool
_08037D64:
	ldr r4, =gUnknown_02023058
	movs r0, 0x60
	bl Alloc
	str r0, [r4]
	movs r0, 0x3
	bl sub_80379F8
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldr r1, =gMain
	ldr r0, [r1, 0x8]
	mov r2, r8
	str r0, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	str r0, [r7]
	ldr r0, =intro_end
	str r0, [r1, 0x8]
	bl sub_81B9150
	b _08037DD6
	.pool
_08037DA4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08037DD6
	movs r0, 0x2
	strb r0, [r5]
	ldr r1, =gBattleTypeFlags
	ldr r0, [r7]
	str r0, [r1]
	ldr r1, =gMain
	mov r2, r8
	ldr r0, [r2]
	str r0, [r1, 0x8]
	ldr r0, =InitBattle
	bl SetMainCallback2
	ldr r4, =gUnknown_02023058
	ldr r0, [r4]
	bl Free
	str r6, [r4]
_08037DD6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end intro_end

	thumb_func_start sub_8037DF4
sub_8037DF4: @ 8037DF4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gBattleScripting
	adds r0, 0x25
	strb r7, [r0]
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	ldr r0, =gBattleCommunication
	ldrb r0, [r0]
	cmp r0, 0xA
	bls _08037E20
	b _080383F8
_08037E20:
	lsls r0, 2
	ldr r1, =_08037E38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08037E38:
	.4byte _08037E64
	.4byte _08037EA8
	.4byte _08037F50
	.4byte _08038026
	.4byte _0803804C
	.4byte _08038140
	.4byte _08038164
	.4byte _080382CC
	.4byte _0803832C
	.4byte _0803836C
	.4byte _080383BC
_08037E64:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08037E90
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl sub_805EF14
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1]
_08037E90:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037E9A
	b _080383F8
_08037E9A:
	bl sub_800E0E8
	b _080383F8
	.pool
_08037EA8:
	ldr r2, =gBattleTypeFlags
	ldr r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08037F30
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037EBE
	b _080383F8
_08037EBE:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08037F02
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, =0x00000181
	adds r1, r0, r2
	movs r0, 0x3
	strb r0, [r1]
	bl sub_8036A5C
	bl sub_8036B44
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	adds r1, r5
	movs r2, 0x20
	bl link_0800A448
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08037F02:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _08037F0C
	b _080383F8
_08037F0C:
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _080383F8
	.pool
_08037F30:
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	bne _08037F40
	movs r0, 0x4
	orrs r1, r0
	str r1, [r2]
_08037F40:
	ldr r1, =gBattleCommunication
	movs r0, 0x7
	strb r0, [r1]
	bl berry_801017C
	b _080383F8
	.pool
_08037F50:
	bl sub_800A550
	movs r1, 0xF
	ands r1, r0
	cmp r1, 0xF
	beq _08037F5E
	b _080383F8
_08037F5E:
	bl sub_800A5B4
	movs r0, 0x4
	adds r1, r7, 0
	bl sub_8036EB8
	bl berry_801017C
	bl sub_8068AA4
	ldr r0, =task00_0800F6FC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x87
	lsls r1, 1
	strh r1, [r0, 0xA]
	movs r1, 0x5A
	strh r1, [r0, 0xC]
	strh r2, [r0, 0x12]
	strh r2, [r0, 0xE]
	strh r2, [r0, 0x10]
	ldr r1, =gUnknown_020223C4
	adds r4, r0, 0
	adds r5, r1, 0x2
	movs r7, 0x3F
	movs r6, 0x3
_08037FA4:
	ldrh r0, [r5]
	str r2, [sp]
	bl sub_8185F90
	ldr r0, =gLinkPlayers
	ldr r2, [sp]
	adds r0, r2, r0
	ldrh r0, [r0, 0x18]
	cmp r0, 0x1
	beq _08037FE6
	cmp r0, 0x1
	bgt _08037FD4
	cmp r0, 0
	beq _08037FDE
	b _0803800C
	.pool
_08037FD4:
	cmp r0, 0x2
	beq _08037FEE
	cmp r0, 0x3
	beq _08037FFE
	b _0803800C
_08037FDE:
	ldrh r0, [r5]
	adds r1, r7, 0
	ands r1, r0
	b _08037FF6
_08037FE6:
	ldrh r0, [r5]
	adds r1, r7, 0
	ands r1, r0
	b _08038006
_08037FEE:
	ldrh r0, [r5]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 6
_08037FF6:
	ldrh r0, [r4, 0xE]
	orrs r1, r0
	strh r1, [r4, 0xE]
	b _0803800C
_08037FFE:
	ldrh r0, [r5]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 6
_08038006:
	ldrh r0, [r4, 0x10]
	orrs r1, r0
	strh r1, [r4, 0x10]
_0803800C:
	movs r0, 0x80
	lsls r0, 1
	adds r5, r0
	adds r2, 0x1C
	subs r6, 0x1
	cmp r6, 0
	bge _08037FA4
	bl ZeroEnemyPartyMons
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08038026:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _08038032
	b _080383F8
_08038032:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty
	movs r2, 0xC8
	bl link_0800A448
	b _080383A6
	.pool
_0803804C:
	bl sub_800A550
	movs r1, 0xF
	ands r1, r0
	cmp r1, 0xF
	beq _0803805A
	b _080383F8
_0803805A:
	bl sub_800A5B4
	movs r6, 0
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	mov r8, r0
	ldr r4, =gUnknown_020223C4
	movs r5, 0
_0803806C:
	cmp r6, r7
	bne _080380A0
	ldr r0, =gLinkPlayers
	adds r0, r5, r0
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _0803808C
	cmp r0, 0x1
	bge _08038098
	cmp r0, 0
	beq _08038090
	b _0803812A
	.pool
_0803808C:
	cmp r0, 0x3
	bne _0803812A
_08038090:
	ldr r0, =gPlayerParty
	b _08038110
	.pool
_08038098:
	ldr r0, =gPlayerParty + 300
	b _08038110
	.pool
_080380A0:
	ldr r2, =gLinkPlayers
	adds r0, r5, r2
	ldrh r1, [r0, 0x18]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080380C4
	mov r1, r8
	adds r0, r1, r2
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080380D2
	b _080380F8
	.pool
_080380C4:
	mov r1, r8
	adds r0, r1, r2
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080380F8
_080380D2:
	adds r0, r5, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _080380E4
	cmp r0, 0x1
	bge _080380F0
	cmp r0, 0
	beq _080380E8
	b _0803812A
_080380E4:
	cmp r0, 0x3
	bne _0803812A
_080380E8:
	ldr r0, =gPlayerParty
	b _08038110
	.pool
_080380F0:
	ldr r0, =gPlayerParty + 300
	b _08038110
	.pool
_080380F8:
	adds r0, r5, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _0803810A
	cmp r0, 0x1
	bge _08038120
	cmp r0, 0
	beq _0803810E
	b _0803812A
_0803810A:
	cmp r0, 0x3
	bne _0803812A
_0803810E:
	ldr r0, =gEnemyParty
_08038110:
	adds r1, r4, 0
	movs r2, 0xC8
	bl memcpy
	b _0803812A
	.pool
_08038120:
	ldr r0, =gEnemyParty + 300
	adds r1, r4, 0
	movs r2, 0xC8
	bl memcpy
_0803812A:
	movs r2, 0x80
	lsls r2, 1
	adds r4, r2
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _0803806C
	b _080383A6
	.pool
_08038140:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _0803814C
	b _080383F8
_0803814C:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty + 200
	movs r2, 0x64
	bl link_0800A448
	b _080383A6
	.pool
_08038164:
	bl sub_800A550
	movs r1, 0xF
	ands r1, r0
	cmp r1, 0xF
	beq _08038172
	b _080383F8
_08038172:
	bl sub_800A5B4
	movs r6, 0
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	mov r8, r0
	ldr r4, =gUnknown_020223C4
	movs r5, 0
_08038184:
	cmp r6, r7
	bne _080381B8
	ldr r0, =gLinkPlayers
	adds r0, r5, r0
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _080381A4
	cmp r0, 0x1
	bge _080381B0
	cmp r0, 0
	beq _080381A8
	b _08038242
	.pool
_080381A4:
	cmp r0, 0x3
	bne _08038242
_080381A8:
	ldr r0, =gPlayerParty + 200
	b _08038228
	.pool
_080381B0:
	ldr r0, =gPlayerParty + 500
	b _08038228
	.pool
_080381B8:
	ldr r2, =gLinkPlayers
	adds r0, r5, r2
	ldrh r1, [r0, 0x18]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080381DC
	mov r1, r8
	adds r0, r1, r2
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080381EA
	b _08038210
	.pool
_080381DC:
	mov r1, r8
	adds r0, r1, r2
	ldrh r1, [r0, 0x18]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08038210
_080381EA:
	adds r0, r5, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _080381FC
	cmp r0, 0x1
	bge _08038208
	cmp r0, 0
	beq _08038200
	b _08038242
_080381FC:
	cmp r0, 0x3
	bne _08038242
_08038200:
	ldr r0, =gPlayerParty + 200
	b _08038228
	.pool
_08038208:
	ldr r0, =gPlayerParty + 500
	b _08038228
	.pool
_08038210:
	adds r0, r5, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bgt _08038222
	cmp r0, 0x1
	bge _08038238
	cmp r0, 0
	beq _08038226
	b _08038242
_08038222:
	cmp r0, 0x3
	bne _08038242
_08038226:
	ldr r0, =gEnemyParty + 200
_08038228:
	adds r1, r4, 0
	movs r2, 0x64
	bl memcpy
	b _08038242
	.pool
_08038238:
	ldr r0, =gEnemyParty + 500
	adds r1, r4, 0
	movs r2, 0x64
	bl memcpy
_08038242:
	movs r2, 0x80
	lsls r2, 1
	adds r4, r2
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _08038184
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0x64
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0xC8
	bl shedinja_something
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	bl shedinja_something
	movs r2, 0xC8
	lsls r2, 1
	adds r0, r4, r2
	bl shedinja_something
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	bl shedinja_something
	ldr r4, =gEnemyParty
	adds r0, r4, 0
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0x64
	bl shedinja_something
	adds r0, r4, 0
	adds r0, 0xC8
	bl shedinja_something
	movs r2, 0x96
	lsls r2, 1
	adds r0, r4, r2
	bl shedinja_something
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	bl shedinja_something
	movs r2, 0xFA
	lsls r2, 1
	adds r0, r4, r2
	bl shedinja_something
	b _080383A6
	.pool
_080382CC:
	bl sub_8032768
	bl sub_8184E58
	ldr r3, =gBattleCommunication
	movs r0, 0
	strb r0, [r3, 0x1]
	strb r0, [r3, 0x2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08038326
	movs r6, 0
	ldr r0, =gLinkPlayers
	ldrb r1, [r0]
	adds r4, r3, 0
	adds r2, r0, 0
	cmp r1, 0x3
	bne _0803830A
	movs r3, 0xFF
_080382F8:
	adds r2, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	bgt _0803830A
	ldrh r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0x3
	beq _080382F8
_0803830A:
	cmp r6, 0x4
	bne _08038320
	movs r0, 0x8
	strb r0, [r4]
	b _080383F8
	.pool
_08038320:
	movs r0, 0xA
	strb r0, [r4]
	b _080383F8
_08038326:
	movs r0, 0xA
	strb r0, [r3]
	b _080383F8
_0803832C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080383F8
	ldr r0, =gBattleStruct
	ldr r4, [r0]
	movs r0, 0xC0
	lsls r0, 1
	adds r4, r0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	str r0, [r4]
	ldr r0, =gUnknown_0203BD2C
	ldr r0, [r0]
	str r0, [r4, 0x4]
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	movs r2, 0x8
	bl link_0800A448
	b _080383A6
	.pool
_0803836C:
	bl sub_800A550
	movs r1, 0xF
	ands r1, r0
	cmp r1, 0xF
	bne _080383F8
	bl sub_800A5B4
	movs r2, 0
	b _08038386
_08038380:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_08038386:
	cmp r2, 0x3
	bhi _080383A6
	ldr r4, =gUnknown_020223C4
	lsls r3, r2, 8
	adds r0, r3, r4
	ldrh r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08038380
	adds r1, r4, 0x4
	adds r1, r3, r1
	ldr r0, =gUnknown_0203BD2C
	movs r2, 0x4
	bl memcpy
_080383A6:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080383F8
	.pool
_080383BC:
	ldr r0, =gUnknown_02024333
	adds r1, r0, 0x1
	bl battle_load_something
	lsls r0, 24
	cmp r0, 0
	beq _080383F8
	ldr r2, =gUnknown_03005D00
	ldr r1, =gMain
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, =sub_8039EF0
	str r0, [r1]
	ldr r0, =sub_8038420
	bl SetMainCallback2
	ldr r3, =gBattleTypeFlags
	ldr r2, [r3]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _080383F8
	ldr r0, =gTrainerBattleOpponent_A
	movs r4, 0x80
	lsls r4, 4
	adds r1, r4, 0
	strh r1, [r0]
	movs r0, 0x20
	orrs r2, r0
	str r2, [r3]
_080383F8:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8037DF4

	thumb_func_start sub_8038420
sub_8038420: @ 8038420
	push {lr}
	sub sp, 0x4
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	bl RunTasks
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08038482
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08038482
	bl rfu_lacks_rfufunc
	lsls r0, 24
	cmp r0, 0
	beq _08038482
	ldr r2, =gScriptResult
	ldr r1, =gBattleOutcome
	movs r0, 0x5
	strb r0, [r1]
	movs r0, 0x5
	strh r0, [r2]
	bl ResetPaletteFadeControl
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_80384E4
	bl SetMainCallback2
_08038482:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038420

	thumb_func_start sub_803849C
sub_803849C: @ 803849C
	push {lr}
	ldr r1, =gMain
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r2, 0x15]
	ldr r0, =0x00000439
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl ZeroEnemyPartyMons
	movs r0, 0x5A
	bl m4aSongNumStop
	bl sub_805F094
	bl dp11_free
	bl sub_8057028
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803849C

	thumb_func_start sub_80384E4
sub_80384E4: @ 80384E4
	push {lr}
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08038512
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
	bl sub_803849C
	bl FreeAllWindowBuffers
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_08038512:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80384E4

	thumb_func_start sub_8038528
sub_8038528: @ 8038528
	movs r1, 0
	strh r1, [r0, 0x2E]
	ldr r1, =sub_8038538
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8038528

	thumb_func_start sub_8038538
sub_8038538: @ 8038538
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r5, =0x0201c000
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0x1
	beq _0803856C
	cmp r1, 0x1
	bgt _08038554
	cmp r1, 0
	beq _0803855A
	b _080385DC
	.pool
_08038554:
	cmp r1, 0x2
	beq _080385C8
	b _080385DC
_0803855A:
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	strh r1, [r3, 0x30]
	ldr r0, =0x00000281
	strh r0, [r3, 0x32]
	strh r1, [r3, 0x34]
	movs r0, 0x1
	strh r0, [r3, 0x36]
_0803856C:
	ldrh r0, [r3, 0x36]
	subs r0, 0x1
	strh r0, [r3, 0x36]
	lsls r0, 16
	cmp r0, 0
	bne _080385DC
	movs r0, 0x2
	strh r0, [r3, 0x36]
	movs r4, 0x30
	ldrsh r2, [r3, r4]
	movs r0, 0x34
	ldrsh r1, [r3, r0]
	lsls r1, 5
	adds r2, r1
	movs r4, 0x32
	ldrsh r0, [r3, r4]
	subs r0, r1
	movs r4, 0x3D
	lsls r0, 1
	adds r0, r5
	lsls r2, 1
	adds r2, r5
	movs r1, 0x1C
_0803859A:
	strh r4, [r2]
	strh r4, [r0]
	adds r0, 0x4
	adds r2, 0x4
	subs r1, 0x2
	cmp r1, 0
	bge _0803859A
	ldrh r0, [r3, 0x34]
	adds r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _080385DC
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	movs r0, 0x20
	strh r0, [r3, 0x30]
	b _080385DC
	.pool
_080385C8:
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _080385DC
	ldr r0, =sub_8036760
	bl SetMainCallback2
_080385DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038538

	thumb_func_start CreateNPCTrainerParty
CreateNPCTrainerParty: @ 80385E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	str r0, [sp, 0x10]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x14]
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	mov r9, r0
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	bne _08038610
	movs r0, 0
	b _080389E2
_08038610:
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	ldr r1, =0x043f0908
	ands r0, r1
	ldr r1, [sp, 0x14]
	lsls r1, 2
	str r1, [sp, 0x20]
	cmp r0, 0x8
	beq _08038624
	b _080389D2
_08038624:
	cmp r2, 0x1
	bne _0803862C
	bl ZeroEnemyPartyMons
_0803862C:
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _08038668
	ldr r0, =gTrainers
	ldr r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	adds r1, r2, r3
	lsls r1, 3
	adds r1, r0
	adds r2, r1, 0
	adds r2, 0x20
	ldrb r1, [r2]
	movs r4, 0x3
	str r4, [sp, 0x1C]
	adds r4, r0, 0
	cmp r1, 0x3
	bhi _0803867C
	adds r2, r1, 0
	str r2, [sp, 0x1C]
	b _0803867C
	.pool
_08038668:
	ldr r1, =gTrainers
	ldr r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	adds r0, r2, r3
	lsls r0, 3
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	str r0, [sp, 0x1C]
	adds r4, r1, 0
_0803867C:
	movs r0, 0
	str r0, [sp, 0x18]
	b _080389B4
	.pool
_08038688:
	ldr r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	adds r0, r2, r3
	lsls r0, 3
	adds r1, r0, r4
	ldrb r0, [r1, 0x18]
	cmp r0, 0x1
	bne _0803869E
	movs r0, 0x80
	mov r10, r0
	b _080386B0
_0803869E:
	ldrb r1, [r1, 0x2]
	movs r0, 0x80
	ands r0, r1
	movs r1, 0x88
	mov r10, r1
	cmp r0, 0
	beq _080386B0
	movs r2, 0x78
	mov r10, r2
_080386B0:
	movs r6, 0
	ldr r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	adds r0, r2, r3
	lsls r0, 3
	adds r1, r4, 0x4
	adds r0, r1
	ldrb r0, [r0]
	ldr r3, [sp, 0x18]
	adds r3, 0x1
	str r3, [sp, 0x24]
	cmp r0, 0xFF
	beq _080386E6
	adds r3, r1, 0
_080386CC:
	ldr r0, [sp, 0x14]
	adds r1, r2, r0
	lsls r1, 3
	adds r0, r6, r1
	adds r0, r3
	ldrb r0, [r0]
	add r9, r0
	adds r6, 0x1
	adds r1, r6, r1
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _080386CC
_080386E6:
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x14]
	adds r0, r1, r2
	lsls r1, r0, 3
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08038794
	cmp r0, 0x1
	bgt _08038700
	cmp r0, 0
	beq _0803870E
	b _080389AC
_08038700:
	cmp r0, 0x2
	bne _08038706
	b _08038854
_08038706:
	cmp r0, 0x3
	bne _0803870C
	b _080388E8
_0803870C:
	b _080389AC
_0803870E:
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r4, [r0]
	movs r6, 0
	ldr r3, [sp, 0x18]
	lsls r2, r3, 3
	adds r0, r2, r4
	ldrh r1, [r0, 0x4]
	movs r0, 0xB
	muls r0, r1
	ldr r1, =gSpeciesNames
	adds r0, r1
	ldrb r0, [r0]
	adds r5, r2, 0
	cmp r0, 0xFF
	beq _08038750
	adds r3, r1, 0
	movs r7, 0xB
_08038734:
	adds r0, r2, r4
	ldrh r0, [r0, 0x4]
	adds r1, r0, 0
	muls r1, r7
	adds r0, r6, r1
	adds r0, r3
	ldrb r0, [r0]
	add r9, r0
	adds r6, 0x1
	adds r1, r6, r1
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _08038734
_08038750:
	mov r2, r9
	lsls r0, r2, 8
	add r10, r0
	adds r4, r5, r4
	ldrh r1, [r4]
	lsls r0, r1, 5
	subs r0, r1
	movs r1, 0xFF
	bl __divsi3
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, [sp, 0x18]
	movs r1, 0x64
	adds r0, r3, 0
	muls r0, r1
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldrh r1, [r4, 0x4]
	ldrb r2, [r4, 0x2]
	movs r3, 0x1
	str r3, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	movs r3, 0x2
	str r3, [sp, 0x8]
	movs r3, 0
	str r3, [sp, 0xC]
	adds r3, r6, 0
	bl CreateMon
	b _080389AC
	.pool
_08038794:
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r7, [r0]
	movs r6, 0
	ldr r4, [sp, 0x18]
	lsls r2, r4, 4
	adds r0, r2, r7
	ldrh r1, [r0, 0x4]
	movs r0, 0xB
	muls r0, r1
	ldr r1, =gSpeciesNames
	adds r0, r1
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, 0xFF
	beq _080387D6
	adds r3, r1, 0
	movs r4, 0xB
_080387BA:
	adds r0, r2, r7
	ldrh r0, [r0, 0x4]
	adds r1, r0, 0
	muls r1, r4
	adds r0, r6, r1
	adds r0, r3
	ldrb r0, [r0]
	add r9, r0
	adds r6, 0x1
	adds r1, r6, r1
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _080387BA
_080387D6:
	mov r2, r9
	lsls r0, r2, 8
	add r10, r0
	mov r3, r8
	adds r4, r3, r7
	ldrh r1, [r4]
	lsls r0, r1, 5
	subs r0, r1
	movs r1, 0xFF
	bl __divsi3
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [sp, 0x18]
	movs r1, 0x64
	adds r5, r0, 0
	muls r5, r1
	ldr r2, [sp, 0x10]
	adds r5, r2, r5
	ldrh r1, [r4, 0x4]
	ldrb r2, [r4, 0x2]
	movs r0, 0x1
	str r0, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	adds r0, r5, 0
	adds r3, r6, 0
	bl CreateMon
	movs r6, 0
	mov r0, r8
	adds r0, 0x6
	adds r4, r7, r0
_08038820:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r5, 0
	adds r2, r4, 0
	bl SetMonData
	adds r1, r6, 0
	adds r1, 0x11
	ldrh r0, [r4]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	ldr r0, =gBattleMoves + 0x4 @ PP offset
	adds r2, r0
	adds r0, r5, 0
	bl SetMonData
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08038820
	b _080389AC
	.pool
_08038854:
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r4, [r0]
	movs r6, 0
	ldr r0, [sp, 0x18]
	lsls r2, r0, 3
	adds r0, r2, r4
	ldrh r1, [r0, 0x4]
	movs r0, 0xB
	muls r0, r1
	ldr r1, =gSpeciesNames
	adds r0, r1
	ldrb r0, [r0]
	adds r5, r2, 0
	cmp r0, 0xFF
	beq _08038896
	adds r3, r1, 0
	movs r7, 0xB
_0803887A:
	adds r0, r2, r4
	ldrh r0, [r0, 0x4]
	adds r1, r0, 0
	muls r1, r7
	adds r0, r6, r1
	adds r0, r3
	ldrb r0, [r0]
	add r9, r0
	adds r6, 0x1
	adds r1, r6, r1
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0803887A
_08038896:
	mov r2, r9
	lsls r0, r2, 8
	add r10, r0
	adds r5, r4
	ldrh r1, [r5]
	lsls r0, r1, 5
	subs r0, r1
	movs r1, 0xFF
	bl __divsi3
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, [sp, 0x18]
	movs r0, 0x64
	adds r4, r3, 0
	muls r4, r0
	ldr r1, [sp, 0x10]
	adds r4, r1, r4
	ldrh r1, [r5, 0x4]
	ldrb r2, [r5, 0x2]
	movs r0, 0x1
	str r0, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	adds r0, r4, 0
	adds r3, r6, 0
	bl CreateMon
	adds r5, 0x6
	adds r0, r4, 0
	movs r1, 0xC
	adds r2, r5, 0
	bl SetMonData
	b _080389AC
	.pool
_080388E8:
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r7, [r0]
	movs r6, 0
	ldr r4, [sp, 0x18]
	lsls r2, r4, 4
	adds r0, r2, r7
	ldrh r1, [r0, 0x4]
	movs r0, 0xB
	muls r0, r1
	ldr r1, =gSpeciesNames
	adds r0, r1
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, 0xFF
	beq _0803892A
	adds r3, r1, 0
	movs r4, 0xB
_0803890E:
	adds r0, r2, r7
	ldrh r0, [r0, 0x4]
	adds r1, r0, 0
	muls r1, r4
	adds r0, r6, r1
	adds r0, r3
	ldrb r0, [r0]
	add r9, r0
	adds r6, 0x1
	adds r1, r6, r1
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0803890E
_0803892A:
	mov r2, r9
	lsls r0, r2, 8
	add r10, r0
	mov r3, r8
	adds r5, r3, r7
	ldrh r1, [r5]
	lsls r0, r1, 5
	subs r0, r1
	movs r1, 0xFF
	bl __divsi3
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [sp, 0x18]
	movs r1, 0x64
	adds r4, r0, 0
	muls r4, r1
	ldr r2, [sp, 0x10]
	adds r4, r2, r4
	ldrh r1, [r5, 0x4]
	ldrb r2, [r5, 0x2]
	movs r0, 0x1
	str r0, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	adds r0, r4, 0
	adds r3, r6, 0
	bl CreateMon
	adds r5, 0x6
	adds r0, r4, 0
	movs r1, 0xC
	adds r2, r5, 0
	bl SetMonData
	movs r6, 0
	adds r5, r4, 0
	mov r0, r8
	adds r0, 0x8
	adds r4, r7, r0
_08038982:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r5, 0
	adds r2, r4, 0
	bl SetMonData
	adds r1, r6, 0
	adds r1, 0x11
	ldrh r0, [r4]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	ldr r0, =gBattleMoves + 0x4 @ PP offset
	adds r2, r0
	adds r0, r5, 0
	bl SetMonData
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08038982
_080389AC:
	ldr r4, [sp, 0x24]
	str r4, [sp, 0x18]
	ldr r4, =gTrainers
	ldr r0, [sp, 0x18]
_080389B4:
	ldr r1, [sp, 0x1C]
	cmp r0, r1
	bge _080389BC
	b _08038688
_080389BC:
	ldr r2, =gBattleTypeFlags
	ldr r1, =gTrainers
	ldr r3, [sp, 0x20]
	ldr r4, [sp, 0x14]
	adds r0, r3, r4
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x18]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080389D2:
	ldr r0, =gTrainers
	ldr r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	adds r1, r2, r3
	lsls r1, 3
	adds r1, r0
	adds r1, 0x20
	ldrb r0, [r1]
_080389E2:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CreateNPCTrainerParty

	thumb_func_start sub_8038A04
sub_8038A04: @ 8038A04
	push {lr}
	ldr r0, =0x04000006
	ldrh r0, [r0]
	subs r0, 0x6F
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x30
	bhi _08038A1E
	movs r1, 0x98
	lsls r1, 8
	movs r0, 0x8
	bl SetGpuReg
_08038A1E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038A04

	thumb_func_start vblank_cb_08078BB4
vblank_cb_08078BB4: @ 8038A28
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x013f0102
	ands r0, r1
	cmp r0, 0
	bne _08038A3A
	bl Random
_08038A3A:
	ldr r0, =gUnknown_02022E14
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, =gUnknown_02022E16
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =gUnknown_02022E18
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1A
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1C
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1E
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, =gUnknown_02022E20
	ldrh r1, [r0]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, =gUnknown_02022E22
	ldrh r1, [r0]
	movs r0, 0x1E
	bl SetGpuReg
	ldr r0, =gUnknown_02022E24
	ldrh r1, [r0]
	movs r0, 0x40
	bl SetGpuReg
	ldr r0, =gUnknown_02022E26
	ldrh r1, [r0]
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =gUnknown_02022E28
	ldrh r1, [r0]
	movs r0, 0x42
	bl SetGpuReg
	ldr r0, =gUnknown_02022E2A
	ldrh r1, [r0]
	movs r0, 0x46
	bl SetGpuReg
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl sub_80BA0A8
	pop {r0}
	bx r0
	.pool
	thumb_func_end vblank_cb_08078BB4

	thumb_func_start nullsub_17
nullsub_17: @ 8038B00
	bx lr
	thumb_func_end nullsub_17

	thumb_func_start sub_8038B04
sub_8038B04: @ 8038B04
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08038B24
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	lsrs r0, 8
	ldrh r1, [r5, 0x30]
	adds r0, r1
	strh r0, [r5, 0x20]
	b _08038B36
_08038B24:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	asrs r0, 8
	ldrh r1, [r5, 0x30]
	subs r1, r0
	strh r1, [r5, 0x20]
_08038B36:
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r5, 0x32]
	adds r0, r1
	strh r0, [r5, 0x32]
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08038B6A
	ldr r4, =0x00002710
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r5, 0
	bl FreeSpriteOamMatrix
	adds r0, r5, 0
	bl DestroySprite
_08038B6A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038B04

	thumb_func_start sub_8038B74
sub_8038B74: @ 8038B74
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =sub_8038B04
	str r0, [r4, 0x1C]
	movs r0, 0x68
	bl PlaySE
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038B74

	thumb_func_start sub_8038B94
sub_8038B94: @ 8038B94
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r2, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08038C04
	ldr r1, =gLinkPlayers
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x18]
	cmp r0, 0x1
	beq _08038BF0
	cmp r0, 0x1
	bgt _08038BE8
	cmp r0, 0
	beq _08038C04
	b _08038C0C
	.pool
_08038BE8:
	cmp r0, 0x2
	beq _08038C04
	cmp r0, 0x3
	bne _08038C0C
_08038BF0:
	ldr r0, =gEnemyParty
	str r0, [sp, 0x4]
	ldr r1, =gPlayerParty
	str r1, [sp, 0x8]
	b _08038C0C
	.pool
_08038C04:
	ldr r2, =gPlayerParty
	str r2, [sp, 0x4]
	ldr r3, =gEnemyParty
	str r3, [sp, 0x8]
_08038C0C:
	movs r7, 0
	movs r0, 0
	mov r8, r0
	ldr r1, [sp]
	lsls r1, 2
	str r1, [sp, 0xC]
	movs r2, 0xCE
	lsls r2, 1
	mov r10, r2
	mov r9, r0
_08038C20:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	ldr r3, [sp, 0x4]
	adds r4, r3, r4
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	adds r1, r0, 0
	cmp r5, 0
	beq _08038C90
	cmp r5, r10
	beq _08038C64
	cmp r6, 0
	beq _08038C64
	cmp r1, 0
	bne _08038C64
	movs r0, 0x1
	mov r2, r9
	lsls r0, r2
	orrs r7, r0
_08038C64:
	cmp r5, 0
	beq _08038C90
	cmp r6, 0
	beq _08038C7C
	cmp r5, r10
	beq _08038C74
	cmp r1, 0
	beq _08038C7C
_08038C74:
	movs r0, 0x2
	mov r3, r9
	lsls r0, r3
	orrs r7, r0
_08038C7C:
	cmp r5, 0
	beq _08038C90
	cmp r5, r10
	beq _08038C90
	cmp r6, 0
	bne _08038C90
	movs r0, 0x3
	mov r1, r9
	lsls r0, r1
	orrs r7, r0
_08038C90:
	movs r2, 0x2
	add r9, r2
	movs r3, 0x1
	add r8, r3
	mov r0, r8
	cmp r0, 0x5
	ble _08038C20
	ldr r1, =gTasks
	ldr r2, [sp, 0xC]
	ldr r3, [sp]
	adds r0, r2, r3
	lsls r0, 3
	adds r0, r1
	strh r7, [r0, 0xE]
	movs r7, 0
	movs r0, 0
	mov r8, r0
	movs r1, 0xCE
	lsls r1, 1
	mov r10, r1
	mov r9, r0
_08038CBA:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	ldr r2, [sp, 0x8]
	adds r4, r2, r4
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	adds r1, r0, 0
	cmp r5, 0
	beq _08038D2A
	cmp r5, r10
	beq _08038CFE
	cmp r6, 0
	beq _08038CFE
	cmp r1, 0
	bne _08038CFE
	movs r0, 0x1
	mov r3, r9
	lsls r0, r3
	orrs r7, r0
_08038CFE:
	cmp r5, 0
	beq _08038D2A
	cmp r6, 0
	beq _08038D16
	cmp r5, r10
	beq _08038D0E
	cmp r1, 0
	beq _08038D16
_08038D0E:
	movs r0, 0x2
	mov r1, r9
	lsls r0, r1
	orrs r7, r0
_08038D16:
	cmp r5, 0
	beq _08038D2A
	cmp r5, r10
	beq _08038D2A
	cmp r6, 0
	bne _08038D2A
	movs r0, 0x3
	mov r2, r9
	lsls r0, r2
	orrs r7, r0
_08038D2A:
	movs r3, 0x2
	add r9, r3
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x5
	ble _08038CBA
	ldr r1, =gTasks
	ldr r2, [sp, 0xC]
	ldr r3, [sp]
	adds r0, r2, r3
	lsls r0, 3
	adds r0, r1
	strh r7, [r0, 0x10]
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038B94

	thumb_func_start sub_8038D64
sub_8038D64: @ 8038D64
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x21
	negs r2, r2
	ands r1, r2
	str r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _08038DAC
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
	bl sub_8057028
	bl dp11_free
	bl sub_805F094
	b _08038EB6
	.pool
_08038DAC:
	str r0, [sp]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	mov r0, sp
	bl CpuSet
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r4, =0x00005051
	movs r0, 0x44
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	ldr r1, =gUnknown_02022E24
	movs r0, 0xF0
	strh r0, [r1]
	ldr r0, =gUnknown_02022E26
	strh r4, [r0]
	bl dp12_8087EA4
	ldr r0, =gUnknown_02038C28
	movs r3, 0xF0
	movs r1, 0xF0
	lsls r1, 3
	adds r2, r0, r1
	movs r1, 0x4F
_08038DFE:
	strh r3, [r0]
	strh r3, [r2]
	adds r2, 0x2
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08038DFE
	movs r1, 0x50
	ldr r0, =gUnknown_02038C28
	ldr r3, =0x0000ff10
	movs r4, 0x82
	lsls r4, 4
	adds r2, r0, r4
	adds r0, 0xA0
_08038E1A:
	strh r3, [r0]
	strh r3, [r2]
	adds r2, 0x2
	adds r0, 0x2
	adds r1, 0x1
	cmp r1, 0x9F
	ble _08038E1A
	bl ResetPaletteFade
	ldr r0, =gUnknown_02022E14
	movs r4, 0
	strh r4, [r0]
	ldr r0, =gUnknown_02022E16
	strh r4, [r0]
	ldr r0, =gUnknown_02022E18
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r4, [r0]
	ldr r0, =gUnknown_02022E20
	strh r4, [r0]
	ldr r0, =gUnknown_02022E22
	strh r4, [r0]
	bl c2_berry_program_update_menu
	ldr r0, =gUnknown_08C004E0
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	bl sub_803570C
	bl ResetSpriteData
	bl ResetTasks
	bl sub_8036154
	movs r0, 0x4A
	movs r1, 0x37
	bl SetGpuReg
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, =vblank_cb_08078BB4
	bl SetVBlankCallback
	ldr r0, =task00_0800F6FC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x87
	lsls r2, 1
	strh r2, [r1, 0xA]
	movs r2, 0x5A
	strh r2, [r1, 0xC]
	movs r2, 0x1
	strh r2, [r1, 0x12]
	bl sub_8038B94
	ldr r0, =sub_8038F14
	bl SetMainCallback2
	ldr r0, =gBattleCommunication
	strb r4, [r0]
_08038EB6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038D64

	thumb_func_start sub_8038F14
sub_8038F14: @ 8038F14
	push {lr}
	bl sub_8038F34
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_8038F14

	thumb_func_start sub_8038F34
sub_8038F34: @ 8038F34
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r0, =gBattleCommunication
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x9
	bls _08038F44
	b _080391C6
_08038F44:
	lsls r0, r1, 2
	ldr r1, =_08038F58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08038F58:
	.4byte _08038F80
	.4byte _08038FA0
	.4byte _08038FC2
	.4byte _080390C8
	.4byte _08039100
	.4byte _08039118
	.4byte _0803912C
	.4byte _0803914C
	.4byte _08039166
	.4byte _08039184
_08038F80:
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r1, =gBattleCommunication
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	b _08039174
	.pool
_08038FA0:
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	strb r0, [r4, 0x1]
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08038FB0
	b _080391C6
_08038FB0:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0803910C
_08038FC2:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08038FD0
	b _080391C6
_08038FD0:
	bl sub_8185FAC
	ldr r2, =gMain
	ldr r1, =0x00000439
	adds r2, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	movs r3, 0x2
	cmp r0, 0
	beq _08038FFC
	movs r3, 0x4
_08038FFC:
	movs r4, 0
	ldr r6, =gSaveBlock2Ptr
	cmp r4, r3
	bge _08039022
	ldr r1, =gLinkPlayers
	ldrb r0, [r1]
	cmp r0, 0x3
	bne _08039022
	movs r5, 0xFF
	adds r2, r1, 0
_08039010:
	adds r2, 0x1C
	adds r4, 0x1
	cmp r4, r3
	bge _08039022
	ldrh r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x3
	beq _08039010
_08039022:
	ldr r0, [r6]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080390AC
	cmp r4, r3
	bne _080390AC
	ldr r0, =0x000008d2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08039074
	bl FreeAllWindowBuffers
	ldr r0, =sub_80392A8
	bl SetMainCallback2
	b _080391C6
	.pool
_08039074:
	ldr r2, =gMain
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08039090
	ldr r0, [r2, 0x8]
	b _080390B0
	.pool
_08039090:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08039172
	ldr r0, =sub_80B3AF8
	movs r1, 0x5
	bl CreateTask
	b _08039172
	.pool
_080390AC:
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
_080390B0:
	bl SetMainCallback2
	bl sub_8057028
	bl dp11_free
	bl sub_805F094
	b _080391C6
	.pool
_080390C8:
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	add r0, sp, 0x4
	bl CpuSet
	movs r4, 0
_080390DA:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80363C4
	adds r4, 0x1
	cmp r4, 0x1
	ble _080390DA
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _08039172
	.pool
_08039100:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080391C6
_0803910C:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _080391C6
	.pool
_08039118:
	ldr r0, =sub_80B3AF8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080391C6
	b _08039172
	.pool
_0803912C:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080391C6
	bl sub_800ADF8
	ldr r0, =gUnknown_0824978D
	movs r1, 0
	bl battle_show_message_maybe
	b _08039172
	.pool
_0803914C:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080391C6
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080391C6
	b _08039172
_08039166:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _08039172
	bl sub_800AC34
_08039172:
	ldr r1, =gBattleCommunication
_08039174:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080391C6
	.pool
_08039184:
	ldr r2, =gMain
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	adds r3, r2, 0
	cmp r0, 0
	beq _080391A6
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080391A6
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080391C6
_080391A6:
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3, 0x8]
	bl SetMainCallback2
	bl sub_8057028
	bl dp11_free
	bl sub_805F094
_080391C6:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8038F34

	thumb_func_start sub_80391E0
sub_80391E0: @ 80391E0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	cmp r1, 0x6
	bhi _080392A0
	lsls r0, r1, 2
	ldr r1, =_08039200
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08039200:
	.4byte _0803921C
	.4byte _08039230
	.4byte _08039244
	.4byte _08039258
	.4byte _0803926C
	.4byte _08039280
	.4byte _08039294
_0803921C:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 30
	lsrs r0, 30
	b _080392A0
	.pool
_08039230:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 30
	b _080392A0
	.pool
_08039244:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldrh r0, [r1]
	lsls r0, 23
	lsrs r0, 27
	b _080392A0
	.pool
_08039258:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 29
	lsrs r0, 30
	b _080392A0
	.pool
_0803926C:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 28
	lsrs r0, 31
	b _080392A0
	.pool
_08039280:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 26
	lsrs r0, 30
	b _080392A0
	.pool
_08039294:
	ldr r0, =gUnknown_0831AA08
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	lsls r0, 8
	lsrs r0, 22
_080392A0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80391E0

	thumb_func_start sub_80392A8
sub_80392A8: @ 80392A8
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r4, 0
	str r4, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	add r0, sp, 0x4
	bl CpuSet
	bl ResetPaletteFade
	ldr r0, =gUnknown_02022E14
	strh r4, [r0]
	ldr r0, =gUnknown_02022E16
	strh r4, [r0]
	ldr r0, =gUnknown_02022E18
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r4, [r0]
	ldr r0, =gUnknown_02022E20
	strh r4, [r0]
	ldr r0, =gUnknown_02022E22
	strh r4, [r0]
	bl c2_berry_program_update_menu
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	bl sub_803570C
_080392FE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80363C4
	adds r4, 0x1
	cmp r4, 0x1
	ble _080392FE
	bl ResetSpriteData
	bl ResetTasks
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, =vblank_cb_08078BB4
	bl SetVBlankCallback
	ldr r0, =sub_803937C
	bl SetMainCallback2
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gBattleCommunication
	strb r4, [r0]
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80392A8

	thumb_func_start sub_803937C
sub_803937C: @ 803937C
	push {lr}
	bl sub_803939C
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_803937C

	thumb_func_start sub_803939C
sub_803939C: @ 803939C
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gBattleCommunication
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0xC
	bls _080393AC
	b _0803975E
_080393AC:
	lsls r0, r1, 2
	ldr r1, =_080393C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080393C0:
	.4byte _080393F4
	.4byte _08039414
	.4byte _08039450
	.4byte _08039470
	.4byte _0803949C
	.4byte _080394D8
	.4byte _0803957C
	.4byte _08039704
	.4byte _080395CC
	.4byte _08039610
	.4byte _08039678
	.4byte _080396A8
	.4byte _08039704
_080393F4:
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_08039414:
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08039434
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08039434
	ldr r0, =sub_80B3AF8
	movs r1, 0x5
	bl CreateTask
_08039434:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_08039450:
	ldr r0, =sub_80B3AF8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0803945E
	b _0803975E
_0803945E:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_08039470:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0803947E
	b _0803975E
_0803947E:
	ldr r0, =gUnknown_085CD28F
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_0803949C:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080394AC
	b _0803975E
_080394AC:
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldr r4, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl sub_8056B74
	b _080396EA
	.pool
_080394D8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08039500
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _080394EC
	b _0803975E
_080394EC:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0
	b _0803951E
	.pool
_08039500:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08039526
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08039510
	b _0803975E
_08039510:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0x1
_0803951E:
	strb r0, [r4, 0x1]
	bl sub_8056B74
	b _0803975E
_08039526:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08039560
	movs r0, 0x5
	bl PlaySE
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08039540
	b _080396EA
_08039540:
	str r5, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	bl sub_8185338
	strb r0, [r4, 0x1]
	movs r0, 0xA
	strb r0, [r4]
	b _0803975E
	.pool
_08039560:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0803956A
	b _0803975E
_0803956A:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_0803957C:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0803958A
	b _0803975E
_0803958A:
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080395B4
	bl sub_800ADF8
	ldr r0, =gUnknown_0824978D
	movs r1, 0
	bl battle_show_message_maybe
_080395B4:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_080395CC:
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	strb r0, [r4, 0x1]
	lsls r0, 24
	cmp r0, 0
	beq _080395DA
	b _0803975E
_080395DA:
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080395F6
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080395F6
	bl sub_800AC34
_080395F6:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	b _0803975C
	.pool
_08039610:
	ldr r2, =gMain
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	adds r3, r2, 0
	cmp r0, 0
	beq _08039634
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _08039634
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08039634
	b _0803975E
_08039634:
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08039650
	b _0803975E
_08039650:
	ldr r0, [r3, 0x8]
	bl SetMainCallback2
	bl sub_8057028
	bl dp11_free
	bl sub_805F094
	b _0803975E
	.pool
_08039678:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	bne _080396A0
	movs r0, 0x37
	bl PlaySE
	ldr r0, =gUnknown_085CD2CB
_08039686:
	bl StrCpyDecodeToDisplayedStringBattle
	ldr r0, =gDisplayedStringBattle
	movs r1, 0
	bl battle_show_message_maybe
	movs r0, 0x80
	strb r0, [r4, 0x1]
	b _080396EA
	.pool
_080396A0:
	ldr r0, =gUnknown_08242481
	b _08039686
	.pool
_080396A8:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803975E
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0803975E
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	strb r0, [r4, 0x1]
	lsls r0, 24
	cmp r0, 0
	bne _0803975E
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080396EA
	bl sub_800ADF8
	ldr r0, =gUnknown_0824978D
	movs r1, 0
	bl battle_show_message_maybe
_080396EA:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0803975E
	.pool
_08039704:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	bne _0803975E
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08039744
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803975E
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	b _0803974A
	.pool
_08039744:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
_0803974A:
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gBattleCommunication
	movs r0, 0x20
	strb r0, [r1, 0x1]
	movs r0, 0x8
_0803975C:
	strb r0, [r1]
_0803975E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803939C

	thumb_func_start shedinja_something
shedinja_something: @ 803976C
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r5, sp, 0xC
	movs r0, 0x1
	strb r0, [r5]
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldr r1, =0x0000012f
	cmp r0, r1
	bne _080397B4
	adds r0, r4, 0
	movs r1, 0x3
	bl GetMonData
	ldrb r1, [r5]
	cmp r0, r1
	beq _080397B4
	adds r0, r4, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r1, =gUnknown_0831ACA0
	mov r0, sp
	bl StringCompareWithoutExtCtrlCodes
	cmp r0, 0
	bne _080397B4
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetMonData
_080397B4:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end shedinja_something

	thumb_func_start sub_80397C4
sub_80397C4: @ 80397C4
	ldr r2, =gUnknown_0831ABA0
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 3
	bx lr
	.pool
	thumb_func_end sub_80397C4

	thumb_func_start oac_poke_opponent
oac_poke_opponent: @ 80397DC
	push {lr}
	sub sp, 0x4
	ldr r1, =sub_803980C
	str r1, [r0, 0x1C]
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	movs r0, 0x80
	lsls r0, 10
	ldr r1, =0x00002108
	str r1, [sp]
	movs r1, 0
	movs r2, 0xA
	movs r3, 0xA
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end oac_poke_opponent

	thumb_func_start sub_803980C
sub_803980C: @ 803980C
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_020243FC
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0803982C
	ldrh r0, [r2, 0x24]
	adds r0, 0x2
	strh r0, [r2, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0803982C
	ldr r0, =sub_8039838
	str r0, [r2, 0x1C]
_0803982C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803980C

	thumb_func_start sub_8039838
sub_8039838: @ 8039838
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08039880
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8076918
	ldr r1, =gHealthBoxesIds
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r0, =sub_8039894
	str r0, [r4, 0x1C]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	movs r0, 0x80
	lsls r0, 10
	ldr r1, =0x00002108
	str r1, [sp]
	movs r1, 0
	movs r2, 0xA
	movs r3, 0
	bl BeginNormalPaletteFade
_08039880:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039838

	thumb_func_start sub_8039894
sub_8039894: @ 8039894
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080398B0
	ldrh r1, [r2, 0x32]
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_806ECEC
_080398B0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039894

	thumb_func_start nullsub_18
nullsub_18: @ 80398B8
	bx lr
	thumb_func_end nullsub_18

	thumb_func_start sub_80398BC
sub_80398BC: @ 80398BC
	movs r1, 0x6
	strh r1, [r0, 0x34]
	movs r1, 0x1
	strh r1, [r0, 0x36]
	ldr r1, =sub_80398D0
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_80398BC

	thumb_func_start sub_80398D0
sub_80398D0: @ 80398D0
	push {r4,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x36]
	subs r0, 0x1
	strh r0, [r3, 0x36]
	lsls r0, 16
	cmp r0, 0
	bne _08039924
	movs r0, 0x8
	strh r0, [r3, 0x36]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r4, 0x5
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x34]
	subs r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	bne _08039924
	ldrb r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	mov r1, r12
	strb r0, [r1]
	ldr r0, =nullsub_18
	str r0, [r3, 0x1C]
	ldr r0, =gUnknown_02022F88
	str r2, [r0]
_08039924:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80398D0

	thumb_func_start sub_8039934
sub_8039934: @ 8039934
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	ldrh r0, [r0, 0x2E]
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _0803995C
	adds r4, r0, 0
	b _08039960
	.pool
_0803995C:
	mov r0, r9
	ldrh r4, [r0, 0x32]
_08039960:
	ldr r1, =gBattlePartyID
	lsls r0, r6, 1
	adds r5, r0, r1
	ldrh r0, [r5]
	movs r1, 0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r7, =gEnemyParty
	adds r0, r7
	movs r1, 0
	bl GetMonData
	cmp r4, 0xC9
	bne _080399E4
	ldrh r0, [r5]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	movs r1, 0
	bl GetMonData
	adds r2, r0, 0
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r2
	lsrs r0, 18
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r2
	lsrs r1, 12
	orrs r0, r1
	movs r1, 0xC0
	lsls r1, 2
	ands r1, r2
	lsrs r1, 6
	orrs r0, r1
	movs r1, 0x3
	ands r1, r2
	orrs r0, r1
	movs r1, 0x1C
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _080399D0
	movs r0, 0xC9
	b _080399DA
	.pool
_080399D0:
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
_080399DA:
	ldr r1, =gUnknown_08300D38
	lsls r0, 2
	b _08039A1C
	.pool
_080399E4:
	ldr r0, =0x00000181
	cmp r4, r0
	bne _08039A08
	ldr r0, =gUnknown_08525F78
	ldr r1, =gBattleMonForms
	adds r1, r6, r1
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	b _08039A20
	.pool
_08039A08:
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bls _08039A18
	ldr r0, =gUnknown_08300D38
	b _08039A1E
	.pool
_08039A18:
	ldr r1, =gUnknown_08300D38
	lsls r0, r4, 2
_08039A1C:
	adds r0, r1
_08039A1E:
	ldrb r0, [r0, 0x1]
_08039A20:
	lsrs r1, r0, 3
	movs r0, 0x8
	subs r0, r1
	mov r1, r9
	strh r0, [r1, 0x34]
	movs r0, 0x1
	strh r0, [r1, 0x36]
	ldr r0, =sub_8039A48
	str r0, [r1, 0x1C]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039934

	thumb_func_start sub_8039A48
sub_8039A48: @ 8039A48
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x36]
	subs r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	cmp r0, 0
	bne _08039AC8
	movs r0, 0x2
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x26]
	adds r0, 0x8
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	subs r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	cmp r0, 0
	bge _08039A7C
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	b _08039AC8
_08039A7C:
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankIdentity
	ldr r1, =gBattleDecompressedSprites
	ldr r1, [r1]
	lsls r0, 24
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r2, =gBattleMonForms
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 11
	ldr r1, [r1]
	adds r1, r0
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	lsls r0, 8
	adds r1, r0
	movs r2, 0
	movs r0, 0xFF
_08039AAE:
	strb r2, [r1]
	adds r1, 0x1
	subs r0, 0x1
	cmp r0, 0
	bge _08039AAE
	ldr r0, =gBattleMonForms
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r4, 0
	bl StartSpriteAnim
_08039AC8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039A48

	thumb_func_start sub_8039AD8
sub_8039AD8: @ 8039AD8
	movs r1, 0x8
	strh r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x3E
	ldrb r1, [r1]
	lsls r1, 29
	lsrs r1, 31
	strh r1, [r0, 0x36]
	ldr r1, =sub_8039AF4
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8039AD8

	thumb_func_start sub_8039AF4
sub_8039AF4: @ 8039AF4
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x34]
	subs r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	cmp r0, 0
	bne _08039B26
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r0, 0x8
	strh r0, [r3, 0x34]
_08039B26:
	pop {r0}
	bx r0
	thumb_func_end sub_8039AF4

	thumb_func_start sub_8039B2C
sub_8039B2C: @ 8039B2C
	movs r1, 0x3E
	adds r1, r0
	mov r12, r1
	movs r1, 0x1
	ldrh r2, [r0, 0x36]
	ands r2, r1
	lsls r2, 2
	mov r1, r12
	ldrb r3, [r1]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	movs r1, 0
	strh r1, [r0, 0x36]
	ldr r1, =nullsub_18
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8039B2C

	thumb_func_start sub_8039B58
sub_8039B58: @ 8039B58
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08039BA0
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08039B80
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _08039B94
_08039B80:
	ldrh r0, [r4, 0x32]
	bl sub_806F0D4
	lsls r0, 24
	cmp r0, 0
	beq _08039B94
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
_08039B94:
	ldrh r1, [r4, 0x32]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_806ECEC
_08039BA0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039B58

	thumb_func_start sub_8039BB4
sub_8039BB4: @ 8039BB4
	ldr r1, =oac_poke_ally_
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8039BB4

	thumb_func_start oac_poke_ally_
oac_poke_ally_: @ 8039BC0
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_020243FC
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08039BE4
	ldrh r0, [r2, 0x24]
	subs r0, 0x2
	strh r0, [r2, 0x24]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _08039BE4
	ldr r0, =nullsub_19
	str r0, [r2, 0x1C]
	strh r1, [r2, 0x30]
_08039BE4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end oac_poke_ally_

	thumb_func_start sub_8039BF0
sub_8039BF0: @ 8039BF0
	ldr r1, =nullsub_19
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8039BF0

	thumb_func_start nullsub_19
nullsub_19: @ 8039BFC
	bx lr
	thumb_func_end nullsub_19

	thumb_func_start sub_8039C00
sub_8039C00: @ 8039C00
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_020243FC
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08039C20
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
_08039C20:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039C00

	thumb_func_start dp11b_obj_instanciate
dp11b_obj_instanciate: @ 8039C28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	cmp r1, 0
	beq _08039C64
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r2, r4, 1
	adds r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	b _08039C76
	.pool
_08039C64:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r2, r4, 1
	adds r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
_08039C76:
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	bne _08039D2C
	ldr r0, =objc_dp11b_pingpong
	bl CreateInvisibleSpriteWithCallback
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	cmp r0, 0x1
	bne _08039CD0
	ldr r0, =gHealthBoxesIds
	adds r0, r4, r0
	ldrb r7, [r0]
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	adds r1, r6, r4
	lsls r1, 2
	adds r0, r1, r0
	strb r5, [r0, 0x2]
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x80
	b _08039CFE
	.pool
_08039CD0:
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r7, [r0]
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	adds r1, r6, r4
	lsls r1, 2
	adds r0, r1, r0
	strb r5, [r0, 0x3]
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0xC0
_08039CFE:
	strh r1, [r0, 0x2E]
	adds r4, r2, 0
	adds r1, r3, r5
	lsls r1, 2
	adds r1, r4
	mov r2, r9
	lsls r0, r2, 24
	asrs r0, 24
	movs r2, 0
	strh r0, [r1, 0x30]
	mov r3, r10
	lsls r0, r3, 24
	asrs r0, 24
	strh r0, [r1, 0x32]
	strh r7, [r1, 0x34]
	mov r0, r8
	strh r0, [r1, 0x36]
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x24]
	strh r2, [r0, 0x26]
_08039D2C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp11b_obj_instanciate

	thumb_func_start dp11b_obj_free
dp11b_obj_free: @ 8039D48
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	bne _08039D9C
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r5, r0, 2
	adds r3, r5, r1
	ldrb r1, [r3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08039DEA
	ldr r2, =gSprites
	ldrb r1, [r3, 0x2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x34]
	lsls r1, 24
	lsrs r4, r1, 24
	bl DestroySprite
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	b _08039DD6
	.pool
_08039D9C:
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r5, r0, 2
	adds r3, r5, r1
	ldrb r1, [r3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08039DEA
	ldr r2, =gSprites
	ldrb r1, [r3, 0x3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x34]
	lsls r1, 24
	lsrs r4, r1, 24
	bl DestroySprite
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
_08039DD6:
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x24]
	strh r0, [r1, 0x26]
_08039DEA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp11b_obj_free

	thumb_func_start objc_dp11b_pingpong
objc_dp11b_pingpong: @ 8039DF8
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08039E10
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	b _08039E14
_08039E10:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
_08039E14:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	ldr r2, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r4, 0x32]
	adds r0, r2
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x2E]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end objc_dp11b_pingpong

	thumb_func_start sub_8039E44
sub_8039E44: @ 8039E44
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08039E5C
	ldrh r1, [r2, 0x32]
	adds r0, r2, 0
	bl sub_806EEB4
_08039E5C:
	pop {r0}
	bx r0
	thumb_func_end sub_8039E44

	thumb_func_start sub_8039E60
sub_8039E60: @ 8039E60
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8039E9C
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08039E7A
	ldr r0, =nullsub_19
	str r0, [r4, 0x1C]
_08039E7A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039E60

	thumb_func_start sub_8039E84
sub_8039E84: @ 8039E84
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, =sub_8039E60
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039E84

	thumb_func_start sub_8039E9C
sub_8039E9C: @ 8039E9C
	push {lr}
	adds r2, r0, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _08039EBE
	ldr r1, =gUnknown_0831ACE0
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r2, 0
	adds r0, 0x28
	strb r1, [r0]
_08039EBE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039E9C

	thumb_func_start nullsub_20
nullsub_20: @ 8039EC8
	bx lr
	thumb_func_end nullsub_20

	thumb_func_start sub_8039ECC
sub_8039ECC: @ 8039ECC
	push {lr}
	bl sub_8039F40
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x1]
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_8012FAC
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039ECC

	thumb_func_start sub_8039EF0
sub_8039EF0: @ 8039EF0
	push {r4,r5,lr}
	ldr r0, =gBattleMainFunc
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039F2A
	ldr r5, =gBattleBankFunc
	adds r4, r1, 0
_08039F0C:
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08039F0C
_08039F2A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039EF0

	thumb_func_start sub_8039F40
sub_8039F40: @ 8039F40
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	bl sub_803D580
	bl sub_803D6A0
	movs r2, 0
	movs r3, 0
	ldr r0, =gUnknown_02024260
	mov r10, r0
	ldr r1, =gUnknown_02024258
	mov r9, r1
	ldr r0, =gUnknown_02024250
	mov r8, r0
	ldr r1, =gLastUsedMovesByBanks
	mov r12, r1
	ldr r5, =gDisableStructs
	movs r4, 0
	ldr r7, =gUnknown_02024240
	ldr r6, =gUnknown_02024268
_08039F70:
	ldr r0, =gStatuses3
	adds r0, r4, r0
	str r3, [r0]
	movs r1, 0
_08039F78:
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, 0x1B
	bls _08039F78
	movs r0, 0x2
	strb r0, [r5, 0x16]
	ldr r1, =gUnknown_02024284
	adds r0, r2, r1
	strb r3, [r0]
	mov r0, r12
	strh r3, [r0]
	mov r1, r8
	strh r3, [r1]
	mov r0, r9
	strh r3, [r0]
	mov r1, r10
	strh r3, [r1]
	ldr r0, =gUnknown_02024270
	adds r1, r2, r0
	movs r0, 0xFF
	strb r0, [r1]
	strh r3, [r6]
	strh r3, [r7]
	ldr r1, =gBattleResources
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r4
	str r3, [r0]
	ldr r1, =gUnknown_02024230
	adds r0, r4, r1
	str r3, [r0]
	movs r0, 0x2
	add r10, r0
	add r9, r0
	add r8, r0
	add r12, r0
	adds r5, 0x1C
	adds r4, 0x4
	adds r7, 0x2
	adds r6, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	ble _08039F70
	movs r5, 0
	ldr r3, =gSideTimers
	ldr r4, =gSideAffecting
	movs r2, 0x1
_08039FD8:
	strh r5, [r4]
	movs r1, 0
_08039FDC:
	adds r0, r3, r1
	strb r5, [r0]
	adds r1, 0x1
	cmp r1, 0xB
	bls _08039FDC
	adds r3, 0xC
	adds r4, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08039FD8
	movs r1, 0
	ldr r2, =gBankAttacker
	strb r1, [r2]
	ldr r0, =gBankTarget
	strb r1, [r0]
	ldr r2, =gBattleWeather
	strh r1, [r2]
	ldr r1, =gUnknown_020243D0
	movs r2, 0
	movs r3, 0
_0803A004:
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, 0x1
	cmp r2, 0x2B
	bls _0803A004
	ldr r2, =gHitMarker
	movs r0, 0
	str r0, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	bne _0803A090
	movs r0, 0x2
	ands r1, r0
	cmp r1, 0
	bne _0803A0AE
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x15]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0803A0AE
	movs r0, 0x80
	b _0803A0AC
	.pool
_0803A090:
	ldr r0, =0x02000002
	ands r1, r0
	cmp r1, 0
	bne _0803A0AE
	bl sub_8185FB8
	lsls r0, 24
	cmp r0, 0
	beq _0803A0AE
	ldr r1, =gHitMarker
	ldr r0, [r1]
	movs r1, 0x80
	orrs r0, r1
	ldr r2, =gHitMarker
_0803A0AC:
	str r0, [r2]
_0803A0AE:
	ldr r3, =gBattleScripting
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsls r0, 30
	lsrs r0, 31
	movs r1, 0
	strb r0, [r3, 0x1D]
	ldr r0, =gUnknown_02024212
	strb r1, [r0]
	ldr r0, =gBattleOutcome
	strb r1, [r0]
	ldr r0, =gBattleExecBuffer
	str r1, [r0]
	ldr r0, =gUnknown_0202432E
	movs r2, 0
	strh r1, [r0]
	ldr r1, =gBattleResources
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r0, 0x20
	strb r2, [r0]
	ldr r0, [r1]
	ldr r0, [r0, 0xC]
	adds r0, 0x20
	strb r2, [r0]
	ldr r5, =gUnknown_0202432C
	ldr r6, =gBattleMoveDamage
	ldr r7, =gUnknown_020243FC
	ldr r0, =gUnknown_03005D54
	mov r8, r0
	ldr r1, =gAbsentBankFlags
	mov r9, r1
	ldr r2, =gEnemyParty
	mov r10, r2
	ldr r1, =gBattleCommunication
	movs r2, 0
	adds r0, r1, 0x7
_0803A0FA:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0803A0FA
	movs r4, 0
	strh r4, [r5]
	movs r0, 0
	str r0, [r6]
	strh r0, [r7]
	strb r4, [r3, 0x18]
	strb r4, [r3, 0x19]
	mov r0, r8
	strb r4, [r0]
	mov r1, r9
	strb r4, [r1]
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, 0x6C
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, 0x79
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, 0x7A
	strb r4, [r0]
	mov r0, r10
	movs r1, 0xB
	bl GetMonData
	ldr r6, [r5]
	adds r6, 0x7C
	ldr r2, =gBaseStats
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x8]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =0x000004fb
	bl __divsi3
	strb r0, [r6]
	ldr r0, [r5]
	adds r0, 0x7B
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r5]
	strb r4, [r0, 0x12]
	ldr r0, [r5]
	adds r0, 0x4A
	movs r1, 0x1
	strb r1, [r0]
	movs r2, 0
	movs r1, 0
	adds r6, r5, 0
_0803A16A:
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0x98
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xB8
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xC8
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xD0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xE0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xE8
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xF0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, 0xF8
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _0803A16A
	movs r2, 0
	ldr r4, =gBattleStruct
	movs r3, 0xA5
	lsls r3, 2
	movs r1, 0x6
_0803A1BA:
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, r3
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _0803A1BA
	ldr r0, [r6]
	adds r0, 0xDF
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, 0x92
	strb r1, [r0]
	bl Random
	ldr r1, =gUnknown_02024330
	strh r0, [r1]
	ldr r1, =gBattleResults
	movs r2, 0
	movs r3, 0
_0803A1E4:
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, 0x1
	cmp r2, 0x43
	bls _0803A1E4
	ldr r0, =gEnemyParty
	bl IsMonShiny
	ldr r3, =gBattleResults
	movs r1, 0x1
	ands r1, r0
	lsls r1, 6
	ldrb r2, [r3, 0x5]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	movs r1, 0xA8
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x000002a1
	adds r0, r2
	strb r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8039F40

	thumb_func_start sub_803A284
sub_803A284: @ 803A284
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, =gDisableStructs
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r1, sp
	adds r0, r4
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, =gBattleMoves
	ldr r3, =gCurrentMove
	ldrh r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	mov r12, r4
	mov r9, r5
	ldr r6, =gStatuses3
	mov r10, r6
	cmp r0, 0x7F
	beq _0803A35C
	movs r5, 0
	mov r6, r9
	movs r4, 0x58
	ldr r2, =gBattleMons
	adds r2, 0x18
	movs r1, 0x6
_0803A2D4:
	ldrb r0, [r6]
	muls r0, r4
	adds r0, r5, r0
	adds r0, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x7
	ble _0803A2D4
	movs r5, 0
	ldr r7, =gNoOfAllBanks
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803A348
	ldr r0, =gBattleMons + 0x50
	mov r8, r0
	ldr r4, =gDisableStructs
	ldr r3, =gStatuses3
_0803A2F6:
	movs r0, 0x58
	muls r0, r5
	mov r1, r8
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 19
	ands r0, r1
	cmp r0, 0
	beq _0803A31A
	ldrb r0, [r4, 0x14]
	ldr r6, =gActiveBank
	ldrb r6, [r6]
	cmp r0, r6
	bne _0803A31A
	ldr r0, =0xfbffffff
	ands r1, r0
	str r1, [r2]
_0803A31A:
	ldr r1, [r3]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _0803A33A
	ldrb r0, [r4, 0x15]
	ldr r7, =gActiveBank
	ldrb r7, [r7]
	cmp r0, r7
	bne _0803A33A
	movs r0, 0x19
	negs r0, r0
	ands r1, r0
	str r1, [r3]
	movs r0, 0
	strb r0, [r4, 0x15]
_0803A33A:
	adds r4, 0x1C
	adds r3, 0x4
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A2F6
_0803A348:
	ldr r1, =gCurrentMove
	ldrh r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r2, =gBattleMoves
	adds r1, r2
	ldrb r0, [r1]
	cmp r0, 0x7F
	bne _0803A414
_0803A35C:
	mov r3, r9
	ldrb r1, [r3]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	ldr r0, =gBattleMons
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0x15100007
	ands r0, r1
	str r0, [r2]
	ldrb r1, [r3]
	lsls r1, 2
	add r1, r10
	ldr r0, [r1]
	ldr r2, =0x0003043f
	ands r0, r2
	str r0, [r1]
	movs r5, 0
	ldr r6, =gNoOfAllBanks
	ldrb r6, [r6]
	cmp r5, r6
	bge _0803A430
	mov r7, r9
	movs r6, 0
_0803A390:
	ldrb r0, [r7]
	bl GetBankSide
	adds r4, r0, 0
	lsls r0, r5, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0803A3D0
	ldr r1, =gStatuses3
	lsls r0, r5, 2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _0803A3D0
	ldr r0, =gDisableStructs
	adds r0, r6, r0
	ldrb r0, [r0, 0x15]
	ldrb r3, [r7]
	cmp r0, r3
	bne _0803A3D0
	movs r0, 0x19
	negs r0, r0
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	str r1, [r2]
_0803A3D0:
	adds r6, 0x1C
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A390
	ldr r6, =gDisableStructs
	mov r12, r6
	ldr r7, =gActiveBank
	mov r9, r7
	b _0803A430
	.pool
_0803A414:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gBattleMons
	adds r1, 0x50
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 2
	add r0, r10
	str r1, [r0]
_0803A430:
	movs r5, 0
	ldr r3, =gBattleStruct
	mov r8, r3
	ldr r6, =gUnknown_020244AC
	mov r10, r6
	ldr r7, =gNoOfAllBanks
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803A490
	ldr r3, =gBattleMons + 0x50
	ldr r7, =gBitTable
	ldr r6, =gActiveBank
_0803A448:
	movs r0, 0x58
	muls r0, r5
	adds r4, r0, r3
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r7
	ldr r0, [r0]
	lsls r2, r0, 16
	ldr r1, [r4]
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _0803A466
	bics r1, r2
	str r1, [r4]
_0803A466:
	ldr r1, [r4]
	movs r0, 0xE0
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0803A486
	mov r2, r8
	ldr r0, [r2]
	adds r0, r5, r0
	ldrb r0, [r0, 0x14]
	ldrb r2, [r6]
	cmp r0, r2
	bne _0803A486
	ldr r0, =0xffff1fff
	ands r1, r0
	str r1, [r4]
_0803A486:
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A448
_0803A490:
	mov r1, r9
	ldrb r0, [r1]
	add r0, r10
	movs r1, 0
	strb r1, [r0]
	mov r2, r9
	ldrb r0, [r2]
	ldr r3, =gUnknown_020244B0
	adds r0, r3
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r6, r12
	adds r1, r0, r6
	movs r5, 0
	movs r2, 0
_0803A4B4:
	adds r0, r1, r5
	strb r2, [r0]
	adds r5, 0x1
	cmp r5, 0x1B
	bls _0803A4B4
	ldr r7, =gCurrentMove
	ldrh r0, [r7]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, =gBattleMoves
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x7F
	bne _0803A540
	mov r2, r9
	ldrb r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	mov r1, sp
	ldrb r1, [r1, 0xA]
	strb r1, [r0, 0xA]
	ldrb r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	mov r1, sp
	ldrb r1, [r1, 0x15]
	strb r1, [r0, 0x15]
	ldrb r0, [r2]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	add r1, r12
	mov r0, sp
	ldrb r2, [r0, 0xF]
	lsls r2, 28
	movs r4, 0xF
	lsrs r2, 28
	ldrb r3, [r1, 0xF]
	movs r0, 0x10
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0xF]
	mov r3, r9
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	mov r1, sp
	ldrb r1, [r1, 0xF]
	lsrs r1, 4
	lsls r1, 4
	ldrb r2, [r0, 0xF]
	ands r4, r2
	orrs r4, r1
	strb r4, [r0, 0xF]
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	mov r1, sp
	ldrb r1, [r1, 0x14]
	strb r1, [r0, 0x14]
_0803A540:
	movs r0, 0
	ldr r6, =gBattleMoveFlags
	strb r0, [r6]
	mov r7, r9
	ldrb r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	movs r4, 0
	movs r1, 0x2
	strb r1, [r0, 0x16]
	ldrb r0, [r7]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	add r1, r12
	mov r0, sp
	ldrb r0, [r0, 0x18]
	movs r2, 0x2
	ands r2, r0
	ldrb r3, [r1, 0x18]
	movs r0, 0x3
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x18]
	ldrb r0, [r7]
	lsls r0, 1
	ldr r1, =gLastUsedMovesByBanks
	adds r0, r1
	movs r2, 0
	strh r4, [r0]
	ldrb r0, [r7]
	lsls r0, 1
	ldr r3, =gUnknown_02024250
	adds r0, r3
	strh r4, [r0]
	ldrb r0, [r7]
	lsls r0, 1
	ldr r6, =gUnknown_02024258
	adds r0, r6
	strh r4, [r0]
	ldrb r0, [r7]
	lsls r0, 1
	ldr r7, =gUnknown_02024260
	adds r0, r7
	strh r4, [r0]
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	ldr r3, =gUnknown_02024240
	adds r0, r3
	strh r4, [r0]
	ldrb r0, [r1]
	ldr r6, =gUnknown_02024270
	adds r0, r6
	movs r1, 0xFF
	strb r1, [r0]
	mov r7, r9
	ldrb r0, [r7]
	mov r3, r8
	ldr r1, [r3]
	lsls r0, 1
	adds r0, r1
	adds r0, 0x98
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 1
	adds r0, r1
	adds r0, 0x99
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE0
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE1
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE2
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE3
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE4
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE5
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE6
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE7
	strb r2, [r0]
	ldr r1, [r3]
	adds r1, 0x92
	ldrb r0, [r7]
	lsls r0, 2
	ldr r6, =gBitTable
	adds r0, r6
	ldr r2, [r0]
	ldrb r0, [r1]
	bics r0, r2
	strb r0, [r1]
	movs r5, 0
	ldr r7, =gNoOfAllBanks
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803A6B4
	mov r3, r9
	mov r7, r8
	movs r6, 0
_0803A656:
	ldrb r0, [r3]
	cmp r5, r0
	beq _0803A68C
	lsls r0, r5, 24
	lsrs r0, 24
	str r3, [sp, 0x1C]
	bl GetBankSide
	adds r4, r0, 0
	ldr r3, [sp, 0x1C]
	ldrb r0, [r3]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	ldr r3, [sp, 0x1C]
	cmp r4, r0
	beq _0803A68C
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, r1, r0
	adds r0, 0x98
	strb r6, [r0]
	ldr r0, [r7]
	adds r1, r0
	adds r1, 0x99
	strb r6, [r1]
_0803A68C:
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, 1
	lsls r2, r5, 3
	adds r0, r2
	adds r0, r1
	adds r0, 0xE0
	strb r6, [r0]
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, 1
	adds r0, r2
	adds r0, r1
	adds r0, 0xE1
	strb r6, [r0]
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A656
_0803A6B4:
	mov r1, r9
	ldrb r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC8
	movs r2, 0
	strb r2, [r0]
	mov r3, r9
	ldrb r0, [r3]
	mov r6, r8
	ldr r1, [r6]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC9
	strb r2, [r0]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldrb r0, [r3]
	lsls r0, 2
	adds r1, r0
	movs r2, 0
	str r2, [r1]
	ldr r0, =gCurrentMove
	strh r2, [r0]
	ldr r0, [r6]
	adds r0, 0xDA
	movs r1, 0xFF
	strb r1, [r0]
	ldrb r0, [r3]
	bl ClearBankMoveHistory
	mov r7, r9
	ldrb r0, [r7]
	bl ClearBankAbilityHistory
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803A284

	thumb_func_start sub_803A75C
sub_803A75C: @ 803A75C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r5, 0
	ldr r6, =gBattleMons
	ldr r0, =gStatuses3
	mov r8, r0
	ldr r1, =gBattleStruct
	mov r12, r1
	ldr r2, =gUnknown_020244AC
	mov r9, r2
	ldr r3, =gUnknown_020244B0
	mov r10, r3
	ldr r7, =gProtectStructs
	ldr r4, =gActiveBank
	movs r3, 0x58
	adds r2, r6, 0
	adds r2, 0x18
	movs r1, 0x6
_0803A788:
	ldrb r0, [r4]
	muls r0, r3
	adds r0, r5, r0
	adds r0, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x7
	ble _0803A788
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r2, r6, 0
	adds r2, 0x50
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 2
	add r0, r8
	str r1, [r0]
	movs r5, 0
	ldr r6, =gNoOfAllBanks
	ldrb r6, [r6]
	cmp r5, r6
	bge _0803A830
	adds r3, r2, 0
	movs r4, 0
	ldr r0, =gBitTable
	mov r8, r0
_0803A7C6:
	ldr r1, [r3]
	movs r0, 0x80
	lsls r0, 19
	ands r0, r1
	cmp r0, 0
	beq _0803A7E6
	ldr r2, =gDisableStructs
	adds r0, r4, r2
	ldrb r0, [r0, 0x14]
	ldr r6, =gActiveBank
	ldrb r6, [r6]
	cmp r0, r6
	bne _0803A7E6
	ldr r0, =0xfbffffff
	ands r1, r0
	str r1, [r3]
_0803A7E6:
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	lsls r0, 2
	add r0, r8
	ldr r0, [r0]
	lsls r2, r0, 16
	ldr r1, [r3]
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _0803A800
	bics r1, r2
	str r1, [r3]
_0803A800:
	ldr r1, [r3]
	movs r0, 0xE0
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0803A822
	mov r2, r12
	ldr r0, [r2]
	adds r0, r5, r0
	ldrb r0, [r0, 0x14]
	ldr r6, =gActiveBank
	ldrb r6, [r6]
	cmp r0, r6
	bne _0803A822
	ldr r0, =0xffff1fff
	ands r1, r0
	str r1, [r3]
_0803A822:
	adds r3, 0x58
	adds r4, 0x1C
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A7C6
_0803A830:
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	add r0, r9
	movs r1, 0
	strb r1, [r0]
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	add r0, r10
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r3, =gDisableStructs
	adds r1, r0, r3
	movs r5, 0
	movs r2, 0
_0803A852:
	adds r0, r1, r5
	strb r2, [r0]
	adds r5, 0x1
	cmp r5, 0x1B
	bls _0803A852
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	mov r9, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r6]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r3, 0x3
	negs r3, r3
	mov r8, r3
	mov r0, r8
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r6]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r6, 0x5
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	subs r3, 0x6
	mov r10, r3
	mov r0, r10
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r5, 0x21
	negs r5, r5
	adds r0, r5, 0
	ands r0, r2
	strb r0, [r1]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r4, 0x41
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1, 0x1]
	mov r0, r9
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1, 0x1]
	mov r0, r8
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1, 0x1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1, 0x1]
	movs r0, 0x19
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x1]
	ands r5, r1
	strb r5, [r0, 0x1]
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x1]
	ands r4, r1
	strb r4, [r0, 0x1]
	ldrb r0, [r2]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x1]
	ands r3, r1
	strb r3, [r0, 0x1]
	ldrb r0, [r2]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x2]
	mov r3, r9
	ands r3, r1
	strb r3, [r0, 0x2]
	ldrb r0, [r2]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x2]
	mov r2, r8
	ands r2, r1
	strb r2, [r0, 0x2]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x2]
	ands r6, r1
	strb r6, [r0, 0x2]
	ldrb r0, [r3]
	lsls r0, 4
	adds r0, r7
	ldrb r1, [r0, 0x2]
	mov r6, r10
	ands r6, r1
	strb r6, [r0, 0x2]
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, =gDisableStructs
	adds r0, r1
	movs r2, 0
	movs r1, 0x2
	strb r1, [r0, 0x16]
	ldrb r0, [r3]
	lsls r0, 1
	ldr r3, =gLastUsedMovesByBanks
	adds r0, r3
	movs r3, 0
	strh r2, [r0]
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 1
	ldr r1, =gUnknown_02024250
	adds r0, r1
	strh r2, [r0]
	ldrb r0, [r6]
	lsls r0, 1
	ldr r6, =gUnknown_02024258
	adds r0, r6
	strh r2, [r0]
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	lsls r0, 1
	ldr r6, =gUnknown_02024260
	adds r0, r6
	strh r2, [r0]
	ldrb r0, [r1]
	lsls r0, 1
	ldr r1, =gUnknown_02024240
	adds r0, r1
	strh r2, [r0]
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldr r6, =gUnknown_02024270
	adds r0, r6
	movs r1, 0xFF
	strb r1, [r0]
	ldrb r0, [r2]
	mov r2, r12
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC8
	strb r3, [r0]
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC9
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0x98
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0x99
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE0
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE1
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE2
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE3
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE4
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE5
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE6
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	adds r0, 0xE7
	strb r3, [r0]
	ldr r1, [r2]
	adds r1, 0x92
	ldrb r0, [r6]
	lsls r0, 2
	ldr r2, =gBitTable
	adds r0, r2
	ldr r2, [r0]
	ldrb r0, [r1]
	bics r0, r2
	strb r0, [r1]
	movs r5, 0
	ldr r3, =gNoOfAllBanks
	ldrb r3, [r3]
	cmp r5, r3
	bge _0803AB02
	adds r3, r6, 0
	mov r7, r12
	movs r6, 0
_0803AAA4:
	ldrb r0, [r3]
	cmp r5, r0
	beq _0803AADA
	lsls r0, r5, 24
	lsrs r0, 24
	str r3, [sp]
	bl GetBankSide
	adds r4, r0, 0
	ldr r3, [sp]
	ldrb r0, [r3]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	ldr r3, [sp]
	cmp r4, r0
	beq _0803AADA
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, r1, r0
	adds r0, 0x98
	strb r6, [r0]
	ldr r0, [r7]
	adds r1, r0
	adds r1, 0x99
	strb r6, [r1]
_0803AADA:
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, 1
	lsls r2, r5, 3
	adds r0, r2
	adds r0, r1
	adds r0, 0xE0
	strb r6, [r0]
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, 1
	adds r0, r2
	adds r0, r1
	adds r0, 0xE1
	strb r6, [r0]
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803AAA4
_0803AB02:
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r1, r0
	movs r0, 0
	str r0, [r1]
	ldr r4, =gBattleMons
	ldrb r0, [r2]
	movs r3, 0x58
	adds r2, r0, 0
	muls r2, r3
	b _0803AB6C
	.pool
_0803AB6C:
	adds r2, r4
	ldr r5, =gBaseStats
	ldrh r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x6]
	adds r2, 0x21
	strb r0, [r2]
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r3
	adds r1, r4
	ldrh r2, [r1]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x7]
	adds r1, 0x22
	strb r0, [r1]
	ldrb r0, [r6]
	bl ClearBankMoveHistory
	ldrb r0, [r6]
	bl ClearBankAbilityHistory
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803A75C

	thumb_func_start bc_8012FAC
bc_8012FAC: @ 803ABC0
	push {r4,r5,lr}
	ldr r5, =gBattleCommunication
	ldrb r0, [r5]
	cmp r0, 0
	beq _0803ABD4
	cmp r0, 0x1
	beq _0803ABF8
	b _0803AC2E
	.pool
_0803ABD4:
	ldr r4, =gActiveBank
	ldrb r0, [r5, 0x1]
	strb r0, [r4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x00_a_b_0
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0803AC2E
	.pool
_0803ABF8:
	ldr r0, =gBattleExecBuffer
	ldr r2, [r0]
	cmp r2, 0
	bne _0803AC2E
	ldrb r0, [r5, 0x1]
	adds r0, 0x1
	strb r0, [r5, 0x1]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _0803AC2C
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_load_battlefield
	str r0, [r1]
	b _0803AC2E
	.pool
_0803AC2C:
	strb r2, [r5]
_0803AC2E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end bc_8012FAC

	thumb_func_start bc_load_battlefield
bc_load_battlefield: @ 803AC34
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r5, [r0]
	cmp r5, 0
	bne _0803AC64
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gUnknown_02022FF0
	ldrb r1, [r0]
	movs r0, 0
	bl dp01_build_cmdbuf_x2E_a
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803AC84
	str r0, [r1]
	ldr r0, =gBattleCommunication
	strb r5, [r0]
	strb r5, [r0, 0x1]
_0803AC64:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_load_battlefield

	thumb_func_start sub_803AC84
sub_803AC84: @ 803AC84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleExecBuffer
	ldr r1, [r0]
	cmp r1, 0
	beq _0803AC98
	b _0803AF4E
_0803AC98:
	ldr r2, =gActiveBank
	strb r1, [r2]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r1, r0
	bcc _0803ACA6
	b _0803AF48
_0803ACA6:
	movs r7, 0x58
	ldr r0, =gBattleMons
	mov r8, r0
	mov r9, r2
	movs r1, 0x48
	add r1, r8
	mov r10, r1
_0803ACB4:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0803ACFC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803ACFC
	ldrb r0, [r4]
	muls r0, r7
	mov r2, r8
	adds r3, r0, r2
	movs r2, 0
	movs r1, 0
_0803ACDA:
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x57
	bls _0803ACDA
	b _0803ADCA
	.pool
_0803ACFC:
	mov r1, r9
	ldrb r0, [r1]
	muls r0, r7
	mov r2, r8
	adds r3, r0, r2
	movs r2, 0
	ldr r6, =gBaseStats
	ldr r5, =gBattleBufferB
	ldr r4, =gActiveBank
_0803AD0E:
	adds r0, r3, r2
	ldrb r1, [r4]
	lsls r1, 9
	adds r1, 0x4
	adds r1, r2, r1
	adds r1, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x57
	bls _0803AD0E
	mov r1, r9
	ldrb r0, [r1]
	adds r2, r0, 0
	muls r2, r7
	add r2, r8
	ldrh r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x6]
	adds r2, 0x21
	strb r0, [r2]
	mov r2, r9
	ldrb r0, [r2]
	adds r2, r0, 0
	muls r2, r7
	add r2, r8
	ldrh r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x7]
	adds r2, 0x22
	strb r0, [r2]
	mov r1, r9
	ldrb r0, [r1]
	adds r1, r0, 0
	muls r1, r7
	add r1, r8
	ldrh r0, [r1]
	ldrb r1, [r1, 0x17]
	lsrs r1, 7
	bl GetAbilityBySpecies
	mov r2, r9
	ldrb r1, [r2]
	muls r1, r7
	add r1, r8
	adds r1, 0x20
	strb r0, [r1]
	ldrb r0, [r2]
	bl GetBankSide
	ldr r1, =gBattleStruct
	lsls r0, 24
	lsrs r0, 23
	adds r0, 0xA8
	ldr r1, [r1]
	adds r1, r0
	mov r2, r9
	ldrb r0, [r2]
	muls r0, r7
	add r0, r8
	ldrh r0, [r0, 0x28]
	strh r0, [r1]
	movs r2, 0
	ldr r4, =gActiveBank
	movs r5, 0x58
	ldr r1, =gBattleMons + 0x18
	adds r6, r4, 0
	movs r0, 0x18
	negs r0, r0
	adds r0, r1
	mov r12, r0
	movs r3, 0x6
_0803ADAA:
	ldrb r0, [r4]
	muls r0, r5
	adds r0, r2, r0
	adds r0, r1
	strb r3, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _0803ADAA
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r7
	mov r0, r12
	adds r0, 0x50
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_0803ADCA:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	bne _0803ADE4
	movs r0, 0
	bl dp01_build_cmdbuf_x07_7_7_7
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803ADE4:
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0803AE60
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803AE0A
	movs r0, 0
	bl dp01_build_cmdbuf_x07_7_7_7
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803AE0A:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803AEC0
	ldr r0, [r5]
	ldr r1, =0x063f0902
	ands r0, r1
	cmp r0, 0
	bne _0803AEC0
	ldrb r0, [r4]
	muls r0, r7
	add r0, r8
	ldrh r0, [r0]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r4]
	muls r1, r7
	add r1, r10
	ldr r2, [r1]
	movs r1, 0x2
	bl SetPokedexFlag
	b _0803AEC0
	.pool
_0803AE60:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803AEC0
	ldr r0, [r5]
	ldr r1, =0x063f0902
	ands r0, r1
	cmp r0, 0
	bne _0803AE96
	ldrb r0, [r4]
	muls r0, r7
	add r0, r8
	ldrh r0, [r0]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r4]
	muls r1, r7
	add r1, r10
	ldr r2, [r1]
	movs r1, 0x2
	bl SetPokedexFlag
_0803AE96:
	movs r0, 0
	bl dp01_build_cmdbuf_x04_4_4_4
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, =gBattleResults
	strh r0, [r1, 0x20]
_0803AEC0:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0803AEF6
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _0803AEEA
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0803AEF6
_0803AEEA:
	movs r0, 0
	bl dp01_build_cmdbuf_x07_7_7_7
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803AEF6:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0803AF20
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0803AF20
	movs r0, 0
	bl dp01_build_cmdbuf_x07_7_7_7
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803AF20:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0803AF32
	bl sub_81A56B4
_0803AF32:
	mov r1, r9
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcs _0803AF48
	b _0803ACB4
_0803AF48:
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_801333C
	str r0, [r1]
_0803AF4E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803AC84

	thumb_func_start bc_801333C
bc_801333C: @ 803AF80
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x30
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0803AF92
	b _0803B10C
_0803AF92:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0803AFA0
	b _0803B0AC
_0803AFA0:
	movs r7, 0
	add r0, sp, 0x4
	mov r8, r0
	mov r6, r8
	mov r5, sp
_0803AFAA:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _0803AFD0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _0803AFE8
_0803AFD0:
	ldr r0, =0x0000ffff
	strh r0, [r5]
	movs r0, 0
	b _0803AFFA
	.pool
_0803AFE8:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
_0803AFFA:
	str r0, [r6]
	adds r6, 0x8
	adds r5, 0x8
	adds r7, 0x1
	cmp r7, 0x5
	ble _0803AFAA
	movs r0, 0x1
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	mov r1, sp
	movs r2, 0x80
	bl dp01_build_cmdbuf_x30_TODO
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	movs r7, 0
	mov r6, r8
	mov r5, sp
_0803B026:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _0803B04C
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _0803B060
_0803B04C:
	ldr r0, =0x0000ffff
	strh r0, [r5]
	movs r0, 0
	b _0803B072
	.pool
_0803B060:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
_0803B072:
	str r0, [r6]
	adds r6, 0x8
	adds r5, 0x8
	adds r7, 0x1
	cmp r7, 0x5
	ble _0803B026
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	mov r1, sp
	movs r2, 0x80
	bl dp01_build_cmdbuf_x30_TODO
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_battle_begin_message
	b _0803B10A
	.pool
_0803B0AC:
	movs r7, 0
	add r6, sp, 0x4
	mov r5, sp
_0803B0B2:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _0803B0D8
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _0803B0E8
_0803B0D8:
	ldr r0, =0x0000ffff
	strh r0, [r5]
	movs r0, 0
	b _0803B0FA
	.pool
_0803B0E8:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
_0803B0FA:
	str r0, [r6]
	adds r6, 0x8
	adds r5, 0x8
	adds r7, 0x1
	cmp r7, 0x5
	ble _0803B0B2
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_8013568
_0803B10A:
	str r0, [r1]
_0803B10C:
	add sp, 0x30
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_801333C

	thumb_func_start bc_battle_begin_message
bc_battle_begin_message: @ 803B120
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803B142
	movs r0, 0x1
	bl GetBankByPlayerAI
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, 0
	bl b_std_message
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B180
	str r0, [r1]
_0803B142:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_battle_begin_message

	thumb_func_start bc_8013568
bc_8013568: @ 803B158
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803B170
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B3CC
	str r0, [r1]
	movs r0, 0
	movs r1, 0
	bl b_std_message
_0803B170:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_8013568

	thumb_func_start sub_803B180
sub_803B180: @ 803B180
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803B1D0
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r2
	cmp r0, 0
	beq _0803B1B8
	movs r0, 0x80
	lsls r0, 18
	ands r0, r2
	cmp r0, 0
	beq _0803B1B8
	movs r1, 0x80
	lsls r1, 24
	ands r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0803B1BA
	.pool
_0803B1B8:
	movs r0, 0x1
_0803B1BA:
	bl GetBankByPlayerAI
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	bl b_std_message
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B25C
	str r0, [r1]
_0803B1D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B180

	thumb_func_start sub_803B1DC
sub_803B1DC: @ 803B1DC
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	beq _0803B1FC
	movs r0, 0x80
	lsls r0, 18
	ands r0, r1
	cmp r0, 0
	beq _0803B1FC
	movs r5, 0x2
	cmp r1, 0
	bge _0803B1FE
_0803B1FC:
	movs r5, 0x3
_0803B1FE:
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803B23A
	adds r4, r1, 0
_0803B20E:
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _0803B228
	movs r0, 0
	bl dp01_build_cmdbuf_x2F_2F_2F_2F
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803B228:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B20E
_0803B23A:
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_801362C
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B1DC

	thumb_func_start sub_803B25C
sub_803B25C: @ 803B25C
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r2
	cmp r0, 0
	beq _0803B298
	movs r0, 0x80
	lsls r0, 18
	ands r0, r2
	cmp r0, 0
	beq _0803B298
	movs r1, 0x80
	lsls r1, 24
	ands r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r5, r0, 31
	b _0803B29A
	.pool
_0803B288:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B1DC
	b _0803B2F0
	.pool
_0803B298:
	movs r5, 0x1
_0803B29A:
	ldr r0, =gBattleExecBuffer
	ldr r2, [r0]
	cmp r2, 0
	bne _0803B2F2
	ldr r0, =gActiveBank
	strb r2, [r0]
	ldr r1, =gNoOfAllBanks
	adds r4, r0, 0
	ldrb r1, [r1]
	cmp r2, r1
	bcs _0803B2EC
	adds r6, r4, 0
_0803B2B2:
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _0803B2D8
	movs r0, 0
	bl dp01_build_cmdbuf_x2F_2F_2F_2F
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00008040
	ands r0, r1
	cmp r0, 0
	bne _0803B288
_0803B2D8:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gActiveBank
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B2B2
_0803B2EC:
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_801362C
_0803B2F0:
	str r0, [r1]
_0803B2F2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B25C

	thumb_func_start bc_801362C
bc_801362C: @ 803B314
	push {r4-r7,lr}
	ldr r0, =gBattleExecBuffer
	ldr r1, [r0]
	cmp r1, 0
	bne _0803B384
	ldr r2, =gActiveBank
	strb r1, [r2]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0803B37E
	adds r4, r2, 0
	ldr r6, =gBattleMons
	movs r5, 0x58
	adds r7, r6, 0
	adds r7, 0x48
_0803B334:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803B36C
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x063f0902
	ands r0, r1
	cmp r0, 0
	bne _0803B36C
	ldrb r0, [r4]
	muls r0, r5
	adds r0, r6
	ldrh r0, [r0]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r4]
	muls r1, r5
	adds r1, r7
	ldr r2, [r1]
	movs r1, 0x2
	bl SetPokedexFlag
_0803B36C:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B334
_0803B37E:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B3CC
	str r0, [r1]
_0803B384:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_801362C

	thumb_func_start sub_803B3AC
sub_803B3AC: @ 803B3AC
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803B3BC
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B3CC
	str r0, [r1]
_0803B3BC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B3AC

	thumb_func_start sub_803B3CC
sub_803B3CC: @ 803B3CC
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803B418
	ldr r1, =gBattleTypeFlags
	ldr r2, [r1]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r2
	cmp r0, 0
	beq _0803B3F4
	movs r0, 0x80
	lsls r0, 18
	ands r0, r2
	cmp r0, 0
	beq _0803B3F4
	movs r3, 0x1
	cmp r2, 0
	bge _0803B3F6
_0803B3F4:
	movs r3, 0
_0803B3F6:
	ldr r0, [r1]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0803B412
	adds r0, r3, 0
	bl GetBankByPlayerAI
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	bl b_std_message
_0803B412:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B4C8
	str r0, [r1]
_0803B418:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B3CC

	thumb_func_start sub_803B42C
sub_803B42C: @ 803B42C
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	beq _0803B44C
	movs r0, 0x80
	lsls r0, 18
	ands r0, r1
	cmp r0, 0
	beq _0803B44C
	movs r5, 0x3
	cmp r1, 0
	bge _0803B44E
_0803B44C:
	movs r5, 0x2
_0803B44E:
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803B48A
	adds r4, r1, 0
_0803B45E:
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _0803B478
	movs r0, 0
	bl dp01_build_cmdbuf_x2F_2F_2F_2F
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803B478:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B45E
_0803B48A:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0x4C
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xD9
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, 0xD1
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B628
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B42C

	thumb_func_start sub_803B4C8
sub_803B4C8: @ 803B4C8
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	beq _0803B500
	movs r0, 0x80
	lsls r0, 18
	ands r0, r1
	cmp r0, 0
	beq _0803B500
	movs r6, 0x1
	cmp r1, 0
	bge _0803B502
	b _0803B500
	.pool
_0803B4F0:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B42C
	b _0803B572
	.pool
_0803B500:
	movs r6, 0
_0803B502:
	ldr r0, =gBattleExecBuffer
	ldr r2, [r0]
	cmp r2, 0
	bne _0803B574
	ldr r0, =gActiveBank
	strb r2, [r0]
	ldr r1, =gNoOfAllBanks
	adds r4, r0, 0
	ldrb r1, [r1]
	cmp r2, r1
	bcs _0803B554
	adds r5, r4, 0
_0803B51A:
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r6
	bne _0803B540
	movs r0, 0
	bl dp01_build_cmdbuf_x2F_2F_2F_2F
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0803B4F0
_0803B540:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gActiveBank
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B51A
_0803B554:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0x4C
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xD9
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, 0xD1
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B628
_0803B572:
	str r0, [r1]
_0803B574:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B4C8

	thumb_func_start sub_803B598
sub_803B598: @ 803B598
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r1, [r0]
	cmp r1, 0
	bne _0803B606
	ldr r2, =gActiveBank
	strb r1, [r2]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0803B5E6
	adds r4, r2, 0
	ldr r5, =gBattlePartyID
_0803B5B2:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803B5D4
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x05_a_b_c
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803B5D4:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B5B2
_0803B5E6:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0x4C
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xD9
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, 0xD1
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B628
	str r0, [r1]
_0803B606:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B598

	thumb_func_start sub_803B628
sub_803B628: @ 803B628
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r9, r0
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0803B642
	b _0803B8B2
_0803B642:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4C
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803B6C2
	movs r5, 0
	ldr r1, =gNoOfAllBanks
	mov r10, r1
	ldrb r3, [r1]
	cmp r5, r3
	bge _0803B668
	ldr r2, =gTurnOrder
_0803B65C:
	adds r0, r5, r2
	strb r5, [r0]
	adds r5, 0x1
	ldrb r0, [r1]
	cmp r5, r0
	blt _0803B65C
_0803B668:
	movs r5, 0
	b _0803B6B8
	.pool
_0803B67C:
	adds r4, r5, 0x1
	mov r8, r4
	ldrb r1, [r1]
	cmp r8, r1
	bge _0803B6B6
	ldr r6, =gTurnOrder
	ldr r1, =gNoOfAllBanks
	mov r10, r1
	lsls r7, r5, 24
_0803B68E:
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r1, r4, r6
	ldrb r1, [r1]
	movs r2, 0x1
	bl b_first_side
	lsls r0, 24
	cmp r0, 0
	beq _0803B6AC
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r7, 24
	bl sub_803CEDC
_0803B6AC:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803B68E
_0803B6B6:
	mov r5, r8
_0803B6B8:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r5, r0
	blt _0803B67C
_0803B6C2:
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	movs r4, 0xD1
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803B6FC
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xFF
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0803B6FC
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	b _0803B8B2
	.pool
_0803B6FC:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0x4C
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _0803B756
	ldr r5, =gTurnOrder
	adds r4, r2, 0
_0803B710:
	ldr r0, [r4]
	adds r0, 0x4C
	ldrb r0, [r0]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0803B736
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0803B736:
	ldr r1, [r4]
	adds r1, 0x4C
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r3, r9
	cmp r3, 0
	beq _0803B748
	b _0803B8B2
_0803B748:
	ldr r0, [r4]
	adds r0, 0x4C
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B710
_0803B756:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0803B770
	b _0803B8B2
_0803B770:
	str r0, [sp]
	movs r0, 0xB
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0803B786
	b _0803B8B2
_0803B786:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0xD9
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _0803B7DA
	ldr r5, =gTurnOrder
	adds r4, r2, 0
_0803B79A:
	ldr r0, [r4]
	adds r0, 0xD9
	ldrb r0, [r0]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0
	movs r2, 0
	bl berry_effects_maybe
	lsls r0, 24
	cmp r0, 0
	beq _0803B7BC
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0803B7BC:
	ldr r1, [r4]
	adds r1, 0xD9
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r0, r9
	cmp r0, 0
	bne _0803B8B2
	ldr r0, [r4]
	adds r0, 0xD9
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803B79A
_0803B7DA:
	movs r5, 0
	ldr r1, =gBattleStruct
	mov r8, r1
	movs r7, 0x6
	ldr r6, =gUnknown_0202421C
	ldr r2, =gUnknown_02024274
	movs r4, 0xFF
	movs r3, 0
_0803B7EA:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5, r0
	adds r0, 0x5C
	strb r7, [r0]
	adds r1, r5, r6
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	strh r3, [r2]
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0803B7EA
	movs r0, 0
	bl sub_803D580
	bl sub_803D6A0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x91
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, =gUnknown_085CC23E
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803BE74
	str r0, [r1]
	bl sub_803F988
	ldr r1, =gBattleCommunication
	movs r2, 0
	adds r0, r1, 0x7
_0803B834:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0803B834
	movs r5, 0
	ldr r3, =gNoOfAllBanks
	ldr r2, =gBattleStruct
	ldr r6, =gBattleScripting
	ldr r7, =gBattleMoveFlags
	ldrb r0, [r3]
	cmp r5, r0
	bge _0803B866
	ldr r0, =gBattleMons
	movs r4, 0x9
	negs r4, r4
	adds r1, r0, 0
	adds r1, 0x50
_0803B856:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, 0x58
	adds r5, 0x1
	ldrb r0, [r3]
	cmp r5, r0
	blt _0803B856
_0803B866:
	ldr r0, [r2]
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, 0x1]
	ldr r0, [r2]
	movs r3, 0xD0
	lsls r3, 1
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x1
	adds r0, r3
	strb r1, [r0]
	movs r1, 0
	strb r1, [r6, 0x14]
	ldr r0, [r2]
	adds r0, 0x4D
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, 0x3]
	strb r1, [r7]
	bl Random
	ldr r1, =gUnknown_02024330
	strh r0, [r1]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0803B8B2
	bl StopCryAndClearCrySongs
	ldr r0, =gUnknown_082DB8BE
	bl b_call_bc_move_exec
_0803B8B2:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B628

	thumb_func_start bc_8013B1C
bc_8013B1C: @ 803B904
	push {r4-r6,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803B994
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803B9BC
	str r0, [r1]
	ldr r3, =gNoOfAllBanks
	ldr r1, =gBattleCommunication
	movs r2, 0
	adds r0, r1, 0x7
_0803B91C:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0803B91C
	movs r4, 0
	ldrb r3, [r3]
	cmp r4, r3
	bge _0803B96E
	ldr r5, =gBattleMons
	adds r6, r5, 0
	adds r6, 0x4C
_0803B932:
	movs r0, 0x58
	adds r2, r4, 0
	muls r2, r0
	adds r1, r5, 0
	adds r1, 0x50
	adds r1, r2, r1
	ldr r3, [r1]
	subs r0, 0x61
	ands r3, r0
	str r3, [r1]
	adds r2, r6
	ldr r0, [r2]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0803B964
	movs r0, 0x80
	lsls r0, 5
	ands r3, r0
	cmp r3, 0
	beq _0803B964
	lsls r0, r4, 24
	lsrs r0, 24
	bl CancelMultiTurnMoves
_0803B964:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803B932
_0803B96E:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, 0x1]
	ldr r0, [r2]
	movs r3, 0xD0
	lsls r3, 1
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x1
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, 0x3]
	ldr r0, =gBattleMoveFlags
	strb r1, [r0]
_0803B994:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_8013B1C

	thumb_func_start sub_803B9BC
sub_803B9BC: @ 803B9BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0x1
	bl sub_803D580
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803B9EA
	bl sub_80401D0
	lsls r0, 24
	cmp r0, 0
	beq _0803B9DE
	b _0803BB78
_0803B9DE:
	bl sub_8040924
	lsls r0, 24
	cmp r0, 0
	beq _0803B9EA
	b _0803BB78
_0803B9EA:
	bl sub_8041728
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0803B9F8
	b _0803BB78
_0803B9F8:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4D
	strb r1, [r0]
	bl sub_8041364
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0803BA0E
	b _0803BB78
_0803BA0E:
	movs r0, 0
	bl sub_803D580
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffdff
	ands r0, r1
	ldr r1, =0xfff7ffff
	ands r0, r1
	ldr r1, =0xffbfffff
	ands r0, r1
	ldr r1, =0xffefffff
	ands r0, r1
	str r0, [r2]
	ldr r0, =gBattleScripting
	strb r4, [r0, 0x18]
	strb r4, [r0, 0x19]
	strb r4, [r0, 0x14]
	ldr r0, =gBattleMoveDamage
	str r4, [r0]
	ldr r0, =gBattleMoveFlags
	strb r4, [r0]
	ldr r1, =gBattleCommunication
	movs r2, 0
	adds r0, r1, 0x4
_0803BA40:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0803BA40
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803BA98
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	strb r0, [r1]
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_bs_exec
	str r0, [r1]
	b _0803BB78
	.pool
_0803BA98:
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x13]
	ldr r2, =gBattleStruct
	mov r8, r2
	cmp r0, 0xFE
	bhi _0803BAB2
	adds r0, 0x1
	strb r0, [r1, 0x13]
	ldr r1, [r2]
	adds r1, 0xDA
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0803BAB2:
	movs r2, 0
	ldr r4, =gNoOfAllBanks
	ldr r0, =gAbsentBankFlags
	mov r12, r0
	ldr r1, =gUnknown_085CC23E
	mov r9, r1
	ldrb r0, [r4]
	cmp r2, r0
	bge _0803BAE0
	ldr r7, =gUnknown_0202421C
	movs r6, 0xFF
	movs r5, 0
	ldr r3, =gUnknown_02024274
_0803BACC:
	adds r1, r2, r7
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	strh r5, [r3]
	adds r3, 0x2
	adds r2, 0x1
	ldrb r1, [r4]
	cmp r2, r1
	blt _0803BACC
_0803BAE0:
	movs r2, 0
	ldr r3, =gBattleStruct
	movs r1, 0x6
_0803BAE6:
	ldr r0, [r3]
	adds r0, r2, r0
	adds r0, 0x5C
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _0803BAE6
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0x91
	mov r2, r12
	ldrb r1, [r2]
	strb r1, [r0]
	mov r0, r9
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803BE74
	str r0, [r1]
	bl Random
	ldr r1, =gUnknown_02024330
	strh r0, [r1]
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 10
	ands r0, r1
	cmp r0, 0
	beq _0803BB5C
	ldr r0, =gUnknown_082DB881
	bl b_call_bc_move_exec
	b _0803BB78
	.pool
_0803BB5C:
	movs r0, 0x80
	lsls r0, 11
	ands r1, r0
	cmp r1, 0
	beq _0803BB78
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xDA
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803BB78
	ldr r0, =gUnknown_082DB8BE
	bl b_call_bc_move_exec
_0803BB78:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803B9BC

	thumb_func_start sub_803BB88
sub_803BB88: @ 803BB88
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0803BBB8
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x7]
	b _0803BBC2
	.pool
_0803BBB8:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r2, r0, 24
_0803BBC2:
	ldr r1, =gStringBank
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	strb r0, [r1]
	cmp r2, 0x25
	bne _0803BBD0
	b _0803BD4C
_0803BBD0:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803BBDE
	b _0803BD4C
_0803BBDE:
	ldr r1, =gBattleMons
	ldrb r2, [r3]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x32
	bne _0803BBF2
	b _0803BD4C
_0803BBF2:
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	bge _0803BC86
	movs r7, 0
_0803BC08:
	lsrs r4, r7, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	beq _0803BC2C
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r5
	adds r0, r1
	adds r2, r0, 0
	adds r2, 0x20
	ldrb r0, [r2]
	cmp r0, 0x17
	bne _0803BC2C
	b _0803BD54
_0803BC2C:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	beq _0803BC76
	ldr r3, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	movs r2, 0x58
	muls r0, r2
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1A
	beq _0803BC76
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0803BC76
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0803BC76
	adds r0, r5, 0
	muls r0, r2
	adds r0, r3
	adds r2, r0, 0
	adds r2, 0x20
	ldrb r0, [r2]
	cmp r0, 0x47
	bne _0803BC76
	b _0803BD70
_0803BC76:
	movs r0, 0x80
	lsls r0, 17
	adds r7, r0
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803BC08
_0803BC86:
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xF
	movs r2, 0x2A
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0803BCF8
	ldr r6, =gBattleMons
	ldrb r0, [r4]
	movs r3, 0x58
	muls r0, r3
	adds r1, r0, r6
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x8
	beq _0803BCBE
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0803BCF8
_0803BCBE:
	ldr r0, =gBattleScripting
	subs r1, r5, 0x1
	strb r1, [r0, 0x17]
	ldr r2, =gLastUsedAbility
	adds r0, r1, 0
	muls r0, r3
	adds r0, r6
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	b _0803BD90
	.pool
_0803BCF8:
	ldr r1, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0400e000
	ands r0, r1
	cmp r0, 0
	bne _0803BD22
	ldr r1, =gStatuses3
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0803BD40
_0803BD22:
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	movs r0, 0x1
	b _0803BD92
	.pool
_0803BD40:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0803BD8C
_0803BD4C:
	movs r0, 0
	b _0803BD92
	.pool
_0803BD54:
	ldr r0, =gBattleScripting
	strb r5, [r0, 0x17]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	b _0803BD90
	.pool
_0803BD70:
	ldr r0, =gBattleScripting
	strb r5, [r0, 0x17]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	b _0803BD90
	.pool
_0803BD8C:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
_0803BD90:
	strb r0, [r1, 0x5]
_0803BD92:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_803BB88

	thumb_func_start sub_803BDA0
sub_803BDA0: @ 803BDA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r0, =gBattlePartyID
	mov r8, r0
	ldr r1, =gUnknown_0203CF00
	mov r12, r1
	ldr r7, =gBattleStruct
	lsls r0, r5, 1
	adds r4, r0, r5
	adds r6, r0, 0
_0803BDBC:
	mov r0, r12
	adds r2, r3, r0
	ldr r1, [r7]
	adds r0, r4, r3
	adds r0, r1
	adds r0, 0x60
	ldrb r0, [r0]
	strb r0, [r2]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0803BDBC
	mov r1, r8
	adds r0, r6, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r7, =gBattleStruct
	ldr r0, [r7]
	adds r0, r5, r0
	adds r0, 0x5C
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_81B8FB0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0803BE4C
	movs r3, 0
	adds r4, r7, 0
	adds r6, r5
	movs r0, 0x2
	adds r1, r5, 0
	eors r1, r0
	ldr r7, =gUnknown_0203CF00
	lsls r0, r1, 1
	adds r5, r0, r1
_0803BE1A:
	ldr r0, [r4]
	adds r1, r6, r3
	adds r1, r0
	adds r1, 0x60
	adds r2, r3, r7
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r5, r3
	adds r0, r1
	adds r0, 0x60
	ldrb r1, [r2]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0803BE1A
	b _0803BE66
	.pool
_0803BE4C:
	movs r3, 0
	adds r2, r6, r5
	ldr r4, =gUnknown_0203CF00
_0803BE52:
	ldr r0, [r7]
	adds r1, r2, r3
	adds r1, r0
	adds r1, 0x60
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0803BE52
_0803BE66:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803BDA0

	thumb_func_start sub_803BE74
sub_803BE74: @ 803BE74
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =gBattleCommunication
	movs r1, 0
	strb r1, [r0, 0x4]
	ldr r0, =gActiveBank
	strb r1, [r0]
	ldr r0, =gNoOfAllBanks
	bl _0803CD12
	.pool
_0803BE9C:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gBattleCommunication
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x8
	bls _0803BEB8
	bl _0803CD04
_0803BEB8:
	lsls r0, 2
	ldr r1, =_0803BED0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803BED0:
	.4byte _0803BEF4
	.4byte _0803BF0C
	.4byte _0803C02C
	.4byte _0803C7D8
	.4byte _0803CAD0
	.4byte _0803CB84
	.4byte _0803CBC8
	.4byte _0803CBF4
	.4byte _0803CC38
_0803BEF4:
	bl sub_8185FD0
	ldr r1, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	bl _0803CC20
	.pool
_0803BF0C:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	adds r1, r0
	adds r1, 0x5C
	movs r0, 0x6
	strb r0, [r1]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0803BF68
	movs r1, 0x2
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	beq _0803BF68
	eors r5, r1
	adds r0, r5, 0
	bl GetBankByPlayerAI
	ldr r1, [r4]
	adds r1, 0x91
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803BF68
	ldr r4, =gBattleCommunication
	adds r0, r5, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _0803BF68
	bl _0803CD04
_0803BF68:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x91
	ldrb r3, [r0]
	ldr r1, =gBitTable
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ands r3, r0
	cmp r3, 0
	beq _0803BFD0
	ldr r0, =gUnknown_0202421C
	adds r0, r2, r0
	movs r1, 0xD
	strb r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0803BFBC
	ldr r0, =gBattleCommunication
	ldrb r1, [r4]
	adds r1, r0
	movs r0, 0x5
	strb r0, [r1]
	bl _0803CD04
	.pool
_0803BFBC:
	ldr r0, =gBattleCommunication
	ldrb r1, [r4]
	adds r1, r0
	movs r0, 0x4
	strb r0, [r1]
	bl _0803CD04
	.pool
_0803BFD0:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _0803BFF0
	movs r0, 0x80
	lsls r0, 15
	ands r1, r0
	cmp r1, 0
	beq _0803C00C
_0803BFF0:
	ldr r0, =gUnknown_0202421C
	adds r0, r2, r0
	strb r3, [r0]
	ldr r1, =gBattleCommunication
	ldrb r0, [r4]
	bl _0803CC72
	.pool
_0803C00C:
	ldr r0, =gUnknown_0202421C
	ldrb r1, [r0]
	ldr r0, =gBattleBufferB
	ldrb r2, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r2, r0
	movs r0, 0
	bl dp01_build_cmdbuf_x12_a_bb
	bl _0803CB68
	.pool
_0803C02C:
	ldr r3, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r6, =gActiveBank
	ldrb r5, [r6]
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r1, r2, 4
	movs r0, 0xF0
	lsls r0, 24
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, 8
	orrs r1, r0
	lsls r2, 12
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, 0
	beq _0803C058
	bl _0803CD04
_0803C058:
	ldr r4, =gBattleBufferB
	lsls r0, r5, 9
	adds r4, 0x1
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8184FBC
	ldr r1, =gUnknown_0202421C
	ldrb r0, [r6]
	adds r1, r0, r1
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r6]
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xC
	bls _0803C084
	b _0803C6C4
_0803C084:
	lsls r0, 2
	ldr r1, =_0803C0A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803C0A8:
	.4byte _0803C0DC
	.4byte _0803C230
	.4byte _0803C268
	.4byte _0803C6C4
	.4byte _0803C6C4
	.4byte _0803C440
	.4byte _0803C48C
	.4byte _0803C6C4
	.4byte _0803C6C4
	.4byte _0803C6C4
	.4byte _0803C6C4
	.4byte _0803C6C4
	.4byte _0803C4B4
_0803C0DC:
	bl sub_80400C8
	lsls r0, 24
	cmp r0, 0
	beq _0803C134
	ldr r0, =gBattleCommunication
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	adds r1, r0
	movs r4, 0
	movs r0, 0x6
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x54
	strb r4, [r1]
	ldrb r1, [r3]
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x84
	movs r0, 0x4
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, [r2]
	adds r2, r1, r2
	ldr r0, =gBattleBufferB
	lsls r1, 9
	adds r0, 0x3
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2, 0xC]
	bl _0803CD70
	.pool
_0803C134:
	ldr r3, =gDisableStructs
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r3
	ldrh r2, [r0, 0x6]
	cmp r2, 0
	beq _0803C188
	ldr r1, =gUnknown_02024274
	lsls r0, r4, 1
	adds r0, r1
	strh r2, [r0]
	ldrb r2, [r5]
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, r2, r1
	adds r1, 0x80
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0xC]
	strb r0, [r1]
	ldr r1, =gBattleCommunication
	ldrb r0, [r5]
	adds r0, r1
	movs r1, 0x4
	strb r1, [r0]
	bl _0803CD70
	.pool
_0803C188:
	add r2, sp, 0x4
	ldr r3, =gBattleMons
	movs r1, 0x58
	adds r0, r4, 0
	muls r0, r1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r2, 0x10]
	ldrb r0, [r5]
	muls r0, r1
	adds r0, r3
	adds r0, 0x21
	ldrb r0, [r0]
	strb r0, [r2, 0x12]
	ldrb r0, [r5]
	muls r0, r1
	adds r0, r3
	adds r0, 0x22
	ldrb r0, [r0]
	strb r0, [r2, 0x13]
	movs r4, 0
	mov r1, sp
	adds r1, 0xC
	str r1, [sp, 0x18]
	add r2, sp, 0x10
	mov r10, r2
	mov r8, r3
	adds r7, r5, 0
	movs r6, 0x58
	movs r0, 0xC
	add r0, r8
	mov r9, r0
	add r5, sp, 0x4
_0803C1CA:
	lsls r2, r4, 1
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r2, r0
	add r0, r9
	ldrh r0, [r0]
	strh r0, [r5]
	ldr r1, [sp, 0x18]
	adds r3, r1, r4
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r4, r0
	mov r1, r8
	adds r1, 0x24
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldrb r0, [r7]
	adds r1, r0, 0
	muls r1, r6
	adds r2, r1
	add r2, r9
	ldrh r0, [r2]
	add r1, r8
	adds r1, 0x3B
	ldrb r1, [r1]
	lsls r2, r4, 24
	lsrs r2, 24
	bl CalculatePPWithBonus
	mov r2, r10
	adds r1, r2, r4
	strb r0, [r1]
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0803C1CA
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x1
	ands r1, r0
	movs r0, 0
	movs r2, 0
	add r3, sp, 0x4
	bl sub_8033E30
	b _0803C42E
	.pool
_0803C230:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x021f0902
	ands r0, r1
	cmp r0, 0
	bne _0803C23E
	b _0803C48C
_0803C23E:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8185008
	ldr r1, =gUnknown_02024220
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB879
	b _0803C784
	.pool
_0803C268:
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r3, =gBattleStruct
	ldr r1, [r3]
	adds r1, r0, r1
	adds r1, 0x58
	ldr r2, =gBattlePartyID
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r7, =gBattleMons
	ldrb r2, [r5]
	movs r6, 0x58
	adds r0, r2, 0
	muls r0, r6
	adds r1, r7, 0
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =0x0400e000
	ands r1, r0
	cmp r1, 0
	bne _0803C2B8
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	bne _0803C2B8
	ldr r0, =gStatuses3
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	movs r0, 0x80
	lsls r0, 3
	ands r1, r0
	cmp r1, 0
	beq _0803C2EC
_0803C2B8:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0x60
	ldr r0, [r3]
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0x6
	b _0803C400
	.pool
_0803C2EC:
	str r1, [sp]
	movs r0, 0xC
	adds r1, r2, 0
	movs r2, 0x17
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0803C374
	ldrb r1, [r5]
	str r4, [sp]
	movs r0, 0xC
	movs r2, 0x47
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0803C33C
	ldrb r0, [r5]
	muls r0, r6
	adds r1, r0, r7
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0803C33C
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0803C33C
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1A
	bne _0803C374
_0803C33C:
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xF
	movs r2, 0x2A
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0803C3B0
	ldr r2, =gBattleMons
	ldrb r1, [r5]
	movs r0, 0x58
	muls r0, r1
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x8
	beq _0803C374
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0803C3B0
_0803C374:
	subs r1, r4, 0x1
	lsls r1, 4
	movs r0, 0x4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gLastUsedAbility
	ldrb r3, [r0]
	ldr r4, =gBattleStruct
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r2, r0, 1
	adds r2, r0
	adds r2, 0x60
	ldr r0, [r4]
	adds r0, r2
	str r0, [sp]
	movs r0, 0
	movs r2, 0x6
	bl dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f
	b _0803C42E
	.pool
_0803C3B0:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x2
	bne _0803C3D8
	ldr r0, =gUnknown_0202421C
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0803C3D8
	ldr r0, =gBattleStruct
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0x5C
	b _0803C3EE
	.pool
_0803C3D8:
	ldrb r0, [r4]
	cmp r0, 0x3
	bne _0803C410
	ldr r0, =gUnknown_0202421C
	ldrb r0, [r0, 0x1]
	cmp r0, 0x2
	bne _0803C410
	ldr r0, =gBattleStruct
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0x5D
_0803C3EE:
	ldrb r2, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, 0x60
	adds r3, r0
	str r3, [sp]
	movs r0, 0
	movs r1, 0
_0803C400:
	movs r3, 0
	bl dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f
	b _0803C42E
	.pool
_0803C410:
	ldr r2, =gBattleStruct
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0x60
	ldr r0, [r2]
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0x6
	movs r3, 0
	bl dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f
_0803C42E:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0803C6C4
	.pool
_0803C440:
	bl PlayerPartyAndPokemonStorageFull
	lsls r0, 24
	cmp r0, 0
	bne _0803C44C
	b _0803C6C4
_0803C44C:
	ldr r1, =gUnknown_02024220
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DAB11
	str r1, [r0]
	ldr r0, =gBattleCommunication
	ldrb r1, [r3]
	adds r1, r0
	movs r4, 0
	movs r0, 0x6
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x54
	strb r4, [r1]
	ldrb r1, [r3]
	b _0803C7A0
	.pool
_0803C48C:
	ldr r2, =gBattleStruct
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, 0x60
	ldr r1, [r2]
	adds r1, r0
	movs r0, 0
	bl sub_8033E6C
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0803C6C4
	.pool
_0803C4B4:
	ldr r4, =gBattleCommunication
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	adds r0, r4
	movs r1, 0x7
	strb r1, [r0]
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r6, 0x2
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	ldrb r0, [r5]
	bl sub_8185008
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r1, =gBattleMons
	lsls r0, 24
	lsrs r0, 24
	movs r7, 0x58
	muls r0, r7
	adds r4, r1, 0
	adds r4, 0x50
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _0803C532
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0803C550
_0803C532:
	movs r0, 0
	bl dp01_build_cmdbuf_x32_32_32_32
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	bl _0803CD70
	.pool
_0803C550:
	ldr r4, =gUnknown_0202421C
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0803C590
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_8185008
	b _0803C6AE
	.pool
_0803C590:
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0803C5B6
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	b _0803C668
_0803C5B6:
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803C628
	ldr r4, =gProtectStructs
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 20
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _0803C616
	ldr r4, =gDisableStructs
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	beq _0803C628
_0803C616:
	ldrb r0, [r5]
	bl GetBankIdentity
	eors r0, r6
	b _0803C668
	.pool
_0803C628:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0803C690
	ldr r4, =gUnknown_0202421C
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl GetBankIdentity
	movs r5, 0x2
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803C690
	ldr r1, =gRngValue
	ldr r0, =gUnknown_0203BD30
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6]
	bl GetBankIdentity
	eors r0, r5
_0803C668:
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_8185008
	b _0803C6AE
	.pool
_0803C690:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl sub_8185008
_0803C6AE:
	movs r0, 0
	bl dp01_build_cmdbuf_x32_32_32_32
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0803CD70
	.pool
_0803C6C4:
	ldr r1, =gBattleTypeFlags
	ldr r2, [r1]
	movs r5, 0x8
	adds r0, r2, 0
	ands r0, r5
	adds r3, r1, 0
	cmp r0, 0
	beq _0803C720
	ldr r0, =0x043f0100
	ands r2, r0
	cmp r2, 0
	beq _0803C720
	ldr r0, =gBattleBufferB
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	lsls r1, r2, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x3
	bne _0803C720
	ldr r1, =gUnknown_02024220
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB9BA
	str r1, [r0]
	ldr r1, =gBattleCommunication
	ldrb r0, [r4]
	adds r0, r1
	movs r3, 0
	strb r5, [r0]
	b _0803C792
	.pool
_0803C720:
	ldr r0, [r3]
	ldr r1, =0x0200000a
	ands r0, r1
	cmp r0, 0x8
	bne _0803C760
	ldr r0, =gBattleBufferB
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x3
	bne _0803C760
	ldr r0, =gUnknown_082DAAFE
	bl b_call_bc_move_exec
	ldr r1, =gBattleCommunication
	ldrb r0, [r4]
	adds r0, r1
	b _0803CC20
	.pool
_0803C760:
	bl sub_803BB88
	lsls r0, 24
	cmp r0, 0
	beq _0803C7C4
	ldr r0, =gBattleBufferB
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	lsls r1, r2, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x3
	bne _0803C7C4
	ldr r1, =gUnknown_02024220
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, =gUnknown_082DAB0B
_0803C784:
	str r1, [r0]
	ldr r0, =gBattleCommunication
	ldrb r1, [r4]
	adds r1, r0
	movs r3, 0
	movs r0, 0x6
	strb r0, [r1]
_0803C792:
	ldrb r1, [r4]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x54
	strb r3, [r1]
	ldrb r1, [r4]
_0803C7A0:
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x84
	movs r0, 0x1
	strb r0, [r1]
	b _0803CD70
	.pool
_0803C7C4:
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803C7D8:
	ldr r4, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r3, =gActiveBank
	ldrb r5, [r3]
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r0, r2, 4
	movs r1, 0xF0
	lsls r1, 24
	orrs r0, r1
	orrs r0, r2
	lsls r1, r2, 8
	orrs r0, r1
	lsls r2, 12
	orrs r0, r2
	ldr r1, [r4]
	ands r1, r0
	adds r4, r3, 0
	cmp r1, 0
	beq _0803C804
	b _0803CD04
_0803C804:
	ldr r1, =gUnknown_0202421C
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x9
	bls _0803C812
	b _0803CD04
_0803C812:
	lsls r0, 2
	ldr r1, =_0803C830
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803C830:
	.4byte _0803C858
	.4byte _0803C99C
	.4byte _0803C9D4
	.4byte _0803CA0A
	.4byte _0803CA2C
	.4byte _0803CA40
	.4byte _0803CA54
	.4byte _0803CA84
	.4byte _0803CA98
	.4byte _0803CABC
_0803C858:
	ldr r1, =gBattleBufferB
	ldrb r3, [r4]
	lsls r0, r3, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0x3
	blt _0803C88A
	cmp r1, 0x9
	ble _0803C878
	cmp r1, 0xF
	beq _0803C87E
	b _0803C88A
	.pool
_0803C878:
	adds r0, r3, r2
	strb r1, [r0]
	b _0803CD70
_0803C87E:
	adds r1, r3, r2
	movs r0, 0x2
	strb r0, [r1]
	bl sub_803CDF8
	b _0803CD70
_0803C88A:
	movs r0, 0x2
	bl sub_818603C
	ldr r4, =gBattleBufferB
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	lsls r1, r3, 9
	adds r5, r4, 0x2
	adds r0, r1, r5
	ldrb r2, [r0]
	adds r7, r4, 0x3
	adds r1, r7
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	ldr r0, =0x0000ffff
	cmp r2, r0
	bne _0803C8D0
	ldr r0, =gBattleCommunication
	adds r0, r3, r0
	movs r1, 0x1
	strb r1, [r0]
	ldrb r0, [r6]
	bl sub_8185008
	b _0803CD04
	.pool
_0803C8D0:
	bl sub_803FB4C
	lsls r0, 24
	cmp r0, 0
	beq _0803C91C
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_8185008
	ldr r0, =gBattleCommunication
	ldrb r1, [r6]
	adds r1, r0
	movs r3, 0
	movs r0, 0x6
	strb r0, [r1]
	ldrb r1, [r6]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x54
	strb r3, [r1]
	ldrb r0, [r6]
	lsls r0, 9
	adds r1, r4, 0x1
	adds r0, r1
	strb r3, [r0]
	ldrb r1, [r6]
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0x84
	movs r0, 0x2
	strb r0, [r1]
	b _0803CD70
	.pool
_0803C91C:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	bne _0803C942
	ldrb r0, [r6]
	lsls r1, r0, 9
	adds r1, r5
	ldrb r1, [r1]
	bl sub_8184FBC
	ldrb r0, [r6]
	lsls r1, r0, 9
	adds r1, r7
	ldrb r1, [r1]
	bl sub_8184FBC
_0803C942:
	ldrb r0, [r6]
	ldr r4, =gBattleStruct
	ldr r1, [r4]
	adds r1, r0, r1
	adds r1, 0x80
	lsls r0, 9
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gUnknown_02024274
	ldrb r2, [r6]
	lsls r5, r2, 1
	adds r5, r0
	ldr r3, =gBattleMons
	ldr r4, [r4]
	adds r0, r2, r4
	adds r0, 0x80
	ldrb r0, [r0]
	lsls r0, 1
	movs r1, 0x58
	muls r1, r2
	adds r0, r1
	adds r3, 0xC
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r5]
	ldrb r0, [r6]
	adds r4, r0, r4
	lsls r0, 9
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r4, 0xC]
	ldr r0, =gBattleCommunication
	ldrb r1, [r6]
	b _0803CB72
	.pool
_0803C99C:
	ldr r2, =gBattleBufferB
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r1, r4, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r0, [r1]
	lsls r0, 8
	orrs r3, r0
	cmp r3, 0
	bne _0803C9BA
	b _0803CC1C
_0803C9BA:
	ldr r0, =gLastUsedItem
	strh r3, [r0]
	ldr r0, =gBattleCommunication
	ldrb r1, [r5]
	b _0803CB72
	.pool
_0803C9D4:
	ldr r0, =gBattleBufferB
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	lsls r1, r2, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _0803CA04
	ldr r0, =gBattleCommunication
	adds r0, r2, r0
	movs r1, 0x1
	strb r1, [r0]
	ldrb r0, [r4]
	bl sub_8185008
	b _0803CD04
	.pool
_0803CA04:
	bl sub_803CDF8
	b _0803CB6E
_0803CA0A:
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 8
	orrs r0, r1
	str r0, [r2]
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803CA2C:
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803CA40:
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803CA54:
	ldr r3, =gBattleBufferB
	ldr r0, =gActiveBank
	ldrb r4, [r0]
	lsls r1, r4, 9
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r3, 0x2
	adds r1, r3
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	cmp r2, 0
	bne _0803CA72
	b _0803CC1C
_0803CA72:
	ldr r1, =gBattleCommunication
	adds r1, r4, r1
	b _0803CB74
	.pool
_0803CA84:
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803CA98:
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 8
	orrs r0, r1
	str r0, [r2]
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803CABC:
	ldr r2, =gBattleCommunication
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, r2
	b _0803CB74
	.pool
_0803CAD0:
	ldr r3, =gBattleExecBuffer
	ldr r6, =gBitTable
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r6
	ldr r2, [r0]
	lsls r1, r2, 4
	movs r0, 0xF0
	lsls r0, 24
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, 8
	orrs r1, r0
	lsls r2, 12
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, 0
	beq _0803CAFA
	b _0803CD04
_0803CAFA:
	bl sub_803CDB8
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x41
	ands r0, r1
	cmp r0, 0x1
	bne _0803CB3C
	movs r1, 0x2
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	bne _0803CB3C
	adds r0, r5, 0
	eors r0, r1
	bl GetBankByPlayerAI
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r1, 0x91
	ldrb r1, [r1]
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0803CB5C
_0803CB3C:
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_8034464
	b _0803CB66
	.pool
_0803CB5C:
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_8034464
_0803CB66:
	ldr r4, =gActiveBank
_0803CB68:
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803CB6E:
	ldr r0, =gBattleCommunication
	ldrb r1, [r4]
_0803CB72:
	adds r1, r0
_0803CB74:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0803CD04
	.pool
_0803CB84:
	ldr r3, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r1, r2, 4
	movs r0, 0xF0
	lsls r0, 24
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, 8
	orrs r1, r0
	lsls r2, 12
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, 0
	beq _0803CBAE
	b _0803CD04
_0803CBAE:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x4]
	adds r0, 0x1
	strb r0, [r1, 0x4]
	b _0803CD04
	.pool
_0803CBC8:
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r1, r2, r0
	adds r0, r1, 0
	adds r0, 0x54
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803CCB4
	ldr r0, =gBattleCommunication
	adds r0, r2, r0
	adds r1, 0x84
	ldrb r1, [r1]
	strb r1, [r0]
	b _0803CD04
	.pool
_0803CBF4:
	ldr r3, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r4, [r0]
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r1, r2, 4
	movs r0, 0xF0
	lsls r0, 24
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, 8
	orrs r1, r0
	lsls r2, 12
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, 0
	bne _0803CD04
_0803CC1C:
	ldr r0, =gBattleCommunication
	adds r0, r4, r0
_0803CC20:
	movs r1, 0x1
	strb r1, [r0]
	b _0803CD04
	.pool
_0803CC38:
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, 0x54
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803CCB4
	ldr r0, =gBattleBufferB
	lsls r1, r2, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xD
	bne _0803CC94
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 8
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gUnknown_0202421C
	ldrb r0, [r5]
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
	ldr r1, =gBattleCommunication
	ldrb r0, [r5]
_0803CC72:
	adds r0, r1
	movs r1, 0x4
	strb r1, [r0]
	b _0803CD04
	.pool
_0803CC94:
	adds r0, r2, 0
	movs r1, 0x1
	bl sub_8185008
	ldr r2, =gBattleCommunication
	ldrb r0, [r5]
	adds r2, r0, r2
	ldr r1, [r4]
	adds r0, r1
	adds r0, 0x84
	ldrb r0, [r0]
	strb r0, [r2]
	b _0803CD04
	.pool
_0803CCB4:
	ldr r0, =gBankAttacker
	strb r2, [r0]
	ldr r7, =gBattlescriptCurrInstr
	ldr r6, =gUnknown_02024220
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r6
	ldr r4, [r0]
	str r4, [r7]
	ldr r3, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r1, r2, 4
	movs r0, 0xF0
	lsls r0, 24
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, 8
	orrs r1, r0
	lsls r2, 12
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, 0
	bne _0803CCFA
	ldr r0, =gBattleScriptingCommandsTable
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_0803CCFA:
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
_0803CD04:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, =gNoOfAllBanks
	lsls r1, 24
	lsrs r1, 24
_0803CD12:
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r1, r0
	bcs _0803CD1E
	bl _0803BE9C
_0803CD1E:
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x4]
	ldrb r1, [r5]
	cmp r0, r1
	bne _0803CD70
	movs r0, 0x1
	bl sub_818603C
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803D2E8
	str r0, [r1]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0803CD70
	movs r4, 0
	ldrb r5, [r5]
	cmp r4, r5
	bge _0803CD70
_0803CD4A:
	ldr r0, =gUnknown_0202421C
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0803CD66
	lsls r0, r4, 24
	lsrs r0, 24
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r1, r4, r1
	adds r1, 0x5C
	ldrb r1, [r1]
	bl sub_80571DC
_0803CD66:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803CD4A
_0803CD70:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803BE74

	thumb_func_start sub_803CDB8
sub_803CDB8: @ 803CDB8
	push {r4,r5,lr}
	movs r3, 0
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	adds r5, r0, 0
	cmp r3, r2
	bge _0803CDDA
	ldr r4, =gBattleCommunication
_0803CDCA:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0803CDD4
	adds r3, 0x1
_0803CDD4:
	adds r1, 0x1
	cmp r1, r2
	blt _0803CDCA
_0803CDDA:
	adds r0, r3, 0x1
	ldrb r5, [r5]
	cmp r0, r5
	beq _0803CDF0
	movs r0, 0
	b _0803CDF2
	.pool
_0803CDF0:
	movs r0, 0x1
_0803CDF2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803CDB8

	thumb_func_start sub_803CDF8
sub_803CDF8: @ 803CDF8
	push {r4-r7,lr}
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	ldr r6, =gBattleStruct
	ldr r1, [r6]
	adds r1, r0, r1
	adds r1, 0x5C
	ldr r4, =gBattleBufferB
	lsls r0, 9
	adds r2, r4, 0x1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r2
	ldrb r1, [r1]
	bl sub_8184FBC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _0803CEC6
	ldrb r0, [r7]
	ldr r2, [r6]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	ldr r2, [r6]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	lsls r0, 9
	adds r5, r4, 0x2
	adds r0, r5
	ldrb r2, [r0]
	movs r3, 0xF0
	adds r0, r3, 0
	ands r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r1, [r7]
	ldr r2, [r6]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r2
	adds r0, 0x61
	lsls r1, 9
	adds r4, 0x3
	mov r12, r4
	add r1, r12
	ldrb r1, [r1]
	strb r1, [r0]
	ldrb r0, [r7]
	movs r4, 0x2
	eors r0, r4
	ldr r2, [r6]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	ldrb r2, [r1]
	adds r0, r3, 0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	eors r0, r4
	ldr r2, [r6]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	ldrb r0, [r7]
	lsls r0, 9
	adds r0, r5
	ldrb r0, [r0]
	ands r3, r0
	lsrs r3, 4
	ldrb r0, [r1]
	orrs r3, r0
	strb r3, [r1]
	ldrb r0, [r7]
	eors r4, r0
	ldr r0, [r6]
	lsls r1, r4, 1
	adds r1, r4
	adds r1, r0
	adds r1, 0x62
	ldrb r0, [r7]
	lsls r0, 9
	add r0, r12
	ldrb r0, [r0]
	strb r0, [r1]
_0803CEC6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803CDF8

	thumb_func_start sub_803CEDC
sub_803CEDC: @ 803CEDC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0202407A
	adds r4, r0, r2
	ldrb r5, [r4]
	adds r2, r1, r2
	ldrb r3, [r2]
	strb r3, [r4]
	strb r5, [r2]
	ldr r2, =gTurnOrder
	adds r0, r2
	ldrb r5, [r0]
	adds r1, r2
	ldrb r2, [r1]
	strb r2, [r0]
	strb r5, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803CEDC

	thumb_func_start b_first_side
b_first_side: @ 803CF10
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0803CFD8
	ldr r1, [sp, 0x8]
	str r1, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0803CFD8
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	adds r0, r1
	adds r0, 0x20
	ldrb r3, [r0]
	cmp r3, 0x21
	bne _0803CF7C
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0803CF8C
_0803CF7C:
	cmp r3, 0x22
	bne _0803CF98
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _0803CF98
_0803CF8C:
	movs r3, 0x2
	b _0803CF9A
	.pool
_0803CF98:
	movs r3, 0x1
_0803CF9A:
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	ldr r2, =gBattleMons
	adds r0, r2
	adds r0, 0x20
	ldrb r2, [r0]
	cmp r2, 0x21
	bne _0803CFBA
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0803CFCA
_0803CFBA:
	cmp r2, 0x22
	bne _0803CFDA
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _0803CFDA
_0803CFCA:
	movs r7, 0x2
	b _0803CFDC
	.pool
_0803CFD8:
	movs r3, 0x1
_0803CFDA:
	movs r7, 0x1
_0803CFDC:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	adds r4, r0, r1
	ldrh r0, [r4, 0x6]
	muls r3, r0
	ldr r2, =gStatStageRatios
	movs r1, 0x1B
	ldrsb r1, [r4, r1]
	lsls r1, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	muls r0, r3
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	bl __divsi3
	mov r8, r0
	ldrh r0, [r4, 0x2E]
	cmp r0, 0xAF
	bne _0803D02C
	ldr r1, =gEnigmaBerries
	mov r3, r9
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r6, [r0, 0x7]
	ldrb r5, [r0, 0x1A]
	b _0803D040
	.pool
_0803D02C:
	ldrh r0, [r4, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r6, r0, 24
	ldrh r0, [r4, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r5, r0, 24
_0803D040:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x023f0102
	ands r0, r1
	cmp r0, 0
	bne _0803D074
	ldr r0, =0x00000869
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0803D074
	mov r0, r9
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803D074
	movs r0, 0x6E
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0x64
	bl __udivsi3
	mov r8, r0
_0803D074:
	cmp r6, 0x18
	bne _0803D07E
	mov r2, r8
	lsrs r2, 1
	mov r8, r2
_0803D07E:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0803D09C
	mov r0, r8
	lsrs r0, 2
	mov r8, r0
_0803D09C:
	cmp r6, 0x1A
	bne _0803D0B8
	ldr r0, =gUnknown_02024330
	ldrh r4, [r0]
	lsls r0, r5, 16
	subs r0, r5
	movs r1, 0x64
	bl __divsi3
	cmp r4, r0
	bge _0803D0B8
	movs r1, 0x1
	negs r1, r1
	mov r8, r1
_0803D0B8:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	adds r4, r0, r1
	ldrh r0, [r4, 0x6]
	adds r3, r0, 0
	muls r3, r7
	ldr r2, =gStatStageRatios
	movs r1, 0x1B
	ldrsb r1, [r4, r1]
	lsls r1, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	muls r0, r3
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	bl __divsi3
	adds r7, r0, 0
	ldrh r0, [r4, 0x2E]
	cmp r0, 0xAF
	bne _0803D118
	ldr r1, =gEnigmaBerries
	mov r3, r10
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r6, [r0, 0x7]
	ldrb r5, [r0, 0x1A]
	b _0803D12C
	.pool
_0803D118:
	ldrh r0, [r4, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r6, r0, 24
	ldrh r0, [r4, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r5, r0, 24
_0803D12C:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x023f0102
	ands r0, r1
	cmp r0, 0
	bne _0803D15C
	ldr r0, =0x00000869
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0803D15C
	mov r0, r10
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803D15C
	movs r0, 0x6E
	muls r0, r7
	movs r1, 0x64
	bl __udivsi3
	adds r7, r0, 0
_0803D15C:
	cmp r6, 0x18
	bne _0803D162
	lsrs r7, 1
_0803D162:
	ldr r2, =gBattleMons
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0803D17E
	lsrs r7, 2
_0803D17E:
	cmp r6, 0x1A
	bne _0803D198
	ldr r0, =gUnknown_02024330
	ldrh r4, [r0]
	lsls r0, r5, 16
	subs r0, r5
	movs r1, 0x64
	bl __divsi3
	cmp r4, r0
	bge _0803D198
	movs r7, 0x1
	negs r7, r7
_0803D198:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	beq _0803D1B8
	movs r3, 0
	b _0803D254
	.pool
_0803D1B8:
	ldr r0, =gUnknown_0202421C
	mov r3, r9
	adds r1, r3, r0
	ldrb r1, [r1]
	adds r2, r0, 0
	cmp r1, 0
	bne _0803D208
	ldr r0, =gProtectStructs
	lsls r1, r3, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 29
	cmp r0, 0
	bge _0803D1E0
	movs r3, 0xA5
	b _0803D20A
	.pool
_0803D1E0:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	add r0, r9
	adds r0, 0x80
	ldrb r0, [r0]
	lsls r0, 1
	movs r1, 0x58
	mov r3, r9
	muls r3, r1
	adds r1, r3, 0
	adds r0, r1
	ldr r1, =gBattleMons
	adds r1, 0xC
	adds r0, r1
	ldrh r3, [r0]
	b _0803D20A
	.pool
_0803D208:
	movs r3, 0
_0803D20A:
	mov r1, r10
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803D254
	ldr r0, =gProtectStructs
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 29
	cmp r0, 0
	bge _0803D22C
	movs r2, 0xA5
	b _0803D256
	.pool
_0803D22C:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	add r0, r10
	adds r0, 0x80
	ldrb r0, [r0]
	lsls r0, 1
	movs r1, 0x58
	mov r2, r10
	muls r2, r1
	adds r1, r2, 0
	adds r0, r1
	ldr r1, =gBattleMons
	adds r1, 0xC
	adds r0, r1
	ldrh r2, [r0]
	b _0803D256
	.pool
_0803D254:
	movs r2, 0
_0803D256:
	ldr r4, =gBattleMoves
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r4
	movs r1, 0x7
	ldrsb r1, [r0, r1]
	lsls r3, r2, 1
	cmp r1, 0
	bne _0803D27A
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x7]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _0803D2B8
_0803D27A:
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x7]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	bne _0803D2AE
	cmp r8, r7
	bne _0803D2A4
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0803D2A4
	movs r3, 0x2
	b _0803D2D4
	.pool
_0803D2A4:
	cmp r8, r7
	bcs _0803D2D6
	movs r0, 0x1
	str r0, [sp, 0x8]
	b _0803D2D6
_0803D2AE:
	cmp r1, r0
	bge _0803D2D6
	movs r1, 0x1
	str r1, [sp, 0x8]
	b _0803D2D6
_0803D2B8:
	cmp r8, r7
	bne _0803D2CE
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0803D2CE
	movs r2, 0x2
	str r2, [sp, 0x8]
	b _0803D2D6
_0803D2CE:
	cmp r8, r7
	bcs _0803D2D6
	movs r3, 0x1
_0803D2D4:
	str r3, [sp, 0x8]
_0803D2D6:
	ldr r0, [sp, 0x8]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end b_first_side

	thumb_func_start sub_803D2E8
sub_803D2E8: @ 803D2E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r3, 0
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0803D354
	ldr r0, =gActiveBank
	strb r3, [r0]
	ldr r4, =gNoOfAllBanks
	mov r8, r0
	ldrb r0, [r4]
	cmp r3, r0
	bcc _0803D310
	b _0803D54A
_0803D310:
	ldr r7, =gUnknown_0202407A
	ldr r6, =gUnknown_0202421C
	mov r2, r8
	ldr r5, =gTurnOrder
_0803D318:
	adds r1, r3, r7
	ldrb r0, [r2]
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r3, r5
	ldrb r0, [r2]
	strb r0, [r1]
	adds r3, 0x1
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r4]
	cmp r0, r1
	bcc _0803D318
	b _0803D54A
	.pool
_0803D354:
	movs r2, 0x2
	ands r1, r2
	cmp r1, 0
	beq _0803D3A4
	ldr r0, =gActiveBank
	strb r3, [r0]
	ldr r1, =gNoOfAllBanks
	mov r8, r0
	adds r2, r1, 0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _0803D3C0
	ldr r0, =gUnknown_0202421C
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x3
	beq _0803D3BE
_0803D376:
	mov r7, r8
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gNoOfAllBanks
	ldrb r1, [r1]
	cmp r0, r1
	bcs _0803D3C0
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0803D376
	b _0803D3BE
	.pool
_0803D3A4:
	ldr r1, =gUnknown_0202421C
	ldrb r0, [r1]
	ldr r4, =gActiveBank
	mov r8, r4
	cmp r0, 0x3
	bne _0803D3B4
	strb r3, [r4]
	movs r3, 0x5
_0803D3B4:
	ldrb r0, [r1, 0x2]
	cmp r0, 0x3
	bne _0803D3C0
	mov r7, r8
	strb r2, [r7]
_0803D3BE:
	movs r3, 0x5
_0803D3C0:
	cmp r3, 0x5
	bne _0803D448
	ldr r6, =gUnknown_0202407A
	ldr r1, =gUnknown_0202421C
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldr r2, =gTurnOrder
	mov r3, r8
	ldrb r0, [r3]
	strb r0, [r2]
	movs r3, 0x1
	movs r5, 0
	adds r4, r1, 0
	ldr r7, =gBattleMainFunc
	mov r10, r7
	ldr r0, =bc_80154A0
	mov r12, r0
	ldr r1, =gBattleStruct
	mov r9, r1
	ldr r7, =gNoOfAllBanks
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803D41A
	adds r7, r6, 0
	adds r6, r4, 0
	adds r4, r2, 0
	ldr r2, =gNoOfAllBanks
_0803D3FC:
	mov r0, r8
	ldrb r0, [r0]
	cmp r5, r0
	beq _0803D412
	adds r1, r3, r7
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r4
	strb r5, [r0]
	adds r3, 0x1
_0803D412:
	adds r5, 0x1
	ldrb r1, [r2]
	cmp r5, r1
	blt _0803D3FC
_0803D41A:
	mov r2, r12
	mov r3, r10
	str r2, [r3]
	mov r4, r9
	ldr r0, [r4]
	b _0803D554
	.pool
_0803D448:
	movs r0, 0
	mov r7, r8
	strb r0, [r7]
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803D48E
	ldr r6, =gUnknown_0202421C
	mov r2, r8
	ldr r5, =gUnknown_0202407A
	ldr r4, =gTurnOrder
_0803D45E:
	ldrb r0, [r2]
	adds r0, r6
	ldrb r1, [r0]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0803D47C
	adds r0, r3, r5
	strb r1, [r0]
	adds r1, r3, r4
	mov r7, r8
	ldrb r0, [r7]
	strb r0, [r1]
	adds r3, 0x1
_0803D47C:
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gNoOfAllBanks
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803D45E
_0803D48E:
	movs r0, 0
	mov r2, r8
	strb r0, [r2]
	ldr r4, =gNoOfAllBanks
	ldrb r0, [r4]
	cmp r0, 0
	beq _0803D4D2
	ldr r6, =gUnknown_0202421C
	ldr r5, =gUnknown_0202407A
	ldr r4, =gTurnOrder
_0803D4A2:
	ldrb r0, [r2]
	adds r0, r6
	ldrb r1, [r0]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _0803D4C0
	adds r0, r3, r5
	strb r1, [r0]
	adds r1, r3, r4
	mov r7, r8
	ldrb r0, [r7]
	strb r0, [r1]
	adds r3, 0x1
_0803D4C0:
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gNoOfAllBanks
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803D4A2
_0803D4D2:
	movs r5, 0
	b _0803D540
	.pool
_0803D4E8:
	adds r4, r5, 0x1
	adds r7, r4, 0
	ldrb r1, [r1]
	cmp r7, r1
	bge _0803D53E
	ldr r6, =gUnknown_0202407A
	lsls r2, r5, 24
	mov r8, r2
_0803D4F8:
	ldr r0, =gTurnOrder
	adds r1, r5, r0
	ldrb r3, [r1]
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r5, r6
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _0803D534
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0803D534
	cmp r2, 0x2
	beq _0803D534
	cmp r0, 0x2
	beq _0803D534
	adds r0, r3, 0
	movs r2, 0
	bl b_first_side
	lsls r0, 24
	cmp r0, 0
	beq _0803D534
	lsls r1, r4, 24
	lsrs r1, 24
	mov r3, r8
	lsrs r0, r3, 24
	bl sub_803CEDC
_0803D534:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803D4F8
_0803D53E:
	adds r5, r7, 0
_0803D540:
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r5, r0
	blt _0803D4E8
_0803D54A:
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_80154A0
	str r0, [r1]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
_0803D554:
	adds r0, 0x48
	movs r1, 0
	strb r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803D2E8

	thumb_func_start sub_803D580
sub_803D580: @ 803D580
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	adds r5, r1, 0
	cmp r2, 0
	beq _0803D678
	ldr r7, =gProtectStructs
	adds r6, r5, 0
	ldr r0, =gBattleMons + 0x50
	mov r12, r0
	ldr r1, =gDisableStructs
	mov r8, r1
	mov r10, r8
_0803D5AE:
	mov r2, r9
	cmp r2, 0
	beq _0803D5EC
	ldrb r1, [r6]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r6]
	lsls r1, 4
	adds r1, r7
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	b _0803D648
	.pool
_0803D5EC:
	ldrb r0, [r6]
	lsls r0, 4
	adds r2, r0, r7
	movs r1, 0
	mov r4, r10
	movs r3, 0
_0803D5F8:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, 0xF
	bls _0803D5F8
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrb r0, [r1, 0x16]
	cmp r0, 0
	beq _0803D616
	subs r0, 0x1
	strb r0, [r1, 0x16]
_0803D616:
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrb r0, [r1, 0x19]
	cmp r0, 0
	beq _0803D648
	subs r0, 0x1
	strb r0, [r1, 0x19]
	ldrb r2, [r5]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x19]
	cmp r0, 0
	bne _0803D648
	movs r0, 0x58
	muls r2, r0
	add r2, r12
	ldr r0, [r2]
	ldr r1, =0xffbfffff
	ands r0, r1
	str r0, [r2]
_0803D648:
	ldrb r2, [r5]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	bne _0803D666
	movs r0, 0x58
	muls r2, r0
	add r2, r12
	ldr r0, [r2]
	ldr r1, =0xfeffffff
	ands r0, r1
	str r0, [r2]
_0803D666:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gNoOfAllBanks
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803D5AE
_0803D678:
	movs r0, 0
	ldr r2, =gSideTimers
	strb r0, [r2, 0x8]
	strb r0, [r2, 0x14]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803D580

	thumb_func_start sub_803D6A0
sub_803D6A0: @ 803D6A0
	push {r4-r6,lr}
	ldr r2, =gActiveBank
	movs r0, 0
	strb r0, [r2]
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	adds r6, r0, 0
	cmp r1, 0
	beq _0803D6DE
	adds r3, r2, 0
	movs r4, 0
	ldr r5, =gSpecialStatuses
_0803D6B8:
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r5
	movs r1, 0
_0803D6C4:
	adds r0, r2, r1
	strb r4, [r0]
	adds r1, 0x1
	cmp r1, 0x13
	bls _0803D6C4
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r6]
	cmp r0, r1
	bcc _0803D6B8
_0803D6DE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803D6A0

	thumb_func_start bc_80154A0
bc_80154A0: @ 803D6F0
	push {r4-r7,lr}
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	bne _0803D7AE
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0x48
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	mov r12, r2
	adds r6, r1, 0
	ldrb r1, [r6]
	cmp r0, r1
	bcs _0803D7AE
	ldr r5, =gActiveBank
	ldr r4, =gBankAttacker
	movs r7, 0x84
	lsls r7, 1
_0803D71C:
	ldr r1, [r2]
	adds r1, 0x48
	ldrb r0, [r1]
	strb r0, [r4]
	strb r0, [r5]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gUnknown_02024274
	ldrb r3, [r5]
	lsls r0, r3, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	bne _0803D7A0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0803D7A0
	ldr r2, =gDisableStructs
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	lsls r0, 31
	cmp r0, 0
	bne _0803D7A0
	ldr r0, =gProtectStructs
	lsls r1, r3, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 29
	cmp r0, 0
	blt _0803D7A0
	ldr r0, =gUnknown_082DB1FF
	bl b_call_bc_move_exec
	b _0803D7E8
	.pool
_0803D7A0:
	mov r2, r12
	ldr r0, [r2]
	adds r0, 0x48
	ldrb r0, [r0]
	ldrb r1, [r6]
	cmp r0, r1
	bcc _0803D71C
_0803D7AE:
	bl b_clear_atk_up_if_hit_flag_unless_enraged
	ldr r1, =gUnknown_02024082
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gFightStateTracker
	ldr r0, =gUnknown_0202407A
	movs r3, 0
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gDynamicBasePower
	movs r2, 0
	strh r3, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	strb r2, [r0, 0x13]
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_bs_exec
	str r0, [r1]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x3]
	strb r2, [r0, 0x4]
	ldr r0, =gBattleScripting
	strb r2, [r0, 0x16]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0x20
	strb r2, [r0]
_0803D7E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_80154A0

	thumb_func_start bc_bs_exec
bc_bs_exec: @ 803D818
	push {r4-r6,lr}
	ldr r6, =gBattleOutcome
	ldrb r0, [r6]
	ldr r2, =gFightStateTracker
	cmp r0, 0
	beq _0803D828
	movs r0, 0xC
	strb r0, [r2]
_0803D828:
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, 0x4B
	ldr r4, =gUnknown_02024082
	ldrb r1, [r4]
	strb r1, [r0]
	ldr r1, =gUnknown_0831BC0C
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _0803D894
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xffefffff
	ands r0, r1
	str r0, [r2]
	ldr r3, =gBattleMainFunc
	ldr r2, =gUnknown_0831BC44
	ldrb r1, [r6]
	movs r0, 0x7F
	ands r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [r3]
	b _0803D8AC
	.pool
_0803D894:
	ldr r0, [r5]
	adds r0, 0x4B
	ldrb r0, [r0]
	cmp r0, r1
	beq _0803D8AC
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffdff
	ands r0, r1
	ldr r1, =0xfff7ffff
	ands r0, r1
	str r0, [r2]
_0803D8AC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_bs_exec

	thumb_func_start sub_803D8C0
sub_803D8C0: @ 803D8C0
	push {r4,lr}
	ldr r1, =gFightStateTracker
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gBattleTypeFlags
	ldr r2, [r1]
	ldr r0, =0x02000002
	ands r0, r2
	cmp r0, 0
	beq _0803D920
	ldr r1, =gScriptResult
	ldr r4, =gBattleOutcome
	ldrb r0, [r4]
	strh r0, [r1]
	ldr r1, =gBattleTextBuff1
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r1, =gBankAttacker
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAA35
	str r0, [r1]
	ldrb r1, [r4]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r4]
	b _0803DAA4
	.pool
_0803D920:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0803D95C
	ldr r0, =0x043f0900
	ands r2, r0
	cmp r2, 0
	beq _0803D95C
	bl sub_805EA60
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAA87
	str r0, [r1]
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _0803D946
	b _0803DA8A
_0803D946:
	b _0803DA94
	.pool
_0803D95C:
	ldr r0, [r1]
	movs r1, 0xA
	ands r0, r1
	cmp r0, 0x8
	beq _0803D968
	b _0803DA9E
_0803D968:
	bl sub_805EA60
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DA92D
	str r0, [r1]
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
	subs r0, 0x3
	cmp r0, 0x32
	bls _0803D98A
	b _0803DA94
_0803D98A:
	lsls r0, 2
	ldr r1, =_0803D9A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803D9A8:
	.4byte _0803DA80
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA80
	.4byte _0803DA94
	.4byte _0803DA80
	.4byte _0803DA94
	.4byte _0803DA80
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA74
	.4byte _0803DA8A
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA74
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA80
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA94
	.4byte _0803DA80
_0803DA74:
	ldr r0, =0x00000163
	bl PlayBGM
	b _0803DAA4
	.pool
_0803DA80:
	movs r0, 0xD4
	lsls r0, 1
	bl PlayBGM
	b _0803DAA4
_0803DA8A:
	movs r0, 0xB1
	lsls r0, 1
	bl PlayBGM
	b _0803DAA4
_0803DA94:
	movs r0, 0xCE
	lsls r0, 1
	bl PlayBGM
	b _0803DAA4
_0803DA9E:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DA96A
	str r0, [r1]
_0803DAA4:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803DCD8
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803D8C0

	thumb_func_start sub_803DAC0
sub_803DAC0: @ 803DAC0
	push {r4,lr}
	ldr r1, =gFightStateTracker
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0803DB7C
	ldr r0, =0x003f0100
	ands r1, r0
	cmp r1, 0
	beq _0803DB44
	ldr r3, =gBattleOutcome
	ldrb r2, [r3]
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _0803DB2C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB9C8
	str r0, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r3]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1]
	b _0803DB82
	.pool
_0803DB2C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAA0B
	str r0, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r3]
	b _0803DB82
	.pool
_0803DB44:
	ldr r1, =gBattleTextBuff1
	ldr r4, =gBattleOutcome
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r1, =gBankAttacker
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAA35
	str r0, [r1]
	ldrb r1, [r4]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r4]
	b _0803DB82
	.pool
_0803DB7C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DA96D
	str r0, [r1]
_0803DB82:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803DCD8
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803DAC0

	thumb_func_start sub_803DBA0
sub_803DBA0: @ 803DBA0
	push {lr}
	ldr r1, =gFightStateTracker
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gBattleTypeFlags
	ldr r2, [r1]
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _0803DBFC
	movs r0, 0x8
	ands r2, r0
	cmp r2, 0
	beq _0803DBFC
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB9C1
	str r0, [r1]
	ldr r1, =gBattleOutcome
	movs r0, 0x9
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1]
	b _0803DC6A
	.pool
_0803DBFC:
	ldr r0, [r1]
	movs r1, 0x80
	lsls r1, 19
	ands r0, r1
	cmp r0, 0
	beq _0803DC24
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB9C1
	str r0, [r1]
	ldr r1, =gBattleOutcome
	movs r0, 0x9
	strb r0, [r1]
	b _0803DC6A
	.pool
_0803DC24:
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 27
	lsrs r0, 30
	cmp r0, 0x1
	beq _0803DC54
	cmp r0, 0x2
	beq _0803DC64
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAAF0
	b _0803DC68
	.pool
_0803DC54:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAADB
	b _0803DC68
	.pool
_0803DC64:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAAE9
_0803DC68:
	str r0, [r1]
_0803DC6A:
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803DCD8
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803DBA0

	thumb_func_start bc_80158BC
bc_80158BC: @ 803DC84
	ldr r1, =gFightStateTracker
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	ldr r2, =gBankAttacker
	ldrb r0, [r2]
	strb r0, [r1, 0x2]
	ldr r3, =gBattlePartyID
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAAF7
	str r0, [r1]
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803DCD8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end bc_80158BC

	thumb_func_start sub_803DCD8
sub_803DCD8: @ 803DCD8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gFightStateTracker
	ldrb r0, [r0]
	subs r0, 0xB
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _0803DCEE
	b _0803DE10
_0803DCEE:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x023f0b92
	ands r1, r0
	cmp r1, 0
	bne _0803DDB6
	ldr r2, =gActiveBank
	strb r1, [r2]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0803DDB2
	adds r5, r2, 0
	ldr r0, =gBattlePartyID
	mov r8, r0
	movs r7, 0x64
	ldr r6, =gPlayerParty
_0803DD10:
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803DDA0
	ldr r4, =gBattleResults
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	bne _0803DD74
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r4, 0x6]
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r6
	movs r1, 0x2
	adds r2, r4, 0
	adds r2, 0x8
	bl GetMonData
	b _0803DDA0
	.pool
_0803DD74:
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r4, 0x26]
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r6
	movs r1, 0x2
	adds r2, r4, 0
	adds r2, 0x14
	bl GetMonData
_0803DDA0:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803DD10
_0803DDB2:
	bl sub_80EC728
_0803DDB6:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x023f0b9a
	ands r0, r1
	cmp r0, 0
	bne _0803DDD2
	ldr r0, =gBattleResults
	ldrb r1, [r0, 0x5]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0803DDD2
	bl sub_80EE184
_0803DDD2:
	bl sub_8186444
	movs r0, 0x3
	bl BeginFastPaletteFade
	movs r0, 0x5
	bl FadeOutMapMusic
	ldr r1, =gBattleMainFunc
	ldr r0, =sub_803DE40
	str r0, [r1]
	ldr r1, =gUnknown_030061E8
	ldr r0, =sub_8038420
	str r0, [r1]
	b _0803DE2A
	.pool
_0803DE10:
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803DE2A
	ldr r1, =gBattleScriptingCommandsTable
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803DE2A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803DCD8

	thumb_func_start sub_803DE40
sub_803DE40: @ 803DE40
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0803DE86
	bl ResetSpriteData
	ldr r0, =gUnknown_03005D54
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803DE62
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0803DE80
_0803DE62:
	ldr r1, =gBattleMainFunc
	ldr r0, =c4_overworld
	str r0, [r1]
	b _0803DEA2
	.pool
_0803DE80:
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_evolution_cutscene
	str r0, [r1]
_0803DE86:
	bl FreeAllWindowBuffers
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0803DEA2
	bl sub_805F094
	bl sub_8057028
	bl dp11_free
_0803DEA2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803DE40

	thumb_func_start bc_evolution_cutscene
bc_evolution_cutscene: @ 803DEB4
	push {r4-r6,lr}
	ldr r0, =gUnknown_03005D54
	ldrb r1, [r0]
	adds r3, r0, 0
	cmp r1, 0
	beq _0803DF2E
_0803DEC0:
	movs r6, 0
_0803DEC2:
	ldrb r2, [r3]
	ldr r0, =gBitTable
	lsls r1, r6, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0803DF20
	bics r2, r1
	strb r2, [r3]
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0
	bl GetEvolutionTargetSpecies
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0803DF20
	bl FreeAllWindowBuffers
	ldr r0, =gBattleMainFunc
	ldr r1, =sub_803DF48
	str r1, [r0]
	lsls r3, r6, 24
	lsrs r3, 24
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl evolution_cutscene
	b _0803DF34
	.pool
_0803DF20:
	adds r6, 0x1
	ldr r3, =gUnknown_03005D54
	cmp r6, 0x5
	ble _0803DEC2
	ldrb r0, [r3]
	cmp r0, 0
	bne _0803DEC0
_0803DF2E:
	ldr r1, =gBattleMainFunc
	ldr r0, =c4_overworld
	str r0, [r1]
_0803DF34:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_evolution_cutscene

	thumb_func_start sub_803DF48
sub_803DF48: @ 803DF48
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	bne _0803DF5A
	ldr r1, =gBattleMainFunc
	ldr r0, =bc_evolution_cutscene
	str r0, [r1]
_0803DF5A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803DF48

	thumb_func_start c4_overworld
c4_overworld: @ 803DF70
	push {r4-r6,lr}
	ldr r6, =gBattleTypeFlags
	ldr r0, [r6]
	movs r5, 0x2
	ands r0, r5
	cmp r0, 0
	bne _0803DF8C
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	bl RandomlyGivePartyPokerus
	adds r0, r4, 0
	bl PartySpreadPokerus
_0803DF8C:
	ldr r4, [r6]
	adds r0, r4, 0
	ands r0, r5
	cmp r0, 0
	beq _0803DF9E
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803DFEC
_0803DF9E:
	ldr r1, =gScriptResult
	ldr r5, =gBattleOutcome
	ldrb r0, [r5]
	strh r0, [r1]
	ldr r3, =gMain
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r3]
	movs r0, 0x80
	lsls r0, 3
	ands r4, r0
	cmp r4, 0
	beq _0803DFDE
	ldr r0, =gEnemyParty
	bl UpdateRoamerHPStatus
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0803DFDA
	cmp r1, 0x7
	bne _0803DFDE
_0803DFDA:
	bl SetRoamerInactive
_0803DFDE:
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_0803DFEC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c4_overworld

	thumb_func_start bc_move_exec_returning
bc_move_exec_returning: @ 803E018
	push {lr}
	ldr r0, =gFightStateTracker
	ldrb r0, [r0]
	subs r0, 0xB
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0803E060
	ldr r3, =gBattleResources
	ldr r0, [r3]
	ldr r0, [r0, 0xC]
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803E03C
	subs r0, 0x1
	strb r0, [r1]
_0803E03C:
	ldr r2, =gBattleMainFunc
	ldr r0, [r3]
	ldr r1, [r0, 0xC]
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _0803E07A
	.pool
_0803E060:
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803E07A
	ldr r1, =gBattleScriptingCommandsTable
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803E07A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bc_move_exec_returning

	thumb_func_start sub_803E08C
sub_803E08C: @ 803E08C
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0803E0A8
	ldr r1, =gBattleScriptingCommandsTable
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803E0A8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803E08C

	thumb_func_start sub_803E0B8
sub_803E0B8: @ 803E0B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0x4
	str r0, [sp]
	ldr r6, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldr r1, =gBattleStruct
	ldr r3, [r1]
	adds r0, r3, 0
	adds r0, 0x91
	ldrb r2, [r0]
	ldr r1, =gBitTable
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _0803E110
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	b _0803E83C
	.pool
_0803E110:
	ldr r1, =gCritMultiplier
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gBattleScripting
	movs r0, 0x1
	strb r0, [r1, 0xE]
	ldr r5, =0x000001a3
	adds r0, r3, r5
	strb r2, [r0]
	ldr r0, =gBattleMoveFlags
	strb r2, [r0]
	ldr r0, =gUnknown_02024212
	strb r2, [r0]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x6]
	ldr r2, =gCurrMovePos
	ldr r0, =gUnknown_020241E9
	mov r9, r0
	ldrb r0, [r6]
	ldr r3, =gBattleStruct
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0x80
	ldrb r0, [r0]
	mov r5, r9
	strb r0, [r5]
	strb r0, [r2]
	ldr r1, =gProtectStructs
	ldrb r4, [r6]
	lsls r0, r4, 4
	adds r3, r0, r1
	ldrb r1, [r3]
	lsls r0, r1, 29
	mov r8, r2
	cmp r0, 0
	bge _0803E1BC
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r2, =gCurrentMove
	ldr r1, =gUnknown_020241EC
	movs r0, 0xA5
	strh r0, [r1]
	strh r0, [r2]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	str r0, [r2]
	movs r0, 0xA5
	movs r1, 0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, =gBattleStruct
	ldr r2, [r3]
	b _0803E316
	.pool
_0803E1BC:
	ldr r5, =gBattleMons
	mov r10, r5
	movs r0, 0x58
	adds r5, r4, 0
	muls r5, r0
	mov r0, r10
	adds r0, 0x50
	adds r0, r5, r0
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _0803E1E2
	movs r7, 0x80
	lsls r7, 15
	ands r7, r1
	cmp r7, 0
	beq _0803E204
_0803E1E2:
	ldr r3, =gCurrentMove
	ldr r2, =gUnknown_020241EC
	ldr r1, =gUnknown_02024268
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	strh r0, [r3]
	b _0803E33C
	.pool
_0803E204:
	ldr r1, =gDisableStructs
	mov r12, r1
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	add r0, r12
	ldrh r3, [r0, 0x6]
	adds r1, r3, 0
	cmp r1, 0
	beq _0803E2DC
	ldrb r2, [r0, 0xC]
	lsls r0, r2, 1
	adds r0, r5
	mov r4, r10
	adds r4, 0xC
	adds r0, r4
	ldrh r0, [r0]
	cmp r1, r0
	bne _0803E268
	ldr r2, =gCurrentMove
	ldr r0, =gUnknown_020241EC
	strh r3, [r0]
	strh r3, [r2]
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r0, [r0, 0xC]
	mov r3, r9
	strb r0, [r3]
	mov r5, r8
	strb r0, [r5]
	ldrh r0, [r2]
	movs r1, 0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, =gBattleStruct
	ldr r2, [r3]
	b _0803E316
	.pool
_0803E268:
	cmp r1, 0
	beq _0803E2DC
	cmp r1, r0
	beq _0803E2DC
	mov r5, r9
	strb r2, [r5]
	mov r0, r8
	strb r2, [r0]
	ldr r3, =gCurrentMove
	ldr r2, =gUnknown_020241EC
	ldrb r0, [r0]
	lsls r0, 1
	ldrb r1, [r6]
	movs r5, 0x58
	muls r1, r5
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r2]
	strh r0, [r3]
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	movs r2, 0
	strh r7, [r0, 0x6]
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	strb r2, [r0, 0xC]
	ldrb r0, [r6]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	add r1, r12
	ldrb r2, [r1, 0xE]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xE]
	ldrh r0, [r3]
	movs r1, 0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, =gBattleStruct
	ldr r2, [r3]
	b _0803E316
	.pool
_0803E2DC:
	ldr r3, =gBattleMons
	mov r5, r8
	ldrb r0, [r5]
	lsls r0, 1
	ldr r4, =gBankAttacker
	ldrb r2, [r4]
	movs r1, 0x58
	muls r1, r2
	adds r0, r1
	adds r3, 0xC
	adds r0, r3
	ldr r1, =gUnknown_02024274
	lsls r2, 1
	adds r2, r1
	ldrh r3, [r0]
	ldrh r2, [r2]
	cmp r3, r2
	beq _0803E334
	ldr r1, =gCurrentMove
	ldr r0, =gUnknown_020241EC
	strh r3, [r0]
	strh r3, [r1]
	ldrh r0, [r1]
	movs r1, 0
	bl GetMoveTarget
	ldrb r1, [r4]
	ldr r2, =gBattleStruct
	ldr r2, [r2]
_0803E316:
	adds r1, r2
	strb r0, [r1, 0xC]
	b _0803E33C
	.pool
_0803E334:
	ldr r1, =gCurrentMove
	ldr r0, =gUnknown_020241EC
	strh r3, [r0]
	strh r3, [r1]
_0803E33C:
	ldr r2, =gBattleMons
	ldr r1, =gBankAttacker
	ldrb r3, [r1]
	movs r0, 0x58
	muls r0, r3
	adds r0, r2
	ldrh r0, [r0, 0x28]
	mov r8, r1
	cmp r0, 0
	beq _0803E384
	adds r0, r3, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803E37C
	ldr r0, =gBattleResults
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	strh r1, [r0, 0x22]
	b _0803E384
	.pool
_0803E37C:
	ldr r0, =gBattleResults
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	strh r1, [r0, 0x24]
_0803E384:
	mov r1, r8
	ldrb r0, [r1]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gSideTimers
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r5, r0, r1
	ldrb r0, [r5, 0x8]
	cmp r0, 0
	beq _0803E400
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0803E400
	mov r3, r8
	ldrb r0, [r3]
	bl GetBankSide
	adds r4, r0, 0
	ldrb r0, [r5, 0x9]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0803E400
	ldr r1, =gBattleMons
	ldrb r2, [r5, 0x9]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _0803E400
	ldr r0, =gBankTarget
	strb r2, [r0]
	b _0803E76A
	.pool
_0803E400:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	ldr r5, =gBankAttacker
	mov r8, r5
	cmp r0, 0
	bne _0803E412
	b _0803E6E0
_0803E412:
	ldr r1, =gSideTimers
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r5, [r0, 0x8]
	cmp r5, 0
	beq _0803E424
	b _0803E630
_0803E424:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _0803E440
	ldrb r0, [r4, 0x6]
	cmp r0, 0x10
	bne _0803E440
	b _0803E630
_0803E440:
	ldr r3, =gBattleMons
	ldr r2, =gBankAttacker
	ldrb r6, [r2]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, r6, r0
	ldrb r1, [r0, 0xC]
	movs r0, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, 0x1F
	bne _0803E460
	b _0803E630
_0803E460:
	ldrb r0, [r4, 0x2]
	cmp r0, 0xD
	beq _0803E468
	b _0803E630
_0803E468:
	adds r0, r6, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gActiveBank
	strb r5, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	bcs _0803E4E0
	adds r4, r1, 0
_0803E480:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	beq _0803E4CE
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r1, r0
	ldrb r0, [r1, 0xC]
	ldrb r1, [r4]
	cmp r0, r1
	beq _0803E4CE
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1F
	bne _0803E4CE
	adds r0, r2, 0
	bl sub_8048728
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [sp]
	cmp r0, r3
	bcs _0803E4CE
	ldrb r0, [r4]
	bl sub_8048728
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
_0803E4CE:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803E480
_0803E4E0:
	ldr r5, [sp]
	cmp r5, 0x4
	beq _0803E4E8
	b _0803E5E2
_0803E4E8:
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020241EC
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	ands r5, r0
	cmp r5, 0
	beq _0803E568
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803E548
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0803E544
	movs r0, 0x1
	b _0803E55A
	.pool
_0803E544:
	movs r0, 0x3
	b _0803E55A
_0803E548:
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0803E558
	movs r0, 0
	b _0803E55A
_0803E558:
	movs r0, 0x2
_0803E55A:
	bl GetBankByPlayerAI
	ldr r1, =gBankTarget
	strb r0, [r1]
	b _0803E578
	.pool
_0803E568:
	ldr r2, =gBankTarget
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	ldrb r0, [r0, 0xC]
	strb r0, [r2]
_0803E578:
	ldr r7, =gAbsentBankFlags
	ldrb r0, [r7]
	ldr r1, =gBitTable
	mov r8, r1
	ldr r5, =gBankTarget
	ldrb r1, [r5]
	lsls r1, 2
	add r1, r8
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _0803E592
	b _0803E76A
_0803E592:
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	adds r4, r0, 0
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0803E5C4
	ldrb r0, [r5]
	b _0803E758
	.pool
_0803E5C4:
	ldrb r0, [r6]
	bl GetBankIdentity
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	strb r0, [r5]
	ldrb r1, [r7]
	ldrb r2, [r5]
	lsls r0, r2, 2
	add r0, r8
	b _0803E74E
_0803E5E2:
	ldr r4, =gActiveBank
	ldr r0, =gTurnOrder
	ldr r3, [sp]
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r4]
	ldrb r0, [r4]
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r1, r0
	adds r1, r2
	adds r1, 0x20
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r2, =gSpecialStatuses
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
	ldr r1, =gBankTarget
	ldrb r0, [r4]
	strb r0, [r1]
	b _0803E76A
	.pool
_0803E630:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r4, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0803E6E0
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020241EC
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x6]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0803E6E0
	mov r5, r8
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803E684
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	beq _0803E680
	movs r0, 0x1
	b _0803E696
	.pool
_0803E680:
	movs r0, 0x3
	b _0803E696
_0803E684:
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	beq _0803E694
	movs r0, 0
	b _0803E696
_0803E694:
	movs r0, 0x2
_0803E696:
	bl GetBankByPlayerAI
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0803E76A
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	adds r4, r0, 0
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0803E76A
	ldrb r0, [r5]
	b _0803E758
	.pool
_0803E6E0:
	ldr r5, =gBankTarget
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	ldrb r0, [r0, 0xC]
	strb r0, [r5]
	ldr r6, =gAbsentBankFlags
	ldrb r1, [r6]
	ldr r7, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0803E76A
	ldrb r0, [r2]
	bl GetBankSide
	adds r4, r0, 0
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0803E730
	ldrb r0, [r5]
	b _0803E758
	.pool
_0803E730:
	mov r1, r8
	ldrb r0, [r1]
	bl GetBankIdentity
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	strb r0, [r5]
	ldrb r1, [r6]
	ldrb r2, [r5]
	lsls r0, r2, 2
	adds r0, r7
_0803E74E:
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0803E76A
	adds r0, r2, 0
_0803E758:
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	strb r0, [r5]
_0803E76A:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 10
	ands r1, r2
	adds r5, r0, 0
	cmp r1, 0
	beq _0803E808
	ldr r0, =gProtectStructs
	ldr r4, =gBankAttacker
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	lsls r0, 27
	cmp r0, 0
	bge _0803E808
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _0803E7B4
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	b _0803E83C
	.pool
_0803E7B4:
	ldr r3, =gUnknown_02024230
	lsls r0, r2, 2
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	beq _0803E7EC
	ldr r1, =gBattleCommunication
	movs r2, 0
	movs r0, 0x4
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r3
	str r2, [r0]
	b _0803E824
	.pool
_0803E7EC:
	ldr r1, =gBattleCommunication
	movs r0, 0x4
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB6AD
	str r0, [r1]
	b _0803E824
	.pool
_0803E808:
	ldr r4, =gBattlescriptCurrInstr
	ldr r3, =gUnknown_082D86A8
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	str r0, [r4]
_0803E824:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0803E838
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl sub_81A56E8
_0803E838:
	ldr r1, =gFightStateTracker
	movs r0, 0xA
_0803E83C:
	strb r0, [r1]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803E0B8

	thumb_func_start bs2_8016374
bs2_8016374: @ 803E868
	push {r4,lr}
	ldr r3, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, =gUnknown_02022E14
	movs r2, 0
	strh r2, [r0]
	ldr r0, =gUnknown_02022E16
	strh r2, [r0]
	ldr r1, =gUnknown_020244AC
	ldrb r0, [r3]
	adds r0, r1
	strb r2, [r0]
	ldr r1, =gUnknown_020244B0
	ldrb r0, [r3]
	adds r0, r1
	strb r2, [r0]
	ldr r2, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r2]
	movs r0, 0x7
	strb r0, [r2, 0x1]
	ldrb r4, [r3]
	strb r4, [r2, 0x2]
	ldrb r0, [r3]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x58
	ldrb r0, [r0]
	strb r0, [r2, 0x3]
	movs r0, 0xFF
	strb r0, [r2, 0x4]
	ldr r0, =gBattleScripting
	strb r4, [r0, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAB15
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	strb r0, [r1]
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x2]
	cmp r0, 0xFE
	bhi _0803E8CE
	adds r0, 0x1
	strb r0, [r1, 0x2]
_0803E8CE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bs2_8016374

	thumb_func_start sub_803E90C
sub_803E90C: @ 803E90C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, =gBankAttacker
	ldr r2, =gBankTarget
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	strb r0, [r4]
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldrb r0, [r4]
	bl sub_8045868
	ldr r5, =gLastUsedItem
	ldr r2, =gBattleBufferB
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r0, [r1]
	lsls r0, 8
	orrs r3, r0
	strh r3, [r5]
	cmp r3, 0xC
	bhi _0803E998
	ldr r2, =gBattlescriptCurrInstr
	ldr r1, =gUnknown_082DBD08
	ldrh r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, =gFightStateTracker
	mov r10, r0
	b _0803EBF6
	.pool
_0803E998:
	adds r0, r3, 0
	subs r0, 0x50
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0803E9C0
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, =gUnknown_082DBD54
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, =gFightStateTracker
	mov r10, r1
	b _0803EBF6
	.pool
_0803E9C0:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803E9E8
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, =gUnknown_082DBD3C
	ldr r1, [r1]
	str r1, [r0]
	ldr r2, =gFightStateTracker
	mov r10, r2
	b _0803EBF6
	.pool
_0803E9E8:
	ldr r3, =gBattleScripting
	ldrb r0, [r4]
	strb r0, [r3, 0x17]
	lsls r0, 24
	lsrs r0, 25
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r0, r1
	adds r0, 0xC4
	ldrb r0, [r0]
	subs r0, 0x1
	mov r8, r4
	ldr r1, =gBattlescriptCurrInstr
	mov r9, r1
	ldr r6, =gUnknown_082DBD3C
	mov r12, r3
	adds r7, r2, 0
	ldr r2, =gFightStateTracker
	mov r10, r2
	cmp r0, 0x4
	bls _0803EA14
	b _0803EBDE
_0803EA14:
	lsls r0, 2
	ldr r1, =_0803EA38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803EA38:
	.4byte _0803EBDE
	.4byte _0803EBDE
	.4byte _0803EA4C
	.4byte _0803EAE0
	.4byte _0803EBB0
_0803EA4C:
	ldr r5, =gBattleCommunication
	movs r0, 0
	strb r0, [r5, 0x5]
	ldr r2, =gBankAttacker
	ldrb r0, [r2]
	lsrs r0, 1
	ldr r1, [r7]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	mov r8, r2
	cmp r0, 0
	beq _0803EA98
	movs r0, 0x3E
	ands r0, r1
	ldr r1, =gBattlescriptCurrInstr
	mov r9, r1
	ldr r6, =gUnknown_082DBD3C
	ldr r2, =gFightStateTracker
	mov r10, r2
	cmp r0, 0
	bne _0803EA7E
	b _0803EBDE
_0803EA7E:
	movs r0, 0x5
	strb r0, [r5, 0x5]
	b _0803EBDE
	.pool
_0803EA98:
	ldr r0, =gBattlescriptCurrInstr
	mov r9, r0
	ldr r6, =gUnknown_082DBD3C
	ldr r1, =gFightStateTracker
	mov r10, r1
	mov r4, r8
	adds r3, r7, 0
	adds r2, r5, 0
_0803EAA8:
	ldrb r1, [r4]
	lsrs r1, 1
	ldr r0, [r3]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	lsrs r0, 1
	strb r0, [r1]
	ldrb r0, [r2, 0x5]
	adds r0, 0x1
	strb r0, [r2, 0x5]
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0803EAA8
	b _0803EBDE
	.pool
_0803EAE0:
	ldr r3, =gBattleCommunication
	movs r0, 0x4
	strb r0, [r3, 0x5]
	ldr r2, =gBankAttacker
	ldrb r0, [r2]
	lsrs r0, 1
	ldr r1, [r7]
	adds r0, r1
	adds r6, r0, 0
	adds r6, 0xC6
	ldrb r1, [r6]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r8, r2
	cmp r5, 0
	beq _0803EB28
	movs r0, 0x5
	strb r0, [r3, 0x5]
	ldr r2, =gBattlescriptCurrInstr
	mov r9, r2
	ldr r6, =gUnknown_082DBD3C
	ldr r0, =gFightStateTracker
	mov r10, r0
	b _0803EBDE
	.pool
_0803EB28:
	ldr r3, =gBattleTextBuff1
	movs r4, 0xFD
	strb r4, [r3]
	movs r0, 0x5
	strb r0, [r3, 0x1]
	movs r2, 0x1
	strb r2, [r3, 0x2]
	movs r0, 0xFF
	strb r0, [r3, 0x3]
	ldr r1, =gBattleTextBuff2
	strb r4, [r1]
	strb r5, [r1, 0x1]
	movs r0, 0xD2
	strb r0, [r1, 0x2]
	strb r5, [r1, 0x3]
	subs r0, 0xD3
	strb r0, [r1, 0x4]
	ldrb r0, [r6]
	ands r2, r0
	ldr r1, =gBattlescriptCurrInstr
	mov r9, r1
	ldr r6, =gUnknown_082DBD3C
	ldr r0, =gFightStateTracker
	mov r10, r0
	cmp r2, 0
	bne _0803EB8C
	mov r5, r8
	adds r4, r7, 0
	adds r2, r3, 0
_0803EB62:
	ldrb r1, [r5]
	lsrs r1, 1
	ldr r0, [r4]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	lsrs r0, 1
	strb r0, [r1]
	ldrb r0, [r2, 0x2]
	adds r0, 0x1
	strb r0, [r2, 0x2]
	ldrb r0, [r5]
	lsrs r0, 1
	ldr r1, [r4]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0803EB62
_0803EB8C:
	ldrb r0, [r3, 0x2]
	adds r0, 0xE
	movs r1, 0
	mov r2, r12
	strb r0, [r2, 0x10]
	strb r1, [r2, 0x11]
	b _0803EBDE
	.pool
_0803EBB0:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0803EBCC
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _0803EBD0
	.pool
_0803EBCC:
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
_0803EBD0:
	ldr r0, =gBankAttacker
	mov r8, r0
	ldr r1, =gBattlescriptCurrInstr
	mov r9, r1
	ldr r6, =gUnknown_082DBD3C
	ldr r2, =gFightStateTracker
	mov r10, r2
_0803EBDE:
	mov r1, r8
	ldrb r0, [r1]
	lsrs r0, 1
	ldr r1, [r7]
	adds r0, r1
	adds r0, 0xC4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	mov r2, r9
	str r0, [r2]
_0803EBF6:
	movs r0, 0xA
	mov r1, r10
	strb r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803E90C

	thumb_func_start sub_803EC20
sub_803EC20: @ 803EC20
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r5
	adds r1, r0, r1
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0803EC54
	ldr r1, =gEnigmaBerries
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x7]
	b _0803EC5E
	.pool
_0803EC54:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r1, r0, 24
_0803EC5E:
	ldr r0, =gStringBank
	strb r5, [r0]
	cmp r1, 0x25
	bne _0803EC9C
	ldr r2, =gLastUsedItem
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r5
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	strh r0, [r2]
	ldr r0, =gProtectStructs
	lsls r2, r5, 4
	adds r2, r0
	ldrb r1, [r2, 0x1]
	movs r0, 0x19
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x1]
	b _0803ED70
	.pool
_0803EC9C:
	ldr r0, =gBattleMons
	mov r10, r0
	movs r2, 0x58
	mov r9, r2
	mov r0, r9
	muls r0, r5
	add r0, r10
	mov r8, r0
	adds r0, 0x20
	ldrb r6, [r0]
	cmp r6, 0x32
	bne _0803ED5C
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0803ED38
	ldr r4, =gBattleStruct
	ldr r1, [r4]
	adds r1, 0x6C
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_81A9E28
	lsls r0, 24
	lsrs r1, r0, 24
	mov r2, r8
	ldrh r0, [r2, 0x6]
	muls r0, r1
	movs r2, 0x1
	adds r1, r5, 0
	eors r1, r2
	mov r2, r9
	muls r2, r1
	adds r1, r2, 0
	add r1, r10
	ldrh r1, [r1, 0x6]
	bl __divsi3
	ldr r1, [r4]
	adds r1, 0x6C
	ldrb r2, [r1]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	bl Random
	movs r1, 0xFF
	ands r1, r0
	cmp r4, r1
	bhi _0803ED0C
	b _0803EE12
_0803ED0C:
	ldr r0, =gLastUsedAbility
	strb r6, [r0]
	ldr r0, =gProtectStructs
	lsls r2, r5, 4
	adds r2, r0
	ldrb r1, [r2, 0x1]
	movs r0, 0x19
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x1]
	b _0803ED70
	.pool
_0803ED38:
	ldr r0, =gLastUsedAbility
	strb r6, [r0]
	ldr r0, =gProtectStructs
	lsls r2, r5, 4
	adds r2, r0
	ldrb r1, [r2, 0x1]
	movs r0, 0x19
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x1]
	b _0803ED70
	.pool
_0803ED5C:
	ldr r1, =gBattleTypeFlags
	ldr r2, [r1]
	ldr r0, =0x043f0100
	ands r0, r2
	cmp r0, 0
	beq _0803ED80
	movs r0, 0x8
	ands r2, r0
	cmp r2, 0
	beq _0803ED80
_0803ED70:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	b _0803EE12
	.pool
_0803ED80:
	ldr r0, [r1]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0803EE06
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0803EDBC
	bl sub_81A9E28
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r4, =gBattleMons
	movs r3, 0x58
	adds r0, r5, 0
	muls r0, r3
	adds r0, r4
	ldrh r0, [r0, 0x6]
	muls r0, r1
	movs r2, 0x1
	adds r1, r5, 0
	eors r1, r2
	muls r1, r3
	adds r1, r4
	b _0803EDDA
	.pool
_0803EDBC:
	ldr r3, =gBattleMons
	movs r2, 0x58
	adds r0, r5, 0
	muls r0, r2
	adds r4, r0, r3
	movs r1, 0x1
	adds r0, r5, 0
	eors r0, r1
	muls r0, r2
	adds r1, r0, r3
	ldrh r0, [r4, 0x6]
	ldrh r2, [r1, 0x6]
	cmp r0, r2
	bcs _0803EE00
	lsls r0, 7
_0803EDDA:
	ldrh r1, [r1, 0x6]
	bl __divsi3
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r1, 0x6C
	ldrb r2, [r1]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	bl Random
	movs r1, 0xFF
	ands r1, r0
	cmp r4, r1
	bls _0803EE06
_0803EE00:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_0803EE06:
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, 0x6C
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0803EE12:
	cmp r7, 0
	beq _0803EE24
	ldr r1, =gUnknown_02024082
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, =gBattleOutcome
	movs r0, 0x4
	strb r0, [r1]
_0803EE24:
	adds r0, r7, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_803EC20

	thumb_func_start sub_803EE48
sub_803EE48: @ 803EE48
	push {r4-r6,lr}
	ldr r4, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r5, =gUnknown_02024082
	ldrb r0, [r5]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0803EF0C
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	strb r1, [r5]
	ldr r2, =gActiveBank
	movs r0, 0
	strb r0, [r2]
	lsls r1, 24
	cmp r1, 0
	beq _0803EEE0
	adds r4, r2, 0
	ldr r6, =gUnknown_0202421C
	ldr r5, =gBattleOutcome
_0803EE7C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803EEBC
	ldrb r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0803EECE
	ldrb r0, [r5]
	movs r1, 0x2
	b _0803EECA
	.pool
_0803EEBC:
	ldrb r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0803EECE
	ldrb r0, [r5]
	movs r1, 0x1
_0803EECA:
	orrs r0, r1
	strb r0, [r5]
_0803EECE:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803EE7C
_0803EEE0:
	ldr r2, =gBattleOutcome
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x8
	orrs r0, r2
	b _0803EF96
	.pool
_0803EF0C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803EF4C
	ldrb r0, [r4]
	bl sub_803EC20
	lsls r0, 24
	cmp r0, 0
	bne _0803EF98
	ldrb r0, [r4]
	bl sub_8045868
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAB02
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	b _0803EF96
	.pool
_0803EF4C:
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0400e000
	ands r0, r1
	cmp r0, 0
	beq _0803EF8C
	ldr r1, =gBattleCommunication
	movs r0, 0x4
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAB02
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	b _0803EF96
	.pool
_0803EF8C:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r1, =gBattleOutcome
	movs r0, 0x6
_0803EF96:
	strb r0, [r1]
_0803EF98:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803EE48

	thumb_func_start sub_803EFA8
sub_803EFA8: @ 803EFA8
	ldr r2, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_803EFA8

	thumb_func_start bs5_8016AC0
bs5_8016AC0: @ 803EFF0
	ldr r2, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r1, =gNumSafariBalls
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	ldr r1, =gLastUsedItem
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD08
	ldr r0, [r0, 0x14]
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end bs5_8016AC0

	thumb_func_start sub_803F050
sub_803F050: @ 803F050
	push {r4-r6,lr}
	ldr r3, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r6, =gBattleCommunication
	ldr r2, =gBattleBufferB
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x1
	strb r0, [r6, 0x5]
	ldr r1, =gLastUsedItem
	ldrb r0, [r3]
	lsls r0, 9
	adds r2, 0x2
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x1F]
	cmp r0, 0xFE
	bhi _0803F096
	adds r0, 0x1
	strb r0, [r1, 0x1F]
_0803F096:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r1, r0, 0
	adds r1, 0x7A
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _0803F0A8
	adds r0, 0x1
	strb r0, [r1]
_0803F0A8:
	ldr r0, [r2]
	adds r3, r0, 0
	adds r3, 0x7B
	ldrb r5, [r3]
	adds r4, r5, 0
	cmp r4, 0x1
	bls _0803F100
	ldr r2, =gUnknown_0831BCE0
	adds r0, 0x7A
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	ldrb r6, [r6, 0x5]
	adds r0, r6
	adds r0, r2
	ldrb r0, [r0]
	cmp r4, r0
	bcs _0803F0FC
	movs r0, 0x1
	b _0803F0FE
	.pool
_0803F0FC:
	subs r0, r5, r0
_0803F0FE:
	strb r0, [r3]
_0803F100:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0, 0x8]
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F050

	thumb_func_start sub_803F120
sub_803F120: @ 803F120
	push {r4,lr}
	ldr r2, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gUnknown_02022E14
	movs r4, 0
	strh r4, [r0]
	ldr r0, =gUnknown_02022E16
	strh r4, [r0]
	ldr r3, =gBattleStruct
	ldr r0, [r3]
	adds r2, r0, 0
	adds r2, 0x7C
	ldr r1, =gUnknown_0831BCEF
	adds r0, 0x79
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x7C
	ldrb r0, [r1]
	cmp r0, 0x14
	bls _0803F162
	movs r0, 0x14
	strb r0, [r1]
_0803F162:
	ldr r0, [r3]
	adds r2, r0, 0
	adds r2, 0x7B
	ldr r1, =gUnknown_0831BCF3
	adds r0, 0x79
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x7B
	ldrb r0, [r1]
	cmp r0, 0x14
	bls _0803F188
	movs r0, 0x14
	strb r0, [r1]
_0803F188:
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x79
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _0803F1C4
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	b _0803F1CA
	.pool
_0803F1C4:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
_0803F1CA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0, 0x4]
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F120

	thumb_func_start bs8_exit_by_flight
bs8_exit_by_flight: @ 803F1F0
	push {r4,lr}
	ldr r2, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r4, =gUnknown_02024082
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0x11
	bl PlaySE
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, =gBattleOutcome
	movs r0, 0x4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bs8_exit_by_flight

	thumb_func_start bs9_8016C9C
bs9_8016C9C: @ 803F22C
	ldr r3, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r0, =gUnknown_02024082
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	strb r2, [r3]
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	strb r2, [r1, 0x2]
	ldr r2, =gBattlePartyID
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0, 0xC]
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xA
	strb r0, [r1]
	ldr r1, =gUnknown_0202407A
	movs r0, 0xC
	strb r0, [r1, 0x1]
	bx lr
	.pool
	thumb_func_end bs9_8016C9C

	thumb_func_start bsB_exit_by_move
bsB_exit_by_move: @ 803F2A4
	push {lr}
	bl sub_8041728
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0803F2C0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4D
	strb r1, [r0]
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	strb r0, [r1]
_0803F2C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bsB_exit_by_move

	thumb_func_start bsD_proceed
bsD_proceed: @ 803F2CC
	ldr r1, =gUnknown_02024082
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r3, =gFightStateTracker
	ldr r2, =gUnknown_0202407A
	ldrb r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xf1e892af
	ands r0, r1
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end bsD_proceed

	thumb_func_start bsC_8016D70
bsC_8016D70: @ 803F300
	push {r4-r6,lr}
	ldr r1, =gTurnOrder
	ldr r2, =gUnknown_02024082
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	ldr r6, =gBattleStruct
	ldr r1, [r6]
	adds r0, r1
	adds r0, 0x5C
	movs r1, 0x6
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldr r3, =gFightStateTracker
	ldr r1, =gUnknown_0202407A
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	bl sub_803D6A0
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xf1e892af
	ands r0, r1
	str r0, [r2]
	ldr r0, =gCurrentMove
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattleMoveDamage
	movs r4, 0
	str r4, [r0]
	ldr r0, =gBattleMoveFlags
	strb r1, [r0]
	ldr r5, =gBattleScripting
	strb r1, [r5, 0x18]
	strb r1, [r5, 0x19]
	ldr r2, =gUnknown_02024250
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	strh r4, [r0]
	ldr r2, =gUnknown_02024258
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	strh r4, [r0]
	ldr r0, [r6]
	strb r1, [r0, 0x13]
	ldr r0, =gDynamicBasePower
	strh r4, [r0]
	strb r1, [r5, 0x14]
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x3]
	strb r1, [r0, 0x4]
	strb r1, [r5, 0x16]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0x20
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bsC_8016D70

	thumb_func_start get_battle_side_of_something
get_battle_side_of_something: @ 803F3CC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0
	cmp r1, 0xE
	bhi _0803F47A
	lsls r0, r1, 2
	ldr r1, =_0803F3E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803F3E8:
	.4byte _0803F424
	.4byte _0803F430
	.4byte _0803F43C
	.4byte _0803F458
	.4byte _0803F464
	.4byte _0803F458
	.4byte _0803F464
	.4byte _0803F448
	.4byte _0803F464
	.4byte _0803F464
	.4byte _0803F44C
	.4byte _0803F464
	.4byte _0803F468
	.4byte _0803F46C
	.4byte _0803F470
_0803F424:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F430:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F43C:
	ldr r0, =gUnknown_0202420E
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F448:
	movs r0, 0
	b _0803F47A
_0803F44C:
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	b _0803F47A
	.pool
_0803F458:
	ldr r0, =gUnknown_0202420D
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F464:
	movs r0, 0
	b _0803F472
_0803F468:
	movs r0, 0x1
	b _0803F472
_0803F46C:
	movs r0, 0x2
	b _0803F472
_0803F470:
	movs r0, 0x3
_0803F472:
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
_0803F47A:
	pop {r1}
	bx r1
	thumb_func_end get_battle_side_of_something

	thumb_func_start sub_803F480
sub_803F480: @ 803F480
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gBattleMons
	movs r4, 0x58
	muls r0, r4
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	mov r12, r1
	cmp r0, 0x2E
	bne _0803F532
	movs r3, 0
	adds r0, r5, 0
	muls r0, r4
	adds r1, 0xC
	adds r1, r0, r1
	b _0803F4BC
	.pool
_0803F4B4:
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	bgt _0803F4C2
_0803F4BC:
	ldrh r0, [r1]
	cmp r0, r2
	bne _0803F4B4
_0803F4C2:
	cmp r3, 0x4
	beq _0803F532
	movs r7, 0x58
	adds r2, r5, 0
	muls r2, r7
	adds r0, r3, r2
	mov r6, r12
	adds r6, 0x24
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803F4DE
	subs r0, 0x1
	strb r0, [r1]
_0803F4DE:
	mov r0, r12
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0803F532
	ldr r1, =gDisableStructs
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803F532
	ldr r4, =gActiveBank
	strb r5, [r4]
	adds r1, r3, 0
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r4]
	muls r0, r7
	adds r0, r6
	adds r0, r3
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803F532:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F480

	thumb_func_start sub_803F548
sub_803F548: @ 803F548
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x4
	mov r8, r0
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bge _0803F5F0
	ldr r1, =gBattleMons
	movs r0, 0x58
	adds r7, r5, 0
	muls r7, r0
	adds r1, 0xC
	mov r10, r1
_0803F57E:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	adds r6, r4, 0x1
	cmp r9, r0
	beq _0803F5E6
	ldr r0, =gBattleMons
	movs r3, 0x58
	adds r1, r4, 0
	muls r1, r3
	adds r1, r0
	adds r1, 0x20
	ldrb r1, [r1]
	adds r4, r0, 0
	cmp r1, 0x2E
	bne _0803F5E6
	movs r2, 0
	adds r0, r5, 0
	muls r0, r3
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x8F
	lsls r1, 1
	cmp r0, r1
	beq _0803F5CE
	adds r3, r1, 0
	mov r0, r10
	adds r1, r7, r0
_0803F5C0:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0803F5CE
	ldrh r0, [r1]
	cmp r0, r3
	bne _0803F5C0
_0803F5CE:
	cmp r2, 0x4
	beq _0803F5E6
	mov r8, r2
	adds r1, r2, r7
	adds r0, r4, 0
	adds r0, 0x24
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803F5E6
	subs r0, 0x1
	strb r0, [r1]
_0803F5E6:
	adds r4, r6, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803F57E
_0803F5F0:
	mov r1, r8
	cmp r1, 0x4
	beq _0803F658
	ldr r6, =gBattleMons
	movs r3, 0x58
	adds r0, r5, 0
	muls r0, r3
	adds r1, r6, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0803F658
	ldr r1, =gDisableStructs
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	mov r4, r8
	lsls r0, r4, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803F658
	ldr r4, =gActiveBank
	strb r5, [r4]
	mov r1, r8
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r4]
	muls r0, r3
	adds r2, r6, 0
	adds r2, 0x24
	adds r0, r2
	add r0, r8
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803F658:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F548

	thumb_func_start sub_803F67C
sub_803F67C: @ 803F67C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r3, r0, 24
	movs r6, 0x4
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	mov r8, r0
	ldrb r0, [r0]
	cmp r1, r0
	bge _0803F6FE
	ldr r7, =gBattleMons
	movs r2, 0x58
	mov r12, r2
	mov r5, r12
	muls r5, r3
	adds r0, r7, 0
	adds r0, 0xC
	adds r2, r5, r0
	mov r10, r2
	mov r9, r5
_0803F6AE:
	mov r0, r12
	muls r0, r1
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	adds r4, r1, 0x1
	cmp r0, 0x2E
	bne _0803F6F4
	cmp r1, r3
	beq _0803F6F4
	movs r2, 0
	mov r1, r10
	ldrh r0, [r1]
	cmp r0, 0xC3
	beq _0803F6DE
	ldr r1, =gBattleMons + 0xC
	add r1, r9
_0803F6D0:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0803F6DE
	ldrh r0, [r1]
	cmp r0, 0xC3
	bne _0803F6D0
_0803F6DE:
	cmp r2, 0x4
	beq _0803F6F4
	adds r6, r2, 0
	adds r0, r6, r5
	ldr r2, =gBattleMons + 0x24
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803F6F4
	subs r0, 0x1
	strb r0, [r1]
_0803F6F4:
	adds r1, r4, 0
	mov r0, r8
	ldrb r0, [r0]
	cmp r1, r0
	blt _0803F6AE
_0803F6FE:
	cmp r6, 0x4
	beq _0803F762
	ldr r7, =gBattleMons
	movs r5, 0x58
	adds r0, r3, 0
	muls r0, r5
	adds r1, r7, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0803F762
	ldr r1, =gDisableStructs
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r6, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803F762
	ldr r4, =gActiveBank
	strb r3, [r4]
	adds r1, r6, 0
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r4]
	muls r0, r5
	adds r2, r7, 0
	adds r2, 0x24
	adds r0, r2
	adds r0, r6
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0803F762:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F67C

	thumb_func_start sub_803F790
sub_803F790: @ 803F790
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803F7D0
	movs r2, 0
	ldr r4, =gNoOfAllBanks
	ldrb r0, [r4]
	cmp r2, r0
	bge _0803F7EE
	ldr r3, =gBattleExecBuffer
	ldr r5, =gBitTable
_0803F7AC:
	ldm r5!, {r1}
	lsls r1, 28
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r2, 0x1
	ldrb r0, [r4]
	cmp r2, r0
	blt _0803F7AC
	b _0803F7EE
	.pool
_0803F7D0:
	movs r2, 0
	ldr r4, =gNoOfAllBanks
	ldrb r0, [r4]
	cmp r2, r0
	bge _0803F7EE
	ldr r3, =gBattleExecBuffer
	ldr r5, =gBitTable
_0803F7DE:
	ldr r0, [r3]
	ldm r5!, {r1}
	orrs r0, r1
	str r0, [r3]
	adds r2, 0x1
	ldrb r0, [r4]
	cmp r2, r0
	blt _0803F7DE
_0803F7EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F790

	thumb_func_start dp01_battle_side_mark_buffer_for_execution
dp01_battle_side_mark_buffer_for_execution: @ 803F800
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803F834
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _0803F844
	.pool
_0803F834:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r2]
_0803F844:
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_battle_side_mark_buffer_for_execution

	thumb_func_start sub_803F850
sub_803F850: @ 803F850
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0
	ldr r5, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r7, 2
	adds r6, r0, r1
	b _0803F87A
	.pool
_0803F86C:
	lsls r0, r4, 2
	ldr r1, [r6]
	lsls r1, r0
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r4, 0x1
_0803F87A:
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _0803F86C
	ldr r2, =gBattleExecBuffer
	movs r1, 0x80
	lsls r1, 21
	lsls r1, r7
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F850

	thumb_func_start CancelMultiTurnMoves
CancelMultiTurnMoves: @ 803F8A0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleMons
	movs r2, 0x58
	adds r3, r0, 0
	muls r3, r2
	adds r1, 0x50
	adds r3, r1
	ldr r1, [r3]
	ldr r2, =0xffffefff
	ands r1, r2
	ldr r2, =0xfffff3ff
	ands r1, r2
	movs r2, 0x71
	negs r2, r2
	ands r1, r2
	ldr r2, =0xfffffcff
	ands r1, r2
	str r1, [r3]
	ldr r1, =gStatuses3
	lsls r2, r0, 2
	adds r2, r1
	ldr r1, [r2]
	ldr r3, =0xfffbff3f
	ands r1, r3
	str r1, [r2]
	ldr r2, =gDisableStructs
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x11]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x11]
	movs r0, 0
	strb r0, [r1, 0x10]
	bx lr
	.pool
	thumb_func_end CancelMultiTurnMoves

	thumb_func_start sub_803F90C
sub_803F90C: @ 803F90C
	push {lr}
	lsls r0, 24
	ldr r1, =gProtectStructs
	lsrs r0, 20
	adds r1, r0, r1
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	bne _0803F952
	ldrb r2, [r1, 0x1]
	lsls r0, r2, 30
	cmp r0, 0
	blt _0803F952
	lsls r0, r2, 26
	cmp r0, 0
	blt _0803F952
	lsls r0, r2, 25
	cmp r0, 0
	blt _0803F952
	lsrs r0, r2, 7
	cmp r0, 0
	bne _0803F952
	ldrb r1, [r1, 0x2]
	lsls r0, r1, 31
	cmp r0, 0
	bne _0803F952
	lsls r0, r1, 30
	cmp r0, 0
	blt _0803F952
	lsls r0, r1, 29
	cmp r0, 0
	blt _0803F952
	lsls r0, r2, 31
	cmp r0, 0
	beq _0803F95C
_0803F952:
	movs r0, 0x1
	b _0803F95E
	.pool
_0803F95C:
	movs r0, 0
_0803F95E:
	pop {r1}
	bx r1
	thumb_func_end sub_803F90C

	thumb_func_start b_std_message
b_std_message: @ 803F964
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gActiveBank
	strb r1, [r4]
	movs r0, 0
	adds r1, r2, 0
	bl dp01_build_cmdbuf_x10_TODO
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_std_message

	thumb_func_start sub_803F988
sub_803F988: @ 803F988
	push {r4-r6,lr}
	movs r3, 0
	ldr r0, =gUnknown_020243FE
	strb r3, [r0]
	strb r3, [r0, 0x1]
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	adds r6, r0, 0
	cmp r1, r2
	bge _0803F9B6
	ldr r5, =gBitTable
	adds r4, r2, 0
	ldr r2, =gBattlePartyID
_0803F9A4:
	ldrh r0, [r2]
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	orrs r3, r0
	adds r2, 0x4
	adds r1, 0x2
	cmp r1, r4
	blt _0803F9A4
_0803F9B6:
	movs r1, 0x1
	adds r2, r6, 0
	ldrb r0, [r2]
	cmp r1, r0
	bge _0803F9D6
	ldr r5, =gUnknown_020243FE
	movs r4, 0x2
_0803F9C4:
	adds r0, r1, 0
	ands r0, r4
	asrs r0, 1
	adds r0, r5
	strb r3, [r0]
	adds r1, 0x2
	ldrb r0, [r2]
	cmp r1, r0
	blt _0803F9C4
_0803F9D6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F988

	thumb_func_start sub_803F9EC
sub_803F9EC: @ 803F9EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803FA50
	movs r0, 0x2
	ands r0, r5
	lsls r0, 24
	lsrs r0, 25
	mov r12, r0
	ldr r1, =gUnknown_020243FE
	adds r0, r1
	strb r4, [r0]
	adds r5, r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	mov r8, r1
	cmp r4, r2
	bge _0803FA4A
	ldr r0, =gAbsentBankFlags
	ldrb r7, [r0]
	ldr r1, =gBitTable
	adds r6, r2, 0
	ldr r3, =gBattlePartyID
	adds r2, r1, 0
_0803FA2E:
	ldr r0, [r2]
	ands r0, r7
	cmp r0, 0
	bne _0803FA40
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r4, r0
_0803FA40:
	adds r3, 0x4
	adds r2, 0x8
	adds r5, 0x2
	cmp r5, r6
	blt _0803FA2E
_0803FA4A:
	mov r0, r12
	add r0, r8
	strb r4, [r0]
_0803FA50:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F9EC

	thumb_func_start sub_803FA70
sub_803FA70: @ 803FA70
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803FA8C
	adds r0, r4, 0
	bl sub_803F9EC
	b _0803FAC2
_0803FA8C:
	movs r3, 0x1
	ldr r5, =gNoOfAllBanks
	ldrb r0, [r5]
	cmp r3, r0
	bge _0803FAC2
	ldr r0, =gUnknown_020243FE
	mov r12, r0
	movs r7, 0x2
	ldr r6, =gBitTable
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r4, r0, r1
_0803FAA4:
	adds r2, r3, 0
	ands r2, r7
	asrs r2, 1
	add r2, r12
	ldrh r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r3, 0x1
	ldrb r0, [r5]
	cmp r3, r0
	blt _0803FAA4
_0803FAC2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803FA70
    
    .align 2, 0 @ Don't pad with nop.
    