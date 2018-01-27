	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start pokemonanimfunc_37
pokemonanimfunc_37: @ 818201C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182036
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_08182036:
	adds r0, r4, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0xFF
	ble _08182060
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _081820A6
	.pool
_08182060:
	adds r0, r1, 0
	adds r0, 0x10
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182072
	adds r0, 0x7F
_08182072:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182092
	adds r0, 0x7F
_08182092:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_081820A6:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081820B2
	adds r0, 0x7F
_081820B2:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	adds r3, r0, 0
	movs r2, 0x80
	lsls r2, 1
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_37

	thumb_func_start pokemonanimfunc_38
pokemonanimfunc_38: @ 81820E0
	push {r4,lr}
	adds r4, r0, 0
	bl HandleStartAffineAnim
	movs r0, 0
	strh r0, [r4, 0x3C]
	strh r0, [r4, 0x36]
	ldr r0, =sub_81820FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_38

	thumb_func_start sub_81820FC
sub_81820FC: @ 81820FC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x18
	ble _0818212C
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0818214A
	movs r0, 0
	strh r0, [r4, 0x36]
	ldr r0, =sub_818216C
	str r0, [r4, 0x1C]
	b _0818214A
	.pool
_0818212C:
	adds r0, r1, 0x2
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_0818214A:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81820FC

	thumb_func_start sub_818216C
sub_818216C: @ 818216C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x20
	ble _0818218C
	movs r0, 0x1
	strh r0, [r4, 0x3A]
	ldr r0, =sub_81821CC
	str r0, [r4, 0x1C]
	b _081821AA
	.pool
_0818218C:
	adds r0, r1, 0x2
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_081821AA:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_818216C

	thumb_func_start sub_81821CC
sub_81821CC: @ 81821CC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 2
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	ble _081821F0
	movs r0, 0x20
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8182248
	str r0, [r4, 0x1C]
_081821F0:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bls _08182224
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_08182224:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81821CC

	thumb_func_start sub_8182248
sub_8182248: @ 8182248
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _08182270
	movs r0, 0
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _0818228E
	.pool
_08182270:
	subs r0, r1, 0x2
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_0818228E:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8182248

	thumb_func_start pokemonanimfunc_39
pokemonanimfunc_39: @ 81822B0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _081822D0
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	b _0818235C
	.pool
_081822D0:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _081822DC
	movs r5, 0x1
_081822DC:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	adds r0, r2, 0
	cmp r2, 0
	bge _081822E8
	adds r0, r2, 0x3
_081822E8:
	asrs r0, 2
	lsls r0, 2
	subs r0, r2, r0
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	asrs r1, 1
	cmp r1, 0
	bne _0818232C
	lsls r0, r2, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0818230C
	adds r0, 0xFF
_0818230C:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
	strh r0, [r4, 0x24]
	negs r0, r0
	b _0818235A
_0818232C:
	lsls r0, r2, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0818233C
	adds r0, 0xFF
_0818233C:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	lsls r0, 16
	asrs r0, 16
	negs r0, r0
	lsls r1, r5, 24
	asrs r1, 24
	muls r0, r1
	strh r0, [r4, 0x24]
_0818235A:
	strh r0, [r4, 0x26]
_0818235C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_39

	thumb_func_start pokemonanimfunc_3A
