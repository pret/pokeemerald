	.set TARGET_SELECTED_POKEMON, 0

	.set F_TARGET_SPECIAL,         1 << 0
	.set F_TARGET_RANDOM,          1 << 2
	.set F_TARGET_BOTH_ENEMIES,    1 << 3
	.set F_TARGET_USER,            1 << 4
	.set F_TARGET_ALL_EXCEPT_USER, 1 << 5
	.set F_TARGET_ENEMY_SIDE,      1 << 6

	.set F_MAKES_CONTACT,          1 << 0
	.set F_AFFECTED_BY_PROTECT,    1 << 1
	.set F_AFFECTED_BY_MAGIC_COAT, 1 << 2
	.set F_AFFECTED_BY_SNATCH,     1 << 3
	.set F_MIRROR_MOVE_COMPATIBLE, 1 << 4
	.set F_AFFECTED_BY_KINGS_ROCK, 1 << 5
