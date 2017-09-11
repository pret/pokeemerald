	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_806ECAC
sub_806ECAC: @ 806ECAC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0xE]
	subs r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _0806ECE2
	ldrh r0, [r2, 0x8]
	ldrh r1, [r2, 0xA]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0xC]
	bl sub_817F578
	movs r0, 0xFF
	bl sub_81C488C
	adds r0, r4, 0
	bl DestroyTask
_0806ECE2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806ECAC

	thumb_func_start sub_806ECEC
sub_806ECEC: @ 806ECEC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806ED30
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _0806ED30
	movs r0, 0x80
	orrs r3, r0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806ED40
	b _0806ED38
	.pool
_0806ED30:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806ED40
_0806ED38:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806ECEC

	thumb_func_start sub_806ED40
sub_806ED40: @ 806ED40
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x7F
	ands r0, r3
	cmp r0, 0
	beq _0806ED60
	cmp r0, 0x1
	beq _0806ED64
	movs r1, 0
	b _0806ED66
_0806ED60:
	movs r1, 0xE7
	b _0806ED66
_0806ED64:
	movs r1, 0x19
_0806ED66:
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _0806ED84
	cmp r2, 0
	bne _0806ED7C
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl PlayCry1
_0806ED7C:
	ldr r0, =SpriteCallbackDummy
	b _0806EDFA
	.pool
_0806ED84:
	cmp r2, 0
	bne _0806EDA6
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl PlayCry1
	adds r0, r4, 0
	bl sub_806F0D4
	lsls r0, 24
	cmp r0, 0
	beq _0806EDA6
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0806EDA6:
	ldr r0, =gUnknown_08329B87
	subs r4, 0x1
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, 0
	beq _0806EDEC
	ldr r0, =sub_806EC70
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	lsrs r0, r5, 16
	strh r0, [r1, 0xA]
	ldr r0, =gUnknown_083299EC
	adds r0, r4, r0
	ldrb r0, [r0]
	strh r0, [r1, 0xC]
	ldrb r0, [r6]
	strh r0, [r1, 0xE]
	b _0806EDF8
	.pool
_0806EDEC:
	ldr r0, =gUnknown_083299EC
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_817F544
_0806EDF8:
	ldr r0, =nullsub_18
_0806EDFA:
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806ED40

	thumb_func_start sub_806EE0C
sub_806EE0C: @ 806EE0C
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	cmp r2, 0
	bne _0806EE2E
	adds r0, r4, 0
	bl sub_806F0D4
	lsls r0, 24
	cmp r0, 0
	beq _0806EE2E
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0806EE2E:
	ldr r0, =gUnknown_08329B87
	subs r4, 0x1
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, 0
	beq _0806EE80
	ldr r0, =sub_806ECAC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	strh r5, [r2, 0x8]
	lsrs r1, r5, 16
	strh r1, [r2, 0xA]
	ldr r1, =gUnknown_083299EC
	adds r1, r4, r1
	ldrb r1, [r1]
	strh r1, [r2, 0xC]
	ldrb r1, [r6]
	strh r1, [r2, 0xE]
	bl sub_81C488C
	adds r0, r5, 0
	bl sub_817F60C
	b _0806EE8C
	.pool
_0806EE80:
	ldr r0, =gUnknown_083299EC
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_817F578
_0806EE8C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EE0C

	thumb_func_start sub_806EE98
sub_806EE98: @ 806EE98
	push {lr}
	ldr r0, =sub_806ECAC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0806EEAC
	bl DestroyTask
_0806EEAC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EE98

	thumb_func_start sub_806EEB4
sub_806EEB4: @ 806EEB4
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806EEE8
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _0806EEE8
	ldr r0, =SpriteCallbackDummy
	b _0806EEFC
	.pool
_0806EEE8:
	adds r0, r2, 0
	bl sub_817F474
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_817F594
	ldr r0, =nullsub_18
_0806EEFC:
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EEB4

	thumb_func_start sub_806EF08
sub_806EF08: @ 806EF08
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x18]
	cmp r0, 0x1
	beq _0806EF4C
	cmp r0, 0x1
	bgt _0806EF38
	cmp r0, 0
	beq _0806EF42
	b _0806EF56
	.pool
_0806EF38:
	cmp r0, 0x2
	beq _0806EF42
	cmp r0, 0x3
	beq _0806EF4C
	b _0806EF56
_0806EF42:
	movs r5, 0x3
	cmp r4, 0
	beq _0806EF56
	movs r5, 0x1
	b _0806EF56
_0806EF4C:
	negs r0, r4
	orrs r0, r4
	asrs r5, r0, 31
	movs r0, 0x2
	ands r5, r0