pokemonanimfunc_3A: @ 8182370
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182392
	adds r0, r4, 0
	bl HandleStartAffineAnim
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3A]
	strh r5, [r4, 0x3C]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08182392:
	ldrh r1, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _081823E4
	subs r0, r1, 0x1
	strh r0, [r4, 0x3A]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _08182494
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 3
	movs r1, 0x14
	bl __divsi3
	adds r1, r0, 0
	ldrh r0, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 16
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x40
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r2, r1, 0
	lsls r0, 16
	asrs r0, 16
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	b _08182494
_081823E4:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	bne _08182424
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x3F
	ble _08182410
	movs r0, 0x40
	strh r0, [r4, 0x3C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
_08182410:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x40
	bl Cos
	lsls r0, 16
	lsrs r3, r0, 16
	b _08182474
	.pool
_08182424:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x40
	bl Sin
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x3F
	ble _08182448
	movs r0, 0
	movs r1, 0x3
	strh r1, [r4, 0x38]
	movs r1, 0xA
	strh r1, [r4, 0x3A]
	strh r0, [r4, 0x3C]
	b _08182474
_08182448:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0x30
	ble _0818245C
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0818245C
	movs r0, 0x2
	b _0818246E
_0818245C:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08182474
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08182474
	movs r0, 0x1
_0818246E:
	strh r0, [r4, 0x38]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
_08182474:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x2
	strh r0, [r4, 0x3C]
	movs r0, 0x80
	lsls r0, 1
	adds r2, r0, 0
	lsls r0, r3, 16
	asrs r0, 16
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
_08182494:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3A

	thumb_func_start pokemonanimfunc_3B
pokemonanimfunc_3B: @ 81824A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081824BA
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_081824BA:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _081824E8
	movs r0, 0
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _08182540
	.pool
_081824E8:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081824F4
	adds r0, 0xFF
_081824F4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182518
	adds r0, 0x7F
_08182518:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x60
	bl Sin
	adds r2, r0, 0
	movs r1, 0x80
	lsls r1, 1
	lsls r2, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl HandleSetAffineData
_08182540:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3B

	thumb_func_start pokemonanimfunc_3C
pokemonanimfunc_3C: @ 8182548
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182562
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_08182562:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r5, 0x80
	lsls r5, 1
	cmp r0, r5
	ble _08182590
	movs r0, 0
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r5, 0
	movs r3, 0
	bl HandleSetAffineData
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _081825D4
	.pool
_08182590:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x4
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081825AE
	adds r0, 0x3F
_081825AE:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x80
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	adds r2, r5
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0
	bl HandleSetAffineData
_081825D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3C

	thumb_func_start pokemonanimfunc_3D
pokemonanimfunc_3D: @ 81825DC
	push {r4,lr}
	adds r4, r0, 0
	bl HandleStartAffineAnim
	ldr r0, =sub_81825F8
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_3D

	thumb_func_start sub_81825F8
sub_81825F8: @ 81825F8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	movs r1, 0
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0818261C
	strh r1, [r4, 0x3C]
	strh r1, [r4, 0x3A]
	ldr r0, =sub_8182648
	str r0, [r4, 0x1C]
	movs r0, 0x40
	b _08182620
	.pool
_0818261C:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
_08182620:
	movs r1, 0x80
	bl Sin
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	lsls r2, r0, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl HandleSetAffineData
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81825F8

	thumb_func_start sub_8182648
sub_8182648: @ 8182648
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x4
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5F
	ble _08182672
	movs r0, 0
	movs r1, 0x80
	bl Cos
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0
	strh r0, [r4, 0x3C]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _081826C8
_08182672:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	lsls r1, 2
	negs r1, r1
	subs r1, r0
	strh r1, [r4, 0x26]
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x3F
	ble _081826A4
	ldr r5, =0x0000ffff
	adds r0, r1, 0
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	b _081826A8
	.pool
_081826A4:
	movs r5, 0x1
	movs r0, 0
_081826A8:
	lsls r0, 16
	asrs r0, 15
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x80
	bl Cos
	lsls r1, r5, 16
	asrs r1, 16
	adds r2, r1, 0
	muls r2, r0
	adds r0, r2, 0
	lsls r0, 16
	lsrs r2, r0, 16
_081826C8:
	movs r1, 0x80
	lsls r1, 1
	lsls r2, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl HandleSetAffineData
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	bne _081826EE
	movs r0, 0
	strh r0, [r4, 0x3C]
	ldr r0, =sub_81826F8
	str r0, [r4, 0x1C]
_081826EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8182648

	thumb_func_start sub_81826F8
sub_81826F8: @ 81826F8
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	bl Cos
	lsls r0, 16
	lsrs r5, r0, 16
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0xC
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x3F
	ble _08182742
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
_08182742:
	movs r1, 0x80
	lsls r1, 1
	lsls r2, r5, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl HandleSetAffineData
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81826F8

	thumb_func_start sub_8182764
sub_8182764: @ 8182764
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08182798
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	b _081827F4
	.pool
_08182798:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081827A4
	adds r0, 0xFF
_081827A4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	cmp r1, 0
	bge _081827CC
	adds r0, 0x7F
_081827CC:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x60
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	asrs r1, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	movs r3, 0
	bl HandleSetAffineData
_081827F4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8182764

	thumb_func_start pokemonanimfunc_3E
pokemonanimfunc_3E: @ 81827FC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182822
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r1, 0x8
	strh r1, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
_08182822:
	adds r0, r4, 0
	bl sub_8182764
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3E

	thumb_func_start sub_8182830
sub_8182830: @ 8182830
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08182864
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	b _081828C0
	.pool
_08182864:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182870
	adds r0, 0xFF
_08182870:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182898
	adds r0, 0x3F
_08182898:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x80
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	asrs r1, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	movs r3, 0
	bl HandleSetAffineData
_081828C0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8182830

	thumb_func_start pokemonanimfunc_3F
pokemonanimfunc_3F: @ 81828C8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081828EE
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
	adds r0, 0xFC
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_081828EE:
	adds r0, r4, 0
	bl sub_8182830
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3F

	thumb_func_start pokemonanimfunc_40
pokemonanimfunc_40: @ 81828FC
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _0818291A
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_0818291A:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _08182948
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _0818299E
	.pool
_08182948:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182954
	adds r0, 0xFF
_08182954:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182978
	adds r0, 0x7F
_08182978:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x60
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
_0818299E:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_40

	thumb_func_start pokemonanimfunc_41
pokemonanimfunc_41: @ 81829AC
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081829CA
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_081829CA:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _081829F8
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _08182A5E
	.pool
_081829F8:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	adds r1, r0, 0
	cmp r0, 0
	bge _08182A04
	adds r1, 0xFF
_08182A04:
	asrs r1, 8
	lsls r1, 8
	subs r1, r0, r1
	lsls r1, 16
	asrs r0, r1, 16
	lsrs r1, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	adds r1, r0, 0
	cmp r0, 0
	bge _08182A30
	adds r1, 0xFF
_08182A30:
	asrs r1, 8
	lsls r1, 8
	subs r1, r0, r1
	lsls r1, 16
	asrs r0, r1, 16
	lsrs r1, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x40
	bl Sin
	adds r2, r0, 0
	negs r2, r2
	lsls r2, 16
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
_08182A5E:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_41

	thumb_func_start pokemonanimfunc_42
pokemonanimfunc_42: @ 8182A6C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182A8A
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_08182A8A:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _08182AB8
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _08182B16
	.pool
_08182AB8:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182AC4
	adds r0, 0xFF
_08182AC4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	adds r1, r0, 0
	cmp r0, 0
	bge _08182AEA
	adds r1, 0xFF
_08182AEA:
	asrs r1, 8
	lsls r1, 8
	subs r1, r0, r1
	lsls r1, 16
	asrs r0, r1, 16
	lsrs r1, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x60
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
_08182B16:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_42

	thumb_func_start pokemonanimfunc_43
pokemonanimfunc_43: @ 8182B24
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _08182B48
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08182C08
	.pool
_08182B48:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _08182B56
	ldr r1, =0x000001ff
	adds r0, r2, r1
_08182B56:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _08182B62
	adds r0, r1, 0x3
_08182B62:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08182BA4
	cmp r0, 0x1
	bgt _08182B80
	cmp r0, 0
	beq _08182B8A
	b _08182BE2
	.pool
_08182B80:
	cmp r0, 0x2
	beq _08182BB8
	cmp r0, 0x3
	beq _08182BCA
	b _08182BE2
_08182B8A:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08182B9C
	ldr r1, =0x000001ff
	adds r0, r1
_08182B9C:
	asrs r0, 9
	b _08182BE0
	.pool
_08182BA4:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08182BB2
	adds r0, 0x1F
_08182BB2:
	asrs r0, 5
	subs r0, 0x10
	b _08182BE0
_08182BB8:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08182BC6
	adds r0, 0x1F
_08182BC6:
	asrs r0, 5
	b _08182BE0
_08182BCA:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08182BDC
	ldr r1, =0x000001ff
	adds r0, r1
_08182BDC:
	asrs r0, 9
	adds r0, 0x10
_08182BE0:
	strh r0, [r4, 0x24]
_08182BE2:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182BEE
	adds r0, 0x7F
_08182BEE:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x18
	strh r0, [r4, 0x32]
_08182C08:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_43

	thumb_func_start pokemonanimfunc_44
pokemonanimfunc_44: @ 8182C18
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08182C34
	strh r0, [r4, 0x3A]
	movs r0, 0x40
	strh r0, [r4, 0x3C]
	adds r0, r1, 0x1
	strh r0, [r4, 0x32]
_08182C34:
	ldrh r0, [r4, 0x3C]
	adds r1, r0, 0
	adds r1, 0x8
	movs r3, 0
	strh r1, [r4, 0x3C]
	ldrh r2, [r4, 0x3A]
	movs r5, 0x3A
	ldrsh r0, [r4, r5]
	cmp r0, 0x4
	bne _08182C52
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _08182C60
	b _08182C5A
_08182C52:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _08182C60
_08182C5A:
	strh r3, [r4, 0x3C]
	adds r0, r2, 0x1
	strh r0, [r4, 0x3A]
_08182C60:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _08182D08
	lsls r0, 2
	ldr r1, =_08182C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08182C78:
	.4byte _08182CEC
	.4byte _08182C8C
	.4byte _08182CAA
	.4byte _08182CCC
	.4byte _08182CEC
_08182C8C:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r5, 0x3C
	ldrsh r0, [r4, r5]
	movs r1, 0x8
	bl Sin
	subs r0, 0x8
	strh r0, [r4, 0x26]
	b _08182D12
_08182CAA:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	adds r0, 0x8
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	b _08182D12
_08182CCC:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	adds r0, 0x8
	strh r0, [r4, 0x26]
	b _08182D12
_08182CEC:
	movs r5, 0x3C
	ldrsh r0, [r4, r5]
	movs r1, 0x8
	bl Sin
	subs r0, 0x8
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x26]
	b _08182D12
_08182D08:
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
_08182D12:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_44

	thumb_func_start pokemonanimfunc_45
pokemonanimfunc_45: @ 8182D24
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x20
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_8180714
	ldr r0, =sub_8180714
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_45

	thumb_func_start pokemonanimfunc_46
pokemonanimfunc_46: @ 8182D40
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F8FC
	ldr r0, =sub_817F8FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_46

	thumb_func_start pokemonanimfunc_47
pokemonanimfunc_47: @ 8182D5C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F978
	ldr r0, =sub_817F978
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_47

	thumb_func_start pokemonanimfunc_48
pokemonanimfunc_48: @ 8182D78
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0x6]
	ldrh r0, [r4, 0x3A]
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_8180900
	ldr r0, =sub_8180900
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_48

	thumb_func_start pokemonanimfunc_49
pokemonanimfunc_49: @ 8182DB4
	push {lr}
	movs r1, 0x1
	strh r1, [r0, 0x3A]
	bl pokemonanimfunc_05
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_49

	thumb_func_start pokemonanimfunc_4A
