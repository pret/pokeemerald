	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start sub_8195960
sub_8195960: @ 8195960
	push {lr}
	ldr r1, =gUnknown_0860DE50
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195960

	thumb_func_start sub_8195980
sub_8195980: @ 8195980
	push {r4-r7,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, [r4]
	ldr r2, =0x00000ca8
	adds r0, r2
	movs r6, 0
	strb r6, [r0]
	ldr r1, [r4]
	adds r2, 0xA
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r4, [r4]
	ldr r0, =0x00000cdc
	adds r3, r4, r0
	ldr r2, =gUnknown_0860DE98
	lsls r1, r5, 2
	lsls r0, r7, 3
	adds r1, r0
	adds r1, r2
	ldr r0, [r3]
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _081959F2
	lsls r0, r5, 1
	lsls r1, r7, 2
	adds r0, r1
	ldr r2, =0x00000dc8
	adds r1, r4, r2
	adds r1, r0
	strh r6, [r1]
_081959F2:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl saved_warp2_set
	ldr r0, =gTrainerBattleOpponent_A
	strh r6, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195980

	thumb_func_start sub_8195A38
sub_8195A38: @ 8195A38
	push {r4-r7,lr}
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r7, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08195A90
	cmp r0, 0x1
	bgt _08195A74
	cmp r0, 0
	beq _08195A7A
	b _08195AD0
	.pool
_08195A74:
	cmp r0, 0x2
	beq _08195AB0
	b _08195AD0
_08195A7A:
	ldr r0, =gSpecialVar_Result
	ldr r1, [r5]
	ldr r2, =0x00000dc6
	adds r1, r2
	ldrh r1, [r1]
	strh r1, [r0]
	b _08195AD0
	.pool
_08195A90:
	ldr r3, =gSpecialVar_Result
	ldr r0, [r5]
	lsls r1, r7, 1
	lsls r2, r6, 2
	adds r1, r2
	ldr r2, =0x00000dc8
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	b _08195AD0
	.pool
_08195AB0:
	ldr r4, =gSpecialVar_Result
	ldr r2, [r5]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_0860DE98
	lsls r0, r7, 2
	lsls r1, r6, 3
	adds r0, r1
	adds r0, r3
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	strh r0, [r4]
_08195AD0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195A38

	thumb_func_start sub_8195AE4
sub_8195AE4: @ 8195AE4
	push {r4-r6,lr}
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08195B3C
	cmp r0, 0x1
	bgt _08195B20
	cmp r0, 0
	beq _08195B26
	b _08195BA0
	.pool
_08195B20:
	cmp r0, 0x2
	beq _08195B5C
	b _08195BA0
_08195B26:
	ldr r0, [r6]
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	ldr r2, =0x00000dc6
	adds r0, r2
	strh r1, [r0]
	b _08195BA0
	.pool
_08195B3C:
	ldr r2, [r6]
	lsls r0, r5, 1
	lsls r1, r4, 2
	adds r0, r1
	ldr r1, =0x00000dc8
	adds r2, r1
	adds r2, r0
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	strh r0, [r2]
	b _08195BA0
	.pool
_08195B5C:
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	beq _08195B88
	ldr r2, [r6]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_0860DE98
	lsls r1, r5, 2
	lsls r0, r4, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	orrs r0, r1
	b _08195B9E
	.pool
_08195B88:
	ldr r2, [r6]
	ldr r1, =0x00000cdc
	adds r2, r1
	ldr r3, =gUnknown_0860DEA8
	lsls r1, r5, 2
	lsls r0, r4, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	ands r0, r1
_08195B9E:
	str r0, [r2]
_08195BA0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195AE4

	thumb_func_start sub_8195BB0
sub_8195BB0: @ 8195BB0
	push {r4,lr}
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	ldr r1, =gSaveBlock2Ptr
	ldr r2, [r1]
	ldr r3, =0x00000ca9
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, 30
	lsrs r1, 29
	lsrs r0, 14
	adds r1, r0
	ldr r0, =0x00000dc8
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, 0x31
	bhi _08195C00
	ldr r4, =gSpecialVar_Result
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	strh r0, [r4]
	b _08195C16
	.pool
_08195C00:
	cmp r0, 0x62
	bhi _08195C10
	ldr r1, =gSpecialVar_Result
	movs r0, 0x3
	b _08195C14
	.pool
_08195C10:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x4
_08195C14:
	strh r0, [r1]
_08195C16:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195BB0

	thumb_func_start sub_8195C20
sub_8195C20: @ 8195C20
	push {r4,lr}
	ldr r4, =gTrainerBattleOpponent_A
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xFF
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsrs r1, 6
	strh r1, [r4]
	ldrh r0, [r4]
	movs r1, 0
	bl sub_8162614
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195C20

	thumb_func_start sub_8195C50
sub_8195C50: @ 8195C50
	push {lr}
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r1, [r3]
	ldr r0, =0x0000012b
	cmp r1, r0
	bhi _08195C6C
	ldr r2, =gFacilityTrainers
	movs r0, 0x34
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xC
	bl ConvertBattleFrontierTrainerSpeechToString
_08195C6C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195C50

	thumb_func_start sub_8195C7C
sub_8195C7C: @ 8195C7C
	push {r4-r7,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r7, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	ldr r4, [r4]
	lsls r1, r7, 1
	lsrs r5, r0, 22
	adds r1, r5
	ldr r3, =0x00000dc8
	adds r6, r4, r3
	adds r3, r6, r1
	ldrh r2, [r3]
	ldr r0, =0x0000270e
	cmp r2, r0
	bhi _08195CCA
	adds r2, 0x1
	strh r2, [r3]
	movs r3, 0xDD
	lsls r3, 4
	adds r0, r4, r3
	adds r1, r0, r1
	adds r0, r5, 0
	ldrh r3, [r1]
	cmp r7, r3
	bls _08195CC0
	adds r0, 0x2
_08195CC0:
	adds r0, r6, r0
	ldrh r0, [r0]
	cmp r0, 0
	beq _08195CCA
	strh r2, [r1]
_08195CCA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195C7C

	thumb_func_start sub_8195CE4
sub_8195CE4: @ 8195CE4
	push {r4,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	movs r1, 0
	bl VarSet
	ldr r1, [r4]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl sub_81A4C30
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195CE4

	thumb_func_start sub_8195D28
sub_8195D28: @ 8195D28
	push {r4,r5,lr}
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	ldr r3, =0x00000ca9
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, 30
	lsrs r1, 29
	lsrs r0, 14
	adds r1, r0
	ldr r0, =0x00000dc8
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, 0x29
	bls _08195D88
	bl Random
	ldr r4, [r4]
	ldr r5, =gUnknown_0860DE84
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 15
	adds r0, r5
	ldrh r0, [r0]
	ldr r1, =0x00000dc6
	adds r4, r1
	b _08195DA6
	.pool
_08195D88:
	bl Random
	ldr r4, [r4]
	ldr r5, =gUnknown_0860DE78
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 15
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, =0x00000dc6
	adds r4, r3
_08195DA6:
	strh r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195D28

	thumb_func_start sub_8195DB8
sub_8195DB8: @ 8195DB8
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000dc6
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _08195E00
	ldr r0, [r4]
	ldr r1, =0x00000dc6
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, [r4]
	ldr r1, =0x00000dc6
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	b _08195E06
	.pool
_08195E00:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
_08195E06:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195DB8

	thumb_func_start sub_8195E10
sub_8195E10: @ 8195E10
	push {lr}
	bl RtcCalcLocalTime
	ldr r0, =gLocalTime
	bl sub_8195E34
	ldr r1, =gUnknown_0203CD80
	adds r0, 0xA
	str r0, [r1]
	movs r0, 0
	strb r0, [r1, 0x6]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195E10

	thumb_func_start sub_8195E34
sub_8195E34: @ 8195E34
	adds r3, r0, 0
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	movs r2, 0x2
	ldrsb r2, [r3, r2]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 2
	adds r0, r1
	movs r1, 0x3
	ldrsb r1, [r3, r1]
	adds r0, r1
	bx lr
	thumb_func_end sub_8195E34

	thumb_func_start sub_8195E58
sub_8195E58: @ 8195E58
	push {lr}
	bl RtcCalcLocalTime
	ldr r0, =gLocalTime
	bl sub_8195E34
	adds r1, r0, 0
	ldr r2, =gUnknown_0203CD80
	ldr r0, [r2]
	cmp r0, r1
	bhi _08195E74
	subs r0, r1, r0
	cmp r0, 0x9
	bls _08195E84
_08195E74:
	str r1, [r2]
	movs r0, 0x1
	b _08195E86
	.pool
_08195E84:
	movs r0, 0
_08195E86:
	pop {r1}
	bx r1
	thumb_func_end sub_8195E58

	thumb_func_start sub_8195E8C
sub_8195E8C: @ 8195E8C
	push {r4,r5,lr}
	movs r5, 0x1
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _08195EAE
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bne _08195EAE
	movs r5, 0x2
_08195EAE:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r5, 1
	adds r1, r5
	cmp r0, r1
	blt _08195ED0
	movs r0, 0
	b _08195ED2
	.pool
_08195ED0:
	movs r0, 0x1
_08195ED2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8195E8C

	thumb_func_start sub_8195ED8
sub_8195ED8: @ 8195ED8
	push {r4,lr}
	ldr r4, =gMapHeader
	ldrb r0, [r4, 0x17]
	bl Overworld_MapTypeAllowsTeleportAndFly
	lsls r0, 24
	cmp r0, 0
	beq _08195F30
	ldrb r0, [r4, 0x14]
	cmp r0, 0x39
	beq _08195F30
	cmp r0, 0xE
	bne _08195F0E
	movs r0, 0xF9
	lsls r0, 2
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08195F0E
	movs r0, 0xDC
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08195F30
_08195F0E:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	cmp r0, 0x38
	bne _08195F38
	movs r0, 0xCF
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08195F38
	movs r0, 0x8B
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08195F38
_08195F30:
	movs r0, 0
	b _08195F3A
	.pool
_08195F38:
	movs r0, 0x1
_08195F3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8195ED8

	thumb_func_start sub_8195F40
sub_8195F40: @ 8195F40
	push {lr}
	ldr r1, =gUnknown_0203CD80
	ldrb r0, [r1, 0x6]
	adds r0, 0x1
	strb r0, [r1, 0x6]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08195F5C
	movs r0, 0
	b _08195F62
	.pool
_08195F5C:
	movs r0, 0
	strb r0, [r1, 0x6]
	movs r0, 0x1
_08195F62:
	pop {r1}
	bx r1
	thumb_func_end sub_8195F40

	thumb_func_start sub_8195F68
sub_8195F68: @ 8195F68
	push {r4,lr}
	bl sub_8195FCC
	adds r4, r0, 0
	cmp r4, 0
	beq _08195FB8
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __umodsi3
	bl sub_8195FF8
	ldr r2, =gUnknown_0203CD80
	movs r1, 0
	strh r0, [r2, 0x4]
	strb r1, [r2, 0x7]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4E
	beq _08195FB8
	ldrh r0, [r2, 0x4]
	bl sub_8196844
	adds r4, r0, 0
	bl sub_819672C
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _08195FC4
	adds r0, r4, 0
	bl sub_8196710
	cmp r0, 0
	bne _08195FC4
_08195FB8:
	movs r0, 0
	b _08195FC6
	.pool
_08195FC4:
	movs r0, 0x1
_08195FC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8195F68

	thumb_func_start sub_8195FCC
sub_8195FCC: @ 8195FCC
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0
_08195FD2:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r4, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08195FE8
	adds r5, 0x1
_08195FE8:
	adds r4, 0x1
	cmp r4, 0x3F
	bls _08195FD2
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8195FCC

	thumb_func_start sub_8195FF8
sub_8195FF8: @ 8195FF8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gRematchTable
_08196000:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r4, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08196022
	cmp r5, 0
	bne _08196020
	ldrh r0, [r6]
	b _0819602C
	.pool
_08196020:
	subs r5, 0x1
_08196022:
	adds r6, 0x10
	adds r4, 0x1
	cmp r4, 0x3F
	bls _08196000
	movs r0, 0x4E
_0819602C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8195FF8

	thumb_func_start sub_8196034
sub_8196034: @ 8196034
	push {lr}
	ldr r0, =0x0000012f
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08196078
	bl sub_8195F40
	cmp r0, 0
	beq _08196078
	bl sub_8195E58
	cmp r0, 0
	beq _08196078
	bl sub_8195E8C
	cmp r0, 0
	beq _08196078
	bl sub_8195ED8
	cmp r0, 0
	beq _08196078
	bl sub_8195F68
	cmp r0, 0
	beq _08196078
	bl task_prev_quest
	movs r0, 0x1
	b _0819607A
	.pool
_08196078:
	movs r0, 0
_0819607A:
	pop {r1}
	bx r1
	thumb_func_end sub_8196034

	thumb_func_start sub_8196080
sub_8196080: @ 8196080
	push {lr}
	ldr r1, =gUnknown_0203CD80
	movs r0, 0x1
	strb r0, [r1, 0x7]
	bl task_prev_quest
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196080

	thumb_func_start sub_8196094
sub_8196094: @ 8196094
	push {lr}
	ldr r0, =sub_81960E0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196094

	thumb_func_start task_prev_quest
task_prev_quest: @ 81960A8
	push {lr}
	ldr r0, =gUnknown_0203CD80
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _081960C2
	bl ScriptContext2_Enable
	bl FreezeEventObjects
	bl sub_808B864
	bl sub_808BCF4
_081960C2:
	ldr r0, =0x00000107
	bl PlaySE
	ldr r0, =sub_81960E0
	movs r1, 0x1
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_prev_quest

	thumb_func_start sub_81960E0
sub_81960E0: @ 81960E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r1, =gUnknown_0860EF78
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
	cmp r0, 0
	beq _0819611E
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r1, 0
	strh r1, [r4, 0x2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7
	bls _0819611E
	adds r0, r5, 0
	bl DestroyTask
_0819611E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81960E0

	thumb_func_start sub_819612C
sub_819612C: @ 819612C
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gUnknown_0860EF98
	bl AddWindow
	strh r0, [r5, 0x4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	bne _0819615C
	adds r0, r4, 0
	b _081961E0
	.pool
_0819615C:
	ldr r1, =gUnknown_0860EA6C
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0x9C
	lsls r3, 2
	movs r0, 0
	bl LoadBgTiles
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _08196188
	ldrb r0, [r5, 0x4]
	bl RemoveWindow
	adds r0, r4, 0
	b _081961E0
	.pool
_08196188:
	ldr r1, =gUnknown_0860EB8C
	ldr r3, =0x00000279
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	bl decompress_and_copy_tile_data_to_vram
	cmp r0, 0
	beq _081961D8
	ldrb r0, [r5, 0x4]
	movs r1, 0x88
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0860EA4C
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0860EB6C
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =0xffffe000
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	b _081961E6
	.pool
_081961D8:
	ldrb r0, [r5, 0x4]
	bl RemoveWindow
	adds r0, r6, 0
_081961E0:
	bl DestroyTask
	movs r0, 0
_081961E6:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_819612C

	thumb_func_start sub_81961F0
sub_81961F0: @ 81961F0
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _08196268
	ldrb r0, [r4, 0x4]
	bl PutWindowTilemap
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r1, 0x9C
	lsls r1, 2
	movs r2, 0xE
	bl sub_819645C
	ldr r1, =0x0000f279
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0xF
	bl WriteSequenceToBgTilemapBuffer
	ldr r0, =sub_8196694
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	ldrb r0, [r4, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	b _0819626A
	.pool
_08196268:
	movs r0, 0
_0819626A:
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81961F0

	thumb_func_start sub_8196274
sub_8196274: @ 8196274
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _08196298
	movs r0, 0
	b _081962A4
	.pool
_08196298:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, =gText_PokenavCallEllipsis
	bl sub_81965D8
	movs r0, 0x1
_081962A4:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196274

	thumb_func_start sub_81962B0
sub_81962B0: @ 81962B0
	push {lr}
	movs r1, 0xC0
	lsls r1, 3
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgY
	cmp r0, 0
	bge _081962C6
	movs r0, 0
	b _081962D2
_081962C6:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
_081962D2:
	pop {r1}
	bx r1
	thumb_func_end sub_81962B0

	thumb_func_start sub_81962D8
sub_81962D8: @ 81962D8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl sub_8196648
	cmp r0, 0
	bne _08196328
	ldrb r0, [r4, 0x4]
	movs r1, 0x88
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_0203CD80
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _0819630C
	ldrh r0, [r1, 0x4]
	ldr r1, =gStringVar4
	bl sub_81967AC
_0819630C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, =gStringVar4
	bl sub_81965D8
	movs r0, 0x1
	b _0819632A
	.pool
_08196328:
	movs r0, 0
_0819632A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81962D8

	thumb_func_start sub_8196330
sub_8196330: @ 8196330
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl sub_8196648
	cmp r0, 0
	bne _08196388
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _08196388
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08196388
	ldrb r0, [r4, 0x4]
	movs r1, 0x88
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x84
	lsls r0, 1
	bl PlaySE
	movs r0, 0x1
	b _0819638A
	.pool
_08196388:
	movs r0, 0
_0819638A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8196330

	thumb_func_start sub_8196390
sub_8196390: @ 8196390
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0xC0
	lsls r1, 3
	movs r0, 0
	movs r2, 0x2
	bl ChangeBgY
	ldr r1, =0xffffe000
	cmp r0, r1
	ble _081963C0
	movs r0, 0
	b _081963E8
	.pool
_081963C0:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xE
	bl FillBgTilemapBufferRect_Palette0
	ldrb r0, [r4, 0xA]
	bl DestroyTask
	ldrb r0, [r4, 0x4]
	bl RemoveWindow
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
_081963E8:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8196390

	thumb_func_start sub_81963F0
sub_81963F0: @ 81963F0
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08196454
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _08196454
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_0203CD80
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _08196446
	bl sub_81973A4
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetEventObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	bl EventObjectClearHeldMovementIfFinished
	bl sub_80D338C
	bl UnfreezeEventObjects
	bl ScriptContext2_Disable
_08196446:
	movs r0, 0x1
	b _08196456
	.pool
_08196454:
	movs r0, 0
_08196456:
	pop {r1}
	bx r1
	thumb_func_end sub_81963F0

	thumb_func_start sub_819645C
sub_819645C: @ 819645C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl GetWindowAttribute
	mov r9, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl GetWindowAttribute
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x2
	bl GetWindowAttribute
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x3
	bl GetWindowAttribute
	adds r6, r0, 0
	adds r0, r4, 0
	movs r1, 0x4
	bl GetWindowAttribute
	str r0, [sp, 0x10]
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r1, 0xA
	bl GetBgAttribute
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0
	lsls r7, 12
	movs r1, 0xF0
	lsls r1, 8
	adds r0, r1, 0
	ands r7, r0
	adds r1, r7, 0
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x8]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	ldr r4, [sp, 0xC]
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	movs r3, 0x1
	mov r8, r3
	str r3, [sp]
	str r3, [sp, 0x4]
	mov r0, r9
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x1
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x8]
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsls r0, r6, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	str r0, [sp]
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x14]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x2
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [sp, 0x8]
	adds r0, r3, r6
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x1C]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x3
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0xC]
	lsls r6, r2, 24
	lsrs r6, 24
	mov r3, r8
	str r3, [sp]
	ldr r0, [sp, 0x10]
	lsls r4, r0, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	mov r0, r9
	mov r2, r10
	adds r3, r6, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x4
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	mov r2, r8
	str r2, [sp]
	str r4, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x1C]
	adds r3, r6, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x5
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [sp, 0xC]
	ldr r2, [sp, 0x10]
	adds r0, r3, r2
	lsls r0, 24
	lsrs r4, r0, 24
	mov r3, r8
	str r3, [sp]
	str r3, [sp, 0x4]
	mov r0, r9
	mov r2, r10
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x6
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x14]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r5, 0x7
	orrs r5, r7
	lsls r5, 16
	lsrs r5, 16
	mov r3, r8
	str r3, [sp]
	str r3, [sp, 0x4]
	mov r0, r9
	adds r1, r5, 0
	ldr r2, [sp, 0x1C]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_819645C

	thumb_func_start sub_81965D8
