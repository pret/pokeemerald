	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80EB18C
sub_80EB18C: @ 80EB18C
	push {r4,r5,lr}
	movs r5, 0
	adds r4, r0, 0
_080EB192:
	ldrb r0, [r4, 0xD]
	cmp r0, 0x1
	bne _080EB19E
	adds r0, r4, 0
	bl ClearSecretBase
_080EB19E:
	adds r4, 0xA0
	adds r5, 0x1
	cmp r5, 0x13
	bls _080EB192
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80EB18C

	thumb_func_start sub_80EB1AC
sub_80EB1AC: @ 80EB1AC
	push {lr}
	ldr r0, =0x000040ec
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ed
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ee
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ef
	movs r1, 0
	bl VarSet
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB1FC
	ldr r0, =0x000040f0
	movs r1, 0x1
	bl VarSet
	b _080EB204
	.pool
_080EB1FC:
	ldr r0, =0x000040f0
	movs r1, 0
	bl VarSet
_080EB204:
	ldr r1, =gUnknown_0203A01D
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB1AC

	thumb_func_start sub_80EB218
sub_80EB218: @ 80EB218
	push {r4-r6,lr}
	ldr r5, =0x000040f0
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB272
	ldr r6, =gUnknown_0203A01D
	ldrb r0, [r6]
	cmp r0, 0x1
	bne _080EB272
	bl CurrentMapIsSecretBase
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080EB272
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	strb r4, [r6]
	bl sub_80EEA70
	ldr r0, =0x000040ec
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ed
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ee
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ef
	movs r1, 0
	bl VarSet
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
_080EB272:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB218

	thumb_func_start sub_80EB290
sub_80EB290: @ 80EB290
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB2BA
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB2BA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB290

	thumb_func_start sub_80EB2C8
sub_80EB2C8: @ 80EB2C8
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB2F2
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB2F2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB2C8

	thumb_func_start sub_80EB300
sub_80EB300: @ 80EB300
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB34C
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB34C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB300

	thumb_func_start sub_80EB368
sub_80EB368: @ 80EB368
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB3B4
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB3B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB368

	thumb_func_start sub_80EB3D0
sub_80EB3D0: @ 80EB3D0
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB41C
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB41C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB3D0

	thumb_func_start sub_80EB438
sub_80EB438: @ 80EB438
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB480
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r4, 0x1
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x1
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB480:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB438

	thumb_func_start sub_80EB498
sub_80EB498: @ 80EB498
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffce4
	adds r0, r1
	cmp r0, 0x18
	bhi _080EB55C
	lsls r0, 2
	ldr r1, =_080EB4D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EB4D0:
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
_080EB534:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB55C
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB55C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB498

	thumb_func_start sub_80EB56C
sub_80EB56C: @ 80EB56C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffdd4
	adds r0, r1
	cmp r0, 0xCF
	bls _080EB594
	b _080EB9D0
_080EB594:
	lsls r0, 2
	ldr r1, =_080EB5A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EB5A8:
	.4byte _080EB930
	.4byte _080EB97C
	.4byte _080EB97C
	.4byte _080EB97C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB930
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB954
	.4byte _080EB954
	.4byte _080EB8E8
	.4byte _080EB8E8
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
_080EB8E8:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x40
	b _080EB994
	.pool
_080EB90C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EB994
	.pool
_080EB930:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x40
	b _080EB994
	.pool
_080EB954:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	b _080EB994
	.pool
_080EB97C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
_080EB994:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EB9D0
	.pool
_080EB9AC:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB9D0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB56C

	thumb_func_start sub_80EB9E0
sub_80EB9E0: @ 80EB9E0
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffd6f
	adds r0, r1
	cmp r0, 0x35
	bls _080EBA08
	b _080EBB18
_080EBA08:
	lsls r0, 2
	ldr r1, =_080EBA1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBA1C:
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
_080EBAF4:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBB18
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBB18:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB9E0

	thumb_func_start sub_80EBB28
sub_80EBB28: @ 80EBB28
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffddb
	adds r0, r1
	cmp r0, 0xA2
	bls _080EBB50
	b _080EBE6C
_080EBB50:
	lsls r0, 2
	ldr r1, =_080EBB64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBB64:
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE14
	.4byte _080EBE14
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
_080EBDF0:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EBE30
	.pool
_080EBE14:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
_080EBE30:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EBE6C
	.pool
_080EBE48:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBE6C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBB28

	thumb_func_start sub_80EBE7C
sub_80EBE7C: @ 80EBE7C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x0000028e
	cmp r1, r0
	bgt _080EBECC
	subs r0, 0x1
	cmp r1, r0
	blt _080EBECC
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBECC
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x4
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBECC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBE7C

	.align 2, 0 @ Don't pad with nop.
