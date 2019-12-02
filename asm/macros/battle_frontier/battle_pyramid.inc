@ TODO: Add explanatory comments

    @ 
    .macro pyramid_init
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT
    special CallBattlePyramidFunction 
    .endm

    @  
    .macro pyramid_get data:req
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_GET_DATA
    setvar VAR_0x8005, \data
    special CallBattlePyramidFunction
    .endm

    @   
    .macro pyramid_set data:req, val:req
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_DATA
    setvar VAR_0x8005, \data
    setvar VAR_0x8006, \val
    special CallBattlePyramidFunction
    .endm

    @ 
    .macro pyramid_save challengeStatus:req
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SAVE
    setvar VAR_0x8005, \challengeStatus
    special CallBattlePyramidFunction    
    .endm

    @  
    .macro pyramid_setprize
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_PRIZE
    special CallBattlePyramidFunction
    .endm

    @  
    .macro pyramid_seedfloor
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SEED_FLOOR
    special CallBattlePyramidFunction
    .endm

    @   
    .macro pyramid_setitem
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_ITEM
    special CallBattlePyramidFunction
    .endm

    @  
    .macro pyramid_hideitem
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_HIDE_ITEM
    special CallBattlePyramidFunction
    .endm

    @ 
    .macro pyramid_inittrainers
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_INIT_TRAINERS
    special CallBattlePyramidFunction 
    .endm

    @  
    .macro pyramid_showhint
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SHOW_HINT_TEXT
    special CallBattlePyramidFunction
    .endm

    @ VAR_RESULT is 1 if on a Pyramid floor, 2 if on the Pyramid peak   
    .macro pyramid_inchallenge
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_IS_IN
    special CallBattlePyramidFunction
    .endm   

    @  
    .macro pyramid_updatelight radius:req, mode:req
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
    setvar VAR_0x8005, \radius
    setvar VAR_0x8006, \mode
    special CallBattlePyramidFunction
    .endm  

    @  
    .macro pyramid_clearhelditems
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_CLEAR_HELD_ITEMS
    special CallBattlePyramidFunction
    .endm

    @ BATTLE_PYRAMID_FUNC_SET_FLOOR_PALETTE 
    .macro pyramid_setfloorpal
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_SET_FLOOR_PALETTE
    special CallBattlePyramidFunction
    .endm             

    @      
    .macro pyramid_healparty
    setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_RESTORE_PARTY
    special CallBattlePyramidFunction 
    .endm
