	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start SetUpItemUseCallback
@ void SetUpItemUseCallback(u8 taskId)
SetUpItemUseCallback: @ 80FD060
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_0203CE7C
	ldrh r0, [r1]
	cmp r0, 0xAF
	bne _080FD084
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x10]
	b _080FD08A
	.pool
_080FD084:
	ldrh r0, [r1]
	bl ItemId_GetType
_080FD08A:
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FD0B8
	ldr r0, =gUnknown_0203CE54
	ldr r2, [r0]
	ldr r1, =gUnknown_085920D8
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	adds r0, r5, 0
	bl unknown_ItemMenu_Confirm
	b _080FD0CC
	.pool
_080FD0B8:
	ldr r0, =gUnknown_0203CF2C
	ldr r2, [r0]
	ldr r1, =gUnknown_085920D8
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	adds r0, r5, 0
	bl sub_81C5B14
_080FD0CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpItemUseCallback

	thumb_func_start SetUpItemUseOnFieldCallback
@ void SetUpItemUseOnFieldCallback()
SetUpItemUseOnFieldCallback: @ 80FD0DC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _080FD110
	ldr r1, =gUnknown_03005DAC
	ldr r0, =MapPostLoadHook_UseItem
	str r0, [r1]
	adds r0, r2, 0
	bl SetUpItemUseCallback
	b _080FD11A
	.pool
_080FD110:
	ldr r0, =gUnknown_0203A0F4
	ldr r1, [r0]
	adds r0, r2, 0
	bl _call_via_r1
_080FD11A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpItemUseOnFieldCallback

	thumb_func_start MapPostLoadHook_UseItem
@ void MapPostLoadHook_UseItem()
MapPostLoadHook_UseItem: @ 80FD124
	push {lr}
	bl pal_fill_black
	ldr r0, =Task_CallItemUseOnFieldCallback
	movs r1, 0x8
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end MapPostLoadHook_UseItem

	thumb_func_start Task_CallItemUseOnFieldCallback
@ void Task_CallItemUseOnFieldCallback(u8 taskId)
Task_CallItemUseOnFieldCallback: @ 80FD13C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FD158
	ldr r0, =gUnknown_0203A0F4
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
_080FD158:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_CallItemUseOnFieldCallback

	thumb_func_start DisplayCannotUseItemMessage
@ void DisplayCannotUseItemMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField, u8 *str)
DisplayCannotUseItemMessage: @ 80FD164
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r1, r2, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gStringVar4
	adds r0, r6, 0
	bl StringExpandPlaceholders
	cmp r4, 0
	bne _080FD1B4
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FD1A0
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl DisplayItemMessage
	b _080FD1BE
	.pool
_080FD1A0:
	ldr r1, =gUnknown_085E8F31
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
	b _080FD1BE
	.pool
_080FD1B4:
	ldr r2, =CleanUpAfterFailingToUseRegisteredKeyItemOnField
	adds r0, r5, 0
	adds r1, r6, 0
	bl DisplayItemMessageOnField
_080FD1BE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisplayCannotUseItemMessage

	thumb_func_start DisplayDadsAdviceCannotUseItemMessage
@ void DisplayDadsAdviceCannotUseItemMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField)
DisplayDadsAdviceCannotUseItemMessage: @ 80FD1C8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085E8F31
	bl DisplayCannotUseItemMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisplayDadsAdviceCannotUseItemMessage

	thumb_func_start DisplayCannotDismountBikeMessage
@ void DisplayCannotDismountBikeMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField)
DisplayCannotDismountBikeMessage: @ 80FD1E0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085E8F6E
	bl DisplayCannotUseItemMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisplayCannotDismountBikeMessage

	thumb_func_start CleanUpAfterFailingToUseRegisteredKeyItemOnField
@ void CleanUpAfterFailingToUseRegisteredKeyItemOnField(u8 taskId)
CleanUpAfterFailingToUseRegisteredKeyItemOnField: @ 80FD1F8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	adds r0, r4, 0
	bl DestroyTask
	bl sub_80984F4
	bl ScriptContext2_Disable
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CleanUpAfterFailingToUseRegisteredKeyItemOnField

	thumb_func_start CheckIfItemIsTMHMOrEvolutionStone
@ u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId)
CheckIfItemIsTMHMOrEvolutionStone: @ 80FD21C
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl ItemId_GetFieldFunc
	ldr r1, =ItemUseOutOfBattle_TMHM
	cmp r0, r1
	bne _080FD238
	movs r0, 0x1
	b _080FD24E
	.pool
_080FD238:
	adds r0, r4, 0
	bl ItemId_GetFieldFunc
	ldr r1, =ItemUseOutOfBattle_EvolutionStone
	cmp r0, r1
	beq _080FD24C
	movs r0, 0
	b _080FD24E
	.pool
_080FD24C:
	movs r0, 0x2
_080FD24E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end CheckIfItemIsTMHMOrEvolutionStone

	thumb_func_start sub_80FD254
sub_80FD254: @ 80FD254
	push {lr}
	sub sp, 0x24
	mov r1, sp
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	strh r0, [r1, 0x20]
	ldr r1, =bag_menu_mail_related
	mov r0, sp
	movs r2, 0
	bl sub_8121478
	add sp, 0x24
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FD254

	thumb_func_start ItemUseOutOfBattle_Mail
