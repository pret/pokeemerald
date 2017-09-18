	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start npc_before_player_of_type
npc_before_player_of_type: @ 8135424
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gUnknown_0203AB40
	adds r1, r4, 0x2
	adds r0, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	bl PlayerGetZCoord
	strb r0, [r4, 0x4]
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	ldrb r2, [r4, 0x4]
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gMapObjects
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r0, [r2, 0x5]
	cmp r0, r5
	bne _08135470
	ldr r1, =gScriptLastTalked
	ldrb r0, [r2, 0x8]
	strh r0, [r1]
	movs r0, 0x1
	b _08135472
	.pool
_08135470:
	movs r0, 0
_08135472:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end npc_before_player_of_type

	thumb_func_start oei_task_add
oei_task_add: @ 8135478
	push {lr}
	ldr r0, =gUnknown_0203AB40
	adds r1, r0, 0x2
	bl GetXYCoordsOneStepInFrontOfPlayer
	ldr r0, =task08_080C9820
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_task_add

	thumb_func_start task08_080C9820
task08_080C9820: @ 813549C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl ScriptContext2_Enable
	ldr r1, =gUnknown_02037590
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrb r1, [r1, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _081354D2
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _0813551E
_081354D2:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x5
	bne _08135504
	movs r0, 0x3B
	bl FieldEffectStart
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8135578
	b _0813551C
	.pool
_08135504:
	bl sub_808C114
	adds r0, r4, 0
	movs r1, 0x39
	bl FieldObjectSetSpecialAnim
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_813552C
_0813551C:
	str r0, [r1]
_0813551E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task08_080C9820

	thumb_func_start sub_813552C
sub_813552C: @ 813552C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08135560
	movs r0, 0x3B
	bl FieldEffectStart
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8135578
	str r0, [r1]
_08135560:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813552C

	thumb_func_start sub_8135578
sub_8135578: @ 8135578
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x6
	bl FieldEffectActiveListContains
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081355FC
	bl player_get_direction_lower_nybble
	ldr r6, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r6, 0x4]
	cmp r0, 0x1
	bne _0813559E
	str r4, [r6, 0x8]
_0813559E:
	ldr r1, [r6, 0x4]
	cmp r1, 0x2
	bne _081355A8
	movs r0, 0x1
	str r0, [r6, 0x8]
_081355A8:
	cmp r1, 0x3
	bne _081355B0
	movs r0, 0x2
	str r0, [r6, 0x8]
_081355B0:
	cmp r1, 0x4
	bne _081355B8
	movs r0, 0x3
	str r0, [r6, 0x8]
_081355B8:
	ldr r5, =gUnknown_02037590
	ldrb r0, [r5, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gMapObjects
	adds r4, r0
	bl GetPlayerAvatarGraphicsIdByCurrentState
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetGraphicsId
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r1, [r6, 0x8]
	bl StartSpriteAnim
	movs r0, 0x6
	bl FieldEffectActiveListRemove
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_813561C
	str r1, [r0]
_081355FC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135578

	thumb_func_start sub_813561C
sub_813561C: @ 813561C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x18]
	lsls r1, 16
	ldrh r0, [r0, 0x1A]
	orrs r1, r0
	bl _call_via_r1
	ldr r1, =gUnknown_02037590
	movs r0, 0
	strb r0, [r1, 0x6]
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813561C

	thumb_func_start sub_8135654
sub_8135654: @ 8135654
	push {r4,lr}
	bl sub_81797DC
	lsls r0, 24
	cmp r0, 0
	beq _0813568C
	ldr r4, =gScriptResult
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_8179834
	b _081356A8
	.pool
_0813568C:
	movs r0, 0x56
	bl npc_before_player_of_type
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813569E
	movs r0, 0
	b _081356AC
_0813569E:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_81356C4
_081356A8:
	str r0, [r1]
	movs r0, 0x1
_081356AC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8135654

	thumb_func_start sub_81356C4
sub_81356C4: @ 81356C4
	push {lr}
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, =gUnknown_082907F0
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81356C4

	thumb_func_start oei_rocksmash
oei_rocksmash: @ 81356E4
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_8135714
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0x13
	bl IncrementGameStat
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_rocksmash

	thumb_func_start sub_8135714
sub_8135714: @ 8135714
	push {lr}
	movs r0, 0x83
	bl PlaySE
	movs r0, 0x25
	bl FieldEffectActiveListRemove
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_8135714

	thumb_func_start sub_813572C
sub_813572C: @ 813572C
	push {lr}
	bl sub_80FE314
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813573E
	movs r0, 0
	b _0813574C
_0813573E:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_dig
	str r0, [r1]
	movs r0, 0x1
_0813574C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813572C

	thumb_func_start hm2_dig
hm2_dig: @ 8135760
	push {lr}
	bl flagmods_08054D70
	movs r0, 0x26
	bl FieldEffectStart
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_dig

	thumb_func_start sub_8135780
sub_8135780: @ 8135780
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_81357BC
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	bl sub_81795E8
	lsls r0, 24
	cmp r0, 0
	bne _081357AC
	movs r0, 0x1
	bl SetPlayerAvatarTransitionFlags
_081357AC:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8135780

	thumb_func_start sub_81357BC
sub_81357BC: @ 81357BC
	push {r4,lr}
	movs r0, 0x26
	bl FieldEffectActiveListRemove
	bl sub_81795E8
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _081357D6
	bl sub_817963C
	b _081357EE
_081357D6:
	ldr r0, =task08_080A1C44
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
_081357EE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81357BC

	thumb_func_start sub_81357FC
sub_81357FC: @ 81357FC
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0203AB50
	ldr r0, =0x00000e88
	bl Alloc
	str r0, [r5]
	ldr r2, =0x00000809
	adds r0, r2
	movs r3, 0
	strb r4, [r0]
	ldr r0, [r5]
	movs r4, 0x80
	lsls r4, 4
	adds r1, r0, r4
	str r3, [r1]
	ldr r1, =0x00000e7c
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00000e7d
	adds r0, r4
	strb r3, [r0]
	ldr r0, =gUnknown_0203AB48
	str r6, [r0]
	ldr r5, [r5]
	adds r2, r5, r2
	ldrb r2, [r2]
	cmp r2, 0x2
	beq _08135888
	cmp r2, 0x2
	bgt _08135864
	cmp r2, 0x1
	beq _0813586A
	b _081358C0
	.pool
_08135864:
	cmp r2, 0x3
	beq _081358A4
	b _081358C0
_0813586A:
	ldr r0, =0x00000804
	adds r1, r5, r0
	ldr r0, =gUnknown_085B269B
	str r0, [r1]
	ldr r4, =0x00000808
	adds r1, r5, r4
	movs r0, 0x2
	b _081358D2
	.pool
_08135888:
	ldr r1, =0x00000804
	adds r0, r5, r1
	ldr r1, =gUnknown_085B269D
	str r1, [r0]
	ldr r4, =0x00000808
	adds r0, r5, r4
	strb r2, [r0]
	b _081358D4
	.pool
_081358A4:
	ldr r0, =0x00000804
	adds r1, r5, r0
	ldr r0, =gUnknown_085B269F
	str r0, [r1]
	ldr r4, =0x00000808
	adds r1, r5, r4
	movs r0, 0x2
	b _081358D2
	.pool
_081358C0:
	ldr r0, =gUnknown_0203AB50
	ldr r1, [r0]
	ldr r0, =0x00000804
	adds r2, r1, r0
	ldr r0, =gUnknown_085B2698
	str r0, [r2]
	ldr r4, =0x00000808
	adds r1, r4
	movs r0, 0x3
_081358D2:
	strb r0, [r1]
_081358D4:
	ldr r0, =sub_813594C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81357FC

	thumb_func_start sub_81358F4
sub_81358F4: @ 81358F4
	push {lr}
	ldr r1, =sub_8059D50
	movs r0, 0x1
	bl sub_81357FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81358F4

	thumb_func_start sub_8135908
sub_8135908: @ 8135908
	push {lr}
	ldr r1, =c2_exit_to_overworld_2_switch
	movs r0, 0x2
	bl sub_81357FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135908

	thumb_func_start sub_813591C
sub_813591C: @ 813591C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_813591C

	thumb_func_start sub_8135938
sub_8135938: @ 8135938
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8135938

	thumb_func_start sub_813594C
sub_813594C: @ 813594C
	push {lr}
_0813594E:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08135972
	bl sub_8135978
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08135972
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813594E
_08135972:
	pop {r0}
	bx r0
	thumb_func_end sub_813594C

	thumb_func_start sub_8135978
sub_8135978: @ 8135978
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x12
	bls _0813598C
	b _08135BB8
_0813598C:
	lsls r0, 2
	ldr r1, =_081359A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081359A0:
	.4byte _081359EC
	.4byte _081359F6
	.4byte _08135A08
	.4byte _08135A0E
	.4byte _08135A30
	.4byte _08135A36
	.4byte _08135A54
	.4byte _08135A70
	.4byte _08135A8C
	.4byte _08135A9A
	.4byte _08135AC4
	.4byte _08135ADC
	.4byte _08135AFC
	.4byte _08135B02
	.4byte _08135B14
	.4byte _08135B1A
	.4byte _08135B64
	.4byte _08135B6A
	.4byte _08135B84
_081359EC:
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	b _08135B9E
_081359F6:
	bl remove_some_task
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135A08:
	bl FreeAllSpritePalettes
	b _08135B9E
_08135A0E:
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135A30:
	bl ResetSpriteData
	b _08135B9E
_08135A36:
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000809
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08135A46
	b _08135B9E
_08135A46:
	bl ResetTasks
	b _08135B9E
	.pool
_08135A54:
	bl sub_8135BDC
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e7e
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _08135B9E
	.pool
_08135A70:
	bl sub_8135C38
	lsls r0, 24
	cmp r0, 0
	bne _08135A7C
	b _08135BD0
_08135A7C:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135A8C:
	bl sub_813625C
	bl sub_81362E0
	bl sub_8136344
	b _08135B9E
_08135A9A:
	movs r0, 0x38
	movs r1, 0x40
	movs r2, 0
	bl sub_8136444
	ldr r1, =gUnknown_0203AB50
	ldr r1, [r1]
	ldr r2, =0x00000e74
	adds r1, r2
	strb r0, [r1]
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135AC4:
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e75
	adds r0, r1
	movs r1, 0x7
	bl sub_8122344
	b _08135B9E
	.pool
_08135ADC:
	ldr r0, =gUnknown_0203AB48
	ldrh r0, [r0, 0x4]
	ldr r1, =0x00001005
	bl sub_8136110
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135AFC:
	bl sub_8135D24
	b _08135B9E
_08135B02:
	bl sub_8135E2C
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135B14:
	bl sub_81363BC
	b _08135B9E
_08135B1A:
	ldr r0, =sub_81365C8
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_03006310
	ldr r2, =gUnknown_0203AB48
	ldrh r1, [r2, 0x6]
	ldrh r2, [r2, 0x4]
	bl ListMenuInit
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x8]
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135B64:
	bl sub_8135DAC
	b _08135B9E
_08135B6A:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _08135BA6
	.pool
_08135B84:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
_08135B9E:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_08135BA6:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08135BD0
	.pool
_08135BB8:
	ldr r0, =sub_8135938
	bl SetVBlankCallback
	ldr r0, =sub_813591C
	bl SetMainCallback2
	movs r0, 0x1
	b _08135BD2
	.pool
_08135BD0:
	movs r0, 0
_08135BD2:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8135978

	thumb_func_start sub_8135BDC
