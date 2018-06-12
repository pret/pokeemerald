	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start Special_ShowDiploma
Special_ShowDiploma: @ 8137CB4
	push {lr}
	ldr r0, =CB2_ShowDiploma
	bl SetMainCallback2
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end Special_ShowDiploma

	thumb_func_start Special_ViewWallClock
Special_ViewWallClock: @ 8137CC8
	push {lr}
	ldr r0, =gMain
	ldr r1, =CB2_ReturnToField
	str r1, [r0, 0x8]
	ldr r0, =Cb2_ViewWallClock
	bl SetMainCallback2
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end Special_ViewWallClock

	thumb_func_start ResetCyclingRoadChallengeData
ResetCyclingRoadChallengeData: @ 8137CEC
	ldr r0, =gBikeCyclingChallenge
	movs r1, 0
	strb r1, [r0]
	ldr r0, =0x0203ab55
	strb r1, [r0]
	ldr r1, =gUnknown_0203AB58
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetCyclingRoadChallengeData

	thumb_func_start Special_BeginCyclingRoadChallenge
Special_BeginCyclingRoadChallenge: @ 8137D0C
	ldr r1, =gBikeCyclingChallenge
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =0x0203ab55
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_0203AB58
	ldr r0, =gMain
	ldr r0, [r0, 0x20]
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end Special_BeginCyclingRoadChallenge

	thumb_func_start GetPlayerAvatarBike
GetPlayerAvatarBike: @ 8137D34
	push {lr}
	movs r0, 0x4
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _08137D46
	movs r0, 0x1
	b _08137D58
_08137D46:
	movs r0, 0x2
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	bne _08137D56
	movs r0, 0
	b _08137D58
_08137D56:
	movs r0, 0x2
_08137D58:
	pop {r1}
	bx r1
	thumb_func_end GetPlayerAvatarBike

	thumb_func_start DetermineCyclingRoadResults
DetermineCyclingRoadResults: @ 8137D5C
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r6, 0x63
	bhi _08137D88
	ldr r4, =gStringVar1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_SpaceTimes
	adds r0, r4, 0
	bl StringAppend
	b _08137D90
	.pool
_08137D88:
	ldr r0, =gStringVar1
	ldr r1, =gText_99TimesPlus
	bl StringCopy
_08137D90:
	ldr r0, =0x00000e0f
	cmp r7, r0
	bhi _08137DF0
	ldr r4, =gStringVar2
	adds r0, r7, 0
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0xAD
	strb r0, [r4, 0x2]
	adds r5, r4, 0x3
	adds r0, r7, 0
	movs r1, 0x3C
	bl __umodsi3
	movs r1, 0x64
	muls r0, r1
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_SpaceSeconds
	adds r0, r4, 0
	bl StringAppend
	b _08137DF8
	.pool
_08137DF0:
	ldr r0, =gStringVar2
	ldr r1, =gText_1MinutePlus
	bl StringCopy
_08137DF8:
	movs r4, 0
	cmp r6, 0
	bne _08137E0C
	movs r4, 0x5
	b _08137E2A
	.pool
_08137E0C:
	cmp r6, 0x3
	bhi _08137E14
	movs r4, 0x4
	b _08137E2A
_08137E14:
	cmp r6, 0x9
	bhi _08137E1C
	movs r4, 0x3
	b _08137E2A
_08137E1C:
	cmp r6, 0x13
	bhi _08137E24
	movs r4, 0x2
	b _08137E2A
_08137E24:
	cmp r6, 0x63
	bhi _08137E2A
	movs r4, 0x1
_08137E2A:
	adds r0, r7, 0
	movs r1, 0x3C
	bl __udivsi3
	cmp r0, 0xA
	bhi _08137E3A
	adds r0, r4, 0x5
	b _08137E58
_08137E3A:
	cmp r0, 0xF
	bhi _08137E42
	adds r0, r4, 0x4
	b _08137E58
_08137E42:
	cmp r0, 0x14
	bhi _08137E4A
	adds r0, r4, 0x3
	b _08137E58
_08137E4A:
	cmp r0, 0x28
	bhi _08137E52
	adds r0, r4, 0x2
	b _08137E58
_08137E52:
	cmp r0, 0x3B
	bhi _08137E5C
	adds r0, r4, 0x1
_08137E58:
	lsls r0, 24
	lsrs r4, r0, 24
_08137E5C:
	ldr r0, =gSpecialVar_Result
	strh r4, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DetermineCyclingRoadResults

	thumb_func_start FinishCyclingRoadChallenge
FinishCyclingRoadChallenge: @ 8137E6C
	push {r4,r5,lr}
	ldr r0, =gMain
	ldr r1, =gUnknown_0203AB58
	ldr r4, [r0, 0x20]
	ldr r0, [r1]
	subs r4, r0
	ldr r5, =0x0203ab55
	ldrb r1, [r5]
	adds r0, r4, 0
	bl DetermineCyclingRoadResults
	ldrb r1, [r5]
	adds r0, r4, 0
	bl RecordCyclingRoadResults
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FinishCyclingRoadChallenge

	thumb_func_start RecordCyclingRoadResults
RecordCyclingRoadResults: @ 8137E9C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r6, =0x00004028
	adds r0, r6, 0
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r7, =0x00004029
	adds r0, r7, 0
	bl VarGet
	lsls r0, 16
	adds r4, r0
	cmp r4, r5
	bhi _08137ECC
	cmp r4, 0
	bne _08137EE6
_08137ECC:
	lsls r1, r5, 16
	lsrs r1, 16
	adds r0, r6, 0
	bl VarSet
	lsrs r1, r5, 16
	adds r0, r7, 0
	bl VarSet
	ldr r0, =0x00004027
	mov r1, r8
	bl VarSet
_08137EE6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RecordCyclingRoadResults

	thumb_func_start GetRecordedCyclingRoadResults
GetRecordedCyclingRoadResults: @ 8137EFC
	push {r4,lr}
	ldr r0, =0x00004028
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004029
	bl VarGet
	lsls r0, 16
	adds r4, r0
	cmp r4, 0
	beq _08137F3C
	ldr r0, =0x00004027
	bl VarGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl DetermineCyclingRoadResults
	movs r0, 0x1
	b _08137F3E
	.pool
_08137F3C:
	movs r0, 0
_08137F3E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetRecordedCyclingRoadResults

	thumb_func_start UpdateCyclingRoadState
UpdateCyclingRoadState: @ 8137F44
	push {r4,lr}
	ldr r0, =gUnknown_020322DC
	ldrh r1, [r0]
	ldr r0, =0x00000c1d
	cmp r1, r0
	beq _08137F7C
	ldr r4, =0x000040a9
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	beq _08137F6E
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bne _08137F7C
_08137F6E:
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	movs r0, 0
	bl Overworld_SetSavedMusic
_08137F7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateCyclingRoadState

	thumb_func_start SetSSTidalFlag
SetSSTidalFlag: @ 8137F90
	push {lr}
	ldr r0, =0x0000088d
	bl FlagSet
	ldr r0, =0x0000404a
	bl GetVarPointer
	movs r1, 0
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetSSTidalFlag

	thumb_func_start ResetSSTidalFlag
ResetSSTidalFlag: @ 8137FB0
	push {lr}
	ldr r0, =0x0000088d
	bl FlagClear
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetSSTidalFlag

	thumb_func_start CountSSTidalStep
CountSSTidalStep: @ 8137FC0
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000088d
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08137FE6
	ldr r0, =0x0000404a
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, r4, r1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xCC
	bhi _08137FF4
_08137FE6:
	movs r0, 0
	b _08137FF6
	.pool
_08137FF4:
	movs r0, 0x1
_08137FF6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end CountSSTidalStep

	thumb_func_start GetSSTidalLocation
GetSSTidalLocation: @ 8137FFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, =0x0000404a
	bl GetVarPointer
	adds r4, r0, 0
	ldr r0, =0x000040b4
	bl GetVarPointer
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r0, 0x9
	bhi _081380C2
	lsls r0, 2
	ldr r1, =_08138038
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08138038:
	.4byte _08138060
	.4byte _08138070
	.4byte _08138064
	.4byte _08138068
	.4byte _08138068
	.4byte _0813806C
	.4byte _08138098
	.4byte _08138060
	.4byte _08138064
	.4byte _0813806C
_08138060:
	movs r0, 0x1
	b _081380CE
_08138064:
	movs r0, 0x4
	b _081380CE
_08138068:
	movs r0, 0x2
	b _081380CE
_0813806C:
	movs r0, 0x3
	b _081380CE
_08138070:
	ldrh r0, [r4]
	cmp r0, 0x3B
	bhi _08138080
	movs r0, 0x31
	strb r0, [r5]
	ldrh r0, [r4]
	adds r0, 0x13
	b _081380C0
_08138080:
	cmp r0, 0x8B
	bhi _0813808E
	movs r0, 0x30
	strb r0, [r5]
	ldrh r0, [r4]
	subs r0, 0x3C
	b _081380C0
_0813808E:
	movs r0, 0x2F
	strb r0, [r5]
	ldrh r0, [r4]
	subs r0, 0x8C
	b _081380C0
_08138098:
	ldrh r0, [r4]
	cmp r0, 0x41
	bhi _081380A8
	movs r0, 0x2F
	strb r0, [r5]
	ldrh r1, [r4]
	movs r0, 0x41
	b _081380BE
_081380A8:
	cmp r0, 0x91
	bhi _081380B6
	movs r0, 0x30
	strb r0, [r5]
	ldrh r1, [r4]
	movs r0, 0x91
	b _081380BE
_081380B6:
	movs r0, 0x31
	strb r0, [r5]
	ldrh r1, [r4]
	movs r0, 0xE0
_081380BE:
	subs r0, r1
_081380C0:
	strh r0, [r6]
_081380C2:
	movs r0, 0
	mov r1, r8
	strb r0, [r1]
	movs r0, 0x14
	strh r0, [r7]
	movs r0, 0
_081380CE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetSSTidalLocation

	thumb_func_start is_tile_that_overrides_player_control
is_tile_that_overrides_player_control: @ 81380D8
	push {lr}
	movs r0, 0x88
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813810A
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _0813810A
	cmp r0, 0x3
	ble _081380F6
	cmp r0, 0x6
	bne _0813810A
_081380F6:
	ldr r0, =0x000040f2
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xF9
	bhi _08138118
_0813810A:
	movs r0, 0
	b _0813811A
	.pool
_08138118:
	movs r0, 0x1
_0813811A:
	pop {r1}
	bx r1
	thumb_func_end is_tile_that_overrides_player_control

	thumb_func_start sub_8138120
sub_8138120: @ 8138120
	push {lr}
	movs r0, 0x8A
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08138152
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _08138152
	cmp r0, 0x3
	ble _0813813E
	cmp r0, 0x6
	bne _08138152
_0813813E:
	ldr r0, =0x000040f3
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x9
	bhi _08138160
_08138152:
	movs r0, 0
	b _08138162
	.pool
_08138160:
	movs r0, 0x1
_08138162:
	pop {r1}
	bx r1
	thumb_func_end sub_8138120

	thumb_func_start sub_8138168
sub_8138168: @ 8138168
	push {lr}
	movs r0, 0x72
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813819A
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _0813819A
	cmp r0, 0x3
	ble _08138186
	cmp r0, 0x6
	bne _0813819A
_08138186:
	ldr r0, =0x000040f5
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x9
	bhi _081381A8
_0813819A:
	movs r0, 0
	b _081381AA
	.pool
_081381A8:
	movs r0, 0x1
_081381AA:
	pop {r1}
	bx r1
	thumb_func_end sub_8138168

	thumb_func_start sub_81381B0
sub_81381B0: @ 81381B0
	push {lr}
	movs r0, 0x80
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081381E2
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _081381E2
	cmp r0, 0x3
	ble _081381CE
	cmp r0, 0x6
	bne _081381E2
_081381CE:
	ldr r0, =0x000040f4
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xF9
	bhi _081381F0
_081381E2:
	movs r0, 0
	b _081381F2
	.pool
_081381F0:
	movs r0, 0x1
_081381F2:
	pop {r1}
	bx r1
	thumb_func_end sub_81381B0

	thumb_func_start sub_81381F8
sub_81381F8: @ 81381F8
	push {lr}
	movs r0, 0x75
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813822A
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _0813822A
	cmp r0, 0x3
	ble _08138216
	cmp r0, 0x6
	bne _0813822A
_08138216:
	ldr r0, =0x000040f6
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xF9
	bhi _08138238
_0813822A:
	movs r0, 0
	b _0813823A
	.pool
_08138238:
	movs r0, 0x1
_0813823A:
	pop {r1}
	bx r1
	thumb_func_end sub_81381F8

	thumb_func_start GetLinkPartnerNames
GetLinkPartnerNames: @ 8138240
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r7, r0, 24
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _0813828A
	ldr r0, =gTVStringVarPtrs
	mov r8, r0
_08138262:
	cmp r7, r4
	beq _08138280
	lsls r0, r6, 2
	add r0, r8
	ldr r0, [r0]
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	ldr r2, =gLinkPlayers + 8
	adds r1, r2
	bl StringCopy
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_08138280:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08138262
_0813828A:
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetLinkPartnerNames

	thumb_func_start SpawnLinkPartnerEventObject
SpawnLinkPartnerEventObject: @ 81382A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r7, 0
	movs r0, 0
	mov r9, r0
	mov r8, r0
	ldr r1, =gUnknown_085B2B5C
	add r0, sp, 0x8
	movs r2, 0x4
	bl memcpy
	add r4, sp, 0xC
	ldr r1, =gUnknown_085B2B60
	adds r0, r4, 0
	movs r2, 0x8
	bl memcpy
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x2
	beq _08138310
	cmp r0, 0x2
	bgt _081382F4
	cmp r0, 0x1
	beq _0813833C
	b _08138350
	.pool
_081382F4:
	cmp r1, 0x3
	beq _081382FE
	cmp r1, 0x4
	beq _08138324
	b _08138350
_081382FE:
	movs r7, 0x2
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1]
	subs r0, 0x1
	b _0813832C
	.pool
_08138310:
	movs r7, 0x1
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0]
	mov r9, r1
	ldrh r0, [r0, 0x2]
	subs r0, 0x1
	b _0813834A
	.pool
_08138324:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
_0813832C:
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldrh r1, [r1, 0x2]
	mov r8, r1
	b _08138350
	.pool
_0813833C:
	movs r7, 0x3
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r3, [r0]
	mov r9, r3
	ldrh r0, [r0, 0x2]
	adds r0, 0x1
_0813834A:
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_08138350:
	movs r6, 0
	b _08138410
	.pool
