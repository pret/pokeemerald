	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start SetUpFieldMove_Flash
SetUpFieldMove_Flash: @ 81370FC
	push {r4,lr}
	bl ShouldDoBrailleFlyEffect
	lsls r0, 24
	cmp r0, 0
	beq _08137134
	ldr r4, =gSpecialVar_Result
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_8179918
	b _08137152
	.pool
_08137134:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x15]
	cmp r0, 0x1
	bne _08137170
	ldr r0, =0x00000888
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08137170
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_flash
_08137152:
	str r0, [r1]
	movs r0, 0x1
	b _08137172
	.pool
_08137170:
	movs r0, 0
_08137172:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end SetUpFieldMove_Flash

	thumb_func_start hm2_flash
hm2_flash: @ 8137178
	push {r4,lr}
	bl oei_task_add
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl GetCursorSelectionMonId
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =sub_81371B4
	lsrs r1, r2, 16
	strh r1, [r0, 0x18]
	strh r2, [r0, 0x1A]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_flash

	thumb_func_start sub_81371B4
sub_81371B4: @ 81371B4
	push {lr}
	movs r0, 0xCF
	bl PlaySE
	ldr r0, =0x00000888
	bl FlagSet
	ldr r0, =EventScript_2926F8
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81371B4

	thumb_func_start sub_81371D4
sub_81371D4: @ 81371D4
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81371D4

	thumb_func_start sub_81371EC
sub_81371EC: @ 81371EC
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81371EC

	thumb_func_start c2_change_map
c2_change_map: @ 8137200
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r4, 0
	str r4, [sp, 0x4]
	add r0, sp, 0x4
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, sp
	strh r4, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl ResetPaletteFade
	bl ResetTasks
	bl ResetSpriteData
	ldr r3, =0x04000208
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, =0x04000200
	ldrh r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	ldr r0, =sub_81371EC
	bl SetVBlankCallback
	ldr r0, =sub_81371D4
	bl SetMainCallback2
	bl sub_8137304
	lsls r0, 24
	cmp r0, 0
	bne _081372D2
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_081372D2:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_change_map

	thumb_func_start sub_8137304
