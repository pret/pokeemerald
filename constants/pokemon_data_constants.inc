	.set GROWTH_MEDIUM_FAST, 0x00
	.set GROWTH_ERRATIC,     0x01
	.set GROWTH_FLUCTUATING, 0x02
	.set GROWTH_MEDIUM_SLOW, 0x03
	.set GROWTH_FAST,        0x04
	.set GROWTH_SLOW,        0x05

	.set BODY_COLOR_RED,    0x00
	.set BODY_COLOR_BLUE,   0x01
	.set BODY_COLOR_YELLOW, 0x02
	.set BODY_COLOR_GREEN,  0x03
	.set BODY_COLOR_BLACK,  0x04
	.set BODY_COLOR_BROWN,  0x05
	.set BODY_COLOR_PURPLE, 0x06
	.set BODY_COLOR_GRAY,   0x07
	.set BODY_COLOR_WHITE,  0x08
	.set BODY_COLOR_PINK,   0x09

	.set F_SUMMARY_SCREEN_FLIP_SPRITE, 0x80

	.set EVO_FRIENDSHIP,       0x0001 @ Pokémon levels up with friendship ≥ 220
	.set EVO_FRIENDSHIP_DAY,   0x0002 @ Pokémon levels up during the day with friendship ≥ 220
	.set EVO_FRIENDSHIP_NIGHT, 0x0003 @ Pokémon levels up at night with friendship ≥ 220
	.set EVO_LEVEL,            0x0004 @ Pokémon reaches the specified level
	.set EVO_TRADE,            0x0005 @ Pokémon is traded
	.set EVO_TRADE_ITEM,       0x0006 @ Pokémon is traded while it's holding the specified item
	.set EVO_ITEM,             0x0007 @ specified item is used on Pokémon
	.set EVO_LEVEL_ATK_GT_DEF, 0x0008 @ Pokémon reaches the specified level with attack > defense
	.set EVO_LEVEL_ATK_EQ_DEF, 0x0009 @ Pokémon reaches the specified level with attack = defense
	.set EVO_LEVEL_ATK_LT_DEF, 0x000a @ Pokémon reaches the specified level with attack < defense
	.set EVO_LEVEL_SILCOON,    0x000b @ Pokémon reaches the specified level with a Silcoon personality value
	.set EVO_LEVEL_CASCOON,    0x000c @ Pokémon reaches the specified level with a Cascoon personality value
	.set EVO_LEVEL_NINJASK,    0x000d @ Pokémon reaches the specified level (special value for Ninjask)
	.set EVO_LEVEL_SHEDINJA,   0x000e @ Pokémon reaches the specified level (special value for Shedinja)
	.set EVO_BEAUTY,           0x000f @ Pokémon levels up with beauty ≥ specified value
