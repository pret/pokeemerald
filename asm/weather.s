	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80AAFA4
@ void sub_80AAFA4()
sub_80AAFA4: @ 80AAFA4
	push {r4-r6,lr}
	ldr r0, =sub_80AB1B0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _080AB060
	movs r0, 0x90
	lsls r0, 5
	bl AllocObjectPalette
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0854C270
	lsls r1, r5, 5
	ldr r2, =gPlttBufferUnfaded + 0x200
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	bl sub_80AB294
	ldr r4, =gUnknown_02038454
	ldr r1, =0x000006d5
	adds r0, r4, r1
	strb r5, [r0]
	ldr r0, =0x00001201
	bl AllocObjectPalette
	ldr r2, =0x000006d4
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, =0x000006da
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, 0x4
	adds r0, r4, r2
	strb r6, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, 0xC
	adds r0, r4, r2
	strb r6, [r0]
	adds r1, 0x22
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, 0x17
	adds r0, r4, r2
	strb r6, [r0]
	adds r1, 0x24
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, 0x1B
	adds r0, r4, r2
	strb r6, [r0]
	subs r1, 0xD
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, 0x18
	adds r0, r4, r2
	strb r6, [r0]
	subs r1, 0x1D
	adds r0, r4, r1
	strb r6, [r0]
	movs r0, 0x10
	movs r1, 0
	bl sub_80AC124
	movs r2, 0xDA
	lsls r2, 3
	adds r0, r4, r2
	strb r6, [r0]
	ldr r0, =0x000006c6
	adds r1, r4, r0
	movs r0, 0x3
	strb r0, [r1]
	movs r1, 0xD9
	lsls r1, 3
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, 0x3
	adds r1, r4, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =sub_80AB160
	movs r1, 0x50
	bl CreateTask
	ldr r1, =0x000006c9
	adds r4, r1
	strb r0, [r4]
_080AB060:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AAFA4

	thumb_func_start weather_set
weather_set: @ 80AB098
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	beq _080AB0AE
	cmp r4, 0x5
	beq _080AB0AE
	cmp r4, 0xD
	beq _080AB0AE
	bl play_some_sound
_080AB0AE:
	ldr r1, =gUnknown_02038454
	ldr r2, =0x000006d1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r4
	beq _080AB0D2
	movs r3, 0xDA
	lsls r3, 3
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r4
	bne _080AB0D2
	ldr r0, =gUnknown_0854C150
	lsls r1, r4, 4
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_080AB0D2:
	ldr r1, =gUnknown_02038454
	ldr r2, =0x000006d3
	adds r0, r1, r2
	movs r2, 0
	strb r2, [r0]
	ldr r3, =0x000006d1
	adds r0, r1, r3
	strb r4, [r0]
	ldr r0, =0x000006ce
	adds r1, r0
	strh r2, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end weather_set

	thumb_func_start sub_80AB104
sub_80AB104: @ 80AB104
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl play_some_sound
	ldr r0, =gUnknown_02038454
	movs r2, 0xDA
	lsls r2, 3
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, =0x000006d1
	adds r0, r1
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB104

	thumb_func_start sub_80AB130
sub_80AB130: @ 80AB130
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl play_some_sound
	ldr r1, =gUnknown_02038454
	movs r2, 0xDA
	lsls r2, 3
	adds r0, r1, r2
	strb r4, [r0]
	adds r2, 0x1
	adds r0, r1, r2
	strb r4, [r0]
	movs r0, 0xD9
	lsls r0, 3
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB130

	thumb_func_start sub_80AB160
sub_80AB160: @ 80AB160
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gUnknown_02038454
	movs r1, 0xD9
	lsls r1, 3
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AB198
	ldr r1, =gUnknown_0854C150
	movs r3, 0xDA
	lsls r3, 3
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 4
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80AB1B0
	str r1, [r0]
_080AB198:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB160

	thumb_func_start sub_80AB1B0
sub_80AB1B0: @ 80AB1B0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r5, =gUnknown_02038454
	movs r0, 0xDA
	lsls r0, 3
	adds r6, r5, r0
	ldr r1, =0x000006d1
	adds r7, r5, r1
	ldrb r0, [r6]
	ldrb r2, [r7]
	cmp r0, r2
	beq _080AB22C
	ldr r0, =gUnknown_0854C150
	mov r9, r0
	ldrb r0, [r6]
	lsls r0, 4
	mov r1, r9
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080AB23C
	ldr r1, =0x000006c6
	adds r1, r5
	mov r8, r1
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _080AB23C
	ldrb r0, [r7]
	lsls r0, 4
	add r0, r9
	ldr r0, [r0]
	bl _call_via_r0
	ldr r2, =0x000006c3
	adds r0, r5, r2
	strb r4, [r0]
	mov r0, r8
	strb r4, [r0]
	ldrb r0, [r7]
	strb r0, [r6]
	adds r2, 0x10
	adds r1, r5, r2
	movs r0, 0x1
	strb r0, [r1]
	b _080AB23C
	.pool
_080AB22C:
	ldr r0, =gUnknown_0854C150
	ldrb r1, [r6]
	lsls r1, 4
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_080AB23C:
	ldr r1, =gUnknown_0854C240
	ldr r0, =gUnknown_02038454
	ldr r2, =0x000006c6
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB1B0

	thumb_func_start sub_80AB26C
sub_80AB26C: @ 80AB26C
	ldr r0, =gUnknown_02038454
	ldr r2, =0x000006c1
	adds r1, r0, r2
	movs r2, 0
	strb r2, [r1]
	ldr r1, =0x000006c2
	adds r0, r1
	strb r2, [r0]
	bx lr
	.pool
	thumb_func_end sub_80AB26C

	thumb_func_start nullsub_36
nullsub_36: @ 80AB28C
	bx lr
	thumb_func_end nullsub_36

	thumb_func_start sub_80AB290
sub_80AB290: @ 80AB290
	movs r0, 0
	bx lr
	thumb_func_end sub_80AB290

	thumb_func_start sub_80AB294
sub_80AB294: @ 80AB294
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r1, =gUnknown_03000F50
	ldr r0, =gUnknown_0854C250
	str r0, [r1]
	movs r0, 0
	mov r12, r0
	ldr r1, =gUnknown_020388B4
	mov r10, r1
_080AB2AC:
	mov r7, r10
	mov r0, r12
	cmp r0, 0
	bne _080AB2B8
	ldr r1, =0xfffffda0
	adds r7, r1
_080AB2B8:
	movs r5, 0
	movs r0, 0x1
	add r0, r12
	mov r9, r0
_080AB2C0:
	lsls r1, r5, 8
	lsls r0, r5, 24
	lsrs r2, r0, 16
	mov r0, r12
	cmp r0, 0
	bne _080AB2E4
	adds r0, r1, 0
	lsls r0, 12
	lsrs r4, r0, 16
	b _080AB2E6
	.pool
_080AB2E4:
	movs r4, 0
_080AB2E6:
	movs r3, 0
	adds r1, r5, 0x1
	mov r8, r1
_080AB2EC:
	subs r1, r2, r4
	lsls r1, 16
	lsrs r2, r1, 16
	lsls r0, r3, 5
	adds r0, r7
	adds r0, r5
	lsrs r1, 24
	strb r1, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x2
	bls _080AB2EC
	adds r6, r2, 0
	movs r0, 0xF8
	lsls r0, 5
	subs r0, r2
	cmp r0, 0
	bge _080AB314
	adds r0, 0xF
_080AB314:
	lsls r0, 12
	lsrs r4, r0, 16
	cmp r5, 0xB
	bhi _080AB35E
	cmp r3, 0x12
	bhi _080AB384
_080AB320:
	adds r0, r2, r4
	lsls r0, 16
	lsrs r2, r0, 16
	subs r0, r2, r6
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	ble _080AB33C
	lsrs r0, 31
	adds r0, r1, r0
	asrs r0, 1
	subs r0, r2, r0
	lsls r0, 16
	lsrs r2, r0, 16
_080AB33C:
	lsls r0, r3, 5
	adds r0, r7
	adds r1, r0, r5
	lsrs r0, r2, 8
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _080AB352
	movs r0, 0x1F
	strb r0, [r1]
_080AB352:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x12
	bls _080AB320
	b _080AB384
_080AB35E:
	cmp r3, 0x12
	bhi _080AB384
	movs r6, 0x1F
_080AB364:
	adds r1, r2, r4
	lsls r1, 16
	lsrs r2, r1, 16
	lsls r0, r3, 5
	adds r0, r7
	adds r0, r5
	lsrs r1, 24
	strb r1, [r0]
	cmp r1, 0x1F
	bls _080AB37A
	strb r6, [r0]
_080AB37A:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x12
	bls _080AB364
_080AB384:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r5, r0, 16
	cmp r5, 0x1F
	bls _080AB2C0
	mov r1, r9
	lsls r0, r1, 16
	lsrs r0, 16
	mov r12, r0
	cmp r0, 0x1
	bls _080AB2AC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB294

	thumb_func_start sub_80AB3A8
sub_80AB3A8: @ 80AB3A8
	push {r4-r7,lr}
	ldr r0, =gUnknown_02038454
	ldr r1, =0x000006c6
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r3, r0, 0
	cmp r1, 0x2
	beq _080AB42C
	movs r7, 0xD8
	lsls r7, 3
	adds r4, r3, r7
	ldr r1, =0x000006c1
	adds r0, r3, r1
	ldrb r7, [r4]
	mov r12, r7
	movs r6, 0
	ldrsb r6, [r4, r6]
	movs r5, 0
	ldrsb r5, [r0, r5]
	cmp r6, r5
	bne _080AB3E4
	movs r0, 0x3
	strb r0, [r2]
	b _080AB42C
	.pool
_080AB3E4:
	ldr r0, =0x000006c3
	adds r2, r3, r0
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldr r7, =0x000006c2
	adds r1, r3, r7
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _080AB42C
	movs r0, 0
	strb r0, [r2]
	mov r0, r12
	cmp r6, r5
	bge _080AB414
	adds r0, 0x1
	b _080AB418
	.pool
_080AB414:
	mov r0, r12
	subs r0, 0x1
_080AB418:
	strb r0, [r4]
	movs r1, 0xD8
	lsls r1, 3
	adds r0, r3, r1
	movs r2, 0
	ldrsb r2, [r0, r2]
	movs r0, 0
	movs r1, 0x20
	bl pal_fade_2
_080AB42C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB3A8

	thumb_func_start sub_80AB434
sub_80AB434: @ 80AB434
	push {lr}
	ldr r2, =gUnknown_02038454
	ldr r0, =0x000006cb
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080AB452
	ldr r3, =0x000006ca
	adds r1, r2, r3
	movs r0, 0
	strb r0, [r1]
_080AB452:
	movs r1, 0xDA
	lsls r1, 3
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, 0x3
	cmp r0, 0xA
	bhi _080AB51C
	lsls r0, 2
	ldr r1, =_080AB47C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AB47C:
	.4byte _080AB4A8
	.4byte _080AB4A8
	.4byte _080AB4A8
	.4byte _080AB4F4
	.4byte _080AB51C
	.4byte _080AB51C
	.4byte _080AB51C
	.4byte _080AB51C
	.4byte _080AB4A8
	.4byte _080AB4D0
	.4byte _080AB4A8
_080AB4A8:
	bl sub_80AB54C
	lsls r0, 24
	cmp r0, 0
	bne _080AB53C
	ldr r0, =gUnknown_02038454
	movs r2, 0xD8
	lsls r2, 3
	adds r1, r0, r2
	movs r2, 0x3
	strb r2, [r1]
	ldr r3, =0x000006c6
	adds r0, r3
	strb r2, [r0]
	b _080AB53C
	.pool
_080AB4D0:
	bl sub_80AB5AC
	lsls r0, 24
	cmp r0, 0
	bne _080AB53C
	ldr r1, =gUnknown_02038454
	movs r0, 0xD8
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0xFA
	strb r0, [r2]
	ldr r2, =0x000006c6
	adds r1, r2
	b _080AB538
	.pool
_080AB4F4:
	bl sub_80AB604
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080AB53C
	ldr r0, =gUnknown_02038454
	movs r3, 0xD8
	lsls r3, 3
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, =0x000006c6
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
	b _080AB53C
	.pool
_080AB51C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080AB53C
	ldr r3, =0x000006c1
	adds r0, r2, r3
	ldrb r1, [r0]
	subs r3, 0x1
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, =0x000006c6
	adds r1, r2, r0
_080AB538:
	movs r0, 0x3
	strb r0, [r1]
_080AB53C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB434

	thumb_func_start sub_80AB54C
sub_80AB54C: @ 80AB54C
	push {r4,lr}
	sub sp, 0x4
	ldr r2, =gUnknown_02038454
	ldr r0, =0x000006c7
	adds r4, r2, r0
	ldrb r0, [r4]
	cmp r0, 0x10
	beq _080AB5A2
	adds r1, r0, 0x1
	strb r1, [r4]
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _080AB594
	movs r3, 0x10
	subs r3, r1
	lsls r3, 24
	lsrs r3, 24
	ldr r1, =0x000006c4
	adds r0, r2, r1
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, 0
	movs r1, 0x20
	movs r2, 0x3
	bl sub_80AB848
	movs r0, 0x1
	b _080AB5A4
	.pool
_080AB594:
	movs r0, 0
	movs r1, 0x20
	movs r2, 0x3
	bl pal_fade_2
	movs r0, 0x10
	strb r0, [r4]
_080AB5A2:
	movs r0, 0
_080AB5A4:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AB54C

	thumb_func_start sub_80AB5AC
sub_80AB5AC: @ 80AB5AC
	push {r4,lr}
	ldr r2, =gUnknown_02038454
	ldr r0, =0x000006c7
	adds r4, r2, r0
	ldrb r0, [r4]
	cmp r0, 0x10
	beq _080AB5FC
	adds r3, r0, 0x1
	strb r3, [r4]
	lsls r0, r3, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _080AB5EC
	movs r0, 0x6
	negs r0, r0
	movs r1, 0x10
	subs r1, r3
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =0x000006c4
	adds r2, r3
	ldrh r2, [r2]
	bl sub_80AB990
	movs r0, 0x1
	b _080AB5FE
	.pool
_080AB5EC:
	movs r2, 0x6
	negs r2, r2
	movs r0, 0
	movs r1, 0x20
	bl pal_fade_2
	movs r0, 0x10
	strb r0, [r4]
_080AB5FC:
	movs r0, 0
_080AB5FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AB5AC

	thumb_func_start sub_80AB604
sub_80AB604: @ 80AB604
	push {lr}
	ldr r2, =gUnknown_02038454
	ldr r1, =0x000006c7
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, 0x10
	beq _080AB638
	adds r1, 0x1
	strb r1, [r0]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0x000006c4
	adds r1, r2, r3
	ldrh r1, [r1]
	bl sub_80ABAB0
	movs r0, 0x1
	b _080AB63A
	.pool
_080AB638:
	movs r0, 0
_080AB63A:
	pop {r1}
	bx r1
	thumb_func_end sub_80AB604

	thumb_func_start nullsub_94
nullsub_94: @ 80AB640
	bx lr
	thumb_func_end nullsub_94

	thumb_func_start pal_fade_2
pal_fade_2: @ 80AB644
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, r3, 0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	asrs r0, r2, 24
	cmp r0, 0
	ble _080AB754
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r6, r3, 4
	adds r0, r1, r3
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r4, r9
	bcc _080AB67C
	b _080AB82E
_080AB67C:
	ldr r1, [sp]
	lsls r0, r1, 24
	asrs r0, 19
	str r0, [sp, 0x4]
_080AB684:
	ldr r0, =gUnknown_03000F50
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB6C0
	lsls r1, r6, 1
	ldr r0, =gPlttBufferUnfaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferFaded
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	mov r2, r9
	lsls r2, 16
	mov r8, r2
	adds r4, 0x1
	mov r12, r4
	b _080AB73E
	.pool
_080AB6C0:
	cmp r0, 0x2
	beq _080AB6D4
	adds r1, r4, 0
	subs r1, 0x10
	ldr r2, =gUnknown_02038454
	ldr r3, =0x000006d5
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _080AB6E4
_080AB6D4:
	ldr r0, =gUnknown_020388B4
	b _080AB6EA
	.pool
_080AB6E4:
	movs r3, 0x80
	lsls r3, 2
	adds r0, r2, r3
_080AB6EA:
	ldr r1, [sp, 0x4]
	adds r5, r1, r0
	movs r7, 0
	mov r2, r9
	lsls r2, 16
	mov r8, r2
	adds r4, 0x1
	mov r12, r4
	ldr r3, =gPlttBufferFaded
	mov r10, r3
_080AB6FE:
	adds r2, r6, 0
	lsls r0, r2, 1
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r1, 27
	lsrs r0, 27
	adds r0, r5, r0
	ldrb r4, [r0]
	lsls r0, r1, 22
	lsrs r0, 27
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r1, 17
	lsrs r1, 27
	adds r1, r5, r1
	ldrb r1, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r2, 1
	add r2, r10
	lsls r1, 10
	lsls r3, 5
	orrs r1, r3
	orrs r1, r4
	strh r1, [r2]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0xF
	bls _080AB6FE
