	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetSafariZoneFlag
GetSafariZoneFlag: @ 80FC0A0
	push {lr}
	ldr r0, =0x0000088c
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSafariZoneFlag

	thumb_func_start SetSafariZoneFlag
SetSafariZoneFlag: @ 80FC0B4
	push {lr}
	ldr r0, =0x0000088c
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetSafariZoneFlag

	thumb_func_start ResetSafariZoneFlag
ResetSafariZoneFlag: @ 80FC0C4
	push {lr}
	ldr r0, =0x0000088c
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetSafariZoneFlag

	thumb_func_start sub_80FC0D4
sub_80FC0D4: @ 80FC0D4
	push {lr}
	movs r0, 0x11
	bl IncrementGameStat
	bl SetSafariZoneFlag
	bl sub_80FC244
	ldr r1, =gUnknown_0203A04C
	movs r0, 0x1E
	strb r0, [r1]
	ldr r1, =gUnknown_0203A04E
	movs r2, 0xFA
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gUnknown_0203A050
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_0203A051
	strb r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC0D4

	thumb_func_start sub_80FC114
sub_80FC114: @ 80FC114
	push {lr}
	ldr r0, =gUnknown_0203A050
	ldrb r0, [r0]
	ldr r1, =gUnknown_0203A051
	ldrb r1, [r1]
	bl sub_80EE44C
	bl ResetSafariZoneFlag
	bl sub_80FC244
	ldr r1, =gUnknown_0203A04C
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_0203A04E
	movs r0, 0
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC114

	thumb_func_start safari_step
safari_step: @ 80FC14C
	push {lr}
	bl GetSafariZoneFlag
	cmp r0, 0
	beq _080FC168
	bl sub_80FC480
	ldr r1, =gUnknown_0203A04E
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _080FC170
_080FC168:
	movs r0, 0
	b _080FC178
	.pool
_080FC170:
	ldr r0, =gUnknown_082A4B8A
	bl script_env_1_execute_new_script
	movs r0, 0x1
_080FC178:
	pop {r1}
	bx r1
	.pool
	thumb_func_end safari_step

	thumb_func_start sub_80FC180
sub_80FC180: @ 80FC180
	push {lr}
	ldr r0, =gUnknown_082A4B6F
	bl script_env_1_execute_new_script
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC180

	thumb_func_start sub_80FC190
sub_80FC190: @ 80FC190
	push {lr}
	ldr r1, =gUnknown_0203A051
	ldr r0, =gUnknown_03005D10
	ldrb r0, [r0, 0x1F]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
	ldr r2, =gBattleOutcome
	ldrb r0, [r2]
	cmp r0, 0x7
	bne _080FC1AE
	ldr r1, =gUnknown_0203A050
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080FC1AE:
	ldr r0, =gUnknown_0203A04C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080FC1D8
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	b _080FC21C
	.pool
_080FC1D8:
	ldrb r0, [r2]
	cmp r0, 0x8
	bne _080FC208
	ldr r0, =gUnknown_082A4B4C
	bl script_env_2_execute_new_script
	bl warp_in
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF6F0
	str r0, [r1]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	b _080FC21C
	.pool
_080FC208:
	cmp r0, 0x7
	bne _080FC21C
	ldr r0, =gUnknown_082A4B9B
	bl script_env_1_execute_new_script
	bl script_env_2_set_ctx_paused
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
_080FC21C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC190

	thumb_func_start sub_80FC228
sub_80FC228: @ 80FC228
	push {lr}
	lsls r0, 24
	lsrs r0, 20
	ldr r1, =gUnknown_0203A054
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC228

	thumb_func_start sub_80FC244
sub_80FC244: @ 80FC244
	push {lr}
	ldr r0, =gUnknown_0203A054
	movs r1, 0
	movs r2, 0xA0
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC244

	thumb_func_start sub_80FC258
sub_80FC258: @ 80FC258
	push {r4,r5,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	movs r5, 0
_080FC26A:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_0203A054
	lsls r0, r5, 4
	adds r3, r0, r1
	movs r1, 0x5
	ldrsb r1, [r2, r1]
	movs r0, 0x4
	ldrsb r0, [r3, r0]
	cmp r1, r0
	bne _080FC2C4
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r3, r2]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _080FC2C4
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _080FC2C4
	ldr r0, =gScriptResult
	strh r5, [r0]
	ldr r1, =gUnknown_085B262C
	ldrb r0, [r3, 0x8]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =gStringVar1
	bl StringCopy
	b _080FC2D6
	.pool
_080FC2C4:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _080FC26A
	ldr r1, =gScriptResult
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_080FC2D6:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC258

	thumb_func_start sub_80FC2E8