@ void ItemUseOutOfBattle_Mail(int taskId)
ItemUseOutOfBattle_Mail: @ 80FD278
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CE54
	ldr r2, [r1]
	ldr r1, =sub_80FD254
	str r1, [r2]
	bl unknown_ItemMenu_Confirm
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_Mail

	thumb_func_start ItemUseOutOfBattle_Bike
@ void ItemUseOutOfBattle_Bike(int taskId)
ItemUseOutOfBattle_Bike: @ 80FD298
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
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
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x0000088b
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FD30E
	adds r0, r4, 0
	bl MetatileBehavior_IsVerticalRail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FD30E
	adds r0, r4, 0
	bl MetatileBehavior_IsHorizontalRail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FD30E
	adds r0, r4, 0
	bl MetatileBehavior_IsIsolatedVerticalRail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FD30E
	adds r0, r4, 0
	bl MetatileBehavior_IsIsolatedHorizontalRail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FD320
_080FD30E:
	ldrb r1, [r6, 0x6]
	adds r0, r5, 0
	bl DisplayCannotDismountBikeMessage
	b _080FD350
	.pool
_080FD320:
	bl sav1_map_is_biking_allowed
	cmp r0, 0x1
	bne _080FD348
	bl sub_8119FF8
	lsls r0, 24
	cmp r0, 0
	bne _080FD348
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =ItemUseOnFieldCB_Bike
	str r0, [r1]
	adds r0, r5, 0
	bl SetUpItemUseOnFieldCallback
	b _080FD350
	.pool
_080FD348:
	ldrb r1, [r6, 0x6]
	adds r0, r5, 0
	bl DisplayDadsAdviceCannotUseItemMessage
_080FD350:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ItemUseOutOfBattle_Bike

	thumb_func_start ItemUseOnFieldCB_Bike
ItemUseOnFieldCB_Bike: @ 80FD358
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemId_GetSecondaryId
	lsls r0, 24
	cmp r0, 0
	bne _080FD378
	movs r0, 0x2
	bl GetOnOffBike
	b _080FD37E
	.pool
_080FD378:
	movs r0, 0x4
	bl GetOnOffBike
_080FD37E:
	bl sub_80984F4
	bl ScriptContext2_Disable
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ItemUseOnFieldCB_Bike

	thumb_func_start CanFish
@ bool8 CanFish()
CanFish: @ 80FD394
	push {r4-r6,lr}
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
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r0, r6, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl MetatileBehavior_IsWaterfall
	lsls r0, 24
	cmp r0, 0
	bne _080FD41C
	movs r0, 0x10
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	bne _080FD41C
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	bne _080FD3EC
	bl IsPlayerFacingSurfableFishableWater
	lsls r0, 24
	cmp r0, 0
	beq _080FD41C
_080FD3E8:
	movs r0, 0x1
	b _080FD41E
_080FD3EC:
	adds r0, r5, 0
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	beq _080FD40C
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridIsImpassableAt
	lsls r0, 24
	cmp r0, 0
	beq _080FD3E8
_080FD40C:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8089510
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FD3E8
_080FD41C:
	movs r0, 0
_080FD41E:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CanFish

	thumb_func_start ItemUseOutOfBattle_Rod
ItemUseOutOfBattle_Rod: @ 80FD428
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl CanFish
	cmp r0, 0x1
	bne _080FD44C
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =ItemUseOnFieldCB_Rod
	str r0, [r1]
	adds r0, r4, 0
	bl SetUpItemUseOnFieldCallback
	b _080FD45E
	.pool
_080FD44C:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r1, [r1, 0xE]
	adds r0, r4, 0
	bl DisplayDadsAdviceCannotUseItemMessage
_080FD45E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_Rod

	thumb_func_start ItemUseOnFieldCB_Rod
ItemUseOnFieldCB_Rod: @ 80FD468
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemId_GetSecondaryId
	lsls r0, 24
	lsrs r0, 24
	bl StartFishing
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOnFieldCB_Rod

	thumb_func_start ItemUseOutOfBattle_Itemfinder
ItemUseOutOfBattle_Itemfinder: @ 80FD490
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x27
	bl IncrementGameStat
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =ItemUseOnFieldCB_Itemfinder
	str r0, [r1]
	adds r0, r4, 0
	bl SetUpItemUseOnFieldCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_Itemfinder

	thumb_func_start ItemUseOnFieldCB_Itemfinder
ItemUseOnFieldCB_Itemfinder: @ 80FD4B8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	adds r1, r4, 0
	bl ItemfinderCheckForHiddenItems
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FD4EC
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80FD504
	str r0, [r1]
	b _080FD4F6
	.pool
_080FD4EC:
	ldr r1, =gUnknown_085E9002
	ldr r2, =sub_80FD5CC
	adds r0, r4, 0
	bl DisplayItemMessageOnField
_080FD4F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOnFieldCB_Itemfinder

	thumb_func_start sub_80FD504
sub_80FD504: @ 80FD504
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r6, r5, 2
	adds r0, r6, r5
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r4, r7, r0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080FD5B8
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0x4
	bne _080FD5AC
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_80FD9B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080FD564
	ldr r1, =gUnknown_085920E4
	subs r0, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80FDA24
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_80FDA94
	str r1, [r0]
	b _080FD5C2
	.pool
_080FD564:
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	adds r3, r6, 0
	ldr r7, =gUnknown_085920E4
	movs r6, 0x3
