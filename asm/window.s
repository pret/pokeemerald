	thumb_func_start nullsub_8
nullsub_8: ; 80031BC
	bx lr
	thumb_func_end nullsub_8

	thumb_func_start InitWindows
; BOOL16 InitWindows(struct WindowTemplate *templates)
InitWindows: ; 80031C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	movs r0, 0
	mov r8, r0
	ldr r4, =0x03002f70
@080031D4:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl GetBgTilemap
	cmp r0, 0
	beq @080031E4
	ldr r0, =nullsub_8
@080031E4:
	str r0, [r4]
	adds r4, 0x4
	movs r2, 0x1
	add r8, r2
	mov r0, r8
	cmp r0, 0x3
	ble @080031D4
	ldr r0, =gDummyWindowTemplate
	ldr r2, [r0]
	ldr r3, [r0, 0x4]
	ldr r1, =0x02020004
	movs r0, 0
	movs r4, 0x1F
	mov r8, r4
@08003200:
	str r2, [r1]
	str r3, [r1, 0x4]
	str r0, [r1, 0x8]
	adds r1, 0xC
	movs r4, 0x1
	negs r4, r4
	add r8, r4
	mov r4, r8
	cmp r4, 0
	bge @08003200
	movs r0, 0
	mov r8, r0
	movs r1, 0
	str r1, [sp]
	ldrb r7, [r5]
	cmp r7, 0xFF
	bne @08003224
	b @0800335C
@08003224:
	adds r6, r5, 0
	movs r2, 0
	str r2, [sp, 0x4]
@0800322A:
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @08003268
	ldrb r1, [r6, 0x3]
	ldrb r0, [r6, 0x4]
	adds r2, r1, 0
	muls r2, r0
	adds r0, r7, 0
	movs r1, 0
	movs r3, 0
	bl DummiedOutFireRedLeafGreenTileAllocFunc
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	ldr r4, [sp]
	cmp r4, r0
	bne @08003268
@08003250:
	movs r0, 0
	b @08003364
	.pool
@08003268:
	ldr r0, =0x03002f70
	mov r9, r0
	lsls r0, r7, 2
	mov r2, r9
	adds r1, r0, r2
	ldr r1, [r1]
	mov r10, r0
	cmp r1, 0
	bne @080032CA
	adds r0, r7, 0
	movs r1, 0x8
	bl GetBgAttribute
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq @080032CA
	adds r0, r5, 0
	bl AllocZeroed
	adds r4, r0, 0
	cmp r4, 0
	bne @080032A8
	bl FreeAllWindowBuffers
	b @08003250
	.pool
@080032A8:
	movs r1, 0
	mov r3, r9
	cmp r1, r5
	bge @080032BC
	movs r2, 0
@080032B2:
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, r5
	blt @080032B2
@080032BC:
	mov r1, r10
	adds r0, r1, r3
	str r4, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl SetBgTilemap
@080032CA:
	ldrb r1, [r6, 0x3]
	ldrb r0, [r6, 0x4]
	muls r0, r1
	lsls r0, 21
	lsrs r0, 16
	bl AllocZeroed
	adds r4, r0, 0
	cmp r4, 0
	bne @0800330C
	adds r0, r7, 0
	bl GetNumActiveWindowsOnBg
	lsls r0, 24
	cmp r0, 0
	bne @08003250
	ldr r0, =0x03002f70
	mov r2, r10
	adds r5, r2, r0
	ldr r1, [r5]
	ldr r0, =nullsub_8
	cmp r1, r0
	beq @08003250
	adds r0, r1, 0
	bl Free
	str r4, [r5]
	b @08003250
	.pool
@0800330C:
	ldr r1, =0x02020004
	adds r0, r1, 0
	adds r0, 0x8
	ldr r2, [sp, 0x4]
	adds r0, r2, r0
	str r4, [r0]
	adds r2, r1
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @08003342
	mov r4, sp
	ldrh r4, [r4]
	strh r4, [r2, 0x6]
	ldrb r0, [r6, 0x3]
	ldrb r1, [r6, 0x4]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r7, 0
	ldr r1, [sp]
	movs r3, 0x1
	bl DummiedOutFireRedLeafGreenTileAllocFunc
@08003342:
	adds r6, 0x8
	ldr r0, [sp, 0x4]
	adds r0, 0xC
	str r0, [sp, 0x4]
	movs r1, 0x1
	add r8, r1
	ldrb r7, [r6]
	cmp r7, 0xFF
	beq @0800335C
	mov r2, r8
	cmp r2, 0x1F
	bgt @0800335C
	b @0800322A
@0800335C:
	ldr r1, =0x03002f60
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
@08003364:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end InitWindows

	thumb_func_start AddWindow
; u8 AddWindow(struct WindowTemplate *template)
AddWindow: ; 8003380
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	movs r6, 0
	ldr r1, =0x02020004
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq @080033B0
@08003398:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1F
	bhi @080033B0
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne @08003398
@080033B0:
	cmp r6, 0x20
	beq @0800346A
	mov r0, r8
	ldrb r7, [r0]
	movs r1, 0
	mov r9, r1
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @080033E2
	mov r2, r8
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	adds r2, r1, 0
	muls r2, r0
	adds r0, r7, 0
	movs r1, 0
	movs r3, 0
	bl DummiedOutFireRedLeafGreenTileAllocFunc
	mov r9, r0
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq @0800346A
@080033E2:
	ldr r3, =0x03002f70
	mov r10, r3
	lsls r0, r7, 2
	adds r1, r0, r3
	ldr r1, [r1]
	str r0, [sp]
	cmp r1, 0
	bne @08003432
	adds r0, r7, 0
	movs r1, 0x8
	bl GetBgAttribute
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq @08003432
	adds r0, r5, 0
	bl AllocZeroed
	adds r4, r0, 0
	cmp r4, 0
	beq @0800346A
	movs r1, 0
	mov r3, r10
	cmp r1, r5
	bge @08003424
	movs r2, 0
