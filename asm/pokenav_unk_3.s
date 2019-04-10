	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(5)

	thumb_func_start sub_81CAAE8
sub_81CAAE8: @ 81CAAE8
	push {r4,lr}
	movs r1, 0xD4
	lsls r1, 1
	movs r0, 0x5
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CAB1C
	ldr r0, =sub_81CAB44
	str r0, [r4, 0x18]
	movs r0, 0
	strh r0, [r4, 0x8]
	str r0, [r4, 0x10]
	ldr r0, =sub_81CAD20
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CAB1E
	.pool
_081CAB1C:
	movs r0, 0
_081CAB1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAAE8

	thumb_func_start sub_81CAB24
sub_81CAB24: @ 81CAB24
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	ldr r1, [r0, 0x18]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CAB24

	thumb_func_start sub_81CAB38
sub_81CAB38: @ 81CAB38
	push {lr}
	movs r0, 0x5
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_81CAB38

	thumb_func_start sub_81CAB44
sub_81CAB44: @ 81CAB44
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r3, =gMain
	ldrh r1, [r3, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CAB5C
	movs r0, 0x2
	b _081CABF4
	.pool
_081CAB5C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CAB68
	movs r0, 0x1
	b _081CABF4
_081CAB68:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CAB74
	movs r0, 0x4
	b _081CABF4
_081CAB74:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CAB84
	movs r0, 0x3
	b _081CABF4
_081CAB84:
	ldrh r1, [r3, 0x2E]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _081CABD0
	ldr r0, =sub_81CAC04
	str r0, [r4, 0x18]
	strh r2, [r4]
	bl GetSelectedMatchCall
	lsls r0, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	beq _081CABAE
	ldrh r0, [r1, 0x1E]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CABC0
_081CABAE:
	ldr r0, =gUnknown_0862250A
	str r0, [r4, 0x4]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	b _081CABC6
	.pool
_081CABC0:
	ldr r0, =gUnknown_08622508
	str r0, [r4, 0x4]
	strh r5, [r4, 0x2]
_081CABC6:
	movs r0, 0x5
	b _081CABF4
	.pool
_081CABD0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CABF2
	bl GetPokenavMode
	cmp r0, 0x1
	beq _081CABEC
	ldr r0, =sub_81CABFC
	str r0, [r4, 0x18]
	movs r0, 0xF
	b _081CABF4
	.pool
_081CABEC:
	movs r0, 0x20
	bl PlaySE
_081CABF2:
	movs r0, 0
_081CABF4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAB44

	thumb_func_start sub_81CABFC
sub_81CABFC: @ 81CABFC
	ldr r0, =0x000186a4
	bx lr
	.pool
	thumb_func_end sub_81CABFC

	thumb_func_start sub_81CAC04
sub_81CAC04: @ 81CAC04
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CAC24
	ldrh r0, [r4]
	cmp r0, 0
	beq _081CAC24
	subs r0, 0x1
	b _081CAC38
	.pool
_081CAC24:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CAC3E
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	cmp r0, r1
	bcs _081CAC3E
	adds r0, 0x1
_081CAC38:
	strh r0, [r4]
	movs r0, 0x6
	b _081CACAC
_081CAC3E:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CAC98
	ldrh r1, [r4]
	ldr r0, [r4, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CAC8C
	cmp r0, 0x1
	bgt _081CAC5E
	cmp r0, 0
	beq _081CAC64
	b _081CAC98
_081CAC5E:
	cmp r0, 0x2
	bne _081CAC98
	b _081CACA6
_081CAC64:
	bl GetPokenavMode
	cmp r0, 0x1
	bne _081CAC72
	movs r0, 0x2
	bl SetPokenavMode
_081CAC72:
	ldr r0, =sub_81CACF8
	str r0, [r4, 0x18]
	bl sub_81CB1D0
	cmp r0, 0
	beq _081CAC88
	movs r0, 0x9
	b _081CACAC
	.pool
_081CAC88:
	movs r0, 0x8
	b _081CACAC
_081CAC8C:
	ldr r0, =sub_81CACB8
	str r0, [r4, 0x18]
	movs r0, 0xB
	b _081CACAC
	.pool
_081CAC98:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CACA6
	movs r0, 0
	b _081CACAC
_081CACA6:
	ldr r0, =sub_81CAB44
	str r0, [r4, 0x18]
	movs r0, 0x7
_081CACAC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAC04

	thumb_func_start sub_81CACB8
sub_81CACB8: @ 81CACB8
	push {lr}
	adds r3, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CACD0
	movs r0, 0xC
	b _081CACF0
	.pool
_081CACD0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CACDC
	movs r0, 0xD
	b _081CACF0
_081CACDC:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CACEA
	movs r0, 0
	b _081CACF0
_081CACEA:
	ldr r0, =sub_81CAB44
	str r0, [r3, 0x18]
	movs r0, 0xE
_081CACF0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CACB8

	thumb_func_start sub_81CACF8
sub_81CACF8: @ 81CACF8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081CAD10
	movs r0, 0
	b _081CAD16
	.pool
_081CAD10:
	ldr r0, =sub_81CAB44
	str r0, [r2, 0x18]
	movs r0, 0xA
_081CAD16:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CACF8

	thumb_func_start sub_81CAD20
sub_81CAD20: @ 81CAD20
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	adds r4, r0, 0
	cmp r5, 0x1
	beq _081CAD4C
	cmp r5, 0x1
	bgt _081CAD3A
	cmp r5, 0
	beq _081CAD44
	b _081CAE00
_081CAD3A:
	cmp r5, 0x2
	beq _081CAD9C
	cmp r5, 0x3
	beq _081CADFC
	b _081CAE00
_081CAD44:
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
_081CAD48:
	movs r0, 0x1
	b _081CAE02
_081CAD4C:
	movs r6, 0
	ldrh r5, [r4, 0x8]
_081CAD50:
	adds r0, r5, 0
	bl MatchCallFlagGetByIndex
	cmp r0, 0
	beq _081CAD80
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	strh r5, [r0, 0x1E]
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0, 0x1C]
	adds r0, r5, 0
	bl sub_81D16DC
	ldrh r1, [r4, 0xA]
	lsls r1, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1D]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_081CAD80:
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	movs r2, 0
	strh r1, [r4, 0x8]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x14
	bhi _081CADF6
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, 0x1D
	ble _081CAD50
	movs r0, 0x3
	b _081CAE02
