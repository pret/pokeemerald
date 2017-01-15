	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A1818
sub_80A1818: @ 80A1818
	push {lr}
	lsls r0, 16
	ldr r2, =gUnknown_0852487C
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 14
	adds r1, r2
	ldr r0, [r1]
	ldr r1, =gUnknown_02037814
	movs r2, 0x10
	bl CpuSet
	ldr r0, =gUnknown_02037FD4
	ldrh r2, [r0, 0x4]
	lsls r2, 21
	lsrs r2, 27
	ldrh r3, [r0, 0x6]
	lsls r3, 17
	lsrs r3, 17
	movs r0, 0x80
	movs r1, 0x10
	bl BlendPalette
	ldr r0, =sub_8149DFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080A1862
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1670
	str r0, [r1]
	ldr r1, =gUnknown_03000F3C
	movs r0, 0x20
	strh r0, [r1]
_080A1862:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1818

	thumb_func_start sub_80A1884
sub_80A1884: @ 80A1884
	push {lr}
	lsls r0, 16
	ldr r2, =gUnknown_0852487C
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 14
	adds r1, r2
	ldr r0, [r1]
	ldr r1, =gUnknown_02037814
	movs r2, 0x10
	bl CpuSet
	ldr r0, =sub_8149DFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080A18D6
	ldr r0, =gUnknown_02037FD4
	ldrh r2, [r0, 0x4]
	lsls r2, 21
	lsrs r2, 27
	ldrh r3, [r0, 0x6]
	lsls r3, 17
	lsrs r3, 17
	movs r0, 0x80
	movs r1, 0x10
	bl BlendPalette
	ldr r1, =gUnknown_03000F3C
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _080A18D6
	ldr r0, =gUnknown_03000F44
	str r1, [r0]
_080A18D6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1884

	thumb_func_start decompress_palette
@ void decompress_palette(void *src, u16 offset, u16 size)
decompress_palette: @ 80A18F4
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	ldr r6, =gUnknown_02037FE8
	adds r1, r6, 0
	bl LZDecompressWram
	lsls r4, 1
	ldr r1, =gUnknown_02037714
	adds r1, r4, r1
	lsrs r5, 17
	adds r0, r6, 0
	adds r2, r5, 0
	bl CpuSet
	ldr r0, =gUnknown_02037B14
	adds r4, r0
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuSet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end decompress_palette

	thumb_func_start gpu_pal_apply
@ void gpu_pal_apply(void *src, int dest_offset, int mode)
gpu_pal_apply: @ 80A1938
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r4, 16
	lsls r5, 16
	lsrs r4, 15
	ldr r1, =gUnknown_02037714
	adds r1, r4, r1
	lsrs r5, 17
	adds r2, r5, 0
	bl CpuSet
	ldr r0, =gUnknown_02037B14
	adds r4, r0
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuSet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end gpu_pal_apply

	thumb_func_start rboxid_80040B8
rboxid_80040B8: @ 80A1970
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r6, 16
	lsrs r6, 16
	lsls r4, 16
	lsls r5, 16
	mov r0, sp
	strh r6, [r0]
	lsrs r4, 15
	ldr r1, =gUnknown_02037714
	adds r1, r4, r1
	lsrs r5, 17
	movs r0, 0x80
	lsls r0, 17
	orrs r5, r0
	mov r0, sp
	adds r2, r5, 0
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	strh r6, [r0]
	ldr r1, =gUnknown_02037B14
	adds r4, r1
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuSet
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end rboxid_80040B8

	thumb_func_start copy_pal_bg_faded_to_pal_ram
@ void copy_pal_bg_faded_to_pal_ram()
copy_pal_bg_faded_to_pal_ram: @ 80A19C0
	push {r4,r5,lr}
	ldr r4, =gUnknown_02037FD4
	ldrb r1, [r4, 0x8]
	movs r5, 0x80
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _080A1A02
	ldr r1, =gUnknown_02037B14
	movs r2, 0xA0
	lsls r2, 19
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	ldr r0, =gUnknown_02037FE4
	str r3, [r0]
	ldrb r1, [r4, 0x9]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _080A1A02
	ldrb r1, [r4, 0x7]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080A1A02
	bl sub_80A2968
_080A1A02:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_pal_bg_faded_to_pal_ram

	thumb_func_start fade_and_return_progress_probably
@ int fade_and_return_progress_probably()
fade_and_return_progress_probably: @ 80A1A1C
	push {lr}
	ldr r0, =gUnknown_02037FE4
	ldr r0, [r0]
	cmp r0, 0
	beq _080A1A30
	movs r0, 0xFF
	b _080A1A68
	.pool
_080A1A30:
	ldr r0, =gUnknown_02037FD4
	ldrb r0, [r0, 0x9]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	bne _080A1A48
	bl pal_fade__0
	b _080A1A56
	.pool
_080A1A48:
	cmp r1, 0x1
	bne _080A1A52
	bl pal_fade__1
	b _080A1A56
_080A1A52:
	bl pal_fade__2
_080A1A56:
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gUnknown_02037FE4
	ldr r0, =gUnknown_02037FD4
	ldr r0, [r0]
	movs r1, 0
	orrs r0, r1
	str r0, [r2]
	adds r0, r3, 0
_080A1A68:
	pop {r1}
	bx r1
	.pool
	thumb_func_end fade_and_return_progress_probably

	thumb_func_start sub_80A1A74
sub_80A1A74: @ 80A1A74
	push {r4,lr}
	movs r4, 0
_080A1A78:
	adds r0, r4, 0
	bl palslot_dead_struct_update
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080A1A78
	bl pal_fade_control_reset_maybe
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A1A74

	thumb_func_start sub_80A1A94
sub_80A1A94: @ 80A1A94
	push {r4-r7,lr}
	movs r0, 0xA0
	lsls r0, 19
	mov r12, r0
	movs r4, 0
	ldr r7, =gUnknown_02037714
	ldr r6, =gUnknown_02037B14
	ldr r5, =0x000001ff
_080A1AA4:
	lsls r1, r4, 1
	adds r3, r1, r7
	mov r0, r12
	adds r2, r1, r0
	ldrh r0, [r2]
	strh r0, [r3]
	adds r1, r6
	ldrh r0, [r2]
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r5
	bls _080A1AA4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1A94

	thumb_func_start pal_fade_maybe