_0806EF56:
	movs r2, 0
	ldr r4, =gLinkPlayers
	ldrh r0, [r4, 0x18]
	adds r1, r5, 0
	cmp r0, r1
	beq _0806EF74
	adds r3, r1, 0
	adds r1, r4, 0
_0806EF66:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0806EF74
	ldrh r0, [r1, 0x18]
	cmp r0, r3
	bne _0806EF66
_0806EF74:
	lsls r0, r2, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806EF08

	thumb_func_start sub_806EF84
sub_806EF84: @ 806EF84
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r4, 0
	ldr r2, =gLinkPlayers
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x1
	beq _0806EFC4
	cmp r0, 0x1
	bgt _0806EFB0
	cmp r0, 0
	beq _0806EFBA
	b _0806EFCE
	.pool
_0806EFB0:
	cmp r0, 0x2
	beq _0806EFBA
	cmp r0, 0x3
	beq _0806EFC4
	b _0806EFCE
_0806EFBA:
	movs r4, 0x3
	cmp r3, 0
	beq _0806EFCE
	movs r4, 0x1
	b _0806EFCE
_0806EFC4:
	negs r0, r3
	orrs r0, r3
	asrs r4, r0, 31
	movs r0, 0x2
	ands r4, r0
_0806EFCE:
	movs r3, 0
	ldrh r0, [r2, 0x18]
	adds r1, r4, 0
	cmp r0, r1
	beq _0806EFE6
_0806EFD8:
	adds r2, 0x1C
	adds r3, 0x1
	cmp r3, 0x3
	bgt _0806EFE6
	ldrh r0, [r2, 0x18]
	cmp r0, r1
	bne _0806EFD8
_0806EFE6:
	lsls r0, r3, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_806EF84

	thumb_func_start TrainerClassToTrainerPic
@ u8 TrainerClassToTrainerPic(u16 trainerClassId)
TrainerClassToTrainerPic: @ 806EFF0
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gTrainerClassToPicIndex
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end TrainerClassToTrainerPic

	thumb_func_start sub_806F000
sub_806F000: @ 806F000
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0806F00C
	movs r0, 0x3C
	b _0806F00E
_0806F00C:
	movs r0, 0x3F
_0806F00E:
	bl TrainerClassToTrainerPic
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_806F000

	thumb_func_start SetPokedexFlag
@ void SetPokedexFlag(u16 nationalPokedexNum, u8 op, u32 personality)
SetPokedexFlag: @ 806F01C
	push {r4-r7,lr}
	adds r7, r2, 0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r0, 0x2
	eors r0, r5
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	adds r0, r4, 0
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	bne _0806F072
	adds r0, r4, 0
	adds r1, r5, 0
	bl pokedex_flag_operation
	adds r0, r4, 0
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC9
	bne _0806F05C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	str r7, [r0, 0x1C]
_0806F05C:
	adds r0, r6, 0
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	movs r1, 0x9A
	lsls r1, 17
	cmp r0, r1
	bne _0806F072
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	str r7, [r0, 0x20]
_0806F072:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetPokedexFlag

	thumb_func_start sub_806F07C
sub_806F07C: @ 806F07C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x00000356
	cmp r2, r0
	bls _0806F08A
	movs r2, 0
_0806F08A:
	ldr r1, =gTrainers
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	muls r0, r1
	ldr r1, =gTrainerClassNames
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F07C

	thumb_func_start sub_806F0B0
sub_806F0B0: @ 806F0B0
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x00000356
	cmp r1, r0
	bls _0806F0BE
	movs r1, 0
_0806F0BE:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTrainers + 0x4 @ name offset
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F0B0

	thumb_func_start sub_806F0D4
sub_806F0D4: @ 806F0D4
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r0, =0x00000181
	cmp r2, r0
	beq _0806F0F8
	adds r0, 0x19
	cmp r2, r0
	beq _0806F0F8
	subs r0, 0x66
	cmp r2, r0
	beq _0806F0F8
	movs r1, 0xC9
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
_0806F0F8:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F0D4

	thumb_func_start sub_806F104
sub_806F104: @ 806F104
	push {lr}
	ldr r2, =gMain
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806F122
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x003f0100
	ands r0, r1
	cmp r0, 0
	bne _0806F144
_0806F122:
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806F158
	bl InBattlePike
	lsls r0, 24
	cmp r0, 0
	bne _0806F144
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0806F158
_0806F144:
	movs r0, 0x1
	b _0806F15A
	.pool
_0806F158:
	movs r0, 0
_0806F15A:
	pop {r1}
	bx r1
	thumb_func_end sub_806F104

	thumb_func_start sub_806F160