pokemonanimfunc_4A: @ 8182DC4
	push {lr}
	movs r1, 0x1
	strh r1, [r0, 0x3A]
	bl pokemonanimfunc_48
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_4A

	thumb_func_start pokemonanimfunc_4B
pokemonanimfunc_4B: @ 8182DD4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08182DE2
	strh r0, [r4, 0x2E]
_08182DE2:
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _08182DF6
	adds r0, r4, 0
	bl sub_817FC20
	movs r0, 0x1
	b _08182DF8
_08182DF6:
	subs r0, r1, 0x1
_08182DF8:
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_4B

	thumb_func_start pokemonanimfunc_4C
pokemonanimfunc_4C: @ 8182E00
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817FCDC
	ldr r0, =sub_817FCDC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4C

	thumb_func_start pokemonanimfunc_4D
pokemonanimfunc_4D: @ 8182E20
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817FD44
	ldr r0, =sub_817FD44
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4D

	thumb_func_start pokemonanimfunc_4E
pokemonanimfunc_4E: @ 8182E3C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r1, 0x6]
	strh r3, [r1]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_817FE30
	ldr r0, =sub_817FE30
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4E

	thumb_func_start pokemonanimfunc_4F
pokemonanimfunc_4F: @ 8182E7C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r1, 0x6]
	movs r0, 0x3
	strh r0, [r1, 0x8]
	movs r0, 0xC
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	bl sub_817FFF0
	ldr r0, =sub_817FFF0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4F

	thumb_func_start pokemonanimfunc_50
pokemonanimfunc_50: @ 8182EBC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x18
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_818031C
	ldr r0, =sub_818031C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_50

	thumb_func_start pokemonanimfunc_51
pokemonanimfunc_51: @ 8182ED8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_81804F8
	ldr r0, =sub_81804F8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_51

	thumb_func_start pokemonanimfunc_52
pokemonanimfunc_52: @ 8182EF4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F9F4
	ldr r0, =sub_817F9F4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_52

	thumb_func_start pokemonanimfunc_53
pokemonanimfunc_53: @ 8182F10
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x3C
	strh r0, [r1]
	movs r0, 0x1E
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_817FF3C
	ldr r0, =sub_817FF3C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_53

	thumb_func_start pokemonanimfunc_54
pokemonanimfunc_54: @ 8182F48
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x2]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_8181214
	ldr r0, =sub_8181214
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_54

	thumb_func_start pokemonanimfunc_55
pokemonanimfunc_55: @ 8182F80
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x4
	strh r0, [r1, 0x6]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_8181810
	ldr r0, =sub_8181810
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_55

	thumb_func_start pokemonanimfunc_56
pokemonanimfunc_56: @ 8182FB8
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl HandleStartAffineAnim
	strh r5, [r4, 0x34]
	adds r0, r4, 0
	bl sub_8181ABC
	ldr r0, =sub_8181ABC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_56

	thumb_func_start pokemonanimfunc_07
pokemonanimfunc_07: @ 8182FFC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x2
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	bl sub_8181CE8
	ldr r0, =sub_8181CE8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_07

	thumb_func_start pokemonanimfunc_08
pokemonanimfunc_08: @ 8183030
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x4
	strh r0, [r1, 0x6]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_8181CE8
	ldr r0, =sub_8181CE8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_08

	thumb_func_start pokemonanimfunc_0B
pokemonanimfunc_0B: @ 8183068
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x64
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_81814D4
	ldr r0, =sub_81814D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0B

	thumb_func_start pokemonanimfunc_0C
pokemonanimfunc_0C: @ 818309C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x32
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_81814D4
	ldr r0, =sub_81814D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0C

	thumb_func_start pokemonanimfunc_0D
pokemonanimfunc_0D: @ 81830D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x64
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_81815D4
	ldr r0, =sub_81815D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0D

	thumb_func_start pokemonanimfunc_0E
pokemonanimfunc_0E: @ 8183108
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x32
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_81815D4
	ldr r0, =sub_81815D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0E

	thumb_func_start sub_8183140
sub_8183140: @ 8183140
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r0, 0x90
	lsls r0, 4
	cmp r2, r0
	ble _0818315C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	b _08183180
	.pool
_0818315C:
	adds r1, r2, 0
	adds r1, 0xC0
	adds r0, r1, 0
	cmp r1, 0
	bge _0818316A
	ldr r3, =0x000001bf
	adds r0, r2, r3
_0818316A:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x3C]
	adds r0, r1
_08183180:
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	ldrh r3, [r4, 0x32]
	adds r0, r3
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8183140

	thumb_func_start pokemonanimfunc_57
pokemonanimfunc_57: @ 8183194
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183140
	ldr r0, =sub_8183140
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_57

	thumb_func_start pokemonanimfunc_58
pokemonanimfunc_58: @ 81831B4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183140
	ldr r0, =sub_8183140
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_58

	thumb_func_start pokemonanimfunc_59
pokemonanimfunc_59: @ 81831D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _081831F8
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _081832BC
	.pool
_081831F8:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _08183206
	ldr r1, =0x000001ff
	adds r0, r2, r1
_08183206:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _08183212
	adds r0, r1, 0x3
_08183212:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08183268
	cmp r0, 0x1
	bgt _08183230
	cmp r0, 0
	beq _0818323A
	b _08183298
	.pool
_08183230:
	cmp r0, 0x2
	beq _0818324C
	cmp r0, 0x3
	beq _08183284
	b _08183298
_0818323A:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183248
	adds r0, 0x1F
_08183248:
	asrs r0, 5
	b _08183296
_0818324C:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _0818325E
	ldr r1, =0x000001ff
	adds r0, r1
_0818325E:
	asrs r0, 9
	b _08183296
	.pool
_08183268:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _0818327A
	ldr r1, =0x000001ff
	adds r0, r1
_0818327A:
	asrs r0, 9
	adds r0, 0x10
	b _08183296
	.pool
_08183284:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183292
	adds r0, 0x1F
_08183292:
	asrs r0, 5
	subs r0, 0x10
_08183296:
	strh r0, [r4, 0x24]
_08183298:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081832A4
	adds r0, 0x7F
_081832A4:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x18
	strh r0, [r4, 0x32]
_081832BC:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_59

	thumb_func_start sub_81832C8
sub_81832C8: @ 81832C8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	movs r0, 0
	mov r8, r0
	movs r2, 0x38
	ldrsh r1, [r6, r2]
	movs r2, 0x3A
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818331A
	mov r0, r8
	strh r0, [r6, 0x26]
	strh r0, [r6, 0x38]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	ldrh r1, [r6, 0x36]
	movs r2, 0x36
	ldrsh r0, [r6, r2]
	cmp r0, 0x1
	bgt _08183310
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r6, 0x1C]
	b _081833DC
	.pool
_08183310:
	subs r0, r1, 0x1
	strh r0, [r6, 0x36]
	mov r0, r8
	strh r0, [r6, 0x3C]
	b _081833DC
_0818331A:
	movs r1, 0x38
	ldrsh r5, [r6, r1]
	lsls r0, r5, 7
	movs r2, 0x3A
	ldrsh r4, [r6, r2]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r4, 0
	bge _08183334
	adds r4, 0x3
_08183334:
	asrs r1, r4, 2
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r1
	blt _08183358
	cmp r5, r0
	bge _08183358
	ldrh r0, [r6, 0x3C]
	adds r0, 0x33
	strh r0, [r6, 0x3C]
	movs r1, 0xFF
	mov r8, r1
	ands r1, r0
	mov r8, r1
_08183358:
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0818337C
	lsls r4, r2, 16
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	ldr r2, =0xffffff00
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	b _08183392
	.pool