pal_fade_maybe: @ 80A1AD4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldr r0, [sp, 0x18]
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r5, =gUnknown_02037FD4
	ldrb r1, [r5, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080A1B08
	movs r0, 0
	b _080A1C00
	.pool
_080A1B08:
	ldrb r0, [r5, 0xA]
	movs r3, 0x79
	negs r3, r3
	adds r2, r3, 0
	ands r2, r0
	movs r0, 0x10
	orrs r2, r0
	strb r2, [r5, 0xA]
	lsls r0, r6, 24
	asrs r1, r0, 24
	cmp r1, 0
	bge _080A1B36
	lsls r0, r2, 25
	lsrs r0, 28
	negs r1, r1
	adds r0, r1
	movs r1, 0xF
	ands r0, r1
	lsls r0, 3
	ands r2, r3
	orrs r2, r0
	strb r2, [r5, 0xA]
	movs r6, 0
_080A1B36:
	str r4, [r5]
	movs r4, 0x3F
	adds r1, r6, 0
	ands r1, r4
	ldrb r2, [r5, 0x4]
	movs r3, 0x40
	negs r3, r3
	adds r0, r3, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x4]
	ands r6, r4
	ldrb r0, [r5, 0x8]
	ands r3, r0
	orrs r3, r6
	strb r3, [r5, 0x8]
	movs r0, 0x1F
	mov r1, r12
	ands r1, r0
	lsls r1, 6
	ldrh r2, [r5, 0x4]
	ldr r0, =0xfffff83f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	lsls r2, r7, 3
	ldrb r1, [r5, 0x5]
	movs r0, 0x7
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	ldr r1, =0x00007fff
	mov r0, r8
	ands r1, r0
	ldrh r2, [r5, 0x6]
	ldr r0, =0xffff8000
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x6]
	ldrb r0, [r5, 0x7]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r5, 0x7]
	ldrb r1, [r5, 0x9]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x9]
	cmp r12, r7
	bcs _080A1BB0
	movs r0, 0x41
	negs r0, r0
	ands r3, r0
	b _080A1BB4
	.pool
_080A1BB0:
	movs r0, 0x40
	orrs r3, r0
_080A1BB4:
	strb r3, [r5, 0x8]
	bl fade_and_return_progress_probably
	ldr r4, =gUnknown_02037FD4
	ldrb r1, [r4, 0x8]
	lsrs r5, r1, 7
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r4, 0x8]
	ldr r0, =gUnknown_02037B14
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x04000100
	bl CpuSet
	ldr r1, =gUnknown_02037FE4
	movs r0, 0
	str r0, [r1]
	ldrb r1, [r4, 0x9]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _080A1BF0
	ldrb r1, [r4, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080A1BF0
	bl sub_80A2968
_080A1BF0:
	ldr r2, =gUnknown_02037FD4
	lsls r3, r5, 7
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x8]
	movs r0, 0x1
_080A1C00:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pal_fade_maybe

	thumb_func_start sub_80A1C1C
sub_80A1C1C: @ 80A1C1C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	ldr r5, [sp, 0x1C]
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r5, 16
	lsrs r5, 16
	str r3, [sp, 0x4]
	bl sub_80A1A94
	lsls r4, 24
	asrs r4, 24
	str r5, [sp]
	mov r0, r8
	adds r1, r4, 0
	adds r2, r6, 0
	ldr r3, [sp, 0x4]
	bl pal_fade_maybe
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A1C1C

	thumb_func_start sub_80A1C64
sub_80A1C64: @ 80A1C64
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	movs r5, 0
_080A1C6E:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, =gUnknown_02037F14
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	lsls r0, 31
	cmp r0, 0
	beq _080A1CCC
	ldr r2, [r4]
	ldrb r0, [r2, 0x8]
	lsls r0, 31
	lsrs r0, 31
	cmp r0, r7
	bne _080A1CCC
	ldrh r1, [r4, 0x6]
	lsls r1, 20
	lsrs r1, 25
	ldrb r0, [r2, 0xB]
	lsls r0, 27
	lsrs r0, 27
	cmp r1, r0
	bne _080A1CAA
	adds r0, r4, 0
	bl sub_80A1F00
	ldrb r0, [r4, 0x4]
	lsls r0, 31
	cmp r0, 0
	beq _080A1CCC
_080A1CAA:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _080A1CC0
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80A1CDC
	b _080A1CC4
	.pool
_080A1CC0:
	subs r0, 0x1
	strb r0, [r4, 0x8]
_080A1CC4:
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80A1E40
_080A1CCC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _080A1C6E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A1C64

	thumb_func_start sub_80A1CDC
