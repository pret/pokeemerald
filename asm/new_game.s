	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start NewGameInitData
@ void NewGameInitData()
NewGameInitData: @ 80844A0
	push {r4,r5,lr}
	ldr r0, =gSaveFileStatus
	ldrh r0, [r0]
	cmp r0, 0
	beq _080844AE
	cmp r0, 0x2
	bne _080844B2
_080844AE:
	bl RtcReset
_080844B2:
	ldr r1, =gDifferentSaveFile
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	adds r0, 0xAC
	movs r5, 0
	str r5, [r0]
	bl ZeroPlayerPartyMons
	bl ZeroEnemyPartyMons
	bl ResetPokedex
	bl sub_8084400
	bl ClearSav1
	bl ClearMailData
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	ldr r0, [r4]
	adds r0, 0xA8
	str r5, [r0]
	bl InitPlayerTrainerId
	bl PlayTimeCounter_Reset
	bl ClearPokedexFlags
	bl InitEventData
	bl ClearTVShowData
	bl ResetGabbyAndTy
	bl ResetSecretBases
	bl ClearBerryTrees
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r1, =0x00000bb8
	bl SetMoney
	movs r0, 0
	bl SetCoins
	bl ResetLinkContestBoolean
	bl ResetGameStats
	bl ClearAllContestWinnerPics
	bl InitLinkBattleRecords
	bl InitSeedotSizeRecord
	bl InitLotadSizeRecord
	ldr r0, =gPlayerPartyCount
	strb r5, [r0]
	bl ZeroPlayerPartyMons
	bl ResetPokemonStorageSystem
	bl ClearRoamerData
	bl ClearRoamerLocationData
	ldr r0, [r4]
	ldr r1, =0x00000496
	adds r0, r1
	strh r5, [r0]
	bl ClearBag
	bl NewGameInitPCItems
	bl ClearPokeblocks
	bl ClearDecorationInventories
	bl InitEasyChatPhrases
	bl SetMauvilleOldMan
	bl InitDewfordTrend
	bl ResetFanClub
	bl ResetLotteryCorner
	bl WarpToTruck
	ldr r0, =gUnknown_082715DE
	bl ScriptContext2_RunNewScript
	bl ResetMiniGamesResults
	bl copy_strings_to_sav1
	bl SetLilycoveLady
	bl sub_819FAA0
	bl sub_81A4B14
	bl sub_8195E10
	bl sub_801AFD8
	bl sub_800E5AC
	bl sub_81D54BC
	bl ResetContestLinkResults
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end NewGameInitData

	thumb_func_start ResetMiniGamesResults
ResetMiniGamesResults: @ 80845CC
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	movs r5, 0
	strh r5, [r0]
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	movs r0, 0xF6
	lsls r0, 1
	adds r1, r0
	ldr r6, =0x01000008
	mov r0, sp
	adds r2, r6, 0
	bl CpuSet
	ldr r0, [r4]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl SetBerryPowder
	bl ResetPokeJumpResults
	mov r0, sp
	adds r0, 0x2
	strh r5, [r0]
	ldr r1, [r4]
	movs r2, 0x83
	lsls r2, 2
	adds r1, r2
	adds r2, r6, 0
	bl CpuSet
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetMiniGamesResults

	.align 2, 0 @ Don't pad with nop.