_080AB73E:
	mov r2, r12
	lsls r0, r2, 16
	lsrs r4, r0, 16
	cmp r0, r8
	bcc _080AB684
	b _080AB82E
	.pool
_080AB754:
	cmp r0, 0
	bge _080AB81C
	mvns r0, r0
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r6, r3, 4
	adds r0, r1, r3
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r4, r3, 0
	cmp r4, r9
	bcs _080AB82E
_080AB770:
	ldr r0, =gUnknown_03000F50
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB7AC
	lsls r1, r6, 1
	ldr r0, =gPlttBufferUnfaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferFaded
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	mov r3, r9
	lsls r3, 16
	mov r8, r3
	adds r4, 0x1
	mov r12, r4
	b _080AB804
	.pool
_080AB7AC:
	movs r7, 0
	mov r0, r9
	lsls r0, 16
	mov r8, r0
	adds r4, 0x1
	mov r12, r4
	ldr r1, =gUnknown_0854014C
	mov r10, r1
	ldr r2, [sp]
	lsls r0, r2, 24
	asrs r5, r0, 11
_080AB7C2:
	lsls r0, r6, 1
	ldr r3, =gPlttBufferFaded
	adds r4, r0, r3
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	ldrh r3, [r0]
	lsls r3, 16
	lsrs r0, r3, 17
	movs r1, 0xF
	ands r0, r1
	lsrs r1, r3, 18
	movs r2, 0xF0
	ands r1, r2
	orrs r0, r1
	lsrs r3, 19
	movs r2, 0xF0
	lsls r2, 4
	adds r1, r2, 0
	ands r3, r1
	orrs r0, r3
	lsls r0, 1
	adds r0, r5
	add r0, r10
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0xF
	bls _080AB7C2
_080AB804:
	mov r3, r12
	lsls r0, r3, 16
	lsrs r4, r0, 16
	cmp r0, r8
	bcc _080AB770
	b _080AB82E
	.pool
_080AB81C:
	lsls r1, r4, 5
	ldr r0, =gPlttBufferUnfaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferFaded
	adds r1, r2
	mov r3, r9
	lsls r2, r3, 3
	bl CpuFastSet
_080AB82E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pal_fade_2

	thumb_func_start sub_80AB848
sub_80AB848: @ 80AB848
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r4, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	mov r1, sp
	strh r4, [r1]
	ldr r1, [sp]
	lsls r3, r1, 27
	lsrs r3, 27
	str r3, [sp, 0x4]
	lsls r3, r1, 22
	lsrs r3, 27
	str r3, [sp, 0x8]
	lsls r1, 17
	lsrs r1, 27
	str r1, [sp, 0xC]
	lsls r6, r0, 4
	mov r3, r10
	adds r1, r3, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r2, r1
	lsrs r2, 24
	adds r4, r0, 0
	cmp r4, r10
	bcs _080AB974
	lsls r0, r2, 24
	asrs r0, 19
	str r0, [sp, 0x10]
_080AB8A0:
	ldr r0, =gUnknown_03000F50
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB8D4
	mov r0, sp
	ldrh r3, [r0]
	adds r0, r6, 0
	movs r1, 0x10
	mov r2, r8
	bl BlendPalette
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	mov r3, r10
	lsls r3, 16
	mov r9, r3
	adds r4, 0x1
	mov r12, r4
	b _080AB96A
	.pool
_080AB8D4:
	cmp r0, 0x1
	bne _080AB8E4
	ldr r0, =gUnknown_02038654
	ldr r1, [sp, 0x10]
	adds r5, r1, r0
	b _080AB8EA
	.pool
_080AB8E4:
	ldr r0, =gUnknown_020388B4
	ldr r3, [sp, 0x10]
	adds r5, r3, r0
_080AB8EA:
	movs r7, 0
	mov r0, r10
	lsls r0, 16
	mov r9, r0
	adds r4, 0x1
	mov r12, r4
_080AB8F6:
	adds r4, r6, 0
	lsls r0, r4, 1
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r1, 27
	lsrs r0, 27
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r0, r1, 22
	lsrs r0, 27
	adds r0, r5, r0
	ldrb r2, [r0]
	lsls r1, 17
	lsrs r1, 27
	adds r1, r5, r1
	ldrb r1, [r1]
	ldr r6, [sp, 0x4]
	subs r0, r6, r3
	mov r6, r8
	muls r6, r0
	adds r0, r6, 0
	asrs r0, 4
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldr r6, [sp, 0x8]
	subs r0, r6, r2
	mov r6, r8
	muls r6, r0
	adds r0, r6, 0
	asrs r0, 4
	adds r2, r0
	lsls r2, 24
	ldr r6, [sp, 0xC]
	subs r0, r6, r1
	mov r6, r8
	muls r6, r0
	adds r0, r6, 0
	asrs r0, 4
	adds r1, r0
	lsls r1, 24
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r4, 1
	ldr r0, =gPlttBufferFaded
	adds r4, r0
	lsrs r1, 14
	lsrs r2, 19
	orrs r1, r2
	orrs r1, r3
	strh r1, [r4]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0xF
	bls _080AB8F6
_080AB96A:
	mov r1, r12
	lsls r0, r1, 16
	lsrs r4, r0, 16
	cmp r0, r9
	bcc _080AB8A0
_080AB974:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB848

	thumb_func_start sub_80AB990
sub_80AB990: @ 80AB990
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r1, 24
	lsrs r6, r1, 24
	mov r1, sp
	strh r2, [r1]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	eors r0, r1
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, [sp]
	lsls r1, r0, 27
	lsrs r1, 27
	str r1, [sp, 0x8]
	lsls r1, r0, 22
	lsrs r1, 27
	str r1, [sp, 0xC]
	lsls r0, 17
	lsrs r0, 27
	mov r10, r0
	movs r5, 0
	movs r4, 0
_080AB9C8:
	ldr r0, =gUnknown_03000F50
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB9F4
	mov r0, sp
	ldrh r3, [r0]
	adds r0, r5, 0
	movs r1, 0x10
	adds r2, r6, 0
	bl BlendPalette
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x1
	mov r8, r4
	b _080ABA8A
	.pool
_080AB9F4:
	movs r0, 0
	mov r12, r0
	ldr r1, [sp, 0x4]
	lsls r0, r1, 24
	adds r4, 0x1
	mov r8, r4
	movs r7, 0x1E
	asrs r0, 11
	mov r9, r0
_080ABA06:
	adds r4, r5, 0
	lsls r0, r4, 1
	ldr r5, =gPlttBufferUnfaded
	adds r0, r5
	ldr r0, [r0]
	lsls r2, r0, 27
	lsrs r2, 27
	lsls r1, r0, 22
	lsrs r1, 27
	lsls r0, 17
	lsrs r0, 27
	ands r0, r7
	lsls r0, 7
	ands r1, r7
	lsls r1, 3
	orrs r0, r1
	ands r2, r7
	lsls r0, 1
	orrs r0, r2
	add r0, r9
	ldr r1, =gUnknown_0854014C
	adds r0, r1
	ldr r1, [r0]
	lsls r3, r1, 27
	lsrs r3, 27
	lsls r2, r1, 22
	lsrs r2, 27
	lsls r1, 17
	lsrs r1, 27
	ldr r5, [sp, 0x8]
	subs r0, r5, r3
	muls r0, r6
	asrs r0, 4
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldr r5, [sp, 0xC]
	subs r0, r5, r2
	muls r0, r6
	asrs r0, 4
	adds r2, r0
	lsls r2, 24
	mov r5, r10
	subs r0, r5, r1
	muls r0, r6
	asrs r0, 4
	adds r1, r0
	lsls r1, 24
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r4, 1
	ldr r0, =gPlttBufferFaded
	adds r4, r0
	lsrs r1, 14
	lsrs r2, 19
	orrs r1, r2
	orrs r1, r3
	strh r1, [r4]
	mov r0, r12
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r12, r0
	cmp r0, 0xF
	bls _080ABA06
_080ABA8A:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r4, r0, 16
	cmp r4, 0x1F
	bls _080AB9C8
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AB990

	thumb_func_start sub_80ABAB0
sub_80ABAB0: @ 80ABAB0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r3, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r3, 16
	lsrs r3, 16
	mov r0, sp
	strh r3, [r0]
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	adds r2, r7, 0
	bl BlendPalette
	ldr r0, [sp]
	lsls r1, r0, 27
	lsrs r1, 27
	str r1, [sp, 0x4]
	lsls r1, r0, 22
	lsrs r1, 27
	str r1, [sp, 0x8]
	lsls r0, 17
	lsrs r0, 27
	mov r10, r0
	movs r4, 0x10
_080ABAEC:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80ABC00
	lsls r0, 24
	cmp r0, 0
	beq _080ABB9C
	adds r0, r4, 0x1
	lsls r1, r0, 20
	lsrs r1, 16
	mov r12, r1
	lsls r1, r4, 20
	lsrs r6, r1, 16
	mov r9, r0
	cmp r6, r12
	bcs _080ABBB0
	movs r0, 0x1C
	mov r8, r0
_080ABB10:
	lsls r5, r6, 1
	ldr r0, =gPlttBufferUnfaded
	adds r0, r5, r0
	ldr r2, [r0]
	lsls r4, r2, 27
	lsrs r4, 27
	lsls r3, r2, 22
	lsrs r3, 27
	lsls r2, 17
	lsrs r2, 27
	mov r0, r8
	subs r1, r0, r4
	lsls r0, r1, 1
	adds r0, r1
	asrs r0, 2
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x1F
	subs r1, r3
	lsls r0, r1, 1
	adds r0, r1
	asrs r0, 2
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	subs r1, r0, r2
	lsls r0, r1, 1
	adds r0, r1
	asrs r0, 2
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldr r1, [sp, 0x4]
	subs r0, r1, r4
	muls r0, r7
	asrs r0, 4
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [sp, 0x8]
	subs r0, r1, r3
	muls r0, r7
	asrs r0, 4
	adds r3, r0
	lsls r3, 24
	mov r1, r10
	subs r0, r1, r2
	muls r0, r7
	asrs r0, 4
	adds r2, r0
	lsls r2, 24
	ldr r0, =gPlttBufferFaded
	adds r5, r0
	lsrs r2, 14
	lsrs r3, 19
	orrs r2, r3
	orrs r2, r4
	strh r2, [r5]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r12
	bcc _080ABB10
	b _080ABBB0
	.pool
_080ABB9C:
	lsls r0, r4, 20
	lsrs r0, 16
	mov r1, sp
	ldrh r3, [r1]
	movs r1, 0x10
	adds r2, r7, 0
	bl BlendPalette
	adds r4, 0x1
	mov r9, r4
_080ABBB0:
	mov r1, r9
	lsls r0, r1, 16
	lsrs r4, r0, 16
	cmp r4, 0x1F
	bls _080ABAEC
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80ABAB0

	thumb_func_start sub_80ABBCC
sub_80ABBCC: @ 80ABBCC
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, =gUnknown_02038454
	ldr r0, =0x000006fa
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, 0x5
	bhi _080ABBEE
	ldr r4, =0x000006f4
	adds r0, r3, r4
	ldrb r3, [r1]
	adds r0, r3
	strb r2, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080ABBEE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ABBCC

	thumb_func_start sub_80ABC00
sub_80ABC00: @ 80ABC00
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r1, 0
	ldr r2, =gUnknown_02038454
	ldr r4, =0x000006fa
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r1, r0
	bcs _080ABC3E
	ldr r5, =0x000006f4
	adds r4, r2, r5
	adds r2, r0, 0
_080ABC1A:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r3
	bne _080ABC34
	movs r0, 0x1
	b _080ABC40
	.pool
_080ABC34:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bcc _080ABC1A
_080ABC3E:
	movs r0, 0
_080ABC40:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABC00

	thumb_func_start sub_80ABC48
sub_80ABC48: @ 80ABC48
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gUnknown_02038454
	ldr r1, =0x000006c6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _080ABC6E
	lsls r2, r4, 24
	asrs r2, 24
	movs r0, 0
	movs r1, 0x20
	bl pal_fade_2
	movs r1, 0xD8
	lsls r1, 3
	adds r0, r5, r1
	strb r4, [r0]
_080ABC6E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ABC48

	thumb_func_start sub_80ABC7C
sub_80ABC7C: @ 80ABC7C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r3, =gUnknown_02038454
	ldr r0, =0x000006c6
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, 0x3
	bne _080ABCBC
	movs r1, 0
	strb r1, [r2]
	movs r2, 0xD8
	lsls r2, 3
	adds r0, r3, r2
	strb r4, [r0]
	adds r2, 0x1
	adds r0, r3, r2
	strb r5, [r0]
	adds r2, 0x2
	adds r0, r3, r2
	strb r1, [r0]
	ldr r1, =0x000006c2
	adds r0, r3, r1
	strb r6, [r0]
	lsls r0, r4, 24
	asrs r0, 24
	bl sub_80ABC48
_080ABCBC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ABC7C

	thumb_func_start fade_screen
fade_screen: @ 80ABCD0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r0, 0x1
	beq _080ABD08
	cmp r0, 0x1
	bgt _080ABCEC
	cmp r0, 0
	beq _080ABCF6
	b _080ABDE4
_080ABCEC:
	cmp r2, 0x2
	beq _080ABCFC
	cmp r2, 0x3
	beq _080ABD0C
	b _080ABDE4
_080ABCF6:
	movs r4, 0
	movs r1, 0
	b _080ABD10
_080ABCFC:
	ldr r4, =0x0000ffff
	movs r1, 0
	b _080ABD10
	.pool
_080ABD08:
	movs r4, 0
	b _080ABD0E
_080ABD0C:
	ldr r4, =0x0000ffff
_080ABD0E:
	movs r1, 0x1
_080ABD10:
	ldr r0, =gUnknown_02038454
	movs r2, 0xDA
	lsls r2, 3
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	blt _080ABD38
	cmp r0, 0x6
	ble _080ABD2A
	cmp r0, 0xD
	bgt _080ABD38
	cmp r0, 0xB
	blt _080ABD38
_080ABD2A:
	movs r2, 0x1
	b _080ABD3A
	.pool
_080ABD38:
	movs r2, 0
_080ABD3A:
	cmp r1, 0
	beq _080ABD7C
	cmp r2, 0
	beq _080ABD4E
	ldr r0, =gPlttBufferFaded
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 1
	bl CpuFastSet
_080ABD4E:
	movs r0, 0x1
	negs r0, r0
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_02038454
	ldr r3, =0x000006c6
	adds r0, r3
	movs r1, 0x2
	strb r1, [r0]
	b _080ABDE4
	.pool
_080ABD7C:
	ldr r1, =gUnknown_02038454
	ldr r3, =0x000006c4
	adds r0, r1, r3
	strh r4, [r0]
	cmp r2, 0
	beq _080ABDA0
	ldr r0, =0x000006c7
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	b _080ABDB2
	.pool
_080ABDA0:
	movs r0, 0x1
	negs r0, r0
	lsls r1, r5, 24
	asrs r1, 24
	str r4, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_080ABDB2:
	ldr r4, =gUnknown_02038454
	ldr r1, =0x000006c6
	adds r0, r4, r1
	movs r1, 0
	movs r5, 0x1
	strb r5, [r0]
	ldr r2, =0x000006ca
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, =0x000006cb
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, 0xE6
	lsls r1, 3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r2, 0x68
	adds r1, r4, r2
	ldrb r1, [r1]
	bl sub_80AC124
	movs r3, 0xD9
	lsls r3, 3
	adds r4, r3
	strb r5, [r4]
_080ABDE4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fade_screen

	thumb_func_start sub_80ABDFC
sub_80ABDFC: @ 80ABDFC
	ldr r0, =gUnknown_02038454
	ldr r1, =0x000006c6
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_80ABDFC

	thumb_func_start sub_80ABE18
@ void sub_80ABE18(u8 a1)
sub_80ABE18: @ 80ABE18
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 8
	movs r1, 0x80
	lsls r1, 13
	adds r0, r1
	lsrs r4, r0, 16
	ldr r5, =gUnknown_02038454
	ldr r2, =0x000006c6
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r1, r5, 0
	cmp r0, 0x1
	beq _080ABE60
	cmp r0, 0x2
	beq _080ABEAC
	adds r2, 0xA
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _080ABEE4
	lsls r0, r4, 24
	lsrs r0, 24
	subs r2, 0x10
	adds r1, r2
	movs r2, 0
	ldrsb r2, [r1, r2]
	movs r1, 0x1
	bl pal_fade_2
	b _080ABEF4
	.pool
_080ABE60:
	ldr r2, =0x000006ca
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080ABEF4
	adds r2, 0x6
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _080ABE7C
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80ABBCC
_080ABE7C:
	lsls r0, r4, 20
	lsrs r4, r0, 16
	movs r2, 0
	ldr r6, =gPlttBufferFaded
	ldr r0, =0x000006c4
	adds r3, r5, r0
