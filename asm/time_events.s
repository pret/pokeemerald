	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetMirageRnd
GetMirageRnd: @ 8137890
	push {r4,lr}
	ldr r0, =0x00004024
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004025
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	orrs r4, r0
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMirageRnd

	thumb_func_start SetMirageRnd
SetMirageRnd: @ 81378BC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x00004024
	lsrs r1, r4, 16
	bl VarSet
	ldr r0, =0x00004025
	lsls r4, 16
	lsrs r4, 16
	adds r1, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetMirageRnd

	thumb_func_start InitMirageRnd
InitMirageRnd: @ 81378E4
	push {r4,lr}
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsls r0, 16
	lsrs r0, 16
	orrs r4, r0
	adds r0, r4, 0
	bl SetMirageRnd
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end InitMirageRnd

	thumb_func_start UpdateMirageRnd
UpdateMirageRnd: @ 8137904
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl GetMirageRnd
	adds r1, r0, 0
	cmp r4, 0
	beq _08137928
	ldr r3, =0x41c64e6d
	ldr r2, =0x00003039
_08137918:
	adds r0, r1, 0
	muls r0, r3
	adds r1, r0, r2
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	bne _08137918
_08137928:
	adds r0, r1, 0
	bl SetMirageRnd
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateMirageRnd

	thumb_func_start IsMirageIslandPresent
IsMirageIslandPresent: @ 813793C
	push {r4-r6,lr}
	bl GetMirageRnd
	lsrs r6, r0, 16
	movs r5, 0
_08137946:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _08137978
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	ldr r1, =0x0000ffff
	ands r1, r0
	cmp r1, r6
	bne _08137978
	movs r0, 0x1
	b _08137980
	.pool
_08137978:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08137946
	movs r0, 0
_08137980:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsMirageIslandPresent

	thumb_func_start UpdateShoalTideFlag
UpdateShoalTideFlag: @ 8137988
	push {lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r0, 24
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	cmp r0, 0
	beq _081379CE
	bl RtcCalcLocalTime
	ldr r1, =gUnknown_085B2B44
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081379C8
	ldr r0, =0x0000089a
	bl FlagSet
	b _081379CE
	.pool
_081379C8:
	ldr r0, =0x0000089a
	bl FlagClear
_081379CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateShoalTideFlag

	thumb_func_start Task_WaitWeather
Task_WaitWeather: @ 81379D8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80AC3BC
	lsls r0, 24
	cmp r0, 0
	beq _081379F2
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_081379F2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end Task_WaitWeather

	thumb_func_start WaitWeather
WaitWeather: @ 81379F8
	push {lr}
	ldr r0, =Task_WaitWeather
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end WaitWeather

	thumb_func_start InitBirchState
InitBirchState: @ 8137A0C
	push {lr}
	ldr r0, =0x00004049
	bl GetVarPointer
	movs r1, 0
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitBirchState

	thumb_func_start UpdateBirchState
UpdateBirchState: @ 8137A20
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004049
	bl GetVarPointer
	adds r5, r0, 0
	ldrh r0, [r5]
	adds r4, r0
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0x7
	bl __umodsi3
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateBirchState
