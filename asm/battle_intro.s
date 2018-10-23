	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start SetAnimBgAttribute
SetAnimBgAttribute: @ 811802C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r6, 0x3
	bls _08118040
	b _08118132
_08118040:
	ldr r0, =gUnknown_0859741A
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetGpuReg
	ldr r1, =gUnknown_0203A114
	strh r0, [r1]
	cmp r5, 0x6
	bhi _08118124
	lsls r0, r5, 2
	ldr r1, =_08118068
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118068:
	.4byte _08118084
	.4byte _08118098
	.4byte _081180B0
	.4byte _081180C8
	.4byte _081180E0
	.4byte _081180FC
	.4byte _08118110
_08118084:
	ldr r2, =gUnknown_0203A114
	lsls r3, r4, 6
	ldrb r1, [r2, 0x1]
	movs r0, 0x3F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x1]
	b _08118124
	.pool
_08118098:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x1
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 5
	ldrb r2, [r3, 0x1]
	movs r0, 0x21
	negs r0, r0
	b _0811811E
	.pool
_081180B0:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x1
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 6
	ldrb r2, [r3]
	movs r0, 0x41
	negs r0, r0
	b _081180EE
	.pool
_081180C8:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x3
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0xD
	negs r0, r0
	b _081180EE
	.pool
_081180E0:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x3
	adds r1, r4, 0
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x4
	negs r0, r0
_081180EE:
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08118124
	.pool
_081180FC:
	ldr r2, =gUnknown_0203A114
	lsls r3, r4, 7
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	b _08118124
	.pool
_08118110:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x1F
	adds r1, r4, 0
	ands r1, r0
	ldrb r2, [r3, 0x1]
	movs r0, 0x20
	negs r0, r0
_0811811E:
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
_08118124:
	ldr r0, =gUnknown_0859741A
	adds r0, r6, r0
	ldrb r0, [r0]
	ldr r1, =gUnknown_0203A114
	ldrh r1, [r1]
	bl SetGpuReg
_08118132:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetAnimBgAttribute

	thumb_func_start GetAnimBgAttribute
GetAnimBgAttribute: @ 8118140
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r2, 0x3
	bhi _081181C8
	ldr r0, =gUnknown_0859741E
	adds r0, r2, r0
	ldrb r0, [r0]
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	cmp r4, 0x6
	bhi _081181C8
	lsls r0, r4, 2
	ldr r1, =_08118174
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118174:
	.4byte _08118190
	.4byte _08118198
	.4byte _081181A0
	.4byte _081181A8
	.4byte _081181B0
	.4byte _081181B8
	.4byte _081181C0
_08118190:
	ldr r0, [sp]
	lsls r0, 16
	lsrs r0, 30
	b _081181CA
_08118198:
	ldr r0, [sp]
	lsls r0, 18
	lsrs r0, 31
	b _081181CA
_081181A0:
	ldr r0, [sp]
	lsls r0, 25
	lsrs r0, 31
	b _081181CA
_081181A8:
	ldr r0, [sp]
	lsls r0, 28
	lsrs r0, 30
	b _081181CA
_081181B0:
	ldr r0, [sp]
	lsls r0, 30
	lsrs r0, 30
	b _081181CA
_081181B8:
	ldr r0, [sp]
	lsls r0, 24
	lsrs r0, 31
	b _081181CA
_081181C0:
	ldr r0, [sp]
	lsls r0, 19
	lsrs r0, 27
	b _081181CA
_081181C8:
	movs r0, 0
_081181CA:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetAnimBgAttribute

	thumb_func_start HandleIntroSlide
HandleIntroSlide: @ 81181D4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08118208
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	beq _08118208
	ldr r0, =sub_8118D68
	b _08118258
	.pool
_08118208:
	ldr r2, [r2]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0811821C
	ldr r0, =task00_battle_intro_wireless
	b _08118258
	.pool
_0811821C:
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _08118230
	ldr r0, =task_battle_intro_anim
	b _08118258
	.pool
_08118230:
	movs r0, 0x80
	lsls r0, 5
	ands r2, r0
	cmp r2, 0
	beq _08118250
	ldr r0, =gGameVersion
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08118250
	movs r4, 0x3
	ldr r0, =task00_battle_intro_80BC6C8
	b _08118258
	.pool