_080ABE88:
	adds r0, r4, r2
	lsls r0, 1
	adds r0, r6
	ldrh r1, [r3]
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _080ABE88
	b _080ABEF4
	.pool
_080ABEAC:
	lsls r0, r4, 20
	lsrs r4, r0, 16
	lsls r1, r4, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
	ldr r0, =gPaletteFade
	ldrh r2, [r0, 0x4]
	lsls r2, 21
	lsrs r2, 27
	ldrh r3, [r0, 0x6]
	lsls r3, 17
	lsrs r3, 17
	adds r0, r4, 0
	movs r1, 0x10
	bl BlendPalette
	b _080ABEF4
	.pool
_080ABEE4:
	lsls r0, r4, 20
	lsrs r4, r0, 16
	ldr r3, =0x000073fc
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0xC
	bl BlendPalette
_080ABEF4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ABE18

	thumb_func_start sub_80ABF00
sub_80ABF00: @ 80ABF00
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02038454
	movs r2, 0xD8
	lsls r2, 3
	adds r1, r2
	movs r2, 0
	ldrsb r2, [r1, r2]
	movs r1, 0x1
	bl pal_fade_2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ABF00

	thumb_func_start sub_80ABF20
sub_80ABF20: @ 80ABF20
	push {lr}
	ldr r1, =gUnknown_02038454
	ldr r2, =0x000006c6
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080ABF3C
	movs r0, 0
	b _080ABF42
	.pool
_080ABF3C:
	ldr r2, =0x000006ca
	adds r0, r1, r2
	ldrb r0, [r0]
_080ABF42:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80ABF20

	thumb_func_start sub_80ABF4C
sub_80ABF4C: @ 80ABF4C
	push {r4,lr}
	ldr r4, =gUnknown_02038454
	ldr r1, =0x000006d4
	adds r4, r1
	ldrb r1, [r4]
	lsls r1, 20
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	ldrb r0, [r4]
	bl sub_80ABE18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ABF4C

	thumb_func_start sub_80ABF7C
sub_80ABF7C: @ 80ABF7C
	movs r2, 0x20
	strb r2, [r0]
	strb r2, [r1]
	bx lr
	thumb_func_end sub_80ABF7C

	thumb_func_start sub_80ABF84
sub_80ABF84: @ 80ABF84
	ldr r0, =gUnknown_02038454
	ldr r2, =0x0000074d
	adds r1, r0, r2
	movs r2, 0x1
	strb r2, [r1]
	ldr r1, =0x0000074e
	adds r0, r1
	strb r2, [r0]
	bx lr
	.pool
	thumb_func_end sub_80ABF84

	thumb_func_start sub_80ABFA4
sub_80ABFA4: @ 80ABFA4
	push {r4,lr}
	ldr r1, =gUnknown_02038454
	ldr r0, =0x0000074d
	adds r4, r1, r0
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0x1F
	bgt _080ABFD8
	ldr r0, =0x0000074e
	adds r1, r0
	adds r0, r4, 0
	bl sub_80ABF7C
	movs r0, 0
	ldrsb r0, [r4, r0]
	cmp r0, 0x1F
	bgt _080ABFD8
	movs r0, 0x1
	b _080ABFDA
	.pool
_080ABFD8:
	movs r0, 0
_080ABFDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABFA4

	thumb_func_start sub_80ABFE0
sub_80ABFE0: @ 80ABFE0
	push {lr}
	lsls r0, 24
	asrs r0, 24
	mvns r0, r0
	bl sub_80ABC48
	pop {r0}
	bx r0
	thumb_func_end sub_80ABFE0

	thumb_func_start sub_80ABFF0
sub_80ABFF0: @ 80ABFF0
	ldr r1, =gUnknown_02038454
	ldr r2, =0x0000073c
	adds r0, r1, r2
	movs r2, 0
	strh r2, [r0]
	movs r3, 0xE8
	lsls r3, 3
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, 0x2
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =0x0000073e
	adds r1, r0
	strh r2, [r1]
	bx lr
	.pool
	thumb_func_end sub_80ABFF0

	thumb_func_start sub_80AC01C
sub_80AC01C: @ 80AC01C
	push {r4-r7,lr}
	ldr r5, =gUnknown_02038454
	ldr r0, =0x00000742
	adds r7, r5, r0
	movs r2, 0
	ldrsh r1, [r7, r2]
	cmp r1, 0x1
	beq _080AC090
	cmp r1, 0x1
	bgt _080AC040
	cmp r1, 0
	beq _080AC046
	b _080AC118
	.pool
_080AC040:
	cmp r1, 0x2
	beq _080AC0E4
	b _080AC118
_080AC046:
	movs r3, 0xE8
	lsls r3, 3
	adds r6, r5, r3
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080AC118
	strh r1, [r6]
	ldr r0, =0x0000073c
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r1, r0, 0x1
	strh r1, [r4]
	lsls r0, 24
	asrs r0, 24
	bl sub_80ABFE0
	ldrh r1, [r4]
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0x5
	ble _080AC118
	ldr r3, =0x0000073e
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, 0x1
	strh r0, [r7]
	movs r0, 0x3C
	strh r0, [r6]
	b _080AC118
	.pool
_080AC090:
	movs r0, 0xE8
	lsls r0, 3
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, 0x3
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, =gUnknown_08329F40
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r0, 0x1
	asrs r0, 6
	adds r0, 0x2
	ldr r2, =0x0000073c
	adds r6, r5, r2
	adds r2, r0, 0
	strh r0, [r6]
	ldr r3, =0x0000073e
	adds r4, r5, r3
	movs r3, 0
	ldrsh r1, [r4, r3]
	cmp r0, r1
	beq _080AC0D0
	lsls r0, r2, 24
	asrs r0, 24
	bl sub_80ABFE0
_080AC0D0:
	ldrh r0, [r6]
	strh r0, [r4]
	b _080AC118
	.pool
_080AC0E4:
	movs r0, 0xE8
	lsls r0, 3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080AC118
	strh r6, [r1]
	ldr r1, =0x0000073c
	adds r4, r5, r1
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 24
	asrs r0, 24
	bl sub_80ABFE0
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	bne _080AC118
	strh r6, [r7]
_080AC118:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC01C

	thumb_func_start sub_80AC124
sub_80AC124: @ 80AC124
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_02038454
	movs r4, 0xE6
	lsls r4, 3
	adds r2, r3, r4
	strh r0, [r2]
	adds r4, 0x2
	adds r2, r3, r4
	strh r1, [r2]
	adds r4, 0x2
	adds r2, r3, r4
	strh r0, [r2]
	ldr r2, =0x00000736
	adds r3, r2
	strh r1, [r3]
	lsls r1, 8
	orrs r1, r0
	movs r0, 0x52
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC124

	thumb_func_start sub_80AC164
sub_80AC164: @ 80AC164
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_02038454
	ldr r5, =0x00000734
	adds r4, r3, r5
	movs r5, 0
	strh r0, [r4]
	ldr r4, =0x00000736
	adds r0, r3, r4
	strh r1, [r0]
	ldr r1, =0x0000073a
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, 0x3
	adds r0, r3, r4
	strb r5, [r0]
	movs r0, 0xE7
	lsls r0, 3
	adds r3, r0
	strb r5, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC164

	thumb_func_start sub_80AC1A8
sub_80AC1A8: @ 80AC1A8
	push {r4-r6,lr}
	ldr r0, =gUnknown_02038454
	movs r1, 0xE6
	lsls r1, 3
	adds r3, r0, r1
	ldr r2, [r3]
	ldr r6, =0x00000734
	adds r4, r0, r6
	ldr r1, [r4]
	adds r5, r0, 0
	cmp r2, r1
	beq _080AC26C
	ldr r0, =0x00000739
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldr r6, =0x0000073a
	adds r1, r5, r6
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bls _080AC238
	movs r0, 0
	strb r0, [r2]
	movs r0, 0xE7
	lsls r0, 3
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080AC210
	ldrh r1, [r3]
	adds r2, r1, 0
	ldrh r0, [r4]
	cmp r2, r0
	bcs _080AC230
	adds r0, r1, 0x1
	b _080AC236
	.pool
_080AC210:
	ldr r1, =0x00000732
	adds r3, r5, r1
	ldr r2, =0x00000736
	adds r0, r5, r2
	ldrh r1, [r3]
	adds r2, r1, 0
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080AC230
	adds r0, r1, 0x1
	b _080AC236
	.pool
_080AC230:
	cmp r2, r0
	bls _080AC238
	subs r0, r1, 0x1
_080AC236:
	strh r0, [r3]
_080AC238:
	ldr r6, =0x00000732
	adds r0, r5, r6
	ldrh r1, [r0]
	lsls r1, 8
	movs r0, 0xE6
	lsls r0, 3
	adds r4, r5, r0
	ldrh r0, [r4]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, [r4]
	ldr r2, =0x00000734
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	beq _080AC26C
	movs r0, 0
	b _080AC26E
	.pool
_080AC26C:
	movs r0, 0x1
_080AC26E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC1A8

	thumb_func_start sub_80AC274
sub_80AC274: @ 80AC274
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x9
	bhi _080AC306
	lsls r0, 2
	ldr r1, =_080AC290
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AC290:
	.4byte _080AC2B8
	.4byte _080AC2C0
	.4byte _080AC2C8
	.4byte _080AC2D0
	.4byte _080AC2D8
	.4byte _080AC2E0
	.4byte _080AC2E8
	.4byte _080AC2F0
	.4byte _080AC2F8
	.4byte _080AC300
_080AC2B8:
	movs r0, 0x1
	bl sub_80AEDF0
	b _080AC306
_080AC2C0:
	movs r0, 0x2
	bl sub_80AEDF0
	b _080AC306
_080AC2C8:
	movs r0, 0x3
	bl sub_80AEDF0
	b _080AC306
_080AC2D0:
	movs r0, 0x4
	bl sub_80AEDF0
	b _080AC306
_080AC2D8:
	movs r0, 0x5
	bl sub_80AEDF0
	b _080AC306
_080AC2E0:
	movs r0, 0x6
	bl sub_80AEDF0
	b _080AC306
_080AC2E8:
	movs r0, 0x9
	bl sub_80AEDF0
	b _080AC306
_080AC2F0:
	movs r0, 0x7
	bl sub_80AEDF0
	b _080AC306
_080AC2F8:
	movs r0, 0x8
	bl sub_80AEDF0
	b _080AC306
_080AC300:
	movs r0, 0xB
	bl sub_80AEDF0
_080AC306:
	pop {r0}
	bx r0
	thumb_func_end sub_80AC274

	thumb_func_start weather_get_current
weather_get_current: @ 80AC30C
	ldr r0, =gUnknown_02038454
	movs r1, 0xDA
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end weather_get_current

	thumb_func_start sub_80AC31C
sub_80AC31C: @ 80AC31C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gUnknown_02038454
	ldr r3, =0x000006c6
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080AC36E
	cmp r2, 0x53
	beq _080AC354
	cmp r2, 0x53
	bgt _080AC344
	cmp r2, 0x51
	beq _080AC360
	b _080AC36E
	.pool
_080AC344:
	cmp r2, 0x55
	bne _080AC36E
	ldr r0, =0x000006dd
	adds r1, r0
	movs r0, 0
	b _080AC366
	.pool
_080AC354:
	ldr r3, =0x000006dd
	adds r1, r3
	movs r0, 0x1
	b _080AC366
	.pool
_080AC360:
	ldr r0, =0x000006dd
	adds r1, r0
	movs r0, 0x2
_080AC366:
	strb r0, [r1]
	adds r0, r2, 0
	bl audio_play
_080AC36E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC31C

	thumb_func_start play_some_sound
play_some_sound: @ 80AC378
	push {lr}
	bl sub_80A390C
	lsls r0, 24
	cmp r0, 0
	beq _080AC3B6
	ldr r0, =gUnknown_02038454
	ldr r1, =0x000006dd
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080AC3A8
	cmp r0, 0x1
	bgt _080AC3B0
	cmp r0, 0
	bne _080AC3B0
	movs r0, 0x56
	bl audio_play
	b _080AC3B6
	.pool
_080AC3A8:
	movs r0, 0x54
	bl audio_play
	b _080AC3B6
_080AC3B0:
	movs r0, 0x52
	bl audio_play
_080AC3B6:
	pop {r0}
	bx r0
	thumb_func_end play_some_sound

	thumb_func_start sub_80AC3BC
sub_80AC3BC: @ 80AC3BC
	ldr r0, =gUnknown_02038454
	ldr r1, =0x000006d3
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80AC3BC

	thumb_func_start sub_80AC3D0
sub_80AC3D0: @ 80AC3D0
	ldr r0, =gUnknown_02038454
	ldr r1, =0x000006c6
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80AC3D0

	thumb_func_start sub_80AC3E4
sub_80AC3E4: @ 80AC3E4
	ldr r0, =gUnknown_02038454
	ldr r1, =0x000006c6
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80AC3E4

	thumb_func_start sub_80AC3F8
sub_80AC3F8: @ 80AC3F8
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0854C250
	ldr r5, =gUnknown_02038BA4
	adds r1, r5, 0
	movs r2, 0x10
	bl CpuSet
	adds r4, r5
	movs r0, 0
	strb r0, [r4]
	ldr r0, =gUnknown_03000F50
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC3F8

	thumb_func_start sub_80AC428
sub_80AC428: @ 80AC428
	ldr r1, =gUnknown_03000F50
	ldr r0, =gUnknown_0854C250
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80AC428

	thumb_func_start sub_80AC438
sub_80AC438: @ 80AC438
	push {lr}
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r2, =0x000006c1
	adds r1, r0, r2
	movs r2, 0
	strb r2, [r1]
	ldr r1, =0x000006c2
	adds r3, r0, r1
	movs r1, 0x14
	strb r1, [r3]
	ldr r3, =0x000006d2
	adds r1, r0, r3
	strb r2, [r1]
	subs r3, 0x6
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, =0x000006de
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC46C
	movs r0, 0
	movs r1, 0x10
	bl sub_80AC124
_080AC46C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC438

	thumb_func_start sub_80AC484
sub_80AC484: @ 80AC484
	push {r4,lr}
	bl sub_80AC438
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC4A4
	adds r4, r1, r2
_080AC49A:
	bl sub_80AC4B4
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AC49A
_080AC4A4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC484

	thumb_func_start sub_80AC4B4
sub_80AC4B4: @ 80AC4B4
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x000006cc
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080AC4E4
	cmp r0, 0x1
	bgt _080AC4D8
	cmp r0, 0
	beq _080AC4DE
	b _080AC508
	.pool
_080AC4D8:
	cmp r0, 0x2
	beq _080AC4F0
	b _080AC508
_080AC4DE:
	bl sub_80AC594
	b _080AC502
_080AC4E4:
	movs r0, 0xC
	movs r1, 0x8
	movs r2, 0x1
	bl sub_80AC164
	b _080AC502
_080AC4F0:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080AC508
	ldr r0, =0x000006d2
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC502:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080AC508:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC4B4

	thumb_func_start sub_80AC514
sub_80AC514: @ 80AC514
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006ce
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0
	beq _080AC534
	cmp r0, 0x1
	beq _080AC540
	movs r0, 0
	b _080AC556
	.pool
_080AC534:
	movs r0, 0
	movs r1, 0x10
	movs r2, 0x1
	bl sub_80AC164
	b _080AC54E
_080AC540:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080AC554
	bl sub_80AC660
_080AC54E:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080AC554:
	movs r0, 0x1
_080AC556:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC514

	thumb_func_start sub_80AC55C
sub_80AC55C: @ 80AC55C
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006c1
	adds r2, r1, r0
	movs r0, 0
	strb r0, [r2]
	ldr r0, =0x000006c2
	adds r1, r0
	movs r0, 0x14
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80AC55C

	thumb_func_start sub_80AC580
sub_80AC580: @ 80AC580
	push {lr}
	bl sub_80AC55C
	pop {r0}
	bx r0
	thumb_func_end sub_80AC580

	thumb_func_start nullsub_95
nullsub_95: @ 80AC58C
	bx lr
	thumb_func_end nullsub_95

	thumb_func_start sub_80AC590
sub_80AC590: @ 80AC590
	movs r0, 0
	bx lr
	thumb_func_end sub_80AC590

	thumb_func_start sub_80AC594
sub_80AC594: @ 80AC594
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006de
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080AC650
	ldr r0, =gUnknown_0854FB5C
	bl LoadObjectPic
	ldr r0, =gUnknown_0854C290
	bl sub_80ABF4C
	movs r5, 0
_080AC5B2:
	ldr r0, =gUnknown_0854FB78
	movs r1, 0
	movs r2, 0
	movs r3, 0xFF
	bl AddObjectToFront
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _080AC628
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	lsls r2, r5, 2
	movs r0, 0xFA
	lsls r0, 1
	adds r1, r0
	adds r1, r2
	lsls r4, r3, 4
	adds r4, r3
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	str r4, [r1]
	ldr r0, =gUnknown_0854FB50
	adds r2, r0
	ldrh r0, [r2]
	adds r0, 0x7
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r2, 0x2]
	adds r1, 0x7
	lsls r1, 16
	asrs r1, 16
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	bl sub_8093038
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	b _080AC63A
	.pool