_081CAD9C:
	movs r6, 0
	ldrh r5, [r4, 0x8]
	movs r7, 0
_081CADA2:
	ldrh r0, [r4, 0x8]
	bl sub_81D1BF8
	cmp r0, 0
	bne _081CADDC
	ldrh r0, [r4, 0x8]
	bl sub_81CAE08
	cmp r0, 0
	beq _081CADDC
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	ldrh r1, [r4, 0x8]
	strh r1, [r0, 0x1E]
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	strb r7, [r0, 0x1C]
	adds r0, r5, 0
	bl sub_81CB0C8
	ldrh r1, [r4, 0xA]
	lsls r1, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1D]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_081CADDC:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4D
	bhi _081CAD48
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, 0x1D
	ble _081CADA2
	movs r0, 0x3
	b _081CAE02
_081CADF6:
	strh r1, [r4, 0xC]
	strh r2, [r4, 0x8]
	b _081CAD48
_081CADFC:
	movs r0, 0x1
	str r0, [r4, 0x10]
_081CAE00:
	movs r0, 0x4
_081CAE02:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAD20

	thumb_func_start sub_81CAE08
sub_81CAE08: @ 81CAE08
	push {lr}
	cmp r0, 0x4D
	ble _081CAE12
	movs r0, 0
	b _081CAE24
_081CAE12:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
_081CAE24:
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE08

	thumb_func_start sub_81CAE28
sub_81CAE28: @ 81CAE28
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	ldr r0, [r0, 0x10]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE28

	thumb_func_start sub_81CAE38
sub_81CAE38: @ 81CAE38
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	ldrh r0, [r0, 0xA]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE38

	thumb_func_start sub_81CAE48
sub_81CAE48: @ 81CAE48
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	ldrh r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE48

	thumb_func_start sub_81CAE58
sub_81CAE58: @ 81CAE58
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	ldrh r1, [r1, 0xC]
	subs r0, r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE58

	thumb_func_start sub_81CAE6C
sub_81CAE6C: @ 81CAE6C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	adds r4, r0
	ldrh r0, [r1, 0xA]
	cmp r4, r0
	bge _081CAE8A
	lsls r0, r4, 2
	adds r0, r1, r0
	ldrh r0, [r0, 0x1E]
	b _081CAE8C
_081CAE8A:
	movs r0, 0x4E
_081CAE8C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE6C

	thumb_func_start sub_81CAE94
sub_81CAE94: @ 81CAE94
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	adds r0, 0x1C
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE94

	thumb_func_start sub_81CAEA4
