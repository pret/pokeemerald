	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8122CDC
sub_8122CDC: @ 8122CDC
	push {lr}
	lsls r2, r1, 24
	lsrs r2, 24
	movs r1, 0
	bl sub_8122CF8
_08122CE8:
	bl sub_8122DB0
	lsls r0, 24
	cmp r0, 0
	bne _08122CE8
	pop {r0}
	bx r0
	thumb_func_end sub_8122CDC

	thumb_func_start sub_8122CF8
sub_8122CF8: @ 8122CF8
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gUnknown_0203A144
	str r0, [r3]
	movs r1, 0x79
	adds r1, r0
	mov r12, r1
	movs r1, 0
	mov r5, r12
	strb r1, [r5]
	adds r0, 0x78
	strb r2, [r0]
	ldr r1, [r3]
	cmp r2, 0x1
	bne _08122D28
	ldr r0, =sub_8123254
	b _08122D2A
	.pool
_08122D28:
	ldr r0, =sub_81230C4
_08122D2A:
	str r0, [r1, 0x18]
	cmp r4, 0
	beq _08122D64
	ldr r1, [r3]
	ldr r0, [r4]
	lsls r0, 30
	lsrs r0, 30
	adds r1, 0x80
	strb r0, [r1]
	ldr r1, [r3]
	ldr r0, [r4]
	lsls r0, 28
	lsrs r0, 30
	adds r1, 0x81
	strb r0, [r1]
	ldr r1, [r3]
	ldr r0, [r4]
	lsls r0, 23
	lsrs r0, 27
	adds r1, 0x82
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x83
	movs r1, 0x1
	strb r1, [r0]
	b _08122D80
	.pool
_08122D64:
	ldr r0, [r3]
	adds r0, 0x80
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, 0x81
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, 0x82
	movs r1, 0x1C
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, 0x83
	strb r4, [r0]
_08122D80:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8122CF8

	thumb_func_start sub_8122D88
sub_8122D88: @ 8122D88
	push {r4,lr}
	ldr r4, =gUnknown_0203A144
	str r0, [r4]
	bl sub_81238AC
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x54
	ldrh r1, [r0]
	adds r0, 0x20
	strh r1, [r0]
	subs r0, 0x1E
	ldrh r1, [r0]
	adds r0, 0x20
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8122D88

	thumb_func_start sub_8122DB0
sub_8122DB0: @ 8122DB0
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	adds r0, 0x79
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _08122DC2
	b _0812300C
_08122DC2:
	lsls r0, 2
	ldr r1, =_08122DD4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08122DD4:
	.4byte _08122DF4
	.4byte _08122E2C
	.4byte _08122E78
	.4byte _08122E94
	.4byte _08122EB0
	.4byte _08122ECC
	.4byte _08122F10
	.4byte _08122F8C
_08122DF4:
	ldr r0, =gUnknown_0203A144
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x83
	ldrb r0, [r0]
	cmp r0, 0
	beq _08122E18
	adds r0, r1, 0
	adds r0, 0x80
	ldrb r0, [r0]
	ldr r1, =gUnknown_0859F77C
	movs r2, 0
	str r2, [sp]
	b _08122E52
	.pool
_08122E18:
	ldr r0, =gUnknown_0859F77C
	ldr r1, =0x06008000
	bl LZ77UnCompVram
	b _08123014
	.pool
_08122E2C:
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	adds r0, 0x83
	ldrb r0, [r0]
	cmp r0, 0
	beq _08122E64
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _08122E44
	b _08123014
_08122E44:
	ldr r0, [r4]
	adds r0, 0x80
	ldrb r0, [r0]
	ldr r1, =gUnknown_085A04E0
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0
_08122E52:
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _08123014
	.pool
_08122E64:
	ldr r0, =gUnknown_085A04E0
	ldr r1, =0x0600e000
	bl LZ77UnCompVram
	b _08123014
	.pool
_08122E78:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _08122E84
	b _08123014
_08122E84:
	ldr r0, =gUnknown_0859F73C
	movs r1, 0x70
	movs r2, 0x60
	bl LoadPalette
	b _08123014
	.pool
_08122E94:
	ldr r0, =gUnknown_0859F60C
	ldr r1, =gUnknown_0203A144
	ldr r1, [r1]
	movs r2, 0xC2
	lsls r2, 1
	adds r1, r2
	bl LZ77UnCompWram
	b _08123014
	.pool
_08122EB0:
	ldr r0, =gUnknown_0859F650
	ldr r1, =gUnknown_0203A144
	ldr r1, [r1]
	movs r5, 0xA1
	lsls r5, 2
	adds r1, r5
	bl LZ77UnCompWram
	b _08123014
	.pool
_08122ECC:
	bl sub_81238AC
	ldr r4, =gUnknown_0203A144
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x54
	ldrh r1, [r0]
	adds r0, 0x20
	strh r1, [r0]
	subs r0, 0x1E
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x76
	strh r0, [r1]
	ldrh r0, [r2]
	bl sub_8123EB4
	ldr r1, [r4]
	strh r0, [r1]
	ldrh r0, [r1]
	bl get_flagnr_blue_points
	ldr r1, [r4]
	strb r0, [r1, 0x2]
	ldr r1, [r4]
	adds r0, r1, 0x4
	ldrh r1, [r1]
	movs r2, 0x10
	bl GetMapName
	b _08123014
	.pool
_08122F10:
	ldr r0, =gUnknown_0203A144
	ldr r4, [r0]
	adds r0, r4, 0
	adds r0, 0x78
	ldrb r1, [r0]
	cmp r1, 0
	bne _08122F3C
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81236C4
	b _08123014
	.pool
_08122F3C:
	adds r1, r4, 0
	adds r1, 0x54
	ldrh r0, [r1]
	lsls r0, 3
	subs r0, 0x34
	adds r2, r4, 0
	adds r2, 0x5C
	movs r3, 0
	strh r0, [r2]
	movs r0, 0x56
	adds r0, r4
	mov r12, r0
	ldrh r0, [r0]
	lsls r0, 3
	subs r0, 0x44
	adds r5, r4, 0
	adds r5, 0x5E
	strh r0, [r5]
	ldrh r1, [r1]
	adds r0, r4, 0
	adds r0, 0x64
	strh r1, [r0]
	mov r0, r12
	ldrh r1, [r0]
	adds r0, r4, 0
	adds r0, 0x66
	strh r1, [r0]
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r2, 0x80
	str r2, [sp]
	str r2, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r2, 0x38
	movs r3, 0x48
	bl sub_81236C4
	b _08123014
_08122F8C:
	bl sub_8123FB0
	bl sub_81237B4
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	movs r1, 0
	str r1, [r0, 0x1C]
	str r1, [r0, 0x20]
	adds r0, 0x7A
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x7E
	strb r1, [r0]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x83
	ldrb r0, [r0]
	cmp r0, 0
	beq _08123002
	adds r0, r1, 0
	adds r0, 0x80
	ldrb r0, [r0]
	movs r1, 0x3
	movs r2, 0x2
	bl SetBgAttribute
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x80
	ldrb r0, [r0]
	adds r1, 0x81
	ldrb r2, [r1]
	movs r1, 0x1
	bl SetBgAttribute
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x80
	ldrb r0, [r0]
	adds r1, 0x82
	ldrb r2, [r1]
	movs r1, 0x2
	bl SetBgAttribute
	ldr r0, [r4]
	adds r0, 0x80
	ldrb r0, [r0]
	movs r1, 0x6
	movs r2, 0x1
	bl SetBgAttribute
	ldr r0, [r4]
	adds r0, 0x80
	ldrb r0, [r0]
	movs r1, 0x4
	movs r2, 0x1
	bl SetBgAttribute
_08123002:
	ldr r1, [r4]
	adds r1, 0x79
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0812300C:
	movs r0, 0
	b _08123022
	.pool
_08123014:
	ldr r0, =gUnknown_0203A144
	ldr r1, [r0]
	adds r1, 0x79
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_08123022:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8122DB0

	thumb_func_start sub_8123030
sub_8123030: @ 8123030
	push {lr}
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0xE0
	lsls r0, 2
	lsls r1, 24
	lsrs r1, 24
	bl BlendPalettes
	ldr r0, =gPlttBufferFaded + 0xE0
	ldr r1, =gPlttBufferUnfaded + 0xE0
	movs r2, 0x30
	bl CpuSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8123030

	thumb_func_start sub_812305C
sub_812305C: @ 812305C
	push {r4,lr}
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	ldr r0, [r0, 0x1C]
	cmp r0, 0
	beq _08123080
	bl DestroySprite
	ldr r0, [r4]
	adds r0, 0x58
	ldrh r0, [r0]
	bl FreeSpriteTilesByTag
	ldr r0, [r4]
	adds r0, 0x5A
	ldrh r0, [r0]
	bl FreeSpritePaletteByTag
_08123080:
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	cmp r0, 0
	beq _081230A0
	bl DestroySprite
	ldr r0, [r4]
	adds r0, 0x70
	ldrh r0, [r0]
	bl FreeSpriteTilesByTag
	ldr r0, [r4]
	adds r0, 0x72
	ldrh r0, [r0]
	bl FreeSpritePaletteByTag
_081230A0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812305C

	thumb_func_start sub_81230AC
sub_81230AC: @ 81230AC
	push {lr}
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81230AC

	thumb_func_start sub_81230C4