@0800341A:
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, r5
	blt @0800341A
@08003424:
	ldr r1, [sp]
	adds r0, r1, r3
	str r4, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl SetBgTilemap
@08003432:
	mov r2, r8
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	muls r0, r1
	lsls r0, 21
	lsrs r0, 16
	bl AllocZeroed
	adds r4, r0, 0
	cmp r4, 0
	bne @08003484
	adds r0, r7, 0
	bl GetNumActiveWindowsOnBg
	lsls r0, 24
	cmp r0, 0
	bne @0800346A
	ldr r0, =0x03002f70
	ldr r3, [sp]
	adds r5, r3, r0
	ldr r1, [r5]
	ldr r0, =nullsub_8
	cmp r1, r0
	beq @0800346A
	adds r0, r1, 0
	bl Free
	str r4, [r5]
@0800346A:
	movs r0, 0xFF
	b @080034C0
	.pool
@08003484:
	ldr r2, =0x02020004
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	str r4, [r0]
	adds r2, r1, r2
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @080034BE
	mov r0, r9
	strh r0, [r2, 0x6]
	ldrb r0, [r2, 0x3]
	ldrb r1, [r2, 0x4]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r7, 0
	mov r1, r9
	movs r3, 0x1
	bl DummiedOutFireRedLeafGreenTileAllocFunc
@080034BE:
	adds r0, r6, 0
@080034C0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddWindow

	thumb_func_start AddWindowWithoutTileMap
; int AddWindowWithoutTileMap(struct WindowTemplate *template)
AddWindowWithoutTileMap: ; 80034D8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r1, =0x02020004
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq @080034FE
@080034E6:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1F
	bhi @080034FE
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne @080034E6
@080034FE:
	cmp r4, 0x20
	beq @08003528
	ldrb r6, [r5]
	movs r3, 0
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @08003534
	ldrb r1, [r5, 0x3]
	ldrb r0, [r5, 0x4]
	adds r2, r1, 0
	muls r2, r0
	adds r0, r6, 0
	movs r1, 0
	bl DummiedOutFireRedLeafGreenTileAllocFunc
	adds r3, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	bne @08003534
@08003528:
	movs r0, 0xFF
	b @08003564
	.pool
@08003534:
	ldr r1, =0x02020004
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, r0, r1
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @08003562
	strh r3, [r2, 0x6]
	ldrb r0, [r2, 0x3]
	ldrb r1, [r2, 0x4]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r6, 0
	adds r1, r3, 0
	movs r3, 0x1
	bl DummiedOutFireRedLeafGreenTileAllocFunc
@08003562:
	adds r0, r4, 0
@08003564:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddWindowWithoutTileMap

	thumb_func_start RemoveWindow
; void RemoveWindow(u8 windowId)
RemoveWindow: ; 8003574
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =0x02020004
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r4, r0, r1
	ldrb r3, [r4]
	adds r7, r3, 0
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @080035A0
	ldrh r1, [r4, 0x6]
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x4]
	muls r2, r0
	adds r0, r3, 0
	movs r3, 0x2
	bl DummiedOutFireRedLeafGreenTileAllocFunc
@080035A0:
	ldr r0, =gDummyWindowTemplate
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r4]
	str r1, [r4, 0x4]
	adds r0, r7, 0
	bl GetNumActiveWindowsOnBg
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne @080035CE
	ldr r0, =0x03002f70
	lsls r1, r7, 2
	adds r4, r1, r0
	ldr r1, [r4]
	ldr r0, =nullsub_8
	cmp r1, r0
	beq @080035CE
	adds r0, r1, 0
	bl Free
	str r5, [r4]
@080035CE:
	ldr r1, =0x02020004
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r1, 0x8
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq @080035E8
	bl Free
	movs r0, 0
	str r0, [r4]
@080035E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveWindow

	thumb_func_start FreeAllWindowBuffers
; void FreeAllWindowBuffers()
FreeAllWindowBuffers: ; 8003604
	push {r4-r6,lr}
	ldr r4, =0x03002f70
	movs r5, 0x3
@0800360A:
	ldr r1, [r4]
	cmp r1, 0
	beq @08003620
	ldr r0, =nullsub_8
	cmp r1, r0
	beq @08003620
	adds r0, r1, 0
	bl Free
	movs r0, 0
	str r0, [r4]
@08003620:
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge @0800360A
	ldr r0, =0x02020004
	adds r4, r0, 0
	adds r4, 0x8
	movs r6, 0
	movs r5, 0x1F
@08003632:
	ldr r0, [r4]
	cmp r0, 0
	beq @0800363E
	bl Free
	str r6, [r4]
@0800363E:
	adds r4, 0xC
	subs r5, 0x1
	cmp r5, 0
	bge @08003632
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeAllWindowBuffers

	thumb_func_start CopyWindowToVram
