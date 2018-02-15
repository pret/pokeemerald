	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start load_intro_part2_graphics
load_intro_part2_graphics: @ 817B064
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_085F0740
	ldr r1, =0x06004000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F0BC0
	ldr r1, =0x06007800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F06E0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	cmp r4, 0
	beq _0817B08C
	cmp r4, 0x1
	beq _0817B0EC
_0817B08C:
	ldr r0, =gUnknown_085F0DBC
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1398
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F0CFC
	movs r1, 0
	movs r2, 0x60
	bl LoadPalette
	ldr r0, =gUnknown_085F5064
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F1668
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	bl sub_817B76C
	b _0817B11E
	.pool
_0817B0EC:
	ldr r0, =gUnknown_085F1824
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1EAC
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F17E4
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085F50EC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F21B0
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	bl sub_817B788
_0817B11E:
	ldr r1, =gUnknown_0203BD28
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x8
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end load_intro_part2_graphics

	thumb_func_start sub_817B150
sub_817B150: @ 817B150
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0817B162
	cmp r0, 0x1
	ble _0817B162
	cmp r0, 0x2
	beq _0817B194
_0817B162:
	ldr r1, =0x00000603
	movs r0, 0xE
	bl SetGpuReg
	ldr r1, =0x00000702
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =0x00000f05
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xF2
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	b _0817B1B6
	.pool
_0817B194:
	ldr r1, =0x00000603
	movs r0, 0xE
	bl SetGpuReg
	ldr r1, =0x00000702
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =0x00000f05
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xF2
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
_0817B1B6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B150

	thumb_func_start sub_817B1C8
sub_817B1C8: @ 817B1C8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_085F0740
	ldr r1, =0x06004000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F0BC0
	ldr r1, =0x06007800
	bl LZ77UnCompVram
	cmp r4, 0x4
	bhi _0817B214
	lsls r0, r4, 2
	ldr r1, =_0817B200
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0817B200:
	.4byte _0817B214
	.4byte _0817B270
	.4byte _0817B2DC
	.4byte _0817B2DC
	.4byte _0817B334
_0817B214:
	ldr r0, =gUnknown_085F06E0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085F0DBC
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1398
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F0CFC
	movs r1, 0
	movs r2, 0x60
	bl LoadPalette
	ldr r0, =gUnknown_085F5064
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F16A8
	ldr r1, =0x06010000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1668
	b _0817B2A6
	.pool
_0817B270:
	ldr r0, =gUnknown_085F0700
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085F0DBC
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1398
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F0D5C
	movs r1, 0
	movs r2, 0x60
	bl LoadPalette
	ldr r0, =gUnknown_085F5064
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F16A8
	ldr r1, =0x06010000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1688
_0817B2A6:
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	bl sub_817B76C
	b _0817B370
	.pool
_0817B2DC:
	ldr r0, =gUnknown_085F0700
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085F1824
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F1EAC
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r4, =gUnknown_085F1804
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085F50EC
	bl LoadCompressedObjectPic
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	bl sub_817B788
	b _0817B370
	.pool
_0817B334:
	ldr r0, =gUnknown_085F0720
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085F235C
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F2568
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085F231C
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	ldr r0, =gUnknown_085F5180
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F2548
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	bl sub_817B7A4
_0817B370:
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x8
	strb r0, [r1]
	ldr r1, =gUnknown_0203BD28
	movs r0, 0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B1C8

	thumb_func_start sub_817B3A8
sub_817B3A8: @ 817B3A8
	push {lr}
	ldr r1, =0x00000603
	movs r0, 0xE
	bl SetGpuReg
	ldr r1, =0x00000702
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =0x00000f05
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B3A8

	thumb_func_start sub_817B3DC