_0818337C:
	lsls r4, r2, 16
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
_08183392:
	adds r7, r4, 0
	ldrh r4, [r6, 0x34]
	lsls r4, 24
	lsrs r4, 24
	mov r5, r8
	adds r0, r4, 0
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl Sin
	adds r5, r0, 0
	asrs r0, r7, 16
	adds r1, r4, 0
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r2, r1, 0
	subs r2, r5
	subs r2, r0
	mov r0, r9
	lsls r1, r0, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r0, r6, 0
	movs r3, 0
	bl SetAffineData
	ldrh r0, [r6, 0x38]
	adds r0, 0x1
	strh r0, [r6, 0x38]
_081833DC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81832C8

	thumb_func_start pokemonanimfunc_5A
pokemonanimfunc_5A: @ 81833E8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _0818340A
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl HandleStartAffineAnim
	strh r4, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_0818340A:
	adds r0, r5, 0
	bl sub_81832C8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5A

	thumb_func_start sub_8183418
sub_8183418: @ 8183418
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	movs r0, 0
	mov r8, r0
	movs r2, 0x38
	ldrsh r1, [r6, r2]
	movs r2, 0x3A
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818346A
	mov r0, r8
	strh r0, [r6, 0x38]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	ldrh r1, [r6, 0x36]
	movs r2, 0x36
	ldrsh r0, [r6, r2]
	cmp r0, 0x1
	bgt _08183460
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r6, 0x1C]
	b _08183538
	.pool
_08183460:
	subs r0, r1, 0x1
	strh r0, [r6, 0x36]
	mov r0, r8
	strh r0, [r6, 0x3C]
	b _08183538
_0818346A:
	movs r1, 0x38
	ldrsh r5, [r6, r1]
	lsls r0, r5, 7
	movs r2, 0x3A
	ldrsh r4, [r6, r2]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r4, 0
	bge _08183486
	adds r4, 0x3
_08183486:
	asrs r1, r4, 2
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r1
	blt _081834AC
	cmp r5, r0
	bge _081834AC
	ldrh r0, [r6, 0x3C]
	adds r0, 0x33
	strh r0, [r6, 0x3C]
	movs r1, 0xFF
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
_081834AC:
	ldrh r0, [r6, 0x34]
	lsls r0, 24
	lsrs r7, r0, 24
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081834F0
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	adds r1, r7, 0
	bl Sin
	adds r4, r0, 0
	mov r5, r8
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r5, 0
	bl Sin
	ldr r1, =0xffffff00
	adds r0, r1
	adds r4, r0
	lsls r4, 16
	lsrs r1, r4, 16
	b _08183522
	.pool
_081834F0:
	mov r4, r8
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r4, 0
	bl Sin
	adds r4, r0, 0
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	adds r1, r7, 0
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r4
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
_08183522:
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	movs r3, 0
	bl SetAffineData
	ldrh r0, [r6, 0x38]
	adds r0, 0x1
	strh r0, [r6, 0x38]
_08183538:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8183418

	thumb_func_start pokemonanimfunc_5B
pokemonanimfunc_5B: @ 8183544
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183566
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl HandleStartAffineAnim
	strh r4, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_08183566:
	adds r0, r5, 0
	bl sub_8183418
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5B

	thumb_func_start sub_8183574
sub_8183574: @ 8183574
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r3, =gUnknown_0860AA80
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r0, r1, r3
	ldrb r5, [r0]
	adds r2, r5, 0
	cmp r5, 0xFF
	beq _081835A6
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r5, r0, 24
_081835A6:
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	movs r7, 0
	cmp r2, 0xFE
	beq _081835C2
	mov r1, r9
	subs r0, r6, r1
	muls r0, r5
	adds r1, r6, 0
	bl __divsi3
	lsls r0, 24
	lsrs r7, r0, 24
_081835C2:
	cmp r5, 0xFF
	bne _081835D8
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x26]
	b _0818360A
	.pool
_081835D8:
	mov r1, r8
	adds r1, 0xC0
	adds r0, r1, 0
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	adds r1, r7, 0
	bl Sin
	adds r0, r7
	strh r0, [r4, 0x26]
	cmp r9, r6
	bne _081835FC
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	movs r0, 0
	b _08183608
_081835FC:
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
_08183608:
	strh r0, [r4, 0x3A]
_0818360A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8183574

	thumb_func_start pokemonanimfunc_5C
pokemonanimfunc_5C: @ 8183618
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x28
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183574
	ldr r0, =sub_8183574
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_5C

	thumb_func_start pokemonanimfunc_5D
pokemonanimfunc_5D: @ 8183638
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x46
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817FCDC
	ldr r0, =sub_817FCDC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_5D

	thumb_func_start pokemonanimfunc_5E
pokemonanimfunc_5E: @ 8183658
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F8FC
	ldr r0, =sub_817F8FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_5E

	thumb_func_start pokemonanimfunc_5F
pokemonanimfunc_5F: @ 8183674
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _08183690
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	b _081836CA
	.pool
_08183690:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _0818369C
	movs r5, 0x1
_0818369C:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _081836B0
	adds r0, 0xFF
_081836B0:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x9
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
_081836CA:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5F

	thumb_func_start pokemonanimfunc_60
pokemonanimfunc_60: @ 81836D8
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _081836F4
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0818372E
	.pool
_081836F4:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _08183700
	movs r5, 0x1
_08183700:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _08183714
	adds r0, 0xFF
_08183714:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xC
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
_0818372E:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_60

	thumb_func_start pokemonanimfunc_61
pokemonanimfunc_61: @ 818373C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x46
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183140
	ldr r0, =sub_8183140
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_61

	thumb_func_start pokemonanimfunc_62
pokemonanimfunc_62: @ 818375C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x18
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183574
	ldr r0, =sub_8183574
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_62

	thumb_func_start pokemonanimfunc_63
pokemonanimfunc_63: @ 818377C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x38
	strh r0, [r4, 0x2E]
	movs r0, 0x9
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183574
	ldr r0, =sub_8183574
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_63

	thumb_func_start pokemonanimfunc_64
pokemonanimfunc_64: @ 818379C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r1, 0x6]
	movs r0, 0x6
	strh r0, [r1, 0x8]
	movs r0, 0x18
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	bl sub_817FFF0
	ldr r0, =sub_817FFF0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_64

	thumb_func_start sub_81837DC
sub_81837DC: @ 81837DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	movs r5, 0
	movs r0, 0x38
	ldrsh r1, [r7, r0]
	movs r2, 0x3A
	ldrsh r0, [r7, r2]
	cmp r1, r0
	ble _0818382C
	strh r5, [r7, 0x26]
	strh r5, [r7, 0x38]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r7, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	ldrh r1, [r7, 0x36]
	movs r2, 0x36
	ldrsh r0, [r7, r2]
	cmp r0, 0x1
	bgt _08183824
	adds r0, r7, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r7, 0x1C]
	b _0818392C
	.pool
_08183824:
	subs r0, r1, 0x1
	strh r0, [r7, 0x36]
	strh r5, [r7, 0x3C]
	b _0818392C
_0818382C:
	movs r0, 0x38
	ldrsh r6, [r7, r0]
	lsls r0, r6, 7
	movs r1, 0x3A
	ldrsh r4, [r7, r1]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r4, 0
	bge _08183846
	adds r4, 0x3
_08183846:
	asrs r1, r4, 2
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r1
	blt _08183866
	cmp r6, r0
	bge _08183866
	ldrh r0, [r7, 0x3C]
	adds r0, 0x33
	strh r0, [r7, 0x3C]
	movs r5, 0xFF
	ands r5, r0
_08183866:
	ldrh r0, [r7, 0x34]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _081838B0
	lsls r2, 16
	mov r8, r2
	asrs r0, r2, 16
	mov r1, r9
	bl Sin
	adds r4, r0, 0
	lsls r6, r5, 16
	asrs r5, r6, 16
	mov r0, r9
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r5, 0
	bl Sin
	ldr r2, =0xffffff00
	adds r4, r2
	adds r0, r4
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r0, r8
	b _081838EA
	.pool
