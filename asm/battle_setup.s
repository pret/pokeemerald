	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start task01_battle_start
task01_battle_start: @ 80B05F0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080B0614
	cmp r0, 0x1
	beq _080B062E
	b _080B0652
	.pool
_080B0614:
	bl c3_80A0DD8_is_running
	cmp r0, 0
	bne _080B0652
	ldrb r0, [r4, 0x2]
	bl sub_8145EF4
	bl sub_81BE72C
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080B0652
_080B062E:
	bl IsBattleTransitionDone
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B0652
	bl overworld_free_bg_tilemaps
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	bl prev_quest_postbuffer_cursor_backup_reset
	bl overworld_poison_timer_set
	adds r0, r5, 0
	bl DestroyTask
_080B0652:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task01_battle_start

	thumb_func_start task_add_01_battle_start
task_add_01_battle_start: @ 80B065C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =task01_battle_start
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xA]
	adds r0, r5, 0
	bl PlayMapChosenOrBattleBGM
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_add_01_battle_start

	thumb_func_start sub_80B0698
sub_80B0698: @ 80B0698
	push {lr}
	bl GetSafariZoneFlag
	cmp r0, 0
	beq _080B06A8
	bl sub_80B077C
	b _080B06AC
_080B06A8:
	bl sub_80B06BC
_080B06AC:
	pop {r0}
	bx r0
	thumb_func_end sub_80B0698

	thumb_func_start sub_80B06B0
sub_80B06B0: @ 80B06B0
	push {lr}
	bl sub_80B07B4
	pop {r0}
	bx r0
	thumb_func_end sub_80B06B0

	thumb_func_start sub_80B06BC
sub_80B06BC: @ 80B06BC
	push {r4,lr}
	bl ScriptContext2_Enable
	bl player_bitmagic
	bl sub_808BCF4
	ldr r1, =gMain
	ldr r0, =sub_80B0AF8
	str r0, [r1, 0x8]
	ldr r4, =gBattleTypeFlags
	movs r0, 0
	str r0, [r4]
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B06F2
	ldr r0, =0x0000400e
	movs r1, 0
	bl VarSet
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 14
	orrs r0, r1
	str r0, [r4]
_080B06F2:
	bl sub_80B0EC8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B06BC

	thumb_func_start sub_80B072C
sub_80B072C: @ 80B072C
	push {lr}
	bl ScriptContext2_Enable
	bl player_bitmagic
	bl sub_808BCF4
	ldr r1, =gMain
	ldr r0, =sub_80B0AF8
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0x80
	lsls r0, 3
	str r0, [r1]
	bl sub_80B0EC8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B072C

	thumb_func_start sub_80B077C
sub_80B077C: @ 80B077C
	push {lr}
	bl ScriptContext2_Enable
	bl player_bitmagic
	bl sub_808BCF4
	ldr r1, =gMain
	ldr r0, =sub_80FC190
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0x80
	str r0, [r1]
	bl sub_80B0EC8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B077C

	thumb_func_start sub_80B07B4
sub_80B07B4: @ 80B07B4
	push {lr}
	bl ScriptContext2_Enable
	bl player_bitmagic
	bl sub_808BCF4
	ldr r1, =gMain
	ldr r0, =sub_80B0AF8
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0x80
	lsls r0, 13
	str r0, [r1]
	bl sub_80B0EC8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B07B4

	thumb_func_start task_add_01_battle_start_with_music_and_stats
task_add_01_battle_start_with_music_and_stats: @ 80B0804
	push {lr}
	bl reads_trainer_data_byte1_byte0x18
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x9
	bl IncrementGameStat
	bl sub_80B1234
	pop {r0}
	bx r0
	thumb_func_end task_add_01_battle_start_with_music_and_stats

	thumb_func_start sub_80B0828
sub_80B0828: @ 80B0828
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B0846
	movs r0, 0xA
	bl sub_80B100C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	b _080B0856
_080B0846:
	movs r0, 0xB
	bl sub_80B100C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
_080B0856:
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x9
	bl IncrementGameStat
	bl sub_80B1234
	pop {r0}
	bx r0
	thumb_func_end sub_80B0828

	thumb_func_start sub_80B086C
sub_80B086C: @ 80B086C
	push {lr}
	ldr r0, =gEnemyParty
	movs r1, 0xC4
	lsls r1, 1
	movs r2, 0x5
	bl CreateMaleMon
	bl ScriptContext2_Enable
	ldr r1, =gMain
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0x80
	lsls r0, 2
	str r0, [r1]
	movs r0, 0x8
	movs r1, 0
	bl task_add_01_battle_start
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B086C

	thumb_func_start BattleSetup_StartScriptedWildBattle
BattleSetup_StartScriptedWildBattle: @ 80B08A8
	push {lr}
	bl ScriptContext2_Enable
	ldr r1, =gMain
	ldr r0, =sub_80B0B6C
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0
	str r0, [r1]
	bl sub_80B0EC8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r0}
	bx r0
	.pool
	thumb_func_end BattleSetup_StartScriptedWildBattle

	thumb_func_start sub_80B08EC
sub_80B08EC: @ 80B08EC
	push {lr}
	bl ScriptContext2_Enable
	ldr r1, =gMain
	ldr r0, =sub_80B0B6C
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0x80
	lsls r0, 6
	str r0, [r1]
	bl sub_80B0EC8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B08EC

	thumb_func_start sub_80B0934
sub_80B0934: @ 80B0934
	push {r4,lr}
	bl ScriptContext2_Enable
	ldr r1, =gMain
	ldr r0, =sub_80B0B6C
	str r0, [r1, 0x8]
	ldr r4, =gBattleTypeFlags
	movs r0, 0x80
	lsls r0, 6
	str r0, [r4]
	ldr r0, =gEnemyParty
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	movs r0, 0xCA
	lsls r0, 1
	cmp r1, r0
	beq _080B09B8
	cmp r1, r0
	bhi _080B0988
	cmp r1, 0x97
	beq _080B09F4
	cmp r1, 0x97
	bcc _080B099A
	cmp r1, 0xFA
	bhi _080B099A
	cmp r1, 0xF9
	bcc _080B099A
	ldr r1, =0x00000229
	b _080B09E6
	.pool
_080B0988:
	movs r0, 0xCB
	lsls r0, 1
	cmp r1, r0
	beq _080B09CE
	cmp r1, r0
	bcc _080B099A
	adds r0, 0x4
	cmp r1, r0
	beq _080B09E4
_080B099A:
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 21
	orrs r0, r1
	str r0, [r2]
	movs r1, 0xF0
	lsls r1, 1
	movs r0, 0x17
	bl task_add_01_battle_start
	b _080B09FE
	.pool
_080B09B8:
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 22
	orrs r0, r1
	str r0, [r4]
	movs r1, 0xF0
	lsls r1, 1
	movs r0, 0x16
	bl task_add_01_battle_start
	b _080B09FE
_080B09CE:
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 23
	orrs r0, r1
	str r0, [r4]
	movs r1, 0xEB
	lsls r1, 1
	movs r0, 0x18
	bl task_add_01_battle_start
	b _080B09FE
_080B09E4:
	ldr r1, =0x00000227
_080B09E6:
	movs r0, 0
	bl task_add_01_battle_start
	b _080B09FE
	.pool
_080B09F4:
	movs r1, 0xEC
	lsls r1, 1
	movs r0, 0xA
	bl task_add_01_battle_start
_080B09FE:
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B0934

	thumb_func_start sub_80B0A18
sub_80B0A18: @ 80B0A18
	push {lr}
	bl ScriptContext2_Enable
	ldr r1, =gMain
	ldr r0, =sub_80B0B6C
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0xC0
	lsls r0, 6
	str r0, [r1]
	ldr r0, =gGameVersion
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080B0A50
	movs r1, 0xF0
	lsls r1, 1
	movs r0, 0xB
	bl task_add_01_battle_start
	b _080B0A5A
	.pool
_080B0A50:
	movs r1, 0xF0
	lsls r1, 1
	movs r0, 0x6
	bl task_add_01_battle_start