sub_81230C4: @ 81230C4
	push {r4,lr}
	movs r4, 0
	ldr r2, =gUnknown_0203A144
	ldr r0, [r2]
	adds r0, 0x7B
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, 0x7C
	strb r4, [r0]
	ldr r3, =gMain
	ldrh r1, [r3, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081230F6
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x56
	ldrh r0, [r0]
	cmp r0, 0x2
	bls _081230F6
	adds r1, 0x7C
	movs r0, 0xFF
	strb r0, [r1]
	movs r4, 0x1
_081230F6:
	ldrh r1, [r3, 0x2C]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08123114
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x56
	ldrh r0, [r0]
	cmp r0, 0xF
	bhi _08123114
	adds r1, 0x7C
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0x1
_08123114:
	ldrh r1, [r3, 0x2C]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08123132
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	cmp r0, 0x1
	bls _08123132
	adds r1, 0x7B
	movs r0, 0xFF
	strb r0, [r1]
	movs r4, 0x1
_08123132:
	ldrh r1, [r3, 0x2C]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08123150
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	cmp r0, 0x1B
	bhi _08123150
	adds r1, 0x7B
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0x1
_08123150:
	ldrh r3, [r3, 0x2E]
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _08123168
	movs r4, 0x4
	b _08123172
	.pool
_08123168:
	movs r0, 0x2
	ands r0, r3
	cmp r0, 0
	beq _08123172
	movs r4, 0x5
_08123172:
	cmp r4, 0x1
	bne _08123184
	ldr r0, [r2]
	adds r0, 0x7A
	movs r1, 0x4
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, =_swiopen
	str r0, [r1, 0x18]
_08123184:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81230C4

	thumb_func_start _swiopen
_swiopen: @ 8123190
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A144
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x7A
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _081231AC
	movs r0, 0x2
	b _08123248
	.pool
_081231AC:
	adds r0, r1, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _081231C2
	adds r1, 0x54
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_081231C2:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _081231DA
	adds r1, 0x54
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_081231DA:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x7C
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _081231F2
	adds r1, 0x56
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_081231F2:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x7C
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _0812320A
	adds r1, 0x56
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_0812320A:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	adds r1, 0x56
	ldrh r1, [r1]
	bl sub_812386C
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl get_flagnr_blue_points
	ldr r1, [r5]
	strb r0, [r1, 0x2]
	ldr r1, [r5]
	ldrh r0, [r1]
	cmp r4, r0
	beq _0812323C
	strh r4, [r1]
	adds r0, r1, 0x4
	ldrh r1, [r1]
	movs r2, 0x10
	bl GetMapName
_0812323C:
	bl sub_8123FB0
	ldr r1, [r5]
	ldr r0, =sub_81230C4
	str r0, [r1, 0x18]
	movs r0, 0x3
_08123248:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end _swiopen

	thumb_func_start sub_8123254
sub_8123254: @ 8123254
	push {r4-r6,lr}
	movs r4, 0
	ldr r3, =gUnknown_0203A144
	ldr r0, [r3]
	mov r12, r0
	adds r0, 0x6A
	strh r4, [r0]
	mov r5, r12
	adds r5, 0x68
	strh r4, [r5]
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	adds r6, r3, 0
	adds r3, r2, 0
	cmp r0, 0
	beq _0812328E
	mov r0, r12
	adds r0, 0x5E
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x34
	negs r0, r0
	cmp r1, r0
	ble _0812328E
	ldr r0, =0x0000ffff
	strh r0, [r5]
	movs r4, 0x1
_0812328E:
	ldrh r1, [r3, 0x2C]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081232AE
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x5E
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, 0x3B
	bgt _081232AE
	adds r1, 0x68
	movs r0, 0x1
	strh r0, [r1]
	movs r4, 0x1
_081232AE:
	ldrh r1, [r3, 0x2C]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081232D4
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x5C
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x2C
	negs r0, r0
	cmp r1, r0
	ble _081232D4
	adds r1, r2, 0
	adds r1, 0x6A
	ldr r0, =0x0000ffff
	strh r0, [r1]
	movs r4, 0x1
_081232D4:
	ldrh r1, [r3, 0x2C]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081232F4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x5C
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0xAB
	bgt _081232F4
	adds r1, 0x6A
	movs r0, 0x1
	strh r0, [r1]
	movs r4, 0x1
_081232F4:
	ldrh r2, [r3, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08123300
	movs r4, 0x4
_08123300:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0812330A
	movs r4, 0x5
_0812330A:
	cmp r4, 0x1
	bne _0812331A
	ldr r0, [r6]
	ldr r1, =sub_8123334
	str r1, [r0, 0x18]
	adds r0, 0x6C
	movs r1, 0
	strh r1, [r0]
_0812331A:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8123254

	thumb_func_start sub_8123334
sub_8123334: @ 8123334
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A144
	ldr r2, [r5]
	adds r3, r2, 0
	adds r3, 0x5E
	adds r0, r2, 0
	adds r0, 0x68
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	adds r1, r2, 0
	adds r1, 0x5C
	adds r0, r2, 0
	adds r0, 0x6A
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	movs r2, 0
	ldrsh r1, [r3, r2]
	bl sub_812378C
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x6C
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	bne _08123410
	adds r0, r2, 0
	adds r0, 0x5C
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r0, r1, 0
	adds r0, 0x2C
	cmp r0, 0
	bge _0812338C
	adds r0, 0x7
_0812338C:
	asrs r0, 3
	adds r0, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r0, r2, 0
	adds r0, 0x5E
	movs r4, 0
	ldrsh r1, [r0, r4]
	adds r0, r1, 0
	adds r0, 0x34
	cmp r0, 0
	bge _081233A6
	adds r0, 0x7
_081233A6:
	asrs r0, 3
	adds r0, 0x2
	lsls r0, 16
	lsrs r1, r0, 16
	adds r4, r2, 0
	adds r4, 0x64
	adds r0, r2, 0
	adds r0, 0x66
	ldrh r2, [r4]
	cmp r3, r2
	bne _081233C2
	ldrh r2, [r0]
	cmp r1, r2
	beq _081233F2
_081233C2:
	strh r3, [r4]
	strh r1, [r0]
	adds r0, r3, 0
	bl sub_812386C
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl get_flagnr_blue_points
	ldr r1, [r5]
	strb r0, [r1, 0x2]
	ldr r1, [r5]
	ldrh r3, [r1]
	cmp r4, r3
	beq _081233EE
	strh r4, [r1]
	adds r0, r1, 0x4
	ldrh r1, [r1]
	movs r2, 0x10
	bl GetMapName
_081233EE:
	bl sub_8123FB0
_081233F2:
	ldr r0, =gUnknown_0203A144
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x6C
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sub_8123254
	str r0, [r2, 0x18]
	movs r0, 0x3
	b _08123412
	.pool
_08123410:
	movs r0, 0x2
_08123412:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8123334

	thumb_func_start sub_8123418
sub_8123418: @ 8123418
	push {r4-r6,lr}
	ldr r1, =gUnknown_0203A144
	ldr r2, [r1]
	adds r0, r2, 0
	adds r0, 0x78
	ldrb r3, [r0]
	adds r5, r1, 0
	cmp r3, 0
	bne _0812349C
	subs r0, 0x1A
	strh r3, [r0]
	subs r0, 0x2
	strh r3, [r0]
	str r3, [r2, 0x40]
	str r3, [r2, 0x3C]
	adds r4, r2, 0
	adds r4, 0x54
	ldrh r0, [r4]
	lsls r0, 3
	subs r0, 0x34
	adds r1, r2, 0
	adds r1, 0x60
	strh r0, [r1]
	movs r0, 0x56
	adds r0, r2
	mov r12, r0
	ldrh r0, [r0]
	lsls r0, 3
	subs r0, 0x44
	adds r3, r2, 0
	adds r3, 0x62
	strh r0, [r3]
	movs r6, 0
	ldrsh r0, [r1, r6]
	lsls r0, 8
	cmp r0, 0
	bge _08123464
	adds r0, 0xF
_08123464:
	asrs r0, 4
	str r0, [r2, 0x44]
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r0, 8
	cmp r0, 0
	bge _08123474
	adds r0, 0xF
_08123474:
	asrs r0, 4
	str r0, [r2, 0x48]
	ldrh r1, [r4]
	adds r0, r2, 0
	adds r0, 0x64
	strh r1, [r0]
	mov r3, r12
	ldrh r0, [r3]
	adds r1, r2, 0
	adds r1, 0x66
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 9
	str r0, [r2, 0x4C]
	ldr r0, =0xfffff800
	b _081234FA
	.pool
_0812349C:
	adds r0, r2, 0
	adds r0, 0x5C
	movs r6, 0
	ldrsh r0, [r0, r6]
	lsls r0, 8
	str r0, [r2, 0x3C]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 8
	str r0, [r2, 0x40]
	adds r0, r2, 0
	adds r0, 0x60
	movs r1, 0
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	ldr r0, [r2, 0x3C]
	cmp r0, 0
	bge _081234C8
	adds r0, 0xF
_081234C8:
	asrs r0, 4
	negs r0, r0
	str r0, [r2, 0x44]
	ldr r0, [r2, 0x40]
	cmp r0, 0
	bge _081234D6
	adds r0, 0xF
_081234D6:
	asrs r0, 4
	negs r0, r0
	str r0, [r2, 0x48]
	adds r0, r2, 0
	adds r0, 0x64
	ldrh r1, [r0]
	subs r0, 0x10
	strh r1, [r0]
	adds r0, 0x12
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x56
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 8
	str r0, [r2, 0x4C]
	movs r0, 0x80
	lsls r0, 4
_081234FA:
	str r0, [r2, 0x50]
	ldr r0, [r5]
	adds r0, 0x6E
	movs r1, 0
	strh r1, [r0]
	bl sub_8124238
	bl sub_81243B0
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8123418

	thumb_func_start sub_8123514
sub_8123514: @ 8123514
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_0203A144
	ldr r3, [r0]
	adds r2, r3, 0
	adds r2, 0x6E
	ldrh r1, [r2]
	adds r5, r0, 0
	cmp r1, 0xF
	bls _08123530
	movs r0, 0
	b _081236B8
	.pool
_08123530:
	adds r0, r1, 0x1
	movs r1, 0
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x10
	bne _081235A4
	str r1, [r3, 0x44]
	str r1, [r3, 0x48]
	adds r0, r3, 0
	adds r0, 0x60
	ldrh r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	adds r0, 0x6
	ldrh r0, [r0]
	adds r1, r3, 0
	adds r1, 0x5E
	strh r0, [r1]
	adds r1, 0x1A
	ldrb r0, [r1]
	movs r2, 0x80
	lsls r2, 9
	cmp r0, 0
	bne _08123566
	movs r2, 0x80
	lsls r2, 8
_08123566:
	str r2, [r3, 0x4C]
	movs r2, 0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08123572
	movs r2, 0x1
_08123572:
	strb r2, [r1]
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x78
	ldrb r0, [r0]
	ldr r2, =sub_8123254
	cmp r0, 0
	bne _08123584
	ldr r2, =sub_81230C4
_08123584:
	str r2, [r1, 0x18]
	adds r0, r1, 0
	adds r0, 0x58
	ldrh r0, [r0]
	adds r1, 0x5A
	ldrh r1, [r1]
	bl sub_81240D4
	bl sub_81243DC
	movs r4, 0
	b _08123686
	.pool
_081235A4:
	ldr r2, [r3, 0x3C]
	ldr r0, [r3, 0x44]
	adds r2, r0
	str r2, [r3, 0x3C]
	ldr r0, [r3, 0x40]
	ldr r1, [r3, 0x48]
	adds r0, r1
	str r0, [r3, 0x40]
	asrs r2, 8
	adds r4, r3, 0
	adds r4, 0x5C
	strh r2, [r4]
	ldr r0, [r3, 0x40]
	asrs r0, 8
	adds r1, r3, 0
	adds r1, 0x5E
	strh r0, [r1]
	ldr r0, [r3, 0x4C]
	ldr r1, [r3, 0x50]
	adds r0, r1
	str r0, [r3, 0x4C]
	ldr r2, [r3, 0x44]
	cmp r2, 0
	bge _081235E4
	adds r0, r3, 0
	adds r0, 0x60
	movs r6, 0
	ldrsh r1, [r4, r6]
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r1, r0
	blt _081235F8
_081235E4:
	cmp r2, 0
	ble _08123608
	adds r0, r3, 0
	adds r0, 0x60
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r1, r0
	ble _08123608
_081235F8:
	ldr r3, [r5]
	adds r0, r3, 0
	adds r0, 0x60
	ldrh r2, [r0]
	subs r0, 0x4
	movs r1, 0
	strh r2, [r0]
	str r1, [r3, 0x44]
_08123608:
	ldr r2, [r5]
	ldr r4, [r2, 0x48]
	cmp r4, 0
	bge _08123624
	adds r0, r2, 0
	adds r0, 0x5E
	adds r3, r2, 0
	adds r3, 0x62
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r6, 0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	blt _0812363C
_08123624:
	cmp r4, 0
	ble _0812364E
	adds r1, r2, 0
	adds r1, 0x5E
	adds r0, r2, 0
	adds r0, 0x62
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r1, r0
	ble _0812364E
_0812363C:
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x62
	ldrh r1, [r0]
	adds r3, r2, 0
	adds r3, 0x5E
	movs r0, 0
	strh r1, [r3]
	str r0, [r2, 0x48]
_0812364E:
	ldr r0, =gUnknown_0203A144
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	ldrb r3, [r0]
	cmp r3, 0
	bne _08123674
	ldr r1, [r2, 0x4C]
	ldr r0, =0x00007fff
	cmp r1, r0
	bgt _08123684
	adds r0, 0x1
	str r0, [r2, 0x4C]
	str r3, [r2, 0x50]
	b _08123684
	.pool
_08123674:
	ldr r0, [r2, 0x4C]
	movs r1, 0x80
	lsls r1, 9
	cmp r0, r1
	ble _08123684
	str r1, [r2, 0x4C]
	movs r0, 0
	str r0, [r2, 0x50]
_08123684:
	movs r4, 0x1
_08123686:
	ldr r0, =gUnknown_0203A144
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0x5C
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r1, r3, 0
	adds r1, 0x5E
	movs r2, 0
	ldrsh r1, [r1, r2]
	ldr r2, [r3, 0x4C]
	lsls r2, 8
	lsrs r2, 16
	str r2, [sp]
	ldr r2, [r3, 0x4C]
	lsls r2, 8
	lsrs r2, 16
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	movs r2, 0x38
	movs r3, 0x48
	bl sub_81236C4
	adds r0, r4, 0
_081236B8:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8123514

	thumb_func_start sub_81236C4
sub_81236C4: @ 81236C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	ldr r7, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r4, 16
	lsrs r4, 16
	mov r8, r4
	lsls r7, 16
	adds r4, r7, 0
	lsrs r4, 16
	mov r9, r4
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gUnknown_0203A144
	ldr r6, [r4]
	ldr r7, =gSineTable
	mov r12, r7
	adds r4, r5, 0
	adds r4, 0x40
	lsls r4, 1
	add r4, r12
	movs r7, 0
	ldrsh r4, [r4, r7]
	str r4, [sp]
	mov r7, r8
	muls r7, r4
	adds r4, r7, 0
	asrs r4, 8
	mov r10, r4
	str r4, [r6, 0x2C]
	lsls r5, 1
	add r5, r12
	movs r7, 0
	ldrsh r5, [r5, r7]
	negs r4, r5
	mov r7, r8
	muls r7, r4
	adds r4, r7, 0
	asrs r4, 8
	mov r12, r4
	str r4, [r6, 0x30]
	mov r7, r9
	muls r7, r5
	adds r5, r7, 0
	asrs r5, 8
	str r5, [r6, 0x34]
	ldr r7, [sp]
	mov r4, r9
	muls r4, r7
	asrs r4, 8
	mov r8, r4
	str r4, [r6, 0x38]
	lsls r0, 16
	asrs r0, 8
	lsls r2, 16
	asrs r2, 16
	lsls r4, r2, 8
	adds r0, r4
	lsls r3, 16
	asrs r3, 16
	adds r4, r3, 0
	muls r4, r5
	mov r5, r10
	muls r5, r2
	adds r4, r5
	subs r0, r4
	str r0, [r6, 0x24]
	lsls r1, 16
	asrs r1, 8
	lsls r0, r3, 8
	adds r1, r0
	mov r0, r8
	muls r0, r3
	mov r3, r12
	muls r3, r2
	adds r2, r3, 0
	adds r0, r2
	subs r1, r0
	str r1, [r6, 0x28]
	adds r6, 0x7D
	movs r0, 0x1
	strb r0, [r6]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81236C4

	thumb_func_start sub_812378C
sub_812378C: @ 812378C
	ldr r2, =gUnknown_0203A144
	ldr r2, [r2]
	lsls r0, 16
	asrs r0, 8
	movs r3, 0xE0
	lsls r3, 5
	adds r0, r3
	str r0, [r2, 0x24]
	lsls r1, 16
	asrs r1, 8
	movs r0, 0x90
	lsls r0, 6
	adds r1, r0
	str r1, [r2, 0x28]
	adds r2, 0x7D
	movs r0, 0x1
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_812378C

	thumb_func_start sub_81237B4
sub_81237B4: @ 81237B4
	push {r4,lr}
	ldr r4, =gUnknown_0203A144
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x7D
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812381A
	ldrh r1, [r1, 0x2C]
	movs r0, 0x20
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x34]
	movs r0, 0x22
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x30]
	movs r0, 0x24
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x38]
	movs r0, 0x26
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x24]
	movs r0, 0x28
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x26]
	movs r0, 0x2A
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x28]
	movs r0, 0x2C
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x2A]
	movs r0, 0x2E
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0x7D
	movs r1, 0
	strb r1, [r0]