sub_80A1CDC: @ 80A1CDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	mov r8, r1
	movs r6, 0
	ldrh r1, [r4, 0x6]
	lsls r1, 20
	lsrs r1, 25
	ldr r3, [r4]
	ldrb r0, [r3, 0x9]
	lsls r2, r0, 25
	lsrs r0, r2, 27
	adds r5, r1, 0
	muls r5, r0
	ldrb r1, [r3, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A1D78
	lsrs r0, r2, 27
	cmp r6, r0
	bcs _080A1DC4
	ldr r0, =gUnknown_02037714
	mov r12, r0
	ldr r7, =gUnknown_02037B14
_080A1D10:
	ldr r0, [r4, 0x4]
	lsls r0, 11
	lsrs r0, 22
	lsls r0, 1
	add r0, r12
	ldr r1, [r3, 0x4]
	lsls r2, r5, 1
	adds r1, r2, r1
	ldrh r1, [r1]
	strh r1, [r0]
	ldr r0, [r4, 0x4]
	lsls r0, 11
	lsrs r0, 22
	lsls r0, 1
	adds r0, r7
	ldr r1, [r4]
	ldr r1, [r1, 0x4]
	adds r2, r1
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, [r4, 0x4]
	lsls r1, r2, 11
	lsrs r1, 22
	adds r1, 0x1
	ldr r0, =0x000003ff
	ands r1, r0
	lsls r1, 11
	ldr r0, =0xffe007ff
	ands r0, r2
	orrs r0, r1
	str r0, [r4, 0x4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r3, [r4]
	ldrb r0, [r3, 0x9]
	lsls r0, 25
	lsrs r0, 27
	cmp r6, r0
	bcc _080A1D10
	b _080A1DC4
	.pool
_080A1D78:
	lsrs r0, r2, 27
	cmp r6, r0
	bcs _080A1DC4
	ldr r3, =gUnknown_02037B14
_080A1D80:
	ldr r1, [r4, 0x4]
	lsls r1, 11
	lsrs r1, 22
	lsls r1, 1
	adds r1, r3
	ldr r0, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, [r4, 0x4]
	lsls r1, r2, 11
	lsrs r1, 22
	adds r1, 0x1
	ldr r0, =0x000003ff
	ands r1, r0
	lsls r1, 11
	ldr r0, =0xffe007ff
	ands r0, r2
	orrs r0, r1
	str r0, [r4, 0x4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [r4]
	ldrb r0, [r0, 0x9]
	lsls r0, 25
	lsrs r0, 27
	cmp r6, r0
	bcc _080A1D80
_080A1DC4:
	ldrh r0, [r4, 0x4]
	lsls r0, 21
	lsrs r0, 23
	lsls r0, 11
	ldr r1, [r4, 0x4]
	ldr r2, =0xffe007ff
	ands r1, r2
	orrs r1, r0
	str r1, [r4, 0x4]
	ldr r3, [r4]
	ldrb r0, [r3, 0xA]
	strb r0, [r4, 0x8]
	ldrh r2, [r4, 0x6]
	lsls r0, r2, 20
	lsrs r0, 25
	adds r0, 0x1
	movs r1, 0x7F
	ands r0, r1
	lsls r0, 5
	ldr r5, =0xfffff01f
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strh r1, [r4, 0x6]
	lsls r1, 20
	lsrs r1, 25
	ldrb r0, [r3, 0xB]
	lsls r0, 27
	lsrs r0, 27
	cmp r1, r0
	blt _080A1E14
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _080A1E0C
	subs r0, 0x1
	strb r0, [r4, 0x9]
_080A1E0C:
	ldrh r1, [r4, 0x6]
	adds r0, r5, 0
	ands r0, r1
	strh r0, [r4, 0x6]
_080A1E14:
	ldrh r0, [r4, 0x4]
	lsls r0, 21
	lsrs r0, 27
	movs r1, 0x1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1CDC

	thumb_func_start sub_80A1E40
sub_80A1E40: @ 80A1E40
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r3, =gUnknown_02037FD4
	ldrb r1, [r3, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080A1EF4
	ldrh r0, [r4, 0x4]
	lsls r0, 21
	lsrs r6, r0, 23
	asrs r1, r6, 4
	movs r5, 0x1
	adds r0, r5, 0
	lsls r0, r1
	ldr r1, [r3]
	ands r0, r1
	cmp r0, 0
	beq _080A1EF4
	ldr r2, [r4]
	ldrb r1, [r2, 0x8]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080A1E9C
	ldrb r1, [r3, 0x4]
	lsls r1, 26
	ldrb r0, [r3, 0x8]
	lsls r0, 26
	cmp r1, r0
	beq _080A1EF4
	adds r0, r6, 0
	ldrb r1, [r2, 0x9]
	lsls r1, 25
	lsrs r1, 27
	ldrh r2, [r3, 0x4]
	lsls r2, 21
	lsrs r2, 27
	ldrh r3, [r3, 0x6]
	lsls r3, 17
	lsrs r3, 17
	bl BlendPalette
	b _080A1EF4
	.pool
_080A1E9C:
	ldrb r1, [r3, 0x4]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _080A1EF4
	ldrb r0, [r4, 0x8]
	ldrb r1, [r2, 0xA]
	cmp r0, r1
	beq _080A1EF4
	ldrh r0, [r4, 0x6]
	lsls r0, 20
	lsrs r0, 25
	ldrb r1, [r2, 0x9]
	lsls r1, 25
	lsrs r2, r1, 27
	adds r5, r0, 0
	muls r5, r2
	movs r3, 0
	adds r1, r2, 0
	cmp r3, r1
	bcs _080A1EF4
	ldr r6, =gUnknown_02037B14
_080A1EC8:
	ldrh r1, [r4, 0x4]
	lsls r1, 21
	lsrs r1, 23
	adds r1, r3
	lsls r1, 1
	adds r1, r6
	ldr r2, [r4]
	adds r0, r5, r3
	ldr r2, [r2, 0x4]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, [r4]
	ldrb r0, [r0, 0x9]
	lsls r0, 25
	lsrs r0, 27
	cmp r3, r0
	bcc _080A1EC8
_080A1EF4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1E40

	thumb_func_start sub_80A1F00
sub_80A1F00: @ 80A1F00
	push {lr}
	adds r3, r0, 0
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	bne _080A1F50
	ldr r2, [r3]
	ldrb r0, [r2, 0xB]
	lsrs r0, 5
	cmp r0, 0
	bne _080A1F40
	ldrh r1, [r3, 0x6]
	ldr r0, =0xfffff01f
	ands r0, r1
	strh r0, [r3, 0x6]
	ldrb r0, [r2, 0xA]
	strb r0, [r3, 0x8]
	ldrb r0, [r2, 0xC]
	strb r0, [r3, 0x9]
	ldrh r0, [r3, 0x4]
	lsls r0, 21
	lsrs r0, 23
	lsls r0, 11
	ldr r1, [r3, 0x4]
	ldr r2, =0xffe007ff
	ands r1, r2
	orrs r1, r0
	str r1, [r3, 0x4]
	b _080A1F54
	.pool
_080A1F40:
	cmp r0, 0
	blt _080A1F54
	cmp r0, 0x2
	bgt _080A1F54
	ldrh r0, [r2]
	bl sub_80A1F58
	b _080A1F54
_080A1F50:
	subs r0, 0x1
	strb r0, [r3, 0x9]
_080A1F54:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1F00

	thumb_func_start sub_80A1F58
sub_80A1F58: @ 80A1F58
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A20A4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _080A1F6E
	bl palslot_dead_struct_update
_080A1F6E:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1F58

	thumb_func_start palslot_dead_struct_update
palslot_dead_struct_update: @ 80A1F74
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02037F14
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, =gUnknown_0852488C
	str r0, [r1]
	ldrb r2, [r1, 0x4]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x4]
	ldrh r2, [r1, 0x4]
	ldr r0, =0xfffff803
	ands r0, r2
	strh r0, [r1, 0x4]
	ldr r0, [r1, 0x4]
	ldr r2, =0xffe007ff
	ands r0, r2
	str r0, [r1, 0x4]
	ldrh r2, [r1, 0x6]
	ldr r0, =0xfffff01f
	ands r0, r2
	strh r0, [r1, 0x6]
	ldrb r2, [r1, 0x4]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x4]
	movs r0, 0
	strb r0, [r1, 0x8]
	strb r0, [r1, 0x9]
	bx lr
	.pool
	thumb_func_end palslot_dead_struct_update

	thumb_func_start pal_fade_control_reset_maybe
pal_fade_control_reset_maybe: @ 80A1FD0
	ldr r2, =gUnknown_02037FD4
	movs r0, 0
	str r0, [r2]
	subs r0, 0x40
	ldrb r1, [r2, 0x4]
	ands r0, r1
	strb r0, [r2, 0x4]
	ldrh r1, [r2, 0x4]
	ldr r0, =0xfffff83f
	ands r0, r1
	strh r0, [r2, 0x4]
	ldrb r1, [r2, 0x5]
	movs r0, 0x7
	ands r0, r1
	strb r0, [r2, 0x5]
	ldrh r1, [r2, 0x6]
	ldr r0, =0xffff8000
	ands r0, r1
	strh r0, [r2, 0x6]
	ldrb r1, [r2, 0x7]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x7]
	movs r0, 0
	strb r0, [r2, 0x8]
	ldrb r1, [r2, 0x9]
	movs r3, 0x5
	negs r3, r3
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x9
	negs r1, r1
	ands r0, r1
	strb r0, [r2, 0x9]
	ldrb r1, [r2, 0xA]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xA]
	ldr r0, [r2, 0x8]
	ldr r1, =0xfffe0fff
	ands r0, r1
	str r0, [r2, 0x8]
	ldrb r0, [r2, 0xA]
	ands r3, r0
	movs r0, 0x79
	negs r0, r0
	ands r3, r0
	movs r0, 0x10
	orrs r3, r0
	strb r3, [r2, 0xA]
	bx lr
	.pool
	thumb_func_end pal_fade_control_reset_maybe

	thumb_func_start sub_80A2048
sub_80A2048: @ 80A2048
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A20A4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x10
	beq _080A206C
	ldr r1, =gUnknown_02037F14
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x4]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0, 0x4]
_080A206C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2048

	thumb_func_start sub_80A2074
sub_80A2074: @ 80A2074
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A20A4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x10
	beq _080A209A
	ldr r0, =gUnknown_02037F14
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x4]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x4]
_080A209A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2074

	thumb_func_start sub_80A20A4