_080B0A5A:
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r0}
	bx r0
	thumb_func_end sub_80B0A18

	thumb_func_start sub_80B0A74
sub_80B0A74: @ 80B0A74
	push {lr}
	bl ScriptContext2_Enable
	ldr r1, =gMain
	ldr r0, =sub_80B0B6C
	str r0, [r1, 0x8]
	ldr r1, =gBattleTypeFlags
	movs r0, 0xC0
	lsls r0, 7
	str r0, [r1]
	ldr r0, =gEnemyParty
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	movs r0, 0xC9
	lsls r0, 1
	cmp r1, r0
	beq _080B0ACC
	cmp r1, r0
	bgt _080B0ABC
	subs r0, 0x1
	cmp r1, r0
	beq _080B0AC8
	b _080B0AD4
	.pool
_080B0ABC:
	ldr r0, =0x00000193
	cmp r2, r0
	beq _080B0AD0
	b _080B0AD4
	.pool
_080B0AC8:
	movs r0, 0x15
	b _080B0AD6
_080B0ACC:
	movs r0, 0x13
	b _080B0AD6
_080B0AD0:
	movs r0, 0x14
	b _080B0AD6
_080B0AD4:
	movs r0, 0xA
_080B0AD6:
	ldr r1, =0x000001df
	bl task_add_01_battle_start
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B0A74

	thumb_func_start sub_80B0AF8
sub_80B0AF8: @ 80B0AF8
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x01000100
	mov r0, sp
	bl CpuSet
	movs r0, 0
	movs r1, 0x80
	bl ResetOamRange
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	bl battle_exit_is_player_defeat
	cmp r0, 0x1
	bne _080B0B4C
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080B0B4C
	bl InBattlePike
	lsls r0, 24
	cmp r0, 0
	bne _080B0B4C
	ldr r0, =c2_whiteout
	bl SetMainCallback2
	b _080B0B58
	.pool
_080B0B4C:
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF6F0
	str r0, [r1]
_080B0B58:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B0AF8

	thumb_func_start sub_80B0B6C
sub_80B0B6C: @ 80B0B6C
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x01000100
	mov r0, sp
	bl CpuSet
	movs r0, 0
	movs r1, 0x80
	bl ResetOamRange
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	bl battle_exit_is_player_defeat
	cmp r0, 0x1
	bne _080B0BC0
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B0BB4
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	b _080B0BC6
	.pool
_080B0BB4:
	ldr r0, =c2_whiteout
	bl SetMainCallback2
	b _080B0BC6
	.pool
_080B0BC0:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
_080B0BC6:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B0B6C

	thumb_func_start BattleSetup_GetTerrainId
BattleSetup_GetTerrainId: @ 80B0BD0
	push {r4,r5,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsTallGrass
	lsls r0, 24
	cmp r0, 0
	beq _080B0C06
	movs r0, 0
	b _080B0D1A
_080B0C06:
	adds r0, r4, 0
	bl MetatileBehavior_IsLongGrass
	lsls r0, 24
	cmp r0, 0
	beq _080B0C16
	movs r0, 0x1
	b _080B0D1A
_080B0C16:
	adds r0, r4, 0
	bl MetatileBehavior_IsSandOrDeepSand
	lsls r0, 24
	cmp r0, 0
	bne _080B0D18
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	subs r0, 0x1
	cmp r0, 0x8
	bhi _080B0C9C
	lsls r0, 2
	ldr r1, =_080B0C40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B0C40:
	.4byte _080B0C9C
	.4byte _080B0C9C
	.4byte _080B0C9C
	.4byte _080B0C64
	.4byte _080B0C88
	.4byte _080B0C8C
	.4byte _080B0C9C
	.4byte _080B0C74
	.4byte _080B0C74
_080B0C64:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_0B
	lsls r0, 24
	cmp r0, 0
	beq _080B0C78
_080B0C74:
	movs r0, 0x8
	b _080B0D1A
_080B0C78:
	adds r0, r4, 0
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _080B0CE0
	movs r0, 0x7
	b _080B0D1A
_080B0C88:
	movs r0, 0x3
	b _080B0D1A
_080B0C8C:
	lsls r0, r5, 24
	lsrs r0, 24
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _080B0CF2
	b _080B0D10
_080B0C9C:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsDeepOrOceanWater
	lsls r0, 24
	cmp r0, 0
	bne _080B0CF2
	adds r0, r4, 0
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _080B0CE0
	adds r0, r4, 0
	bl MetatileBehavior_IsMountain
	lsls r0, 24
	cmp r0, 0
	beq _080B0CC8
	movs r0, 0x6
	b _080B0D1A
_080B0CC8:
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _080B0CF6
	adds r0, r4, 0
	bl MetatileBehavior_GetBridgeSth
	lsls r0, 24
	cmp r0, 0
	beq _080B0CE4
_080B0CE0:
	movs r0, 0x5
	b _080B0D1A
_080B0CE4:
	adds r0, r4, 0
	bl MetatileBehavior_IsBridge
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B0CF6
_080B0CF2:
	movs r0, 0x4
	b _080B0D1A
_080B0CF6:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	movs r0, 0xE0
	lsls r0, 5
	cmp r1, r0
	beq _080B0D18
	bl sav1_get_weather_probably
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	beq _080B0D18
_080B0D10:
	movs r0, 0x9
	b _080B0D1A
	.pool
_080B0D18:
	movs r0, 0x2
_080B0D1A:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end BattleSetup_GetTerrainId

	thumb_func_start sub_80B0D24
sub_80B0D24: @ 80B0D24
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r4, r0, 16
	bl sav1_get_flash_used_on_map
	lsls r0, 24
	cmp r0, 0
	beq _080B0D54
	movs r0, 0x2
	b _080B0D7E
_080B0D54:
	lsls r0, r4, 24
	lsrs r0, 24
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _080B0D7C
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x4
	beq _080B0D78
	cmp r0, 0x5
	beq _080B0D7C
	movs r0, 0
	b _080B0D7E
	.pool
_080B0D78:
	movs r0, 0x1
	b _080B0D7E
_080B0D7C:
	movs r0, 0x3
_080B0D7E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B0D24

	thumb_func_start sub_80B0D88
sub_80B0D88: @ 80B0D88
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	movs r6, 0
_080B0D92:
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	adds r1, r0, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _080B0DD6
	cmp r1, 0
	beq _080B0DD6
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080B0DD6
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	adds r0, r7, r0
	lsls r0, 24
	lsrs r7, r0, 24
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _080B0DDC
_080B0DD6:
	adds r6, 0x1
	cmp r6, 0x5
	ble _080B0D92
_080B0DDC:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B0D88

	thumb_func_start reads_trainer_data_byte0
reads_trainer_data_byte0: @ 80B0DE8
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r5, =gTrainers
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r5
	adds r0, r2, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, r4
	bcs _080B0E08
	adds r4, r0, 0
_080B0E08:
	movs r3, 0
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _080B0E50
	cmp r0, 0x1
	bgt _080B0E20
	cmp r0, 0
	beq _080B0E2A
	b _080B0EC0
	.pool
_080B0E20:
	cmp r0, 0x2
	beq _080B0E76
	cmp r0, 0x3
	beq _080B0E9C
	b _080B0EC0
_080B0E2A:
	adds r0, r5, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	movs r2, 0
	cmp r3, r4
	bcs _080B0EC0
_080B0E38:
	lsls r0, r2, 3
	adds r0, r1
	ldrb r0, [r0, 0x2]
	adds r0, r3, r0
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r4
	bcc _080B0E38
	b _080B0EC0
_080B0E50:
	adds r0, r5, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	movs r2, 0
	cmp r3, r4
	bcs _080B0EC0
_080B0E5E:
	lsls r0, r2, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	adds r0, r3, r0
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r4
	bcc _080B0E5E
	b _080B0EC0
_080B0E76:
	adds r0, r5, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	movs r2, 0
	cmp r3, r4
	bcs _080B0EC0
_080B0E84:
	lsls r0, r2, 3
	adds r0, r1
	ldrb r0, [r0, 0x2]
	adds r0, r3, r0
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r4
	bcc _080B0E84
	b _080B0EC0
_080B0E9C:
	adds r0, r5, 0
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	movs r2, 0
	cmp r3, r4
	bcs _080B0EC0
_080B0EAA:
	lsls r0, r2, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	adds r0, r3, r0
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r4
	bcc _080B0EAA
_080B0EC0:
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end reads_trainer_data_byte0

	thumb_func_start sub_80B0EC8
sub_80B0EC8: @ 80B0EC8
	push {r4-r6,lr}
	bl sub_80B0D24
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	ldr r0, =gEnemyParty
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_80B0D88
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcs _080B0F10
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B0F04
	movs r0, 0
	b _080B0F2E
	.pool
_080B0F04:
	ldr r0, =gUnknown_0854FE88
	lsls r1, r5, 1
	b _080B0F20
	.pool
_080B0F10:
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080B0F2C
	ldr r0, =gUnknown_0854FE88
	lsls r1, r6, 1
	adds r0, 0x1
_080B0F20:
	adds r1, r0
	ldrb r0, [r1]
	b _080B0F2E
	.pool
_080B0F2C:
	movs r0, 0xA
_080B0F2E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B0EC8

	thumb_func_start reads_trainer_data_byte1_byte0x18
reads_trainer_data_byte1_byte0x18: @ 80B0F34
	push {r4-r6,lr}
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r1, [r4]
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	beq _080B0F98
	ldr r1, =gTrainers
	ldrh r2, [r4]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x1]
	cmp r1, 0x1F
	bne _080B0F94
	adds r1, r2, 0
	ldr r0, =0x00000105
	cmp r1, r0
	bne _080B0F6C
	movs r0, 0xC
	b _080B1000
	.pool