_0812381A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81237B4

	thumb_func_start sub_8123824
sub_8123824: @ 8123824
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 16
	asrs r5, r1, 16
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x38
	movs r3, 0x48
	bl sub_81236C4
	bl sub_81237B4
	ldr r0, =gUnknown_0203A144
	ldr r2, [r0]
	ldr r1, [r2, 0x20]
	cmp r1, 0
	beq _08123860
	negs r0, r4
	strh r0, [r1, 0x24]
	ldr r1, [r2, 0x20]
	negs r0, r5
	strh r0, [r1, 0x26]
_08123860:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8123824

	thumb_func_start sub_812386C
sub_812386C: @ 812386C
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 16
	ldr r0, =0xfffe0000
	adds r1, r0
	lsrs r2, r1, 16
	cmp r2, 0xE
	bhi _08123886
	cmp r3, 0
	beq _08123886
	cmp r3, 0x1C
	bls _08123890
_08123886:
	movs r0, 0xD5
	b _081238A4
	.pool
_08123890:
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r1, =gUnknown_085A096C
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3, r0
	adds r0, r1
	ldrb r0, [r0]
_081238A4:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812386C

	thumb_func_start sub_81238AC
sub_81238AC: @ 81238AC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	adds r3, r0, 0
	cmp r1, 0x19
	bne _081238DC
	ldrb r0, [r2, 0x5]
	subs r0, 0x29
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081238DC
	bl sub_8123C00
	b _08123BEC
	.pool