_080FD574:
	adds r0, r1, r7
	adds r1, 0x1
	ldrb r0, [r0]
	cmp r2, r0
	bne _080FD584
	adds r0, r1, 0
	ands r0, r6
	strh r0, [r4, 0xA]
_080FD584:
	lsls r0, r1, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _080FD574
	ldr r1, =gTasks
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80FDADC
	str r1, [r0]
	movs r0, 0
	strh r0, [r4, 0x6]
	strh r0, [r4, 0x4]
	b _080FD5C2
	.pool
_080FD5AC:
	movs r0, 0x48
	bl PlaySE
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080FD5B8:
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r4, 0x6]
_080FD5C2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80FD504

	thumb_func_start sub_80FD5CC
sub_80FD5CC: @ 80FD5CC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	bl sub_80984F4
	bl ScriptContext2_Disable
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FD5CC

	thumb_func_start ItemfinderCheckForHiddenItems
@ bool8 ItemfinderCheckForHiddenItems(struct map_events *events, u8 taskId)
ItemfinderCheckForHiddenItems: @ 80FD5F0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	movs r3, 0
	mov r9, r4
	ldrb r0, [r5, 0x3]
	cmp r3, r0
	bge _080FD6A4
	subs r1, 0x5
	mov r8, r1
_080FD628:
	lsls r3, 16
	asrs r1, r3, 16
	ldr r2, [r5, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r4, r0, 2
	adds r1, r4, r2
	ldrb r0, [r1, 0x5]
	adds r7, r3, 0
	cmp r0, 0x7
	bne _080FD694
	movs r2, 0xFA
	lsls r2, 1
	adds r0, r2, 0
	ldrh r1, [r1, 0xA]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080FD694
	ldr r1, [r5, 0x10]
	adds r1, r4, r1
	ldrh r2, [r1]
	adds r2, 0x7
	mov r0, sp
	ldrh r0, [r0]
	subs r2, r0
	ldrh r0, [r1, 0x2]
	adds r0, 0x7
	mov r3, r9
	ldrh r1, [r3]
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 16
	asrs r1, r2, 16
	movs r3, 0xE0
	lsls r3, 11
	adds r2, r3
	lsrs r2, 16
	cmp r2, 0xE
	bhi _080FD694
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, r8
	blt _080FD694
	cmp r2, 0x5
	bgt _080FD694
	adds r0, r6, 0
	bl sub_80FD8E0
_080FD694:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r7, r1
	lsrs r3, r0, 16
	asrs r0, 16
	ldrb r2, [r5, 0x3]
	cmp r0, r2
	blt _080FD628
_080FD6A4:
	adds r0, r6, 0
	bl sub_80FD7C8
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	beq _080FD6C4
	movs r0, 0
	b _080FD6C6
	.pool
_080FD6C4:
	movs r0, 0x1
_080FD6C6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ItemfinderCheckForHiddenItems

	thumb_func_start sub_80FD6D4
sub_80FD6D4: @ 80FD6D4
	push {r4-r6,lr}
	lsls r1, 16
	lsrs r3, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	ldrb r2, [r0, 0x3]
	ldr r5, [r0, 0x10]
	movs r1, 0
	cmp r1, r2
	bge _080FD728
	lsls r0, r3, 16
	asrs r6, r0, 16
	lsls r0, r4, 16
	asrs r4, r0, 16
	adds r3, r5, 0
_080FD6F2:
	ldrb r0, [r3, 0x5]
	cmp r0, 0x7
	bne _080FD720
	ldrh r0, [r3]
	cmp r6, r0
	bne _080FD720
	ldrh r0, [r3, 0x2]
	cmp r4, r0
	bne _080FD720
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1, 0
	ldrh r3, [r3, 0xA]
	adds r0, r3
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080FD728
	movs r0, 0x1
	b _080FD72A
_080FD720:
	adds r3, 0xC
	adds r1, 0x1
	cmp r1, r2
	blt _080FD6F2
_080FD728:
	movs r0, 0
_080FD72A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80FD6D4

	thumb_func_start sub_80FD730
sub_80FD730: @ 80FD730
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	bl mapconnection_get_mapheader
	adds r3, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x2
	beq _080FD758
	cmp r0, 0x2
	bgt _080FD74E
	cmp r0, 0x1
	beq _080FD76C
	b _080FD7AC
_080FD74E:
	cmp r0, 0x3
	beq _080FD784
	cmp r0, 0x4
	beq _080FD78E
	b _080FD7AC
_080FD758:
	ldr r0, [r4, 0x4]
	adds r0, 0x7
	subs r0, r5, r0
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	subs r0, 0x7
	adds r0, r6
	b _080FD7A2
_080FD76C:
	ldr r0, [r4, 0x4]
	adds r0, 0x7
	subs r0, r5, r0
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	b _080FD79E
	.pool
_080FD784:
	ldr r0, [r3]
	ldr r0, [r0]
	subs r0, 0x7
	adds r0, r5
	b _080FD798
_080FD78E:
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x7
	subs r0, r5, r0
_080FD798:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, [r4, 0x4]
_080FD79E:
	adds r0, 0x7
	subs r0, r6, r0
_080FD7A2:
	lsls r0, 16
	lsrs r2, r0, 16
	b _080FD7B0
	.pool
_080FD7AC:
	movs r0, 0
	b _080FD7C2
_080FD7B0:
	ldr r0, [r3, 0x4]
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	bl sub_80FD6D4
	lsls r0, 24
	lsrs r0, 24
_080FD7C2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80FD730

	thumb_func_start sub_80FD7C8
sub_80FD7C8: @ 80FD7C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, =gMapHeader
	ldr r1, [r0]
	ldr r0, [r1]
	adds r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	ldr r0, [r1, 0x4]
	adds r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x7
	lsls r0, 16
	lsrs r3, r0, 16
	asrs r0, 16
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	adds r1, 0x7
	cmp r0, r1
	bgt _080FD8CC
_080FD816:
	mov r5, sp
	ldrh r0, [r5, 0x2]
	subs r0, 0x5
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r2, r4, 16
	asrs r1, r2, 16
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	adds r0, 0x5
	lsls r3, 16
	mov r8, r3
	cmp r1, r0
	bgt _080FD8B6
	movs r0, 0x7
	str r0, [sp, 0x10]
	mov r1, r8
	asrs r1, 16
	mov r9, r1
	mov r10, r0
_080FD83E:
	ldr r3, [sp, 0x10]
	cmp r3, r9
	bgt _080FD860
	ldr r5, [sp, 0x8]
	lsls r0, r5, 16
	asrs r0, 16
	cmp r9, r0
	bge _080FD860
	asrs r1, r2, 16
	cmp r10, r1
	bgt _080FD860
	ldr r6, [sp, 0xC]
	lsls r0, r6, 16
	asrs r0, 16
	lsls r7, r4, 16
	cmp r1, r0
	blt _080FD89E
_080FD860:
	mov r0, r8
	asrs r5, r0, 16
	lsls r4, 16
	asrs r6, r4, 16
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8088A8C
	adds r7, r4, 0
	cmp r0, 0
	beq _080FD89E
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80FD730
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FD89E
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r5, r1
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r0, 0x2]
	subs r2, r6, r2
	lsls r2, 16
	asrs r2, 16
	ldr r0, [sp, 0x4]
	bl sub_80FD8E0