_080B0F6C:
	movs r0, 0x83
	lsls r0, 1
	cmp r1, r0
	bne _080B0F78
	movs r0, 0xD
	b _080B1000
_080B0F78:
	ldr r0, =0x00000107
	cmp r1, r0
	bne _080B0F88
	movs r0, 0xE
	b _080B1000
	.pool
_080B0F88:
	movs r0, 0x84
	lsls r0, 1
	cmp r1, r0
	bne _080B0F98
	movs r0, 0xF
	b _080B1000
_080B0F94:
	cmp r1, 0x26
	bne _080B0F9C
_080B0F98:
	movs r0, 0x10
	b _080B1000
_080B0F9C:
	cmp r1, 0x9
	beq _080B0FA8
	cmp r1, 0x35
	beq _080B0FA8
	cmp r1, 0x31
	bne _080B0FAC
_080B0FA8:
	movs r0, 0x12
	b _080B1000
_080B0FAC:
	cmp r1, 0x3
	beq _080B0FB8
	cmp r1, 0xD
	beq _080B0FB8
	cmp r1, 0xB
	bne _080B0FBC
_080B0FB8:
	movs r0, 0x11
	b _080B1000
_080B0FBC:
	ldrb r0, [r0, 0x18]
	movs r5, 0x1
	cmp r0, 0x1
	bne _080B0FC6
	movs r5, 0x2
_080B0FC6:
	bl sub_80B0D24
	lsls r0, 24
	lsrs r6, r0, 24
	ldrh r0, [r4]
	adds r1, r5, 0
	bl reads_trainer_data_byte0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80B0D88
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _080B0FF8
	ldr r0, =gUnknown_0854FE90
	lsls r1, r6, 1
	adds r0, 0x1
	b _080B0FFC
	.pool
_080B0FF8:
	ldr r0, =gUnknown_0854FE90
	lsls r1, r6, 1
_080B0FFC:
	adds r1, r0
	ldrb r0, [r1]
_080B1000:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end reads_trainer_data_byte1_byte0x18

	thumb_func_start sub_80B100C
sub_80B100C: @ 80B100C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gEnemyParty
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_80B0D88
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcs _080B1090
	cmp r5, 0xA
	beq _080B1048
	cmp r5, 0xA
	bgt _080B1040
	cmp r5, 0x3
	beq _080B105C
	b _080B106C
	.pool
_080B1040:
	cmp r5, 0xD
	bgt _080B106C
	movs r0, 0x4
	b _080B1120
_080B1048:
	ldr r4, =gUnknown_0854FEA4
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	b _080B1114
	.pool
_080B105C:
	ldr r4, =gUnknown_0854FEA7
	bl Random
	ands r5, r0
	lsls r0, r5, 16
	b _080B111A
	.pool
_080B106C:
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	beq _080B10EC
	ldr r4, =gUnknown_0854FE98
	bl Random
	lsls r0, 16
	lsrs r0, 16
	b _080B1112
	.pool
_080B1090:
	cmp r5, 0xA
	beq _080B10A6
	cmp r5, 0xA
	bgt _080B109E
	cmp r5, 0x3
	beq _080B10B8
	b _080B10C8
_080B109E:
	cmp r5, 0xD
	bgt _080B10C8
	movs r0, 0x3
	b _080B1120
_080B10A6:
	ldr r4, =gUnknown_0854FEA4
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	b _080B1114
	.pool
_080B10B8:
	ldr r4, =gUnknown_0854FEA7
	bl Random
	ands r5, r0
	lsls r0, r5, 16
	b _080B111A
	.pool
_080B10C8:
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	beq _080B10EC
	ldr r4, =gUnknown_0854FE98
	bl Random
	lsls r0, 16
	lsrs r0, 16
	b _080B1112
	.pool
_080B10EC:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r2, r0, 2
	ldr r3, =0x00000cb4
	adds r1, r3
	adds r2, r1, r2
	lsls r0, 1
	adds r0, 0x1
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_0854FE98
_080B1112:
	movs r1, 0xC
_080B1114:
	bl __umodsi3
	lsls r0, 16
_080B111A:
	lsrs r0, 16
	adds r0, r4
	ldrb r0, [r0]
_080B1120:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B100C

	thumb_func_start sub_80B1138
sub_80B1138: @ 80B1138
	push {lr}
	ldr r0, =CB2_ChooseStarter
	bl SetMainCallback2
	ldr r1, =gMain
	ldr r0, =sub_80B1158
	str r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1138

	thumb_func_start sub_80B1158
sub_80B1158: @ 80B1158
	push {lr}
	sub sp, 0x8
	ldr r0, =0x00004023
	bl GetVarPointer
	ldr r2, =gScriptResult
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r0, [r2]
	bl GetStarterPokemon
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0x5
	movs r2, 0
	movs r3, 0
	bl ScriptGiveMon
	bl ResetTasks
	bl PlayBattleBGM
	ldr r0, =sub_80B11A8
	bl SetMainCallback2
	movs r0, 0
	bl sub_8145F10
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1158

	thumb_func_start sub_80B11A8
sub_80B11A8: @ 80B11A8
	push {lr}
	bl UpdatePaletteFade
	bl RunTasks
	bl IsBattleTransitionDone
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B11F0
	ldr r1, =gBattleTypeFlags
	movs r0, 0x10
	str r0, [r1]
	ldr r1, =gMain
	ldr r0, =sub_80B1204
	str r0, [r1, 0x8]
	bl FreeAllWindowBuffers
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	bl prev_quest_postbuffer_cursor_backup_reset
	bl overworld_poison_timer_set
	movs r0, 0x7
	bl IncrementGameStat
	movs r0, 0x8
	bl IncrementGameStat
	bl sub_80EECC8
	bl sub_80B1218
_080B11F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B11A8

	thumb_func_start sub_80B1204
sub_80B1204: @ 80B1204
	push {lr}
	bl sav1_reset_battle_music_maybe
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1204

	thumb_func_start sub_80B1218
sub_80B1218: @ 80B1218
	push {lr}
	movs r0, 0x8
	bl GetGameStat
	movs r1, 0x3C
	bl __umodsi3
	cmp r0, 0
	bne _080B122E
	bl sub_81DA57C