sub_817B3DC: @ 817B3DC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 16
	lsrs r6, 16
	mov r0, r8
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	ldr r1, =sub_817B458
	mov r9, r1
	mov r0, r9
	movs r1, 0
	str r3, [sp]
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	strh r5, [r0, 0x8]
	strh r6, [r0, 0xA]
	strh r2, [r0, 0xC]
	strh r2, [r0, 0xE]
	mov r1, r8
	strh r1, [r0, 0x10]
	strh r2, [r0, 0x12]
	strh r2, [r0, 0x14]
	ldr r3, [sp]
	strh r3, [r0, 0x16]
	movs r1, 0x8
	strh r1, [r0, 0x18]
	strh r2, [r0, 0x1A]
	adds r0, r4, 0
	bl _call_via_r9
	adds r0, r4, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817B3DC

	thumb_func_start sub_817B458
sub_817B458: @ 817B458
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	lsls r2, r0, 16
	cmp r2, 0
	beq _0817B4A0
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	lsls r0, 16
	ldrh r1, [r4, 0xE]
	adds r1, r0, r1
	lsrs r0, r2, 12
	subs r1, r0
	asrs r0, r1, 16
	strh r0, [r4, 0xC]
	strh r1, [r4, 0xE]
	ldrh r1, [r4, 0xC]
	movs r0, 0x14
	bl SetGpuReg
	ldr r2, =gUnknown_0203BD24
	ldr r0, =gUnknown_0203BD26
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x16
	bl SetGpuReg
_0817B4A0:
	ldrh r0, [r4, 0x10]
	lsls r2, r0, 16
	cmp r2, 0
	beq _0817B4FA
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r0, 16
	ldrh r1, [r4, 0x14]
	adds r1, r0, r1
	lsrs r0, r2, 12
	subs r1, r0
	asrs r0, r1, 16
	strh r0, [r4, 0x12]
	strh r1, [r4, 0x14]
	ldrh r1, [r4, 0x12]
	movs r0, 0x18
	bl SetGpuReg
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0817B4F0
	ldr r2, =gUnknown_0203BD24
	ldr r0, =gUnknown_0203BD26
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	b _0817B4FA
	.pool
_0817B4F0:
	ldr r0, =gUnknown_0203BD24
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
_0817B4FA:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r2, r1, r0
	ldrh r0, [r2, 0x16]
	lsls r3, r0, 16
	cmp r3, 0
	beq _0817B532
	movs r1, 0x18
	ldrsh r0, [r2, r1]
	lsls r0, 16
	ldrh r1, [r2, 0x1A]
	adds r1, r0, r1
	lsrs r0, r3, 12
	subs r1, r0
	asrs r0, r1, 16
	strh r0, [r2, 0x18]
	strh r1, [r2, 0x1A]
	ldrh r1, [r2, 0x18]
	movs r0, 0x1C
	bl SetGpuReg
	ldr r0, =gUnknown_0203BD24
	ldrh r1, [r0]
	movs r0, 0x1E
	bl SetGpuReg
_0817B532:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B458

	thumb_func_start sub_817B540
sub_817B540: @ 817B540
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0817B620
	cmp r0, 0x1
	ble _0817B554
	cmp r0, 0x2
	beq _0817B5B8
_0817B554:
	ldr r0, =gMain
	ldr r2, [r0, 0x20]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0
	bne _0817B620
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817B620
	movs r0, 0x4
	ands r2, r0
	cmp r2, 0
	beq _0817B58C
	ldr r2, =gPlttBufferUnfaded
	ldrh r1, [r2, 0x12]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, 0x14]
	b _0817B596
	.pool
_0817B58C:
	ldr r2, =gPlttBufferUnfaded
	ldrh r1, [r2, 0x14]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, 0x12]
_0817B596:
	adds r0, 0x2
	strh r1, [r0]
	adds r4, r0, 0
	mov r0, sp
	movs r1, 0x9
	movs r2, 0x2
	bl LoadPalette
	adds r0, r4, 0
	movs r1, 0xA
	movs r2, 0x2
	bl LoadPalette
	b _0817B620
	.pool
_0817B5B8:
	ldr r0, =gMain
	ldr r2, [r0, 0x20]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0
	bne _0817B620
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817B620
	movs r0, 0x4
	ands r2, r0
	cmp r2, 0
	beq _0817B5F8
	mov r1, sp
	ldr r2, =0x00003d27
	adds r0, r2, 0
	strh r0, [r1]
	adds r1, 0x2
	ldr r2, =0x00000295
	b _0817B606
	.pool