sub_80A20A4: @ 80A20A4
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r3, =gUnknown_02037F14
_080A20AE:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, r2
	bne _080A20C8
	adds r0, r1, 0
	b _080A20D4
	.pool
_080A20C8:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _080A20AE
	movs r0, 0x10
_080A20D4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A20A4

	thumb_func_start pal_fade__0
pal_fade__0: @ 80A20D8
	push {r4-r7,lr}
	ldr r4, =gUnknown_02037FD4
	ldrb r1, [r4, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080A20F0
	movs r0, 0
	b _080A220C
	.pool
_080A20F0:
	bl sub_80A29BC
	lsls r0, 24
	cmp r0, 0
	beq _080A20FE
	ldrb r0, [r4, 0x7]
	b _080A220A
_080A20FE:
	ldrb r1, [r4, 0xA]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A2132
	ldrb r2, [r4, 0x4]
	lsls r1, r2, 26
	ldrb r0, [r4, 0x8]
	lsls r0, 26
	cmp r1, r0
	bcs _080A212A
	lsrs r0, r1, 26
	adds r0, 0x1
	movs r1, 0x3F
	ands r0, r1
	movs r1, 0x40
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x4]
	movs r0, 0x2
	b _080A220C
_080A212A:
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	strb r0, [r4, 0x4]
_080A2132:
	movs r5, 0
	ldr r2, =gUnknown_02037FD4
	ldrb r1, [r2, 0xA]
	movs r0, 0x4
	ands r0, r1
	adds r7, r2, 0
	cmp r0, 0
	bne _080A214C
	ldrh r4, [r7]
	b _080A2152
	.pool
_080A214C:
	ldrh r4, [r7, 0x2]
	movs r5, 0x80
	lsls r5, 1
_080A2152:
	cmp r4, 0
	beq _080A2184
	ldr r7, =gUnknown_02037FD4
	adds r6, r7, 0
_080A215A:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _080A2176
	ldrh r2, [r6, 0x4]
	lsls r2, 21
	lsrs r2, 27
	ldrh r3, [r6, 0x6]
	lsls r3, 17
	lsrs r3, 17
	adds r0, r5, 0
	movs r1, 0x10
	bl BlendPalette
_080A2176:
	lsrs r4, 1
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r4, 0
	bne _080A215A
_080A2184:
	ldrb r2, [r7, 0xA]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r4, 0x5
	negs r4, r4
	ands r4, r2
	orrs r4, r1
	strb r4, [r7, 0xA]
	movs r0, 0x4
	ands r0, r4
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _080A2208
	ldrh r6, [r7, 0x4]
	lsls r2, r6, 21
	ldrb r0, [r7, 0x5]
	lsls r5, r0, 24
	lsrs r1, r2, 27
	lsrs r0, r5, 27
	cmp r1, r0
	bne _080A21C4
	str r3, [r7]
	movs r0, 0x2
	orrs r4, r0
	strb r4, [r7, 0xA]
	b _080A2208
	.pool
_080A21C4:
	ldrb r1, [r7, 0x8]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080A21E0
	lsrs r3, r2, 27
	lsls r0, r4, 25
	lsrs r0, 28
	adds r3, r0, r3
	lsrs r0, r5, 27
	cmp r3, r0
	ble _080A21F6
	adds r3, r0, 0
	b _080A21F6
_080A21E0:
	lsrs r3, r2, 27
	lsls r0, r4, 25
	lsrs r0, 28
	subs r0, r3, r0
	lsls r0, 24
	lsrs r3, r0, 24
	asrs r0, 24
	lsrs r1, r5, 27
	cmp r0, r1
	bge _080A21F6
	adds r3, r1, 0
_080A21F6:
	lsls r0, r3, 24
	asrs r0, 24
	movs r1, 0x1F
	ands r0, r1
	lsls r0, 6
	ldr r1, =0xfffff83f
	ands r1, r6
	orrs r1, r0
	strh r1, [r7, 0x4]
_080A2208:
	ldrb r0, [r7, 0x7]
_080A220A:
	lsrs r0, 7
_080A220C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pal_fade__0

	thumb_func_start sub_80A2218
sub_80A2218: @ 80A2218
	push {r4-r7,lr}
	adds r1, r0, 0
	movs r3, 0
	cmp r1, 0
	beq _080A2256
	ldr r7, =gUnknown_02037B14
_080A2224:
	movs r0, 0x1
	ands r0, r1
	lsrs r4, r1, 1
	adds r5, r3, 0
	adds r5, 0x10
	cmp r0, 0
	beq _080A224C
	movs r2, 0
	adds r6, r7, 0
_080A2236:
	adds r0, r3, r2
	lsls r0, 1
	adds r0, r6
	ldrh r1, [r0]
	mvns r1, r1
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080A2236
_080A224C:
	adds r1, r4, 0
	lsls r0, r5, 16
	lsrs r3, r0, 16
	cmp r1, 0
	bne _080A2224
_080A2256:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2218

	thumb_func_start sub_80A2260
sub_80A2260: @ 80A2260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x4]
	movs r0, 0
	mov r9, r0
	cmp r4, 0
	beq _080A231C
	lsls r1, 24
	str r1, [sp, 0x8]
_080A228A:
	movs r0, 0x1
	ands r0, r4
	lsrs r4, 1
	str r4, [sp, 0xC]
	movs r1, 0x10
	add r1, r9
	mov r10, r1
	cmp r0, 0
	beq _080A230E
	movs r4, 0
	ldr r2, =gUnknown_02037B14
	mov r8, r2
	ldr r1, [sp]
	lsls r0, r1, 24
	ldr r2, [sp, 0x4]
	lsls r1, r2, 24
	ldr r2, [sp, 0x8]
	asrs r2, 24
	mov r12, r2
	movs r5, 0x1F
	asrs r7, r0, 24
	asrs r6, r1, 24
_080A22B6:
	mov r0, r9
	adds r2, r0, r4
	lsls r2, 1
	add r2, r8
	ldr r1, [r2]
	lsls r1, 27
	lsrs r1, 27
	add r1, r12
	ands r1, r5
	ldrb r3, [r2]
	movs r0, 0x20
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r2]
	lsls r1, 22
	lsrs r1, 27
	adds r1, r7
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 5
	ldrh r3, [r2]
	ldr r0, =0xfffffc1f
	ands r0, r3
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r2]
	lsls r1, 17
	lsrs r1, 27
	adds r1, r6
	ands r1, r5
	lsls r1, 2
	ldrb r3, [r2, 0x1]
	movs r0, 0x7D
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080A22B6
_080A230E:
	ldr r4, [sp, 0xC]
	mov r1, r10
	lsls r0, r1, 16
	lsrs r0, 16
	mov r9, r0
	cmp r4, 0
	bne _080A228A
_080A231C:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2260

	thumb_func_start sub_80A2334
sub_80A2334: @ 80A2334
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r1, r0, 0
	movs r3, 0
	cmp r1, 0
	beq _080A237E
	ldr r0, =gUnknown_02037B14
	mov r8, r0
	ldr r0, =gUnknown_02037714
	mov r12, r0
