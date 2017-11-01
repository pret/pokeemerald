	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
	bl FreeRegionMapIconResources
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
