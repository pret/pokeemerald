SecretBase_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_OnResume
	.byte 0

SecretBase_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

SecretBase_OnTransition:
	call SecretBase_EventScript_SetDecorationFlags
	special SetSecretBaseOwnerGfxId
	special InitSecretBaseVars
	end

SecretBase_OnFrame:
	map_script_2 VAR_INIT_SECRET_BASE, 0, SecretBase_EventScript_FirstEntrance
	.2byte 0

SecretBase_OnResume:
	setstepcallback STEP_CB_SECRET_BASE
	end

SecretBase_EventScript_PC::
	lockall
	playse SE_PC_LOGIN
	message SecretBase_Text_BootUpPC
	dofieldeffect FLDEFF_PCTURN_ON
	waitstate
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCShowMainMenu::
	message SecretBase_Text_WhatWouldYouLikeToDo
	waitmessage
	goto_if_set FLAG_SECRET_BASE_REGISTRY_ENABLED, SecretBase_EventScript_PCMainMenuWithRegister
	goto SecretBase_EventScript_PCMainMenuWithoutRegister
	end

SecretBase_EventScript_PCCancel::
	lockall
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCMainMenuWithRegister::
	multichoice 0, 0, MULTI_BASE_PC_WITH_REGISTRY, FALSE
	switch VAR_RESULT
	case 0, SecretBase_EventScript_PCDecorationMenu
	case 1, SecretBase_EventScript_PCPackUp
	case 2, SecretBase_EventScript_PCRegistryMenu
	case 3, SecretBase_EventScript_PCTurnOff
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_PCMainMenuWithoutRegister::
	multichoice 0, 0, MULTI_BASE_PC_NO_REGISTRY, FALSE
	switch VAR_RESULT
	case 0, SecretBase_EventScript_PCDecorationMenu
	case 1, SecretBase_EventScript_PCPackUp
	case 2, SecretBase_EventScript_PCTurnOff
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_PCPackUp::
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_PCShowMainMenu
	closemessage
	special MoveOutOfSecretBase
	releaseall
	end

SecretBase_EventScript_PCDecorationMenu::
	special ShowSecretBaseDecorationMenu
	end

SecretBase_EventScript_PCRegistryMenu::
	special ShowSecretBaseRegistryMenu
	end

SecretBase_EventScript_RecordMixingPC::
	lockall
	message SecretBase_Text_BootUpPC
	playse SE_PC_LOGIN
	dofieldeffect FLDEFF_PCTURN_ON
	waitstate
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	goto SecretBase_EventScript_PCRegisterMenu
	end

SecretBase_EventScript_PCRegisterMenu::
	message SecretBase_Text_WhatWouldYouLikeToDo
	waitmessage
	multichoice 0, 0, MULTI_REGISTER_MENU, FALSE
	switch VAR_RESULT
	case 0, SecretBase_EventScript_PCRegister
	case 1, SecretBase_EventScript_PCRegistryMenu
	case 2, SecretBase_EventScript_PCRegistryInfo
	case 3, SecretBase_EventScript_PCTurnOff
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_ShowRegisterMenu::
	lockall
	goto SecretBase_EventScript_PCRegisterMenu
	end

SecretBase_EventScript_PCRegister::
	special GetCurSecretBaseRegistrationValidity
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_AlreadyRegistered
	goto_if_eq VAR_RESULT, 2, SecretBase_EventScript_CantRegisterTooManyBases
	special CopyCurSecretBaseOwnerName_StrVar1
	msgbox SecretBase_Text_WantToRegisterSecretBase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_PCRegisterMenu
	msgbox SecretBase_Text_RegistrationCompleted, MSGBOX_SIGN
	special ToggleCurSecretBaseRegistry
	special DoSecretBasePCTurnOffEffect
	releaseall
	end

SecretBase_EventScript_AlreadyRegistered::
	msgbox SecretBase_Text_AlreadyRegisteredDelete, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_PCRegisterMenu
	msgbox SecretBase_Text_DataUnregistered, MSGBOX_SIGN
	special ToggleCurSecretBaseRegistry
	special DoSecretBasePCTurnOffEffect
	releaseall
	end

SecretBase_EventScript_CantRegisterTooManyBases::
	msgbox SecretBase_Text_TooManyBasesDeleteSome, MSGBOX_SIGN
	special DoSecretBasePCTurnOffEffect
	closemessage
	releaseall
	end

SecretBase_EventScript_PCRegistryInfo::
	msgbox SecretBase_Text_RegistryInfo, MSGBOX_DEFAULT
	goto SecretBase_EventScript_PCRegisterMenu
	end

SecretBase_EventScript_PCTurnOff::
	special DoSecretBasePCTurnOffEffect
	closemessage
	releaseall
	end

@ Unused
SecretBase_EventScript_Poster::
	special CheckInteractedWithFriendsPosterDecor
	end

@ Unused
SecretBase_EventScript_FurnitureBottom::
	special CheckInteractedWithFriendsFurnitureBottom
	end

@ Unused
SecretBase_EventScript_FurnitureMiddle::
	special CheckInteractedWithFriendsFurnitureMiddle
	end

@ Unused
SecretBase_EventScript_FurnitureTop::
	special CheckInteractedWithFriendsFurnitureTop
	end

SecretBase_EventScript_SandOrnament::
	special CheckInteractedWithFriendsSandOrnament
	dofieldeffect FLDEFF_SAND_PILLAR
	waitstate
	end

SecretBase_EventScript_ShieldOrToyTV::
	special InteractWithShieldOrTVDecoration
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_BattleTowerShield
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_ToyTV
	goto_if_eq VAR_RESULT, 2, SecretBase_EventScript_SeedotTV
	goto_if_eq VAR_RESULT, 3, SecretBase_EventScript_SkittyTV
	end

SecretBase_EventScript_BattleTowerShield::
	msgbox SecretBase_Text_BattleTowerShield, MSGBOX_SIGN
	end

SecretBase_EventScript_ToyTV::
	msgbox SecretBase_Text_ToyTV, MSGBOX_SIGN
	end

SecretBase_EventScript_SeedotTV::
	msgbox SecretBase_Text_SeedotTV, MSGBOX_SIGN
	end

SecretBase_EventScript_SkittyTV::
	msgbox SecretBase_Text_SkittyTV, MSGBOX_SIGN
	end

SecretBase_Text_SmallIndentInWall::
	.string "Il y a une petite fissure dans le mur.$"

SecretBase_Text_IndentUseSecretPower::
	.string "Il y a une petite fissure dans le mur.\p"
	.string "Voulez-vous utiliser FORCE CACHEE?$"

SecretBase_Text_DiscoveredSmallCavern::
	.string "Une petite caverne a été découverte!$"

SecretBase_Text_WantToMakeYourSecretBaseHere:
	.string "Créer une BASE SECRETE ici?$"