_081238DC:
	ldr r1, [r3]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	bl get_map_light_level_by_bank_and_number
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x8
	bhi _08123928
	lsls r0, 2
	ldr r1, =_08123904
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08123904:
	.4byte _08123928
	.4byte _08123928
	.4byte _08123928
	.4byte _0812396C
	.4byte _08123928
	.4byte _08123928
	.4byte _0812396C
	.4byte _08123A28
	.4byte _081239E4
_08123928:
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	ldr r3, =gMapHeader
	ldrb r1, [r3, 0x14]
	movs r2, 0
	strh r1, [r0]
	adds r0, 0x7F
	strb r2, [r0]
	ldr r0, [r3]
	ldrh r2, [r0]
	ldrh r0, [r0, 0x4]
	mov r9, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r6, [r0]
	ldrh r3, [r0, 0x2]
	ldr r1, [r4]
	ldrh r0, [r1]
	cmp r0, 0x45
	beq _08123956
	cmp r0, 0xCC
	beq _08123956
	b _08123ABE
_08123956:
	adds r1, 0x7F
	movs r0, 0x1
	strb r0, [r1]
	b _08123ABE
	.pool
_0812396C:
	ldr r2, =gMapHeader
	ldrb r1, [r2, 0x1A]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081239C8
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	adds r1, 0x25
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	adds r5, r0, 0
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	ldrb r1, [r5, 0x14]
	strh r1, [r0]
	adds r0, 0x7F
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r5]
	ldrh r2, [r0]
	ldrh r0, [r0, 0x4]
	mov r9, r0
	ldr r0, [r4]
	ldrh r6, [r0, 0x28]
	ldrh r3, [r0, 0x2A]
	b _08123ABE
	.pool
_081239C8:
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	ldrb r1, [r2, 0x14]
	strh r1, [r0]
	adds r0, 0x7F
	movs r1, 0x1
	strb r1, [r0]
	movs r2, 0x1
	mov r9, r2
	movs r6, 0x1
	movs r3, 0x1
	b _08123ABE
	.pool
_081239E4:
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	movs r0, 0x14
	ldrsb r0, [r1, r0]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x15]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	adds r5, r0, 0
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	ldrb r1, [r5, 0x14]
	strh r1, [r0]
	adds r0, 0x7F
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r5]
	ldrh r2, [r0]
	ldrh r0, [r0, 0x4]
	mov r9, r0
	ldr r0, [r4]
	ldrh r6, [r0, 0x18]
	ldrh r3, [r0, 0x1A]
	b _08123ABE
	.pool
_08123A28:
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	ldr r1, =gMapHeader
	ldrb r1, [r1, 0x14]
	strh r1, [r0]
	cmp r1, 0x57
	beq _08123A64
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r7, r0, 0
	adds r7, 0x24
	movs r0, 0
	ldrsb r0, [r7, r0]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ldrsb r1, [r7, r1]
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	adds r5, r0, 0
	b _08123A8A
	.pool
_08123A64:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r7, r0, 0
	adds r7, 0x14
	ldrb r0, [r0, 0x14]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ldrsb r1, [r7, r1]
	lsls r1, 16
	lsrs r1, 16
	bl get_mapheader_by_bank_and_number
	adds r5, r0, 0
	ldr r1, [r4]
	ldrb r0, [r5, 0x14]
	strh r0, [r1]
_08123A8A:
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	ldrb r0, [r0]
	bl sub_8123F74
	adds r1, r0, 0
	cmp r1, 0
	beq _08123AAC
	ldr r0, [r4]
	adds r0, 0x7F
	movs r1, 0x1
	b _08123AB0
	.pool
_08123AAC:
	ldr r0, [r4]
	adds r0, 0x7F
_08123AB0:
	strb r1, [r0]
	ldr r0, [r5]
	ldrh r2, [r0]
	ldrh r0, [r0, 0x4]
	mov r9, r0
	ldrh r6, [r7, 0x4]
	ldrh r3, [r7, 0x6]
_08123ABE:
	str r6, [sp]
	ldr r5, =gRegionMapEntries
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	mov r10, r0
	ldrh r7, [r0]
	lsls r0, r7, 3
	adds r0, r5
	str r0, [sp, 0x4]
	ldrb r0, [r0, 0x2]
	mov r8, r0
	adds r0, r2, 0
	mov r1, r8
	str r3, [sp, 0x8]
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r3, [sp, 0x8]
	cmp r1, 0
	bne _08123AEA
	movs r1, 0x1
_08123AEA:
	adds r0, r6, 0
	str r3, [sp, 0x8]
	bl __udivsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r3, [sp, 0x8]
	cmp r6, r8
	bcc _08123B04
	mov r0, r8
	subs r0, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_08123B04:
	ldr r2, [sp, 0x4]
	ldrb r4, [r2, 0x3]
	mov r0, r9
	adds r1, r4, 0
	str r3, [sp, 0x8]
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r3, [sp, 0x8]
	cmp r1, 0
	bne _08123B1E
	movs r1, 0x1
_08123B1E:
	adds r0, r3, 0
	bl __udivsi3
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r4
	bcc _08123B32
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
_08123B32:
	cmp r7, 0x29
	beq _08123B5E
	cmp r7, 0x29
	bgt _08123B4C
	cmp r7, 0x1D
	beq _08123B56
	cmp r7, 0x24
	beq _08123B94
	b _08123BC6
	.pool
_08123B4C:
	cmp r7, 0x33
	beq _08123B5E
	cmp r7, 0xCC
	beq _08123BB8
	b _08123BC6
_08123B56:
	cmp r3, 0
	beq _08123BC6
	movs r6, 0
	b _08123BC6
_08123B5E:
	movs r6, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x20
	ble _08123B6E
	movs r6, 0x1
_08123B6E:
	cmp r0, 0x33
	ble _08123B78
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_08123B78:
	movs r3, 0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, 0x25
	ble _08123B84
	movs r3, 0x1
_08123B84:
	cmp r0, 0x38
	ble _08123BC6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	b _08123BC6
	.pool
_08123B94:
	movs r6, 0
	ldr r0, [sp]
	cmp r0, 0xE
	bls _08123B9E
	movs r6, 0x1
_08123B9E:
	ldr r2, [sp]
	cmp r2, 0x1C
	bls _08123BAA
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_08123BAA:
	ldr r0, [sp]
	cmp r0, 0x36
	bls _08123BC6
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	b _08123BC6
_08123BB8:
	mov r0, r10
	adds r0, 0x54
	mov r1, r10
	adds r1, 0x56
	bl sub_8123F30
	b _08123BEC
_08123BC6:
	ldr r0, =gUnknown_0203A144
	ldr r2, [r0]
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0]
	adds r0, r6, r0
	adds r0, 0x1
	adds r1, r2, 0
	adds r1, 0x54
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r5
	ldrb r0, [r0, 0x1]
	adds r0, r3, r0
	adds r0, 0x2
	adds r2, 0x56
	strh r0, [r2]
_08123BEC:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81238AC

	thumb_func_start sub_8123C00
sub_8123C00: @ 8123C00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r7, 0
	movs r0, 0
	mov r8, r0
	mov r4, sp
	adds r4, 0x1
	mov r5, sp
	adds r5, 0x2
	add r6, sp, 0x4
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8137FFC
	lsls r0, 24
	lsrs r0, 24
	mov r10, r5
	cmp r0, 0x4
	bhi _08123C94
	lsls r0, 2
	ldr r1, =_08123C40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08123C40:
	.4byte _08123C94
	.4byte _08123C54
	.4byte _08123C64
	.4byte _08123C74
	.4byte _08123C84
_08123C54:
	ldr r2, =gUnknown_0203A144
	ldr r1, [r2]
	movs r0, 0x8
	strh r0, [r1]
	b _08123D10
	.pool
_08123C64:
	ldr r2, =gUnknown_0203A144
	ldr r1, [r2]
	movs r0, 0xC
	strh r0, [r1]
	b _08123D10
	.pool
_08123C74:
	ldr r2, =gUnknown_0203A144
	ldr r1, [r2]
	movs r0, 0x27
	strh r0, [r1]
	b _08123D10
	.pool
_08123C84:
	ldr r2, =gUnknown_0203A144
	ldr r1, [r2]
	movs r0, 0x2E
	strh r0, [r1]
	b _08123D10
	.pool
_08123C94:
	mov r0, sp
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl get_mapheader_by_bank_and_number
	ldr r1, =gUnknown_0203A144
	mov r9, r1
	ldr r2, [r1]
	ldrb r1, [r0, 0x14]
	strh r1, [r2]
	ldr r6, [r0]
	ldr r1, =gRegionMapEntries
	ldrh r0, [r2]
	lsls r0, 3
	adds r5, r0, r1
	ldrb r4, [r5, 0x2]
	ldr r0, [r6]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08123CC6
	movs r1, 0x1
_08123CC6:
	mov r2, r10
	movs r3, 0
	ldrsh r0, [r2, r3]
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r8, r4
	bcc _08123CE2
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_08123CE2:
	ldrb r4, [r5, 0x3]
	ldr r0, [r6, 0x4]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08123CF6
	movs r1, 0x1