_081838B0:
	lsls r2, 16
	mov r8, r2
	asrs r0, r2, 16
	mov r1, r9
	bl Sin
	adds r6, r0, 0
	lsls r5, 16
	asrs r4, r5, 16
	mov r0, r9
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r4, 0
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r6
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	mov r0, r8
	adds r6, r5, 0
_081838EA:
	asrs r0, 16
	mov r1, r9
	bl Sin
	adds r5, r0, 0
	asrs r4, r6, 16
	mov r0, r9
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r2, r1, 0
	subs r2, r5
	subs r2, r0
	mov r0, r10
	lsls r1, r0, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r0, r7, 0
	movs r3, 0
	bl SetAffineData
	ldrh r0, [r7, 0x38]
	adds r0, 0x1
	strh r0, [r7, 0x38]
_0818392C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81837DC

	thumb_func_start pokemonanimfunc_65
pokemonanimfunc_65: @ 818393C
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _0818395E
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl HandleStartAffineAnim
	strh r4, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_0818395E:
	adds r0, r5, 0
	bl sub_81837DC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_65

	thumb_func_start pokemonanimfunc_66
pokemonanimfunc_66: @ 818396C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _08183990
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08183A54
	.pool
_08183990:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _0818399E
	ldr r1, =0x000001ff
	adds r0, r2, r1
_0818399E:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _081839AA
	adds r0, r1, 0x3
_081839AA:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08183A00
	cmp r0, 0x1
	bgt _081839C8
	cmp r0, 0
	beq _081839D2
	b _08183A30
	.pool
_081839C8:
	cmp r0, 0x2
	beq _081839E4
	cmp r0, 0x3
	beq _08183A1C
	b _08183A30
_081839D2:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _081839E0
	adds r0, 0x1F
_081839E0:
	asrs r0, 5
	b _08183A2E
_081839E4:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _081839F6
	ldr r1, =0x000001ff
	adds r0, r1
_081839F6:
	asrs r0, 9
	b _08183A2E
	.pool
_08183A00:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08183A12
	ldr r1, =0x000001ff
	adds r0, r1
_08183A12:
	asrs r0, 9
	adds r0, 0x10
	b _08183A2E
	.pool
_08183A1C:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183A2A
	adds r0, 0x1F
_08183A2A:
	asrs r0, 5
	subs r0, 0x10
_08183A2E:
	strh r0, [r4, 0x24]
_08183A30:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08183A3C
	adds r0, 0x7F
_08183A3C:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x30
	strh r0, [r4, 0x32]
_08183A54:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_66

	thumb_func_start pokemonanimfunc_67
pokemonanimfunc_67: @ 8183A60
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _08183A84
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08183B40
	.pool
_08183A84:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _08183A92
	ldr r1, =0x000001ff
	adds r0, r2, r1
_08183A92:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _08183A9E
	adds r0, r1, 0x3
_08183A9E:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08183AF4
	cmp r0, 0x1
	bgt _08183ABC
	cmp r0, 0
	beq _08183AC6
	b _08183B24
	.pool
_08183ABC:
	cmp r0, 0x2
	beq _08183AD8
	cmp r0, 0x3
	beq _08183B10
	b _08183B24
_08183AC6:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183AD4
	adds r0, 0x1F
_08183AD4:
	asrs r0, 5
	b _08183B22
_08183AD8:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08183AEA
	ldr r1, =0x000001ff
	adds r0, r1
_08183AEA:
	asrs r0, 9
	b _08183B22
	.pool
_08183AF4:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08183B06
	ldr r1, =0x000001ff
	adds r0, r1
_08183B06:
	asrs r0, 9
	adds r0, 0x10
	b _08183B22
	.pool
_08183B10:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183B1E
	adds r0, 0x1F
_08183B1E:
	asrs r0, 5
	subs r0, 0x10
_08183B22:
	strh r0, [r4, 0x24]
_08183B24:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x60
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x40
	strh r0, [r4, 0x32]
_08183B40:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_67

	thumb_func_start sub_8183B4C
sub_8183B4C: @ 8183B4C
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08183B5E
	strh r0, [r4, 0x34]
_08183B5E:
	ldr r7, =gUnknown_0860ADBE
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	adds r5, r7, 0x2
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl __divsi3
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08183B8C
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x34]
	strh r1, [r4, 0x32]
_08183B8C:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r6, r0, r1
	adds r0, r6, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x38
	ldrsh r5, [r4, r1]
	adds r1, r5, 0
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bne _08183BCC
	ldrh r0, [r4, 0x3A]
	subs r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	cmp r0, 0
	bne _08183BC8
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _08183C06
	.pool
_08183BC8:
	strh r1, [r4, 0x32]
	b _08183C06
_08183BCC:
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	muls r0, r5
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	adds r1, r7, 0x1
	adds r0, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, 0x38]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
_08183C06:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8183B4C

	thumb_func_start pokemonanimfunc_68
pokemonanimfunc_68: @ 8183C0C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x38]
	strh r0, [r4, 0x3A]
	adds r0, r4, 0
	bl sub_8183B4C
	ldr r0, =sub_8183B4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_68

	thumb_func_start pokemonanimfunc_69
pokemonanimfunc_69: @ 8183C2C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	strh r0, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x3A]
	adds r0, r4, 0
	bl sub_8183B4C
	ldr r0, =sub_8183B4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_69

	thumb_func_start pokemonanimfunc_6A
pokemonanimfunc_6A: @ 8183C4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	strh r0, [r4, 0x38]
	strh r0, [r4, 0x3A]
	adds r0, r4, 0
	bl sub_8183B4C
	ldr r0, =sub_8183B4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_6A

	thumb_func_start sub_8183C6C
sub_8183C6C: @ 8183C6C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0xFF
	ble _08183CAE
	ldrh r1, [r4, 0x38]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bgt _08183CA4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	b _08183CE8
	.pool
_08183CA4:
	subs r0, r1, 0x1
	movs r1, 0
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x3C]
	b _08183CE8
_08183CAE:
	ldrh r0, [r4, 0x3A]
	adds r0, r1, r0
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	movs r5, 0x80
	lsls r5, 1
	cmp r0, r5
	ble _08183CC2
	strh r5, [r4, 0x3C]
_08183CC2:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x40
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	subs r2, r5, r2
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
_08183CE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8183C6C

	thumb_func_start pokemonanimfunc_6B
pokemonanimfunc_6B: @ 8183CF0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183D16
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
	movs r0, 0x1
	strh r0, [r4, 0x38]
_08183D16:
	adds r0, r4, 0
	bl sub_8183C6C
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6B

	thumb_func_start pokemonanimfunc_6C
pokemonanimfunc_6C: @ 8183D28
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183D4E
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0x2
	strh r0, [r4, 0x38]
_08183D4E:
	adds r0, r4, 0
	bl sub_8183C6C
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6C

	thumb_func_start pokemonanimfunc_6D
pokemonanimfunc_6D: @ 8183D60
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183D88
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_08183D88:
	adds r0, r4, 0
	bl sub_8182764
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6D

	thumb_func_start pokemonanimfunc_6E
pokemonanimfunc_6E: @ 8183D94
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183DBA
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
	adds r0, 0xFC
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_08183DBA:
	adds r0, r4, 0
	bl sub_8182764
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6E

	thumb_func_start pokemonanimfunc_6F
pokemonanimfunc_6F: @ 8183DC8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183DF0
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_08183DF0:
	adds r0, r4, 0
	bl sub_8182830
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6F

	thumb_func_start pokemonanimfunc_70