sub_8135BDC: @ 8135BDC
	push {lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085B2620
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0203AB50
	ldr r1, [r0]
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135BDC

	thumb_func_start sub_8135C38
sub_8135C38: @ 8135C38
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e7e
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x5
	bhi _08135D18
	lsls r0, 2
	ldr r1, =_08135C64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08135C64:
	.4byte _08135C7C
	.4byte _08135C98
	.4byte _08135CBC
	.4byte _08135CCC
	.4byte _08135CD8
	.4byte _08135CFC
_08135C7C:
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08D9B2B4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _08135CDE
	.pool
_08135C98:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08135D18
	ldr r0, =gUnknown_08D9B7C8
	ldr r4, =gUnknown_0203AB50
	ldr r1, [r4]
	bl LZDecompressWram
	ldr r1, [r4]
	b _08135CE2
	.pool
_08135CBC:
	ldr r0, =gUnknown_08D9B470
	movs r1, 0
	movs r2, 0xC0
	bl LoadCompressedPalette
	b _08135CDE
	.pool
_08135CCC:
	ldr r0, =gUnknown_085B26F4
	bl LoadCompressedObjectPic
	b _08135CDE
	.pool
_08135CD8:
	ldr r0, =gUnknown_085B26FC
	bl LoadCompressedObjectPalette
_08135CDE:
	ldr r0, =gUnknown_0203AB50
	ldr r1, [r0]
_08135CE2:
	ldr r0, =0x00000e7e
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _08135D18
	.pool
_08135CFC:
	bl sub_8122328
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e7e
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _08135D1A
	.pool
_08135D18:
	movs r0, 0
_08135D1A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8135C38

	thumb_func_start sub_8135D24
sub_8135D24: @ 8135D24
	push {r4,lr}
	ldr r0, =gUnknown_085B2748
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_809882C
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xD0
	bl copy_textbox_border_tile_patterns_to_vram
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_08135D50:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xA
	bls _08135D50
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135D24

	thumb_func_start sub_8135D7C
sub_8135D7C: @ 8135D7C
	push {r4,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r3, =gUnknown_085B271C
	str r3, [sp, 0x8]
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135D7C

	thumb_func_start sub_8135DAC
sub_8135DAC: @ 8135DAC
	push {r4,lr}
	ldr r0, =0x00000111
	bl ItemId_GetItem
	adds r4, r0, 0
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x48
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	movs r0, 0
	adds r1, r4, 0
	bl sub_8135D7C
	ldr r1, =gUnknown_085E931D
	movs r0, 0x2
	movs r2, 0
	bl sub_8135D7C
	ldr r1, =gUnknown_085E9323
	movs r0, 0x3
	movs r2, 0
	bl sub_8135D7C
	ldr r1, =gUnknown_085E9327
	movs r0, 0x4
	movs r2, 0
	bl sub_8135D7C
	ldr r1, =gUnknown_085E932D
	movs r0, 0x5
	movs r2, 0
	bl sub_8135D7C
	ldr r1, =gUnknown_085E9334
	movs r0, 0x6
	movs r2, 0
	bl sub_8135D7C
	movs r4, 0
_08135DFE:
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _08135DFE
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135DAC

	thumb_func_start sub_8135E2C
sub_8135E2C: @ 8135E2C
	push {r4-r7,lr}
	movs r6, 0
	ldr r1, =gUnknown_0203AB50
	ldr r0, [r1]
	ldr r2, =0x0000080a
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _08135E7C
	adds r5, r1, 0
_08135E42:
	lsls r4, r6, 5
	ldr r3, =0x00000954
	adds r4, r3
	ldr r0, [r5]
	adds r0, r4
	adds r1, r6, 0
	bl sub_8135F04
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r7, =0x0000080c
	adds r0, r1, r7
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	movs r3, 0x81
	lsls r3, 4
	adds r0, r1, r3
	adds r0, r2
	str r6, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r4, =0x0000080a
	adds r1, r4
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r6, r0
	blt _08135E42
_08135E7C:
	ldr r5, =gUnknown_0203AB50
	lsls r4, r6, 5
	ldr r7, =0x00000954
	adds r4, r7
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gUnknown_085E9344
	bl StringCopy
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x0000080c
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	movs r0, 0x81
	lsls r0, 4
	adds r1, r0
	adds r1, r2
	movs r0, 0x2
	negs r0, r0
	str r0, [r1]
	ldr r2, =gUnknown_03006310
	adds r1, r2, 0
	ldr r0, =gUnknown_085B27B0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldrb r1, [r2, 0x17]
	movs r0, 0x40
	negs r0, r0
	ands r0, r1
	movs r1, 0x7
	orrs r0, r1
	strb r0, [r2, 0x17]
	ldr r1, [r5]
	ldr r4, =0x0000080a
	adds r0, r1, r4
	ldrb r0, [r0]
	strh r0, [r2, 0xC]
	adds r3, r1, r3
	str r3, [r2]
	ldr r6, =0x0000080b
	adds r1, r6
	ldrb r0, [r1]
	strh r0, [r2, 0xE]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135E2C

	thumb_func_start sub_8135F04
sub_8135F04: @ 8135F04
	push {r4-r6,lr}
	lsls r1, 16
	ldr r2, =gSaveBlock1Ptr
	lsrs r1, 13
	ldr r3, =0x00000848
	adds r1, r3
	ldr r5, [r2]
	adds r5, r1
	ldr r2, =gPokeblockNames
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	adds r4, r0, 0
	movs r0, 0xFC
	strb r0, [r4]
	adds r4, 0x1
	movs r0, 0x12
	strb r0, [r4]
	adds r4, 0x1
	movs r0, 0x57
	strb r0, [r4]
	adds r4, 0x1
	ldr r6, =gStringVar1
	adds r0, r5, 0
	bl sub_8136EA4
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_085E934F
	adds r0, r4, 0
	bl StringExpandPlaceholders
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135F04

	thumb_func_start sub_8135F70
sub_8135F70: @ 8135F70
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _08135F9C
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e74
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8136470
	str r1, [r0]
_08135F9C:
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e7d
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08135FB0
	adds r0, r4, 0
	bl sub_8135FCC
_08135FB0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135F70

	thumb_func_start sub_8135FCC
sub_8135FCC: @ 8135FCC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0x7
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081360A0
	ldr r1, =gSaveBlock1Ptr
	lsls r0, r4, 3
	ldr r2, =0x00000848
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	mov r8, r1
	add r1, sp, 0x8
	movs r0, 0x17
	strh r0, [r1]
	movs r0, 0x18
	strh r0, [r1, 0x2]
	movs r5, 0
	adds r6, r1, 0
_08136002:
	adds r4, r5, 0x1
	lsls r1, r4, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_8136F9C
	lsls r0, 16
	adds r7, r4, 0
	cmp r0, 0
	ble _0813602C
	lsls r1, r5, 12
	adds r0, r1, 0
	adds r0, 0x17
	strh r0, [r6]
	adds r1, 0x18
	strh r1, [r6, 0x2]
	b _08136032
	.pool
_0813602C:
	movs r0, 0xF
	strh r0, [r6]
	strh r0, [r6, 0x2]
_08136032:
	adds r0, r5, 0
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 1
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x3
	bl __umodsi3
	adds r3, r0, 0
	lsls r3, 25
	movs r0, 0xD0
	lsls r0, 20
	adds r3, r0
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	add r1, sp, 0x8
	adds r2, r4, 0
	bl CopyToBgTilemapBufferRect
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _08136002
	ldr r4, =gStringVar1
	mov r0, r8
	bl sub_8136EDC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x4
	bl sub_8135D7C
	b _081360F8
	.pool
_081360A0:
	add r0, sp, 0x8
	movs r1, 0xF
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r5, 0
_081360AA:
	adds r0, r5, 0
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 1
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x3
	bl __umodsi3
	adds r3, r0, 0
	lsls r3, 25
	movs r2, 0xD0
	lsls r2, 20
	adds r3, r2
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	add r1, sp, 0x8
	adds r2, r4, 0
	bl CopyToBgTilemapBufferRect
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _081360AA
	movs r0, 0x7
	movs r1, 0x2
	bl CopyWindowToVram
_081360F8:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8135FCC

	thumb_func_start sub_8136110
sub_8136110: @ 8136110
	push {lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r3, 16
	lsls r1, 16
	lsrs r1, 16
	lsrs r3, 15
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0xE
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r2, 0xF
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8136110

	thumb_func_start sub_8136140
sub_8136140: @ 8136140
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
_0813614A:
	adds r1, r2, 0x1
	lsls r0, r1, 16
	lsrs r6, r0, 16
	mov r12, r1
	cmp r6, 0x27
	bhi _08136192
	ldr r0, =gSaveBlock1Ptr
	mov r9, r0
	lsls r7, r2, 3
	ldr r1, =0x00000848
	mov r8, r1
_08136160:
	mov r0, r9
	ldr r2, [r0]
	adds r0, r2, r7
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _08136188
	ldr r1, =0x00000848
	adds r2, r1
	adds r3, r2, r7
	ldr r4, [r3]
	ldr r5, [r3, 0x4]
	lsls r0, r6, 3
	adds r2, r0
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [r3]
	str r1, [r3, 0x4]
	str r4, [r2]
	str r5, [r2, 0x4]
_08136188:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x27
	bls _08136160
_08136192:
	mov r1, r12
	lsls r0, r1, 16
	lsrs r2, r0, 16
	cmp r2, 0x26
	bls _0813614A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136140

	thumb_func_start sub_81361B0
sub_81361B0: @ 81361B0
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00000848
	adds r6, r0, r1
	cmp r4, r5
	beq _08136246
	movs r0, 0x8
	bl Alloc
	adds r7, r0, 0
	lsls r0, r4, 3
	adds r0, r6
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r7]
	str r1, [r7, 0x4]
	cmp r5, r4
	bls _0813620C
	subs r5, 0x1
	lsls r3, r4, 16
	lsls r0, r5, 16
	asrs r1, r0, 16
	cmp r3, r0
	bge _08136234
	adds r4, r1, 0
_081361E8:
	asrs r3, 16
	lsls r2, r3, 3
	adds r2, r6
	ldr r0, [r2, 0x8]
	ldr r1, [r2, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r3, 0x1
	lsls r3, 16
	asrs r0, r3, 16
	cmp r0, r4
	blt _081361E8
	b _08136234
	.pool
_0813620C:
	lsls r3, r4, 16
	lsls r0, r5, 16
	asrs r1, r0, 16
	cmp r3, r0
	ble _08136234
	adds r4, r1, 0
_08136218:
	asrs r3, 16
	lsls r2, r3, 3
	adds r2, r6
	adds r0, r2, 0
	subs r0, 0x8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	subs r3, 0x1
	lsls r3, 16
	asrs r0, r3, 16
	cmp r0, r4
	bgt _08136218
_08136234:
	lsls r2, r5, 3
	adds r2, r6
	ldr r0, [r7]
	ldr r1, [r7, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r7, 0
	bl Free
_08136246:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81361B0

	thumb_func_start sub_813624C
sub_813624C: @ 813624C
	ldr r1, =gUnknown_0203AB48
	movs r0, 0
	strh r0, [r1, 0x4]
	strh r0, [r1, 0x6]
	bx lr
	.pool
	thumb_func_end sub_813624C

	thumb_func_start sub_813625C
sub_813625C: @ 813625C
	push {r4,r5,lr}
	bl sub_8136140
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x0000080a
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00000848
_08136274:
	ldr r0, [r5]
	lsls r1, r2, 3
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	ldr r3, =gUnknown_0203AB50
	cmp r0, 0
	beq _08136290
	ldr r1, [r3]
	ldr r0, =0x0000080a
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08136290:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x27
	bls _08136274
	ldr r0, [r3]
	ldr r2, =0x0000080a
	adds r0, r2
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r2, [r2]
	cmp r2, 0x9
	bls _081362D0
	ldr r2, =0x0000080b
	adds r1, r0, r2
	movs r0, 0x9
	strb r0, [r1]
	b _081362D6
	.pool
_081362D0:
	ldr r1, =0x0000080b
	adds r0, r1
	strb r2, [r0]
_081362D6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813625C

	thumb_func_start sub_81362E0
sub_81362E0: @ 81362E0
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203AB48
	ldrh r1, [r0, 0x6]
	adds r3, r0, 0
	ldr r4, =gUnknown_0203AB50
	cmp r1, 0
	beq _08136308
	ldrh r0, [r3, 0x6]
	ldr r1, [r4]
	ldr r5, =0x0000080b
	adds r2, r1, r5
	ldrb r2, [r2]
	adds r0, r2
	subs r5, 0x1
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	ble _08136308
	subs r0, r1, r2
	strh r0, [r3, 0x6]
_08136308:
	adds r2, r3, 0
	ldrh r1, [r2, 0x6]
	ldrh r0, [r2, 0x4]
	adds r1, r0
	ldr r0, [r4]
	ldr r4, =0x0000080a
	adds r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _0813633C
	adds r1, r0, 0
	cmp r1, 0
	bne _08136338
	strh r1, [r2, 0x4]
	b _0813633C
	.pool
_08136338:
	subs r0, 0x1
	strh r0, [r3, 0x4]
_0813633C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81362E0

	thumb_func_start sub_8136344
sub_8136344: @ 8136344
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203AB48
	ldrh r1, [r0, 0x4]
	adds r5, r0, 0
	cmp r1, 0x4
	bls _081363A4
	movs r4, 0
	ldrh r0, [r5, 0x4]
	subs r0, 0x4
	cmp r4, r0
	bge _081363A4
	ldrh r2, [r5, 0x6]
	ldr r6, =gUnknown_0203AB50
	ldr r0, [r6]
	ldr r3, =0x0000080b
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, r1
	ldr r7, =0x0000080a
	adds r0, r7
	ldrb r0, [r0]
	cmp r2, r0
	beq _081363A4
	adds r3, r5, 0
_08136374:
	ldrh r0, [r3, 0x4]
	subs r0, 0x1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	adds r0, 0x1
	strh r0, [r3, 0x6]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r3, 0x4]
	subs r0, 0x4
	cmp r4, r0
	bge _081363A4
	ldrh r2, [r5, 0x6]
	ldr r1, [r6]
	ldr r7, =0x0000080b
	adds r0, r1, r7
	ldrb r0, [r0]
	adds r2, r0
	ldr r0, =0x0000080a
	adds r1, r0
	ldrb r1, [r1]
	cmp r2, r1
	bne _08136374
_081363A4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136344

	thumb_func_start sub_81363BC
sub_81363BC: @ 81363BC
	push {r4,lr}
	sub sp, 0x10
	ldr r4, =gUnknown_0203AB50
	ldr r1, [r4]
	ldr r2, =0x00000e7c
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081363FC
	ldr r2, =0x0000080a
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x00000456
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0203AB4E
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xB0
	movs r2, 0x8
	movs r3, 0x98
	bl AddScrollIndicatorArrowPairParametrized
	ldr r1, [r4]
	ldr r2, =0x00000e7c
	adds r1, r2
	strb r0, [r1]
_081363FC:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81363BC

	thumb_func_start sub_8136418
sub_8136418: @ 8136418
	push {r4,lr}
	ldr r4, =gUnknown_0203AB50
	ldr r0, [r4]
	ldr r2, =0x00000e7c
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08136436
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x00000e7c
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_08136436:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136418

	thumb_func_start sub_8136444
sub_8136444: @ 8136444
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_085B2704
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8136444

	thumb_func_start sub_8136470
sub_8136470: @ 8136470
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	ble _08136480
	movs r0, 0
	strh r0, [r4, 0x2E]
_08136480:
	movs r0, 0x2E
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _0813648E
	cmp r5, 0x1
	beq _081364B4
	b _081364E0
_0813648E:
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =gUnknown_085B26F0
	str r0, [r4, 0x10]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	strh r5, [r4, 0x30]
	b _081364E0
	.pool
_081364B4:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _081364E0
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	strh r2, [r4, 0x2E]
	strh r2, [r4, 0x30]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081364E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136470

	thumb_func_start sub_81364EC
sub_81364EC: @ 81364EC
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8136524
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81364EC

	thumb_func_start sub_8136524
sub_8136524: @ 8136524
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r2, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081365BE
	ldr r6, =gUnknown_0203AB50
	ldr r0, [r6]
	ldr r1, =0x00000809
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0813655A
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
_0813655A:
	ldrb r0, [r2]
	ldr r4, =gUnknown_0203AB4E
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl sub_81AE6C8
	bl sub_8136418
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _081365A4
	bl SetMainCallback2
	b _081365AC
	.pool
_081365A4:
	subs r0, r4, 0x6
	ldr r0, [r0]
	bl SetMainCallback2
_081365AC:
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
_081365BE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136524

	thumb_func_start sub_81365C8
sub_81365C8: @ 81365C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	mov r8, r0
	ldr r0, =gTasks + 0x8
	mov r10, r0
	mov r6, r8
	add r6, r10
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081365F4
	b _08136708
_081365F4:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08136602
	b _08136708
_08136602:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0
	beq _08136688
	ldrb r0, [r6]
	ldr r4, =gUnknown_0203AB4E
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl get_coro_args_x18_x1A
	subs r4, 0x6
	ldrh r1, [r4, 0x6]
	ldrh r0, [r4, 0x4]
	adds r1, r0
	ldr r5, =gUnknown_0203AB50
	ldr r0, [r5]
	ldr r2, =0x0000080a
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08136708
	movs r0, 0x5
	bl PlaySE
	ldrh r0, [r4, 0x4]
	ldr r1, =0x00002005
	bl sub_8136110
	ldrh r0, [r4, 0x4]
	ldrh r4, [r4, 0x6]
	adds r0, r4
	strh r0, [r6, 0x4]
	ldr r0, [r5]
	ldr r1, =0x00000e7d
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	mov r0, r10
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_813671C
	str r1, [r0]
	b _08136708
	.pool
_08136688:
	ldr r5, =gUnknown_0203AB48
	ldrh r2, [r5, 0x4]
	mov r8, r2
	ldrb r0, [r6]
	bl ListMenuHandleInput
	adds r4, r0, 0
	ldrb r0, [r6]
	adds r1, r5, 0x6
	adds r2, r5, 0x4
	bl get_coro_args_x18_x1A
	ldrh r0, [r5, 0x4]
	cmp r8, r0
	beq _081366B6
	mov r0, r8
	movs r1, 0x5
	bl sub_8136110
	ldrh r0, [r5, 0x4]
	ldr r1, =0x00001005
	bl sub_8136110
_081366B6:
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081366D0
	adds r0, 0x1
	cmp r4, r0
	bne _081366F8
	b _08136708
	.pool
_081366D0:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gScriptResult
	ldr r2, =0x0000ffff
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =gScriptItemId
	mov r1, r9
	strh r1, [r0]
	adds r0, r7, 0
	bl sub_81364EC
	b _08136708
	.pool
_081366F8:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gScriptItemId
	strh r4, [r0]
	adds r0, r7, 0
	bl sub_8136938
_08136708:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81365C8

	thumb_func_start sub_813671C
sub_813671C: @ 813671C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08136742
	b _08136848
_08136742:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0813676C
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r7]
	ldr r1, =gUnknown_0203AB4E
	subs r2, r1, 0x2
	bl get_coro_args_x18_x1A
	b _08136822
	.pool
_0813676C:
	ldr r6, =gUnknown_0203AB48
	ldrh r4, [r6, 0x6]
	ldrh r5, [r6, 0x4]
	ldrb r0, [r7]
	bl ListMenuHandleInput
	mov r9, r0
	ldrb r0, [r7]
	adds r1, r6, 0x6
	adds r2, r6, 0x4
	bl get_coro_args_x18_x1A
	ldrh r0, [r6, 0x6]
	cmp r4, r0
	bne _08136790
	ldrh r6, [r6, 0x4]
	cmp r5, r6
	beq _081367CA
_08136790:
	movs r4, 0
_08136792:
	ldr r0, =gUnknown_0203AB48
	ldrh r0, [r0, 0x6]
	adds r0, r4, r0
	lsls r0, 16
	lsrs r5, r0, 16
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	cmp r5, r0
	bne _081367B8
	adds r0, r4, 0
	ldr r1, =0x00002005
	bl sub_8136110
	b _081367C0
	.pool
_081367B8:
	adds r0, r4, 0
	movs r1, 0x5
	bl sub_8136110
_081367C0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x8
	bls _08136792
_081367CA:
	ldr r5, =gUnknown_0203AB50
	ldr r0, [r5]
	ldr r4, =0x00000e75
	adds r0, r4
	movs r1, 0x7
	movs r2, 0
	bl sub_81223FC
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gUnknown_0203AB48
	ldrh r3, [r1, 0x4]
	lsls r3, 4
	adds r3, 0x8
	lsls r3, 16
	lsrs r3, 16
	movs r1, 0x7
	movs r2, 0x80
	bl sub_8122448
	movs r0, 0x2
	negs r0, r0
	cmp r9, r0
	beq _08136810
	adds r0, 0x1
	cmp r9, r0
	bne _0813683A
	b _08136848
	.pool
_08136810:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08136830
_08136822:
	mov r0, r8
	movs r1, 0
	bl sub_8136854
	b _08136848
	.pool
_08136830:
	mov r0, r8
	movs r1, 0x1
	bl sub_8136854
	b _08136848
_0813683A:
	movs r0, 0x5
	bl PlaySE
	mov r0, r8
	movs r1, 0
	bl sub_8136854
_08136848:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_813671C

	thumb_func_start sub_8136854
sub_8136854: @ 8136854
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r2, =gUnknown_0203AB48
	ldrh r0, [r2, 0x4]
	ldrh r1, [r2, 0x6]
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e7d
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldrb r0, [r6]
	adds r1, r2, 0x6
	adds r2, 0x4
	bl sub_81AE6C8
	cmp r4, 0
	bne _081368AA
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	cmp r1, r5
	beq _081368BA
	subs r0, r5, 0x1
	cmp r1, r0
	beq _081368AA
	adds r0, r1, 0
	adds r1, r5, 0
	bl sub_81361B0
	bl sub_8135E2C
_081368AA:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, r5
	bge _081368BA
	ldr r1, =gUnknown_0203AB48
	ldrh r0, [r1, 0x4]
	subs r0, 0x1
	strh r0, [r1, 0x4]
_081368BA:
	ldr r0, =gUnknown_03006310
	ldr r2, =gUnknown_0203AB48
	ldrh r1, [r2, 0x6]
	ldrh r2, [r2, 0x4]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000e75
	adds r0, r1
	movs r1, 0x7
	movs r2, 0x1
	bl sub_81223FC
	movs r4, 0
	lsls r5, r7, 2
_081368E6:
	adds r0, r4, 0
	movs r1, 0x5
	bl sub_8136110
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x8
	bls _081368E6
	ldr r0, =gUnknown_0203AB48
	ldrh r0, [r0, 0x4]
	ldr r1, =0x00001005
	bl sub_8136110
	ldr r1, =gTasks
	adds r0, r5, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81365C8
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136854

	thumb_func_start sub_8136938
sub_8136938: @ 8136938
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r1, =0x00000808
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08136968
	movs r0, 0x8
	b _0813696A
	.pool
_08136968:
	movs r0, 0x9
_0813696A:
	strh r0, [r6, 0x2]
	bl sub_8136418
	ldrb r0, [r6, 0x2]
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldrb r0, [r6, 0x2]
	ldr r5, =gUnknown_0203AB50
	ldr r3, [r5]
	ldr r4, =0x00000808
	adds r1, r3, r4
	ldrb r1, [r1]
	ldr r2, =gUnknown_085B2668
	mov r12, r2
	ldr r2, =0x00000804
	adds r3, r2
	ldr r3, [r3]
	mov r2, r12
	bl sub_81995E4
	ldrb r0, [r6, 0x2]
	ldr r1, [r5]
	adds r1, r4
	ldrb r1, [r1]
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	ldrb r0, [r6, 0x2]
	bl PutWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81369E0
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136938

	thumb_func_start sub_81369E0
sub_81369E0: @ 81369E0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08136A3C
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _08136A3C
	adds r0, 0x1
	cmp r4, r0
	bne _08136A18
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_8136DE8
	b _08136A3C
_08136A18:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gUnknown_085B2668
	ldr r0, =gUnknown_0203AB50
	ldr r0, [r0]
	ldr r2, =0x00000804
	adds r0, r2
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl _call_via_r1
_08136A3C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81369E0

	thumb_func_start sub_8136A50
sub_8136A50: @ 8136A50
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203AB50
	ldr r1, [r1]
	movs r2, 0x80
	lsls r2, 4
	adds r1, r2
	ldr r2, =sub_8136A74
	str r2, [r1]
	bl sub_81364EC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136A50

	thumb_func_start sub_8136A74
sub_8136A74: @ 8136A74
	push {lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gScriptItemId
	ldrh r1, [r0]
	lsls r1, 3
	ldr r0, =0x00000848
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r1, =sub_8136AA0
	bl sub_8166204
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136A74

	thumb_func_start sub_8136AA0
sub_8136AA0: @ 8136AA0
	push {lr}
	ldr r0, =gUnknown_0203AB48
	ldr r1, [r0]
	movs r0, 0
	bl sub_81357FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136AA0

	thumb_func_start sub_8136AB4
sub_8136AB4: @ 8136AB4
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	ldrb r0, [r0, 0x2]
	movs r1, 0
	bl sub_8198070
	ldr r0, =gStringVar1
	ldr r3, =gPokeblockNames
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldr r1, =gScriptItemId
	ldrh r1, [r1]
	lsls r1, 3
	adds r2, r1
	ldr r1, =0x00000848
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl StringCopy
	ldr r5, =gStringVar4
	ldr r1, =gUnknown_085E9353
	adds r0, r5, 0
	bl StringExpandPlaceholders
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	ldr r0, =sub_8136B48
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0xA
	movs r2, 0xA
	movs r3, 0xD
	bl DisplayMessageAndContinueTask
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136AB4

	thumb_func_start sub_8136B48
sub_8136B48: @ 8136B48
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_085B27A8
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0xE
	str r2, [sp, 0x8]
	ldr r2, =gUnknown_085B26A4
	str r2, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136B48

	thumb_func_start sub_8136B78
sub_8136B78: @ 8136B78
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gStringVar4
	ldr r1, =gUnknown_085E9367
	adds r0, r5, 0
	bl StringExpandPlaceholders
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	ldr r0, =sub_8136BC0
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0xA
	movs r2, 0xA
	movs r3, 0xD
	bl DisplayMessageAndContinueTask
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136B78

	thumb_func_start sub_8136BC0
sub_8136BC0: @ 8136BC0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08136C36
	ldr r0, =gScriptItemId
	ldrb r0, [r0]
	bl sub_8136F68
	movs r0, 0x5
	bl PlaySE
	ldr r5, =gUnknown_0203AB4E
	subs r6, r5, 0x2
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4]
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81AE6C8
	ldrh r0, [r6]
	movs r1, 0x5
	bl sub_8136110
	bl sub_813625C
	bl sub_81362E0
	bl sub_8135E2C
	ldr r0, =gUnknown_03006310
	ldrh r1, [r5]
	ldrh r2, [r6]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldrh r0, [r6]
	ldr r1, =0x00001005
	bl sub_8136110
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r7, 0
	bl sub_8136C54
_08136C36:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136BC0

	thumb_func_start sub_8136C54
sub_8136C54: @ 8136C54
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xA
	movs r1, 0
	bl sub_8197DF8
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	bl sub_81363BC
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81365C8
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136C54

	thumb_func_start sub_8136C8C
sub_8136C8C: @ 8136C8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gEnemyParty
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSaveBlock1Ptr
	ldr r7, =gScriptItemId
	ldrh r2, [r7]
	lsls r2, 3
	ldr r6, =0x00000848
	adds r2, r6
	ldr r1, [r5]
	adds r1, r2
	bl sub_8136FE4
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gBattleTextBuff1
	ldr r3, =gPokeblockNames
	ldr r2, [r5]
	ldrh r1, [r7]
	lsls r1, 3
	adds r2, r1
	adds r2, r6
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl StringCopy
	ldrb r0, [r7]
	bl sub_8136F68
	ldr r1, [r5]
	ldrh r0, [r7]
	lsls r0, 3
	adds r1, r0
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 8
	strh r0, [r7]
	lsls r4, 16
	asrs r4, 16
	cmp r4, 0
	bne _08136D10
	adds r0, 0x1
	b _08136D1A
	.pool
_08136D10:
	cmp r4, 0
	ble _08136D18
	adds r0, 0x2
	b _08136D1A
_08136D18:
	adds r0, 0x3
_08136D1A:
	strh r0, [r7]
	mov r0, r8
	bl sub_81364EC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8136C8C

	thumb_func_start sub_8136D2C
sub_8136D2C: @ 8136D2C
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gScriptItemId
	ldrb r0, [r5]
	bl SafariZoneActivatePokeblockFeeder
	ldr r0, =gStringVar1
	ldr r3, =gPokeblockNames
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrh r1, [r5]
	lsls r1, 3
	adds r2, r1
	ldr r1, =0x00000848
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl StringCopy
	ldr r1, =gScriptResult
	ldrh r0, [r5]
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8136F68
	movs r0, 0
	strh r0, [r5]
	adds r0, r4, 0
	bl sub_81364EC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136D2C

	thumb_func_start sub_8136D90
sub_8136D90: @ 8136D90
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gSpecialVar_0x8004
	ldr r0, =gSaveBlock1Ptr
	ldr r5, =gScriptItemId
	ldrh r1, [r5]
	lsls r1, 3
	ldr r2, =0x00000848
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
	bl sub_818E704
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6]
	ldr r1, =gScriptResult
	ldrh r0, [r5]
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8136F68
	movs r0, 0
	strh r0, [r5]
	adds r0, r4, 0
	bl sub_81364EC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136D90

	thumb_func_start sub_8136DE8
sub_8136DE8: @ 8136DE8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r0, r4, r5
	ldrb r0, [r0, 0x2]
	movs r1, 0
	bl sub_8198070
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	bl sub_81363BC
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81365C8
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136DE8

	thumb_func_start sub_8136E20
sub_8136E20: @ 8136E20
	push {r4,lr}
	lsls r0, 24
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	lsrs r0, 21
	adds r1, r0
	ldr r2, =0x00000848
	adds r1, r2
	movs r2, 0
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	ldr r4, =0x00000849
	adds r1, r4
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	adds r4, 0x1
	adds r1, r4
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	adds r4, 0x1
	adds r1, r4
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	adds r4, 0x1
	adds r1, r4
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	adds r4, 0x1
	adds r1, r4
	strb r2, [r1]
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =0x0000084e
	adds r1, r0
	strb r2, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8136E20

	thumb_func_start ClearPokeblocks
ClearPokeblocks: @ 8136E88
	push {r4,lr}
	movs r4, 0
_08136E8C:
	adds r0, r4, 0
	bl sub_8136E20
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x27
	bls _08136E8C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ClearPokeblocks

	thumb_func_start sub_8136EA4
sub_8136EA4: @ 8136EA4
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_8136F9C
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x1
_08136EB4:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8136F9C
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bcs _08136ECC
	adds r5, r0, 0
_08136ECC:
	adds r1, r4, 0
	cmp r1, 0x4
	bls _08136EB4
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8136EA4

	thumb_func_start sub_8136EDC
sub_8136EDC: @ 8136EDC
	push {lr}
	movs r1, 0x6
	bl sub_8136F9C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x63
	bls _08136EEE
	movs r0, 0x63
_08136EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8136EDC

	thumb_func_start sub_8136EF4
sub_8136EF4: @ 8136EF4
	push {lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r3, =0x00000848
_08136EFE:
	lsls r0, r1, 3
	adds r0, r2, r0
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08136F18
	lsls r0, r1, 24
	asrs r0, 24
	b _08136F26
	.pool
_08136F18:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x27
	bls _08136EFE
	movs r0, 0x1
	negs r0, r0
_08136F26:
	pop {r1}
	bx r1
	thumb_func_end sub_8136EF4

	thumb_func_start sub_8136F2C
sub_8136F2C: @ 8136F2C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8136EF4
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08136F60
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	lsls r0, r1, 3
	ldr r1, =0x00000848
	adds r2, r1
	adds r2, r0
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x1
	b _08136F62
	.pool
_08136F60:
	movs r0, 0
_08136F62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8136F2C

	thumb_func_start sub_8136F68
sub_8136F68: @ 8136F68
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, r2, 3
	adds r0, r1
	ldr r1, =0x00000848
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08136F94
	adds r0, r2, 0
	bl sub_8136E20
	movs r0, 0x1
	b _08136F96
	.pool
_08136F94:
	movs r0, 0
_08136F96:
	pop {r1}
	bx r1
	thumb_func_end sub_8136F68

	thumb_func_start sub_8136F9C
sub_8136F9C: @ 8136F9C
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0
	bne _08136FAC
	ldrb r0, [r0]
	b _08136FDE
_08136FAC:
	cmp r1, 0x1
	bne _08136FB4
	ldrb r0, [r0, 0x1]
	b _08136FDE
_08136FB4:
	cmp r1, 0x2
	bne _08136FBC
	ldrb r0, [r0, 0x2]
	b _08136FDE
_08136FBC:
	cmp r1, 0x3
	bne _08136FC4
	ldrb r0, [r0, 0x3]
	b _08136FDE
_08136FC4:
	cmp r1, 0x4
	bne _08136FCC
	ldrb r0, [r0, 0x4]
	b _08136FDE
_08136FCC:
	cmp r1, 0x5
	bne _08136FD4
	ldrb r0, [r0, 0x5]
	b _08136FDE
_08136FD4:
	cmp r2, 0x6
	beq _08136FDC
	movs r0, 0
	b _08136FDE
_08136FDC:
	ldrb r0, [r0, 0x6]
_08136FDE:
	pop {r1}
	bx r1
	thumb_func_end sub_8136F9C

	thumb_func_start sub_8136FE4
sub_8136FE4: @ 8136FE4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r1
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0
	movs r4, 0
	ldr r1, =gPokeblockFlavorCompatibilityTable
	mov r9, r1
	lsls r1, r0, 2
	adds r7, r1, r0
_08136FFE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	adds r1, r5, 0
	bl sub_8136F9C
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	ble _0813702A
	adds r0, r7, r4
	add r0, r9
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	muls r1, r0
	lsls r0, r6, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
_0813702A:
	adds r4, r5, 0
	cmp r4, 0x4
	bls _08136FFE
	lsls r0, r6, 16
	asrs r0, 16
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8136FE4

	thumb_func_start sub_8137044
sub_8137044: @ 8137044
	push {r4,lr}
	adds r4, r1, 0
	movs r1, 0
	bl sub_8136F9C
	lsls r0, 24
	ldr r1, =gPokeblockNames
	lsrs r0, 22
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137044

	thumb_func_start sub_8137068
sub_8137068: @ 8137068
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r7, =gPokeblockNames
_08137074:
	lsls r1, r4, 3
	ldr r0, =gUnknown_085B2720
	adds r1, r0
	adds r0, r5, 0
	bl sub_8136FE4
	lsls r0, 16
	cmp r0, 0
	ble _081370A0
	adds r0, r4, 0x1
	lsls r0, 2
	adds r0, r7
	ldr r1, [r0]
	adds r0, r6, 0
	bl StringCopy
	movs r0, 0x1
	b _081370AC
	.pool
_081370A0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _08137074
	movs r0, 0
_081370AC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8137068

	thumb_func_start sub_81370B4
sub_81370B4: @ 81370B4
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r7, 0
	movs r6, 0
_081370BC:
	adds r1, r7, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_8136F9C
	adds r4, r0, 0
	adds r1, r6, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_8136F9C
	lsls r4, 16
	lsls r0, 16
	lsls r1, r6, 16
	cmp r4, r0
	bge _081370E2
	lsrs r7, r1, 16
_081370E2:
	movs r2, 0x80
	lsls r2, 9
	adds r0, r1, r2
	lsrs r6, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _081370BC
	lsls r0, r7, 24
	lsrs r0, 24
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81370B4

	thumb_func_start sub_81370FC
sub_81370FC: @ 81370FC
	push {r4,lr}
	bl sub_81798D0
	lsls r0, 24
	cmp r0, 0
	beq _08137134
	ldr r4, =gScriptResult
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_8179918
	b _08137152
	.pool
_08137134:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x15]
	cmp r0, 0x1
	bne _08137170
	ldr r0, =0x00000888
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08137170
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_flash
_08137152:
	str r0, [r1]
	movs r0, 0x1
	b _08137172
	.pool
_08137170:
	movs r0, 0
_08137172:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81370FC

	thumb_func_start hm2_flash
hm2_flash: @ 8137178
	push {r4,lr}
	bl oei_task_add
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =sub_81371B4
	lsrs r1, r2, 16
	strh r1, [r0, 0x18]
	strh r2, [r0, 0x1A]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_flash

	thumb_func_start sub_81371B4
sub_81371B4: @ 81371B4
	push {lr}
	movs r0, 0xCF
	bl PlaySE
	ldr r0, =0x00000888
	bl FlagSet
	ldr r0, =gUnknown_082926F8
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81371B4

	thumb_func_start sub_81371D4
sub_81371D4: @ 81371D4
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81371D4

	thumb_func_start sub_81371EC
sub_81371EC: @ 81371EC
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81371EC

	thumb_func_start c2_change_map
c2_change_map: @ 8137200
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r4, 0
	str r4, [sp, 0x4]
	add r0, sp, 0x4
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, sp
	strh r4, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl ResetPaletteFade
	bl ResetTasks
	bl ResetSpriteData
	ldr r3, =0x04000208
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, =0x04000200
	ldrh r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	ldr r0, =sub_81371EC
	bl SetVBlankCallback
	ldr r0, =sub_81371D4
	bl SetMainCallback2
	bl sub_8137304
	lsls r0, 24
	cmp r0, 0
	bne _081372D2
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_081372D2:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_change_map

	thumb_func_start sub_8137304
sub_8137304: @ 8137304
	push {r4-r7,lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r6, r0, 24
	bl sav1_map_get_light_level
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r4, =gUnknown_085B27C8
	ldrb r0, [r4]
	cmp r0, 0
	beq _08137358
	adds r7, r4, 0
	adds r0, r4, 0x4
	mov r12, r0
_08137326:
	lsls r2, r3, 3
	adds r1, r2, r7
	ldrb r0, [r1]
	cmp r0, r6
	bne _08137348
	ldrb r0, [r1, 0x1]
	cmp r0, r5
	bne _08137348
	mov r1, r12
	adds r0, r2, r1
	ldr r0, [r0]
	bl _call_via_r0
	movs r0, 0x1
	b _0813735A
	.pool
_08137348:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08137326
_08137358:
	movs r0, 0
_0813735A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8137304

	thumb_func_start sub_8137360
sub_8137360: @ 8137360
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r5, r0, 24
	lsrs r4, r1, 24
	movs r3, 0
	ldr r1, =gUnknown_085B27C8
	ldrb r0, [r1]
	cmp r0, 0
	beq _081373A0
	adds r6, r1, 0
_08137376:
	lsls r0, r3, 3
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, r5
	bne _08137390
	ldrb r0, [r2, 0x1]
	cmp r0, r4
	bne _08137390
	ldrb r0, [r2, 0x2]
	b _081373A2
	.pool
_08137390:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08137376
_081373A0:
	movs r0, 0
_081373A2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8137360

	thumb_func_start fade_type_for_given_maplight_pair
fade_type_for_given_maplight_pair: @ 81373A8
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r5, r0, 24
	lsrs r4, r1, 24
	movs r3, 0
	ldr r1, =gUnknown_085B27C8
	ldrb r0, [r1]
	cmp r0, 0
	beq _081373E8
	adds r6, r1, 0
_081373BE:
	lsls r0, r3, 3
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, r5
	bne _081373D8
	ldrb r0, [r2, 0x1]
	cmp r0, r4
	bne _081373D8
	ldrb r0, [r2, 0x3]
	b _081373EA
	.pool
_081373D8:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081373BE
_081373E8:
	movs r0, 0
_081373EA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end fade_type_for_given_maplight_pair

	thumb_func_start sub_81373F0
sub_81373F0: @ 81373F0
	push {lr}
	ldr r0, =sub_8137404
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81373F0

	thumb_func_start sub_8137404
sub_8137404: @ 8137404
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_8137420
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8137404

	thumb_func_start sub_8137420
sub_8137420: @ 8137420
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_085B2A90
	ldr r1, =0x0600c000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B28B0
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B2850
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085B28A0
	movs r1, 0xE0
	movs r2, 0x10
	bl LoadPalette
	ldr r1, =0x00003e41
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001f0c
	movs r0, 0x8
	bl SetGpuReg
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81374C4
	str r1, [r0]
	movs r2, 0
	movs r1, 0x10
	strh r1, [r0, 0x8]
	strh r2, [r0, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137420

	thumb_func_start sub_81374C4
sub_81374C4: @ 81374C4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrh r4, [r5, 0xA]
	movs r0, 0x80
	lsls r0, 5
	adds r1, r4, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	cmp r4, 0x10
	bhi _081374F8
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	b _08137500
	.pool
_081374F8:
	movs r0, 0
	strh r0, [r5, 0xC]
	ldr r0, =sub_813750C
	str r0, [r5]
_08137500:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81374C4

	thumb_func_start sub_813750C
sub_813750C: @ 813750C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =0x00001010
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0xC]
	cmp r1, 0x7
	bhi _08137554
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	lsls r1, 1
	ldr r0, =gUnknown_085B28A0
	adds r0, r1, r0
	movs r2, 0x10
	subs r2, r1
	lsls r2, 16
	lsrs r2, 16
	movs r1, 0xE0
	bl LoadPalette
	b _08137566
	.pool
_08137554:
	ldr r0, =gUnknown_085B2850
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =sub_8137574
	str r0, [r4]
	movs r0, 0x8
	strh r0, [r4, 0xC]
_08137566:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813750C

	thumb_func_start sub_8137574
sub_8137574: @ 8137574
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08137598
	subs r0, r2, 0x1
	strh r0, [r1, 0xC]
	b _081375A0
	.pool
_08137598:
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_081375A0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137574

	thumb_func_start sub_81375A8
sub_81375A8: @ 81375A8
	push {lr}
	ldr r0, =sub_81375BC
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81375A8

	thumb_func_start sub_81375BC
sub_81375BC: @ 81375BC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_81375D8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81375BC

	thumb_func_start sub_81375D8
sub_81375D8: @ 81375D8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_085B2A90
	ldr r1, =0x0600c000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B28B0
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00001f0c
	movs r0, 0x8
	bl SetGpuReg
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gUnknown_085B2850
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085B2870
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8137678
	str r1, [r0]
	movs r2, 0
	movs r1, 0x10
	strh r1, [r0, 0x8]
	strh r2, [r0, 0xA]
	strh r2, [r0, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81375D8

	thumb_func_start sub_8137678
sub_8137678: @ 8137678
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0xC]
	cmp r1, 0xF
	bhi _081376B4
	adds r2, r1, 0x1
	adds r0, r2, 0x1
	strh r0, [r4, 0xC]
	movs r0, 0xF
	subs r0, r1
	lsls r0, 1
	ldr r1, =gUnknown_085B2890
	adds r0, r1
	lsls r2, 17
	lsrs r2, 16
	movs r1, 0xE0
	bl LoadPalette
	b _081376C8
	.pool
_081376B4:
	ldr r1, =0x00001010
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =0x00003e41
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =sub_81376DC
	str r0, [r4]
_081376C8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137678

	thumb_func_start sub_81376DC
sub_81376DC: @ 81376DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrh r0, [r5, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 16
	lsrs r4, r1, 16
	movs r0, 0x80
	lsls r0, 21
	adds r1, r0
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	cmp r4, 0
	beq _08137714
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	b _08137726
	.pool
_08137714:
	ldr r0, =gUnknown_085B2870
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_08137726:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81376DC

	thumb_func_start sub_8137734
sub_8137734: @ 8137734
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x1C
	bl sp000_heal_pokemon
	ldr r4, =0x00000864
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _08137760
	ldr r0, =gUnknown_0203BCE4
	strb r1, [r0]
	b _0813776C
	.pool
_08137760:
	ldr r1, =gUnknown_0203BCE4
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl FlagSet
_0813776C:
	movs r0, 0x1
	bl GetGameStat
	cmp r0, 0
	bne _0813778E
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrh r1, [r2, 0xE]
	lsls r1, 16
	ldrb r0, [r2, 0x10]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x11]
	orrs r1, r0
	movs r0, 0x1
	bl sav12_xor_set
_0813778E:
	bl sub_8076D48
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _081377AC
	movs r0, 0x1
	bl sub_8084F6C
	b _081377B2
	.pool
_081377AC:
	movs r0, 0x2
	bl sub_8084F6C
_081377B2:
	movs r7, 0
	movs r6, 0
	add r0, sp, 0x18
	mov r8, r0
	mov r5, sp
_081377BC:
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	movs r0, 0
	strb r6, [r5]
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _0813780A
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _0813780A
	adds r0, r4, 0
	movs r1, 0x43
	bl GetMonData
	cmp r0, 0
	bne _0813780A
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x43
	add r2, sp, 0x18
	bl SetMonData
	adds r0, r4, 0
	bl sub_80EE5A4
	strb r0, [r5, 0x1]
	movs r7, 0x1
_0813780A:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x5
	ble _081377BC
	cmp r7, 0x1
	bne _0813785A
	movs r0, 0x2A
	bl IncrementGameStat
	ldr r0, =0x0000089b
	bl FlagSet
	mov r3, sp
	add r2, sp, 0x4
	movs r6, 0x4
_08137828:
	ldrb r1, [r3, 0x1]
	ldrb r0, [r2, 0x1]
	cmp r0, r1
	bls _08137838
	ldr r1, [sp]
	ldr r0, [r2]
	str r0, [sp]
	str r1, [r2]
_08137838:
	adds r2, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _08137828
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bls _0813785A
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x43
	bl sub_80EE4DC
_0813785A:
	ldr r0, =sub_8173694
	bl SetMainCallback2
	movs r0, 0
	add sp, 0x1C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8137734

	thumb_func_start sp0C8_whiteout_maybe
sp0C8_whiteout_maybe: @ 813787C
	push {lr}
	ldr r0, =c2_whiteout
	bl SetMainCallback2
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sp0C8_whiteout_maybe

	thumb_func_start sub_8137890
sub_8137890: @ 8137890
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
	thumb_func_end sub_8137890

	thumb_func_start sub_81378BC
sub_81378BC: @ 81378BC
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
	thumb_func_end sub_81378BC

	thumb_func_start sub_81378E4
sub_81378E4: @ 81378E4
	push {r4,lr}
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsls r0, 16
	lsrs r0, 16
	orrs r4, r0
	adds r0, r4, 0
	bl sub_81378BC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81378E4

	thumb_func_start sub_8137904
sub_8137904: @ 8137904
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl sub_8137890
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
	bl sub_81378BC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137904

	thumb_func_start sub_813793C
sub_813793C: @ 813793C
	push {r4-r6,lr}
	bl sub_8137890
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
	thumb_func_end sub_813793C

	thumb_func_start sub_8137988
sub_8137988: @ 8137988
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
	bl FlagReset
_081379CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137988

	thumb_func_start sub_81379D8
sub_81379D8: @ 81379D8
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
	thumb_func_end sub_81379D8

	thumb_func_start sub_81379F8
sub_81379F8: @ 81379F8
	push {lr}
	ldr r0, =sub_81379D8
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81379F8

	thumb_func_start sub_8137A0C
sub_8137A0C: @ 8137A0C
	push {lr}
	ldr r0, =0x00004049
	bl GetVarPointer
	movs r1, 0
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137A0C

	thumb_func_start sub_8137A20
sub_8137A20: @ 8137A20
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
	thumb_func_end sub_8137A20

	thumb_func_start sub_8137A4C
sub_8137A4C: @ 8137A4C
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08137A70
	movs r0, 0
	bl sub_80C0844
	ldr r1, =gSpecialVar_0x8005
	strh r0, [r1]
	movs r0, 0x1
	bl sub_80C0844
	b _08137A80
	.pool
_08137A70:
	movs r0, 0
	bl pokedex_count
	ldr r1, =gSpecialVar_0x8005
	strh r0, [r1]
	movs r0, 0x1
	bl pokedex_count
_08137A80:
	ldr r1, =gSpecialVar_0x8006
	strh r0, [r1]
	bl IsNationalPokedexEnabled
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8137A4C

	thumb_func_start sub_8137A98
sub_8137A98: @ 8137A98
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x9
	bhi _08137AA4
	b _08137BFC
_08137AA4:
	cmp r0, 0x13
	bhi _08137AB0
	ldr r0, =gUnknown_082A5DAB
	b _08137C06
	.pool
_08137AB0:
	cmp r0, 0x1D
	bhi _08137ABC
	ldr r0, =gUnknown_082A5DF1
	b _08137C06
	.pool
_08137ABC:
	cmp r0, 0x27
	bhi _08137AC8
	ldr r0, =gUnknown_082A5E34
	b _08137C06
	.pool
_08137AC8:
	cmp r0, 0x31
	bhi _08137AD4
	ldr r0, =gUnknown_082A5E83
	b _08137C06
	.pool
_08137AD4:
	cmp r0, 0x3B
	bhi _08137AE0
	ldr r0, =gUnknown_082A5EB9
	b _08137C06
	.pool
_08137AE0:
	cmp r0, 0x45
	bhi _08137AEC
	ldr r0, =gUnknown_082A5EF4
	b _08137C06
	.pool
_08137AEC:
	cmp r0, 0x4F
	bhi _08137AF8
	ldr r0, =gUnknown_082A5F39
	b _08137C06
	.pool
_08137AF8:
	cmp r0, 0x59
	bhi _08137B04
	ldr r0, =gUnknown_082A5F82
	b _08137C06
	.pool
_08137B04:
	cmp r0, 0x63
	bhi _08137B10
	ldr r0, =gUnknown_082A5FB9
	b _08137C06
	.pool
_08137B10:
	cmp r0, 0x6D
	bhi _08137B1C
	ldr r0, =gUnknown_082A6018
	b _08137C06
	.pool
_08137B1C:
	cmp r0, 0x77
	bhi _08137B28
	ldr r0, =gUnknown_082A6061
	b _08137C06
	.pool
_08137B28:
	cmp r0, 0x81
	bhi _08137B34
	ldr r0, =gUnknown_082A609C
	b _08137C06
	.pool
_08137B34:
	cmp r0, 0x8B
	bhi _08137B40
	ldr r0, =gUnknown_082A60D5
	b _08137C06
	.pool
_08137B40:
	cmp r0, 0x95
	bhi _08137B4C
	ldr r0, =gUnknown_082A6124
	b _08137C06
	.pool
_08137B4C:
	cmp r0, 0x9F
	bhi _08137B58
	ldr r0, =gUnknown_082A616F
	b _08137C06
	.pool
_08137B58:
	cmp r0, 0xA9
	bhi _08137B64
	ldr r0, =gUnknown_082A61D6
	b _08137C06
	.pool
_08137B64:
	cmp r0, 0xB3
	bhi _08137B70
	ldr r0, =gUnknown_082A623A
	b _08137C06
	.pool
_08137B70:
	cmp r0, 0xBD
	bhi _08137B7C
	ldr r0, =gUnknown_082A6287
	b _08137C06
	.pool
_08137B7C:
	cmp r0, 0xC7
	bls _08137BEA
	cmp r0, 0xC8
	bne _08137BB8
	ldr r0, =0x00000199
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	bne _08137BEA
	movs r0, 0xCD
	lsls r0, 1
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	bne _08137BEA
	b _08137C04
	.pool
_08137BB8:
	cmp r0, 0xC9
	bne _08137BF8
	ldr r0, =0x00000199
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _08137C04
	movs r0, 0xCD
	lsls r0, 1
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _08137C04
_08137BEA:
	ldr r0, =gUnknown_082A62C9
	b _08137C06
	.pool
_08137BF8:
	cmp r0, 0xCA
	beq _08137C04
_08137BFC:
	ldr r0, =gUnknown_082A5D6C
	b _08137C06
	.pool
_08137C04:
	ldr r0, =gUnknown_082A6312
_08137C06:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8137A98

	thumb_func_start sub_8137C10
sub_8137C10: @ 8137C10
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl sub_8137A98
	bl box_related_two__2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137C10

	thumb_func_start sub_8137C28
sub_8137C28: @ 8137C28
	push {lr}
	ldr r0, =sub_8174194
	bl SetMainCallback2
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137C28

	thumb_func_start sub_8137C3C
sub_8137C3C: @ 8137C3C
	push {lr}
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	ldr r1, =gFieldCallback
	ldr r0, =mapldr_080CA5C0
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137C3C

	thumb_func_start mapldr_080CA5C0
mapldr_080CA5C0: @ 8137C5C
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	bl sub_8085784
	bl sp109_CreatePCMenu
	bl sub_80E2514
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_8137C94
	movs r1, 0xA
	bl CreateTask
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_080CA5C0

	thumb_func_start sub_8137C94
sub_8137C94: @ 8137C94
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08137CAC
	adds r0, r2, 0
	bl DestroyTask
_08137CAC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137C94

	thumb_func_start sub_8137CB4
sub_8137CB4: @ 8137CB4
	push {lr}
	ldr r0, =sub_8177888
	bl SetMainCallback2
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137CB4

	thumb_func_start Special_ViewWallClock
Special_ViewWallClock: @ 8137CC8
	push {lr}
	ldr r0, =gMain
	ldr r1, =c2_exit_to_overworld_2_switch
	str r1, [r0, 0x8]
	ldr r0, =Cb2_ViewWallClock
	bl SetMainCallback2
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end Special_ViewWallClock

	thumb_func_start wild_pokemon_reroll
wild_pokemon_reroll: @ 8137CEC
	ldr r0, =gUnknown_0203AB54
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_0203AB55
	strb r1, [r0]
	ldr r1, =gUnknown_0203AB58
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end wild_pokemon_reroll

	thumb_func_start sub_8137D0C
sub_8137D0C: @ 8137D0C
	ldr r1, =gUnknown_0203AB54
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gUnknown_0203AB55
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_0203AB58
	ldr r0, =gMain
	ldr r0, [r0, 0x20]
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8137D0C

	thumb_func_start sp0E3_walkrun_bitfield_interpretation
sp0E3_walkrun_bitfield_interpretation: @ 8137D34
	push {lr}
	movs r0, 0x4
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _08137D46
	movs r0, 0x1
	b _08137D58
_08137D46:
	movs r0, 0x2
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	bne _08137D56
	movs r0, 0
	b _08137D58
_08137D56:
	movs r0, 0x2
_08137D58:
	pop {r1}
	bx r1
	thumb_func_end sp0E3_walkrun_bitfield_interpretation

	thumb_func_start sub_8137D5C
sub_8137D5C: @ 8137D5C
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r6, 0x63
	bhi _08137D88
	ldr r4, =gStringVar1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_085EB5EE
	adds r0, r4, 0
	bl StringAppend
	b _08137D90
	.pool
_08137D88:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EB5CF
	bl StringCopy
_08137D90:
	ldr r0, =0x00000e0f
	cmp r7, r0
	bhi _08137DF0
	ldr r4, =gStringVar2
	adds r0, r7, 0
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0xAD
	strb r0, [r4, 0x2]
	adds r5, r4, 0x3
	adds r0, r7, 0
	movs r1, 0x3C
	bl __umodsi3
	movs r1, 0x64
	muls r0, r1
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_085EB5E5
	adds r0, r4, 0
	bl StringAppend
	b _08137DF8
	.pool
_08137DF0:
	ldr r0, =gStringVar2
	ldr r1, =gUnknown_085EB5DA
	bl StringCopy
_08137DF8:
	movs r4, 0
	cmp r6, 0
	bne _08137E0C
	movs r4, 0x5
	b _08137E2A
	.pool
_08137E0C:
	cmp r6, 0x3
	bhi _08137E14
	movs r4, 0x4
	b _08137E2A
_08137E14:
	cmp r6, 0x9
	bhi _08137E1C
	movs r4, 0x3
	b _08137E2A
_08137E1C:
	cmp r6, 0x13
	bhi _08137E24
	movs r4, 0x2
	b _08137E2A
_08137E24:
	cmp r6, 0x63
	bhi _08137E2A
	movs r4, 0x1
_08137E2A:
	adds r0, r7, 0
	movs r1, 0x3C
	bl __udivsi3
	cmp r0, 0xA
	bhi _08137E3A
	adds r0, r4, 0x5
	b _08137E58
_08137E3A:
	cmp r0, 0xF
	bhi _08137E42
	adds r0, r4, 0x4
	b _08137E58
_08137E42:
	cmp r0, 0x14
	bhi _08137E4A
	adds r0, r4, 0x3
	b _08137E58
_08137E4A:
	cmp r0, 0x28
	bhi _08137E52
	adds r0, r4, 0x2
	b _08137E58
_08137E52:
	cmp r0, 0x3B
	bhi _08137E5C
	adds r0, r4, 0x1
_08137E58:
	lsls r0, 24
	lsrs r4, r0, 24
_08137E5C:
	ldr r0, =gScriptResult
	strh r4, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137D5C

	thumb_func_start sub_8137E6C
sub_8137E6C: @ 8137E6C
	push {r4,r5,lr}
	ldr r0, =gMain
	ldr r1, =gUnknown_0203AB58
	ldr r4, [r0, 0x20]
	ldr r0, [r1]
	subs r4, r0
	ldr r5, =gUnknown_0203AB55
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_8137D5C
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_8137E9C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137E6C

	thumb_func_start sub_8137E9C
sub_8137E9C: @ 8137E9C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r6, =0x00004028
	adds r0, r6, 0
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r7, =0x00004029
	adds r0, r7, 0
	bl VarGet
	lsls r0, 16
	adds r4, r0
	cmp r4, r5
	bhi _08137ECC
	cmp r4, 0
	bne _08137EE6
_08137ECC:
	lsls r1, r5, 16
	lsrs r1, 16
	adds r0, r6, 0
	bl VarSet
	lsrs r1, r5, 16
	adds r0, r7, 0
	bl VarSet
	ldr r0, =0x00004027
	mov r1, r8
	bl VarSet
_08137EE6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137E9C

	thumb_func_start sub_8137EFC
sub_8137EFC: @ 8137EFC
	push {r4,lr}
	ldr r0, =0x00004028
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004029
	bl VarGet
	lsls r0, 16
	adds r4, r0
	cmp r4, 0
	beq _08137F3C
	ldr r0, =0x00004027
	bl VarGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_8137D5C
	movs r0, 0x1
	b _08137F3E
	.pool
_08137F3C:
	movs r0, 0
_08137F3E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8137EFC

	thumb_func_start sub_8137F44
sub_8137F44: @ 8137F44
	push {r4,lr}
	ldr r0, =gUnknown_020322DC
	ldrh r1, [r0]
	ldr r0, =0x00000c1d
	cmp r1, r0
	beq _08137F7C
	ldr r4, =0x000040a9
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	beq _08137F6E
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bne _08137F7C
_08137F6E:
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	movs r0, 0
	bl sav1_set_battle_music_maybe
_08137F7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137F44

	thumb_func_start sub_8137F90
sub_8137F90: @ 8137F90
	push {lr}
	ldr r0, =0x0000088d
	bl FlagSet
	ldr r0, =0x0000404a
	bl GetVarPointer
	movs r1, 0
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137F90

	thumb_func_start sub_8137FB0
sub_8137FB0: @ 8137FB0
	push {lr}
	ldr r0, =0x0000088d
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8137FB0

	thumb_func_start sub_8137FC0
sub_8137FC0: @ 8137FC0
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000088d
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08137FE6
	ldr r0, =0x0000404a
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, r4, r1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xCC
	bhi _08137FF4
_08137FE6:
	movs r0, 0
	b _08137FF6
	.pool
_08137FF4:
	movs r0, 0x1
_08137FF6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8137FC0

	thumb_func_start sub_8137FFC
sub_8137FFC: @ 8137FFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, =0x0000404a
	bl GetVarPointer
	adds r4, r0, 0
	ldr r0, =0x000040b4
	bl GetVarPointer
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r0, 0x9
	bhi _081380C2
	lsls r0, 2
	ldr r1, =_08138038
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08138038:
	.4byte _08138060
	.4byte _08138070
	.4byte _08138064
	.4byte _08138068
	.4byte _08138068
	.4byte _0813806C
	.4byte _08138098
	.4byte _08138060
	.4byte _08138064
	.4byte _0813806C
_08138060:
	movs r0, 0x1
	b _081380CE
_08138064:
	movs r0, 0x4
	b _081380CE
_08138068:
	movs r0, 0x2
	b _081380CE
_0813806C:
	movs r0, 0x3
	b _081380CE
_08138070:
	ldrh r0, [r4]
	cmp r0, 0x3B
	bhi _08138080
	movs r0, 0x31
	strb r0, [r5]
	ldrh r0, [r4]
	adds r0, 0x13
	b _081380C0
_08138080:
	cmp r0, 0x8B
	bhi _0813808E
	movs r0, 0x30
	strb r0, [r5]
	ldrh r0, [r4]
	subs r0, 0x3C
	b _081380C0
_0813808E:
	movs r0, 0x2F
	strb r0, [r5]
	ldrh r0, [r4]
	subs r0, 0x8C
	b _081380C0
_08138098:
	ldrh r0, [r4]
	cmp r0, 0x41
	bhi _081380A8
	movs r0, 0x2F
	strb r0, [r5]
	ldrh r1, [r4]
	movs r0, 0x41
	b _081380BE
_081380A8:
	cmp r0, 0x91
	bhi _081380B6
	movs r0, 0x30
	strb r0, [r5]
	ldrh r1, [r4]
	movs r0, 0x91
	b _081380BE
_081380B6:
	movs r0, 0x31
	strb r0, [r5]
	ldrh r1, [r4]
	movs r0, 0xE0
_081380BE:
	subs r0, r1
_081380C0:
	strh r0, [r6]
_081380C2:
	movs r0, 0
	mov r1, r8
	strb r0, [r1]
	movs r0, 0x14
	strh r0, [r7]
	movs r0, 0
_081380CE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8137FFC

	thumb_func_start is_tile_that_overrides_player_control
is_tile_that_overrides_player_control: @ 81380D8
	push {lr}
	movs r0, 0x88
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813810A
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _0813810A
	cmp r0, 0x3
	ble _081380F6
	cmp r0, 0x6
	bne _0813810A
_081380F6:
	ldr r0, =0x000040f2
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xF9
	bhi _08138118
_0813810A:
	movs r0, 0
	b _0813811A
	.pool
_08138118:
	movs r0, 0x1
_0813811A:
	pop {r1}
	bx r1
	thumb_func_end is_tile_that_overrides_player_control

	thumb_func_start sub_8138120
sub_8138120: @ 8138120
	push {lr}
	movs r0, 0x8A
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08138152
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _08138152
	cmp r0, 0x3
	ble _0813813E
	cmp r0, 0x6
	bne _08138152
_0813813E:
	ldr r0, =0x000040f3
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x9
	bhi _08138160
_08138152:
	movs r0, 0
	b _08138162
	.pool
_08138160:
	movs r0, 0x1
_08138162:
	pop {r1}
	bx r1
	thumb_func_end sub_8138120

	thumb_func_start sub_8138168
sub_8138168: @ 8138168
	push {lr}
	movs r0, 0x72
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813819A
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _0813819A
	cmp r0, 0x3
	ble _08138186
	cmp r0, 0x6
	bne _0813819A
_08138186:
	ldr r0, =0x000040f5
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x9
	bhi _081381A8
_0813819A:
	movs r0, 0
	b _081381AA
	.pool
_081381A8:
	movs r0, 0x1
_081381AA:
	pop {r1}
	bx r1
	thumb_func_end sub_8138168

	thumb_func_start sub_81381B0
sub_81381B0: @ 81381B0
	push {lr}
	movs r0, 0x80
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081381E2
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _081381E2
	cmp r0, 0x3
	ble _081381CE
	cmp r0, 0x6
	bne _081381E2
_081381CE:
	ldr r0, =0x000040f4
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xF9
	bhi _081381F0
_081381E2:
	movs r0, 0
	b _081381F2
	.pool
_081381F0:
	movs r0, 0x1
_081381F2:
	pop {r1}
	bx r1
	thumb_func_end sub_81381B0

	thumb_func_start sub_81381F8
sub_81381F8: @ 81381F8
	push {lr}
	movs r0, 0x75
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0813822A
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x1
	blt _0813822A
	cmp r0, 0x3
	ble _08138216
	cmp r0, 0x6
	bne _0813822A
_08138216:
	ldr r0, =0x000040f6
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xF9
	bhi _08138238
_0813822A:
	movs r0, 0
	b _0813823A
	.pool
_08138238:
	movs r0, 0x1
_0813823A:
	pop {r1}
	bx r1
	thumb_func_end sub_81381F8

	thumb_func_start sub_8138240
sub_8138240: @ 8138240
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r7, r0, 24
	bl sub_8009FCC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _0813828A
	ldr r0, =gUnknown_0858D144
	mov r8, r0
_08138262:
	cmp r7, r4
	beq _08138280
	lsls r0, r6, 2
	add r0, r8
	ldr r0, [r0]
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	ldr r2, =gLinkPlayers + 8
	adds r1, r2
	bl StringCopy
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_08138280:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08138262
_0813828A:
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8138240

	thumb_func_start SpawnLinkPartnerFieldObject
SpawnLinkPartnerFieldObject: @ 81382A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r7, 0
	movs r0, 0
	mov r9, r0
	mov r8, r0
	ldr r1, =gUnknown_085B2B5C
	add r0, sp, 0x8
	movs r2, 0x4
	bl memcpy
	add r4, sp, 0xC
	ldr r1, =gUnknown_085B2B60
	adds r0, r4, 0
	movs r2, 0x8
	bl memcpy
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x2
	beq _08138310
	cmp r0, 0x2
	bgt _081382F4
	cmp r0, 0x1
	beq _0813833C
	b _08138350
	.pool
_081382F4:
	cmp r1, 0x3
	beq _081382FE
	cmp r1, 0x4
	beq _08138324
	b _08138350
_081382FE:
	movs r7, 0x2
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1]
	subs r0, 0x1
	b _0813832C
	.pool
_08138310:
	movs r7, 0x1
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0]
	mov r9, r1
	ldrh r0, [r0, 0x2]
	subs r0, 0x1
	b _0813834A
	.pool