_080AC628:
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	lsls r0, r5, 2
	movs r2, 0xFA
	lsls r2, 1
	adds r1, r2
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_080AC63A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x2
	bls _080AC5B2
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006de
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080AC650:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC594

	thumb_func_start sub_80AC660
sub_80AC660: @ 80AC660
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006de
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AC6A4
	movs r4, 0
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r1, r0
_080AC678:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080AC686
	bl RemoveObjectAndFreeTiles
_080AC686:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x2
	bls _080AC678
	movs r0, 0x90
	lsls r0, 5
	bl FreeObjectTilesByTag
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006de
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080AC6A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC660

	thumb_func_start sub_80AC6B4
sub_80AC6B4: @ 80AC6B4
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	movs r1, 0x1
	ands r0, r1
	strh r0, [r2, 0x2E]
	cmp r0, 0
	beq _080AC6CC
	ldrh r0, [r2, 0x20]
	subs r0, 0x1
	strh r0, [r2, 0x20]
_080AC6CC:
	pop {r0}
	bx r0
	thumb_func_end sub_80AC6B4

	thumb_func_start sub_80AC6D0
sub_80AC6D0: @ 80AC6D0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006cc
	adds r3, r1, r0
	movs r2, 0
	movs r0, 0
	strh r0, [r3]
	ldr r3, =0x000006d2
	adds r0, r1, r3
	strb r2, [r0]
	subs r3, 0x11
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, =0x000006c2
	adds r1, r0
	strb r2, [r1]
	bx lr
	.pool
	thumb_func_end sub_80AC6D0

	thumb_func_start sub_80AC704
sub_80AC704: @ 80AC704
	push {r4,lr}
	bl sub_80AC6D0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC724
	adds r4, r1, r2
_080AC71A:
	bl sub_80AC734
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AC71A
_080AC724:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC704

	thumb_func_start sub_80AC734
sub_80AC734: @ 80AC734
	push {lr}
	ldr r1, =gUnknown_0854C14C
	ldr r0, [r1]
	ldr r2, =0x000006cc
	adds r0, r2
	ldrh r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _080AC810
	lsls r0, 2
	ldr r1, =_080AC75C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AC75C:
	.4byte _080AC770
	.4byte _080AC78C
	.4byte _080AC7A4
	.4byte _080AC7C0
	.4byte _080AC7D8
_080AC770:
	ldr r1, [r2]
	ldr r2, =0x000006c6
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AC814
	ldr r0, =0x000006cc
	adds r1, r0
	b _080AC7F8
	.pool
_080AC78C:
	bl sub_80ABF84
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r1, r2
	b _080AC7F8
	.pool
_080AC7A4:
	bl sub_80ABFA4
	lsls r0, 24
	cmp r0, 0
	bne _080AC814
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006cc
	adds r1, r0
	b _080AC7F8
	.pool
_080AC7C0:
	bl sub_80ABFF0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r1, r2
	b _080AC7F8
	.pool
_080AC7D8:
	bl sub_80AC01C
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r1, =0x0000073c
	adds r0, r2, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	bne _080AC814
	ldr r0, =0x000006d2
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x000006cc
	adds r1, r2, r0
_080AC7F8:
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _080AC814
	.pool
_080AC810:
	bl sub_80AC01C
_080AC814:
	pop {r0}
	bx r0
	thumb_func_end sub_80AC734

	thumb_func_start sub_80AC818
sub_80AC818: @ 80AC818
	movs r0, 0
	bx lr
	thumb_func_end sub_80AC818

	thumb_func_start sub_80AC81C
sub_80AC81C: @ 80AC81C
	push {lr}
	ldr r0, =task50_0807B6D4
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC81C

	thumb_func_start task50_0807B6D4
task50_0807B6D4: @ 80AC830
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _080AC922
	lsls r0, 2
	ldr r1, =_080AC85C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AC85C:
	.4byte _080AC870
	.4byte _080AC89A
	.4byte _080AC8C8
	.4byte _080AC8F8
	.4byte _080AC918
_080AC870:
	movs r0, 0
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	ldr r0, =0x04000048
	ldrh r0, [r0]
	strh r0, [r4, 0xE]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0x9E
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080AC89A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x3
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _080AC8AC
	movs r0, 0x10
	strh r0, [r4, 0xA]
_080AC8AC:
	ldrh r1, [r4, 0xA]
	movs r0, 0x54
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	ble _080AC922
	b _080AC910
	.pool
_080AC8C8:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	ble _080AC922
	strh r1, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bgt _080AC8EE
	strh r1, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080AC8EE:
	ldrh r1, [r4, 0xA]
	movs r0, 0x54
	bl SetGpuReg
	b _080AC922
_080AC8F8:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4, 0xE]
	movs r0, 0x48
	bl SetGpuReg
_080AC910:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080AC922
_080AC918:
	bl script_env_2_enable_and_set_ctx_running
	adds r0, r5, 0
	bl DestroyTask
_080AC922:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task50_0807B6D4

	thumb_func_start sub_80AC928
sub_80AC928: @ 80AC928
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r0, r1, r2
	movs r3, 0
	movs r2, 0
	strh r2, [r0]
	ldr r4, =0x000006d2
	adds r0, r1, r4
	strb r3, [r0]
	adds r4, 0x4
	adds r0, r1, r4
	strh r2, [r0]
	ldr r0, =0x000006db
	adds r2, r1, r0
	movs r0, 0x8
	strb r0, [r2]
	ldr r2, =0x000006dc
	adds r0, r1, r2
	strb r3, [r0]
	adds r4, 0x3
	adds r2, r1, r4
	movs r0, 0xA
	strb r0, [r2]
	ldr r0, =0x000006c1
	adds r2, r1, r0
	movs r0, 0x3
	strb r0, [r2]
	ldr r2, =0x000006c2
	adds r1, r2
	movs r0, 0x14
	strb r0, [r1]
	movs r0, 0x55
	bl sub_80AC31C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC928

	thumb_func_start sub_80AC994
sub_80AC994: @ 80AC994
	push {r4,lr}
	bl sub_80AC928
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC9B4
	adds r4, r1, r2
_080AC9AA:
	bl sub_80AC9C4
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AC9AA
_080AC9B4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC994

	thumb_func_start sub_80AC9C4
sub_80AC9C4: @ 80AC9C4
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x000006cc
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080AC9F4
	cmp r0, 0x1
	bgt _080AC9E8
	cmp r0, 0
	beq _080AC9EE
	b _080ACA18
	.pool
_080AC9E8:
	cmp r0, 0x2
	beq _080ACA00
	b _080ACA18
_080AC9EE:
	bl sub_80ACD68
	b _080ACA12
_080AC9F4:
	bl sub_80ACD78
	lsls r0, 24
	cmp r0, 0
	bne _080ACA18
	b _080ACA12
_080ACA00:
	bl sub_80ACEAC
	lsls r0, 24
	cmp r0, 0
	bne _080ACA18
	ldr r0, =0x000006d2
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080ACA12:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080ACA18:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AC9C4

	thumb_func_start sub_80ACA24
sub_80ACA24: @ 80ACA24
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r1, =0x000006ce
	adds r3, r2, r1
	ldrh r1, [r3]
	adds r4, r0, 0
	cmp r1, 0
	beq _080ACA48
	cmp r1, 0x1
	beq _080ACA7C
	movs r0, 0
	b _080ACAAA
	.pool
_080ACA48:
	ldr r5, =0x000006d1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080ACA5A
	cmp r0, 0x5
	beq _080ACA5A
	cmp r0, 0xD
	bne _080ACA70
_080ACA5A:
	ldr r0, [r4]
	ldr r1, =0x000006ce
	adds r0, r1
	movs r1, 0xFF
	strh r1, [r0]
	movs r0, 0
	b _080ACAAA
	.pool
_080ACA70:
	ldr r4, =0x000006d9
	adds r0, r2, r4
	strb r1, [r0]
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
_080ACA7C:
	bl sub_80ACEAC
	lsls r0, 24
	cmp r0, 0
	bne _080ACAA8
	bl sub_80ACF38
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r5, =0x000006ce
	adds r1, r5
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0
	b _080ACAAA
	.pool
_080ACAA8:
	movs r0, 0x1
_080ACAAA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACA24

	thumb_func_start sub_80ACAB0
sub_80ACAB0: @ 80ACAB0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _080ACAC4
	ldr r0, =0x00000169
	strh r0, [r7, 0x30]
_080ACAC4:
	movs r2, 0x30
	ldrsh r1, [r7, r2]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r3, =0x00003039
	adds r0, r3
	lsls r0, 1
	lsrs r0, 17
	movs r1, 0x96
	lsls r1, 2
	bl __umodsi3
	movs r1, 0
	mov r8, r1
	strh r0, [r7, 0x30]
	ldr r1, =gUnknown_0854FC4C
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r2, =0x000006dc
	adds r5, r2
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldrh r6, [r0]
	movs r3, 0x30
	ldrsh r0, [r7, r3]
	movs r1, 0x1E
	bl __modsi3
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r0, r4, 3
	strh r0, [r7, 0x32]
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	movs r1, 0x1E
	bl __divsi3
	lsls r0, 16
	lsls r4, 7
	strh r4, [r7, 0x32]
	asrs r0, 9
	strh r0, [r7, 0x34]
	ldr r2, =gUnknown_0854FC44
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r1, r6
	subs r4, r1
	strh r4, [r7, 0x32]
	ldrb r1, [r5]
	lsls r1, 2
	adds r2, 0x2
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	muls r1, r6
	subs r0, r1
	strh r0, [r7, 0x34]
	adds r0, r7, 0
	movs r1, 0
	bl StartObjectImageAnim
	mov r3, r8
	strh r3, [r7, 0x36]
	adds r2, r7, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	strh r6, [r7, 0x2E]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ACAB0

	thumb_func_start sub_80ACB84
sub_80ACB84: @ 80ACB84
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080ACC60
	ldr r3, =gUnknown_0854FC44
	ldr r4, =gUnknown_0854C14C
	ldr r2, [r4]
	ldr r0, =0x000006dc
	adds r2, r0
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0]
	ldrh r0, [r5, 0x32]
	adds r1, r0
	strh r1, [r5, 0x32]
	ldrb r0, [r2]
	lsls r0, 2
	adds r3, 0x2
	adds r0, r3
	ldrh r0, [r0]
	ldrh r2, [r5, 0x34]
	adds r0, r2
	strh r0, [r5, 0x34]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r5, 0x20]
	lsls r0, 16
	asrs r2, r0, 20
	strh r2, [r5, 0x22]
	movs r3, 0x38
	ldrsh r0, [r5, r3]
	adds r3, r4, 0
	cmp r0, 0
	beq _080ACC04
	adds r0, r1, 0
	adds r0, 0x8
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 17
	cmp r0, r1
	bhi _080ACC04
	adds r1, r2, 0
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	blt _080ACC04
	cmp r1, 0xB0
	bgt _080ACC04
	adds r0, r5, 0
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _080ACC0E
	.pool
_080ACC04:
	adds r0, r5, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_080ACC0E:
	strb r1, [r0]
	adds r4, r0, 0
	ldrh r0, [r5, 0x2E]
	subs r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _080ACC80
	ldr r0, [r3]
	ldr r1, =0x000006dc
	adds r0, r1
	ldrb r1, [r0]
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartObjectImageAnim
	movs r0, 0x1
	strh r0, [r5, 0x36]
	ldr r1, =gUnknown_02021BBC
	ldrh r0, [r5, 0x20]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r5, 0x20]
	ldr r1, =gUnknown_02021BBE
	ldrh r0, [r5, 0x22]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	b _080ACC80
	.pool
_080ACC60:
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080ACC80
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_80ACAB0
_080ACC80:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80ACB84

	thumb_func_start sub_80ACC88
sub_80ACC88: @ 80ACC88
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080ACCA8
	adds r0, r4, 0
	bl sub_80ACAB0
	ldr r0, =sub_80ACB84
	str r0, [r4, 0x1C]
	b _080ACCAC
	.pool
_080ACCA8:
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
_080ACCAC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80ACC88

	thumb_func_start sub_80ACCB4
sub_80ACCB4: @ 80ACCB4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	lsls r5, r1, 16
	lsrs r5, 16
	ldr r2, =gUnknown_0854FC4C
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006dc
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0, r2
	ldrh r1, [r1]
	mov r8, r1
	adds r2, 0x2
	adds r0, r2
	ldrh r4, [r0]
	add r4, r8
	adds r0, r5, 0
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 16
	lsrs r4, r0, 16
	subs r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x0000ffff
	cmp r6, r0
	beq _080ACD12
	adds r5, r0, 0
_080ACD02:
	adds r0, r7, 0
	bl sub_80ACAB0
	subs r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r5
	bne _080ACD02
_080ACD12:
	cmp r4, r8
	bcs _080ACD48
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _080ACD34
	adds r5, r0, 0
_080ACD24:
	adds r0, r7, 0
	bl sub_80ACB84
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r5
	bne _080ACD24
_080ACD34:
	movs r0, 0
	b _080ACD5C
	.pool
_080ACD48:
	mov r1, r8
	subs r0, r4, r1
	strh r0, [r7, 0x2E]
	adds r2, r7, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
_080ACD5C:
	strh r0, [r7, 0x3A]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80ACCB4

	thumb_func_start sub_80ACD68
sub_80ACD68: @ 80ACD68
	push {lr}
	ldr r0, =gUnknown_0854FC54
	bl LoadObjectPic
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ACD68

	thumb_func_start sub_80ACD78
sub_80ACD78: @ 80ACD78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r0, =0x000006da
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, 0x18
	bne _080ACD92
	b _080ACE98
_080ACD92:
	ldrb r7, [r2]
	ldr r0, =gUnknown_0854FC2C
	ldr r2, =gUnknown_0854FB90
	lsls r6, r7, 2
	adds r2, r6, r2
	movs r3, 0
	ldrsh r1, [r2, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	movs r3, 0x4E
	bl AddObjectToBack
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _080ACE40
	ldr r3, =gUnknown_02020630
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r3
	movs r0, 0
	strh r0, [r1, 0x38]
	lsls r2, r7, 3
	adds r0, r2, r7
	lsls r0, 4
	adds r0, r7
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	ldr r1, =0x00000257
	mov r10, r6
	mov r9, r3
	mov r12, r4
	mov r8, r2
	cmp r0, r1
	ble _080ACDF6
	adds r2, r1, 0
_080ACDDE:
	adds r0, r4, r5
	lsls r0, 2
	ldr r6, =gUnknown_02020630
	adds r0, r6
	ldr r3, =0xfffffda8
	ldrh r6, [r0, 0x30]
	adds r1, r3, r6
	strh r1, [r0, 0x30]
	lsls r1, 16
	asrs r1, 16
	cmp r1, r2
	bgt _080ACDDE
_080ACDF6:
	mov r0, r12
	adds r4, r0, r5
	lsls r4, 2
	add r4, r9
	adds r0, r4, 0
	bl sub_80ACAB0
	mov r3, r8
	adds r1, r3, r7
	adds r0, r4, 0
	bl sub_80ACCB4
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	add r0, r10
	str r4, [r0]
	b _080ACE46
	.pool
_080ACE40:
	adds r1, r4, r6
	movs r0, 0
	str r0, [r1]
_080ACE46:
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r6, =0x000006da
	adds r1, r2, r6
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x18
	bne _080ACE9C
	movs r3, 0
	adds r1, r2, 0
	ldr r5, =sub_80ACB84
	ldr r4, =sub_80ACC88
_080ACE64:
	lsls r0, r3, 2
	adds r0, r1, r0
	ldr r2, [r0]
	cmp r2, 0
	beq _080ACE8E
	movs r6, 0x3A
	ldrsh r0, [r2, r6]
	cmp r0, 0
	bne _080ACE8C
	str r5, [r2, 0x1C]
	b _080ACE8E
	.pool
_080ACE8C:
	str r4, [r2, 0x1C]
_080ACE8E:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x17
	bls _080ACE64
_080ACE98:
	movs r0, 0
	b _080ACE9E
_080ACE9C:
	movs r0, 0x1
_080ACE9E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACD78

	thumb_func_start sub_80ACEAC
sub_80ACEAC: @ 80ACEAC
	push {r4-r7,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r3, [r0]
	movs r0, 0xDB
	lsls r0, 3
	adds r4, r3, r0
	ldr r1, =0x000006d9
	adds r5, r3, r1
	ldrb r0, [r4]
	ldrb r7, [r5]
	cmp r0, r7
	bne _080ACED0
	movs r0, 0
	b _080ACF32
	.pool
_080ACED0:
	ldr r0, =0x000006d6
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r2]
	ldr r7, =0x000006db
	adds r1, r3, r7
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1]
	cmp r0, r1
	bls _080ACF30
	strh r6, [r2]
	ldrb r0, [r4]
	adds r1, r0, 0
	ldrb r5, [r5]
	cmp r1, r5
	bcs _080ACF10
	adds r0, 0x1
	strb r0, [r4]
	lsls r0, r1, 2
	adds r0, r3, r0
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x38]
	b _080ACF30
	.pool
