	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




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