_08138324:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
_0813832C:
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldrh r1, [r1, 0x2]
	mov r8, r1
	b _08138350
	.pool
_0813833C:
	movs r7, 0x3
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r3, [r0]
	mov r9, r3
	ldrh r0, [r0, 0x2]
	adds r0, 0x1
_0813834A:
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_08138350:
	movs r6, 0
	b _08138410
	.pool
_08138358:
	cmp r10, r6
	beq _0813840A
	ldr r0, =gLinkPlayers
	lsls r2, r6, 3
	subs r1, r2, r6
	lsls r1, 2
	adds r1, r0
	ldrb r3, [r1]
	adds r4, r0, 0
	cmp r3, 0x1
	blt _0813838C
	cmp r3, 0x2
	ble _0813837C
	cmp r3, 0x3
	beq _08138388
	b _0813838C
	.pool
_0813837C:
	ldrb r0, [r1, 0x13]
	movs r5, 0xEC
	cmp r0, 0
	bne _0813839C
	movs r5, 0xEB
	b _0813839C
_08138388:
	ldrb r0, [r1, 0x13]
	b _08138394
_0813838C:
	subs r0, r2, r6
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x13]
_08138394:
	movs r5, 0x69
	cmp r0, 0
	bne _0813839C
	movs r5, 0x64