sub_80FC2E8: @ 80FC2E8
	push {r4-r7,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	movs r5, 0
	adds r6, r4, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r7, [r0]
	mov r4, sp
	ldr r0, =gUnknown_0203A054
	mov r12, r0
_080FC306:
	lsls r0, r5, 4
	mov r1, r12
	adds r3, r0, r1
	movs r1, 0x5
	ldrsb r1, [r7, r1]
	movs r0, 0x4
	ldrsb r0, [r3, r0]
	cmp r1, r0
	bne _080FC364
	ldrh r0, [r4]
	ldrh r1, [r3]
	subs r0, r1
	strh r0, [r4]
	adds r2, r6, 0
	ldrh r0, [r2]
	ldrh r1, [r3, 0x2]
	subs r0, r1
	strh r0, [r2]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _080FC336
	negs r0, r0
	strh r0, [r4]
_080FC336:
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bge _080FC342
	negs r0, r0
	strh r0, [r2]
_080FC342:
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r2, 0
	ldrsh r1, [r6, r2]
	adds r0, r1
	cmp r0, 0x5
	bgt _080FC364
	ldr r0, =gScriptResult
	strh r5, [r0]
	b _080FC376
	.pool
_080FC364:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _080FC306
	ldr r1, =gScriptResult
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_080FC376:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC2E8

	thumb_func_start sub_80FC388
sub_80FC388: @ 80FC388
	push {lr}
	bl sub_80FC258
	ldr r2, =gScriptResult
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080FC3B0
	adds r0, r1, 0
	lsls r0, 4
	ldr r1, =gUnknown_0203A05C
	adds r0, r1
	b _080FC3B2
	.pool
_080FC3B0:
	movs r0, 0
_080FC3B2:
	pop {r1}
	bx r1
	thumb_func_end sub_80FC388

	thumb_func_start sub_80FC3B8
sub_80FC3B8: @ 80FC3B8
	push {lr}
	bl sub_80FC2E8
	ldr r2, =gScriptResult
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080FC3E0
	adds r0, r1, 0
	lsls r0, 4
	ldr r1, =gUnknown_0203A05C
	adds r0, r1
	b _080FC3E2
	.pool
_080FC3E0:
	movs r0, 0
_080FC3E2:
	pop {r1}
	bx r1
	thumb_func_end sub_80FC3B8

	thumb_func_start sub_80FC3E8
sub_80FC3E8: @ 80FC3E8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r1, 0
	ldr r2, =gUnknown_0203A054
	mov r6, sp
	adds r6, 0x2
	movs r0, 0x8
	adds r0, r2
	mov r9, r0
	ldr r7, =gSaveBlock1Ptr
_080FC408:
	lsls r5, r1, 4
	adds r4, r5, r2
	movs r0, 0x4
	ldrsb r0, [r4, r0]
	cmp r0, 0
	bne _080FC468
	movs r3, 0
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _080FC468
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _080FC468
	mov r0, sp
	adds r1, r6, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	ldr r0, [r7]
	ldrb r0, [r0, 0x5]
	strb r0, [r4, 0x4]
	mov r0, r9
	adds r2, r5, r0
	ldr r0, [r7]
	mov r3, r8
	lsls r1, r3, 3
	ldr r3, =0x00000848
	adds r0, r3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x64
	strb r0, [r4, 0x5]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r6]
	strh r0, [r4, 0x2]
	b _080FC472
	.pool
_080FC468:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _080FC408
_080FC472:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80FC3E8

	thumb_func_start sub_80FC480
sub_80FC480: @ 80FC480
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_0203A054
_080FC486:
	lsls r0, r4, 4
	adds r1, r0, r5
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	beq _080FC4A0
	subs r0, 0x1
	strb r0, [r1, 0x5]
	lsls r0, 24
	cmp r0, 0
	bne _080FC4A0
	adds r0, r4, 0
	bl sub_80FC228
_080FC4A0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080FC486
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC480

	thumb_func_start sub_80FC4B4
sub_80FC4B4: @ 80FC4B4
	push {lr}
	bl sub_80FC258
	ldr r3, =gScriptResult
	ldrh r1, [r3]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080FC4EC
	ldr r0, =gStringVar2
	ldr r2, =gUnknown_0203A054
	lsls r1, 4
	adds r1, r2
	ldrb r1, [r1, 0x5]
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	b _080FC4EE
	.pool
_080FC4EC:
	movs r0, 0
_080FC4EE:
	pop {r1}
	bx r1
	thumb_func_end sub_80FC4B4

	.align 2, 0 @ Don't pad with nop.
