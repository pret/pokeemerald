@ TODO: Add explanatory comments to macros

	@ Initialize the Battle Factory challenge
	.macro factory_init
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_INIT
	special CallBattleFactoryFunction
	.endm

	@ Get the value of some FACTORY_DATA_*. See GetBattleFactoryData for the data types that can be retrieved
	.macro factory_get data:req
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleFactoryFunction
	.endm

	@ Set some FACTORY_DATA_* to val. See SetBattleFactoryData for the data types that can be set
	.macro factory_set data:req, val=0xFFFF
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val == 0xFFFF
	@ argument not provided
	.elseif \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallBattleFactoryFunction
	.endm

	@ Save the game and set the challenge status
	.macro factory_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleFactoryFunction
	.endm

	@  
	.macro factory_rentmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SELECT_RENT_MONS
	special CallBattleFactoryFunction
	.endm

	@ 
	.macro factory_swapmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SWAP_RENT_MONS
	special CallBattleFactoryFunction
	.endm

	@
	.macro factory_setswapped
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_SWAPPED
	special CallBattleFactoryFunction
	.endm

	@ 
	.macro factory_setopponentmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_OPPONENT_MONS
	special CallBattleFactoryFunction
	.endm

	@ 
	.macro factory_setparties arg:req
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_PARTIES
	setvar VAR_0x8005, \arg
	special CallBattleFactoryFunction
	.endm

	@ 
	.macro factory_setopponentgfx
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_OPPONENT_GFX
	special CallBattleFactoryFunction
	.endm

	@  
	.macro factory_generateopponentmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GENERATE_OPPONENT_MONS
	special CallBattleFactoryFunction
	.endm

	@  
	.macro factory_generaterentalmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GENERATE_RENTAL_MONS
	special CallBattleFactoryFunction
	.endm

	@  
	.macro factory_getopponentmontype
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GET_OPPONENT_MON_TYPE
	special CallBattleFactoryFunction
	.endm

	@ 
	.macro factory_getopponentstyle 
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GET_OPPONENT_STYLE
	special CallBattleFactoryFunction
	.endm

	@  
	.macro factory_resethelditems
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_RESET_HELD_ITEMS
	special CallBattleFactoryFunction
	.endm