_08138358:
	cmp r10, r6
	beq _0813840A
	ldr r0, =gLinkPlayers
	lsls r2, r6, 3
	subs r1, r2, r6
	lsls r1, 2
	adds r1, r0
	ldrb r3, [r1]
	adds r4, r0, 0
	cmp r3, 0x1
	blt _0813838C
	cmp r3, 0x2
	ble _0813837C
	cmp r3, 0x3
	beq _08138388
	b _0813838C
	.pool
_0813837C:
	ldrb r0, [r1, 0x13]
	movs r5, 0xEC
	cmp r0, 0
	bne _0813839C
	movs r5, 0xEB
	b _0813839C
_08138388:
	ldrb r0, [r1, 0x13]
	b _08138394
_0813838C:
	subs r0, r2, r6
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x13]
_08138394:
	movs r5, 0x69
	cmp r0, 0
	bne _0813839C
	movs r5, 0x64
_0813839C:
	mov r0, sp
	adds r0, r7
	adds r0, 0x8
	ldrb r1, [r0]
	movs r4, 0xF0
	subs r4, r6
	lsls r4, 24
	lsrs r4, 24
	lsls r2, r7, 1
	mov r0, sp
	adds r0, r2
	adds r0, 0xC
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r3, r9
	lsls r3, 16
	asrs r3, 16
	mov r12, r3
	add r0, r12
	adds r3, r0, 0x7
	lsls r3, 16
	asrs r3, 16
	mov r12, r3
	mov r0, sp
	adds r0, 0xD
	adds r0, r2
	movs r2, 0
	ldrsb r2, [r0, r2]
	mov r3, r8
	lsls r0, r3, 16
	asrs r0, 16
	adds r0, r2
	adds r0, 0x7
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r2, r4, 0
	mov r3, r12
	bl SpawnSpecialEventObjectParametrized
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_813842C
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x4
	bne _0813840A
	movs r7, 0
_0813840A:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_08138410:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r6, r0
	bcc _08138358
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpawnLinkPartnerEventObject

	thumb_func_start sub_813842C
sub_813842C: @ 813842C
	push {r4,r5,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 24
	movs r1, 0xC0
	lsls r1, 19
	adds r2, r1
	lsrs r5, r2, 24
	lsrs r4, r0, 24
	movs r2, 0xA8
	lsls r2, 21
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bls _08138454
	cmp r4, 0x64
	beq _08138454
	cmp r4, 0x69
	bne _081384E6
_08138454:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	adds r0, r3, 0
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x10
	beq _081384E6
	ldr r1, =gEventObjects
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	lsls r3, r5, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	cmp r4, 0x69
	beq _081384D8
	cmp r4, 0x69
	bgt _081384A8
	cmp r4, 0x64
	beq _081384C4
	b _081384E6
	.pool
_081384A8:
	cmp r4, 0xEB
	beq _081384B2
	cmp r4, 0xEC
	beq _081384BC
	b _081384E6
_081384B2:
	ldr r0, =gEventObjectPalette33
	b _081384C6
	.pool
_081384BC:
	ldr r0, =gEventObjectPalette34
	b _081384C6
	.pool
_081384C4:
	ldr r0, =gEventObjectPalette8
_081384C6:
	movs r2, 0x80
	lsls r2, 1
	adds r1, r3, r2
	movs r2, 0x20
	bl LoadPalette
	b _081384E6
	.pool
_081384D8:
	ldr r0, =gEventObjectPalette17
	movs r2, 0x80
	lsls r2, 1
	adds r1, r3, r2
	movs r2, 0x20
	bl LoadPalette
_081384E6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813842C

	thumb_func_start MauvilleGymSpecial1
MauvilleGymSpecial1: @ 81384F0
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_085B2B68
_081384F6:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r4, r0
	bne _0813851C
	lsls r1, r4, 2
	adds r1, r5
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	ldr r2, =0x00000206
	bl MapGridSetMetatileIdAt
	b _0813852A
	.pool
_0813851C:
	lsls r1, r4, 2
	adds r1, r5
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	ldr r2, =0x00000205
	bl MapGridSetMetatileIdAt
_0813852A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081384F6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MauvilleGymSpecial1

	thumb_func_start MauvilleGymSpecial2
MauvilleGymSpecial2: @ 8138540
	push {r4-r6,lr}
	movs r5, 0xC
_08138544:
	movs r4, 0x7
	adds r6, r5, 0x1
_08138548:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffde6
	adds r0, r1
	cmp r0, 0x37
	bls _0813855A
	b _08138734
_0813855A:
	lsls r0, 2
	ldr r1, =_0813856C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813856C:
	.4byte _081386F2
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813864C
	.4byte _08138652
	.4byte _0813868C
	.4byte _08138694
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813865C
	.4byte _08138662
	.4byte _0813869C
	.4byte _081386A4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813866C
	.4byte _08138672
	.4byte _081386AC
	.4byte _081386B4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813867C
	.4byte _08138684
	.4byte _081386BC
	.4byte _081386C4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _081386CC
	.4byte _081386DC
	.4byte _081386EC
	.4byte _08138714
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _081386D4
	.4byte _081386E4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813872A
	.4byte _0813871C
_0813864C:
	movs r2, 0x8C
	lsls r2, 2
	b _08138720
_08138652:
	ldr r2, =0x00000231
	b _08138720
	.pool
_0813865C:
	movs r2, 0x8E
	lsls r2, 2
	b _08138720
_08138662:
	ldr r2, =0x00000239
	b _08138720
	.pool
_0813866C:
	movs r2, 0x88
	lsls r2, 2
	b _08138720
_08138672:
	ldr r2, =0x00000221
	b _08138720
	.pool
_0813867C:
	ldr r2, =0x00000e28
	b _08138720
	.pool
_08138684:
	ldr r2, =0x00000e29
	b _08138720
	.pool
_0813868C:
	ldr r2, =0x00000232
	b _08138720
	.pool
_08138694:
	ldr r2, =0x00000233
	b _08138720
	.pool
_0813869C:
	ldr r2, =0x0000023a
	b _08138720
	.pool
_081386A4:
	ldr r2, =0x0000023b
	b _08138720
	.pool
_081386AC:
	ldr r2, =0x00000222
	b _08138720
	.pool
_081386B4:
	ldr r2, =0x00000223
	b _08138720
	.pool
_081386BC:
	ldr r2, =0x00000e2a
	b _08138720
	.pool
_081386C4:
	ldr r2, =0x00000e2b
	b _08138720
	.pool
_081386CC:
	ldr r2, =0x00000e42
	b _08138720
	.pool
_081386D4:
	ldr r2, =0x0000021a
	b _08138720
	.pool
_081386DC:
	ldr r2, =0x00000e43
	b _08138720
	.pool
_081386E4:
	ldr r2, =0x0000021a
	b _08138720
	.pool
_081386EC:
	movs r2, 0xE4
	lsls r2, 4
	b _08138720
_081386F2:
	subs r1, r5, 0x1
	adds r0, r4, 0
	bl MapGridGetMetatileIdAt
	movs r1, 0x90
	lsls r1, 2
	cmp r0, r1
	bne _0813870C
	ldr r2, =0x00000e48
	b _08138720
	.pool
_0813870C:
	ldr r2, =0x00000e49
	b _08138720
	.pool
_08138714:
	ldr r2, =0x00000e41
	b _08138720
	.pool
_0813871C:
	movs r2, 0xE5
	lsls r2, 4
_08138720:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _08138734
_0813872A:
	ldr r2, =0x00000251
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_08138734:
	adds r4, 0x1
	cmp r4, 0xF
	bgt _0813873C
	b _08138548
_0813873C:
	adds r5, r6, 0
	cmp r5, 0x17
	bgt _08138744
	b _08138544
_08138744:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MauvilleGymSpecial2

	thumb_func_start MauvilleGymSpecial3
MauvilleGymSpecial3: @ 8138750
	push {r4-r6,lr}
	ldr r4, =gUnknown_085B2B68
	movs r5, 0x3
_08138756:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	ldr r2, =0x00000206
	bl MapGridSetMetatileIdAt
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08138756
	movs r5, 0xC
_0813876A:
	movs r4, 0x7
	adds r6, r5, 0x1
_0813876E:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffde0
	adds r0, r1
	cmp r0, 0x30
	bls _08138780
	b _081388CA
_08138780:
	lsls r0, 2
	ldr r1, =_0813879C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813879C:
	.4byte _08138860
	.4byte _08138866
	.4byte _08138880
	.4byte _08138888
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _08138870
	.4byte _08138876
	.4byte _08138890
	.4byte _08138898
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388A0
	.4byte _081388A8
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388B0
	.4byte _081388B0
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388C0
_08138860:
	movs r2, 0x8C
	lsls r2, 2
	b _081388B2
_08138866:
	ldr r2, =0x00000231
	b _081388B2
	.pool
_08138870:
	movs r2, 0x8E
	lsls r2, 2
	b _081388B2
_08138876:
	ldr r2, =0x00000239
	b _081388B2
	.pool
_08138880:
	ldr r2, =0x00000232
	b _081388B2
	.pool
_08138888:
	ldr r2, =0x00000233
	b _081388B2
	.pool
_08138890:
	ldr r2, =0x0000023a
	b _081388B2
	.pool
_08138898:
	ldr r2, =0x0000023b
	b _081388B2
	.pool
_081388A0:
	ldr r2, =0x00000e42
	b _081388B2
	.pool
_081388A8:
	ldr r2, =0x00000e43
	b _081388B2
	.pool
_081388B0:
	ldr r2, =0x0000021a
_081388B2:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _081388CA
	.pool
_081388C0:
	ldr r2, =0x00000251
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_081388CA:
	adds r4, 0x1
	cmp r4, 0xF
	bgt _081388D2
	b _0813876E
_081388D2:
	adds r5, r6, 0
	cmp r5, 0x17
	bgt _081388DA
	b _0813876A
_081388DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MauvilleGymSpecial3

	thumb_func_start PetalburgGymSpecial1
PetalburgGymSpecial1: @ 81388E4
	push {lr}
	ldr r0, =gUnknown_0203AB5C
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_0203AB5D
	strb r1, [r0]
	movs r0, 0x2C
	bl PlaySE
	ldr r0, =Task_PetalburgGym
	movs r1, 0x8
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end PetalburgGymSpecial1

	thumb_func_start Task_PetalburgGym
Task_PetalburgGym: @ 8138910
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_085B2B78
	ldr r5, =gUnknown_0203AB5D
	ldrb r1, [r5]
	adds r0, r1, r0
	ldr r4, =gUnknown_0203AB5C
	ldrb r2, [r4]
	ldrb r0, [r0]
	cmp r0, r2
	bne _0813896C
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	ldr r2, =gUnknown_085B2B7E
	lsls r1, 1
	adds r1, r2
	ldrh r1, [r1]
	bl PetalburgGymFunc
	movs r0, 0
	strb r0, [r4]
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08138970
	adds r0, r6, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	b _08138970
	.pool
_0813896C:
	adds r0, r2, 0x1
	strb r0, [r4]
_08138970:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end Task_PetalburgGym

	thumb_func_start PetalburgGymFunc
PetalburgGymFunc: @ 8138978
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r2, r1, 16
	movs r7, 0
	subs r0, 0x1
	cmp r0, 0x7
	bhi _08138A40
	lsls r0, 2
	ldr r1, =_081389A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081389A0:
	.4byte _081389C0
	.4byte _081389D2
	.4byte _081389E4
	.4byte _081389F6
	.4byte _08138A04
	.4byte _08138A1A
	.4byte _08138A26
	.4byte _08138A34
_081389C0:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x68
	b _08138A14
_081389D2:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x4E
	b _08138A14
_081389E4:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x5B
	b _08138A14
_081389F6:
	movs r7, 0x1
	mov r1, sp
	movs r0, 0x7
	strh r0, [r1]
	add r1, sp, 0x8
	movs r0, 0x27
	b _08138A3E
_08138A04:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x34
_08138A14:
	strh r0, [r1]
	strh r0, [r1, 0x2]
	b _08138A40
_08138A1A:
	movs r7, 0x1
	mov r0, sp
	strh r7, [r0]
	add r1, sp, 0x8
	movs r0, 0x41
	b _08138A3E
_08138A26:
	movs r7, 0x1
	mov r1, sp
	movs r0, 0x7
	strh r0, [r1]
	add r1, sp, 0x8
	movs r0, 0xD
	b _08138A3E
_08138A34:
	movs r7, 0x1
	mov r0, sp
	strh r7, [r0]
	add r1, sp, 0x8
	movs r0, 0x1A
_08138A3E:
	strh r0, [r1]
_08138A40:
	movs r6, 0
	cmp r6, r7
	bcs _08138A92
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1, 0
	adds r1, r2, 0
	orrs r1, r0
	lsls r1, 16
	mov r9, r1
	adds r1, r2, 0
	adds r1, 0x8
	orrs r1, r0
	lsls r1, 16
	mov r8, r1
_08138A5E:
	lsls r1, r6, 1
	mov r3, sp
	adds r5, r3, r1
	ldrh r0, [r5]
	adds r0, 0x7
	add r4, sp, 0x8
	adds r4, r1
	ldrh r1, [r4]
	adds r1, 0x7
	mov r3, r9
	lsrs r2, r3, 16
	bl MapGridSetMetatileIdAt
	ldrh r0, [r5]
	adds r0, 0x7
	ldrh r1, [r4]
	adds r1, 0x8
	mov r3, r8
	lsrs r2, r3, 16
	bl MapGridSetMetatileIdAt
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _08138A5E
_08138A92:
	bl DrawWholeMapView
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PetalburgGymFunc

	thumb_func_start PetalburgGymSpecial2
PetalburgGymSpecial2: @ 8138AA4
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	ldr r1, =gUnknown_085B2B7E
	ldrh r1, [r1, 0x8]
	bl PetalburgGymFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end PetalburgGymSpecial2

	thumb_func_start ShowFieldMessageStringVar4
ShowFieldMessageStringVar4: @ 8138AC0
	push {lr}
	ldr r0, =gStringVar4
	bl ShowFieldMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowFieldMessageStringVar4

	thumb_func_start StorePlayerCoordsInVars
StorePlayerCoordsInVars: @ 8138AD0
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end StorePlayerCoordsInVars

	thumb_func_start GetPlayerTrainerIdOnesDigit
GetPlayerTrainerIdOnesDigit: @ 8138AF0
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0xB]
	lsls r1, 8
	ldrb r0, [r0, 0xA]
	orrs r0, r1
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetPlayerTrainerIdOnesDigit

	thumb_func_start GetPlayerBigGuyGirlString
GetPlayerBigGuyGirlString: @ 8138B10
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08138B34
	ldr r0, =gStringVar1
	ldr r1, =gText_BigGuy
	bl StringCopy
	b _08138B3C
	.pool
_08138B34:
	ldr r0, =gStringVar1
	ldr r1, =gText_BigGirl
	bl StringCopy
_08138B3C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetPlayerBigGuyGirlString

	thumb_func_start GetRivalSonDaughterString
