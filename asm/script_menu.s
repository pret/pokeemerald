	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80E2878
sub_80E2878: @ 80E2878
	push {lr}
	ldr r2, =gSpecialVar_Result
	ldrh r0, [r2]
	cmp r0, 0x7F
	beq _080E288C
	ldr r0, =gUnknown_03001124
	ldrh r1, [r2]
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r2]
_080E288C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2878

	thumb_func_start task_picbox
task_picbox: @ 80E2898
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
	cmp r0, 0x1
	beq _080E28F8
	cmp r0, 0x1
	bgt _080E28C0
	cmp r0, 0
	beq _080E28DE
	b _080E28F8
	.pool
_080E28C0:
	cmp r0, 0x2
	beq _080E28CA
	cmp r0, 0x3
	beq _080E28EC
	b _080E28F8
_080E28CA:
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r1, [r4, 0xC]
	bl FreeResourcesAndDestroySprite
_080E28DE:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080E28F8
	.pool
_080E28EC:
	ldrb r0, [r4, 0x12]
	bl sub_80E2A78
	adds r0, r5, 0
	bl DestroyTask
_080E28F8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_picbox

	thumb_func_start ScriptMenu_ShowPokemonPic
ScriptMenu_ShowPokemonPic: @ 80E2900
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r4, =task_picbox
	adds r0, r4, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080E29B8
	lsls r1, r7, 19
	movs r0, 0xA0
	lsls r0, 14
	adds r1, r0
	asrs r1, 16
	lsls r2, r6, 19
	adds r2, r0
	asrs r2, 16
	mov r0, r8
	movs r3, 0
	bl CreateMonSprite_PicBox
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x8
	movs r3, 0x8
	bl CreateWindowFromRect
	ldr r1, =gTasks
	lsls r3, r4, 2
	adds r3, r4
	lsls r3, 3
	adds r3, r1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r3, 0x12]
	strh r1, [r3, 0x8]
	mov r0, r8
	strh r0, [r3, 0xA]
	strh r5, [r3, 0xC]
	ldr r4, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =SpriteCallbackDummy
	str r2, [r0]
	adds r1, r4
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r0, [r3, 0x12]
	movs r1, 0x1
	bl SetStandardWindowBorderStyle
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	b _080E29BA
	.pool
_080E29B8:
	movs r0, 0
_080E29BA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ScriptMenu_ShowPokemonPic

	thumb_func_start ScriptMenu_GetPicboxWaitFunc
ScriptMenu_GetPicboxWaitFunc: @ 80E29C4
	push {lr}
	ldr r0, =task_picbox
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080E29F4
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r0, =sub_80E29FC
	b _080E29F6
	.pool
_080E29F4:
	movs r0, 0
_080E29F6:
	pop {r1}
	bx r1
	thumb_func_end ScriptMenu_GetPicboxWaitFunc

	thumb_func_start sub_80E29FC
sub_80E29FC: @ 80E29FC
	push {lr}
	ldr r0, =task_picbox
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080E2A14
	movs r0, 0
	b _080E2A16
	.pool
_080E2A14:
	movs r0, 0x1
_080E2A16:
	pop {r1}
	bx r1
	thumb_func_end sub_80E29FC

	thumb_func_start CreateWindowFromRect
CreateWindowFromRect: @ 80E2A1C
	push {r4,r5,lr}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsls r5, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x80
	lsls r0, 17
	adds r4, r0
	lsrs r4, 24
	adds r5, r0
	lsrs r5, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x64
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl CreateWindowTemplate
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	add r0, sp, 0x18
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CreateWindowFromRect

	thumb_func_start sub_80E2A78
sub_80E2A78: @ 80E2A78
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8198070
	adds r0, r4, 0
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80E2A78

	thumb_func_start sub_80E2A94
sub_80E2A94: @ 80E2A94
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x4A
	cmp r0, 0x5
	bhi _080E2B70
	lsls r0, 2
	ldr r1, =_080E2AB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E2AB0:
	.4byte _080E2B40
	.4byte _080E2B08
	.4byte _080E2AD8
	.4byte _080E2AC8
	.4byte _080E2AE8
	.4byte _080E2AF8
_080E2AC8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBAC
	b _080E2B12
	.pool
