	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start PrintStartMenuActions
PrintStartMenuActions: @ 809F7C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	adds r6, r1, 0
	ldrb r2, [r0]
	ldr r0, =sStartMenuItems
	mov r9, r0
	ldr r1, =gStringVar4
	mov r10, r1
_0809F7DA:
	ldr r0, =sCurrentStartMenuActions
	lsls r2, 24
	asrs r4, r2, 24
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r3, r0, 3
	mov r0, r9
	adds r0, 0x4
	adds r0, r3, r0
	ldr r1, [r0]
	ldr r0, =StartMenu_PlayerName
	adds r7, r2, 0
	cmp r1, r0
	bne _0809F828
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r5]
	lsls r1, 3
	add r1, r9
	ldr r1, [r1]
	lsls r3, r4, 4
	adds r3, 0x9
	lsls r3, 16
	lsrs r3, 16
	movs r2, 0x8
	bl sub_819A024
	b _0809F858
	.pool
_0809F828:
	mov r1, r9
	adds r0, r3, r1
	ldr r1, [r0]
	mov r0, r10
	bl StringExpandPlaceholders
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 4
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	mov r2, r10
	movs r3, 0x8
	bl PrintTextOnWindow
_0809F858:
	movs r0, 0x80
	lsls r0, 17
	adds r1, r7, r0
	lsrs r2, r1, 24
	asrs r1, 24
	ldr r0, =sNumStartMenuActions
	ldrb r0, [r0]
	cmp r1, r0
	bge _0809F87C
	subs r6, 0x1
	cmp r6, 0
	bne _0809F7DA
	mov r1, r8
	strb r2, [r1]
	movs r0, 0
	b _0809F882
	.pool
_0809F87C:
	mov r0, r8
	strb r2, [r0]
	movs r0, 0x1
_0809F882:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end PrintStartMenuActions

	thumb_func_start sub_809F894
sub_809F894: @ 809F894
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_02037619
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r2, r0, 0
	cmp r1, 0x5
	bhi _0809F98C
	lsls r0, r1, 2
	ldr r1, =_0809F8B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0809F8B8:
	.4byte _0809F8D0
	.4byte _0809F8D8
	.4byte _0809F8E4
	.4byte _0809F90C
	.4byte _0809F930
	.4byte _0809F94C
_0809F8D0:
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _0809F98C
_0809F8D8:
	bl BuildStartMenuActions
	ldr r1, =gUnknown_02037619
	b _0809F940
	.pool
_0809F8E4:
	bl sub_81973A4
	ldr r0, =sNumStartMenuActions
	ldrb r0, [r0]
	bl sub_81979C4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81973FC
	ldr r1, =gUnknown_02037619
	movs r0, 0
	strb r0, [r1, 0x1]
	b _0809F940
	.pool
_0809F90C:
	bl GetSafariZoneFlag
	cmp r0, 0
	beq _0809F918
	bl DisplaySafariBallsWindow
_0809F918:
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0809F926
	bl DisplayPyramidFloorWindow
_0809F926:
	ldr r1, =gUnknown_02037619
	b _0809F940
	.pool
_0809F930:
	ldr r4, =gUnknown_0203761A
	adds r0, r4, 0
	movs r1, 0x2
	bl PrintStartMenuActions
	cmp r0, 0
	beq _0809F98C
	subs r1, r4, 0x1
_0809F940:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0809F98C
	.pool