sub_81CAEA4: @ 81CAEA4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	lsls r4, 2
	adds r0, r4
	ldrb r0, [r0, 0x1D]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAEA4

	thumb_func_start sub_81CAEBC
sub_81CAEBC: @ 81CAEBC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	lsls r1, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAED4
	ldrh r4, [r1, 0x1E]
	b _081CAEDC
_081CAED4:
	ldrh r0, [r1, 0x1E]
	bl MatchCall_GetRematchTableIdx
	adds r4, r0, 0
_081CAEDC:
	cmp r4, 0x4E
	beq _081CAEFC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _081CAEFE
	.pool
_081CAEFC:
	movs r0, 0
_081CAEFE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAEBC

	thumb_func_start sub_81CAF04
sub_81CAF04: @ 81CAF04
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	lsls r1, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAF34
	ldrh r0, [r1, 0x1E]
	bl GetTrainerIdxByRematchIdx
	adds r4, r0, 0
	ldr r1, =gTrainers
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x3]
	b _081CAF6C
	.pool
_081CAF34:
	ldrh r5, [r1, 0x1E]
	adds r0, r5, 0
	bl MatchCall_GetRematchTableIdx
	adds r4, r0, 0
	cmp r4, 0x4E
	bne _081CAF58
	adds r0, r5, 0
	bl sub_81D1BD0
	adds r4, r0, 0
	ldr r0, =gFacilityClassToPicIndex
	adds r0, r4, r0
	ldrb r0, [r0]
	b _081CAF6C
	.pool
_081CAF58:
	adds r0, r4, 0
	bl GetTrainerIdxByRematchIdx
	adds r4, r0, 0
	ldr r0, =gTrainers
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x3]
_081CAF6C:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAF04

	thumb_func_start sub_81CAF78
sub_81CAF78: @ 81CAF78
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0x5
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r0, 0
	strb r0, [r6]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	bl Overworld_MapTypeAllowsTeleportAndFly
	lsls r0, 24
	cmp r0, 0
	bne _081CAFA4
	ldr r0, =gText_CallCantBeMadeHere
	b _081CAFCE
	.pool
_081CAFA4:
	lsls r0, r5, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAFC4
	ldrh r0, [r1, 0x1E]
	bl GetTrainerIdxByRematchIdx
	ldr r1, =gStringVar4
	bl SelectMatchCallMessage
	strb r0, [r6]
	b _081CAFCC
	.pool
_081CAFC4:
	ldrh r0, [r1, 0x1E]
	ldr r1, =gStringVar4
	bl MatchCall_GetMessage
_081CAFCC:
	ldr r0, =gStringVar4
_081CAFCE:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAF78

	thumb_func_start sub_81CAFD8
sub_81CAFD8: @ 81CAFD8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x5
	bl GetSubstructPtr
	lsls r4, 2
	adds r4, r0, r4
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CB004
	ldrh r0, [r4, 0x1E]
	bl MatchCall_GetRematchTableIdx
	adds r1, r0, 0
	cmp r1, 0x4E
	bne _081CB006
	ldrh r0, [r4, 0x1E]
	adds r1, r5, 0
	bl sub_81D1B40
	b _081CB012
_081CB004:
	ldrh r1, [r4, 0x1E]
_081CB006:
	ldr r2, =gUnknown_08622028
	lsls r0, r5, 2
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
_081CB012:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAFD8

	thumb_func_start sub_81CB01C
sub_81CB01C: @ 81CB01C
	push {lr}
	movs r0, 0x5
	bl GetSubstructPtr
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CB01C

	thumb_func_start sub_81CB02C