_080FD89E:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r7, r1
	lsrs r4, r0, 16
	lsls r2, r4, 16
	asrs r1, r2, 16
	mov r3, sp
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	adds r0, 0x5
	cmp r1, r0
	ble _080FD83E
_080FD8B6:
	movs r1, 0x80
	lsls r1, 9
	add r1, r8
	lsrs r3, r1, 16
	asrs r1, 16
	mov r0, sp
	movs r6, 0
	ldrsh r0, [r0, r6]
	adds r0, 0x7
	cmp r1, r0
	ble _080FD816
_080FD8CC:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FD7C8

	thumb_func_start sub_80FD8E0
sub_80FD8E0: @ 80FD8E0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r12, r2
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r3, r1, r0
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _080FD918
	strh r7, [r3]
	mov r0, r12
	strh r0, [r3, 0x2]
	movs r0, 0x1
	strh r0, [r3, 0x4]
	b _080FD9A2
	.pool
_080FD918:
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bge _080FD928
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
	b _080FD92A
_080FD928:
	ldrh r4, [r3]
_080FD92A:
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	ldrh r1, [r3, 0x2]
	mov r9, r1
	cmp r0, 0
	bge _080FD93E
	negs r0, r0
	lsls r0, 16
	lsrs r2, r0, 16
	b _080FD940
_080FD93E:
	ldrh r2, [r3, 0x2]
_080FD940:
	lsls r1, r7, 16
	asrs r0, r1, 16
	cmp r0, 0
	bge _080FD950
	negs r0, r0
	lsls r0, 16
	lsrs r6, r0, 16
	b _080FD952
_080FD950:
	lsrs r6, r1, 16
_080FD952:
	mov r1, r12
	lsls r0, r1, 16
	asrs r1, r0, 16
	mov r8, r0
	cmp r1, 0
	bge _080FD964
	negs r0, r1
	lsls r0, 16
	b _080FD966
_080FD964:
	mov r0, r8
_080FD966:
	lsrs r5, r0, 16
	lsls r0, r4, 16
	asrs r0, 16
	lsls r1, r2, 16
	asrs r2, r1, 16
	adds r4, r0, r2
	lsls r0, r6, 16
	asrs r0, 16
	lsls r1, r5, 16
	asrs r1, 16
	adds r0, r1
	cmp r4, r0
	ble _080FD988
	strh r7, [r3]
	mov r1, r12
	strh r1, [r3, 0x2]
	b _080FD9A2
_080FD988:
	cmp r4, r0
	bne _080FD9A2
	cmp r2, r1
	bgt _080FD99C
	cmp r2, r1
	bne _080FD9A2
	mov r1, r9
	lsls r0, r1, 16
	cmp r0, r8
	bge _080FD9A2
_080FD99C:
	strh r7, [r3]
	mov r0, r12
	strh r0, [r3, 0x2]
_080FD9A2:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80FD8E0

	thumb_func_start sub_80FD9B0