_0817B5F8:
	mov r1, sp
	movs r2, 0xC7
	lsls r2, 2
	adds r0, r2, 0
	strh r0, [r1]
	adds r1, 0x2
	ldr r2, =0x00003d27
_0817B606:
	adds r0, r2, 0
	strh r0, [r1]
	adds r4, r1, 0
	mov r0, sp
	movs r1, 0xC
	movs r2, 0x2
	bl LoadPalette
	adds r0, r4, 0
	movs r1, 0xD
	movs r2, 0x2
	bl LoadPalette
_0817B620:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B540

	thumb_func_start sub_817B62C
sub_817B62C: @ 817B62C
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	beq _0817B690
	cmp r0, 0
	beq _0817B64C
	adds r0, r2, 0
	bl DestroySprite
	b _0817B690
	.pool
_0817B64C:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	lsls r0, 16
	ldrh r1, [r2, 0x32]
	orrs r0, r1
	ldrh r1, [r2, 0x30]
	adds r0, r1
	asrs r1, r0, 16
	strh r1, [r2, 0x20]
	strh r0, [r2, 0x32]
	cmp r1, 0xFF
	ble _0817B668
	ldr r0, =0x0000ffe0
	strh r0, [r2, 0x20]
_0817B668:
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0817B688
	ldr r1, =gUnknown_0203BD24
	ldr r0, =gUnknown_0203BD26
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	b _0817B68C
	.pool
_0817B688:
	ldr r0, =gUnknown_0203BD24
	ldrh r0, [r0]
_0817B68C:
	negs r0, r0
	strh r0, [r2, 0x26]
_0817B690:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B62C

	thumb_func_start sub_817B698
sub_817B698: @ 817B698
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	movs r7, 0
	cmp r7, r8
	bcs _0817B74E
	ldr r0, =gSprites
	mov r10, r0
	movs r2, 0x3F
	mov r9, r2
_0817B6C2:
	lsls r6, r7, 3
	ldr r0, [sp, 0x4]
	adds r6, r0
	ldrb r1, [r6, 0x1]
	ldrb r2, [r6, 0x2]
	ldrb r3, [r6, 0x3]
	ldr r0, =gUnknown_085F504C
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	mov r2, r10
	adds r4, r5, r2
	ldrb r2, [r6]
	lsls r1, r2, 26
	lsrs r1, 30
	lsrs r2, 6
	adds r0, r4, 0
	movs r3, 0
	bl CalcCenterToCornerVec
	ldrb r3, [r4, 0x5]
	movs r0, 0xC
	orrs r3, r0
	strb r3, [r4, 0x5]
	ldrb r1, [r6]
	lsls r1, 26
	lsrs r1, 30
	lsls r1, 6
	ldrb r2, [r4, 0x1]
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r6]
	lsrs r1, 6
	lsls r1, 6
	ldrb r2, [r4, 0x3]
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	movs r0, 0xF
	ands r3, r0
	strb r3, [r4, 0x5]
	ldr r0, =gSprites + 8
	adds r5, r0
	ldr r2, [sp, 0x8]
	str r2, [r5]
	ldrb r1, [r6]
	lsls r1, 28
	lsrs r1, 28
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r1, 0
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x2E]
	ldrh r0, [r6, 0x4]
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x32]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, r8
	bcc _0817B6C2
_0817B74E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B698

	thumb_func_start sub_817B76C
sub_817B76C: @ 817B76C
	push {lr}
	ldr r1, =gUnknown_085F50A4
	ldr r2, =gUnknown_085F5094
	movs r0, 0
	movs r3, 0x9
	bl sub_817B698
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B76C

	thumb_func_start sub_817B788
sub_817B788: @ 817B788
	push {lr}
	ldr r1, =gUnknown_085F5120
	ldr r2, =gUnknown_085F5114
	movs r0, 0x1
	movs r3, 0xC
	bl sub_817B698
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B788

	thumb_func_start sub_817B7A4
