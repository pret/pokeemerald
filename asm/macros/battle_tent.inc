@ TODO: Add explanatory comments

@ Verdanturf Tent

    @   
    .macro verdanturftent_init
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_INIT
    special CallVerdanturfTentFunction
    .endm

    @  
    .macro verdanturftent_getprize
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_GET_PRIZE
    special CallVerdanturfTentFunction
    .endm

    @ Unused. 
    .macro verdanturftent_setprize
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_SET_PRIZE
    special CallVerdanturfTentFunction
    .endm

    @ Unused. 
    .macro verdanturftent_setopponentgfx
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_SET_OPPONENT_GFX
    special CallVerdanturfTentFunction
    .endm

    @ Buffers the opponents intro speech to STR_VAR_4. Despite being a Verdanturf Tent function, it serves the same purpose for all 3 tents. 
    .macro battletent_getopponentintro
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_GET_OPPONENT_INTRO
    special CallVerdanturfTentFunction
    .endm

    @ 
    .macro verdanturftent_save challengeStatus:req
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_SAVE
    setvar VAR_0x8005, \challengeStatus
    special CallVerdanturfTentFunction  
    .endm           

    @   
    .macro verdanturftent_setrandomprize
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_SET_RANDOM_PRIZE
    special CallVerdanturfTentFunction
    .endm

    @     
    .macro verdanturftent_giveprize
    setvar VAR_0x8004, VERDANTURF_TENT_FUNC_GIVE_PRIZE
    special CallVerdanturfTentFunction
    .endm  


@ Fallarbor Tent

    @  
    .macro fallarbortent_init
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_INIT
    special CallFallarborTentFunction
    .endm

    @  
    .macro fallarbortent_getprize
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GET_PRIZE
    special CallFallarborTentFunction
    .endm

    @ Unused.
    .macro fallarbortent_setprize
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SET_PRIZE
    special CallFallarborTentFunction
    .endm

    @    
    .macro fallarbortent_save challengeStatus:req
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SAVE
    setvar VAR_0x8005, \challengeStatus
    special CallFallarborTentFunction
    .endm   

    @   
    .macro fallarbortent_setrandomprize
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SET_RANDOM_PRIZE
    special CallFallarborTentFunction
    .endm

    @  
    .macro fallarbortent_giveprize
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GIVE_PRIZE
    special CallFallarborTentFunction
    .endm    

    @  
    .macro fallarbortent_getopponentname
    setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GET_OPPONENT_NAME
    special CallFallarborTentFunction
    .endm 


@ Slateport Tent

    @     
    .macro slateporttent_init
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_INIT
    special CallSlateportTentFunction
    .endm

    @   
    .macro slateporttent_getprize
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GET_PRIZE
    special CallSlateportTentFunction
    .endm

    @ Unused.
    .macro slateporttent_setprize
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SET_PRIZE
    special CallSlateportTentFunction
    .endm

    @    
    .macro slateporttent_save challengeStatus:req
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SAVE
    setvar VAR_0x8005, \challengeStatus
    special CallSlateportTentFunction
    .endm   

    @  
    .macro slateporttent_setrandomprize
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SET_RANDOM_PRIZE
    special CallSlateportTentFunction
    .endm

    @   
    .macro slateporttent_giveprize
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GIVE_PRIZE
    special CallSlateportTentFunction
    .endm

    @   
    .macro slateporttent_rentmons
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SELECT_RENT_MONS
    special CallSlateportTentFunction
    .endm

    @    
    .macro slateporttent_swapmons
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SWAP_RENT_MONS
    special CallSlateportTentFunction
    .endm

    @       
    .macro slateporttent_generateopponentmons
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GENERATE_OPPONENT_MONS
    special CallSlateportTentFunction
    .endm 

    @   
    .macro slateporttent_generaterentalmons
    setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GENERATE_RENTAL_MONS
    special CallSlateportTentFunction
    .endm