sub_80FD9B0: @ 80FD9B0
	push {r4,r5,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsrs r2, r0, 16
	cmp r0, 0
	bne _080FD9C2
	cmp r1, 0
	beq _080FDA1C
_080FD9C2:
	lsls r0, r2, 16
	asrs r2, r0, 16
	adds r5, r0, 0
	cmp r2, 0
	bge _080FD9D4
	negs r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	b _080FD9D6
_080FD9D4:
	lsrs r4, r5, 16
_080FD9D6:
	lsls r0, r1, 16
	asrs r2, r0, 16
	adds r1, r0, 0
	cmp r2, 0
	bge _080FD9E8
	negs r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	b _080FD9EA
_080FD9E8:
	lsrs r3, r1, 16
_080FD9EA:
	lsls r0, r4, 16
	asrs r2, r0, 16
	lsls r0, r3, 16
	asrs r0, 16
	cmp r2, r0
	ble _080FDA02
	cmp r5, 0
	bge _080FD9FE
	movs r0, 0x4
	b _080FDA1E
_080FD9FE:
	movs r0, 0x2
	b _080FDA1E
_080FDA02:
	cmp r2, r0
	bge _080FDA0C
	cmp r1, 0
	blt _080FDA14
	b _080FDA18
_080FDA0C:
	cmp r2, r0
	bne _080FDA1C
	cmp r1, 0
	bge _080FDA18
_080FDA14:
	movs r0, 0x1
	b _080FDA1E
_080FDA18:
	movs r0, 0x3
	b _080FDA1E
_080FDA1C:
	movs r0, 0
_080FDA1E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80FD9B0

	thumb_func_start sub_80FDA24
sub_80FDA24: @ 80FDA24
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r4, =gMapObjects
	adds r0, r4
	bl FieldObjectClearAnimIfSpecialAnimFinished
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl FieldObjectClearAnim
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl npc_sync_anim_pause_bits
	adds r0, r5, 0
	bl PlayerTurnInPlace
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDA24

	thumb_func_start sub_80FDA94
sub_80FDA94: @ 80FDA94
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FDACA
	ldr r1, =gUnknown_085E8F93
	ldr r2, =sub_80FD5CC
	adds r0, r4, 0
	bl DisplayItemMessageOnField
_080FDACA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDA94

	thumb_func_start sub_80FDADC
sub_80FDADC: @ 80FDADC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FDB1C
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080FDB50
_080FDB1C:
	ldr r1, =gUnknown_085920E4
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80FDA24
	movs r0, 0x1
	strh r0, [r4, 0x4]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _080FDB50
	ldr r1, =gUnknown_085E8FDB
	ldr r2, =sub_80FD5CC
	adds r0, r5, 0
	bl DisplayItemMessageOnField
_080FDB50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDADC

	thumb_func_start ItemUseOutOfBattle_PokeblockCase
ItemUseOutOfBattle_PokeblockCase: @ 80FDB6C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FDB98
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r1, [r1, 0xE]
	adds r0, r4, 0
	bl DisplayDadsAdviceCannotUseItemMessage
	b _080FDBDA
	.pool
_080FDB98:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r5, r1, r0
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080FDBC8
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	ldr r0, =sub_80FDBEC
	str r0, [r1]
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	b _080FDBDA
	.pool
_080FDBC8:
	ldr r0, =gUnknown_03005DAC
	ldr r1, =sub_80AF6D4
	str r1, [r0]
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r0, =sub_80FDC00
	str r0, [r5]
_080FDBDA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_PokeblockCase

	thumb_func_start sub_80FDBEC
sub_80FDBEC: @ 80FDBEC
	push {lr}
	ldr r1, =bag_menu_mail_related
	movs r0, 0
	bl sub_81357FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDBEC

	thumb_func_start sub_80FDC00
sub_80FDC00: @ 80FDC00
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080FDC24
	bl overworld_free_bg_tilemaps
	ldr r1, =c2_exit_to_overworld_2_switch
	movs r0, 0
	bl sub_81357FC
	adds r0, r4, 0
	bl DestroyTask
_080FDC24:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDC00

	thumb_func_start ItemUseOutOfBattle_CoinCase
ItemUseOutOfBattle_CoinCase: @ 80FDC34
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gStringVar1
	bl GetCoins
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E9026
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080FDC90
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
	b _080FDC9A
	.pool
_080FDC90:
	ldr r2, =CleanUpAfterFailingToUseRegisteredKeyItemOnField
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_080FDC9A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_CoinCase

	thumb_func_start ItemUseOutOfBattle_PowderJar
ItemUseOutOfBattle_PowderJar: @ 80FDCA4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gStringVar1
	bl sub_80247BC
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E9138
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080FDCFC
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
	b _080FDD06
	.pool
_080FDCFC:
	ldr r2, =CleanUpAfterFailingToUseRegisteredKeyItemOnField
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_080FDD06:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_PowderJar

	thumb_func_start sub_80FDD10
sub_80FDD10: @ 80FDD10
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsPlayerFacingPlantedBerryTree
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FDD58
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =sub_80FDD74
	str r0, [r1]
	ldr r1, =gUnknown_03005DAC
	ldr r0, =MapPostLoadHook_UseItem
	str r0, [r1]
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	str r0, [r1]
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	b _080FDD68
	.pool
_080FDD58:
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemId_GetFieldFunc
	adds r1, r0, 0
	adds r0, r4, 0
	bl _call_via_r1
_080FDD68:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDD10

	thumb_func_start sub_80FDD74
sub_80FDD74: @ 80FDD74
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
	bl ScriptContext2_Enable
	ldr r0, =gUnknown_08274482
	bl ScriptContext1_SetupScript
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDD74

	thumb_func_start ItemUseOutOfBattle_WailmerPail
ItemUseOutOfBattle_WailmerPail: @ 80FDDA4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl sub_80FDE2C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FDDC8
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =sub_80FDE7C
	b _080FDDD8
	.pool
_080FDDC8:
	bl WaterBerryTree
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FDDEC
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =sub_80FDE08
_080FDDD8:
	str r0, [r1]
	adds r0, r4, 0
	bl SetUpItemUseOnFieldCallback
	b _080FDDFE
	.pool
_080FDDEC:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrb r1, [r1, 0xE]
	adds r0, r5, 0
	bl DisplayDadsAdviceCannotUseItemMessage
_080FDDFE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_WailmerPail

	thumb_func_start sub_80FDE08
sub_80FDE08: @ 80FDE08
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ScriptContext2_Enable
	ldr r0, =gUnknown_082744C0
	bl ScriptContext1_SetupScript
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDE08

	thumb_func_start sub_80FDE2C
sub_80FDE2C: @ 80FDE2C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	bl PlayerGetZCoord
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r4]
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x10
	beq _080FDE68
	ldr r0, =gMapObjects
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x5]
	cmp r0, 0xE4
	beq _080FDE70