pokemonanimfunc_70: @ 8183DFC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183E22
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r1, 0x8
	strh r1, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
_08183E22:
	adds r0, r4, 0
	bl sub_8182830
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_70

	thumb_func_start pokemonanimfunc_71
pokemonanimfunc_71: @ 8183E30
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08183E4A
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x5
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
_08183E4A:
	adds r0, r4, 0
	bl sub_8180828
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_71

	thumb_func_start pokemonanimfunc_72
pokemonanimfunc_72: @ 8183E58
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08183E72
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
_08183E72:
	adds r0, r4, 0
	bl sub_8180828
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_72

	thumb_func_start pokemonanimfunc_73
pokemonanimfunc_73: @ 8183E80
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183EA2
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl HandleStartAffineAnim
	strh r4, [r5, 0x36]
	movs r0, 0x1E
	strh r0, [r5, 0x3A]
	movs r0, 0x3C
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x3C]
_08183EA2:
	adds r0, r5, 0
	bl sub_81832C8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_73

	thumb_func_start pokemonanimfunc_74
pokemonanimfunc_74: @ 8183EB0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183ED4
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
	movs r0, 0x46
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x3C]
_08183ED4:
	adds r0, r4, 0
	bl sub_81832C8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_74

	thumb_func_start pokemonanimfunc_75
pokemonanimfunc_75: @ 8183EE0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183F06
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
	movs r0, 0x46
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3C]
_08183F06:
	adds r0, r4, 0
	bl sub_8183418
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_75

	thumb_func_start pokemonanimfunc_76
pokemonanimfunc_76: @ 8183F14
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183F38
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl HandleStartAffineAnim
	strh r4, [r5, 0x36]
	movs r0, 0x1E
	strh r0, [r5, 0x3A]
	movs r0, 0x3C
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_08183F38:
	adds r0, r5, 0
	bl sub_8183418
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_76

	thumb_func_start pokemonanimfunc_77
pokemonanimfunc_77: @ 8183F44
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183F6A
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
	movs r0, 0x46
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3C]
_08183F6A:
	adds r0, r4, 0
	bl sub_81837DC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_77

	thumb_func_start pokemonanimfunc_78
pokemonanimfunc_78: @ 8183F78
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183F9C
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl HandleStartAffineAnim
	strh r4, [r5, 0x36]
	movs r0, 0x1E
	strh r0, [r5, 0x3A]
	movs r0, 0x3C
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_08183F9C:
	adds r0, r5, 0
	bl sub_81837DC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_78

	thumb_func_start sub_8183FA8
sub_8183FA8: @ 8183FA8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _08183FEA
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bgt _08183FD0
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	b _0818403E
	.pool
_08183FD0:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08183FDC
	adds r0, 0xFF
_08183FDC:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	strh r0, [r4, 0x3C]
	subs r0, r2, 0x1
	strh r0, [r4, 0x3A]
	b _0818403E
_08183FEA:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r3, 0x3C
	ldrsh r2, [r4, r3]
	adds r1, r2, 0
	adds r1, 0xC0
	adds r0, r1, 0
	cmp r1, 0
	bge _0818400C
	ldr r3, =0x000001bf
	adds r0, r2, r3
_0818400C:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	ble _0818402E
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	negs r0, r0
	strh r0, [r4, 0x26]
_0818402E:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	strh r0, [r4, 0x3C]
_0818403E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8183FA8

	thumb_func_start pokemonanimfunc_79
pokemonanimfunc_79: @ 8184048
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _08184066
	movs r0, 0x1
	strh r0, [r1, 0x32]
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0xC
	strh r0, [r1, 0x38]
	strh r0, [r1, 0x36]
	movs r0, 0x4
	strh r0, [r1, 0x34]
_08184066:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_79

	thumb_func_start pokemonanimfunc_7A
pokemonanimfunc_7A: @ 8184070
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _0818408E
	movs r0, 0x1
	strh r0, [r1, 0x32]
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0xC
	strh r0, [r1, 0x38]
	strh r0, [r1, 0x36]
	movs r0, 0x6
	strh r0, [r1, 0x34]
_0818408E:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7A

	thumb_func_start pokemonanimfunc_7B
pokemonanimfunc_7B: @ 8184098
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _081840B8
	movs r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0x2
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0xC
	strh r0, [r1, 0x38]
	strh r0, [r1, 0x36]
	movs r0, 0x8
	strh r0, [r1, 0x34]
_081840B8:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7B

	thumb_func_start sub_81840C4
sub_81840C4: @ 81840C4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	lsls r1, 1
	cmp r0, r1
	ble _081840FC
	movs r2, 0x3A
	ldrsh r1, [r5, r2]
	ldrh r2, [r5, 0x36]
	movs r3, 0x36
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bgt _081840EC
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r5, 0x1C]
	b _081840F4
	.pool
_081840EC:
	adds r0, r2, 0x1
	movs r1, 0
	strh r0, [r5, 0x36]
	strh r1, [r5, 0x3C]
_081840F4:
	movs r0, 0
	strh r0, [r5, 0x24]
	strh r0, [r5, 0x26]
	b _08184188
_081840FC:
	cmp r0, 0x9F
	ble _08184126
	cmp r0, r1
	ble _08184106
	strh r1, [r5, 0x3C]
_08184106:
	movs r0, 0x3C
	ldrsh r1, [r5, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08184112
	adds r0, 0xFF
_08184112:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	b _08184154
_08184126:
	cmp r0, 0x5F
	ble _0818414A
	movs r0, 0x60
	movs r1, 0x6
	bl Sin
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	subs r0, 0x60
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	subs r4, r0
	strh r4, [r5, 0x26]
	b _08184156
_0818414A:
	movs r2, 0x3C
	ldrsh r0, [r5, r2]
	movs r1, 0x6
	bl Sin
_08184154:
	strh r0, [r5, 0x26]
_08184156:
	movs r3, 0x3C
	ldrsh r0, [r5, r3]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x38
	ldrsh r1, [r5, r2]
	bl Sin
	negs r0, r0
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r5, 0x36]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0818417E
	lsls r0, r2, 16
	negs r0, r0
	lsrs r2, r0, 16
_0818417E:
	strh r2, [r5, 0x24]
	ldrh r0, [r5, 0x34]
	ldrh r3, [r5, 0x3C]
	adds r0, r3
	strh r0, [r5, 0x3C]
_08184188:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81840C4

	thumb_func_start pokemonanimfunc_7C
pokemonanimfunc_7C: @ 8184190
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _081841B0
	movs r1, 0x1
	strh r1, [r2, 0x32]
	movs r0, 0x2
	strh r0, [r2, 0x3A]
	strh r3, [r2, 0x3C]
	movs r0, 0x10
	strh r0, [r2, 0x38]
	strh r1, [r2, 0x36]
	movs r0, 0x4
	strh r0, [r2, 0x34]
_081841B0:
	adds r0, r2, 0
	bl sub_81840C4
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7C

	thumb_func_start pokemonanimfunc_7D
pokemonanimfunc_7D: @ 81841BC
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _081841DC
	movs r1, 0x1
	strh r1, [r2, 0x32]
	movs r0, 0x2
	strh r0, [r2, 0x3A]
	strh r3, [r2, 0x3C]
	movs r0, 0x10
	strh r0, [r2, 0x38]
	strh r1, [r2, 0x36]
	movs r0, 0x6
	strh r0, [r2, 0x34]
_081841DC:
	adds r0, r2, 0
	bl sub_81840C4
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7D

	thumb_func_start pokemonanimfunc_7E