_080A234A:
	movs r0, 0x1
	ands r0, r1
	lsrs r4, r1, 1
	adds r5, r3, 0
	adds r5, 0x10
	cmp r0, 0
	beq _080A2374
	movs r2, 0
	mov r7, r8
	mov r6, r12
_080A235E:
	adds r0, r3, r2
	lsls r0, 1
	adds r1, r0, r7
	adds r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080A235E
_080A2374:
	adds r1, r4, 0
	lsls r0, r5, 16
	lsrs r3, r0, 16
	cmp r1, 0
	bne _080A234A
_080A237E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2334

	thumb_func_start sub_80A2390
sub_80A2390: @ 80A2390
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_02037FD4
	ldrb r2, [r3, 0xA]
	movs r1, 0x79
	negs r1, r1
	ands r1, r2
	movs r2, 0x10
	orrs r1, r2
	strb r1, [r3, 0xA]
	bl sub_80A23B4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2390

	thumb_func_start sub_80A23B4
sub_80A23B4: @ 80A23B4
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r2, =gUnknown_02037FD4
	ldrh r0, [r2, 0x4]
	movs r3, 0xF8
	lsls r3, 3
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2, 0x4]
	movs r1, 0x3F
	ands r1, r4
	ldrb r3, [r2, 0x8]
	movs r0, 0x40
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldrb r0, [r2, 0x7]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x7]
	ldrb r1, [r2, 0x9]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	cmp r4, 0x2
	bne _080A2406
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02037B14
	ldr r2, =0x01000200
	mov r0, sp
	bl CpuSet
_080A2406:
	cmp r4, 0
	bne _080A241C
	mov r0, sp
	adds r0, 0x2
	ldr r2, =0x00007fff
	adds r1, r2, 0
	strh r1, [r0]
	ldr r1, =gUnknown_02037B14
	ldr r2, =0x01000200
	bl CpuSet
_080A241C:
	bl fade_and_return_progress_probably
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A23B4

	thumb_func_start pal_fade__1