_080FDE68:
	movs r0, 0
	b _080FDE72
	.pool
_080FDE70:
	movs r0, 0x1
_080FDE72:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80FDE2C

	thumb_func_start sub_80FDE7C
sub_80FDE7C: @ 80FDE7C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ScriptContext2_Enable
	ldr r0, =gUnknown_08242CFC
	bl ScriptContext1_SetupScript
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDE7C

	thumb_func_start ItemUseOutOfBattle_Medicine
ItemUseOutOfBattle_Medicine: @ 80FDEA0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =ItemUseCB_Medicine
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_Medicine

	thumb_func_start ItemUseOutOfBattle_ReduceEV
ItemUseOutOfBattle_ReduceEV: @ 80FDEBC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =sub_81B67C8
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_ReduceEV

	thumb_func_start ItemUseOutOfBattle_SacredAsh
ItemUseOutOfBattle_SacredAsh: @ 80FDED8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =sub_81B79E8
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_SacredAsh

	thumb_func_start ItemUseOutOfBattle_PPRecovery
ItemUseOutOfBattle_PPRecovery: @ 80FDEF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =dp05_ether
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_PPRecovery

	thumb_func_start ItemUseOutOfBattle_PPUp
ItemUseOutOfBattle_PPUp: @ 80FDF10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =dp05_pp_up
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_PPUp

	thumb_func_start ItemUseOutOfBattle_RareCandy
ItemUseOutOfBattle_RareCandy: @ 80FDF2C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =dp05_rare_candy
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_RareCandy

	thumb_func_start ItemUseOutOfBattle_TMHM
ItemUseOutOfBattle_TMHM: @ 80FDF48
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r1, [r0]
	movs r0, 0xA9
	lsls r0, 1
	cmp r1, r0
	bls _080FDF74
	ldr r2, =gUnknown_085E9047
	ldr r3, =sub_80FDF90
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FDF80
	.pool
_080FDF74:
	ldr r2, =gUnknown_085E9037
	ldr r3, =sub_80FDF90
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
_080FDF80:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_TMHM

	thumb_func_start sub_80FDF90
sub_80FDF90: @ 80FDF90
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	bl PlaySE
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task08_0809AD8C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FDF90

	thumb_func_start task08_0809AD8C
task08_0809AD8C: @ 80FDFBC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080FE000
	ldr r4, =gStringVar1
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemIdToBattleMoveId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E9058
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r3, =sub_80FE024
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
_080FE000:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task08_0809AD8C

	thumb_func_start sub_80FE024
sub_80FE024: @ 80FE024
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_085920E8
	movs r1, 0x6
	bl bag_menu_yes_no
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE024

	thumb_func_start sub_80FE03C
sub_80FE03C: @ 80FE03C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =sub_81B6DC4
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE03C

	thumb_func_start sub_80FE058
sub_80FE058: @ 80FE058
	push {r4,lr}
	ldr r4, =gUnknown_0203CE7C
	ldrh r0, [r4]
	movs r1, 0x1
	bl RemoveBagItem
	ldrh r0, [r4]
	ldr r1, =gStringVar2
	bl CopyItemName
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085E9080
	bl StringExpandPlaceholders
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE0AC
	ldrh r0, [r4]
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	bl sub_81AB9A8
	ldrh r0, [r4]
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	bl sub_81ABA88
	b _080FE0B4
	.pool
_080FE0AC:
	bl sub_81C5924
	bl sub_81C59BC
_080FE0B4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FE058

	thumb_func_start ItemUseOutOfBattle_Repel
ItemUseOutOfBattle_Repel: @ 80FE0BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =0x00004021
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _080FE0EC
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80FE124
	str r0, [r1]
	b _080FE116
	.pool
_080FE0EC:
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE10C
	ldr r2, =gUnknown_085E9092
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE116
	.pool
_080FE10C:
	ldr r1, =gUnknown_085E9092
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
_080FE116:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_Repel

	thumb_func_start sub_80FE124