_0813839C:
	mov r0, sp
	adds r0, r7
	adds r0, 0x8
	ldrb r1, [r0]
	movs r4, 0xF0
	subs r4, r6
	lsls r4, 24
	lsrs r4, 24
	lsls r2, r7, 1
	mov r0, sp
	adds r0, r2
	adds r0, 0xC
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r3, r9
	lsls r3, 16
	asrs r3, 16
	mov r12, r3
	add r0, r12
	adds r3, r0, 0x7
	lsls r3, 16
	asrs r3, 16
	mov r12, r3
	mov r0, sp
	adds r0, 0xD
	adds r0, r2
	movs r2, 0
	ldrsb r2, [r0, r2]
	mov r3, r8
	lsls r0, r3, 16
	asrs r0, 16
	adds r0, r2
	adds r0, 0x7
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r2, r4, 0
	mov r3, r12
	bl SpawnSpecialFieldObjectParametrized
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_813842C
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x4
	bne _0813840A
	movs r7, 0
_0813840A:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_08138410:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r6, r0
	bcc _08138358
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpawnLinkPartnerFieldObject

	thumb_func_start sub_813842C
sub_813842C: @ 813842C
	push {r4,r5,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 24
	movs r1, 0xC0
	lsls r1, 19
	adds r2, r1
	lsrs r5, r2, 24
	lsrs r4, r0, 24
	movs r2, 0xA8
	lsls r2, 21
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bls _08138454
	cmp r4, 0x64
	beq _08138454
	cmp r4, 0x69
	bne _081384E6
_08138454:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	adds r0, r3, 0
	bl GetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x10
	beq _081384E6
	ldr r1, =gMapObjects
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	lsls r3, r5, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	cmp r4, 0x69
	beq _081384D8
	cmp r4, 0x69
	bgt _081384A8
	cmp r4, 0x64
	beq _081384C4
	b _081384E6
	.pool
_081384A8:
	cmp r4, 0xEB
	beq _081384B2
	cmp r4, 0xEC
	beq _081384BC
	b _081384E6
_081384B2:
	ldr r0, =gFieldObjectPalette33
	b _081384C6
	.pool
_081384BC:
	ldr r0, =gFieldObjectPalette34
	b _081384C6
	.pool
_081384C4:
	ldr r0, =gFieldObjectPalette8
_081384C6:
	movs r2, 0x80
	lsls r2, 1
	adds r1, r3, r2
	movs r2, 0x20
	bl LoadPalette
	b _081384E6
	.pool
_081384D8:
	ldr r0, =gFieldObjectPalette17
	movs r2, 0x80
	lsls r2, 1
	adds r1, r3, r2
	movs r2, 0x20
	bl LoadPalette
_081384E6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813842C

	thumb_func_start sub_81384F0
sub_81384F0: @ 81384F0
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_085B2B68
_081384F6:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r4, r0
	bne _0813851C
	lsls r1, r4, 2
	adds r1, r5
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	ldr r2, =0x00000206
	bl MapGridSetMetatileIdAt
	b _0813852A
	.pool
_0813851C:
	lsls r1, r4, 2
	adds r1, r5
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	ldr r2, =0x00000205
	bl MapGridSetMetatileIdAt
_0813852A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081384F6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81384F0

	thumb_func_start sub_8138540
sub_8138540: @ 8138540
	push {r4-r6,lr}
	movs r5, 0xC
_08138544:
	movs r4, 0x7
	adds r6, r5, 0x1
_08138548:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffde6
	adds r0, r1
	cmp r0, 0x37
	bls _0813855A
	b _08138734
_0813855A:
	lsls r0, 2
	ldr r1, =_0813856C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813856C:
	.4byte _081386F2
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813864C
	.4byte _08138652
	.4byte _0813868C
	.4byte _08138694
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813865C
	.4byte _08138662
	.4byte _0813869C
	.4byte _081386A4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813866C
	.4byte _08138672
	.4byte _081386AC
	.4byte _081386B4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813867C
	.4byte _08138684
	.4byte _081386BC
	.4byte _081386C4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _081386CC
	.4byte _081386DC
	.4byte _081386EC
	.4byte _08138714
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _081386D4
	.4byte _081386E4
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _08138734
	.4byte _0813872A
	.4byte _0813871C
_0813864C:
	movs r2, 0x8C
	lsls r2, 2
	b _08138720
_08138652:
	ldr r2, =0x00000231
	b _08138720
	.pool
_0813865C:
	movs r2, 0x8E
	lsls r2, 2
	b _08138720
_08138662:
	ldr r2, =0x00000239
	b _08138720
	.pool
_0813866C:
	movs r2, 0x88
	lsls r2, 2
	b _08138720
_08138672:
	ldr r2, =0x00000221
	b _08138720
	.pool
_0813867C:
	ldr r2, =0x00000e28
	b _08138720
	.pool
_08138684:
	ldr r2, =0x00000e29
	b _08138720
	.pool
_0813868C:
	ldr r2, =0x00000232
	b _08138720
	.pool
_08138694:
	ldr r2, =0x00000233
	b _08138720
	.pool
_0813869C:
	ldr r2, =0x0000023a
	b _08138720
	.pool
_081386A4:
	ldr r2, =0x0000023b
	b _08138720
	.pool
_081386AC:
	ldr r2, =0x00000222
	b _08138720
	.pool
_081386B4:
	ldr r2, =0x00000223
	b _08138720
	.pool
_081386BC:
	ldr r2, =0x00000e2a
	b _08138720
	.pool
_081386C4:
	ldr r2, =0x00000e2b
	b _08138720
	.pool
_081386CC:
	ldr r2, =0x00000e42
	b _08138720
	.pool
_081386D4:
	ldr r2, =0x0000021a
	b _08138720
	.pool
_081386DC:
	ldr r2, =0x00000e43
	b _08138720
	.pool
_081386E4:
	ldr r2, =0x0000021a
	b _08138720
	.pool
_081386EC:
	movs r2, 0xE4
	lsls r2, 4
	b _08138720
_081386F2:
	subs r1, r5, 0x1
	adds r0, r4, 0
	bl MapGridGetMetatileIdAt
	movs r1, 0x90
	lsls r1, 2
	cmp r0, r1
	bne _0813870C
	ldr r2, =0x00000e48
	b _08138720
	.pool
_0813870C:
	ldr r2, =0x00000e49
	b _08138720
	.pool
_08138714:
	ldr r2, =0x00000e41
	b _08138720
	.pool
_0813871C:
	movs r2, 0xE5
	lsls r2, 4
_08138720:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _08138734
_0813872A:
	ldr r2, =0x00000251
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_08138734:
	adds r4, 0x1
	cmp r4, 0xF
	bgt _0813873C
	b _08138548
_0813873C:
	adds r5, r6, 0
	cmp r5, 0x17
	bgt _08138744
	b _08138544
_08138744:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138540

	thumb_func_start sub_8138750
sub_8138750: @ 8138750
	push {r4-r6,lr}
	ldr r4, =gUnknown_085B2B68
	movs r5, 0x3
_08138756:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	ldr r2, =0x00000206
	bl MapGridSetMetatileIdAt
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08138756
	movs r5, 0xC
_0813876A:
	movs r4, 0x7
	adds r6, r5, 0x1
_0813876E:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffde0
	adds r0, r1
	cmp r0, 0x30
	bls _08138780
	b _081388CA
_08138780:
	lsls r0, 2
	ldr r1, =_0813879C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813879C:
	.4byte _08138860
	.4byte _08138866
	.4byte _08138880
	.4byte _08138888
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _08138870
	.4byte _08138876
	.4byte _08138890
	.4byte _08138898
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388A0
	.4byte _081388A8
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388B0
	.4byte _081388B0
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388CA
	.4byte _081388C0
_08138860:
	movs r2, 0x8C
	lsls r2, 2
	b _081388B2
_08138866:
	ldr r2, =0x00000231
	b _081388B2
	.pool
_08138870:
	movs r2, 0x8E
	lsls r2, 2
	b _081388B2
_08138876:
	ldr r2, =0x00000239
	b _081388B2
	.pool
_08138880:
	ldr r2, =0x00000232
	b _081388B2
	.pool
_08138888:
	ldr r2, =0x00000233
	b _081388B2
	.pool
_08138890:
	ldr r2, =0x0000023a
	b _081388B2
	.pool
_08138898:
	ldr r2, =0x0000023b
	b _081388B2
	.pool
_081388A0:
	ldr r2, =0x00000e42
	b _081388B2
	.pool
_081388A8:
	ldr r2, =0x00000e43
	b _081388B2
	.pool
_081388B0:
	ldr r2, =0x0000021a
_081388B2:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _081388CA
	.pool
_081388C0:
	ldr r2, =0x00000251
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_081388CA:
	adds r4, 0x1
	cmp r4, 0xF
	bgt _081388D2
	b _0813876E
_081388D2:
	adds r5, r6, 0
	cmp r5, 0x17
	bgt _081388DA
	b _0813876A
_081388DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138750

	thumb_func_start sub_81388E4
sub_81388E4: @ 81388E4
	push {lr}
	ldr r0, =gUnknown_0203AB5C
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_0203AB5D
	strb r1, [r0]
	movs r0, 0x2C
	bl PlaySE
	ldr r0, =sub_8138910
	movs r1, 0x8
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81388E4

	thumb_func_start sub_8138910
sub_8138910: @ 8138910
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_085B2B78
	ldr r5, =gUnknown_0203AB5D
	ldrb r1, [r5]
	adds r0, r1, r0
	ldr r4, =gUnknown_0203AB5C
	ldrb r2, [r4]
	ldrb r0, [r0]
	cmp r0, r2
	bne _0813896C
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	ldr r2, =gUnknown_085B2B7E
	lsls r1, 1
	adds r1, r2
	ldrh r1, [r1]
	bl sub_8138978
	movs r0, 0
	strb r0, [r4]
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08138970
	adds r0, r6, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	b _08138970
	.pool
_0813896C:
	adds r0, r2, 0x1
	strb r0, [r4]
_08138970:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8138910

	thumb_func_start sub_8138978
sub_8138978: @ 8138978
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r2, r1, 16
	movs r7, 0
	subs r0, 0x1
	cmp r0, 0x7
	bhi _08138A40
	lsls r0, 2
	ldr r1, =_081389A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081389A0:
	.4byte _081389C0
	.4byte _081389D2
	.4byte _081389E4
	.4byte _081389F6
	.4byte _08138A04
	.4byte _08138A1A
	.4byte _08138A26
	.4byte _08138A34
_081389C0:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x68
	b _08138A14
_081389D2:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x4E
	b _08138A14
_081389E4:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x5B
	b _08138A14
_081389F6:
	movs r7, 0x1
	mov r1, sp
	movs r0, 0x7
	strh r0, [r1]
	add r1, sp, 0x8
	movs r0, 0x27
	b _08138A3E
_08138A04:
	movs r7, 0x2
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x7
	strh r0, [r1, 0x2]
	add r1, sp, 0x8
	movs r0, 0x34
_08138A14:
	strh r0, [r1]
	strh r0, [r1, 0x2]
	b _08138A40
_08138A1A:
	movs r7, 0x1
	mov r0, sp
	strh r7, [r0]
	add r1, sp, 0x8
	movs r0, 0x41
	b _08138A3E
_08138A26:
	movs r7, 0x1
	mov r1, sp
	movs r0, 0x7
	strh r0, [r1]
	add r1, sp, 0x8
	movs r0, 0xD
	b _08138A3E
_08138A34:
	movs r7, 0x1
	mov r0, sp
	strh r7, [r0]
	add r1, sp, 0x8
	movs r0, 0x1A
_08138A3E:
	strh r0, [r1]
_08138A40:
	movs r6, 0
	cmp r6, r7
	bcs _08138A92
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1, 0
	adds r1, r2, 0
	orrs r1, r0
	lsls r1, 16
	mov r9, r1
	adds r1, r2, 0
	adds r1, 0x8
	orrs r1, r0
	lsls r1, 16
	mov r8, r1
_08138A5E:
	lsls r1, r6, 1
	mov r3, sp
	adds r5, r3, r1
	ldrh r0, [r5]
	adds r0, 0x7
	add r4, sp, 0x8
	adds r4, r1
	ldrh r1, [r4]
	adds r1, 0x7
	mov r3, r9
	lsrs r2, r3, 16
	bl MapGridSetMetatileIdAt
	ldrh r0, [r5]
	adds r0, 0x7
	ldrh r1, [r4]
	adds r1, 0x8
	mov r3, r8
	lsrs r2, r3, 16
	bl MapGridSetMetatileIdAt
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _08138A5E
_08138A92:
	bl DrawWholeMapView
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8138978

	thumb_func_start sub_8138AA4
sub_8138AA4: @ 8138AA4
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	ldr r1, =gUnknown_085B2B7E
	ldrh r1, [r1, 0x8]
	bl sub_8138978
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138AA4

	thumb_func_start sub_8138AC0
sub_8138AC0: @ 8138AC0
	push {lr}
	ldr r0, =gStringVar4
	bl box_related_two__2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138AC0

	thumb_func_start sub_8138AD0
sub_8138AD0: @ 8138AD0
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8138AD0

	thumb_func_start sub_8138AF0
sub_8138AF0: @ 8138AF0
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0xB]
	lsls r1, 8
	ldrb r0, [r0, 0xA]
	orrs r0, r1
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8138AF0

	thumb_func_start sub_8138B10