pokemonanimfunc_7E: @ 81841E8
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _08184208
	movs r1, 0x1
	strh r1, [r2, 0x32]
	movs r0, 0x3
	strh r0, [r2, 0x3A]
	strh r3, [r2, 0x3C]
	movs r0, 0x10
	strh r0, [r2, 0x38]
	strh r1, [r2, 0x36]
	movs r0, 0x8
	strh r0, [r2, 0x34]
_08184208:
	adds r0, r2, 0
	bl sub_81840C4
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7E

	thumb_func_start pokemonanimfunc_7F
pokemonanimfunc_7F: @ 8184214
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r1, [r2, r0]
	cmp r1, 0
	bne _08184232
	movs r0, 0x1
	strh r0, [r2, 0x32]
	strh r0, [r2, 0x3A]
	strh r1, [r2, 0x3C]
	movs r1, 0x4
	strh r1, [r2, 0x38]
	movs r0, 0x6
	strh r0, [r2, 0x36]
	strh r1, [r2, 0x34]
_08184232:
	adds r0, r2, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7F

	thumb_func_start pokemonanimfunc_80
pokemonanimfunc_80: @ 818423C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _0818425A
	movs r0, 0x1
	strh r0, [r1, 0x32]
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0x4
	strh r0, [r1, 0x38]
	movs r0, 0x6
	strh r0, [r1, 0x36]
	strh r0, [r1, 0x34]
_0818425A:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_80

	thumb_func_start pokemonanimfunc_81
pokemonanimfunc_81: @ 8184264
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _08184286
	movs r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0x2
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0x4
	strh r0, [r1, 0x38]
	movs r0, 0x6
	strh r0, [r1, 0x36]
	movs r0, 0x8
	strh r0, [r1, 0x34]
_08184286:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_81

	thumb_func_start sub_8184290
sub_8184290: @ 8184290
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r0, r1, 8
	negs r0, r0
	strh r0, [r4, 0x3A]
	movs r0, 0x36
	ldrsh r2, [r4, r0]
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F3F0
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3A]
	adds r0, r4, 0
	adds r1, r2, 0
	bl HandleSetAffineData
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8184290

	thumb_func_start pokemonanimfunc_82
pokemonanimfunc_82: @ 81842DC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08184300
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x3C
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x38]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x2E]
_08184300:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _0818434C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	movs r2, 0
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08184348
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _08184358
	.pool
_08184348:
	strh r2, [r4, 0x32]
	b _08184352
_0818434C:
	adds r0, r4, 0
	bl sub_8184290
_08184352:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08184358:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_82

	thumb_func_start pokemonanimfunc_83
pokemonanimfunc_83: @ 8184360
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08184384
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x5A
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x38]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x2E]
_08184384:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _081843D0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	movs r2, 0
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bgt _081843CC
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _081843DC
	.pool
_081843CC:
	strh r2, [r4, 0x32]
	b _081843D6
_081843D0:
	adds r0, r4, 0
	bl sub_8184290
_081843D6:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_081843DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_83

	thumb_func_start pokemonanimfunc_84
pokemonanimfunc_84: @ 81843E4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08184408
	adds r0, r4, 0
	bl HandleStartAffineAnim
	movs r0, 0x1E
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x38]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x36]
	movs r0, 0x2
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x2E]
_08184408:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08184454
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	movs r2, 0
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08184450
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _08184460
	.pool
_08184450:
	strh r2, [r4, 0x32]
	b _0818445A
_08184454:
	adds r0, r4, 0
	bl sub_8184290
_0818445A:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08184460:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_84

	thumb_func_start sub_8184468
sub_8184468: @ 8184468
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0x32
	ldrsh r1, [r6, r0]
	movs r2, 0x3C
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818449C
	movs r0, 0
	strh r0, [r6, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl HandleSetAffineData
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r6, 0x1C]
	b _08184544
	.pool
_0818449C:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	movs r2, 0x3A
	ldrsh r4, [r6, r2]
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 24
	lsrs r0, 16
	adds r1, r4, 0
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _081844BC
	adds r0, 0xFF
_081844BC:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldrh r0, [r6, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081844F8
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x20
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x20
	bl Sin
	adds r0, r5
	strh r0, [r6, 0x38]
	adds r0, r4, 0
	movs r1, 0x20
	b _0818451E
_081844F8:
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r5, r2, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	adds r0, r5
	strh r0, [r6, 0x38]
	adds r0, r4, 0
	movs r1, 0x8
_0818451E:
	bl Sin
	lsls r0, 24
	lsrs r0, 24
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _08184530
	adds r0, 0x7
_08184530:
	lsrs r0, 3
	strh r0, [r6, 0x26]
	movs r0, 0x36
	ldrsh r1, [r6, r0]
	movs r0, 0x38
	ldrsh r2, [r6, r0]
	adds r0, r6, 0
	movs r3, 0
	bl HandleSetAffineData
_08184544:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8184468

	thumb_func_start pokemonanimfunc_85
pokemonanimfunc_85: @ 8184550
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08184570
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	movs r0, 0x28
	strh r0, [r4, 0x3A]
	movs r0, 0x50
	strh r0, [r4, 0x3C]
_08184570:
	adds r0, r4, 0
	bl sub_8184468
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_85

	thumb_func_start pokemonanimfunc_86
pokemonanimfunc_86: @ 818457C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0818459A
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	movs r0, 0x28
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x3C]
_0818459A:
	adds r0, r4, 0
	bl sub_8184468
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_86

	thumb_func_start pokemonanimfunc_87
pokemonanimfunc_87: @ 81845A8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081845C6
	adds r0, r4, 0
	bl HandleStartAffineAnim
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	movs r0, 0x50
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x3C]
_081845C6:
	adds r0, r4, 0
	bl sub_8184468
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_87

	thumb_func_start sub_81845D4
sub_81845D4: @ 81845D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x32]
	subs r0, r1
	strh r0, [r4, 0x24]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bgt _081845FE
	ldrh r0, [r4, 0x3A]
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r0, 0x2
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8184610
	str r0, [r4, 0x1C]
_081845FE:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81845D4

	thumb_func_start sub_8184610
sub_8184610: @ 8184610
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	ldrh r2, [r4, 0x24]
	adds r1, r0, r2
	strh r1, [r4, 0x24]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r1, 16
	cmp r1, 0
	blt _0818462E
	ldr r0, =sub_8184640
	str r0, [r4, 0x1C]
_0818462E:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184610

	thumb_func_start sub_8184640
sub_8184640: @ 8184640
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	ldrh r2, [r4, 0x24]
	adds r1, r0, r2
	strh r1, [r4, 0x24]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08184668
	strh r2, [r4, 0x24]
	ldr r0, =sub_8184678
	str r0, [r4, 0x1C]
_08184668:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184640

	thumb_func_start sub_8184678
sub_8184678: @ 8184678
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r2, [r4, 0x34]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _08184698
	ldr r0, =sub_81846B8
	str r0, [r4, 0x1C]
	b _081846AC
	.pool
_08184698:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	negs r0, r0
	strh r0, [r4, 0x36]
	adds r0, r2, 0x1
	strh r0, [r4, 0x34]
_081846AC:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8184678

	thumb_func_start sub_81846B8
sub_81846B8: @ 81846B8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	subs r0, 0x2
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bgt _081846DA
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
_081846DA:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81846B8

	thumb_func_start pokemonanimfunc_88
pokemonanimfunc_88: @ 81846EC
	push {r4,lr}
	adds r4, r0, 0
	bl HandleStartAffineAnim
	movs r2, 0
	movs r1, 0x4
	strh r1, [r4, 0x3C]
	movs r0, 0xC
	strh r0, [r4, 0x3A]
	movs r0, 0x10
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	ldr r0, =sub_81845D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_88

	thumb_func_start pokemonanimfunc_89