; void CopyWindowToVram(u8 windowId, u8 mode)
CopyWindowToVram: ; 8003658
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	adds r5, r3, 0
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	mov r0, sp
	adds r1, r2
	ldm r1!, {r2,r4,r6}
	stm r0!, {r2,r4,r6}
	mov r0, sp
	ldrb r1, [r0, 0x3]
	ldrb r0, [r0, 0x4]
	muls r0, r1
	lsls r0, 21
	lsrs r4, r0, 16
	cmp r3, 0x2
	beq @080036A4
	cmp r3, 0x2
	bgt @08003694
	cmp r3, 0x1
	beq @0800369A
	b @080036CE
	.pool
@08003694:
	cmp r5, 0x3
	beq @080036B6
	b @080036CE
@0800369A:
	mov r0, sp
	ldrb r0, [r0]
	bl CopyBgTilemapBufferToVram
	b @080036CE
@080036A4:
	mov r0, sp
	ldrb r0, [r0]
	ldr r1, [sp, 0x8]
	mov r2, sp
	ldrh r3, [r2, 0x6]
	adds r2, r4, 0
	bl LoadBgTiles
	b @080036CE
@080036B6:
	mov r0, sp
	ldrb r0, [r0]
	ldr r1, [sp, 0x8]
	mov r2, sp
	ldrh r3, [r2, 0x6]
	adds r2, r4, 0
	bl LoadBgTiles
	mov r0, sp
	ldrb r0, [r0]
	bl CopyBgTilemapBufferToVram
@080036CE:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end CopyWindowToVram

	thumb_func_start CopyWindowRectToVram
; void CopyWindowRectToVram(int rbox_id, int mode, int x, int y, int w, int h)
CopyWindowRectToVram: ; 80036D8
	push {r4-r7,lr}
	sub sp, 0xC
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r12, r3
	ldr r3, [sp, 0x24]
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq @08003782
	cmp r3, 0
	beq @08003782
	ldr r2, =0x02020004
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	mov r1, sp
	adds r0, r2
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	subs r2, r3, 0x1
	mov r0, sp
	ldrb r1, [r0, 0x3]
	adds r3, r2, 0
	muls r3, r1
	subs r0, r1, r4
	adds r3, r0
	ldr r2, [sp, 0x20]
	adds r0, r4, r2
	subs r0, r1, r0
	subs r3, r0
	lsls r3, 5
	mov r0, r12
	muls r0, r1
	adds r4, r0, r4
	cmp r5, 0x2
	beq @08003740
	cmp r5, 0x2
	bhi @08003730
	cmp r5, 0x1
	beq @08003736
	b @08003782
	.pool
@08003730:
	cmp r5, 0x3
	beq @0800375E
	b @08003782
@08003736:
	mov r0, sp
	ldrb r0, [r0]
	bl CopyBgTilemapBufferToVram
	b @08003782
@08003740:
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r4, 5
	ldr r1, [sp, 0x8]
	adds r1, r2
	lsls r2, r3, 16
	lsrs r2, 16
	mov r3, sp
	ldrh r3, [r3, 0x6]
	adds r3, r4
	lsls r3, 16
	lsrs r3, 16
	bl LoadBgTiles
	b @08003782
@0800375E:
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r4, 5
	ldr r1, [sp, 0x8]
	adds r1, r2
	lsls r2, r3, 16
	lsrs r2, 16
	mov r3, sp
	ldrh r3, [r3, 0x6]
	adds r3, r4
	lsls r3, 16
	lsrs r3, 16
	bl LoadBgTiles
	mov r0, sp
	ldrb r0, [r0]
	bl CopyBgTilemapBufferToVram
@08003782:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CopyWindowRectToVram

	thumb_func_start PutWindowTilemap
; void PutWindowTilemap(u8 windowId)
PutWindowTilemap: ; 800378C
	push {r4,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	add r0, sp, 0x10
	adds r1, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	add r0, sp, 0x10
	ldrb r0, [r0]
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	add r0, sp, 0x10
	ldrh r0, [r0, 0x6]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	add r0, sp, 0x10
	ldrb r0, [r0]
	add r2, sp, 0x10
	ldrb r2, [r2, 0x1]
	add r3, sp, 0x10
	ldrb r3, [r3, 0x2]
	add r4, sp, 0x10
	ldrb r4, [r4, 0x3]
	str r4, [sp]
	add r4, sp, 0x10
	ldrb r4, [r4, 0x4]
	str r4, [sp, 0x4]
	add r4, sp, 0x10
	ldrb r4, [r4, 0x5]
	str r4, [sp, 0x8]
	movs r4, 0x1
	str r4, [sp, 0xC]
	bl WriteSequenceToBgTilemapBuffer
	add sp, 0x1C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PutWindowTilemap

	thumb_func_start PutWindowRectTilemapOverridePalette
; void PutWindowRectTilemapOverridePalette(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 palette)
PutWindowRectTilemapOverridePalette: ; 80037EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r4, [sp, 0x44]
	ldr r5, [sp, 0x48]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x1C]
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	lsls r5, 24
	lsrs r5, 24
	str r5, [sp, 0x20]
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	add r0, sp, 0x10
	adds r1, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	add r0, sp, 0x10
	ldrb r0, [r0]
	movs r1, 0xA
	bl GetBgAttribute
	add r2, sp, 0x10
	adds r1, r2, 0
	ldrb r1, [r1, 0x3]
	mov r3, r9
	muls r3, r1
	adds r1, r3, 0
	ldrh r2, [r2, 0x6]
	adds r1, r2
	add r1, r10
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	movs r5, 0
	cmp r5, r8
	bge @0800388E
	add r4, sp, 0x10
	movs r7, 0x1