sub_817B7A4: @ 817B7A4
	push {lr}
	ldr r1, =gUnknown_085F519C
	ldr r2, =gUnknown_085F5198
	movs r0, 0x1
	movs r3, 0x6
	bl sub_817B698
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B7A4

	thumb_func_start nullsub_65
nullsub_65: @ 817B7C0
	bx lr
	thumb_func_end nullsub_65

	thumb_func_start sub_817B7C4
sub_817B7C4: @ 817B7C4
	push {r4,lr}
	ldr r4, =gSprites
	movs r1, 0x2E
	ldrsh r2, [r0, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r1, [r1]
	movs r2, 0x3E
	adds r2, r0
	mov r12, r2
	movs r2, 0x4
	ands r2, r1
	mov r1, r12
	ldrb r3, [r1]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	movs r1, 0x2E
	ldrsh r2, [r0, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x20]
	strh r1, [r0, 0x20]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x24]
	strh r1, [r0, 0x24]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x26]
	strh r1, [r0, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B7C4

	thumb_func_start intro_create_brendan_sprite
intro_create_brendan_sprite: @ 817B834
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, =gUnknown_085F51EC
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x2
	bl CreateSprite
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_085F523C
	adds r4, 0x8
	lsls r4, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	strh r6, [r1, 0x2E]
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end intro_create_brendan_sprite

	thumb_func_start intro_create_may_sprite
intro_create_may_sprite: @ 817B88C
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, =gUnknown_085F5204
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x2
	bl CreateSprite
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_085F5254
	adds r4, 0x8
	lsls r4, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	strh r6, [r1, 0x2E]
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end intro_create_may_sprite

	thumb_func_start nullsub_66
nullsub_66: @ 817B8E4
	bx lr
	thumb_func_end nullsub_66

	thumb_func_start sub_817B8E8
sub_817B8E8: @ 817B8E8
	push {r4,lr}
	ldr r4, =gSprites
	movs r1, 0x2E
	ldrsh r2, [r0, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r1, [r1]
	movs r2, 0x3E
	adds r2, r0
	mov r12, r2
	movs r2, 0x4
	ands r2, r1
	mov r1, r12
	ldrb r3, [r1]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	movs r1, 0x2E
	ldrsh r2, [r0, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x22]
	strh r1, [r0, 0x22]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x24]
	strh r1, [r0, 0x24]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x26]
	strh r1, [r0, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B8E8

	thumb_func_start sub_817B948
sub_817B948: @ 817B948
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r2, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_085F528C
	mov r8, r0
	lsls r2, 16
	asrs r4, r2, 16
	ldr r0, =0xffe00000
	adds r2, r0
	asrs r2, 16
	lsls r5, 16
	asrs r5, 16
	mov r0, r8
	adds r1, r2, 0
	adds r2, r5, 0
	movs r3, 0x5
	bl CreateSprite
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	adds r4, 0x20
	lsls r4, 16
	asrs r4, 16
	mov r0, r8
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r0, r4, r5
	strh r6, [r0, 0x2E]
	movs r1, 0x1
	bl StartSpriteAnim
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_817B8E8
	str r0, [r4]
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817B948

	thumb_func_start intro_create_flygon_sprite
intro_create_flygon_sprite: @ 817B9C4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r2, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_085F52A4
	mov r8, r0
	lsls r2, 16
	asrs r4, r2, 16
	ldr r0, =0xffe00000
	adds r2, r0
	asrs r2, 16
	lsls r5, 16
	asrs r5, 16
	mov r0, r8
	adds r1, r2, 0
	adds r2, r5, 0
	movs r3, 0x5
	bl CreateSprite
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	adds r4, 0x20
	lsls r4, 16
	asrs r4, 16
	mov r0, r8
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r0, r4, r5
	strh r6, [r0, 0x2E]
	movs r1, 0x1
	bl StartSpriteAnim
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_817B8E8
	str r0, [r4]
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end intro_create_flygon_sprite

	.align 2, 0 @ Don't pad with nop.
