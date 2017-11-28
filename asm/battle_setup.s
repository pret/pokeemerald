	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





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
	bl GetSumOfPlayerPartyLevel
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
	ldr r2, =gSpecialVar_Result
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
	bl ResetPoisonStepCounter
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

	thumb_func_start IsPlayerDefeated
IsPlayerDefeated: @ 80B12A8
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
	thumb_func_end IsPlayerDefeated

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
	ldr r0, =gSpecialVar_LastTalked
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
	ldr r0, =EventScript_2713C2
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
	ldr r0, =EventScript_27138A
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
	ldr r0, =EventScript_2713F8
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
	ldr r0, =EventScript_2713D1
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
	ldr r0, =gSpecialVar_LastTalked
	ldrb r0, [r0]
	bl sub_81A9AA8
	ldr r1, =gTrainerBattleOpponent_A
	b _080B157E
	.pool
_080B156C:
	ldr r0, =gUnknown_08550014
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	ldr r0, =gSpecialVar_LastTalked
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
	ldr r0, =gSpecialVar_LastTalked
	ldrb r0, [r0]
	bl battle_init
	ldr r1, =gTrainerBattleOpponent_A
	b _080B157E
	.pool
_080B15D8:
	ldr r0, =gUnknown_08550014
	adds r1, r5, 0
	bl TrainerBattleLoadArgs
	ldr r0, =gSpecialVar_LastTalked
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
	ldr r0, =EventScript_271362
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
	ldr r4, =gSpecialVar_LastTalked
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
	ldr r0, =EventScript_271354
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
	ldr r4, =gSpecialVar_LastTalked
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
	ldr r0, =EventScript_271354
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
	bl DoTrainerBattle
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
	bl IsPlayerDefeated
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
	ldr r0, =CB2_WhiteOut
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
	bl IsPlayerDefeated
	cmp r0, 0x1
	bne _080B19D0
	ldr r0, =CB2_WhiteOut
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
	bl DoTrainerBattle
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
	ldr r0, =gSpecialVar_LastTalked
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
	ldr r0, =gSpecialVar_LastTalked
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
	ldr r0, =EventScript_2C8436
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
	ldr r0, =LavaridgeTown_Gym_1F_EventScript_2742E6
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
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _080B230A
	.pool
_080B2300:
	ldr r1, =gUnknown_02038BF8
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gSpecialVar_Result
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