_080B122E:
	pop {r0}
	bx r0
	thumb_func_end sub_80B1218

	thumb_func_start sub_80B1234
sub_80B1234: @ 80B1234
	push {lr}
	movs r0, 0x9
	bl GetGameStat
	movs r1, 0x14
	bl __umodsi3
	cmp r0, 0
	bne _080B124A
	bl sub_81DA57C
_080B124A:
	pop {r0}
	bx r0
	thumb_func_end sub_80B1234

	thumb_func_start TrainerBattleLoadArg32
@ u32 TrainerBattleLoadArg32(u8 *arg)
TrainerBattleLoadArg32: @ 80B1250
	adds r2, r0, 0
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	orrs r0, r1
	ldrb r1, [r2, 0x2]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 24
	orrs r0, r1
	bx lr
	thumb_func_end TrainerBattleLoadArg32

	thumb_func_start TrainerBattleLoadArg16
@ u16 TrainerBattleLoadArg16(u8 *arg)
TrainerBattleLoadArg16: @ 80B1268
	adds r1, r0, 0
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	lsls r1, 8
	orrs r0, r1
	bx lr
	thumb_func_end TrainerBattleLoadArg16

	thumb_func_start TrainerBattleLoadArg8
@ u8 TrainerBattleLoadArg8(u8 *arg)
TrainerBattleLoadArg8: @ 80B1274
	ldrb r0, [r0]
	bx lr
	thumb_func_end TrainerBattleLoadArg8

	thumb_func_start trainerflag_opponent
trainerflag_opponent: @ 80B1278
	ldr r1, =gTrainerBattleOpponent_A
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r2, 0
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end trainerflag_opponent

	thumb_func_start sub_80B1290
sub_80B1290: @ 80B1290
	ldr r1, =gTrainerBattleOpponent_B
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r2, 0
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_80B1290

	thumb_func_start battle_exit_is_player_defeat
battle_exit_is_player_defeat: @ 80B12A8
	push {lr}
	subs r0, 0x1
	cmp r0, 0x6
	bhi _080B12E0
	lsls r0, 2
	ldr r1, =_080B12C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B12C0:
	.4byte _080B12E0
	.4byte _080B12DC
	.4byte _080B12DC
	.4byte _080B12E0
	.4byte _080B12E0
	.4byte _080B12E0
	.4byte _080B12E0
_080B12DC:
	movs r0, 0x1
	b _080B12E2
_080B12E0:
	movs r0, 0
_080B12E2:
	pop {r1}
	bx r1
	thumb_func_end battle_exit_is_player_defeat

	thumb_func_start ResetTrainerOpponentIds
ResetTrainerOpponentIds: @ 80B12E8
	ldr r0, =gTrainerBattleOpponent_A
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gTrainerBattleOpponent_B
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end ResetTrainerOpponentIds

	thumb_func_start InitTrainerBattleVariables
@ void InitTrainerBattleVariables()
InitTrainerBattleVariables: @ 80B12FC
	push {lr}
	ldr r0, =gUnknown_02038BC8
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02038BFC
	ldrb r1, [r0]
	cmp r1, 0
	bne _080B132C
	ldr r0, =gUnknown_02038BD4
	str r1, [r0]
	ldr r0, =gUnknown_02038BDC
	str r1, [r0]
	ldr r0, =gUnknown_02038BF0
	b _080B1338
	.pool
_080B132C:
	ldr r0, =gUnknown_02038BD8
	movs r1, 0
	str r1, [r0]
	ldr r0, =gUnknown_02038BE0
	str r1, [r0]
	ldr r0, =gUnknown_02038BF4
_080B1338:
	str r1, [r0]
	ldr r1, =gUnknown_02038BD0
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gUnknown_02038BE4
	movs r1, 0
	str r1, [r0]
	ldr r0, =gUnknown_02038BE8
	str r1, [r0]
	ldr r0, =gUnknown_02038BEC
	str r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitTrainerBattleVariables

	thumb_func_start TrainerBattleLoadArgs
@ void TrainerBattleLoadArgs(struct TrainerBattleArgSpec *argSpecs, u8 *args)
TrainerBattleLoadArgs: @ 80B1370
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
_080B1376:
	ldrb r0, [r4, 0x4]
	cmp r0, 0x6
	bhi _080B13E8
	lsls r0, 2
	ldr r1, =_080B138C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B138C:
	.4byte _080B13A8
	.4byte _080B13B6
	.4byte _080B13C4
	.4byte _080B13D2
	.4byte _080B13DA
	.4byte _080B13E2
	.4byte _080B13EC
_080B13A8:
	adds r0, r5, 0
	bl TrainerBattleLoadArg8
	ldr r1, [r4]
	strb r0, [r1]
	adds r5, 0x1
	b _080B13E8
_080B13B6:
	adds r0, r5, 0
	bl TrainerBattleLoadArg16
	ldr r1, [r4]
	strh r0, [r1]
	adds r5, 0x2
	b _080B13E8
_080B13C4:
	adds r0, r5, 0
	bl TrainerBattleLoadArg32
	ldr r1, [r4]
	str r0, [r1]
	adds r5, 0x4
	b _080B13E8
_080B13D2:
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1]
	b _080B13E8
_080B13DA:
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1]
	b _080B13E8
_080B13E2:
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1]
_080B13E8:
	adds r4, 0x8
	b _080B1376
_080B13EC:
	ldr r0, [r4]
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end TrainerBattleLoadArgs

	thumb_func_start battle_80801F0
battle_80801F0: @ 80B13F8
	push {lr}
	ldr r0, =gUnknown_02038BD0
	ldrh r1, [r0]
	cmp r1, 0
	beq _080B141A
	ldr r0, =gScriptLastTalked
	strh r1, [r0]
	lsls r0, r1, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl GetFieldObjectIdByLocalIdAndMap
	ldr r1, =gSelectedMapObject
	strb r0, [r1]
_080B141A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end battle_80801F0

	thumb_func_start BattleSetup_ConfigureTrainerBattle
@ u8 *BattleSetup_ConfigureTrainerBattle(u8 *args)
BattleSetup_ConfigureTrainerBattle: @ 80B1430
	push {r4,r5,lr}
	adds r5, r0, 0
	bl InitTrainerBattleVariables
	ldr r4, =gUnknown_02038BC8
	adds r0, r5, 0
	bl TrainerBattleLoadArg8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldrh r0, [r4]
	subs r0, 0x1
	cmp r0, 0xB
	bls _080B1450
	b _080B15F4
_080B1450:
	lsls r0, 2
	ldr r1, =_080B1464
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B1464:
	.4byte _080B14CC
	.4byte _080B14B0
	.4byte _080B1494
	.4byte _080B14A8
	.4byte _080B1514
	.4byte _080B14D4
	.4byte _080B14EC
	.4byte _080B14D4
	.4byte _080B153C
	.4byte _080B1590
	.4byte _080B1598
	.4byte _080B15A8
_080B1494:
	ldr r0, =gUnknown_0854FF84
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	ldr r0, =gUnknown_082713C2
	b _080B161E
	.pool
_080B14A8:
	ldr r0, =gUnknown_0854FF3C
	b _080B14D6
	.pool
_080B14B0:
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B14C4
	ldr r0, =gUnknown_0854FEF4
	b _080B15FE
	.pool
_080B14C4:
	ldr r0, =gUnknown_0855005C
	b _080B1616
	.pool
_080B14CC:
	ldr r0, =gUnknown_0854FEF4
	b _080B15FE
	.pool
_080B14D4:
	ldr r0, =gUnknown_0854FFCC
_080B14D6:
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	bl battle_80801F0
	ldr r0, =gUnknown_0827138A
	b _080B161E
	.pool
_080B14EC:
	ldr r0, =gUnknown_0854FF3C
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	bl battle_80801F0
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r0, [r4]
	bl sub_80B2234
	strh r0, [r4]
	ldr r0, =gUnknown_082713F8
	b _080B161E
	.pool