sub_81965D8: @ 81965D8
	push {lr}
	sub sp, 0x10
	str r1, [sp]
	mov r1, sp
	movs r3, 0
	strb r0, [r1, 0x4]
	mov r0, sp
	movs r1, 0x1
	strb r1, [r0, 0x5]
	movs r2, 0x20
	strb r2, [r0, 0x6]
	strb r1, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r3, [r0, 0xA]
	strb r3, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x11
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r3, 0xF
	movs r0, 0xA0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	movs r0, 0x8
	orrs r1, r0
	strb r1, [r2, 0xD]
	ands r1, r3
	movs r0, 0xE0
	orrs r1, r0
	strb r1, [r2, 0xD]
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl GetPlayerTextSpeed
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81965D8

	thumb_func_start sub_8196648
sub_8196648: @ 8196648
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0819666C
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _08196678
	.pool
_0819666C:
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08196678:
	bl RunTextPrinters
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196648

	thumb_func_start sub_8196694
sub_8196694: @ 8196694
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _081966FC
	movs r1, 0
	strh r1, [r2]
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	strh r0, [r2, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _081966C8
	strh r1, [r2, 0x2]
_081966C8:
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	lsls r1, 4
	ldr r0, =0x00000279
	adds r1, r0
	strh r1, [r2, 0x4]
	ldr r2, =0xfffff000
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0xF
	bl WriteSequenceToBgTilemapBuffer
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_081966FC:
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196694

	thumb_func_start sub_8196710
sub_8196710: @ 8196710
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x000009ca
	adds r1, r2
	adds r1, r0
	ldrb r1, [r1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_8196710

	thumb_func_start sub_819672C
sub_819672C: @ 819672C
	push {lr}
	ldr r1, =gRematchTable
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	adds r0, r2, 0
	bl Overworld_GetMapHeaderByGroupAndId
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_819672C

	thumb_func_start sub_8196748
sub_8196748: @ 8196748
	push {r4-r6,lr}
	movs r5, 0
	movs r6, 0
	ldr r4, =gRematchTable
_08196750:
	ldrh r0, [r4]
	bl HasTrainerBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _0819675E
	adds r6, 0x1
_0819675E:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x3F
	bls _08196750
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196748

	thumb_func_start sub_8196774
sub_8196774: @ 8196774
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0
	ldr r5, =gRematchTable
_0819677E:
	ldrh r0, [r5]
	bl HasTrainerBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _0819679A
	cmp r6, r7
	bne _08196798
	adds r0, r4, 0
	b _081967A4
	.pool
_08196798:
	adds r6, 0x1
_0819679A:
	adds r5, 0x10
	adds r4, 0x1
	cmp r4, 0x4D
	bls _0819677E
	movs r0, 0x4E
_081967A4:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8196774

	thumb_func_start sub_81967AC
sub_81967AC: @ 81967AC
	push {r4-r7,lr}
	adds r6, r1, 0
	movs r7, 0
	bl sub_8196844
	adds r5, r0, 0
	ldr r0, =gUnknown_0203CD88
	strh r7, [r0]
	adds r0, r5, 0
	bl sub_8196710
	cmp r0, 0
	beq _081967EC
	adds r0, r5, 0
	bl sub_819672C
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081967EC
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8196864
	b _08196830
	.pool
_081967EC:
	adds r0, r5, 0
	bl sub_8196D74
	cmp r0, 0
	beq _0819680A
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8196890
	adds r4, r0, 0
	movs r7, 0x1
	adds r0, r5, 0
	bl UpdateRematchIfDefeated
	b _08196832
_0819680A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08196828
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_81968BC
	b _08196830
_08196828:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8196910
_08196830:
	adds r4, r0, 0
_08196832:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_81969E0
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81967AC

	thumb_func_start sub_8196844
sub_8196844: @ 8196844
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =gUnknown_0860DEB8
_0819684C:
	ldrh r0, [r1]
	cmp r0, r3
	beq _0819685C
	adds r1, 0x14
	adds r2, 0x1
	b _0819684C
	.pool
_0819685C:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8196844

	thumb_func_start sub_8196864
sub_8196864: @ 8196864
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r1, [r1, 0xE]
	movs r2, 0xFF
	lsrs r0, r1, 8
	subs r0, 0x1
	ands r1, r2
	subs r1, 0x1
	ldr r2, =gUnknown_0860EA2C
	lsls r0, 2
	adds r0, r2
	lsls r1, 3
	ldr r0, [r0]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_8196864

	thumb_func_start sub_8196890
sub_8196890: @ 8196890
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r1, [r1, 0x10]
	movs r2, 0xFF
	lsrs r0, r1, 8
	subs r0, 0x1
	ands r1, r2
	subs r1, 0x1
	ldr r2, =gUnknown_0860EA2C
	lsls r0, 2
	adds r0, r2
	lsls r1, 3
	ldr r0, [r0]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_8196890

	thumb_func_start sub_81968BC
sub_81968BC: @ 81968BC
	push {r4,lr}
	adds r4, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	ldr r2, =gUnknown_0860DEB8
	lsrs r0, 15
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	adds r0, r1
	adds r2, 0x4
	adds r0, r2
	ldrh r4, [r0]
	cmp r4, 0
	bne _081968EC
	movs r0, 0
	bl SpriteCallbackDummy
_081968EC:
	movs r1, 0xFF
	lsrs r0, r4, 8
	subs r0, 0x1
	ands r4, r1
	subs r1, r4, 0x1
	ldr r2, =gUnknown_0860EA20
	lsls r0, 2
	adds r0, r2
	lsls r1, 3
	ldr r0, [r0]
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81968BC

	thumb_func_start sub_8196910
sub_8196910: @ 8196910
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081969AC
	movs r5, 0
	movs r4, 0
	lsls r7, r6, 2
_0819692C:
	lsls r0, r4, 16
	lsrs r0, 16
	mov r1, sp
	bl sub_8196E04
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08196940
	adds r5, 0x1
_08196940:
	adds r4, 0x1
	cmp r4, 0x6
	ble _0819692C
	cmp r5, 0
	beq _081969AC
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	adds r5, r0, 0
	movs r4, 0
	b _08196962
_0819695E:
	subs r5, 0x1
_08196960:
	adds r4, 0x1
_08196962:
	cmp r4, 0x6
	bgt _08196980
	lsls r0, r4, 16
	lsrs r0, 16
	mov r1, sp
	bl sub_8196E04
	ldr r1, =gUnknown_0203CD88
	strh r0, [r1, 0x2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08196960
	cmp r5, 0
	bne _0819695E
_08196980:
	ldr r0, =gUnknown_0203CD88
	strh r4, [r0]
	ldr r1, =gUnknown_0860DEB8
	adds r0, r7, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0xC]
	subs r2, r0, 0x1
	ldr r1, =gUnknown_0860EA34
	ldr r0, [sp]
	lsls r0, 2
	adds r0, r1
	lsls r1, r2, 3
	ldr r0, [r0]
	adds r0, r1
	b _081969D0
	.pool
_081969AC:
	ldr r1, =gUnknown_0860DEB8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrh r2, [r0, 0xA]
	lsrs r1, r2, 8
	subs r1, 0x1
	str r1, [sp]
	movs r0, 0xFF
	ands r0, r2
	subs r2, r0, 0x1
	ldr r0, =gUnknown_0860EA34
	lsls r1, 2
	adds r1, r0
	lsls r2, 3
	ldr r0, [r1]
	adds r0, r2
_081969D0:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196910

	thumb_func_start sub_81969E0
sub_81969E0: @ 81969E0
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r1, r4, 0x4
	bl sub_81969FC
	ldr r1, [r4]
	adds r0, r5, 0
	bl StringExpandPlaceholders
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81969E0

	thumb_func_start sub_81969FC
sub_81969FC: @ 81969FC
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	movs r4, 0
	ldr r5, =gUnknown_0860EFA0
_08196A06:
	adds r1, r6, r4
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0
	blt _08196A1A
	adds r1, r0, 0
	ldr r2, [r5]
	adds r0, r7, 0
	bl sub_8196A2C
_08196A1A:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0x2
	ble _08196A06
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81969FC

	thumb_func_start sub_8196A2C
sub_8196A2C: @ 8196A2C
	push {lr}
	ldr r3, =gUnknown_0860EFAC
	lsls r1, 2
	adds r1, r3
	ldr r3, [r1]
	adds r1, r2, 0
	bl _call_via_r3
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196A2C

	thumb_func_start sub_8196A44
sub_8196A44: @ 8196A44
	push {r4-r6,lr}
	adds r5, r1, 0
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r4, [r1]
	movs r2, 0
	ldr r3, =gUnknown_0860EFC4
	adds r6, r3, 0
_08196A5A:
	lsls r1, r2, 3
	ldrh r0, [r3]
	cmp r0, r4
	bne _08196A78
	adds r0, r6, 0x4
	adds r0, r1, r0
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy
	b _08196A90
	.pool
_08196A78:
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x5
	bls _08196A5A
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	ldr r0, =gTrainers + 0x4 @ name offset
	adds r1, r0
	adds r0, r5, 0
	bl StringCopy
_08196A90:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196A44

	thumb_func_start sub_8196A9C
sub_8196A9C: @ 8196A9C
	push {r4,lr}
	adds r4, r1, 0
	bl sub_819672C
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl GetMapName
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8196A9C

	thumb_func_start sub_8196AB8
sub_8196AB8: @ 8196AB8
	push {lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x13
	bgt _08196AD4
	movs r0, 0
	b _08196B4A
_08196AD4:
	adds r0, r1, 0
	subs r0, 0x14
	cmp r0, 0x13
	bhi _08196AE0
	movs r0, 0x1
	b _08196B4A
_08196AE0:
	adds r0, r1, 0
	subs r0, 0x28
	cmp r0, 0x9
	bhi _08196AEC
	movs r0, 0x2
	b _08196B4A
_08196AEC:
	adds r0, r1, 0
	subs r0, 0x32
	cmp r0, 0x9
	bhi _08196AF8
	movs r0, 0x3
	b _08196B4A
_08196AF8:
	adds r0, r1, 0
	subs r0, 0x3C
	cmp r0, 0x9
	bhi _08196B04
	movs r0, 0x4
	b _08196B4A
_08196B04:
	adds r0, r1, 0
	subs r0, 0x46
	cmp r0, 0x9
	bhi _08196B10
	movs r0, 0x5
	b _08196B4A
_08196B10:
	adds r0, r1, 0
	subs r0, 0x50
	cmp r0, 0x4
	bhi _08196B1C
	movs r0, 0x6
	b _08196B4A
_08196B1C:
	adds r0, r1, 0
	subs r0, 0x55
	cmp r0, 0x4
	bhi _08196B28
	movs r0, 0x7
	b _08196B4A
_08196B28:
	adds r0, r1, 0
	subs r0, 0x5A
	cmp r0, 0x3
	bhi _08196B34
	movs r0, 0x8
	b _08196B4A
_08196B34:
	adds r0, r1, 0
	subs r0, 0x5E
	cmp r0, 0x3
	bhi _08196B40
	movs r0, 0x9
	b _08196B4A
_08196B40:
	cmp r1, 0x62
	beq _08196B48
	movs r0, 0xB
	b _08196B4A
_08196B48:
	movs r0, 0xA
_08196B4A:
	pop {r1}
	bx r1
	thumb_func_end sub_8196AB8

	thumb_func_start sub_8196B50
sub_8196B50: @ 8196B50
	push {lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3B
	bgt _08196B6C
	movs r0, 0
	b _08196B92
_08196B6C:
	adds r0, r1, 0
	subs r0, 0x3C
	cmp r0, 0x1D
	bhi _08196B78
	movs r0, 0x1
	b _08196B92
_08196B78:
	adds r0, r1, 0
	subs r0, 0x5A
	cmp r0, 0x4
	bhi _08196B84
	movs r0, 0x2
	b _08196B92
_08196B84:
	adds r0, r1, 0
	subs r0, 0x5F
	cmp r0, 0x3
	bls _08196B90
	movs r0, 0x4
	b _08196B92
_08196B90:
	movs r0, 0x3
_08196B92:
	pop {r1}
	bx r1
	thumb_func_end sub_8196B50

	thumb_func_start sub_8196B98
sub_8196B98: @ 8196B98
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r2, r0, 0
	mov r8, r1
	movs r3, 0
	ldr r0, =gWildMonHeaders
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0xFF
	beq _08196C5C
	ldr r1, =gRematchTable
	lsls r0, r2, 4
	adds r2, r0, r1
	ldrh r4, [r2, 0xA]
	adds r1, r7, 0
_08196BBA:
	ldrb r0, [r1]
	cmp r0, r4
	bne _08196BC8
	ldrb r0, [r1, 0x1]
	ldrh r5, [r2, 0xC]
	cmp r0, r5
	beq _08196BD2
_08196BC8:
	adds r1, 0x14
	adds r3, 0x1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _08196BBA
_08196BD2:
	adds r1, r7, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r5, r0, 2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _08196C5C
	movs r6, 0
	adds r0, r1, 0x4
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r4, 0
	beq _08196C02
	bl sub_8196AB8
	lsls r0, 24
	mov r2, sp
	ldr r1, [r4, 0x4]
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0, 0x2]
	strh r0, [r2]
	movs r6, 0x1
_08196C02:
	adds r0, r7, 0
	adds r0, 0x8
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r4, 0
	beq _08196C26
	bl sub_8196B50
	lsls r0, 24
	lsls r1, r6, 1
	mov r3, sp
	adds r2, r3, r1
	ldr r1, [r4, 0x4]
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0, 0x2]
	strh r0, [r2]
	adds r6, 0x1
_08196C26:
	cmp r6, 0
	beq _08196C5C
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 1
	add r0, sp
	ldrh r1, [r0]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	mov r0, r8
	bl StringCopy
	b _08196C62
	.pool
_08196C5C:
	movs r0, 0xFF
	mov r5, r8
	strb r0, [r5]
_08196C62:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8196B98

	thumb_func_start sub_8196C70
sub_8196C70: @ 8196C70
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1]
	bl GetLastBeatenRematchTrainerId
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gTrainers
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r0, r5, 0
	adds r0, 0x24
	adds r0, r4, r0
	ldr r6, [r0]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r4, r5
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r1, [r1]
	bl __modsi3
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r4]
	cmp r1, 0x1
	beq _08196CD4
	cmp r1, 0x1
	ble _08196CC2
	cmp r1, 0x2
	beq _08196CD0
	cmp r1, 0x3
	beq _08196CD4