_08123CF6:
	mov r2, sp
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
	mov r2, r9
	cmp r7, r4
	bcc _08123D10
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
_08123D10:
	ldr r0, [r2]
	adds r0, 0x7F
	movs r1, 0
	strb r1, [r0]
	ldr r2, [r2]
	ldr r3, =gRegionMapEntries
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0]
	add r0, r8
	adds r0, 0x1
	adds r1, r2, 0
	adds r1, 0x54
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x1]
	adds r0, r7, r0
	adds r0, 0x2
	adds r2, 0x56
	strh r0, [r2]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8123C00

	thumb_func_start get_flagnr_blue_points
get_flagnr_blue_points: @ 8123D58
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x9
	beq _08123E18
	cmp r0, 0x9
	bgt _08123D9A
	cmp r0, 0x4
	beq _08123DF0
	cmp r0, 0x4
	bgt _08123D88
	cmp r0, 0x1
	beq _08123DD8
	cmp r0, 0x1
	bgt _08123D7E
	cmp r0, 0
	beq _08123DD0
	b _08123E94
_08123D7E:
	cmp r0, 0x2
	beq _08123DDE
	cmp r0, 0x3
	beq _08123DE8
	b _08123E94
_08123D88:
	cmp r0, 0x6
	beq _08123E00
	cmp r0, 0x6
	blt _08123DF8
	cmp r0, 0x7
	beq _08123E08
	cmp r0, 0x8
	beq _08123E10
	b _08123E94
_08123D9A:
	cmp r0, 0xE
	beq _08123E40
	cmp r0, 0xE
	bgt _08123DB4
	cmp r0, 0xB
	beq _08123E28
	cmp r0, 0xB
	blt _08123E20
	cmp r0, 0xC
	beq _08123E30
	cmp r0, 0xD
	beq _08123E38
	b _08123E94
_08123DB4:
	cmp r0, 0x3A
	beq _08123E60
	cmp r0, 0x3A
	bgt _08123DC2
	cmp r0, 0xF
	beq _08123E48
	b _08123E94
_08123DC2:
	cmp r1, 0x49
	beq _08123E7C
	cmp r1, 0xD5
	beq _08123DCC
	b _08123E94
_08123DCC:
	movs r0, 0
	b _08123E96
_08123DD0:
	ldr r0, =0x0000086f
	b _08123E4A
	.pool
_08123DD8:
	movs r0, 0x87
	lsls r0, 4
	b _08123E4A
_08123DDE:
	ldr r0, =0x00000871
	b _08123E4A
	.pool
_08123DE8:
	ldr r0, =0x00000872
	b _08123E4A
	.pool
_08123DF0:
	ldr r0, =0x00000873
	b _08123E4A
	.pool
_08123DF8:
	ldr r0, =0x00000874
	b _08123E4A
	.pool
_08123E00:
	ldr r0, =0x00000875
	b _08123E4A
	.pool
_08123E08:
	ldr r0, =0x00000876
	b _08123E4A
	.pool
_08123E10:
	ldr r0, =0x00000877
	b _08123E4A
	.pool
_08123E18:
	ldr r0, =0x00000878
	b _08123E4A
	.pool
_08123E20:
	ldr r0, =0x00000879
	b _08123E4A
	.pool
_08123E28:
	ldr r0, =0x0000087a
	b _08123E4A
	.pool
_08123E30:
	ldr r0, =0x0000087b
	b _08123E4A
	.pool
_08123E38:
	ldr r0, =0x0000087c
	b _08123E4A
	.pool
_08123E40:
	ldr r0, =0x0000087d
	b _08123E4A
	.pool
_08123E48:
	ldr r0, =0x0000087e
_08123E4A:
	bl FlagGet
	lsls r0, 24
	movs r1, 0x3
	cmp r0, 0
	beq _08123E58
	movs r1, 0x2
_08123E58:
	adds r0, r1, 0
	b _08123E96
	.pool
_08123E60:
	ldr r0, =0x000008a8
	bl FlagGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	asrs r0, 31
	movs r1, 0x4
	ands r0, r1
	b _08123E96
	.pool
_08123E7C:
	ldr r0, =0x000008a9
	bl FlagGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _08123E96
	.pool
_08123E94:
	movs r0, 0x1
_08123E96:
	pop {r1}
	bx r1
	thumb_func_end get_flagnr_blue_points

	thumb_func_start sub_8123E9C
sub_8123E9C: @ 8123E9C
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_812386C
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8123E9C

	thumb_func_start sub_8123EB4
sub_8123EB4: @ 8123EB4
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r1, =gUnknown_085A1B84
_08123EBE:
	ldrh r0, [r1]
	cmp r0, r3
	bne _08123ED4
	bl sub_8123F04
	lsls r0, 16
	lsrs r0, 16
	b _08123F00
	.pool
_08123ED4:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x2
	bls _08123EBE
	ldr r1, =gUnknown_085A1B24
	ldrh r0, [r1]
	cmp r0, 0xD5
	beq _08123EFE
	adds r2, r1, 0
_08123EE6:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08123EF4
	ldrh r0, [r1, 0x2]
	b _08123F00
	.pool
_08123EF4:
	adds r1, 0x4
	adds r2, 0x4
	ldrh r0, [r1]
	cmp r0, 0xD5
	bne _08123EE6
_08123EFE:
	adds r0, r3, 0
_08123F00:
	pop {r1}
	bx r1
	thumb_func_end sub_8123EB4

	thumb_func_start sub_8123F04
sub_8123F04: @ 8123F04
	push {lr}
	ldr r0, =0x00004037
	bl VarGet
	subs r0, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xF
	bls _08123F18
	movs r1, 0
_08123F18:
	ldr r0, =gUnknown_085A1B8A
	lsls r1, 16
	asrs r1, 15
	adds r1, r0
	ldrh r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8123F04

	thumb_func_start sub_8123F30
sub_8123F30: @ 8123F30
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =0x00004037
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xfff70000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0x7
	bls _08123F4C
	movs r1, 0x9
_08123F4C:
	subs r1, 0x9
	lsls r1, 16
	ldr r0, =gUnknown_085A1BAC
	lsrs r1, 14
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r4]
	ldrh r0, [r1, 0x2]
	adds r0, 0x2
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8123F30

	thumb_func_start sub_8123F74
sub_8123F74: @ 8123F74
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_085A1BCC
_08123F7E:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _08123F90
	movs r0, 0x1
	b _08123F98
	.pool
_08123F90:
	adds r1, 0x1
	cmp r1, 0
	beq _08123F7E
	movs r0, 0
_08123F98:
	pop {r1}
	bx r1
	thumb_func_end sub_8123F74

	thumb_func_start sub_8123F9C
sub_8123F9C: @ 8123F9C
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_8123EB4
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8123F9C

	thumb_func_start sub_8123FB0
sub_8123FB0: @ 8123FB0
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203A144
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r0, 0xD5
	bne _08123FC8
	movs r0, 0
	strb r0, [r1, 0x3]
	b _0812402E
	.pool
_08123FC8:
	adds r0, r1, 0
	adds r0, 0x78
	ldrb r0, [r0]
	cmp r0, 0
	bne _08123FD8
	adds r0, r1, 0
	adds r0, 0x54
	b _08123FDC
_08123FD8:
	adds r0, r1, 0
	adds r0, 0x64
_08123FDC:
	ldrh r4, [r0]
	adds r0, 0x2
	ldrh r5, [r0]
	movs r6, 0
	b _08124008
_08123FE6:
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_812386C
	ldr r1, =gUnknown_0203A144
	ldr r1, [r1]
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bne _08124008
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_08124008:
	cmp r4, 0x1
	bhi _08123FE6
	adds r0, r5, 0
	bl sub_8124038
	lsls r0, 24
	cmp r0, 0
	beq _08124028
	subs r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	movs r4, 0x1D
	b _08124008
	.pool
_08124028:
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	strb r6, [r0, 0x3]
_0812402E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8123FB0

	thumb_func_start sub_8124038
sub_8124038: @ 8124038
	push {r4,r5,lr}
	lsls r0, 16
	ldr r1, =0xffff0000
	adds r0, r1
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	bne _08124058
	b _0812407A
	.pool
_08124054:
	movs r0, 0x1
	b _0812407C
_08124058:
	movs r4, 0x1
_0812405A:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_812386C
	ldr r1, =gUnknown_0203A144
	ldr r1, [r1]
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	beq _08124054
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1C
	bls _0812405A
_0812407A:
	movs r0, 0
_0812407C:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8124038

	thumb_func_start sub_8124088
sub_8124088: @ 8124088
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A144
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0x7A
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0
	beq _081240C6
	adds r0, r1, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r4, [r2, 0x20]
	adds r0, r4
	strh r0, [r2, 0x20]
	adds r0, r1, 0
	adds r0, 0x7C
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r1, [r2, 0x22]
	adds r0, r1
	strh r0, [r2, 0x22]
	ldrb r0, [r3]
	subs r0, 0x1
	strb r0, [r3]
_081240C6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124088

	thumb_func_start TaskDummy8
TaskDummy8: @ 81240D0
	bx lr
	thumb_func_end TaskDummy8

	thumb_func_start sub_81240D4