pal_fade__1: @ 80A2438
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r4, =gUnknown_02037FD4
	ldrb r1, [r4, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080A2458
	movs r0, 0
	b _080A2792
	.pool
_080A2458:
	bl sub_80A29BC
	lsls r0, 24
	cmp r0, 0
	beq _080A2466
	ldrb r0, [r4, 0x7]
	b _080A2790
_080A2466:
	ldrb r1, [r4, 0xA]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A247C
	movs r2, 0x80
	lsls r2, 1
	movs r0, 0x80
	lsls r0, 2
	mov r10, r0
	b _080A2484
_080A247C:
	movs r2, 0
	movs r1, 0x80
	lsls r1, 1
	mov r10, r1
_080A2484:
	ldr r1, =gUnknown_02037FD4
	ldrb r0, [r1, 0x8]
	lsls r0, 26
	lsrs r0, 26
	cmp r0, 0x1
	beq _080A2544
	cmp r0, 0x1
	bgt _080A24A0
	cmp r0, 0
	beq _080A24AE
	b _080A2694
	.pool
_080A24A0:
	cmp r0, 0x2
	bne _080A24A6
	b _080A25A8
_080A24A6:
	cmp r0, 0x3
	bne _080A24AC
	b _080A2630
_080A24AC:
	b _080A2694
_080A24AE:
	adds r7, r2, 0
	cmp r7, r10
	bcc _080A24B6
	b _080A2694
_080A24B6:
	lsls r2, r7, 1
	ldr r0, =gUnknown_02037714
	adds r0, r2, r0
	ldr r1, [r0]
	lsls r3, r1, 27
	lsls r0, r1, 22
	lsrs r0, 27
	mov r12, r0
	lsls r1, 17
	lsrs r1, 27
	mov r8, r1
	ldr r0, =gUnknown_02037B14
	adds r2, r0
	mov r9, r2
	ldr r1, [r2]
	lsls r2, r1, 27
	lsrs r2, 3
	movs r4, 0xFE
	lsls r4, 24
	adds r2, r4
	lsls r0, r1, 22
	lsrs r0, 27
	subs r0, 0x2
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 17
	lsrs r1, 27
	subs r1, 0x2
	lsls r1, 24
	lsrs r4, r1, 24
	lsrs r6, r2, 24
	asrs r2, 24
	lsrs r3, 3
	asrs r0, r3, 24
	cmp r2, r0
	bge _080A2500
	lsrs r6, r3, 24
_080A2500:
	lsls r0, r5, 24
	asrs r0, 24
	mov r2, r12
	lsls r1, r2, 24
	cmp r0, r12
	bge _080A250E
	lsrs r5, r1, 24
_080A250E:
	lsls r0, r4, 24
	asrs r0, 24
	mov r3, r8
	lsls r1, r3, 24
	cmp r0, r8
	bge _080A251C
	lsrs r4, r1, 24
_080A251C:
	lsls r1, r6, 24
	asrs r1, 24
	lsls r0, r5, 24
	asrs r0, 19
	orrs r1, r0
	lsls r0, r4, 24
	asrs r0, 14
	orrs r1, r0
	mov r4, r9
	strh r1, [r4]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, r10
	bcc _080A24B6
	b _080A2694
	.pool
_080A2544:
	adds r7, r2, 0
	cmp r7, r10
	bcc _080A254C
	b _080A2694
_080A254C:
	lsls r1, r7, 1
	ldr r0, =gUnknown_02037B14
	adds r2, r1, r0
	ldr r1, [r2]
	lsls r0, r1, 27
	lsrs r0, 3
	movs r3, 0x80
	lsls r3, 18
	adds r0, r3
	lsrs r6, r0, 24
	lsls r0, r1, 22
	lsrs r0, 27
	adds r5, r0, 0x2
	lsls r1, 17
	lsrs r1, 27
	adds r4, r1, 0x2
	cmp r6, 0x1F
	ble _080A2572
	movs r6, 0x1F
_080A2572:
	lsls r0, r5, 24
	asrs r0, 24
	cmp r0, 0x1F
	ble _080A257C
	movs r5, 0x1F
_080A257C:
	lsls r0, r4, 24
	asrs r0, 24
	cmp r0, 0x1F
	ble _080A2586
	movs r4, 0x1F
_080A2586:
	lsls r1, r6, 24
	asrs r1, 24
	lsls r0, r5, 24
	asrs r0, 19
	orrs r1, r0
	lsls r0, r4, 24
	asrs r0, 14
	orrs r1, r0
	strh r1, [r2]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, r10
	bcc _080A254C
	b _080A2694
	.pool
_080A25A8:
	adds r7, r2, 0
	cmp r7, r10
	bcs _080A2694
_080A25AE:
	lsls r2, r7, 1
	ldr r0, =gUnknown_02037714
	adds r0, r2, r0
	ldr r1, [r0]
	lsls r3, r1, 27
	lsls r0, r1, 22
	lsrs r0, 27
	mov r12, r0
	lsls r1, 17
	lsrs r1, 27
	mov r8, r1
	ldr r0, =gUnknown_02037B14
	adds r2, r0
	ldr r1, [r2]
	lsls r0, r1, 27
	lsrs r0, 3
	movs r4, 0x80
	lsls r4, 18
	adds r0, r4
	lsrs r6, r0, 24
	lsls r0, r1, 22
	lsrs r0, 27
	adds r5, r0, 0x2
	lsls r1, 17
	lsrs r1, 27
	adds r4, r1, 0x2
	lsrs r3, 3
	asrs r0, r3, 24
	cmp r6, r0
	ble _080A25EC
	lsrs r6, r3, 24
_080A25EC:
	lsls r0, r5, 24
	asrs r0, 24
	mov r3, r12
	lsls r1, r3, 24
	cmp r0, r12
	ble _080A25FA
	lsrs r5, r1, 24
_080A25FA:
	lsls r0, r4, 24
	asrs r0, 24
	mov r3, r8
	lsls r1, r3, 24
	cmp r0, r8
	ble _080A2608
	lsrs r4, r1, 24
_080A2608:
	lsls r1, r6, 24
	asrs r1, 24
	lsls r0, r5, 24
	asrs r0, 19
	orrs r1, r0
	lsls r0, r4, 24
	asrs r0, 14
	orrs r1, r0
	strh r1, [r2]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, r10
	bcc _080A25AE
	b _080A2694
	.pool
_080A2630:
	adds r7, r2, 0
	cmp r7, r10
	bcs _080A2694
	ldr r4, =gUnknown_02037B14
	mov r8, r4
_080A263A:
	lsls r0, r7, 1
	mov r1, r8
	adds r3, r0, r1
	ldr r1, [r3]
	lsls r2, r1, 27
	lsrs r2, 3
	movs r4, 0xFE
	lsls r4, 24
	adds r2, r4
	lsls r0, r1, 22
	lsrs r0, 27
	subs r0, 0x2
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 17
	lsrs r1, 27
	subs r1, 0x2
	lsls r1, 24
	lsrs r4, r1, 24
	lsrs r6, r2, 24
	cmp r2, 0
	bge _080A2668
	movs r6, 0
_080A2668:
	lsls r0, r5, 24
	cmp r0, 0
	bge _080A2670
	movs r5, 0
_080A2670:
	lsls r0, r4, 24
	cmp r0, 0
	bge _080A2678
	movs r4, 0
_080A2678:
	lsls r1, r6, 24
	asrs r1, 24
	lsls r0, r5, 24
	asrs r0, 19
	orrs r1, r0
	lsls r0, r4, 24
	asrs r0, 14
	orrs r1, r0
	strh r1, [r3]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, r10
	bcc _080A263A
_080A2694:
	ldr r0, =gUnknown_02037FD4
	ldrb r2, [r0, 0xA]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r3, 0x5
	negs r3, r3
	ands r3, r2
	orrs r3, r1
	ldr r1, =gUnknown_02037FD4
	strb r3, [r1, 0xA]
	movs r0, 0x4
	ands r0, r3
	cmp r0, 0
	beq _080A26C4
	ldrb r0, [r1, 0x7]
	b _080A2790
	.pool
_080A26C4:
	ldr r2, =gUnknown_02037FD4
	ldrh r4, [r2, 0x4]
	lsls r5, r4, 21
	lsrs r0, r5, 27
	lsls r2, r3, 25
	lsrs r1, r2, 28
	subs r0, r1
	cmp r0, 0
	bge _080A26E8
	ldr r0, =0xfffff83f
	ands r0, r4
	ldr r3, =gUnknown_02037FD4
	strh r0, [r3, 0x4]
	b _080A26FE
	.pool
_080A26E8:
	lsrs r1, r5, 27
	lsrs r0, r2, 28
	subs r1, r0
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 6
	ldr r0, =0xfffff83f
	ands r0, r4
	orrs r0, r1
	ldr r4, =gUnknown_02037FD4
	strh r0, [r4, 0x4]
_080A26FE:
	ldr r1, =gUnknown_02037FD4
	ldrh r0, [r1, 0x4]
	movs r1, 0xF8
	lsls r1, 3
	ands r1, r0
	cmp r1, 0
	bne _080A278C
	ldr r2, =gUnknown_02037FD4
	ldrb r0, [r2, 0x8]
	lsls r0, 26
	lsrs r0, 26
	cmp r0, 0x1
	beq _080A2750
	cmp r0, 0x1
	bgt _080A272C
	cmp r0, 0
	beq _080A2736
	b _080A2778
	.pool
_080A272C:
	cmp r0, 0x2
	beq _080A2736
	cmp r0, 0x3
	beq _080A276C
	b _080A2778
_080A2736:
	ldr r0, =gUnknown_02037714
	ldr r1, =gUnknown_02037B14
	ldr r2, =0x04000100
	bl CpuSet
	b _080A2778
	.pool
_080A2750:
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	ldr r1, =gUnknown_02037B14
	ldr r2, =0x05000100
	mov r0, sp
	bl CpuSet
	b _080A2778
	.pool
_080A276C:
	str r1, [sp, 0x4]
	add r0, sp, 0x4
	ldr r1, =gUnknown_02037B14
	ldr r2, =0x05000100
	bl CpuSet
_080A2778:
	ldr r2, =gUnknown_02037FD4
	ldrb r1, [r2, 0x9]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldrb r0, [r2, 0xA]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0xA]
_080A278C:
	ldr r3, =gUnknown_02037FD4
	ldrb r0, [r3, 0x7]
_080A2790:
	lsrs r0, 7
_080A2792:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pal_fade__1

	thumb_func_start sub_80A27B0
sub_80A27B0: @ 80A27B0
	push {r4-r7,lr}
	ldr r5, [sp, 0x14]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r7, =gUnknown_02037FD4
	str r0, [r7]
	movs r0, 0x3F
	ands r1, r0
	ldrb r4, [r7, 0x4]
	movs r6, 0x40
	negs r6, r6
	adds r0, r6, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r7, 0x4]
	ldrb r0, [r7, 0x8]
	ands r6, r0
	orrs r6, r1
	strb r6, [r7, 0x8]
	movs r0, 0x1F
	adds r1, r2, 0
	ands r1, r0
	lsls r1, 6
	ldrh r4, [r7, 0x4]
	ldr r0, =0xfffff83f
	ands r0, r4
	orrs r0, r1
	strh r0, [r7, 0x4]
	lsls r4, r3, 3
	ldrb r1, [r7, 0x5]
	movs r0, 0x7
	ands r0, r1
	orrs r0, r4
	strb r0, [r7, 0x5]
	ldrb r0, [r7, 0x7]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r7, 0x7]
	ldrb r1, [r7, 0x9]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	movs r1, 0x1
	ands r5, r1
	lsls r5, 2
	subs r1, 0x6
	ands r0, r1
	orrs r0, r5
	subs r1, 0x4
	ands r0, r1
	strb r0, [r7, 0x9]
	cmp r2, r3
	bcs _080A2840
	movs r0, 0x41
	negs r0, r0
	ands r6, r0
	b _080A2844
	.pool
_080A2840:
	movs r0, 0x40
	orrs r6, r0
_080A2844:
	strb r6, [r7, 0x8]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A27B0

	thumb_func_start pal_fade__2
