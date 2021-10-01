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

	@ Select the initial rental mons for the challenge
	.macro factory_rentmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SELECT_RENT_MONS
	special CallBattleFactoryFunction
	.endm

	@ Select a mon to swap for from the previously defeated team
	.macro factory_swapmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SWAP_RENT_MONS
	special CallBattleFactoryFunction
	.endm

	@ Allows FACTORY_DATA_WIN_STREAK_SWAPS to be incremented once
	.macro factory_setswapped
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_SWAPPED
	special CallBattleFactoryFunction
	.endm

	@ Update gEnemyParty with the next set of rental mons
	.macro factory_setopponentmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_OPPONENT_MONS
	special CallBattleFactoryFunction
	.endm

	@ Populate gPlayerParty and gEnemyParty with the rental mons. Only needed when resuming a challenge, otherwise only factory_setopponentmons and factory_rentmons/factory_swapmons are needed
	.macro factory_setparties arg:req
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_PARTIES
	setvar VAR_0x8005, \arg
	special CallBattleFactoryFunction
	.endm

	@ Set the object event gfx for the opponent trainer
	.macro factory_setopponentgfx
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_SET_OPPONENT_GFX
	special CallBattleFactoryFunction
	.endm

	@ Generate the mons for the opponents team
	.macro factory_generateopponentmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GENERATE_OPPONENT_MONS
	special CallBattleFactoryFunction
	.endm

	@ Generate the random 6 mons to choose from for the initial rental
	.macro factory_generaterentalmons
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GENERATE_RENTAL_MONS
	special CallBattleFactoryFunction
	.endm

	@ Return the pokemon type most common in the opponents team, or NUMBER_OF_MON_TYPES if there is no standout type
	.macro factory_getopponentmontype
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GET_OPPONENT_MON_TYPE
	special CallBattleFactoryFunction
	.endm

	@ Return the FACTORY_STYLE_* dependent on what types of moves the opponents team has, or FACTORY_NUM_STYLES if multiple styles tie for the same amount of moves
	.macro factory_getopponentstyle
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_GET_OPPONENT_STYLE
	special CallBattleFactoryFunction
	.endm

	@ Restore the held items for the players party to what they were pre-battle
	.macro factory_resethelditems
	setvar VAR_0x8004, BATTLE_FACTORY_FUNC_RESET_HELD_ITEMS
	special CallBattleFactoryFunction
	.endm