sub_8138B10: @ 8138B10
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08138B34
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EB5F9
	bl StringCopy
	b _08138B3C
	.pool
_08138B34:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EB601
	bl StringCopy
_08138B3C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138B10

	thumb_func_start sub_8138B48
sub_8138B48: @ 8138B48
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08138B6C
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EB60E
	bl StringCopy
	b _08138B74
	.pool
_08138B6C:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EB60A
	bl StringCopy
_08138B74:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138B48

	thumb_func_start sub_8138B80
sub_8138B80: @ 8138B80
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8138B80

	thumb_func_start sub_8138B8C
sub_8138B8C: @ 8138B8C
	push {lr}
	sub sp, 0x4
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	beq _08138BB0
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r3, 0x6
	bl warp1_set
	b _08138BC2
	.pool
_08138BB0:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0x1
	movs r3, 0x6
	bl warp1_set
_08138BC2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8138B8C

	thumb_func_start sub_8138BC8
sub_8138BC8: @ 8138BC8
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138BC8

	thumb_func_start sub_8138BDC
sub_8138BDC: @ 8138BDC
	push {lr}
	ldr r0, =gLocalTime
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x7
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _08138BF6
	adds r0, r1, 0
_08138BF6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8138BDC

	thumb_func_start sub_8138C04
sub_8138C04: @ 8138C04
	push {r4,lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0xFF
	bne _08138C2C
	movs r0, 0x6
	b _08138C7E
	.pool
_08138C2C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0xC7
	bls _08138C3C
	movs r0, 0x5
	b _08138C7E
_08138C3C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0x95
	bls _08138C4C
	movs r0, 0x4
	b _08138C7E
_08138C4C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0x63
	bls _08138C5C
	movs r0, 0x3
	b _08138C7E
_08138C5C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0x31
	bls _08138C6C
	movs r0, 0x2
	b _08138C7E
_08138C6C:
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	cmp r0, 0
	bne _08138C7C
	movs r0, 0
	b _08138C7E
_08138C7C:
	movs r0, 0x1
_08138C7E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8138C04

	thumb_func_start sub_8138C84
sub_8138C84: @ 8138C84
	push {lr}
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl sub_817018C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138C84

	thumb_func_start sub_8138C94
sub_8138C94: @ 8138C94
	push {lr}
	ldr r0, =sub_8138C84
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138C94

	thumb_func_start sp0D9_ComputerRelated
sp0D9_ComputerRelated: @ 8138CA4
	push {r4,lr}
	ldr r4, =sub_8138CE8
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08138CD8
	adds r0, r4, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r2, [r1, 0xC]
	strh r2, [r1, 0xE]
	strh r2, [r1, 0x10]
_08138CD8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp0D9_ComputerRelated

	thumb_func_start sub_8138CE8
sub_8138CE8: @ 8138CE8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08138D06
	adds r0, r1, 0
	bl sub_8138D10
_08138D06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138CE8

	thumb_func_start sub_8138D10
sub_8138D10: @ 8138D10
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r6, 0
	movs r5, 0
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bne _08138D7C
	strh r5, [r4, 0xE]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x3
	beq _08138D44
	cmp r0, 0x3
	bgt _08138D3A
	cmp r0, 0x2
	beq _08138D40
	b _08138D4C
_08138D3A:
	cmp r1, 0x4
	beq _08138D48
	b _08138D4C
_08138D40:
	movs r6, 0
	b _08138D4A
_08138D44:
	movs r6, 0xFF
	b _08138D4A
_08138D48:
	movs r6, 0x1
_08138D4A:
	movs r5, 0xFF
_08138D4C:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsls r1, r6, 24
	asrs r1, 24
	lsls r2, r5, 24
	asrs r2, 24
	bl sub_8138D88
	bl DrawWholeMapView
	ldrh r0, [r4, 0x10]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _08138D7C
	ldrb r0, [r4, 0xA]
	bl DestroyTask
_08138D7C:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8138D10

	thumb_func_start sub_8138D88
sub_8138D88: @ 8138D88
	push {r4,r5,lr}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	movs r3, 0
	lsls r0, 16
	cmp r0, 0
	beq _08138DC4
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08138DAC
	movs r3, 0x4
	b _08138DE6
	.pool
_08138DAC:
	cmp r0, 0x1
	bne _08138DB8
	ldr r3, =0x0000025a
	b _08138DE6
	.pool
_08138DB8:
	cmp r0, 0x2
	bne _08138DE6
	ldr r3, =0x00000259
	b _08138DE6
	.pool
_08138DC4:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08138DD4
	movs r3, 0x5
	b _08138DE6
	.pool
_08138DD4:
	cmp r0, 0x1
	bne _08138DE0
	ldr r3, =0x0000027f
	b _08138DE6
	.pool
_08138DE0:
	cmp r0, 0x2
	bne _08138DE6
	ldr r3, =0x0000027e
_08138DE6:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r5, 0
	ldrsh r0, [r2, r5]
	lsls r1, 24
	asrs r1, 24
	adds r0, r1
	adds r0, 0x7
	movs r5, 0x2
	ldrsh r1, [r2, r5]
	lsls r2, r4, 24
	asrs r2, 24
	adds r1, r2
	adds r1, 0x7
	movs r4, 0xC0
	lsls r4, 4
	adds r2, r4, 0
	orrs r3, r2
	adds r2, r3, 0
	bl MapGridSetMetatileIdAt
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138D88

	thumb_func_start sub_8138E20
sub_8138E20: @ 8138E20
	push {lr}
	bl sub_8138E2C
	pop {r0}
	bx r0
	thumb_func_end sub_8138E20

	thumb_func_start sub_8138E2C
sub_8138E2C: @ 8138E2C
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	movs r4, 0
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x3
	beq _08138E56
	cmp r0, 0x3
	bgt _08138E4C
	cmp r0, 0x2
	beq _08138E52
	b _08138E5E
_08138E4C:
	cmp r1, 0x4
	beq _08138E5A
	b _08138E5E
_08138E52:
	movs r6, 0
	b _08138E5C
_08138E56:
	movs r6, 0xFF
	b _08138E5C
_08138E5A:
	movs r6, 0x1
_08138E5C:
	movs r5, 0xFF
_08138E5E:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08138E70
	movs r4, 0x4
	b _08138E82
	.pool
_08138E70:
	cmp r0, 0x1
	bne _08138E7C
	ldr r4, =0x0000025a
	b _08138E82
	.pool
_08138E7C:
	cmp r0, 0x2
	bne _08138E82
	ldr r4, =0x00000259
_08138E82:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r6, 24
	asrs r1, 24
	adds r0, r1
	adds r0, 0x7
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	lsls r2, r5, 24
	asrs r2, 24
	adds r1, r2
	adds r1, 0x7
	movs r3, 0xC0
	lsls r3, 4
	adds r2, r3, 0
	orrs r4, r2
	adds r2, r4, 0
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138E2C

	thumb_func_start sub_8138EC0
sub_8138EC0: @ 8138EC0
	push {r4,lr}
	ldr r4, =sub_8138F04
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08138EF4
	adds r0, r4, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r2, [r1, 0xC]
	strh r2, [r1, 0xE]
	strh r2, [r1, 0x10]
_08138EF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138EC0

	thumb_func_start sub_8138F04
sub_8138F04: @ 8138F04
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08138F22
	adds r0, r1, 0
	bl sub_8138F2C
_08138F22:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138F04

	thumb_func_start sub_8138F2C
sub_8138F2C: @ 8138F2C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bne _08138F9A
	movs r0, 0
	strh r0, [r4, 0xE]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08138F64
	ldr r2, =0x00000e9d
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000ea5
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	b _08138F7A
	.pool
_08138F64:
	ldr r2, =0x00000e58
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	movs r2, 0xE6
	lsls r2, 4
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
_08138F7A:
	bl DrawWholeMapView
	ldrh r0, [r4, 0x10]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _08138F9A
	ldrb r0, [r4, 0xA]
	bl DestroyTask
_08138F9A:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138F2C

	thumb_func_start sub_8138FAC
sub_8138FAC: @ 8138FAC
	push {lr}
	ldr r2, =0x00000e9d
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000ea5
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138FAC

	thumb_func_start sub_8138FD4
sub_8138FD4: @ 8138FD4
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x000001f5
	strh r0, [r1]
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138FD4

	thumb_func_start sub_8138FEC
sub_8138FEC: @ 8138FEC
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x000001f5
	strh r0, [r1]
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8138FEC

	thumb_func_start sub_8139004
sub_8139004: @ 8139004
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	bl GetMonData
	cmp r0, 0xC7
	bls _08139028
	movs r0, 0x1
	b _0813902A
	.pool
_08139028:
	movs r0, 0
_0813902A:
	pop {r1}
	bx r1
	thumb_func_end sub_8139004

	thumb_func_start sub_8139030
sub_8139030: @ 8139030
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	bl GetMonData
	cmp r0, 0xC7
	bls _08139054
	movs r0, 0x1
	b _08139056
	.pool
_08139054:
	movs r0, 0
_08139056:
	pop {r1}
	bx r1
	thumb_func_end sub_8139030

	thumb_func_start sub_813905C
sub_813905C: @ 813905C
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	bl GetMonData
	cmp r0, 0xC7
	bls _08139080
	movs r0, 0x1
	b _08139082
	.pool
_08139080:
	movs r0, 0
_08139082:
	pop {r1}
	bx r1
	thumb_func_end sub_813905C

	thumb_func_start sub_8139088
sub_8139088: @ 8139088
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	bl GetMonData
	cmp r0, 0xC7
	bls _081390AC
	movs r0, 0x1
	b _081390AE
	.pool
_081390AC:
	movs r0, 0
_081390AE:
	pop {r1}
	bx r1
	thumb_func_end sub_8139088

	thumb_func_start sub_81390B4
sub_81390B4: @ 81390B4
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	bl GetMonData
	cmp r0, 0xC7
	bls _081390D8
	movs r0, 0x1
	b _081390DA
	.pool
_081390D8:
	movs r0, 0
_081390DA:
	pop {r1}
	bx r1
	thumb_func_end sub_81390B4

	thumb_func_start sub_81390E0
sub_81390E0: @ 81390E0
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gBaseStats
_081390E6:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _0813913C
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0813913C
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x6]
	cmp r0, 0xC
	beq _08139128
	ldrb r0, [r1, 0x7]
	cmp r0, 0xC
	bne _0813913C
_08139128:
	ldr r1, =gScriptResult
	movs r0, 0x1
	b _0813914A
	.pool
_0813913C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _081390E6
	ldr r1, =gScriptResult
	movs r0, 0
_0813914A:
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81390E0

	thumb_func_start SpawnScriptFieldObject
SpawnScriptFieldObject: @ 8139158
	push {lr}
	sub sp, 0x8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r3, [r0]
	adds r3, 0x7
	lsls r3, 16
	asrs r3, 16
	ldrh r0, [r0, 0x2]
	adds r0, 0x7
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x7
	movs r1, 0x8
	movs r2, 0x7F
	bl SpawnSpecialFieldObjectParametrized
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gMapObjects
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x1]
	movs r2, 0x20
	orrs r0, r2
	strb r0, [r1, 0x1]
	ldrb r0, [r1, 0x4]
	bl CameraObjectSetFollowedObjectId
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end SpawnScriptFieldObject

	thumb_func_start RemoveScriptFieldObject
RemoveScriptFieldObject: @ 81391AC
	push {lr}
	bl GetPlayerAvatarObjectId
	lsls r0, 24
	lsrs r0, 24
	bl CameraObjectSetFollowedObjectId
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x7F
	bl RemoveFieldObjectByLocalIdAndMap
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveScriptFieldObject

	thumb_func_start sub_81391D0
sub_81391D0: @ 81391D0
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar1
	bl sub_8137068
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81391D0

	thumb_func_start sub_8139200
sub_8139200: @ 8139200
	push {r4,lr}
	ldr r4, =gStringVar1
	ldr r0, =0x00004026
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl GetMapName
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139200

	thumb_func_start sub_8139228
sub_8139228: @ 8139228
	push {lr}
	movs r0, 0x20
	bl GetGameStat
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8139228

	thumb_func_start sub_8139238
sub_8139238: @ 8139238
	push {lr}
	ldr r0, =gStringVar1
	bl sub_8165284
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139238

	thumb_func_start sub_8139248