pal_fade__2: @ 80A284C
	push {r4-r7,lr}
	ldr r2, =gUnknown_02037FD4
	ldrb r1, [r2, 0x7]
	movs r0, 0x80
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	bne _080A2864
	movs r0, 0
	b _080A295C
	.pool
_080A2864:
	ldrb r2, [r4, 0x4]
	lsls r1, r2, 26
	ldrb r3, [r4, 0x8]
	lsls r0, r3, 26
	cmp r1, r0
	bcs _080A2886
	lsrs r0, r1, 26
	adds r0, 0x1
	movs r1, 0x3F
	ands r0, r1
	movs r1, 0x40
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x4]
	movs r0, 0x2
	b _080A295C
_080A2886:
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	strb r0, [r4, 0x4]
	movs r0, 0x40
	ands r0, r3
	cmp r0, 0
	bne _080A28E4
	ldrh r1, [r4, 0x4]
	lsls r0, r1, 21
	lsrs r0, 27
	adds r0, 0x1
	movs r7, 0x1F
	ands r0, r7
	lsls r0, 6
	ldr r6, =0xfffff83f
	adds r3, r6, 0
	ands r3, r1
	orrs r3, r0
	strh r3, [r4, 0x4]
	lsls r5, r3, 21
	ldrb r0, [r4, 0x5]
	lsrs r1, r5, 27
	lsrs r0, 3
	cmp r1, r0
	bls _080A2930
	ldrb r2, [r4, 0x9]
	lsls r1, r2, 28
	lsrs r1, 31
	adds r1, 0x1
	movs r0, 0x1
	ands r1, r0
	lsls r1, 3
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x9]
	lsrs r0, r5, 27
	subs r0, 0x1
	ands r0, r7
	lsls r0, 6
	ands r3, r6
	b _080A292C
	.pool
_080A28E4:
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 21
	lsrs r0, r1, 27
	subs r0, 0x1
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 6
	ldr r5, =0xfffff83f
	adds r3, r5, 0
	ands r3, r2
	orrs r3, r0
	strh r3, [r4, 0x4]
	lsrs r1, 27
	subs r1, 0x1
	ldrb r0, [r4, 0x5]
	lsrs r0, 3
	cmp r1, r0
	bge _080A2930
	ldrb r2, [r4, 0x9]
	lsls r1, r2, 28
	lsrs r1, 31
	adds r1, 0x1
	movs r0, 0x1
	ands r1, r0
	lsls r1, 3
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x9]
	lsls r0, r3, 21
	lsrs r0, 27
	adds r0, 0x1
	ands r0, r6
	lsls r0, 6
	ands r3, r5
_080A292C:
	orrs r3, r0
	strh r3, [r4, 0x4]
_080A2930:
	ldrb r1, [r4, 0x9]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A2958
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A294E
	movs r0, 0
	str r0, [r4]
	ldrh r1, [r4, 0x4]
	ldr r0, =0xfffff83f
	ands r0, r1
	strh r0, [r4, 0x4]
_080A294E:
	ldrb r1, [r4, 0x9]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x9]
_080A2958:
	ldrb r0, [r4, 0x7]
	lsrs r0, 7
_080A295C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end pal_fade__2

	thumb_func_start sub_80A2968
sub_80A2968: @ 80A2968
	push {r4,lr}
	ldr r4, =gUnknown_02037FD4
	ldrh r1, [r4]
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r4, 0x4]
	lsls r1, 21
	lsrs r1, 27
	movs r0, 0x54
	bl SetGpuReg
	ldrb r1, [r4, 0x9]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A29AC
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	negs r1, r1
	ands r0, r1
	strb r0, [r4, 0x9]
	movs r0, 0
	str r0, [r4]
	ldrh r1, [r4, 0x4]
	ldr r0, =0xfffff83f
	ands r0, r1
	strh r0, [r4, 0x4]
	ldrb r1, [r4, 0x7]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r4, 0x7]
_080A29AC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2968

	thumb_func_start sub_80A29BC
sub_80A29BC: @ 80A29BC
	push {r4,lr}
	ldr r3, =gUnknown_02037FD4
	ldrb r4, [r3, 0xA]
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _080A2A18
	ldr r2, [r3, 0x8]
	movs r0, 0xF8
	lsls r0, 9
	ands r0, r2
	movs r1, 0x80
	lsls r1, 7
	cmp r0, r1
	bne _080A29FC
	ldrb r1, [r3, 0x7]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r3, 0x7]
	movs r0, 0x3
	negs r0, r0
	ands r0, r4
	strb r0, [r3, 0xA]
	ldr r0, [r3, 0x8]
	ldr r1, =0xfffe0fff
	ands r0, r1
	str r0, [r3, 0x8]
	b _080A2A10
	.pool
_080A29FC:
	lsls r0, r2, 15
	lsrs r0, 27
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	lsls r0, 12
	ldr r1, =0xfffe0fff
	ands r1, r2
	orrs r1, r0
	str r1, [r3, 0x8]
_080A2A10:
	movs r0, 0x1
	b _080A2A1A
	.pool
_080A2A18:
	movs r0, 0
_080A2A1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A29BC

	thumb_func_start sub_80A2A20
sub_80A2A20: @ 80A2A20
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 16
	lsrs r6, r2, 16
	movs r5, 0
	cmp r4, 0
	beq _080A2A54
_080A2A32:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _080A2A46
	adds r0, r5, 0
	movs r1, 0x10
	adds r2, r7, 0
	adds r3, r6, 0
	bl BlendPalette
_080A2A46:
	lsrs r4, 1
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r4, 0
	bne _080A2A32
_080A2A54:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2A20

	thumb_func_start sub_80A2A5C
sub_80A2A5C: @ 80A2A5C
	push {r4,r5,lr}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gUnknown_02037714
	ldr r5, =gUnknown_02037B14
	ldr r3, =0x040000d4
	str r4, [r3]
	str r5, [r3, 0x4]
	ldr r4, =0x84000100
	str r4, [r3, 0x8]
	ldr r3, [r3, 0x8]
	bl sub_80A2A20
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2A5C

	thumb_func_start TintPalette_GrayScale
TintPalette_GrayScale: @ 80A2A90
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0
	beq _080A2AD8
	movs r6, 0x1F
	adds r5, r1, 0
_080A2AA0:
	ldrh r1, [r4]
	movs r2, 0x1F
	ands r2, r1
	lsls r1, 16
	lsrs r3, r1, 21
	ands r3, r6
	lsrs r1, 26
	ands r1, r6
	movs r0, 0x4C
	muls r2, r0
	movs r0, 0x97
	muls r0, r3
	adds r2, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	adds r2, r0
	asrs r2, 8
	lsls r0, r2, 10
	lsls r1, r2, 5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r4]
	adds r4, 0x2
	subs r5, 0x1
	cmp r5, 0
	bne _080A2AA0
_080A2AD8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end TintPalette_GrayScale

	thumb_func_start sub_80A2AE0
sub_80A2AE0: @ 80A2AE0
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0
	beq _080A2B34
	movs r6, 0x1F
	ldr r7, =gUnknown_0852489C
	adds r5, r1, 0