_08118250:
	ldr r1, =gUnknown_08597424
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
_08118258:
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r4, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	strh r0, [r1, 0x12]
	strh r0, [r1, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end HandleIntroSlide

	thumb_func_start sub_811828C
sub_811828C: @ 811828C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldr r0, =gBattle_BG1_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG2_X
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811828C

	thumb_func_start task_battle_intro_80BC47C
task_battle_intro_80BC47C: @ 81182EC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	adds r0, 0x6
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	mov r8, r1
	cmp r0, 0x4
	bls _08118318
	b _0811852A
_08118318:
	lsls r0, 2
	ldr r1, =_08118330
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118330:
	.4byte _08118344
	.4byte _08118374
	.4byte _0811839C
	.4byte _081183E4
	.4byte _08118524
_08118344:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08118360
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r1, 0x10
	b _0811836A
	.pool
_08118360:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r1, 0x1
_0811836A:
	strh r1, [r0, 0xC]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0811852A
_08118374:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	mov r3, r8
	adds r1, r0, r3
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0811838C
	b _0811852A
_0811838C:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	b _0811852A
_0811839C:
	ldr r1, =gBattle_WIN0V
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _081183B4
	b _0811852A
_081183B4:
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	add r1, r8
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	ldr r2, =gIntroSlideFlags
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _0811852A
	.pool
_081183E4:
	lsls r0, r4, 2
	adds r1, r0, r4
	lsls r1, 3
	mov r5, r8
	adds r2, r1, r5
	ldrh r3, [r2, 0xE]
	movs r5, 0xE
	ldrsh r1, [r2, r5]
	mov r12, r0
	cmp r1, 0
	beq _08118400
	subs r0, r3, 0x1
	strh r0, [r2, 0xE]
	b _0811842E
_08118400:
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	bne _08118420
	ldr r2, =gBattle_BG1_Y
	ldrh r1, [r2]
	ldr r0, =0x0000ffb0
	cmp r1, r0
	beq _0811842E
	subs r0, r1, 0x2
	b _0811842C
	.pool
_08118420:
	ldr r2, =gBattle_BG1_Y
	ldrh r1, [r2]
	ldr r0, =0x0000ffc8
	cmp r1, r0
	beq _0811842E
	subs r0, r1, 0x1
_0811842C:
	strh r0, [r2]
_0811842E:
	ldr r2, =gBattle_WIN0V
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08118442
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_08118442:
	mov r5, r12
	adds r0, r5, r4
	lsls r0, 3
	mov r2, r8
	adds r1, r0, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0811845A
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_0811845A:
	movs r3, 0
	ldr r5, =gScanlineEffect
	mov r9, r5
	ldr r7, =gScanlineEffectRegBuffers
	mov r6, r9
	adds r5, r1, 0
_08118466:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r5, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _08118466
	cmp r3, 0x9F
	bgt _081184AA
	ldr r7, =gScanlineEffectRegBuffers
	ldr r6, =gScanlineEffect
	ldr r1, =gTasks
	mov r2, r12
	adds r0, r2, r4
	lsls r0, 3
	adds r5, r0, r1
_08118490:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r5, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _08118490
_081184AA:
	mov r3, r12
	adds r0, r3, r4
	lsls r0, 3
	mov r5, r8
	adds r1, r0, r5
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _0811852A
	movs r0, 0x3
	mov r3, r9
	strb r0, [r3, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r2, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _0811852A
	.pool
_08118524:
	adds r0, r4, 0
	bl sub_811828C
_0811852A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end task_battle_intro_80BC47C

	thumb_func_start task00_battle_intro_80BC6C8
task00_battle_intro_80BC6C8: @ 8118538
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x3
	beq _08118578
	cmp r0, 0x3
	bgt _08118568
	cmp r0, 0x2
	beq _0811856C
	b _08118580
	.pool
_08118568:
	cmp r0, 0x4
	bne _08118580
_0811856C:
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	adds r0, 0x8
	b _0811857E
	.pool
_08118578:
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	adds r0, 0x6
_0811857E:
	strh r0, [r1]
_08118580:
	lsls r0, r5, 2
	adds r1, r0, r5
	lsls r1, 3
	adds r4, r1, r2
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	adds r6, r0, 0
	cmp r1, 0x4
	bne _081185E4
	ldr r7, =gBattle_BG1_Y
	ldrh r0, [r4, 0x14]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _081185A6
	ldr r1, =0x000001ff
	adds r0, r1
_081185A6:
	asrs r0, 9
	subs r0, 0x8
	strh r0, [r7]
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0xB3
	bgt _081185C8
	adds r0, r1, 0x4
	b _081185CA
	.pool
_081185C8:
	adds r0, r1, 0x6
_081185CA:
	strh r0, [r4, 0x14]
	ldr r2, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r3, r0, r2
	movs r0, 0x14
	ldrsh r1, [r3, r0]
	movs r0, 0xB4
	lsls r0, 1
	cmp r1, r0
	bne _081185E4
	movs r0, 0
	strh r0, [r3, 0x14]
_081185E4:
	adds r0, r6, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bls _081185F4
	b _0811881A
_081185F4:
	lsls r0, 2
	ldr r1, =_08118608
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118608:
	.4byte _0811861C
	.4byte _0811864C
	.4byte _08118678
	.4byte _081186C8
	.4byte _08118814
_0811861C:
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x10
	strh r3, [r2, 0x10]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08118640
	strh r3, [r2, 0xC]
	b _08118644
	.pool
_08118640:
	movs r0, 0x1
	strh r0, [r2, 0xC]
_08118644:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _0811881A
_0811864C:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118662
	b _0811881A
_08118662:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	b _0811881A
	.pool
_08118678:
	ldr r1, =gBattle_WIN0V
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _08118690
	b _0811881A
_08118690:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	movs r0, 0x1
	strh r0, [r1, 0x12]
	ldr r2, =gIntroSlideFlags
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _0811881A
	.pool
_081186C8:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08118708
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08118728
	ldr r1, =0x00001842
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0xF
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	b _08118728
	.pool
_08118708:
	ldrh r2, [r1, 0x10]
	movs r0, 0x1F
	ands r0, r2
	cmp r0, 0
	beq _08118728
	ldrh r0, [r1, 0x12]
	subs r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	cmp r0, 0
	bne _08118728
	adds r0, r2, 0
	adds r0, 0xFF
	strh r0, [r1, 0x10]
	movs r0, 0x4
	strh r0, [r1, 0x12]
_08118728:
	ldr r2, =gBattle_WIN0V
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0811873C
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_0811873C:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08118752
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_08118752:
	movs r3, 0
	ldr r0, =gScanlineEffect
	mov r8, r0
	ldr r2, =gScanlineEffectRegBuffers
	mov r12, r2
	mov r7, r8
	adds r4, r1, 0
_08118760:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r12
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _08118760
	cmp r3, 0x9F
	bgt _081187A4
	ldr r0, =gScanlineEffectRegBuffers
	mov r12, r0
	ldr r7, =gScanlineEffect
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r4, r0, r1
_0811878A:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r12
	ldrh r0, [r4, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _0811878A
_081187A4:
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0xC
	ldrsh r2, [r1, r3]
	cmp r2, 0
	bne _0811881A
	movs r0, 0x3
	mov r3, r8
	strb r0, [r3, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r2, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _0811881A
	.pool
_08118814:
	adds r0, r5, 0
	bl sub_811828C
_0811881A:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	beq _08118832
	ldrh r1, [r1, 0x10]
	movs r0, 0x52
	bl SetGpuReg
_08118832:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_battle_intro_80BC6C8

	thumb_func_start task_battle_intro_anim
task_battle_intro_anim: @ 8118844
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	adds r0, 0x8
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _0811886E
	b _08118A96
_0811886E:
	lsls r0, 2
	ldr r1, =_08118884
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118884:
	.4byte _08118898
	.4byte _081188F0
	.4byte _0811891C
	.4byte _0811896C
	.4byte _08118A90
_08118898:
	ldr r1, =0x00001842
	movs r0, 0x50
	bl SetGpuReg
	ldr r4, =0x00000808
	movs r0, 0x52
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	strh r4, [r2, 0x10]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _081188E4
	movs r0, 0x10
	b _081188E6
	.pool
_081188E4:
	movs r0, 0x1
_081188E6:
	strh r0, [r2, 0xC]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _08118A96
_081188F0:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118908
	b _08118A96
_08118908:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	b _08118A96
	.pool
_0811891C:
	ldr r1, =gBattle_WIN0V
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _08118934
	b _08118A96
_08118934:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	movs r0, 0x1
	strh r0, [r1, 0x12]
	ldr r2, =gIntroSlideFlags
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _08118A96
	.pool
_0811896C:
	lsls r0, r5, 2
	adds r1, r0, r5
	lsls r1, 3
	adds r2, r1, r4
	ldrh r3, [r2, 0xE]
	movs r6, 0xE
	ldrsh r1, [r2, r6]
	mov r12, r0
	cmp r1, 0
	beq _08118986
	subs r0, r3, 0x1
	strh r0, [r2, 0xE]
	b _081189A6
_08118986:
	ldrh r1, [r2, 0x10]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _081189A6
	ldrh r0, [r2, 0x12]
	subs r0, 0x1
	strh r0, [r2, 0x12]
	lsls r0, 16
	cmp r0, 0
	bne _081189A6
	adds r0, r1, 0
	adds r0, 0xFF
	strh r0, [r2, 0x10]
	movs r0, 0x6
	strh r0, [r2, 0x12]
_081189A6:
	ldr r2, =gBattle_WIN0V
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _081189BA
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_081189BA:
	mov r6, r12
	adds r0, r6, r5
	lsls r0, 3
	adds r1, r0, r4
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _081189D0
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_081189D0:
	movs r3, 0
	ldr r6, =gScanlineEffect
	mov r8, r6
	ldr r7, =gScanlineEffectRegBuffers
	adds r4, r1, 0
_081189DA:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _081189DA
	cmp r3, 0x9F
	bgt _08118A1E
	ldr r7, =gScanlineEffectRegBuffers
	ldr r6, =gScanlineEffect
	ldr r1, =gTasks
	mov r2, r12
	adds r0, r2, r5
	lsls r0, 3
	adds r4, r0, r1
_08118A04:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r4, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _08118A04
_08118A1E:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0xC
	ldrsh r2, [r1, r3]
	cmp r2, 0
	bne _08118A96
	movs r0, 0x3
	mov r6, r8
	strb r0, [r6, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r2, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _08118A96
	.pool
_08118A90:
	adds r0, r5, 0
	bl sub_811828C
_08118A96:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	beq _08118AB0
	ldrh r1, [r1, 0x10]
	movs r0, 0x52
	bl SetGpuReg
_08118AB0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_battle_intro_anim

	thumb_func_start task00_battle_intro_wireless
task00_battle_intro_wireless: @ 8118AC0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	ble _08118B36
	movs r2, 0x10
	ldrsh r0, [r7, r2]
	cmp r0, 0
	bne _08118B36
	ldr r2, =gBattle_BG1_X
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _08118AFE
	cmp r1, 0x4F
	bhi _08118B18
_08118AFE:
	adds r0, r1, 0x3
	strh r0, [r2]
	ldr r1, =gBattle_BG2_X
	ldrh r0, [r1]
	subs r0, 0x3
	strh r0, [r1]
	b _08118B36
	.pool
_08118B18:
	str r5, [sp]
	ldr r1, =0x0600e000
	ldr r4, =0x05000200
	mov r0, sp
	adds r2, r4, 0
	bl CpuSet
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	ldr r1, =0x0600f000
	adds r2, r4, 0
	bl CpuSet
	movs r0, 0x1
	strh r0, [r7, 0x10]
_08118B36:
	ldr r0, =gTasks
	lsls r2, r6, 2
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	movs r3, 0x8
	ldrsh r1, [r1, r3]
	mov r9, r0
	adds r5, r2, 0
	cmp r1, 0x4
	bls _08118B4E
	b _08118D5A
_08118B4E:
	lsls r0, r1, 2
	ldr r1, =_08118B6C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118B6C:
	.4byte _08118B80
	.4byte _08118B92
	.4byte _08118C38
	.4byte _08118C7C
	.4byte _08118D54
_08118B80:
	adds r0, r5, r6
	lsls r0, 3
	add r0, r9
	movs r1, 0x20
	strh r1, [r0, 0xC]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _08118D5A
_08118B92:
	adds r0, r5, r6
	lsls r0, 3
	mov r2, r9
	adds r1, r0, r2
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118BA8
	b _08118D5A
_08118BA8:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r4, =gSprites
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, 0x7D
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r3, [r1, 0x1]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r3, 0x8
	mov r9, r3
	mov r3, r9
	orrs r0, r3
	strb r0, [r1, 0x1]
	ldr r3, [r5]
	adds r0, r3, 0
	adds r0, 0x7D
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	movs r1, 0x1C
	adds r1, r4
	mov r8, r1
	add r0, r8
	ldr r6, =sub_8038B74
	str r6, [r0]
	adds r3, 0x7E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	ands r2, r1
	mov r3, r9
	orrs r2, r3
	strb r2, [r0, 0x1]
	ldr r0, [r5]
	adds r0, 0x7E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r6, [r0]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	ldr r1, =0x00003f06
	movs r0, 0x4A
	bl SetGpuReg
	b _08118D5A
	.pool
_08118C38:
	ldr r1, =gBattle_WIN0V
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _08118C50
	b _08118D5A
_08118C50:
	adds r1, r5, r6
	lsls r1, 3
	add r1, r9
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	ldr r2, =gIntroSlideFlags
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _08118D5A
	.pool
_08118C7C:
	ldr r2, =gBattle_WIN0V
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08118C90
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_08118C90:
	adds r0, r5, r6
	lsls r0, 3
	mov r2, r9
	adds r1, r0, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08118CA6
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_08118CA6:
	movs r3, 0
	ldr r0, =gScanlineEffect
	mov r12, r0
	ldr r2, =gScanlineEffectRegBuffers
	mov r8, r2
	mov r7, r12
	adds r4, r1, 0
_08118CB4:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r8
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _08118CB4
	cmp r3, 0x9F
	bgt _08118CF8
	ldr r0, =gScanlineEffectRegBuffers
	mov r8, r0
	ldr r7, =gScanlineEffect
	ldr r1, =gTasks
	adds r0, r5, r6
	lsls r0, 3
	adds r4, r0, r1
_08118CDE:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r8
	ldrh r0, [r4, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _08118CDE
_08118CF8:
	adds r0, r5, r6
	lsls r0, 3
	mov r2, r9
	adds r1, r0, r2
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08118D5A
	movs r0, 0x3
	mov r2, r12
	strb r0, [r2, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _08118D5A
	.pool
_08118D54:
	adds r0, r6, 0
	bl sub_811828C
_08118D5A:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end task00_battle_intro_wireless

	thumb_func_start sub_8118D68
sub_8118D68: @ 8118D68
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r6, r1, 0
	cmp r0, 0x5
	bls _08118D86
	b _08118FB2
_08118D86:
	lsls r0, 2
	ldr r1, =_08118D98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118D98:
	.4byte _08118DB0
	.4byte _08118DBE
	.4byte _08118E4C
	.4byte _08118EA8
	.4byte _08118F00
	.4byte _08118FAC
_08118DB0:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	movs r1, 0x1
	strh r1, [r0, 0xC]
	b _08118F84
_08118DBE:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r6
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118DD4
	b _08118FB2
_08118DD4:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r1, =0x00005c0a
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =0x00005e0a
	movs r0, 0xC
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	ldr r2, =0x0000f040
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r1, 0xF8
	lsls r1, 6
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	ldr r1, =gBattle_BG0_Y
	ldr r2, =0x0000ffd0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG1_X
	movs r0, 0xF0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_X
	subs r2, 0xC0
	adds r0, r2, 0
	strh r0, [r1]
	b _08118FB2
	.pool
_08118E4C:
	ldr r2, =gBattle_WIN0V
	ldrh r3, [r2]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	adds r1, r3, r0
	strh r1, [r2]
	movs r5, 0xFF
	lsls r5, 8
	ands r1, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	beq _08118E6E
	adds r0, r3, 0
	adds r0, 0xFF
	strh r0, [r2]
_08118E6E:
	ldrh r0, [r2]
	adds r1, r5, 0
	ands r1, r0
	movs r0, 0x80
	lsls r0, 6
	cmp r1, r0
	beq _08118E7E
	b _08118FB2
_08118E7E:
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	ldr r2, =gIntroSlideFlags
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _08118FB2
	.pool
_08118EA8:
	ldr r3, =gBattle_WIN0V
	ldrh r2, [r3]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r2
	movs r1, 0x98
	lsls r1, 7
	cmp r0, r1
	beq _08118EC2
	movs r1, 0xFF
	lsls r1, 2
	adds r0, r2, r1
	strh r0, [r3]
_08118EC2:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r3, r0, r6
	ldrh r1, [r3, 0xC]
	movs r2, 0xC
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08118ED8
	subs r0, r1, 0x2
	strh r0, [r3, 0xC]
_08118ED8:
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r3, 0xC]
	strh r0, [r1]
	ldr r2, =gBattle_BG2_X
	negs r1, r0
	strh r1, [r2]
	lsls r0, 16
	cmp r0, 0
	bne _08118FB2
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _08118FB2
	.pool
_08118F00:
	ldr r1, =gBattle_BG0_Y
	ldrh r0, [r1]
	adds r3, r0, 0x2
	strh r3, [r1]
	ldr r1, =gBattle_BG2_Y
	ldrh r0, [r1]
	adds r0, 0x2
	strh r0, [r1]
	ldr r5, =gBattle_WIN0V
	ldrh r2, [r5]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r2
	movs r1, 0xA0
	lsls r1, 7
	cmp r0, r1
	beq _08118F28
	adds r0, r2, 0
	adds r0, 0xFF
	strh r0, [r5]
_08118F28:
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r0, 0
	bne _08118FB2
	str r0, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000800
	mov r0, sp
	bl CpuSet
	movs r0, 0
	bl GetGpuReg
	ldr r1, =0x0000bfff
	ands r1, r0
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
_08118F84:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _08118FB2
	.pool
_08118FAC:
	adds r0, r4, 0
	bl sub_811828C
_08118FB2:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8118D68

	thumb_func_start sub_8118FBC
sub_8118FBC: @ 8118FBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	adds r6, r2, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x24]
	ldr r7, [sp, 0x28]
	ldr r2, [sp, 0x2C]
	mov r9, r2
	ldr r5, [sp, 0x30]
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gMonSpritesGfxPtr
	ldr r2, [r1]
	lsls r4, 2
	adds r2, 0x4
	adds r2, r4
	ldr r1, =gBattleMonForms
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 11
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x80
	lsls r2, 3
	adds r1, r7, 0
	bl CpuSet
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 5
	adds r1, r7, 0
	adds r3, r5, 0
	bl LoadBgTiles
	adds r0, r6, 0
	adds r0, 0x8
	cmp r6, r0
	bge _08119068
	mov r12, r0
	mov r2, r8
	lsls r7, r2, 1
_0811903A:
	mov r1, r8
	adds r2, r1, 0
	adds r2, 0x8
	adds r4, r6, 0x1
	cmp r1, r2
	bge _08119062
	mov r0, r10
	lsls r3, r0, 12
	lsls r0, r6, 6
	add r0, r9
	adds r6, r7, r0
	subs r1, r2, r1
_08119052:
	adds r0, r5, 0
	orrs r0, r3
	strh r0, [r6]
	adds r5, 0x1
	adds r6, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _08119052
_08119062:
	adds r6, r4, 0
	cmp r6, r12
	blt _0811903A
_08119068:
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 4
	mov r1, r9
	movs r3, 0
	bl LoadBgTilemap
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8118FBC

	thumb_func_start sub_8119094
sub_8119094: @ 8119094
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	mov r8, r5
	ldr r5, [sp, 0x2C]
	ldr r6, [sp, 0x30]
	mov r9, r6
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r1, 24
	lsls r2, 24
	lsls r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	mov r7, r8
	lsls r7, 16
	lsrs r6, r7, 16
	lsls r5, 24
	lsrs r5, 24
	mov r0, r9
	lsls r0, 24
	mov r9, r0
	ldr r4, =0x040000d4
	ldr r0, =gMonSpritesGfxPtr
	ldr r0, [r0]
	lsrs r2, 22
	adds r0, 0x4
	adds r0, r2
	lsrs r3, 13
	ldr r0, [r0]
	adds r0, r3
	str r0, [r4]
	movs r0, 0xC0
	lsls r0, 19
	adds r6, r0
	str r6, [r4, 0x4]
	ldr r0, =0x80000400
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	adds r2, r7, 0
	lsrs r2, 21
	mov r6, r9
	lsrs r6, 15
	subs r4, r2, r6
	lsrs r0, r1, 24
	adds r1, r0, 0
	adds r1, 0x8
	cmp r0, r1
	bge _08119148
	mov r9, r1
	mov r7, r12
	lsls r7, 1
	mov r8, r7
	lsls r5, 11
	str r5, [sp]
_08119110:
	mov r2, r12
	adds r3, r2, 0
	adds r3, 0x8
	adds r5, r0, 0x1
	cmp r2, r3
	bge _08119142
	mov r1, r10
	lsls r6, r1, 12
	lsls r0, 6
	movs r7, 0xC0
	lsls r7, 19
	adds r0, r7
	ldr r1, [sp]
	adds r0, r1, r0
	mov r7, r8
	adds r1, r7, r0
	subs r2, r3, r2
_08119132:
	adds r0, r4, 0
	orrs r0, r6
	strh r0, [r1]
	adds r4, 0x1
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _08119132
_08119142:
	adds r0, r5, 0
	cmp r0, r9
	blt _08119110
_08119148:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119094

	.align 2, 0 @ Don't pad with nop.