@0800385A:
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	add r2, r10
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	add r3, r9
	adds r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r1, [sp, 0x1C]
	str r1, [sp]
	str r7, [sp, 0x4]
	ldr r1, [sp, 0x20]
	str r1, [sp, 0x8]
	str r7, [sp, 0xC]
	adds r1, r6, 0
	bl WriteSequenceToBgTilemapBuffer
	ldrb r0, [r4, 0x3]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r5, 0x1
	cmp r5, r8
	blt @0800385A
@0800388E:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PutWindowRectTilemapOverridePalette

	thumb_func_start ClearWindowTilemap
; void ClearWindowTilemap(u8 windowId)
ClearWindowTilemap: ; 80038A4
	push {r4,lr}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	add r0, sp, 0xC
	adds r1, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	add r0, sp, 0xC
	ldrb r0, [r0]
	ldr r1, =0x03002f60
	ldrb r1, [r1]
	add r2, sp, 0xC
	ldrb r2, [r2, 0x1]
	add r3, sp, 0xC
	ldrb r3, [r3, 0x2]
	add r4, sp, 0xC
	ldrb r4, [r4, 0x3]
	str r4, [sp]
	add r4, sp, 0xC
	ldrb r4, [r4, 0x4]
	str r4, [sp, 0x4]
	add r4, sp, 0xC
	ldrb r4, [r4, 0x5]
	str r4, [sp, 0x8]
	bl FillBgTilemapBufferRect
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearWindowTilemap

	thumb_func_start PutWindowRectTilemap
; void PutWindowRectTilemap(u8 windowId, u8 x, u8 y, u8 width, u8 height)
PutWindowRectTilemap: ; 80038F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x40]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x1C]
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	add r0, sp, 0x10
	adds r1, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	add r0, sp, 0x10
	ldrb r0, [r0]
	movs r1, 0xA
	bl GetBgAttribute
	add r2, sp, 0x10
	adds r1, r2, 0
	ldrb r1, [r1, 0x3]
	mov r3, r9
	muls r3, r1
	adds r1, r3, 0
	ldrh r2, [r2, 0x6]
	adds r1, r2
	add r1, r10
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	movs r5, 0
	cmp r5, r8
	bge @0800398E
	add r4, sp, 0x10
	movs r7, 0x1
@0800395A:
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	add r2, r10
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	add r3, r9
	adds r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r1, [sp, 0x1C]
	str r1, [sp]
	str r7, [sp, 0x4]
	ldrb r1, [r4, 0x5]
	str r1, [sp, 0x8]
	str r7, [sp, 0xC]
	adds r1, r6, 0
	bl WriteSequenceToBgTilemapBuffer
	ldrb r0, [r4, 0x3]
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r5, 0x1
	cmp r5, r8
	blt @0800395A
@0800398E:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PutWindowRectTilemap

	thumb_func_start BlitBitmapToWindow
; void BlitBitmapToWindow(u8 windowId, u8 *pixels, u16 x, u16 y, u16 width, u16 height)
BlitBitmapToWindow: ; 80039A4
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	str r4, [sp]
	str r5, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	str r4, [sp, 0x10]
	str r5, [sp, 0x14]
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end BlitBitmapToWindow

	thumb_func_start BlitBitmapRectToWindow
; void BlitBitmapRectToWindow(u8 rbox_id, u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight)
BlitBitmapRectToWindow: ; 80039DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r4, [sp, 0x44]
	ldr r5, [sp, 0x48]
	ldr r6, [sp, 0x4C]
	mov r8, r6
	ldr r6, [sp, 0x50]
	mov r9, r6
	ldr r6, [sp, 0x54]
	mov r10, r6
	ldr r6, [sp, 0x58]
	mov r12, r6
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	mov r6, r8
	lsls r6, 16
	lsrs r6, 16
	mov r8, r6
	mov r6, r9
	lsls r6, 16
	lsrs r6, 16
	mov r9, r6
	mov r6, r10
	lsls r6, 16
	lsrs r6, 16
	mov r10, r6
	mov r6, r12
	lsls r6, 16
	lsrs r6, 16
	mov r12, r6
	str r1, [sp, 0x14]
	ldr r7, =0xffff0000
	lsls r5, 16
	ldr r6, =0x0000ffff
	lsrs r4, 16
	orrs r4, r5
	str r4, [sp, 0x18]
	ldr r1, =0x02020004
	lsls r5, r0, 1
	adds r5, r0
	lsls r5, 2
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	adds r5, r1
	ldrb r0, [r5, 0x3]
	lsls r0, 3
	add r1, sp, 0x1C
	ldr r4, [r1, 0x4]
	ands r4, r7
	orrs r4, r0
	str r4, [r1, 0x4]
	ldrb r0, [r5, 0x4]
	lsls r0, 19
	ands r6, r4
	orrs r6, r0
	str r6, [r1, 0x4]
	mov r0, r8
	str r0, [sp]
	mov r6, r9
	str r6, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	mov r6, r12
	str r6, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	add r0, sp, 0x14
	bl BlitBitmapRect4Bit
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BlitBitmapRectToWindow

	thumb_func_start BlitBitmapRectToWindowWithColorKey
; void BlitBitmapRectToWindowWithColorKey(u8 rbox_id, u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight, u8 colorKey)
BlitBitmapRectToWindowWithColorKey: ; 8003A9C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	ldr r4, [sp, 0x48]
	ldr r5, [sp, 0x4C]
	ldr r6, [sp, 0x50]
	mov r8, r6
	ldr r7, [sp, 0x54]
	mov r9, r7
	ldr r6, [sp, 0x58]
	mov r10, r6
	ldr r7, [sp, 0x5C]
	mov r12, r7
	ldr r6, [sp, 0x60]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	mov r7, r8
	lsls r7, 16
	lsrs r7, 16
	mov r8, r7
	mov r7, r9
	lsls r7, 16
	lsrs r7, 16
	mov r9, r7
	mov r7, r10
	lsls r7, 16
	lsrs r7, 16
	mov r10, r7
	mov r7, r12
	lsls r7, 16
	lsrs r7, 16
	mov r12, r7
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x24]
	str r1, [sp, 0x14]
	lsls r5, 16
	ldr r6, =0x0000ffff
	lsrs r4, 16
	orrs r4, r5
	str r4, [sp, 0x18]
	ldr r1, =0x02020004
	lsls r5, r0, 1
	adds r5, r0
	lsls r5, 2
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	adds r5, r1
	ldrb r0, [r5, 0x3]
	lsls r0, 3
	add r1, sp, 0x1C
	ldr r4, [r1, 0x4]
	ldr r7, =0xffff0000
	ands r4, r7
	orrs r4, r0
	str r4, [r1, 0x4]
	ldrb r0, [r5, 0x4]
	lsls r0, 19
	ands r6, r4
	orrs r6, r0
	str r6, [r1, 0x4]
	mov r0, r8
	str r0, [sp]
	mov r6, r9
	str r6, [sp, 0x4]
	mov r7, r10
	str r7, [sp, 0x8]
	mov r0, r12
	str r0, [sp, 0xC]
	ldr r6, [sp, 0x24]
	str r6, [sp, 0x10]
	add r0, sp, 0x14
	bl BlitBitmapRect4Bit
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BlitBitmapRectToWindowWithColorKey

	thumb_func_start FillWindowPixelRect
; void FillWindowPixelRect(u8 windowId, u8 fillValue, u16 x, u16 y, u16 width, u16 height)
FillWindowPixelRect: ; 8003B64
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	mov r9, r3
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	mov r8, r4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r4, r9
	lsls r4, 16
	lsrs r4, 16
	mov r9, r4
	lsls r3, 16
	lsrs r3, 16
	mov r4, r8
	lsls r4, 16
	lsrs r4, 16
	mov r8, r4
	ldr r5, =0x02020004
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r4, r5
	ldrb r0, [r4, 0x3]
	lsls r0, 3
	ldr r6, =0xffff0000
	ldr r5, [sp, 0xC]
	ands r5, r6
	orrs r5, r0
	str r5, [sp, 0xC]
	ldrb r4, [r4, 0x4]
	lsls r4, 19
	ldr r0, =0x0000ffff
	ands r0, r5
	orrs r0, r4
	str r0, [sp, 0xC]
	mov r0, r8
	str r0, [sp]
	str r1, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r2, 0
	mov r2, r9
	bl FillBitmapRect4Bit
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillWindowPixelRect

	thumb_func_start CopyToWindowPixelBuffer
; void CopyToWindowPixelBuffer(u8 windowId, u8 *src, u32 size, u16 tileOffset)
CopyToWindowPixelBuffer: ; 8003BF0
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r5, r2, 16
	lsls r3, 16
	lsrs r2, r3, 16
	cmp r5, 0
	beq @08003C24
	ldr r1, =0x02020004
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	lsls r2, 5
	ldr r1, [r0]
	adds r1, r2
	lsrs r2, r5, 17
	adds r0, r6, 0
	bl CpuSet
	b @08003C3C
	.pool
@08003C24:
	ldr r1, =0x02020004
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	lsls r2, 5
	ldr r1, [r0]
	adds r1, r2
	adds r0, r6, 0
	bl LZ77UnCompWram
@08003C3C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyToWindowPixelBuffer

	thumb_func_start FillWindowPixelBuffer
; void FillWindowPixelBuffer(u8 rbox_id, u32 fillValue)
FillWindowPixelBuffer: ; 8003C48
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r5, =0x02020004
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r0, r4, r5
	ldrb r2, [r0, 0x3]
	ldrb r0, [r0, 0x4]
	muls r2, r0
	lsls r0, r1, 24
	lsls r3, r1, 16
	orrs r0, r3
	lsls r3, r1, 8
	orrs r0, r3
	orrs r0, r1
	str r0, [sp]
	adds r5, 0x8
	adds r4, r5
	ldr r1, [r4]
	lsls r2, 3
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	bl CpuFastSet
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillWindowPixelBuffer

	thumb_func_start ScrollWindow
; void ScrollWindow(u8 windowId, u8 direction, u8 distance, u8 fillValue)
ScrollWindow: ; 8003C94
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r4, r1, r2
	adds r2, 0x8
	adds r1, r2
	ldr r5, [r1]
	lsls r7, r3, 24
	lsls r0, r3, 16
	orrs r7, r0
	lsls r0, r3, 8
	orrs r7, r0
	orrs r7, r3
	ldr r1, [r4]
	ldr r2, [r4, 0x4]
	ldrb r3, [r4, 0x4]
	lsrs r0, r1, 24
	muls r0, r3
	lsls r6, r0, 5
	lsrs r1, 24
	mov r12, r1
	mov r0, r8
	cmp r0, 0x1
	bne @08003CE8
	b @08003E9E