_08196CC2:
	lsls r0, 3
	b _08196CD6
	.pool
_08196CD0:
	lsls r0, 3
	b _08196CD6
_08196CD4:
	lsls r0, 4
_08196CD6:
	adds r0, r6
	ldrh r1, [r0, 0x4]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r7, 0
	bl StringCopy
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196C70

	thumb_func_start sub_8196CF4
sub_8196CF4: @ 8196CF4
	push {lr}
	adds r0, r1, 0
	ldr r2, =gUnknown_0860EFF4
	ldr r1, =gUnknown_0203CD88
	ldrh r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196CF4

	thumb_func_start sub_8196D14
sub_8196D14: @ 8196D14
	push {r4-r6,lr}
	adds r5, r1, 0
	movs r4, 0
	ldr r0, =gUnknown_0203CD88
	ldrh r1, [r0, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	beq _08196D34
_08196D24:
	adds r0, r1, 0
	movs r1, 0xA
	bl __divsi3
	adds r1, r0, 0
	adds r4, 0x1
	cmp r1, 0
	bne _08196D24
_08196D34:
	ldrh r1, [r6, 0x2]
	lsls r3, r4, 24
	lsrs r3, 24
	adds r0, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196D14

	thumb_func_start sub_8196D4C
sub_8196D4C: @ 8196D4C
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_0860F010
	b _08196D5C
	.pool
_08196D58:
	adds r5, 0x2
	adds r4, 0x1
_08196D5C:
	cmp r4, 0x7
	bhi _08196D6C
	ldrh r0, [r5]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08196D58
_08196D6C:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8196D4C

	thumb_func_start sub_8196D74
sub_8196D74: @ 8196D74
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	bl sub_8196D4C
	cmp r0, 0x4
	ble _08196DF4
	bl RtcGetLocalDayCount
	adds r4, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xA
	bl ReadUnalignedWord
	adds r6, r0, 0
	ldr r0, =0x0000ffff
	ands r6, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e6a
	adds r0, r1
	ldrh r5, [r0]
	bl sub_8196748
	mov r9, r0
	movs r0, 0xD
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xA
	bl __divsi3
	mov r8, r0
	movs r0, 0x9
	bl GetGameStat
	eors r4, r5
	eors r5, r0
	adds r4, r5
	eors r4, r6
	adds r0, r4, 0
	mov r1, r8
	bl __modsi3
	cmp r0, r9
	bge _08196DF4
	bl sub_8196774
	cmp r0, r7
	bne _08196DF4
	movs r0, 0x1
	b _08196DF6
	.pool
_08196DF4:
	movs r0, 0
_08196DF6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8196D74

	thumb_func_start sub_8196E04
sub_8196E04: @ 8196E04
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 16
	lsrs r0, 16
	movs r4, 0
	cmp r0, 0x6
	bls _08196E14
	b _08196F7E
_08196E14:
	lsls r0, 2
	ldr r1, =_08196E24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08196E24:
	.4byte _08196E9C
	.4byte _08196E40
	.4byte _08196ED0
	.4byte _08196F38
	.4byte _08196E74
	.4byte _08196F04
	.4byte _08196F60
_08196E40:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000d14
	adds r0, r1
_08196E4A:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196E52:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196E5A
	ldrh r4, [r1]
_08196E5A:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196E52
	cmp r3, 0x1
	ble _08196E4A
	movs r0, 0x3
	b _08196F7C
	.pool
_08196E74:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e08
	adds r0, r1
	movs r3, 0x1
_08196E7E:
	ldrh r6, [r0]
	cmp r4, r6
	bcs _08196E86
	ldrh r4, [r0]
_08196E86:
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08196E7E
	movs r0, 0x4
	b _08196F7C
	.pool
_08196E9C:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xCF
	lsls r1, 4
	adds r0, r1
_08196EA8:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196EB0:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196EB8
	ldrh r4, [r1]
_08196EB8:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196EB0
	movs r2, 0x2
	cmp r3, 0x3
	ble _08196EA8
	str r2, [r5]
	b _08196F7E
	.pool
_08196ED0:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xDD
	lsls r1, 4
	adds r0, r1
_08196EDC:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196EE4:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196EEC
	ldrh r4, [r1]
_08196EEC:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196EE4
	movs r2, 0x2
	cmp r3, 0x1
	ble _08196EDC
	str r2, [r5]
	b _08196F7E
	.pool
_08196F04:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dea
	adds r0, r1
_08196F0E:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196F16:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196F1E
	ldrh r4, [r1]
_08196F1E:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196F16
	movs r2, 0x2
	cmp r3, 0x1
	ble _08196F0E
	str r2, [r5]
	b _08196F7E
	.pool
_08196F38:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dde
	adds r0, r1
	movs r3, 0x1
_08196F42:
	ldrh r6, [r0]
	cmp r4, r6
	bcs _08196F4A
	ldrh r4, [r0]
_08196F4A:
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08196F42
	movs r3, 0x2
	str r3, [r5]
	b _08196F7E
	.pool
_08196F60:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e1e
	adds r0, r1
	movs r3, 0x1
_08196F6A:
	ldrh r6, [r0]
	cmp r4, r6
	bcs _08196F72
	ldrh r4, [r0]
_08196F72:
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08196F6A
	movs r0, 0x5
_08196F7C:
	str r0, [r5]
_08196F7E:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196E04

	thumb_func_start sub_8196F90
sub_8196F90: @ 8196F90
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9
	bhi _08196F9E
	movs r0, 0
	b _0819707A
_08196F9E:
	cmp r4, 0x13
	bhi _08196FA6
	movs r0, 0x1
	b _0819707A
_08196FA6:
	cmp r4, 0x1D
	bhi _08196FAE
	movs r0, 0x2
	b _0819707A
_08196FAE:
	cmp r4, 0x27
	bhi _08196FB6
	movs r0, 0x3
	b _0819707A
_08196FB6:
	cmp r4, 0x31
	bhi _08196FBE
	movs r0, 0x4
	b _0819707A
_08196FBE:
	cmp r4, 0x3B
	bhi _08196FC6
	movs r0, 0x5
	b _0819707A
_08196FC6:
	cmp r4, 0x45
	bhi _08196FCE
	movs r0, 0x6
	b _0819707A
_08196FCE:
	cmp r4, 0x4F
	bhi _08196FD6
	movs r0, 0x7
	b _0819707A
_08196FD6:
	cmp r4, 0x59
	bhi _08196FDE
	movs r0, 0x8
	b _0819707A
_08196FDE:
	cmp r4, 0x63
	bhi _08196FE6
	movs r0, 0x9
	b _0819707A
_08196FE6:
	cmp r4, 0x6D
	bhi _08196FEE
	movs r0, 0xA
	b _0819707A
_08196FEE:
	cmp r4, 0x77
	bhi _08196FF6
	movs r0, 0xB
	b _0819707A
_08196FF6:
	cmp r4, 0x81
	bhi _08196FFE
	movs r0, 0xC
	b _0819707A
_08196FFE:
	cmp r4, 0x8B
	bhi _08197006
	movs r0, 0xD
	b _0819707A
_08197006:
	cmp r4, 0x95
	bhi _0819700E
	movs r0, 0xE
	b _0819707A
_0819700E:
	cmp r4, 0x9F
	bhi _08197016
	movs r0, 0xF
	b _0819707A
_08197016:
	cmp r4, 0xA9
	bhi _0819701E
	movs r0, 0x10
	b _0819707A
_0819701E:
	cmp r4, 0xB3
	bhi _08197026
	movs r0, 0x11
	b _0819707A
_08197026:
	cmp r4, 0xBD
	bhi _0819702E
	movs r0, 0x12
	b _0819707A
_0819702E:
	cmp r4, 0xC7
	bls _08197078
	movs r0, 0xCD
	lsls r0, 1
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _08197050
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08197050:
	ldr r0, =0x00000199
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _0819706C
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_0819706C:
	cmp r4, 0xC7
	bls _08197078
	movs r0, 0x14
	b _0819707A
	.pool
_08197078:
	movs r0, 0x13
_0819707A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8196F90

	thumb_func_start sub_8197080
sub_8197080: @ 8197080
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	movs r0, 0xFA
	lsls r0, 2
	bl Alloc
	adds r7, r0, 0
	cmp r7, 0
	bne _081970A2
	movs r0, 0xFF
	mov r1, r8
	strb r0, [r1]
	b _0819715C
_081970A2:
	movs r0, 0
	bl GetHoennPokedexCount
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	bl GetHoennPokedexCount
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gStringVar1
	mov r10, r0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar2
	mov r9, r1
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	bl sub_8196F90
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gUnknown_082A5C9C
	adds r0, r7, 0
	bl StringCopy
	adds r5, r0, 0
	movs r6, 0xFB
	strb r6, [r5]
	adds r5, 0x1
	ldr r1, =gUnknown_082A5D2C
	adds r0, r5, 0
	bl StringCopy
	adds r5, r0, 0
	strb r6, [r5]
	adds r5, 0x1
	ldr r0, =gUnknown_0860F020
	lsls r4, 2
	adds r4, r0
	ldr r1, [r4]
	adds r0, r5, 0
	bl StringCopy
	mov r0, r8
	adds r1, r7, 0
	bl StringExpandPlaceholders
	adds r5, r0, 0
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _08197156
	strb r6, [r5]
	adds r5, 0x1
	movs r0, 0
	bl GetNationalPokedexCount
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	bl GetNationalPokedexCount
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_082A633D
	adds r0, r5, 0
	bl StringExpandPlaceholders
_08197156:
	adds r0, r7, 0
	bl Free
_0819715C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool

	thumb_func_end sub_8197080
	thumb_func_start sub_8197184
sub_8197184: @ 8197184
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0860EA6C
	movs r2, 0x80
	lsls r2, 1
	lsls r4, 16
	lsrs r4, 16
	adds r3, r4, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_0860EA4C
	lsls r5, 20
	lsrs r5, 16
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197184

	thumb_func_start sub_81971C4
sub_81971C4: @ 81971C4
	push {lr}
	bl sub_819645C
	pop {r0}
	bx r0
	thumb_func_end sub_81971C4

	.align 2, 0 @ Don't pad with nop.
