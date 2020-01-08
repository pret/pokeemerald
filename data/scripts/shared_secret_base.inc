SecretBase_MapScripts::
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_OnWarp
    map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_OnFrame
    map_script MAP_SCRIPT_ON_RESUME, SecretBase_OnResume
    .byte 0

SecretBase_OnWarp: @ 823B498
    map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
    .2byte 0

SecretBase_OnTransition: @ 823B4A2
    call SecretBase_EventScript_SetDecorationFlags
    special SetSecretBaseOwnerGfxId
    special InitSecretBaseVars
    end

SecretBase_OnFrame: @ 823B4AE
    map_script_2 VAR_INIT_SECRET_BASE, 0, SecretBase_EventScript_FirstEntrance
    .2byte 0

SecretBase_OnResume: @ 823B4B8
    setstepcallback STEP_CB_SECRET_BASE
    end

SecretBase_EventScript_PC:: @ 823B4BB
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

SecretBase_EventScript_PCShowMainMenu:: @ 823B4D3
    message SecretBase_Text_WhatWouldYouLikeToDo
    waitmessage
    goto_if_set FLAG_SECRET_BASE_REGISTRY_ENABLED, SecretBase_EventScript_PCMainMenuWithRegister
    goto SecretBase_EventScript_PCMainMenuWithoutRegister
    end

SecretBase_EventScript_PCCancel:: @ 823B4E8
    lockall
    goto SecretBase_EventScript_PCShowMainMenu
    end

SecretBase_EventScript_PCMainMenuWithRegister:: @ 823B4EF
    multichoice 0, 0, MULTI_BASE_PC_WITH_REGISTRY, 0
    switch VAR_RESULT
    case 0, SecretBase_EventScript_PCDecorationMenu
    case 1, SecretBase_EventScript_PCPackUp
    case 2, SecretBase_EventScript_PCRegistryMenu
    case 3, SecretBase_EventScript_PCTurnOff
    case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
    end

SecretBase_EventScript_PCMainMenuWithoutRegister:: @ 823B531
    multichoice 0, 0, MULTI_BASE_PC_NO_REGISTRY, 0
    switch VAR_RESULT
    case 0, SecretBase_EventScript_PCDecorationMenu
    case 1, SecretBase_EventScript_PCPackUp
    case 2, SecretBase_EventScript_PCTurnOff
    case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
    end

SecretBase_EventScript_PCPackUp:: @ 823B568
    msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SecretBase_EventScript_PCShowMainMenu
    closemessage
    special MoveOutOfSecretBase
    releaseall
    end

SecretBase_EventScript_PCDecorationMenu:: @ 823B581
    special ShowSecretBaseDecorationMenu
    end

SecretBase_EventScript_PCRegistryMenu:: @ 823B585
    special ShowSecretBaseRegistryMenu
    end

SecretBase_EventScript_RecordMixingPC:: @ 823B589
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

SecretBase_EventScript_PCRegisterMenu:: @ 823B5A1
    message SecretBase_Text_WhatWouldYouLikeToDo
    waitmessage
    multichoice 0, 0, MULTI_REGISTER_MENU, 0
    switch VAR_RESULT
    case 0, SecretBase_EventScript_PCRegister
    case 1, SecretBase_EventScript_PCRegistryMenu
    case 2, SecretBase_EventScript_PCRegistryInfo
    case 3, SecretBase_EventScript_PCTurnOff
    case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
    end

SecretBase_EventScript_ShowRegisterMenu:: @ 823B5E9
    lockall
    goto SecretBase_EventScript_PCRegisterMenu
    end

SecretBase_EventScript_PCRegister:: @ 823B5F0
    special GetCurSecretBaseRegistrationValidity
    compare VAR_RESULT, 1
    goto_if_eq SecretBase_EventScript_AlreadyRegistered
    compare VAR_RESULT, 2
    goto_if_eq SecretBase_EventScript_CantRegisterTooManyBases
    special CopyCurSecretBaseOwnerName_StrVar1
    msgbox SecretBase_Text_WantToRegisterSecretBase, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SecretBase_EventScript_PCRegisterMenu
    msgbox SecretBase_Text_RegistrationCompleted, MSGBOX_SIGN
    special ToggleCurSecretBaseRegistry
    special DoSecretBasePCTurnOffEffect
    releaseall
    end