sub_80FE124: @ 80FE124
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r4, r1, 3
	ldr r5, =gTasks + 0x8
	adds r1, r4, r5
	ldrh r0, [r1, 0x10]
	adds r0, 0x1
	strh r0, [r1, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080FE156
	movs r0, 0
	strh r0, [r1, 0x10]
	movs r0, 0x2F
	bl PlaySE
	adds r0, r5, 0
	subs r0, 0x8
	adds r0, r4, r0
	ldr r1, =sub_80FE164
	str r1, [r0]
_080FE156:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE124

	thumb_func_start sub_80FE164
sub_80FE164: @ 80FE164
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _080FE1C2
	ldr r4, =0x00004021
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemId_GetHoldEffectParam
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl VarSet
	bl sub_80FE058
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE1B8
	ldr r2, =gStringVar4
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r5, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE1C2
	.pool
_080FE1B8:
	ldr r1, =gStringVar4
	ldr r2, =sub_81C6714
	adds r0, r6, 0
	bl DisplayItemMessageInBattlePyramid
_080FE1C2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE164

	thumb_func_start sub_80FE1D0
sub_80FE1D0: @ 80FE1D0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x18]
	adds r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080FE226
	movs r0, 0x75
	bl PlaySE
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE21C
	ldr r2, =gStringVar4
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE226
	.pool
_080FE21C:
	ldr r1, =gStringVar4
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
_080FE226:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE1D0

	thumb_func_start ItemUseOutOfBattle_BlackWhiteFlute
ItemUseOutOfBattle_BlackWhiteFlute: @ 80FE234
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203CE7C
	ldrh r0, [r4]
	ldr r1, =gStringVar2
	bl CopyItemName
	ldrh r0, [r4]
	cmp r0, 0x2B
	bne _080FE278
	ldr r0, =0x000008ad
	bl FlagSet
	ldr r0, =0x000008ae
	bl FlagReset
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085E90C6
	bl StringExpandPlaceholders
	b _080FE28C
	.pool
_080FE278:
	ldr r0, =0x000008ae
	bl FlagSet
	ldr r0, =0x000008ad
	bl FlagReset
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085E90F4
	bl StringExpandPlaceholders
_080FE28C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x18]
	ldr r1, =sub_80FE1D0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_BlackWhiteFlute

	thumb_func_start task08_080A1C44
task08_080A1C44: @ 80FE2BC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl player_avatar_init_params_reset
	bl sub_80B7CC8
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task08_080A1C44

	thumb_func_start re_escape_rope
re_escape_rope: @ 80FE2D8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl flagmods_08054D70
	bl sub_80FE058
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	ldr r1, =gStringVar4
	ldr r2, =task08_080A1C44
	adds r0, r4, 0
	bl DisplayItemMessageOnField
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end re_escape_rope

	thumb_func_start sub_80FE314
sub_80FE314: @ 80FE314
	push {lr}
	ldr r0, =gMapHeader
	ldrb r1, [r0, 0x1A]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080FE32C
	movs r0, 0
	b _080FE32E
	.pool
_080FE32C:
	movs r0, 0x1
_080FE32E:
	pop {r1}
	bx r1
	thumb_func_end sub_80FE314

	thumb_func_start ItemUseOutOfBattle_EscapeRope
ItemUseOutOfBattle_EscapeRope: @ 80FE334
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80FE314
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FE35C
	ldr r1, =gUnknown_0203A0F4
	ldr r0, =re_escape_rope
	str r0, [r1]
	adds r0, r4, 0
	bl SetUpItemUseOnFieldCallback
	b _080FE36E
	.pool
_080FE35C:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r1, [r1, 0xE]
	adds r0, r4, 0
	bl DisplayDadsAdviceCannotUseItemMessage
_080FE36E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_EscapeRope

	thumb_func_start ItemUseOutOfBattle_EvolutionStone
ItemUseOutOfBattle_EvolutionStone: @ 80FE378
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =sub_81B7C74
	str r1, [r2]
	bl SetUpItemUseCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_EvolutionStone

	thumb_func_start ItemUseInBattle_PokeBall
ItemUseInBattle_PokeBall: @ 80FE394
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl PlayerPartyAndPokemonStorageFull
	lsls r0, 24
	cmp r0, 0
	bne _080FE3D0
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE3C8
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	b _080FE3FA
	.pool
_080FE3C8:
	adds r0, r4, 0
	bl sub_81C5B14
	b _080FE3FA
_080FE3D0:
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE3F0
	ldr r2, =gUnknown_085E9125
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE3FA
	.pool
_080FE3F0:
	ldr r1, =gUnknown_085E9125
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
_080FE3FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseInBattle_PokeBall

	thumb_func_start sub_80FE408
sub_80FE408: @ 80FE408
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080FE43A
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE434
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	b _080FE43A
	.pool
_080FE434:
	adds r0, r5, 0
	bl sub_81C5B14
_080FE43A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FE408

	thumb_func_start sub_80FE440
sub_80FE440: @ 80FE440
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x18]
	adds r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080FE4AC
	movs r0, 0x1
	bl PlaySE
	ldr r4, =gUnknown_0203CE7C
	ldrh r0, [r4]
	movs r1, 0x1
	bl RemoveBagItem
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE49C
	ldrh r0, [r4]
	bl sub_806CF78
	adds r2, r0, 0
	ldr r3, =sub_80FE408
	adds r0, r5, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE4AC
	.pool