_080ACF10:
	subs r0, 0x1
	strb r0, [r4]
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r3, r0
	ldr r0, [r0]
	strh r6, [r0, 0x38]
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
_080ACF30:
	movs r0, 0x1
_080ACF32:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACEAC

	thumb_func_start sub_80ACF38
sub_80ACF38: @ 80ACF38
	push {r4-r7,lr}
	movs r4, 0
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r3, =0x000006da
	adds r1, r2, r3
	adds r7, r0, 0
	ldrb r1, [r1]
	cmp r4, r1
	bcs _080ACF6A
	adds r5, r2, 0
	adds r6, r5, r3
_080ACF50:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080ACF5E
	bl RemoveObjectAndFreeTiles
_080ACF5E:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r0, [r6]
	cmp r4, r0
	bcc _080ACF50
_080ACF6A:
	ldr r0, [r7]
	ldr r1, =0x000006da
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, =0x00001206
	bl FreeObjectTilesByTag
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ACF38

	thumb_func_start sub_80ACF8C
sub_80ACF8C: @ 80ACF8C
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r0, r1, r2
	movs r2, 0
	movs r3, 0
	strh r3, [r0]
	ldr r4, =0x000006d2
	adds r0, r1, r4
	strb r2, [r0]
	ldr r0, =0x000006c1
	adds r2, r1, r0
	movs r0, 0x3
	strb r0, [r2]
	subs r4, 0x10
	adds r2, r1, r4
	movs r0, 0x14
	strb r0, [r2]
	ldr r0, =0x000006e5
	adds r2, r1, r0
	movs r0, 0x10
	strb r0, [r2]
	movs r2, 0xDC
	lsls r2, 3
	adds r1, r2
	strh r3, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ACF8C

	thumb_func_start sub_80ACFDC
sub_80ACFDC: @ 80ACFDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_80ACF8C
	ldr r2, =gUnknown_0854C14C
	ldr r1, [r2]
	ldr r3, =0x000006d2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD032
	mov r8, r2
	adds r7, r1, r3
_080ACFF8:
	bl snowflakes_progress2
	movs r4, 0
	mov r1, r8
	ldr r0, [r1]
	ldr r3, =0x000006e4
	adds r0, r3
	ldrb r0, [r0]
	cmp r4, r0
	bcs _080AD02C
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	adds r6, r5, r3
_080AD012:
	lsls r1, r4, 2
	adds r0, r5, 0
	adds r0, 0x60
	adds r0, r1
	ldr r0, [r0]
	bl sub_80AD30C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r0, [r6]
	cmp r4, r0
	bcc _080AD012
_080AD02C:
	ldrb r0, [r7]
	cmp r0, 0
	beq _080ACFF8
_080AD032:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ACFDC

	thumb_func_start snowflakes_progress2
snowflakes_progress2: @ 80AD048
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x000006cc
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, 0
	bne _080AD070
	bl snowflakes_progress
	lsls r0, 24
	cmp r0, 0
	bne _080AD070
	ldr r0, =0x000006d2
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080AD070:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end snowflakes_progress2

	thumb_func_start sub_80AD084
sub_80AD084: @ 80AD084
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r0, =0x000006ce
	adds r3, r2, r0
	ldrh r1, [r3]
	cmp r1, 0
	beq _080AD0A4
	cmp r1, 0x1
	beq _080AD0B6
	movs r0, 0
	b _080AD0E2
	.pool
_080AD0A4:
	ldr r4, =0x000006e5
	adds r0, r2, r4
	strb r1, [r0]
	subs r4, 0x5
	adds r0, r2, r4
	strh r1, [r0]
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
_080AD0B6:
	bl snowflakes_progress
	lsls r0, 24
	cmp r0, 0
	bne _080AD0E0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006ce
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0
	b _080AD0E2
	.pool
_080AD0E0:
	movs r0, 0x1
_080AD0E2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD084

	thumb_func_start snowflakes_progress
snowflakes_progress: @ 80AD0E8
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006e4
	adds r3, r1, r0
	ldr r4, =0x000006e5
	adds r2, r1, r4
	ldrb r0, [r3]
	ldrb r4, [r2]
	cmp r0, r4
	bne _080AD110
	movs r0, 0
	b _080AD152
	.pool
_080AD110:
	movs r0, 0xDC
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x24
	bls _080AD13A
	movs r0, 0
	strh r0, [r1]
	ldrb r0, [r3]
	ldrb r2, [r2]
	cmp r0, r2
	bcs _080AD136
	bl snowflake_add
	b _080AD13A
_080AD136:
	bl snowflake_remove
_080AD13A:
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r2, =0x000006e4
	adds r1, r0, r2
	ldr r4, =0x000006e5
	adds r0, r4
	ldrb r1, [r1]
	ldrb r0, [r0]
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080AD152:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end snowflakes_progress

	thumb_func_start snowflake_add
snowflake_add: @ 80AD164
	push {r4-r6,lr}
	ldr r0, =gUnknown_0854FC8C
	movs r1, 0
	movs r2, 0
	movs r3, 0x4E
	bl AddObjectToBack
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080AD1C8
	ldr r0, =gUnknown_02020630
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r4, r0
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x000006e4
	adds r6, r5, r0
	ldrb r0, [r6]
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_80AD204
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6]
	adds r1, r0, 0x1
	strb r1, [r6]
	lsls r0, 24
	lsrs r0, 22
	adds r5, 0x60
	adds r5, r0
	str r4, [r5]
	movs r0, 0x1
	b _080AD1CA
	.pool
_080AD1C8:
	movs r0, 0
_080AD1CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end snowflake_add

	thumb_func_start snowflake_remove
snowflake_remove: @ 80AD1D0
	push {lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006e4
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0
	bne _080AD1EC
	movs r0, 0
	b _080AD200
	.pool
_080AD1EC:
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 22
	adds r1, 0x60
	adds r1, r0
	ldr r0, [r1]
	bl RemoveObjectAndFreeTiles
	movs r0, 0x1
_080AD200:
	pop {r1}
	bx r1
	thumb_func_end snowflake_remove

	thumb_func_start sub_80AD204
sub_80AD204: @ 80AD204
	push {r4-r7,lr}
	adds r5, r0, 0
	bl GenerateRandomNumber
	movs r1, 0x36
	ldrsh r2, [r5, r1]
	lsls r1, r2, 2
	adds r1, r2
	movs r2, 0x7
	ands r1, r2
	lsls r4, r1, 4
	subs r4, r1
	lsls r4, 1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	ldr r1, =gUnknown_02021BBE
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r1]
	adds r0, r1
	movs r2, 0x3
	negs r2, r2
	adds r1, r2, 0
	subs r1, r0
	movs r7, 0
	strh r1, [r5, 0x22]
	ldr r1, =gUnknown_02021BBC
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r1]
	adds r0, r1
	subs r4, r0
	strh r4, [r5, 0x20]
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	lsls r0, 7
	strh r0, [r5, 0x2E]
	strh r7, [r5, 0x24]
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	adds r6, r0, 0
	movs r4, 0x3
	ands r4, r6
	lsls r0, r4, 2
	adds r0, r4
	adds r0, 0x40
	strh r0, [r5, 0x30]
	strh r0, [r5, 0x3C]
	movs r1, 0x1
	bics r1, r6
	adds r0, r5, 0
	bl StartObjectImageAnim
	strh r7, [r5, 0x34]
	movs r0, 0x1
	cmp r4, 0
	bne _080AD294
	movs r0, 0x2
_080AD294:
	strh r0, [r5, 0x32]
	movs r0, 0x1F
	ands r0, r6
	adds r0, 0xD2
	strh r0, [r5, 0x3A]
	strh r7, [r5, 0x38]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD204

	thumb_func_start sub_80AD2B0
sub_80AD2B0: @ 80AD2B0
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006e2
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0x12
	bls _080AD2F6
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =sub_80AD30C
	str r0, [r3, 0x1C]
	ldr r1, =gUnknown_02021BBE
	adds r0, r3, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r1]
	adds r0, r1
	movs r1, 0xFA
	subs r1, r0
	movs r2, 0
	strh r1, [r3, 0x22]
	movs r1, 0x22
	ldrsh r0, [r3, r1]
	lsls r0, 7
	strh r0, [r3, 0x2E]
	strh r2, [r4]
_080AD2F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD2B0

	thumb_func_start sub_80AD30C
sub_80AD30C: @ 80AD30C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x2E]
	adds r0, r1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 23
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x34]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	ldr r1, =gUnknown_08329F40
	movs r3, 0x34
	ldrsh r0, [r4, r3]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080AD33E
	adds r0, 0x3F
_080AD33E:
	asrs r0, 6
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	adds r0, 0x28
	movs r5, 0
	ldrsb r5, [r0, r5]
	ldrh r0, [r4, 0x20]
	adds r0, r5
	ldr r1, =gUnknown_02021BBC
	ldrh r1, [r1]
	adds r3, r1, r0
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r3, r0
	adds r2, r3, 0
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _080AD370
	ldr r3, =0xffffff00
	adds r0, r3, 0
	orrs r2, r0
	lsls r0, r2, 16
	lsrs r3, r0, 16
_080AD370:
	lsls r0, r3, 16
	asrs r0, 16
	movs r2, 0x3
	negs r2, r2
	cmp r0, r2
	bge _080AD394
	adds r1, r5
	movs r0, 0xF2
	subs r0, r1
	b _080AD39C
	.pool
_080AD394:
	cmp r0, 0xF2
	ble _080AD39E
	adds r0, r1, r5
	subs r0, r2, r0
_080AD39C:
	strh r0, [r4, 0x20]
_080AD39E:
	adds r0, r4, 0
	adds r0, 0x29
	movs r3, 0
	ldrsb r3, [r0, r3]
	ldrh r0, [r4, 0x22]
	adds r0, r3
	ldr r1, =gUnknown_02021BBE
	ldrh r1, [r1]
	adds r2, r1, r0
	movs r0, 0xFF
	ands r2, r0
	adds r0, r2, 0
	subs r0, 0xA4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bhi _080AD3E0
	adds r1, r3
	movs r0, 0xFA
	subs r0, r1
	movs r1, 0
	strh r0, [r4, 0x22]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	lsls r0, 7
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x38]
	movs r0, 0xDC
	strh r0, [r4, 0x3A]
	b _080AD40C
	.pool
_080AD3E0:
	adds r0, r2, 0
	subs r0, 0xF3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bhi _080AD40C
	movs r1, 0
	movs r0, 0xA3
	strh r0, [r4, 0x22]
	lsls r0, 7
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x38]
	movs r0, 0xDC
	strh r0, [r4, 0x3A]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_80AD2B0
	str r0, [r4, 0x1C]
_080AD40C:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x3A
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _080AD438
	adds r0, r4, 0
	bl sub_80AD204
	movs r0, 0xFA
	strh r0, [r4, 0x22]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_80AD2B0
	str r0, [r4, 0x1C]
_080AD438:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD30C

	thumb_func_start sub_80AD444
sub_80AD444: @ 80AD444
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r0, r1, r2
	movs r3, 0
	movs r2, 0
	strh r2, [r0]
	ldr r5, =0x000006d2
	adds r4, r1, r5
	strb r3, [r4]
	adds r5, 0x4
	adds r0, r1, r5
	strh r2, [r0]
	ldr r0, =0x000006db
	adds r2, r1, r0
	movs r0, 0x4
	strb r0, [r2]
	ldr r2, =0x000006dc
	adds r0, r1, r2
	strb r3, [r0]
	adds r5, 0x3
	adds r2, r1, r5
	movs r0, 0x10
	strb r0, [r2]
	ldr r0, =0x000006c1
	adds r2, r1, r0
	movs r0, 0x3
	strb r0, [r2]
	subs r5, 0x17
	adds r2, r1, r5
	movs r0, 0x14
	strb r0, [r2]
	strb r3, [r4]
	ldr r0, =0x000006ed
	adds r1, r0
	strb r3, [r1]
	movs r0, 0x51
	bl sub_80AC31C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD444

	thumb_func_start sub_80AD4B8
sub_80AD4B8: @ 80AD4B8
	push {r4,lr}
	bl sub_80AD444
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD4D8
	adds r4, r1, r2
_080AD4CE:
	bl sub_80AD584
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AD4CE
_080AD4D8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD4B8

	thumb_func_start sub_80AD4E8
sub_80AD4E8: @ 80AD4E8
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r0, r1, r2
	movs r4, 0
	movs r2, 0
	strh r2, [r0]
	ldr r5, =0x000006d2
	adds r3, r1, r5
	strb r4, [r3]
	adds r5, 0x4
	adds r0, r1, r5
	strh r2, [r0]
	ldr r0, =0x000006db
	adds r2, r1, r0
	movs r0, 0x4
	strb r0, [r2]
	adds r5, 0x6
	adds r2, r1, r5
	movs r0, 0x1
	strb r0, [r2]
	ldr r0, =0x000006d9
	adds r2, r1, r0
	movs r0, 0x18
	strb r0, [r2]
	subs r5, 0x1B
	adds r2, r1, r5
	movs r0, 0x3
	strb r0, [r2]
	ldr r0, =0x000006c2
	adds r1, r0
	movs r0, 0x14
	strb r0, [r1]
	strb r4, [r3]
	movs r0, 0x53
	bl sub_80AC31C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD4E8

	thumb_func_start sub_80AD554
sub_80AD554: @ 80AD554
	push {r4,lr}
	bl sub_80AD4E8
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD574
	adds r4, r1, r2
_080AD56A:
	bl sub_80AD584
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AD56A
_080AD574:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD554

	thumb_func_start sub_80AD584
sub_80AD584: @ 80AD584
	push {r4,r5,lr}
	bl sub_80AD9F8
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006cc
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0xE
	bls _080AD59A
	b _080AD8FA
_080AD59A:
	lsls r0, 2
	ldr r1, =_080AD5B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AD5B0:
	.4byte _080AD5EC
	.4byte _080AD608
	.4byte _080AD62C
	.4byte _080AD65C
	.4byte _080AD680
	.4byte _080AD6B0
	.4byte _080AD6E0
	.4byte _080AD70C
	.4byte _080AD72A
	.4byte _080AD788
	.4byte _080AD80C
	.4byte _080AD834
	.4byte _080AD864
	.4byte _080AD8A8
	.4byte _080AD8DC
_080AD5EC:
	bl sub_80ACD68
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006cc
	adds r1, r2
	ldrh r0, [r1]
	adds r0, 0x1
	b _080AD8F8
	.pool
_080AD608:
	bl sub_80ACD78
	lsls r0, 24
	cmp r0, 0
	beq _080AD614
	b _080AD8FA
_080AD614:
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r3, =0x000006cc
	adds r1, r3
	ldrh r0, [r1]
	adds r0, 0x1
	b _080AD8F8
	.pool
_080AD62C:
	bl sub_80ACEAC
	lsls r0, 24
	cmp r0, 0
	beq _080AD638
	b _080AD8FA
_080AD638:
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006d2
	adds r2, r1, r0
	movs r0, 0x1
	strb r0, [r2]
	ldr r2, =0x000006cc
	adds r1, r2
	ldrh r0, [r1]
	adds r0, 0x1
	b _080AD8F8
	.pool
_080AD65C:
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r3, =0x000006c6
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD66C
	b _080AD8FA
_080AD66C:
	ldr r0, =0x000006cc
	adds r1, r0
	movs r0, 0x6
	b _080AD8F8
	.pool
_080AD680:
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r2, =0x000006ea
	adds r1, r4, r2
	movs r0, 0x1
	strb r0, [r1]
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r5, 0xB4
	lsls r5, 1
	adds r1, r5, 0
	bl __umodsi3
	adds r0, r5
	ldr r3, =0x000006e6
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, =0x000006cc
	adds r4, r0
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080AD6B0:
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r3, =0x000006e6
	adds r1, r2, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _080AD6C6
	b _080AD8FA
_080AD6C6:
	ldr r0, =0x000006cc
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	b _080AD8F8
	.pool
_080AD6E0:
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r1, =0x000006ea
	adds r0, r4, r1
	movs r5, 0x1
	strb r5, [r0]
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	ands r0, r5
	ldr r2, =0x000006eb
	adds r1, r4, r2
	strb r0, [r1]
	b _080AD768
	.pool
_080AD70C:
	bl GenerateRandomNumber
	ldr r1, =gUnknown_0854C14C
	ldr r2, [r1]
	movs r1, 0x1
	ands r1, r0
	adds r1, 0x1
	ldr r3, =0x000006ec
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, =0x000006cc
	adds r2, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
_080AD72A:
	movs r0, 0x13
	bl sub_80ABC48
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006eb
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD74E
	ldr r3, =0x000006ec
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080AD74E
	movs r0, 0x14
	bl sub_80AD9BC
