	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80D47D4
sub_80D47D4: @ 80D47D4
	push {lr}
	bl sub_80A0934
	bl AddMapNamePopUpWindowTask
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_80D47D4

	thumb_func_start AddMapNamePopUpWindowTask
AddMapNamePopUpWindowTask: @ 80D47E4
	push {r4,lr}
	movs r0, 0x80
	lsls r0, 7
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080D486C
	ldr r4, =Task_MapNamePopUpWindow
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080D4844
	adds r0, r4, 0
	movs r1, 0x5A
	bl CreateTask
	ldr r4, =gUnknown_02039DD4
	strb r0, [r4]
	movs r0, 0x12
	movs r1, 0x28
	bl SetGpuReg
	ldr r2, =gTasks
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x6
	strh r1, [r0, 0x8]
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x28
	strh r1, [r0, 0xC]
	b _080D486C
	.pool
_080D4844:
	ldr r3, =gTasks
	ldr r2, =gUnknown_02039DD4
	ldrb r0, [r2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	movs r4, 0x8
	ldrsh r0, [r1, r4]
	cmp r0, 0x2
	beq _080D485E
	movs r0, 0x2
	strh r0, [r1, 0x8]
_080D485E:
	ldrb r0, [r2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	movs r0, 0x1
	strh r0, [r1, 0xE]
_080D486C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddMapNamePopUpWindowTask

	thumb_func_start Task_MapNamePopUpWindow
Task_MapNamePopUpWindow: @ 80D487C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	adds r3, r0, 0
	cmp r1, 0x6
	bhi _080D4966
	lsls r0, r1, 2
	ldr r1, =_080D48A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D48A8:
	.4byte _080D48DE
	.4byte _080D4908
	.4byte _080D4920
	.4byte _080D4966
	.4byte _080D494C
	.4byte _080D4960
	.4byte _080D48C4
_080D48C4:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _080D4966
	strh r1, [r4, 0x8]
	strh r1, [r4, 0x10]
	bl ShowMapNamePopUpWindow
	b _080D4966
_080D48DE:
	ldrh r0, [r4, 0xC]
	subs r0, 0x2
	movs r2, 0
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bgt _080D4966
	strh r2, [r4, 0xC]
	movs r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_02039DD4
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r3
	strh r2, [r0, 0xA]
	b _080D4966
	.pool
_080D4908:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x78
	ble _080D4966
	movs r0, 0
	strh r0, [r4, 0xA]
	movs r0, 0x2
	strh r0, [r4, 0x8]
	b _080D4966
_080D4920:
	ldrh r0, [r4, 0xC]
	adds r0, 0x2
	movs r1, 0
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _080D4966
	movs r0, 0x28
	strh r0, [r4, 0xC]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080D4946
	movs r0, 0x6
	strh r0, [r4, 0x8]
	strh r1, [r4, 0x10]
	strh r1, [r4, 0xE]
	b _080D4966
_080D4946:
	movs r0, 0x4
	strh r0, [r4, 0x8]
	b _080D496E
_080D494C:
	bl GetMapNamePopUpWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_819746C
	movs r0, 0x5
	strh r0, [r4, 0x8]
	b _080D4966
_080D4960:
	bl HideMapNamePopUpWindow
	b _080D496E
_080D4966:
	ldrh r1, [r4, 0xC]
	movs r0, 0x12
	bl SetGpuReg
_080D496E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end Task_MapNamePopUpWindow

	thumb_func_start HideMapNamePopUpWindow
HideMapNamePopUpWindow: @ 80D4974
	push {lr}
	ldr r0, =Task_MapNamePopUpWindow
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _080D49A4
	bl GetMapNamePopUpWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_819746C
	bl RemoveMapNamePopUpWindow
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg_ForcedBlank
	ldr r0, =gUnknown_02039DD4
	ldrb r0, [r0]
	bl DestroyTask
_080D49A4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end HideMapNamePopUpWindow

	thumb_func_start ShowMapNamePopUpWindow
ShowMapNamePopUpWindow: @ 80D49B0
	push {r4,r5,lr}
	sub sp, 0x24
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080D4A08
	ldr r0, =gMapHeader
	ldrh r1, [r0, 0x12]
	movs r0, 0xBD
	lsls r0, 1
	cmp r1, r0
	bne _080D49DC
	mov r4, sp
	adds r4, 0xF
	ldr r0, =gUnknown_0857F544
	ldr r1, [r0, 0x1C]
	b _080D49F2
	.pool
_080D49DC:
	mov r4, sp
	adds r4, 0xF
	ldr r1, =gUnknown_0857F544
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000cb2
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
_080D49F2:
	adds r0, r4, 0
	bl StringCopy
	b _080D4A18
	.pool
_080D4A08:
	mov r4, sp
	adds r4, 0xF
	ldr r0, =gMapHeader
	ldrb r1, [r0, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl GetMapName
_080D4A18:
	bl AddMapNamePopUpWindow
	bl LoadMapNamePopUpWindowBg
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x50
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	add r1, sp, 0xC
	movs r5, 0
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	adds r0, r1, 0
	strb r5, [r0, 0x2]
	bl GetMapNamePopUpWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x7
	add r2, sp, 0xC
	adds r3, r4, 0
	bl PrintTextOnWindow
	bl GetMapNamePopUpWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x24
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowMapNamePopUpWindow

	thumb_func_start sub_80D4A78
sub_80D4A78: @ 80D4A78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r4, [sp, 0x3C]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x10]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x14]
	movs r5, 0
	lsls r0, r1, 24
	asrs r1, r0, 24
	lsrs r3, r2, 24
	str r3, [sp, 0xC]
	movs r6, 0xFF
	lsls r6, 24
	adds r6, r2
	mov r8, r6
	str r0, [sp, 0x18]
	subs r4, r1, 0x1
_080D4AB4:
	ldr r0, =0x0000021d
	adds r1, r5, r0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	movs r6, 0xE
	mov r9, r6
	str r6, [sp, 0x8]
	adds r0, r7, 0
	mov r6, r8
	lsrs r3, r6, 24
	bl FillBgTilemapBufferRect
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0xB
	ble _080D4AB4
	ldr r1, =0x00000229
	movs r0, 0x1
	negs r0, r0
	add r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	ldr r3, [sp, 0xC]
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000022a
	ldr r6, [sp, 0x10]
	add r6, r10
	lsls r6, 24
	lsrs r6, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	adds r0, r7, 0
	adds r2, r6, 0
	ldr r3, [sp, 0xC]
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000022b
	ldr r4, [sp, 0xC]
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	movs r1, 0x8B
	lsls r1, 2
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r7, 0
	adds r2, r6, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000022d
	ldr r4, [sp, 0xC]
	adds r4, 0x2
	lsls r4, 24
	lsrs r4, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	adds r0, r7, 0
	mov r2, r8
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000022e
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r7, 0
	adds r2, r6, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	movs r5, 0
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x14]
	adds r0, r1, r2
	lsls r4, r0, 24
	movs r6, 0x1
