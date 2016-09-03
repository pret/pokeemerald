	.set NATURE_HARDY,   0
	.set NATURE_LONELY,  1
	.set NATURE_BRAVE,   2
	.set NATURE_ADAMANT, 3
	.set NATURE_NAUGHTY, 4
	.set NATURE_BOLD,    5
	.set NATURE_DOCILE,  6
	.set NATURE_RELAXED, 7
	.set NATURE_IMPISH,  8
	.set NATURE_LAX,     9
	.set NATURE_TIMID,   10
	.set NATURE_HASTY,   11
	.set NATURE_SERIOUS, 12
	.set NATURE_JOLLY,   13
	.set NATURE_NAIVE,   14
	.set NATURE_MODEST,  15
	.set NATURE_MILD,    16
	.set NATURE_QUIET,   17
	.set NATURE_BASHFUL, 18
	.set NATURE_RASH,    19
	.set NATURE_CALM,    20
	.set NATURE_GENTLE,  21
	.set NATURE_SASSY,   22
	.set NATURE_CAREFUL, 23
	.set NATURE_QUIRKY,  24

	.set GROWTH_MEDIUM_FAST, 0x00
	.set GROWTH_ERRATIC,     0x01
	.set GROWTH_FLUCTUATING, 0x02
	.set GROWTH_MEDIUM_SLOW, 0x03
	.set GROWTH_FAST,        0x04
	.set GROWTH_SLOW,        0x05

	.set EGG_GROUP_NONE,         0x00
	.set EGG_GROUP_MONSTER,      0x01
	.set EGG_GROUP_WATER_1,      0x02
	.set EGG_GROUP_BUG,          0x03
	.set EGG_GROUP_FLYING,       0x04
	.set EGG_GROUP_FIELD,        0x05
	.set EGG_GROUP_FAIRY,        0x06
	.set EGG_GROUP_GRASS,        0x07
	.set EGG_GROUP_HUMAN_LIKE,   0x08
	.set EGG_GROUP_WATER_3,      0x09
	.set EGG_GROUP_MINERAL,      0x0a
	.set EGG_GROUP_AMORPHOUS,    0x0b
	.set EGG_GROUP_WATER_2,      0x0c
	.set EGG_GROUP_DITTO,        0x0d
	.set EGG_GROUP_DRAGON,       0x0e
	.set EGG_GROUP_UNDISCOVERED, 0x0f

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