_080AD74E:
	bl GenerateRandomNumber
	ldr r1, =gUnknown_0854C14C
	ldr r4, [r1]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r0, 0x6
	ldr r2, =0x000006e6
	adds r1, r4, r2
	strh r0, [r1]
_080AD768:
	ldr r3, =0x000006cc
	adds r4, r3
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080AD8FA
	.pool
_080AD788:
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r0, =0x000006e6
	adds r5, r4, r0
	ldrh r0, [r5]
	subs r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	cmp r0, 0
	beq _080AD79E
	b _080AD8FA
_080AD79E:
	movs r0, 0x3
	bl sub_80ABC48
	ldr r2, =0x000006ea
	adds r1, r4, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r3, =0x000006ec
	adds r1, r4, r3
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	beq _080AD7E8
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	ands r0, r1
	adds r0, 0x3C
	strh r0, [r5]
	ldr r0, =0x000006cc
	adds r1, r4, r0
	movs r0, 0xA
	b _080AD8F8
	.pool
_080AD7E8:
	ldr r1, =0x000006eb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD800
	ldr r2, =0x000006cc
	adds r1, r4, r2
	b _080AD8F6
	.pool
_080AD800:
	ldr r3, =0x000006cc
	adds r1, r4, r3
	movs r0, 0xB
	b _080AD8F8
	.pool
_080AD80C:
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r0, =0x000006e6
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _080AD8FA
	ldr r3, =0x000006cc
	adds r1, r2, r3
	movs r0, 0x8
	b _080AD8F8
	.pool
_080AD834:
	bl GenerateRandomNumber
	ldr r1, =gUnknown_0854C14C
	ldr r2, [r1]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	ands r0, r1
	adds r0, 0x3C
	ldr r3, =0x000006e6
	adds r1, r2, r3
	strh r0, [r1]
	ldr r0, =0x000006cc
	adds r2, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _080AD8FA
	.pool
_080AD864:
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r1, =0x000006e6
	adds r4, r5, r1
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	bne _080AD8FA
	movs r0, 0x64
	bl sub_80AD9BC
	movs r0, 0x13
	bl sub_80ABC48
	bl GenerateRandomNumber
	movs r1, 0xF
	ands r1, r0
	adds r1, 0x1E
	strh r1, [r4]
	ldr r2, =0x000006cc
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, 0x1
	b _080AD8F8
	.pool
_080AD8A8:
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r3, =0x000006e6
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _080AD8FA
	movs r0, 0x13
	movs r1, 0x3
	movs r2, 0x5
	bl sub_80ABC7C
	ldr r0, =0x000006cc
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, 0x1
	b _080AD8F8
	.pool
_080AD8DC:
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r1, =0x000006c6
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _080AD8FA
	ldr r3, =0x000006ea
	adds r1, r2, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x000006cc
	adds r1, r2, r0
_080AD8F6:
	movs r0, 0x4
_080AD8F8:
	strh r0, [r1]
_080AD8FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD584

	thumb_func_start sub_80AD910
sub_80AD910: @ 80AD910
	push {r4-r6,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r6, [r0]
	ldr r0, =0x000006ce
	adds r5, r6, r0
	ldrh r1, [r5]
	cmp r1, 0x1
	beq _080AD946
	cmp r1, 0x1
	bgt _080AD934
	cmp r1, 0
	beq _080AD93A
	b _080AD9AC
	.pool
_080AD934:
	cmp r1, 0x2
	beq _080AD990
	b _080AD9AC
_080AD93A:
	ldr r2, =0x000006ea
	adds r0, r6, r2
	strb r1, [r0]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_080AD946:
	bl sub_80AD584
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r1, =0x000006ea
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AD9B4
	subs r1, 0x19
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080AD9AC
	cmp r0, 0x5
	beq _080AD9AC
	cmp r0, 0xD
	beq _080AD9AC
	ldr r0, =0x000006d9
	adds r1, r2, r0
	movs r0, 0
	strb r0, [r1]
	ldr r0, =0x000006ce
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _080AD9B4
	.pool
_080AD990:
	bl sub_80ACEAC
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080AD9B4
	bl sub_80ACF38
	ldr r1, =0x000006ed
	adds r0, r6, r1
	strb r4, [r0]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_080AD9AC:
	movs r0, 0
	b _080AD9B6
	.pool
_080AD9B4:
	movs r0, 0x1
_080AD9B6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD910

	thumb_func_start sub_80AD9BC
sub_80AD9BC: @ 80AD9BC
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r0, =0x000006ed
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, 0
	bne _080AD9EA
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __umodsi3
	movs r2, 0xDD
	lsls r2, 3
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, 0x1
	strb r0, [r5]
_080AD9EA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AD9BC

	thumb_func_start sub_80AD9F8
sub_80AD9F8: @ 80AD9F8
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006ed
	adds r0, r1, r2
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _080ADA58
	movs r0, 0xDD
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080ADA54
	bl mplay_has_finished_maybe
	lsls r0, 24
	cmp r0, 0
	bne _080ADA58
	bl GenerateRandomNumber
	ands r4, r0
	cmp r4, 0
	beq _080ADA38
	movs r0, 0x57
	bl audio_play
	b _080ADA3E
	.pool
_080ADA38:
	movs r0, 0x58
	bl audio_play
_080ADA3E:
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006ed
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	b _080ADA58
	.pool
_080ADA54:
	subs r0, 0x1
	strh r0, [r1]
_080ADA58:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD9F8

	thumb_func_start sub_80ADA60
sub_80ADA60: @ 80ADA60
	push {lr}
	ldr r0, =gUnknown_0854C14C
	ldr r3, [r0]
	ldr r0, =0x000006cc
	adds r1, r3, r0
	movs r2, 0
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x000006d2
	adds r0, r3, r1
	strb r2, [r0]
	subs r1, 0x11
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, =0x000006c2
	adds r1, r3, r2
	movs r0, 0x14
	strb r0, [r1]
	ldr r1, =0x000006fb
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, 0
	bne _080ADAA8
	adds r2, 0x2E
	adds r0, r3, r2
	strh r1, [r0]
	adds r2, 0x2
	adds r0, r3, r2
	strh r1, [r0]
	subs r2, 0x4
	adds r0, r3, r2
	strh r1, [r0]
	movs r0, 0
	movs r1, 0x10
	bl sub_80AC124
_080ADAA8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADA60

	thumb_func_start sub_80ADAC0
sub_80ADAC0: @ 80ADAC0
	push {r4,lr}
	bl sub_80ADA60
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080ADAE0
	adds r4, r1, r2
_080ADAD6:
	bl sub_80ADAF0
	ldrb r0, [r4]
	cmp r0, 0
	beq _080ADAD6
_080ADAE0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADAC0

	thumb_func_start sub_80ADAF0
sub_80ADAF0: @ 80ADAF0
	push {r4-r6,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r6, [r0]
	ldr r0, =gUnknown_02021BBC
	ldr r1, =0x000006f2
	adds r2, r6, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	ldr r3, =0x000006ee
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, 0xDE
	lsls r0, 3
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bls _080ADB2A
	movs r0, 0
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
_080ADB2A:
	ldr r1, =0x000006cc
	adds r5, r6, r1
	ldrh r4, [r5]
	cmp r4, 0
	beq _080ADB50
	cmp r4, 0x1
	beq _080ADB90
	b _080ADBA6
	.pool
_080ADB50:
	bl sub_80ADCAC
	movs r3, 0xDA
	lsls r3, 3
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _080ADB6C
	movs r0, 0xC
	movs r1, 0x8
	movs r2, 0x3
	bl sub_80AC164
	b _080ADB76
_080ADB6C:
	movs r0, 0x4
	movs r1, 0x10
	movs r2, 0
	bl sub_80AC164
_080ADB76:
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006cc
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _080ADBA6
	.pool
_080ADB90:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080ADBA6
	ldr r1, =0x000006d2
	adds r0, r6, r1
	strb r4, [r0]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_080ADBA6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADAF0

	thumb_func_start sub_80ADBB0
sub_80ADBB0: @ 80ADBB0
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r0, =gUnknown_02021BBC
	ldr r1, =0x000006f2
	adds r3, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r3]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	ldr r4, =0x000006ee
	adds r1, r2, r4
	strh r0, [r1]
	movs r0, 0xDE
	lsls r0, 3
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bls _080ADBEA
	movs r0, 0
	strh r0, [r1]
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
_080ADBEA:
	ldr r1, =0x000006ce
	adds r4, r2, r1
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080ADC26
	cmp r0, 0x1
	bgt _080ADC14
	cmp r0, 0
	beq _080ADC1A
	b _080ADC3E
	.pool
_080ADC14:
	cmp r0, 0x2
	beq _080ADC32
	b _080ADC3E
_080ADC1A:
	movs r0, 0
	movs r1, 0x10
	movs r2, 0x3
	bl sub_80AC164
	b _080ADC36
_080ADC26:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080ADC42
	b _080ADC36
_080ADC32:
	bl sub_80ADD68
_080ADC36:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080ADC42
_080ADC3E:
	movs r0, 0
	b _080ADC44
_080ADC42:
	movs r0, 0x1
_080ADC44:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADBB0

	thumb_func_start sub_80ADC4C
sub_80ADC4C: @ 80ADC4C
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_02021BBE
	ldrb r0, [r0]
	strh r0, [r3, 0x26]
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006ee
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r1, 0x20
	movs r4, 0x2E
	ldrsh r0, [r3, r4]
	lsls r0, 6
	adds r1, r0
	strh r1, [r3, 0x20]
	lsls r1, 16
	ldr r0, =0x010f0000
	cmp r1, r0
	ble _080ADC90
	movs r0, 0xF0
	lsls r0, 1
	adds r1, r0, 0
	ldrh r2, [r2]
	adds r1, r2
	movs r4, 0x2E
	ldrsh r2, [r3, r4]
	movs r0, 0x4
	subs r0, r2
	lsls r0, 6
	subs r1, r0
	ldr r0, =0x000001ff
	ands r1, r0
	strh r1, [r3, 0x20]
_080ADC90:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADC4C

	thumb_func_start sub_80ADCAC
sub_80ADCAC: @ 80ADCAC
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006fb
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080ADD56
	ldr r0, =gUnknown_0854FD30
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	bl LoadObjectPic
	movs r5, 0
_080ADCD0:
	ldr r0, =gUnknown_0854FD18
	movs r1, 0
	movs r2, 0
	movs r3, 0xFF
	bl AddObjectToBack
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080ADD34
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0x5
	bl __umodsi3
	strh r0, [r4, 0x2E]
	lsls r0, 16
	lsrs r0, 10
	adds r0, 0x20
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 10
	adds r0, 0x20
	strh r0, [r4, 0x22]
	ldr r2, =gUnknown_0854C14C
	ldr r0, [r2]
	lsls r1, r5, 2
	adds r0, 0xA0
	adds r0, r1
	str r4, [r0]
	b _080ADD42
	.pool
_080ADD34:
	ldr r2, =gUnknown_0854C14C
	ldr r1, [r2]
	lsls r0, r5, 2
	adds r1, 0xA0
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_080ADD42:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x13
	bls _080ADCD0
	ldr r0, [r2]
	ldr r1, =0x000006fb
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080ADD56:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADCAC

	thumb_func_start sub_80ADD68
sub_80ADD68: @ 80ADD68
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006fb
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080ADDA8
	movs r4, 0
	adds r5, r1, 0
	adds r5, 0xA0
_080ADD7E:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080ADD8C
	bl RemoveObjectAndFreeTiles
_080ADD8C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080ADD7E
	ldr r0, =0x00001201
	bl FreeObjectTilesByTag
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006fb
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080ADDA8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADD68

	thumb_func_start sub_80ADDBC
sub_80ADDBC: @ 80ADDBC
	push {lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006cc
	adds r2, r1, r0
	movs r3, 0
	movs r0, 0
	strh r0, [r2]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	strb r3, [r0]
	subs r2, 0x11
	adds r0, r1, r2
	strb r3, [r0]
	ldr r3, =0x000006c2
	adds r0, r1, r3
	movs r2, 0x14
	strb r2, [r0]
	adds r3, 0x3C
	adds r0, r1, r3
	strh r2, [r0]
	movs r0, 0xE0
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _080ADE04
	movs r0, 0
	movs r1, 0x10
	bl sub_80AC124
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x52
	bl SetGpuReg
_080ADE04:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADDBC

	thumb_func_start sub_80ADE18
sub_80ADE18: @ 80ADE18
	push {r4,lr}
	bl sub_80ADDBC
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080ADE38
	adds r4, r1, r2
_080ADE2E:
	bl sub_80ADE48
	ldrb r0, [r4]
	cmp r0, 0
	beq _080ADE2E
_080ADE38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADE18

	thumb_func_start sub_80ADE48
sub_80ADE48: @ 80ADE48
	push {r4,r5,lr}
	ldr r2, =gUnknown_0854C14C
	ldr r1, [r2]
	ldr r0, =gUnknown_02021BBC
	ldrh r0, [r0]
	ldr r3, =0x000001ff
	ands r3, r0
	ldr r0, =0x000006fc
	adds r1, r0
	strh r3, [r1]
	cmp r3, 0xEF
	bls _080ADE74
	adds r4, r1, 0
	adds r1, r3, 0
_080ADE64:
	adds r3, r1, 0
	subs r3, 0xF0
	adds r1, r3, 0
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r0, 0xEF
	bhi _080ADE64
	strh r3, [r4]
_080ADE74:
	ldr r5, [r2]
	ldr r1, =0x000006cc
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080ADEAC
	cmp r0, 0x1
	bgt _080ADEA0
	cmp r0, 0
	beq _080ADEA6
	b _080ADEE8
	.pool
_080ADEA0:
	cmp r0, 0x2
	beq _080ADEC8
	b _080ADEE8
_080ADEA6:
	bl sub_80ADF5C
	b _080ADEDA
_080ADEAC:
	movs r1, 0xE0
	lsls r1, 3
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080ADEBC
	bl sub_80ADF6C
_080ADEBC:
	movs r0, 0x10
	movs r1, 0
	movs r2, 0x1
	bl sub_80AC164
	b _080ADEDA
_080ADEC8:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080ADEEC
	ldr r0, =0x000006d2
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080ADEDA:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080ADEEC
	.pool
_080ADEE8:
	bl sub_80AC1A8
_080ADEEC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80ADE48

	thumb_func_start sub_80ADEF4
sub_80ADEF4: @ 80ADEF4
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006ce
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080ADF2A
	cmp r0, 0x1
	bgt _080ADF18
	cmp r0, 0
	beq _080ADF1E
	b _080ADF4E
	.pool
_080ADF18:
	cmp r0, 0x2
	beq _080ADF40
	b _080ADF4E
_080ADF1E:
	movs r0, 0
	movs r1, 0x10
	movs r2, 0x1
	bl sub_80AC164
	b _080ADF38
_080ADF2A:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080ADF52
	bl sub_80AE014
_080ADF38:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080ADF52
_080ADF40:
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080ADF4E:
	movs r0, 0
	b _080ADF54
_080ADF52:
	movs r0, 0x1
_080ADF54:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADEF4

	thumb_func_start sub_80ADF5C
sub_80ADF5C: @ 80ADF5C
	push {lr}
	ldr r0, =gUnknown_0854FD38
	bl LoadObjectPic
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADF5C

	thumb_func_start sub_80ADF6C
sub_80ADF6C: @ 80ADF6C
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	movs r1, 0xE0
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AE008
	movs r5, 0
_080ADF80:
	ldr r0, =gUnknown_0854FD58
	movs r1, 0
	movs r2, 0
	movs r3, 0x4E
	bl AddObjectToBack
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080ADFE4
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r0, r5, 0
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	adds r0, r5, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x34]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	lsls r0, 6
	adds r0, 0x20
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_0854C14C
	ldr r0, [r2]
	lsls r1, r5, 2
	adds r0, 0xF0
	adds r0, r1
	str r4, [r0]
	b _080ADFF2
	.pool
_080ADFE4:
	ldr r2, =gUnknown_0854C14C
	ldr r1, [r2]
	lsls r0, r5, 2
	adds r1, 0xF0
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_080ADFF2:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080ADF80
	ldr r0, [r2]
	movs r1, 0xE0
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080AE008:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80ADF6C

	thumb_func_start sub_80AE014
sub_80AE014: @ 80AE014
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	movs r2, 0xE0
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AE058
	movs r4, 0
	adds r5, r1, 0
	adds r5, 0xF0
_080AE02C:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080AE03A
	bl RemoveObjectAndFreeTiles
_080AE03A:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080AE02C
	ldr r0, =0x00001202
	bl FreeObjectTilesByTag
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	movs r1, 0xE0
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080AE058:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE014

	thumb_func_start sub_80AE068
sub_80AE068: @ 80AE068
	push {r4,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080AE084
	movs r0, 0
	strh r0, [r3, 0x30]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
_080AE084:
	ldr r1, =gUnknown_02021BBE
	ldrh r0, [r3, 0x2E]
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r3, 0x22]
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006fc
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r1, 0x20
	movs r4, 0x32
	ldrsh r0, [r3, r4]
	lsls r0, 6
	adds r1, r0
	strh r1, [r3, 0x20]
	lsls r1, 16
	ldr r0, =0x010f0000
	cmp r1, r0
	ble _080AE0C8
	movs r0, 0xF0
	lsls r0, 1
	adds r1, r0, 0
	ldrh r2, [r2]
	adds r1, r2
	movs r4, 0x32
	ldrsh r2, [r3, r4]
	movs r0, 0x4
	subs r0, r2
	lsls r0, 6
	subs r1, r0
	ldr r0, =0x000001ff
	ands r1, r0
	strh r1, [r3, 0x20]
_080AE0C8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE068

	thumb_func_start sub_80AE0E4
sub_80AE0E4: @ 80AE0E4
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r3, [r0]
	ldr r1, =0x000006cc
	adds r0, r3, r1
	movs r1, 0
	movs r2, 0
	strh r2, [r0]
	ldr r4, =0x000006d2
	adds r0, r3, r4
	strb r1, [r0]
	subs r4, 0x11
	adds r0, r3, r4
	strb r1, [r0]
	ldr r0, =0x000006c2
	adds r1, r3, r0
	movs r0, 0x14
	strb r0, [r1]
	movs r1, 0xDE
	lsls r1, 3
	adds r0, r3, r1
	strh r2, [r0]
	adds r4, 0x31
	adds r1, r3, r4
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, =0x00000724
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, 0
	bne _080AE14E
	adds r4, 0x2A
	adds r0, r3, r4
	strh r2, [r0]
	subs r1, 0x6
	adds r0, r3, r1
	strh r2, [r0]
	adds r4, 0x4
	adds r0, r3, r4
	strh r2, [r0]
	adds r1, 0x4
	adds r0, r3, r1
	strh r2, [r0]
	subs r4, 0x8
	adds r0, r3, r4
	strh r2, [r0]
	subs r1, 0x8
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, 0
	movs r1, 0x10
	bl sub_80AC124
_080AE14E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE0E4

	thumb_func_start sub_80AE168
sub_80AE168: @ 80AE168
	push {r4,lr}
	bl sub_80AE0E4
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AE188
	adds r4, r1, r2
_080AE17E:
	bl sub_80AE198
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AE17E
_080AE188:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE168

	thumb_func_start sub_80AE198
sub_80AE198: @ 80AE198
	push {r4,r5,lr}
	bl sub_80AE25C
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x000006cc
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080AE1CC
	cmp r0, 0x1
	bgt _080AE1C0
	cmp r0, 0
	beq _080AE1C6
	b _080AE1F0
	.pool
_080AE1C0:
	cmp r0, 0x2
	beq _080AE1D8
	b _080AE1F0
_080AE1C6:
	bl sub_80AE2F0
	b _080AE1EA
_080AE1CC:
	movs r0, 0xC
	movs r1, 0x8
	movs r2, 0x8
	bl sub_80AC164
	b _080AE1EA
_080AE1D8:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080AE1F0
	ldr r0, =0x000006d2
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080AE1EA:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080AE1F0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE198

	thumb_func_start sub_80AE1FC
sub_80AE1FC: @ 80AE1FC
	push {r4,lr}
	bl sub_80AE25C
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006ce
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080AE236
	cmp r0, 0x1
	bgt _080AE224
	cmp r0, 0
	beq _080AE22A
	b _080AE24E
	.pool
_080AE224:
	cmp r0, 0x2
	beq _080AE242
	b _080AE24E
_080AE22A:
	movs r0, 0
	movs r1, 0x10
	movs r2, 0x1
	bl sub_80AC164
	b _080AE246
_080AE236:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080AE252
	b _080AE246
_080AE242:
	bl sub_80AE3A8
_080AE246:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080AE252
_080AE24E:
	movs r0, 0
	b _080AE254
_080AE252:
	movs r0, 0x1
_080AE254:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AE1FC

	thumb_func_start sub_80AE25C
sub_80AE25C: @ 80AE25C
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r3, [r0]
	ldr r0, =0x0000071c
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r2]
	ldr r1, =0x0000ffff
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080AE288
	movs r0, 0xE4
	lsls r0, 3
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	strh r5, [r2]
_080AE288:
	ldr r1, =0x0000071e
	adds r2, r3, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	ands r0, r4
	cmp r0, 0x4
	bls _080AE2A4
	ldr r0, =0x00000722
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	strh r5, [r2]
_080AE2A4:
	ldr r0, =gUnknown_02021BBC
	movs r2, 0xE4
	lsls r2, 3
	adds r1, r3, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	subs r2, 0x8
	adds r1, r3, r2
	strh r0, [r1]
	ldr r1, =gUnknown_02021BBE
	adds r2, 0xA
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	subs r2, 0x8
	adds r1, r3, r2
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE25C

	thumb_func_start sub_80AE2F0