_0809F94C:
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x10
	str r1, [sp]
	ldr r1, =sNumStartMenuActions
	ldrb r1, [r1]
	str r1, [sp, 0x4]
	ldr r4, =sStartMenuCursorPos
	ldrb r1, [r4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x9
	bl sub_81983AC
	strb r0, [r4]
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl CopyWindowToVram
	movs r0, 0x1
	b _0809F98E
	.pool
_0809F98C:
	movs r0, 0
_0809F98E:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809F894

	thumb_func_start sub_809F998
sub_809F998: @ 809F998
	push {lr}
	ldr r1, =gUnknown_02037619
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
_0809F9A2:
	bl sub_809F894
	cmp r0, 0
	beq _0809F9A2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809F998

	thumb_func_start task50_startmenu
task50_startmenu: @ 809F9B4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_809F894
	cmp r0, 0x1
	bne _0809F9C8
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
_0809F9C8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task50_startmenu

	thumb_func_start sub_809F9D0
sub_809F9D0: @ 809F9D0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =gUnknown_02037619
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	ldr r4, =task50_startmenu
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r2, r5, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809F9D0

	thumb_func_start sub_809FA00
sub_809FA00: @ 809FA00
	push {lr}
	bl sub_809F894
	cmp r0, 0
	beq _0809FA12
	bl sub_80AF688
	movs r0, 0x1
	b _0809FA14
_0809FA12:
	movs r0, 0
_0809FA14:
	pop {r1}
	bx r1
	thumb_func_end sub_809FA00

	thumb_func_start sub_809FA18
sub_809FA18: @ 809FA18
	ldr r1, =gUnknown_02037619
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	ldr r1, =gUnknown_03005DB0
	ldr r0, =sub_809FA00
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_809FA18

	thumb_func_start sub_809FA34
sub_809FA34: @ 809FA34
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0809FA58
	cmp r0, 0x1
	beq _0809FA7C
	b _0809FA92
	.pool
_0809FA58:
	bl InUnionRoom
	cmp r0, 0x1
	bne _0809FA64
	bl var_800D_set_xB
_0809FA64:
	ldr r1, =gUnknown_03005DF4
	ldr r0, =HandleStartMenuInput
	str r0, [r1]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0809FA92
	.pool
_0809FA7C:
	ldr r0, =gUnknown_03005DF4
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809FA92
	adds r0, r5, 0
	bl DestroyTask
_0809FA92:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809FA34

	thumb_func_start sub_809FA9C
sub_809FA9C: @ 809FA9C
	push {lr}
	bl is_c1_link_related_active
	cmp r0, 0
	bne _0809FAB2
	bl player_bitmagic
	bl sub_808B864
	bl sub_808BCF4
_0809FAB2:
	ldr r0, =sub_809FA34
	bl sub_809F9D0
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809FA9C

	thumb_func_start HandleStartMenuInput
HandleStartMenuInput: @ 809FAC4
	push {r4,lr}
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0809FAE4
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	bl MoveMenuCursor
	ldr r1, =sStartMenuCursorPos
	strb r0, [r1]
_0809FAE4:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FAFE
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl MoveMenuCursor
	ldr r1, =sStartMenuCursorPos
	strb r0, [r1]
_0809FAFE:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809FB98
	movs r0, 0x5
	bl PlaySE
	ldr r1, =sStartMenuItems
	ldr r2, =sCurrentStartMenuActions
	ldr r0, =sStartMenuCursorPos
	ldrb r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =StartMenu_Pokedex
	cmp r1, r0
	bne _0809FB34
	movs r0, 0
	bl pokedex_count
	lsls r0, 16
	cmp r0, 0
	beq _0809FBA0
_0809FB34:
	ldr r3, =gUnknown_03005DF4
	ldr r1, =sStartMenuItems
	ldr r2, =sCurrentStartMenuActions
	ldr r0, =sStartMenuCursorPos
	ldrb r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	str r1, [r3]
	ldr r0, =StartMenu_Save
	cmp r1, r0
	beq _0809FBA0
	ldr r0, =StartMenu_Exit
	cmp r1, r0
	beq _0809FBA0
	ldr r0, =StartMenu_SafariZoneRetire
	cmp r1, r0
	beq _0809FBA0
	ldr r0, =StartMenu_BattlePyramidRetire
	cmp r1, r0
	beq _0809FBA0
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	b _0809FBA0
	.pool
_0809FB98:
	movs r0, 0xA
	ands r0, r1
	cmp r0, 0
	bne _0809FBA4
_0809FBA0:
	movs r0, 0
	b _0809FBAE
_0809FBA4:
	bl RemoveExtraStartMenuWindows
	bl sub_80A0934
	movs r0, 0x1
_0809FBAE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end HandleStartMenuInput

	thumb_func_start StartMenu_Pokedex
StartMenu_Pokedex: @ 809FBB4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FBCC
	movs r0, 0
	b _0809FBE6
	.pool
_0809FBCC:
	movs r0, 0x29
	bl IncrementGameStat
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	ldr r0, =sub_80BB534
	bl SetMainCallback2
	movs r0, 0x1
_0809FBE6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_Pokedex

	thumb_func_start StartMenu_Pokemon
StartMenu_Pokemon: @ 809FBF0
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FC08
	movs r0, 0
	b _0809FC1C
	.pool
_0809FC08:
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	ldr r0, =CB2_PartyMenuFromStartMenu
	bl SetMainCallback2
	movs r0, 0x1
_0809FC1C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_Pokemon

	thumb_func_start StartMenu_Bag
StartMenu_Bag: @ 809FC24
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FC3C
	movs r0, 0
	b _0809FC50
	.pool
_0809FC3C:
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	ldr r0, =CB2_BagMenuFromStartMenu
	bl SetMainCallback2
	movs r0, 0x1
_0809FC50:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_Bag

	thumb_func_start StartMenu_PokeNav
StartMenu_PokeNav: @ 809FC58
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FC70
	movs r0, 0
	b _0809FC84
	.pool
_0809FC70:
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	ldr r0, =CB2_PokeNav
	bl SetMainCallback2
	movs r0, 0x1
_0809FC84:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_PokeNav

	thumb_func_start StartMenu_PlayerName
StartMenu_PlayerName: @ 809FC8C
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0809FCF4
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	bl is_c1_link_related_active
	cmp r0, 0
	bne _0809FCB6
	bl InUnionRoom
	cmp r0, 0
	beq _0809FCC8
_0809FCB6:
	ldr r0, =sub_8086194
	bl sub_80C4DDC
	b _0809FCEA
	.pool
_0809FCC8:
	ldr r0, =0x000008d2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809FCE4
	ldr r0, =sub_8086194
	bl sub_80C51C4
	b _0809FCEA
	.pool
_0809FCE4:
	ldr r0, =sub_8086194
	bl sub_80C4DDC
_0809FCEA:
	movs r0, 0x1
	b _0809FCF6
	.pool
_0809FCF4:
	movs r0, 0
_0809FCF6:
	pop {r1}
	bx r1
	thumb_func_end StartMenu_PlayerName

	thumb_func_start StartMenu_Save
StartMenu_Save: @ 809FCFC
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0809FD0C
	bl RemoveExtraStartMenuWindows
_0809FD0C:
	ldr r1, =gUnknown_03005DF4
	ldr r0, =sub_809FE28
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_Save

	thumb_func_start StartMenu_Option
StartMenu_Option: @ 809FD20
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FD38
	movs r0, 0
	b _0809FD52
	.pool
_0809FD38:
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	ldr r0, =CB2_OptionsMenu
	bl SetMainCallback2
	ldr r1, =gMain
	ldr r0, =sub_8086194
	str r0, [r1, 0x8]
	movs r0, 0x1
_0809FD52:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_Option

	thumb_func_start StartMenu_Exit
StartMenu_Exit: @ 809FD64
	push {lr}
	bl RemoveExtraStartMenuWindows
	bl sub_80A0934
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end StartMenu_Exit

	thumb_func_start StartMenu_SafariZoneRetire
StartMenu_SafariZoneRetire: @ 809FD74
	push {lr}
	bl RemoveExtraStartMenuWindows
	bl sub_80A0934
	bl SafariZoneRetirePrompt
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end StartMenu_SafariZoneRetire

	thumb_func_start StartMenu_LinkModePlayerName
StartMenu_LinkModePlayerName: @ 809FD88
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FDA0
	movs r0, 0
	b _0809FDB4
	.pool
_0809FDA0:
	bl play_some_sound
	bl overworld_free_bg_tilemaps
	ldr r0, =gUnknown_03005DB4
	ldrb r0, [r0]
	ldr r1, =sub_8086194
	bl sub_80C4E74
	movs r0, 0x1
_0809FDB4:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_LinkModePlayerName

	thumb_func_start StartMenu_BattlePyramidRetire
StartMenu_BattlePyramidRetire: @ 809FDC0
	ldr r1, =gUnknown_03005DF4
	ldr r0, =sub_809FE9C
	str r0, [r1]
	movs r0, 0
	bx lr
	.pool
	thumb_func_end StartMenu_BattlePyramidRetire

	thumb_func_start sub_809FDD4
sub_809FDD4: @ 809FDD4
	push {lr}
	movs r0, 0
	movs r1, 0
	bl sub_8197DF8
	bl sub_80984F4
	ldr r0, =sub_809FA34
	bl sub_809F9D0
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809FDD4

	thumb_func_start StartMenu_BattlePyramidBag
StartMenu_BattlePyramidBag: @ 809FDF4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809FE0C
	movs r0, 0
	b _0809FE20
	.pool
_0809FE0C:
	bl play_some_sound
	bl RemoveExtraStartMenuWindows
	bl overworld_free_bg_tilemaps
	ldr r0, =sub_81C4EFC
	bl SetMainCallback2
	movs r0, 0x1
_0809FE20:
	pop {r1}
	bx r1
	.pool
	thumb_func_end StartMenu_BattlePyramidBag

	thumb_func_start sub_809FE28
sub_809FE28: @ 809FE28
	push {lr}
	bl sub_809FF28
	ldr r1, =gUnknown_03005DF4
	ldr r0, =sub_809FE44
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809FE28

	thumb_func_start sub_809FE44
sub_809FE44: @ 809FE44
	push {lr}
	bl sub_809FF4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809FE7C
	cmp r0, 0x1
	ble _0809FE94
	cmp r0, 0x2
	beq _0809FE60
	cmp r0, 0x3
	beq _0809FE7C
	b _0809FE94
_0809FE60:
	movs r0, 0
	movs r1, 0
	bl sub_8197DF8
	bl sub_809F998
	ldr r1, =gUnknown_03005DF4
	ldr r0, =HandleStartMenuInput
	str r0, [r1]
	b _0809FE94
	.pool
_0809FE7C:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197DF8
	bl sub_80984F4
	bl ScriptContext2_Disable
	bl sub_81A9EC8
	movs r0, 0x1
	b _0809FE96
_0809FE94:
	movs r0, 0
_0809FE96:
	pop {r1}
	bx r1
	thumb_func_end sub_809FE44

	thumb_func_start sub_809FE9C
sub_809FE9C: @ 809FE9C
	push {lr}
	bl sub_80A0340
	ldr r1, =gUnknown_03005DF4
	ldr r0, =sub_809FED4
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809FE9C

	thumb_func_start sub_809FEB8
sub_809FEB8: @ 809FEB8
	push {lr}
	bl sub_809F998
	ldr r1, =gUnknown_03005DF4
	ldr r0, =HandleStartMenuInput
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809FEB8

	thumb_func_start sub_809FED4
sub_809FED4: @ 809FED4
	push {lr}
	bl sub_809FF4C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809FEEC
	cmp r0, 0x1
	ble _0809FF20
	cmp r0, 0x2
	beq _0809FF00
	b _0809FF20
_0809FEEC:
	bl RemoveExtraStartMenuWindows
	ldr r1, =gUnknown_03005DF4
	ldr r0, =sub_809FEB8
	str r0, [r1]
	b _0809FF20
	.pool
_0809FF00:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197DF8
	bl sub_80984F4
	bl ScriptContext2_Disable
	ldr r0, =BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88
	bl ScriptContext1_SetupScript
	movs r0, 0x1
	b _0809FF22
	.pool
_0809FF20:
	movs r0, 0
_0809FF22:
	pop {r1}
	bx r1
	thumb_func_end sub_809FED4

	thumb_func_start sub_809FF28
sub_809FF28: @ 809FF28
	push {lr}
	bl save_serialize_map
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A00A0
	str r0, [r1]
	ldr r1, =gUnknown_02037621
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809FF28

	thumb_func_start sub_809FF4C
sub_809FF4C: @ 809FF4C
	push {lr}
	bl sub_8197224
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	beq _0809FF78
	ldr r1, =gUnknown_02037621
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gUnknown_0203761C
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	b _0809FF7A
	.pool
_0809FF78:
	movs r0, 0
_0809FF7A:
	pop {r1}
	bx r1
	thumb_func_end sub_809FF4C

	thumb_func_start sub_809FF80
sub_809FF80: @ 809FF80
	push {lr}
	bl sub_809FF28
	ldr r0, =task50_save_game
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809FF80

	thumb_func_start sub_809FF98
sub_809FF98: @ 809FF98
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldr r0, =gStringVar4
	adds r1, r2, 0
	bl StringExpandPlaceholders
	movs r0, 0
	movs r1, 0x1
	bl sub_819786C
	movs r0, 0x1
	bl AddTextPrinterForMessage_2
	ldr r1, =gUnknown_02037621
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_0203761C
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809FF98

	thumb_func_start task50_save_game
task50_save_game: @ 809FFD0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_809FF4C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	beq _0809FFFC
	cmp r1, 0x1
	bgt _0809FFEC
	cmp r1, 0
	beq _080A000A
	b _080A0000
_0809FFEC:
	cmp r1, 0x3
	bgt _080A0000
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	b _080A0000
	.pool
_0809FFFC:
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
_080A0000:
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_080A000A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task50_save_game

	thumb_func_start sub_80A0014
sub_80A0014: @ 80A0014
	push {lr}
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	pop {r0}
	bx r0
	thumb_func_end sub_80A0014

	thumb_func_start sub_80A0024
sub_80A0024: @ 80A0024
	push {lr}
	bl sub_80A0888
	pop {r0}
	bx r0
	thumb_func_end sub_80A0024

	thumb_func_start sub_80A0030
sub_80A0030: @ 80A0030
	ldr r1, =gUnknown_02037620
	movs r0, 0x3C
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80A0030

	thumb_func_start sub_80A003C
sub_80A003C: @ 80A003C
	push {lr}
	ldr r1, =gUnknown_02037620
	ldrb r0, [r1]
	subs r2, r0, 0x1
	strb r2, [r1]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A0064
	lsls r0, r2, 24
	cmp r0, 0
	beq _080A006A
	movs r0, 0
	b _080A006C
	.pool
_080A0064:
	movs r0, 0x5
	bl PlaySE
_080A006A:
	movs r0, 0x1
_080A006C:
	pop {r1}
	bx r1
	thumb_func_end sub_80A003C

	thumb_func_start sub_80A0070
sub_80A0070: @ 80A0070
	push {lr}
	ldr r1, =gUnknown_02037620
	ldrb r0, [r1]
	cmp r0, 0
	bne _080A0094
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A0098
	movs r0, 0x1
	b _080A009A
	.pool
_080A0094:
	subs r0, 0x1
	strb r0, [r1]
_080A0098:
	movs r0, 0
_080A009A:
	pop {r1}
	bx r1
	thumb_func_end sub_80A0070

	thumb_func_start sub_80A00A0
sub_80A00A0: @ 80A00A0
	push {lr}
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_819746C
	bl remove_start_menu_window_maybe
	bl sub_80A06B4
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080A00D4
	ldr r0, =BattleFrontier_BattlePyramidEmptySquare_Text_252CA7
	ldr r1, =sub_80A00EC
	bl sub_809FF98
	b _080A00DC
	.pool
_080A00D4:
	ldr r0, =gUnknown_082C87B4
	ldr r1, =sub_80A00EC
	bl sub_809FF98
_080A00DC:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A00A0

	thumb_func_start sub_80A00EC
sub_80A00EC: @ 80A00EC
	push {lr}
	bl sub_8197930
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A0108
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A00EC

	thumb_func_start sub_80A0108
sub_80A0108: @ 80A0108
	push {lr}
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080A012A
	cmp r1, 0
	bgt _080A0124
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A0168
	b _080A0174
_080A0124:
	cmp r1, 0x1
	beq _080A0168
	b _080A0174
_080A012A:
	ldr r0, =gSaveFileStatus
	ldrh r0, [r0]
	cmp r0, 0
	beq _080A0136
	cmp r0, 0x2
	bne _080A013E
_080A0136:
	ldr r0, =gDifferentSaveFile
	ldrb r0, [r0]
	cmp r0, 0
	bne _080A0158
_080A013E:
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A017C
	str r0, [r1]
	b _080A0174
	.pool
_080A0158:
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A0234
	str r0, [r1]
	b _080A0174
	.pool
_080A0168:
	bl sub_80A0024
	bl sub_80A0014
	movs r0, 0x2
	b _080A0176
_080A0174:
	movs r0, 0
_080A0176:
	pop {r1}
	bx r1
	thumb_func_end sub_80A0108

	thumb_func_start sub_80A017C
sub_80A017C: @ 80A017C
	push {lr}
	ldr r0, =gDifferentSaveFile
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080A019C
	ldr r0, =gUnknown_082C8845
	ldr r1, =sub_80A01B4
	bl sub_809FF98
	b _080A01A4
	.pool
_080A019C:
	ldr r0, =gUnknown_082C87D5
	ldr r1, =sub_80A01D0
	bl sub_809FF98
_080A01A4:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A017C

	thumb_func_start sub_80A01B4
sub_80A01B4: @ 80A01B4
	push {lr}
	movs r0, 0x1
	bl sub_8197948
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A01EC
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A01B4

	thumb_func_start sub_80A01D0
sub_80A01D0: @ 80A01D0
	push {lr}
	bl sub_8197930
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A01EC
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A01D0

	thumb_func_start sub_80A01EC
sub_80A01EC: @ 80A01EC
	push {lr}
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080A020E
	cmp r1, 0
	bgt _080A0208
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A0220
	b _080A022C
_080A0208:
	cmp r1, 0x1
	beq _080A0220
	b _080A022C
_080A020E:
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A0234
	str r0, [r1]
	b _080A022C
	.pool
_080A0220:
	bl sub_80A0024
	bl sub_80A0014
	movs r0, 0x2
	b _080A022E
_080A022C:
	movs r0, 0
_080A022E:
	pop {r1}
	bx r1
	thumb_func_end sub_80A01EC

	thumb_func_start sub_80A0234
sub_80A0234: @ 80A0234
	push {lr}
	ldr r0, =gUnknown_082C8810
	ldr r1, =sub_80A024C
	bl sub_809FF98
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A0234

	thumb_func_start sub_80A024C
sub_80A024C: @ 80A024C
	push {r4,lr}
	movs r0, 0
	bl IncrementGameStat
	bl sub_81A9E90
	ldr r4, =gDifferentSaveFile
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _080A0274
	movs r0, 0x4
	bl TrySavingData
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0
	strb r0, [r4]
	b _080A027E
	.pool
_080A0274:
	movs r0, 0
	bl TrySavingData
	lsls r0, 24
	lsrs r1, r0, 24
_080A027E:
	cmp r1, 0x1
	bne _080A0294
	ldr r0, =gUnknown_082C8832
	ldr r1, =sub_80A02B0
	bl sub_809FF98
	b _080A029C
	.pool
_080A0294:
	ldr r0, =gUnknown_082C892A
	ldr r1, =sub_80A02FC
	bl sub_809FF98
_080A029C:
	bl sub_80A0030
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A024C

	thumb_func_start sub_80A02B0
sub_80A02B0: @ 80A02B0
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080A02CA
	movs r0, 0x37
	bl PlaySE
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A02D8
	str r0, [r1]
_080A02CA:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A02B0

	thumb_func_start sub_80A02D8
sub_80A02D8: @ 80A02D8
	push {lr}
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _080A02F6
	bl sub_80A003C
	lsls r0, 24
	cmp r0, 0
	beq _080A02F6
	bl sub_80A0024
	movs r0, 0x1
	b _080A02F8
_080A02F6:
	movs r0, 0
_080A02F8:
	pop {r1}
	bx r1
	thumb_func_end sub_80A02D8

	thumb_func_start sub_80A02FC
sub_80A02FC: @ 80A02FC
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080A0316
	movs r0, 0x16
	bl PlaySE
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A0324
	str r0, [r1]
_080A0316:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A02FC

	thumb_func_start sub_80A0324
sub_80A0324: @ 80A0324
	push {lr}
	bl sub_80A0070
	lsls r0, 24
	cmp r0, 0
	beq _080A0338
	bl sub_80A0024
	movs r0, 0x3
	b _080A033A
_080A0338:
	movs r0, 0
_080A033A:
	pop {r1}
	bx r1
	thumb_func_end sub_80A0324

	thumb_func_start sub_80A0340
sub_80A0340: @ 80A0340
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A035C
	str r0, [r1]
	ldr r1, =gUnknown_02037621
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80A0340

	thumb_func_start sub_80A035C
sub_80A035C: @ 80A035C
	push {lr}
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_819746C
	bl remove_start_menu_window_maybe
	ldr r0, =BattleFrontier_BattlePyramidEmptySquare_Text_252CFB
	ldr r1, =sub_80A0388
	bl sub_809FF98
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A035C

	thumb_func_start sub_80A0388
sub_80A0388: @ 80A0388
	push {lr}
	movs r0, 0x1
	bl sub_8197948
	ldr r1, =gUnknown_0203761C
	ldr r0, =sub_80A03A4
	str r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A0388

	thumb_func_start sub_80A03A4
sub_80A03A4: @ 80A03A4
	push {lr}
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080A03C6
	cmp r1, 0
	bgt _080A03C0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A03CA
	b _080A03D2
_080A03C0:
	cmp r1, 0x1
	beq _080A03CA
	b _080A03D2
_080A03C6:
	movs r0, 0x2
	b _080A03D4
_080A03CA:
	bl sub_80A0014
	movs r0, 0x1
	b _080A03D4
_080A03D2:
	movs r0, 0
_080A03D4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A03A4

	thumb_func_start sub_80A03D8
sub_80A03D8: @ 80A03D8
	push {lr}
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_80A03D8

	thumb_func_start sub_80A03E4
sub_80A03E4: @ 80A03E4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _080A03F6
	b _080A04FC
_080A03F6:
	lsls r0, 2
	ldr r1, =_080A0404
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080A0404:
	.4byte _080A0418
	.4byte _080A0490
	.4byte _080A04A2
	.4byte _080A04D4
	.4byte _080A04F8
_080A0418:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl SetVBlankCallback
	bl remove_some_task
	movs r2, 0xA0
	lsls r2, 19
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x81000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0xC0
	lsls r2, 19
	movs r3, 0xC0
	lsls r3, 9
	mov r4, sp
	movs r6, 0
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_080A045A:
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r5
	subs r3, r5
	cmp r3, r5
	bhi _080A045A
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	b _080A04FC
	.pool
_080A0490:
	bl ResetSpriteData
	bl ResetTasks
	bl ResetPaletteFade
	bl dp12_8087EA4
	b _080A04FC
_080A04A2:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085105A8
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085105AC
	bl InitWindows
	movs r0, 0
	movs r1, 0x8
	movs r2, 0xE0
	bl box_border_load_tiles_and_pal
	movs r0, 0xF0
	bl sub_81978B0
	b _080A04FC
	.pool
_080A04D4:
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =sub_80A03D8
	bl SetVBlankCallback
	movs r0, 0x1
	bl EnableInterrupts
	b _080A04FC
	.pool
_080A04F8:
	movs r0, 0x1
	b _080A0506
_080A04FC:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
_080A0506:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A03E4

	thumb_func_start sub_80A0514
sub_80A0514: @ 80A0514
	push {lr}
	ldr r0, =gMain+0x438
	bl sub_80A03E4
	cmp r0, 0
	beq _080A052E
	ldr r0, =sub_80A0550
	movs r1, 0x50
	bl CreateTask
	ldr r0, =sub_80A0540
	bl SetMainCallback2
_080A052E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0514

	thumb_func_start sub_80A0540
sub_80A0540: @ 80A0540
	push {lr}
	bl RunTasks
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_80A0540

	thumb_func_start sub_80A0550
sub_80A0550: @ 80A0550
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080A0570
	b _080A06A8
_080A0570:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x6
	bls _080A057A
	b _080A06A8
_080A057A:
	lsls r0, 2
	ldr r1, =_080A0590
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080A0590:
	.4byte _080A05AC
	.4byte _080A0630
	.4byte _080A063C
	.4byte _080A065C
	.4byte _080A0670
	.4byte _080A0688
	.4byte _080A0698
_080A05AC:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_SavingDontTurnOffPower
	movs r4, 0
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r6, 0x1
	str r6, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0xFF
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x8
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A0620
	bl InUnionRoom
	cmp r0, 0
	beq _080A0620
	bl sub_800A07C
	cmp r0, 0
	beq _080A061C
	strh r6, [r5]
	b _080A06A8
	.pool
_080A061C:
	movs r0, 0x5
	b _080A06A6
_080A0620:
	ldr r0, =gSoftResetDisabled
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	b _080A06A6
	.pool
_080A0630:
	bl sub_8076D5C
	bl sub_8153430
	movs r0, 0x2
	b _080A06A6
_080A063C:
	bl sub_8153474
	lsls r0, 24
	cmp r0, 0
	beq _080A06A8
	bl sav2_gender2_inplace_and_xFE
	movs r0, 0x3
	strh r0, [r5]
	ldr r1, =gSoftResetDisabled
	movs r0, 0
	strb r0, [r1]
	b _080A06A8
	.pool
_080A065C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	movs r0, 0x4
	b _080A06A6
_080A0670:
	bl FreeAllWindowBuffers
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
	b _080A06A8
	.pool
_080A0688:
	ldr r0, =sub_8153688
	movs r1, 0x5
	bl CreateTask
	movs r0, 0x6
	b _080A06A6
	.pool
_080A0698:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080A06A8
	movs r0, 0x3
_080A06A6:
	strh r0, [r5]
_080A06A8:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0550

	thumb_func_start sub_80A06B4
sub_80A06B4: @ 80A06B4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r0, =gUnknown_085105BC
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	ldr r0, =0x00000861
	mov r10, r0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080A06EC
	add r0, sp, 0xC
	ldrb r1, [r0, 0x4]
	subs r1, 0x2
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =0xffffff00
	ldr r0, [sp, 0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x10]
_080A06EC:
	ldr r6, =gUnknown_02037622
	add r0, sp, 0xC
	bl AddWindow
	strb r0, [r6]
	ldrb r0, [r6]
	movs r1, 0
	bl sub_81973FC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	movs r1, 0x4
	mov r9, r1
	cmp r0, 0
	bne _080A0710
	movs r0, 0x8
	mov r9, r0
_080A0710:
	movs r4, 0x1
	ldr r5, =gStringVar4
	movs r0, 0x3
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_819A344
	ldrb r0, [r6]
	str r4, [sp]
	movs r1, 0xFF
	mov r8, r1
	str r1, [sp, 0x4]
	movs r7, 0
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0
	bl PrintTextOnWindow
	movs r4, 0x11
	ldrb r0, [r6]
	ldr r2, =gText_SavingPlayer
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	adds r1, r5, 0
	mov r2, r9
	bl sub_819A344
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	ldrb r0, [r6]
	lsls r2, 16
	lsrs r2, 16
	adds r1, r5, 0
	movs r3, 0x11
	bl sub_819A024
	movs r4, 0x21
	ldrb r0, [r6]
	ldr r2, =gText_SavingBadges
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0x4
	adds r1, r5, 0
	mov r2, r9
	bl sub_819A344
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	ldrb r0, [r6]
	lsls r3, r2, 24
	lsrs r3, 24
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl PrintTextOnWindow
	mov r0, r10
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080A0802
	movs r4, 0x31
	ldrb r0, [r6]
	ldr r2, =gText_SavingPokedex
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0x1
	adds r1, r5, 0
	mov r2, r9
	bl sub_819A344
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	ldrb r0, [r6]
	lsls r3, r2, 24
	lsrs r3, 24
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl PrintTextOnWindow
_080A0802:
	adds r4, 0x10
	ldrb r0, [r6]
	ldr r2, =gText_SavingTime
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0x2
	adds r1, r5, 0
	mov r2, r9
	bl sub_819A344
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	ldrb r0, [r6]
	lsls r3, r2, 24
	lsrs r3, 24
	str r4, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl PrintTextOnWindow
	ldrb r0, [r6]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A06B4

	thumb_func_start sub_80A0888
sub_80A0888: @ 80A0888
	push {r4,lr}
	ldr r4, =gUnknown_02037622
	ldrb r0, [r4]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0888

	thumb_func_start sub_80A08A4
sub_80A08A4: @ 80A08A4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080A08C0
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_080A08C0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A08A4

	thumb_func_start sub_80A08CC
sub_80A08CC: @ 80A08CC
	push {r4,r5,lr}
	ldr r0, =sub_8153688
	movs r1, 0x5
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0, 0xC]
	ldr r0, =sub_80A08A4
	movs r1, 0x6
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	strh r4, [r1, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A08CC

	thumb_func_start sub_80A0914
sub_80A0914: @ 80A0914
	push {lr}
	bl GetStartMenuWindowId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_819746C
	bl remove_start_menu_window_maybe
	bl sub_80984F4
	bl ScriptContext2_Disable
	pop {r0}
	bx r0
	thumb_func_end sub_80A0914

	thumb_func_start sub_80A0934
sub_80A0934: @ 80A0934
	push {lr}
	movs r0, 0x5
	bl PlaySE
	bl sub_80A0914
	pop {r0}
	bx r0
	thumb_func_end sub_80A0934

	thumb_func_start AppendToList
AppendToList: @ 80A0944
	ldrb r3, [r1]
	adds r0, r3
	strb r2, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bx lr
	thumb_func_end AppendToList

	.align 2, 0 @ Don't pad with nop.