_080E2AD8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BB9C
	b _080E2B12
	.pool
_080E2AE8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBBC
	b _080E2B12
	.pool
_080E2AF8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBCC
	b _080E2B12
	.pool
_080E2B08:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBEC
_080E2B12:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
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
	bl AddTextPrinterParameterized2
	b _080E2B70
	.pool
_080E2B40:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBE0
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
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
	bl AddTextPrinterParameterized2
_080E2B70:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2A94

	thumb_func_start sp106_CreateStartMenu
sp106_CreateStartMenu: @ 80E2B7C
	push {lr}
	ldr r0, =Task_HandleMultichoiceInput
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E2BA4
	ldr r1, =gSpecialVar_Result
	movs r0, 0xFF
	strh r0, [r1]
	bl CreateStartMenu
	movs r0, 0x1
	b _080E2BA6
	.pool
_080E2BA4:
	movs r0, 0
_080E2BA6:
	pop {r1}
	bx r1
	thumb_func_end sp106_CreateStartMenu

	thumb_func_start CreateStartMenu
CreateStartMenu: @ 80E2BAC
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x15
	movs r1, 0
	movs r2, 0x7
	movs r3, 0x12
	bl CreateWindowFromRect
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r2, =gText_MenuOptionPokedex
	movs r0, 0x9
	str r0, [sp]
	movs r5, 0xFF
	str r5, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r2, =gText_MenuOptionPokemon
	movs r0, 0x19
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r2, =gText_MenuOptionBag
	movs r0, 0x29
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r2, =gText_MenuOptionPokenav
	movs r0, 0x39
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	movs r0, 0x49
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r2, =gText_MenuOptionSave
	movs r0, 0x59
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r2, =gText_MenuOptionOption
	movs r0, 0x69
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r2, =gText_MenuOptionExit
	movs r0, 0x79
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	movs r0, 0x10
	str r0, [sp]
	movs r0, 0x8
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x9
	bl sub_81983AC
	movs r0, 0
	movs r1, 0x8
	adds r2, r4, 0
	movs r3, 0x56
	bl sub_80E2CC4
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateStartMenu

	thumb_func_start sub_80E2CC4
sub_80E2CC4: @ 80E2CC4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r1, =gUnknown_02039F90
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, =Task_HandleMultichoiceInput
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r4, [r1, 0x10]
	strh r0, [r1, 0x12]
	strh r5, [r1, 0x14]
	strh r6, [r1, 0x16]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2CC4

	thumb_func_start display_text_and_get_width_internal
display_text_and_get_width_internal: @ 80E2D10
	push {lr}
	sub sp, 0x40
	adds r1, r0, 0
	mov r0, sp
	bl StringExpandPlaceholders
	movs r0, 0x1
	mov r1, sp
	movs r2, 0
	bl GetStringWidth
	add sp, 0x40
	pop {r1}
	bx r1
	thumb_func_end display_text_and_get_width_internal

	thumb_func_start display_text_and_get_width
display_text_and_get_width: @ 80E2D2C
	push {r4,lr}
	adds r4, r1, 0
	bl display_text_and_get_width_internal
	cmp r0, r4
	bge _080E2D3A
	adds r0, r4, 0
_080E2D3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end display_text_and_get_width

	thumb_func_start convert_pixel_width_to_tile_width
convert_pixel_width_to_tile_width: @ 80E2D40
	push {lr}
	adds r1, r0, 0
	adds r0, 0x9
	cmp r0, 0
	bge _080E2D4C
	adds r0, 0x7
_080E2D4C:
	asrs r0, 3
	adds r0, 0x1
	cmp r0, 0x1C
	ble _080E2D56
	movs r0, 0x1C
_080E2D56:
	pop {r1}
	bx r1
	thumb_func_end convert_pixel_width_to_tile_width

	thumb_func_start sub_80E2D5C
sub_80E2D5C: @ 80E2D5C
	push {lr}
	adds r2, r0, 0
	adds r0, r2, r1
	cmp r0, 0x1C
	ble _080E2D70
	movs r0, 0x1C
	subs r2, r0, r1
	cmp r2, 0
	bge _080E2D70
	movs r2, 0
_080E2D70:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80E2D5C

	.align 2, 0 @ Don't pad with nop.