_080A2AF2:
	ldrh r1, [r4]
	movs r2, 0x1F
	ands r2, r1
	lsls r1, 16
	lsrs r3, r1, 21
	ands r3, r6
	lsrs r1, 26
	ands r1, r6
	movs r0, 0x4C
	muls r2, r0
	movs r0, 0x97
	muls r0, r3
	adds r2, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	adds r2, r0
	asrs r2, 8
	cmp r2, 0x1F
	bls _080A2B1E
	movs r2, 0x1F
_080A2B1E:
	adds r0, r2, r7
	ldrb r2, [r0]
	lsls r0, r2, 10
	lsls r1, r2, 5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r4]
	adds r4, 0x2
	subs r5, 0x1
	cmp r5, 0
	bne _080A2AF2
_080A2B34:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2AE0

	thumb_func_start TintPalette_SepiaTone
TintPalette_SepiaTone: @ 80A2B40
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0
	beq _080A2BA2
	movs r7, 0x1F
	adds r6, r1, 0
_080A2B50:
	ldrh r0, [r5]
	movs r1, 0x1F
	ands r1, r0
	lsls r0, 16
	lsrs r2, r0, 21
	ands r2, r7
	lsrs r3, r0, 26
	ands r3, r7
	movs r0, 0x4C
	muls r1, r0
	movs r0, 0x97
	muls r0, r2
	adds r1, r0
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r3
	adds r1, r0
	asrs r1, 8
	ldr r0, =0x00000133
	muls r0, r1
	lsls r0, 16
	lsrs r2, r0, 24
	lsls r0, r1, 24
	lsrs r4, r0, 24
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 20
	lsrs r3, r0, 24
	cmp r2, 0x1F
	ble _080A2B90
	movs r2, 0x1F
_080A2B90:
	lsls r0, r3, 10
	lsls r1, r4, 5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r5]
	adds r5, 0x2
	subs r6, 0x1
	cmp r6, 0
	bne _080A2B50
_080A2BA2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TintPalette_SepiaTone

	thumb_func_start sub_80A2BAC
sub_80A2BAC: @ 80A2BAC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	ldr r0, [sp, 0x1C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	lsls r3, 16
	lsrs r3, 16
	mov r8, r3
	lsls r0, 16
	lsrs r0, 16
	mov r12, r0
	cmp r1, 0
	beq _080A2C38
	movs r7, 0x1F
	adds r6, r1, 0
_080A2BD6:
	ldrh r0, [r5]
	movs r1, 0x1F
	ands r1, r0
	lsls r0, 16
	lsrs r2, r0, 21
	ands r2, r7
	lsrs r3, r0, 26
	ands r3, r7
	movs r0, 0x4C
	muls r1, r0
	movs r0, 0x97
	muls r0, r2
	adds r1, r0
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r3
	adds r1, r0
	asrs r1, 8
	mov r0, r9
	muls r0, r1
	lsls r0, 16
	lsrs r4, r0, 24
	mov r0, r8
	muls r0, r1
	lsls r0, 16
	lsrs r2, r0, 24
	mov r0, r12
	muls r0, r1
	lsls r0, 16
	lsrs r3, r0, 24
	cmp r4, 0x1F
	ble _080A2C1A
	movs r4, 0x1F
_080A2C1A:
	cmp r2, 0x1F
	ble _080A2C20
	movs r2, 0x1F
_080A2C20:
	cmp r3, 0x1F
	ble _080A2C26
	movs r3, 0x1F
_080A2C26:
	lsls r0, r3, 10
	lsls r1, r2, 5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r5]
	adds r5, 0x2
	subs r6, 0x1
	cmp r6, 0
	bne _080A2BD6
_080A2C38:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2BAC

	thumb_func_start sub_80A2C44
sub_80A2C44: @ 80A2C44
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	adds r4, r1, 0
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r5, [sp, 0x28]
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r1, 24
	lsrs r1, 24
	lsls r5, 24
	lsrs r5, 24
	mov r8, r5
	ldr r0, =sub_80A2D54
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	strh r7, [r1, 0x8]
	strh r6, [r1, 0xA]
	lsls r4, 24
	asrs r4, 24
	cmp r4, 0
	blt _080A2CA4
	strh r4, [r1, 0xE]
	movs r0, 0x1
	b _080A2CAC
	.pool
_080A2CA4:
	movs r0, 0
	strh r0, [r1, 0xE]
	negs r0, r4
	adds r0, 0x1
_080A2CAC:
	strh r0, [r1, 0xC]
	lsls r4, r5, 2
	cmp r6, r7
	bcs _080A2CC4
	ldr r0, =gTasks
	adds r1, r4, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0xC]
_080A2CC4:
	adds r0, r5, 0
	movs r1, 0x5
	mov r2, r10
	bl SetWordTaskArg
	ldr r0, =gTasks
	adds r1, r4, r5
	lsls r1, 3
	adds r1, r0
	mov r0, r9
	strh r0, [r1, 0x16]
	mov r2, r8
	strh r2, [r1, 0x18]
	ldr r1, [r1]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2C44

	thumb_func_start sub_80A2CF8
sub_80A2CF8: @ 80A2CF8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r4, =sub_80A2D54
	ldr r1, =gTasks
_080A2D04:
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	bne _080A2D24
	ldr r0, [r1]
	cmp r0, r4
	bne _080A2D24
	movs r5, 0x18
	ldrsh r0, [r1, r5]
	cmp r0, r3
	bne _080A2D24
	movs r0, 0x1
	b _080A2D2E
	.pool
_080A2D24:
	adds r1, 0x28
	adds r2, 0x1
	cmp r2, 0xF
	ble _080A2D04
	movs r0, 0
_080A2D2E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2CF8

	thumb_func_start sub_80A2D34
sub_80A2D34: @ 80A2D34
	push {lr}
	b _080A2D3C
_080A2D38:
	bl DestroyTask
_080A2D3C:
	ldr r0, =sub_80A2D54
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080A2D38
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A2D34

	thumb_func_start sub_80A2D54
sub_80A2D54: @ 80A2D54
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	adds r0, r5, 0
	movs r1, 0x5
	bl GetWordTaskArg
	adds r3, r0, 0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _080A2DCC
	movs r0, 0
	strh r0, [r4, 0x8]
	ldrb r1, [r4]
	ldrh r2, [r4, 0xE]
	adds r0, r3, 0
	bl sub_80A2A20
	ldrh r1, [r4]
	movs r6, 0
	ldrsh r0, [r4, r6]
	ldrh r3, [r4, 0x2]
	movs r6, 0x2
	ldrsh r2, [r4, r6]
	cmp r0, r2
	bne _080A2DAC
	adds r0, r5, 0
	bl DestroyTask
	b _080A2DCC
	.pool
_080A2DAC:
	ldrh r0, [r4, 0x4]
	adds r1, r0
	strh r1, [r4]
	lsls r0, 16
	cmp r0, 0
	blt _080A2DC2
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r2
	blt _080A2DCC
	b _080A2DCA
_080A2DC2:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r2
	bgt _080A2DCC
_080A2DCA:
	strh r3, [r4]
_080A2DCC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2D54

	.align 2, 0 @ Don't pad with nop.