sub_806F160: @ 806F160
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	ldrb r0, [r6]
	lsls r0, 28
	movs r4, 0
	cmp r0, 0
	beq _0806F1EA
_0806F176:
	ldr r0, [r6, 0xC]
	lsls r2, r4, 1
	adds r1, r2, r4
	lsls r1, 3
	adds r0, r1, r0
	ldr r3, =gUnknown_08329D98
	adds r1, r3
	ldm r1!, {r3,r5,r7}
	stm r0!, {r3,r5,r7}
	ldm r1!, {r3,r5,r7}
	stm r0!, {r3,r5,r7}
	movs r5, 0
	ldrb r3, [r6, 0x1]
	ldr r7, [r6, 0xC]
	mov r9, r7
	mov r8, r2
	ldr r0, [r6, 0x10]
	mov r12, r0
	adds r1, r4, 0x1
	mov r10, r1
	cmp r5, r3
	bcs _0806F1C8
	mov r7, r12
	ldr r1, [r6, 0x8]
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
_0806F1AC:
	adds r0, r4, 0
	muls r0, r3
	adds r0, r5
	lsls r0, 3
	adds r0, r7
	lsls r1, r5, 11
	adds r1, r2, r1
	str r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r3, [r6, 0x1]
	cmp r5, r3
	bcc _0806F1AC
_0806F1C8:
	mov r3, r8
	adds r1, r3, r4
	lsls r1, 3
	add r1, r9
	ldrb r0, [r6, 0x1]
	muls r0, r4
	lsls r0, 3
	add r0, r12
	str r0, [r1, 0xC]
	mov r5, r10
	lsls r0, r5, 16
	lsrs r4, r0, 16
	ldrb r0, [r6]
	lsls r0, 28
	lsrs r0, 28
	cmp r4, r0
	blt _0806F176
_0806F1EA:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806F160

	thumb_func_start sub_806F1FC
sub_806F1FC: @ 806F1FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	ldrb r0, [r4]
	lsls r0, 28
	movs r3, 0
	cmp r0, 0
	beq _0806F296
	ldr r0, =gUnknown_08329F28
	mov r10, r0
_0806F216:
	ldr r0, [r4, 0xC]
	lsls r2, r3, 1
	adds r1, r2, r3
	lsls r1, 3
	adds r1, r0
	mov r0, r10
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	movs r5, 0
	ldr r0, [r4, 0xC]
	mov r8, r0
	mov r12, r2
	ldr r7, [r4, 0x10]
	adds r1, r3, 0x1
	mov r9, r1
	ldrb r6, [r4, 0x1]
	cmp r5, r6
	bcs _0806F26A
	adds r6, r7, 0
	ldr r1, [r4, 0x8]
	lsls r0, r3, 2
	adds r0, r1
	ldr r2, [r0]
_0806F248:
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	adds r1, r3, 0
	muls r1, r0
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	lsls r0, r5, 11
	adds r0, r2, r0
	str r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r0, [r4, 0x1]
	cmp r5, r0
	bcc _0806F248
_0806F26A:
	mov r5, r12
	adds r1, r5, r3
	lsls r1, 3
	add r1, r8
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	muls r0, r3
	lsls r0, 3
	adds r0, r7, r0
	str r0, [r1, 0xC]
	ldr r6, =gUnknown_082FF70C
	str r6, [r1, 0x8]
	strh r3, [r1, 0x2]
	mov r7, r9
	lsls r0, r7, 16
	lsrs r3, r0, 16
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F216
_0806F296:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806F1FC

	thumb_func_start sub_806F2AC
sub_806F2AC: @ 806F2AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r7, 0
	movs r0, 0x1
	ands r6, r0
	movs r0, 0x14
	bl AllocZeroed
	adds r4, r0, 0
	cmp r4, 0
	bne _0806F2D0
	movs r0, 0
	b _0806F46E
_0806F2D0:
	cmp r5, 0
	beq _0806F2E6
	cmp r5, 0x2
	bne _0806F2E6
	movs r0, 0x77
	strb r0, [r4]
	movs r0, 0x4
	strb r0, [r4, 0x1]
	movs r0, 0x21
	strb r0, [r4, 0x3]
	b _0806F30E
_0806F2E6:
	ldrb r1, [r4]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r3, 0xF
	ands r0, r3
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x4
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	ands r2, r3
	strb r2, [r4, 0x3]
_0806F30E:
	ldrb r1, [r4, 0x3]
	lsls r1, 28
	lsrs r1, 28
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 15
	muls r0, r1
	bl AllocZeroed
	str r0, [r4, 0x4]
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 23
	bl AllocZeroed
	adds r1, r0, 0
	str r1, [r4, 0x8]
	ldr r2, [r4, 0x4]
	cmp r2, 0
	beq _0806F33A
	cmp r1, 0
	bne _0806F344