sub_8137304: @ 8137304
	push {r4-r7,lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r6, r0, 24
	bl sav1_map_get_light_level
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r4, =gUnknown_085B27C8
	ldrb r0, [r4]
	cmp r0, 0
	beq _08137358
	adds r7, r4, 0
	adds r0, r4, 0x4
	mov r12, r0
_08137326:
	lsls r2, r3, 3
	adds r1, r2, r7
	ldrb r0, [r1]
	cmp r0, r6
	bne _08137348
	ldrb r0, [r1, 0x1]
	cmp r0, r5
	bne _08137348
	mov r1, r12
	adds r0, r2, r1
	ldr r0, [r0]
	bl _call_via_r0
	movs r0, 0x1
	b _0813735A
	.pool
_08137348:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08137326
_08137358:
	movs r0, 0
_0813735A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8137304

	thumb_func_start sub_8137360
sub_8137360: @ 8137360
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r5, r0, 24
	lsrs r4, r1, 24
	movs r3, 0
	ldr r1, =gUnknown_085B27C8
	ldrb r0, [r1]
	cmp r0, 0
	beq _081373A0
	adds r6, r1, 0
_08137376:
	lsls r0, r3, 3
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, r5
	bne _08137390
	ldrb r0, [r2, 0x1]
	cmp r0, r4
	bne _08137390
	ldrb r0, [r2, 0x2]
	b _081373A2
	.pool
_08137390:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08137376
_081373A0:
	movs r0, 0
_081373A2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8137360

	thumb_func_start fade_type_for_given_maplight_pair
fade_type_for_given_maplight_pair: @ 81373A8
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r5, r0, 24
	lsrs r4, r1, 24
	movs r3, 0
	ldr r1, =gUnknown_085B27C8
	ldrb r0, [r1]
	cmp r0, 0
	beq _081373E8
	adds r6, r1, 0
_081373BE:
	lsls r0, r3, 3
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, r5
	bne _081373D8
	ldrb r0, [r2, 0x1]
	cmp r0, r4
	bne _081373D8
	ldrb r0, [r2, 0x3]
	b _081373EA
	.pool
_081373D8:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081373BE
_081373E8:
	movs r0, 0
_081373EA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end fade_type_for_given_maplight_pair

	thumb_func_start sub_81373F0
sub_81373F0: @ 81373F0
	push {lr}
	ldr r0, =sub_8137404
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81373F0

	thumb_func_start sub_8137404
sub_8137404: @ 8137404
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_8137420
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8137404

	thumb_func_start sub_8137420
sub_8137420: @ 8137420
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gCaveTransitionTiles
	ldr r1, =0x0600c000
	bl LZ77UnCompVram
	ldr r0, =gCaveTransitionTilemap
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	ldr r0, =gCaveTransitionPalette_White
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085B28A0
	movs r1, 0xE0
	movs r2, 0x10
	bl LoadPalette
	ldr r1, =0x00003e41
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001f0c
	movs r0, 0x8
	bl SetGpuReg
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81374C4
	str r1, [r0]
	movs r2, 0
	movs r1, 0x10
	strh r1, [r0, 0x8]
	strh r2, [r0, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137420

	thumb_func_start sub_81374C4
sub_81374C4: @ 81374C4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrh r4, [r5, 0xA]
	movs r0, 0x80
	lsls r0, 5
	adds r1, r4, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	cmp r4, 0x10
	bhi _081374F8
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	b _08137500
	.pool
_081374F8:
	movs r0, 0
	strh r0, [r5, 0xC]
	ldr r0, =sub_813750C
	str r0, [r5]
_08137500:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81374C4

	thumb_func_start sub_813750C
sub_813750C: @ 813750C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =0x00001010
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0xC]
	cmp r1, 0x7
	bhi _08137554
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	lsls r1, 1
	ldr r0, =gUnknown_085B28A0
	adds r0, r1, r0
	movs r2, 0x10
	subs r2, r1
	lsls r2, 16
	lsrs r2, 16
	movs r1, 0xE0
	bl LoadPalette
	b _08137566
	.pool
_08137554:
	ldr r0, =gCaveTransitionPalette_White
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =sub_8137574
	str r0, [r4]
	movs r0, 0x8
	strh r0, [r4, 0xC]
_08137566:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813750C

	thumb_func_start sub_8137574
sub_8137574: @ 8137574
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08137598
	subs r0, r2, 0x1
	strh r0, [r1, 0xC]
	b _081375A0
	.pool
_08137598:
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_081375A0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137574

	thumb_func_start sub_81375A8
sub_81375A8: @ 81375A8
	push {lr}
	ldr r0, =sub_81375BC
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81375A8

	thumb_func_start sub_81375BC
sub_81375BC: @ 81375BC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_81375D8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81375BC

	thumb_func_start sub_81375D8
sub_81375D8: @ 81375D8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gCaveTransitionTiles
	ldr r1, =0x0600c000
	bl LZ77UnCompVram
	ldr r0, =gCaveTransitionTilemap
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001f0c
	movs r0, 0x8
	bl SetGpuReg
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gCaveTransitionPalette_White
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gCaveTransitionPalette_Black
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8137678
	str r1, [r0]
	movs r2, 0
	movs r1, 0x10
	strh r1, [r0, 0x8]
	strh r2, [r0, 0xA]
	strh r2, [r0, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81375D8

	thumb_func_start sub_8137678
sub_8137678: @ 8137678
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0xC]
	cmp r1, 0xF
	bhi _081376B4
	adds r2, r1, 0x1
	adds r0, r2, 0x1
	strh r0, [r4, 0xC]
	movs r0, 0xF
	subs r0, r1
	lsls r0, 1
	ldr r1, =gUnknown_085B2890
	adds r0, r1
	lsls r2, 17
	lsrs r2, 16
	movs r1, 0xE0
	bl LoadPalette
	b _081376C8
	.pool
_081376B4:
	ldr r1, =0x00001010
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =0x00003e41
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =sub_81376DC
	str r0, [r4]
_081376C8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137678

	thumb_func_start sub_81376DC
sub_81376DC: @ 81376DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrh r0, [r5, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 16
	lsrs r4, r1, 16
	movs r0, 0x80
	lsls r0, 21
	adds r1, r0
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	cmp r4, 0
	beq _08137714
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	b _08137726
	.pool
_08137714:
	ldr r0, =gCaveTransitionPalette_Black
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_08137726:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81376DC