sub_81CB02C: @ 81CB02C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	adds r1, r0, 0
	ldrh r0, [r1, 0x2]
	cmp r0, r4
	blt _081CB046
	ldr r0, [r1, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	b _081CB048
_081CB046:
	movs r0, 0x3
_081CB048:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB02C

	thumb_func_start sub_81CB050
sub_81CB050: @ 81CB050
	push {r4,lr}
	sub sp, 0x8
	adds r2, r0, 0
	adds r4, r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _081CB088
	ldrh r0, [r2, 0x2]
	bl GetTrainerIdxByRematchIdx
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTrainers
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	muls r0, r2
	ldr r2, =gTrainerClassNames
	adds r0, r2
	str r0, [sp]
	adds r1, 0x4
	str r1, [sp, 0x4]
	b _081CB092
	.pool
_081CB088:
	ldrh r0, [r2, 0x2]
	add r2, sp, 0x4
	mov r1, sp
	bl sub_81D1A78
_081CB092:
	ldr r2, [sp]
	cmp r2, 0
	beq _081CB0B4
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _081CB0B4
	adds r0, r4, 0
	movs r1, 0x7
	movs r3, 0x45
	bl sub_81DB494
	ldr r2, [sp, 0x4]
	movs r1, 0x7
	movs r3, 0x33
	bl sub_81DB494
	b _081CB0C0
_081CB0B4:
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0
	movs r3, 0x78
	bl sub_81DB494
_081CB0C0:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CB050

	thumb_func_start sub_81CB0C8
sub_81CB0C8: @ 81CB0C8
	push {lr}
	ldr r1, =gRematchTable
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	adds r0, r2, 0
	bl Overworld_GetMapHeaderByGroupAndId
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CB0C8

	thumb_func_start sub_81CB0E4
sub_81CB0E4: @ 81CB0E4
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	adds r7, r0, 0
	movs r6, 0x1
	adds r5, 0x1
	ldrh r0, [r7, 0xA]
	cmp r5, r0
	bge _081CB120
	lsls r0, r5, 2
	adds r0, 0x1C
	adds r4, r0, r7
_081CB100:
	ldrb r0, [r4]
	cmp r0, 0
	beq _081CB110
	ldrh r0, [r4, 0x2]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CB114
_081CB110:
	adds r0, r6, 0
	b _081CB122
_081CB114:
	adds r6, 0x1
	adds r4, 0x4
	adds r5, 0x1
	ldrh r0, [r7, 0xA]
	cmp r5, r0
	blt _081CB100
_081CB120:
	movs r0, 0
_081CB122:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB0E4

	thumb_func_start sub_81CB128
sub_81CB128: @ 81CB128
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl GetSubstructPtr
	adds r1, r0, 0
	movs r6, 0x1
	negs r6, r6
	subs r5, 0x1
	cmp r5, 0
	blt _081CB162
	lsls r0, r5, 2
	adds r0, 0x1C
	adds r4, r0, r1
_081CB144:
	ldrb r0, [r4]
	cmp r0, 0
	beq _081CB154
	ldrh r0, [r4, 0x2]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CB158
_081CB154:
	adds r0, r6, 0
	b _081CB164
_081CB158:
	subs r6, 0x1
	subs r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _081CB144
_081CB162:
	movs r0, 0
_081CB164:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB128

	thumb_func_start sub_81CB16C
sub_81CB16C: @ 81CB16C
	push {r4,lr}
	movs r4, 0
_081CB170:
	adds r0, r4, 0
	bl sub_81CAE08
	cmp r0, 0
	beq _081CB18A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CB1B2
_081CB18A:
	adds r4, 0x1
	cmp r4, 0x4D
	ble _081CB170
	movs r4, 0
_081CB192:
	adds r0, r4, 0
	bl MatchCallFlagGetByIndex
	cmp r0, 0
	beq _081CB1C0
	adds r0, r4, 0
	bl MatchCall_GetRematchTableIdx
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x000009ca
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _081CB1C0
_081CB1B2:
	movs r0, 0x1
	b _081CB1C8
	.pool
_081CB1C0:
	adds r4, 0x1
	cmp r4, 0x14
	ble _081CB192
	movs r0, 0
_081CB1C8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB16C

	thumb_func_start sub_81CB1D0
sub_81CB1D0: @ 81CB1D0
	push {r4,lr}
	movs r0, 0x5
	bl GetSubstructPtr
	adds r4, r0, 0
	bl GetSelectedMatchCall
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r4, r0
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	bne _081CB218
	adds r0, r1, 0
	bl sub_81CAEA4
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081CB258
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	ldrh r4, [r4, 0x1E]
	adds r0, r4
	ldrb r0, [r0]
	b _081CB246
	.pool
_081CB218:
	ldrh r0, [r4, 0x1E]
	cmp r0, 0xB
	bne _081CB258
	adds r0, r1, 0
	bl sub_81CAEA4
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081CB258
	ldr r0, =0x0000086b
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081CB258
	movs r0, 0x5B
	bl FlagGet
	lsls r0, 24
_081CB246:
	cmp r0, 0
	bne _081CB258
	movs r0, 0x1
	b _081CB25A
	.pool
_081CB258:
	movs r0, 0
_081CB25A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB1D0
    
	.align 2, 0 @ Don't pad with nop.