sub_80AE2F0: @ 80AE2F0
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x00000724
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AE396
	ldr r0, =gUnknown_0854FD70
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	bl LoadObjectPic
	movs r6, 0
_080AE314:
	adds r0, r6, 0
	movs r1, 0x5
	bl __udivsi3
	adds r5, r0, 0
	lsls r2, r5, 22
	asrs r2, 16
	ldr r0, =gUnknown_0854FD8C
	movs r1, 0
	movs r3, 0xFF
	bl AddObjectToBack
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080AE370
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	adds r0, r6, 0
	movs r1, 0x5
	bl __umodsi3
	strh r0, [r4, 0x2E]
	strh r5, [r4, 0x30]
	ldr r2, =gUnknown_0854C14C
	ldr r0, [r2]
	lsls r1, r6, 2
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r3
	adds r0, r1
	str r4, [r0]
	b _080AE382
	.pool
_080AE370:
	ldr r2, =gUnknown_0854C14C
	ldr r1, [r2]
	lsls r0, r6, 2
	movs r3, 0xA0
	lsls r3, 1
	adds r1, r3
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_080AE382:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x13
	bls _080AE314
	ldr r0, [r2]
	ldr r1, =0x00000724
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080AE396:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE2F0

	thumb_func_start sub_80AE3A8
sub_80AE3A8: @ 80AE3A8
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x00000724
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AE3EA
	movs r4, 0
	movs r0, 0xA0
	lsls r0, 1
	adds r5, r1, r0
_080AE3C0:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080AE3CE
	bl RemoveObjectAndFreeTiles
_080AE3CE:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080AE3C0
	ldr r0, =0x00001203
	bl FreeObjectTilesByTag
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x00000724
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080AE3EA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE3A8

	thumb_func_start sub_80AE3FC
sub_80AE3FC: @ 80AE3FC
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x0000071a
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r3, 0x26]
	movs r4, 0xE3
	lsls r4, 3
	adds r2, r1, r4
	ldrh r1, [r2]
	adds r1, 0x20
	movs r4, 0x2E
	ldrsh r0, [r3, r4]
	lsls r0, 6
	adds r1, r0
	strh r1, [r3, 0x20]
	lsls r1, 16
	ldr r0, =0x010f0000
	cmp r1, r0
	ble _080AE444
	movs r0, 0xF0
	lsls r0, 1
	adds r1, r0, 0
	ldrh r2, [r2]
	adds r1, r2
	movs r4, 0x2E
	ldrsh r2, [r3, r4]
	movs r0, 0x4
	subs r0, r2
	lsls r0, 6
	subs r1, r0
	ldr r0, =0x000001ff
	ands r1, r0
	strh r1, [r3, 0x20]
_080AE444:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE3FC

	thumb_func_start sub_80AE45C
sub_80AE45C: @ 80AE45C
	push {r4,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r3, [r0]
	ldr r0, =0x000006cc
	adds r1, r3, r0
	movs r2, 0
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x000006d2
	adds r0, r3, r1
	strb r2, [r0]
	ldr r4, =0x000006c1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r0, =0x000006c2
	adds r1, r3, r0
	movs r0, 0x14
	strb r0, [r1]
	ldr r1, =0x00000716
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, 0
	bne _080AE4B8
	adds r4, 0x43
	adds r1, r3, r4
	adds r4, 0x4
	adds r0, r3, r4
	str r2, [r0]
	str r2, [r1]
	ldr r0, =0x00000712
	adds r1, r3, r0
	movs r0, 0x8
	strh r0, [r1]
	adds r4, 0xC
	adds r0, r3, r4
	strh r2, [r0]
	ldrh r2, [r1]
	cmp r2, 0x5F
	bls _080AE4B0
	movs r0, 0x80
	subs r0, r2
	strh r0, [r1]
_080AE4B0:
	movs r0, 0
	movs r1, 0x10
	bl sub_80AC124
_080AE4B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE45C

	thumb_func_start sub_80AE4DC
sub_80AE4DC: @ 80AE4DC
	push {r4,lr}
	bl sub_80AE45C
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AE4FC
	adds r4, r1, r2
_080AE4F2:
	bl sub_80AE50C
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AE4F2
_080AE4FC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE4DC

	thumb_func_start sub_80AE50C
sub_80AE50C: @ 80AE50C
	push {r4,r5,lr}
	bl sub_80AE624
	bl sub_80AE5EC
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x00000712
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, 0x5F
	bls _080AE528
	movs r0, 0x20
	strh r0, [r1]
_080AE528:
	ldr r0, =0x000006cc
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080AE558
	cmp r0, 0x1
	bgt _080AE548
	cmp r0, 0
	beq _080AE54E
	b _080AE57C
	.pool
_080AE548:
	cmp r0, 0x2
	beq _080AE564
	b _080AE57C
_080AE54E:
	bl sub_80AE738
	bl sub_80AE7F8
	b _080AE576
_080AE558:
	movs r0, 0x10
	movs r1, 0
	movs r2, 0
	bl sub_80AC164
	b _080AE576
_080AE564:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080AE57C
	ldr r0, =0x000006d2
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080AE576:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080AE57C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE50C

	thumb_func_start sub_80AE588
sub_80AE588: @ 80AE588
	push {r4,lr}
	bl sub_80AE624
	bl sub_80AE5EC
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x000006ce
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _080AE5C6
	cmp r0, 0x1
	bgt _080AE5B4
	cmp r0, 0
	beq _080AE5BA
	b _080AE5DE
	.pool
_080AE5B4:
	cmp r0, 0x2
	beq _080AE5D2
	b _080AE5DE
_080AE5BA:
	movs r0, 0
	movs r1, 0x10
	movs r2, 0
	bl sub_80AC164
	b _080AE5D6
_080AE5C6:
	bl sub_80AC1A8
	lsls r0, 24
	cmp r0, 0
	beq _080AE5E2
	b _080AE5D6
_080AE5D2:
	bl sub_80AE6A4
_080AE5D6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080AE5E2
_080AE5DE:
	movs r0, 0
	b _080AE5E4
_080AE5E2:
	movs r0, 0x1
_080AE5E4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AE588

	thumb_func_start sub_80AE5EC
sub_80AE5EC: @ 80AE5EC
	push {lr}
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r0, =0x00000714
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r1, r0, 0x1
	strh r1, [r3]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bls _080AE612
	ldr r1, =0x00000712
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r1, 0x1
	movs r2, 0
	strh r1, [r0]
	strh r2, [r3]
_080AE612:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE5EC

	thumb_func_start sub_80AE624
sub_80AE624: @ 80AE624
	push {r4-r6,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r2, [r0]
	ldr r0, =0x00000704
	adds r4, r2, r0
	ldr r6, =gUnknown_08329F40
	ldr r1, =0x00000712
	adds r5, r2, r1
	ldrh r0, [r5]
	lsls r0, 1
	adds r0, r6
	movs r3, 0
	ldrsh r1, [r0, r3]
	lsls r1, 2
	ldr r0, [r4]
	subs r0, r1
	str r0, [r4]
	movs r0, 0xE1
	lsls r0, 3
	adds r3, r2, r0
	ldrh r0, [r5]
	lsls r0, 1
	adds r0, r6
	movs r5, 0
	ldrsh r1, [r0, r5]
	ldr r0, [r3]
	subs r0, r1
	str r0, [r3]
	ldr r1, =gUnknown_02021BBC
	ldr r0, [r4]
	lsrs r0, 8
	ldrh r1, [r1]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	ldr r4, =0x0000070e
	adds r1, r2, r4
	strh r0, [r1]
	ldr r1, =gUnknown_02021BBE
	ldr r0, [r3]
	lsrs r0, 8
	ldrh r1, [r1]
	adds r0, r1
	movs r5, 0xE2
	lsls r5, 3
	adds r2, r5
	strh r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE624

	thumb_func_start sub_80AE6A4
sub_80AE6A4: @ 80AE6A4
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x00000716
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AE6E6
	movs r4, 0
	movs r0, 0xC8
	lsls r0, 1
	adds r5, r1, r0
_080AE6BC:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080AE6CA
	bl RemoveObjectAndFreeTiles
_080AE6CA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080AE6BC
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x00000716
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, =0x00001204
	bl FreeObjectTilesByTag
_080AE6E6:
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x00000717
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080AE720
	movs r4, 0
	movs r0, 0xF0
	lsls r0, 1
	adds r5, r1, r0
_080AE6FC:
	lsls r0, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080AE70A
	bl RemoveObjectAndFreeTiles
_080AE70A:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _080AE6FC
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x00000717
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080AE720:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE6A4

	thumb_func_start sub_80AE738
sub_80AE738: @ 80AE738
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x00000716
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AE7E6
	ldr r0, =gUnknown_0854FDDC
	bl LoadObjectPic
	ldr r0, =gUnknown_0854C2B0
	bl sub_80ABF4C
	movs r7, 0
_080AE758:
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	adds r6, r0, 0
	lsls r2, r6, 22
	asrs r2, 16
	ldr r0, =gUnknown_0854FDC4
	movs r1, 0
	movs r3, 0x1
	bl AddObjectToBack
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080AE7C0
	ldr r2, =gUnknown_0854C14C
	ldr r5, [r2]
	lsls r0, r7, 2
	movs r3, 0xC8
	lsls r3, 1
	adds r5, r3
	adds r5, r0
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	str r4, [r5]
	adds r0, r7, 0
	movs r1, 0x5
	str r2, [sp]
	bl __umodsi3
	strh r0, [r4, 0x2E]
	ldr r0, [r5]
	strh r6, [r0, 0x30]
	ldr r2, [sp]
	b _080AE7D2
	.pool
_080AE7C0:
	ldr r2, =gUnknown_0854C14C
	ldr r1, [r2]
	lsls r0, r7, 2
	movs r3, 0xC8
	lsls r3, 1
	adds r1, r3
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_080AE7D2:
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x13
	bls _080AE758
	ldr r0, [r2]
	ldr r1, =0x00000716
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080AE7E6:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE738

	thumb_func_start sub_80AE7F8
sub_80AE7F8: @ 80AE7F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, =gUnknown_0854C14C
	ldr r0, [r4]
	ldr r1, =0x00000717
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AE8E4
	movs r7, 0
	mov r9, r4
	movs r2, 0
	mov r10, r2
_080AE818:
	lsls r0, r7, 1
	mov r8, r0
	adds r6, r0, r7
	lsls r5, r6, 4
	adds r1, r5, 0
	adds r1, 0x18
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_0854FDC4
	movs r2, 0xD0
	movs r3, 0x1
	bl AddObjectToBack
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080AE8BC
	mov r2, r9
	ldr r4, [r2]
	lsls r0, r7, 2
	movs r2, 0xF0
	lsls r2, 1
	adds r4, r2
	adds r4, r0
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	ldr r0, =gUnknown_02020630
	adds r2, r0
	str r2, [r4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x3]
	ldr r1, [r4]
	adds r0, r6, r5
	strh r0, [r1, 0x30]
	ldr r1, [r4]
	movs r0, 0x8
	strh r0, [r1, 0x2E]
	ldr r0, [r4]
	mov r1, r10
	strh r1, [r0, 0x32]
	ldr r1, [r4]
	ldr r0, =0x00006730
	strh r0, [r1, 0x36]
	ldr r1, [r4]
	ldr r0, =gUnknown_0854FDE4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1, 0x34]
	ldr r0, [r4]
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0
	bl CalcVecFromObjectCenterToObjectUpperLeft
	ldr r1, [r4]
	ldr r0, =sub_80AE958
	str r0, [r1, 0x1C]
	b _080AE8CE
	.pool
_080AE8BC:
	mov r2, r9
	ldr r0, [r2]
	lsls r1, r7, 2
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r2
	adds r0, r1
	mov r1, r10
	str r1, [r0]
_080AE8CE:
	mov r2, r9
	ldr r0, [r2]
	ldr r1, =0x00000717
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x4
	bls _080AE818
_080AE8E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE7F8

	thumb_func_start sub_80AE8F8
sub_80AE8F8: @ 80AE8F8
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	movs r2, 0xE2
	lsls r2, 3
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r3, 0x26]
	ldr r4, =0x0000070e
	adds r2, r1, r4
	ldrh r1, [r2]
	adds r1, 0x20
	movs r4, 0x2E
	ldrsh r0, [r3, r4]
	lsls r0, 6
	adds r1, r0
	strh r1, [r3, 0x20]
	lsls r1, 16
	ldr r0, =0x010f0000
	cmp r1, r0
	ble _080AE940
	movs r0, 0xF0
	lsls r0, 1
	adds r1, r0, 0
	ldrh r2, [r2]
	adds r1, r2
	movs r4, 0x2E
	ldrsh r2, [r3, r4]
	movs r0, 0x4
	subs r0, r2
	lsls r0, 6
	subs r1, r0
	ldr r0, =0x000001ff
	ands r1, r0
	strh r1, [r3, 0x20]