_080FE49C:
	ldrh r0, [r4]
	bl sub_806CF78
	adds r1, r0, 0
	ldr r2, =sub_80FE408
	adds r0, r6, 0
	bl DisplayItemMessageInBattlePyramid
_080FE4AC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE440

	thumb_func_start ItemUseInBattle_StatIncrease
ItemUseInBattle_StatIncrease: @ 80FE4B8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gBattlePartyID
	ldr r0, =gUnknown_020244B8
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gUnknown_0203CE7C
	ldrh r1, [r1]
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	bl ExecuteTableBasedItemEffect_
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _080FE52C
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE518
	ldr r2, =gUnknown_085E96F6
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE53C
	.pool
_080FE518:
	ldr r1, =gUnknown_085E96F6
	ldr r2, =sub_81C6714
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _080FE53C
	.pool
_080FE52C:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80FE440
	str r0, [r1]
	strh r2, [r1, 0x18]
_080FE53C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseInBattle_StatIncrease

	thumb_func_start sub_80FE54C
sub_80FE54C: @ 80FE54C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE574
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	ldr r0, =sub_81B89F0
	str r0, [r1]
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	b _080FE582
	.pool
_080FE574:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =sub_81B89F0
	str r0, [r1]
	adds r0, r4, 0
	bl sub_81C5B14
_080FE582:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE54C

	thumb_func_start ItemUseInBattle_Medicine
ItemUseInBattle_Medicine: @ 80FE590
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =ItemUseCB_Medicine
	str r1, [r2]
	bl sub_80FE54C
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseInBattle_Medicine

	thumb_func_start sub_80FE5AC
sub_80FE5AC: @ 80FE5AC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =sub_81B79E8
	str r1, [r2]
	bl sub_80FE54C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE5AC

	thumb_func_start ItemUseInBattle_PPRecovery
ItemUseInBattle_PPRecovery: @ 80FE5C8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_03006328
	ldr r1, =dp05_ether
	str r1, [r2]
	bl sub_80FE54C
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseInBattle_PPRecovery

	thumb_func_start ItemUseInBattle_Escape
ItemUseInBattle_Escape: @ 80FE5E4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080FE634
	bl sub_80FE058
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080FE620
	ldr r2, =gStringVar4
	ldr r3, =unknown_ItemMenu_Confirm
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _080FE646
	.pool
_080FE620:
	ldr r1, =gStringVar4
	ldr r2, =sub_81C5B14
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _080FE646
	.pool
_080FE634:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r1, [r1, 0xE]
	adds r0, r4, 0
	bl DisplayDadsAdviceCannotUseItemMessage
_080FE646:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseInBattle_Escape

	thumb_func_start ItemUseOutOfBattle_EnigmaBerry
ItemUseOutOfBattle_EnigmaBerry: @ 80FE650
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl GetItemEffectType
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x14
	bls _080FE66A
	b _080FE75C
_080FE66A:
	lsls r0, 2
	ldr r1, =_080FE67C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FE67C:
	.4byte _080FE708
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE75C
	.4byte _080FE75C
	.4byte _080FE6EC
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE6D0
	.4byte _080FE75C
	.4byte _080FE724
	.4byte _080FE724
	.4byte _080FE740
_080FE6D0:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x10]
	adds r0, r4, 0
	bl ItemUseOutOfBattle_Medicine
	b _080FE770
	.pool
_080FE6EC:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x10]
	adds r0, r4, 0
	bl ItemUseOutOfBattle_SacredAsh
	b _080FE770
	.pool
_080FE708:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x10]
	adds r0, r4, 0
	bl ItemUseOutOfBattle_RareCandy
	b _080FE770
	.pool
_080FE724:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x10]
	adds r0, r4, 0
	bl ItemUseOutOfBattle_PPUp
	b _080FE770
	.pool
_080FE740:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x10]
	adds r0, r4, 0
	bl ItemUseOutOfBattle_PPRecovery
	b _080FE770
	.pool
_080FE75C:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x4
	strh r0, [r1, 0x10]
	adds r0, r4, 0
	bl ItemUseOutOfBattle_CannotUse
_080FE770:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_EnigmaBerry

	thumb_func_start ItemUseInBattle_EnigmaBerry
ItemUseInBattle_EnigmaBerry: @ 80FE77C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl GetItemEffectType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x15
	bhi _080FE814
	lsls r0, 2
	ldr r1, =_080FE7A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FE7A4:
	.4byte _080FE7FC
	.4byte _080FE814
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE804
	.4byte _080FE814
	.4byte _080FE804
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE814
	.4byte _080FE80C
_080FE7FC:
	adds r0, r4, 0
	bl ItemUseInBattle_StatIncrease
	b _080FE81A
_080FE804:
	adds r0, r4, 0
	bl ItemUseInBattle_Medicine
	b _080FE81A
_080FE80C:
	adds r0, r4, 0
	bl ItemUseInBattle_PPRecovery
	b _080FE81A
_080FE814:
	adds r0, r4, 0
	bl ItemUseOutOfBattle_CannotUse
_080FE81A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ItemUseInBattle_EnigmaBerry

	thumb_func_start ItemUseOutOfBattle_CannotUse
ItemUseOutOfBattle_CannotUse: @ 80FE820
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r1, [r1, 0xE]
	bl DisplayDadsAdviceCannotUseItemMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseOutOfBattle_CannotUse

	.align 2, 0 @ Don't pad with nop.