_080B1514:
	ldr r0, =gUnknown_0854FEAC
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	bl battle_80801F0
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r0, [r4]
	bl sub_80B2234
	strh r0, [r4]
	ldr r0, =gUnknown_082713D1
	b _080B161E
	.pool
_080B153C:
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B156C
	ldr r0, =gUnknown_0854FEAC
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	bl battle_80801F0
	ldr r0, =gScriptLastTalked
	ldrb r0, [r0]
	bl sub_81A9AA8
	ldr r1, =gTrainerBattleOpponent_A
	b _080B157E
	.pool
_080B156C:
	ldr r0, =gUnknown_08550014
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	ldr r0, =gScriptLastTalked
	ldrb r0, [r0]
	bl sub_81A9AA8
_080B157C:
	ldr r1, =gTrainerBattleOpponent_B
_080B157E:
	strh r0, [r1]
	b _080B161C
	.pool
_080B1590:
	ldr r0, =gUnknown_0854FEAC
	b _080B159A
	.pool
_080B1598:
	ldr r0, =gUnknown_08550014
_080B159A:
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	movs r0, 0
	b _080B161E
	.pool
_080B15A8:
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B15D8
	ldr r0, =gUnknown_0854FEAC
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	bl battle_80801F0
	ldr r0, =gScriptLastTalked
	ldrb r0, [r0]
	bl battle_init
	ldr r1, =gTrainerBattleOpponent_A
	b _080B157E
	.pool
_080B15D8:
	ldr r0, =gUnknown_08550014
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	ldr r0, =gScriptLastTalked
	ldrb r0, [r0]
	bl battle_init
	b _080B157C
	.pool
_080B15F4:
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B1614
	ldr r0, =gUnknown_0854FEAC
_080B15FE:
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	bl battle_80801F0
	b _080B161C
	.pool
_080B1614:
	ldr r0, =gUnknown_08550014
_080B1616:
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
_080B161C:
	ldr r0, =gUnknown_08271362
_080B161E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end BattleSetup_ConfigureTrainerBattle

	thumb_func_start SingleTrainerWantsBattle
@ void SingleTrainerWantsBattle(u8 trainerFieldObjectId, u8 *trainerScript)
SingleTrainerWantsBattle: @ 80B162C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSelectedMapObject
	strb r0, [r2]
	ldr r4, =gScriptLastTalked
	ldr r3, =gMapObjects
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r0, [r2, 0x8]
	strh r0, [r4]
	adds r1, 0x1
	adds r0, r1, 0
	bl BattleSetup_ConfigureTrainerBattle
	ldr r0, =gUnknown_08271354
	bl ScriptContext1_SetupScript
	bl ScriptContext2_Enable
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SingleTrainerWantsBattle

	thumb_func_start TwoTrainersWantBattle
@ void TwoTrainersWantBattle(u8 trainerFieldObjectId, u8 *trainerScript)
TwoTrainersWantBattle: @ 80B1670
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSelectedMapObject
	strb r0, [r2]
	ldr r4, =gScriptLastTalked
	ldr r3, =gMapObjects
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r0, [r2, 0x8]
	strh r0, [r4]
	adds r1, 0x1
	adds r0, r1, 0
	bl BattleSetup_ConfigureTrainerBattle
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TwoTrainersWantBattle

	thumb_func_start TwoTrainersWantBattleExecuteScript
@ void TwoTrainersWantBattleExecuteScript()
TwoTrainersWantBattleExecuteScript: @ 80B16A4
	push {lr}
	ldr r0, =gUnknown_08271354
	bl ScriptContext1_SetupScript
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end TwoTrainersWantBattleExecuteScript

	thumb_func_start GetTrainerFlagFromScriptPointer
@ u8 GetTrainerFlagFromScriptPointer(u8 *scriptPointer)
GetTrainerFlagFromScriptPointer: @ 80B16B8
	push {lr}
	adds r0, 0x2
	bl TrainerBattleLoadArg16
	lsls r0, 16
	movs r1, 0xA0
	lsls r1, 19
	adds r0, r1
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end GetTrainerFlagFromScriptPointer

	thumb_func_start sub_80B16D8
sub_80B16D8: @ 80B16D8
	push {r4,lr}
	ldr r0, =gSelectedMapObject
	ldrb r0, [r0]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gMapObjects
	adds r4, r0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl npc_running_behaviour_by_direction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl npc_set_running_behaviour_etc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B16D8

	thumb_func_start sub_80B170C
sub_80B170C: @ 80B170C
	ldr r0, =gUnknown_02038BC8
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80B170C

	thumb_func_start check_trainer_flag
@ pokescrcmd
check_trainer_flag: @ 80B1718
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B1734
	ldr r0, =gSelectedMapObject
	ldrb r0, [r0]
	bl GetBattlePyramidTrainerFlag
	b _080B1752
	.pool
_080B1734:
	bl InTrainerHill
	cmp r0, 0
	bne _080B174A
	bl trainerflag_opponent
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	b _080B1752
_080B174A:
	ldr r0, =gSelectedMapObject
	ldrb r0, [r0]
	bl GetTrainerHillTrainerFlag
_080B1752:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end check_trainer_flag

	thumb_func_start rom_npc_set_flag_for_script_id
rom_npc_set_flag_for_script_id: @ 80B1760
	push {lr}
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	cmp r0, 0
	beq _080B1776
	bl sub_80B1290
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
_080B1776:
	bl trainerflag_opponent
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end rom_npc_set_flag_for_script_id

	thumb_func_start sub_80B178C
sub_80B178C: @ 80B178C
	push {lr}
	bl trainerflag_opponent
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
	pop {r0}
	bx r0
	thumb_func_end sub_80B178C

	thumb_func_start HasTrainerAlreadyBeenFought
HasTrainerAlreadyBeenFought: @ 80B17A0
	push {lr}
	lsls r0, 16
	movs r1, 0xA0
	lsls r1, 19
	adds r0, r1
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end HasTrainerAlreadyBeenFought

	thumb_func_start trainer_flag_set
trainer_flag_set: @ 80B17B8
	push {lr}
	lsls r0, 16
	movs r1, 0xA0
	lsls r1, 19
	adds r0, r1
	lsrs r0, 16
	bl FlagSet
	pop {r0}
	bx r0
	thumb_func_end trainer_flag_set

	thumb_func_start trainer_flag_clear
trainer_flag_clear: @ 80B17CC
	push {lr}
	lsls r0, 16
	movs r1, 0xA0
	lsls r1, 19
	adds r0, r1
	lsrs r0, 16
	bl FlagClear
	pop {r0}
	bx r0
	thumb_func_end trainer_flag_clear

	thumb_func_start BattleSetup_StartTrainerBattle
BattleSetup_StartTrainerBattle: @ 80B17E0
	push {r4,lr}
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080B17FC
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x00008009
	b _080B1800
	.pool
_080B17FC:
	ldr r1, =gBattleTypeFlags
	movs r0, 0x8
_080B1800:
	str r0, [r1]
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B1884
	ldr r0, =0x0000400e
	movs r1, 0
	bl VarSet
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 14
	orrs r0, r1
	str r0, [r2]
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080B1864
	movs r0, 0x1
	bl sub_816306C
	ldr r4, =gEnemyParty + 100
	adds r0, r4, 0
	bl ZeroMonData
	adds r0, r4, 0
	adds r0, 0x64
	bl ZeroMonData
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	bl ZeroMonData
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	bl ZeroMonData
	b _080B187A
	.pool
_080B1864:
	movs r0, 0x1
	bl sub_8163048
	ldr r4, =gEnemyParty + 100
	adds r0, r4, 0
	bl ZeroMonData
	adds r4, 0x64
	adds r0, r4, 0
	bl ZeroMonData
_080B187A:
	bl sub_81A9B04
	b _080B18B8
	.pool
_080B1884:
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _080B18B8
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 19
	orrs r0, r1
	str r0, [r2]
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080B18B0
	bl sub_81D639C
	b _080B18B4
	.pool
_080B18B0:
	bl sub_81D6384
_080B18B4:
	bl sub_81D61E8