sub_8139248: @ 8139248
	push {r4,r5,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x00002e68
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 25
	ldr r0, =0x00002e6a
	adds r2, r0
	lsrs r1, 25
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =gUnknown_085B2B88
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	adds r5, r1, r0
	movs r0, 0x2
	bl GetPriceReduction
	lsls r0, 24
	cmp r0, 0
	bne _08139294
	ldr r4, =gUnknown_085B2B94
	b _08139296
	.pool
_08139294:
	ldr r4, =gUnknown_085B2BA0
_08139296:
	adds r0, r5, 0
	movs r1, 0xC
	bl __umodsi3
	adds r0, r4
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8139248

	thumb_func_start sub_81392AC
sub_81392AC: @ 81392AC
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x00000213
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081392CC
	movs r0, 0x1
	b _081392CE
	.pool
_081392CC:
	movs r0, 0
_081392CE:
	pop {r1}
	bx r1
	thumb_func_end sub_81392AC

	thumb_func_start sub_81392D4
sub_81392D4: @ 81392D4
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x85
	lsls r0, 2
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081392F0
	movs r0, 0x1
	b _081392F2
	.pool
_081392F0:
	movs r0, 0
_081392F2:
	pop {r1}
	bx r1
	thumb_func_end sub_81392D4

	thumb_func_start sub_81392F8
sub_81392F8: @ 81392F8
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x00000215
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139318
	movs r0, 0x1
	b _0813931A
	.pool
_08139318:
	movs r0, 0
_0813931A:
	pop {r1}
	bx r1
	thumb_func_end sub_81392F8

	thumb_func_start sub_8139320
sub_8139320: @ 8139320
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r0, =0x00000216
	strh r0, [r1]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139340
	movs r0, 0x1
	b _08139342
	.pool
_08139340:
	movs r0, 0
_08139342:
	pop {r1}
	bx r1
	thumb_func_end sub_8139320

	thumb_func_start sub_8139348
sub_8139348: @ 8139348
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x47
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8139348

	thumb_func_start sub_8139370
sub_8139370: @ 8139370
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x2A
	bl IncrementGameStat
	ldr r0, =0x0000089b
	bl FlagSet
	movs r1, 0x1
	mov r0, sp
	strb r1, [r0]
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x47
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	bl sub_80EE5A4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _081393B6
	adds r0, r4, 0
	movs r1, 0x47
	bl sub_80EE4DC
_081393B6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139370

	thumb_func_start sub_81393C8
sub_81393C8: @ 81393C8
	push {lr}
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetMonEVCount
	lsls r0, 16
	ldr r1, =0x01fd0000
	cmp r0, r1
	bhi _081393F4
	movs r0, 0
	b _081393F6
	.pool
_081393F4:
	movs r0, 0x1
_081393F6:
	pop {r1}
	bx r1
	thumb_func_end sub_81393C8

	thumb_func_start sub_81393FC
sub_81393FC: @ 81393FC
	push {lr}
	movs r0, 0xC7
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08139454
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0x83
	lsls r0, 3
	cmp r1, r0
	bne _08139454
	subs r0, 0x75
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139434
	ldr r0, =0x0000409a
	movs r1, 0x4
	b _08139446
	.pool
_08139434:
	movs r0, 0xE9
	lsls r0, 2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08139454
	ldr r0, =0x0000409a
	movs r1, 0x5
_08139446:
	bl VarSet
	movs r0, 0x1
	b _08139456
	.pool
_08139454:
	movs r0, 0
_08139456:
	pop {r1}
	bx r1
	thumb_func_end sub_81393FC

	thumb_func_start sub_813945C
sub_813945C: @ 813945C
	push {lr}
	ldr r0, =0x000008bf
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813945C

	thumb_func_start sub_813946C
sub_813946C: @ 813946C
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r5, =gPlayerParty
	movs r1, 0x90
	lsls r1, 1
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r5, 0
	movs r2, 0x7
	movs r3, 0x20
	bl CreateMon
	movs r1, 0x1
	add r0, sp, 0x10
	strh r1, [r0]
	adds r0, r5, 0
	movs r1, 0x2E
	add r2, sp, 0x10
	bl SetMonData
	add r1, sp, 0x10
	movs r0, 0x21
	strh r0, [r1]
	adds r0, r5, 0
	movs r1, 0xD
	add r2, sp, 0x10
	bl SetMonData
	add r0, sp, 0x10
	strh r4, [r0]
	adds r0, r5, 0
	movs r1, 0xE
	add r2, sp, 0x10
	bl SetMonData
	adds r0, r5, 0
	movs r1, 0xF
	add r2, sp, 0x10
	bl SetMonData
	adds r0, r5, 0
	movs r1, 0x10
	add r2, sp, 0x10
	bl SetMonData
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813946C

	thumb_func_start sub_81394D8
sub_81394D8: @ 81394D8
	push {r4-r6,lr}
	ldr r0, =0x00004023
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl sub_8133EDC
	lsls r0, 16
	lsrs r6, r0, 16
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _08139526
_081394FA:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	cmp r0, r6
	bne _0813951C
	movs r0, 0x1
	b _08139528
	.pool
_0813951C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _081394FA
_08139526:
	movs r0, 0
_08139528:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81394D8

	thumb_func_start sub_8139530
sub_8139530: @ 8139530
	push {lr}
	bl sub_80D2218
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8139530

	thumb_func_start sub_8139540
sub_8139540: @ 8139540
	push {lr}
	ldr r0, =gPlayerParty
	movs r1, 0x3F
	bl CheckPartyPokerus
	lsls r0, 24
	cmp r0, 0
	beq _08139558
	movs r0, 0x1
	b _0813955A
	.pool
_08139558:
	movs r0, 0
_0813955A:
	pop {r1}
	bx r1
	thumb_func_end sub_8139540

	thumb_func_start sub_8139560
sub_8139560: @ 8139560
	push {lr}
	ldr r0, =sub_81395BC
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	movs r2, 0
	strh r0, [r1, 0x8]
	strh r2, [r1, 0xA]
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	strh r0, [r1, 0xC]
	ldr r0, =gSpecialVar_0x8007
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	strh r0, [r1, 0x10]
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0xD6
	bl PlaySE
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139560

	thumb_func_start sub_81395BC
sub_81395BC: @ 81395BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _08139614
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	ldrh r0, [r4]
	negs r0, r0
	strh r0, [r4]
	ldrh r0, [r4, 0x8]
	negs r0, r0
	strh r0, [r4, 0x8]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	bl SetCameraPanning
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08139614
	adds r0, r5, 0
	bl sub_8139620
	bl InstallCameraPanAheadCallback
_08139614:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81395BC

	thumb_func_start sub_8139620
sub_8139620: @ 8139620
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_8139620

	thumb_func_start sub_8139634
sub_8139634: @ 8139634
	push {lr}
	movs r0, 0x95
	lsls r0, 2
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8139634

	thumb_func_start sub_8139648
sub_8139648: @ 8139648
	push {lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r0, 24
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08139664
	movs r0, 0x14
	bl sub_80AED7C
_08139664:
	pop {r0}
	bx r0
	thumb_func_end sub_8139648

	thumb_func_start sub_8139668
sub_8139668: @ 8139668
	push {lr}
	bl get_map_light_from_warp0
	lsls r0, 24
	lsrs r0, 24
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08139684
	movs r0, 0x15
	bl sub_80AED7C
_08139684:
	pop {r0}
	bx r0
	thumb_func_end sub_8139668

	thumb_func_start sub_8139688
sub_8139688: @ 8139688
	push {r4-r6,lr}
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	cmp r5, r6
	bcs _081396D6
_08139698:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _081396CC
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _081396CC
	adds r0, r5, 0
	b _081396D8
	.pool
_081396CC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r6
	bcc _08139698
_081396D6:
	movs r0, 0
_081396D8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8139688

	thumb_func_start sub_81396E0
sub_81396E0: @ 81396E0
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81396E0

	thumb_func_start nullsub_54
nullsub_54: @ 8139708
	bx lr
	thumb_func_end nullsub_54

	thumb_func_start sub_813970C
sub_813970C: @ 813970C
	push {r4,lr}
	ldr r0, =0x000040c2
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r3, r0, 0
	ldr r2, =gLocalTime
	movs r1, 0
	ldrsh r0, [r2, r1]
	subs r0, r3
	cmp r0, 0x6
	ble _08139734
	movs r0, 0
	b _0813974C
	.pool
_08139734:
	ldrh r1, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	blt _0813974A
	subs r1, r3
	movs r0, 0x7
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	b _0813974C
_0813974A:
	movs r0, 0x8
_0813974C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813970C

	thumb_func_start sub_8139754
sub_8139754: @ 8139754
	push {r4,lr}
	ldr r0, =0x000040c2
	ldr r4, =gLocalTime
	ldrh r1, [r4]
	bl VarSet
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8139754

	thumb_func_start sub_8139770
sub_8139770: @ 8139770
	push {r4-r6,lr}
	ldr r6, =gSpecialVar_0x8004
	ldrh r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3
	bl GetMonData
	cmp r0, 0x2
	bne _081397A6
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	ldr r4, =gStringVar1
	movs r1, 0x7
	adds r2, r4, 0
	bl GetMonData
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r1, r4, 0
	bl StringCompare
	cmp r0, 0
	beq _081397BC
_081397A6:
	movs r0, 0x1
	b _081397BE
	.pool
_081397BC:
	movs r0, 0
_081397BE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8139770

	thumb_func_start sub_81397C4
sub_81397C4: @ 81397C4
	push {r4,r5,lr}
	ldr r2, =gScriptResult
	ldrh r1, [r2]
	ldr r0, =0x0000270f
	cmp r1, r0
	bls _081397E0
	movs r0, 0
	bl sub_80EF340
	b _08139862
	.pool
_081397E0:
	ldr r0, =0x000003e7
	cmp r1, r0
	bls _081397F8
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	adds r4, 0x1
	b _0813981C
	.pool
_081397F8:
	cmp r1, 0x63
	bls _0813980C
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	adds r4, 0x2
	b _0813981C
	.pool
_0813980C:
	cmp r1, 0x9
	bls _0813983C
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	adds r4, 0x3
_0813981C:
	ldrh r5, [r2]
	adds r0, r5, 0
	bl sub_80EF370
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
	b _08139862
	.pool
_0813983C:
	ldr r4, =gStringVar1
	movs r0, 0xA1
	strb r0, [r4]
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	adds r4, 0x4
	ldrh r5, [r2]
	adds r0, r5, 0
	bl sub_80EF370
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
_08139862:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81397C4

	thumb_func_start sub_813986C
sub_813986C: @ 813986C
	push {lr}
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _081398B8
	lsls r0, 2
	ldr r1, =_08139888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08139888:
	.4byte _0813989C
	.4byte _081398A0
	.4byte _081398A4
	.4byte _081398A8
	.4byte _081398AC
_0813989C:
	movs r0, 0x3
	b _081398AE
_081398A0:
	movs r0, 0x4
	b _081398AE
_081398A4:
	movs r0, 0
	b _081398AE
_081398A8:
	movs r0, 0x1
	b _081398AE
_081398AC:
	movs r0, 0x2
_081398AE:
	bl mevent_081445C0
	lsls r0, 16
	lsrs r0, 16
	b _081398BA
_081398B8:
	movs r0, 0
_081398BA:
	pop {r1}
	bx r1
	thumb_func_end sub_813986C

	thumb_func_start sub_81398C0
sub_81398C0: @ 81398C0
	push {r4,lr}
	ldr r1, =gSpecialVar_0x8004
	ldr r2, =0xfffffedf
	adds r0, r2, 0
	ldrh r2, [r1]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x39
	bls _081398E0
	movs r0, 0
	b _081398FC
	.pool
_081398E0:
	ldr r4, =gStringVar2
	ldrh r0, [r1]
	bl ItemIdToBattleMoveId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0x1
_081398FC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81398C0

	thumb_func_start sub_813990C
sub_813990C: @ 813990C
	push {r4,r5,lr}
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _08139942
_0813991C:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x4
	bl GetMonData
	cmp r0, 0x1
	bne _08139938
	movs r0, 0x1
	b _08139944
	.pool
_08139938:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0813991C
_08139942:
	movs r0, 0
_08139944:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_813990C

	thumb_func_start InMultiBattleRoom
InMultiBattleRoom: @ 813994C
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00000f1a
	cmp r1, r0
	bne _08139978
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _08139978
	movs r0, 0x1
	b _0813997A
	.pool
_08139978:
	movs r0, 0
_0813997A:
	pop {r1}
	bx r1
	thumb_func_end InMultiBattleRoom

	thumb_func_start sub_8139980
sub_8139980: @ 8139980
	push {lr}
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0x8
	movs r1, 0
	bl SetCameraPanning
	pop {r0}
	bx r0
	thumb_func_end sub_8139980

	thumb_func_start sub_8139994
sub_8139994: @ 8139994
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	subs r0, 0x10
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x5
	bhi _081399E4
	lsls r0, 2
	ldr r1, =_081399B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081399B8:
	.4byte _081399E4
	.4byte _081399D0
	.4byte _081399D4
	.4byte _081399D8
	.4byte _081399DC
	.4byte _081399E0
_081399D0:
	movs r1, 0x5
	b _081399E6
_081399D4:
	movs r1, 0x6
	b _081399E6
_081399D8:
	movs r1, 0x7
	b _081399E6
_081399DC:
	movs r1, 0x8
	b _081399E6
_081399E0:
	movs r1, 0xF
	b _081399E6
_081399E4:
	movs r1, 0x4
_081399E6:
	ldr r0, =0x00004043
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139994

	thumb_func_start sub_81399F4
sub_81399F4: @ 81399F4
	push {r4,lr}
	ldr r2, =gUnknown_0203AB60
	movs r0, 0
	strh r0, [r2]
	ldr r1, =gUnknown_0203AB62
	strh r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r0, 0x14
	ldrsb r0, [r3, r0]
	adds r4, r1, 0
	cmp r0, 0xD
	bne _08139A6E
	ldrb r0, [r3, 0x15]
	subs r0, 0x10
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bhi _08139A6E
	lsls r0, 2
	ldr r1, =_08139A34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08139A34:
	.4byte _08139A66
	.4byte _08139A5E
	.4byte _08139A56
	.4byte _08139A4E
	.4byte _08139A48
_08139A48:
	movs r0, 0
	strh r0, [r2]
	b _08139A6C
_08139A4E:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
	b _08139A6C
_08139A56:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x2
	b _08139A6C
_08139A5E:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x3
	b _08139A6C
_08139A66:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x4
_08139A6C:
	strh r0, [r4]
_08139A6E:
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81399F4

	thumb_func_start sub_8139A78
sub_8139A78: @ 8139A78
	push {r4-r6,lr}
	ldr r0, =sub_8139AF4
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r3, 0
	strh r3, [r4, 0x2]
	strh r3, [r4, 0x4]
	movs r6, 0x1
	strh r6, [r4, 0x8]
	ldr r0, =gSpecialVar_0x8005
	ldr r1, =gSpecialVar_0x8006
	ldrh r2, [r0]
	ldrh r0, [r1]
	cmp r2, r0
	bls _08139AC0
	subs r0, r2, r0
	lsls r0, 16
	lsrs r5, r0, 16
	strh r6, [r4, 0xC]
	b _08139AC8
	.pool
_08139AC0:
	subs r0, r2
	lsls r0, 16
	lsrs r5, r0, 16
	strh r3, [r4, 0xC]
_08139AC8:
	cmp r5, 0x8
	bls _08139ACE
	movs r5, 0x8
_08139ACE:
	ldr r0, =gUnknown_085B2C18
	adds r0, r5, r0
	ldrb r0, [r0]
	strh r0, [r4, 0xA]
	movs r0, 0
	bl SetCameraPanningCallback
	ldrb r1, [r4, 0xC]
	adds r0, r5, 0
	bl sub_8139C2C
	movs r0, 0x59
	bl PlaySE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139A78

	thumb_func_start sub_8139AF4
sub_8139AF4: @ 8139AF4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _08139B54
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	ldrh r0, [r4, 0x8]
	negs r0, r0
	strh r0, [r4, 0x8]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	movs r0, 0
	bl SetCameraPanning
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08139B54
	movs r0, 0x49
	bl PlaySE
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	bl InstallCameraPanAheadCallback
_08139B54:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139AF4

	thumb_func_start sub_8139B60
sub_8139B60: @ 8139B60
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	ldr r5, =gUnknown_0203AB5E
	ldr r0, =gUnknown_085B2BAC
	bl AddWindow
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r4, =gUnknown_085EB6A5
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldrb r0, [r5]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	mov r9, r1
	str r1, [sp, 0x4]
	movs r1, 0
	mov r8, r1
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	ldr r6, =gUnknown_085B2BB4
	ldr r4, =gSpecialVar_0x8005
	ldrh r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	movs r0, 0x1
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldrb r0, [r5]
	ldrh r1, [r4]
	lsls r1, 2
	adds r1, r6
	ldr r2, [r1]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x11
	str r1, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	movs r1, 0x1
	bl PrintTextOnWindow
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139B60

	thumb_func_start sub_8139C10
sub_8139C10: @ 8139C10
	push {r4,lr}
	ldr r4, =gUnknown_0203AB5E
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139C10

	thumb_func_start sub_8139C2C
sub_8139C2C: @ 8139C2C
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, =sub_8139C80
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08139C6C
	adds r0, r4, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r5, [r1, 0xC]
	ldr r0, =gUnknown_085B2C21
	adds r0, r6, r0
	ldrb r0, [r0]
	strh r0, [r1, 0xE]
_08139C6C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139C2C

	thumb_func_start sub_8139C80
sub_8139C80: @ 8139C80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r0, 0x6
	bne _08139D7C
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08139D10
	movs r1, 0
	ldr r2, =gUnknown_085B2BF4
	mov r10, r2
_08139CBA:
	movs r5, 0
	adds r7, r1, 0x7
	lsls r0, r1, 1
	adds r2, r1, 0x1
	mov r8, r2
	adds r0, r1
	lsls r0, 1
	mov r9, r0
_08139CCA:
	adds r4, r5, 0
	adds r4, 0x8
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 15
	add r0, r9
	add r0, r10
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 4
	adds r2, r1, 0
	orrs r2, r0
	adds r0, r4, 0
	adds r1, r7, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _08139CCA
	mov r2, r8
	lsls r0, r2, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bls _08139CBA
	b _08139D62
	.pool
_08139D10:
	movs r1, 0
	ldr r0, =gUnknown_085B2C06
	mov r10, r0
_08139D16:
	movs r5, 0
	adds r7, r1, 0x7
	lsls r0, r1, 1
	adds r2, r1, 0x1
	mov r8, r2
	adds r0, r1
	lsls r0, 1
	mov r9, r0
_08139D26:
	adds r4, r5, 0
	adds r4, 0x8
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 15
	add r0, r9
	add r0, r10
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 4
	adds r2, r1, 0
	orrs r2, r0
	adds r0, r4, 0
	adds r1, r7, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _08139D26
	mov r2, r8
	lsls r0, r2, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bls _08139D16
_08139D62:
	bl DrawWholeMapView
	movs r0, 0
	strh r0, [r6, 0x2]
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r2, 0x6
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _08139D7C
	ldr r0, [sp]
	bl DestroyTask
_08139D7C:
	ldrh r0, [r6, 0x2]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139C80

	thumb_func_start sub_8139D98
sub_8139D98: @ 8139D98
	push {r4-r7,lr}
	sub sp, 0x18
	ldr r6, =gSpecialVar_0x8004
	ldrh r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x27
	bl GetMonData
	str r0, [sp]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x28
	bl GetMonData
	str r0, [sp, 0x4]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x29
	bl GetMonData
	str r0, [sp, 0x8]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x2A
	bl GetMonData
	str r0, [sp, 0xC]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x2B
	bl GetMonData
	str r0, [sp, 0x10]
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x2C
	bl GetMonData
	str r0, [sp, 0x14]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0
	strh r0, [r1]
	movs r4, 0
	adds r2, r1, 0
_08139E00:
	lsls r0, r4, 2
	add r0, sp
	ldr r1, [r0]
	ldrh r0, [r2]
	adds r0, r1
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _08139E00
	ldr r2, =gSpecialVar_0x8006
	movs r0, 0
	strh r0, [r2]
	ldr r1, =gSpecialVar_0x8007
	ldr r0, [sp]
	strh r0, [r1]
	movs r4, 0x1
	adds r6, r2, 0
	adds r7, r1, 0
_08139E28:
	ldrh r0, [r6]
	lsls r0, 2
	mov r2, sp
	adds r1, r2, r0
	lsls r0, r4, 2
	adds r5, r2, r0
	ldr r1, [r1]
	ldr r0, [r5]
	cmp r1, r0
	bcs _08139E54
	strh r4, [r6]
	b _08139E6C
	.pool
_08139E54:
	cmp r1, r0
	bne _08139E6E
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08139E6E
	strh r4, [r6]
	ldr r0, [r5]
_08139E6C:
	strh r0, [r7]
_08139E6E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _08139E28
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8139D98

	thumb_func_start warp0_in_pokecenter
warp0_in_pokecenter: @ 8139E80
	push {r4,lr}
	ldr r0, =gUnknown_020322DC
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gUnknown_085B2C2A
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _08139EC6
	adds r4, r1, 0
	adds r1, r2, 0
_08139EA4:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08139EBC
	movs r0, 0x1
	b _08139EC8
	.pool
_08139EBC:
	adds r1, 0x2
	adds r2, 0x2
	ldrh r0, [r1]
	cmp r0, r4
	bne _08139EA4
_08139EC6:
	movs r0, 0
_08139EC8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end warp0_in_pokecenter

	thumb_func_start sub_8139ED0
sub_8139ED0: @ 8139ED0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00003c1a
	cmp r1, r0
	beq _08139EEC
	movs r0, 0x1
	b _08139EEE
	.pool
_08139EEC:
	movs r0, 0
_08139EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8139ED0

	thumb_func_start sub_8139EF4
sub_8139EF4: @ 8139EF4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x0000402f
	bl GetVarPointer
	adds r5, r0, 0
	ldrh r0, [r5]
	adds r4, r0
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0xA
	bl __umodsi3
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139EF4

	thumb_func_start sub_8139F20
sub_8139F20: @ 8139F20
	push {r4-r7,lr}
	movs r4, 0
	ldr r0, =0x0000402f
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x9
	bls _08139F34
	b _0813A03A
_08139F34:
	lsls r0, r6, 2
	ldr r1, =_08139F48
	adds r1, r0, r1
	ldr r1, [r1]
	adds r2, r0, 0
	mov pc, r1
	.pool
	.align 2, 0
_08139F48:
	.4byte _08139F70
	.4byte _08139F70
	.4byte _08139F70
	.4byte _08139F70
	.4byte _08139F94
	.4byte _08139FB4
	.4byte _08139FCC
	.4byte _08139FE4
	.4byte _08139FFC
	.4byte _0813A014
_08139F70:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r3, 0xCE
	lsls r3, 4
	adds r1, r0, r3
	adds r3, r1, r2
	ldr r1, =0x00000ce2
	adds r0, r1
	adds r1, r0, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bcs _0813A028
	b _0813A038
	.pool
_08139F94:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d0c
	adds r2, r0, r3
	adds r3, 0x2
_08139F9E:
	adds r1, r0, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcs _0813A028
	b _0813A038
	.pool
_08139FB4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000de2
	adds r2, r0, r1
	ldr r3, =0x00000de4
	b _08139F9E
	.pool
_08139FCC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dc8
	adds r2, r0, r1
	ldr r3, =0x00000dca
	b _08139F9E
	.pool
_08139FE4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dda
	adds r2, r0, r1
	ldr r3, =0x00000ddc
	b _08139F9E
	.pool
_08139FFC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e04
	adds r2, r0, r1
	ldr r3, =0x00000e06
	b _08139F9E
	.pool
_0813A014:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e1a
	adds r2, r0, r1
	ldr r3, =0x00000e1c
	adds r1, r0, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcc _0813A038
_0813A028:
	adds r4, r0, 0
	b _0813A03A
	.pool
_0813A038:
	ldrh r4, [r1]
_0813A03A:
	movs r2, 0
	ldr r5, =gUnknown_085B2CC8
	lsls r0, r6, 1
	adds r1, r0, r5
	ldrb r1, [r1]
	adds r3, r0, 0
	ldr r7, =gUnknown_085B2C50
	cmp r1, r4
	bcs _0813A062
	adds r1, r3, 0
_0813A04E:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bhi _0813A062
	adds r0, r2, r1
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, r4
	bcc _0813A04E
_0813A062:
	adds r0, r3, r6
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldr r0, [r0]
	bl box_related_two__2
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8139F20

	thumb_func_start sub_813A080
sub_813A080: @ 813A080
	push {r4-r7,lr}
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r4, r0, 30
	cmp r5, 0x2
	bne _0813A0D8
	movs r0, 0xA9
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _0813A0D8
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =gSpecialVar_0x8006
	movs r0, 0x4
	strh r0, [r1]
	b _0813A110
	.pool
_0813A0D0:
	movs r0, 0x4
	strh r0, [r6]
	adds r0, r3, 0x5
	b _0813A10E
_0813A0D8:
	movs r3, 0
	ldr r6, =gSpecialVar_0x8005
	ldr r7, =gSpecialVar_0x8006
	lsls r1, r4, 1
	lsls r2, r5, 2
	ldr r4, =gUnknown_085B2CDC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r1, r2
	movs r2, 0xCE
	lsls r2, 4
	adds r0, r2
	adds r0, r1
	ldrh r1, [r0]
_0813A0F4:
	lsls r0, r3, 1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r1
	bhi _0813A0D0
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x8
	bls _0813A0F4
	movs r0, 0x4
	strh r0, [r6]
	movs r0, 0xC
_0813A10E:
	strh r0, [r7]
_0813A110:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A080

	thumb_func_start sub_813A128
sub_813A128: @ 813A128
	push {r4,lr}
	ldr r0, =sub_813A2DC
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	ldr r1, =gSpecialVar_0x8004
	ldrh r0, [r1]
	strh r0, [r3, 0x1E]
	ldrh r0, [r1]
	cmp r0, 0xC
	bls _0813A14E
	b _0813A2C6
_0813A14E:
	lsls r0, 2
	ldr r1, =_0813A168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813A168:
	.4byte _0813A19C
	.4byte _0813A1AA
	.4byte _0813A1C2
	.4byte _0813A1D6
	.4byte _0813A1F0
	.4byte _0813A208
	.4byte _0813A222
	.4byte _0813A23C
	.4byte _0813A25A
	.4byte _0813A274
	.4byte _0813A274
	.4byte _0813A28E
	.4byte _0813A2A8
_0813A19C:
	movs r1, 0
	movs r0, 0x1
	strh r0, [r3, 0x8]
	strh r0, [r3, 0xA]
	strh r0, [r3, 0xC]
	strh r0, [r3, 0xE]
	b _0813A2BC
_0813A1AA:
	movs r1, 0
	movs r0, 0x5
	strh r0, [r3, 0x8]
	movs r0, 0x8
	strh r0, [r3, 0xA]
	movs r0, 0x1
	strh r0, [r3, 0xC]
	strh r0, [r3, 0xE]
	movs r0, 0x9
	strh r0, [r3, 0x10]
	movs r0, 0xA
	b _0813A2BE
_0813A1C2:
	movs r2, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r1, 0xC
	strh r1, [r3, 0xA]
	movs r0, 0x1
	strh r0, [r3, 0xC]
	strh r0, [r3, 0xE]
	movs r0, 0x7
	b _0813A250
_0813A1D6:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xB
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A1F0:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A208:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0x7
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A222:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xA
	strh r0, [r3, 0xA]
	movs r0, 0xE
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xF
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A23C:
	movs r2, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r1, 0xC
	strh r1, [r3, 0xA]
	movs r0, 0xF
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xE
_0813A250:
	strh r0, [r3, 0x10]
	strh r1, [r3, 0x12]
	strh r2, [r3, 0x14]
	strh r4, [r3, 0x26]
	b _0813A2D2
_0813A25A:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xA
	strh r0, [r3, 0xA]
	movs r0, 0x11
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xB
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A274:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0xB
	strh r0, [r3, 0xA]
	movs r0, 0xF
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xE
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A28E:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0x7
	strh r0, [r3, 0xA]
	movs r0, 0x13
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xA
	strh r0, [r3, 0x10]
	movs r0, 0xC
	b _0813A2BE
_0813A2A8:
	movs r1, 0
	movs r0, 0x6
	strh r0, [r3, 0x8]
	movs r0, 0x7
	strh r0, [r3, 0xA]
	movs r0, 0x11
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0xE]
	movs r0, 0xC
_0813A2BC:
	strh r0, [r3, 0x10]
_0813A2BE:
	strh r0, [r3, 0x12]
	strh r1, [r3, 0x14]
	strh r4, [r3, 0x26]
	b _0813A2D2
_0813A2C6:
	ldr r1, =gScriptResult
	movs r0, 0x7F
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0813A2D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A128

	thumb_func_start sub_813A2DC
sub_813A2DC: @ 813A2DC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	bl ScriptContext2_Enable
	ldr r0, =gUnknown_0203AB68
	movs r5, 0
	strh r5, [r0]
	ldr r1, =gUnknown_0203AB6C
	movs r0, 0x40
	strb r0, [r1]
	ldrh r0, [r6, 0x1E]
	movs r1, 0
	bl sub_813AA60
	ldrb r0, [r6, 0x1E]
	movs r1, 0
	bl sub_813ACE8
	ldr r4, =gUnknown_0203AB64
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gUnknown_0203AB6A
	strh r5, [r0]
	bl sub_813A42C
	movs r3, 0
	movs r4, 0
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	add r1, sp, 0x18
	mov r8, r1
	cmp r3, r0
	bge _0813A36A
	ldr r5, =gUnknown_085B2CF0
_0813A33A:
	lsls r1, r4, 2
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r1, r5
	ldr r0, [r1]
	ldr r1, =gUnknown_0203AB64
	ldr r2, [r1]
	lsls r1, r4, 3
	adds r1, r2
	str r0, [r1]
	str r4, [r1, 0x4]
	adds r1, r3, 0
	bl display_text_and_get_width
	adds r3, r0, 0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	cmp r4, r0
	blt _0813A33A
_0813A36A:
	adds r0, r3, 0
	bl convert_pixel_width_to_tile_width
	strh r0, [r6, 0x10]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	adds r0, r1
	cmp r0, 0x1D
	ble _0813A38C
	movs r0, 0x1D
	subs r0, r1
	cmp r0, 0
	bge _0813A38A
	movs r0, 0
_0813A38A:
	strh r0, [r6, 0xC]
_0813A38C:
	ldrb r2, [r6, 0xC]
	ldrb r3, [r6, 0xE]
	ldrb r0, [r6, 0x10]
	str r0, [sp]
	ldrb r0, [r6, 0x12]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x64
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	bl sub_8198A50
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	mov r0, r8
	bl AddWindow
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r4, =gUnknown_030061D0
	ldrh r0, [r6, 0xA]
	strh r0, [r4, 0xC]
	ldrh r0, [r6, 0x8]
	strh r0, [r4, 0xE]
	ldrh r0, [r6, 0x22]
	strb r0, [r4, 0x10]
	adds r0, r7, 0
	bl sub_813A694
	ldrh r1, [r6, 0x16]
	ldrh r2, [r6, 0x18]
	adds r0, r4, 0
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x24]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_813A4EC
	str r1, [r0]
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A2DC

	thumb_func_start sub_813A42C