SecretBase_EventScript_AlreadyRegistered:: @ 823B62F
    msgbox SecretBase_Text_AlreadyRegisteredDelete, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SecretBase_EventScript_PCRegisterMenu
    msgbox SecretBase_Text_DataUnregistered, MSGBOX_SIGN
    special ToggleCurSecretBaseRegistry
    special DoSecretBasePCTurnOffEffect
    releaseall
    end

SecretBase_EventScript_CantRegisterTooManyBases:: @ 823B652
    msgbox SecretBase_Text_TooManyBasesDeleteSome, MSGBOX_SIGN
    special DoSecretBasePCTurnOffEffect
    closemessage
    releaseall
    end

SecretBase_EventScript_PCRegistryInfo:: @ 823B660
    msgbox SecretBase_Text_RegistryInfo, MSGBOX_DEFAULT
    goto SecretBase_EventScript_PCRegisterMenu
    end

SecretBase_EventScript_PCTurnOff:: @ 823B66E
    special DoSecretBasePCTurnOffEffect
    closemessage
    releaseall
    end

@ Unused
SecretBase_EventScript_Poster:: @ 823B674
    special CheckInteractedWithFriendsPosterDecor
    end

@ Unused
SecretBase_EventScript_FurnitureBottom:: @ 823B678
    special CheckInteractedWithFriendsFurnitureBottom
    end

@ Unused
SecretBase_EventScript_FurnitureMiddle:: @ 823B67C
    special CheckInteractedWithFriendsFurnitureMiddle
    end

@ Unused
SecretBase_EventScript_FurnitureTop:: @ 823B680
    special CheckInteractedWithFriendsFurnitureTop
    end

SecretBase_EventScript_SandOrnament:: @ 823B684
    special CheckInteractedWithFriendsSandOrnament
    dofieldeffect FLDEFF_SAND_PILLAR
    waitstate
    end

SecretBase_EventScript_ShieldOrToyTV:: @ 823B68C
    special InteractWithShieldOrTVDecoration
    compare VAR_RESULT, 0
    goto_if_eq SecretBase_EventScript_BattleTowerShield
    compare VAR_RESULT, 1
    goto_if_eq SecretBase_EventScript_ToyTV
    compare VAR_RESULT, 2
    goto_if_eq SecretBase_EventScript_SeedotTV
    compare VAR_RESULT, 3
    goto_if_eq SecretBase_EventScript_SkittyTV
    end

SecretBase_EventScript_BattleTowerShield:: @ 823B6BC
    msgbox SecretBase_Text_BattleTowerShield, MSGBOX_SIGN
    end

SecretBase_EventScript_ToyTV:: @ 823B6C5
    msgbox SecretBase_Text_ToyTV, MSGBOX_SIGN
    end

SecretBase_EventScript_SeedotTV:: @ 823B6CE
    msgbox SecretBase_Text_SeedotTV, MSGBOX_SIGN
    end

SecretBase_EventScript_SkittyTV:: @ 823B6D7
    msgbox SecretBase_Text_SkittyTV, MSGBOX_SIGN
    end

SecretBase_Text_SmallIndentInWall:: @ 823B6E0
    .string "There's a small indent in the wall.$"

SecretBase_Text_IndentUseSecretPower:: @ 823B704
    .string "There's a small indent in the wall.\p"
    .string "Use the SECRET POWER?$"

SecretBase_Text_DiscoveredSmallCavern:: @ 823B73E
    .string "Discovered a small cavern!$"

SecretBase_Text_WantToMakeYourSecretBaseHere: @ 823B759
    .string "Want to make your SECRET BASE here?$"