@08003CE8:
	cmp r0, 0x1
	ble @08003CEE
	b @08004046
@08003CEE:
	cmp r0, 0
	beq @08003CF4
	b @08004046
@08003CF4:
	movs r4, 0
	cmp r4, r6
	blt @08003CFC
	b @08004046
@08003CFC:
	movs r1, 0x8
	negs r1, r1
	mov r9, r1
	movs r2, 0x7
	mov r8, r2
	mov r10, r5
@08003D08:
	ldr r3, [sp]
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r3, 0
	mov r2, r8
	ands r0, r2
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003D34
	adds r0, r5, r1
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1]
	b @08003D38
	.pool
@08003D34:
	mov r2, r10
	str r7, [r2]
@08003D38:
	adds r3, 0x1
	adds r2, r4, 0x4
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003D64
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003D68
@08003D64:
	adds r0, r5, r2
	str r7, [r0]
@08003D68:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x8
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003D96
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003D9A
@08003D96:
	adds r0, r5, r2
	str r7, [r0]
@08003D9A:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0xC
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003DC8
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003DCC
@08003DC8:
	adds r0, r5, r2
	str r7, [r0]
@08003DCC:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x10
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003DFA
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003DFE
@08003DFA:
	adds r0, r5, r2
	str r7, [r0]
@08003DFE:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x14
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003E2C
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003E30
@08003E2C:
	adds r0, r5, r2
	str r7, [r0]
@08003E30:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x18
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003E5E
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003E62
@08003E5E:
	adds r0, r5, r2
	str r7, [r0]
@08003E62:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x1C
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r1, 0
	mov r1, r8
	ands r3, r1
	orrs r0, r3
	lsls r0, 2
	adds r1, r4, r0
	cmp r1, r6
	bge @08003E8C
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003E90
@08003E8C:
	adds r0, r5, r2
	str r7, [r0]
@08003E90:
	movs r2, 0x20
	add r10, r2
	adds r4, 0x20
	cmp r4, r6
	bge @08003E9C
	b @08003D08
@08003E9C:
	b @08004046
@08003E9E:
	subs r0, r6, 0x4
	adds r5, r0
	movs r4, 0
	cmp r4, r6
	blt @08003EAA
	b @08004046
@08003EAA:
	movs r0, 0x8
	negs r0, r0
	mov r9, r0
	movs r1, 0x7
	mov r8, r1
	mov r10, r5
@08003EB6:
	ldr r3, [sp]
	adds r0, r3, 0
	mov r2, r9
	ands r0, r2
	mov r1, r12
	muls r1, r0
	adds r0, r3, 0
	mov r2, r8
	ands r0, r2
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003EDC
	subs r0, r5, r1
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1]
	b @08003EE0
@08003EDC:
	mov r2, r10
	str r7, [r2]
@08003EE0:
	adds r3, 0x1
	adds r2, r4, 0x4
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003F0C
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003F10
@08003F0C:
	subs r0, r5, r2
	str r7, [r0]
@08003F10:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x8
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003F3E
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003F42
@08003F3E:
	subs r0, r5, r2
	str r7, [r0]
@08003F42:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0xC
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003F70
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003F74
@08003F70:
	subs r0, r5, r2
	str r7, [r0]
@08003F74:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x10
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003FA2
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003FA6
@08003FA2:
	subs r0, r5, r2
	str r7, [r0]
@08003FA6:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x14
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08003FD4
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08003FD8
@08003FD4:
	subs r0, r5, r2
	str r7, [r0]
@08003FD8:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x18
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge @08004006
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @0800400A
@08004006:
	subs r0, r5, r2
	str r7, [r0]
@0800400A:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x1C
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r1, 0
	mov r1, r8
	ands r3, r1
	orrs r0, r3
	lsls r0, 2
	adds r1, r4, r0
	cmp r1, r6
	bge @08004034
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b @08004038
@08004034:
	subs r0, r5, r2
	str r7, [r0]
@08004038:
	movs r2, 0x20
	negs r2, r2
	add r10, r2
	adds r4, 0x20
	cmp r4, r6
	bge @08004046
	b @08003EB6
@08004046:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ScrollWindow

	thumb_func_start CallWindowFunction
; void CallWindowFunction(u8 windowId, void ( *func)(u8, u8, u8, u8, u8, u8))
CallWindowFunction: ; 8004058
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	mov r8, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r5, [r1]
	ldr r6, [r1, 0x4]
	ldrb r0, [r1]
	lsrs r1, r5, 8
	lsls r1, 24
	lsrs r1, 24
	lsrs r2, r5, 16
	lsls r2, 24
	lsrs r2, 24
	lsrs r3, r5, 24
	lsls r4, r6, 24
	lsrs r4, 24
	str r4, [sp]
	lsrs r4, r6, 8
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	bl _call_via_r8
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CallWindowFunction

	thumb_func_start SetWindowAttribute