sub_813A42C: @ 813A42C
	ldr r1, =gUnknown_030061D0
	ldr r0, =gUnknown_0203AB64
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, =sub_813A46C
	str r0, [r1, 0x4]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r2, 0
	movs r0, 0x1
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strb r2, [r1, 0x10]
	strb r2, [r1, 0x11]
	movs r0, 0x8
	strb r0, [r1, 0x12]
	strb r2, [r1, 0x13]
	movs r0, 0x21
	strb r0, [r1, 0x14]
	movs r0, 0x31
	strb r0, [r1, 0x15]
	movs r0, 0
	strb r0, [r1, 0x16]
	movs r0, 0x1
	strb r0, [r1, 0x17]
	bx lr
	.pool
	thumb_func_end sub_813A42C

	thumb_func_start sub_813A46C
sub_813A46C: @ 813A46C
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_813A4EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0813A4D4
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	bl get_coro_args_x18_x1A
	ldr r1, =gUnknown_0203AB68
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	bl sub_81AE838
	ldrh r0, [r4, 0x1E]
	ldr r5, =gUnknown_0203AB6A
	ldrh r1, [r5]
	bl sub_813AC44
	ldrh r0, [r4, 0x1E]
	mov r1, sp
	ldrh r1, [r1]
	bl sub_813AA60
	ldrb r0, [r4, 0x1E]
	mov r1, sp
	ldrh r1, [r1]
	bl sub_813AD34
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5]
_0813A4D4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A46C

	thumb_func_start sub_813A4EC
sub_813A4EC: @ 813A4EC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrh r0, [r6, 0x24]
	lsls r0, 24
	lsrs r0, 24
	bl ListMenuHandleInput
	adds r4, r0, 0
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0813A51C
	adds r0, 0x1
	cmp r4, r0
	bne _0813A530
	b _0813A566
	.pool
_0813A51C:
	ldr r1, =gScriptResult
	movs r0, 0x7F
	strh r0, [r1]
	movs r0, 0x5
	bl PlaySE
	b _0813A54C
	.pool
_0813A530:
	ldr r0, =gScriptResult
	strh r4, [r0]
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0813A54C
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	cmp r4, r0
	bne _0813A558
_0813A54C:
	adds r0, r5, 0
	bl sub_813A570
	b _0813A566
	.pool
_0813A558:
	adds r0, r5, 0
	bl sub_813A738
	ldr r0, =sub_813A600
	str r0, [r6]
	bl EnableBothScriptContexts
_0813A566:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A4EC

	thumb_func_start sub_813A570
sub_813A570: @ 813A570
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	bl sub_81AE838
	ldrh r0, [r4, 0x1E]
	mov r1, sp
	ldrh r1, [r1]
	bl sub_813AC44
	adds r0, r5, 0
	bl sub_813A738
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203AB64
	ldr r0, [r0]
	bl Free
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_8198070
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl CopyWindowToVram
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A570

	thumb_func_start sub_813A600
sub_813A600: @ 813A600
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x14
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0813A624
	cmp r0, 0x2
	bne _0813A624
	movs r0, 0x1
	strh r0, [r1, 0x14]
	ldr r0, =sub_813A664
	str r0, [r1]
_0813A624:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A600

	thumb_func_start sub_813A630
sub_813A630: @ 813A630
	push {lr}
	ldr r0, =sub_813A600
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _0813A64C
	bl EnableBothScriptContexts
	b _0813A65C
	.pool
_0813A64C:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	adds r0, 0x1
	strh r0, [r1, 0x14]
_0813A65C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A630

	thumb_func_start sub_813A664
sub_813A664: @ 813A664
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ScriptContext2_Enable
	adds r0, r4, 0
	bl sub_813A694
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_813A4EC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A664

	thumb_func_start sub_813A694
sub_813A694: @ 813A694
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	mov r1, sp
	ldr r0, =gUnknown_085B3030
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	beq _0813A724
	mov r2, sp
	movs r3, 0x10
	ldrsh r1, [r4, r3]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 3
	adds r1, 0xC
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	subs r0, 0x1
	lsls r0, 3
	adds r1, r0
	movs r3, 0
	strb r1, [r2, 0x1]
	mov r1, sp
	movs r0, 0x8
	strb r0, [r1, 0x2]
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 3
	adds r1, 0xC
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	subs r0, 0x1
	lsls r0, 3
	adds r1, r0
	strb r1, [r2, 0x4]
	mov r1, sp
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, 0xA
	strb r0, [r1, 0x5]
	mov r0, sp
	strh r3, [r0, 0x6]
	mov r2, sp
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	subs r0, r1
	strh r0, [r2, 0x8]
	ldr r1, =gUnknown_0203AB68
	mov r0, sp
	bl AddScrollIndicatorArrowPair
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
_0813A724:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A694

	thumb_func_start sub_813A738
sub_813A738: @ 813A738
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r2, r1, r0
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _0813A75E
	ldrh r0, [r2, 0x20]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveScrollIndicatorArrowPair
_0813A75E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A738

	thumb_func_start nullsub_55
nullsub_55: @ 813A768
	bx lr
	thumb_func_end nullsub_55

	thumb_func_start sub_813A76C
sub_813A76C: @ 813A76C
	push {r4-r6,lr}
	movs r4, 0
	ldr r6, =gLinkPlayers
	ldr r0, =0x0000401f
	adds r5, r0, 0
_0813A776:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	bne _0813A79C
	subs r0, r5, r4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl VarSet
	b _0813A7A8
	.pool
_0813A79C:
	subs r0, r5, r4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x69
	bl VarSet
_0813A7A8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _0813A776
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_813A76C

	thumb_func_start sub_813A7B8
sub_813A7B8: @ 813A7B8
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	ldrh r0, [r1]
	cmp r0, 0x5
	bls _0813A7C6
	movs r0, 0
	strh r0, [r1]
_0813A7C6:
	ldrh r1, [r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	lsls r0, 24
	ldr r1, =gUnknown_085B3040
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bl box_related_two__2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A7B8

	thumb_func_start sub_813A7F4
sub_813A7F4: @ 813A7F4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004030
	bl GetVarPointer
	adds r5, r0, 0
	ldrh r0, [r5]
	adds r4, r0
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0xC
	bl __umodsi3
	strh r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A7F4

	thumb_func_start sub_813A820
sub_813A820: @ 813A820
	push {r4,lr}
	ldr r0, =0x00004030
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r1, =gUnknown_085B30A4
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	bl box_related_two__2
	ldr r0, =0x00004031
	adds r1, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A820

	thumb_func_start sub_813A854
sub_813A854: @ 813A854
	push {r4,lr}
	ldr r4, =gUnknown_085B30D4
	ldr r0, =0x00004031
	bl VarGet
	lsls r0, 16
	lsrs r0, 14
	adds r0, r4
	ldr r0, [r0]
	bl box_related_two__2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A854

	thumb_func_start sub_813A878
sub_813A878: @ 813A878
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =0x00004031
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r4, =0x00004033
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0813A8F0
	ldr r1, =gUnknown_085B3104
	lsls r0, r6, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r5, 8
	adds r0, r7
	cmp r1, r0
	bne _0813A8F0
	mov r0, r8
	cmp r0, 0
	beq _0813A8E8
	adds r0, r4, 0
	movs r1, 0x2
	bl VarSet
	b _0813A8F0
	.pool
_0813A8E8:
	adds r0, r4, 0
	movs r1, 0x3
	bl VarSet
_0813A8F0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_813A878

	thumb_func_start sub_813A8FC
sub_813A8FC: @ 813A8FC
	push {lr}
	sub sp, 0x2C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000eb8
	adds r0, r1
	ldrh r1, [r0]
	add r0, sp, 0xC
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_085EB6AD
	bl StringCopy
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x30
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	ldr r0, =gUnknown_0203AB6D
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	bl PrintTextOnWindow
	add sp, 0x2C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A8FC

	thumb_func_start sub_813A958
sub_813A958: @ 813A958
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6D
	ldr r0, =gUnknown_085B311C
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	bl sub_813A8FC
	ldrb r0, [r4]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A958

	thumb_func_start sub_813A988
sub_813A988: @ 813A988
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6D
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813A988

	thumb_func_start sub_813A9A4
sub_813A9A4: @ 813A9A4
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000eb8
	adds r1, r0, r2
	ldr r0, =gSpecialVar_0x8004
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r2, r0
	bcs _0813A9C8
	movs r0, 0
	b _0813A9CA
	.pool
_0813A9C8:
	subs r0, r2, r0
_0813A9CA:
	strh r0, [r1]
	pop {r0}
	bx r0
	thumb_func_end sub_813A9A4

	thumb_func_start sub_813A9D0
sub_813A9D0: @ 813A9D0
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000eb8
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	adds r1, r0
	ldr r0, =0x0000270f
	cmp r1, r0
	ble _0813A9FC
	strh r0, [r2]
	b _0813A9FE
	.pool
_0813A9FC:
	strh r1, [r2]
_0813A9FE:
	pop {r0}
	bx r0
	thumb_func_end sub_813A9D0

	thumb_func_start sub_813AA04
sub_813AA04: @ 813AA04
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000eb8
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_813AA04

	thumb_func_start sub_813AA18
sub_813AA18: @ 813AA18
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6E
	ldr r0, =gUnknown_085B3124
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r4]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AA18

	thumb_func_start sub_813AA44
sub_813AA44: @ 813AA44
	push {r4,lr}
	ldr r4, =gUnknown_0203AB6E
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AA44

	thumb_func_start sub_813AA60
sub_813AA60: @ 813AA60
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	lsrs r4, r0, 16
	ldr r1, =0xfffd0000
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x3
	bls _0813AA78
	b _0813ABC2
_0813AA78:
	movs r0, 0xD8
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	cmp r4, 0x4
	beq _0813AAE8
	cmp r4, 0x4
	bgt _0813AAA0
	cmp r4, 0x3
	beq _0813AAAA
	b _0813ABC2
	.pool
_0813AAA0:
	cmp r4, 0x5
	beq _0813AB5C
	cmp r4, 0x6
	beq _0813AB94
	b _0813ABC2
_0813AAAA:
	ldr r1, =gUnknown_085B3170
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	ldr r1, =gUnknown_085B312C
	lsls r0, r5, 1
	adds r1, r0, r1
	ldrh r5, [r1]
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _0813AB18
	b _0813AB2C
	.pool
_0813AAE8:
	ldr r1, =gUnknown_085B319C
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	ldr r1, =gUnknown_085B3142
	lsls r0, r5, 1
	adds r1, r0, r1
	ldrh r5, [r1]
	ldr r0, =0x0000ffff
	cmp r5, r0
	bne _0813AB2C
_0813AB18:
	ldrh r0, [r1]
	bl sub_813ABD4
	b _0813ABC2
	.pool
_0813AB2C:
	ldr r4, =0x0000157c
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	lsls r0, r5, 24
	lsrs r0, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r1, 0x21
	movs r2, 0x58
	movs r3, 0
	bl AddDecorationIconObject
	ldr r1, =gUnknown_0203AB6C
	strb r0, [r1]
	b _0813ABC2
	.pool
_0813AB5C:
	ldr r1, =gUnknown_085B31B4
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	ldr r1, =gUnknown_085B314E
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	bl sub_813ABD4
	b _0813ABC2
	.pool
_0813AB94:
	ldr r1, =gUnknown_085B31D0
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	ldr r1, =gUnknown_085B315C
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	bl sub_813ABD4
_0813ABC2:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AA60

	thumb_func_start sub_813ABD4
sub_813ABD4: @ 813ABD4
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r4, =0x0000157c
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl AddItemIconObject
	ldr r4, =gUnknown_0203AB6C
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0813AC32
	ldr r3, =gSprites
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x24
	strh r1, [r0, 0x20]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x5C
	strh r1, [r0, 0x22]
_0813AC32:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ABD4

	thumb_func_start sub_813AC44
sub_813AC44: @ 813AC44
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =gUnknown_0203AB6C
	ldrb r0, [r2]
	cmp r0, 0x40
	beq _0813AC70
	cmp r1, 0x6
	bgt _0813AC6A
	cmp r1, 0x3
	blt _0813AC6A
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySpriteAndFreeResources
_0813AC6A:
	ldr r1, =gUnknown_0203AB6C
	movs r0, 0x40
	strb r0, [r1]
_0813AC70:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AC44

	thumb_func_start sub_813AC7C
sub_813AC7C: @ 813AC7C
	push {lr}
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0
	beq _0813ACB8
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B320C
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	b _0813ACD2
	.pool
_0813ACB8:
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B31F8
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
_0813ACD2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AC7C

	thumb_func_start sub_813ACE8
sub_813ACE8: @ 813ACE8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0813AD20
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813AD18
	ldr r4, =gUnknown_0203AB5E
	ldr r0, =gUnknown_085B3220
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl SetStandardWindowBorderStyle
_0813AD18:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_813AD34
_0813AD20:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ACE8

	thumb_func_start sub_813AD34
sub_813AD34: @ 813AD34
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	adds r7, r5, 0
	lsrs r6, r0, 24
	movs r1, 0xF7
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0813ADAC
	ldr r4, =gUnknown_0203AB5E
	ldrb r0, [r4]
	movs r1, 0x60
	str r1, [sp]
	movs r1, 0x30
	str r1, [sp, 0x4]
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	cmp r6, 0xA
	bne _0813AD90
	ldrb r0, [r4]
	ldr r2, =gUnknown_085B3254
	lsls r1, r5, 2
	adds r1, r2
	ldr r2, [r1]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	b _0813ADAC
	.pool
_0813AD90:
	ldrb r0, [r4]
	ldr r2, =gUnknown_085B3228
	lsls r1, r7, 2
	adds r1, r2
	ldr r2, [r1]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
_0813ADAC:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AD34

	thumb_func_start sub_813ADB8
sub_813ADB8: @ 813ADB8
	push {r4,lr}
	ldr r4, =gUnknown_0203AB5E
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ADB8

	thumb_func_start sub_813ADD4