sub_81240D4: @ 81240D4
	push {r4-r7,lr}
	sub sp, 0x28
	lsls r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r1, =gUnknown_085A1C00
	ldr r2, [r1, 0x4]
	ldr r1, [r1]
	str r1, [sp, 0x20]
	str r2, [sp, 0x24]
	mov r2, sp
	ldr r1, =gUnknown_085A1C08
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	lsrs r3, r0, 16
	add r2, sp, 0x18
	ldrh r1, [r2, 0x4]
	orrs r1, r0
	str r1, [r2, 0x4]
	mov r0, sp
	strh r3, [r0]
	ldr r0, =gUnknown_0203A144
	ldr r4, [r0]
	adds r0, r4, 0
	adds r0, 0x58
	strh r3, [r0]
	ldr r5, =0xffff0000
	add r1, sp, 0x20
	ldr r0, [r1, 0x4]
	ands r0, r5
	orrs r0, r6
	str r0, [r1, 0x4]
	mov r0, sp
	strh r6, [r0, 0x2]
	adds r3, r4, 0
	adds r0, r3, 0
	adds r0, 0x5A
	strh r6, [r0]
	adds r0, 0x1E
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0
	bne _08124158
	movs r1, 0xC2
	lsls r1, 1
	adds r0, r3, r1
	str r0, [sp, 0x18]
	ldr r0, [r2, 0x4]
	ands r0, r5
	subs r1, 0x84
	orrs r0, r1
	str r0, [r2, 0x4]
	ldr r0, =sub_8124088
	b _0812416E
	.pool
_08124158:
	movs r3, 0xA1
	lsls r3, 2
	adds r0, r4, r3
	str r0, [sp, 0x18]
	ldr r0, [r2, 0x4]
	ands r0, r5
	movs r1, 0xC0
	lsls r1, 3
	orrs r0, r1
	str r0, [r2, 0x4]
	ldr r0, =TaskDummy8
_0812416E:
	str r0, [sp, 0x14]
	adds r0, r2, 0
	bl LoadSpriteSheet
	adds r0, r7, 0
	bl LoadSpritePalette
	mov r0, sp
	movs r1, 0x38
	movs r2, 0x48
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _08124228
	ldr r4, =gUnknown_0203A144
	ldr r2, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	str r3, [r2, 0x1C]
	adds r2, 0x78
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _081241DC
	ldrb r1, [r3, 0x3]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x3]
	ldr r2, [r4]
	ldr r1, [r2, 0x1C]
	ldrh r0, [r1, 0x20]
	subs r0, 0x8
	strh r0, [r1, 0x20]
	ldr r1, [r2, 0x1C]
	ldrh r0, [r1, 0x22]
	subs r0, 0x8
	strh r0, [r1, 0x22]
	ldr r0, [r2, 0x1C]
	movs r1, 0x1
	bl StartSpriteAnim
	b _08124204
	.pool
_081241DC:
	ldrb r1, [r3, 0x3]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r3, 0x3]
	ldr r1, [r4]
	ldr r2, [r1, 0x1C]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r2, 0x20]
	ldr r2, [r1, 0x1C]
	adds r1, 0x56
	ldrh r0, [r1]
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r2, 0x22]
_08124204:
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	ldr r1, [r0, 0x1C]
	movs r0, 0x2
	strh r0, [r1, 0x30]
	adds r0, r6, 0
	bl IndexOfSpritePaletteTag
	ldr r1, [r4]
	ldr r2, [r1, 0x1C]
	lsls r0, 24
	lsrs r0, 20
	ldr r4, =0x00000101
	adds r0, r4
	strh r0, [r2, 0x32]
	ldr r1, [r1, 0x1C]
	movs r0, 0x1
	strh r0, [r1, 0x34]
_08124228:
	add sp, 0x28
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81240D4

	thumb_func_start sub_8124238
sub_8124238: @ 8124238
	push {r4,lr}
	ldr r4, =gUnknown_0203A144
	ldr r0, [r4]
	ldr r0, [r0, 0x1C]
	cmp r0, 0
	beq _0812425C
	bl DestroySprite
	ldr r0, [r4]
	adds r0, 0x58
	ldrh r0, [r0]
	bl FreeSpriteTilesByTag
	ldr r0, [r4]
	adds r0, 0x5A
	ldrh r0, [r0]
	bl FreeSpritePaletteByTag
_0812425C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124238

	thumb_func_start sub_8124268
sub_8124268: @ 8124268
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	movs r0, 0x1
	strh r0, [r1, 0x34]
	bx lr
	.pool
	thumb_func_end sub_8124268

	thumb_func_start sub_8124278
sub_8124278: @ 8124278
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	movs r0, 0
	strh r0, [r1, 0x34]
	bx lr
	.pool
	thumb_func_end sub_8124278

	thumb_func_start sub_8124288
sub_8124288: @ 8124288
	push {r4-r6,lr}
	sub sp, 0x28
	lsls r0, 16
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_085A084C
	str r2, [sp, 0x18]
	movs r2, 0x80
	add r6, sp, 0x18
	lsrs r3, r0, 16
	orrs r0, r2
	str r0, [r6, 0x4]
	ldr r0, =gUnknown_085A082C
	str r0, [sp, 0x20]
	ldr r2, =0xffff0000
	add r4, sp, 0x20
	ldr r0, [r4, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [r4, 0x4]
	mov r0, sp
	movs r5, 0
	strh r3, [r0]
	strh r1, [r0, 0x2]
	ldr r0, =gUnknown_085A1C20
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_085A1C30
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [sp, 0x10]
	ldr r0, =SpriteCallbackDummy
	str r0, [sp, 0x14]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	bl sub_8124668
	cmp r0, 0
	beq _08124304
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	str r5, [r0, 0x20]
	b _081243A4
	.pool
_08124304:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	bne _08124316
	ldr r0, =gUnknown_085A08EC
	str r0, [sp, 0x18]
	ldr r0, =gUnknown_085A08CC
	str r0, [sp, 0x20]
_08124316:
	adds r0, r6, 0
	bl LoadSpriteSheet
	adds r0, r4, 0
	bl LoadSpritePalette
	mov r0, sp
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203A144
	ldr r2, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2, 0x20]
	adds r0, r2, 0
	adds r0, 0x78
	ldrb r0, [r0]
	cmp r0, 0
	bne _08124384
	adds r0, r2, 0
	adds r0, 0x74
	ldrh r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r1, 0x20]
	ldr r1, [r2, 0x20]
	adds r0, r2, 0
	adds r0, 0x76
	ldrh r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r1, 0x22]
	ldr r1, [r2, 0x20]
	ldr r0, =sub_81244EC
	b _081243A2
	.pool
_08124384:
	adds r0, r2, 0
	adds r0, 0x74
	ldrh r0, [r0]
	lsls r0, 4
	subs r0, 0x30
	strh r0, [r1, 0x20]
	ldr r1, [r2, 0x20]
	adds r0, r2, 0
	adds r0, 0x76
	ldrh r0, [r0]
	lsls r0, 4
	subs r0, 0x42
	strh r0, [r1, 0x22]
	ldr r1, [r2, 0x20]
	ldr r0, =sub_812445C
_081243A2:
	str r0, [r1, 0x1C]
_081243A4:
	add sp, 0x28
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124288

	thumb_func_start sub_81243B0
sub_81243B0: @ 81243B0
	push {lr}
	ldr r3, =gUnknown_0203A144
	ldr r0, [r3]
	ldr r2, [r0, 0x20]
	cmp r2, 0
	beq _081243CE
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldr r1, [r0, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_081243CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81243B0

	thumb_func_start sub_81243DC
sub_81243DC: @ 81243DC
	push {lr}
	ldr r0, =gUnknown_0203A144
	ldr r3, [r0]
	ldr r1, [r3, 0x20]
	cmp r1, 0
	beq _08124452
	adds r0, r3, 0
	adds r0, 0x78
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0812441C
	adds r0, r3, 0
	adds r0, 0x74
	ldrh r0, [r0]
	lsls r0, 4
	subs r0, 0x30
	strh r0, [r1, 0x20]
	ldr r1, [r3, 0x20]
	adds r0, r3, 0
	adds r0, 0x76
	ldrh r0, [r0]
	lsls r0, 4
	subs r0, 0x42
	strh r0, [r1, 0x22]
	ldr r1, [r3, 0x20]
	ldr r0, =sub_812445C
	b _08124444
	.pool
_0812441C:
	adds r0, r3, 0
	adds r0, 0x74
	ldrh r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	movs r2, 0
	strh r0, [r1, 0x20]
	ldr r1, [r3, 0x20]
	adds r0, r3, 0
	adds r0, 0x76
	ldrh r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r1, 0x22]
	ldr r0, [r3, 0x20]
	strh r2, [r0, 0x24]
	ldr r0, [r3, 0x20]
	strh r2, [r0, 0x26]
	ldr r1, [r3, 0x20]
	ldr r0, =sub_81244EC
_08124444:
	str r0, [r1, 0x1C]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_08124452:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81243DC

	thumb_func_start sub_812445C
sub_812445C: @ 812445C
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0203A144
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x5C
	movs r4, 0
	ldrsh r2, [r0, r4]
	lsls r2, 1
	negs r2, r2
	strh r2, [r3, 0x24]
	adds r1, 0x5E
	movs r4, 0
	ldrsh r0, [r1, r4]
	lsls r0, 1
	negs r0, r0
	strh r0, [r3, 0x26]
	ldrh r1, [r3, 0x22]
	adds r1, r0
	adds r0, r3, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	strh r0, [r3, 0x2E]
	ldrh r1, [r3, 0x20]
	adds r1, r2
	adds r2, r3, 0
	adds r2, 0x28
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	adds r2, r1
	strh r2, [r3, 0x30]
	adds r0, 0x8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB0
	bhi _081244BC
	lsls r0, r2, 16
	asrs r2, r0, 16
	movs r0, 0x8
	negs r0, r0
	cmp r2, r0
	blt _081244BC
	cmp r2, 0xF8
	ble _081244C4