_080B18B8:
	ldr r1, =gUnknown_02038BF9
	ldr r2, =gUnknown_030060A8
	ldrb r0, [r2]
	strb r0, [r1]
	movs r1, 0
	strb r1, [r2]
	ldr r0, =gUnknown_02038BF8
	strb r1, [r0]
	ldr r1, =gUnknown_03006080
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gMain
	ldr r0, =sub_80B1918
	str r0, [r1, 0x8]
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080B18E8
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _080B1908
_080B18E8:
	bl sub_80B0828
	b _080B190C
	.pool
_080B1908:
	bl task_add_01_battle_start_with_music_and_stats
_080B190C:
	bl ScriptContext1_Stop
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end BattleSetup_StartTrainerBattle

	thumb_func_start sub_80B1918
sub_80B1918: @ 80B1918
	push {lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	beq _080B1946
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	bl battle_exit_is_player_defeat
	cmp r0, 0x1
	bne _080B1968
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080B1946
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _080B195C
_080B1946:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	b _080B198A
	.pool
_080B195C:
	ldr r0, =c2_whiteout
	bl SetMainCallback2
	b _080B198A
	.pool
_080B1968:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080B198A
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	bne _080B198A
	bl sub_80B20BC
	bl rom_npc_set_flag_for_script_id
_080B198A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1918

	thumb_func_start sub_80B1994
sub_80B1994: @ 80B1994
	push {lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	bne _080B19B4
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	b _080B19E2
	.pool
_080B19B4:
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	bl battle_exit_is_player_defeat
	cmp r0, 0x1
	bne _080B19D0
	ldr r0, =c2_whiteout
	bl SetMainCallback2
	b _080B19E2
	.pool
_080B19D0:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	bl sub_80B20BC
	bl rom_npc_set_flag_for_script_id
	bl sub_80B22BC
_080B19E2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1994

	thumb_func_start sub_80B19EC
sub_80B19EC: @ 80B19EC
	push {lr}
	ldr r1, =gBattleTypeFlags
	movs r0, 0x8
	str r0, [r1]
	ldr r1, =gMain
	ldr r0, =sub_80B1994
	str r0, [r1, 0x8]
	bl task_add_01_battle_start_with_music_and_stats
	bl ScriptContext1_Stop
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B19EC

	thumb_func_start sub_80B1A14
sub_80B1A14: @ 80B1A14
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B1A7C
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _080B1A44
	ldr r0, =gScriptLastTalked
	ldrb r0, [r0]
	bl sub_81A9AA8
	lsls r0, 16
	lsrs r0, 16
	bl sub_81A9EDC
	b _080B1AD8
	.pool
_080B1A44:
	ldr r3, =gMapObjects
	ldr r2, =gUnknown_03006090
	ldr r0, =gUnknown_02038BFC
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x8]
	bl sub_81A9AA8
	lsls r0, 16
	lsrs r0, 16
	bl sub_81A9EDC
	b _080B1AD8
	.pool
_080B1A7C:
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _080B1AEC
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _080B1AAC
	ldr r0, =gScriptLastTalked
	ldrb r0, [r0]
	bl battle_init
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x2
	bl sub_81D572C
	b _080B1AD8
	.pool
_080B1AAC:
	ldr r3, =gMapObjects
	ldr r2, =gUnknown_03006090
	ldr r0, =gUnknown_02038BFC
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x8]
	bl battle_init
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x2
	bl sub_81D572C
_080B1AD8:
	bl sub_80982B8
	b _080B1AF4
	.pool
_080B1AEC:
	bl sub_80B1C7C
	bl ShowFieldMessage
_080B1AF4:
	pop {r0}
	bx r0
	thumb_func_end sub_80B1A14

	thumb_func_start BattleSetup_GetScriptAddrAfterBattle
BattleSetup_GetScriptAddrAfterBattle: @ 80B1AF8
	push {lr}
	ldr r0, =gUnknown_02038BEC
	ldr r0, [r0]
	cmp r0, 0
	bne _080B1B04
	ldr r0, =gUnknown_082C8436
_080B1B04:
	pop {r1}
	bx r1
	.pool
	thumb_func_end BattleSetup_GetScriptAddrAfterBattle

	thumb_func_start BattleSetup_GetTrainerPostBattleScript
BattleSetup_GetTrainerPostBattleScript: @ 80B1B10
	push {lr}
	ldr r1, =gUnknown_02038BF8
	ldrb r2, [r1]
	cmp r2, 0
	beq _080B1B3C
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gUnknown_02038BF4
	ldr r2, [r0]
	cmp r2, 0
	beq _080B1B54
	ldr r1, =gUnknown_03006080
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r2, 0
	b _080B1B56
	.pool
_080B1B3C:
	ldr r0, =gUnknown_02038BF0
	ldr r1, [r0]
	cmp r1, 0
	beq _080B1B54
	ldr r0, =gUnknown_03006080
	strh r2, [r0]
	adds r0, r1, 0
	b _080B1B56
	.pool
_080B1B54:
	ldr r0, =gUnknown_082742E6
_080B1B56:
	pop {r1}
	bx r1
	.pool
	thumb_func_end BattleSetup_GetTrainerPostBattleScript

	thumb_func_start special_trainer_unable_to_battle
special_trainer_unable_to_battle: @ 80B1B60
	push {lr}
	bl sub_80B1D18
	bl ShowFieldMessage
	pop {r0}
	bx r0
	thumb_func_end special_trainer_unable_to_battle

	thumb_func_start SetUpTrainerEncounterMusic
@ void SetUpTrainerEncounterMusic()
SetUpTrainerEncounterMusic: @ 80B1B70
	push {lr}
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B1B88
	ldr r0, =gTrainerBattleOpponent_A
	b _080B1B8A
	.pool
_080B1B88:
	ldr r0, =gTrainerBattleOpponent_B
_080B1B8A:
	ldrh r1, [r0]
	ldr r0, =gUnknown_02038BC8
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080B1C62
	cmp r0, 0x8
	beq _080B1C62
	adds r0, r1, 0
	bl GetTrainerEncounterMusicId
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD
	bhi _080B1C5C
	lsls r0, 2
	ldr r1, =_080B1BBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B1BBC:
	.4byte _080B1BF4
	.4byte _080B1BFA
	.4byte _080B1C04
	.4byte _080B1C5C
	.4byte _080B1C0C
	.4byte _080B1C12
	.4byte _080B1C1C
	.4byte _080B1C24
	.4byte _080B1C2C
	.4byte _080B1C34
	.4byte _080B1C3C
	.4byte _080B1C42
	.4byte _080B1C4C
	.4byte _080B1C54
_080B1BF4:
	movs r0, 0xBE
	lsls r0, 1
	b _080B1C5E
_080B1BFA:
	ldr r0, =0x00000197
	b _080B1C5E
	.pool
_080B1C04:
	ldr r0, =0x0000017b
	b _080B1C5E
	.pool
_080B1C0C:
	movs r0, 0xD0
	lsls r0, 1
	b _080B1C5E
_080B1C12:
	ldr r0, =0x000001a1
	b _080B1C5E
	.pool
_080B1C1C:
	ldr r0, =0x000001a3
	b _080B1C5E
	.pool
_080B1C24:
	ldr r0, =0x000001b9
	b _080B1C5E
	.pool
_080B1C2C:
	ldr r0, =0x00000181
	b _080B1C5E
	.pool
_080B1C34:
	ldr r0, =0x000001c1
	b _080B1C5E
	.pool
_080B1C3C:
	movs r0, 0xE1
	lsls r0, 1
	b _080B1C5E
_080B1C42:
	ldr r0, =0x000001c3
	b _080B1C5E
	.pool
_080B1C4C:
	ldr r0, =0x000001c5
	b _080B1C5E
	.pool
_080B1C54:
	ldr r0, =0x0000018d
	b _080B1C5E
	.pool
_080B1C5C:
	ldr r0, =0x000001a7
_080B1C5E:
	bl PlayNewMapMusic