GetRivalSonDaughterString: @ 8138B48
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08138B6C
	ldr r0, =gStringVar1
	ldr r1, =gText_Daughter
	bl StringCopy
	b _08138B74
	.pool
_08138B6C:
	ldr r0, =gStringVar1
	ldr r1, =gText_Son
	bl StringCopy
_08138B74:
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetRivalSonDaughterString

	thumb_func_start sub_8138B80
sub_8138B80: @ 8138B80
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8138B80

	thumb_func_start CableCarWarp
CableCarWarp: @ 8138B8C
	push {lr}
	sub sp, 0x4
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	beq _08138BB0
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r3, 0x6
	bl Overworld_SetWarpDestination
	b _08138BC2
	.pool
_08138BB0:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0x1
	movs r3, 0x6
	bl Overworld_SetWarpDestination
_08138BC2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end CableCarWarp

	thumb_func_start SetFlagInVar
SetFlagInVar: @ 8138BC8
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetFlagInVar

	thumb_func_start GetWeekCount
GetWeekCount: @ 8138BDC
	push {lr}
	ldr r0, =gLocalTime
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x7
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _08138BF6
	adds r0, r1, 0
_08138BF6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetWeekCount

	thumb_func_start GetLeadMonFriendshipScore
GetLeadMonFriendshipScore: @ 8138C04
	push {r4,lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0xFF
	bne _08138C2C
	movs r0, 0x6
	b _08138C7E
	.pool
_08138C2C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0xC7
	bls _08138C3C
	movs r0, 0x5
	b _08138C7E
_08138C3C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0x95
	bls _08138C4C
	movs r0, 0x4
	b _08138C7E
_08138C4C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0x63
	bls _08138C5C
	movs r0, 0x3
	b _08138C7E
_08138C5C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0x31
	bls _08138C6C
	movs r0, 0x2
	b _08138C7E
_08138C6C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0
	bne _08138C7C
	movs r0, 0
	b _08138C7E
_08138C7C:
	movs r0, 0x1
_08138C7E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetLeadMonFriendshipScore

	thumb_func_start CB2_FieldShowRegionMap
CB2_FieldShowRegionMap: @ 8138C84
	push {lr}
	ldr r0, =CB2_ReturnToFieldContinueScript
	bl sub_817018C
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_FieldShowRegionMap

	thumb_func_start FieldShowRegionMap
FieldShowRegionMap: @ 8138C94
	push {lr}
	ldr r0, =CB2_FieldShowRegionMap
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldShowRegionMap

	thumb_func_start DoPCTurnOnEffect
DoPCTurnOnEffect: @ 8138CA4
	push {r4,lr}
	ldr r4, =Task_PCTurnOnEffect
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08138CD8
	adds r0, r4, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r2, [r1, 0xC]
	strh r2, [r1, 0xE]
	strh r2, [r1, 0x10]
_08138CD8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoPCTurnOnEffect

	thumb_func_start Task_PCTurnOnEffect
Task_PCTurnOnEffect: @ 8138CE8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08138D06
	adds r0, r1, 0
	bl PCTurnOnEffect_0
_08138D06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_PCTurnOnEffect

	thumb_func_start PCTurnOnEffect_0
PCTurnOnEffect_0: @ 8138D10
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r6, 0
	movs r5, 0
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bne _08138D7C
	strh r5, [r4, 0xE]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x3
	beq _08138D44
	cmp r0, 0x3
	bgt _08138D3A
	cmp r0, 0x2
	beq _08138D40
	b _08138D4C
_08138D3A:
	cmp r1, 0x4
	beq _08138D48
	b _08138D4C
_08138D40:
	movs r6, 0
	b _08138D4A
_08138D44:
	movs r6, 0xFF
	b _08138D4A
_08138D48:
	movs r6, 0x1
_08138D4A:
	movs r5, 0xFF
_08138D4C:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsls r1, r6, 24
	asrs r1, 24
	lsls r2, r5, 24
	asrs r2, 24
	bl PCTurnOnEffect_1
	bl DrawWholeMapView
	ldrh r0, [r4, 0x10]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _08138D7C
	ldrb r0, [r4, 0xA]
	bl DestroyTask
_08138D7C:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end PCTurnOnEffect_0

	thumb_func_start PCTurnOnEffect_1
PCTurnOnEffect_1: @ 8138D88
	push {r4,r5,lr}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	movs r3, 0
	lsls r0, 16
	cmp r0, 0
	beq _08138DC4
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08138DAC
	movs r3, 0x4
	b _08138DE6
	.pool
_08138DAC:
	cmp r0, 0x1
	bne _08138DB8
	ldr r3, =0x0000025a
	b _08138DE6
	.pool
_08138DB8:
	cmp r0, 0x2
	bne _08138DE6
	ldr r3, =0x00000259
	b _08138DE6
	.pool
_08138DC4:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08138DD4
	movs r3, 0x5
	b _08138DE6
	.pool
_08138DD4:
	cmp r0, 0x1
	bne _08138DE0
	ldr r3, =0x0000027f
	b _08138DE6
	.pool
_08138DE0:
	cmp r0, 0x2
	bne _08138DE6
	ldr r3, =0x0000027e
_08138DE6:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r5, 0
	ldrsh r0, [r2, r5]
	lsls r1, 24
	asrs r1, 24
	adds r0, r1
	adds r0, 0x7
	movs r5, 0x2
	ldrsh r1, [r2, r5]
	lsls r2, r4, 24
	asrs r2, 24
	adds r1, r2
	adds r1, 0x7
	movs r4, 0xC0
	lsls r4, 4
	adds r2, r4, 0
	orrs r3, r2
	adds r2, r3, 0
	bl MapGridSetMetatileIdAt
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PCTurnOnEffect_1

	thumb_func_start DoPCTurnOffEffect
DoPCTurnOffEffect: @ 8138E20
	push {lr}
	bl PCTurnOffEffect
	pop {r0}
	bx r0
	thumb_func_end DoPCTurnOffEffect

	thumb_func_start PCTurnOffEffect
PCTurnOffEffect: @ 8138E2C
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	movs r4, 0
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x3
	beq _08138E56
	cmp r0, 0x3
	bgt _08138E4C
	cmp r0, 0x2
	beq _08138E52
	b _08138E5E
_08138E4C:
	cmp r1, 0x4
	beq _08138E5A
	b _08138E5E
_08138E52:
	movs r6, 0
	b _08138E5C
_08138E56:
	movs r6, 0xFF
	b _08138E5C
_08138E5A:
	movs r6, 0x1
_08138E5C:
	movs r5, 0xFF
_08138E5E:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08138E70
	movs r4, 0x4
	b _08138E82
	.pool
_08138E70:
	cmp r0, 0x1
	bne _08138E7C
	ldr r4, =0x0000025a
	b _08138E82
	.pool
_08138E7C:
	cmp r0, 0x2
	bne _08138E82
	ldr r4, =0x00000259
_08138E82:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r6, 24
	asrs r1, 24
	adds r0, r1
	adds r0, 0x7
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	lsls r2, r5, 24
	asrs r2, 24
	adds r1, r2
	adds r1, 0x7
	movs r3, 0xC0
	lsls r3, 4
	adds r2, r3, 0
	orrs r4, r2
	adds r2, r4, 0
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PCTurnOffEffect

	thumb_func_start DoLotteryCornerComputerEffect
DoLotteryCornerComputerEffect: @ 8138EC0
	push {r4,lr}
	ldr r4, =Task_LotteryCornerComputerEffect
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08138EF4
	adds r0, r4, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r2, [r1, 0xC]
	strh r2, [r1, 0xE]
	strh r2, [r1, 0x10]
_08138EF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoLotteryCornerComputerEffect

	thumb_func_start Task_LotteryCornerComputerEffect
Task_LotteryCornerComputerEffect: @ 8138F04
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08138F22
	adds r0, r1, 0
	bl LotteryCornerComputerEffect
_08138F22:
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_LotteryCornerComputerEffect

	thumb_func_start LotteryCornerComputerEffect
LotteryCornerComputerEffect: @ 8138F2C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bne _08138F9A
	movs r0, 0
	strh r0, [r4, 0xE]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08138F64
	ldr r2, =0x00000e9d
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000ea5
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	b _08138F7A
	.pool
_08138F64:
	ldr r2, =0x00000e58
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	movs r2, 0xE6
	lsls r2, 4
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
_08138F7A:
	bl DrawWholeMapView
	ldrh r0, [r4, 0x10]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _08138F9A
	ldrb r0, [r4, 0xA]
	bl DestroyTask
_08138F9A:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LotteryCornerComputerEffect

	thumb_func_start EndLotteryCornerComputerEffect
EndLotteryCornerComputerEffect: @ 8138FAC
	push {lr}
	ldr r2, =0x00000e9d
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000ea5
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	pop {r0}
	bx r0
	.pool
	thumb_func_end EndLotteryCornerComputerEffect

	thumb_func_start SetTrickHouseEndRoomFlag
SetTrickHouseEndRoomFlag: @ 8138FD4
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x000001f5
	strh r0, [r1]
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetTrickHouseEndRoomFlag

	thumb_func_start ResetTrickHouseEndRoomFlag
ResetTrickHouseEndRoomFlag: @ 8138FEC
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x000001f5
	strh r0, [r1]
	bl FlagClear
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetTrickHouseEndRoomFlag

	thumb_func_start CheckLeadMonCool
CheckLeadMonCool: @ 8139004
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	bl GetMonData
	cmp r0, 0xC7
	bls _08139028
	movs r0, 0x1
	b _0813902A
	.pool
_08139028:
	movs r0, 0
_0813902A:
	pop {r1}
	bx r1
	thumb_func_end CheckLeadMonCool

	thumb_func_start CheckLeadMonBeauty
CheckLeadMonBeauty: @ 8139030
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	bl GetMonData
	cmp r0, 0xC7
	bls _08139054
	movs r0, 0x1
	b _08139056
	.pool
_08139054:
	movs r0, 0
_08139056:
	pop {r1}
	bx r1
	thumb_func_end CheckLeadMonBeauty

	thumb_func_start CheckLeadMonCute
CheckLeadMonCute: @ 813905C
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	bl GetMonData
	cmp r0, 0xC7
	bls _08139080
	movs r0, 0x1
	b _08139082
	.pool
_08139080:
	movs r0, 0
_08139082:
	pop {r1}
	bx r1
	thumb_func_end CheckLeadMonCute

	thumb_func_start CheckLeadMonSmart
CheckLeadMonSmart: @ 8139088
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	bl GetMonData
	cmp r0, 0xC7
	bls _081390AC
	movs r0, 0x1
	b _081390AE
	.pool
_081390AC:
	movs r0, 0
_081390AE:
	pop {r1}
	bx r1
	thumb_func_end CheckLeadMonSmart

	thumb_func_start CheckLeadMonTough
CheckLeadMonTough: @ 81390B4
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	bl GetMonData
	cmp r0, 0xC7
	bls _081390D8
	movs r0, 0x1
	b _081390DA
	.pool
_081390D8:
	movs r0, 0
_081390DA:
	pop {r1}
	bx r1
	thumb_func_end CheckLeadMonTough

	thumb_func_start IsGrassTypeInParty
IsGrassTypeInParty: @ 81390E0
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gBaseStats
_081390E6:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _0813913C
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0813913C
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x6]
	cmp r0, 0xC
	beq _08139128
	ldrb r0, [r1, 0x7]
	cmp r0, 0xC
	bne _0813913C
_08139128:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _0813914A
	.pool
_0813913C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _081390E6
	ldr r1, =gSpecialVar_Result
	movs r0, 0
_0813914A:
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end IsGrassTypeInParty

	thumb_func_start SpawnScriptEventObject
SpawnScriptEventObject: @ 8139158
	push {lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r3, [r0]
	adds r3, 0x7
	lsls r3, 16
	asrs r3, 16
	ldrh r0, [r0, 0x2]
	adds r0, 0x7
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x7
	movs r1, 0x8
	movs r2, 0x7F
	bl SpawnSpecialEventObjectParametrized
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gEventObjects
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x1]
	movs r2, 0x20
	orrs r0, r2
	strb r0, [r1, 0x1]
	ldrb r0, [r1, 0x4]
	bl CameraObjectSetFollowedObjectId
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpawnScriptEventObject

	thumb_func_start RemoveScriptEventObject
RemoveScriptEventObject: @ 81391AC
	push {lr}
	bl GetPlayerAvatarObjectId
	lsls r0, 24
	lsrs r0, 24
	bl CameraObjectSetFollowedObjectId
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x7F
	bl RemoveEventObjectByLocalIdAndMap
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveScriptEventObject

	thumb_func_start GetPokeblockNameByMonNature
GetPokeblockNameByMonNature: @ 81391D0
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar1
	bl CopyMonFavoritePokeblockName
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetPokeblockNameByMonNature

	thumb_func_start GetSecretBaseNearbyMapName
GetSecretBaseNearbyMapName: @ 8139200
	push {r4,lr}
	ldr r4, =gStringVar1
	ldr r0, =0x00004026
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl GetMapName
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetSecretBaseNearbyMapName

	thumb_func_start sub_8139228
sub_8139228: @ 8139228
	push {lr}
	movs r0, 0x20
	bl GetGameStat
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8139228

	thumb_func_start sub_8139238
sub_8139238: @ 8139238
	push {lr}
	ldr r0, =gStringVar1
	bl GetEreaderTrainerName
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139238

	thumb_func_start sub_8139248