sub_813ADD4: @ 813ADD4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	ldr r0, =sub_813A600
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _0813AE90
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrh r0, [r6, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r4, sp
	adds r4, 0x16
	add r1, sp, 0x14
	adds r2, r4, 0
	bl get_coro_args_x18_x1A
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl SetStandardWindowBorderStyle
	movs r5, 0
	mov r9, r4
	ldr r0, =gUnknown_085B2CF0
	mov r8, r0
	movs r4, 0
_0813AE1E:
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	add r1, sp, 0x14
	ldrh r2, [r1]
	adds r2, r5
	lsls r2, 2
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 6
	adds r2, r1
	add r2, r8
	ldr r2, [r2]
	lsls r1, r5, 28
	lsrs r1, 24
	str r1, [sp]
	movs r7, 0xFF
	str r7, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0xA
	bl sub_8199F74
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0813AE1E
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_SelectorArrow
	mov r3, r9
	ldrh r1, [r3]
	lsls r1, 28
	lsrs r1, 24
	str r1, [sp]
	str r7, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrh r0, [r6, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl CopyWindowToVram
_0813AE90:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813ADD4

	thumb_func_start sub_813AEB4
sub_813AEB4: @ 813AEB4
	push {r4,lr}
	movs r1, 0
	ldr r0, =gSpecialVar_0x8005
	strh r1, [r0]
	ldr r0, =0x0000400e
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x0000400d
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r4, 0
	beq _0813AF18
	movs r2, 0
	lsls r1, 1
	ldr r3, =gUnknown_0861500C
	ldr r0, =gUnknown_085B320C
	adds r0, r1, r0
	ldrh r1, [r0]
_0813AEE2:
	lsls r0, r2, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	beq _0813AF0C
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1D
	bls _0813AEE2
	b _0813AF38
	.pool
_0813AF0C:
	ldr r0, =gSpecialVar_0x8005
	strh r2, [r0]
	b _0813AF38
	.pool
_0813AF18:
	movs r2, 0
	lsls r1, 1
	ldr r3, =gUnknown_0861500C
	ldr r0, =gUnknown_085B31F8
	adds r0, r1, r0
	ldrh r1, [r0]
_0813AF24:
	lsls r0, r2, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	beq _0813AF0C
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1D
	bls _0813AF24
_0813AF38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AEB4

	thumb_func_start sub_813AF48
sub_813AF48: @ 813AF48
	push {r4,r5,lr}
	ldr r0, =sub_813A600
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xFF
	beq _0813AFB6
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203AB64
	ldr r0, [r0]
	bl Free
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_8198070
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl ClearWindowTilemap
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl CopyWindowToVram
	ldrh r0, [r4, 0x22]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
_0813AFB6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AF48

	thumb_func_start sub_813AFC8
sub_813AFC8: @ 813AFC8
	push {lr}
	ldr r0, =task_deoxys_sound
	movs r1, 0x8
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813AFC8

	thumb_func_start task_deoxys_sound
task_deoxys_sound: @ 813AFDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =0x000008d4
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B004
	ldr r1, =gScriptResult
	movs r0, 0x3
	b _0813B06A
	.pool
_0813B004:
	ldr r0, =0x00004035
	mov r8, r0
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r4, =0x00004034
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	cmp r5, 0
	beq _0813B05C
	ldr r0, =gUnknown_085B33F6
	subs r1, r5, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, r6
	bcs _0813B05C
	movs r0, 0
	bl sub_813B0B4
	mov r0, r8
	movs r1, 0
	bl VarSet
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	b _0813B070
	.pool
_0813B05C:
	cmp r5, 0xA
	bne _0813B080
	ldr r0, =0x000008d4
	bl FlagSet
	ldr r1, =gScriptResult
	movs r0, 0x2
_0813B06A:
	strh r0, [r1]
	bl EnableBothScriptContexts
_0813B070:
	adds r0, r7, 0
	bl DestroyTask
	b _0813B0A2
	.pool
_0813B080:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_813B0B4
	ldr r0, =0x00004035
	adds r1, r5, 0
	bl VarSet
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r7, 0
	bl DestroyTask
_0813B0A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_deoxys_sound

	thumb_func_start sub_813B0B4
sub_813B0B4: @ 813B0B4
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 5
	ldr r1, =gUnknown_085B3280
	adds r0, r1
	movs r1, 0xD0
	lsls r1, 1
	movs r2, 0x8
	bl LoadPalette
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x1
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	cmp r4, 0
	bne _0813B0F0
	movs r0, 0xC4
	bl PlaySE
	b _0813B0F8
	.pool
_0813B0F0:
	movs r0, 0x82
	lsls r0, 1
	bl PlaySE
_0813B0F8:
	ldr r0, =sub_813B160
	movs r1, 0x8
	bl CreateTask
	ldr r3, =gUnknown_02038C08
	movs r0, 0x1
	str r0, [r3]
	movs r0, 0x3A
	str r0, [r3, 0x4]
	movs r0, 0x1A
	str r0, [r3, 0x8]
	ldr r0, =gUnknown_085B33E0
	lsls r2, r4, 1
	adds r1, r2, r0
	ldrb r1, [r1]
	str r1, [r3, 0xC]
	adds r0, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	str r0, [r3, 0x10]
	adds r5, r2, 0
	cmp r4, 0
	bne _0813B138
	movs r0, 0x3C
	b _0813B13A
	.pool
_0813B138:
	movs r0, 0x5
_0813B13A:
	str r0, [r3, 0x14]
	movs r0, 0x42
	bl FieldEffectStart
	ldr r0, =gUnknown_085B33E0
	adds r1, r5, r0
	ldrb r1, [r1]
	adds r0, 0x1
	adds r0, r5, r0
	ldrb r2, [r0]
	movs r0, 0x1
	bl update_saveblock1_field_object_coords
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B0B4

	thumb_func_start sub_813B160
sub_813B160: @ 813B160
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x42
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _0813B17C
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_0813B17C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_813B160

	thumb_func_start increment_var_x4026_on_birth_island_modulo_100
increment_var_x4026_on_birth_island_modulo_100: @ 813B184
	push {r4,lr}
	ldr r4, =0x00004034
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00003a1a
	cmp r1, r0
	bne _0813B1C8
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x63
	bls _0813B1C0
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	b _0813B1C8
	.pool
_0813B1C0:
	adds r0, r4, 0
	adds r1, r2, 0
	bl VarSet
_0813B1C8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end increment_var_x4026_on_birth_island_modulo_100

	thumb_func_start sub_813B1D0
sub_813B1D0: @ 813B1D0
	push {lr}
	ldr r0, =0x00004035
	bl VarGet
	lsls r0, 24
	lsrs r0, 19
	ldr r1, =gUnknown_085B3280
	adds r0, r1
	movs r1, 0xD0
	lsls r1, 1
	movs r2, 0x8
	bl LoadPalette
	movs r0, 0x80
	lsls r0, 19
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B1D0

	thumb_func_start set_unknown_box_id
@ void set_unknown_box_id(char id)
set_unknown_box_id: @ 813B204
	ldr r1, =gUnknown_0203AB6F
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end set_unknown_box_id

	thumb_func_start get_unknown_box_id
get_unknown_box_id: @ 813B210
	ldr r0, =gUnknown_0203AB6F
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_unknown_box_id

	thumb_func_start sub_813B21C
sub_813B21C: @ 813B21C
	push {r4,r5,lr}
	ldr r5, =0x000008d7
	adds r0, r5, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _0813B258
	bl StorageGetCurrentBox
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	beq _0813B258
	adds r0, r5, 0
	bl FlagSet
	movs r0, 0x1
	b _0813B25A
	.pool
_0813B258:
	movs r0, 0
_0813B25A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_813B21C

	thumb_func_start sub_813B260
sub_813B260: @ 813B260
	push {r4-r7,lr}
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl set_unknown_box_id
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r4, r0, 24
_0813B278:
	movs r5, 0
	lsls r6, r4, 24
	lsls r7, r4, 16
_0813B27E:
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	bl GetBoxedMonPtr
	movs r1, 0xB
	movs r2, 0
	bl GetBoxMonData
	cmp r0, 0
	bne _0813B2C0
	bl get_unknown_box_id
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	beq _0813B2A6
	ldr r0, =0x000008d7
	bl FlagReset
_0813B2A6:
	ldr r0, =0x00004036
	lsrs r1, r7, 16
	bl VarSet
	bl sub_813B21C
	lsls r0, 24
	lsrs r0, 24
	b _0813B2DC
	.pool
_0813B2C0:
	adds r5, 0x1
	cmp r5, 0x1D
	ble _0813B27E
	adds r4, 0x1
	cmp r4, 0xE
	bne _0813B2CE
	movs r4, 0
_0813B2CE:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0813B278
	movs r0, 0
_0813B2DC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813B260

	thumb_func_start sub_813B2E4
sub_813B2E4: @ 813B2E4
	push {r4,lr}
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004038
	movs r1, 0
	bl VarSet
	movs r0, 0xDF
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B340
	ldr r0, =0x000001bf
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B330
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0
	adds r1, 0x9
	bl VarSet
	b _0813B36A
	.pool
_0813B330:
	movs r0, 0x1
	ands r4, r0
	cmp r4, 0
	bne _0813B354
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
_0813B340:
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0x1
	bl VarSet
	b _0813B36A
	.pool
_0813B354:
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0
	adds r1, 0x9
	bl VarSet
_0813B36A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B2E4

	thumb_func_start sub_813B374
sub_813B374: @ 813B374
	push {r4,lr}
	ldr r0, =0x00004037
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B3400
	subs r1, r4, 0x1
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl GetMapName
	cmp r4, 0x8
	bls _0813B3A8
	movs r0, 0x1
	b _0813B3AA
	.pool
_0813B3A8:
	movs r0, 0
_0813B3AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813B374

	thumb_func_start sub_813B3B0
sub_813B3B0: @ 813B3B0
	push {r4-r6,lr}
	ldr r5, =0x00004038
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004037
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _0813B47C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x000003e7
	cmp r4, r0
	bls _0813B474
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	cmp r0, 0x18
	bne _0813B414
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0x69
	bgt _0813B414
	cmp r0, 0x65
	blt _0813B414
	ldr r0, =0x00004039
	movs r1, 0x1
	b _0813B478
	.pool
_0813B414:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	adds r3, r0, 0
	cmp r1, 0
	bne _0813B444
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, 0x34
	beq _0813B436
	cmp r0, 0x34
	blt _0813B444
	cmp r0, 0x38
	bgt _0813B444
	cmp r0, 0x36
	blt _0813B444
_0813B436:
	ldr r0, =0x00004039
	movs r1, 0x1
	b _0813B478
	.pool
_0813B444:
	ldr r3, [r3]
	movs r2, 0x5
	ldrsb r2, [r3, r2]
	ldr r1, =gUnknown_085B3410
	subs r0, r6, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0813B468
	movs r0, 0x4
	ldrsb r0, [r3, r0]
	cmp r0, 0
	bne _0813B468
	movs r0, 0x1
	b _0813B47E
	.pool
_0813B468:
	ldr r0, =0x00004037
	movs r1, 0
	b _0813B478
	.pool
_0813B474:
	adds r0, r5, 0
	adds r1, r4, 0
_0813B478:
	bl VarSet
_0813B47C:
	movs r0, 0
_0813B47E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_813B3B0

	thumb_func_start sub_813B484
sub_813B484: @ 813B484
	push {lr}
	movs r0, 0x2
	bl sub_80AB104
	pop {r0}
	bx r0
	thumb_func_end sub_813B484

	thumb_func_start sub_813B490
sub_813B490: @ 813B490
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	movs r6, 0x4
	ldrsb r6, [r4, r6]
	ldr r5, =gUnknown_085B3420
	adds r0, r5, 0x2
	mov r12, r0
	adds r7, r5, 0x1
_0813B4A4:
	lsls r0, r3, 1
	adds r2, r0, r3
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r6, r0
	bne _0813B4CC
	movs r1, 0x5
	ldrsb r1, [r4, r1]
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r1, r0
	bne _0813B4CC
	mov r1, r12
	adds r0, r2, r1
	ldrb r0, [r0]
	b _0813B4D8
	.pool
_0813B4CC:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xB
	bls _0813B4A4
	movs r0, 0x1
_0813B4D8:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813B490

	thumb_func_start sub_813B4E0
sub_813B4E0: @ 813B4E0
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl sub_81D15CC
	cmp r0, 0
	blt _0813B50C
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B50C
	movs r0, 0x1
	b _0813B50E
	.pool
_0813B50C:
	movs r0, 0
_0813B50E:
	pop {r1}
	bx r1
	thumb_func_end sub_813B4E0

	thumb_func_start sub_813B514
sub_813B514: @ 813B514
	push {lr}
	ldr r0, =0x0000403f
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _0813B52C
	movs r0, 0x1
	b _0813B52E
	.pool
_0813B52C:
	movs r0, 0
_0813B52E:
	pop {r1}
	bx r1
	thumb_func_end sub_813B514

	thumb_func_start sub_813B534
sub_813B534: @ 813B534
	push {lr}
	ldr r2, =gUnknown_0203AB70
	ldr r1, =gBattleTypeFlags
	ldr r0, [r1]
	str r0, [r2]
	movs r0, 0
	str r0, [r1]
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _0813B552
	ldr r0, =sub_80B3AF8
	movs r1, 0x5
	bl CreateTask
_0813B552:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B534

	thumb_func_start sub_813B568
sub_813B568: @ 813B568
	push {lr}
	ldr r0, =sub_813B57C
	movs r1, 0x5
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B568

	thumb_func_start sub_813B57C
sub_813B57C: @ 813B57C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	bls _0813B596
	b _0813B7C6
_0813B596:
	lsls r0, 2
	ldr r1, =_0813B5A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813B5A8:
	.4byte _0813B5D0
	.4byte _0813B5E4
	.4byte _0813B614
	.4byte _0813B6B4
	.4byte _0813B6E4
	.4byte _0813B728
	.4byte _0813B764
	.4byte _0813B772
	.4byte _0813B784
	.4byte _0813B7A8
_0813B5D0:
	ldr r0, =sub_80B3AF8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0813B5DE
	b _0813B7C6
_0813B5DE:
	b _0813B790
	.pool
_0813B5E4:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B5F2
	b _0813B7C6
_0813B5F2:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B5FE
	b _0813B790
_0813B5FE:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_0x8004
	movs r2, 0x2
	bl link_0800A448
	b _0813B708
	.pool
_0813B614:
	bl sub_800A550
	movs r1, 0x2
	ands r1, r0
	cmp r1, 0
	bne _0813B622
	b _0813B7C6
_0813B622:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0813B62E
	b _0813B790
_0813B62E:
	ldr r5, =gSpecialVar_0x8005
	ldr r0, =gUnknown_020223C4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, 0x1
	bl sub_800A5EC
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0813B668
	ldrh r1, [r5]
	cmp r1, 0x1
	bne _0813B668
	ldr r0, =gScriptResult
	strh r1, [r0]
	b _0813B790
	.pool
_0813B668:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	adds r2, r0, 0
	cmp r1, 0
	bne _0813B68C
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0813B68C
	ldr r1, =gScriptResult
	movs r0, 0x2
	b _0813B6AC
	.pool
_0813B68C:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _0813B6A8
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813B6A8
	ldr r1, =gScriptResult
	movs r0, 0x3
	b _0813B6AC
	.pool
_0813B6A8:
	ldr r1, =gScriptResult
	movs r0, 0
_0813B6AC:
	strh r0, [r1]
	b _0813B790
	.pool
_0813B6B4:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B6C2
	b _0813B7C6
_0813B6C2:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B790
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gScriptResult
	movs r2, 0x2
	bl link_0800A448
	b _0813B708
	.pool
_0813B6E4:
	bl sub_800A550
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0813B7C6
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0813B790
	ldr r1, =gScriptResult
	ldr r0, =gUnknown_020223C4
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, 0
	bl sub_800A5EC
_0813B708:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0813B7C6
	.pool
_0813B728:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B74C
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x2
	bne _0813B790
	ldr r0, =gUnknown_0824979B
	bl box_related_two__3
	b _0813B790
	.pool
_0813B74C:
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x3
	bne _0813B790
	ldr r0, =gUnknown_0824979B
	bl box_related_two__3
	b _0813B790
	.pool
_0813B764:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813B7C6
	b _0813B790
_0813B772:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B7C6
	bl sub_800ADF8
	b _0813B790
_0813B784:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B7C6
_0813B790:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0813B7C6
	.pool
_0813B7A8:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _0813B7B4
	bl sub_800AC34
_0813B7B4:
	ldr r0, =gBattleTypeFlags
	ldr r1, =gUnknown_0203AB70
	ldr r1, [r1]
	str r1, [r0]
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_0813B7C6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B57C

	thumb_func_start sub_813B7D8
sub_813B7D8: @ 813B7D8
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813B7F8
	ldr r2, =c2_exit_to_overworld_1_continue_scripts_restart_music
	movs r0, 0
	movs r1, 0x1
	bl sub_81D6720
	b _0813B802
	.pool
_0813B7F8:
	ldr r2, =c2_exit_to_overworld_1_continue_scripts_restart_music
	movs r0, 0x1
	movs r1, 0
	bl sub_81D6720
_0813B802:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B7D8

	thumb_func_start sub_813B80C
sub_813B80C: @ 813B80C
	push {lr}
	ldr r0, =sub_813B824
	movs r1, 0x8
	bl CreateTask
	movs r0, 0x9D
	bl PlaySE
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B80C

	thumb_func_start sub_813B824
sub_813B824: @ 813B824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r1, r0
	bne _0813B858
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x9D
	bl PlaySE
_0813B858:
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _0813B86C
	adds r0, r5, 0
	bl DestroyTask
_0813B86C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B824

	thumb_func_start sub_813B880
sub_813B880: @ 813B880
	push {lr}
	ldr r0, =_fwalk
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	movs r0, 0x4
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r2, [r1, 0xE]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B880

	thumb_func_start _fwalk
_fwalk: @ 813B8B0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	lsls r1, 1
	adds r1, r5
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r0, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0813B94E
	movs r6, 0
_0813B8EA:
	movs r4, 0
	lsls r3, r6, 3
	mov r10, r3
	adds r7, r6, 0x1
	mov r8, r7
_0813B8F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, r4
	adds r0, 0x6
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r1, r6
	adds r1, 0x4
	ldr r7, =0x00000201
	adds r2, r4, r7
	add r2, r10
	movs r7, 0x6
	ldrsh r3, [r5, r7]
	lsls r3, 5
	adds r2, r3
	lsls r2, 16
	lsrs r2, 16
	bl MapGridSetMetatileIdAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0813B8F4
	mov r1, r8
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0813B8EA
	bl DrawWholeMapView
	ldrh r0, [r5, 0x6]
	adds r0, 0x1
	strh r0, [r5, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0813B94E
	mov r0, r9
	bl DestroyTask
	bl EnableBothScriptContexts
_0813B94E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end _fwalk

	thumb_func_start sub_813B968
sub_813B968: @ 813B968
	push {r4,r5,lr}
	ldr r5, =gScriptResult
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	strh r0, [r5]
	ldrh r4, [r5]
	adds r0, r4, 0
	movs r1, 0x14
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	subs r4, r1
	strh r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B968

	thumb_func_start sub_813B9A0
sub_813B9A0: @ 813B9A0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x1C]
	movs r0, 0xB0
	lsls r0, 4
	cmp r1, r0
	bne _0813B9B6
	movs r0, 0x3
	bl sub_8084D1C
_0813B9B6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B9A0

	thumb_func_start sub_813B9C0
sub_813B9C0: @ 813B9C0
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gUnknown_085B3444
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0813BA06
	adds r4, r1, 0
	adds r1, r2, 0
_0813B9E6:
	ldrh r0, [r2]
	cmp r0, r3
	bne _0813B9FC
	movs r0, 0x1
	b _0813BA08
	.pool
_0813B9FC:
	adds r1, 0x2
	adds r2, 0x2
	ldrh r0, [r1]
	cmp r0, r4
	bne _0813B9E6
_0813BA06:
	movs r0, 0
_0813BA08:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813B9C0

	thumb_func_start ResetFanClub
ResetFanClub: @ 813BA10
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x0000141e
	adds r1, r0, r2
	movs r2, 0
	strh r2, [r1]
	movs r1, 0xA1
	lsls r1, 5
	adds r0, r1
	strh r2, [r0]
	bx lr
	.pool
	thumb_func_end ResetFanClub

	thumb_func_start sub_813BA30
sub_813BA30: @ 813BA30
	push {lr}
	bl sub_813BF44
	lsls r0, 24
	cmp r0, 0
	beq _0813BA52
	bl sub_813BCE8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
_0813BA52:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BA30

	thumb_func_start sub_813BA60
sub_813BA60: @ 813BA60
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 7
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0813BAB6
	bl sub_813BF60
	bl sub_813BD84
	ldr r1, [r4]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	ldr r0, =0x00000315
	bl FlagReset
	ldr r0, =0x00000316
	bl FlagReset
	ldr r0, =0x00000317
	bl FlagReset
	movs r0, 0xC6
	lsls r0, 2
	bl FlagReset
	ldr r0, =0x000002da
	bl FlagReset
	ldr r0, =0x00004095
	movs r1, 0x1
	bl VarSet
_0813BAB6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BA60

	thumb_func_start sub_813BADC
sub_813BADC: @ 813BADC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x00004095
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _0813BB58
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x0000141e
	adds r3, r0, r5
	ldrh r2, [r3]
	movs r1, 0x7F
	ands r1, r2
	ldr r0, =gUnknown_085B3470
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r1, r0
	cmp r1, 0x13
	ble _0813BB54
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0813BB3C
	bl sub_813BB74
	ldr r0, [r4]
	adds r0, r5
	ldrh r2, [r0]
	ldr r1, =0x0000ff80
	ands r1, r2
	strh r1, [r0]
	b _0813BB58
	.pool
_0813BB3C:
	ldr r2, [r4]
	adds r2, r5
	ldrh r1, [r2]
	ldr r0, =0x0000ff80
	ands r0, r1
	movs r1, 0x14
	orrs r0, r1
	strh r0, [r2]
	b _0813BB58
	.pool
_0813BB54:
	adds r0, r2, r0
	strh r0, [r3]
_0813BB58:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x7F
	ands r0, r1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BADC

	thumb_func_start sub_813BB74
sub_813BB74: @ 813BB74
	push {r4-r7,lr}
	sub sp, 0x8
	movs r3, 0
	movs r5, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r2, =0x0000141e
	movs r6, 0x1
_0813BB82:
	ldr r0, [r7]
	adds r0, r2
	ldrh r1, [r0]
	ldr r0, =gUnknown_085B3474
	adds r0, r5, r0
	ldrb r4, [r0]
	asrs r1, r4
	ands r1, r6
	cmp r1, 0
	bne _0813BBC8
	adds r3, r5, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	bl Random
	adds r1, r6, 0
	ands r1, r0
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r1, 0
	beq _0813BBC8
	ldr r0, [r7]
	adds r0, r2
	adds r1, r6, 0
	lsls r1, r4
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _0813BBEA
	.pool
_0813BBC8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _0813BB82
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x0000141e
	adds r2, r0
	ldr r1, =gUnknown_085B3474
	adds r1, r3, r1
	movs r0, 0x1
	ldrb r1, [r1]
	lsls r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813BBEA:
	adds r0, r3, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BB74

	thumb_func_start sub_813BC00
sub_813BC00: @ 813BC00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0813BC2E
	movs r0, 0
	b _0813BC8E
_0813BC1E:
	mov r1, r8
	ldr r0, [r1]
	add r0, r9
	lsls r4, r6
	ldrh r1, [r0]
	eors r4, r1
	strh r4, [r0]
	b _0813BC8C
_0813BC2E:
	movs r5, 0
	ldr r2, =gSaveBlock1Ptr
	mov r8, r2
	ldr r0, =0x0000141e
	mov r9, r0
	movs r4, 0x1
_0813BC3A:
	mov r1, r8
	ldr r0, [r1]
	add r0, r9
	ldrh r1, [r0]
	ldr r7, =gUnknown_085B347C
	adds r0, r5, r7
	ldrb r6, [r0]
	asrs r1, r6
	ands r1, r4
	cmp r1, 0
	beq _0813BC5E
	mov r10, r5
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	bne _0813BC1E
_0813BC5E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _0813BC3A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x0000141e
	adds r4, r0, r2
	ldrh r1, [r4]
	mov r2, r10
	adds r0, r2, r7
	ldrb r2, [r0]
	adds r0, r1, 0
	asrs r0, r2
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0813BC8C
	adds r0, r3, 0
	lsls r0, r2
	eors r1, r0
	strh r1, [r4]
_0813BC8C:
	mov r0, r10
_0813BC8E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BC00

	thumb_func_start sub_813BCA8
sub_813BCA8: @ 813BCA8
	push {r4,r5,lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r4, [r0]
	movs r5, 0x1
_0813BCBA:
	adds r1, r2, 0
	adds r1, 0x8
	adds r0, r4, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _0813BCCE
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_0813BCCE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0813BCBA
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BCA8

	thumb_func_start sub_813BCE8
sub_813BCE8: @ 813BCE8
	push {r4-r6,lr}
	movs r5, 0
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldrh r1, [r0, 0xE]
	ldr r0, =0x000003e6
	cmp r1, r0
	bhi _0813BD58
	adds r6, r2, 0
	b _0813BD32
	.pool
_0813BD04:
	ldr r0, [r6]
	ldrh r1, [r0, 0xE]
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r2, 0xA1
	lsls r2, 5
	adds r0, r2
	ldrh r0, [r0]
	subs r1, r0
	cmp r1, 0xB
	ble _0813BD58
	bl sub_813BC00
	ldr r0, [r4]
	movs r1, 0xA1
	lsls r1, 5
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0xC
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0813BD32:
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _0813BD54
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r6]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	b _0813BD58
	.pool
_0813BD54:
	cmp r5, 0x8
	bne _0813BD04
_0813BD58:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_813BCE8

	thumb_func_start sub_813BD60
sub_813BD60: @ 813BD60
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_813BD60

	thumb_func_start sub_813BD84
sub_813BD84: @ 813BD84
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x0000141e
	adds r2, r0
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 3
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_813BD84

	thumb_func_start sub_813BDB4
sub_813BDB4: @ 813BDB4
	push {lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x8
	cmp r0, 0x7
	bhi _0813BE14
	lsls r0, 2
	ldr r1, =_0813BDD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813BDD8:
	.4byte _0813BE14
	.4byte _0813BE14
	.4byte _0813BDF8
	.4byte _0813BDFE
	.4byte _0813BE04
	.4byte _0813BE0A
	.4byte _0813BE10
	.4byte _0813BE14
_0813BDF8:
	movs r3, 0
	movs r2, 0x3
	b _0813BE14
_0813BDFE:
	movs r3, 0
	movs r2, 0x1
	b _0813BE14
_0813BE04:
	movs r3, 0x1
	movs r2, 0
	b _0813BE14
_0813BE0A:
	movs r3, 0
	movs r2, 0x4
	b _0813BE14
_0813BE10:
	movs r3, 0x1
	movs r2, 0x5
_0813BE14:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003150
	adds r0, r1
	adds r1, r3, 0
	bl sub_813BE30
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BDB4

	thumb_func_start sub_813BE30
sub_813BE30: @ 813BE30
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, r5, 4
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0813BEE8
	cmp r2, 0x5
	bhi _0813BED4
	lsls r0, r2, 2
	ldr r1, =_0813BE58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813BE58:
	.4byte _0813BED4
	.4byte _0813BE70
	.4byte _0813BE84
	.4byte _0813BE98
	.4byte _0813BEAC
	.4byte _0813BEC0
_0813BE70:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EAD14
	bl StringCopy
	b _0813BF04
	.pool
_0813BE84:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EAD1B
	bl StringCopy
	b _0813BF04
	.pool
_0813BE98:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EAD22
	bl StringCopy
	b _0813BF04
	.pool
_0813BEAC:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EAD29
	bl StringCopy
	b _0813BF04
	.pool
_0813BEC0:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EAD30
	bl StringCopy
	b _0813BF04
	.pool
_0813BED4:
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EAD0C
	bl StringCopy
	b _0813BF04
	.pool
_0813BEE8:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	movs r2, 0x7
	bl StringCopyN
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	adds r0, r6, 0
	adds r0, 0x50
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	bl ConvertInternationalString
_0813BF04:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BE30

	thumb_func_start sub_813BF10
sub_813BF10: @ 813BF10
	push {lr}
	ldr r0, =0x00004095
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _0813BF40
	bl sub_813BA30
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0813BF3C
	bl sub_813BB74
	b _0813BF40
	.pool
_0813BF3C:
	bl sub_813BC00
_0813BF40:
	pop {r0}
	bx r0
	thumb_func_end sub_813BF10

	thumb_func_start sub_813BF44
sub_813BF44: @ 813BF44
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 7
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_813BF44

	thumb_func_start sub_813BF60
sub_813BF60: @ 813BF60
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x0000141e
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x80
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_813BF60

	thumb_func_start sub_813BF7C
sub_813BF7C: @ 813BF7C
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	bl sub_813BADC
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BF7C

	.align 2, 0 @ Don't pad with nop.