_081244BC:
	movs r0, 0
	b _081244C6
	.pool
_081244C4:
	movs r0, 0x1
_081244C6:
	strh r0, [r3, 0x32]
	movs r1, 0x32
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	bne _081244D8
	adds r0, r3, 0
	bl sub_81244F8
	b _081244E4
_081244D8:
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_081244E4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812445C

	thumb_func_start sub_81244EC
sub_81244EC: @ 81244EC
	push {lr}
	bl sub_81244F8
	pop {r0}
	bx r0
	thumb_func_end sub_81244EC

	thumb_func_start sub_81244F8
sub_81244F8: @ 81244F8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	adds r0, 0x7E
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812453C
	ldrh r0, [r2, 0x3C]
	adds r0, 0x1
	strh r0, [r2, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08124548
	movs r0, 0
	strh r0, [r2, 0x3C]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08124548
	.pool
_0812453C:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08124548:
	pop {r0}
	bx r0
	thumb_func_end sub_81244F8

	thumb_func_start sub_812454C
sub_812454C: @ 812454C
	push {lr}
	ldr r0, =gUnknown_0203A144
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x7F
	ldrb r0, [r0]
	cmp r0, 0
	beq _08124562
	adds r1, 0x7E
	movs r0, 0x1
	strb r0, [r1]
_08124562:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812454C

	thumb_func_start GetMapName
@ u8 *GetMapName(u8 *dest, u16 regionMapId, u16 padLength)
GetMapName: @ 812456C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	cmp r1, 0x56
	bne _08124584
	bl GetSecretBaseMapName
	adds r1, r0, 0
	b _081245B2
_08124584:
	cmp r1, 0xD4
	bhi _081245A0
	ldr r0, =gRegionMapEntries
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl StringCopy
	adds r1, r0, 0
	b _081245B2
	.pool
_081245A0:
	cmp r4, 0
	bne _081245A6
	movs r4, 0x12
_081245A6:
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	bl StringFill
	b _081245D6
_081245B2:
	cmp r4, 0
	beq _081245D4
	subs r0, r1, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bcs _081245D0
	movs r2, 0
_081245C2:
	strb r2, [r1]
	adds r1, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bcc _081245C2
_081245D0:
	movs r0, 0xFF
	strb r0, [r1]
_081245D4:
	adds r0, r1, 0
_081245D6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetMapName

	thumb_func_start sub_81245DC
sub_81245DC: @ 81245DC
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x56
	beq _081245F8
	cmp r1, 0x57
	bne _08124604
	ldr r1, =gText_Ferry
	bl StringCopy
	b _0812460A
	.pool
_081245F8:
	ldr r1, =gText_SecretBase
	bl StringCopy
	b _0812460A
	.pool
_08124604:
	movs r2, 0
	bl GetMapName
_0812460A:
	pop {r1}
	bx r1
	thumb_func_end sub_81245DC

	thumb_func_start sub_8124610
sub_8124610: @ 8124610
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x42
	beq _08124620
	bl sub_81245DC
	b _08124626
_08124620:
	ldr r1, =gText_Hideout
	bl StringCopy
_08124626:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8124610

	thumb_func_start sub_8124630
sub_8124630: @ 8124630
	push {r4,r5,lr}
	ldr r5, [sp, 0xC]
	lsls r0, 16
	ldr r4, =gRegionMapEntries
	lsrs r0, 13
	adds r0, r4
	ldrb r4, [r0]
	strh r4, [r1]
	ldrb r1, [r0, 0x1]
	strh r1, [r2]
	ldrb r1, [r0, 0x2]
	strh r1, [r3]
	ldrb r0, [r0, 0x3]
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124630

	thumb_func_start sub_8124658
sub_8124658: @ 8124658
	ldr r0, =gUnknown_0203A144
	ldr r0, [r0]
	adds r0, 0x78
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8124658

	thumb_func_start sub_8124668
sub_8124668: @ 8124668
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_085A1C34
_08124672:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bne _08124684
	movs r0, 0x1
	b _0812468C
	.pool
_08124684:
	adds r1, 0x1
	cmp r1, 0x2
	bls _08124672
	movs r0, 0
_0812468C:
	pop {r1}
	bx r1
	thumb_func_end sub_8124668

	thumb_func_start sub_8124690
sub_8124690: @ 8124690
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xA
	bls _081246A4
	b _081248AA
_081246A4:
	lsls r0, 2
	ldr r1, =_081246B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081246B8:
	.4byte _081246E4
	.4byte _08124766
	.4byte _0812477C
	.4byte _0812478C
	.4byte _0812479C
	.4byte _081247E4
	.4byte _081247F8
	.4byte _0812480C
	.4byte _0812484C
	.4byte _08124852
	.4byte _0812486C
_081246E4:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
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
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	ldr r4, =gUnknown_0203A148
	ldr r0, =0x00000a74
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _08124754
	ldr r0, =sub_8086194
	bl SetMainCallback2
	b _081248AA
	.pool
_08124754:
	bl ResetPaletteFade
	bl ResetSpriteData
	bl FreeSpriteTileRanges
	bl FreeAllSpritePalettes
	b _0812489C
_08124766:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085A1EE4
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	b _0812489C
	.pool
_0812477C:
	ldr r0, =gUnknown_085A1EF0
	bl InitWindows
	bl DeactivateAllTextPrinters
	b _0812489C
	.pool
_0812478C:
	movs r0, 0
	movs r1, 0x65
	movs r2, 0xD0
	bl sub_809882C
	bl clear_scheduled_bg_copies_to_vram
	b _0812489C
_0812479C:
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	bl sub_8122CDC
	movs r0, 0
	movs r1, 0
	bl sub_81240D4
	movs r0, 0x1
	movs r1, 0x1
	bl sub_8124288
	ldr r0, [r4]
	ldrh r1, [r0, 0x8]
	strh r1, [r0, 0x6]
	ldr r1, =0x00000a4c
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl StringFill
	ldr r1, =gUnknown_03001180
	movs r0, 0x1
	str r0, [r1]
	bl sub_8124904
	b _0812489C
	.pool
_081247E4:
	ldr r0, =gUnknown_085A1C58
	ldr r1, =0x0600c000
	bl LZ77UnCompVram
	b _0812489C
	.pool
_081247F8:
	ldr r0, =gUnknown_085A1C90
	ldr r1, =0x0600f000
	bl LZ77UnCompVram
	b _0812489C
	.pool
_0812480C:
	ldr r0, =gUnknown_085A1C38
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r2, =gText_FlyToWhere
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	b _0812489C
	.pool
_0812484C:
	bl sub_8124A70
	b _0812489C
_08124852:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_81248C0
	bl SetVBlankCallback
	b _0812489C
	.pool
_0812486C:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =sub_8124D14
	bl sub_81248F4
	ldr r0, =sub_81248D4
	bl SetMainCallback2
_0812489C:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081248AA:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124690

	thumb_func_start sub_81248C0
sub_81248C0: @ 81248C0
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81248C0

	thumb_func_start sub_81248D4
sub_81248D4: @ 81248D4
	push {lr}
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldr r0, [r0]
	bl _call_via_r0
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81248D4

	thumb_func_start sub_81248F4
sub_81248F4: @ 81248F4
	ldr r1, =gUnknown_0203A148
	ldr r1, [r1]
	str r0, [r1]
	movs r0, 0
	strh r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_81248F4

	thumb_func_start sub_8124904
sub_8124904: @ 8124904
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r2, =gUnknown_0203A148
	ldr r0, [r2]
	ldrb r0, [r0, 0xA]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0812491A
	b _08124A2C
_0812491A:
	movs r7, 0
	movs r3, 0
	ldr r0, =gUnknown_085A1EDC
	mov r12, r0
	adds r5, r2, 0
	movs r6, 0
_08124926:
	ldr r0, [r5]
	lsls r1, r3, 3
	mov r2, r12
	adds r4, r1, r2
	ldrh r0, [r0, 0x8]
	ldrh r1, [r4, 0x4]
	cmp r0, r1
	bne _081249C4
	ldrh r0, [r4, 0x6]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081249CE
	ldr r0, [r5]
	ldrb r0, [r0, 0xB]
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl StringLength
	movs r7, 0x1
	movs r0, 0
	movs r1, 0
	bl sub_8198070
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x65
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r2, [r5]
	adds r2, 0xC
	str r7, [sp]
	str r6, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldr r0, [r5]
	ldrb r0, [r0, 0xB]
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x11
	str r0, [sp]
	str r6, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_03001180
	str r7, [r0]
	b _081249CE
	.pool
_081249C4:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _08124926
_081249CE:
	cmp r7, 0
	bne _08124A62
	ldr r0, =gUnknown_03001180
	ldr r0, [r0]
	cmp r0, 0x1
	bne _081249F4
	movs r0, 0x1
	movs r1, 0
	bl sub_8198070
	movs r0, 0
	movs r1, 0
	movs r2, 0x65
	movs r3, 0xD
	bl SetWindowBorderStyle
	b _081249FC
	.pool
_081249F4:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
_081249FC:
	ldr r0, =gUnknown_0203A148
	ldr r2, [r0]
	adds r2, 0xC
	movs r0, 0x1
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_03001180
	str r4, [r0]
	b _08124A62
	.pool
_08124A2C:
	ldr r4, =gUnknown_03001180
	ldr r0, [r4]
	cmp r0, 0x1
	bne _08124A48
	movs r0, 0x1
	movs r1, 0
	bl sub_8198070
	movs r0, 0
	movs r1, 0
	movs r2, 0x65
	movs r3, 0xD
	bl SetWindowBorderStyle
_08124A48:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	str r0, [r4]
_08124A62:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124904

	thumb_func_start sub_8124A70
sub_8124A70: @ 8124A70
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_085A1D68
	ldr r5, =gUnknown_0203A148
	ldr r1, [r5]
	ldr r4, =0x0000088c
	adds r1, r4
	bl LZ77UnCompWram
	ldr r0, [r5]
	adds r0, r4
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0xE0
	lsls r1, 1
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 10
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085A1F10
	bl LoadSpritePalette
	bl sub_8124AD4
	bl sub_8124BE4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124A70

	thumb_func_start sub_8124AD4
sub_8124AD4: @ 8124AD4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =0x0000086f
	str r0, [sp, 0xC]
	movs r1, 0
	mov r9, r1
	mov r2, sp
	adds r2, 0x6
	str r2, [sp, 0x14]
	mov r3, sp
	adds r3, 0xA
	str r3, [sp, 0x18]
	mov r0, sp
	adds r0, 0x8
	str r0, [sp, 0x10]
	add r1, sp, 0x4
	mov r10, r1
_08124AFE:
	ldr r2, [sp, 0x18]
	str r2, [sp]
	mov r0, r9
	add r1, sp, 0x4
	mov r2, sp
	adds r2, 0x6
	ldr r3, [sp, 0x10]
	bl sub_8124630
	mov r3, r10
	ldrh r0, [r3]
	adds r0, 0x1
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r3]
	mov r1, sp
	ldrh r0, [r1, 0x6]
	adds r0, 0x2
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r1, 0x6]
	ldr r2, [sp, 0x10]
	ldrh r0, [r2]
	cmp r0, 0x2
	bne _08124B38
	movs r7, 0x1
	b _08124B44
	.pool