sub_8139248: @ 8139248
	push {r4,r5,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x00002e68
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 25
	ldr r0, =0x00002e6a
	adds r2, r0
	lsrs r1, 25
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =gUnknown_085B2B88
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	adds r5, r1, r0
	movs r0, 0x2
	bl GetPriceReduction
	lsls r0, 24
	cmp r0, 0
	bne _08139294
	ldr r4, =gUnknown_085B2B94
	b _08139296
	.pool
_08139294:
	ldr r4, =gUnknown_085B2BA0
_08139296:
	adds r0, r5, 0
	movs r1, 0xC
	bl __umodsi3
	adds r0, r4
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8139248

	thumb_func_start sub_81392AC
sub_81392AC: @ 81392AC
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x00000213
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081392CC
	movs r0, 0x1
	b _081392CE
	.pool
_081392CC:
	movs r0, 0
_081392CE:
	pop {r1}
	bx r1
	thumb_func_end sub_81392AC

	thumb_func_start sub_81392D4
sub_81392D4: @ 81392D4
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x85
	lsls r0, 2
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081392F0
	movs r0, 0x1
	b _081392F2
	.pool
_081392F0:
	movs r0, 0
_081392F2:
	pop {r1}
	bx r1
	thumb_func_end sub_81392D4

	thumb_func_start sub_81392F8
sub_81392F8: @ 81392F8
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x00000215
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139318
	movs r0, 0x1
	b _0813931A
	.pool
_08139318:
	movs r0, 0
_0813931A:
	pop {r1}
	bx r1
	thumb_func_end sub_81392F8

	thumb_func_start sub_8139320
sub_8139320: @ 8139320
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x00000216
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139340
	movs r0, 0x1
	b _08139342
	.pool
_08139340:
	movs r0, 0
_08139342:
	pop {r1}
	bx r1
	thumb_func_end sub_8139320

	thumb_func_start LeadMonHasEffortRibbon
LeadMonHasEffortRibbon: @ 8139348
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x47
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end LeadMonHasEffortRibbon

	thumb_func_start GiveLeadMonEffortRibbon
GiveLeadMonEffortRibbon: @ 8139370
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x2A
	bl IncrementGameStat
	ldr r0, =0x0000089b
	bl FlagSet
	movs r1, 0x1
	mov r0, sp
	strb r1, [r0]
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x47
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _081393B6
	adds r0, r4, 0
	movs r1, 0x47
	bl sub_80EE4DC
_081393B6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GiveLeadMonEffortRibbon

	thumb_func_start Special_AreLeadMonEVsMaxedOut
Special_AreLeadMonEVsMaxedOut: @ 81393C8
	push {lr}
	bl GetLeadMonIndex
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetMonEVCount
	lsls r0, 16
	ldr r1, =0x01fd0000
	cmp r0, r1
	bhi _081393F4
	movs r0, 0
	b _081393F6
	.pool
_081393F4:
	movs r0, 0x1
_081393F6:
	pop {r1}
	bx r1
	thumb_func_end Special_AreLeadMonEVsMaxedOut

	thumb_func_start sub_81393FC
sub_81393FC: @ 81393FC
	push {lr}
	movs r0, 0xC7
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08139454
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0x83
	lsls r0, 3
	cmp r1, r0
	bne _08139454
	subs r0, 0x75
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139434
	ldr r0, =0x0000409a
	movs r1, 0x4
	b _08139446
	.pool
_08139434:
	movs r0, 0xE9
	lsls r0, 2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139454
	ldr r0, =0x0000409a
	movs r1, 0x5
_08139446:
	bl VarSet
	movs r0, 0x1
	b _08139456
	.pool
_08139454:
	movs r0, 0
_08139456:
	pop {r1}
	bx r1
	thumb_func_end sub_81393FC

	thumb_func_start SetShoalItemFlag
SetShoalItemFlag: @ 813945C
	push {lr}
	ldr r0, =0x000008bf
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetShoalItemFlag

	thumb_func_start PutZigzagoonInPlayerParty
PutZigzagoonInPlayerParty: @ 813946C
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r5, =gPlayerParty
	movs r1, 0x90
	lsls r1, 1
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r5, 0
	movs r2, 0x7
	movs r3, 0x20
	bl CreateMon
	movs r1, 0x1
	add r0, sp, 0x10
	strh r1, [r0]
	adds r0, r5, 0
	movs r1, 0x2E
	add r2, sp, 0x10
	bl SetMonData
	add r1, sp, 0x10
	movs r0, 0x21
	strh r0, [r1]
	adds r0, r5, 0
	movs r1, 0xD
	add r2, sp, 0x10
	bl SetMonData
	add r0, sp, 0x10
	strh r4, [r0]
	adds r0, r5, 0
	movs r1, 0xE
	add r2, sp, 0x10
	bl SetMonData
	adds r0, r5, 0
	movs r1, 0xF
	add r2, sp, 0x10
	bl SetMonData
	adds r0, r5, 0
	movs r1, 0x10
	add r2, sp, 0x10
	bl SetMonData
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PutZigzagoonInPlayerParty

	thumb_func_start IsStarterInParty
IsStarterInParty: @ 81394D8
	push {r4-r6,lr}
	ldr r0, =0x00004023
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl GetStarterPokemon
	lsls r0, 16
	lsrs r6, r0, 16
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _08139526
_081394FA:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	cmp r0, r6
	bne _0813951C
	movs r0, 0x1
	b _08139528
	.pool
_0813951C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _081394FA
_08139526:
	movs r0, 0
_08139528:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsStarterInParty

	thumb_func_start ScriptCheckFreePokemonStorageSpace
ScriptCheckFreePokemonStorageSpace: @ 8139530
	push {lr}
	bl CheckFreePokemonStorageSpace
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end ScriptCheckFreePokemonStorageSpace

	thumb_func_start IsPokerusInParty
IsPokerusInParty: @ 8139540
	push {lr}
	ldr r0, =gPlayerParty
	movs r1, 0x3F
	bl CheckPartyPokerus
	lsls r0, 24
	cmp r0, 0
	beq _08139558
	movs r0, 0x1
	b _0813955A
	.pool
_08139558:
	movs r0, 0
_0813955A:
	pop {r1}
	bx r1
	thumb_func_end IsPokerusInParty

	thumb_func_start sub_8139560
sub_8139560: @ 8139560
	push {lr}
	ldr r0, =sub_81395BC
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	movs r2, 0
	strh r0, [r1, 0x8]
	strh r2, [r1, 0xA]
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	strh r0, [r1, 0xC]
	ldr r0, =gSpecialVar_0x8007
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	strh r0, [r1, 0x10]
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0xD6
	bl PlaySE
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139560

	thumb_func_start sub_81395BC
sub_81395BC: @ 81395BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _08139614
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	ldrh r0, [r4]
	negs r0, r0
	strh r0, [r4]
	ldrh r0, [r4, 0x8]
	negs r0, r0
	strh r0, [r4, 0x8]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	bl SetCameraPanning
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08139614
	adds r0, r5, 0
	bl sub_8139620
	bl InstallCameraPanAheadCallback
_08139614:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81395BC

	thumb_func_start sub_8139620
sub_8139620: @ 8139620
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_8139620

	thumb_func_start sub_8139634
sub_8139634: @ 8139634
	push {lr}
	movs r0, 0x95
	lsls r0, 2
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8139634

	thumb_func_start SetRoute119Weather
SetRoute119Weather: @ 8139648
	push {lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r0, 24
	bl is_map_type_1_2_3_5_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08139664
	movs r0, 0x14
	bl SetSav1Weather
_08139664:
	pop {r0}
	bx r0
	thumb_func_end SetRoute119Weather

	thumb_func_start SetRoute123Weather
SetRoute123Weather: @ 8139668
	push {lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r0, 24
	bl is_map_type_1_2_3_5_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08139684
	movs r0, 0x15
	bl SetSav1Weather
_08139684:
	pop {r0}
	bx r0
	thumb_func_end SetRoute123Weather

	thumb_func_start GetLeadMonIndex
GetLeadMonIndex: @ 8139688
	push {r4-r6,lr}
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	cmp r5, r6
	bcs _081396D6
_08139698:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _081396CC
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _081396CC
	adds r0, r5, 0
	b _081396D8
	.pool
_081396CC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r6
	bcc _08139698
_081396D6:
	movs r0, 0
_081396D8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetLeadMonIndex

	thumb_func_start ScriptGetPartyMonSpecies
ScriptGetPartyMonSpecies: @ 81396E0
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end ScriptGetPartyMonSpecies

	thumb_func_start nullsub_54
nullsub_54: @ 8139708
	bx lr
	thumb_func_end nullsub_54

	thumb_func_start sub_813970C
sub_813970C: @ 813970C
	push {r4,lr}
	ldr r0, =0x000040c2
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r3, r0, 0
	ldr r2, =gLocalTime
	movs r1, 0
	ldrsh r0, [r2, r1]
	subs r0, r3
	cmp r0, 0x6
	ble _08139734
	movs r0, 0
	b _0813974C
	.pool
_08139734:
	ldrh r1, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	blt _0813974A
	subs r1, r3
	movs r0, 0x7
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	b _0813974C
_0813974A:
	movs r0, 0x8
_0813974C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813970C

	thumb_func_start sub_8139754
sub_8139754: @ 8139754
	push {r4,lr}
	ldr r0, =0x000040c2
	ldr r4, =gLocalTime
	ldrh r1, [r4]
	bl VarSet
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8139754

	thumb_func_start sub_8139770
sub_8139770: @ 8139770
	push {r4-r6,lr}
	ldr r6, =gSpecialVar_0x8004
	ldrh r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3
	bl GetMonData
	cmp r0, 0x2
	bne _081397A6
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	ldr r4, =gStringVar1
	movs r1, 0x7
	adds r2, r4, 0
	bl GetMonData
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r1, r4, 0
	bl StringCompare
	cmp r0, 0
	beq _081397BC
_081397A6:
	movs r0, 0x1
	b _081397BE
	.pool
_081397BC:
	movs r0, 0
_081397BE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8139770

	thumb_func_start sub_81397C4
sub_81397C4: @ 81397C4
	push {r4,r5,lr}
	ldr r2, =gSpecialVar_Result
	ldrh r1, [r2]
	ldr r0, =0x0000270f
	cmp r1, r0
	bls _081397E0
	movs r0, 0
	bl TV_PrintIntToStringVar
	b _08139862
	.pool
_081397E0:
	ldr r0, =0x000003e7
	cmp r1, r0
	bls _081397F8
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	adds r4, 0x1
	b _0813981C
	.pool
_081397F8:
	cmp r1, 0x63
	bls _0813980C
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	adds r4, 0x2
	b _0813981C
	.pool
_0813980C:
	cmp r1, 0x9
	bls _0813983C
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	adds r4, 0x3
_0813981C:
	ldrh r5, [r2]
	adds r0, r5, 0
	bl CountDigits
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
	b _08139862
	.pool
_0813983C:
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	adds r4, 0x4
	ldrh r5, [r2]
	adds r0, r5, 0
	bl CountDigits
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
_08139862:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81397C4

	thumb_func_start sub_813986C
sub_813986C: @ 813986C
	push {lr}
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _081398B8
	lsls r0, 2
	ldr r1, =_08139888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08139888:
	.4byte _0813989C
	.4byte _081398A0
	.4byte _081398A4
	.4byte _081398A8
	.4byte _081398AC
_0813989C:
	movs r0, 0x3
	b _081398AE
_081398A0:
	movs r0, 0x4
	b _081398AE
_081398A4:
	movs r0, 0
	b _081398AE
_081398A8:
	movs r0, 0x1
	b _081398AE
_081398AC:
	movs r0, 0x2
_081398AE:
	bl mevent_081445C0
	lsls r0, 16
	lsrs r0, 16
	b _081398BA
_081398B8:
	movs r0, 0
_081398BA:
	pop {r1}
	bx r1
	thumb_func_end sub_813986C

	thumb_func_start sub_81398C0
sub_81398C0: @ 81398C0
	push {r4,lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r2, =0xfffffedf
	adds r0, r2, 0
	ldrh r2, [r1]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x39
	bls _081398E0
	movs r0, 0
	b _081398FC
	.pool
_081398E0:
	ldr r4, =gStringVar2
	ldrh r0, [r1]
	bl ItemIdToBattleMoveId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0x1
_081398FC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81398C0

	thumb_func_start sub_813990C
sub_813990C: @ 813990C
	push {r4,r5,lr}
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _08139942
_0813991C:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x4
	bl GetMonData
	cmp r0, 0x1
	bne _08139938
	movs r0, 0x1
	b _08139944
	.pool
_08139938:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0813991C
_08139942:
	movs r0, 0
_08139944:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_813990C

	thumb_func_start InMultiBattleRoom
InMultiBattleRoom: @ 813994C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00000f1a
	cmp r1, r0
	bne _08139978
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _08139978
	movs r0, 0x1
	b _0813997A
	.pool
_08139978:
	movs r0, 0
_0813997A:
	pop {r1}
	bx r1
	thumb_func_end InMultiBattleRoom

	thumb_func_start sub_8139980
sub_8139980: @ 8139980
	push {lr}
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0x8
	movs r1, 0
	bl SetCameraPanning
	pop {r0}
	bx r0
	thumb_func_end sub_8139980

	thumb_func_start sub_8139994
sub_8139994: @ 8139994
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	subs r0, 0x10
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x5
	bhi _081399E4
	lsls r0, 2
	ldr r1, =_081399B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081399B8:
	.4byte _081399E4
	.4byte _081399D0
	.4byte _081399D4
	.4byte _081399D8
	.4byte _081399DC
	.4byte _081399E0
_081399D0:
	movs r1, 0x5
	b _081399E6
_081399D4:
	movs r1, 0x6
	b _081399E6
_081399D8:
	movs r1, 0x7
	b _081399E6
_081399DC:
	movs r1, 0x8
	b _081399E6
_081399E0:
	movs r1, 0xF
	b _081399E6
_081399E4:
	movs r1, 0x4
_081399E6:
	ldr r0, =0x00004043
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139994

	thumb_func_start sub_81399F4
sub_81399F4: @ 81399F4
	push {r4,lr}
	ldr r2, =gUnknown_0203AB60
	movs r0, 0
	strh r0, [r2]
	ldr r1, =gUnknown_0203AB62
	strh r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r0, 0x14
	ldrsb r0, [r3, r0]
	adds r4, r1, 0
	cmp r0, 0xD
	bne _08139A6E
	ldrb r0, [r3, 0x15]
	subs r0, 0x10
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bhi _08139A6E
	lsls r0, 2
	ldr r1, =_08139A34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08139A34:
	.4byte _08139A66
	.4byte _08139A5E
	.4byte _08139A56
	.4byte _08139A4E
	.4byte _08139A48
_08139A48:
	movs r0, 0
	strh r0, [r2]
	b _08139A6C
_08139A4E:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
	b _08139A6C
_08139A56:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x2
	b _08139A6C
_08139A5E:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x3
	b _08139A6C
_08139A66:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x4
_08139A6C:
	strh r0, [r4]
_08139A6E:
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81399F4

	thumb_func_start sub_8139A78
sub_8139A78: @ 8139A78
	push {r4-r6,lr}
	ldr r0, =sub_8139AF4
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r3, 0
	strh r3, [r4, 0x2]
	strh r3, [r4, 0x4]
	movs r6, 0x1
	strh r6, [r4, 0x8]
	ldr r0, =gSpecialVar_0x8005
	ldr r1, =gSpecialVar_0x8006
	ldrh r2, [r0]
	ldrh r0, [r1]
	cmp r2, r0
	bls _08139AC0
	subs r0, r2, r0
	lsls r0, 16
	lsrs r5, r0, 16
	strh r6, [r4, 0xC]
	b _08139AC8
	.pool
_08139AC0:
	subs r0, r2
	lsls r0, 16
	lsrs r5, r0, 16
	strh r3, [r4, 0xC]
_08139AC8:
	cmp r5, 0x8
	bls _08139ACE
	movs r5, 0x8
_08139ACE:
	ldr r0, =gUnknown_085B2C18
	adds r0, r5, r0
	ldrb r0, [r0]
	strh r0, [r4, 0xA]
	movs r0, 0
	bl SetCameraPanningCallback
	ldrb r1, [r4, 0xC]
	adds r0, r5, 0
	bl sub_8139C2C
	movs r0, 0x59
	bl PlaySE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139A78

	thumb_func_start sub_8139AF4
sub_8139AF4: @ 8139AF4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _08139B54
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	ldrh r0, [r4, 0x8]
	negs r0, r0
	strh r0, [r4, 0x8]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	movs r0, 0
	bl SetCameraPanning
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08139B54
	movs r0, 0x49
	bl PlaySE
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	bl InstallCameraPanAheadCallback
_08139B54:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139AF4

	thumb_func_start sub_8139B60
sub_8139B60: @ 8139B60
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	ldr r5, =gUnknown_0203AB5E
	ldr r0, =gUnknown_085B2BAC
	bl AddWindow
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r4, =gText_ElevatorNowOn
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldrb r0, [r5]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	mov r9, r1
	str r1, [sp, 0x4]
	movs r1, 0
	mov r8, r1
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	ldr r6, =gElevatorFloorsTable
	ldr r4, =gSpecialVar_0x8005
	ldrh r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	movs r0, 0x1
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldrb r0, [r5]
	ldrh r1, [r4]
	lsls r1, 2
	adds r1, r6
	ldr r2, [r1]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x11
	str r1, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	movs r1, 0x1
	bl PrintTextOnWindow
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139B60

	thumb_func_start sub_8139C10
sub_8139C10: @ 8139C10
	push {r4,lr}
	ldr r4, =gUnknown_0203AB5E
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139C10

	thumb_func_start sub_8139C2C
sub_8139C2C: @ 8139C2C
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, =sub_8139C80
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08139C6C
	adds r0, r4, 0
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
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r5, [r1, 0xC]
	ldr r0, =gUnknown_085B2C21
	adds r0, r6, r0
	ldrb r0, [r0]
	strh r0, [r1, 0xE]
_08139C6C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139C2C

	thumb_func_start sub_8139C80
sub_8139C80: @ 8139C80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r0, 0x6
	bne _08139D7C
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08139D10
	movs r1, 0
	ldr r2, =gUnknown_085B2BF4
	mov r10, r2
_08139CBA:
	movs r5, 0
	adds r7, r1, 0x7
	lsls r0, r1, 1
	adds r2, r1, 0x1
	mov r8, r2
	adds r0, r1
	lsls r0, 1
	mov r9, r0
_08139CCA:
	adds r4, r5, 0
	adds r4, 0x8
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 15
	add r0, r9
	add r0, r10
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 4
	adds r2, r1, 0
	orrs r2, r0
	adds r0, r4, 0
	adds r1, r7, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _08139CCA
	mov r2, r8
	lsls r0, r2, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bls _08139CBA
	b _08139D62
	.pool
_08139D10:
	movs r1, 0
	ldr r0, =gUnknown_085B2C06
	mov r10, r0
_08139D16:
	movs r5, 0
	adds r7, r1, 0x7
	lsls r0, r1, 1
	adds r2, r1, 0x1
	mov r8, r2
	adds r0, r1
	lsls r0, 1
	mov r9, r0
_08139D26:
	adds r4, r5, 0
	adds r4, 0x8
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 15
	add r0, r9
	add r0, r10
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 4
	adds r2, r1, 0
	orrs r2, r0
	adds r0, r4, 0
	adds r1, r7, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _08139D26
	mov r2, r8
	lsls r0, r2, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bls _08139D16
_08139D62:
	bl DrawWholeMapView
	movs r0, 0
	strh r0, [r6, 0x2]
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r2, 0x6
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _08139D7C
	ldr r0, [sp]
	bl DestroyTask
_08139D7C:
	ldrh r0, [r6, 0x2]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139C80

	thumb_func_start sub_8139D98
sub_8139D98: @ 8139D98
	push {r4-r7,lr}
	sub sp, 0x18
	ldr r6, =gSpecialVar_0x8004
	ldrh r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x27
	bl GetMonData
	str r0, [sp]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x28
	bl GetMonData
	str r0, [sp, 0x4]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x29
	bl GetMonData
	str r0, [sp, 0x8]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x2A
	bl GetMonData
	str r0, [sp, 0xC]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x2B
	bl GetMonData
	str r0, [sp, 0x10]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x2C
	bl GetMonData
	str r0, [sp, 0x14]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0
	strh r0, [r1]
	movs r4, 0
	adds r2, r1, 0
_08139E00:
	lsls r0, r4, 2
	add r0, sp
	ldr r1, [r0]
	ldrh r0, [r2]
	adds r0, r1
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _08139E00
	ldr r2, =gSpecialVar_0x8006
	movs r0, 0
	strh r0, [r2]
	ldr r1, =gSpecialVar_0x8007
	ldr r0, [sp]
	strh r0, [r1]
	movs r4, 0x1
	adds r6, r2, 0
	adds r7, r1, 0
_08139E28:
	ldrh r0, [r6]
	lsls r0, 2
	mov r2, sp
	adds r1, r2, r0
	lsls r0, r4, 2
	adds r5, r2, r0
	ldr r1, [r1]
	ldr r0, [r5]
	cmp r1, r0
	bcs _08139E54
	strh r4, [r6]
	b _08139E6C
	.pool
_08139E54:
	cmp r1, r0
	bne _08139E6E
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08139E6E
	strh r4, [r6]
	ldr r0, [r5]
_08139E6C:
	strh r0, [r7]
_08139E6E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _08139E28
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8139D98

	thumb_func_start warp0_in_pokecenter
warp0_in_pokecenter: @ 8139E80
	push {r4,lr}
	ldr r0, =gUnknown_020322DC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gUnknown_085B2C2A
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _08139EC6
	adds r4, r1, 0
	adds r1, r2, 0
_08139EA4:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08139EBC
	movs r0, 0x1
	b _08139EC8
	.pool
_08139EBC:
	adds r1, 0x2
	adds r2, 0x2
	ldrh r0, [r1]
	cmp r0, r4
	bne _08139EA4
_08139EC6:
	movs r0, 0
_08139EC8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end warp0_in_pokecenter

	thumb_func_start sub_8139ED0
sub_8139ED0: @ 8139ED0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00003c1a
	cmp r1, r0
	beq _08139EEC
	movs r0, 0x1
	b _08139EEE
	.pool
_08139EEC:
	movs r0, 0
_08139EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8139ED0

	thumb_func_start UpdateFrontierManiac
UpdateFrontierManiac: @ 8139EF4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x0000402f
	bl GetVarPointer
	adds r5, r0, 0
	ldrh r0, [r5]
	adds r4, r0
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0xA
	bl __umodsi3
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateFrontierManiac

	thumb_func_start sub_8139F20
sub_8139F20: @ 8139F20
	push {r4-r7,lr}
	movs r4, 0
	ldr r0, =0x0000402f
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x9
	bls _08139F34
	b _0813A03A
_08139F34:
	lsls r0, r6, 2
	ldr r1, =_08139F48
	adds r1, r0, r1
	ldr r1, [r1]
	adds r2, r0, 0
	mov pc, r1
	.pool
	.align 2, 0
_08139F48:
	.4byte _08139F70
	.4byte _08139F70
	.4byte _08139F70
	.4byte _08139F70
	.4byte _08139F94
	.4byte _08139FB4
	.4byte _08139FCC
	.4byte _08139FE4
	.4byte _08139FFC
	.4byte _0813A014
_08139F70:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r3, 0xCE
	lsls r3, 4
	adds r1, r0, r3
	adds r3, r1, r2
	ldr r1, =0x00000ce2
	adds r0, r1
	adds r1, r0, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bcs _0813A028
	b _0813A038
	.pool
_08139F94:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d0c
	adds r2, r0, r3
	adds r3, 0x2
_08139F9E:
	adds r1, r0, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcs _0813A028
	b _0813A038
	.pool
_08139FB4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000de2
	adds r2, r0, r1
	ldr r3, =0x00000de4
	b _08139F9E
	.pool
_08139FCC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dc8
	adds r2, r0, r1
	ldr r3, =0x00000dca
	b _08139F9E
	.pool
_08139FE4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dda
	adds r2, r0, r1
	ldr r3, =0x00000ddc
	b _08139F9E
	.pool
_08139FFC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e04
	adds r2, r0, r1
	ldr r3, =0x00000e06
	b _08139F9E
	.pool
_0813A014:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e1a
	adds r2, r0, r1
	ldr r3, =0x00000e1c
	adds r1, r0, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcc _0813A038
_0813A028:
	adds r4, r0, 0
	b _0813A03A
	.pool
_0813A038:
	ldrh r4, [r1]
_0813A03A:
	movs r2, 0
	ldr r5, =gUnknown_085B2CC8
	lsls r0, r6, 1
	adds r1, r0, r5
	ldrb r1, [r1]
	adds r3, r0, 0
	ldr r7, =gUnknown_085B2C50
	cmp r1, r4
	bcs _0813A062
	adds r1, r3, 0
_0813A04E:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bhi _0813A062
	adds r0, r2, r1
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, r4
	bcc _0813A04E
_0813A062:
	adds r0, r3, r6
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139F20

	thumb_func_start sub_813A080
sub_813A080: @ 813A080
	push {r4-r7,lr}
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r4, r0, 30
	cmp r5, 0x2
	bne _0813A0D8
	movs r0, 0xA9
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _0813A0D8
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8006
	movs r0, 0x4
	strh r0, [r1]
	b _0813A110
	.pool
_0813A0D0:
	movs r0, 0x4
	strh r0, [r6]
	adds r0, r3, 0x5
	b _0813A10E
_0813A0D8:
	movs r3, 0
	ldr r6, =gSpecialVar_0x8005
	ldr r7, =gSpecialVar_0x8006
	lsls r1, r4, 1
	lsls r2, r5, 2
	ldr r4, =gUnknown_085B2CDC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r1, r2
	movs r2, 0xCE
	lsls r2, 4
	adds r0, r2
	adds r0, r1
	ldrh r1, [r0]
_0813A0F4:
	lsls r0, r3, 1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r1
	bhi _0813A0D0
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x8
	bls _0813A0F4
	movs r0, 0x4
	strh r0, [r6]
	movs r0, 0xC
_0813A10E:
	strh r0, [r7]
_0813A110:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A080

	thumb_func_start sub_813A128
sub_813A128: @ 813A128
	push {r4,lr}
	ldr r0, =sub_813A2DC
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	ldr r1, =gSpecialVar_0x8004
	ldrh r0, [r1]
	strh r0, [r3, 0x1E]
	ldrh r0, [r1]
	cmp r0, 0xC
	bls _0813A14E
	b _0813A2C6
_0813A14E:
	lsls r0, 2
	ldr r1, =_0813A168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813A168:
	.4byte _0813A19C
	.4byte _0813A1AA
	.4byte _0813A1C2
	.4byte _0813A1D6
	.4byte _0813A1F0
	.4byte _0813A208
	.4byte _0813A222
	.4byte _0813A23C
	.4byte _0813A25A
	.4byte _0813A274
	.4byte _0813A274
	.4byte _0813A28E
	.4byte _0813A2A8
_0813A19C:
	movs r1, 0
	movs r0, 0x1
	strh r0, [r3, 0x8]
	strh r0, [r3, 0xA]
	strh r0, [r3, 0xC]
	strh r0, [r3, 0xE]
	b _0813A2BC
_0813A1AA:
	movs r1, 0
	movs r0, 0x5
	strh r0, [r3, 0x8]
	movs r0, 0x8
	strh r0, [r3, 0xA]
	movs r0, 0x1
	strh r0, [r3, 0xC]
	strh r0, [r3, 0xE]
	movs r0, 0x9
	strh r0, [r3, 0x10]
	movs r0, 0xA
	b _0813A2BE
_0813A1C2:
	movs r2, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r1, 0xC
	strh r1, [r3, 0xA]
	movs r0, 0x1
	strh r0, [r3, 0xC]
	strh r0, [r3, 0xE]
	movs r0, 0x7
	b _0813A250
_0813A1D6:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xB
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A1F0:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A208:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0x7
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A222:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xA
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A23C:
	movs r2, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r1, 0xC
	strh r1, [r3, 0xA]
	movs r0, 0xF
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xE
_0813A250:
	strh r0, [r3, 0x10]
	strh r1, [r3, 0x12]
	strh r2, [r3, 0x14]
	strh r4, [r3, 0x26]
	b _0813A2D2
_0813A25A:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xA
	strh r0, [r3, 0xA]
	movs r0, 0x11
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xB
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A274:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xB
	strh r0, [r3, 0xA]
	movs r0, 0xF
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xE
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A28E:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0x7
	strh r0, [r3, 0xA]
	movs r0, 0x13
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xA
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A2A8:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0x7
	strh r0, [r3, 0xA]
	movs r0, 0x11
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xC
_0813A2BC:
	strh r0, [r3, 0x10]
_0813A2BE:
	strh r0, [r3, 0x12]
	strh r1, [r3, 0x14]
	strh r4, [r3, 0x26]
	b _0813A2D2
_0813A2C6:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x7F
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0813A2D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A128

	thumb_func_start sub_813A2DC
sub_813A2DC: @ 813A2DC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	bl ScriptContext2_Enable
	ldr r0, =gUnknown_0203AB68
	movs r5, 0
	strh r5, [r0]
	ldr r1, =gUnknown_0203AB6C
	movs r0, 0x40
	strb r0, [r1]
	ldrh r0, [r6, 0x1E]
	movs r1, 0
	bl sub_813AA60
	ldrb r0, [r6, 0x1E]
	movs r1, 0
	bl sub_813ACE8
	ldr r4, =gUnknown_0203AB64
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gUnknown_0203AB6A
	strh r5, [r0]
	bl sub_813A42C
	movs r3, 0
	movs r4, 0
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	add r1, sp, 0x18
	mov r8, r1
	cmp r3, r0
	bge _0813A36A
	ldr r5, =gUnknown_085B2CF0
_0813A33A:
	lsls r1, r4, 2
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r1, r5
	ldr r0, [r1]
	ldr r1, =gUnknown_0203AB64
	ldr r2, [r1]
	lsls r1, r4, 3
	adds r1, r2
	str r0, [r1]
	str r4, [r1, 0x4]
	adds r1, r3, 0
	bl display_text_and_get_width
	adds r3, r0, 0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	cmp r4, r0
	blt _0813A33A
_0813A36A:
	adds r0, r3, 0
	bl convert_pixel_width_to_tile_width
	strh r0, [r6, 0x10]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	adds r0, r1
	cmp r0, 0x1D
	ble _0813A38C
	movs r0, 0x1D
	subs r0, r1
	cmp r0, 0
	bge _0813A38A
	movs r0, 0
_0813A38A:
	strh r0, [r6, 0xC]
_0813A38C:
	ldrb r2, [r6, 0xC]
	ldrb r3, [r6, 0xE]
	ldrb r0, [r6, 0x10]
	str r0, [sp]
	ldrb r0, [r6, 0x12]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x64
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	bl sub_8198A50
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	mov r0, r8
	bl AddWindow
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r4, =gUnknown_030061D0
	ldrh r0, [r6, 0xA]
	strh r0, [r4, 0xC]
	ldrh r0, [r6, 0x8]
	strh r0, [r4, 0xE]
	ldrh r0, [r6, 0x22]
	strb r0, [r4, 0x10]
	adds r0, r7, 0
	bl sub_813A694
	ldrh r1, [r6, 0x16]
	ldrh r2, [r6, 0x18]
	adds r0, r4, 0
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x24]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_813A4EC
	str r1, [r0]
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A2DC

	thumb_func_start sub_813A42C
sub_813A42C: @ 813A42C
	ldr r1, =gUnknown_030061D0
	ldr r0, =gUnknown_0203AB64
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, =sub_813A46C
	str r0, [r1, 0x4]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r2, 0
	movs r0, 0x1
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strb r2, [r1, 0x10]
	strb r2, [r1, 0x11]
	movs r0, 0x8
	strb r0, [r1, 0x12]
	strb r2, [r1, 0x13]
	movs r0, 0x21
	strb r0, [r1, 0x14]
	movs r0, 0x31
	strb r0, [r1, 0x15]
	movs r0, 0
	strb r0, [r1, 0x16]
	movs r0, 0x1
	strb r0, [r1, 0x17]
	bx lr
	.pool
	thumb_func_end sub_813A42C

	thumb_func_start sub_813A46C
sub_813A46C: @ 813A46C
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_813A4EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0813A4D4
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	bl ListMenuGetScrollAndRow
	ldr r1, =gUnknown_0203AB68
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	bl ListMenuGetCurrentItemArrayId
	ldrh r0, [r4, 0x1E]
	ldr r5, =gUnknown_0203AB6A
	ldrh r1, [r5]
	bl sub_813AC44
	ldrh r0, [r4, 0x1E]
	mov r1, sp
	ldrh r1, [r1]
	bl sub_813AA60
	ldrb r0, [r4, 0x1E]
	mov r1, sp
	ldrh r1, [r1]
	bl sub_813AD34
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5]
_0813A4D4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A46C

	thumb_func_start sub_813A4EC
sub_813A4EC: @ 813A4EC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrh r0, [r6, 0x24]
	lsls r0, 24
	lsrs r0, 24
	bl ListMenuHandleInputGetItemId
	adds r4, r0, 0
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0813A51C
	adds r0, 0x1
	cmp r4, r0
	bne _0813A530
	b _0813A566
	.pool
_0813A51C:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x7F
	strh r0, [r1]
	movs r0, 0x5
	bl PlaySE
	b _0813A54C
	.pool
_0813A530:
	ldr r0, =gSpecialVar_Result
	strh r4, [r0]
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0813A54C
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	cmp r4, r0
	bne _0813A558
_0813A54C:
	adds r0, r5, 0
	bl sub_813A570
	b _0813A566
	.pool
_0813A558:
	adds r0, r5, 0
	bl sub_813A738
	ldr r0, =sub_813A600
	str r0, [r6]
	bl EnableBothScriptContexts
_0813A566:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A4EC

	thumb_func_start sub_813A570
sub_813A570: @ 813A570
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	bl ListMenuGetCurrentItemArrayId
	ldrh r0, [r4, 0x1E]
	mov r1, sp
	ldrh r1, [r1]
	bl sub_813AC44
	adds r0, r5, 0
	bl sub_813A738
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0
	bl DestroyListMenuTask
	ldr r0, =gUnknown_0203AB64
	ldr r0, [r0]
	bl Free
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_8198070
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl CopyWindowToVram
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A570

	thumb_func_start sub_813A600
sub_813A600: @ 813A600
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x14
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0813A624
	cmp r0, 0x2
	bne _0813A624
	movs r0, 0x1
	strh r0, [r1, 0x14]
	ldr r0, =sub_813A664
	str r0, [r1]
_0813A624:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A600

	thumb_func_start sub_813A630
sub_813A630: @ 813A630
	push {lr}
	ldr r0, =sub_813A600
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _0813A64C
	bl EnableBothScriptContexts
	b _0813A65C
	.pool
_0813A64C:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	strh r0, [r1, 0x14]
_0813A65C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A630

	thumb_func_start sub_813A664
sub_813A664: @ 813A664
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ScriptContext2_Enable
	adds r0, r4, 0
	bl sub_813A694
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_813A4EC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A664

	thumb_func_start sub_813A694
sub_813A694: @ 813A694
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	mov r1, sp
	ldr r0, =gUnknown_085B3030
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	beq _0813A724
	mov r2, sp
	movs r3, 0x10
	ldrsh r1, [r4, r3]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 3
	adds r1, 0xC
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	subs r0, 0x1
	lsls r0, 3
	adds r1, r0
	movs r3, 0
	strb r1, [r2, 0x1]
	mov r1, sp
	movs r0, 0x8
	strb r0, [r1, 0x2]
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 3
	adds r1, 0xC
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	subs r0, 0x1
	lsls r0, 3
	adds r1, r0
	strb r1, [r2, 0x4]
	mov r1, sp
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, 0xA
	strb r0, [r1, 0x5]
	mov r0, sp
	strh r3, [r0, 0x6]
	mov r2, sp
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	subs r0, r1
	strh r0, [r2, 0x8]
	ldr r1, =gUnknown_0203AB68
	mov r0, sp
	bl AddScrollIndicatorArrowPair
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
_0813A724:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A694

	thumb_func_start sub_813A738
sub_813A738: @ 813A738
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r2, r1, r0
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _0813A75E
	ldrh r0, [r2, 0x20]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveScrollIndicatorArrowPair
_0813A75E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A738

	thumb_func_start nullsub_55
nullsub_55: @ 813A768
	bx lr
	thumb_func_end nullsub_55

	thumb_func_start sub_813A76C
sub_813A76C: @ 813A76C
	push {r4-r6,lr}
	movs r4, 0
	ldr r6, =gLinkPlayers
	ldr r0, =0x0000401f
	adds r5, r0, 0
_0813A776:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	bne _0813A79C
	subs r0, r5, r4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl VarSet
	b _0813A7A8
	.pool
_0813A79C:
	subs r0, r5, r4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x69
	bl VarSet
_0813A7A8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0813A776
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_813A76C

	thumb_func_start sub_813A7B8
sub_813A7B8: @ 813A7B8
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldrh r0, [r1]
	cmp r0, 0x5
	bls _0813A7C6
	movs r0, 0
	strh r0, [r1]
_0813A7C6:
	ldrh r1, [r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	lsls r0, 24
	ldr r1, =gUnknown_085B3040
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A7B8

	thumb_func_start UpdateFrontierGambler
UpdateFrontierGambler: @ 813A7F4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004030
	bl GetVarPointer
	adds r5, r0, 0
	ldrh r0, [r5]
	adds r4, r0
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0xC
	bl __umodsi3
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateFrontierGambler

	thumb_func_start sub_813A820
sub_813A820: @ 813A820
	push {r4,lr}
	ldr r0, =0x00004030
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r1, =gUnknown_085B30A4
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	ldr r0, =0x00004031
	adds r1, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A820

	thumb_func_start sub_813A854
sub_813A854: @ 813A854
	push {r4,lr}
	ldr r4, =gUnknown_085B30D4
	ldr r0, =0x00004031
	bl VarGet
	lsls r0, 16
	lsrs r0, 14
	adds r0, r4
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A854

	thumb_func_start sub_813A878
sub_813A878: @ 813A878
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =0x00004031
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r4, =0x00004033
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0813A8F0
	ldr r1, =gUnknown_085B3104
	lsls r0, r6, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r5, 8
	adds r0, r7
	cmp r1, r0
	bne _0813A8F0
	mov r0, r8
	cmp r0, 0
	beq _0813A8E8
	adds r0, r4, 0
	movs r1, 0x2
	bl VarSet
	b _0813A8F0
	.pool
_0813A8E8:
	adds r0, r4, 0
	movs r1, 0x3
	bl VarSet
_0813A8F0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_813A878

	thumb_func_start sub_813A8FC
sub_813A8FC: @ 813A8FC
	push {lr}
	sub sp, 0x2C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000eb8
	adds r0, r1
	ldrh r1, [r0]
	add r0, sp, 0xC
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_BP
	bl StringCopy
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x30
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	ldr r0, =gUnknown_0203AB6D
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	bl PrintTextOnWindow
	add sp, 0x2C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A8FC

	thumb_func_start sub_813A958
sub_813A958: @ 813A958
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6D
	ldr r0, =gUnknown_085B311C
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	bl sub_813A8FC
	ldrb r0, [r4]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A958

	thumb_func_start sub_813A988
sub_813A988: @ 813A988
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6D
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A988

	thumb_func_start sub_813A9A4
sub_813A9A4: @ 813A9A4
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000eb8
	adds r1, r0, r2
	ldr r0, =gSpecialVar_0x8004
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r2, r0
	bcs _0813A9C8
	movs r0, 0
	b _0813A9CA
	.pool
_0813A9C8:
	subs r0, r2, r0
_0813A9CA:
	strh r0, [r1]
	pop {r0}
	bx r0
	thumb_func_end sub_813A9A4

	thumb_func_start sub_813A9D0
sub_813A9D0: @ 813A9D0
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000eb8
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	adds r1, r0
	ldr r0, =0x0000270f
	cmp r1, r0
	ble _0813A9FC
	strh r0, [r2]
	b _0813A9FE
	.pool
_0813A9FC:
	strh r1, [r2]
_0813A9FE:
	pop {r0}
	bx r0
	thumb_func_end sub_813A9D0

	thumb_func_start sub_813AA04
sub_813AA04: @ 813AA04
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000eb8
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_813AA04

	thumb_func_start sub_813AA18
sub_813AA18: @ 813AA18
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6E
	ldr r0, =gUnknown_085B3124
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r4]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AA18

	thumb_func_start sub_813AA44
sub_813AA44: @ 813AA44
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6E
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AA44

	thumb_func_start sub_813AA60
sub_813AA60: @ 813AA60
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	lsrs r4, r0, 16
	ldr r1, =0xfffd0000
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x3
	bls _0813AA78
	b _0813ABC2
_0813AA78:
	movs r0, 0xD8
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	cmp r4, 0x4
	beq _0813AAE8
	cmp r4, 0x4
	bgt _0813AAA0
	cmp r4, 0x3
	beq _0813AAAA
	b _0813ABC2
	.pool
_0813AAA0:
	cmp r4, 0x5
	beq _0813AB5C
	cmp r4, 0x6
	beq _0813AB94
	b _0813ABC2
_0813AAAA:
	ldr r1, =gUnknown_085B3170
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r1, =gUnknown_085B312C
	lsls r0, r5, 1
	adds r1, r0, r1
	ldrh r5, [r1]
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _0813AB18
	b _0813AB2C
	.pool
_0813AAE8:
	ldr r1, =gUnknown_085B319C
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
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
	bl AddTextPrinterParameterized
	ldr r1, =gUnknown_085B3142
	lsls r0, r5, 1
	adds r1, r0, r1
	ldrh r5, [r1]
	ldr r0, =0x0000ffff
	cmp r5, r0
	bne _0813AB2C
_0813AB18:
	ldrh r0, [r1]
	bl sub_813ABD4
	b _0813ABC2
	.pool
_0813AB2C:
	ldr r4, =0x0000157c
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	lsls r0, r5, 24
	lsrs r0, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x21
	movs r2, 0x58
	movs r3, 0
	bl AddDecorationIconObject
	ldr r1, =gUnknown_0203AB6C
	strb r0, [r1]
	b _0813ABC2
	.pool
_0813AB5C:
	ldr r1, =gUnknown_085B31B4
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
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
	bl AddTextPrinterParameterized
	ldr r1, =gUnknown_085B314E
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	bl sub_813ABD4
	b _0813ABC2
	.pool
_0813AB94:
	ldr r1, =gUnknown_085B31D0
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
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
	bl AddTextPrinterParameterized
	ldr r1, =gUnknown_085B315C
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	bl sub_813ABD4
_0813ABC2:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AA60

	thumb_func_start sub_813ABD4
sub_813ABD4: @ 813ABD4
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r4, =0x0000157c
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl AddItemIconSprite
	ldr r4, =gUnknown_0203AB6C
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0813AC32
	ldr r3, =gSprites
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x24
	strh r1, [r0, 0x20]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x5C
	strh r1, [r0, 0x22]
_0813AC32:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ABD4

	thumb_func_start sub_813AC44
sub_813AC44: @ 813AC44
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =gUnknown_0203AB6C
	ldrb r0, [r2]
	cmp r0, 0x40
	beq _0813AC70
	cmp r1, 0x6
	bgt _0813AC6A
	cmp r1, 0x3
	blt _0813AC6A
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySpriteAndFreeResources
_0813AC6A:
	ldr r1, =gUnknown_0203AB6C
	movs r0, 0x40
	strb r0, [r1]
_0813AC70:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AC44

	thumb_func_start sub_813AC7C
sub_813AC7C: @ 813AC7C
	push {lr}
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0
	beq _0813ACB8
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B320C
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	b _0813ACD2
	.pool
_0813ACB8:
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B31F8
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
_0813ACD2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AC7C

	thumb_func_start sub_813ACE8
sub_813ACE8: @ 813ACE8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0813AD20
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813AD18
	ldr r4, =gUnknown_0203AB5E
	ldr r0, =gUnknown_085B3220
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl SetStandardWindowBorderStyle
_0813AD18:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_813AD34
_0813AD20:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ACE8

	thumb_func_start sub_813AD34
sub_813AD34: @ 813AD34
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	adds r7, r5, 0
	lsrs r6, r0, 24
	movs r1, 0xF7
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0813ADAC
	ldr r4, =gUnknown_0203AB5E
	ldrb r0, [r4]
	movs r1, 0x60
	str r1, [sp]
	movs r1, 0x30
	str r1, [sp, 0x4]
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	cmp r6, 0xA
	bne _0813AD90
	ldrb r0, [r4]
	ldr r2, =gUnknown_085B3254
	lsls r1, r5, 2
	adds r1, r2
	ldr r2, [r1]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	b _0813ADAC
	.pool
_0813AD90:
	ldrb r0, [r4]
	ldr r2, =gUnknown_085B3228
	lsls r1, r7, 2
	adds r1, r2
	ldr r2, [r1]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
_0813ADAC:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AD34

	thumb_func_start sub_813ADB8
sub_813ADB8: @ 813ADB8
	push {r4,lr}
	ldr r4, =gUnknown_0203AB5E
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ADB8

	thumb_func_start sub_813ADD4
sub_813ADD4: @ 813ADD4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	ldr r0, =sub_813A600
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _0813AE90
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrh r0, [r6, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r4, sp
	adds r4, 0x16
	add r1, sp, 0x14
	adds r2, r4, 0
	bl ListMenuGetScrollAndRow
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl SetStandardWindowBorderStyle
	movs r5, 0
	mov r9, r4
	ldr r0, =gUnknown_085B2CF0
	mov r8, r0
	movs r4, 0
_0813AE1E:
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	add r1, sp, 0x14
	ldrh r2, [r1]
	adds r2, r5
	lsls r2, 2
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 6
	adds r2, r1
	add r2, r8
	ldr r2, [r2]
	lsls r1, r5, 28
	lsrs r1, 24
	str r1, [sp]
	movs r7, 0xFF
	str r7, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0xA
	bl sub_8199F74
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0813AE1E
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_SelectorArrow
	mov r3, r9
	ldrh r1, [r3]
	lsls r1, 28
	lsrs r1, 24
	str r1, [sp]
	str r7, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl CopyWindowToVram
_0813AE90:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ADD4

	thumb_func_start sub_813AEB4
sub_813AEB4: @ 813AEB4
	push {r4,lr}
	movs r1, 0
	ldr r0, =gSpecialVar_0x8005
	strh r1, [r0]
	ldr r0, =0x0000400e
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x0000400d
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r4, 0
	beq _0813AF18
	movs r2, 0
	lsls r1, 1
	ldr r3, =gUnknown_0861500C
	ldr r0, =gUnknown_085B320C
	adds r0, r1, r0
	ldrh r1, [r0]
_0813AEE2:
	lsls r0, r2, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	beq _0813AF0C
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1D
	bls _0813AEE2
	b _0813AF38
	.pool
_0813AF0C:
	ldr r0, =gSpecialVar_0x8005
	strh r2, [r0]
	b _0813AF38
	.pool
_0813AF18:
	movs r2, 0
	lsls r1, 1
	ldr r3, =gUnknown_0861500C
	ldr r0, =gUnknown_085B31F8
	adds r0, r1, r0
	ldrh r1, [r0]
_0813AF24:
	lsls r0, r2, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	beq _0813AF0C
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1D
	bls _0813AF24
_0813AF38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AEB4

	thumb_func_start sub_813AF48
sub_813AF48: @ 813AF48
	push {r4,r5,lr}
	ldr r0, =sub_813A600
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xFF
	beq _0813AFB6
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0
	bl DestroyListMenuTask
	ldr r0, =gUnknown_0203AB64
	ldr r0, [r0]
	bl Free
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_8198070
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl ClearWindowTilemap
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl CopyWindowToVram
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
_0813AFB6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AF48

	thumb_func_start sub_813AFC8
sub_813AFC8: @ 813AFC8
	push {lr}
	ldr r0, =task_deoxys_sound
	movs r1, 0x8
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AFC8

	thumb_func_start task_deoxys_sound
task_deoxys_sound: @ 813AFDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =0x000008d4
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B004
	ldr r1, =gSpecialVar_Result
	movs r0, 0x3
	b _0813B06A
	.pool
_0813B004:
	ldr r0, =0x00004035
	mov r8, r0
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r4, =0x00004034
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	cmp r5, 0
	beq _0813B05C
	ldr r0, =gUnknown_085B33F6
	subs r1, r5, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, r6
	bcs _0813B05C
	movs r0, 0
	bl sub_813B0B4
	mov r0, r8
	movs r1, 0
	bl VarSet
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	b _0813B070
	.pool
_0813B05C:
	cmp r5, 0xA
	bne _0813B080
	ldr r0, =0x000008d4
	bl FlagSet
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
_0813B06A:
	strh r0, [r1]
	bl EnableBothScriptContexts
_0813B070:
	adds r0, r7, 0
	bl DestroyTask
	b _0813B0A2
	.pool
_0813B080:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_813B0B4
	ldr r0, =0x00004035
	adds r1, r5, 0
	bl VarSet
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r7, 0
	bl DestroyTask
_0813B0A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_deoxys_sound

	thumb_func_start sub_813B0B4
sub_813B0B4: @ 813B0B4
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 5
	ldr r1, =gUnknown_085B3280
	adds r0, r1
	movs r1, 0xD0
	lsls r1, 1
	movs r2, 0x8
	bl LoadPalette
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x1
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	cmp r4, 0
	bne _0813B0F0
	movs r0, 0xC4
	bl PlaySE
	b _0813B0F8
	.pool
_0813B0F0:
	movs r0, 0x82
	lsls r0, 1
	bl PlaySE
_0813B0F8:
	ldr r0, =sub_813B160
	movs r1, 0x8
	bl CreateTask
	ldr r3, =gFieldEffectArguments
	movs r0, 0x1
	str r0, [r3]
	movs r0, 0x3A
	str r0, [r3, 0x4]
	movs r0, 0x1A
	str r0, [r3, 0x8]
	ldr r0, =gUnknown_085B33E0
	lsls r2, r4, 1
	adds r1, r2, r0
	ldrb r1, [r1]
	str r1, [r3, 0xC]
	adds r0, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	str r0, [r3, 0x10]
	adds r5, r2, 0
	cmp r4, 0
	bne _0813B138
	movs r0, 0x3C
	b _0813B13A
	.pool
_0813B138:
	movs r0, 0x5
_0813B13A:
	str r0, [r3, 0x14]
	movs r0, 0x42
	bl FieldEffectStart
	ldr r0, =gUnknown_085B33E0
	adds r1, r5, r0
	ldrb r1, [r1]
	adds r0, 0x1
	adds r0, r5, r0
	ldrb r2, [r0]
	movs r0, 0x1
	bl Overworld_SetEventObjTemplateCoords
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B0B4

	thumb_func_start sub_813B160
sub_813B160: @ 813B160
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x42
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _0813B17C
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_0813B17C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_813B160

	thumb_func_start increment_var_x4026_on_birth_island_modulo_100
increment_var_x4026_on_birth_island_modulo_100: @ 813B184
	push {r4,lr}
	ldr r4, =0x00004034
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00003a1a
	cmp r1, r0
	bne _0813B1C8
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x63
	bls _0813B1C0
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	b _0813B1C8
	.pool
_0813B1C0:
	adds r0, r4, 0
	adds r1, r2, 0
	bl VarSet
_0813B1C8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end increment_var_x4026_on_birth_island_modulo_100

	thumb_func_start sub_813B1D0
sub_813B1D0: @ 813B1D0
	push {lr}
	ldr r0, =0x00004035
	bl VarGet
	lsls r0, 24
	lsrs r0, 19
	ldr r1, =gUnknown_085B3280
	adds r0, r1
	movs r1, 0xD0
	lsls r1, 1
	movs r2, 0x8
	bl LoadPalette
	movs r0, 0x80
	lsls r0, 19
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B1D0

	thumb_func_start set_unknown_box_id
@ void set_unknown_box_id(char id)
set_unknown_box_id: @ 813B204
	ldr r1, =gUnknown_0203AB6F
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end set_unknown_box_id

	thumb_func_start get_unknown_box_id
get_unknown_box_id: @ 813B210
	ldr r0, =gUnknown_0203AB6F
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_unknown_box_id

	thumb_func_start sub_813B21C
sub_813B21C: @ 813B21C
	push {r4,r5,lr}
	ldr r5, =0x000008d7
	adds r0, r5, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _0813B258
	bl StorageGetCurrentBox
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	beq _0813B258
	adds r0, r5, 0
	bl FlagSet
	movs r0, 0x1
	b _0813B25A
	.pool
_0813B258:
	movs r0, 0
_0813B25A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_813B21C

	thumb_func_start sub_813B260
sub_813B260: @ 813B260
	push {r4-r7,lr}
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl set_unknown_box_id
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r4, r0, 24
_0813B278:
	movs r5, 0
	lsls r6, r4, 24
	lsls r7, r4, 16
_0813B27E:
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	bl GetBoxedMonPtr
	movs r1, 0xB
	movs r2, 0
	bl GetBoxMonData
	cmp r0, 0
	bne _0813B2C0
	bl get_unknown_box_id
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	beq _0813B2A6
	ldr r0, =0x000008d7
	bl FlagClear
_0813B2A6:
	ldr r0, =0x00004036
	lsrs r1, r7, 16
	bl VarSet
	bl sub_813B21C
	lsls r0, 24
	lsrs r0, 24
	b _0813B2DC
	.pool
_0813B2C0:
	adds r5, 0x1
	cmp r5, 0x1D
	ble _0813B27E
	adds r4, 0x1
	cmp r4, 0xE
	bne _0813B2CE
	movs r4, 0
_0813B2CE:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0813B278
	movs r0, 0
_0813B2DC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813B260

	thumb_func_start sub_813B2E4
sub_813B2E4: @ 813B2E4
	push {r4,lr}
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004038
	movs r1, 0
	bl VarSet
	movs r0, 0xDF
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B340
	ldr r0, =0x000001bf
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B330
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0
	adds r1, 0x9
	bl VarSet
	b _0813B36A
	.pool
_0813B330:
	movs r0, 0x1
	ands r4, r0
	cmp r4, 0
	bne _0813B354
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
_0813B340:
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0x1
	bl VarSet
	b _0813B36A
	.pool
_0813B354:
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0
	adds r1, 0x9
	bl VarSet
_0813B36A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B2E4

	thumb_func_start sub_813B374
sub_813B374: @ 813B374
	push {r4,lr}
	ldr r0, =0x00004037
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B3400
	subs r1, r4, 0x1
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl GetMapName
	cmp r4, 0x8
	bls _0813B3A8
	movs r0, 0x1
	b _0813B3AA
	.pool
_0813B3A8:
	movs r0, 0
_0813B3AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813B374

	thumb_func_start sub_813B3B0
sub_813B3B0: @ 813B3B0
	push {r4-r6,lr}
	ldr r5, =0x00004038
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004037
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _0813B47C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x000003e7
	cmp r4, r0
	bls _0813B474
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	cmp r0, 0x18
	bne _0813B414
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0x69
	bgt _0813B414
	cmp r0, 0x65
	blt _0813B414
	ldr r0, =0x00004039
	movs r1, 0x1
	b _0813B478
	.pool
_0813B414:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	adds r3, r0, 0
	cmp r1, 0
	bne _0813B444
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, 0x34
	beq _0813B436
	cmp r0, 0x34
	blt _0813B444
	cmp r0, 0x38
	bgt _0813B444
	cmp r0, 0x36
	blt _0813B444
_0813B436:
	ldr r0, =0x00004039
	movs r1, 0x1
	b _0813B478
	.pool
_0813B444:
	ldr r3, [r3]
	movs r2, 0x5
	ldrsb r2, [r3, r2]
	ldr r1, =gUnknown_085B3410
	subs r0, r6, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0813B468
	movs r0, 0x4
	ldrsb r0, [r3, r0]
	cmp r0, 0
	bne _0813B468
	movs r0, 0x1
	b _0813B47E
	.pool
_0813B468:
	ldr r0, =0x00004037
	movs r1, 0
	b _0813B478
	.pool
_0813B474:
	adds r0, r5, 0
	adds r1, r4, 0
_0813B478:
	bl VarSet
_0813B47C:
	movs r0, 0
_0813B47E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_813B3B0

	thumb_func_start sub_813B484
sub_813B484: @ 813B484
	push {lr}
	movs r0, 0x2
	bl sub_80AB104
	pop {r0}
	bx r0
	thumb_func_end sub_813B484

	thumb_func_start sub_813B490
sub_813B490: @ 813B490
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	movs r6, 0x4
	ldrsb r6, [r4, r6]
	ldr r5, =gUnknown_085B3420
	adds r0, r5, 0x2
	mov r12, r0
	adds r7, r5, 0x1
_0813B4A4:
	lsls r0, r3, 1
	adds r2, r0, r3
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r6, r0
	bne _0813B4CC
	movs r1, 0x5
	ldrsb r1, [r4, r1]
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r1, r0
	bne _0813B4CC
	mov r1, r12
	adds r0, r2, r1
	ldrb r0, [r0]
	b _0813B4D8
	.pool
_0813B4CC:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xB
	bls _0813B4A4
	movs r0, 0x1
_0813B4D8:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813B490

	thumb_func_start sub_813B4E0
sub_813B4E0: @ 813B4E0
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl GetRematchIdxByTrainerIdx
	cmp r0, 0
	blt _0813B50C
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B50C
	movs r0, 0x1
	b _0813B50E
	.pool
_0813B50C:
	movs r0, 0
_0813B50E:
	pop {r1}
	bx r1
	thumb_func_end sub_813B4E0

	thumb_func_start sub_813B514
sub_813B514: @ 813B514
	push {lr}
	ldr r0, =0x0000403f
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _0813B52C
	movs r0, 0x1
	b _0813B52E
	.pool
_0813B52C:
	movs r0, 0
_0813B52E:
	pop {r1}
	bx r1
	thumb_func_end sub_813B514

	thumb_func_start sub_813B534
sub_813B534: @ 813B534
	push {lr}
	ldr r2, =gUnknown_0203AB70
	ldr r1, =gBattleTypeFlags
	ldr r0, [r1]
	str r0, [r2]
	movs r0, 0
	str r0, [r1]
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0813B552
	ldr r0, =sub_80B3AF8
	movs r1, 0x5
	bl CreateTask
_0813B552:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B534

	thumb_func_start sub_813B568
sub_813B568: @ 813B568
	push {lr}
	ldr r0, =sub_813B57C
	movs r1, 0x5
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B568

	thumb_func_start sub_813B57C
sub_813B57C: @ 813B57C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	bls _0813B596
	b _0813B7C6
_0813B596:
	lsls r0, 2
	ldr r1, =_0813B5A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813B5A8:
	.4byte _0813B5D0
	.4byte _0813B5E4
	.4byte _0813B614
	.4byte _0813B6B4
	.4byte _0813B6E4
	.4byte _0813B728
	.4byte _0813B764
	.4byte _0813B772
	.4byte _0813B784
	.4byte _0813B7A8
_0813B5D0:
	ldr r0, =sub_80B3AF8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0813B5DE
	b _0813B7C6
_0813B5DE:
	b _0813B790
	.pool
_0813B5E4:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B5F2
	b _0813B7C6
_0813B5F2:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B5FE
	b _0813B790
_0813B5FE:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_0x8004
	movs r2, 0x2
	bl SendBlock
	b _0813B708
	.pool
_0813B614:
	bl GetBlockReceivedStatus
	movs r1, 0x2
	ands r1, r0
	cmp r1, 0
	bne _0813B622
	b _0813B7C6
_0813B622:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0813B62E
	b _0813B790
_0813B62E:
	ldr r5, =gSpecialVar_0x8005
	ldr r0, =gBlockRecvBuffer
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, 0x1
	bl ResetBlockReceivedFlag
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0813B668
	ldrh r1, [r5]
	cmp r1, 0x1
	bne _0813B668
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
	b _0813B790
	.pool
_0813B668:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	adds r2, r0, 0
	cmp r1, 0
	bne _0813B68C
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0813B68C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
	b _0813B6AC
	.pool
_0813B68C:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _0813B6A8
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813B6A8
	ldr r1, =gSpecialVar_Result
	movs r0, 0x3
	b _0813B6AC
	.pool
_0813B6A8:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
_0813B6AC:
	strh r0, [r1]
	b _0813B790
	.pool
_0813B6B4:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B6C2
	b _0813B7C6
_0813B6C2:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B790
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_Result
	movs r2, 0x2
	bl SendBlock
	b _0813B708
	.pool
_0813B6E4:
	bl GetBlockReceivedStatus
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0813B7C6
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0813B790
	ldr r1, =gSpecialVar_Result
	ldr r0, =gBlockRecvBuffer
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, 0
	bl ResetBlockReceivedFlag
_0813B708:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0813B7C6
	.pool
_0813B728:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B74C
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x2
	bne _0813B790
	ldr r0, =gText_YourPartnerHasRetired
	bl ShowFieldAutoScrollMessage
	b _0813B790
	.pool
_0813B74C:
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x3
	bne _0813B790
	ldr r0, =gText_YourPartnerHasRetired
	bl ShowFieldAutoScrollMessage
	b _0813B790
	.pool
_0813B764:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813B7C6
	b _0813B790
_0813B772:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B7C6
	bl sub_800ADF8
	b _0813B790
_0813B784:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B7C6
_0813B790:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0813B7C6
	.pool
_0813B7A8:
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	bne _0813B7B4
	bl sub_800AC34
_0813B7B4:
	ldr r0, =gBattleTypeFlags
	ldr r1, =gUnknown_0203AB70
	ldr r1, [r1]
	str r1, [r0]
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_0813B7C6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B57C

	thumb_func_start sub_813B7D8
sub_813B7D8: @ 813B7D8
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813B7F8
	ldr r2, =CB2_ReturnToFieldContinueScript
	movs r0, 0
	movs r1, 0x1
	bl DoRayquazaScene
	b _0813B802
	.pool
_0813B7F8:
	ldr r2, =CB2_ReturnToFieldContinueScript
	movs r0, 0x1
	movs r1, 0
	bl DoRayquazaScene
_0813B802:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B7D8

	thumb_func_start sub_813B80C
sub_813B80C: @ 813B80C
	push {lr}
	ldr r0, =sub_813B824
	movs r1, 0x8
	bl CreateTask
	movs r0, 0x9D
	bl PlaySE
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B80C

	thumb_func_start sub_813B824
sub_813B824: @ 813B824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r1, r0
	bne _0813B858
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x9D
	bl PlaySE
_0813B858:
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _0813B86C
	adds r0, r5, 0
	bl DestroyTask
_0813B86C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B824

	thumb_func_start sub_813B880
sub_813B880: @ 813B880
	push {lr}
	ldr r0, =_fwalk
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	movs r0, 0x4
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r2, [r1, 0xE]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B880

	thumb_func_start _fwalk
_fwalk: @ 813B8B0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	lsls r1, 1
	adds r1, r5
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r0, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0813B94E
	movs r6, 0
_0813B8EA:
	movs r4, 0
	lsls r3, r6, 3
	mov r10, r3
	adds r7, r6, 0x1
	mov r8, r7
_0813B8F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, r4
	adds r0, 0x6
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r1, r6
	adds r1, 0x4
	ldr r7, =0x00000201
	adds r2, r4, r7
	add r2, r10
	movs r7, 0x6
	ldrsh r3, [r5, r7]
	lsls r3, 5
	adds r2, r3
	lsls r2, 16
	lsrs r2, 16
	bl MapGridSetMetatileIdAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0813B8F4
	mov r1, r8
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0813B8EA
	bl DrawWholeMapView
	ldrh r0, [r5, 0x6]
	adds r0, 0x1
	strh r0, [r5, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0813B94E
	mov r0, r9
	bl DestroyTask
	bl EnableBothScriptContexts
_0813B94E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end _fwalk

	thumb_func_start sub_813B968
sub_813B968: @ 813B968
	push {r4,r5,lr}
	ldr r5, =gSpecialVar_Result
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	strh r0, [r5]
	ldrh r4, [r5]
	adds r0, r4, 0
	movs r1, 0x14
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	subs r4, r1
	strh r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B968

	thumb_func_start sub_813B9A0
sub_813B9A0: @ 813B9A0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x1C]
	movs r0, 0xB0
	lsls r0, 4
	cmp r1, r0
	bne _0813B9B6
	movs r0, 0x3
	bl Overworld_SetHealLocationWarp
_0813B9B6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B9A0

	thumb_func_start sub_813B9C0
sub_813B9C0: @ 813B9C0
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gUnknown_085B3444
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0813BA06
	adds r4, r1, 0
	adds r1, r2, 0
_0813B9E6:
	ldrh r0, [r2]
	cmp r0, r3
	bne _0813B9FC
	movs r0, 0x1
	b _0813BA08
	.pool
_0813B9FC:
	adds r1, 0x2
	adds r2, 0x2
	ldrh r0, [r1]
	cmp r0, r4
	bne _0813B9E6
_0813BA06:
	movs r0, 0
_0813BA08:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813B9C0

	thumb_func_start ResetFanClub
ResetFanClub: @ 813BA10
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x0000141e
	adds r1, r0, r2
	movs r2, 0
	strh r2, [r1]
	movs r1, 0xA1
	lsls r1, 5
	adds r0, r1
	strh r2, [r0]
	bx lr
	.pool
	thumb_func_end ResetFanClub

	thumb_func_start sub_813BA30
sub_813BA30: @ 813BA30
	push {lr}
	bl sub_813BF44
	lsls r0, 24
	cmp r0, 0
	beq _0813BA52
	bl sub_813BCE8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
_0813BA52:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BA30

	thumb_func_start sub_813BA60
sub_813BA60: @ 813BA60
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 7
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0813BAB6
	bl sub_813BF60
	bl sub_813BD84
	ldr r1, [r4]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	ldr r0, =0x00000315
	bl FlagClear
	ldr r0, =0x00000316
	bl FlagClear
	ldr r0, =0x00000317
	bl FlagClear
	movs r0, 0xC6
	lsls r0, 2
	bl FlagClear
	ldr r0, =0x000002da
	bl FlagClear
	ldr r0, =0x00004095
	movs r1, 0x1
	bl VarSet
_0813BAB6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BA60

	thumb_func_start sub_813BADC
sub_813BADC: @ 813BADC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x00004095
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _0813BB58
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x0000141e
	adds r3, r0, r5
	ldrh r2, [r3]
	movs r1, 0x7F
	ands r1, r2
	ldr r0, =gUnknown_085B3470
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r1, r0
	cmp r1, 0x13
	ble _0813BB54
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0813BB3C
	bl sub_813BB74
	ldr r0, [r4]
	adds r0, r5
	ldrh r2, [r0]
	ldr r1, =0x0000ff80
	ands r1, r2
	strh r1, [r0]
	b _0813BB58
	.pool
_0813BB3C:
	ldr r2, [r4]
	adds r2, r5
	ldrh r1, [r2]
	ldr r0, =0x0000ff80
	ands r0, r1
	movs r1, 0x14
	orrs r0, r1
	strh r0, [r2]
	b _0813BB58
	.pool
_0813BB54:
	adds r0, r2, r0
	strh r0, [r3]
_0813BB58:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x7F
	ands r0, r1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BADC

	thumb_func_start sub_813BB74
sub_813BB74: @ 813BB74
	push {r4-r7,lr}
	sub sp, 0x8
	movs r3, 0
	movs r5, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r2, =0x0000141e
	movs r6, 0x1
_0813BB82:
	ldr r0, [r7]
	adds r0, r2
	ldrh r1, [r0]
	ldr r0, =gUnknown_085B3474
	adds r0, r5, r0
	ldrb r4, [r0]
	asrs r1, r4
	ands r1, r6
	cmp r1, 0
	bne _0813BBC8
	adds r3, r5, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	bl Random
	adds r1, r6, 0
	ands r1, r0
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r1, 0
	beq _0813BBC8
	ldr r0, [r7]
	adds r0, r2
	adds r1, r6, 0
	lsls r1, r4
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _0813BBEA
	.pool
_0813BBC8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _0813BB82
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x0000141e
	adds r2, r0
	ldr r1, =gUnknown_085B3474
	adds r1, r3, r1
	movs r0, 0x1
	ldrb r1, [r1]
	lsls r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813BBEA:
	adds r0, r3, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BB74

	thumb_func_start sub_813BC00
sub_813BC00: @ 813BC00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0813BC2E
	movs r0, 0
	b _0813BC8E
_0813BC1E:
	mov r1, r8
	ldr r0, [r1]
	add r0, r9
	lsls r4, r6
	ldrh r1, [r0]
	eors r4, r1
	strh r4, [r0]
	b _0813BC8C
_0813BC2E:
	movs r5, 0
	ldr r2, =gSaveBlock1Ptr
	mov r8, r2
	ldr r0, =0x0000141e
	mov r9, r0
	movs r4, 0x1
_0813BC3A:
	mov r1, r8
	ldr r0, [r1]
	add r0, r9
	ldrh r1, [r0]
	ldr r7, =gUnknown_085B347C
	adds r0, r5, r7
	ldrb r6, [r0]
	asrs r1, r6
	ands r1, r4
	cmp r1, 0
	beq _0813BC5E
	mov r10, r5
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	bne _0813BC1E
_0813BC5E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _0813BC3A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x0000141e
	adds r4, r0, r2
	ldrh r1, [r4]
	mov r2, r10
	adds r0, r2, r7
	ldrb r2, [r0]
	adds r0, r1, 0
	asrs r0, r2
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0813BC8C
	adds r0, r3, 0
	lsls r0, r2
	eors r1, r0
	strh r1, [r4]
_0813BC8C:
	mov r0, r10
_0813BC8E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BC00

	thumb_func_start sub_813BCA8
sub_813BCA8: @ 813BCA8
	push {r4,r5,lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r4, [r0]
	movs r5, 0x1
_0813BCBA:
	adds r1, r2, 0
	adds r1, 0x8
	adds r0, r4, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _0813BCCE
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_0813BCCE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0813BCBA
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BCA8

	thumb_func_start sub_813BCE8
sub_813BCE8: @ 813BCE8
	push {r4-r6,lr}
	movs r5, 0
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldrh r1, [r0, 0xE]
	ldr r0, =0x000003e6
	cmp r1, r0
	bhi _0813BD58
	adds r6, r2, 0
	b _0813BD32
	.pool
_0813BD04:
	ldr r0, [r6]
	ldrh r1, [r0, 0xE]
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r2, 0xA1
	lsls r2, 5
	adds r0, r2
	ldrh r0, [r0]
	subs r1, r0
	cmp r1, 0xB
	ble _0813BD58
	bl sub_813BC00
	ldr r0, [r4]
	movs r1, 0xA1
	lsls r1, 5
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0xC
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0813BD32:
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _0813BD54
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r6]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	b _0813BD58
	.pool
_0813BD54:
	cmp r5, 0x8
	bne _0813BD04
_0813BD58:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_813BCE8

	thumb_func_start sub_813BD60
sub_813BD60: @ 813BD60
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_813BD60

	thumb_func_start sub_813BD84
sub_813BD84: @ 813BD84
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x0000141e
	adds r2, r0
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 3
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_813BD84

	thumb_func_start sub_813BDB4
sub_813BDB4: @ 813BDB4
	push {lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x8
	cmp r0, 0x7
	bhi _0813BE14
	lsls r0, 2
	ldr r1, =_0813BDD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813BDD8:
	.4byte _0813BE14
	.4byte _0813BE14
	.4byte _0813BDF8
	.4byte _0813BDFE
	.4byte _0813BE04
	.4byte _0813BE0A
	.4byte _0813BE10
	.4byte _0813BE14
_0813BDF8:
	movs r3, 0
	movs r2, 0x3
	b _0813BE14
_0813BDFE:
	movs r3, 0
	movs r2, 0x1
	b _0813BE14
_0813BE04:
	movs r3, 0x1
	movs r2, 0
	b _0813BE14
_0813BE0A:
	movs r3, 0
	movs r2, 0x4
	b _0813BE14
_0813BE10:
	movs r3, 0x1
	movs r2, 0x5
_0813BE14:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003150
	adds r0, r1
	adds r1, r3, 0
	bl sub_813BE30
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BDB4

	thumb_func_start sub_813BE30
sub_813BE30: @ 813BE30
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, r5, 4
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0813BEE8
	cmp r2, 0x5
	bhi _0813BED4
	lsls r0, r2, 2
	ldr r1, =_0813BE58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813BE58:
	.4byte _0813BED4
	.4byte _0813BE70
	.4byte _0813BE84
	.4byte _0813BE98
	.4byte _0813BEAC
	.4byte _0813BEC0
_0813BE70:
	ldr r0, =gStringVar1
	ldr r1, =gText_Steven
	bl StringCopy
	b _0813BF04
	.pool
_0813BE84:
	ldr r0, =gStringVar1
	ldr r1, =gText_Brawly
	bl StringCopy
	b _0813BF04
	.pool
_0813BE98:
	ldr r0, =gStringVar1
	ldr r1, =gText_Winona
	bl StringCopy
	b _0813BF04
	.pool
_0813BEAC:
	ldr r0, =gStringVar1
	ldr r1, =gText_Phoebe
	bl StringCopy
	b _0813BF04
	.pool
_0813BEC0:
	ldr r0, =gStringVar1
	ldr r1, =gText_Glacia
	bl StringCopy
	b _0813BF04
	.pool
_0813BED4:
	ldr r0, =gStringVar1
	ldr r1, =gText_Wallace
	bl StringCopy
	b _0813BF04
	.pool
_0813BEE8:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	movs r2, 0x7
	bl StringCopyN
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	adds r0, r6, 0
	adds r0, 0x50
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	bl ConvertInternationalString
_0813BF04:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BE30

	thumb_func_start sub_813BF10
sub_813BF10: @ 813BF10
	push {lr}
	ldr r0, =0x00004095
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _0813BF40
	bl sub_813BA30
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0813BF3C
	bl sub_813BB74
	b _0813BF40
	.pool
_0813BF3C:
	bl sub_813BC00
_0813BF40:
	pop {r0}
	bx r0
	thumb_func_end sub_813BF10

	thumb_func_start sub_813BF44
sub_813BF44: @ 813BF44
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 7
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_813BF44

	thumb_func_start sub_813BF60
sub_813BF60: @ 813BF60
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x0000141e
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x80
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_813BF60

	thumb_func_start sub_813BF7C
sub_813BF7C: @ 813BF7C
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	bl sub_813BADC
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BF7C

	.align 2, 0 @ Don't pad with nop.