; BOOL SetWindowAttribute(u8 windowId, u8 attributeId, u32 value)
SetWindowAttribute: ; 80040A8
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0x7
	bhi @08004142
	lsls r0, 2
	ldr r1, =@080040C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@080040C4:
	.4byte @08004142
	.4byte @080040E4
	.4byte @080040F8
	.4byte @08004142
	.4byte @08004142
	.4byte @0800410C
	.4byte @08004120
	.4byte @08004134
@080040E4:
	ldr r1, =0x02020004
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x1]
	movs r0, 0
	b @08004144
	.pool
@080040F8:
	ldr r1, =0x02020004
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x2]
	movs r0, 0
	b @08004144
	.pool
@0800410C:
	ldr r1, =0x02020004
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x5]
	movs r0, 0
	b @08004144
	.pool
@08004120:
	ldr r1, =0x02020004
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strh r2, [r0, 0x6]
	movs r0, 0
	b @08004144
	.pool
@08004134:
	ldr r1, =0x02020004
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	str r2, [r0]
@08004142:
	movs r0, 0x1
@08004144:
	pop {r1}
	bx r1
	.pool
	thumb_func_end SetWindowAttribute

	thumb_func_start GetWindowAttribute
; u32 GetWindowAttribute(u8 windowId, u8 attributeId)
GetWindowAttribute: ; 800414C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0x7
	bhi @08004228
	lsls r0, 2
	ldr r1, =@08004168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08004168:
	.4byte @08004188
	.4byte @0800419C
	.4byte @080041B0
	.4byte @080041C4
	.4byte @080041D8
	.4byte @080041EC
	.4byte @08004200
	.4byte @08004214
@08004188:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	b @0800422A
	.pool
@0800419C:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	b @0800422A
	.pool
@080041B0:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	b @0800422A
	.pool
@080041C4:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x3]
	b @0800422A
	.pool
@080041D8:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x4]
	b @0800422A
	.pool
@080041EC:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x5]
	b @0800422A
	.pool
@08004200:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	b @0800422A
	.pool
@08004214:
	ldr r0, =0x02020004
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r0, 0x8
	adds r1, r0
	ldr r0, [r1]
	b @0800422A
	.pool
@08004228:
	movs r0, 0
@0800422A:
	pop {r1}
	bx r1
	thumb_func_end GetWindowAttribute

	thumb_func_start GetNumActiveWindowsOnBg
; u8 GetNumActiveWindowsOnBg(u8 bgId)
GetNumActiveWindowsOnBg: ; 8004230
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r2, =0x02020004
	movs r1, 0x1F
@0800423C:
	ldrb r0, [r2]
	cmp r0, r4
	bne @08004248
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
@08004248:
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge @0800423C
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetNumActiveWindowsOnBg

	thumb_func_start nullsub_9
nullsub_9: ; 800425C
	bx lr
	thumb_func_end nullsub_9

	thumb_func_start AddWindow8Bit
; u16 AddWindow8Bit(struct WindowTemplate *template)
AddWindow8Bit: ; 8004260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	movs r6, 0
	ldr r1, =0x02020004
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq @0800428E
@08004276:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1F
	bhi @0800428E
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne @08004276
@0800428E:
	cmp r6, 0x20
	beq @08004322
	mov r0, r9
	ldrb r7, [r0]
	ldr r1, =0x03002f70
	mov r10, r1
	lsls r2, r7, 2
	mov r8, r2
	mov r0, r8
	add r0, r10
	ldr r0, [r0]
	cmp r0, 0
	bne @080042EA
	adds r0, r7, 0
	movs r1, 0x8
	bl GetBgAttribute
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq @080042EA
	adds r0, r5, 0
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	beq @08004322
	movs r1, 0
	mov r12, r10
	mov r3, r8
	cmp r1, r5
	bge @080042DC
	movs r2, 0
@080042D2:
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, r5
	blt @080042D2
@080042DC:
	mov r1, r12
	adds r0, r3, r1
	str r4, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl SetBgTilemap
@080042EA:
	mov r2, r9
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	muls r0, r1
	lsls r0, 22
	lsrs r0, 16
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	bne @08004338
	adds r0, r7, 0
	bl GetNumActiveWindowsOnBg8Bit
	lsls r0, 24
	cmp r0, 0
	bne @08004322
	ldr r0, =0x03002f70
	lsls r1, r7, 2
	adds r5, r1, r0
	ldr r1, [r5]
	ldr r0, =nullsub_9
	cmp r1, r0
	beq @08004322
	adds r0, r1, 0
	bl Free
	str r4, [r5]
@08004322:
	movs r0, 0xFF
	b @08004356
	.pool
@08004338:
	ldr r1, =0x02020004
	lsls r2, r6, 1
	adds r2, r6
	lsls r2, 2
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r2, r0
	str r4, [r0]
	adds r2, r1
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r6, 0
@08004356:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddWindow8Bit

	thumb_func_start FillWindowPixelBuffer8Bit
; void FillWindowPixelBuffer8Bit(u8 windowId, u8 fillValue)
FillWindowPixelBuffer8Bit: ; 8004368
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r6, =0x02020004
	lsls r1, r0, 1
	adds r1, r0
	lsls r4, r1, 2
	adds r0, r4, r6
	ldrb r1, [r0, 0x3]
	ldrb r0, [r0, 0x4]
	muls r0, r1
	lsls r0, 22
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r3
	bge @0800439E
	adds r0, r6, 0
	adds r0, 0x8
	adds r1, r4, r0