_08124B38:
	ldr r3, [sp, 0x18]
	ldrh r0, [r3]
	movs r7, 0
	cmp r0, 0x2
	bne _08124B44
	movs r7, 0x2
_08124B44:
	mov r0, r10
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, [sp, 0x14]
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r0, =gUnknown_085A1F7C
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _08124BB8
	ldr r1, =gSprites
	mov r8, r1
	lsls r4, r5, 4
	adds r0, r4, r5
	lsls r6, r0, 2
	adds r2, r6, r1
	lsls r3, r7, 6
	ldrb r1, [r2, 0x1]
	movs r0, 0x3F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x1]
	ldr r0, [sp, 0xC]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08124B9C
	mov r0, r8
	adds r0, 0x1C
	adds r0, r6, r0
	ldr r1, =sub_8124CBC
	str r1, [r0]
	b _08124BA2
	.pool
_08124B9C:
	adds r0, r7, 0x3
	lsls r0, 16
	lsrs r7, r0, 16
_08124BA2:
	adds r4, r5
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	lsls r1, r7, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	mov r2, r9
	strh r2, [r4, 0x2E]
_08124BB8:
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0xF
	bls _08124AFE
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124AD4

	thumb_func_start sub_8124BE4
sub_8124BE4: @ 8124BE4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r0, 0
	mov r8, r0
	ldr r6, =gUnknown_085A1F18
	ldrh r0, [r6, 0x2]
	cmp r0, 0xD5
	beq _08124C9C
	mov r5, sp
	adds r5, 0x6
	add r7, sp, 0x4
	ldr r1, =gSprites
	mov r9, r1
	movs r0, 0x1C
	add r0, r9
	mov r10, r0
_08124C0C:
	mov r1, r8
	lsls r4, r1, 2
	adds r0, r4, r6
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08124C84
	adds r0, r6, 0x2
	adds r0, r4, r0
	ldrh r6, [r0]
	mov r0, sp
	adds r0, 0xA
	str r0, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	add r3, sp, 0x8
	bl sub_8124630
	ldrh r0, [r7]
	adds r0, 0x1
	lsls r0, 3
	strh r0, [r7]
	ldrh r0, [r5]
	adds r0, 0x2
	lsls r0, 3
	strh r0, [r5]
	movs r0, 0
	ldrsh r1, [r7, r0]
	movs r0, 0
	ldrsh r2, [r5, r0]
	ldr r0, =gUnknown_085A1F7C
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08124C84
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	mov r1, r9
	adds r4, r2, r1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x3]
	add r2, r10
	ldr r0, =sub_8124CBC
	str r0, [r2]
	adds r0, r4, 0
	movs r1, 0x6
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
_08124C84:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r6, =gUnknown_085A1F18
	lsls r0, 2
	adds r1, r6, 0x2
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0xD5
	bne _08124C0C
_08124C9C:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124BE4

	thumb_func_start sub_8124CBC
sub_8124CBC: @ 8124CBC
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldrh r1, [r0, 0x8]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _08124D00
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08124D0E
	movs r0, 0
	strh r0, [r2, 0x30]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08124D0E
	.pool
_08124D00:
	movs r0, 0x10
	strh r0, [r2, 0x30]
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x15
	ands r0, r1
	strb r0, [r2]
_08124D0E:
	pop {r0}
	bx r0
	thumb_func_end sub_8124CBC

	thumb_func_start sub_8124D14
sub_8124D14: @ 8124D14
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	ldrh r1, [r0, 0x4]
	cmp r1, 0
	beq _08124D2C
	cmp r1, 0x1
	beq _08124D46
	b _08124D56
	.pool
_08124D2C:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _08124D56
_08124D46:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08124D56
	ldr r0, =sub_8124D64
	bl sub_81248F4
_08124D56:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124D14

	thumb_func_start sub_8124D64
sub_8124D64: @ 8124D64
	push {r4,lr}
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	bne _08124DF8
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bhi _08124DF8
	lsls r0, 2
	ldr r1, =_08124D90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08124D90:
	.4byte _08124DF8
	.4byte _08124DF8
	.4byte _08124DF8
	.4byte _08124DA8
	.4byte _08124DAE
	.4byte _08124DE0
_08124DA8:
	bl sub_8124904
	b _08124DF8
_08124DAE:
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0x2
	beq _08124DBC
	cmp r0, 0x4
	bne _08124DF8
_08124DBC:
	movs r0, 0x5
	bl m4aSongNumStart
	ldr r0, [r4]
	ldr r1, =0x00000a72
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, =sub_8124E0C
	bl sub_81248F4
	b _08124DF8
	.pool
_08124DE0:
	movs r0, 0x5
	bl m4aSongNumStart
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldr r1, =0x00000a72
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, =sub_8124E0C
	bl sub_81248F4
_08124DF8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124D64

	thumb_func_start sub_8124E0C
sub_8124E0C: @ 8124E0C
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	ldrh r1, [r0, 0x4]
	cmp r1, 0
	beq _08124E24
	cmp r1, 0x1
	beq _08124E3E
	b _08124F1A
	.pool
_08124E24:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _08124F1A
_08124E3E:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08124F1A
	bl sub_812305C
	ldr r1, [r4]
	ldr r2, =0x00000a72
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08124F00
	ldrh r0, [r1, 0x8]
	cmp r0, 0xF
	beq _08124E98
	cmp r0, 0xF
	bgt _08124E6C
	cmp r0, 0
	beq _08124E84
	b _08124EBC
	.pool
_08124E6C:
	cmp r0, 0x3A
	beq _08124E7C
	cmp r0, 0x49
	bne _08124EBC
	movs r0, 0x15
	bl sub_8084CCC
	b _08124EFA
_08124E7C:
	movs r0, 0x16
	bl sub_8084CCC
	b _08124EFA
_08124E84:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	movs r1, 0xD
	cmp r0, 0
	bne _08124EB0
	movs r1, 0xC
	b _08124EB0
	.pool
_08124E98:
	ldr r0, =0x000008b4
	bl FlagGet
	lsls r0, 24
	movs r1, 0xB
	cmp r0, 0
	beq _08124EB0
	ldr r0, [r4]
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	bne _08124EB0
	movs r1, 0x14
_08124EB0:
	adds r0, r1, 0
	bl sub_8084CCC
	b _08124EFA
	.pool
_08124EBC:
	ldr r3, =gUnknown_085A1E3C
	ldr r0, =gUnknown_0203A148
	ldr r0, [r0]
	ldrh r1, [r0, 0x8]
	lsls r0, r1, 1
	adds r2, r0, r1
	adds r0, r3, 0x2
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08124EE0
	bl sub_8084CCC
	b _08124EFA
	.pool
_08124EE0:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	bl warp1_set_2
_08124EFA:
	bl sub_80B69DC
	b _08124F06
_08124F00:
	ldr r0, =sub_81B58A8
	bl SetMainCallback2
_08124F06:
	ldr r4, =gUnknown_0203A148
	ldr r0, [r4]
	cmp r0, 0
	beq _08124F16
	bl Free
	movs r0, 0
	str r0, [r4]
_08124F16:
	bl FreeAllWindowBuffers
_08124F1A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8124E0C

	.align 2, 0 @ Don't pad with nop.