_080D4B8A:
	ldr r3, =0x0000022f
	adds r1, r5, r3
	lsls r1, 16
	lsrs r1, 16
	subs r0, r5, 0x1
	ldr r3, [sp, 0x18]
	asrs r2, r3, 24
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xE
	str r0, [sp, 0x8]
	adds r0, r7, 0
	lsrs r3, r4, 24
	bl FillBgTilemapBufferRect
	adds r5, 0x1
	cmp r5, 0xB
	ble _080D4B8A
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D4A78

	thumb_func_start LoadMapNamePopUpWindowBg
LoadMapNamePopUpWindowBg: @ 80D4BE0
	push {r4,r5,lr}
	sub sp, 0x8
	bl GetMapNamePopUpWindowId
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gMapHeader
	ldrb r1, [r0, 0x14]
	cmp r1, 0x57
	bls _080D4C0A
	cmp r1, 0xC4
	bls _080D4C08
	adds r0, r1, 0
	subs r0, 0x6D
	lsls r0, 16
	lsrs r1, r0, 16
	b _080D4C0A
	.pool
_080D4C08:
	movs r1, 0
_080D4C0A:
	ldr r0, =gUnknown_0857F464
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 4
	subs r1, r4
	lsls r1, 6
	ldr r2, =gUnknown_0857DD04
	adds r1, r2
	movs r2, 0x80
	lsls r2, 3
	ldr r3, =0x0000021d
	bl LoadBgTiles
	ldr r1, =sub_80D4A78
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	bl PutWindowTilemap
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x16]
	cmp r0, 0xE
	bne _080D4C6C
	ldr r0, =gUnknown_0857F444
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	b _080D4C7A
	.pool
_080D4C6C:
	lsls r0, r4, 5
	ldr r1, =gUnknown_0857F384
	adds r0, r1
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
_080D4C7A:
	lsls r1, r4, 4
	subs r1, r4
	lsls r1, 6
	ldr r0, =gUnknown_0857C684
	adds r1, r0
	movs r0, 0x50
	str r0, [sp]
	movs r0, 0x18
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapToWindow
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadMapNamePopUpWindowBg

	.align 2, 0 @ Don't pad with nop.