@08004392:
	ldr r0, [r1]
	adds r0, r2
	strb r5, [r0]
	adds r2, 0x1
	cmp r2, r3
	blt @08004392
@0800439E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillWindowPixelBuffer8Bit

	thumb_func_start FillWindowPixelRect8Bit
; void FillWindowPixelRect8Bit(u8 windowId, u8 fillValue, u16 x, u16 y, u16 width, u16 height)
FillWindowPixelRect8Bit: ; 80043A8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	mov r9, r3
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	mov r8, r4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r4, r9
	lsls r4, 16
	lsrs r4, 16
	mov r9, r4
	lsls r3, 16
	lsrs r3, 16
	mov r4, r8
	lsls r4, 16
	lsrs r4, 16
	mov r8, r4
	ldr r5, =0x02020004
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r4, r5
	ldrb r0, [r4, 0x3]
	lsls r0, 3
	ldr r6, =0xffff0000
	ldr r5, [sp, 0xC]
	ands r5, r6
	orrs r5, r0
	str r5, [sp, 0xC]
	ldrb r4, [r4, 0x4]
	lsls r4, 19
	ldr r0, =0x0000ffff
	ands r0, r5
	orrs r0, r4
	str r0, [sp, 0xC]
	mov r0, r8
	str r0, [sp]
	str r1, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r2, 0
	mov r2, r9
	bl FillBitmapRect8Bit
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillWindowPixelRect8Bit

	thumb_func_start BlitBitmapRectToWindow4BitTo8Bit
; void BlitBitmapRectToWindow4BitTo8Bit(u8 rbox_id, u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight, u8 paletteOffset)
BlitBitmapRectToWindow4BitTo8Bit: ; 8004434
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	ldr r4, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	ldr r6, [sp, 0x54]
	mov r8, r6
	ldr r7, [sp, 0x58]
	mov r9, r7
	ldr r6, [sp, 0x5C]
	mov r10, r6
	ldr r7, [sp, 0x60]
	mov r12, r7
	ldr r6, [sp, 0x64]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	mov r7, r8
	lsls r7, 16
	lsrs r7, 16
	mov r8, r7
	mov r7, r9
	lsls r7, 16
	lsrs r7, 16
	mov r9, r7
	mov r7, r10
	lsls r7, 16
	lsrs r7, 16
	mov r10, r7
	mov r7, r12
	lsls r7, 16
	lsrs r7, 16
	mov r12, r7
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x28]
	str r1, [sp, 0x18]
	lsls r5, 16
	ldr r6, =0x0000ffff
	lsrs r4, 16
	orrs r4, r5
	str r4, [sp, 0x1C]
	ldr r1, =0x02020004
	lsls r5, r0, 1
	adds r5, r0
	lsls r5, 2
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, 0x20]
	adds r5, r1
	ldrb r0, [r5, 0x3]
	lsls r0, 3
	add r1, sp, 0x20
	ldr r4, [r1, 0x4]
	ldr r7, =0xffff0000
	ands r4, r7
	orrs r4, r0
	str r4, [r1, 0x4]
	ldrb r0, [r5, 0x4]
	lsls r0, 19
	ands r6, r4
	orrs r6, r0
	str r6, [r1, 0x4]
	mov r0, r8
	str r0, [sp]
	mov r6, r9
	str r6, [sp, 0x4]
	mov r7, r10
	str r7, [sp, 0x8]
	mov r0, r12
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	ldr r6, [sp, 0x28]
	str r6, [sp, 0x14]
	add r0, sp, 0x18
	bl BlitBitmapRect4BitTo8Bit
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BlitBitmapRectToWindow4BitTo8Bit

	thumb_func_start CopyWindowToVram8Bit
; void CopyWindowToVram8Bit(u8 windowId, u8 mode)
CopyWindowToVram8Bit: ; 8004500
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	adds r5, r2, 0
	ldr r6, =0x02020184
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, =0x02020004
	adds r3, r1, r0
	str r3, [r6]
	ldr r4, =0x02020188
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	muls r0, r1
	lsls r0, 6
	strh r0, [r4]
	cmp r2, 0x2
	beq @0800454E
	cmp r2, 0x2
	bgt @08004540
	cmp r2, 0x1
	beq @08004546
	b @08004570
	.pool
@08004540:
	cmp r5, 0x3
	beq @0800455C
	b @08004570
@08004546:
	ldrb r0, [r3]
	bl CopyBgTilemapBufferToVram
	b @08004570
@0800454E:
	ldrb r0, [r3]
	ldr r1, [r3, 0x8]
	ldrh r2, [r4]
	ldrh r3, [r3, 0x6]
	bl LoadBgTiles
	b @08004570
@0800455C:
	ldrb r0, [r3]
	ldr r1, [r3, 0x8]
	ldrh r2, [r4]
	ldrh r3, [r3, 0x6]
	bl LoadBgTiles
	ldr r0, [r6]
	ldrb r0, [r0]
	bl CopyBgTilemapBufferToVram
@08004570:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end CopyWindowToVram8Bit

	thumb_func_start GetNumActiveWindowsOnBg8Bit
; int GetNumActiveWindowsOnBg8Bit(int bg_id)
GetNumActiveWindowsOnBg8Bit: ; 8004578
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r2, =0x02020004
	movs r1, 0x1F
@08004584:
	ldrb r0, [r2]
	cmp r0, r4
	bne @08004590
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
@08004590:
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge @08004584
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetNumActiveWindowsOnBg8Bit
