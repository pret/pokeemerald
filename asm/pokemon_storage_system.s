	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


    thumb_func_start sub_80C7128
sub_80C7128: @ 80C7128
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	adds r7, r3, 0
	ldr r5, [sp, 0x1C]
	ldr r4, [sp, 0x20]
	ldr r0, [sp, 0x24]
	mov r9, r0
	ldr r0, [sp, 0x28]
	ldr r3, [sp, 0x2C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	mov r0, r9
	lsls r0, 17
	mov r9, r0
	lsrs r2, 11
	adds r2, r1
	lsls r2, 1
	adds r6, r2
	adds r0, r4, 0
	muls r0, r3
	adds r0, r5
	lsls r0, 1
	adds r7, r0
	movs r4, 0
	cmp r4, r8
	bcs _080C7198
	mov r0, r9
	lsrs r0, 1
	mov r9, r0
	lsls r5, r3, 1
_080C717E:
	adds r0, r7, 0
	adds r1, r6, 0
	mov r3, r9
	lsrs r2, r3, 16
	bl CpuSet
	adds r6, 0x40
	adds r7, r5
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r8
	bcc _080C717E
_080C7198:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C7128

	thumb_func_start sub_80C71A4
sub_80C71A4: @ 80C71A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, [sp, 0x28]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsrs r2, 11
	adds r2, r1
	lsls r2, 1
	adds r4, r2
	lsls r3, 17
	lsrs r0, r3, 16
	str r0, [sp, 0x4]
	movs r0, 0
	cmp r0, r10
	bcs _080C724E
	movs r6, 0x80
	lsls r6, 5
	mov r5, sp
	ldr r7, =0x040000d4
	lsrs r3, 17
	mov r9, r3
	mov r1, r9
	movs r2, 0x81
	lsls r2, 24
	orrs r1, r2
	mov r9, r1
_080C71EA:
	adds r3, r4, 0
	ldr r2, [sp, 0x4]
	movs r1, 0x40
	adds r1, r4
	mov r8, r1
	adds r0, 0x1
	mov r12, r0
	cmp r2, r6
	bhi _080C7214
	movs r0, 0
	strh r0, [r5]
	mov r2, sp
	str r2, [r7]
	str r4, [r7, 0x4]
	mov r0, r9
	str r0, [r7, 0x8]
	ldr r0, [r7, 0x8]
	b _080C7242
	.pool
_080C7214:
	movs r4, 0
	strh r4, [r5]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	ldr r0, =0x81000800
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r6
	subs r2, r6
	cmp r2, r6
	bhi _080C7214
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r2, 1
	movs r2, 0x81
	lsls r2, 24
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_080C7242:
	mov r4, r8
	mov r1, r12
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, r10
	bcc _080C71EA
_080C724E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C71A4

	thumb_func_start c3_0808C39C
c3_0808C39C: @ 80C7268
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bls _080C7284
	b _080C756A
_080C7284:
	lsls r0, 2
	ldr r1, =_080C7298
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C7298:
	.4byte _080C72AC
	.4byte _080C730C
	.4byte _080C7320
	.4byte _080C746A
	.4byte _080C7544
_080C72AC:
	ldrb r0, [r5, 0xA]
	adds r1, r5, 0
	adds r1, 0x26
	bl sub_80C75FC
	bl sub_81973A4
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085716C0
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r1, 0x4
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
	movs r3, 0xFF
	bl AddTextPrinterParameterized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldrh r0, [r5, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl CopyWindowToVram
	b _080C7318
	.pool
_080C730C:
	bl sub_80ABDFC
	lsls r0, 24
	cmp r0, 0
	bne _080C7318
	b _080C756A
_080C7318:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _080C756A
_080C7320:
	bl ProcessMenuInput
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0xC]
	movs r3, 0xC
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080C73D0
	cmp r1, r0
	bgt _080C7342
	subs r0, 0x1
	cmp r1, r0
	beq _080C7348
	b _080C73F6
_080C7342:
	cmp r1, 0x4
	beq _080C73D0
	b _080C73F6
_080C7348:
	ldrh r3, [r5, 0xA]
	strh r3, [r5, 0xE]
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C7366
	subs r0, r3, 0x1
	strh r0, [r5, 0xE]
	lsls r0, 16
	cmp r0, 0
	bge _080C7366
	movs r0, 0x4
	strh r0, [r5, 0xE]
_080C7366:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C7382
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _080C7382
	movs r0, 0
	strh r0, [r5, 0xE]
_080C7382:
	lsls r0, r3, 16
	asrs r0, 16
	ldrh r2, [r5, 0xE]
	movs r3, 0xE
	ldrsh r1, [r5, r3]
	cmp r0, r1
	bne _080C7392
	b _080C756A
_080C7392:
	movs r4, 0
	strh r2, [r5, 0xA]
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085716C0
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r2, [r0]
	str r4, [sp]
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
	b _080C756A
	.pool
_080C73D0:
	ldrh r0, [r5, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_819746C
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
	ldrh r0, [r5, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	b _080C756A
_080C73F6:
	movs r3, 0xC
	ldrsh r4, [r5, r3]
	cmp r4, 0
	bne _080C7428
	bl CountPartyMons
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _080C7428
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_PartyFull
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r4, 0x3
	str r4, [sp, 0xC]
	b _080C7532
	.pool
_080C7428:
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080C745C
	bl CountPartyMons
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _080C745C
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_JustOnePkmn
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r4, 0x3
	str r4, [sp, 0xC]
	b _080C7532
	.pool
_080C745C:
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	movs r0, 0x4
	strh r0, [r5, 0x8]
	b _080C756A
_080C746A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r7, 0x3
	adds r4, r7, 0
	ands r4, r1
	cmp r4, 0
	beq _080C749C
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085716C0
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	b _080C7528
	.pool
_080C749C:
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _080C74E8
	ldrh r0, [r5, 0xA]
	subs r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	cmp r0, 0
	bge _080C74B8
	movs r0, 0x4
	strh r0, [r5, 0xA]
_080C74B8:
	movs r0, 0x1
	negs r0, r0
	bl MoveMenuCursor
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085716C0
	movs r3, 0xA
	ldrsh r0, [r5, r3]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r2, [r0]
	str r4, [sp]
	b _080C7528
	.pool
_080C74E8:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C756A
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _080C7500
	strh r6, [r5, 0xA]
_080C7500:
	movs r0, 0x1
	bl MoveMenuCursor
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085716C0
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r2, [r0]
	str r6, [sp]
_080C7528:
	movs r4, 0x2
	str r4, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
_080C7532:
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	strh r4, [r5, 0x8]
	b _080C756A
	.pool
_080C7544:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080C756A
	bl overworld_free_bg_tilemaps
	ldrb r0, [r5, 0xC]
	bl sub_80C7D74
	ldrh r0, [r5, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
_080C756A:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_0808C39C

	thumb_func_start sub_80C7578
sub_80C7578: @ 80C7578
	push {lr}
	ldr r0, =c3_0808C39C
	movs r1, 0x50
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
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7578

	thumb_func_start mapldr_0808C6D8
mapldr_0808C6D8: @ 80C75A8
	push {r4,r5,lr}
	ldr r0, =gMain
	ldr r5, [r0, 0xC]
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =c3_0808C39C
	adds r0, r4, 0
	movs r1, 0x50
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
	ldr r2, =gUnknown_02039D00
	ldrb r2, [r2]
	strh r2, [r1, 0xA]
	bl _call_via_r4
	adds r0, r5, 0
	bl SetVBlankCallback
	bl pal_fill_black
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_0808C6D8

	thumb_func_start sub_80C75FC
sub_80C75FC: @ 80C75FC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r6, r0, 0
	mov r9, r1
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_085716E8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_085716C0
	mov r8, r0
	movs r1, 0x5
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, r5, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	adds r0, r4, 0
	movs r1, 0x5
	mov r2, r8
	bl PrintMenuTable
	adds r0, r4, 0
	movs r1, 0x5
	adds r2, r6, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	mov r0, r9
	strh r5, [r0]
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C75FC

	thumb_func_start sub_80C7678
sub_80C7678: @ 80C7678
	push {lr}
	bl sub_80CAEA0
	ldr r1, =gUnknown_02039D00
	strb r0, [r1]
	ldr r1, =gFieldCallback
	ldr r0, =mapldr_0808C6D8
	str r0, [r1]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7678

	thumb_func_start sub_80C76A4
sub_80C76A4: @ 80C76A4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	adds r4, r3, 0
	ldr r2, =0x0000ffff
	cmp r3, 0x1
	bhi _080C76C6
	movs r2, 0x1
	cmp r3, 0x1
	beq _080C76CA
_080C76C6:
	cmp r4, 0x3
	bne _080C7714
_080C76CA:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080C7760
	cmp r1, r7
	bgt _080C7760
_080C76E2:
	asrs r4, r0, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	add r0, r8
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	bne _080C770C
	asrs r0, r6, 16
	adds r0, r4, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080C7760
	cmp r2, r7
	ble _080C76E2
	b _080C7760
	.pool
_080C770C:
	adds r0, r4, 0
	b _080C7764
_080C7710:
	adds r0, r5, 0
	b _080C7764
_080C7714:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080C7760
	cmp r1, r7
	bgt _080C7760
_080C772C:
	asrs r5, r0, 16
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 4
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _080C7750
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetBoxMonData
	cmp r0, 0
	beq _080C7710
_080C7750:
	asrs r0, r6, 16
	adds r0, r5, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080C7760
	cmp r2, r7
	ble _080C772C
_080C7760:
	movs r0, 0x1
	negs r0, r0
_080C7764:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80C76A4

	thumb_func_start ResetPokemonStorageSystem
ResetPokemonStorageSystem: @ 80C7770
	push {r4-r6,lr}
	movs r0, 0
	bl sub_80D1D18
	movs r5, 0
_080C777A:
	movs r4, 0
	lsls r6, r5, 24
_080C777E:
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	bl sub_80D2018
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1D
	bls _080C777E
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xD
	bls _080C777A
	movs r5, 0
_080C779E:
	lsls r0, r5, 24
	lsrs r0, 24
	bl GetBoxNamePtr
	ldr r1, =gText_Box
	bl StringCopy
	adds r4, r5, 0x1
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	lsls r4, 16
	lsrs r5, r4, 16
	cmp r5, 0xD
	bls _080C779E
	movs r5, 0
_080C77C2:
	lsls r0, r5, 24
	lsrs r0, 24
	movs r1, 0x3
	ands r1, r5
	bl sub_80D2120
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xD
	bls _080C77C2
	bl ResetWaldaWallpaper
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetPokemonStorageSystem

	thumb_func_start sub_80C77E8
sub_80C77E8: @ 80C77E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r6, r1, 0
	lsls r2, 16
	lsrs r2, 16
	adds r7, r2, 0
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	ldr r0, =gUnknown_0857173C
	str r0, [sp, 0x18]
	ldr r1, =0xffff0000
	add r4, sp, 0x18
	ldr r0, [r4, 0x4]
	ands r0, r1
	orrs r0, r7
	str r0, [r4, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_0857175C
	str r0, [sp]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0x4]
	strh r6, [r1, 0x6]
	ldr r0, =gUnknown_08571F5C
	str r0, [sp, 0x8]
	movs r0, 0xC0
	lsls r0, 1
	strh r0, [r1, 0xC]
	adds r0, r6, 0x1
	strh r0, [r1, 0xE]
	add r0, sp, 0x10
	movs r1, 0
	movs r2, 0x8
	bl memset
	ldr r0, [sp, 0x38]
	cmp r0, 0
	beq _080C7846
	adds r0, r4, 0
	bl LoadSpritePalette
_080C7846:
	mov r0, sp
	bl LoadSpriteSheets
	ldr r0, =gUnknown_02039D04
	str r5, [r0]
	movs r1, 0x90
	lsls r1, 2
	adds r0, r5, r1
	strh r6, [r0]
	adds r1, 0x2
	adds r0, r5, r1
	strh r7, [r0]
	adds r1, 0x4
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	movs r1, 0x8F
	lsls r1, 2
	adds r0, r5, r1
	ldr r1, [sp, 0x38]
	str r1, [r0]
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C77E8

	thumb_func_start sub_80C7890
sub_80C7890: @ 80C7890
	push {r4,r5,lr}
	ldr r5, =gUnknown_02039D04
	ldr r1, [r5]
	movs r2, 0x8F
	lsls r2, 2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _080C78AC
	adds r2, 0x6
	adds r0, r1, r2
	ldrh r0, [r0]
	bl FreeSpritePaletteByTag
_080C78AC:
	ldr r0, [r5]
	movs r4, 0x90
	lsls r4, 2
	adds r0, r4
	ldrh r0, [r0]
	bl FreeSpriteTilesByTag
	ldr r0, [r5]
	adds r0, r4
	ldrh r0, [r0]
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	bl FreeSpriteTilesByTag
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7890

	thumb_func_start sub_80C78D4
sub_80C78D4: @ 80C78D4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_80C7958
	pop {r0}
	bx r0
	thumb_func_end sub_80C78D4

	thumb_func_start sub_80C78E4
sub_80C78E4: @ 80C78E4
	push {lr}
	bl sub_80C7B14
	pop {r0}
	bx r0
	thumb_func_end sub_80C78E4

	thumb_func_start sub_80C78F0
sub_80C78F0: @ 80C78F0
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080C790C
	movs r0, 0x5
	bl PlaySE
	movs r0, 0xC9
	b _080C7954
	.pool
_080C790C:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C792C
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_02039D04
	ldr r0, [r0]
	movs r1, 0x91
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	b _080C7954
	.pool
_080C792C:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080C7940
	movs r0, 0x5
	bl PlaySE
	bl sub_80C7BB4
	b _080C7952
_080C7940:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080C7952
	movs r0, 0x5
	bl PlaySE
	bl sub_80C7B80
_080C7952:
	movs r0, 0xC8
_080C7954:
	pop {r1}
	bx r1
	thumb_func_end sub_80C78F0

	thumb_func_start sub_80C7958
sub_80C7958: @ 80C7958
	push {r4-r6,lr}
	sub sp, 0x3C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x34]
	str r1, [sp, 0x38]
	movs r1, 0xC0
	lsls r1, 24
	ldr r0, [sp, 0x34]
	orrs r0, r1
	str r0, [sp, 0x34]
	ldr r1, =0xffff0fff
	add r4, sp, 0x34
	ldr r0, [r4, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 5
	orrs r0, r1
	str r0, [r4, 0x4]
	add r1, sp, 0x1C
	movs r2, 0
	strh r2, [r1]
	mov r0, sp
	adds r0, 0x1E
	strh r2, [r0]
	str r4, [sp, 0x20]
	ldr r0, =gDummySpriteAnimTable
	str r0, [sp, 0x24]
	str r2, [sp, 0x28]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [sp, 0x2C]
	ldr r0, =SpriteCallbackDummy
	str r0, [sp, 0x30]
	add r0, sp, 0x4
	movs r2, 0x18
	bl memcpy
	ldr r6, =gUnknown_02039D04
	ldr r0, [r6]
	movs r1, 0x91
	lsls r1, 2
	adds r0, r1
	strb r5, [r0]
	add r2, sp, 0x4
	ldr r1, [r6]
	movs r5, 0x90
	lsls r5, 2
	adds r0, r1, r5
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r3, =0x00000242
	adds r1, r3
	ldrh r0, [r1]
	strh r0, [r2, 0x2]
	adds r0, r2, 0
	movs r1, 0xA0
	movs r2, 0x60
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r2, [r4, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r2
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	ands r1, r0
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4, 0x3]
	add r1, sp, 0x4
	adds r3, r5
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r1]
	ldr r0, =sSpriteAnimTable_8571710
	str r0, [sp, 0xC]
	movs r4, 0
_080C7A10:
	ldr r0, [r6]
	ldr r1, =0x00000246
	adds r0, r1
	ldrb r3, [r0]
	add r0, sp, 0x4
	movs r1, 0x7C
	movs r2, 0x50
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r2, [r6]
	lsls r3, r4, 2
	adds r2, 0x4
	adds r2, r3
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r1, r0, r1
	str r1, [r2]
	movs r5, 0
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _080C7A4A
	movs r0, 0xC4
	strh r0, [r1, 0x20]
	movs r5, 0x2
_080C7A4A:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _080C7A6E
	ldr r1, [r6]
	adds r1, 0x4
	adds r1, r3
	ldr r2, [r1]
	movs r0, 0x70
	strh r0, [r2, 0x22]
	ldr r2, [r1]
	ldrb r1, [r2, 0x3]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x3]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080C7A6E:
	ldr r0, [r6]
	adds r0, 0x4
	adds r0, r3
	ldr r0, [r0]
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _080C7A10
	movs r4, 0
	ldr r5, =gUnknown_02039D04
_080C7A8C:
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 19
	movs r3, 0xF8
	lsls r3, 15
	adds r0, r3
	lsrs r0, 16
	lsls r2, r4, 24
	lsrs r2, 24
	ldr r1, [r5]
	ldr r3, =0x00000246
	adds r1, r3
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, 0x58
	movs r3, 0
	bl sub_80CD2E8
	adds r2, r0, 0
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r0, 0x20
	adds r0, r1
	str r2, [r0]
	cmp r2, 0
	beq _080C7AD4
	movs r1, 0x1
	cmp r4, 0
	bne _080C7ACC
	movs r3, 0x1
	negs r3, r3
	adds r1, r3, 0
_080C7ACC:
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80C7CF4
	str r0, [r1, 0x1C]
_080C7AD4:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _080C7A8C
	bl sub_80C7BE4
	add sp, 0x3C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7958

	thumb_func_start sub_80C7B14
sub_80C7B14: @ 80C7B14
	push {r4-r6,lr}
	ldr r4, =gUnknown_02039D04
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _080C7B2A
	bl DestroySprite
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1]
_080C7B2A:
	movs r5, 0
	adds r6, r4, 0
_080C7B2E:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0x4
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080C7B4A
	bl DestroySprite
	ldr r0, [r6]
	adds r0, 0x4
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080C7B4A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _080C7B2E
	movs r5, 0
_080C7B56:
	ldr r0, =gUnknown_02039D04
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, 0x20
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080C7B6A
	bl DestroySprite
_080C7B6A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x1
	bls _080C7B56
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7B14

	thumb_func_start sub_80C7B80
sub_80C7B80: @ 80C7B80
	push {lr}
	ldr r2, =gUnknown_02039D04
	ldr r1, [r2]
	movs r0, 0x91
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD
	bls _080C7BA6
	ldr r0, [r2]
	movs r1, 0x91
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080C7BA6:
	bl sub_80C7BE4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7B80

	thumb_func_start sub_80C7BB4
sub_80C7BB4: @ 80C7BB4
	push {lr}
	ldr r0, =gUnknown_02039D04
	ldr r2, [r0]
	movs r1, 0x91
	lsls r1, 2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C7BD0
	subs r1, r0, 0x1
	b _080C7BD2
	.pool
_080C7BD0:
	movs r1, 0xD
_080C7BD2:
	movs r3, 0x91
	lsls r3, 2
	adds r0, r2, r3
	strb r1, [r0]
	bl sub_80C7BE4
	pop {r0}
	bx r0
	thumb_func_end sub_80C7BB4

	thumb_func_start sub_80C7BE4
sub_80C7BE4: @ 80C7BE4
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x24
	ldr r0, =gUnknown_02039D04
	mov r9, r0
	ldr r0, [r0]
	movs r4, 0x91
	lsls r4, 2
	adds r0, r4
	ldrb r0, [r0]
	bl GetBoxNamePtr
	mov r10, r0
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0]
	bl CountMonsInBox
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	add r4, sp, 0x1C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r0, 0x8
	strb r0, [r4, 0x3]
	movs r0, 0x4
	strb r0, [r4, 0x4]
	adds r0, r4, 0
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x44
	bl FillWindowPixelBuffer
	movs r0, 0x1
	mov r1, r10
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_08571734
	mov r8, r0
	str r0, [sp]
	movs r6, 0x1
	negs r6, r6
	str r6, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	add r0, sp, 0xC
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_08571737
	add r0, sp, 0xC
	bl StringAppend
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	mov r0, r8
	str r0, [sp]
	str r6, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	adds r0, r4, 0
	movs r1, 0x7
	bl GetWindowAttribute
	adds r5, r0, 0
	mov r1, r9
	ldr r0, [r1]
	movs r1, 0x90
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0]
	bl GetSpriteTileStartByTag
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 11
	ldr r0, =0x06010100
	adds r1, r0
	ldr r2, =0x04000100
	adds r0, r5, 0
	bl CpuSet
	adds r0, r4, 0
	bl RemoveWindow
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7BE4

	thumb_func_start sub_80C7CF4
sub_80C7CF4: @ 80C7CF4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _080C7D24
	strh r2, [r1, 0x30]
	ldrh r0, [r1, 0x2E]
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080C7D24
	strh r2, [r1, 0x32]
	strh r2, [r1, 0x24]
_080C7D24:
	pop {r0}
	bx r0
	thumb_func_end sub_80C7CF4

	thumb_func_start sub_80C7D28
sub_80C7D28: @ 80C7D28
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl sub_80D2AA4
	bl TransferPlttBuffer
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0xB3
	lsls r1, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7D28

	thumb_func_start c2_Box
c2_Box: @ 80C7D54
	push {lr}
	bl RunTasks
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl sub_80CA028
	bl sub_80CAA14
	bl AnimateSprites
	bl BuildOamBuffer
	pop {r0}
	bx r0
	thumb_func_end c2_Box

	thumb_func_start sub_80C7D74
sub_80C7D74: @ 80C7D74
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl ResetTasks
	ldr r0, =gUnknown_02039D0D
	strb r5, [r0]
	ldr r4, =gUnknown_02039D08
	ldr r0, =0x000062c4
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _080C7DA8
	ldr r0, =sub_80C7678
	bl SetMainCallback2
	b _080C7DD4
	.pool
_080C7DA8:
	movs r2, 0
	strb r5, [r0, 0x1]
	ldr r0, [r4]
	strb r2, [r0, 0x3]
	ldr r0, =gUnknown_02039D12
	movs r1, 0
	strh r2, [r0]
	ldr r0, [r4]
	strb r1, [r0]
	ldr r0, =task_box_related_3
	movs r1, 0x3
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0x4]
	bl StorageGetCurrentBox
	ldr r1, =gUnknown_02039D10
	strb r0, [r1]
	ldr r0, =c2_Box
	bl SetMainCallback2
_080C7DD4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7D74

	thumb_func_start c2_808CE60
c2_808CE60: @ 80C7DEC
	push {r4,lr}
	bl ResetTasks
	ldr r4, =gUnknown_02039D08
	ldr r0, =0x000062c4
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	cmp r1, 0
	bne _080C7E18
	ldr r0, =sub_80C7678
	bl SetMainCallback2
	b _080C7E3C
	.pool
_080C7E18:
	ldr r0, =gUnknown_02039D0D
	ldrb r0, [r0]
	movs r2, 0
	strb r0, [r1, 0x1]
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x3]
	ldr r0, [r4]
	strb r2, [r0]
	ldr r0, =task_box_related_3
	movs r1, 0x3
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0x4]
	ldr r0, =c2_Box
	bl SetMainCallback2
_080C7E3C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_808CE60

	thumb_func_start sub_80C7E50
sub_80C7E50: @ 80C7E50
	push {lr}
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_80C7E50

	thumb_func_start sub_80C7E98
sub_80C7E98: @ 80C7E98
	push {r4,lr}
	sub sp, 0x4
	bl ResetPaletteFade
	bl ResetSpriteData
	bl FreeSpriteTileRanges
	bl FreeAllSpritePalettes
	bl ClearDma3Requests
	ldr r1, =gReservedSpriteTileCount
	movs r2, 0xA0
	lsls r2, 2
	adds r0, r2, 0
	strh r0, [r1]
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, 0x10
	movs r2, 0x8
	bl sub_80D2A90
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	bl clear_scheduled_bg_copies_to_vram
	movs r0, 0x3
	bl sub_80D259C
	ldr r2, =gUnknown_0857239C
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x8
	bl sub_80D2644
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_80D2770
	ldr r0, [r4]
	ldr r1, =0x000002c7
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7E98

	thumb_func_start sub_80C7F1C
sub_80C7F1C: @ 80C7F1C
	push {lr}
	bl sub_80CDC0C
	ldr r2, =gUnknown_02039D0C
	movs r1, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _080C7F32
	movs r1, 0x1
_080C7F32:
	strb r1, [r2]
	ldr r1, =gUnknown_02039D0E
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7F1C

	thumb_func_start sub_80C7F4C
sub_80C7F4C: @ 80C7F4C
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080C7F6A
	movs r1, 0xFC
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000b07
	movs r0, 0x52
	bl SetGpuReg
_080C7F6A:
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C7F4C

	thumb_func_start add_to_c3_somehow
add_to_c3_somehow: @ 80C7F80
	push {r4,lr}
	ldr r4, =gTasks
	ldr r1, =gUnknown_02039D08
	ldr r3, [r1]
	ldrb r2, [r3, 0x4]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r4
	str r0, [r1]
	movs r0, 0
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end add_to_c3_somehow

	thumb_func_start task_box_related_3
task_box_related_3: @ 80C7FA8
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xA
	bls _080C7FB8
	b _080C81A2
_080C7FB8:
	lsls r0, 2
	ldr r1, =_080C7FCC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C7FCC:
	.4byte _080C7FF8
	.4byte _080C8050
	.4byte _080C805E
	.4byte _080C808C
	.4byte _080C80A8
	.4byte _080C80C6
	.4byte _080C80E6
	.4byte _080C80EC
	.4byte _080C80F2
	.4byte _080C8100
	.4byte _080C814A
_080C7FF8:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	bl sub_80C7E98
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _080C8046
	ldr r0, =gUnknown_02039D0F
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C8036
	cmp r0, 0x1
	bgt _080C8030
	cmp r0, 0
	beq _080C803C
	b _080C8046
	.pool
_080C8030:
	cmp r0, 0x2
	beq _080C8042
	b _080C8046
_080C8036:
	bl sub_80CE790
	b _080C8046
_080C803C:
	bl sub_80CE8E4
	b _080C8046
_080C8042:
	bl sub_80C9F6C
_080C8046:
	bl sub_80CA044
	bl sub_80CA0C8
	b _080C8198
_080C8050:
	bl sub_80CA0A4
	lsls r0, 24
	cmp r0, 0
	beq _080C805C
	b _080C8198
_080C805C:
	b _080C80D0
_080C805E:
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl ClearWindowTilemap
	movs r0, 0
	str r0, [sp]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05000080
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0xB
	movs r2, 0xE0
	bl sub_809882C
	b _080C8198
	.pool
_080C808C:
	bl sub_80C7E50
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _080C809C
	b _080C8198
_080C809C:
	bl sub_80C7F1C
	b _080C8198
	.pool
_080C80A8:
	bl sub_80CAF04
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	bne _080C80C0
	bl sub_80CD36C
	b _080C8198
	.pool
_080C80C0:
	bl sub_80CD3EC
	b _080C8198
_080C80C6:
	bl sub_80D0164
	lsls r0, 24
	cmp r0, 0
	bne _080C80DC
_080C80D0:
	ldr r0, =sub_80C9E50
	bl add_to_c3_somehow
	b _080C81A2
	.pool
_080C80DC:
	bl sub_80C9FEC
	bl sub_80CAC1C
	b _080C8198
_080C80E6:
	bl sub_80CA0D8
	b _080C8198
_080C80EC:
	bl sub_80CA704
	b _080C8198
_080C80F2:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	bl sub_80CC32C
	b _080C8198
_080C8100:
	bl sub_80CC35C
	lsls r0, 24
	cmp r0, 0
	bne _080C81A2
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldrb r0, [r2, 0x1]
	cmp r0, 0x3
	beq _080C8140
	ldr r1, =0x00000da4
	adds r0, r2, r1
	movs r1, 0xD
	strh r1, [r0]
	ldr r1, =0x00000da6
	adds r2, r1
	ldr r1, =0x0000dace
	strh r1, [r2]
	bl sub_811F90C
	bl sub_811FA90
	b _080C8198
	.pool
_080C8140:
	bl sub_80D0C60
	bl sub_80CAEAC
	b _080C8198
_080C814A:
	bl sub_80C7F4C
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	bne _080C8174
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_80C81AC
	bl add_to_c3_somehow
	b _080C8186
	.pool
_080C8174:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =box_related_2
	bl add_to_c3_somehow
_080C8186:
	ldr r0, =sub_80C7D28
	bl SetVBlankCallback
	b _080C81A2
	.pool
_080C8198:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C81A2:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_box_related_3

	thumb_func_start sub_80C81AC
sub_80C81AC: @ 80C81AC
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C81C4
	cmp r0, 0x1
	beq _080C81DE
	b _080C81EE
	.pool
_080C81C4:
	movs r0, 0x2
	bl PlaySE
	movs r0, 0x14
	movs r1, 0
	movs r2, 0x1
	bl sub_80F9BCC
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C81EE
_080C81DE:
	bl sub_80F9C1C
	lsls r0, 24
	cmp r0, 0
	bne _080C81EE
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C81EE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C81AC

	thumb_func_start box_related_2
box_related_2: @ 80C81F8
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C8230
	cmp r0, 0x1
	bgt _080C8214
	cmp r0, 0
	beq _080C821E
	b _080C82A0
	.pool
_080C8214:
	cmp r0, 0x2
	beq _080C8268
	cmp r0, 0x3
	beq _080C8290
	b _080C82A0
_080C821E:
	movs r1, 0x1
	negs r1, r1
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _080C8282
_080C8230:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C82A0
	ldr r0, =gUnknown_02039D0F
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080C825C
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C825C
	movs r0, 0x1C
	bl sub_80CAC58
	b _080C8282
	.pool
_080C825C:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C82A0
	.pool
_080C8268:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C82A0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080C82A0
	bl sub_80CADC4
_080C8282:
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C82A0
	.pool
_080C8290:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C82A0
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C82A0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end box_related_2

	thumb_func_start task_pokemon_box_related
task_pokemon_box_related: @ 80C82AC
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xB
	bls _080C82BA
	b _080C879E
_080C82BA:
	lsls r0, 2
	ldr r1, =_080C82CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C82CC:
	.4byte _080C82FC
	.4byte _080C861C
	.4byte _080C865C
	.4byte _080C86B4
	.4byte _080C86D8
	.4byte _080C86E2
	.4byte _080C86FC
	.4byte _080C871C
	.4byte _080C8722
	.4byte _080C8738
	.4byte _080C8764
	.4byte _080C878C
_080C82FC:
	bl sub_80CF9EC
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x19
	bls _080C830C
	b _080C879E
_080C830C:
	lsls r0, 2
	ldr r1, =_080C831C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C831C:
	.4byte _080C8384
	.4byte _080C879E
	.4byte _080C879E
	.4byte _080C8414
	.4byte _080C8398
	.4byte _080C83CC
	.4byte _080C842C
	.4byte _080C8440
	.4byte _080C844C
	.4byte _080C8484
	.4byte _080C84C8
	.4byte _080C854C
	.4byte _080C850C
	.4byte _080C851E
	.4byte _080C8560
	.4byte _080C8574
	.4byte _080C8588
	.4byte _080C859C
	.4byte _080C8420
	.4byte _080C85B0
	.4byte _080C85D0
	.4byte _080C85BA
	.4byte _080C85DA
	.4byte _080C8614
	.4byte _080C85DE
	.4byte _080C85F8
_080C8384:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1]
	b _080C879E
	.pool
_080C8398:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080C83BC
	movs r0, 0x10
	bl sub_80CAC58
	ldr r1, [r4]
	movs r0, 0x3
	strb r0, [r1]
	b _080C879E
	.pool
_080C83BC:
	bl sub_80CDC0C
	ldr r0, =sub_80C87A8
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C83CC:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x2
	bne _080C8400
	bl sub_80CEAD0
	lsls r0, 24
	cmp r0, 0
	beq _080C8406
	ldr r0, [r4]
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _080C83F4
	b _080C84E6
_080C83F4:
	b _080C8406
	.pool
_080C8400:
	cmp r0, 0x3
	beq _080C8406
	b _080C879E
_080C8406:
	ldr r0, =sub_80C87E8
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8414:
	ldr r0, =sub_80C9BE8
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8420:
	ldr r0, =sub_80C9D1C
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C842C:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =box_related
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8440:
	ldr r0, =sub_80C8864
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C844C:
	movs r0, 0x5
	bl PlaySE
	bl StorageGetCurrentBox
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	ldr r2, =0x000002ca
	adds r1, r2
	strh r0, [r1]
	cmp r0, 0xD
	ble _080C846E
	movs r0, 0
	strh r0, [r1]
_080C846E:
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x3
	beq _080C84BC
	adds r0, r1, r2
	b _080C8776
	.pool
_080C8484:
	movs r0, 0x5
	bl PlaySE
	bl StorageGetCurrentBox
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	ldr r2, =0x000002ca
	adds r1, r2
	strh r0, [r1]
	cmp r0, 0
	bge _080C84A6
	movs r0, 0xD
	strh r0, [r1]
_080C84A6:
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x3
	beq _080C84BC
	adds r0, r1, r2
	b _080C8776
	.pool
_080C84BC:
	bl sub_80CFEA8
	ldr r1, [r4]
	movs r0, 0xA
	strb r0, [r1]
	b _080C879E
_080C84C8:
	bl sub_80CEA30
	lsls r0, 24
	cmp r0, 0
	bne _080C8528
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _080C84F8
_080C84E6:
	ldr r1, [r4]
	movs r0, 0x5
	strb r0, [r1]
	b _080C879E
	.pool
_080C84F8:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C8D78
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C850C:
	bl sub_80CEA30
	lsls r0, 24
	cmp r0, 0
	bne _080C8528
	movs r0, 0x5
	bl PlaySE
	b _080C872C
_080C851E:
	bl sub_80CEA6C
	lsls r0, 24
	cmp r0, 0
	bne _080C8538
_080C8528:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x4
	strb r0, [r1]
	b _080C879E
	.pool
_080C8538:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =c3_0808DC50
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C854C:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C8C90
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8560:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C8BEC
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8574:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C9128
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8588:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C91DC
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C859C:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C93B0
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C85B0:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	b _080C8600
_080C85BA:
	movs r0, 0x1
	bl sub_80D01D0
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x8
	strb r0, [r1]
	b _080C879E
	.pool
_080C85D0:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x2
	b _080C85E6
_080C85DA:
	movs r0, 0x3
	b _080C8600
_080C85DE:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
_080C85E6:
	bl sub_80D01D0
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x9
	strb r0, [r1]
	b _080C879E
	.pool
_080C85F8:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x5
_080C8600:
	bl sub_80D01D0
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x7
	strb r0, [r1]
	b _080C879E
	.pool
_080C8614:
	movs r0, 0x20
	bl PlaySE
	b _080C879E
_080C861C:
	bl sub_80CD554
	lsls r0, 24
	cmp r0, 0
	beq _080C8628
	b _080C879E
_080C8628:
	bl sub_80CEAF8
	lsls r0, 24
	cmp r0, 0
	beq _080C8638
	bl sub_80CA9C0
	b _080C863C
_080C8638:
	bl sub_80CA9EC
_080C863C:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00000cea
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C864E
	bl BoxSetMosaic
_080C864E:
	ldr r1, [r4]
	b _080C86C8
	.pool
_080C865C:
	bl sub_80CC54C
	lsls r0, 24
	cmp r0, 0
	beq _080C8668
	b _080C879E
_080C8668:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000002ca
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80D1D18
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C8690
	bl sub_80CEAD0
	lsls r0, 24
	cmp r0, 0
	bne _080C8690
	bl sub_80CE00C
	bl BoxSetMosaic
_080C8690:
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x3
	bne _080C86C8
	bl sub_80CFECC
	ldr r1, [r4]
	movs r0, 0xB
	strb r0, [r1]
	b _080C879E
	.pool
_080C86B4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C879E
	bl sub_80CADC4
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
_080C86C8:
	movs r0, 0
	strb r0, [r1]
	b _080C879E
	.pool
_080C86D8:
	movs r0, 0x20
	bl PlaySE
	movs r0, 0xD
	b _080C86EA
_080C86E2:
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x16
_080C86EA:
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x6
	strb r0, [r1]
	b _080C879E
	.pool
_080C86FC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C879E
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C871C:
	bl sub_80D01E4
	b _080C8790
_080C8722:
	bl sub_80D01E4
	lsls r0, 24
	cmp r0, 0
	bne _080C879E
_080C872C:
	ldr r0, =sub_80C8B90
	bl add_to_c3_somehow
	b _080C879E
	.pool
_080C8738:
	bl sub_80D01E4
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080C879E
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r1, =0x00000cea
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8756
	bl BoxSetMosaic
_080C8756:
	ldr r0, [r5]
	strb r4, [r0]
	b _080C879E
	.pool
_080C8764:
	bl sub_80D1218
	lsls r0, 24
	cmp r0, 0
	bne _080C879E
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x000002ca
	adds r0, r1
_080C8776:
	ldrb r0, [r0]
	bl sub_80CC464
	ldr r1, [r4]
	movs r0, 0x2
	strb r0, [r1]
	b _080C879E
	.pool
_080C878C:
	bl sub_80D1218
_080C8790:
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080C879E
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	strb r1, [r0]
_080C879E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_pokemon_box_related

	thumb_func_start sub_80C87A8
sub_80C87A8: @ 80C87A8
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C87C0
	cmp r0, 0x1
	beq _080C87CE
	b _080C87DE
	.pool
_080C87C0:
	bl sub_80CAB4C
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C87DE
_080C87CE:
	bl sub_80CAB70
	lsls r0, 24
	cmp r0, 0
	bne _080C87DE
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C87DE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C87A8

	thumb_func_start sub_80C87E8
sub_80C87E8: @ 80C87E8
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C8816
	cmp r0, 0x1
	bgt _080C8804
	cmp r0, 0
	beq _080C880A
	b _080C8856
	.pool
_080C8804:
	cmp r0, 0x2
	beq _080C8836
	b _080C8856
_080C880A:
	movs r0, 0x5
	bl PlaySE
	bl sub_80CA888
	b _080C882C
_080C8816:
	bl sub_80CA8C8
	lsls r0, 24
	cmp r0, 0
	bne _080C8856
	bl sub_80CDC2C
	lsls r0, 24
	lsrs r0, 24
	bl sub_80CDBF8
_080C882C:
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C8856
_080C8836:
	bl sub_80CD554
	lsls r0, 24
	cmp r0, 0
	bne _080C8856
	ldr r0, [r4]
	ldr r1, =0x00000cea
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8850
	bl BoxSetMosaic
_080C8850:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C8856:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C87E8

	thumb_func_start sub_80C8864
sub_80C8864: @ 80C8864
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x6
	bls _080C8872
	b _080C8B82
_080C8872:
	lsls r0, 2
	ldr r1, =_080C8884
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C8884:
	.4byte _080C88A0
	.4byte _080C8904
	.4byte _080C8920
	.4byte _080C8B3C
	.4byte _080C8B50
	.4byte _080C8B46
	.4byte _080C8B6C
_080C88A0:
	bl sub_80CA2B8
	lsls r0, 24
	cmp r0, 0
	beq _080C88AC
	b _080C8B82
_080C88AC:
	movs r0, 0x5
	bl PlaySE
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	beq _080C88C8
	movs r0, 0x4
	bl sub_80CAC58
	b _080C88F2
	.pool
_080C88C8:
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	bne _080C88DE
	ldr r0, [r4]
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C88EC
_080C88DE:
	movs r0, 0x17
	bl sub_80CAC58
	b _080C88F2
	.pool
_080C88EC:
	movs r0, 0x18
	bl sub_80CAC58
_080C88F2:
	bl sub_80CFFD0
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1]
	b _080C8B82
	.pool
_080C8904:
	bl sub_80D00A8
	lsls r0, 24
	cmp r0, 0
	beq _080C8910
	b _080C8B82
_080C8910:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1]
	b _080C8B82
	.pool
_080C8920:
	bl sub_80D00AC
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x12
	bls _080C8930
	b _080C8B82
_080C8930:
	lsls r0, 2
	ldr r1, =_080C8940
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C8940:
	.4byte _080C898C
	.4byte _080C898C
	.4byte _080C8A0C
	.4byte _080C89F4
	.4byte _080C899C
	.4byte _080C89D4
	.4byte _080C89BC
	.4byte _080C8AAC
	.4byte _080C8A48
	.4byte _080C8AC0
	.4byte _080C8B82
	.4byte _080C8B82
	.4byte _080C8B82
	.4byte _080C8AD4
	.4byte _080C8AE8
	.4byte _080C8B1C
	.4byte _080C8B08
	.4byte _080C8AFC
	.4byte _080C8B30
_080C898C:
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C899C:
	bl sub_80CEA30
	lsls r0, 24
	cmp r0, 0
	bne _080C8A52
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =sub_80C8B90
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C89BC:
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =sub_80C8BEC
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C89D4:
	bl sub_80CEA6C
	lsls r0, 24
	cmp r0, 0
	beq _080C8A52
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =c3_0808DC50
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C89F4:
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =sub_80C8C90
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8A0C:
	bl sub_80CEA30
	lsls r0, 24
	cmp r0, 0
	bne _080C8A52
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r2, =0x00000ce6
	adds r0, r2
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	bne _080C8A8C
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =sub_80C8D78
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8A48:
	bl sub_80CEA30
	lsls r0, 24
	cmp r0, 0
	beq _080C8A60
_080C8A52:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x3
	strb r0, [r1]
	b _080C8B82
	.pool
_080C8A60:
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r2, =0x00000ced
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8A7C
	movs r0, 0x5
	strb r0, [r1]
	b _080C8B82
	.pool
_080C8A7C:
	ldr r2, =0x00000ce6
	adds r0, r1, r2
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _080C8A98
_080C8A8C:
	ldr r1, [r4]
	movs r0, 0x4
	strb r0, [r1]
	b _080C8B82
	.pool
_080C8A98:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C8EB4
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8AAC:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C9B28
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8AC0:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C90A4
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8AD4:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C9128
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8AE8:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C91DC
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8AFC:
	ldr r0, =sub_80C9298
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8B08:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C93B0
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8B1C:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C9B88
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8B30:
	ldr r0, =sub_80C9498
	bl add_to_c3_somehow
	b _080C8B82
	.pool
_080C8B3C:
	movs r0, 0x20
	bl PlaySE
	movs r0, 0xD
	b _080C8B58
_080C8B46:
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x11
	b _080C8B58
_080C8B50:
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x16
_080C8B58:
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x6
	strb r0, [r1]
	b _080C8B82
	.pool
_080C8B6C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C8B82
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C8B82:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C8864

	thumb_func_start sub_80C8B90
sub_80C8B90: @ 80C8B90
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8BA8
	cmp r0, 0x1
	beq _080C8BB8
	b _080C8BE2
	.pool
_080C8BA8:
	movs r0, 0
	bl sub_80CDC38
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C8BE2
_080C8BB8:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080C8BE2
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8BDC
	ldr r0, =sub_80C9670
	bl add_to_c3_somehow
	b _080C8BE2
	.pool
_080C8BDC:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C8BE2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C8B90

	thumb_func_start sub_80C8BEC
sub_80C8BEC: @ 80C8BEC
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8C04
	cmp r0, 0x1
	beq _080C8C14
	b _080C8C3E
	.pool
_080C8C04:
	movs r0, 0x1
	bl sub_80CDC38
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C8C3E
_080C8C14:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080C8C3E
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8C38
	ldr r0, =sub_80C9670
	bl add_to_c3_somehow
	b _080C8C3E
	.pool
_080C8C38:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C8C3E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C8BEC

	thumb_func_start c3_0808DC50
c3_0808DC50: @ 80C8C48
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8C60
	cmp r0, 0x1
	beq _080C8C70
	b _080C8C84
	.pool
_080C8C60:
	movs r0, 0x2
	bl sub_80CDC38
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C8C84
_080C8C70:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080C8C84
	bl BoxSetMosaic
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C8C84:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_0808DC50

	thumb_func_start sub_80C8C90
sub_80C8C90: @ 80C8C90
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _080C8D6E
	lsls r0, 2
	ldr r1, =_080C8CB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C8CB0:
	.4byte _080C8CC8
	.4byte _080C8D00
	.4byte _080C8D20
	.4byte _080C8D36
	.4byte _080C8D48
	.4byte _080C8D68
_080C8CC8:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _080C8CE8
	movs r0, 0xE
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1]
	b _080C8D6E
	.pool
_080C8CE8:
	bl sub_80CDC18
	movs r0, 0
	bl sub_80CDC38
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1]
	b _080C8D6E
	.pool
_080C8D00:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C8D6E
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C8D6E
	.pool
_080C8D20:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080C8D6E
	movs r0, 0x1
	bl sub_80CC0D4
	bl sub_80CAB4C
	b _080C8D56
_080C8D36:
	bl sub_80CAB70
	lsls r0, 24
	cmp r0, 0
	bne _080C8D6E
	movs r0, 0x1
	bl sub_80CDC38
	b _080C8D56
_080C8D48:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080C8D6E
	bl sub_80CAB20
_080C8D56:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C8D6E
	.pool
_080C8D68:
	ldr r0, =sub_80C87E8
	bl add_to_c3_somehow
_080C8D6E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C8C90

	thumb_func_start sub_80C8D78
sub_80C8D78: @ 80C8D78
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _080C8D88
	b _080C8EA2
_080C8D88:
	lsls r0, 2
	ldr r1, =_080C8D9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C8D9C:
	.4byte _080C8DB0
	.4byte _080C8DEC
	.4byte _080C8E4C
	.4byte _080C8E64
	.4byte _080C8E88
_080C8DB0:
	movs r0, 0x6
	bl sub_80CAC58
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00001e5c
	adds r0, r1
	ldr r2, =0x0000dac7
	movs r1, 0
	str r1, [sp]
	movs r1, 0xA
	movs r3, 0x3
	bl sub_80C77E8
	ldr r0, =gUnknown_02039D0E
	ldrb r0, [r0]
	bl sub_80C78D4
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C8EA0
	.pool
_080C8DEC:
	bl sub_80C78F0
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r0, 0xC8
	beq _080C8EA2
	cmp r0, 0xC9
	bne _080C8E0C
	bl sub_80CADC4
	bl sub_80C78E4
	bl sub_80C7890
	b _080C8E7A
_080C8E0C:
	adds r0, r4, 0
	bl sub_80CE19C
	lsls r0, 24
	cmp r0, 0
	beq _080C8E38
	ldr r0, =gUnknown_02039D0E
	strb r4, [r0]
	bl sub_80CADC4
	bl sub_80C78E4
	bl sub_80C7890
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x2
	b _080C8EA0
	.pool
_080C8E38:
	movs r0, 0x8
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x4
	b _080C8EA0
	.pool
_080C8E4C:
	bl CompactPartySlots
	bl sub_80CB950
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C8EA0
	.pool
_080C8E64:
	bl sub_80CB9BC
	lsls r0, 24
	cmp r0, 0
	bne _080C8EA2
	bl sub_80CE22C
	bl BoxSetMosaic
	bl sub_80CAB20
_080C8E7A:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C8EA2
	.pool
_080C8E88:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C8EA2
	movs r0, 0x6
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
_080C8EA0:
	strb r0, [r1]
_080C8EA2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C8D78

	thumb_func_start sub_80C8EB4
sub_80C8EB4: @ 80C8EB4
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xD
	bls _080C8EC2
	b _080C9096
_080C8EC2:
	lsls r0, 2
	ldr r1, =_080C8ED4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C8ED4:
	.4byte _080C8F0C
	.4byte _080C8F22
	.4byte _080C8F5A
	.4byte _080C8F80
	.4byte _080C8F8C
	.4byte _080C8FA4
	.4byte _080C8FE0
	.4byte _080C8FF8
	.4byte _080C9004
	.4byte _080C9008
	.4byte _080C901C
	.4byte _080C9038
	.4byte _080C904A
	.4byte _080C9080
_080C8F0C:
	movs r0, 0x9
	bl sub_80CAC58
	movs r0, 0x1
	bl sub_80CAD9C
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C8F22:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080C8F4C
	cmp r1, 0
	bgt _080C8F40
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080C8F46
	b _080C9096
	.pool
_080C8F40:
	cmp r1, 0x1
	beq _080C8F46
	b _080C9096
_080C8F46:
	bl sub_80CADC4
	b _080C8FF8
_080C8F4C:
	bl sub_80CADC4
	bl sub_80CE3A0
	bl sub_80CE250
	b _080C905C
_080C8F5A:
	bl sub_80CE580
	bl sub_80CE2A8
	lsls r0, 24
	cmp r0, 0
	beq _080C8F6A
	b _080C9096
_080C8F6A:
	b _080C8F72
_080C8F6C:
	cmp r0, 0
	bne _080C8F72
	b _080C9070
_080C8F72:
	bl sub_80CE580
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080C8F6C
	b _080C905C
_080C8F80:
	bl sub_80CE2D8
	bl sub_80CA230
	movs r0, 0xA
	b _080C9058
_080C8F8C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	bne _080C8F9A
	b _080C9096
_080C8F9A:
	movs r0, 0xB
	b _080C9058
	.pool
_080C8FA4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9096
	bl sub_80CADC4
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C8FD0
	bl CompactPartySlots
	bl sub_80CB950
	b _080C905C
	.pool
_080C8FD0:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x7
	strb r0, [r1]
	b _080C9096
	.pool
_080C8FE0:
	bl sub_80CB9BC
	lsls r0, 24
	cmp r0, 0
	bne _080C9096
	bl sub_80CE00C
	bl BoxSetMosaic
	bl sub_80CAB20
	b _080C905C
_080C8FF8:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C9096
	.pool
_080C9004:
	movs r0, 0xA
	b _080C9058
_080C9008:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9096
	movs r0, 0x15
	b _080C9058
	.pool
_080C901C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9096
	bl sub_80CADC4
	bl sub_80CC064
	b _080C905C
	.pool
_080C9038:
	bl sub_80CC0A0
	lsls r0, 24
	cmp r0, 0
	bne _080C9096
	bl sub_80CE324
	movs r0, 0x13
	b _080C9058
_080C904A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9096
	movs r0, 0x14
_080C9058:
	bl sub_80CAC58
_080C905C:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9096
	.pool
_080C9070:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x8
	strb r0, [r1]
	b _080C9096
	.pool
_080C9080:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9096
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C9096:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C8EB4

	thumb_func_start sub_80C90A4
sub_80C90A4: @ 80C90A4
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C90BC
	cmp r0, 0x1
	beq _080C90F0
	b _080C9118
	.pool
_080C90BC:
	movs r0, 0xC
	bl sub_80CAC58
	ldr r0, [r4]
	ldr r2, =0x00000ceb
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, =0x00000da8
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0xB0
	movs r2, 0x10
	bl sub_811FAA4
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9118
	.pool
_080C90F0:
	bl sub_811FBA4
	lsls r0, 24
	cmp r0, 0
	bne _080C9118
	bl sub_811FAF8
	bl sub_80CADC4
	ldr r0, [r4]
	ldr r1, =0x00000da8
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80CE9A8
	bl sub_80CA230
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C9118:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C90A4

	thumb_func_start sub_80C9128
sub_80C9128: @ 80C9128
	push {r4,r5,lr}
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldrb r1, [r0]
	cmp r1, 0x1
	beq _080C9174
	cmp r1, 0x1
	bgt _080C9144
	cmp r1, 0
	beq _080C914E
	b _080C91D2
	.pool
_080C9144:
	cmp r1, 0x2
	beq _080C919C
	cmp r1, 0x3
	beq _080C91C2
	b _080C91D2
_080C914E:
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	bne _080C9168
	bl sub_80CADC4
	b _080C91B8
	.pool
_080C9168:
	ldr r0, =sub_80C96B8
	bl add_to_c3_somehow
	b _080C91D2
	.pool
_080C9174:
	movs r0, 0x2
	bl sub_80CFE54
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_80CFE08
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80D0E90
	b _080C91B8
	.pool
_080C919C:
	bl sub_80D1218
	lsls r0, 24
	cmp r0, 0
	bne _080C91D2
	movs r0, 0x3
	bl sub_80CFE54
	bl sub_80CADC4
	bl sub_80CE00C
	bl sub_80CA4FC
_080C91B8:
	ldr r1, [r5]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C91D2
_080C91C2:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C91D2
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C91D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9128

	thumb_func_start sub_80C91DC
sub_80C91DC: @ 80C91DC
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _080C928C
	lsls r0, 2
	ldr r1, =_080C91FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C91FC:
	.4byte _080C9264
	.4byte _080C9210
	.4byte _080C9238
	.4byte _080C9258
	.4byte _080C927C
_080C9210:
	movs r0, 0x2
	bl sub_80CFE54
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_80CFE08
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80D1080
	b _080C9268
	.pool
_080C9238:
	bl sub_80D1218
	lsls r0, 24
	cmp r0, 0
	bne _080C928C
	movs r0, 0
	bl sub_80CFE54
	bl sub_80CE00C
	bl sub_80CA4FC
	movs r0, 0x1C
	bl sub_80CAC58
	b _080C9268
_080C9258:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C928C
_080C9264:
	bl sub_80CADC4
_080C9268:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C928C
	.pool
_080C927C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C928C
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C928C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C91DC

	thumb_func_start sub_80C9298
sub_80C9298: @ 80C9298
	push {r4,r5,lr}
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x4
	bls _080C92A8
	b _080C93A2
_080C92A8:
	lsls r0, 2
	ldr r1, =_080C92BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C92BC:
	.4byte _080C92D0
	.4byte _080C9328
	.4byte _080C9348
	.4byte _080C938C
	.4byte _080C9374
_080C92D0:
	ldr r0, [r5]
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	bne _080C92FC
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x1A
	bl sub_80CAC58
	ldr r1, [r5]
	movs r0, 0x3
	strb r0, [r1]
	b _080C93A2
	.pool
_080C92FC:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_80CFE08
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80D1114
	ldr r1, [r5]
	movs r0, 0x1
	strb r0, [r1]
	b _080C93A2
	.pool
_080C9328:
	bl sub_80D1218
	lsls r0, 24
	cmp r0, 0
	bne _080C93A2
	movs r0, 0x19
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1]
	b _080C93A2
	.pool
_080C9348:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C93A2
	bl sub_80CADC4
	bl sub_80CE00C
	bl sub_80CA4FC
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x4
	strb r0, [r1]
	b _080C93A2
	.pool
_080C9374:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C93A2
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C93A2
	.pool
_080C938C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C93A2
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C93A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9298

	thumb_func_start sub_80C93B0
sub_80C93B0: @ 80C93B0
	push {r4,lr}
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _080C948C
	lsls r0, 2
	ldr r1, =_080C93D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C93D0:
	.4byte _080C93E4
	.4byte _080C9410
	.4byte _080C9438
	.4byte _080C9458
	.4byte _080C947C
_080C93E4:
	ldr r0, [r4]
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	bne _080C9404
	bl sub_80CADC4
	ldr r1, [r4]
	b _080C946C
	.pool
_080C9404:
	ldr r0, =sub_80C96B8
	bl add_to_c3_somehow
	b _080C948C
	.pool
_080C9410:
	movs r0, 0x2
	bl sub_80CFE54
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_80CFE08
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80D0FAC
	b _080C9468
	.pool
_080C9438:
	bl sub_80D1218
	lsls r0, 24
	cmp r0, 0
	bne _080C948C
	movs r0, 0x3
	bl sub_80CFE54
	bl sub_80CE00C
	bl sub_80CA4FC
	movs r0, 0x1D
	bl sub_80CAC58
	b _080C9468
_080C9458:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C948C
	bl sub_80CADC4
_080C9468:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
_080C946C:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C948C
	.pool
_080C947C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C948C
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C948C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C93B0

	thumb_func_start sub_80C9498
sub_80C9498: @ 80C9498
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x6
	bhi _080C9544
	lsls r0, 2
	ldr r1, =_080C94B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C94B8:
	.4byte _080C94D4
	.4byte _080C94DA
	.4byte _080C94F4
	.4byte _080C94FA
	.4byte _080C9500
	.4byte _080C9518
	.4byte _080C9534
_080C94D4:
	bl sub_80CADC4
	b _080C9522
_080C94DA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C9544
	movs r0, 0x6
	bl PlaySE
	bl sub_80D17B4
	bl sub_80D1818
	b _080C9522
_080C94F4:
	bl sub_80D184C
	b _080C951C
_080C94FA:
	bl IsDma3ManagerBusyWithBgCopy
	b _080C951C
_080C9500:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9544
	movs r0, 0x6
	bl PlaySE
	b _080C9522
	.pool
_080C9518:
	bl sub_80D18E4
_080C951C:
	lsls r0, 24
	cmp r0, 0
	bne _080C9544
_080C9522:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9544
	.pool
_080C9534:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C9544
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C9544:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9498

	thumb_func_start sub_80C954C
sub_80C954C: @ 80C954C
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x5
	bls _080C955A
	b _080C9664
_080C955A:
	lsls r0, 2
	ldr r1, =_080C956C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C956C:
	.4byte _080C9584
	.4byte _080C95A4
	.4byte _080C9602
	.4byte _080C9624
	.4byte _080C9638
	.4byte _080C9654
_080C9584:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1B
	bl sub_80CAC58
	movs r0, 0
	bl sub_80CAD9C
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1]
	b _080C9664
	.pool
_080C95A4:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080C95C8
	cmp r1, 0
	bgt _080C95BE
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080C95C2
	b _080C9664
_080C95BE:
	cmp r1, 0x1
	bne _080C9664
_080C95C2:
	bl sub_80CADC4
	b _080C9648
_080C95C8:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00002234
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080C95F4
	bl sub_80CADC4
	ldr r1, [r4]
	movs r0, 0x3
	strb r0, [r1]
	b _080C9664
	.pool
_080C95F4:
	movs r0, 0x1A
	bl sub_80CAC58
	ldr r1, [r4]
	movs r0, 0x2
	strb r0, [r1]
	b _080C9664
_080C9602:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9664
	bl sub_80CADC4
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x5
	strb r0, [r1]
	b _080C9664
	.pool
_080C9624:
	bl sub_80D1194
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x4
	strb r0, [r1]
	b _080C9664
	.pool
_080C9638:
	bl sub_80D1218
	lsls r0, 24
	cmp r0, 0
	bne _080C9664
	movs r0, 0
	bl sub_80CFE54
_080C9648:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C9664
	.pool
_080C9654:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C9664
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C9664:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C954C

	thumb_func_start sub_80C9670
sub_80C9670: @ 80C9670
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C9688
	cmp r0, 0x1
	beq _080C969A
	b _080C96AE
	.pool
_080C9688:
	bl CompactPartySlots
	bl sub_80CB950
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C96AE
_080C969A:
	bl sub_80CB9BC
	lsls r0, 24
	cmp r0, 0
	bne _080C96AE
	bl sub_80CAB20
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C96AE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9670

	thumb_func_start sub_80C96B8
sub_80C96B8: @ 80C96B8
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C96E6
	cmp r0, 0x1
	bgt _080C96D4
	cmp r0, 0
	beq _080C96DE
	b _080C9720
	.pool
_080C96D4:
	cmp r0, 0x2
	beq _080C96F2
	cmp r0, 0x3
	beq _080C9710
	b _080C9720
_080C96DE:
	movs r0, 0x1E
	bl sub_80CAC58
	b _080C9702
_080C96E6:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C9720
	b _080C9702
_080C96F2:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9720
	bl sub_80CADC4
_080C9702:
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9720
	.pool
_080C9710:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C9720
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C9720:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C96B8

	thumb_func_start box_related
box_related: @ 80C972C
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C9762
	cmp r0, 0x1
	bgt _080C9748
	cmp r0, 0
	beq _080C974E
	b _080C9818
	.pool
_080C9748:
	cmp r0, 0x2
	beq _080C9774
	b _080C9818
_080C974E:
	movs r0, 0x1
	bl sub_80CAC58
	bl sub_80CFFD0
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9818
_080C9762:
	bl sub_80D00A8
	lsls r0, 24
	cmp r0, 0
	bne _080C9818
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C9774:
	bl sub_80D00AC
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080C9818
	lsls r0, 2
	ldr r1, =_080C9790
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C9790:
	.4byte _080C97C4
	.4byte _080C97C4
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9818
	.4byte _080C9808
	.4byte _080C97F0
	.4byte _080C97DC
_080C97C4:
	movs r0, 0x1
	bl sub_80CD1A8
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C9818
	.pool
_080C97DC:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_80C9AC8
	bl add_to_c3_somehow
	b _080C9818
	.pool
_080C97F0:
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =sub_80C9824
	bl add_to_c3_somehow
	b _080C9818
	.pool
_080C9808:
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r0, =sub_80C99D8
	bl add_to_c3_somehow
_080C9818:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end box_related

	thumb_func_start sub_80C9824
sub_80C9824: @ 80C9824
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x6
	bls _080C9832
	b _080C99CC
_080C9832:
	lsls r0, 2
	ldr r1, =_080C9844
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C9844:
	.4byte _080C9860
	.4byte _080C9878
	.4byte _080C9894
	.4byte _080C990C
	.4byte _080C993C
	.4byte _080C9990
	.4byte _080C99AC
_080C9860:
	bl sub_80CADD8
	movs r0, 0x2
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C99CA
	.pool
_080C9878:
	bl sub_80D00A8
	lsls r0, 24
	cmp r0, 0
	beq _080C9884
	b _080C99CC
_080C9884:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C99CA
	.pool
_080C9894:
	bl sub_80D00AC
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r5, =0x0000078e
	adds r1, r5
	strh r0, [r1]
	movs r0, 0
	ldrsh r1, [r1, r0]
	cmp r1, 0x15
	bgt _080C98C0
	cmp r1, 0x12
	bge _080C98D2
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080C98C6
	b _080C99CC
	.pool
_080C98C0:
	cmp r1, 0x16
	beq _080C98EC
	b _080C99CC
_080C98C6:
	movs r0, 0x1
	bl sub_80CD1A8
	bl sub_80CADC4
	b _080C99A0
_080C98D2:
	movs r0, 0x5
	bl PlaySE
	bl sub_80D013C
	ldr r1, [r4]
	adds r2, r1, r5
	ldrh r0, [r2]
	subs r0, 0x12
	strh r0, [r2]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C99CA
_080C98EC:
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r4]
	movs r1, 0xF2
	lsls r1, 3
	adds r0, r1
	movs r1, 0x10
	strh r1, [r0]
	bl sub_80D013C
	bl sub_80CADC4
	ldr r1, [r4]
	movs r0, 0x6
	b _080C99CA
_080C990C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C99CC
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x0000078e
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80CAE0C
	movs r0, 0x3
	bl sub_80CAC58
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C99CA
	.pool
_080C993C:
	bl sub_80D00AC
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	movs r5, 0xF2
	lsls r5, 3
	adds r1, r5
	strh r0, [r1]
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _080C99CC
	adds r0, 0x1
	cmp r1, r0
	bne _080C996C
	bl sub_80CADC4
	ldr r1, [r4]
	movs r0, 0
	b _080C99CA
	.pool
_080C996C:
	movs r0, 0x5
	bl PlaySE
	bl sub_80CADC4
	ldr r1, [r4]
	adds r1, r5
	ldrh r0, [r1]
	subs r0, 0x17
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80CC680
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	b _080C99CA
_080C9990:
	bl sub_80CC6B0
	lsls r0, 24
	cmp r0, 0
	bne _080C99CC
	movs r0, 0x1
	bl sub_80CD1A8
_080C99A0:
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C99CC
	.pool
_080C99AC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080C99CC
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	movs r1, 0xF2
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80CC680
	ldr r1, [r4]
	movs r0, 0x5
_080C99CA:
	strb r0, [r1]
_080C99CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9824

	thumb_func_start sub_80C99D8
sub_80C99D8: @ 80C99D8
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldrb r4, [r0]
	cmp r4, 0x1
	beq _080C9A2C
	cmp r4, 0x1
	bgt _080C99F4
	cmp r4, 0
	beq _080C99FE
	b _080C9AB8
	.pool
_080C99F4:
	cmp r4, 0x2
	beq _080C9A84
	cmp r4, 0x3
	beq _080C9A9C
	b _080C9AB8
_080C99FE:
	movs r0, 0x5
	bl sub_80CAC58
	ldr r0, [r5]
	ldr r1, =0x00001e5c
	adds r0, r1
	ldr r2, =0x0000dac7
	str r4, [sp]
	movs r1, 0xA
	movs r3, 0x3
	bl sub_80C77E8
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	bl sub_80C78D4
	b _080C9A8E
	.pool
_080C9A2C:
	bl sub_80C78F0
	ldr r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x000002ca
	adds r1, r2
	strh r0, [r1]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xC8
	beq _080C9AB8
	bl sub_80CADC4
	bl sub_80C78E4
	bl sub_80C7890
	ldr r0, [r5]
	ldr r2, =0x000002ca
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xC9
	beq _080C9A6C
	adds r4, r0, 0
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080C9A8E
_080C9A6C:
	movs r0, 0x1
	bl sub_80CD1A8
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C9AB8
	.pool
_080C9A84:
	ldr r1, =0x000002ca
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80CC464
_080C9A8E:
	ldr r1, [r5]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9AB8
	.pool
_080C9A9C:
	bl sub_80CC54C
	lsls r0, 24
	cmp r0, 0
	bne _080C9AB8
	ldr r0, [r5]
	ldr r2, =0x000002ca
	adds r0, r2
	ldrb r0, [r0]
	bl sub_80D1D18
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
_080C9AB8:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C99D8

	thumb_func_start sub_80C9AC8
sub_80C9AC8: @ 80C9AC8
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldrb r4, [r0]
	cmp r4, 0
	beq _080C9AE0
	cmp r4, 0x1
	beq _080C9AFE
	b _080C9B18
	.pool
_080C9AE0:
	bl sub_80CE760
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r5]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9B18
_080C9AFE:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C9B18
	ldr r0, =gUnknown_02039D0F
	strb r4, [r0]
	ldr r1, [r5]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	ldr r0, =sub_80C9E50
	bl add_to_c3_somehow
_080C9B18:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9AC8

	thumb_func_start sub_80C9B28
sub_80C9B28: @ 80C9B28
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldrb r4, [r0]
	cmp r4, 0
	beq _080C9B40
	cmp r4, 0x1
	beq _080C9B5E
	b _080C9B78
	.pool
_080C9B40:
	bl sub_80CE7E8
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r5]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9B78
_080C9B5E:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080C9B78
	ldr r0, =gUnknown_02039D0F
	strb r1, [r0]
	ldr r0, [r5]
	strb r4, [r0, 0x2]
	ldr r0, =sub_80C9E50
	bl add_to_c3_somehow
_080C9B78:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9B28

	thumb_func_start sub_80C9B88
sub_80C9B88: @ 80C9B88
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldrb r1, [r0]
	cmp r1, 0
	beq _080C9BA0
	cmp r1, 0x1
	beq _080C9BBA
	b _080C9BD6
	.pool
_080C9BA0:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9BD6
_080C9BBA:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C9BD6
	ldr r1, =gUnknown_02039D0F
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, [r4]
	movs r0, 0x3
	strb r0, [r1, 0x2]
	ldr r0, =sub_80C9E50
	bl add_to_c3_somehow
_080C9BD6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9B88

	thumb_func_start sub_80C9BE8
sub_80C9BE8: @ 80C9BE8
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _080C9BF6
	b _080C9D08
_080C9BF6:
	lsls r0, 2
	ldr r1, =_080C9C08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C9C08:
	.4byte _080C9C1C
	.4byte _080C9C78
	.4byte _080C9C8C
	.4byte _080C9CC8
	.4byte _080C9CE4
_080C9C1C:
	bl sub_80CEAD0
	lsls r0, 24
	cmp r0, 0
	beq _080C9C40
	movs r0, 0x20
	bl PlaySE
	movs r0, 0xF
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1]
	b _080C9D08
	.pool
_080C9C40:
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	beq _080C9C58
	ldr r0, =sub_80C954C
	bl add_to_c3_somehow
	b _080C9D08
	.pool
_080C9C58:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_80CAC58
	movs r0, 0
	bl sub_80CAD9C
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1]
	b _080C9D08
	.pool
_080C9C78:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9D08
	b _080C9CAA
	.pool
_080C9C8C:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080C9CBC
	cmp r1, 0
	bgt _080C9CA6
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080C9CAA
	b _080C9D08
_080C9CA6:
	cmp r1, 0x1
	bne _080C9D08
_080C9CAA:
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C9D08
	.pool
_080C9CBC:
	movs r0, 0x3
	bl PlaySE
	bl sub_80CADC4
	b _080C9CD2
_080C9CC8:
	movs r0, 0x14
	movs r1, 0
	movs r2, 0x1
	bl sub_80F9BF4
_080C9CD2:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9D08
	.pool
_080C9CE4:
	bl sub_80F9C30
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080C9D08
	bl sub_80CABE0
	bl CalculatePlayerPartyCount
	ldr r1, =gPlayerPartyCount
	strb r0, [r1]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	strb r4, [r0, 0x2]
	ldr r0, =sub_80C9E50
	bl add_to_c3_somehow
_080C9D08:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9BE8

	thumb_func_start sub_80C9D1C
sub_80C9D1C: @ 80C9D1C
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _080C9D2A
	b _080C9E3C
_080C9D2A:
	lsls r0, 2
	ldr r1, =_080C9D3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C9D3C:
	.4byte _080C9D50
	.4byte _080C9DAC
	.4byte _080C9DC0
	.4byte _080C9DFC
	.4byte _080C9E18
_080C9D50:
	bl sub_80CEAD0
	lsls r0, 24
	cmp r0, 0
	beq _080C9D74
	movs r0, 0x20
	bl PlaySE
	movs r0, 0xF
	bl sub_80CAC58
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1]
	b _080C9E3C
	.pool
_080C9D74:
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	beq _080C9D8C
	ldr r0, =sub_80C954C
	bl add_to_c3_somehow
	b _080C9E3C
	.pool
_080C9D8C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x12
	bl sub_80CAC58
	movs r0, 0
	bl sub_80CAD9C
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1]
	b _080C9E3C
	.pool
_080C9DAC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF3
	ands r0, r1
	cmp r0, 0
	beq _080C9E3C
	b _080C9DE0
	.pool
_080C9DC0:
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080C9DE0
	cmp r1, 0
	bgt _080C9DDA
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080C9DF0
	b _080C9E3C
_080C9DDA:
	cmp r1, 0x1
	beq _080C9DF0
	b _080C9E3C
_080C9DE0:
	bl sub_80CADC4
	ldr r0, =task_pokemon_box_related
	bl add_to_c3_somehow
	b _080C9E3C
	.pool
_080C9DF0:
	movs r0, 0x3
	bl PlaySE
	bl sub_80CADC4
	b _080C9E06
_080C9DFC:
	movs r0, 0x14
	movs r1, 0
	movs r2, 0
	bl sub_80F9BF4
_080C9E06:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C9E3C
	.pool
_080C9E18:
	bl sub_80F9C30
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080C9E3C
	bl sub_80CABE0
	bl CalculatePlayerPartyCount
	ldr r1, =gPlayerPartyCount
	strb r0, [r1]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	strb r4, [r0, 0x2]
	ldr r0, =sub_80C9E50
	bl add_to_c3_somehow
_080C9E3C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9D1C

	thumb_func_start sub_80C9E50
sub_80C9E50: @ 80C9E50
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r4, [r0, 0x2]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080C9E88
	bl sub_80D127C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080C9E88
	bl sub_80D12D4
	ldr r1, =gUnknown_02039D12
	b _080C9E8C
	.pool
_080C9E88:
	ldr r1, =gUnknown_02039D12
	movs r0, 0
_080C9E8C:
	strh r0, [r1]
	cmp r4, 0x1
	beq _080C9EB4
	cmp r4, 0x1
	ble _080C9E9E
	cmp r4, 0x2
	beq _080C9F1C
	cmp r4, 0x3
	beq _080C9F48
_080C9E9E:
	bl sub_80C9FC8
	ldr r0, =sub_80C7678
	bl SetMainCallback2
	b _080C9F56
	.pool
_080C9EB4:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x0000218c
	adds r0, r1, r2
	ldr r4, [r0]
	subs r2, 0x5
	adds r0, r1, r2
	ldrb r7, [r0]
	subs r2, 0x1
	adds r0, r1, r2
	ldrb r6, [r0]
	ldr r0, =0x00002188
	adds r1, r0
	ldrb r5, [r1]
	bl sub_80C9FC8
	cmp r5, 0
	bne _080C9F04
	ldr r0, =gUnknown_02039D14
	cmp r4, r0
	bne _080C9F04
	ldr r0, =c2_808CE60
	str r0, [sp]
	movs r0, 0
	adds r1, r4, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_81BFA80
	b _080C9F56
	.pool
_080C9F04:
	ldr r0, =c2_808CE60
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_81BF8EC
	b _080C9F56
	.pool
_080C9F1C:
	bl sub_80C9FC8
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	bl GetBoxNamePtr
	adds r1, r0, 0
	movs r0, 0
	str r0, [sp]
	ldr r0, =c2_808CE60
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl DoNamingScreen
	b _080C9F56
	.pool
_080C9F48:
	bl sub_80C9FC8
	ldr r2, =c2_808CE60
	movs r0, 0xB
	movs r1, 0
	bl GoToBagMenu
_080C9F56:
	mov r0, r8
	bl DestroyTask
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9E50

	thumb_func_start sub_80C9F6C
sub_80C9F6C: @ 80C9F6C
	push {lr}
	sub sp, 0x4
	ldr r0, =gSpecialVar_ItemId
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	cmp r1, 0
	beq _080C9FC0
	bl sub_80CFE08
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C9FAC
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	b _080C9FB6
	.pool
_080C9FAC:
	adds r0, r1, 0
	movs r1, 0xC
	mov r2, sp
	bl SetBoxMonDataFromSelectedBox
_080C9FB6:
	mov r0, sp
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
_080C9FC0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80C9F6C

	thumb_func_start sub_80C9FC8
sub_80C9FC8: @ 80C9FC8
	push {r4,lr}
	bl sub_80D25F0
	bl sub_80D01B8
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	bl FreeAllWindowBuffers
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9FC8

	thumb_func_start sub_80C9FEC
sub_80C9FEC: @ 80C9FEC
	push {lr}
	sub sp, 0x4
	ldr r1, =0x00001f0f
	movs r0, 0xE
	bl SetGpuReg
	ldr r1, =gUnknown_085720DC
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r0, =gUnknown_08572174
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C9FEC

	thumb_func_start sub_80CA028
sub_80CA028: @ 80CA028
	push {lr}
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x2
	bl ChangeBgY
	pop {r0}
	bx r0
	thumb_func_end sub_80CA028

	thumb_func_start sub_80CA044
sub_80CA044: @ 80CA044
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_08572734
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r1, =gPSSMenu_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r0, =gUnknown_085722A0
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldr r4, =0x00005ac4
	adds r1, r4
	bl LZ77UnCompWram
	ldr r1, [r5]
	adds r1, r4
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA044

	thumb_func_start sub_80CA0A4
sub_80CA0A4: @ 80CA0A4
	push {lr}
	ldr r0, =gUnknown_08572714
	bl InitWindows
	lsls r0, 16
	cmp r0, 0
	beq _080CA0C0
	bl DeactivateAllTextPrinters
	movs r0, 0x1
	b _080CA0C2
	.pool
_080CA0C0:
	movs r0, 0
_080CA0C2:
	pop {r1}
	bx r1
	thumb_func_end sub_80CA0A4

	thumb_func_start sub_80CA0C8
sub_80CA0C8: @ 80CA0C8
	push {lr}
	ldr r0, =gWaveformSpritePalette
	bl LoadSpritePalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA0C8

	thumb_func_start sub_80CA0D8
sub_80CA0D8: @ 80CA0D8
	push {lr}
	ldr r0, =gUnknown_085723DC
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085723FC
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085726F4
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	beq _080CA124
	ldr r0, =gUnknown_0857241C
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	b _080CA12E
	.pool
_080CA124:
	ldr r0, =gUnknown_0857243C
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
_080CA12E:
	ldr r1, =0x00001e05
	movs r0, 0xA
	bl SetGpuReg
	bl sub_80CA318
	bl sub_80CA154
	bl sub_80CA1C4
	bl sub_80CA230
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA0D8

	thumb_func_start sub_80CA154
sub_80CA154: @ 80CA154
	push {r4,lr}
	ldr r1, =0x0000dac8
	movs r0, 0x10
	movs r2, 0
	bl sub_811FFB4
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r3, =0x00000d94
	adds r1, r3
	str r0, [r1]
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r0, [r4]
	adds r0, r3
	ldr r0, [r0]
	adds r0, 0x43
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0x28
	strh r1, [r2, 0x20]
	ldr r1, [r0]
	movs r0, 0x96
	strh r0, [r1, 0x22]
	movs r0, 0x10
	bl GetSpriteTileStartByTag
	ldr r1, [r4]
	movs r2, 0xDA
	lsls r2, 4
	adds r1, r2
	lsls r0, 16
	lsrs r0, 11
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA154

	thumb_func_start sub_80CA1C4
sub_80CA1C4: @ 80CA1C4
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gWaveformSpriteSheet
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	movs r4, 0
_080CA1DA:
	lsls r1, r4, 6
	subs r1, r4
	adds r1, 0x8
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_085728BC
	movs r2, 0x9
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D08
	ldr r2, [r1]
	lsls r1, r4, 2
	ldr r3, =0x00000d98
	adds r2, r3
	adds r2, r1
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _080CA1DA
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA1C4

	thumb_func_start sub_80CA230
sub_80CA230: @ 80CA230
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000ce4
	adds r0, r1, r2
	ldrh r0, [r0]
	subs r2, 0x4
	adds r1, r2
	ldr r1, [r1]
	bl sub_80CA44C
	bl sub_80CA4FC
	bl sub_80CA65C
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA230

	thumb_func_start BoxSetMosaic
BoxSetMosaic: @ 80CA260
	push {lr}
	bl sub_80CA230
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	movs r1, 0x89
	lsls r1, 6
	adds r0, r1
	ldr r2, [r0]
	cmp r2, 0
	beq _080CA2AC
	ldrb r0, [r2, 0x1]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r1, [r3]
	movs r0, 0x89
	lsls r0, 6
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0xA
	strh r0, [r2, 0x2E]
	ldr r2, [r1]
	movs r0, 0x1
	strh r0, [r2, 0x30]
	ldr r2, [r1]
	ldr r0, =BoxSetMosaic2
	str r0, [r2, 0x1C]
	ldr r0, [r1]
	ldrh r0, [r0, 0x2E]
	lsls r1, r0, 12
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
_080CA2AC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end BoxSetMosaic

	thumb_func_start sub_80CA2B8
sub_80CA2B8: @ 80CA2B8
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0x89
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsls r0, 27
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_80CA2B8

	thumb_func_start BoxSetMosaic2
BoxSetMosaic2: @ 80CA2D0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	subs r0, r1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bge _080CA2E6
	movs r0, 0
	strh r0, [r4, 0x2E]
_080CA2E6:
	ldrh r0, [r4, 0x2E]
	lsls r1, r0, 12
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080CA30E
	ldrb r0, [r4, 0x1]
	movs r1, 0x11
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080CA30E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BoxSetMosaic2

	thumb_func_start sub_80CA318
sub_80CA318: @ 80CA318
	push {r4-r7,lr}
	sub sp, 0x28
	ldr r0, =gUnknown_02039D08
	mov r12, r0
	ldr r1, [r0]
	ldr r4, =0x000022c4
	adds r0, r1, r4
	str r0, [sp, 0x18]
	add r3, sp, 0x18
	movs r0, 0x82
	lsls r0, 10
	str r0, [r3, 0x4]
	ldr r5, =0x00002244
	adds r1, r5
	str r1, [sp, 0x20]
	ldr r0, =0x0000dac6
	add r2, sp, 0x20
	str r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_08572754
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	movs r6, 0
	adds r7, r2, 0
	mov r5, r12
	movs r2, 0
	ldr r1, =0x000007ff
_080CA352:
	ldr r0, [r5]
	adds r0, r4
	adds r0, r6
	strb r2, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r1
	bls _080CA352
	movs r6, 0
	ldr r5, =gUnknown_02039D08
	ldr r4, =0x00002244
	movs r2, 0
_080CA36C:
	ldr r0, [r5]
	lsls r1, r6, 1
	adds r0, r4
	adds r0, r1
	strh r2, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0xF
	bls _080CA36C
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r6, 0x89
	lsls r6, 6
	adds r0, r6
	movs r1, 0
	str r1, [r0]
	adds r0, r3, 0
	bl LoadSpriteSheet
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _080CA420
	adds r0, r7, 0
	bl LoadSpritePalette
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _080CA420
	b _080CA40C
	.pool
_080CA3C4:
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	movs r7, 0x89
	lsls r7, 6
	adds r3, r2, r7
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	lsls r0, r4, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	ldr r3, =0x0000223a
	adds r1, r2, r3
	strh r0, [r1]
	ldr r6, =0x0000223c
	adds r2, r6
	lsls r0, r5, 5
	ldr r7, =0x06010000
	adds r0, r7
	str r0, [r2]
	b _080CA420
	.pool
_080CA40C:
	mov r0, sp
	movs r1, 0x28
	movs r2, 0x30
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	bne _080CA3C4
_080CA420:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0x89
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _080CA43C
	movs r0, 0x2
	bl FreeSpriteTilesByTag
	ldr r0, =0x0000dac6
	bl FreeSpritePaletteByTag
_080CA43C:
	add sp, 0x28
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA318

	thumb_func_start sub_80CA44C
sub_80CA44C: @ 80CA44C
	push {r4-r7,lr}
	sub sp, 0x4
	adds r3, r1, 0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r6, =gUnknown_02039D08
	ldr r2, [r6]
	movs r7, 0x89
	lsls r7, 6
	adds r0, r2, r7
	ldr r0, [r0]
	cmp r0, 0
	beq _080CA4F2
	cmp r4, 0
	beq _080CA4E8
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r5, =0x000022c4
	adds r1, r2, r5
	movs r2, 0x1
	str r2, [sp]
	adds r2, r4, 0
	bl LoadSpecialPokePic
	ldr r1, [r6]
	ldr r2, =0x00000cdc
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r4, =0x00002244
	adds r1, r4
	bl LZ77UnCompWram
	ldr r0, [r6]
	adds r5, r0, r5
	ldr r1, =0x0000223c
	adds r0, r1
	ldr r1, [r0]
	ldr r2, =0x04000200
	adds r0, r5, 0
	bl CpuSet
	ldr r0, [r6]
	adds r4, r0, r4
	ldr r2, =0x0000223a
	adds r0, r2
	ldrh r1, [r0]
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, [r6]
	adds r0, r7
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	b _080CA4F2
	.pool
_080CA4E8:
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080CA4F2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80CA44C

	thumb_func_start sub_80CA4FC
sub_80CA4FC: @ 80CA4FC
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r6, =gUnknown_02039D08
	ldr r2, [r6]
	ldrb r0, [r2, 0x1]
	cmp r0, 0x3
	beq _080CA588
	ldr r0, =0x00000cf9
	adds r2, r0
	movs r4, 0
	str r4, [sp]
	movs r5, 0xFF
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x6
	bl PrintTextOnWindow
	ldr r2, [r6]
	ldr r1, =0x00000d1d
	adds r2, r1
	movs r0, 0xF
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r3, 0x6
	bl PrintTextOnWindow
	ldr r2, [r6]
	ldr r0, =0x00000d41
	adds r2, r0
	movs r0, 0x1D
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r3, 0xA
	bl PrintTextOnWindow
	ldr r2, [r6]
	ldr r1, =0x00000d65
	adds r2, r1
	movs r0, 0x2B
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r3, 0x6
	bl PrintTextOnWindow
	b _080CA5E8
	.pool
_080CA588:
	ldr r0, =0x00000d65
	adds r2, r0
	movs r4, 0
	str r4, [sp]
	movs r5, 0xFF
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r3, 0x6
	bl PrintTextOnWindow
	ldr r2, [r6]
	ldr r1, =0x00000cf9
	adds r2, r1
	movs r0, 0xD
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x6
	bl PrintTextOnWindow
	ldr r2, [r6]
	ldr r0, =0x00000d1d
	adds r2, r0
	movs r0, 0x1C
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r3, 0x6
	bl PrintTextOnWindow
	ldr r2, [r6]
	ldr r1, =0x00000d41
	adds r2, r1
	movs r0, 0x2A
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r3, 0xA
	bl PrintTextOnWindow
_080CA5E8:
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r2, =0x00000ce4
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	beq _080CA640
	adds r2, 0x7
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0xB5
	adds r1, r2
	ldr r1, [r1]
	bl sub_8120084
	ldr r0, [r4]
	ldr r1, =0x00000d94
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	b _080CA64E
	.pool
_080CA640:
	ldr r2, =0x00000d94
	adds r0, r1, r2
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
_080CA64E:
	strb r0, [r1]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA4FC

	thumb_func_start sub_80CA65C
sub_80CA65C: @ 80CA65C
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000ce4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080CA6B4
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x8
	bl sub_80D27AC
	movs r4, 0
_080CA680:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, =0x00000d98
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAnimIfDifferent
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _080CA680
	b _080CA6E6
	.pool
_080CA6B4:
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x8
	bl sub_80D27AC
	movs r4, 0
_080CA6C6:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, =0x00000d98
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	lsls r1, r4, 25
	lsrs r1, 24
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _080CA6C6
_080CA6E6:
	movs r0, 0
	bl sub_80D2918
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA65C

	thumb_func_start sub_80CA704
sub_80CA704: @ 80CA704
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_08DD36C8
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	adds r1, 0xB0
	bl LZ77UnCompWram
	ldr r0, =gPSSMenu_Pal
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	ldr r2, [r4]
	adds r2, 0xB0
	movs r0, 0x16
	str r0, [sp]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0xC
	bl sub_80D2644
	ldr r2, =gUnknown_0857245C
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x9
	bl sub_80D2644
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0
	bl sub_80D2770
	movs r0, 0x2
	movs r1, 0x15
	movs r2, 0
	bl sub_80D2770
	bl sub_80CAA74
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CA790
	movs r0, 0x1
	bl sub_80CA984
	movs r0, 0x1
	bl sub_80CB7E8
	movs r0, 0x2
	bl sub_80D2918
	movs r0, 0x1
	bl sub_80D2918
	b _080CA7B2
	.pool
_080CA790:
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x14
	movs r3, 0xC
	bl sub_80D27AC
	movs r0, 0x1
	bl sub_80CA984
	movs r0, 0x1
	bl sub_80D2918
	movs r0, 0x2
	bl sub_80D2918
_080CA7B2:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000002c7
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA704

	thumb_func_start sub_80CA7D4
sub_80CA7D4: @ 80CA7D4
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r0, 0xB0
	lsls r0, 2
	adds r2, r1, r0
	movs r3, 0
	movs r0, 0x14
	strh r0, [r2]
	ldr r0, =0x000002c2
	adds r2, r1, r0
	movs r0, 0x2
	strh r0, [r2]
	ldr r0, =0x000002c5
	adds r1, r0
	strb r3, [r1]
	movs r0, 0
	bl sub_80CB7E8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA7D4

	thumb_func_start sub_80CA80C
sub_80CA80C: @ 80CA80C
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	ldr r1, =0x000002c5
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x14
	beq _080CA87A
	movs r0, 0xB0
	lsls r0, 2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldr r0, =0x000002c2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_80D27F4
	movs r0, 0x1
	bl sub_80D2918
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x8
	bl sub_80CBAF0
	ldr r1, [r4]
	ldr r0, =0x000002c5
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x14
	beq _080CA874
	movs r0, 0x1
	b _080CA87C
	.pool
_080CA874:
	ldr r1, =gUnknown_02039D0C
	movs r0, 0x1
	strb r0, [r1]
_080CA87A:
	movs r0, 0
_080CA87C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CA80C

	thumb_func_start sub_80CA888
sub_80CA888: @ 80CA888
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	movs r0, 0xB0
	lsls r0, 2
	adds r2, r1, r0
	movs r3, 0
	movs r0, 0
	strh r0, [r2]
	ldr r0, =0x000002c2
	adds r2, r1, r0
	movs r0, 0x16
	strh r0, [r2]
	ldr r0, =0x000002c5
	adds r1, r0
	strb r3, [r1]
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080CA8B4
	bl sub_80D11CC
_080CA8B4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA888

	thumb_func_start sub_80CA8C8
sub_80CA8C8: @ 80CA8C8
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, =gUnknown_02039D08
	ldr r2, [r5]
	ldr r1, =0x000002c5
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x14
	beq _080CA974
	movs r0, 0xB0
	lsls r0, 2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r4, =0x000002c2
	adds r1, r2, r4
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	movs r1, 0x3
	bl sub_80D27F4
	movs r0, 0x1
	bl sub_80D2918
	movs r1, 0x80
	lsls r1, 1
	ldr r0, [r5]
	adds r0, r4
	ldrb r3, [r0]
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r2, 0xA
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x8
	negs r0, r0
	bl sub_80CBAF0
	ldr r1, [r5]
	ldr r0, =0x000002c5
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x14
	beq _080CA94C
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	b _080CA976
	.pool
_080CA94C:
	ldr r0, =gUnknown_02039D0C
	movs r1, 0
	strb r1, [r0]
	bl sub_80CBB9C
	bl CompactPartySlots
	movs r0, 0x2
	str r0, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x9
	bl sub_80D27AC
	movs r0, 0x2
	bl sub_80D2918
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_080CA974:
	movs r0, 0
_080CA976:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CA8C8

	thumb_func_start sub_80CA984
sub_80CA984: @ 80CA984
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	beq _080CA99E
	movs r0, 0x2
	str r0, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x9
	bl sub_80D27AC
	b _080CA9AC
_080CA99E:
	movs r0, 0x2
	str r0, [sp]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x9
	bl sub_80D27AC
_080CA9AC:
	movs r0, 0x2
	bl sub_80D2918
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80CA984

	thumb_func_start sub_80CA9C0
sub_80CA9C0: @ 80CA9C0
	ldr r2, =gUnknown_02039D08
	ldr r0, [r2]
	ldr r1, =0x000002c7
	adds r0, r1
	movs r3, 0x1
	strb r3, [r0]
	ldr r0, [r2]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0x1E
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x000002c9
	adds r0, r1
	strb r3, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CA9C0

	thumb_func_start sub_80CA9EC
sub_80CA9EC: @ 80CA9EC
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x000002c7
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080CAA06
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	bl sub_80CA984
_080CAA06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CA9EC

	thumb_func_start sub_80CAA14
sub_80CAA14: @ 80CAA14
	push {r4,lr}
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	ldr r2, =0x000002c7
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CAA60
	movs r0, 0xB2
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1E
	bls _080CAA60
	ldr r0, [r3]
	movs r1, 0xB2
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r3]
	movs r2, 0
	ldr r4, =0x000002c9
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0
	bne _080CAA54
	movs r2, 0x1
_080CAA54:
	strb r2, [r1]
	ldr r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80CA984
_080CAA60:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAA14

	thumb_func_start sub_80CAA74
sub_80CAA74: @ 80CAA74
	push {r4,lr}
	movs r4, 0x1
_080CAA78:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	adds r0, r4, 0
	bl sub_80CAAA8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _080CAA78
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAA74

	thumb_func_start sub_80CAAA8
sub_80CAAA8: @ 80CAAA8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r7, =gUnknown_085724BC
	cmp r1, 0
	beq _080CAAB8
	ldr r7, =gUnknown_085724A4
_080CAAB8:
	subs r0, 0x1
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 18
	movs r1, 0xE0
	lsls r1, 11
	adds r0, r1
	lsrs r3, r0, 16
	movs r0, 0
	ldr r1, =gUnknown_02039D08
	mov r12, r1
_080CAAD4:
	movs r2, 0
	adds r4, r7, 0
	adds r4, 0x8
	adds r5, r3, 0
	adds r5, 0xC
	adds r6, r0, 0x1
_080CAAE0:
	mov r0, r12
	ldr r1, [r0]
	adds r0, r3, r2
	lsls r0, 1
	adds r1, 0xB0
	adds r1, r0
	lsls r0, r2, 1
	adds r0, r7
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x3
	bls _080CAAE0
	adds r7, r4, 0
	lsls r0, r5, 16
	lsrs r3, r0, 16
	lsls r0, r6, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080CAAD4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAAA8

	thumb_func_start sub_80CAB20
sub_80CAB20: @ 80CAB20
	push {lr}
	sub sp, 0x4
	bl sub_80CAA74
	movs r0, 0x16
	str r0, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl sub_80D27AC
	movs r0, 0x1
	bl sub_80D2918
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80CAB20

	thumb_func_start sub_80CAB4C
sub_80CAB4C: @ 80CAB4C
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000002c6
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x6
	bl PlaySE
	bl sub_80CA7D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAB4C

	thumb_func_start sub_80CAB70
sub_80CAB70: @ 80CAB70
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r5, =0x000002c6
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CABAA
	cmp r0, 0x1
	bgt _080CAB94
	cmp r0, 0
	beq _080CAB9A
	b _080CABD8
	.pool
_080CAB94:
	cmp r0, 0x2
	beq _080CABD4
	b _080CABD8
_080CAB9A:
	bl sub_80CA80C
	lsls r0, 24
	cmp r0, 0
	bne _080CABD8
	bl sub_80CDBA0
	b _080CABC4
_080CABAA:
	bl sub_80CD554
	lsls r0, 24
	cmp r0, 0
	bne _080CABD8
	ldr r0, [r4]
	ldr r1, =0x00000cea
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CABC4
	bl BoxSetMosaic
_080CABC4:
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080CABD8
	.pool
_080CABD4:
	movs r0, 0
	b _080CABDA
_080CABD8:
	movs r0, 0x1
_080CABDA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80CAB70

	thumb_func_start sub_80CABE0
sub_80CABE0: @ 80CABE0
	push {r4,lr}
	ldr r4, =gUnknown_02039D10
	bl StorageGetCurrentBox
	ldrb r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	beq _080CAC0A
	ldr r0, =0x000008d7
	bl FlagClear
	ldr r4, =0x00004036
	bl StorageGetCurrentBox
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl VarSet
_080CAC0A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CABE0

	thumb_func_start sub_80CAC1C
sub_80CAC1C: @ 80CAC1C
	push {lr}
	sub sp, 0xC
	movs r1, 0xE8
	lsls r1, 5
	movs r0, 0x8
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0xD0
	bl sub_809882C
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_80CAC1C

	thumb_func_start sub_80CAC58
sub_80CAC58: @ 80CAC58
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	bl UnkTextUtil_Reset
	ldr r1, =gUnknown_0857276C
	lsls r0, r6, 3
	adds r0, r1
	ldrb r0, [r0, 0x4]
	cmp r0, 0x7
	bhi _080CAD30
	lsls r0, 2
	ldr r1, =_080CAC84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CAC84:
	.4byte _080CAD30
	.4byte _080CACA4
	.4byte _080CACA4
	.4byte _080CACA4
	.4byte _080CACB8
	.4byte _080CACB8
	.4byte _080CACB8
	.4byte _080CACD0
_080CACA4:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r0, =0x00000cee
	adds r1, r0
	b _080CACC0
	.pool
_080CACB8:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x000021e0
	adds r1, r2
_080CACC0:
	movs r0, 0
	bl UnkTextUtil_SetPtrI
	b _080CAD30
	.pool
_080CACD0:
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	beq _080CACF4
	ldr r0, =gUnknown_02039D08
	ldr r4, [r0]
	ldr r0, =0x000021eb
	adds r4, r0
	bl sub_80D12B8
	adds r1, r0, 0
	adds r0, r4, 0
	b _080CAD00
	.pool
_080CACF4:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x000021eb
	adds r0, r1, r2
	ldr r2, =0x00000d65
	adds r1, r2
_080CAD00:
	bl StringCopy
	adds r2, r0, 0
	b _080CAD16
	.pool
_080CAD14:
	adds r2, r1, 0
_080CAD16:
	subs r1, r2, 0x1
	ldrb r0, [r1]
	cmp r0, 0
	beq _080CAD14
	movs r0, 0xFF
	strb r0, [r2]
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r0, =0x000021eb
	adds r1, r0
	movs r0, 0
	bl UnkTextUtil_SetPtrI
_080CAD30:
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x00002190
	adds r0, r4
	ldr r2, =gUnknown_0857276C
	lsls r1, r6, 3
	adds r1, r2
	ldr r1, [r1]
	bl UnkTextUtil_StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, [r5]
	adds r2, r4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAC58

	thumb_func_start sub_80CAD9C
sub_80CAD9C: @ 80CAD9C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_08572864
	movs r1, 0xB
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	lsls r4, 24
	asrs r4, 24
	adds r0, r4, 0
	bl MoveMenuCursorNoWrapAround
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAD9C

	thumb_func_start sub_80CADC4
sub_80CADC4: @ 80CADC4
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl sub_8198070
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_80CADC4

	thumb_func_start sub_80CADD8
sub_80CADD8: @ 80CADD8
	push {lr}
	bl sub_80CFEF0
	movs r0, 0x12
	bl sub_80CFF34
	movs r0, 0x13
	bl sub_80CFF34
	movs r0, 0x14
	bl sub_80CFF34
	movs r0, 0x15
	bl sub_80CFF34
	bl IsWaldaWallpaperUnlocked
	cmp r0, 0
	beq _080CAE04
	movs r0, 0x16
	bl sub_80CFF34
_080CAE04:
	bl sub_80CFFD0
	pop {r0}
	bx r0
	thumb_func_end sub_80CADD8

	thumb_func_start sub_80CAE0C
sub_80CAE0C: @ 80CAE0C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl sub_80CFEF0
	cmp r4, 0x1
	beq _080CAE4A
	cmp r4, 0x1
	bgt _080CAE26
	cmp r4, 0
	beq _080CAE30
	b _080CAE96
_080CAE26:
	cmp r5, 0x2
	beq _080CAE64
	cmp r5, 0x3
	beq _080CAE7E
	b _080CAE96
_080CAE30:
	movs r0, 0x17
	bl sub_80CFF34
	movs r0, 0x18
	bl sub_80CFF34
	movs r0, 0x19
	bl sub_80CFF34
	movs r0, 0x1A
	bl sub_80CFF34
	b _080CAE96
_080CAE4A:
	movs r0, 0x1B
	bl sub_80CFF34
	movs r0, 0x1C
	bl sub_80CFF34
	movs r0, 0x1D
	bl sub_80CFF34
	movs r0, 0x1E
	bl sub_80CFF34
	b _080CAE96
_080CAE64:
	movs r0, 0x1F
	bl sub_80CFF34
	movs r0, 0x20
	bl sub_80CFF34
	movs r0, 0x21
	bl sub_80CFF34
	movs r0, 0x22
	bl sub_80CFF34
	b _080CAE96
_080CAE7E:
	movs r0, 0x23
	bl sub_80CFF34
	movs r0, 0x24
	bl sub_80CFF34
	movs r0, 0x25
	bl sub_80CFF34
	movs r0, 0x26
	bl sub_80CFF34
_080CAE96:
	bl sub_80CFFD0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80CAE0C

	thumb_func_start sub_80CAEA0
sub_80CAEA0: @ 80CAEA0
	ldr r0, =gUnknown_02039D0D
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CAEA0

	thumb_func_start sub_80CAEAC
sub_80CAEAC: @ 80CAEAC
	push {lr}
	bl sub_80CEADC
	lsls r0, 24
	cmp r0, 0
	bne _080CAEE8
	ldr r0, =gUnknown_02039D0C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CAED8
	bl sub_80CFE08
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	bl sub_80D0D8C
	b _080CAEE8
	.pool
_080CAED8:
	bl sub_80CFE08
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_80D0D8C
_080CAEE8:
	ldr r1, =gUnknown_02039D12
	ldrh r0, [r1]
	cmp r0, 0
	beq _080CAEFA
	bl sub_80D0F38
	movs r0, 0x3
	bl sub_80CFE54
_080CAEFA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAEAC

	thumb_func_start sub_80CAF04
sub_80CAF04: @ 80CAF04
	push {r4-r6,lr}
	bl sub_80D2F04
	movs r2, 0
	ldr r3, =gUnknown_02039D08
	ldr r5, =0x00000b08
	movs r4, 0
	adds r6, r3, 0
_080CAF14:
	ldr r0, [r3]
	lsls r1, r2, 1
	adds r0, r5
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x27
	bls _080CAF14
	movs r2, 0
	ldr r5, =gUnknown_02039D08
	ldr r4, =0x00000b58
	movs r3, 0
_080CAF30:
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r0, r4
	adds r0, r1
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x27
	bls _080CAF30
	movs r2, 0
	ldr r5, =gUnknown_02039D08
	movs r4, 0xA7
	lsls r4, 4
	movs r3, 0
_080CAF4E:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	str r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _080CAF4E
	movs r2, 0
	ldr r5, =gUnknown_02039D08
	ldr r4, =0x00000a88
	movs r3, 0
_080CAF6A:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	str r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x1D
	bls _080CAF6A
	ldr r0, [r6]
	ldr r2, =0x00000a6c
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r1, =0x0000078c
	adds r0, r1
	strh r2, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAF04

	thumb_func_start sub_80CAFAC
sub_80CAFAC: @ 80CAFAC
	push {lr}
	bl sub_80CEB24
	lsls r0, 24
	movs r1, 0x1
	cmp r0, 0
	beq _080CAFBC
	movs r1, 0x2
_080CAFBC:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80CAFAC

	thumb_func_start sub_80CAFC4
sub_80CAFC4: @ 80CAFC4
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x000020a4
	adds r0, r4
	movs r1, 0
	bl GetMonData
	adds r6, r0, 0
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x41
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_80CAFAC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_80CC230
	ldr r1, [r5]
	ldr r2, =0x00000a6c
	adds r1, r2
	str r0, [r1]
	ldr r1, =sub_80CC100
	str r1, [r0, 0x1C]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CAFC4

	thumb_func_start sub_80CB028
sub_80CB028: @ 80CB028
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	mov r8, r0
	movs r6, 0
	movs r7, 0
_080CB042:
	movs r5, 0
	adds r1, r7, 0x1
	mov r10, r1
_080CB048:
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0x41
	bl GetBoxMonDataFromAnyBox
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080CB0B0
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	bl GetBoxMonDataFromAnyBox
	adds r1, r0, 0
	lsls r2, r5, 1
	adds r2, r5
	lsls r2, 19
	movs r3, 0xC8
	lsls r3, 15
	adds r2, r3
	asrs r2, 16
	lsls r3, r7, 1
	adds r3, r7
	lsls r3, 19
	movs r0, 0xB0
	lsls r0, 14
	adds r3, r0
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0x13
	subs r0, r5
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	adds r0, r4, 0
	asrs r3, 16
	bl sub_80CC230
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	mov r3, r8
	lsls r2, r3, 2
	ldr r3, =0x00000a88
	adds r1, r3
	adds r1, r2
	str r0, [r1]
	b _080CB0C0
	.pool
_080CB0B0:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, =0x00000a88
	adds r0, r3
	adds r0, r1
	str r4, [r0]
_080CB0C0:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _080CB048
	mov r1, r10
	lsls r0, r1, 16
	lsrs r7, r0, 16
	cmp r7, 0x4
	bls _080CB042
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080CB126
	movs r6, 0
	movs r2, 0xD
	negs r2, r2
	adds r4, r2, 0
_080CB0F6:
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0xC
	bl GetBoxMonDataFromAnyBox
	cmp r0, 0
	bne _080CB11C
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, =0x00000a88
	adds r0, r3
	adds r0, r1
	ldr r2, [r0]
	ldrb r0, [r2, 0x1]
	ands r0, r4
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x1]
_080CB11C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1D
	bls _080CB0F6
_080CB126:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB028

	thumb_func_start sub_80CB140
sub_80CB140: @ 80CB140
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r7, 0
	movs r1, 0x41
	bl GetBoxMonDataFromSelectedBox
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	beq _080CB1DA
	adds r0, r7, 0
	movs r1, 0x6
	bl __umodsi3
	adds r6, r0, 0
	lsls r0, r6, 24
	lsrs r0, 24
	lsls r5, r0, 1
	adds r5, r0
	lsls r5, 19
	movs r0, 0xC8
	lsls r0, 15
	adds r5, r0
	lsrs r5, 16
	adds r0, r7, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 19
	movs r0, 0xB0
	lsls r0, 14
	adds r4, r0
	lsrs r4, 16
	adds r0, r7, 0
	movs r1, 0
	bl GetBoxMonDataFromSelectedBox
	adds r1, r0, 0
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0x13
	subs r0, r6
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	mov r0, r8
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80CC230
	adds r3, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	lsls r1, r7, 2
	ldr r4, =0x00000a88
	adds r0, r2, r4
	adds r0, r1
	str r3, [r0]
	ldrb r0, [r2, 0x1]
	cmp r0, 0x3
	bne _080CB1DA
	ldrb r0, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r3, 0x1]
_080CB1DA:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB140

	thumb_func_start sub_80CB1F0
sub_80CB1F0: @ 80CB1F0
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r7, =gUnknown_02039D08
	ldr r6, =0x00000a88
	movs r5, 0x1
	ldr r4, =sub_80CB278
_080CB200:
	ldr r0, [r7]
	lsls r1, r2, 2
	adds r0, r6
	adds r1, r0, r1
	ldr r0, [r1]
	cmp r0, 0
	beq _080CB218
	strh r3, [r0, 0x32]
	ldr r0, [r1]
	strh r5, [r0, 0x36]
	ldr r0, [r1]
	str r4, [r0, 0x1C]
_080CB218:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x1D
	bls _080CB200
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB1F0

	thumb_func_start sub_80CB234
sub_80CB234: @ 80CB234
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x30]
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _080CB250
	subs r0, r1, 0x1
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
	b _080CB266
_080CB250:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r3, =0x00000c66
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldrh r0, [r2, 0x34]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_080CB266:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB234

	thumb_func_start sub_80CB278
sub_80CB278: @ 80CB278
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x36]
	movs r3, 0x36
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _080CB28C
	subs r0, r1, 0x1
	strh r0, [r2, 0x36]
	b _080CB2A8
_080CB28C:
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x38]
	subs r0, 0x45
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB6
	bls _080CB2A8
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_080CB2A8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB278

	thumb_func_start sub_80CB2B0
sub_80CB2B0: @ 80CB2B0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r7, =gUnknown_02039D08
_080CB2BA:
	ldr r0, [r7]
	lsls r4, r5, 2
	ldr r1, =0x00000a88
	adds r0, r1
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080CB2DA
	bl sub_80CC314
	ldr r0, [r7]
	ldr r1, =0x00000a88
	adds r0, r1
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080CB2DA:
	adds r0, r5, 0x6
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x4
	bls _080CB2BA
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB2B0

	thumb_func_start sub_80CB2F8
sub_80CB2F8: @ 80CB2F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x8]
	lsls r2, 16
	movs r1, 0x2C
	mov r8, r1
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 19
	movs r3, 0xC8
	lsls r3, 15
	adds r1, r3
	lsrs r1, 16
	str r1, [sp, 0x10]
	ldr r1, [sp, 0x8]
	adds r1, 0x1
	lsrs r6, r2, 16
	str r6, [sp, 0xC]
	asrs r2, 16
	muls r1, r2
	ldr r2, [sp, 0x10]
	subs r1, r2, r1
	lsls r1, 16
	lsrs r2, r1, 16
	movs r1, 0x13
	subs r1, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x14]
	movs r3, 0
	mov r9, r3
	adds r5, r0, 0
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	beq _080CB3F0
	movs r7, 0x4
	lsls r2, 16
	mov r10, r2
_080CB358:
	ldr r6, =gUnknown_02039D08
	ldr r2, [r6]
	lsls r0, r5, 1
	ldr r3, =0x00000ba8
	adds r1, r2, r3
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080CB3C2
	lsls r4, r5, 2
	ldr r6, =0x00000be4
	adds r1, r2, r6
	adds r1, r4
	ldr r1, [r1]
	mov r2, r8
	lsls r3, r2, 16
	asrs r3, 16
	movs r2, 0x2
	str r2, [sp]
	ldr r6, [sp, 0x14]
	str r6, [sp, 0x4]
	mov r6, r10
	asrs r2, r6, 16
	bl sub_80CC230
	adds r2, r0, 0
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r3, =0x00000a88
	adds r0, r3
	adds r1, r0, r4
	str r2, [r1]
	cmp r2, 0
	beq _080CB3C2
	mov r6, sp
	ldrh r6, [r6, 0x8]
	strh r6, [r2, 0x30]
	ldr r0, [r1]
	mov r2, sp
	ldrh r2, [r2, 0xC]
	strh r2, [r0, 0x32]
	ldr r0, [r1]
	mov r3, sp
	ldrh r3, [r3, 0x10]
	strh r3, [r0, 0x34]
	ldr r1, [r1]
	ldr r0, =sub_80CB234
	str r0, [r1, 0x1C]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080CB3C2:
	adds r0, r5, 0x6
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	adds r0, 0x18
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	subs r7, 0x1
	cmp r7, 0
	bge _080CB358
	b _080CB4A6
	.pool
_080CB3F0:
	mov r10, r1
	movs r7, 0x4
	lsls r2, 16
	str r2, [sp, 0x18]
_080CB3F8:
	mov r6, r10
	ldr r2, [r6]
	lsls r0, r5, 1
	ldr r3, =0x00000ba8
	adds r1, r2, r3
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080CB490
	lsls r4, r5, 2
	ldr r6, =0x00000be4
	adds r1, r2, r6
	adds r1, r4
	ldr r1, [r1]
	mov r2, r8
	lsls r3, r2, 16
	asrs r3, 16
	movs r2, 0x2
	str r2, [sp]
	ldr r6, [sp, 0x14]
	str r6, [sp, 0x4]
	ldr r6, [sp, 0x18]
	asrs r2, r6, 16
	bl sub_80CC230
	adds r2, r0, 0
	mov r0, r10
	ldr r3, [r0]
	ldr r1, =0x00000a88
	adds r0, r3, r1
	adds r1, r0, r4
	str r2, [r1]
	cmp r2, 0
	beq _080CB490
	mov r6, sp
	ldrh r6, [r6, 0x8]
	strh r6, [r2, 0x30]
	ldr r0, [r1]
	mov r2, sp
	ldrh r2, [r2, 0xC]
	strh r2, [r0, 0x32]
	ldr r0, [r1]
	mov r6, sp
	ldrh r6, [r6, 0x10]
	strh r6, [r0, 0x34]
	ldr r1, [r1]
	ldr r0, =sub_80CB234
	str r0, [r1, 0x1C]
	ldr r1, =0x00000c5c
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r1, r5, 0
	movs r2, 0xC
	bl GetBoxMonDataFromAnyBox
	cmp r0, 0
	bne _080CB486
	mov r2, r10
	ldr r0, [r2]
	ldr r3, =0x00000a88
	adds r0, r3
	adds r0, r4
	ldr r2, [r0]
	ldrb r1, [r2, 0x1]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r2, 0x1]
_080CB486:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080CB490:
	adds r0, r5, 0x6
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	adds r0, 0x18
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	subs r7, 0x1
	cmp r7, 0
	bge _080CB3F8
_080CB4A6:
	mov r0, r9
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CB2F8

	thumb_func_start sub_80CB4CC
sub_80CB4CC: @ 80CB4CC
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gUnknown_02039D08
	ldr r1, [r6]
	ldr r2, =0x00000c6a
	adds r1, r2
	movs r5, 0
	strb r5, [r1]
	ldr r1, [r6]
	ldr r3, =0x00000c6b
	adds r1, r3
	strb r0, [r1]
	ldr r1, [r6]
	ldr r7, =0x00000c69
	adds r1, r7
	strb r4, [r1]
	ldr r3, [r6]
	movs r1, 0xC6
	lsls r1, 4
	adds r2, r3, r1
	movs r1, 0x20
	strh r1, [r2]
	lsls r4, 24
	asrs r4, 24
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 1
	negs r1, r1
	subs r7, 0x5
	adds r2, r3, r7
	strh r1, [r2]
	ldr r1, =0x00000c66
	adds r3, r1
	strh r5, [r3]
	bl sub_80CB6F0
	cmp r4, 0
	ble _080CB544
	ldr r0, [r6]
	ldr r2, =0x00000c68
	adds r0, r2
	movs r1, 0
	b _080CB54C
	.pool
_080CB544:
	ldr r0, [r6]
	ldr r3, =0x00000c68
	adds r0, r3
	movs r1, 0x5
_080CB54C:
	strb r1, [r0]
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldr r7, =0x00000c68
	adds r0, r2, r7
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x64
	ldr r3, =0x00000c62
	adds r1, r2, r3
	strh r0, [r1]
	subs r7, 0x4
	adds r2, r7
	movs r1, 0
	ldrsh r0, [r2, r1]
	bl sub_80CB1F0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB4CC

	thumb_func_start sub_80CB584
sub_80CB584: @ 80CB584
	push {r4-r6,lr}
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	movs r4, 0xC6
	lsls r4, 4
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, 0
	beq _080CB59A
	subs r0, 0x1
	strh r0, [r1]
_080CB59A:
	ldr r3, [r5]
	ldr r6, =0x00000c6a
	adds r0, r3, r6
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CB61C
	cmp r0, 0x1
	bgt _080CB5B8
	cmp r0, 0
	beq _080CB5C0
	b _080CB6DE
	.pool
_080CB5B8:
	cmp r0, 0x2
	bne _080CB5BE
	b _080CB6CC
_080CB5BE:
	b _080CB6DE
_080CB5C0:
	ldr r0, =0x00000c62
	adds r1, r3, r0
	ldr r2, =0x00000c64
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	subs r0, 0x41
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xBA
	bhi _080CB5DC
	b _080CB6E8
_080CB5DC:
	ldr r1, =0x00000c68
	adds r0, r3, r1
	ldrb r0, [r0]
	bl sub_80CB2B0
	ldr r2, [r5]
	ldr r0, =0x00000c62
	adds r3, r2, r0
	ldr r1, =0x00000c69
	adds r0, r2, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	adds r2, r6
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _080CB6E8
	.pool
_080CB61C:
	ldr r2, =0x00000c62
	adds r1, r3, r2
	ldr r6, =0x00000c64
	adds r2, r3, r6
	ldrh r0, [r2]
	ldrh r6, [r1]
	adds r0, r6
	strh r0, [r1]
	ldr r6, =0x00000c68
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, r3, r4
	ldrh r1, [r1]
	movs r3, 0
	ldrsh r2, [r2, r3]
	bl sub_80CB2F8
	ldr r2, [r5]
	ldr r3, =0x00000c66
	adds r1, r2, r3
	lsls r0, 24
	lsrs r0, 24
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	ldr r1, =0x00000c69
	adds r0, r2, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	cmp r1, 0
	ble _080CB662
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _080CB66E
_080CB662:
	cmp r1, 0
	bge _080CB69C
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CB69C
_080CB66E:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000c6a
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080CB6E8
	.pool
_080CB69C:
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r6, =0x00000c68
	adds r1, r0, r6
	ldr r2, =0x00000c69
	adds r0, r2
	ldrb r0, [r0]
	ldrb r6, [r1]
	adds r0, r6
	movs r2, 0
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, =0x00000c6a
	adds r0, r1
	strb r2, [r0]
	b _080CB6E8
	.pool
_080CB6CC:
	ldr r2, =0x00000c66
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _080CB6E8
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080CB6DE:
	movs r0, 0
	b _080CB6EA
	.pool
_080CB6E8:
	movs r0, 0x1
_080CB6EA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80CB584

	thumb_func_start sub_80CB6F0
sub_80CB6F0: @ 80CB6F0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0
	ldr r1, =gUnknown_02039D08
	mov r9, r1
_080CB704:
	adds r0, 0x1
	mov r8, r0
	movs r7, 0x5
_080CB70A:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x41
	bl GetBoxMonDataFromAnyBox
	mov r2, r9
	ldr r1, [r2]
	lsls r2, r5, 1
	ldr r3, =0x00000ba8
	adds r1, r3
	adds r1, r2
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _080CB744
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	bl GetBoxMonDataFromAnyBox
	mov r2, r9
	ldr r1, [r2]
	lsls r2, r5, 2
	ldr r3, =0x00000be4
	adds r1, r3
	adds r1, r2
	str r0, [r1]
_080CB744:
	adds r5, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _080CB70A
	mov r0, r8
	cmp r0, 0x4
	ble _080CB704
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000c5c
	adds r0, r1
	strb r6, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB6F0

	thumb_func_start sub_80CB778
sub_80CB778: @ 80CB778
	push {r4,r5,lr}
	lsls r0, 24
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	lsrs r4, r0, 22
	ldr r0, =0x00000a88
	adds r1, r0
	adds r1, r4
	ldr r0, [r1]
	cmp r0, 0
	beq _080CB79E
	bl sub_80CC314
	ldr r0, [r5]
	ldr r1, =0x00000a88
	adds r0, r1
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080CB79E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB778

	thumb_func_start sub_80CB7AC
sub_80CB7AC: @ 80CB7AC
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	lsrs r0, 22
	ldr r3, =0x00000a88
	adds r1, r3
	adds r1, r0
	ldr r3, [r1]
	cmp r3, 0
	beq _080CB7DA
	movs r0, 0x3
	adds r1, r2, 0
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
_080CB7DA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB7AC

	thumb_func_start sub_80CB7E8
sub_80CB7E8: @ 80CB7E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r1, r0, 0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xC
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x68
	movs r3, 0x40
	bl sub_80CC230
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	movs r2, 0xA7
	lsls r2, 4
	adds r1, r2
	str r0, [r1]
	movs r7, 0x1
	movs r6, 0x1
_080CB830:
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _080CB894
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r1, r0, 0
	subs r0, r6, 0x1
	lsls r3, r0, 1
	adds r3, r0
	lsls r3, 19
	movs r0, 0x80
	lsls r0, 13
	adds r3, r0
	asrs r3, 16
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xC
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x98
	bl sub_80CC230
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	lsls r2, r6, 2
	movs r3, 0xA7
	lsls r3, 4
	adds r1, r3
	adds r1, r2
	str r0, [r1]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	b _080CB8A4
	.pool
_080CB894:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r6, 2
	movs r2, 0xA7
	lsls r2, 4
	adds r0, r2
	adds r0, r1
	str r5, [r0]
_080CB8A4:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _080CB830
	ldr r3, =gUnknown_02039D08
	mov r0, r8
	cmp r0, 0
	bne _080CB8EA
	movs r6, 0
	cmp r6, r7
	bcs _080CB8EA
	mov r12, r3
	movs r5, 0xA7
	lsls r5, 4
	movs r4, 0x4
_080CB8C4:
	mov r2, r12
	ldr r1, [r2]
	lsls r0, r6, 2
	adds r1, r5
	adds r1, r0
	ldr r2, [r1]
	ldrh r0, [r2, 0x22]
	subs r0, 0xA0
	strh r0, [r2, 0x22]
	ldr r1, [r1]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r7
	bcc _080CB8C4
_080CB8EA:
	ldr r0, [r3]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080CB93C
	movs r6, 0
	adds r7, r3, 0
	movs r5, 0xA7
	lsls r5, 4
_080CB8FA:
	ldr r0, [r7]
	lsls r4, r6, 2
	adds r0, r5
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080CB932
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	cmp r0, 0
	bne _080CB932
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	ldr r2, [r0]
	ldrb r1, [r2, 0x1]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r2, 0x1]
_080CB932:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _080CB8FA
_080CB93C:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB7E8

	thumb_func_start sub_80CB950
sub_80CB950: @ 80CB950
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000c5e
	adds r1, r2
	movs r2, 0
	strb r2, [r1]
	movs r5, 0
	movs r6, 0
	adds r3, r0, 0
	movs r7, 0xA7
	lsls r7, 4
_080CB96A:
	ldr r0, [r3]
	lsls r4, r5, 2
	adds r0, r7
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080CB9A0
	cmp r5, r6
	beq _080CB99A
	adds r1, r6, 0
	str r3, [sp]
	bl sub_80CB9D0
	ldr r3, [sp]
	ldr r2, [r3]
	adds r0, r2, r7
	adds r0, r4
	movs r1, 0
	str r1, [r0]
	ldr r0, =0x00000c5e
	adds r2, r0
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
_080CB99A:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080CB9A0:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _080CB96A
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB950

	thumb_func_start sub_80CB9BC
sub_80CB9BC: @ 80CB9BC
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000c5e
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CB9BC

	thumb_func_start sub_80CB9D0
sub_80CB9D0: @ 80CB9D0
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	strh r1, [r2, 0x30]
	cmp r1, 0
	bne _080CB9E4
	movs r3, 0x68
	movs r4, 0x40
	b _080CB9F6
_080CB9E4:
	movs r3, 0x98
	subs r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 19
	movs r1, 0x80
	lsls r1, 13
	adds r0, r1
	lsrs r4, r0, 16
_080CB9F6:
	ldrh r0, [r2, 0x20]
	lsls r0, 3
	strh r0, [r2, 0x32]
	ldrh r0, [r2, 0x22]
	lsls r0, 3
	strh r0, [r2, 0x34]
	lsls r1, r3, 3
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, 0
	bge _080CBA10
	adds r0, 0x7
_080CBA10:
	asrs r0, 3
	strh r0, [r2, 0x36]
	lsls r0, r4, 16
	asrs r0, 13
	movs r3, 0x34
	ldrsh r1, [r2, r3]
	subs r0, r1
	cmp r0, 0
	bge _080CBA24
	adds r0, 0x7
_080CBA24:
	asrs r0, 3
	strh r0, [r2, 0x38]
	movs r0, 0x8
	strh r0, [r2, 0x3A]
	ldr r0, =sub_80CBA3C
	str r0, [r2, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CB9D0

	thumb_func_start sub_80CBA3C
sub_80CBA3C: @ 80CBA3C
	push {r4,lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x3A]
	movs r1, 0x3A
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _080CBA6C
	ldrh r0, [r3, 0x36]
	ldrh r4, [r3, 0x32]
	adds r0, r4
	strh r0, [r3, 0x32]
	ldrh r1, [r3, 0x38]
	ldrh r4, [r3, 0x34]
	adds r1, r4
	strh r1, [r3, 0x34]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r3, 0x20]
	lsls r1, 16
	asrs r1, 19
	strh r1, [r3, 0x22]
	subs r0, r2, 0x1
	strh r0, [r3, 0x3A]
	b _080CBAB2
_080CBA6C:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _080CBA7C
	movs r0, 0x68
	strh r0, [r3, 0x20]
	movs r0, 0x40
	b _080CBA8E
_080CBA7C:
	movs r0, 0x98
	strh r0, [r3, 0x20]
	movs r4, 0x30
	ldrsh r1, [r3, r4]
	subs r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x10
_080CBA8E:
	strh r0, [r3, 0x22]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	movs r0, 0x30
	ldrsh r1, [r3, r0]
	lsls r1, 2
	movs r4, 0xA7
	lsls r4, 4
	adds r0, r2, r4
	adds r0, r1
	str r3, [r0]
	ldr r0, =0x00000c5e
	adds r2, r0
	ldrb r0, [r2]
	subs r0, 0x1
	strb r0, [r2]
_080CBAB2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBA3C

	thumb_func_start sub_80CBAC4
sub_80CBAC4: @ 80CBAC4
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00000a6c
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080CBAE2
	bl sub_80CC314
	ldr r0, [r4]
	ldr r1, =0x00000a6c
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_080CBAE2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBAC4

	thumb_func_start sub_80CBAF0
sub_80CBAF0: @ 80CBAF0
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, =gUnknown_02039D08
	lsls r0, 16
	asrs r4, r0, 16
	movs r5, 0x5
	negs r5, r5
_080CBAFE:
	ldr r0, [r6]
	lsls r1, r3, 2
	movs r2, 0xA7
	lsls r2, 4
	adds r0, r2
	adds r2, r0, r1
	ldr r1, [r2]
	cmp r1, 0
	beq _080CBB56
	ldrh r0, [r1, 0x22]
	adds r0, r4, r0
	strh r0, [r1, 0x22]
	ldr r2, [r2]
	ldrh r1, [r2, 0x26]
	ldrh r0, [r2, 0x22]
	adds r1, r0
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 13
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0xC0
	bls _080CBB4C
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _080CBB56
	.pool
_080CBB4C:
	adds r2, 0x3E
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
_080CBB56:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _080CBAFE
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80CBAF0

	thumb_func_start sub_80CBB68
sub_80CBB68: @ 80CBB68
	push {r4,r5,lr}
	lsls r0, 24
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	lsrs r4, r0, 22
	movs r0, 0xA7
	lsls r0, 4
	adds r1, r0
	adds r1, r4
	ldr r0, [r1]
	cmp r0, 0
	beq _080CBB92
	bl sub_80CC314
	ldr r0, [r5]
	movs r1, 0xA7
	lsls r1, 4
	adds r0, r1
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080CBB92:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBB68

	thumb_func_start sub_80CBB9C
sub_80CBB9C: @ 80CBB9C
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_02039D08
_080CBBA2:
	ldr r0, [r6]
	lsls r4, r5, 2
	movs r1, 0xA7
	lsls r1, 4
	adds r0, r1
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080CBBC6
	bl sub_80CC314
	ldr r0, [r6]
	movs r1, 0xA7
	lsls r1, 4
	adds r0, r1
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080CBBC6:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _080CBBA2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBB9C

	thumb_func_start sub_80CBBDC
sub_80CBBDC: @ 80CBBDC
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	lsrs r0, 22
	movs r3, 0xA7
	lsls r3, 4
	adds r1, r3
	adds r1, r0
	ldr r3, [r1]
	cmp r3, 0
	beq _080CBC0C
	movs r0, 0x3
	adds r1, r2, 0
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
_080CBC0C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBBDC

	thumb_func_start sub_80CBC14
sub_80CBC14: @ 80CBC14
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	cmp r4, 0
	bne _080CBC44
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r5, =0x00000a6c
	adds r2, r0, r5
	lsls r1, 2
	adds r5, 0x4
	adds r0, r5
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	str r4, [r0]
	b _080CBC60
	.pool
_080CBC44:
	cmp r4, 0x1
	bne _080CBC96
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r1, =0x00000a6c
	adds r2, r0, r1
	lsls r1, r5, 2
	ldr r4, =0x00000a88
	adds r0, r4
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	movs r1, 0
	str r1, [r0]
_080CBC60:
	adds r5, r3, 0
	ldr r0, [r5]
	ldr r4, =0x00000a6c
	adds r0, r4
	ldr r1, [r0]
	ldr r0, =sub_80CC100
	str r0, [r1, 0x1C]
	bl sub_80CAFAC
	ldr r1, [r5]
	adds r1, r4
	ldr r3, [r1]
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r0, [r5]
	adds r0, r4
	ldr r0, [r0]
	adds r0, 0x43
	movs r1, 0x7
	strb r1, [r0]
_080CBC96:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBC14

	thumb_func_start sub_80CBCAC
sub_80CBCAC: @ 80CBCAC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r0, 0xE
	bne _080CBCF8
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	lsls r5, r6, 2
	movs r4, 0xA7
	lsls r4, 4
	adds r0, r1, r4
	adds r0, r5
	ldr r2, =0x00000a6c
	adds r1, r2
	ldr r2, [r1]
	str r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r3]
	adds r0, r4
	adds r0, r5
	ldr r0, [r0]
	adds r0, 0x43
	movs r1, 0xC
	strb r1, [r0]
	b _080CBD34
	.pool
_080CBCF8:
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	lsls r4, r6, 2
	ldr r3, =0x00000a88
	adds r0, r1, r3
	adds r0, r4
	ldr r2, =0x00000a6c
	adds r1, r2
	ldr r2, [r1]
	str r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r5]
	adds r0, r3
	adds r0, r4
	ldr r4, [r0]
	adds r0, r6, 0
	movs r1, 0x6
	bl __umodsi3
	movs r1, 0x13
	subs r1, r0
	adds r4, 0x43
	strb r1, [r4]
	adds r3, r5, 0
_080CBD34:
	ldr r1, [r3]
	ldr r0, =0x00000a6c
	adds r1, r0
	ldr r2, [r1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	movs r0, 0
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBCAC

	thumb_func_start sub_80CBD5C
sub_80CBD5C: @ 80CBD5C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r0, 0xE
	bne _080CBD80
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	movs r0, 0xB0
	lsls r0, 4
	adds r2, r1, r0
	lsls r0, r4, 2
	movs r4, 0xA7
	lsls r4, 4
	b _080CBD8E
	.pool
_080CBD80:
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	movs r0, 0xB0
	lsls r0, 4
	adds r2, r1, r0
	lsls r0, r4, 2
	ldr r4, =0x00000a88
_080CBD8E:
	adds r0, r4
	adds r1, r0
	str r1, [r2]
	ldr r1, [r3]
	ldr r2, =0x00000a6c
	adds r0, r1, r2
	ldr r2, [r0]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	ldr r4, =0x00000c5d
	adds r1, r4
	movs r0, 0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBD5C

	thumb_func_start sub_80CBDC4
sub_80CBDC4: @ 80CBDC4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r6, =gUnknown_02039D08
	ldr r0, [r6]
	ldr r1, =0x00000c5d
	mov r9, r1
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x10
	bne _080CBDE8
	movs r0, 0
	b _080CBEF4
	.pool
_080CBDE8:
	adds r0, 0x1
	strb r0, [r1]
	ldr r2, [r6]
	ldr r5, =0x00000c5d
	adds r0, r2, r5
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080CBE18
	movs r1, 0xB0
	lsls r1, 4
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r0]
	ldrh r0, [r1, 0x22]
	subs r0, 0x1
	strh r0, [r1, 0x22]
	ldr r5, =0x00000a6c
	adds r0, r2, r5
	ldr r1, [r0]
	ldrh r0, [r1, 0x22]
	adds r0, 0x1
	strh r0, [r1, 0x22]
_080CBE18:
	ldr r3, [r6]
	movs r7, 0xB0
	lsls r7, 4
	adds r4, r3, r7
	ldr r0, [r4]
	ldr r0, [r0]
	mov r8, r0
	ldr r5, =gSineTable
	mov r0, r9
	adds r1, r3, r0
	ldrb r0, [r1]
	lsls r0, 4
	adds r0, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _080CBE3C
	adds r0, 0xF
_080CBE3C:
	asrs r0, 4
	mov r2, r8
	strh r0, [r2, 0x24]
	ldr r0, =0x00000a6c
	mov r8, r0
	add r3, r8
	ldr r2, [r3]
	ldrb r0, [r1]
	lsls r0, 4
	adds r0, r5
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, 0
	bge _080CBE5A
	adds r0, 0xF
_080CBE5A:
	asrs r0, 4
	negs r0, r0
	strh r0, [r2, 0x24]
	ldrb r0, [r1]
	cmp r0, 0x8
	bne _080CBEBE
	ldr r3, [r3]
	ldr r0, [r4]
	ldr r0, [r0]
	ldrb r0, [r0, 0x5]
	movs r5, 0x3
	movs r1, 0xC
	ands r1, r0
	ldrb r2, [r3, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r0, [r6]
	mov r2, r8
	adds r1, r0, r2
	ldr r1, [r1]
	adds r0, r7
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x43
	ldrb r0, [r0]
	adds r1, 0x43
	strb r0, [r1]
	bl sub_80CAFAC
	ldr r1, [r6]
	adds r1, r7
	ldr r1, [r1]
	ldr r1, [r1]
	ands r5, r0
	lsls r5, 2
	ldrb r0, [r1, 0x5]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0x5]
	ldr r0, [r6]
	adds r0, r7
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x43
	movs r1, 0x7
	strb r1, [r0]
_080CBEBE:
	ldr r1, [r6]
	mov r5, r9
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x10
	bne _080CBEF2
	mov r0, r8
	adds r2, r1, r0
	ldr r3, [r2]
	adds r1, r7
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r1]
	str r3, [r0]
	ldr r1, [r6]
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	ldr r0, =sub_80CC100
	str r0, [r2, 0x1C]
	adds r1, r7
	ldr r0, [r1]
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_080CBEF2:
	movs r0, 0x1
_080CBEF4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CBDC4

	thumb_func_start sub_80CBF14
sub_80CBF14: @ 80CBF14
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r0, 0x1
	beq _080CBF4C
	cmp r0, 0x1
	bgt _080CBF2E
	cmp r0, 0
	beq _080CBF34
	b _080CBFC0
_080CBF2E:
	cmp r2, 0x2
	beq _080CBF70
	b _080CBFC0
_080CBF34:
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	ldr r0, =0x00000b04
	adds r2, r1, r0
	lsls r0, r4, 2
	movs r4, 0xA7
	lsls r4, 4
	b _080CBF58
	.pool
_080CBF4C:
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	ldr r0, =0x00000b04
	adds r2, r1, r0
	lsls r0, r4, 2
	ldr r4, =0x00000a88
_080CBF58:
	adds r0, r4
	adds r1, r0
	str r1, [r2]
	adds r4, r3, 0
	b _080CBF80
	.pool
_080CBF70:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r3, =0x00000b04
	adds r2, r1, r3
	ldr r4, =0x00000a6c
	adds r1, r4
	str r1, [r2]
	adds r4, r0, 0
_080CBF80:
	ldr r0, [r4]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _080CBFC0
	bl InitSpriteAffineAnim
	ldr r0, [r4]
	ldr r3, =0x00000b04
	adds r0, r3
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r1, [r4]
	adds r1, r3
	ldr r0, [r1]
	ldr r2, [r0]
	ldr r0, =gSpriteAffineAnimTable_857291C
	str r0, [r2, 0x10]
	ldr r0, [r1]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAffineAnim
_080CBFC0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CBF14

	thumb_func_start sub_80CBFD8
sub_80CBFD8: @ 80CBFD8
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0
	beq _080CBFF8
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _080CC004
_080CBFF8:
	movs r0, 0
	b _080CC01A
	.pool
_080CC004:
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080CC018
	movs r0, 0x4
	orrs r0, r2
	strb r0, [r3]
_080CC018:
	movs r0, 0x1
_080CC01A:
	pop {r1}
	bx r1
	thumb_func_end sub_80CBFD8

	thumb_func_start sub_80CC020
sub_80CC020: @ 80CC020
	push {r4,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _080CC056
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldr r0, [r4]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	bl sub_80CC314
	ldr r0, [r4]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1]
_080CC056:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CC020

	thumb_func_start sub_80CC064
sub_80CC064: @ 80CC064
	push {lr}
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _080CC094
	adds r2, r0, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldr r1, =0x00000b04
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAffineAnim
_080CC094:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CC064

	thumb_func_start sub_80CC0A0
sub_80CC0A0: @ 80CC0A0
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000b04
	adds r2, r0, r1
	ldr r0, [r2]
	cmp r0, 0
	bne _080CC0BC
	movs r0, 0
	b _080CC0D0
	.pool
_080CC0BC:
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080CC0CE
	movs r0, 0
	str r0, [r2]
_080CC0CE:
	movs r0, 0x1
_080CC0D0:
	pop {r1}
	bx r1
	thumb_func_end sub_80CC0A0

	thumb_func_start sub_80CC0D4
sub_80CC0D4: @ 80CC0D4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	ldr r2, =0x00000a6c
	adds r1, r2
	ldr r3, [r1]
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r3, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x5]
	bx lr
	.pool
	thumb_func_end sub_80CC0D4

	thumb_func_start sub_80CC100
sub_80CC100: @ 80CC100
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	ldr r2, =0x00000cb4
	adds r1, r2
	ldr r2, [r1]
	ldrh r2, [r2, 0x20]
	strh r2, [r0, 0x20]
	ldr r2, [r1]
	ldrh r1, [r2, 0x26]
	ldrh r2, [r2, 0x22]
	adds r1, r2
	adds r1, 0x4
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end sub_80CC100

	thumb_func_start sub_80CC124
sub_80CC124: @ 80CC124
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r4, 0
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r2, =0x00000b58
	adds r0, r2
	ldrh r0, [r0]
	adds r2, r1, 0
	cmp r0, r3
	beq _080CC158
	adds r6, r2, 0
	ldr r5, =0x00000b58
_080CC140:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x27
	bhi _080CC158
	ldr r0, [r6]
	lsls r1, r4, 1
	adds r0, r5
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _080CC140
_080CC158:
	cmp r4, 0x28
	bne _080CC198
	movs r4, 0
	ldr r0, [r2]
	ldr r5, =0x00000b58
	adds r0, r5
	ldrh r0, [r0]
	cmp r0, 0
	beq _080CC184
	adds r6, r2, 0
_080CC16C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x27
	bhi _080CC184
	ldr r0, [r6]
	lsls r1, r4, 1
	adds r0, r5
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080CC16C
_080CC184:
	cmp r4, 0x28
	bne _080CC198
	ldr r0, =0x0000ffff
	b _080CC1CA
	.pool
_080CC198:
	ldr r1, [r2]
	lsls r2, r4, 1
	ldr r5, =0x00000b58
	adds r0, r1, r5
	adds r0, r2
	strh r3, [r0]
	ldr r0, =0x00000b08
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r4, 20
	lsrs r4, 16
	adds r0, r3, 0
	movs r1, 0x1
	bl GetMonIconTiles
	lsls r1, r4, 5
	ldr r2, =0x06010000
	adds r1, r2
	ldr r2, =0x04000080
	bl CpuSet
	adds r0, r4, 0
_080CC1CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CC124

	thumb_func_start sub_80CC1E0
sub_80CC1E0: @ 80CC1E0
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	movs r3, 0
	ldr r6, =gUnknown_02039D08
_080CC1EA:
	ldr r1, [r6]
	lsls r2, r3, 1
	ldr r4, =0x00000b58
	adds r0, r1, r4
	adds r4, r0, r2
	ldrh r0, [r4]
	cmp r0, r5
	bne _080CC220
	ldr r0, =0x00000b08
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _080CC22A
	strh r0, [r4]
	b _080CC22A
	.pool
_080CC220:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x27
	bls _080CC1EA
_080CC22A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80CC1E0

	thumb_func_start sub_80CC230
sub_80CC230: @ 80CC230
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r4, [sp, 0x3C]
	ldr r5, [sp, 0x40]
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x18]
	lsls r3, 16
	lsrs r3, 16
	mov r8, r3
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r9, r5
	mov r2, sp
	ldr r0, =gUnknown_085728D4
	ldm r0!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldm r0!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	adds r0, r6, 0
	bl mon_icon_convert_unown_species_id
	mov r10, r0
	mov r6, r10
	mov r2, sp
	ldr r1, =gMonIconPaletteIndices
	adds r1, r6, r1
	ldr r3, =0x0000dac0
	adds r0, r3, 0
	ldrb r1, [r1]
	adds r0, r1
	strh r0, [r2, 0x2]
	adds r0, r6, 0
	bl sub_80CC124
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0, 0
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _080CC302
	ldr r7, [sp, 0x18]
	lsls r1, r7, 16
	asrs r1, 16
	mov r0, r8
	lsls r2, r0, 16
	asrs r2, 16
	mov r0, sp
	mov r3, r9
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _080CC2FC
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldr r2, =0x000003ff
	ands r2, r5
	ldrh r3, [r0, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x4]
	movs r1, 0x3
	ands r4, r1
	lsls r3, r4, 2
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r3
	strb r1, [r0, 0x5]
	mov r1, r10
	strh r1, [r0, 0x2E]
	b _080CC304
	.pool
_080CC2FC:
	adds r0, r6, 0
	bl sub_80CC1E0
_080CC302:
	movs r0, 0
_080CC304:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80CC230

	thumb_func_start sub_80CC314
sub_80CC314: @ 80CC314
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	bl sub_80CC1E0
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80CC314

	thumb_func_start sub_80CC32C
sub_80CC32C: @ 80CC32C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80CC370
	movs r1, 0x2
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CC32C

	thumb_func_start sub_80CC35C
sub_80CC35C: @ 80CC35C
	push {lr}
	ldr r0, =sub_80CC370
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CC35C

	thumb_func_start sub_80CC370
sub_80CC370: @ 80CC370
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _080CC454
	lsls r0, 2
	ldr r1, =_080CC39C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CC39C:
	.4byte _080CC3B0
	.4byte _080CC3E8
	.4byte _080CC41C
	.4byte _080CC426
	.4byte _080CC44C
_080CC3B0:
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r2, =0x000002d2
	adds r0, r2
	movs r2, 0
	strb r2, [r0]
	ldr r1, [r1]
	movs r3, 0xB3
	lsls r3, 2
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =0x00004ac4
	adds r1, r0
	movs r2, 0x80
	lsls r2, 5
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	strh r0, [r4, 0xA]
	b _080CC458
	.pool
_080CC3E8:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl CheckForSpaceForDma3Request
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080CC45E
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00004ac4
	adds r1, r2
	movs r0, 0x2
	bl SetBgTilemapBuffer
	movs r0, 0x2
	bl ShowBg
	b _080CC458
	.pool
_080CC41C:
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl sub_80CC7A0
	b _080CC458
_080CC426:
	bl sub_80CCA00
	cmp r0, 0
	beq _080CC45E
	ldrb r0, [r4, 0xC]
	bl sub_80CCB50
	bl sub_80CD02C
	ldrb r0, [r4, 0xC]
	bl sub_80CB028
	ldr r1, =0x00005b0a
	movs r0, 0xC
	bl SetGpuReg
	b _080CC458
	.pool
_080CC44C:
	adds r0, r2, 0
	bl DestroyTask
	b _080CC458
_080CC454:
	movs r0, 0
	b _080CC45C
_080CC458:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
_080CC45C:
	strh r0, [r4, 0x8]
_080CC45E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80CC370

	thumb_func_start sub_80CC464
sub_80CC464: @ 80CC464
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	adds r0, r4, 0
	bl sub_80CC644
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r5, =gUnknown_02039D08
	ldr r2, [r5]
	lsls r0, r6, 24
	asrs r3, r0, 24
	movs r0, 0x6
	negs r0, r0
	adds r1, r0, 0
	cmp r3, 0
	ble _080CC490
	movs r1, 0x6
_080CC490:
	ldr r7, =0x000002ce
	adds r0, r2, r7
	strh r1, [r0]
	movs r1, 0x2
	cmp r3, 0
	ble _080CC49E
	movs r1, 0x1
_080CC49E:
	ldr r7, =0x000002d3
	adds r0, r2, r7
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, 0xB4
	lsls r0, 2
	adds r1, r2, r0
	movs r0, 0x20
	strh r0, [r1]
	movs r1, 0xB5
	lsls r1, 2
	adds r0, r2, r1
	strb r4, [r0]
	ldr r2, [r5]
	movs r1, 0
	cmp r3, 0
	bgt _080CC4C2
	movs r1, 0x5
_080CC4C2:
	ldr r4, =0x000002d6
	adds r0, r2, r4
	strh r1, [r0]
	movs r7, 0xB6
	lsls r7, 2
	adds r0, r2, r7
	strh r3, [r0]
	movs r1, 0x38
	cmp r3, 0
	ble _080CC4DC
	movs r0, 0x84
	lsls r0, 1
	adds r1, r0, 0
_080CC4DC:
	ldr r4, =0x000002da
	adds r0, r2, r4
	strh r1, [r0]
	movs r1, 0
	cmp r3, 0
	bgt _080CC4EA
	movs r1, 0x5
_080CC4EA:
	movs r7, 0xB7
	lsls r7, 2
	adds r0, r2, r7
	strh r1, [r0]
	ldr r0, =0x000002de
	adds r1, r2, r0
	movs r0, 0
	strh r0, [r1]
	movs r3, 0xB8
	lsls r3, 2
	adds r1, r2, r3
	movs r0, 0x2
	strh r0, [r1]
	ldr r4, =0x00000a64
	adds r0, r2, r4
	mov r7, r8
	strb r7, [r0]
	ldr r0, [r5]
	ldr r1, =0x00000a65
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	ldr r3, =0x00000a63
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CC464

	thumb_func_start sub_80CC54C
sub_80CC54C: @ 80CC54C
	push {r4-r6,lr}
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r5, =0x00000a63
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CC594
	cmp r0, 0x1
	bgt _080CC570
	cmp r0, 0
	beq _080CC576
	b _080CC624
	.pool
_080CC570:
	cmp r0, 0x2
	beq _080CC5E4
	b _080CC624
_080CC576:
	ldr r2, =0x00000a64
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	bl sub_80CC7A0
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080CC594:
	bl sub_80CCA00
	cmp r0, 0
	beq _080CC632
	ldr r6, =gUnknown_02039D08
	ldr r1, [r6]
	ldr r4, =0x00000a64
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r5, =0x00000a65
	adds r1, r5
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	bl sub_80CB4CC
	ldr r1, [r6]
	adds r4, r1, r4
	ldrb r0, [r4]
	adds r1, r5
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	bl sub_80CCCFC
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80CD0B8
	b _080CC624
	.pool
_080CC5E4:
	bl sub_80CB584
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, [r4]
	movs r4, 0xB4
	lsls r4, 2
	adds r3, r2, r4
	ldrh r0, [r3]
	cmp r0, 0
	beq _080CC620
	movs r0, 0xB3
	lsls r0, 2
	adds r1, r2, r0
	subs r4, 0x2
	adds r0, r2, r4
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	ldrh r0, [r3]
	subs r0, 0x1
	strh r0, [r3]
	lsls r0, 16
	cmp r0, 0
	bne _080CC632
	bl sub_80CCEE0
	bl sub_80CD158
_080CC620:
	adds r0, r5, 0
	b _080CC634
_080CC624:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r4, =0x00000a63
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080CC632:
	movs r0, 0x1
_080CC634:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CC54C

	thumb_func_start sub_80CC644
sub_80CC644: @ 80CC644
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0
	cmp r1, r4
	beq _080CC66E
_080CC658:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bls _080CC664
	movs r1, 0
_080CC664:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r1, r4
	bne _080CC658
_080CC66E:
	movs r0, 0x1
	negs r0, r0
	cmp r2, 0x6
	bhi _080CC678
	movs r0, 0x1
_080CC678:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80CC644

	thumb_func_start sub_80CC680
sub_80CC680: @ 80CC680
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_80D2120
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000a62
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CC680

	thumb_func_start sub_80CC6B0
sub_80CC6B0: @ 80CC6B0
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r2, =0x00000a62
	adds r0, r2
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _080CC794
	lsls r0, 2
	ldr r1, =_080CC6DC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CC6DC:
	.4byte _080CC6F0
	.4byte _080CC718
	.4byte _080CC732
	.4byte _080CC76C
	.4byte _080CC790
_080CC6F0:
	ldr r0, [r4]
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldr r2, =0x00000a62
	adds r1, r2
	b _080CC77E
	.pool
_080CC718:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080CC794
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80CC7A0
	b _080CC776
_080CC732:
	bl sub_80CCA00
	cmp r0, 0x1
	bne _080CC794
	bl sub_80CCF9C
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldr r2, =0x00000a62
	adds r1, r2
	b _080CC77E
	.pool
_080CC76C:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080CC794
_080CC776:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r0, =0x00000a62
	adds r1, r0
_080CC77E:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080CC794
	.pool
_080CC790:
	movs r0, 0
	b _080CC796
_080CC794:
	movs r0, 0x1
_080CC796:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80CC6B0

	thumb_func_start sub_80CC7A0
sub_80CC7A0: @ 80CC7A0
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	ldr r3, =0x000006f9
	adds r2, r3
	movs r3, 0
	strb r3, [r2]
	ldr r2, [r4]
	ldr r3, =0x000006fa
	adds r2, r3
	strb r0, [r2]
	ldr r0, [r4]
	ldr r2, =0x000006fb
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r4]
	adds r2, r1, r2
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _080CC7E6
	movs r3, 0
	ldr r0, =0x000002d2
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0
	bne _080CC7DA
	movs r3, 0x1
_080CC7DA:
	strb r3, [r2]
	ldr r0, [r4]
	ldr r1, =0x00004ac4
	adds r0, r1
	bl sub_80CCAE0
_080CC7E6:
	ldr r7, =gUnknown_02039D08
	ldr r0, [r7]
	ldr r2, =0x000006fa
	adds r0, r2
	ldrb r0, [r0]
	bl sub_80D20F8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x10
	beq _080CC8C4
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gWallpaperTable
	adds r6, r0, r1
	ldr r0, [r6, 0x4]
	ldr r1, [r7]
	ldr r5, =0x00000792
	adds r1, r5
	bl LZ77UnCompWram
	ldr r0, [r7]
	adds r5, r0, r5
	ldr r4, =0x000006fb
	adds r1, r0, r4
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r3, =0x000002d2
	adds r0, r3
	ldrb r2, [r0]
	adds r0, r5, 0
	bl sub_80CCA3C
	ldr r1, [r7]
	adds r4, r1, r4
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0
	beq _080CC874
	ldr r0, [r6, 0x8]
	ldr r2, =0x000002d2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 21
	movs r3, 0x80
	lsls r3, 15
	adds r1, r3
	lsrs r1, 16
	movs r2, 0x40
	bl LoadPalette
	b _080CC888
	.pool
_080CC874:
	ldr r0, [r6, 0x8]
	ldr r2, =0x000002d2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 6
	ldr r2, =gPlttBufferUnfaded + 0x80
	adds r1, r2
	movs r2, 0x20
	bl CpuSet
_080CC888:
	ldr r0, [r6]
	mov r1, sp
	bl malloc_and_decompress
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r3, [r0]
	ldr r2, =0x00000a68
	adds r0, r3, r2
	str r1, [r0]
	ldr r2, [sp]
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =0x000002d2
	adds r3, r0
	ldrb r3, [r3]
	lsls r3, 8
	movs r0, 0x2
	bl LoadBgTiles
	b _080CC9DA
	.pool
_080CC8C4:
	bl GetWaldaWallpaperPatternId
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_0857AF44
	adds r6, r1, r0
	ldr r0, [r6, 0x4]
	ldr r1, [r7]
	ldr r4, =0x00000792
	adds r1, r4
	bl LZ77UnCompWram
	ldr r2, [r7]
	adds r0, r2, r4
	ldr r5, =0x000006fb
	adds r1, r2, r5
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r3, =0x000002d2
	adds r2, r3
	ldrb r2, [r2]
	bl sub_80CCA3C
	ldr r0, [r6, 0x8]
	ldr r1, [r7]
	adds r1, r4
	movs r2, 0x20
	bl CpuSet
	bl GetWaldaWallpaperColorsPtr
	ldr r1, [r7]
	ldr r2, =0x00000794
	adds r1, r2
	movs r2, 0x2
	bl CpuSet
	bl GetWaldaWallpaperColorsPtr
	ldr r1, [r7]
	ldr r3, =0x000007b4
	adds r1, r3
	movs r2, 0x2
	bl CpuSet
	ldr r1, [r7]
	adds r5, r1, r5
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	beq _080CC960
	adds r0, r1, r4
	ldr r2, =0x000002d2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 21
	movs r3, 0x80
	lsls r3, 15
	adds r1, r3
	lsrs r1, 16
	movs r2, 0x40
	bl LoadPalette
	b _080CC976
	.pool
_080CC960:
	ldr r2, =0x00000792
	adds r0, r1, r2
	ldr r3, =0x000002d2
	adds r1, r3
	ldrb r1, [r1]
	lsls r1, 6
	ldr r2, =gPlttBufferUnfaded + 0x80
	adds r1, r2
	movs r2, 0x20
	bl CpuSet
_080CC976:
	ldr r0, [r6]
	mov r1, sp
	bl malloc_and_decompress
	ldr r6, =gUnknown_02039D08
	ldr r1, [r6]
	ldr r5, =0x00000a68
	adds r1, r5
	str r0, [r1]
	ldr r4, =gUnknown_0857B004
	bl GetWaldaWallpaperIconId
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	add r1, sp, 0x4
	bl malloc_and_decompress
	adds r4, r0, 0
	ldr r0, [r6]
	adds r0, r5
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, [sp, 0x4]
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0x80
	lsls r0, 19
	orrs r2, r0
	adds r0, r4, 0
	bl CpuSet
	adds r0, r4, 0
	bl Free
	ldr r0, [r6]
	adds r5, r0, r5
	ldr r1, [r5]
	ldr r2, [sp]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, =0x000002d2
	adds r0, r3
	ldrb r3, [r0]
	lsls r3, 8
	movs r0, 0x2
	bl LoadBgTiles
_080CC9DA:
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CC7A0

	thumb_func_start sub_80CCA00
sub_80CCA00: @ 80CCA00
	push {r4,r5,lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080CCA12
	movs r0, 0
	b _080CCA2E
_080CCA12:
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r1, =0x00000a68
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080CCA2C
	bl Free
	ldr r0, [r5]
	ldr r1, =0x00000a68
	adds r0, r1
	str r4, [r0]
_080CCA2C:
	movs r0, 0x1
_080CCA2E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CCA00

	thumb_func_start sub_80CCA3C
sub_80CCA3C: @ 80CCA3C
	push {r4-r7,lr}
	sub sp, 0x24
	adds r5, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r4, r2, 17
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r3, 0xB3
	lsls r3, 2
	adds r0, r3
	ldrh r3, [r0]
	lsrs r3, 3
	adds r3, 0xA
	lsls r1, 24
	asrs r7, r1, 24
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 3
	adds r6, r3, r0
	movs r0, 0x3F
	ands r6, r0
	movs r3, 0x14
	str r3, [sp]
	movs r1, 0x12
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	str r1, [sp, 0x14]
	movs r0, 0x11
	str r0, [sp, 0x18]
	lsls r2, 24
	asrs r2, 16
	str r2, [sp, 0x1C]
	movs r0, 0xC0
	lsls r0, 10
	adds r4, r0
	asrs r4, 16
	str r4, [sp, 0x20]
	movs r0, 0x2
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	cmp r7, 0
	beq _080CCAD2
	cmp r7, 0
	ble _080CCAB0
	lsls r0, r6, 16
	movs r1, 0xA0
	lsls r1, 13
	adds r0, r1
	b _080CCAB6
	.pool
_080CCAB0:
	lsls r0, r6, 16
	ldr r3, =0xfffc0000
	adds r0, r3
_080CCAB6:
	lsrs r6, r0, 16
	lsls r2, r6, 24
	lsrs r2, 24
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x12
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r3, 0x2
	bl FillBgTilemapBufferRect
_080CCAD2:
	add sp, 0x24
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCA3C

	thumb_func_start sub_80CCAE0
sub_80CCAE0: @ 80CCAE0
	push {r4-r6,lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0xB3
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 3
	adds r3, r0, 0
	adds r3, 0x1E
	movs r0, 0x3F
	ands r3, r0
	adds r0, r3, 0
	cmp r0, 0x1F
	bgt _080CCB10
	lsls r0, 1
	movs r6, 0x98
	lsls r6, 3
	adds r0, r6
	b _080CCB18
	.pool
_080CCB10:
	lsls r0, 1
	movs r1, 0xC8
	lsls r1, 4
	adds r0, r1
_080CCB18:
	adds r2, r0
	movs r0, 0
	movs r5, 0
	movs r4, 0x3F
_080CCB20:
	strh r5, [r2]
	adds r2, 0x2
	adds r3, 0x1
	ands r3, r4
	adds r1, r3, 0
	cmp r1, 0
	bne _080CCB32
	ldr r6, =0xfffff7c0
	adds r2, r6
_080CCB32:
	cmp r1, 0x20
	bne _080CCB3C
	movs r1, 0xF8
	lsls r1, 3
	adds r2, r1
_080CCB3C:
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2B
	bls _080CCB20
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCAE0

	thumb_func_start sub_80CCB50
sub_80CCB50: @ 80CCB50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gUnknown_02039D08
	mov r10, r1
	ldr r1, [r1]
	movs r2, 0xBE
	lsls r2, 2
	adds r0, r1, r2
	str r0, [sp, 0x24]
	mov r3, sp
	adds r3, 0x24
	str r3, [sp, 0x2C]
	ldr r0, =0x00030200
	str r0, [r3, 0x4]
	ldr r4, =0x000006fc
	adds r1, r4
	str r1, [sp, 0x14]
	add r0, sp, 0x18
	ldr r7, =0x0000dac9
	strh r7, [r0]
	add r0, sp, 0x1C
	movs r1, 0
	movs r2, 0x8
	bl memset
	add r1, sp, 0x14
	add r0, sp, 0x4
	movs r2, 0x10
	bl memcpy
	mov r0, r8
	bl sub_80D20F8
	lsls r0, 24
	mov r5, r10
	ldr r4, [r5]
	ldr r2, =gUnknown_08577574
	lsrs r0, 22
	adds r1, r0, r2
	ldrh r3, [r1]
	movs r5, 0xE3
	lsls r5, 3
	adds r1, r4, r5
	strh r3, [r1]
	adds r2, 0x2
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, =0x0000071a
	adds r4, r1
	strh r0, [r4]
	add r0, sp, 0x4
	bl LoadSpritePalettes
	mov r2, r10
	ldr r0, [r2]
	movs r6, 0xE7
	lsls r6, 3
	adds r0, r6
	movs r1, 0xFC
	lsls r1, 2
	str r1, [r0]
	adds r0, r7, 0
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	mov r4, r10
	ldr r3, [r4]
	lsls r1, r0, 4
	movs r5, 0x87
	lsls r5, 1
	mov r9, r5
	add r1, r9
	ldr r4, =0x0000071c
	adds r2, r3, r4
	strh r1, [r2]
	adds r3, r6
	movs r5, 0x80
	lsls r5, 9
	adds r1, r5, 0
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r0, r7, 0
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	mov r1, r10
	ldr r4, [r1]
	lsls r1, r0, 4
	add r1, r9
	ldr r3, =0x0000071e
	adds r2, r4, r3
	strh r1, [r2]
	adds r6, r4, r6
	lsls r5, r0
	ldr r0, [r6]
	orrs r0, r5
	str r0, [r6]
	ldr r5, =0x000021b8
	adds r4, r5
	mov r0, r8
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x8
	bl StringCopyPadded
	mov r4, r10
	ldr r1, [r4]
	adds r5, r1, r5
	movs r0, 0xBE
	lsls r0, 2
	adds r1, r0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_80C6D80
	ldr r0, [sp, 0x2C]
	bl LoadSpriteSheet
	mov r0, r8
	bl GetBoxNamePtr
	bl sub_80CD00C
	movs r4, 0
	lsls r0, 16
	asrs r6, r0, 16
_080CCC70:
	lsls r1, r4, 5
	adds r1, r6, r1
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gSpriteTemplate_857B0A8
	movs r2, 0x1C
	movs r3, 0x18
	bl CreateSprite
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r5, =gUnknown_02039D08
	ldr r2, [r5]
	lsls r0, r4, 2
	movs r3, 0xE4
	lsls r3, 3
	adds r2, r3
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	lsls r1, r4, 24
	lsrs r1, 24
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	bls _080CCC70
	ldr r0, [r5]
	movs r4, 0xDF
	lsls r4, 3
	adds r0, r4
	movs r1, 0
	strb r1, [r0]
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCB50

	thumb_func_start sub_80CCCFC
sub_80CCCFC: @ 80CCCFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	movs r1, 0xBE
	lsls r1, 2
	adds r0, r2, r1
	str r0, [sp, 0x1C]
	add r3, sp, 0x1C
	ldr r5, =0x0000ffff
	mov r12, r5
	movs r6, 0xC0
	lsls r6, 10
	mov r9, r6
	ldr r0, =0x00030200
	str r0, [r3, 0x4]
	add r1, sp, 0x4
	ldr r0, =gSpriteTemplate_857B0A8
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	movs r1, 0
	movs r5, 0xDF
	lsls r5, 3
	adds r2, r5
	ldrb r0, [r2]
	mov r8, r4
	adds r6, r3, 0
	cmp r0, 0
	bne _080CCD50
	movs r1, 0x1
_080CCD50:
	strb r1, [r2]
	mov r7, r8
	ldr r0, [r7]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CCD8C
	ldr r0, [r6, 0x4]
	mov r1, r12
	ands r0, r1
	mov r3, r9
	orrs r0, r3
	str r0, [r6, 0x4]
	ldr r0, [r7]
	ldr r5, =0x0000071c
	adds r0, r5
	ldrh r0, [r0]
	mov r9, r0
	b _080CCDB0
	.pool
_080CCD8C:
	ldr r0, [r6, 0x4]
	mov r7, r12
	ands r0, r7
	movs r1, 0x80
	lsls r1, 11
	orrs r0, r1
	str r0, [r6, 0x4]
	mov r1, r8
	ldr r0, [r1]
	ldr r3, =0x0000071c
	adds r0, r3
	ldrh r0, [r0]
	mov r9, r0
	add r1, sp, 0x4
	movs r0, 0x4
	strh r0, [r1]
	ldr r0, =0x0000dac9
	strh r0, [r1, 0x2]
_080CCDB0:
	mov r5, r8
	ldr r4, [r5]
	ldr r5, =0x000021b8
	adds r4, r5
	ldr r0, [sp, 0x28]
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x8
	bl StringCopyPadded
	mov r7, r8
	ldr r1, [r7]
	adds r5, r1, r5
	movs r0, 0xBE
	lsls r0, 2
	adds r1, r0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_80C6D80
	adds r0, r6, 0
	bl LoadSpriteSheet
	ldr r0, [sp, 0x28]
	bl sub_80D20F8
	lsls r0, 24
	lsrs r0, 22
	ldr r1, =gUnknown_08577574
	adds r0, r1
	mov r1, r9
	movs r2, 0x4
	bl LoadPalette
	ldr r0, [sp, 0x28]
	bl GetBoxNamePtr
	bl sub_80CD00C
	lsls r0, 16
	mov r1, r10
	lsls r2, r1, 24
	asrs r2, 24
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 6
	lsrs r3, r0, 16
	str r3, [sp, 0x24]
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	movs r7, 0
	mov r9, r8
	negs r2, r2
	mov r8, r2
_080CCE2E:
	lsls r6, r7, 5
	mov r5, r10
	lsls r1, r5, 16
	asrs r1, 16
	adds r1, r6
	lsls r1, 16
	asrs r1, 16
	add r0, sp, 0x4
	movs r2, 0x1C
	movs r3, 0x18
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r1, r9
	ldr r2, [r1]
	lsls r5, r7, 2
	movs r3, 0xE5
	lsls r3, 3
	adds r2, r3
	adds r2, r5
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	mov r0, r8
	lsls r4, r0, 1
	add r4, r8
	lsls r4, 1
	strh r4, [r1, 0x2E]
	ldr r1, [r2]
	ldr r3, [sp, 0x24]
	lsls r0, r3, 16
	asrs r0, 16
	adds r0, r6
	strh r0, [r1, 0x30]
	ldr r0, [r2]
	movs r6, 0
	strh r6, [r0, 0x32]
	ldr r0, [r2]
	ldr r1, =sub_80CCF30
	str r1, [r0, 0x1C]
	lsls r1, r7, 24
	lsrs r1, 24
	bl StartSpriteAnim
	mov r1, r9
	ldr r0, [r1]
	movs r3, 0xE4
	lsls r3, 3
	adds r0, r3
	adds r0, r5
	ldr r1, [r0]
	strh r4, [r1, 0x2E]
	ldr r2, [r0]
	movs r1, 0x1
	strh r1, [r2, 0x30]
	ldr r1, [r0]
	ldr r0, =sub_80CCF64
	str r0, [r1, 0x1C]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x1
	bls _080CCE2E
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCCFC

	thumb_func_start sub_80CCEE0
sub_80CCEE0: @ 80CCEE0
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0xDF
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CCF00
	movs r0, 0x4
	bl FreeSpriteTilesByTag
	b _080CCF06
	.pool
_080CCF00:
	movs r0, 0x3
	bl FreeSpriteTilesByTag
_080CCF06:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r3, 0xE4
	lsls r3, 3
	adds r2, r0, r3
	adds r3, 0x8
	adds r1, r0, r3
	ldr r1, [r1]
	str r1, [r2]
	ldr r2, =0x00000724
	adds r1, r0, r2
	adds r3, 0x4
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCEE0

	thumb_func_start sub_80CCF30
sub_80CCF30: @ 80CCF30
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x32]
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _080CCF44
	subs r0, r1, 0x1
	strh r0, [r2, 0x32]
	b _080CCF5C
_080CCF44:
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x30
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bne _080CCF5C
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_080CCF5C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCF30

	thumb_func_start sub_80CCF64
sub_80CCF64: @ 80CCF64
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x30]
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _080CCF78
	subs r0, r1, 0x1
	strh r0, [r2, 0x30]
	b _080CCF96
_080CCF78:
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x32]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC0
	bls _080CCF96
	adds r0, r2, 0
	bl DestroySprite
_080CCF96:
	pop {r0}
	bx r0
	thumb_func_end sub_80CCF64

	thumb_func_start sub_80CCF9C
sub_80CCF9C: @ 80CCF9C
	push {lr}
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	bl sub_80D20F8
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	movs r3, 0xDF
	lsls r3, 3
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CCFE4
	lsls r0, r1, 2
	ldr r1, =gUnknown_08577574
	adds r0, r1
	adds r3, 0x24
	adds r1, r2, r3
	ldrh r1, [r1]
	lsls r1, 1
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	movs r2, 0x2
	bl CpuSet
	b _080CCFFC
	.pool
_080CCFE4:
	lsls r0, r1, 2
	ldr r1, =gUnknown_08577574
	adds r0, r1
	ldr r3, =0x0000071e
	adds r1, r2, r3
	ldrh r1, [r1]
	lsls r1, 1
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	movs r2, 0x2
	bl CpuSet
_080CCFFC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CCF9C

	thumb_func_start sub_80CD00C
sub_80CD00C: @ 80CD00C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r1, r0, 0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	movs r0, 0xB0
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_80CD00C

	thumb_func_start sub_80CD02C
sub_80CD02C: @ 80CD02C
	push {r4,r5,lr}
	ldr r0, =gUnknown_0857B080
	bl LoadSpriteSheet
	movs r5, 0
_080CD036:
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 19
	movs r0, 0xB8
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	ldr r0, =gUnknown_0857B0E0
	movs r2, 0x1C
	movs r3, 0x16
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080CD088
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0x1
	cmp r5, 0
	bne _080CD076
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_080CD076:
	strh r0, [r4, 0x34]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r5, 2
	movs r2, 0xE6
	lsls r2, 3
	adds r0, r2
	adds r0, r1
	str r4, [r0]
_080CD088:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x1
	bls _080CD036
	bl sub_80CEADC
	lsls r0, 24
	cmp r0, 0
	beq _080CD0A2
	movs r0, 0x1
	bl sub_80CD1A8
_080CD0A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD02C

	thumb_func_start sub_80CD0B8
sub_80CD0B8: @ 80CD0B8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldr r7, =gUnknown_02039D08
	mov r12, r7
	movs r6, 0xE6
	lsls r6, 3
	movs r4, 0
	movs r3, 0x2
_080CD0CC:
	mov r0, r12
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r6
	adds r1, r0
	ldr r0, [r1]
	strh r4, [r0, 0x24]
	ldr r0, [r1]
	strh r3, [r0, 0x2E]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x1
	bls _080CD0CC
	lsls r0, r5, 24
	cmp r0, 0
	bge _080CD114
	ldr r1, [r7]
	movs r2, 0xE6
	lsls r2, 3
	adds r3, r1, r2
	ldr r2, [r3]
	movs r0, 0x1D
	strh r0, [r2, 0x30]
	ldr r0, =0x00000734
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x5
	strh r0, [r2, 0x30]
	ldr r0, [r3]
	movs r2, 0x48
	b _080CD130
	.pool
_080CD114:
	ldr r1, [r7]
	movs r2, 0xE6
	lsls r2, 3
	adds r3, r1, r2
	ldr r2, [r3]
	movs r0, 0x5
	strh r0, [r2, 0x30]
	ldr r0, =0x00000734
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x1D
	strh r0, [r2, 0x30]
	ldr r0, [r3]
	movs r2, 0xF8
_080CD130:
	strh r2, [r0, 0x32]
	ldr r0, [r1]
	strh r2, [r0, 0x32]
	ldr r1, [r7]
	movs r2, 0xE6
	lsls r2, 3
	adds r0, r1, r2
	ldr r2, [r0]
	movs r0, 0
	strh r0, [r2, 0x3C]
	ldr r0, =0x00000734
	adds r1, r0
	ldr r1, [r1]
	movs r0, 0x1
	strh r0, [r1, 0x3C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD0B8

	thumb_func_start sub_80CD158
sub_80CD158: @ 80CD158
	push {r4-r6,lr}
	movs r3, 0
	movs r5, 0
	movs r6, 0x5
	negs r6, r6
	ldr r4, =gUnknown_02039D08
_080CD164:
	ldr r1, [r4]
	lsls r0, r3, 2
	movs r2, 0xE6
	lsls r2, 3
	adds r1, r2
	adds r1, r0
	ldr r2, [r1]
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 3
	adds r0, 0x5C
	strh r0, [r2, 0x20]
	ldr r0, [r1]
	strh r5, [r0, 0x24]
	ldr r1, [r1]
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x1
	bls _080CD164
	movs r0, 0x1
	bl sub_80CD1A8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD158

	thumb_func_start sub_80CD1A8
sub_80CD1A8: @ 80CD1A8
	push {r4-r6,lr}
	lsls r0, 24
	cmp r0, 0
	beq _080CD1E4
	movs r2, 0
	ldr r6, =gUnknown_02039D08
	movs r5, 0xE6
	lsls r5, 3
	movs r3, 0
	movs r4, 0x1
_080CD1BC:
	ldr r1, [r6]
	lsls r0, r2, 2
	adds r1, r5
	adds r1, r0
	ldr r0, [r1]
	strh r4, [r0, 0x2E]
	ldr r0, [r1]
	strh r3, [r0, 0x30]
	ldr r0, [r1]
	strh r3, [r0, 0x32]
	ldr r0, [r1]
	strh r3, [r0, 0x36]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x1
	bls _080CD1BC
	b _080CD204
	.pool
_080CD1E4:
	movs r2, 0
	ldr r5, =gUnknown_02039D08
	movs r4, 0xE6
	lsls r4, 3
	movs r3, 0
_080CD1EE:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r4
	adds r0, r1
	ldr r0, [r0]
	strh r3, [r0, 0x2E]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x1
	bls _080CD1EE
_080CD204:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD1A8

	thumb_func_start sub_80CD210
sub_80CD210: @ 80CD210
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x4
	bhi _080CD2DC
	lsls r0, 2
	ldr r1, =_080CD22C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CD22C:
	.4byte _080CD240
	.4byte _080CD246
	.4byte _080CD274
	.4byte _080CD27A
	.4byte _080CD2CC
_080CD240:
	movs r0, 0
	strh r0, [r2, 0x24]
	b _080CD2DC
_080CD246:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _080CD2DC
	strh r1, [r2, 0x30]
	ldrh r0, [r2, 0x34]
	ldrh r3, [r2, 0x24]
	adds r0, r3
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080CD2DC
	strh r1, [r2, 0x32]
	strh r1, [r2, 0x24]
	b _080CD2DC
_080CD274:
	movs r0, 0x3
	strh r0, [r2, 0x2E]
	b _080CD2DC
_080CD27A:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r0, =0x000002ce
	adds r1, r0
	ldrh r0, [r2, 0x20]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r2, 0x20]
	subs r0, 0x49
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAE
	bls _080CD2A0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
_080CD2A0:
	ldrh r0, [r2, 0x30]
	subs r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080CD2DC
	ldrh r0, [r2, 0x32]
	strh r0, [r2, 0x20]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	movs r0, 0x4
	strh r0, [r2, 0x2E]
	b _080CD2DC
	.pool
_080CD2CC:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000002ce
	adds r0, r1
	ldrh r1, [r2, 0x20]
	ldrh r0, [r0]
	subs r1, r0
	strh r1, [r2, 0x20]
_080CD2DC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD210

	thumb_func_start sub_80CD2E8
sub_80CD2E8: @ 80CD2E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, [sp, 0x18]
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0857B0E0
	lsls r5, 16
	asrs r5, 16
	lsls r6, 16
	asrs r6, 16
	adds r1, r5, 0
	adds r2, r6, 0
	adds r3, r4, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080CD360
	movs r1, 0x1
	ands r1, r7
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r5, =gSprites
	adds r6, r4, r5
	adds r0, r6, 0
	bl StartSpriteAnim
	movs r0, 0x3
	mov r1, r8
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r6, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x5]
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =SpriteCallbackDummy
	str r0, [r4]
	adds r0, r6, 0
	b _080CD362
	.pool
_080CD360:
	movs r0, 0
_080CD362:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80CD2E8

	thumb_func_start sub_80CD36C
sub_80CD36C: @ 80CD36C
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	cmp r1, 0x1
	beq _080CD388
	ldr r1, =gUnknown_02039D78
	movs r0, 0
	strb r0, [r1]
	b _080CD38C
	.pool
_080CD388:
	ldr r0, =gUnknown_02039D78
	strb r1, [r0]
_080CD38C:
	ldr r0, =gUnknown_02039D79
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_02039D7A
	strb r1, [r0]
	ldr r0, =gUnknown_02039D7B
	strb r1, [r0]
	ldr r0, =gUnknown_02039D7C
	strb r1, [r0]
	ldr r0, =gUnknown_02039D7D
	strb r1, [r0]
	bl sub_80CDC0C
	bl sub_80CFC14
	ldr r2, =gUnknown_02039D08
	ldr r0, [r2]
	ldr r1, =0x00000cd6
	adds r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x000021ff
	adds r0, r1
	strb r3, [r0]
	bl sub_80CEB40
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD36C

	thumb_func_start sub_80CD3EC
sub_80CD3EC: @ 80CD3EC
	push {lr}
	bl sub_80CFC14
	bl sub_80CEBDC
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r1, =0x00000cd6
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	ldr r1, =0x000021ff
	adds r0, r1
	strb r2, [r0]
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CD426
	ldr r0, [r3]
	ldr r1, =0x000020a4
	adds r0, r1
	ldr r1, =gUnknown_02039D14
	movs r2, 0x64
	bl memcpy
	bl sub_80CAFC4
_080CD426:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD3EC

	thumb_func_start sub_80CD444
sub_80CD444: @ 80CD444
	push {r4-r6,lr}
	adds r4, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r0, 0x4
	bhi _080CD4FC
	lsls r0, 2
	ldr r1, =_080CD464
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CD464:
	.4byte _080CD478
	.4byte _080CD4A6
	.4byte _080CD4CE
	.4byte _080CD4D6
	.4byte _080CD4F4
_080CD478:
	adds r0, r5, 0
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x64
	strh r1, [r4]
	adds r0, r5, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x20
	strh r1, [r6]
	b _080CD4FC
_080CD4A6:
	cmp r5, 0
	bne _080CD4B2
	movs r0, 0x68
	strh r0, [r4]
	movs r0, 0x34
	b _080CD4FA
_080CD4B2:
	cmp r5, 0x6
	bne _080CD4BE
	movs r0, 0x98
	strh r0, [r4]
	movs r0, 0x84
	b _080CD4FA
_080CD4BE:
	movs r0, 0x98
	strh r0, [r4]
	subs r1, r5, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	b _080CD4FA
_080CD4CE:
	movs r0, 0xA2
	strh r0, [r4]
	movs r0, 0xC
	b _080CD4FA
_080CD4D6:
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	movs r1, 0xE
	cmp r0, 0
	beq _080CD4E2
	movs r1, 0x8
_080CD4E2:
	strh r1, [r6]
	movs r0, 0x58
	muls r0, r5
	adds r0, 0x78
	strh r0, [r4]
	b _080CD4FC
	.pool
_080CD4F4:
	movs r0, 0xA0
	strh r0, [r4]
	movs r0, 0x60
_080CD4FA:
	strh r0, [r6]
_080CD4FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80CD444

	thumb_func_start sub_80CD504
sub_80CD504: @ 80CD504
	push {lr}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _080CD538
	cmp r0, 0x1
	bne _080CD54C
	ldr r0, =gUnknown_02039D79
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	b _080CD542
	.pool
_080CD538:
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	movs r1, 0xB
	bl GetBoxMonDataFromSelectedBox
_080CD542:
	lsls r0, 16
	lsrs r0, 16
	b _080CD54E
	.pool
_080CD54C:
	movs r0, 0
_080CD54E:
	pop {r1}
	bx r1
	thumb_func_end sub_80CD504

	thumb_func_start sub_80CD554
sub_80CD554: @ 80CD554
	push {r4-r7,lr}
	ldr r7, =gUnknown_02039D08
	ldr r5, [r7]
	movs r0, 0xCD
	lsls r0, 4
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080CD57E
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	beq _080CD574
	movs r0, 0
	b _080CD69A
	.pool
_080CD574:
	bl sub_80D1218
	lsls r0, 24
	lsrs r0, 24
	b _080CD69A
_080CD57E:
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _080CD67C
	ldr r1, =0x00000cbc
	adds r4, r5, r1
	ldr r2, =0x00000cc4
	adds r1, r5, r2
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	movs r0, 0xCC
	lsls r0, 4
	adds r3, r5, r0
	adds r2, 0x4
	adds r1, r5, r2
	ldr r0, [r3]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r3]
	ldr r6, =0x00000cb4
	adds r1, r5, r6
	ldr r2, [r1]
	ldr r0, [r4]
	asrs r0, 8
	strh r0, [r2, 0x20]
	ldr r2, [r1]
	ldr r0, [r3]
	asrs r0, 8
	strh r0, [r2, 0x22]
	ldr r1, [r1]
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x80
	lsls r3, 1
	cmp r0, r3
	ble _080CD5DA
	ldr r4, =0xffffff00
	adds r0, r2, r4
	lsls r0, 16
	asrs r0, 16
	adds r0, 0x40
	strh r0, [r1, 0x20]
_080CD5DA:
	ldr r0, [r7]
	adds r0, r6
	ldr r1, [r0]
	ldrh r2, [r1, 0x20]
	movs r4, 0x20
	ldrsh r0, [r1, r4]
	cmp r0, 0x3F
	bgt _080CD5F6
	movs r0, 0x40
	subs r0, r2
	lsls r0, 16
	asrs r0, 16
	subs r0, r3, r0
	strh r0, [r1, 0x20]
_080CD5F6:
	ldr r0, [r7]
	adds r0, r6
	ldr r1, [r0]
	ldrh r2, [r1, 0x22]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0xB0
	ble _080CD612
	adds r0, r2, 0
	subs r0, 0xB0
	lsls r0, 16
	asrs r0, 16
	subs r0, 0x10
	strh r0, [r1, 0x22]
_080CD612:
	ldr r0, [r7]
	adds r0, r6
	ldr r2, [r0]
	ldrh r3, [r2, 0x22]
	movs r4, 0x22
	ldrsh r0, [r2, r4]
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080CD632
	subs r0, r1, r3
	movs r1, 0xB0
	lsls r0, 16
	asrs r0, 16
	subs r1, r0
	strh r1, [r2, 0x22]
_080CD632:
	ldr r0, [r7]
	ldr r2, =0x00000cd7
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080CD698
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _080CD698
	ldr r0, [r7]
	adds r0, r6
	ldr r2, [r0]
	adds r2, 0x3F
	ldrb r3, [r2]
	lsrs r1, r3, 1
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 1
	movs r0, 0x3
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	b _080CD698
	.pool
_080CD67C:
	ldr r3, =0x00000cb4
	adds r2, r5, r3
	ldr r1, [r2]
	ldr r4, =0x00000ccc
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1, 0x20]
	ldr r1, [r2]
	ldr r2, =0x00000cce
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1, 0x22]
	bl sub_80CDA68
_080CD698:
	movs r0, 0x1
_080CD69A:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CD554

	thumb_func_start sub_80CD6AC
sub_80CD6AC: @ 80CD6AC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r6, sp
	adds r6, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	adds r3, r6, 0
	bl sub_80CD444
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r2, =0x00000cd4
	adds r0, r2
	strb r4, [r0]
	ldr r0, [r1]
	ldr r3, =0x00000cd5
	adds r0, r3
	strb r5, [r0]
	ldr r1, [r1]
	mov r0, sp
	ldrh r2, [r0]
	subs r3, 0x9
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r6]
	ldr r2, =0x00000cce
	adds r1, r2
	strh r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD6AC

	thumb_func_start sub_80CD70C
sub_80CD70C: @ 80CD70C
	push {r4-r7,lr}
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldr r3, =0x00000cd2
	adds r1, r2, r3
	ldrh r1, [r1]
	adds r4, r0, 0
	cmp r1, 0
	beq _080CD730
	movs r0, 0xCD
	lsls r0, 4
	adds r1, r2, r0
	movs r0, 0xC
	b _080CD738
	.pool
_080CD730:
	movs r3, 0xCD
	lsls r3, 4
	adds r1, r2, r3
	movs r0, 0x6
_080CD738:
	strh r0, [r1]
	ldr r1, [r4]
	ldr r0, =0x00000cd7
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080CD752
	movs r3, 0xCD
	lsls r3, 4
	adds r0, r1, r3
	ldrh r0, [r0]
	lsrs r0, 1
	strb r0, [r2]
_080CD752:
	ldr r2, [r4]
	ldr r1, =0x00000cd2
	adds r0, r2, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080CD78C
	cmp r1, 0x1
	beq _080CD7AC
	ldr r3, =0x00000cce
	adds r0, r2, r3
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, =0x00000cb4
	adds r0, r2, r3
	ldr r0, [r0]
	movs r2, 0x22
	ldrsh r0, [r0, r2]
	b _080CD7C0
	.pool
_080CD78C:
	ldr r3, =0x00000cce
	adds r0, r2, r3
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, =0x00000cb4
	adds r0, r2, r3
	ldr r0, [r0]
	movs r2, 0x22
	ldrsh r0, [r0, r2]
	adds r0, 0xC0
	b _080CD7C0
	.pool
_080CD7AC:
	ldr r3, =0x00000cce
	adds r0, r2, r3
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, =0x00000cb4
	adds r0, r2, r3
	ldr r0, [r0]
	movs r2, 0x22
	ldrsh r0, [r0, r2]
	subs r0, 0xC0
_080CD7C0:
	subs r7, r1, r0
	ldr r2, [r4]
	ldr r3, =0x00000cd3
	adds r0, r2, r3
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080CD7FC
	cmp r1, 0x1
	beq _080CD81C
	ldr r1, =0x00000ccc
	adds r0, r2, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, =0x00000cb4
	adds r0, r2, r3
	ldr r0, [r0]
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	b _080CD830
	.pool
_080CD7FC:
	ldr r3, =0x00000ccc
	adds r0, r2, r3
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, =0x00000cb4
	adds r0, r2, r3
	ldr r0, [r0]
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	adds r0, 0xC0
	b _080CD830
	.pool
_080CD81C:
	ldr r3, =0x00000ccc
	adds r0, r2, r3
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, =0x00000cb4
	adds r0, r2, r3
	ldr r0, [r0]
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	subs r0, 0xC0
_080CD830:
	subs r0, r1, r0
	lsls r7, 8
	lsls r0, 8
	ldr r4, [r4]
	ldr r3, =0x00000cc4
	adds r6, r4, r3
	movs r1, 0xCD
	lsls r1, 4
	adds r5, r4, r1
	ldrh r1, [r5]
	bl __divsi3
	str r0, [r6]
	ldr r2, =0x00000cc8
	adds r6, r4, r2
	ldrh r1, [r5]
	adds r0, r7, 0
	bl __divsi3
	str r0, [r6]
	ldr r3, =0x00000cbc
	adds r2, r4, r3
	ldr r0, =0x00000cb4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r3, 0x20
	ldrsh r0, [r0, r3]
	lsls r0, 8
	str r0, [r2]
	movs r0, 0xCC
	lsls r0, 4
	adds r4, r0
	ldr r0, [r1]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	lsls r0, 8
	str r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD70C

	thumb_func_start sub_80CD894
sub_80CD894: @ 80CD894
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80CD6AC
	bl sub_80CD70C
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x3
	beq _080CD8E4
	ldr r2, =0x000021ff
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CD8FC
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CD8FC
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _080CD8FC
	.pool
_080CD8E4:
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	bne _080CD8FC
	ldr r0, [r5]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
_080CD8FC:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080CD95C
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CD930
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	movs r0, 0
	bl sub_80D0E50
	b _080CD93E
	.pool
_080CD930:
	cmp r0, 0x1
	bne _080CD93E
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	movs r0, 0x1
	bl sub_80D0E50
_080CD93E:
	cmp r4, 0
	bne _080CD950
	movs r0, 0
	adds r1, r6, 0
	bl sub_80D0D8C
	b _080CD95C
	.pool
_080CD950:
	cmp r4, 0x1
	bne _080CD988
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_80D0D8C
_080CD95C:
	cmp r4, 0x1
	bne _080CD988
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	beq _080CD988
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r2, =0x00000cd6
	adds r0, r2
	strb r4, [r0]
	ldr r0, [r1]
	ldr r1, =0x00000cb8
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
_080CD988:
	cmp r4, 0
	beq _080CD9E4
	cmp r4, 0
	blt _080CDA56
	cmp r4, 0x3
	bgt _080CDA56
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r2, =0x00000cb4
	adds r0, r2
	ldr r4, [r0]
	ldrb r1, [r4, 0x5]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r4, 0x5]
	ldr r0, [r5]
	ldr r4, =0x00000cb8
	adds r0, r4
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r4
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	ands r2, r0
	orrs r2, r3
	strb r2, [r1, 0x5]
	b _080CDA56
	.pool
_080CD9E4:
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	ldr r2, =0x000021ff
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CDA28
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r3]
	ldr r1, =0x00000cb8
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	b _080CDA56
	.pool
_080CDA28:
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CDA56
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CDA56
	movs r0, 0x2
	bl sub_80CC0D4
_080CDA56:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CD894

	thumb_func_start sub_80CDA68
sub_80CDA68: @ 80CDA68
	push {r4,lr}
	ldr r1, =gUnknown_02039D78
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	ldr r3, =0x00000cd4
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, =gUnknown_02039D79
	adds r3, 0x1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2, 0x1]
	cmp r0, 0x3
	beq _080CDAC0
	ldr r1, =0x000021ff
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CDAD8
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CDAD8
	subs r3, 0x21
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	b _080CDAD8
	.pool
_080CDAC0:
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	bne _080CDAD8
	ldr r0, [r4]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
_080CDAD8:
	bl sub_80CEB40
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	beq _080CDB0E
	cmp r0, 0x1
	bgt _080CDAFC
	cmp r0, 0
	beq _080CDB30
	b _080CDB8A
	.pool
_080CDAFC:
	cmp r0, 0x2
	beq _080CDB06
	cmp r0, 0x3
	bne _080CDB8A
	b _080CDB1E
_080CDB06:
	movs r0, 0x1
	bl sub_80CD1A8
	b _080CDB8A
_080CDB0E:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00000cb8
	adds r0, r2
	ldr r0, [r0]
	adds r0, 0x43
	movs r1, 0xD
	strb r1, [r0]
_080CDB1E:
	movs r0, 0x1
	bl sub_80CC0D4
	b _080CDB8A
	.pool
_080CDB30:
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r3, =0x000021ff
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CDB8A
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldr r3, [r0]
	ldrb r1, [r3, 0x5]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r0, [r4]
	ldr r3, =0x00000cb8
	adds r0, r3
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	ands r2, r0
	movs r0, 0x8
	orrs r2, r0
	strb r2, [r1, 0x5]
	ldr r0, [r4]
	adds r0, r3
	ldr r0, [r0]
	adds r0, 0x43
	movs r1, 0x15
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	movs r0, 0x2
	bl sub_80CC0D4
_080CDB8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CDA68

	thumb_func_start sub_80CDBA0
sub_80CDBA0: @ 80CDBA0
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CDBB4
	movs r3, 0
	b _080CDBC2
	.pool
_080CDBB4:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x5
	bls _080CDBC2
	movs r3, 0x5
_080CDBC2:
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldr r1, =0x00000cb4
	adds r0, r2, r1
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080CDBE0
	ldr r0, =0x00000cd7
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080CDBE0:
	movs r0, 0x1
	adds r1, r3, 0
	bl sub_80CD894
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CDBA0

	thumb_func_start sub_80CDBF8
sub_80CDBF8: @ 80CDBF8
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_80CD894
	pop {r0}
	bx r0
	thumb_func_end sub_80CDBF8

	thumb_func_start sub_80CDC0C
sub_80CDC0C: @ 80CDC0C
	ldr r1, =gUnknown_02039D7E
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80CDC0C

	thumb_func_start sub_80CDC18
sub_80CDC18: @ 80CDC18
	ldr r0, =gUnknown_02039D7E
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CDC18

	thumb_func_start sub_80CDC2C
sub_80CDC2C: @ 80CDC2C
	ldr r0, =gUnknown_02039D7E
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CDC2C

	thumb_func_start sub_80CDC38
sub_80CDC38: @ 80CDC38
	lsls r0, 24
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	ldr r2, =0x00000d8c
	adds r3, r1, r2
	ldr r2, =gUnknown_0857B998
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	str r0, [r3]
	movs r0, 0xD9
	lsls r0, 4
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80CDC38

	thumb_func_start sub_80CDC64
sub_80CDC64: @ 80CDC64
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _080CDC84
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000d8c
	adds r1, r2
	ldr r2, =sub_80CDEB4
	b _080CDC8E
	.pool
_080CDC84:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000d8c
	adds r1, r2
	ldr r2, =sub_80CDEC4
_080CDC8E:
	str r2, [r1]
	ldr r0, [r0]
	movs r1, 0xD9
	lsls r1, 4
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CDC64

	thumb_func_start sub_80CDCAC
sub_80CDCAC: @ 80CDCAC
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000d8c
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CDCAC

	thumb_func_start sub_80CDCCC
sub_80CDCCC: @ 80CDCCC
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	movs r5, 0xD9
	lsls r5, 4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CDD1C
	cmp r0, 0x1
	bgt _080CDCEC
	cmp r0, 0
	beq _080CDCF6
	b _080CDD54
	.pool
_080CDCEC:
	cmp r0, 0x2
	beq _080CDD40
	cmp r0, 0x3
	beq _080CDCFE
	b _080CDD54
_080CDCF6:
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CDD08
_080CDCFE:
	movs r0, 0
	b _080CDD56
	.pool
_080CDD08:
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	b _080CDD4A
	.pool
_080CDD1C:
	bl sub_80CDED4
	lsls r0, 24
	cmp r0, 0
	bne _080CDD54
	ldr r0, [r4]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
	bl sub_80CDF38
	b _080CDD4A
	.pool
_080CDD40:
	bl sub_80CDF08
	lsls r0, 24
	cmp r0, 0
	bne _080CDD54
_080CDD4A:
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080CDD54:
	movs r0, 0x1
_080CDD56:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80CDCCC

	thumb_func_start sub_80CDD5C
sub_80CDD5C: @ 80CDD5C
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	movs r5, 0xD9
	lsls r5, 4
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CDDA4
	cmp r0, 0x1
	bgt _080CDD7C
	cmp r0, 0
	beq _080CDD82
	b _080CDDD0
	.pool
_080CDD7C:
	cmp r0, 0x2
	beq _080CDDCC
	b _080CDDD0
_080CDD82:
	bl sub_80CDED4
	lsls r0, 24
	cmp r0, 0
	bne _080CDDD0
	ldr r0, [r4]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	bl sub_80CDFAC
	b _080CDDBC
	.pool
_080CDDA4:
	bl sub_80CDF08
	lsls r0, 24
	cmp r0, 0
	bne _080CDDD0
	ldr r0, [r4]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
_080CDDBC:
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080CDDD0
	.pool
_080CDDCC:
	movs r0, 0
	b _080CDDD2
_080CDDD0:
	movs r0, 0x1
_080CDDD2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80CDD5C

	thumb_func_start sub_80CDDD8
sub_80CDDD8: @ 80CDDD8
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	movs r5, 0xD9
	lsls r5, 4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CDE68
	cmp r0, 0x1
	bgt _080CDDF8
	cmp r0, 0
	beq _080CDDFE
	b _080CDEAC
	.pool
_080CDDF8:
	cmp r0, 0x2
	beq _080CDEA8
	b _080CDEAC
_080CDDFE:
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _080CDE20
	cmp r0, 0x1
	bne _080CDEA8
	ldr r0, =0x00000d91
	adds r1, r0
	movs r0, 0xE
	b _080CDE2A
	.pool
_080CDE20:
	bl StorageGetCurrentBox
	ldr r1, [r4]
	ldr r2, =0x00000d91
	adds r1, r2
_080CDE2A:
	strb r0, [r1]
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	ldr r0, [r4]
	ldr r2, =0x00000d91
	adds r0, r2
	ldrb r0, [r0]
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	bl sub_80CBD5C
	ldr r1, [r4]
	movs r0, 0xD9
	lsls r0, 4
	adds r1, r0
	b _080CDE94
	.pool
_080CDE68:
	bl sub_80CBDC4
	lsls r0, 24
	cmp r0, 0
	bne _080CDEAC
	ldr r0, [r4]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
	ldr r0, [r4]
	ldr r2, =0x00000d91
	adds r0, r2
	ldrb r0, [r0]
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	bl diegohint1
	ldr r1, [r4]
	adds r1, r5
_080CDE94:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080CDEAC
	.pool
_080CDEA8:
	movs r0, 0
	b _080CDEAE
_080CDEAC:
	movs r0, 0x1
_080CDEAE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80CDDD8

	thumb_func_start sub_80CDEB4
sub_80CDEB4: @ 80CDEB4
	push {lr}
	bl sub_80CDED4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80CDEB4

	thumb_func_start sub_80CDEC4
sub_80CDEC4: @ 80CDEC4
	push {lr}
	bl sub_80CDF08
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80CDEC4

	thumb_func_start sub_80CDED4
sub_80CDED4: @ 80CDED4
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r1, [r0]
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080CDEEC
	cmp r0, 0x8
	beq _080CDEFC
_080CDEEC:
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _080CDF00
	.pool
_080CDEFC:
	movs r0, 0
	b _080CDF02
_080CDF00:
	movs r0, 0x1
_080CDF02:
	pop {r1}
	bx r1
	thumb_func_end sub_80CDED4

	thumb_func_start sub_80CDF08
sub_80CDF08: @ 80CDF08
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r1, [r0]
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080CDF30
	ldrh r0, [r1, 0x26]
	subs r0, 0x1
	strh r0, [r1, 0x26]
	movs r0, 0x1
	b _080CDF32
	.pool
_080CDF30:
	movs r0, 0
_080CDF32:
	pop {r1}
	bx r1
	thumb_func_end sub_80CDF08

	thumb_func_start sub_80CDF38
sub_80CDF38: @ 80CDF38
	push {r4,lr}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _080CDF68
	cmp r0, 0x1
	bne _080CDF94
	ldr r4, =gUnknown_02039D79
	ldrb r1, [r4]
	movs r0, 0xE
	bl sub_80CE018
	ldrb r1, [r4]
	movs r0, 0
	bl sub_80CBC14
	b _080CDF8E
	.pool
_080CDF68:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000021ff
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CDF8E
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_02039D79
	ldrb r1, [r4]
	bl sub_80CE018
	ldrb r1, [r4]
	movs r0, 0x1
	bl sub_80CBC14
_080CDF8E:
	ldr r1, =gUnknown_02039D7A
	movs r0, 0x1
	strb r0, [r1]
_080CDF94:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CDF38

	thumb_func_start sub_80CDFAC
sub_80CDFAC: @ 80CDFAC
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _080CDFDC
	cmp r0, 0x1
	bne _080CDFFE
	ldr r4, =gUnknown_02039D79
	ldrb r1, [r4]
	movs r0, 0xE
	bl diegohint2
	ldrb r1, [r4]
	movs r0, 0xE
	bl sub_80CBCAC
	b _080CDFF8
	.pool
_080CDFDC:
	bl StorageGetCurrentBox
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_02039D79
	ldrb r1, [r5]
	adds r0, r4, 0
	bl diegohint2
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_80CBCAC
_080CDFF8:
	ldr r1, =gUnknown_02039D7A
	movs r0, 0
	strb r0, [r1]
_080CDFFE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CDFAC

	thumb_func_start sub_80CE00C
sub_80CE00C: @ 80CE00C
	push {lr}
	bl sub_80CEB40
	pop {r0}
	bx r0
	thumb_func_end sub_80CE00C

	thumb_func_start sub_80CE018
sub_80CE018: @ 80CE018
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r4, 0xE
	bne _080CE054
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000020a4
	adds r0, r1
	ldr r3, =gPlayerParty
	ldr r1, =gUnknown_02039D79
	movs r2, 0
	ldrsb r2, [r1, r2]
	movs r1, 0x64
	muls r1, r2
	adds r1, r3
	movs r2, 0x64
	bl memcpy
	b _080CE064
	.pool
_080CE054:
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldr r0, =0x000020a4
	adds r2, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80D2054
_080CE064:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80CE0E8
	ldr r0, =gUnknown_02039D7B
	strb r4, [r0]
	ldr r0, =gUnknown_02039D7C
	strb r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE018

	thumb_func_start diegohint2
diegohint2: @ 80CE08C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r6, 0xE
	bne _080CE0C0
	ldr r1, =gPlayerParty
	movs r0, 0x64
	muls r0, r7
	adds r0, r1
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	ldr r2, =0x000020a4
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	b _080CE0D8
	.pool
_080CE0C0:
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x000020a4
	adds r0, r4
	bl BoxMonRestorePP
	ldr r2, [r5]
	adds r2, r4
	adds r0, r6, 0
	adds r1, r7, 0
	bl CopyBoxMonFromAnyBox
_080CE0D8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end diegohint2

	thumb_func_start sub_80CE0E8
sub_80CE0E8: @ 80CE0E8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r0, 0xE
	bne _080CE108
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl ZeroMonData
	b _080CE10C
	.pool
_080CE108:
	bl sub_80D2018
_080CE10C:
	pop {r0}
	bx r0
	thumb_func_end sub_80CE0E8

	thumb_func_start diegohint1
diegohint1: @ 80CE110
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r6, 0xE
	bne _080CE144
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002108
	adds r0, r1
	ldr r2, =gPlayerParty
	movs r1, 0x64
	muls r1, r7
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	b _080CE154
	.pool
_080CE144:
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldr r0, =0x00002108
	adds r2, r0
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80D2054
_080CE154:
	adds r0, r6, 0
	adds r1, r7, 0
	bl diegohint2
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldr r4, =0x000020a4
	adds r0, r1, r4
	ldr r2, =0x00002108
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	bl sub_80CEC00
	ldr r0, =gUnknown_02039D7B
	strb r6, [r0]
	ldr r0, =gUnknown_02039D7C
	strb r7, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end diegohint1

	thumb_func_start sub_80CE19C
sub_80CE19C: @ 80CE19C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	bl GetFirstFreeBoxSpot
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080CE1BA
	movs r0, 0
	b _080CE21A
_080CE1BA:
	ldr r5, =gUnknown_02039D7A
	ldrb r0, [r5]
	cmp r0, 0
	beq _080CE1DC
	lsls r4, 24
	lsrs r1, r4, 24
	adds r0, r6, 0
	bl diegohint2
	bl sub_80CBAC4
	movs r0, 0
	strb r0, [r5]
	b _080CE1F6
	.pool
_080CE1DC:
	ldr r5, =gUnknown_02039D79
	ldrb r1, [r5]
	movs r0, 0xE
	bl sub_80CE018
	lsls r4, 24
	lsrs r1, r4, 24
	adds r0, r6, 0
	bl diegohint2
	ldrb r0, [r5]
	bl sub_80CBB68
_080CE1F6:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _080CE208
	lsrs r0, r4, 24
	bl sub_80CB140
_080CE208:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	movs r0, 0x1
_080CE21A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CE19C

	thumb_func_start sub_80CE22C
sub_80CE22C: @ 80CE22C
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	bl sub_80CEB40
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE22C

	thumb_func_start sub_80CE250
sub_80CE250: @ 80CE250
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE264
	movs r2, 0x2
	b _080CE274
	.pool
_080CE264:
	ldr r0, =gUnknown_02039D78
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r2, 0x1
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r2, r0, 31
_080CE274:
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	adds r0, r2, 0
	bl sub_80CBF14
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x000021e0
	adds r0, r1, r2
	ldr r2, =0x00000cee
	adds r1, r2
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE250

	thumb_func_start sub_80CE2A8
sub_80CE2A8: @ 80CE2A8
	push {lr}
	bl sub_80CBFD8
	lsls r0, 24
	cmp r0, 0
	beq _080CE2B8
	movs r0, 0x1
	b _080CE2CA
_080CE2B8:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	movs r0, 0
_080CE2CA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CE2A8

	thumb_func_start sub_80CE2D8
sub_80CE2D8: @ 80CE2D8
	push {lr}
	bl sub_80CC020
	ldr r1, =gUnknown_02039D7A
	ldrb r0, [r1]
	cmp r0, 0
	beq _080CE2F0
	movs r0, 0
	strb r0, [r1]
	b _080CE316
	.pool
_080CE2F0:
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CE304
	movs r2, 0xE
	b _080CE30C
	.pool
_080CE304:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r2, r0, 24
_080CE30C:
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	adds r0, r2, 0
	bl sub_80CE0E8
_080CE316:
	bl sub_80CEB40
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE2D8

	thumb_func_start sub_80CE324
sub_80CE324: @ 80CE324
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE33E
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
_080CE33E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE324

	thumb_func_start sub_80CE350
sub_80CE350: @ 80CE350
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_0857B9A4
_080CE358:
	movs r1, 0
	ldrsb r1, [r4, r1]
	cmp r1, 0x22
	beq _080CE378
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r0, 0x4
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _080CE37E
	movs r1, 0x1
	ldrsb r1, [r4, r1]
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _080CE37E
_080CE378:
	ldrh r0, [r4, 0x2]
	strh r0, [r3]
	adds r3, 0x2
_080CE37E:
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0x5
	bls _080CE358
	ldr r1, =0x00000163
	adds r0, r1, 0
	strh r0, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE350

	thumb_func_start sub_80CE3A0
sub_80CE3A0: @ 80CE3A0
	push {r4,r5,lr}
	bl sub_80CE51C
	adds r3, r0, 0
	cmp r3, 0
	bne _080CE3D0
	ldr r2, =gUnknown_02039D08
	ldr r0, [r2]
	ldr r1, =0x0000216d
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x0000216c
	adds r0, r2
	strb r3, [r0]
	b _080CE504
	.pool
_080CE3D0:
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE418
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r3, =0x00002108
	adds r0, r1, r3
	ldr r2, =0x000020a4
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	ldr r0, [r4]
	ldr r3, =0x00002170
	adds r0, r3
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, =0x00002171
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	b _080CE494
	.pool
_080CE418:
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CE464
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r2, =0x00002108
	adds r0, r2
	ldr r3, =gPlayerParty
	ldr r1, =gUnknown_02039D79
	movs r2, 0
	ldrsb r2, [r1, r2]
	movs r1, 0x64
	muls r1, r2
	adds r1, r3
	movs r2, 0x64
	bl memcpy
	ldr r0, [r4]
	ldr r3, =0x00002170
	adds r0, r3
	movs r1, 0xE
	strb r1, [r0]
	b _080CE488
	.pool
_080CE464:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	ldr r3, =0x00002108
	adds r2, r3
	bl sub_80D2054
	bl StorageGetCurrentBox
	ldr r1, [r4]
	ldr r2, =0x00002170
	adds r1, r2
	strb r0, [r1]
_080CE488:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	ldr r3, =0x00002171
	adds r0, r3
_080CE494:
	strb r1, [r0]
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x00002176
	adds r0, r4
	bl sub_80CE350
	ldr r2, [r5]
	ldr r1, =0x00002108
	adds r0, r2, r1
	adds r2, r4
	movs r1, 0x51
	bl GetMonData
	ldr r2, [r5]
	ldr r3, =0x00002174
	adds r1, r2, r3
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _080CE4E8
	ldr r0, =0x0000216d
	adds r1, r2, r0
	movs r0, 0
	strb r0, [r1]
	b _080CE4F8
	.pool
_080CE4E8:
	ldr r1, =0x0000216d
	adds r0, r2, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, =0x0000216c
	adds r0, r2
	strb r1, [r0]
_080CE4F8:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r3, =0x00002172
	adds r0, r3
	movs r1, 0
	strh r1, [r0]
_080CE504:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE3A0

	thumb_func_start sub_80CE51C
sub_80CE51C: @ 80CE51C
	push {r4-r6,lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r5, r0, 31
	movs r4, 0
_080CE52A:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _080CE53E
	adds r5, 0x1
_080CE53E:
	adds r4, 0x1
	cmp r4, 0x5
	ble _080CE52A
	cmp r5, 0x2
	ble _080CE554
_080CE548:
	movs r0, 0x1
	b _080CE578
	.pool
_080CE554:
	movs r6, 0
_080CE556:
	movs r4, 0
_080CE558:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80D2270
	cmp r0, 0
	beq _080CE56A
	adds r5, 0x1
	cmp r5, 0x2
	bgt _080CE548
_080CE56A:
	adds r4, 0x1
	cmp r4, 0x1D
	ble _080CE558
	adds r6, 0x1
	cmp r6, 0xD
	ble _080CE556
	movs r0, 0
_080CE578:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80CE51C

	thumb_func_start sub_80CE580
sub_80CE580: @ 80CE580
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
	ldr r3, =0x0000216d
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r5, r0, 0
	cmp r1, 0
	beq _080CE5B0
	ldr r1, =0x0000216c
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _080CE736
	.pool
_080CE5B0:
	ldr r3, =0x00002172
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _080CE5C4
	cmp r0, 0x1
	beq _080CE690
	b _080CE732
	.pool
_080CE5C4:
	movs r6, 0
_080CE5C6:
	ldr r2, [r5]
	ldr r1, =0x00002170
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xE
	bne _080CE5E4
	ldr r3, =0x00002171
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, r6
	beq _080CE606
_080CE5E4:
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =0x00002176
	adds r2, r1
	movs r1, 0x51
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r1, [r5]
	ldr r2, =0x00002174
	adds r1, r2
	ldrh r0, [r1]
	bics r0, r4
	strh r0, [r1]
_080CE606:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _080CE5C6
	ldr r2, =gUnknown_02039D08
	ldr r1, [r2]
	ldr r3, =0x00002174
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, 0
	bne _080CE64C
	subs r3, 0x7
	adds r0, r1, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x0000216c
	adds r0, r2
	strb r1, [r0]
	b _080CE732
	.pool
_080CE64C:
	ldr r3, =0x0000216e
	adds r0, r1, r3
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, =0x00002172
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _080CE732
	.pool
_080CE674:
	ldr r1, =0x0000216d
	adds r0, r5, r1
	movs r1, 0x1
	strb r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r3, =0x0000216c
	adds r0, r3
	strb r1, [r0]
	b _080CE732
	.pool
_080CE690:
	movs r6, 0
	mov r8, r5
	ldr r7, =0x0000ffff
_080CE696:
	mov r0, r8
	ldr r3, [r0]
	ldr r1, =0x0000216e
	adds r0, r3, r1
	ldrb r0, [r0]
	ldr r2, =0x0000216f
	adds r1, r3, r2
	ldrb r1, [r1]
	adds r2, 0x7
	adds r3, r2
	movs r2, 0x51
	bl GetAndCopyBoxMonDataFromAnyBox
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080CE6E0
	ldr r5, [r5]
	ldr r3, =0x00002170
	adds r0, r5, r3
	ldrh r2, [r0]
	ldr r1, =0x0000216e
	adds r0, r5, r1
	ldrh r3, [r0]
	adds r1, r7, 0
	ands r1, r2
	adds r0, r7, 0
	ands r0, r3
	cmp r1, r0
	beq _080CE6E0
	ldr r2, =0x00002174
	adds r1, r5, r2
	ldrh r0, [r1]
	bics r0, r4
	strh r0, [r1]
	cmp r0, 0
	beq _080CE674
_080CE6E0:
	ldr r2, =gUnknown_02039D08
	ldr r1, [r2]
	ldr r3, =0x0000216f
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	movs r3, 0
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	adds r5, r2, 0
	cmp r0, 0x1D
	ble _080CE728
	ldr r0, [r2]
	ldr r1, =0x0000216f
	adds r0, r1
	strb r3, [r0]
	ldr r1, [r2]
	ldr r0, =0x0000216e
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xD
	ble _080CE728
	ldr r0, [r2]
	ldr r1, =0x0000216d
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x0000216c
	adds r0, r2
	strb r3, [r0]
_080CE728:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1D
	bls _080CE696
_080CE732:
	movs r0, 0x1
	negs r0, r0
_080CE736:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CE580

	thumb_func_start sub_80CE760
sub_80CE760: @ 80CE760
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE77A
	ldr r0, =gUnknown_02039D14
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	ldr r2, =0x000020a4
	adds r1, r2
	movs r2, 0x64
	bl memcpy
_080CE77A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE760

	thumb_func_start sub_80CE790
sub_80CE790: @ 80CE790
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE7D8
	ldr r0, =gUnknown_02039D7B
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _080CE7C8
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000020a4
	adds r0, r1
	ldr r1, =gUnknown_02039D14
	movs r2, 0x64
	bl memcpy
	b _080CE7D8
	.pool
_080CE7C8:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000020a4
	adds r0, r1
	ldr r1, =gUnknown_02039D14
	movs r2, 0x50
	bl memcpy
_080CE7D8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE790

	thumb_func_start sub_80CE7E8
sub_80CE7E8: @ 80CE7E8
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r5, [r0]
	cmp r5, 0
	beq _080CE838
	bl sub_80CE760
	ldr r3, =gUnknown_02039D08
	ldr r1, [r3]
	ldr r0, =0x0000218c
	adds r2, r1, r0
	ldr r0, =gUnknown_02039D14
	str r0, [r2]
	ldr r2, =0x00002187
	adds r1, r2
	movs r2, 0
	strb r2, [r1]
	ldr r0, [r3]
	ldr r4, =0x00002186
	adds r0, r4
	strb r2, [r0]
	ldr r0, [r3]
	ldr r1, =0x00002188
	adds r0, r1
	strb r2, [r0]
	b _080CE8CA
	.pool
_080CE838:
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CE894
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r0, =0x0000218c
	adds r2, r1, r0
	ldr r0, =gPlayerParty
	str r0, [r2]
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	ldr r2, =0x00002187
	adds r1, r2
	strb r0, [r1]
	bl CountPartyMons
	ldr r1, [r4]
	subs r0, 0x1
	ldr r2, =0x00002186
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r4, =0x00002188
	adds r0, r4
	strb r5, [r0]
	b _080CE8CA
	.pool
_080CE894:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetBoxedMonPtr
	ldr r3, =gUnknown_02039D08
	ldr r2, [r3]
	ldr r4, =0x0000218c
	adds r1, r2, r4
	str r0, [r1]
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	ldr r1, =0x00002187
	adds r2, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldr r2, =0x00002186
	adds r0, r2
	movs r1, 0x1D
	strb r1, [r0]
	ldr r0, [r3]
	subs r4, 0x4
	adds r0, r4
	movs r1, 0x2
	strb r1, [r0]
_080CE8CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE7E8

	thumb_func_start sub_80CE8E4
sub_80CE8E4: @ 80CE8E4
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE8F8
	bl sub_80CE790
	b _080CE900
	.pool
_080CE8F8:
	ldr r0, =gUnknown_02039D79
	ldr r1, =gUnknown_0203CF20
	ldrb r1, [r1]
	strb r1, [r0]
_080CE900:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE8E4

	thumb_func_start CompactPartySlots
CompactPartySlots: @ 80CE90C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r7, =0x0000ffff
	movs r6, 0
	movs r5, 0
	movs r0, 0x64
	mov r9, r0
	ldr r1, =gPlayerParty
	mov r8, r1
	subs r0, 0x65
	mov r10, r0
_080CE928:
	mov r0, r9
	muls r0, r6
	mov r1, r8
	adds r4, r0, r1
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	cmp r0, 0
	beq _080CE960
	cmp r6, r5
	beq _080CE950
	mov r0, r9
	muls r0, r5
	add r0, r8
	adds r1, r4, 0
	movs r2, 0x64
	bl memcpy
_080CE950:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _080CE96A
	.pool
_080CE960:
	lsls r0, r7, 16
	asrs r0, 16
	cmp r0, r10
	bne _080CE96A
	adds r7, r6, 0
_080CE96A:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _080CE928
	lsls r7, 16
	cmp r5, 0x5
	bhi _080CE992
	movs r6, 0x64
	ldr r4, =gPlayerParty
_080CE97E:
	adds r0, r5, 0
	muls r0, r6
	adds r0, r4
	bl ZeroMonData
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _080CE97E
_080CE992:
	asrs r0, r7, 16
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CompactPartySlots

	thumb_func_start sub_80CE9A8
sub_80CE9A8: @ 80CE9A8
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	ldr r2, =gUnknown_02039D08
	ldr r1, [r2]
	ldr r3, =0x00000ceb
	adds r1, r3
	strb r0, [r1]
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CE9E8
	ldr r0, [r2]
	ldr r1, =0x000020a4
	adds r0, r1
	movs r1, 0x8
	mov r2, sp
	bl SetMonData
	b _080CEA1C
	.pool
_080CE9E8:
	ldr r4, =gUnknown_02039D78
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0x1
	bne _080CEA08
	ldr r0, =gUnknown_02039D79
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x8
	mov r2, sp
	bl SetMonData
_080CEA08:
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0
	bne _080CEA1C
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	movs r1, 0x8
	mov r2, sp
	bl SetBoxMonDataFromSelectedBox
_080CEA1C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CE9A8

	thumb_func_start sub_80CEA30
sub_80CEA30: @ 80CEA30
	push {lr}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CEA64
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CEA64
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	bl CountPartyAliveNonEggMonsExcept
	lsls r0, 24
	cmp r0, 0
	bne _080CEA64
	movs r0, 0x1
	b _080CEA66
	.pool
_080CEA64:
	movs r0, 0
_080CEA66:
	pop {r1}
	bx r1
	thumb_func_end sub_80CEA30

	thumb_func_start sub_80CEA6C
sub_80CEA6C: @ 80CEA6C
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CEAC8
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CEAAC
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	bl CountPartyAliveNonEggMonsExcept
	lsls r0, 24
	cmp r0, 0
	bne _080CEAAC
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000ced
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CEAC8
	ldr r2, =0x000020a4
	adds r0, r1, r2
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080CEAC8
_080CEAAC:
	movs r0, 0x1
	b _080CEACA
	.pool
_080CEAC8:
	movs r0, 0
_080CEACA:
	pop {r1}
	bx r1
	thumb_func_end sub_80CEA6C

	thumb_func_start sub_80CEAD0
sub_80CEAD0: @ 80CEAD0
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CEAD0

	thumb_func_start sub_80CEADC
sub_80CEADC: @ 80CEADC
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x2
	bne _080CEAEE
	movs r1, 0x1
_080CEAEE:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CEADC

	thumb_func_start sub_80CEAF8
sub_80CEAF8: @ 80CEAF8
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x3
	bne _080CEB16
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CEB16
	movs r1, 0x1
_080CEB16:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CEAF8

	thumb_func_start sub_80CEB24
sub_80CEB24: @ 80CEB24
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CEB36
	movs r1, 0x1
_080CEB36:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CEB24

	thumb_func_start sub_80CEB40
sub_80CEB40: @ 80CEB40
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	movs r2, 0
	ldr r3, =gUnknown_02039D7A
	ldrb r0, [r3]
	cmp r0, 0
	bne _080CEB52
	movs r2, 0x1
_080CEB52:
	ldr r4, =0x00000cea
	adds r0, r1, r4
	strb r2, [r0]
	ldrb r0, [r3]
	cmp r0, 0
	bne _080CEBD0
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	beq _080CEB8A
	cmp r0, 0x1
	bgt _080CEB84
	cmp r0, 0
	beq _080CEBBA
	b _080CEBD0
	.pool
_080CEB84:
	cmp r0, 0x3
	bgt _080CEBD0
	b _080CEBB0
_080CEB8A:
	ldr r1, =gUnknown_02039D79
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0x5
	bgt _080CEBB0
	adds r1, r0, 0
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	bl sub_80CEC00
	b _080CEBD0
	.pool
_080CEBB0:
	movs r0, 0
	movs r1, 0x2
	bl sub_80CEC00
	b _080CEBD0
_080CEBBA:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	bl GetBoxedMonPtr
	movs r1, 0x1
	bl sub_80CEC00
_080CEBD0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CEB40

	thumb_func_start sub_80CEBDC
sub_80CEBDC: @ 80CEBDC
	push {lr}
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CEBF8
	ldr r0, =gUnknown_02039D14
	movs r1, 0
	bl sub_80CEC00
	b _080CEBFC
	.pool
_080CEBF8:
	bl sub_80CEB40
_080CEBFC:
	pop {r0}
	bx r0
	thumb_func_end sub_80CEBDC

	thumb_func_start sub_80CEC00
sub_80CEC00: @ 80CEC00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	ldr r0, =gUnknown_02039D08
	mov r8, r0
	ldr r1, [r0]
	ldr r3, =0x00000ce6
	adds r2, r1, r3
	movs r0, 0
	strh r0, [r2]
	mov r9, r0
	mov r10, r0
	cmp r5, 0
	bne _080CED18
	adds r6, r4, 0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	mov r2, r8
	ldr r1, [r2]
	ldr r3, =0x00000ce4
	adds r1, r3
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _080CEC44
	b _080CEE34
_080CEC44:
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0
	beq _080CEC74
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00000ced
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _080CEC86
	.pool
_080CEC74:
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, r8
	ldr r1, [r3]
	ldr r2, =0x00000ced
	adds r1, r2
	strb r0, [r1]
_080CEC86:
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	ldr r5, =0x00000cee
	adds r2, r5
	adds r0, r6, 0
	movs r1, 0x2
	bl GetMonData
	ldr r0, [r4]
	adds r0, r5
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [r4]
	ldr r3, =0x00000cec
	adds r1, r3
	strb r0, [r1]
	adds r0, r6, 0
	movs r1, 0x8
	bl GetMonData
	ldr r1, [r4]
	ldr r2, =0x00000ceb
	adds r1, r2
	strb r0, [r1]
	adds r0, r6, 0
	movs r1, 0
	bl GetMonData
	ldr r1, [r4]
	movs r3, 0xCE
	lsls r3, 4
	adds r1, r3
	str r0, [r1]
	adds r0, r6, 0
	bl GetMonFrontSpritePal
	ldr r1, [r4]
	ldr r2, =0x00000cdc
	adds r1, r2
	str r0, [r1]
	adds r0, r6, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl GetMonData
	ldr r1, [r4]
	ldr r3, =0x00000ce6
	adds r1, r3
	strh r0, [r1]
	b _080CEE26
	.pool
_080CED18:
	cmp r5, 0x1
	beq _080CED1E
	b _080CEE1C
_080CED1E:
	adds r7, r4, 0
	adds r0, r7, 0
	movs r1, 0x41
	bl GetBoxMonData
	mov r2, r8
	ldr r1, [r2]
	ldr r3, =0x00000ce4
	adds r1, r3
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _080CED3A
	b _080CEE34
_080CED3A:
	adds r0, r7, 0
	movs r1, 0x1
	bl GetBoxMonData
	mov r9, r0
	adds r0, r7, 0
	movs r1, 0x4
	bl GetBoxMonData
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0
	beq _080CED6C
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00000ced
	adds r0, r2
	strb r5, [r0]
	b _080CED7E
	.pool
_080CED6C:
	adds r0, r7, 0
	movs r1, 0x2D
	bl GetBoxMonData
	mov r3, r8
	ldr r1, [r3]
	ldr r2, =0x00000ced
	adds r1, r2
	strb r0, [r1]
_080CED7E:
	ldr r5, =gUnknown_02039D08
	ldr r2, [r5]
	ldr r4, =0x00000cee
	adds r2, r4
	adds r0, r7, 0
	movs r1, 0x2
	bl GetBoxMonData
	ldr r0, [r5]
	adds r0, r4
	bl StringGetEnd10
	adds r0, r7, 0
	bl GetLevelFromBoxMonExp
	ldr r1, [r5]
	ldr r3, =0x00000cec
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x8
	bl GetBoxMonData
	ldr r1, [r5]
	ldr r2, =0x00000ceb
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0
	bl GetBoxMonData
	adds r2, r0, 0
	ldr r1, [r5]
	movs r6, 0xCE
	lsls r6, 4
	adds r0, r1, r6
	str r2, [r0]
	subs r4, 0xA
	adds r1, r4
	ldrh r0, [r1]
	mov r1, r9
	bl GetFrontSpritePalFromSpeciesAndPersonality
	ldr r1, [r5]
	ldr r3, =0x00000cdc
	adds r2, r1, r3
	str r0, [r2]
	adds r4, r1, r4
	ldrh r0, [r4]
	adds r1, r6
	ldr r1, [r1]
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r7, 0
	movs r1, 0xC
	bl GetBoxMonData
	ldr r1, [r5]
	ldr r2, =0x00000ce6
	adds r1, r2
	strh r0, [r1]
	b _080CEE26
	.pool
_080CEE1C:
	ldr r3, =0x00000ce4
	adds r0, r1, r3
	mov r1, r9
	strh r1, [r0]
	strh r1, [r2]
_080CEE26:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r2, =0x00000ce4
	adds r0, r1, r2
	ldrh r2, [r0]
	cmp r2, 0
	bne _080CEE94
_080CEE34:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r3, =0x00000cee
	adds r0, r3
	movs r1, 0
	movs r2, 0x5
	bl StringFill
	ldr r0, [r4]
	ldr r1, =0x00000cf9
	adds r0, r1
	movs r1, 0
	movs r2, 0x8
	bl StringFill
	ldr r0, [r4]
	ldr r2, =0x00000d1d
	adds r0, r2
	movs r1, 0
	movs r2, 0x8
	bl StringFill
	ldr r0, [r4]
	ldr r3, =0x00000d41
	adds r0, r3
	movs r1, 0
	movs r2, 0x8
	bl StringFill
	ldr r0, [r4]
	ldr r1, =0x00000d65
	adds r0, r1
	b _080CEEF2
	.pool
_080CEE94:
	ldr r3, =0x00000ced
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CEF14
	mov r0, r10
	cmp r0, 0
	beq _080CEEC0
	ldr r2, =0x00000cf9
	adds r0, r1, r2
	adds r3, 0x1
	adds r1, r3
	movs r2, 0
	movs r3, 0x5
	bl StringCopyPadded
	b _080CEECE
	.pool
_080CEEC0:
	ldr r2, =0x00000cf9
	adds r0, r1, r2
	ldr r1, =gText_EggNickname
	movs r2, 0
	movs r3, 0x8
	bl StringCopyPadded
_080CEECE:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r3, =0x00000d1d
	adds r0, r3
	movs r1, 0
	movs r2, 0x8
	bl StringFill
	ldr r0, [r4]
	ldr r1, =0x00000d41
	adds r0, r1
	movs r1, 0
	movs r2, 0x8
	bl StringFill
	ldr r0, [r4]
	ldr r2, =0x00000d65
	adds r0, r2
_080CEEF2:
	movs r1, 0
	movs r2, 0x8
	bl StringFill
	b _080CF0B8
	.pool
_080CEF14:
	cmp r2, 0x1D
	beq _080CEF1C
	cmp r2, 0x20
	bne _080CEF20
_080CEF1C:
	movs r3, 0xFF
	mov r9, r3
_080CEF20:
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r2, =0x00000cf9
	adds r0, r1, r2
	ldr r3, =0x00000cee
	adds r1, r3
	movs r2, 0
	movs r3, 0x5
	bl StringCopyPadded
	ldr r1, [r4]
	ldr r0, =0x00000d1d
	adds r2, r1, r0
	movs r0, 0xBA
	strb r0, [r2]
	ldr r3, =0x00000d1e
	adds r2, r1, r3
	ldr r0, [r4]
	ldr r1, =0x00000ce4
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x5
	bl StringCopyPadded
	ldr r4, [r4]
	ldr r3, =0x00000d41
	adds r2, r4, r3
	movs r0, 0xFC
	strb r0, [r2]
	ldr r0, =0x00000d42
	adds r2, r4, r0
	movs r0, 0x4
	strb r0, [r2]
	ldr r1, =0x00000d43
	adds r2, r4, r1
	mov r3, r9
	cmp r3, 0
	beq _080CEFD4
	cmp r3, 0xFE
	beq _080CF000
	movs r0, 0x2
	strb r0, [r2]
	ldr r0, =0x00000d44
	adds r2, r4, r0
	movs r0, 0x1
	strb r0, [r2]
	adds r1, 0x2
	adds r2, r4, r1
	movs r0, 0x3
	strb r0, [r2]
	ldr r3, =0x00000d46
	adds r2, r4, r3
	movs r0, 0x77
	strb r0, [r2]
	ldr r0, =0x00000d47
	adds r2, r4, r0
	b _080CF020
	.pool
_080CEFD4:
	strb r0, [r2]
	ldr r1, =0x00000d44
	adds r2, r4, r1
	movs r0, 0x1
	strb r0, [r2]
	ldr r3, =0x00000d45
	adds r2, r4, r3
	movs r0, 0x5
	strb r0, [r2]
	ldr r0, =0x00000d46
	adds r2, r4, r0
	movs r0, 0xB5
	strb r0, [r2]
	adds r1, 0x3
	adds r2, r4, r1
	b _080CF020
	.pool
_080CF000:
	movs r0, 0x6
	strb r0, [r2]
	ldr r3, =0x00000d44
	adds r2, r4, r3
	movs r0, 0x1
	strb r0, [r2]
	ldr r0, =0x00000d45
	adds r2, r4, r0
	movs r0, 0x7
	strb r0, [r2]
	ldr r1, =0x00000d46
	adds r2, r4, r1
	movs r0, 0xB6
	strb r0, [r2]
	adds r3, 0x3
	adds r2, r4, r3
_080CF020:
	movs r0, 0xFC
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x4
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x2
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x1
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x3
	strb r0, [r2]
	adds r2, 0x1
	movs r5, 0
	strb r5, [r2]
	adds r2, 0x1
	movs r0, 0xF9
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x5
	strb r0, [r2]
	adds r2, 0x1
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r1, =0x00000cec
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r2, r0, 0
	strb r5, [r2]
	movs r0, 0xFF
	strb r0, [r2, 0x1]
	ldr r4, [r4]
	ldr r2, =0x00000ce6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _080CF0AC
	ldr r3, =0x00000d65
	adds r4, r3
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x8
	bl StringCopyPadded
	b _080CF0B8
	.pool
_080CF0AC:
	ldr r1, =0x00000d65
	adds r0, r4, r1
	movs r1, 0
	movs r2, 0x8
	bl StringFill
_080CF0B8:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CEC00

	thumb_func_start sub_80CF0CC
sub_80CF0CC: @ 80CF0CC
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000021ff
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080CF0F4
	cmp r0, 0x1
	ble _080CF0E4
	cmp r0, 0x2
	beq _080CF0FA
_080CF0E4:
	bl sub_80CF108
	b _080CF0FE
	.pool
_080CF0F4:
	bl sub_80CF374
	b _080CF0FE
_080CF0FA:
	bl sub_80CF4B0
_080CF0FE:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80CF0CC

	thumb_func_start sub_80CF108
sub_80CF108: @ 80CF108
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	mov r8, r0
	ldr r2, =gUnknown_02039D79
	ldrb r4, [r2]
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r1, =0x00000cd2
	mov r10, r1
	add r0, r10
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r7, =0x00000cd3
	adds r0, r7
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, =0x00000cd7
	mov r9, r3
	add r0, r9
	strb r1, [r0]
	ldr r6, =gMain
	ldrh r1, [r6, 0x30]
	movs r0, 0x40
	ands r0, r1
	adds r3, r2, 0
	cmp r0, 0
	beq _080CF14C
	b _080CF33C
_080CF14C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080CF1A8
	movs r6, 0x1
	lsls r0, r4, 24
	movs r1, 0xC0
	lsls r1, 19
	adds r0, r1
	lsrs r4, r0, 24
	asrs r0, 24
	cmp r0, 0x1D
	bgt _080CF168
	b _080CF358
_080CF168:
	movs r2, 0x3
	mov r8, r2
	subs r0, 0x1E
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x3
	bl __divsi3
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, [r5]
	add r0, r10
	strb r6, [r0]
	ldr r0, [r5]
	add r0, r9
	strb r6, [r0]
	b _080CF358
	.pool
_080CF1A8:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080CF1DE
	movs r6, 0x1
	movs r0, 0
	ldrsb r0, [r3, r0]
	movs r1, 0x6
	bl __modsi3
	lsls r0, 24
	cmp r0, 0
	beq _080CF1CA
	lsls r0, r4, 24
	movs r3, 0xFF
	lsls r3, 24
	b _080CF34C
_080CF1CA:
	ldr r0, [r5]
	adds r0, r7
	movs r1, 0xFF
	strb r1, [r0]
	lsls r0, r4, 24
	movs r1, 0xA0
	lsls r1, 19
	adds r0, r1
	lsrs r4, r0, 24
	b _080CF358
_080CF1DE:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080CF212
	movs r6, 0x1
	movs r0, 0
	ldrsb r0, [r3, r0]
	adds r0, 0x1
	movs r1, 0x6
	bl __modsi3
	cmp r0, 0
	beq _080CF204
	lsls r0, r4, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r4, r0, 24
	b _080CF358
_080CF204:
	ldr r0, [r5]
	adds r0, r7
	strb r6, [r0]
	lsls r0, r4, 24
	movs r3, 0xFB
	lsls r3, 24
	b _080CF34C
_080CF212:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080CF220
	movs r6, 0x1
	b _080CF352
_080CF220:
	movs r4, 0x1
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080CF2E4
	bl sub_80CFA5C
	lsls r0, 24
	cmp r0, 0
	beq _080CF2E4
	ldr r0, =gUnknown_02039D7D
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CF244
	movs r0, 0x8
	b _080CF366
	.pool
_080CF244:
	ldr r1, [r5]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _080CF254
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080CF2D4
_080CF254:
	movs r0, 0
	bl sub_80CFF98
	subs r0, 0x1
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xE
	bhi _080CF2E4
	lsls r0, 2
	ldr r1, =_080CF278
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CF278:
	.4byte _080CF2B4
	.4byte _080CF2B8
	.4byte _080CF2BC
	.4byte _080CF2C0
	.4byte _080CF2C4
	.4byte _080CF2E4
	.4byte _080CF2E4
	.4byte _080CF2E4
	.4byte _080CF2E4
	.4byte _080CF2E4
	.4byte _080CF2E4
	.4byte _080CF2C8
	.4byte _080CF2CC
	.4byte _080CF2E4
	.4byte _080CF2D0
_080CF2B4:
	movs r0, 0xB
	b _080CF366
_080CF2B8:
	movs r0, 0xC
	b _080CF366
_080CF2BC:
	movs r0, 0xD
	b _080CF366
_080CF2C0:
	movs r0, 0xE
	b _080CF366
_080CF2C4:
	movs r0, 0xF
	b _080CF366
_080CF2C8:
	movs r0, 0x10
	b _080CF366
_080CF2CC:
	movs r0, 0x11
	b _080CF366
_080CF2D0:
	movs r0, 0x12
	b _080CF366
_080CF2D4:
	ldr r2, =0x000021ff
	adds r0, r1, r2
	strb r4, [r0]
	movs r0, 0x14
	b _080CF366
	.pool
_080CF2E4:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080CF2F8
	movs r0, 0x13
	b _080CF366
	.pool
_080CF2F8:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080CF326
	ldrh r1, [r2, 0x2C]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080CF318
	movs r0, 0xA
	b _080CF366
	.pool
_080CF318:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080CF326
	movs r0, 0x9
	b _080CF366
_080CF326:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080CF338
	bl sub_80CFDC4
	movs r0, 0
	b _080CF366
_080CF338:
	movs r6, 0
	b _080CF364
_080CF33C:
	movs r6, 0x1
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0x5
	ble _080CF352
	lsls r0, r4, 24
	movs r3, 0xFA
	lsls r3, 24
_080CF34C:
	adds r0, r3
	lsrs r4, r0, 24
	b _080CF358
_080CF352:
	movs r0, 0x2
	mov r8, r0
	movs r4, 0
_080CF358:
	cmp r6, 0
	beq _080CF364
	mov r0, r8
	adds r1, r4, 0
	bl sub_80CD894
_080CF364:
	adds r0, r6, 0
_080CF366:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80CF108

	thumb_func_start sub_80CF374
sub_80CF374: @ 80CF374
	push {r4,lr}
	ldr r1, =gMain
	ldrh r0, [r1, 0x2C]
	movs r4, 0x1
	ands r4, r0
	cmp r4, 0
	beq _080CF428
	ldrh r1, [r1, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080CF3AC
	ldr r4, =gUnknown_02039D79
	movs r0, 0
	ldrsb r0, [r4, r0]
	movs r1, 0x6
	bl __divsi3
	lsls r0, 24
	cmp r0, 0
	beq _080CF420
	ldrb r1, [r4]
	subs r1, 0x6
	b _080CF40E
	.pool
_080CF3AC:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080CF3CC
	ldr r1, =gUnknown_02039D79
	movs r0, 0
	ldrsb r0, [r1, r0]
	adds r0, 0x6
	cmp r0, 0x1D
	bgt _080CF420
	ldrb r1, [r1]
	adds r1, 0x6
	b _080CF40E
	.pool
_080CF3CC:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080CF3F0
	ldr r4, =gUnknown_02039D79
	movs r0, 0
	ldrsb r0, [r4, r0]
	movs r1, 0x6
	bl __modsi3
	lsls r0, 24
	cmp r0, 0
	beq _080CF420
	ldrb r1, [r4]
	subs r1, 0x1
	b _080CF40E
	.pool
_080CF3F0:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080CF424
	ldr r4, =gUnknown_02039D79
	movs r0, 0
	ldrsb r0, [r4, r0]
	adds r0, 0x1
	movs r1, 0x6
	bl __modsi3
	cmp r0, 0
	beq _080CF420
	ldrb r1, [r4]
	adds r1, 0x1
_080CF40E:
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_80CD894
	movs r0, 0x15
	b _080CF49C
	.pool
_080CF420:
	movs r0, 0x18
	b _080CF49C
_080CF424:
	movs r0, 0
	b _080CF49C
_080CF428:
	bl sub_80D0BA4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	cmp r0, r1
	beq _080CF47C
	ldr r2, =gUnknown_02039D7A
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r3, =0x00000ce4
	adds r0, r1, r3
	ldrh r0, [r0]
	negs r0, r0
	lsrs r0, 31
	strb r0, [r2]
	ldr r0, =0x000021ff
	adds r1, r0
	movs r0, 0x2
	strb r0, [r1]
	bl StorageGetCurrentBox
	ldr r1, =gUnknown_02039D7B
	strb r0, [r1]
	movs r0, 0x17
	b _080CF49C
	.pool
_080CF47C:
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	ldr r2, =0x000021ff
	adds r0, r2
	strb r4, [r0]
	ldr r0, [r1]
	ldr r3, =0x00000cb8
	adds r0, r3
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	movs r0, 0x16
_080CF49C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80CF374

	thumb_func_start sub_80CF4B0
sub_80CF4B0: @ 80CF4B0
	push {r4,lr}
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080CF4DC
	movs r0, 0
	bl sub_80D0580
	lsls r0, 24
	cmp r0, 0
	beq _080CF588
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	subs r1, 0x6
	b _080CF53A
	.pool
_080CF4DC:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080CF4FC
	movs r0, 0x1
	bl sub_80D0580
	lsls r0, 24
	cmp r0, 0
	beq _080CF588
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	adds r1, 0x6
	b _080CF53A
	.pool
_080CF4FC:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080CF51C
	movs r0, 0x2
	bl sub_80D0580
	lsls r0, 24
	cmp r0, 0
	beq _080CF5A2
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	subs r1, 0x1
	b _080CF53A
	.pool
_080CF51C:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080CF54C
	movs r0, 0x3
	bl sub_80D0580
	lsls r0, 24
	cmp r0, 0
	beq _080CF5B6
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	adds r1, 0x1
_080CF53A:
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_80CD894
	movs r0, 0x19
	b _080CF5BC
	.pool
_080CF54C:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080CF580
	bl sub_80D0BC0
	lsls r0, 24
	cmp r0, 0
	beq _080CF588
	ldr r0, =gUnknown_02039D7A
	strb r4, [r0]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x000021ff
	adds r0, r1
	strb r4, [r0]
	movs r0, 0x1A
	b _080CF5BC
	.pool
_080CF580:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080CF58C
_080CF588:
	movs r0, 0x18
	b _080CF5BC
_080CF58C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080CF5BA
	ldrh r1, [r2, 0x2C]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080CF5AC
_080CF5A2:
	movs r0, 0xA
	b _080CF5BC
	.pool
_080CF5AC:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080CF5BA
_080CF5B6:
	movs r0, 0x9
	b _080CF5BC
_080CF5BA:
	movs r0, 0
_080CF5BC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80CF4B0

	thumb_func_start sub_80CF5C4
sub_80CF5C4: @ 80CF5C4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	mov r9, r0
	ldr r6, =gUnknown_02039D79
	ldrb r4, [r6]
	ldr r2, =gUnknown_02039D08
	ldr r0, [r2]
	ldr r1, =0x00000cd3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, =0x00000cd2
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x5
	adds r0, r3
	strb r1, [r0]
	mov r8, r1
	movs r7, 0
	ldr r1, =gMain
	ldrh r3, [r1, 0x30]
	movs r0, 0x40
	ands r0, r3
	adds r5, r6, 0
	mov r12, r1
	cmp r0, 0
	beq _080CF608
	b _080CF7A8
_080CF608:
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _080CF64C
	lsls r0, r4, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r4, r0, 24
	asrs r0, 24
	cmp r0, 0x6
	ble _080CF622
	movs r4, 0
_080CF622:
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r5, r1]
	cmp r0, r1
	bne _080CF630
	b _080CF7C6
_080CF630:
	movs r7, 0x1
	b _080CF7CA
	.pool
_080CF64C:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _080CF670
	ldrb r1, [r5]
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	beq _080CF670
	movs r7, 0x1
	ldr r0, [r2]
	ldr r2, =0x00000cd6
	adds r0, r2
	strb r1, [r0]
	movs r4, 0
	b _080CF7C6
	.pool
_080CF670:
	mov r3, r12
	ldrh r1, [r3, 0x30]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080CF69E
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	bne _080CF694
	movs r7, 0x1
	ldr r0, [r2]
	ldr r1, =0x00000cd6
	adds r0, r1
	ldrb r4, [r0]
	b _080CF7C6
	.pool
_080CF694:
	movs r7, 0x6
	movs r2, 0
	mov r9, r2
	movs r4, 0
	b _080CF7C6
_080CF69E:
	mov r3, r12
	ldrh r1, [r3, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080CF75C
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0x6
	bne _080CF6C4
	ldr r0, [r2]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _080CF6BE
	movs r0, 0x4
	b _080CF7D8
_080CF6BE:
	movs r0, 0x1
	mov r8, r0
	b _080CF75C
_080CF6C4:
	bl sub_80CFA5C
	lsls r0, 24
	cmp r0, 0
	beq _080CF75C
	ldr r0, =gUnknown_02039D7D
	ldrb r0, [r0]
	cmp r0, 0
	bne _080CF6E0
	movs r0, 0x8
	b _080CF7D8
	.pool
_080CF6E0:
	movs r0, 0
	bl sub_80CFF98
	subs r0, 0x1
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xE
	bhi _080CF75C
	lsls r0, 2
	ldr r1, =_080CF700
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080CF700:
	.4byte _080CF73C
	.4byte _080CF740
	.4byte _080CF744
	.4byte _080CF748
	.4byte _080CF74C
	.4byte _080CF75C
	.4byte _080CF75C
	.4byte _080CF75C
	.4byte _080CF75C
	.4byte _080CF75C
	.4byte _080CF75C
	.4byte _080CF750
	.4byte _080CF754
	.4byte _080CF75C
	.4byte _080CF758
_080CF73C:
	movs r0, 0xB
	b _080CF7D8
_080CF740:
	movs r0, 0xC
	b _080CF7D8
_080CF744:
	movs r0, 0xD
	b _080CF7D8
_080CF748:
	movs r0, 0xE
	b _080CF7D8
_080CF74C:
	movs r0, 0xF
	b _080CF7D8
_080CF750:
	movs r0, 0x10
	b _080CF7D8
_080CF754:
	movs r0, 0x11
	b _080CF7D8
_080CF758:
	movs r0, 0x12
	b _080CF7D8
_080CF75C:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	mov r12, r2
	cmp r0, 0
	beq _080CF784
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _080CF780
	movs r0, 0x13
	b _080CF7D8
	.pool
_080CF780:
	movs r1, 0x1
	mov r8, r1
_080CF784:
	mov r2, r8
	cmp r2, 0
	beq _080CF794
	movs r7, 0x6
	movs r3, 0
	mov r9, r3
	movs r4, 0
	b _080CF7C6
_080CF794:
	mov r0, r12
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080CF7C6
	bl sub_80CFDC4
	movs r0, 0
	b _080CF7D8
_080CF7A8:
	lsls r0, r4, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r4, r0, 24
	cmp r0, 0
	bge _080CF7B8
	movs r4, 0x6
_080CF7B8:
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r6, r1]
	cmp r0, r1
	beq _080CF7C6
	movs r7, 0x1
_080CF7C6:
	cmp r7, 0
	beq _080CF7D6
_080CF7CA:
	cmp r7, 0x6
	beq _080CF7D6
	mov r0, r9
	adds r1, r4, 0
	bl sub_80CD894
_080CF7D6:
	adds r0, r7, 0
_080CF7D8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80CF5C4

	thumb_func_start sub_80CF7E4
sub_80CF7E4: @ 80CF7E4
	push {r4-r6,lr}
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r1, =0x00000cd3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r3]
	ldr r2, =0x00000cd2
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r3]
	ldr r5, =0x00000cd7
	adds r0, r5
	strb r1, [r0]
	ldr r1, =gMain
	ldrh r2, [r1, 0x30]
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	bne _080CF8AA
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _080CF834
	movs r4, 0x1
	movs r1, 0
	movs r6, 0x2
	b _080CF8B6
	.pool
_080CF834:
	ldrh r2, [r1, 0x2C]
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _080CF85A
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	bne _080CF86E
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _080CF872
	movs r0, 0x80
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	beq _080CF864
_080CF85A:
	movs r0, 0xA
	b _080CF8D2
	.pool
_080CF864:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _080CF872
_080CF86E:
	movs r0, 0x9
	b _080CF8D2
_080CF872:
	ldrh r1, [r1, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080CF88A
	movs r0, 0
	bl sub_80CD1A8
	bl sub_80CFA38
	movs r0, 0x7
	b _080CF8D2
_080CF88A:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080CF896
	movs r0, 0x13
	b _080CF8D2
_080CF896:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080CF8A6
	bl sub_80CFDC4
	movs r0, 0
	b _080CF8D2
_080CF8A6:
	movs r4, 0
	b _080CF8D0
_080CF8AA:
	movs r4, 0x1
	movs r1, 0x3
	movs r6, 0
	ldr r0, [r3]
	adds r0, r5
	strb r4, [r0]
_080CF8B6:
	cmp r4, 0
	beq _080CF8D0
	lsls r5, r1, 24
	cmp r1, 0x2
	beq _080CF8C6
	movs r0, 0
	bl sub_80CD1A8
_080CF8C6:
	lsrs r0, r5, 24
	lsls r1, r6, 24
	lsrs r1, 24
	bl sub_80CD894
_080CF8D0:
	adds r0, r4, 0
_080CF8D2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80CF7E4

	thumb_func_start sub_80CF8D8
sub_80CF8D8: @ 80CF8D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	mov r8, r0
	ldr r0, =gUnknown_02039D79
	mov r12, r0
	ldrb r2, [r0]
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldr r1, =0x00000cd3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r3]
	ldr r6, =0x00000cd2
	adds r0, r6
	strb r1, [r0]
	ldr r0, [r3]
	ldr r5, =0x00000cd7
	adds r0, r5
	strb r1, [r0]
	ldr r7, =gMain
	ldrh r1, [r7, 0x30]
	movs r0, 0x40
	ands r0, r1
	adds r4, r3, 0
	cmp r0, 0
	bne _080CF9B2
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	beq _080CF944
	movs r7, 0x1
	movs r0, 0x2
	mov r8, r0
	movs r2, 0
	ldr r0, [r4]
	b _080CF9D0
	.pool
_080CF944:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080CF960
	movs r7, 0x1
	lsls r0, r2, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r2, r0, 24
	cmp r0, 0
	bge _080CF9D4
	movs r2, 0x1
	b _080CF9D4
_080CF960:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080CF97E
	movs r7, 0x1
	lsls r0, r2, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x1
	ble _080CF9D4
	movs r2, 0
	b _080CF9D4
_080CF97E:
	ldrh r1, [r7, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080CF992
	movs r0, 0x4
	cmp r2, 0
	bne _080CF9E2
	movs r0, 0x5
	b _080CF9E2
_080CF992:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080CF99E
	movs r0, 0x13
	b _080CF9E2
_080CF99E:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080CF9AE
	bl sub_80CFDC4
	movs r0, 0
	b _080CF9E2
_080CF9AE:
	movs r7, 0
	b _080CF9E0
_080CF9B2:
	movs r7, 0x1
	movs r0, 0
	mov r8, r0
	ldr r0, [r3]
	adds r0, r6
	movs r1, 0xFF
	strb r1, [r0]
	mov r1, r12
	movs r0, 0
	ldrsb r0, [r1, r0]
	movs r2, 0x1D
	cmp r0, 0
	bne _080CF9CE
	movs r2, 0x18
_080CF9CE:
	ldr r0, [r3]
_080CF9D0:
	adds r0, r5
	strb r7, [r0]
_080CF9D4:
	cmp r7, 0
	beq _080CF9E0
	mov r0, r8
	adds r1, r2, 0
	bl sub_80CD894
_080CF9E0:
	adds r0, r7, 0
_080CF9E2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80CF8D8

	thumb_func_start sub_80CF9EC
sub_80CF9EC: @ 80CF9EC
	push {r4,r5,lr}
	movs r3, 0
	ldr r0, =gUnknown_0857B9BC
	ldr r1, [r0]
	adds r4, r0, 0
	cmp r1, 0
	beq _080CFA30
	ldr r5, =gUnknown_02039D78
_080CF9FC:
	lsls r0, r3, 3
	adds r2, r0, r4
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bne _080CFA20
	ldr r0, [r2]
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	b _080CFA32
	.pool
_080CFA20:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r0, r3, 3
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	bne _080CF9FC
_080CFA30:
	movs r0, 0
_080CFA32:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80CF9EC

	thumb_func_start sub_80CFA38
sub_80CFA38: @ 80CFA38
	push {lr}
	bl sub_80CFEF0
	movs r0, 0x9
	bl sub_80CFF34
	movs r0, 0xA
	bl sub_80CFF34
	movs r0, 0xB
	bl sub_80CFF34
	movs r0, 0
	bl sub_80CFF34
	pop {r0}
	bx r0
	thumb_func_end sub_80CFA38

	thumb_func_start sub_80CFA5C
sub_80CFA5C: @ 80CFA5C
	push {lr}
	bl sub_80CFEF0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080CFA78
	bl sub_80CFB44
	b _080CFA7C
	.pool
_080CFA78:
	bl sub_80CFA84
_080CFA7C:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80CFA5C

	thumb_func_start sub_80CFA84
sub_80CFA84: @ 80CFA84
	push {lr}
	bl sub_80CD504
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080CFAAE
	cmp r0, 0x1
	bgt _080CFAA8
	cmp r0, 0
	beq _080CFABA
	b _080CFAF4
	.pool
_080CFAA8:
	cmp r0, 0x2
	beq _080CFAC6
	b _080CFAF4
_080CFAAE:
	cmp r1, 0
	beq _080CFAF4
	movs r0, 0x1
	bl sub_80CFF34
	b _080CFAF8
_080CFABA:
	cmp r1, 0
	beq _080CFAF4
	movs r0, 0x2
	bl sub_80CFF34
	b _080CFAF8
_080CFAC6:
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CFAE8
	cmp r1, 0
	beq _080CFAE0
	movs r0, 0x4
	bl sub_80CFF34
	b _080CFAF8
	.pool
_080CFAE0:
	movs r0, 0x5
	bl sub_80CFF34
	b _080CFAF8
_080CFAE8:
	cmp r1, 0
	beq _080CFAF4
	movs r0, 0x3
	bl sub_80CFF34
	b _080CFAF8
_080CFAF4:
	movs r0, 0
	b _080CFB3E
_080CFAF8:
	movs r0, 0x6
	bl sub_80CFF34
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x2
	bne _080CFB2A
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CFB24
	movs r0, 0x2
	bl sub_80CFF34
	b _080CFB2A
	.pool
_080CFB24:
	movs r0, 0x1
	bl sub_80CFF34
_080CFB2A:
	movs r0, 0x8
	bl sub_80CFF34
	movs r0, 0x7
	bl sub_80CFF34
	movs r0, 0
	bl sub_80CFF34
	movs r0, 0x1
_080CFB3E:
	pop {r1}
	bx r1
	thumb_func_end sub_80CFA84

	thumb_func_start sub_80CFB44
sub_80CFB44: @ 80CFB44
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	ldr r5, =0x00000ce4
	adds r0, r5
	ldrh r1, [r0]
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _080CFBDA
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	bne _080CFBAC
	ldr r2, [r4]
	ldr r0, =0x00000ce6
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080CFB8C
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, 0
	beq _080CFBDA
	movs r0, 0xE
	bl sub_80CFF34
	b _080CFBE4
	.pool
_080CFB8C:
	ldrh r0, [r1]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	bne _080CFBA4
	movs r0, 0xC
	bl sub_80CFF34
	movs r0, 0x10
	bl sub_80CFF34
_080CFBA4:
	movs r0, 0x11
	bl sub_80CFF34
	b _080CFBE4
_080CFBAC:
	ldr r2, [r4]
	ldr r0, =0x00000ce6
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080CFBCC
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, 0
	beq _080CFBDA
	movs r0, 0xD
	bl sub_80CFF34
	b _080CFBE4
	.pool
_080CFBCC:
	ldrh r0, [r1]
	bl ItemIsMail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080CFBDE
_080CFBDA:
	movs r0, 0
	b _080CFBEC
_080CFBDE:
	movs r0, 0xF
	bl sub_80CFF34
_080CFBE4:
	movs r0, 0
	bl sub_80CFF34
	movs r0, 0x1
_080CFBEC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80CFB44

	thumb_func_start sub_80CFBF4
sub_80CFBF4: @ 80CFBF4
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	ldr r2, =0x00000cb4
	adds r1, r2
	ldr r2, [r1]
	ldrh r2, [r2, 0x20]
	strh r2, [r0, 0x20]
	ldr r1, [r1]
	ldrh r1, [r1, 0x22]
	adds r1, 0x14
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end sub_80CFBF4

	thumb_func_start sub_80CFC14
sub_80CFC14: @ 80CFC14
	push {r4-r6,lr}
	sub sp, 0x2C
	mov r1, sp
	ldr r0, =gHandCursorSpriteSheets
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	add r4, sp, 0x18
	adds r1, r4, 0
	ldr r0, =gHandCursorSpritePalettes
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	mov r0, sp
	bl LoadSpriteSheets
	adds r0, r4, 0
	bl LoadSpritePalettes
	ldr r0, =0x0000daca
	bl IndexOfSpritePaletteTag
	ldr r6, =gUnknown_02039D08
	ldr r1, [r6]
	ldr r4, =0x00000cd8
	adds r1, r4
	strb r0, [r1]
	ldr r0, =0x0000dac7
	bl IndexOfSpritePaletteTag
	ldr r1, [r6]
	ldr r5, =0x00000cd9
	adds r1, r5
	strb r0, [r1]
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	ldr r1, =gUnknown_02039D79
	ldrb r1, [r1]
	add r4, sp, 0x28
	mov r5, sp
	adds r5, 0x2A
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80CD444
	ldr r0, =gSpriteTemplate_857BA50
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0
	ldrsh r2, [r5, r3]
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080CFD18
	ldr r2, [r6]
	ldr r4, =0x00000cb4
	adds r3, r2, r4
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r3]
	ldr r0, =gUnknown_02039D7D
	ldr r5, =0x00000cd8
	adds r2, r5
	ldrb r0, [r0]
	adds r2, r0
	ldrb r2, [r2]
	lsls r2, 4
	ldrb r3, [r1, 0x5]
	movs r0, 0xF
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r6]
	adds r0, r4
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, =gUnknown_02039D7A
	ldrb r0, [r0]
	cmp r0, 0
	beq _080CFD22
	ldr r0, [r6]
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
	b _080CFD22
	.pool
_080CFD18:
	ldr r0, [r6]
	ldr r1, =0x00000cb4
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_080CFD22:
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _080CFD3C
	movs r3, 0xD
	movs r4, 0x1
	b _080CFD40
	.pool
_080CFD3C:
	movs r3, 0x15
	movs r4, 0x2
_080CFD40:
	ldr r0, =gSpriteTemplate_857BA68
	movs r1, 0
	movs r2, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080CFDA8
	ldr r5, =gUnknown_02039D08
	ldr r2, [r5]
	ldr r3, =0x00000cb8
	adds r2, r3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	lsls r3, r4, 2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _080CFDB4
	ldr r0, [r5]
	ldr r4, =0x00000cb8
	adds r0, r4
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	b _080CFDB4
	.pool
_080CFDA8:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r5, =0x00000cb8
	adds r0, r5
	movs r1, 0
	str r1, [r0]
_080CFDB4:
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFC14

	thumb_func_start sub_80CFDC4
sub_80CFDC4: @ 80CFDC4
	push {lr}
	ldr r2, =gUnknown_02039D7D
	movs r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _080CFDD2
	movs r1, 0x1
_080CFDD2:
	strb r1, [r2]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r3, =0x00000cb4
	adds r1, r0, r3
	ldr r3, [r1]
	ldr r1, =0x00000cd8
	adds r0, r1
	ldrb r2, [r2]
	adds r0, r2
	ldrb r1, [r0]
	lsls r1, 4
	ldrb r2, [r3, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFDC4

	thumb_func_start sub_80CFE08
sub_80CFE08: @ 80CFE08
	ldr r0, =gUnknown_02039D79
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CFE08

	thumb_func_start sub_80CFE14
sub_80CFE14: @ 80CFE14
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CFE48
	ldr r4, =gUnknown_02039D79
	movs r0, 0
	ldrsb r0, [r4, r0]
	movs r1, 0x6
	bl __modsi3
	strb r0, [r5]
	movs r0, 0
	ldrsb r0, [r4, r0]
	movs r1, 0x6
	bl __divsi3
	b _080CFE4C
	.pool
_080CFE48:
	movs r0, 0
	strb r0, [r5]
_080CFE4C:
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80CFE14

	thumb_func_start sub_80CFE54
sub_80CFE54: @ 80CFE54
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00000cb4
	adds r0, r2
	ldr r0, [r0]
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFE54

	thumb_func_start sub_80CFE78
sub_80CFE78: @ 80CFE78
	ldr r0, =gUnknown_02039D7B
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CFE78

	thumb_func_start sub_80CFE84
sub_80CFE84: @ 80CFE84
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	bx lr
	.pool
	thumb_func_end sub_80CFE84

	thumb_func_start sub_80CFEA8
sub_80CFEA8: @ 80CFEA8
	push {lr}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CFEC0
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	movs r0, 0
	bl sub_80D0E50
_080CFEC0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFEA8

	thumb_func_start sub_80CFECC
sub_80CFECC: @ 80CFECC
	push {lr}
	ldr r0, =gUnknown_02039D78
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080CFEE4
	ldr r0, =gUnknown_02039D79
	ldrb r1, [r0]
	movs r0, 0
	bl sub_80D0D8C
_080CFEE4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFECC

	thumb_func_start sub_80CFEF0
sub_80CFEF0: @ 80CFEF0
	ldr r2, =gUnknown_02039D08
	ldr r0, [r2]
	ldr r1, =0x00000cac
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, =0x00000cad
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	subs r3, 0x41
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, =0x00000c71
	adds r0, r1
	movs r1, 0xF
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x6
	adds r0, r3
	movs r1, 0x5C
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80CFEF0

	thumb_func_start sub_80CFF34
sub_80CFF34: @ 80CFF34
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =gUnknown_02039D08
	ldr r2, [r4]
	ldr r5, =0x00000cac
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, 0x6
	bhi _080CFF7E
	adds r1, r0, 0
	lsls r1, 3
	ldr r0, =0x00000c74
	adds r1, r0
	adds r1, r2, r1
	ldr r2, =gUnknown_0857BA80
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	str r3, [r1, 0x4]
	bl StringLength
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, [r4]
	ldr r2, =0x00000cad
	adds r0, r2
	ldrb r2, [r0]
	cmp r1, r2
	bls _080CFF74
	strb r1, [r0]
_080CFF74:
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080CFF7E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFF34

	thumb_func_start sub_80CFF98
sub_80CFF98: @ 80CFF98
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldr r3, =0x00000cac
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bcs _080CFFC8
	lsls r0, r2, 3
	ldr r2, =0x00000c78
	adds r1, r2
	adds r1, r0
	movs r0, 0
	ldrsb r0, [r1, r0]
	b _080CFFCC
	.pool
_080CFFC8:
	movs r0, 0x1
	negs r0, r0
_080CFFCC:
	pop {r1}
	bx r1
	thumb_func_end sub_80CFF98

	thumb_func_start sub_80CFFD0
sub_80CFFD0: @ 80CFFD0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldr r2, =0x00000cad
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, 0x2
	subs r2, 0x3E
	adds r1, r2
	strb r0, [r1]
	ldr r1, [r5]
	ldr r6, =0x00000cac
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, 1
	movs r3, 0xC7
	lsls r3, 4
	adds r1, r3
	strb r0, [r1]
	ldr r1, [r5]
	adds r2, r1, r2
	ldrb r2, [r2]
	movs r0, 0x1D
	subs r0, r2
	ldr r2, =0x00000c6d
	adds r1, r2
	strb r0, [r1]
	ldr r1, [r5]
	adds r3, r1, r3
	ldrb r2, [r3]
	movs r0, 0xF
	subs r0, r2
	ldr r3, =0x00000c6e
	adds r1, r3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, =0x00000c6c
	adds r0, r1
	bl AddWindow
	ldr r1, [r5]
	movs r4, 0xCB
	lsls r4, 4
	adds r1, r4
	movs r2, 0
	mov r8, r2
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	movs r2, 0xB
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldr r2, [r5]
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r1, r2, r6
	ldrb r1, [r1]
	ldr r3, =0x00000c74
	adds r2, r3
	bl PrintMenuTable
	ldr r1, [r5]
	adds r4, r1, r4
	ldrb r0, [r4]
	adds r1, r6
	ldrb r1, [r1]
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, [r5]
	ldr r1, =0x00000cae
	adds r0, r1
	mov r2, r8
	strb r2, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80CFFD0

	thumb_func_start sub_80D00A8
sub_80D00A8: @ 80D00A8
	movs r0, 0
	bx lr
	thumb_func_end sub_80D00A8

	thumb_func_start sub_80D00AC
sub_80D00AC: @ 80D00AC
	push {r4,r5,lr}
	movs r5, 0x2
	negs r5, r5
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080D0102
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080D00CE
	movs r0, 0x5
	bl PlaySE
	adds r5, 0x1
_080D00CE:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080D00EC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	bl MoveMenuCursor
	b _080D010A
	.pool
_080D00EC:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080D010A
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl MoveMenuCursor
	b _080D010A
_080D0102:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r5, r0, 24
_080D010A:
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _080D0116
	bl sub_80D013C
_080D0116:
	cmp r5, 0
	blt _080D0128
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r5, 3
	ldr r2, =0x00000c78
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
_080D0128:
	lsls r0, r5, 16
	asrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D00AC

	thumb_func_start sub_80D013C
sub_80D013C: @ 80D013C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	movs r4, 0xCB
	lsls r4, 4
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_8198070
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D013C

	thumb_func_start sub_80D0164
sub_80D0164: @ 80D0164
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, =0x00000974
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _080D01B0
	ldr r0, =gUnknown_0857BB1C
	bl AddWindow8Bit
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r2, 0x88
	lsls r2, 6
	adds r0, r2
	strh r1, [r0]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _080D01B0
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	b _080D01B2
	.pool
_080D01B0:
	movs r0, 0
_080D01B2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0164

	thumb_func_start sub_80D01B8
sub_80D01B8: @ 80D01B8
	push {lr}
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	cmp r0, 0
	beq _080D01C6
	bl Free
_080D01C6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D01B8

	thumb_func_start sub_80D01D0
sub_80D01D0: @ 80D01D0
	ldr r2, =gUnknown_02039D80
	ldr r1, [r2]
	movs r3, 0
	strb r0, [r1]
	ldr r0, [r2]
	strb r3, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_80D01D0

	thumb_func_start sub_80D01E4
sub_80D01E4: @ 80D01E4
	push {lr}
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _080D0244
	lsls r0, 2
	ldr r1, =_080D0204
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D0204:
	.4byte _080D021C
	.4byte _080D0222
	.4byte _080D0228
	.4byte _080D022E
	.4byte _080D0234
	.4byte _080D023A
_080D021C:
	bl sub_80D024C
	b _080D023E
_080D0222:
	bl sub_80D0344
	b _080D023E
_080D0228:
	bl sub_80D03B0
	b _080D023E
_080D022E:
	bl sub_80D0420
	b _080D023E
_080D0234:
	bl sub_80D04A0
	b _080D023E
_080D023A:
	bl sub_80D04C8
_080D023E:
	lsls r0, 24
	lsrs r0, 24
	b _080D0246
_080D0244:
	movs r0, 0
_080D0246:
	pop {r1}
	bx r1
	thumb_func_end sub_80D01E4

	thumb_func_start sub_80D024C
sub_80D024C: @ 80D024C
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, =gUnknown_02039D80
	ldr r1, [r6]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x1
	beq _080D027C
	cmp r0, 0x1
	bgt _080D0268
	cmp r0, 0
	beq _080D026E
	b _080D0338
	.pool
_080D0268:
	cmp r0, 0x2
	beq _080D0324
	b _080D0338
_080D026E:
	movs r0, 0
	bl HideBg
	movs r0, 0x80
	bl sub_80D304C
	b _080D030E
_080D027C:
	adds r0, r1, 0x2
	adds r1, 0x3
	bl sub_80CFE14
	ldr r1, [r6]
	ldrb r0, [r1, 0x2]
	strb r0, [r1, 0x4]
	ldr r1, [r6]
	ldrb r0, [r1, 0x3]
	strb r0, [r1, 0x5]
	ldr r4, =0xfffffc00
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	movs r4, 0x88
	lsls r4, 6
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer8Bit
	ldr r1, [r6]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	bl sub_80D07B0
	movs r0, 0
	movs r1, 0x4
	movs r2, 0x1
	bl SetBgAttribute
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram8Bit
	movs r0, 0xFC
	lsls r0, 6
	ldr r2, =0x00007fff
	movs r1, 0x8
	bl BlendPalettes
	movs r0, 0x2
	bl sub_80CFE54
	movs r0, 0x8
	movs r1, 0x80
	bl SetGpuRegBits
_080D030E:
	ldr r1, [r6]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0338
	.pool
_080D0324:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080D0338
	movs r0, 0
	bl ShowBg
	movs r0, 0
	b _080D033A
_080D0338:
	movs r0, 0x1
_080D033A:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D024C

	thumb_func_start sub_80D0344
sub_80D0344: @ 80D0344
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080D036E
	cmp r0, 0x1
	bgt _080D0360
	cmp r0, 0
	beq _080D0366
	b _080D03A8
	.pool
_080D0360:
	cmp r0, 0x2
	beq _080D0382
	b _080D03A8
_080D0366:
	movs r0, 0
	bl HideBg
	b _080D0378
_080D036E:
	bl sub_80D0B5C
	movs r0, 0
	bl sub_80CFE54
_080D0378:
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D03A8
_080D0382:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080D03A8
	bl sub_80CFE84
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl ShowBg
	movs r0, 0
	b _080D03AA
_080D03A8:
	movs r0, 0x1
_080D03AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0344

	thumb_func_start sub_80D03B0
sub_80D03B0: @ 80D03B0
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _080D03C8
	cmp r0, 0x1
	beq _080D040C
	b _080D0416
	.pool
_080D03C8:
	bl sub_80CD554
	lsls r0, 24
	cmp r0, 0
	bne _080D0416
	ldr r1, [r4]
	adds r0, r1, 0x6
	adds r1, 0x7
	bl sub_80CFE14
	bl sub_80D062C
	ldr r1, [r4]
	ldrb r0, [r1, 0x6]
	strb r0, [r1, 0x4]
	ldr r1, [r4]
	ldrb r0, [r1, 0x7]
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0x88
	lsls r1, 6
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram8Bit
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0416
	.pool
_080D040C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _080D0418
_080D0416:
	movs r0, 0x1
_080D0418:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D03B0

	thumb_func_start sub_80D0420
sub_80D0420: @ 80D0420
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080D044E
	cmp r0, 0x1
	bgt _080D043C
	cmp r0, 0
	beq _080D0442
	b _080D0498
	.pool
_080D043C:
	cmp r0, 0x2
	beq _080D047A
	b _080D0498
_080D0442:
	bl sub_80D08CC
	bl sub_80D09A4
	movs r0, 0
	b _080D046C
_080D044E:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080D0498
	movs r0, 0x3
	bl sub_80CFE54
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	movs r2, 0x8
	bl sub_80D0884
	movs r0, 0x1
_080D046C:
	bl sub_80CDC64
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0498
_080D047A:
	bl sub_80D0894
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80CDCAC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0
	bne _080D0498
	cmp r0, 0
	bne _080D0498
	movs r0, 0
	b _080D049A
_080D0498:
	movs r0, 0x1
_080D049A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0420

	thumb_func_start sub_80D04A0
sub_80D04A0: @ 80D04A0
	push {r4,lr}
	bl sub_80CD554
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80D0894
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0
	bne _080D04C0
	cmp r0, 0
	bne _080D04C0
	movs r0, 0
	b _080D04C2
_080D04C0:
	movs r0, 0x1
_080D04C2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D04A0

	thumb_func_start sub_80D04C8
sub_80D04C8: @ 80D04C8
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080D0506
	cmp r0, 0x1
	bgt _080D04E4
	cmp r0, 0
	beq _080D04EE
	b _080D0576
	.pool
_080D04E4:
	cmp r0, 0x2
	beq _080D0532
	cmp r0, 0x3
	beq _080D0550
	b _080D0576
_080D04EE:
	bl sub_80D0AAC
	movs r1, 0xFF
	lsls r1, 8
	movs r0, 0
	movs r2, 0x8
	bl sub_80D0884
	movs r0, 0
	bl sub_80CDC64
	b _080D0546
_080D0506:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	bl sub_80D0894
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	bl sub_80D0A1C
	movs r0, 0x2
	bl sub_80CFE54
	movs r0, 0x1
	bl sub_80CDC64
	movs r0, 0
	bl HideBg
	b _080D0546
_080D0532:
	bl sub_80CDCAC
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	movs r0, 0
	bl sub_80CFE54
	bl sub_80D0B5C
_080D0546:
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0576
_080D0550:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	bl sub_80CFE84
	movs r0, 0
	bl ShowBg
	movs r0, 0
	b _080D0578
_080D0576:
	movs r0, 0x1
_080D0578:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D04C8

	thumb_func_start sub_80D0580
sub_80D0580: @ 80D0580
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _080D05BC
	cmp r0, 0x1
	bgt _080D0596
	cmp r0, 0
	beq _080D05A0
	b _080D0624
_080D0596:
	cmp r1, 0x2
	beq _080D05DC
	cmp r1, 0x3
	beq _080D05FC
	b _080D0624
_080D05A0:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	beq _080D060A
	subs r0, 0x1
	strb r0, [r1, 0x9]
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	b _080D05F0
	.pool
_080D05BC:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r2, [r1, 0x9]
	ldrb r0, [r1, 0xB]
	adds r0, r2, r0
	cmp r0, 0x4
	bgt _080D060A
	adds r0, r2, 0x1
	strb r0, [r1, 0x9]
	movs r1, 0xFC
	lsls r1, 8
	movs r0, 0
	b _080D05F0
	.pool
_080D05DC:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _080D060A
	subs r0, 0x1
	strb r0, [r1, 0x8]
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0
_080D05F0:
	movs r2, 0x6
	bl sub_80D0884
	b _080D0624
	.pool
_080D05FC:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	ldrb r0, [r1, 0xA]
	adds r0, r2, r0
	cmp r0, 0x5
	ble _080D0614
_080D060A:
	movs r0, 0
	b _080D0626
	.pool
_080D0614:
	adds r0, r2, 0x1
	strb r0, [r1, 0x8]
	movs r0, 0xFC
	lsls r0, 8
	movs r1, 0
	movs r2, 0x6
	bl sub_80D0884
_080D0624:
	movs r0, 0x1
_080D0626:
	pop {r1}
	bx r1
	thumb_func_end sub_80D0580

	thumb_func_start sub_80D062C
sub_80D062C: @ 80D062C
	push {r4-r7,lr}
	ldr r6, =gUnknown_02039D80
	ldr r2, [r6]
	ldrb r3, [r2, 0x2]
	ldrb r5, [r2, 0x6]
	subs r1, r3, r5
	cmp r1, 0
	bge _080D063E
	negs r1, r1
_080D063E:
	ldrb r0, [r2, 0x4]
	subs r0, r3, r0
	cmp r0, 0
	bge _080D0648
	negs r0, r0
_080D0648:
	subs r0, r1, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x7]
	subs r3, r1, r0
	cmp r3, 0
	bge _080D065A
	negs r3, r3
_080D065A:
	ldrb r2, [r2, 0x5]
	subs r0, r1, r2
	cmp r0, 0
	bge _080D0664
	negs r0, r0
_080D0664:
	subs r0, r3, r0
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r0, r4, 16
	asrs r4, r0, 16
	cmp r4, 0
	ble _080D0678
	adds r0, r5, 0
	bl sub_80D06D0
_080D0678:
	cmp r4, 0
	bge _080D0694
	ldr r2, [r6]
	ldrb r0, [r2, 0x4]
	ldrb r1, [r2, 0x3]
	ldrb r2, [r2, 0x5]
	bl sub_80D0740
	ldr r2, [r6]
	ldrb r0, [r2, 0x6]
	ldrb r1, [r2, 0x3]
	ldrb r2, [r2, 0x5]
	bl sub_80D06D0
_080D0694:
	lsls r0, r7, 16
	asrs r4, r0, 16
	cmp r4, 0
	ble _080D06A8
	ldr r2, [r6]
	ldrb r0, [r2, 0x7]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x4]
	bl sub_80D0708
_080D06A8:
	cmp r4, 0
	bge _080D06C4
	ldr r2, [r6]
	ldrb r0, [r2, 0x5]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x4]
	bl sub_80D0778
	ldr r2, [r6]
	ldrb r0, [r2, 0x7]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x4]
	bl sub_80D0708
_080D06C4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D062C

	thumb_func_start sub_80D06D0
sub_80D06D0: @ 80D06D0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D06EE
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D0700
_080D06EE:
	adds r1, r4, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	bl sub_80D07B0
	cmp r4, r5
	bls _080D06EE
_080D0700:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D06D0

	thumb_func_start sub_80D0708
sub_80D0708: @ 80D0708
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D0726
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D0738
_080D0726:
	adds r0, r4, 0
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r6, 0
	bl sub_80D07B0
	cmp r4, r5
	bls _080D0726
_080D0738:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D0708

	thumb_func_start sub_80D0740
sub_80D0740: @ 80D0740
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D075E
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D0770
_080D075E:
	adds r1, r4, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	bl sub_80D0834
	cmp r4, r5
	bls _080D075E
_080D0770:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D0740

	thumb_func_start sub_80D0778
sub_80D0778: @ 80D0778
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D0796
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D07A8
_080D0796:
	adds r0, r4, 0
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r6, 0
	bl sub_80D0834
	cmp r4, r5
	bls _080D0796
_080D07A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D0778

	thumb_func_start sub_80D07B0
sub_80D07B0: @ 80D07B0
	push {r4-r7,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r7, r0, r1
	lsls r4, r7, 1
	adds r4, r6, r4
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x41
	bl GetBoxMonDataFromSelectedBox
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0
	bl GetBoxMonDataFromSelectedBox
	adds r1, r0, 0
	cmp r5, 0
	beq _080D0828
	adds r0, r5, 0
	movs r2, 0x1
	bl GetMonIconPtr
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_80D3080
	adds r0, 0x8
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	movs r2, 0x88
	lsls r2, 6
	adds r1, r2
	ldrb r3, [r1]
	movs r2, 0x20
	str r2, [sp]
	str r2, [sp, 0x4]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	str r1, [sp, 0x8]
	lsls r1, r7, 3
	str r1, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	str r0, [sp, 0x18]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow4BitTo8Bit
_080D0828:
	add sp, 0x1C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D07B0

	thumb_func_start sub_80D0834
sub_80D0834: @ 80D0834
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r5, r0, r1
	lsls r0, r5, 1
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x41
	bl GetBoxMonDataFromSelectedBox
	lsls r0, 16
	cmp r0, 0
	beq _080D0878
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0x88
	lsls r1, 6
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r4, 1
	adds r2, r4
	lsls r2, 3
	lsls r3, r5, 3
	movs r1, 0x20
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	bl FillWindowPixelRect8Bit
_080D0878:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0834

	thumb_func_start sub_80D0884
sub_80D0884: @ 80D0884
	ldr r3, =gUnknown_02039D80
	ldr r3, [r3]
	strh r0, [r3, 0xC]
	strh r1, [r3, 0xE]
	strh r2, [r3, 0x10]
	bx lr
	.pool
	thumb_func_end sub_80D0884

	thumb_func_start sub_80D0894
sub_80D0894: @ 80D0894
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r1, [r4]
	ldrh r0, [r1, 0x10]
	cmp r0, 0
	beq _080D08BE
	ldrh r1, [r1, 0xC]
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgX
	ldr r0, [r4]
	ldrh r1, [r0, 0xE]
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgY
	ldr r1, [r4]
	ldrh r0, [r1, 0x10]
	subs r0, 0x1
	strh r0, [r1, 0x10]
_080D08BE:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D0894

	thumb_func_start sub_80D08CC
sub_80D08CC: @ 80D08CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, =gUnknown_02039D80
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	ldrb r2, [r1, 0x2]
	cmp r0, r2
	bls _080D08E4
	adds r0, r2, 0
_080D08E4:
	strb r0, [r1, 0x8]
	ldr r1, [r4]
	ldrb r0, [r1, 0x5]
	ldrb r2, [r1, 0x3]
	cmp r0, r2
	bls _080D08F2
	adds r0, r2, 0
_080D08F2:
	strb r0, [r1, 0x9]
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x4]
	subs r0, r1, r0
	cmp r0, 0
	bge _080D0902
	negs r0, r0
_080D0902:
	adds r0, 0x1
	strb r0, [r2, 0xA]
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x5]
	subs r0, r1, r0
	cmp r0, 0
	bge _080D0914
	negs r0, r0
_080D0914:
	adds r0, 0x1
	strb r0, [r2, 0xB]
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r6, 0
	ldr r0, [r4]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r8, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r0, r1
	mov r9, r0
	adds r2, r1, 0
	cmp r2, r9
	bge _080D0990
_080D093C:
	lsls r0, r2, 1
	adds r0, r2
	ldr r3, =gUnknown_02039D80
	ldr r1, [r3]
	lsls r0, 1
	ldrb r3, [r1, 0x8]
	adds r0, r3
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	adds r7, r2, 0x1
	cmp r4, r8
	bge _080D098A
	mov r0, r8
	subs r4, r0, r4
_080D095A:
	mov r0, r10
	adds r1, r5, 0
	bl GetBoxedMonPtr
	adds r1, r0, 0
	ldr r2, =gUnknown_02039D80
	ldr r0, [r2]
	lsls r2, r6, 2
	adds r2, r6
	lsls r2, 4
	adds r0, r2
	adds r0, 0x14
	movs r2, 0x50
	bl memcpy
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	subs r4, 0x1
	cmp r4, 0
	bne _080D095A
_080D098A:
	adds r2, r7, 0
	cmp r2, r9
	blt _080D093C
_080D0990:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D08CC

	thumb_func_start sub_80D09A4
sub_80D09A4: @ 80D09A4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r7, r2, r1
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r1, r0
	mov r9, r1
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, [r4]
	ldrb r2, [r0, 0x9]
	cmp r2, r9
	bge _080D0A0C
_080D09D0:
	lsls r0, r2, 1
	adds r0, r2
	ldr r1, =gUnknown_02039D80
	ldr r1, [r1]
	lsls r0, 1
	ldrb r3, [r1, 0x8]
	adds r0, r3
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	adds r6, r2, 0x1
	cmp r4, r7
	bge _080D0A06
	subs r4, r7, r4
_080D09EC:
	adds r0, r5, 0
	bl sub_80CB778
	mov r0, r8
	adds r1, r5, 0
	bl sub_80D2018
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	subs r4, 0x1
	cmp r4, 0
	bne _080D09EC
_080D0A06:
	adds r2, r6, 0
	cmp r2, r9
	blt _080D09D0
_080D0A0C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D09A4

	thumb_func_start sub_80D0A1C
sub_80D0A1C: @ 80D0A1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r8, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r0, r1
	mov r10, r0
	movs r6, 0
	adds r2, r1, 0
	cmp r2, r10
	bge _080D0A98
_080D0A42:
	lsls r0, r2, 1
	adds r0, r2
	ldr r3, =gUnknown_02039D80
	ldr r1, [r3]
	lsls r0, 1
	ldrb r4, [r1, 0x8]
	adds r0, r4
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	adds r7, r2, 0x1
	cmp r4, r8
	bge _080D0A92
	mov r9, r3
	mov r0, r8
	subs r4, r0, r4
_080D0A62:
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 4
	adds r1, 0x14
	mov r2, r9
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D0A80
	adds r0, r5, 0
	bl sub_80CB140
_080D0A80:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	subs r4, 0x1
	cmp r4, 0
	bne _080D0A62
_080D0A92:
	adds r2, r7, 0
	cmp r2, r10
	blt _080D0A42
_080D0A98:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0A1C

	thumb_func_start sub_80D0AAC
sub_80D0AAC: @ 80D0AAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r10, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r1, r0
	str r1, [sp]
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r7, 0
	ldr r0, [r4]
	ldrb r3, [r0, 0x9]
	ldr r0, [sp]
	cmp r3, r0
	bge _080D0B46
_080D0AE2:
	lsls r0, r3, 1
	adds r0, r3
	ldr r2, =gUnknown_02039D80
	ldr r1, [r2]
	lsls r0, 1
	ldrb r4, [r1, 0x8]
	adds r0, r4
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r5, [r1, 0x8]
	adds r3, 0x1
	mov r9, r3
	cmp r5, r10
	bge _080D0B3E
	mov r8, r2
	mov r0, r10
	subs r5, r0, r5
_080D0B04:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 4
	adds r4, r0, 0
	adds r4, 0x14
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D0B2C
	mov r0, r8
	ldr r2, [r0]
	adds r2, r4
	ldr r0, [sp, 0x4]
	adds r1, r6, 0
	bl CopyBoxMonFromAnyBox
_080D0B2C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	subs r5, 0x1
	cmp r5, 0
	bne _080D0B04
_080D0B3E:
	mov r3, r9
	ldr r1, [sp]
	cmp r3, r1
	blt _080D0AE2
_080D0B46:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0AAC

	thumb_func_start sub_80D0B5C
sub_80D0B5C: @ 80D0B5C
	push {lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0
	movs r1, 0x4
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x8
	movs r1, 0x80
	bl ClearGpuRegBits
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80D0B5C

	thumb_func_start sub_80D0BA4
sub_80D0BA4: @ 80D0BA4
	ldr r0, =gUnknown_02039D80
	ldr r2, [r0]
	ldrb r1, [r2, 0x3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	ldrb r2, [r2, 0x2]
	adds r0, r2
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_80D0BA4

	thumb_func_start sub_80D0BC0
sub_80D0BC0: @ 80D0BC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r9, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r0, r1, r0
	str r0, [sp]
	movs r7, 0
	adds r6, r1, 0
	cmp r6, r0
	bge _080D0C4E
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 1
	mov r8, r0
_080D0BF0:
	ldr r2, =gUnknown_02039D80
	ldr r1, [r2]
	ldrb r0, [r1, 0x8]
	add r0, r8
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	cmp r4, r9
	bge _080D0C42
	mov r10, r2
_080D0C04:
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 4
	adds r1, 0x14
	mov r2, r10
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D0C30
	adds r0, r5, 0
	movs r1, 0x5
	bl GetBoxMonDataFromSelectedBox
	cmp r0, 0
	beq _080D0C30
	movs r0, 0
	b _080D0C50
	.pool
_080D0C30:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x1
	cmp r4, r9
	blt _080D0C04
_080D0C42:
	movs r0, 0x6
	add r8, r0
	adds r6, 0x1
	ldr r2, [sp]
	cmp r6, r2
	blt _080D0BF0
_080D0C4E:
	movs r0, 0x1
_080D0C50:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0BC0

	thumb_func_start sub_80D0C60
sub_80D0C60: @ 80D0C60
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0D3E
	ldr r0, =gUnknown_03000F78
	str r0, [sp, 0x18]
	ldr r1, =0xffff0000
	add r2, sp, 0x18
	ldr r0, [r2, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	str r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gSpriteTemplate_857BC70
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r7, 0
	mov r9, r2
	mov r8, r3
	movs r0, 0
	mov r10, r0
_080D0CA0:
	adds r6, r7, 0x7
	lsls r1, r6, 16
	mov r2, r9
	ldrh r0, [r2, 0x4]
	orrs r0, r1
	str r0, [r2, 0x4]
	mov r0, r9
	bl LoadCompressedObjectPic
	mov r4, r9
	ldrh r0, [r4, 0x6]
	bl GetSpriteTileStartByTag
	mov r5, r8
	ldr r1, [r5]
	lsls r5, r7, 4
	ldr r2, =0x00002208
	adds r1, r2
	adds r1, r5
	lsls r0, 16
	lsrs r0, 11
	ldr r4, =0x06010000
	adds r0, r4
	str r0, [r1]
	ldr r0, =0xffffdacb
	adds r4, r7, r0
	lsls r0, r4, 16
	lsrs r0, 16
	bl AllocSpritePalette
	mov r2, r8
	ldr r1, [r2]
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x0000220c
	adds r1, r2
	strh r0, [r1]
	ldrh r0, [r1]
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	strh r0, [r1]
	mov r0, sp
	strh r6, [r0]
	strh r4, [r0, 0x2]
	movs r1, 0
	movs r2, 0
	movs r3, 0xB
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r4, r8
	ldr r2, [r4]
	ldr r6, =0x00002204
	adds r2, r6
	adds r2, r5
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r5
	ldr r1, =0x00002210
	adds r0, r1
	mov r2, r10
	strb r2, [r0]
	adds r7, 0x1
	cmp r7, 0x2
	ble _080D0CA0
_080D0D3E:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r4, =0x00002234
	adds r0, r4
	movs r1, 0
	strh r1, [r0]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0C60

	thumb_func_start sub_80D0D8C
sub_80D0D8C: @ 80D0D8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0E42
	mov r0, r8
	adds r1, r7, 0
	bl sub_80D1324
	cmp r0, 0
	bne _080D0E42
	mov r0, r8
	cmp r0, 0
	beq _080D0DC4
	cmp r0, 0x1
	beq _080D0DDA
	b _080D0E42
	.pool
_080D0DC4:
	adds r0, r7, 0
	movs r1, 0x5
	bl GetBoxMonDataFromSelectedBox
	cmp r0, 0
	beq _080D0E42
	adds r0, r7, 0
	movs r1, 0xC
	bl GetBoxMonDataFromSelectedBox
	b _080D0DFC
_080D0DDA:
	cmp r7, 0x5
	bhi _080D0E42
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _080D0E42
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
_080D0DFC:
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080D0E42
	adds r0, r4, 0
	bl GetItemIconPic
	adds r6, r0, 0
	adds r0, r4, 0
	bl GetItemIconPalette
	adds r5, r0, 0
	bl sub_80D12E8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_80D140C
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80D1524
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80D1740
_080D0E42:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0D8C

	thumb_func_start sub_80D0E50
sub_80D0E50: @ 80D0E50
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0E86
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_80D1604
_080D0E86:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0E50

	thumb_func_start sub_80D0E90
sub_80D0E90: @ 80D0E90
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r7, r5, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0F20
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_80D1604
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_80D140C
	cmp r6, 0
	bne _080D0EF8
	adds r0, r5, 0
	movs r1, 0xC
	mov r2, sp
	bl SetBoxMonDataFromSelectedBox
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80CB7AC
	b _080D0F10
	.pool
_080D0EF8:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_80CBBDC
_080D0F10:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00000ce6
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r2, =0x00002234
	adds r0, r2
	strh r1, [r0]
_080D0F20:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0E90

	thumb_func_start sub_80D0F38
sub_80D0F38: @ 80D0F38
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r5, 0
	bl GetItemIconPic
	mov r8, r0
	adds r0, r5, 0
	bl GetItemIconPalette
	adds r6, r0, 0
	bl sub_80D12E8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_80D1524
	adds r0, r4, 0
	movs r1, 0x6
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl sub_80D1604
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_80D140C
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80D1740
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	adds r0, r1
	strh r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0F38

	thumb_func_start sub_80D0FAC
sub_80D0FAC: @ 80D0FAC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gUnknown_02039D08
	mov r8, r0
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D106A
	mov r0, r9
	adds r1, r7, 0
	bl sub_80D1370
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0
	bl sub_80D1604
	mov r1, r9
	cmp r1, 0
	bne _080D101C
	adds r0, r7, 0
	movs r1, 0xC
	bl GetBoxMonDataFromSelectedBox
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r8
	ldr r2, [r0]
	ldr r4, =0x00002234
	adds r2, r4
	adds r0, r7, 0
	movs r1, 0xC
	bl SetBoxMonDataFromSelectedBox
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	b _080D1048
	.pool
_080D101C:
	movs r0, 0x64
	adds r4, r7, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r8
	ldr r2, [r0]
	ldr r5, =0x00002234
	adds r2, r5
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
_080D1048:
	strh r6, [r0]
	movs r0, 0x2
	movs r1, 0
	bl sub_80D1370
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x4
	mov r2, r9
	adds r3, r7, 0
	bl sub_80D1604
_080D106A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0FAC

	thumb_func_start sub_80D1080
sub_80D1080: @ 80D1080
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	mov r8, r5
	ldr r6, =gUnknown_02039D08
	ldr r0, [r6]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D1100
	movs r0, 0x2
	movs r1, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_80D1604
	cmp r7, 0
	bne _080D10E0
	ldr r2, [r6]
	ldr r0, =0x00002234
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0xC
	bl SetBoxMonDataFromSelectedBox
	adds r0, r5, 0
	movs r1, 0
	bl sub_80CB7AC
	b _080D1100
	.pool
_080D10E0:
	movs r0, 0x64
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r2, [r6]
	ldr r1, =0x00002234
	adds r2, r1
	movs r1, 0xC
	bl SetMonData
	mov r0, r8
	movs r1, 0
	bl sub_80CBBDC
_080D1100:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1080

	thumb_func_start sub_80D1114
sub_80D1114: @ 80D1114
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r7, r5, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D1188
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_80D1604
	cmp r6, 0
	bne _080D1170
	adds r0, r5, 0
	movs r1, 0xC
	mov r2, sp
	bl SetBoxMonDataFromSelectedBox
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80CB7AC
	b _080D1188
	.pool
_080D1170:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_80CBBDC
_080D1188:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1114

	thumb_func_start sub_80D1194
sub_80D1194: @ 80D1194
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D11C2
	movs r0, 0x2
	movs r1, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x5
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0
	bl sub_80D1604
_080D11C2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1194

	thumb_func_start sub_80D11CC
sub_80D11CC: @ 80D11CC
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D120A
	movs r4, 0
_080D11DA:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	lsls r0, r4, 4
	adds r1, r0
	ldr r2, =0x00002210
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D1204
	subs r2, 0x2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D1204
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0x7
	movs r2, 0x2
	movs r3, 0
	bl sub_80D1604
_080D1204:
	adds r4, 0x1
	cmp r4, 0x2
	ble _080D11DA
_080D120A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D11CC

	thumb_func_start sub_80D1218
sub_80D1218: @ 80D1218
	push {r4,r5,lr}
	movs r5, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002204
	adds r4, r0, r1
	adds r3, r0, 0
_080D1226:
	ldr r1, =0x00002210
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D1268
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x28
	ands r0, r1
	cmp r0, 0x8
	beq _080D124E
	ldr r1, [r2, 0x1C]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _080D1268
	ldr r0, =sub_80D1AD8
	cmp r1, r0
	beq _080D1268
_080D124E:
	movs r0, 0x1
	b _080D1274
	.pool
_080D1268:
	adds r4, 0x10
	adds r3, 0x10
	adds r5, 0x1
	cmp r5, 0x2
	ble _080D1226
	movs r0, 0
_080D1274:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80D1218

	thumb_func_start sub_80D127C
sub_80D127C: @ 80D127C
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x3
	bne _080D12B0
	movs r2, 0
	ldr r0, =0x0000220e
	adds r1, r0
_080D128E:
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _080D12A8
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _080D12A8
	movs r0, 0x1
	b _080D12B2
	.pool
_080D12A8:
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x2
	ble _080D128E
_080D12B0:
	movs r0, 0
_080D12B2:
	pop {r1}
	bx r1
	thumb_func_end sub_80D127C

	thumb_func_start sub_80D12B8
sub_80D12B8: @ 80D12B8
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetItem
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D12B8

	thumb_func_start sub_80D12D4
sub_80D12D4: @ 80D12D4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80D12D4

	thumb_func_start sub_80D12E8
sub_80D12E8: @ 80D12E8
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gUnknown_02039D08
	ldr r3, =0x00002210
	movs r4, 0x1
_080D12F2:
	ldr r0, [r5]
	lsls r1, r2, 4
	adds r0, r1
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _080D1310
	strb r4, [r1]
	adds r0, r2, 0
	b _080D131C
	.pool
_080D1310:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _080D12F2
	movs r0, 0x3
_080D131C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80D12E8

	thumb_func_start sub_80D1324
sub_80D1324: @ 80D1324
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
_080D1334:
	ldr r5, =0x00002210
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D1360
	subs r5, 0x2
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D1360
	adds r5, 0x1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r1
	bne _080D1360
	movs r0, 0x1
	b _080D136A
	.pool
_080D1360:
	adds r2, 0x10
	adds r3, 0x1
	cmp r3, 0x2
	ble _080D1334
	movs r0, 0
_080D136A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80D1324

	thumb_func_start sub_80D1370
sub_80D1370: @ 80D1370
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r3, 0
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
_080D1380:
	lsls r0, r3, 4
	adds r2, r1, r0
	ldr r6, =0x00002210
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D13B0
	subs r6, 0x2
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, r5
	bne _080D13B0
	adds r6, 0x1
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D13B0
	adds r0, r3, 0
	b _080D13BC
	.pool
_080D13B0:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _080D1380
	movs r0, 0x3
_080D13BC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D1370

	thumb_func_start sub_80D13C4
sub_80D13C4: @ 80D13C4
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r2, 0
	ldr r0, =gUnknown_02039D08
	ldr r3, [r0]
	ldr r0, =0x00002204
	adds r4, r3, r0
	ldr r6, =0x00002210
_080D13D4:
	lsls r1, r2, 4
	adds r0, r3, r1
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D13F8
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, r5
	bne _080D13F8
	adds r0, r2, 0
	b _080D1404
	.pool
_080D13F8:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _080D13D4
	movs r0, 0x3
_080D1404:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D13C4

	thumb_func_start sub_80D140C
sub_80D140C: @ 80D140C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	cmp r5, 0x2
	bhi _080D150A
	cmp r1, 0
	beq _080D1438
	cmp r1, 0x1
	beq _080D1494
	ldr r4, =gUnknown_02039D08
	lsls r3, r5, 4
	b _080D14F4
	.pool
_080D1438:
	adds r0, r7, 0
	movs r1, 0x6
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_02039D08
	ldr r2, [r6]
	lsls r5, 4
	ldr r1, =0x00002204
	adds r2, r1
	adds r2, r5
	ldr r3, [r2]
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, 0x70
	strh r1, [r3, 0x20]
	ldr r3, [r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x38
	strh r1, [r3, 0x22]
	ldr r2, [r2]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r4, r6, 0
	adds r3, r5, 0
	b _080D14F4
	.pool
_080D1494:
	cmp r7, 0
	bne _080D14BC
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	lsls r3, r5, 4
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0x74
	strh r1, [r2, 0x20]
	ldr r1, [r0]
	movs r0, 0x4C
	strh r0, [r1, 0x22]
	b _080D14DC
	.pool
_080D14BC:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	lsls r3, r5, 4
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0xA4
	strh r1, [r2, 0x20]
	ldr r2, [r0]
	subs r1, r7, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x1C
	strh r0, [r2, 0x22]
_080D14DC:
	ldr r0, [r4]
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
_080D14F4:
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =0x0000220e
	adds r0, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =0x0000220f
	adds r0, r1
	strb r7, [r0]
_080D150A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D140C

	thumb_func_start sub_80D1524
sub_80D1524: @ 80D1524
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r1
	mov r9, r2
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x2
	bhi _080D15AC
	movs r0, 0
	str r0, [sp]
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r6, =0x000042c4
	adds r1, r6
	ldr r2, =0x01000080
	mov r0, sp
	bl CpuFastSet
	ldr r1, [r4]
	ldr r5, =0x000022c4
	adds r1, r5
	mov r0, r8
	bl LZ77UnCompWram
	lsls r7, 4
	mov r8, r7
	adds r7, r4, 0
	movs r4, 0x2
_080D1562:
	ldr r1, [r7]
	adds r0, r1, r5
	adds r1, r6
	movs r2, 0x18
	bl CpuFastSet
	adds r6, 0x80
	adds r5, 0x60
	subs r4, 0x1
	cmp r4, 0
	bge _080D1562
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldr r4, =0x000042c4
	adds r0, r1, r4
	ldr r2, =0x00002208
	adds r1, r2
	add r1, r8
	ldr r1, [r1]
	movs r2, 0x80
	bl CpuFastSet
	ldr r1, [r5]
	adds r1, r4
	mov r0, r9
	bl LZ77UnCompWram
	ldr r0, [r5]
	adds r4, r0, r4
	add r0, r8
	ldr r1, =0x0000220c
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
_080D15AC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1524

	thumb_func_start sub_80D15D4
sub_80D15D4: @ 80D15D4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	cmp r2, 0x2
	bhi _080D15F6
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r2, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	adds r1, r3, 0
	bl StartSpriteAffineAnim
_080D15F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D15D4

	thumb_func_start sub_80D1604
sub_80D1604: @ 80D1604
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	cmp r4, 0x2
	bls _080D161C
	b _080D172E
_080D161C:
	cmp r0, 0x7
	bls _080D1622
	b _080D172E
_080D1622:
	lsls r0, 2
	ldr r1, =_080D1630
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D1630:
	.4byte _080D1650
	.4byte _080D1674
	.4byte _080D1698
	.4byte _080D16C4
	.4byte _080D16F0
	.4byte _080D172E
	.4byte _080D172E
	.4byte _080D171C
_080D1650:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	strh r4, [r1, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80D1A48
	b _080D172C
	.pool
_080D1674:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80D1A74
	b _080D172C
	.pool
_080D1698:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	strh r5, [r1, 0x3A]
	ldr r1, [r0]
	strh r3, [r1, 0x3C]
	ldr r1, [r0]
	ldr r0, =sub_80D1B14
	b _080D172C
	.pool
_080D16C4:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r2, [r0]
	ldr r1, =sub_80D1B94
	str r1, [r2, 0x1C]
	strh r5, [r2, 0x3A]
	ldr r0, [r0]
	strh r3, [r0, 0x3C]
	b _080D172E
	.pool
_080D16F0:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	strh r5, [r1, 0x3A]
	ldr r1, [r0]
	strh r3, [r1, 0x3C]
	ldr r1, [r0]
	ldr r0, =sub_80D1C30
	b _080D172C
	.pool
_080D171C:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =sub_80D1CCC
_080D172C:
	str r0, [r1, 0x1C]
_080D172E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1604

	thumb_func_start sub_80D1740
sub_80D1740: @ 80D1740
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r2, 0x2
	bhi _080D1780
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	lsls r2, 4
	adds r0, r2
	ldr r3, =0x00002210
	adds r0, r3
	strb r4, [r0]
	ldr r0, [r1]
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	movs r3, 0
	cmp r4, 0
	bne _080D176E
	movs r3, 0x1
_080D176E:
	adds r2, r0, 0
	adds r2, 0x3E
	lsls r3, 2
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_080D1780:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1740

	thumb_func_start GetItemIconPic
GetItemIconPic: @ 80D1794
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPic

	thumb_func_start GetItemIconPalette
GetItemIconPalette: @ 80D17A4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPalette

	thumb_func_start sub_80D17B4
sub_80D17B4: @ 80D17B4
	push {r4,lr}
	sub sp, 0x14
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	beq _080D17D4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	b _080D17DA
	.pool
_080D17D4:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000ce6
_080D17DA:
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetDescription
	adds r4, r0, 0
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl sub_8199F74
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D17B4

	thumb_func_start sub_80D1818
sub_80D1818: @ 80D1818
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002236
	adds r0, r1
	movs r1, 0x15
	strh r1, [r0]
	ldr r1, =gUnknown_0857BB24
	movs r3, 0x9D
	lsls r3, 1
	movs r0, 0
	movs r2, 0x80
	bl LoadBgTiles
	movs r0, 0
	bl sub_80D19B4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1818

	thumb_func_start sub_80D184C
sub_80D184C: @ 80D184C
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0
	bne _080D186C
	movs r0, 0
	b _080D18D2
	.pool
_080D186C:
	subs r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, 0x15
	subs r5, r0, r1
	movs r4, 0
	cmp r4, r5
	bge _080D18BC
_080D187C:
	movs r0, 0
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r0, r2
	adds r1, 0x14
	ldrh r0, [r0]
	adds r1, r0
	adds r1, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x15
	str r0, [sp, 0xC]
	movs r0, 0
	movs r3, 0xD
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x1
	cmp r4, r5
	blt _080D187C
_080D18BC:
	adds r0, r5, 0
	bl sub_80D19B4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002236
	adds r0, r1
	ldrh r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080D18D2:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D184C

	thumb_func_start sub_80D18E4
sub_80D18E4: @ 80D18E4
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x00002236
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x16
	bne _080D1904
	movs r0, 0
	b _080D19A4
	.pool
_080D1904:
	cmp r0, 0
	bne _080D1920
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x15
	movs r3, 0xC
	bl FillBgTilemapBufferRect
_080D1920:
	ldr r1, [r5]
	adds r1, r4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, 0x15
	subs r5, r0, r1
	movs r4, 0
	cmp r4, r5
	bge _080D1976
_080D1936:
	movs r0, 0
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r0, r2
	adds r1, 0x14
	ldrh r0, [r0]
	adds r1, r0
	adds r1, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x15
	str r0, [sp, 0xC]
	movs r0, 0
	movs r3, 0xD
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x1
	cmp r4, r5
	blt _080D1936
_080D1976:
	cmp r5, 0
	blt _080D1980
	adds r0, r5, 0
	bl sub_80D19B4
_080D1980:
	adds r2, r5, 0x1
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
_080D19A4:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D18E4

	thumb_func_start sub_80D19B4
sub_80D19B4: @ 80D19B4
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	cmp r7, 0
	beq _080D19EC
	movs r1, 0x9D
	lsls r1, 1
	lsls r4, r7, 24
	lsrs r4, 24
	str r4, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000093a
	str r4, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0x14
	bl FillBgTilemapBufferRect
_080D19EC:
	ldr r1, =0x0000013b
	lsls r5, r7, 24
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r6, 0xF
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0xD
	bl FillBgTilemapBufferRect
	movs r1, 0x9E
	lsls r1, 1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000013d
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0x14
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D19B4

	thumb_func_start sub_80D1A48
sub_80D1A48: @ 80D1A48
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080D1A68
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80D1740
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D1A68:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1A48

	thumb_func_start sub_80D1A74
sub_80D1A74: @ 80D1A74
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _080D1A86
	cmp r1, 0x1
	beq _080D1AA2
	b _080D1AD0
_080D1A86:
	ldrh r0, [r3, 0x20]
	lsls r0, 4
	strh r0, [r3, 0x30]
	ldrh r0, [r3, 0x22]
	lsls r0, 4
	strh r0, [r3, 0x32]
	movs r0, 0xA
	strh r0, [r3, 0x34]
	movs r0, 0x15
	strh r0, [r3, 0x36]
	strh r1, [r3, 0x38]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
_080D1AA2:
	ldrh r1, [r3, 0x30]
	ldrh r0, [r3, 0x34]
	subs r1, r0
	strh r1, [r3, 0x30]
	ldrh r0, [r3, 0x32]
	ldrh r2, [r3, 0x36]
	subs r0, r2
	strh r0, [r3, 0x32]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r3, 0x20]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r3, 0x22]
	ldrh r0, [r3, 0x38]
	adds r0, 0x1
	strh r0, [r3, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1AD0
	ldr r0, =sub_80D1AD8
	str r0, [r3, 0x1C]
_080D1AD0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1A74

	thumb_func_start sub_80D1AD8
sub_80D1AD8: @ 80D1AD8
	ldr r1, =gUnknown_02039D08
	ldr r3, [r1]
	ldr r1, =0x00000cb4
	adds r3, r1
	ldr r1, [r3]
	ldrh r1, [r1, 0x20]
	adds r1, 0x4
	strh r1, [r0, 0x20]
	ldr r2, [r3]
	ldrh r1, [r2, 0x26]
	ldrh r2, [r2, 0x22]
	adds r1, r2
	adds r1, 0x8
	strh r1, [r0, 0x22]
	ldr r1, [r3]
	ldrb r1, [r1, 0x5]
	movs r2, 0xC
	ands r2, r1
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	bx lr
	.pool
	thumb_func_end sub_80D1AD8

	thumb_func_start sub_80D1B14
sub_80D1B14: @ 80D1B14
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1B26
	cmp r1, 0x1
	beq _080D1B42
	b _080D1B8A
_080D1B26:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1B42:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	ldrh r2, [r4, 0x32]
	adds r1, r2
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1B8A
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D1B8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1B14

	thumb_func_start sub_80D1B94
sub_80D1B94: @ 80D1B94
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1BA6
	cmp r1, 0x1
	beq _080D1BC2
	b _080D1C20
_080D1BA6:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1BC2:
	ldrh r1, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	subs r1, r0
	strh r1, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	subs r0, r2
	strh r0, [r4, 0x32]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x20]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x22]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1C20
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =sub_80D1AD8
	str r0, [r4, 0x1C]
_080D1C20:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1B94

	thumb_func_start sub_80D1C30
sub_80D1C30: @ 80D1C30
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1C42
	cmp r1, 0x1
	beq _080D1C5E
	b _080D1CBE
_080D1C42:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1C5E:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	ldrh r2, [r4, 0x32]
	adds r1, r2
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1CBE
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
_080D1CBE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1C30

	thumb_func_start sub_80D1CCC
sub_80D1CCC: @ 80D1CCC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x22]
	subs r0, 0x8
	strh r0, [r2, 0x22]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080D1CFC
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	adds r0, r2, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80D1740
_080D1CFC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1CCC

	thumb_func_start TaskDummy0
TaskDummy0: @ 80D1D04
	bx lr
	thumb_func_end TaskDummy0

	thumb_func_start nullsub_98
nullsub_98: @ 80D1D08
	bx lr
	thumb_func_end nullsub_98

	thumb_func_start StorageGetCurrentBox
@ char StorageGetCurrentBox()
StorageGetCurrentBox: @ 80D1D0C
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end StorageGetCurrentBox

	thumb_func_start sub_80D1D18
sub_80D1D18: @ 80D1D18
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bhi _080D1D28
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	strb r1, [r0]
_080D1D28:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1D18

	thumb_func_start GetBoxMonDataFromAnyBox
GetBoxMonDataFromAnyBox: @ 80D1D30
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1D6C
	cmp r4, 0x1D
	bhi _080D1D6C
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	bl GetBoxMonData
	b _080D1D6E
	.pool
_080D1D6C:
	movs r0, 0
_080D1D6E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetBoxMonDataFromAnyBox

	thumb_func_start SetBoxMonDataFromAnyBox
SetBoxMonDataFromAnyBox: @ 80D1D74
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1DAC
	cmp r4, 0x1D
	bhi _080D1DAC
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	adds r2, r6, 0
	bl SetBoxMonData
_080D1DAC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonDataFromAnyBox

	thumb_func_start GetBoxMonDataFromSelectedBox
GetBoxMonDataFromSelectedBox: @ 80D1DB8
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r3, 0
	bl GetBoxMonDataFromAnyBox
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBoxMonDataFromSelectedBox

	thumb_func_start SetBoxMonDataFromSelectedBox
SetBoxMonDataFromSelectedBox: @ 80D1DD8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl SetBoxMonDataFromAnyBox
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonDataFromSelectedBox

	thumb_func_start GetBoxMonNickFromAnyBox
GetBoxMonNickFromAnyBox: @ 80D1DFC
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1E38
	cmp r4, 0x1D
	bhi _080D1E38
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	movs r1, 0x2
	adds r2, r5, 0
	bl GetBoxMonData
	b _080D1E3C
	.pool
_080D1E38:
	movs r0, 0xFF
	strb r0, [r5]
_080D1E3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetBoxMonNickFromAnyBox

	thumb_func_start sub_80D1E44
sub_80D1E44: @ 80D1E44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r0, 0xD
	bhi _080D1E84
	cmp r2, 0x1D
	bhi _080D1E84
	ldr r6, =gPokemonStoragePtr
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	ldr r0, [r6]
	adds r0, r5
	lsls r1, r2, 2
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D1E84
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	bl GetLevelFromBoxMonExp
_080D1E84:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D1E44

	thumb_func_start SetBoxMonNickFromAnyBox
SetBoxMonNickFromAnyBox: @ 80D1E90
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1EC6
	cmp r4, 0x1D
	bhi _080D1EC6
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	movs r1, 0x2
	adds r2, r5, 0
	bl SetBoxMonData
_080D1EC6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonNickFromAnyBox

	thumb_func_start GetAndCopyBoxMonDataFromAnyBox
GetAndCopyBoxMonDataFromAnyBox: @ 80D1ED0
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1F10
	cmp r4, 0x1D
	bhi _080D1F10
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	adds r2, r6, 0
	bl GetBoxMonData
	b _080D1F12
	.pool
_080D1F10:
	movs r0, 0
_080D1F12:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetAndCopyBoxMonDataFromAnyBox

	thumb_func_start CopyBoxMonFromAnyBox
CopyBoxMonFromAnyBox: @ 80D1F18
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r4, 0xD
	bhi _080D1F4E
	cmp r1, 0x1D
	bhi _080D1F4E
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	lsls r3, r1, 2
	adds r3, r1
	lsls r3, 4
	lsls r2, r4, 2
	adds r2, r4
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 5
	adds r3, r1
	adds r0, r3
	adds r0, 0x4
	adds r1, r5, 0
	movs r2, 0x50
	bl memcpy
_080D1F4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyBoxMonFromAnyBox

	thumb_func_start sub_80D1F58
sub_80D1F58: @ 80D1F58
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r4, 0xD
	bhi _080D1F8E
	cmp r2, 0x1D
	bhi _080D1F8E
	ldr r0, =gPokemonStoragePtr
	ldr r1, [r0]
	lsls r3, r2, 2
	adds r3, r2
	lsls r3, 4
	lsls r2, r4, 2
	adds r2, r4
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	adds r3, r0
	adds r1, r3
	adds r1, 0x4
	adds r0, r5, 0
	movs r2, 0x50
	bl memcpy
_080D1F8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1F58

	thumb_func_start sub_80D1F98
sub_80D1F98: @ 80D1F98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	ldr r4, [sp, 0x30]
	ldr r5, [sp, 0x34]
	ldr r6, [sp, 0x3C]
	mov r12, r6
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r0, r12
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r7, 0xD
	bhi _080D2004
	cmp r6, 0x1D
	bhi _080D2004
	ldr r2, =gPokemonStoragePtr
	lsls r0, r7, 2
	adds r0, r7
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 4
	adds r0, r1
	str r5, [sp]
	ldr r1, [sp, 0x38]
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r1, [sp, 0x40]
	str r1, [sp, 0xC]
	mov r1, r9
	mov r2, r8
	adds r3, r4, 0
	bl CreateBoxMon
_080D2004:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1F98

	thumb_func_start sub_80D2018
sub_80D2018: @ 80D2018
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D2048
	cmp r4, 0x1D
	bhi _080D2048
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	bl ZeroBoxMonData
_080D2048:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2018

	thumb_func_start sub_80D2054
sub_80D2054: @ 80D2054
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D2088
	cmp r4, 0x1D
	bhi _080D2088
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	bl BoxMonToMon
_080D2088:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2054

	thumb_func_start GetBoxedMonPtr
@ pokemon *GetBoxedMonPtr(u8 box_id, u8 pos)
GetBoxedMonPtr: @ 80D2094
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D20C8
	cmp r4, 0x1D
	bhi _080D20C8
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	b _080D20CA
	.pool
_080D20C8:
	movs r0, 0
_080D20CA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBoxedMonPtr

	thumb_func_start GetBoxNamePtr
GetBoxNamePtr: @ 80D20D0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xD
	bls _080D20DE
	movs r0, 0
	b _080D20EC
_080D20DE:
	ldr r0, =gPokemonStoragePtr
	lsls r1, r2, 3
	adds r1, r2
	ldr r2, =0x00008344
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
_080D20EC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBoxNamePtr

	thumb_func_start sub_80D20F8
sub_80D20F8: @ 80D20F8
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bls _080D2106
	movs r0, 0
	b _080D2112
_080D2106:
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldr r2, =0x000083c2
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
_080D2112:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D20F8

	thumb_func_start sub_80D2120
sub_80D2120: @ 80D2120
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r2, 0xD
	bhi _080D213E
	cmp r1, 0x10
	bhi _080D213E
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldr r3, =0x000083c2
	adds r0, r3
	adds r0, r2
	strb r1, [r0]
_080D213E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2120

	thumb_func_start sub_80D214C
sub_80D214C: @ 80D214C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	adds r4, r3, 0
	ldr r2, =0x0000ffff
	cmp r3, 0x1
	bhi _080D216E
	movs r2, 0x1
	cmp r3, 0x1
	beq _080D2172
_080D216E:
	cmp r4, 0x3
	bne _080D21BC
_080D2172:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080D2208
	cmp r1, r7
	bgt _080D2208
_080D218A:
	asrs r4, r0, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	add r0, r8
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	bne _080D21B4
	asrs r0, r6, 16
	adds r0, r4, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080D2208
	cmp r2, r7
	ble _080D218A
	b _080D2208
	.pool
_080D21B4:
	adds r0, r4, 0
	b _080D220C
_080D21B8:
	adds r0, r5, 0
	b _080D220C
_080D21BC:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080D2208
	cmp r1, r7
	bgt _080D2208
_080D21D4:
	asrs r5, r0, 16
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 4
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _080D21F8
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetBoxMonData
	cmp r0, 0
	beq _080D21B8
_080D21F8:
	asrs r0, r6, 16
	adds r0, r5, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080D2208
	cmp r2, r7
	ble _080D21D4
_080D2208:
	movs r0, 0x1
	negs r0, r0
_080D220C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D214C

	thumb_func_start CheckFreePokemonStorageSpace
CheckFreePokemonStorageSpace: @ 80D2218
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gPokemonStoragePtr
	mov r8, r0
	movs r7, 0x4
_080D2228:
	movs r5, 0
	adds r6, r7, 0
	movs r4, 0
_080D222E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	adds r0, r4
	movs r1, 0x5
	str r2, [sp]
	bl GetBoxMonData
	ldr r2, [sp]
	cmp r0, 0
	bne _080D224C
	movs r0, 0x1
	b _080D2262
	.pool
_080D224C:
	adds r4, 0x50
	adds r5, 0x1
	cmp r5, 0x1D
	ble _080D222E
	movs r0, 0x96
	lsls r0, 4
	adds r7, r0
	adds r2, 0x1
	cmp r2, 0xD
	ble _080D2228
	movs r0, 0
_080D2262:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckFreePokemonStorageSpace

	thumb_func_start sub_80D2270
sub_80D2270: @ 80D2270
	push {r4-r6,lr}
	adds r2, r1, 0
	cmp r0, 0xD
	bhi _080D22C8
	cmp r2, 0x1D
	bhi _080D22C8
	ldr r6, =gPokemonStoragePtr
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	ldr r0, [r6]
	adds r0, r5
	lsls r1, r2, 2
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D22C8
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D22C8
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0x4
	bl GetBoxMonData
	cmp r0, 0
	bne _080D22C8
	movs r0, 0x1
	b _080D22CA
	.pool
_080D22C8:
	movs r0, 0
_080D22CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2270

	thumb_func_start sub_80D22D0
sub_80D22D0: @ 80D22D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	movs r0, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_080D22E0:
	lsls r1, r0, 2
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	movs r5, 0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r4, r0, 0x4
	movs r6, 0x1D
_080D22F4:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	adds r0, r5
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D231A
	mov r2, r9
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D231A
	adds r7, 0x1
_080D231A:
	adds r5, 0x50
	subs r6, 0x1
	cmp r6, 0
	bge _080D22F4
	mov r0, r8
	cmp r0, 0xD
	ble _080D22E0
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D22D0

	thumb_func_start sub_80D233C
sub_80D233C: @ 80D233C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	movs r0, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_080D234C:
	lsls r1, r0, 2
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	movs r5, 0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r4, r0, 0x4
	movs r6, 0x1D
_080D2360:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	adds r0, r5
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	bne _080D2384
	mov r2, r9
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2386
_080D2384:
	adds r7, 0x1
_080D2386:
	adds r5, 0x50
	subs r6, 0x1
	cmp r6, 0
	bge _080D2360
	mov r0, r8
	cmp r0, 0xD
	ble _080D234C
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D233C

	thumb_func_start sub_80D23A8
sub_80D23A8: @ 80D23A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	ldr r0, =0x00000163
	strh r0, [r1, 0x2]
	movs r0, 0
	mov r8, r0
	ldr r7, =gPokemonStoragePtr
	movs r5, 0x4
_080D23C0:
	movs r6, 0
	movs r4, 0
_080D23C4:
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2404
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D2404
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x51
	mov r2, sp
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2404
	movs r0, 0x1
	b _080D241E
	.pool
_080D2404:
	adds r4, 0x50
	adds r6, 0x1
	cmp r6, 0x1D
	ble _080D23C4
	movs r0, 0x96
	lsls r0, 4
	adds r5, r0
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0xD
	ble _080D23C0
	movs r0, 0
_080D241E:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D23A8

	thumb_func_start ResetWaldaWallpaper
ResetWaldaWallpaper: @ 80D242C
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x00003d84
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, =0x00003d85
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, =0x00003d70
	adds r2, r1, r0
	ldr r0, =0x00007b35
	strh r0, [r2]
	subs r3, 0x14
	adds r2, r1, r3
	ldr r0, =0x00006186
	strh r0, [r2]
	ldr r0, =0x00003d74
	adds r1, r0
	movs r0, 0xFF
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetWaldaWallpaper

	thumb_func_start SetWaldaWallpaperLockedOrUnlocked
SetWaldaWallpaperLockedOrUnlocked: @ 80D2480
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x00003d86
	adds r1, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end SetWaldaWallpaperLockedOrUnlocked

	thumb_func_start IsWaldaWallpaperUnlocked
IsWaldaWallpaperUnlocked: @ 80D2494
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d86
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end IsWaldaWallpaperUnlocked

	thumb_func_start GetWaldaWallpaperPatternId
GetWaldaWallpaperPatternId: @ 80D24A8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d85
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperPatternId

	thumb_func_start SetWaldaWallpaperPatternId
SetWaldaWallpaperPatternId: @ 80D24BC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bhi _080D24D0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d85
	adds r0, r2
	strb r1, [r0]
_080D24D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperPatternId

	thumb_func_start GetWaldaWallpaperIconId
GetWaldaWallpaperIconId: @ 80D24DC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d84
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperIconId

	thumb_func_start SetWaldaWallpaperIconId
SetWaldaWallpaperIconId: @ 80D24F0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1D
	bhi _080D2504
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d84
	adds r0, r2
	strb r1, [r0]
_080D2504:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperIconId

	thumb_func_start GetWaldaWallpaperColorsPtr
GetWaldaWallpaperColorsPtr: @ 80D2510
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d70
	adds r0, r1
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperColorsPtr

	thumb_func_start SetWaldaWallpaperColors
SetWaldaWallpaperColors: @ 80D2524
	push {r4,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	ldr r4, =0x00003d70
	adds r3, r2, r4
	strh r0, [r3]
	ldr r0, =0x00003d72
	adds r2, r0
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperColors

	thumb_func_start GetWaldaPhrasePtr
GetWaldaPhrasePtr: @ 80D2548
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d74
	adds r0, r1
	bx lr
	.pool
	thumb_func_end GetWaldaPhrasePtr

	thumb_func_start SetWaldaPhrase
SetWaldaPhrase: @ 80D255C
	push {lr}
	adds r1, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d74
	adds r0, r2
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaPhrase

	thumb_func_start IsWaldaPhraseEmpty
IsWaldaPhraseEmpty: @ 80D2578
	push {lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d74
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080D258C
	movs r1, 0x1
_080D258C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsWaldaPhraseEmpty

	thumb_func_start sub_80D259C
sub_80D259C: @ 80D259C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_02039D84
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 4
	bl Alloc
	str r0, [r6]
	ldr r5, =gUnknown_02039D88
	movs r1, 0
	cmp r0, 0
	beq _080D25BA
	adds r1, r4, 0
_080D25BA:
	strh r1, [r5]
	movs r2, 0
	cmp r2, r1
	bcs _080D25E2
	movs r3, 0
	adds r4, r5, 0
_080D25C6:
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 4
	adds r1, r0
	str r3, [r1, 0x18]
	adds r1, 0x2C
	strb r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r4]
	cmp r2, r0
	bcc _080D25C6
_080D25E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D259C

	thumb_func_start sub_80D25F0
sub_80D25F0: @ 80D25F0
	push {lr}
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D25F0

	thumb_func_start sub_80D2604
sub_80D2604: @ 80D2604
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	bge _080D2634
	movs r5, 0
_080D2612:
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	adds r0, r5, r0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D2628
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80D2918
_080D2628:
	adds r5, 0x30
	adds r4, 0x1
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	blt _080D2612
_080D2634:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2604

	thumb_func_start sub_80D2644
sub_80D2644: @ 80D2644
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r2, 0
	ldr r2, [sp, 0x24]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r3, 16
	lsrs r3, 16
	mov r10, r3
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080D272C
	ldr r0, =gUnknown_02039D84
	mov r9, r0
	ldr r0, [r0]
	lsls r1, r6, 1
	mov r8, r1
	adds r5, r1, r6
	lsls r5, 4
	adds r0, r5, r0
	movs r1, 0
	str r1, [r0, 0x18]
	str r4, [r0, 0x1C]
	adds r0, 0x2B
	strb r7, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, r5, r0
	mov r3, r10
	strh r3, [r0, 0x24]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x26]
	adds r0, r7, 0
	movs r1, 0x3
	bl GetBgAttribute
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	movs r1, 0x9
	bl GetBgAttribute
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	ldr r1, [r2]
	adds r5, r1
	ldr r2, =gSpriteTemplate_857BC88
	lsls r4, 2
	lsls r1, r0, 4
	adds r4, r1
	adds r4, r2
	ldrh r1, [r4]
	strh r1, [r5, 0x20]
	ldrh r1, [r4, 0x2]
	strh r1, [r5, 0x22]
	mov r2, r8
	cmp r0, 0
	beq _080D26E8
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x1
	b _080D26EE
	.pool
_080D26E8:
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x2
_080D26EE:
	strb r0, [r1]
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	adds r2, r6
	lsls r2, 4
	adds r1, r2, r1
	adds r0, r1, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	mov r3, r10
	muls r3, r0
	movs r0, 0
	strh r3, [r1, 0x28]
	mov r3, r10
	strh r3, [r1, 0x10]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1, 0x12]
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, [r4]
	adds r2, r0
	adds r2, 0x2C
	movs r0, 0x1
	strb r0, [r2]
_080D272C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2644

	thumb_func_start sub_80D2740
sub_80D2740: @ 80D2740
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2764
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r0, r1
	str r3, [r0, 0x18]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D2764:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2740

	thumb_func_start sub_80D2770
sub_80D2770: @ 80D2770
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r3, r0
	bcs _080D279C
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 4
	adds r0, r1
	strh r4, [r0, 0x14]
	strh r2, [r0, 0x16]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D279C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2770

	thumb_func_start sub_80D27AC
sub_80D27AC: @ 80D27AC
	push {r4-r6,lr}
	ldr r4, [sp, 0x10]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcs _080D27E6
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 4
	adds r0, r1
	strh r6, [r0, 0xC]
	strh r2, [r0, 0xE]
	strh r3, [r0, 0x10]
	strh r4, [r0, 0x12]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D27E6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27AC

	thumb_func_start sub_80D27F4
sub_80D27F4: @ 80D27F4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080D280C
	b _080D290E
_080D280C:
	ldr r4, =gUnknown_02039D84
	lsls r2, r5, 1
	cmp r1, 0x5
	bls _080D2816
	b _080D2900
_080D2816:
	lsls r0, r1, 2
	ldr r1, =_080D282C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D282C:
	.4byte _080D2844
	.4byte _080D2864
	.4byte _080D2888
	.4byte _080D28A8
	.4byte _080D28CC
	.4byte _080D28E8
_080D2844:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x14]
	adds r0, r2
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x10]
	subs r0, r2
	b _080D287E
	.pool
_080D2864:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x10]
	adds r0, r2
_080D287E:
	strh r0, [r1, 0x10]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D2888:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x16]
	adds r0, r2
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x12]
	subs r0, r2
	b _080D28C2
	.pool
_080D28A8:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xE]
	subs r0, r2
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x12]
	adds r0, r2
_080D28C2:
	strh r0, [r1, 0x12]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D28CC:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x14]
	adds r0, r4
	strh r0, [r1, 0x14]
	b _080D28FE
	.pool
_080D28E8:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x16]
	adds r0, r4
	strh r0, [r1, 0x16]
_080D28FE:
	adds r4, r3, 0
_080D2900:
	ldr r0, [r4]
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0x1
	strb r0, [r1]
_080D290E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27F4

	thumb_func_start sub_80D2918
sub_80D2918: @ 80D2918
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r6, r2, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2952
	ldr r5, =gUnknown_02039D84
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4, r0
	ldr r0, [r0, 0x18]
	cmp r0, 0
	beq _080D2940
	adds r0, r2, 0
	bl sub_80D2960
_080D2940:
	adds r0, r6, 0
	bl sub_80D29F8
	ldr r1, [r5]
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080D2952:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2918

	thumb_func_start sub_80D2960
sub_80D2960: @ 80D2960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x20]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x18]
	adds r1, r2
	movs r6, 0x8
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x6]
	cmp r6, r0
	bge _080D29E4
	mov r10, r4
_080D29AA:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x8]
	ldrb r3, [r1, 0xA]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x4]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x6]
	cmp r6, r4
	blt _080D29AA
_080D29E4:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2960

	thumb_func_start sub_80D29F8
sub_80D29F8: @ 80D29F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x24]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xE
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x1C]
	adds r1, r2
	movs r6, 0xC
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x12]
	cmp r6, r0
	bge _080D2A7C
	mov r10, r4
_080D2A42:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x14]
	ldrb r3, [r1, 0x16]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x10]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x12]
	cmp r6, r4
	blt _080D2A42
_080D2A7C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D29F8

	thumb_func_start sub_80D2A90
sub_80D2A90: @ 80D2A90
	ldr r3, =gUnknown_02039D8C
	str r0, [r3]
	str r1, [r0]
	movs r1, 0
	strb r2, [r0, 0x5]
	strb r1, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_80D2A90

	thumb_func_start sub_80D2AA4
sub_80D2AA4: @ 80D2AA4
	push {r4,r5,lr}
	ldr r2, =gUnknown_02039D8C
	ldr r1, [r2]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080D2AE2
	movs r4, 0
	ldrb r1, [r1, 0x4]
	cmp r4, r1
	bcs _080D2ADA
	adds r5, r2, 0
_080D2ABA:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r0, r1
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bcc _080D2ABA
_080D2ADA:
	ldr r0, =gUnknown_02039D8C
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x4]
_080D2AE2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2AA4

	thumb_func_start sub_80D2AEC
sub_80D2AEC: @ 80D2AEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	mov r10, r3
	ldr r0, [sp, 0x24]
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2B74
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r4, 1
	strh r0, [r1, 0x8]
	ldr r2, [sp]
	lsls r0, r2, 5
	add r0, r12
	lsls r0, 1
	add r0, r9
	str r0, [r1, 0x4]
	adds r0, r3, 0
	muls r0, r6
	add r0, r8
	lsls r0, 1
	add r0, r10
	str r0, [r1]
	strh r5, [r1, 0xC]
	strh r6, [r1, 0xA]
	ldr r0, =sub_80D2B88
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2B76
	.pool
_080D2B74:
	movs r0, 0
_080D2B76:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2AEC

	thumb_func_start sub_80D2B88
sub_80D2B88: @ 80D2B88
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	b _080D2BB2
_080D2B90:
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldrh r2, [r4, 0x8]
	lsrs r2, 1
	bl CpuSet
	ldr r0, [r4, 0x4]
	adds r0, 0x40
	str r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	lsls r1, 1
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080D2BB2:
	ldrh r0, [r4, 0xC]
	cmp r5, r0
	bcc _080D2B90
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80D2B88

	thumb_func_start sub_80D2BC0
sub_80D2BC0: @ 80D2BC0
	push {r4-r7,lr}
	mov r12, r0
	ldr r0, [sp, 0x14]
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2C14
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r3, 1
	strh r0, [r1, 0x8]
	lsls r0, r4, 5
	adds r0, r6
	lsls r0, 1
	add r0, r12
	str r0, [r1, 0x4]
	strh r5, [r1, 0xC]
	ldr r0, =sub_80D2C1C
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2C16
	.pool
_080D2C14:
	movs r0, 0
_080D2C16:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2BC0

	thumb_func_start sub_80D2C1C
sub_80D2C1C: @ 80D2C1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	movs r0, 0
	ldrh r1, [r6, 0xC]
	cmp r0, r1
	bcs _080D2CAA
	movs r7, 0x80
	lsls r7, 5
	mov r5, sp
	ldr r2, =0x040000d4
	mov r8, r2
	movs r1, 0x81
	lsls r1, 24
	mov r10, r1
_080D2C42:
	ldr r2, [r6, 0x4]
	ldrh r3, [r6, 0x8]
	mov r12, r2
	adds r0, 0x1
	mov r9, r0
	cmp r3, r7
	bhi _080D2C6C
	movs r0, 0
	strh r0, [r5]
	mov r2, sp
	mov r0, r8
	str r2, [r0]
	mov r1, r12
	str r1, [r0, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
	mov r1, r8
	b _080D2C94
	.pool
_080D2C6C:
	movs r4, 0
	strh r4, [r5]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x81000800
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r7
	subs r3, r7
	cmp r3, r7
	bhi _080D2C6C
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
_080D2C94:
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, r12
	adds r0, 0x40
	str r0, [r6, 0x4]
	mov r1, r9
	lsls r0, r1, 16
	lsrs r0, 16
	ldrh r2, [r6, 0xC]
	cmp r0, r2
	bcc _080D2C42
_080D2CAA:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2C1C

	.align 2, 0 @ Don't pad with nop.