_080AE940:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE8F8

	thumb_func_start sub_80AE958
sub_80AE958: @ 80AE958
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x34]
	subs r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080AE972
	ldr r0, =sub_80AE97C
	str r0, [r2, 0x1C]
_080AE972:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE958

	thumb_func_start sub_80AE97C
sub_80AE97C: @ 80AE97C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x22]
	subs r0, 0x1
	strh r0, [r5, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x30
	negs r1, r1
	cmp r0, r1
	bge _080AE99A
	movs r0, 0xD0
	strh r0, [r5, 0x22]
	movs r0, 0x4
	strh r0, [r5, 0x2E]
_080AE99A:
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	ldr r3, =gUnknown_08329F40
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	lsls r0, r1, 1
	adds r0, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r2, r4, 0
	muls r2, r0
	adds r1, 0x40
	lsls r1, 1
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	muls r0, r4
	lsrs r2, 8
	strh r2, [r5, 0x24]
	lsrs r0, 8
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x30]
	adds r0, 0xA
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _080AE9E6
	movs r0, 0
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_080AE9E6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AE97C

	thumb_func_start sub_80AE9F0
sub_80AE9F0: @ 80AE9F0
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x000006cc
	adds r2, r1, r0
	movs r0, 0
	strh r0, [r2]
	ldr r0, =0x000006c1
	adds r2, r1, r0
	movs r0, 0x3
	strb r0, [r2]
	ldr r0, =0x000006c2
	adds r1, r0
	movs r0, 0x14
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80AE9F0

	thumb_func_start sub_80AEA20
sub_80AEA20: @ 80AEA20
	push {lr}
	bl sub_80AE9F0
	pop {r0}
	bx r0
	thumb_func_end sub_80AEA20

	thumb_func_start nullsub_96
nullsub_96: @ 80AEA2C
	bx lr
	thumb_func_end nullsub_96

	thumb_func_start sub_80AEA30
sub_80AEA30: @ 80AEA30
	movs r0, 0
	bx lr
	thumb_func_end sub_80AEA30

	thumb_func_start sub_80AEA34
sub_80AEA34: @ 80AEA34
	push {r4,r5,lr}
	bl sub_80ADA60
	ldr r0, =gUnknown_0854C14C
	ldr r4, [r0]
	ldr r1, =0x0000072e
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, 0
	bne _080AEA6C
	ldr r0, =gUnknown_0854FDF8
	bl LoadObjectPic
	movs r2, 0xE5
	lsls r2, 3
	adds r0, r4, r2
	strh r5, [r0]
	ldr r0, =gUnknown_0854FDF0
	ldrb r1, [r0]
	subs r2, 0x2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, =0x0000072a
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, 0x6
	adds r0, r4, r2
	strh r5, [r0]
_080AEA6C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEA34

	thumb_func_start sub_80AEA88
sub_80AEA88: @ 80AEA88
	push {r4,lr}
	bl sub_80AEA34
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r2, =0x000006d2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AEAA8
	adds r4, r1, r2
_080AEA9E:
	bl sub_80AEAB8
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AEA9E
_080AEAA8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEA88

	thumb_func_start sub_80AEAB8
sub_80AEAB8: @ 80AEAB8
	push {r4-r7,lr}
	bl sub_80ADAF0
	ldr r0, =gUnknown_0854C14C
	ldr r5, [r0]
	ldr r0, =0x00000726
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r4]
	ldr r1, =0x0000ffff
	adds r7, r1, 0
	ldr r2, =gUnknown_0854FDF0
	movs r1, 0xE5
	lsls r1, 3
	adds r3, r5, r1
	ldrh r1, [r3]
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1]
	cmp r0, r1
	bls _080AEB10
	strh r6, [r4]
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
	ands r0, r7
	cmp r0, 0x7
	bls _080AEAF8
	strh r6, [r3]
_080AEAF8:
	ldr r0, =0x0000072a
	adds r4, r5, r0
	ldrh r0, [r4]
	bl sub_80AEB48
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ands r0, r7
	cmp r0, 0xC
	bls _080AEB10
	strh r6, [r4]
_080AEB10:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEAB8

	thumb_func_start sub_80AEB2C
sub_80AEB2C: @ 80AEB2C
	push {lr}
	bl sub_80ADBB0
	lsls r0, 24
	cmp r0, 0
	beq _080AEB3C
	movs r0, 0x1
	b _080AEB42
_080AEB3C:
	bl sub_80AEBD0
	movs r0, 0
_080AEB42:
	pop {r1}
	bx r1
	thumb_func_end sub_80AEB2C

	thumb_func_start sub_80AEB48
sub_80AEB48: @ 80AEB48
	push {r4,lr}
	lsls r0, 16
	ldr r1, =gUnknown_0854FE00
	lsrs r0, 14
	adds r3, r0, r1
	adds r1, 0x2
	adds r0, r1
	ldr r1, =gUnknown_02021BBE
	ldrh r2, [r0]
	ldrh r0, [r1]
	subs r2, r0
	ldr r0, =gUnknown_0854FE44
	movs r4, 0
	ldrsh r1, [r3, r4]
	lsls r2, 16
	asrs r2, 16
	movs r3, 0
	bl AddObjectToBack
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _080AEBB0
	ldr r0, =gUnknown_02020630
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x5]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	movs r0, 0
	strh r0, [r1, 0x2E]
	strh r0, [r1, 0x30]
	strh r0, [r1, 0x32]
	ldr r0, =gUnknown_0854C14C
	ldr r1, [r0]
	ldr r0, =0x0000072c
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080AEBB0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEB48

	thumb_func_start sub_80AEBD0
sub_80AEBD0: @ 80AEBD0
	push {r4,r5,lr}
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x0000072c
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080AEC1A
	movs r4, 0
	ldr r5, =gUnknown_02020630
_080AEBE4:
	lsls r0, r4, 4
	adds r0, r4
	lsls r2, r0, 2
	adds r0, r5, 0
	adds r0, 0x14
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =gUnknown_0854FE44
	cmp r1, r0
	bne _080AEBFE
	adds r0, r2, r5
	bl RemoveObjectAndFreeTiles
_080AEBFE:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3F
	bls _080AEBE4
	ldr r0, =0x00001205
	bl FreeObjectTilesByTag
	ldr r0, =gUnknown_0854C14C
	ldr r0, [r0]
	ldr r1, =0x0000072c
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
_080AEC1A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEBD0

	thumb_func_start unc_0807DAB4
unc_0807DAB4: @ 80AEC34
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	movs r2, 0
	adds r0, 0x2
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _080AEC74
	strh r2, [r1, 0x2E]
	movs r3, 0x30
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _080AEC66
	ldrh r0, [r1, 0x24]
	adds r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _080AEC74
	movs r0, 0x1
	strh r0, [r1, 0x30]
	b _080AEC74
_080AEC66:
	ldrh r0, [r1, 0x24]
	subs r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	cmp r0, 0
	bgt _080AEC74
	strh r2, [r1, 0x30]
_080AEC74:
	ldrh r0, [r1, 0x22]
	subs r0, 0x3
	strh r0, [r1, 0x22]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x77
	ble _080AEC8E
	adds r0, r1, 0
	bl RemoveObjectAndFreeTiles
_080AEC8E:
	pop {r0}
	bx r0
	thumb_func_end unc_0807DAB4

	thumb_func_start sub_80AEC94
sub_80AEC94: @ 80AEC94
	ldr r2, =gUnknown_02038BC4
	strb r0, [r2]
	ldr r0, =gUnknown_02038BC6
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80AEC94

	thumb_func_start sub_80AECA8
sub_80AECA8: @ 80AECA8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080AECCC
	cmp r0, 0x1
	beq _080AECF8
	b _080AED1C
	.pool
_080AECCC:
	ldrh r0, [r4, 0x1E]
	subs r1, r0, 0x1
	strh r1, [r4, 0x1E]
	lsls r0, 16
	cmp r0, 0
	bgt _080AED1C
	ldrb r0, [r4, 0x2]
	bl weather_set
	ldr r1, =gUnknown_02038BC4
	ldrh r0, [r4, 0x2]
	strb r0, [r1]
	movs r1, 0x96
	lsls r1, 2
	adds r0, r1, 0
	strh r0, [r4, 0x1E]
	ldrh r0, [r4]
	adds r0, 0x1
	b _080AED1A
	.pool
_080AECF8:
	ldrh r0, [r4, 0x1E]
	subs r1, r0, 0x1
	strh r1, [r4, 0x1E]
	lsls r0, 16
	cmp r0, 0
	bgt _080AED1C
	ldrb r0, [r4, 0x4]
	bl weather_set
	ldr r1, =gUnknown_02038BC4
	ldrh r0, [r4, 0x4]
	strb r0, [r1]
	movs r1, 0x96
	lsls r1, 2
	adds r0, r1, 0
	strh r0, [r4, 0x1E]
	movs r0, 0
_080AED1A:
	strh r0, [r4]
_080AED1C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AECA8

	thumb_func_start bag_add_task0_by_acit
bag_add_task0_by_acit: @ 80AED28
	push {lr}
	ldr r0, =sub_80AECA8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	movs r2, 0x96
	lsls r2, 2
	adds r0, r2, 0
	strh r0, [r1, 0x1E]
	ldr r3, =gUnknown_02038BC4
	ldrb r2, [r3]
	cmp r2, 0xD
	bne _080AED60
	movs r0, 0xC
	b _080AED66
	.pool
_080AED60:
	cmp r2, 0xC
	bne _080AED6C
	movs r0, 0xD
_080AED66:
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	b _080AED78
_080AED6C:
	movs r0, 0xD
	strb r0, [r3]
	movs r0, 0xC
	strh r0, [r1, 0x2]
	movs r0, 0xD
	strh r0, [r1, 0x4]
_080AED78:
	pop {r0}
	bx r0
	thumb_func_end bag_add_task0_by_acit

	thumb_func_start sub_80AED7C
sub_80AED7C: @ 80AED7C
	push {r4,r5,lr}
	ldr r4, =gUnknown_03005D8C
	ldr r1, [r4]
	adds r1, 0x2E
	ldrb r5, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80AEEE8
	ldr r1, [r4]
	adds r1, 0x2E
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x2E
	ldrb r0, [r0]
	adds r1, r5, 0
	bl sub_80AEFDC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AED7C

	thumb_func_start sav1_get_weather_probably
sav1_get_weather_probably: @ 80AEDAC
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	adds r0, 0x2E
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sav1_get_weather_probably

	thumb_func_start sub_80AEDBC
sub_80AEDBC: @ 80AEDBC
	push {r4,r5,lr}
	ldr r4, =gUnknown_03005D8C
	ldr r0, [r4]
	adds r0, 0x2E
	ldrb r5, [r0]
	ldr r0, =gUnknown_02037318
	ldrb r0, [r0, 0x16]
	bl sub_80AEEE8
	ldr r1, [r4]
	adds r1, 0x2E
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x2E
	ldrb r0, [r0]
	adds r1, r5, 0
	bl sub_80AEFDC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEDBC

	thumb_func_start sub_80AEDF0
sub_80AEDF0: @ 80AEDF0
	push {lr}
	bl sub_80AED7C
	bl sav1_get_weather_probably
	lsls r0, 24
	lsrs r0, 24
	bl weather_set
	pop {r0}
	bx r0
	thumb_func_end sub_80AEDF0

	thumb_func_start sub_80AEE08
sub_80AEE08: @ 80AEE08
	push {lr}
	bl sub_80AED7C
	bl sav1_get_weather_probably
	lsls r0, 24
	lsrs r0, 24
	bl sub_80AB104
	pop {r0}
	bx r0
	thumb_func_end sub_80AEE08

	thumb_func_start sub_80AEE20
sub_80AEE20: @ 80AEE20
	push {r4,r5,lr}
	bl sav1_get_weather_probably
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bne _080AEE4C
	ldr r0, =sub_80AECA8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080AEE3E
	bl bag_add_task0_by_acit
_080AEE3E:
	ldr r0, =gUnknown_02038BC4
	ldrb r4, [r0]
	b _080AEE6E
	.pool
_080AEE4C:
	ldr r5, =sub_80AECA8
	adds r0, r5, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _080AEE68
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080AEE68:
	ldr r1, =gUnknown_02038BC4
	movs r0, 0xD
	strb r0, [r1]
_080AEE6E:
	adds r0, r4, 0
	bl weather_set
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEE20

	thumb_func_start sub_80AEE84
sub_80AEE84: @ 80AEE84
	push {r4,r5,lr}
	bl sav1_get_weather_probably
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bne _080AEEB0
	ldr r0, =sub_80AECA8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080AEEA2
	bl bag_add_task0_by_acit
_080AEEA2:
	ldr r0, =gUnknown_02038BC4
	ldrb r4, [r0]
	b _080AEED2
	.pool
_080AEEB0:
	ldr r5, =sub_80AECA8
	adds r0, r5, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _080AEECC
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080AEECC:
	ldr r1, =gUnknown_02038BC4
	movs r0, 0xD
	strb r0, [r1]
_080AEED2:
	adds r0, r4, 0
	bl sub_80AB104
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80AEE84

	thumb_func_start sub_80AEEE8
sub_80AEEE8: @ 80AEEE8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x15
	bhi _080AEFB4
	lsls r0, 2
	ldr r1, =_080AEF00
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080AEF00:
	.4byte _080AEFB4
	.4byte _080AEF58
	.4byte _080AEF5C
	.4byte _080AEF60
	.4byte _080AEF64
	.4byte _080AEF68
	.4byte _080AEF6C
	.4byte _080AEF70
	.4byte _080AEF74
	.4byte _080AEF78
	.4byte _080AEF7C
	.4byte _080AEF80
	.4byte _080AEF84
	.4byte _080AEF88
	.4byte _080AEF8C
	.4byte _080AEF90
	.4byte _080AEFB4
	.4byte _080AEFB4
	.4byte _080AEFB4
	.4byte _080AEFB4
	.4byte _080AEF94
	.4byte _080AEF9C
_080AEF58:
	movs r0, 0x1
	b _080AEFB6
_080AEF5C:
	movs r0, 0x2
	b _080AEFB6
_080AEF60:
	movs r0, 0x3
	b _080AEFB6
_080AEF64:
	movs r0, 0x4
	b _080AEFB6
_080AEF68:
	movs r0, 0x5
	b _080AEFB6
_080AEF6C:
	movs r0, 0x6
	b _080AEFB6
_080AEF70:
	movs r0, 0x7
	b _080AEFB6
_080AEF74:
	movs r0, 0x8
	b _080AEFB6
_080AEF78:
	movs r0, 0x9
	b _080AEFB6
_080AEF7C:
	movs r0, 0xA
	b _080AEFB6
_080AEF80:
	movs r0, 0xB
	b _080AEFB6
_080AEF84:
	movs r0, 0xC
	b _080AEFB6
_080AEF88:
	movs r0, 0xD
	b _080AEFB6
_080AEF8C:
	movs r0, 0xE
	b _080AEFB6
_080AEF90:
	movs r0, 0xF
	b _080AEFB6
_080AEF94:
	ldr r1, =gUnknown_0854FE5C
	b _080AEF9E
	.pool
_080AEF9C:
	ldr r1, =gUnknown_0854FE60
_080AEF9E:
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	adds r0, 0x2F
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	b _080AEFB6
	.pool
_080AEFB4:
	movs r0, 0
_080AEFB6:
	pop {r1}
	bx r1
	thumb_func_end sub_80AEEE8

	thumb_func_start sub_80AEFBC
sub_80AEFBC: @ 80AEFBC
	lsls r0, 16
	ldr r1, =gUnknown_03005D8C
	ldr r2, [r1]
	adds r2, 0x2F
	lsrs r0, 16
	ldrb r1, [r2]
	adds r0, r1
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 16
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_80AEFBC

	thumb_func_start sub_80AEFDC
sub_80AEFDC: @ 80AEFDC
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r2, r0, 24
	cmp r0, r1
	beq _080AEFF6
	cmp r2, 0x3
	beq _080AEFF0
	cmp r2, 0x5
	bne _080AEFF6
_080AEFF0:
	movs r0, 0x28
	bl sav12_xor_increment
_080AEFF6:
	pop {r0}
	bx r0
	thumb_func_end sub_80AEFDC

	.align 2, 0 @ Don't pad with nop.