pokemonanimfunc_89: @ 8184718
	push {r4,lr}
	adds r4, r0, 0
	bl HandleStartAffineAnim
	movs r2, 0
	movs r1, 0x2
	strh r1, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0xC
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x32]
	ldr r0, =sub_81845D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_89

	thumb_func_start pokemonanimfunc_8A
pokemonanimfunc_8A: @ 8184744
	push {r4,lr}
	adds r4, r0, 0
	bl HandleStartAffineAnim
	movs r1, 0
	strh r1, [r4, 0x3C]
	movs r0, 0x6
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x32]
	ldr r0, =sub_81845D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_8A

	thumb_func_start sub_8184770
sub_8184770: @ 8184770
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	strh r0, [r1, 0x24]
	ldrh r2, [r1, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	ble _0818478E
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x30]
	movs r0, 0
	b _08184790
_0818478E:
	adds r0, r2, 0x1
_08184790:
	strh r0, [r1, 0x2E]
	pop {r0}
	bx r0
	thumb_func_end sub_8184770

	thumb_func_start sub_8184798
sub_8184798: @ 8184798
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_0860AE7C
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r4, 0
	bl sub_8184770
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	bne _081847D0
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _0818482E
	.pool
_081847D0:
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bne _08184800
	ldrb r0, [r1]
	cmp r0, 0
	beq _081847F0
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0x10
	bl BlendPalette
	b _081847FC
	.pool
_081847F0:
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
_081847FC:
	movs r0, 0
	strh r0, [r4, 0x36]
_08184800:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08184828
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _0818482E
	.pool
_08184828:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_0818482E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8184798

	thumb_func_start pokemonanimfunc_8B
pokemonanimfunc_8B: @ 8184834
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08184860
	ldrb r0, [r2, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4, 0
	adds r0, r1
	strh r0, [r2, 0x3C]
	strh r3, [r2, 0x3A]
	strh r3, [r2, 0x38]
	strh r3, [r2, 0x36]
	strh r3, [r2, 0x34]
_08184860:
	adds r0, r2, 0
	bl sub_8184798
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8B

	thumb_func_start pokemonanimfunc_8C
pokemonanimfunc_8C: @ 818486C
	push {r4,r5,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0x1
	bne _08184898
	ldrb r0, [r2, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r5, 0x80
	lsls r5, 1
	adds r1, r5, 0
	adds r0, r1
	strh r0, [r2, 0x3C]
	strh r3, [r2, 0x3A]
	strh r3, [r2, 0x38]
	strh r3, [r2, 0x36]
	strh r4, [r2, 0x34]
_08184898:
	adds r0, r2, 0
	bl sub_8184798
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8C

	thumb_func_start pokemonanimfunc_8D
pokemonanimfunc_8D: @ 81848A4
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _081848D2
	ldrb r0, [r2, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4, 0
	adds r0, r1
	strh r0, [r2, 0x3C]
	strh r3, [r2, 0x3A]
	strh r3, [r2, 0x38]
	strh r3, [r2, 0x36]
	movs r0, 0x2
	strh r0, [r2, 0x34]
_081848D2:
	adds r0, r2, 0
	bl sub_8184798
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8D

	thumb_func_start sub_81848E0
sub_81848E0: @ 81848E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _08184904
	ldrh r0, [r4, 0x3C]
	movs r1, 0x10
	movs r2, 0
	movs r3, 0x1F
	bl BlendPalette
	ldr r0, =SpriteCB_SetDummyOnAnimEnd
	str r0, [r4, 0x1C]
	b _0818492A
	.pool
_08184904:
	movs r5, 0x32
	ldrsh r0, [r4, r5]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gUnknown_0860AE88
	movs r5, 0x30
	ldrsh r1, [r4, r5]
	lsls r1, 1
	adds r1, r3
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
_0818492A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81848E0

	thumb_func_start sub_8184934
sub_8184934: @ 8184934
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _081849CC
	adds r0, r4, 0
	bl sub_817F70C
	movs r3, 0x38
	ldrsh r1, [r4, r3]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08184970
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0818496C
	strh r2, [r4, 0x38]
_0818496C:
	strh r2, [r4, 0x24]
	b _081849C6
_08184970:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	lsls r1, 16
	asrs r1, 15
	movs r0, 0x1
	subs r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 7
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _081849A4
	adds r0, 0xFF
_081849A4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r1, 0
	muls r2, r0
	adds r0, r2, 0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_081849C6:
	adds r0, r4, 0
	bl sub_817F70C
_081849CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8184934

	thumb_func_start pokemonanimfunc_8E
pokemonanimfunc_8E: @ 81849D4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _081849FE
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x30]
_081849FE:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184A0E
	adds r0, r4, 0
	bl sub_81848E0
_08184A0E:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184A30
	adds r0, r4, 0
	bl sub_8184934
_08184A30:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8E

	thumb_func_start pokemonanimfunc_8F
pokemonanimfunc_8F: @ 8184A3C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184A66
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x30]
_08184A66:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184A76
	adds r0, r4, 0
	bl sub_81848E0
_08184A76:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184A98
	adds r0, r4, 0
	bl sub_8184934
_08184A98:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8F

	thumb_func_start pokemonanimfunc_90
pokemonanimfunc_90: @ 8184AA4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184ACE
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x30]
_08184ACE:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184ADE
	adds r0, r4, 0
	bl sub_81848E0
_08184ADE:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184B00
	adds r0, r4, 0
	bl sub_8184934
_08184B00:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_90

	thumb_func_start pokemonanimfunc_91
pokemonanimfunc_91: @ 8184B0C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184B38
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x30]
_08184B38:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184B48
	adds r0, r4, 0
	bl sub_81848E0
_08184B48:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184B6A
	adds r0, r4, 0
	bl sub_8184934
_08184B6A:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_91

	thumb_func_start pokemonanimfunc_92
pokemonanimfunc_92: @ 8184B78
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184BA2
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r0, [r4, 0x30]
_08184BA2:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184BB2
	adds r0, r4, 0
	bl sub_81848E0
_08184BB2:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184BD4
	adds r0, r4, 0
	bl sub_8184934
_08184BD4:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_92

	thumb_func_start pokemonanimfunc_93
pokemonanimfunc_93: @ 8184BE0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184C0A
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r0, [r4, 0x30]
_08184C0A:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184C1A
	adds r0, r4, 0
	bl sub_81848E0
_08184C1A:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184C3C
	adds r0, r4, 0
	bl sub_8184934
_08184C3C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_93

	thumb_func_start pokemonanimfunc_94
pokemonanimfunc_94: @ 8184C48
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184C72
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r0, [r4, 0x30]
_08184C72:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184C82
	adds r0, r4, 0
	bl sub_81848E0
_08184C82:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184CA4
	adds r0, r4, 0
	bl sub_8184934
_08184CA4:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_94

	thumb_func_start pokemonanimfunc_95
pokemonanimfunc_95: @ 8184CB0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184CDC
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x2
	strh r0, [r4, 0x30]
_08184CDC:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184CEC
	adds r0, r4, 0
	bl sub_81848E0
_08184CEC:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184D0E
	adds r0, r4, 0
	bl sub_8184934
_08184D0E:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_95

	thumb_func_start pokemonanimfunc_96
pokemonanimfunc_96: @ 8184D1C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184D48
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x2
	strh r0, [r4, 0x30]
_08184D48:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184D58
	adds r0, r4, 0
	bl sub_81848E0
_08184D58:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184D7A
	adds r0, r4, 0
	bl sub_8184934
_08184D7A:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_96

	thumb_func_start SpriteCB_SetDummyOnAnimEnd
SpriteCB_SetDummyOnAnimEnd: @ 8184D88
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08184D9C
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_08184D9C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpriteCB_SetDummyOnAnimEnd

	.align 2, 0 @ Don't pad with nop.