_080B1C62:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpTrainerEncounterMusic

	thumb_func_start ReturnEmptyStringIfNull
@ u8 *ReturnEmptyStringIfNull(u8 *str)
ReturnEmptyStringIfNull: @ 80B1C6C
	push {lr}
	cmp r0, 0
	bne _080B1C74
	ldr r0, =gText_EmptyString2
_080B1C74:
	pop {r1}
	bx r1
	.pool
	thumb_func_end ReturnEmptyStringIfNull

	thumb_func_start sub_80B1C7C
sub_80B1C7C: @ 80B1C7C
	push {lr}
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B1C94
	ldr r0, =gUnknown_02038BD8
	b _080B1C96
	.pool
_080B1C94:
	ldr r0, =gUnknown_02038BD4
_080B1C96:
	ldr r0, [r0]
	bl ReturnEmptyStringIfNull
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B1C7C

	thumb_func_start GetTrainer1LoseText
GetTrainer1LoseText: @ 80B1CA4
	push {r4,lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	bne _080B1CBC
	bl sub_80EA250
	b _080B1CC0
	.pool
_080B1CBC:
	ldr r0, =gUnknown_02038BDC
	ldr r0, [r0]
_080B1CC0:
	ldr r4, =gStringVar4
	bl ReturnEmptyStringIfNull
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTrainer1LoseText

	thumb_func_start GetTrainer2LoseText
GetTrainer2LoseText: @ 80B1CE0
	push {r4,lr}
	ldr r4, =gStringVar4
	ldr r0, =gUnknown_02038BE0
	ldr r0, [r0]
	bl ReturnEmptyStringIfNull
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTrainer2LoseText

	thumb_func_start sub_80B1D04
sub_80B1D04: @ 80B1D04
	push {lr}
	ldr r0, =gUnknown_02038BE4
	ldr r0, [r0]
	bl ReturnEmptyStringIfNull
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B1D04

	thumb_func_start sub_80B1D18
sub_80B1D18: @ 80B1D18
	push {lr}
	ldr r0, =gUnknown_02038BE8
	ldr r0, [r0]
	bl ReturnEmptyStringIfNull
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B1D18

	thumb_func_start sub_80B1D2C
sub_80B1D2C: @ 80B1D2C
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	movs r3, 0
	adds r2, r0, 0
_080B1D36:
	ldrh r0, [r2]
	cmp r0, r1
	bne _080B1D40
	adds r0, r3, 0
	b _080B1D4C
_080B1D40:
	adds r2, 0x10
	adds r3, 0x1
	cmp r3, 0x4D
	ble _080B1D36
	movs r0, 0x1
	negs r0, r0
_080B1D4C:
	pop {r1}
	bx r1
	thumb_func_end sub_80B1D2C

	thumb_func_start sub_80B1D50
sub_80B1D50: @ 80B1D50
	push {r4,r5,lr}
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
	adds r2, r0, 0
_080B1D5A:
	movs r1, 0
	ldrh r0, [r2]
	cmp r0, 0
	beq _080B1D80
	movs r3, 0
_080B1D64:
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, r5
	bne _080B1D70
	adds r0, r4, 0
	b _080B1D8C
_080B1D70:
	adds r3, 0x2
	adds r1, 0x1
	cmp r1, 0x4
	bgt _080B1D80
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, 0
	bne _080B1D64
_080B1D80:
	adds r2, 0x10
	adds r4, 0x1
	cmp r4, 0x4D
	ble _080B1D5A
	movs r0, 0x1
	negs r0, r0
_080B1D8C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B1D50

	thumb_func_start sub_80B1D94
sub_80B1D94: @ 80B1D94
	push {lr}
	cmp r0, 0x48
	ble _080B1D9E
	movs r0, 0x1
	b _080B1DB8
_080B1D9E:
	cmp r0, 0x40
	bne _080B1DB6
	movs r0, 0x7E
	bl FlagGet
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _080B1DB2
	movs r1, 0x1
_080B1DB2:
	adds r0, r1, 0
	b _080B1DB8
_080B1DB6:
	movs r0, 0
_080B1DB8:
	pop {r1}
	bx r1
	thumb_func_end sub_80B1D94

	thumb_func_start sub_80B1DBC
sub_80B1DBC: @ 80B1DBC
	push {r4-r6,lr}
	adds r6, r1, 0
	movs r5, 0x1
	lsls r1, r6, 4
	adds r1, r0
	adds r4, r1, 0x2
	b _080B1DCE
_080B1DCA:
	adds r4, 0x2
	adds r5, 0x1
_080B1DCE:
	cmp r5, 0x4
	bgt _080B1DE2
	ldrh r0, [r4]
	cmp r0, 0
	beq _080B1DE2
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	cmp r0, 0
	bne _080B1DCA
_080B1DE2:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r6
	strb r5, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1DBC

	thumb_func_start sub_80B1DFC
sub_80B1DFC: @ 80B1DFC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	movs r7, 0
	movs r5, 0
	adds r4, r6, 0
	adds r4, 0xA
_080B1E1A:
	ldrh r0, [r4]
	cmp r0, r9
	bne _080B1E74
	ldrh r0, [r4, 0x2]
	cmp r0, r8
	bne _080B1E74
	adds r0, r5, 0
	bl sub_80B1D94
	cmp r0, 0
	bne _080B1E74
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B1E72
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r5, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080B1E74
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bhi _080B1E74
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80B1DBC
_080B1E72:
	movs r7, 0x1
_080B1E74:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x40
	ble _080B1E1A
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B1DFC

	thumb_func_start sub_80B1E94
sub_80B1E94: @ 80B1E94
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_085500A4
	lsls r0, r4, 4
	adds r0, r5
	ldrh r0, [r0]
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B1EB4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80B1DBC
_080B1EB4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B1E94

	thumb_func_start sub_80B1EC0
sub_80B1EC0: @ 80B1EC0
	push {r4-r6,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	movs r1, 0
	adds r3, r0, 0
	adds r3, 0xA
	ldr r5, =gSaveBlock1Ptr
_080B1ED2:
	ldrh r0, [r3]
	cmp r0, r4
	bne _080B1EF8
	ldrh r0, [r3, 0x2]
	cmp r0, r2
	bne _080B1EF8
	ldr r0, [r5]
	ldr r6, =0x000009ca
	adds r0, r6
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B1EF8
	movs r0, 0x1
	b _080B1F02
	.pool
_080B1EF8:
	adds r3, 0x10
	adds r1, 0x1
	cmp r1, 0x4D
	ble _080B1ED2
	movs r0, 0
_080B1F02:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B1EC0

	thumb_func_start sub_80B1F08
sub_80B1F08: @ 80B1F08
	push {r4,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	movs r1, 0
	adds r3, r0, 0
	adds r3, 0xA
_080B1F18:
	ldrh r0, [r3]
	cmp r0, r4
	bne _080B1F28
	ldrh r0, [r3, 0x2]
	cmp r0, r2
	bne _080B1F28
	movs r0, 0x1
	b _080B1F32
_080B1F28:
	adds r3, 0x10
	adds r1, 0x1
	cmp r1, 0x4D
	ble _080B1F18
	movs r0, 0
_080B1F32:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B1F08

	thumb_func_start sub_80B1F38
sub_80B1F38: @ 80B1F38
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B1D2C
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080B1F6C
	cmp r1, 0x63
	bgt _080B1F6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B1F6C
	movs r0, 0x1
	b _080B1F6E
	.pool
_080B1F6C:
	movs r0, 0
_080B1F6E:
	pop {r1}
	bx r1
	thumb_func_end sub_80B1F38

	thumb_func_start sub_80B1F74
sub_80B1F74: @ 80B1F74
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B1D50
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080B1FA8
	cmp r1, 0x63
	bgt _080B1FA8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B1FA8
	movs r0, 0x1
	b _080B1FAA
	.pool
_080B1FA8:
	movs r0, 0
_080B1FAA:
	pop {r1}
	bx r1
	thumb_func_end sub_80B1F74

	thumb_func_start sub_80B1FB0
sub_80B1FB0: @ 80B1FB0
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B1D2C
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B1FD8
	movs r0, 0
	b _080B1FFE
_080B1FCA:
	subs r0, r6, 0x1
	lsls r0, 1
	adds r0, r7, r0
	ldrh r0, [r0]
	b _080B1FFE
_080B1FD4:
	ldrh r0, [r5]
	b _080B1FFE
_080B1FD8:
	lsls r0, r1, 4
	adds r7, r4, r0
	movs r6, 0x1
	adds r5, r7, 0x2
	adds r4, r5, 0
_080B1FE2:
	ldrh r0, [r4]
	cmp r0, 0
	beq _080B1FCA
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _080B1FD4
	adds r4, 0x2
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x4
	ble _080B1FE2
	ldrh r0, [r7, 0x8]
_080B1FFE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B1FB0

	thumb_func_start sub_80B2004
sub_80B2004: @ 80B2004
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B1D2C
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B2032
	movs r0, 0
	b _080B2054
_080B201E:
	subs r0, r5, 0x1
	lsls r0, 1
	adds r0, r6, r0
	ldrh r0, [r0]
	b _080B2054
_080B2028:
	subs r0, r5, 0x1
	lsls r0, 1
	adds r0, r6, r0
	ldrh r0, [r0]
	b _080B2054
_080B2032:
	lsls r0, r1, 4
	adds r6, r4, r0
	movs r5, 0x1
	adds r4, r6, 0x2
_080B203A:
	ldrh r0, [r4]
	cmp r0, 0
	beq _080B201E
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _080B2028
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x4
	ble _080B203A
	ldrh r0, [r6, 0x8]
_080B2054:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B2004

	thumb_func_start sub_80B205C
sub_80B205C: @ 80B205C
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B1D50
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080B207E
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_080B207E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B205C

	thumb_func_start sub_80B208C
sub_80B208C: @ 80B208C
	push {r4,lr}
	adds r3, r0, 0
	movs r1, 0
	movs r4, 0xAE
	lsls r4, 1
	ldr r2, =gUnknown_085500A4
_080B2098:
	ldrh r0, [r2]
	cmp r0, r3
	bne _080B20A8
	adds r0, r1, r4
	b _080B20B2
	.pool
_080B20A8:
	adds r2, 0x10
	adds r1, 0x1
	cmp r1, 0x4D
	ble _080B2098
	ldr r0, =0x0000ffff
_080B20B2:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B208C

	thumb_func_start sub_80B20BC
sub_80B20BC: @ 80B20BC
	push {lr}
	ldr r0, =0x0000012f
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080B20E2
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	bl sub_80B208C
	adds r1, r0, 0
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080B20E2
	lsls r0, r1, 16
	lsrs r0, 16
	bl FlagSet
_080B20E2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B20BC

	thumb_func_start sub_80B20F4
sub_80B20F4: @ 80B20F4
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	bl sub_80B1D2C
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080B211E
	lsls r0, r1, 4
	adds r0, r4
	ldrh r0, [r0, 0x2]
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _080B211E
	movs r0, 0x1
	b _080B2120
_080B211E:
	movs r0, 0
_080B2120:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B20F4

	thumb_func_start sub_80B2128
sub_80B2128: @ 80B2128
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	ldr r4, =gUnknown_08550584
_080B2130:
	ldrh r0, [r4]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B214C
	adds r6, 0x1
	cmp r6, 0x4
	ble _080B214C
	movs r0, 0x1
	b _080B2156
	.pool
_080B214C:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x7
	bls _080B2130
	movs r0, 0
_080B2156:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B2128

	thumb_func_start sub_80B215C
sub_80B215C: @ 80B215C
	push {lr}
	bl sub_80B2128
	cmp r0, 0
	beq _080B2184
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000009c8
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0xFE
	bls _080B2180
	movs r0, 0xFF
	b _080B2182
	.pool
_080B2180:
	adds r0, 0x1
_080B2182:
	strh r0, [r1]
_080B2184:
	pop {r0}
	bx r0
	thumb_func_end sub_80B215C

	thumb_func_start sub_80B2188
sub_80B2188: @ 80B2188
	push {lr}
	bl sub_80B2128
	cmp r0, 0
	beq _080B21AC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009c8
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0xFE
	bls _080B21AC
	movs r0, 0x1
	b _080B21AE
	.pool
_080B21AC:
	movs r0, 0
_080B21AE:
	pop {r1}
	bx r1
	thumb_func_end sub_80B2188

	thumb_func_start sub_80B21B4
sub_80B21B4: @ 80B21B4
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	bl sub_80B2188
	cmp r0, 0
	beq _080B21E0
	ldr r0, =gUnknown_085500A4
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80B1DFC
	cmp r0, 0x1
	bne _080B21E0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009c8
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
_080B21E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B21B4

	thumb_func_start sub_80B21F4
sub_80B21F4: @ 80B21F4
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_085500A4
	adds r1, r3, 0
	bl sub_80B1EC0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B21F4

	thumb_func_start sub_80B2214
sub_80B2214: @ 80B2214
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_085500A4
	adds r1, r3, 0
	bl sub_80B1F08
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B2214

	thumb_func_start sub_80B2234
sub_80B2234: @ 80B2234
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gUnknown_085500A4
	bl sub_80B1FB0
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B2234

	thumb_func_start sub_80B2250
sub_80B2250: @ 80B2250
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gUnknown_085500A4
	bl sub_80B2004
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B2250

	thumb_func_start sub_80B226C
sub_80B226C: @ 80B226C
	push {r4,r5,lr}
	ldr r5, =gUnknown_085500A4
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r1, [r4]
	adds r0, r5, 0
	bl sub_80B1F38
	lsls r0, 24
	cmp r0, 0
	bne _080B2298
	ldrh r1, [r4]
	adds r0, r5, 0
	bl sub_80B20F4
	lsls r0, 24
	lsrs r0, 24
	b _080B229A
	.pool
_080B2298:
	movs r0, 0x1
_080B229A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B226C

	thumb_func_start sub_80B22A0
sub_80B22A0: @ 80B22A0
	push {lr}
	ldr r0, =gUnknown_085500A4
	ldr r1, =gTrainerBattleOpponent_A
	ldrh r1, [r1]
	bl sub_80B1F74
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B22A0

	thumb_func_start sub_80B22BC
sub_80B22BC: @ 80B22BC
	push {lr}
	ldr r0, =gUnknown_085500A4
	ldr r1, =gTrainerBattleOpponent_A
	ldrh r1, [r1]
	bl sub_80B205C
	bl rom_npc_set_flag_for_script_id
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B22BC

	thumb_func_start CheckIfMultipleTrainersWantBattle
CheckIfMultipleTrainersWantBattle: @ 80B22D8
	push {lr}
	ldr r1, =gUnknown_02038BF9
	ldrb r0, [r1]
	cmp r0, 0x1
	bls _080B2300
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_02038BF8
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gScriptResult
	movs r0, 0x1
	b _080B230A
	.pool
_080B2300:
	ldr r1, =gUnknown_02038BF8
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gScriptResult
	movs r0, 0
_080B230A:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end CheckIfMultipleTrainersWantBattle

	thumb_func_start sub_80B2318
sub_80B2318: @ 80B2318
	push {r4-r7,lr}
	lsls r0, 16
	ldr r7, =gUnknown_085500A4
	lsrs r4, r0, 12
	adds r6, r4, r7
	ldrh r0, [r6]
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B2338
	movs r0, 0
	b _080B2364
	.pool
_080B2338:
	movs r5, 0x1
	adds r0, r4, 0x2
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, 0
	beq _080B2360
	adds r4, r6, 0x2
_080B2346:
	ldrh r0, [r4]
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _080B2360
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x4
	bgt _080B2360
	ldrh r0, [r4]
	cmp r0, 0
	bne _080B2346
_080B2360:
	lsls r0, r5, 16
	lsrs r0, 16
_080B2364:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B2318

	.align 2, 0 @ Don't pad with nop.