_0806F33A:
	movs r0, 0x1
	orrs r7, r0
	lsls r6, 2
	mov r8, r6
	b _0806F378
_0806F344:
	ldrb r0, [r4]
	lsls r0, 28
	movs r3, 0
	lsls r6, 2
	mov r8, r6
	cmp r0, 0
	beq _0806F378
	adds r6, r1, 0
	adds r5, r2, 0
_0806F356:
	lsls r2, r3, 2
	adds r2, r6
	ldrb r0, [r4, 0x3]
	lsls r0, 28
	lsrs r0, 28
	lsls r1, r3, 13
	muls r0, r1
	adds r0, r5, r0
	str r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F356
_0806F378:
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4, 0xC]
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	ldrb r0, [r4, 0x1]
	lsls r0, 3
	muls r0, r1
	bl AllocZeroed
	adds r1, r0, 0
	str r1, [r4, 0x10]
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F3A8
	cmp r1, 0
	bne _0806F3B2
_0806F3A8:
	movs r0, 0x2
	orrs r7, r0
	lsls r0, r7, 24
	lsrs r7, r0, 24
	b _0806F400
_0806F3B2:
	movs r3, 0
	ldrb r0, [r4, 0x1]
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	muls r0, r1
	cmp r3, r0
	bge _0806F3E2
	movs r2, 0x80
	lsls r2, 4
_0806F3C6:
	ldr r1, [r4, 0x10]
	lsls r0, r3, 3
	adds r0, r1
	strh r2, [r0, 0x4]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r4, 0x1]
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	muls r0, r1
	cmp r3, r0
	blt _0806F3C6
_0806F3E2:
	ldrb r0, [r4, 0x3]
	lsrs r0, 4
	cmp r0, 0
	blt _0806F3FA
	cmp r0, 0x1
	ble _0806F3FA
	cmp r0, 0x2
	bne _0806F3FA
	adds r0, r4, 0
	bl sub_806F1FC
	b _0806F400
_0806F3FA:
	adds r0, r4, 0
	bl sub_806F160
_0806F400:
	movs r0, 0x2
	ands r0, r7
	cmp r0, 0
	beq _0806F424
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806F416
	bl Free
	movs r0, 0
	str r0, [r4, 0x10]
_0806F416:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F424
	bl Free
	movs r0, 0
	str r0, [r4, 0xC]
_0806F424:
	movs r0, 0x1
	ands r0, r7
	cmp r0, 0
	beq _0806F448
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F43A
	bl Free
	movs r0, 0
	str r0, [r4, 0x8]
_0806F43A:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0806F448
	bl Free
	movs r0, 0
	str r0, [r4, 0x4]
_0806F448:
	cmp r7, 0
	beq _0806F45E
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	adds r0, r4, 0
	bl Free
	b _0806F468
_0806F45E:
	movs r0, 0xA3
	strb r0, [r4, 0x2]
	ldr r0, =gUnknown_020249B4
	add r0, r8
	str r4, [r0]
_0806F468:
	ldr r0, =gUnknown_020249B4
	add r0, r8
	ldr r0, [r0]
_0806F46E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F2AC

	thumb_func_start sub_806F47C
sub_806F47C: @ 806F47C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_020249B4
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _0806F4F0
	ldrb r0, [r4, 0x2]
	cmp r0, 0xA3
	beq _0806F4A8
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	b _0806F4F0
	.pool
_0806F4A8:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806F4B6
	bl Free
	movs r0, 0
	str r0, [r4, 0x10]
_0806F4B6:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F4C4
	bl Free
	movs r0, 0
	str r0, [r4, 0xC]
_0806F4C4:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F4D2
	bl Free
	movs r0, 0
	str r0, [r4, 0x8]
_0806F4D2:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0806F4E0
	bl Free
	movs r0, 0
	str r0, [r4, 0x4]
_0806F4E0:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	adds r0, r4, 0
	bl Free
_0806F4F0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806F47C

	thumb_func_start sub_806F4F8
sub_806F4F8: @ 806F4F8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r2, =gUnknown_020249B4
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	cmp r0, 0xA3
	beq _0806F51C
	movs r0, 0
	b _0806F530
	.pool
_0806F51C:
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F528
	movs r3, 0
_0806F528:
	ldr r0, [r1, 0x8]
	lsls r1, r3, 2
	adds r1, r0
	ldr r0, [r1]
_0806F530:
	pop {r1}
	bx r1
	thumb_func_end sub_806F4F8

	.align 2, 0 @ Don't pad with nop.
