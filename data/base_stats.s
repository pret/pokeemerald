	.align 2, 0

gBaseStats: @ 83203CC
@ ??????????
	.fill 28, 1, 0

@ Bulbasaur
	base_stats 45, 49, 49, 45, 65, 65
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 64 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Ivysaur
	base_stats 60, 62, 63, 60, 80, 80
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 141 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Venusaur
	base_stats 80, 82, 83, 80, 100, 100
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 208 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Charmander
	base_stats 39, 52, 43, 65, 60, 50
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Charmeleon
	base_stats 58, 64, 58, 80, 80, 65
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 142 @ base exp. yield
	ev_yield 0, 0, 0, 1, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Charizard
	base_stats 78, 84, 78, 100, 109, 85
	.byte TYPE_FIRE
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 209 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Squirtle
	base_stats 44, 48, 65, 43, 50, 64
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 66 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Wartortle
	base_stats 59, 63, 80, 58, 65, 80
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 143 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Blastoise
	base_stats 79, 83, 100, 78, 85, 105
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 210 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Caterpie
	base_stats 45, 30, 35, 45, 20, 20
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 255 @ catch rate
	.byte 53 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHIELD_DUST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Metapod
	base_stats 50, 20, 55, 30, 25, 25
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 120 @ catch rate
	.byte 72 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Butterfree
	base_stats 60, 45, 50, 70, 80, 80
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 160 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 1
	.2byte ITEM_NONE
	.2byte ITEM_SILVER_POWDER
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_COMPOUND_EYES
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Weedle
	base_stats 40, 35, 30, 50, 20, 20
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 255 @ catch rate
	.byte 52 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHIELD_DUST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Kakuna
	base_stats 45, 25, 50, 35, 25, 25
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 120 @ catch rate
	.byte 71 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Beedrill
	base_stats 65, 80, 40, 75, 45, 80
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 159 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_POISON_BARB
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Pidgey
	base_stats 40, 45, 40, 56, 35, 35
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 55 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Pidgeotto
	base_stats 63, 60, 55, 71, 50, 50
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 120 @ catch rate
	.byte 113 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Pidgeot
	base_stats 83, 80, 75, 91, 70, 70
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 172 @ base exp. yield
	ev_yield 0, 0, 0, 3, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Rattata
	base_stats 30, 56, 35, 72, 25, 35
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 57 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_GUTS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Raticate
	base_stats 55, 81, 60, 97, 50, 70
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 127 @ catch rate
	.byte 116 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_GUTS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Spearow
	base_stats 40, 60, 30, 70, 31, 31
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 58 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Fearow
	base_stats 65, 90, 65, 100, 61, 61
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 90 @ catch rate
	.byte 162 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SHARP_BEAK
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Ekans
	base_stats 35, 60, 44, 55, 40, 54
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 255 @ catch rate
	.byte 62 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_SHED_SKIN
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Arbok
	base_stats 60, 85, 69, 80, 65, 79
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 90 @ catch rate
	.byte 147 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_SHED_SKIN
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Pikachu
	base_stats 35, 55, 30, 90, 50, 40
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 190 @ catch rate
	.byte 82 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_LIGHT_BALL
	.byte 127 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 6 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Raichu
	base_stats 60, 90, 55, 100, 90, 80
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 75 @ catch rate
	.byte 122 @ base exp. yield
	ev_yield 0, 0, 0, 3, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_ORAN_BERRY
	.byte 127 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Sandshrew
	base_stats 50, 75, 85, 40, 20, 30
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 93 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_QUICK_CLAW
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Sandslash
	base_stats 75, 100, 110, 65, 45, 55
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 90 @ catch rate
	.byte 163 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_QUICK_CLAW
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Nidoran♀
	base_stats 55, 47, 52, 41, 40, 40
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 235 @ catch rate
	.byte 59 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 254 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Nidorina
	base_stats 70, 62, 67, 56, 55, 55
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 120 @ catch rate
	.byte 117 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 254 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Nidoqueen
	base_stats 90, 82, 87, 76, 75, 85
	.byte TYPE_POISON
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 194 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 254 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Nidoran♂
	base_stats 46, 57, 40, 50, 40, 40
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 235 @ catch rate
	.byte 60 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Nidorino
	base_stats 61, 72, 57, 65, 55, 55
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 120 @ catch rate
	.byte 118 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Nidoking
	base_stats 81, 92, 77, 85, 85, 75
	.byte TYPE_POISON
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 195 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Clefairy
	base_stats 70, 45, 48, 35, 60, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 150 @ catch rate
	.byte 68 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_MOON_STONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 140 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Clefable
	base_stats 95, 70, 73, 60, 85, 90
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 25 @ catch rate
	.byte 129 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_MOON_STONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 140 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Vulpix
	base_stats 38, 41, 40, 65, 50, 65
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 190 @ catch rate
	.byte 63 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 191 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_FLASH_FIRE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Ninetales
	base_stats 73, 76, 75, 100, 81, 100
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 75 @ catch rate
	.byte 178 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 1
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 191 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_FLASH_FIRE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Jigglypuff
	base_stats 115, 45, 20, 20, 45, 25
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 170 @ catch rate
	.byte 76 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Wigglytuff
	base_stats 140, 70, 45, 45, 75, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 50 @ catch rate
	.byte 109 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Zubat
	base_stats 40, 45, 35, 55, 30, 40
	.byte TYPE_POISON
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 54 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Golbat
	base_stats 75, 80, 70, 90, 65, 75
	.byte TYPE_POISON
	.byte TYPE_FLYING
	.byte 90 @ catch rate
	.byte 171 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Oddish
	base_stats 45, 50, 55, 30, 75, 65
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 255 @ catch rate
	.byte 78 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Gloom
	base_stats 60, 65, 70, 40, 85, 75
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 120 @ catch rate
	.byte 132 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 6 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Vileplume
	base_stats 75, 80, 85, 50, 100, 90
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 184 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Paras
	base_stats 35, 70, 55, 25, 45, 55
	.byte TYPE_BUG
	.byte TYPE_GRASS
	.byte 190 @ catch rate
	.byte 70 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_TINY_MUSHROOM
	.2byte ITEM_BIG_MUSHROOM
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_GRASS
	.byte ABILITY_EFFECT_SPORE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Parasect
	base_stats 60, 95, 80, 30, 60, 80
	.byte TYPE_BUG
	.byte TYPE_GRASS
	.byte 75 @ catch rate
	.byte 128 @ base exp. yield
	ev_yield 0, 2, 1, 0, 0, 0
	.2byte ITEM_TINY_MUSHROOM
	.2byte ITEM_BIG_MUSHROOM
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_GRASS
	.byte ABILITY_EFFECT_SPORE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Venonat
	base_stats 60, 55, 50, 45, 40, 55
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 190 @ catch rate
	.byte 75 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_COMPOUND_EYES
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Venomoth
	base_stats 70, 65, 60, 90, 90, 75
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 75 @ catch rate
	.byte 138 @ base exp. yield
	ev_yield 0, 0, 0, 1, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHIELD_DUST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Diglett
	base_stats 10, 55, 25, 95, 35, 45
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 81 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_ARENA_TRAP
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Dugtrio
	base_stats 35, 80, 50, 120, 50, 70
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 50 @ catch rate
	.byte 153 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_ARENA_TRAP
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Meowth
	base_stats 40, 45, 35, 90, 40, 40
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 69 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_PICKUP
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Persian
	base_stats 65, 70, 60, 115, 65, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 90 @ catch rate
	.byte 148 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_LIMBER
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Psyduck
	base_stats 50, 52, 48, 55, 65, 50
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 190 @ catch rate
	.byte 80 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_DAMP
	.byte ABILITY_CLOUD_NINE
	.byte 6 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Golduck
	base_stats 80, 82, 78, 85, 95, 80
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 75 @ catch rate
	.byte 174 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_DAMP
	.byte ABILITY_CLOUD_NINE
	.byte 8 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Mankey
	base_stats 40, 80, 35, 70, 35, 45
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 190 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_VITAL_SPIRIT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Primeape
	base_stats 65, 105, 60, 95, 60, 70
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 75 @ catch rate
	.byte 149 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_VITAL_SPIRIT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Growlithe
	base_stats 55, 70, 45, 60, 70, 50
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 190 @ catch rate
	.byte 91 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_FLASH_FIRE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Arcanine
	base_stats 90, 110, 80, 95, 100, 80
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 75 @ catch rate
	.byte 213 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_FLASH_FIRE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Poliwag
	base_stats 40, 50, 40, 90, 40, 40
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 255 @ catch rate
	.byte 77 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_WATER_ABSORB
	.byte ABILITY_DAMP
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Poliwhirl
	base_stats 65, 65, 65, 90, 50, 50
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 120 @ catch rate
	.byte 131 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_WATER_ABSORB
	.byte ABILITY_DAMP
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Poliwrath
	base_stats 90, 85, 95, 70, 70, 90
	.byte TYPE_WATER
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 185 @ base exp. yield
	ev_yield 0, 0, 3, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_WATER_ABSORB
	.byte ABILITY_DAMP
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Abra
	base_stats 25, 20, 15, 90, 105, 55
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 200 @ catch rate
	.byte 73 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_TWISTED_SPOON
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_INNER_FOCUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Kadabra
	base_stats 40, 35, 30, 105, 120, 70
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 100 @ catch rate
	.byte 145 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_TWISTED_SPOON
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_INNER_FOCUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Alakazam
	base_stats 55, 50, 45, 120, 135, 85
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 50 @ catch rate
	.byte 186 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_TWISTED_SPOON
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_INNER_FOCUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Machop
	base_stats 70, 80, 50, 35, 35, 35
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 180 @ catch rate
	.byte 88 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Machoke
	base_stats 80, 100, 70, 45, 50, 60
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 90 @ catch rate
	.byte 146 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Machamp
	base_stats 90, 130, 80, 55, 65, 85
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 193 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Bellsprout
	base_stats 50, 75, 35, 40, 70, 30
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 255 @ catch rate
	.byte 84 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Weepinbell
	base_stats 65, 90, 50, 55, 85, 45
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 120 @ catch rate
	.byte 151 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Victreebel
	base_stats 80, 105, 65, 70, 100, 60
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 191 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Tentacool
	base_stats 40, 40, 35, 70, 50, 100
	.byte TYPE_WATER
	.byte TYPE_POISON
	.byte 190 @ catch rate
	.byte 105 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_LIQUID_OOZE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Tentacruel
	base_stats 80, 70, 65, 100, 80, 120
	.byte TYPE_WATER
	.byte TYPE_POISON
	.byte 60 @ catch rate
	.byte 205 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_LIQUID_OOZE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Geodude
	base_stats 40, 80, 100, 20, 30, 30
	.byte TYPE_ROCK
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 86 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_EVERSTONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_STURDY
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Graveler
	base_stats 55, 95, 115, 35, 45, 45
	.byte TYPE_ROCK
	.byte TYPE_GROUND
	.byte 120 @ catch rate
	.byte 134 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_EVERSTONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Golem
	base_stats 80, 110, 130, 45, 55, 65
	.byte TYPE_ROCK
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 177 @ base exp. yield
	ev_yield 0, 0, 3, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_EVERSTONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Ponyta
	base_stats 50, 85, 55, 90, 65, 65
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 190 @ catch rate
	.byte 152 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_FLASH_FIRE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Rapidash
	base_stats 65, 100, 70, 105, 80, 80
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 60 @ catch rate
	.byte 192 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_FLASH_FIRE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Slowpoke
	base_stats 90, 65, 65, 15, 40, 40
	.byte TYPE_WATER
	.byte TYPE_PSYCHIC
	.byte 190 @ catch rate
	.byte 99 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_OWN_TEMPO
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Slowbro
	base_stats 95, 75, 110, 30, 100, 80
	.byte TYPE_WATER
	.byte TYPE_PSYCHIC
	.byte 75 @ catch rate
	.byte 164 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_OWN_TEMPO
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Magnemite
	base_stats 25, 35, 70, 45, 95, 55
	.byte TYPE_ELECTRIC
	.byte TYPE_STEEL
	.byte 190 @ catch rate
	.byte 89 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_COAT
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_MAGNET_PULL
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Magneton
	base_stats 50, 60, 95, 70, 120, 70
	.byte TYPE_ELECTRIC
	.byte TYPE_STEEL
	.byte 60 @ catch rate
	.byte 161 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_COAT
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_MAGNET_PULL
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Farfetch'd
	base_stats 52, 65, 55, 60, 58, 62
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 94 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_STICK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FIELD
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_INNER_FOCUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Doduo
	base_stats 35, 85, 45, 75, 35, 35
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 190 @ catch rate
	.byte 96 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SHARP_BEAK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_EARLY_BIRD
	.byte 8 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Dodrio
	base_stats 60, 110, 70, 100, 60, 60
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 158 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SHARP_BEAK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_EARLY_BIRD
	.byte 10 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Seel
	base_stats 65, 45, 55, 45, 45, 70
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 190 @ catch rate
	.byte 100 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Dewgong
	base_stats 90, 70, 80, 70, 70, 95
	.byte TYPE_WATER
	.byte TYPE_ICE
	.byte 75 @ catch rate
	.byte 176 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Grimer
	base_stats 80, 80, 50, 25, 40, 50
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 190 @ catch rate
	.byte 90 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NUGGET
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_STENCH
	.byte ABILITY_STICKY_HOLD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Muk
	base_stats 105, 105, 75, 50, 65, 100
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 75 @ catch rate
	.byte 157 @ base exp. yield
	ev_yield 1, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NUGGET
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_STENCH
	.byte ABILITY_STICKY_HOLD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Shellder
	base_stats 30, 65, 100, 40, 45, 25
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 190 @ catch rate
	.byte 97 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_PEARL
	.2byte ITEM_BIG_PEARL
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SHELL_ARMOR
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Cloyster
	base_stats 50, 95, 180, 70, 85, 45
	.byte TYPE_WATER
	.byte TYPE_ICE
	.byte 60 @ catch rate
	.byte 203 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_PEARL
	.2byte ITEM_BIG_PEARL
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SHELL_ARMOR
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Gastly
	base_stats 30, 35, 30, 80, 100, 35
	.byte TYPE_GHOST
	.byte TYPE_POISON
	.byte 190 @ catch rate
	.byte 95 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Haunter
	base_stats 45, 50, 45, 95, 115, 55
	.byte TYPE_GHOST
	.byte TYPE_POISON
	.byte 90 @ catch rate
	.byte 126 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Gengar
	base_stats 60, 65, 60, 110, 130, 75
	.byte TYPE_GHOST
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 190 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Onix
	base_stats 35, 45, 160, 70, 30, 45
	.byte TYPE_ROCK
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 108 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Drowzee
	base_stats 60, 48, 45, 42, 43, 90
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 190 @ catch rate
	.byte 102 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_INSOMNIA
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Hypno
	base_stats 85, 73, 70, 67, 73, 115
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 75 @ catch rate
	.byte 165 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_INSOMNIA
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Krabby
	base_stats 30, 105, 90, 50, 25, 25
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 225 @ catch rate
	.byte 115 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Kingler
	base_stats 55, 130, 115, 75, 50, 50
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 60 @ catch rate
	.byte 206 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_RED
	.2byte 0 @ padding

@ Voltorb
	base_stats 40, 30, 50, 100, 55, 55
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 190 @ catch rate
	.byte 103 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_SOUNDPROOF
	.byte ABILITY_STATIC
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Electrode
	base_stats 60, 50, 70, 140, 80, 80
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 60 @ catch rate
	.byte 150 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_SOUNDPROOF
	.byte ABILITY_STATIC
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Exeggcute
	base_stats 60, 40, 80, 40, 60, 45
	.byte TYPE_GRASS
	.byte TYPE_PSYCHIC
	.byte 90 @ catch rate
	.byte 98 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Exeggutor
	base_stats 95, 95, 85, 55, 125, 65
	.byte TYPE_GRASS
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 212 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Cubone
	base_stats 50, 50, 95, 35, 40, 50
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 190 @ catch rate
	.byte 87 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_THICK_CLUB
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_LIGHTNING_ROD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Marowak
	base_stats 60, 80, 110, 45, 50, 80
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 75 @ catch rate
	.byte 124 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_THICK_CLUB
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_LIGHTNING_ROD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Hitmonlee
	base_stats 50, 120, 53, 87, 35, 110
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 139 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_LIMBER
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Hitmonchan
	base_stats 50, 105, 79, 76, 35, 110
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 140 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Lickitung
	base_stats 90, 55, 75, 30, 60, 75
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 127 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_OWN_TEMPO
	.byte ABILITY_OBLIVIOUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Koffing
	base_stats 40, 65, 95, 35, 60, 45
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 190 @ catch rate
	.byte 114 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SMOKE_BALL
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Weezing
	base_stats 65, 90, 120, 60, 85, 70
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 60 @ catch rate
	.byte 173 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SMOKE_BALL
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Rhyhorn
	base_stats 80, 85, 95, 25, 30, 30
	.byte TYPE_GROUND
	.byte TYPE_ROCK
	.byte 120 @ catch rate
	.byte 135 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_LIGHTNING_ROD
	.byte ABILITY_ROCK_HEAD
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Rhydon
	base_stats 105, 130, 120, 40, 45, 45
	.byte TYPE_GROUND
	.byte TYPE_ROCK
	.byte 60 @ catch rate
	.byte 204 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_LIGHTNING_ROD
	.byte ABILITY_ROCK_HEAD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Chansey
	base_stats 250, 5, 5, 50, 35, 105
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 30 @ catch rate
	.byte 255 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_LUCKY_EGG
	.byte 254 @ gender
	.byte 40 @ egg cycles
	.byte 140 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_NATURAL_CURE
	.byte ABILITY_SERENE_GRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Tangela
	base_stats 65, 55, 115, 60, 100, 40
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 166 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Kangaskhan
	base_stats 105, 95, 80, 90, 40, 80
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 175 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 254 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_EARLY_BIRD
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Horsea
	base_stats 30, 40, 70, 60, 70, 25
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 225 @ catch rate
	.byte 83 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Seadra
	base_stats 55, 65, 95, 85, 95, 45
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 75 @ catch rate
	.byte 155 @ base exp. yield
	ev_yield 0, 0, 1, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_POISON_POINT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Goldeen
	base_stats 45, 67, 60, 63, 35, 50
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 225 @ catch rate
	.byte 111 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_WATER_VEIL
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Seaking
	base_stats 80, 92, 65, 68, 65, 80
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 60 @ catch rate
	.byte 170 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_WATER_VEIL
	.byte 6 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Staryu
	base_stats 30, 45, 55, 85, 70, 55
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 225 @ catch rate
	.byte 106 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_STARDUST
	.2byte ITEM_STAR_PIECE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_ILLUMINATE
	.byte ABILITY_NATURAL_CURE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Starmie
	base_stats 60, 75, 85, 115, 100, 85
	.byte TYPE_WATER
	.byte TYPE_PSYCHIC
	.byte 60 @ catch rate
	.byte 207 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_STARDUST
	.2byte ITEM_STAR_PIECE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_ILLUMINATE
	.byte ABILITY_NATURAL_CURE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Mr. mime
	base_stats 40, 45, 65, 90, 100, 120
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 136 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_LEPPA_BERRY
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_SOUNDPROOF
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Scyther
	base_stats 70, 110, 80, 105, 55, 80
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 187 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Jynx
	base_stats 65, 50, 35, 95, 115, 95
	.byte TYPE_ICE
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 137 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.byte 254 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Electabuzz
	base_stats 65, 83, 57, 105, 95, 85
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 45 @ catch rate
	.byte 156 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 63 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Magmar
	base_stats 65, 95, 57, 93, 100, 85
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 167 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 63 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_FLAME_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Pinsir
	base_stats 65, 125, 100, 85, 55, 70
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 45 @ catch rate
	.byte 200 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_NONE
	.byte 8 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Tauros
	base_stats 75, 100, 95, 110, 40, 70
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 211 @ base exp. yield
	ev_yield 0, 1, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Magikarp
	base_stats 20, 10, 55, 80, 15, 20
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 255 @ catch rate
	.byte 20 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 5 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Gyarados
	base_stats 95, 125, 79, 81, 60, 100
	.byte TYPE_WATER
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 214 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 5 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Lapras
	base_stats 130, 85, 80, 60, 85, 95
	.byte TYPE_WATER
	.byte TYPE_ICE
	.byte 45 @ catch rate
	.byte 219 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_WATER_ABSORB
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Ditto
	base_stats 48, 48, 48, 48, 48, 48
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 35 @ catch rate
	.byte 61 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_POWDER
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_DITTO
	.byte EGG_GROUP_DITTO
	.byte ABILITY_LIMBER
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Eevee
	base_stats 55, 55, 50, 55, 45, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 92 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Vaporeon
	base_stats 130, 65, 60, 65, 110, 95
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 196 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_WATER_ABSORB
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Jolteon
	base_stats 65, 65, 60, 130, 110, 95
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 45 @ catch rate
	.byte 197 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_VOLT_ABSORB
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Flareon
	base_stats 65, 130, 60, 65, 95, 110
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 198 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_FLASH_FIRE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Porygon
	base_stats 65, 60, 70, 40, 85, 75
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 130 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_TRACE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Omanyte
	base_stats 35, 40, 100, 35, 90, 55
	.byte TYPE_ROCK
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 120 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Omastar
	base_stats 70, 60, 125, 55, 115, 70
	.byte TYPE_ROCK
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 199 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Kabuto
	base_stats 30, 80, 90, 55, 55, 45
	.byte TYPE_ROCK
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 119 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_BATTLE_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Kabutops
	base_stats 60, 115, 105, 80, 65, 70
	.byte TYPE_ROCK
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 201 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_BATTLE_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Aerodactyl
	base_stats 80, 105, 65, 130, 60, 75
	.byte TYPE_ROCK
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 202 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_PRESSURE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Snorlax
	base_stats 160, 110, 65, 30, 65, 110
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 25 @ catch rate
	.byte 154 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_LEFTOVERS
	.byte 31 @ gender
	.byte 40 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_IMMUNITY
	.byte ABILITY_THICK_FAT
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Articuno
	base_stats 90, 85, 100, 85, 95, 125
	.byte TYPE_ICE
	.byte TYPE_FLYING
	.byte 3 @ catch rate
	.byte 215 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Zapdos
	base_stats 90, 90, 85, 100, 125, 90
	.byte TYPE_ELECTRIC
	.byte TYPE_FLYING
	.byte 3 @ catch rate
	.byte 216 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Moltres
	base_stats 90, 100, 90, 90, 125, 85
	.byte TYPE_FIRE
	.byte TYPE_FLYING
	.byte 3 @ catch rate
	.byte 217 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Dratini
	base_stats 41, 64, 45, 50, 50, 50
	.byte TYPE_DRAGON
	.byte TYPE_DRAGON
	.byte 45 @ catch rate
	.byte 67 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Dragonair
	base_stats 61, 84, 65, 70, 70, 70
	.byte TYPE_DRAGON
	.byte TYPE_DRAGON
	.byte 45 @ catch rate
	.byte 144 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Dragonite
	base_stats 91, 134, 95, 80, 100, 100
	.byte TYPE_DRAGON
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 218 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Mewtwo
	base_stats 106, 110, 90, 130, 154, 90
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 220 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Mew
	base_stats 100, 100, 100, 100, 100, 100
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 64 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_LUM_BERRY
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 100 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Chikorita
	base_stats 45, 49, 65, 45, 49, 65
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 64 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Bayleef
	base_stats 60, 62, 80, 60, 63, 80
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 141 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Meganium
	base_stats 80, 82, 100, 80, 83, 100
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 208 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Cyndaquil
	base_stats 39, 52, 43, 65, 60, 50
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Quilava
	base_stats 58, 64, 58, 80, 80, 65
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 142 @ base exp. yield
	ev_yield 0, 0, 0, 1, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Typhlosion
	base_stats 78, 84, 78, 100, 109, 85
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 209 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Totodile
	base_stats 50, 65, 64, 43, 44, 48
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 66 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Croconaw
	base_stats 65, 80, 80, 58, 59, 63
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 143 @ base exp. yield
	ev_yield 0, 1, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Feraligatr
	base_stats 85, 105, 100, 78, 79, 83
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 210 @ base exp. yield
	ev_yield 0, 2, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Sentret
	base_stats 35, 46, 34, 20, 35, 45
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 57 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_ORAN_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_KEEN_EYE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Furret
	base_stats 85, 76, 64, 90, 45, 55
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 90 @ catch rate
	.byte 116 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_SITRUS_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_KEEN_EYE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Hoothoot
	base_stats 60, 30, 30, 50, 36, 56
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 58 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_INSOMNIA
	.byte ABILITY_KEEN_EYE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Noctowl
	base_stats 100, 50, 50, 70, 76, 96
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 90 @ catch rate
	.byte 162 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_INSOMNIA
	.byte ABILITY_KEEN_EYE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Ledyba
	base_stats 40, 20, 30, 55, 40, 80
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 54 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_EARLY_BIRD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Ledian
	base_stats 55, 35, 50, 85, 55, 110
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 90 @ catch rate
	.byte 134 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_EARLY_BIRD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Spinarak
	base_stats 40, 60, 40, 30, 40, 40
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 255 @ catch rate
	.byte 54 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_INSOMNIA
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Ariados
	base_stats 70, 90, 70, 40, 60, 60
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 90 @ catch rate
	.byte 134 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_INSOMNIA
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Crobat
	base_stats 85, 90, 80, 130, 70, 80
	.byte TYPE_POISON
	.byte TYPE_FLYING
	.byte 90 @ catch rate
	.byte 204 @ base exp. yield
	ev_yield 0, 0, 0, 3, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Chinchou
	base_stats 75, 38, 38, 67, 56, 56
	.byte TYPE_WATER
	.byte TYPE_ELECTRIC
	.byte 190 @ catch rate
	.byte 90 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_YELLOW_SHARD
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_VOLT_ABSORB
	.byte ABILITY_ILLUMINATE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Lanturn
	base_stats 125, 58, 58, 67, 76, 76
	.byte TYPE_WATER
	.byte TYPE_ELECTRIC
	.byte 75 @ catch rate
	.byte 156 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_YELLOW_SHARD
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_VOLT_ABSORB
	.byte ABILITY_ILLUMINATE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Pichu
	base_stats 20, 40, 15, 60, 35, 35
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 190 @ catch rate
	.byte 42 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_ORAN_BERRY
	.byte 127 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Cleffa
	base_stats 50, 25, 28, 15, 45, 55
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 150 @ catch rate
	.byte 37 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_MOON_STONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 140 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Igglybuff
	base_stats 90, 30, 15, 15, 40, 20
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 170 @ catch rate
	.byte 39 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_PINK
	.2byte 0 @ padding

@ Togepi
	base_stats 35, 20, 65, 20, 40, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 190 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_HUSTLE
	.byte ABILITY_SERENE_GRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Togetic
	base_stats 55, 40, 85, 40, 80, 105
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 75 @ catch rate
	.byte 114 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_HUSTLE
	.byte ABILITY_SERENE_GRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Natu
	base_stats 40, 50, 45, 70, 70, 45
	.byte TYPE_PSYCHIC
	.byte TYPE_FLYING
	.byte 190 @ catch rate
	.byte 73 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_EARLY_BIRD
	.byte 6 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Xatu
	base_stats 65, 75, 70, 95, 95, 70
	.byte TYPE_PSYCHIC
	.byte TYPE_FLYING
	.byte 75 @ catch rate
	.byte 171 @ base exp. yield
	ev_yield 0, 0, 0, 1, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_EARLY_BIRD
	.byte 8 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Mareep
	base_stats 55, 40, 40, 35, 65, 45
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 235 @ catch rate
	.byte 59 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Flaaffy
	base_stats 70, 55, 55, 45, 80, 60
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 120 @ catch rate
	.byte 117 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Ampharos
	base_stats 90, 75, 75, 55, 115, 90
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 45 @ catch rate
	.byte 194 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Bellossom
	base_stats 75, 80, 85, 50, 90, 100
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 184 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Marill
	base_stats 70, 20, 50, 40, 20, 50
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 190 @ catch rate
	.byte 58 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_THICK_FAT
	.byte ABILITY_HUGE_POWER
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Azumarill
	base_stats 100, 50, 80, 50, 50, 80
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 75 @ catch rate
	.byte 153 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_THICK_FAT
	.byte ABILITY_HUGE_POWER
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Sudowoodo
	base_stats 70, 100, 115, 30, 30, 65
	.byte TYPE_ROCK
	.byte TYPE_ROCK
	.byte 65 @ catch rate
	.byte 135 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_STURDY
	.byte ABILITY_ROCK_HEAD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Politoed
	base_stats 90, 75, 75, 70, 90, 100
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 185 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_WATER_ABSORB
	.byte ABILITY_DAMP
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Hoppip
	base_stats 35, 35, 40, 50, 35, 55
	.byte TYPE_GRASS
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Skiploom
	base_stats 55, 45, 50, 80, 45, 65
	.byte TYPE_GRASS
	.byte TYPE_FLYING
	.byte 120 @ catch rate
	.byte 136 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Jumpluff
	base_stats 75, 55, 70, 110, 55, 85
	.byte TYPE_GRASS
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 176 @ base exp. yield
	ev_yield 0, 0, 0, 3, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Aipom
	base_stats 55, 70, 55, 85, 40, 55
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 94 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_PICKUP
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Sunkern
	base_stats 30, 30, 30, 30, 30, 30
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 235 @ catch rate
	.byte 52 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Sunflora
	base_stats 75, 75, 55, 30, 105, 85
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 120 @ catch rate
	.byte 146 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Yanma
	base_stats 65, 65, 45, 95, 75, 45
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 75 @ catch rate
	.byte 147 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SPEED_BOOST
	.byte ABILITY_COMPOUND_EYES
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Wooper
	base_stats 55, 45, 45, 15, 25, 25
	.byte TYPE_WATER
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 52 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_DAMP
	.byte ABILITY_WATER_ABSORB
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Quagsire
	base_stats 95, 85, 85, 35, 65, 65
	.byte TYPE_WATER
	.byte TYPE_GROUND
	.byte 90 @ catch rate
	.byte 137 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_DAMP
	.byte ABILITY_WATER_ABSORB
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Espeon
	base_stats 65, 65, 60, 110, 130, 95
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 197 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Umbreon
	base_stats 95, 65, 110, 65, 60, 130
	.byte TYPE_DARK
	.byte TYPE_DARK
	.byte 45 @ catch rate
	.byte 197 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 35 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Murkrow
	base_stats 60, 85, 42, 91, 85, 42
	.byte TYPE_DARK
	.byte TYPE_FLYING
	.byte 30 @ catch rate
	.byte 107 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_INSOMNIA
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Slowking
	base_stats 95, 75, 80, 30, 100, 110
	.byte TYPE_WATER
	.byte TYPE_PSYCHIC
	.byte 70 @ catch rate
	.byte 164 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_OWN_TEMPO
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Misdreavus
	base_stats 60, 60, 60, 85, 85, 85
	.byte TYPE_GHOST
	.byte TYPE_GHOST
	.byte 45 @ catch rate
	.byte 147 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 1
	.2byte ITEM_NONE
	.2byte ITEM_SPELL_TAG
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Unown
	base_stats 48, 72, 48, 48, 72, 48
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 225 @ catch rate
	.byte 61 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 40 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Wobbuffet
	base_stats 190, 33, 58, 33, 33, 58
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 177 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_SHADOW_TAG
	.byte ABILITY_NONE
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Girafarig
	base_stats 70, 80, 65, 85, 90, 65
	.byte TYPE_NORMAL
	.byte TYPE_PSYCHIC
	.byte 60 @ catch rate
	.byte 149 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_PERSIM_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_EARLY_BIRD
	.byte 4 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Pineco
	base_stats 50, 65, 90, 15, 35, 35
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 190 @ catch rate
	.byte 60 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_STURDY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Forretress
	base_stats 75, 90, 140, 40, 60, 60
	.byte TYPE_BUG
	.byte TYPE_STEEL
	.byte 75 @ catch rate
	.byte 118 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_STURDY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Dunsparce
	base_stats 100, 70, 70, 45, 65, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 190 @ catch rate
	.byte 75 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SERENE_GRACE
	.byte ABILITY_RUN_AWAY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Gligar
	base_stats 65, 75, 105, 85, 35, 65
	.byte TYPE_GROUND
	.byte TYPE_FLYING
	.byte 60 @ catch rate
	.byte 108 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_SAND_VEIL
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Steelix
	base_stats 75, 85, 200, 30, 55, 65
	.byte TYPE_STEEL
	.byte TYPE_GROUND
	.byte 25 @ catch rate
	.byte 196 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_COAT
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Snubbull
	base_stats 60, 80, 50, 30, 40, 40
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 190 @ catch rate
	.byte 63 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_RUN_AWAY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Granbull
	base_stats 90, 120, 75, 45, 60, 60
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 75 @ catch rate
	.byte 178 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_INTIMIDATE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Qwilfish
	base_stats 65, 95, 75, 85, 55, 55
	.byte TYPE_WATER
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 100 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_POISON_POINT
	.byte ABILITY_SWIFT_SWIM
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Scizor
	base_stats 70, 130, 100, 65, 55, 80
	.byte TYPE_BUG
	.byte TYPE_STEEL
	.byte 25 @ catch rate
	.byte 200 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Shuckle
	base_stats 20, 10, 230, 5, 10, 230
	.byte TYPE_BUG
	.byte TYPE_ROCK
	.byte 190 @ catch rate
	.byte 80 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 1
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_ORAN_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_STURDY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Heracross
	base_stats 80, 125, 75, 85, 40, 95
	.byte TYPE_BUG
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 200 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_GUTS
	.byte 8 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Sneasel
	base_stats 55, 95, 55, 115, 35, 75
	.byte TYPE_DARK
	.byte TYPE_ICE
	.byte 60 @ catch rate
	.byte 132 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_QUICK_CLAW
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_KEEN_EYE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Teddiursa
	base_stats 60, 80, 50, 40, 50, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 120 @ catch rate
	.byte 124 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_PICKUP
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Ursaring
	base_stats 90, 130, 75, 55, 75, 75
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 60 @ catch rate
	.byte 189 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Slugma
	base_stats 40, 40, 40, 20, 70, 40
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 190 @ catch rate
	.byte 78 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_MAGMA_ARMOR
	.byte ABILITY_FLAME_BODY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Magcargo
	base_stats 50, 50, 120, 30, 80, 80
	.byte TYPE_FIRE
	.byte TYPE_ROCK
	.byte 75 @ catch rate
	.byte 154 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_MAGMA_ARMOR
	.byte ABILITY_FLAME_BODY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Swinub
	base_stats 50, 50, 40, 50, 30, 30
	.byte TYPE_ICE
	.byte TYPE_GROUND
	.byte 225 @ catch rate
	.byte 78 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Piloswine
	base_stats 100, 100, 80, 50, 60, 60
	.byte TYPE_ICE
	.byte TYPE_GROUND
	.byte 75 @ catch rate
	.byte 160 @ base exp. yield
	ev_yield 1, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Corsola
	base_stats 55, 55, 85, 35, 65, 85
	.byte TYPE_WATER
	.byte TYPE_ROCK
	.byte 60 @ catch rate
	.byte 113 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_RED_SHARD
	.byte 191 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_HUSTLE
	.byte ABILITY_NATURAL_CURE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Remoraid
	base_stats 35, 65, 35, 65, 65, 35
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 190 @ catch rate
	.byte 78 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_HUSTLE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Octillery
	base_stats 75, 105, 75, 45, 105, 75
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 75 @ catch rate
	.byte 164 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_SUCTION_CUPS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Delibird
	base_stats 45, 55, 45, 75, 65, 45
	.byte TYPE_ICE
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 183 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_VITAL_SPIRIT
	.byte ABILITY_HUSTLE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Mantine
	base_stats 65, 40, 70, 70, 80, 140
	.byte TYPE_WATER
	.byte TYPE_FLYING
	.byte 25 @ catch rate
	.byte 168 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_WATER_ABSORB
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Skarmory
	base_stats 65, 80, 140, 70, 40, 70
	.byte TYPE_STEEL
	.byte TYPE_FLYING
	.byte 25 @ catch rate
	.byte 168 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_STURDY
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Houndour
	base_stats 45, 60, 30, 65, 80, 50
	.byte TYPE_DARK
	.byte TYPE_FIRE
	.byte 120 @ catch rate
	.byte 114 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_EARLY_BIRD
	.byte ABILITY_FLASH_FIRE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Houndoom
	base_stats 75, 90, 50, 95, 110, 80
	.byte TYPE_DARK
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 204 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_EARLY_BIRD
	.byte ABILITY_FLASH_FIRE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Kingdra
	base_stats 75, 95, 95, 85, 95, 95
	.byte TYPE_WATER
	.byte TYPE_DRAGON
	.byte 45 @ catch rate
	.byte 207 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 1
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Phanpy
	base_stats 90, 60, 60, 40, 40, 40
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 120 @ catch rate
	.byte 124 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_PICKUP
	.byte ABILITY_NONE
	.byte 10 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Donphan
	base_stats 90, 120, 120, 50, 60, 60
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 60 @ catch rate
	.byte 189 @ base exp. yield
	ev_yield 0, 1, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_STURDY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Porygon2
	base_stats 85, 80, 90, 60, 105, 95
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 180 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_TRACE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Stantler
	base_stats 73, 95, 62, 85, 85, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 165 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Smeargle
	base_stats 55, 20, 35, 75, 20, 45
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 106 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_OWN_TEMPO
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Tyrogue
	base_stats 35, 35, 35, 35, 35, 35
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 75 @ catch rate
	.byte 91 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Hitmontop
	base_stats 50, 95, 95, 70, 35, 110
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 138 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Smoochum
	base_stats 45, 30, 15, 65, 85, 65
	.byte TYPE_ICE
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 87 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.byte 254 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Elekid
	base_stats 45, 63, 37, 95, 65, 55
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 45 @ catch rate
	.byte 106 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 63 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_STATIC
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Magby
	base_stats 45, 75, 37, 83, 70, 55
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 117 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 63 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_FLAME_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Miltank
	base_stats 95, 80, 105, 100, 40, 70
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 200 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_MOOMOO_MILK
	.byte 254 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Blissey
	base_stats 255, 10, 10, 55, 75, 135
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 30 @ catch rate
	.byte 255 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_LUCKY_EGG
	.byte 254 @ gender
	.byte 40 @ egg cycles
	.byte 140 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_NATURAL_CURE
	.byte ABILITY_SERENE_GRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Raikou
	base_stats 90, 85, 75, 115, 115, 100
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 3 @ catch rate
	.byte 216 @ base exp. yield
	ev_yield 0, 0, 0, 2, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Entei
	base_stats 115, 115, 85, 100, 90, 75
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 3 @ catch rate
	.byte 217 @ base exp. yield
	ev_yield 1, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Suicune
	base_stats 100, 75, 115, 85, 90, 115
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 3 @ catch rate
	.byte 215 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Larvitar
	base_stats 50, 64, 50, 41, 45, 50
	.byte TYPE_ROCK
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 67 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Pupitar
	base_stats 70, 84, 70, 51, 65, 70
	.byte TYPE_ROCK
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 144 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Tyranitar
	base_stats 100, 134, 110, 61, 95, 100
	.byte TYPE_ROCK
	.byte TYPE_DARK
	.byte 45 @ catch rate
	.byte 218 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_SAND_STREAM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Lugia
	base_stats 106, 90, 130, 110, 90, 154
	.byte TYPE_PSYCHIC
	.byte TYPE_FLYING
	.byte 3 @ catch rate
	.byte 220 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Ho-Oh
	base_stats 106, 130, 90, 90, 110, 154
	.byte TYPE_FIRE
	.byte TYPE_FLYING
	.byte 3 @ catch rate
	.byte 220 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_SACRED_ASH
	.2byte ITEM_SACRED_ASH
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Celebi
	base_stats 100, 100, 100, 100, 100, 100
	.byte TYPE_PSYCHIC
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 64 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_LUM_BERRY
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 100 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NATURAL_CURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ ?
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 3 @ catch rate
	.byte 1 @ base exp. yield
	ev_yield 2, 2, 2, 2, 2, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_NONE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Treecko
	base_stats 40, 45, 35, 70, 65, 55
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Grovyle
	base_stats 50, 65, 45, 95, 85, 65
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 141 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Sceptile
	base_stats 70, 85, 65, 120, 105, 85
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 208 @ base exp. yield
	ev_yield 0, 0, 0, 3, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_OVERGROW
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Torchic
	base_stats 45, 60, 40, 45, 70, 50
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 45 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Combusken
	base_stats 60, 85, 60, 55, 85, 60
	.byte TYPE_FIRE
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 142 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Blaziken
	base_stats 80, 120, 70, 80, 110, 70
	.byte TYPE_FIRE
	.byte TYPE_FIGHTING
	.byte 45 @ catch rate
	.byte 209 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_BLAZE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Mudkip
	base_stats 50, 70, 50, 40, 50, 50
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Marshtomp
	base_stats 70, 85, 70, 50, 60, 70
	.byte TYPE_WATER
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 143 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Swampert
	base_stats 100, 110, 90, 60, 85, 90
	.byte TYPE_WATER
	.byte TYPE_GROUND
	.byte 45 @ catch rate
	.byte 210 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_TORRENT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Poochyena
	base_stats 35, 55, 35, 35, 30, 30
	.byte TYPE_DARK
	.byte TYPE_DARK
	.byte 255 @ catch rate
	.byte 55 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_PECHA_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_RUN_AWAY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Mightyena
	base_stats 70, 90, 70, 70, 60, 60
	.byte TYPE_DARK
	.byte TYPE_DARK
	.byte 127 @ catch rate
	.byte 128 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_PECHA_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Zigzagoon
	base_stats 38, 30, 41, 60, 30, 41
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 60 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_ORAN_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_PICKUP
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Linoone
	base_stats 78, 70, 61, 100, 50, 61
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 90 @ catch rate
	.byte 128 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_SITRUS_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_PICKUP
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Wurmple
	base_stats 45, 45, 35, 20, 20, 30
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 255 @ catch rate
	.byte 54 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHIELD_DUST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Silcoon
	base_stats 50, 35, 55, 15, 25, 25
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 120 @ catch rate
	.byte 71 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Beautifly
	base_stats 60, 70, 50, 65, 90, 50
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 161 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_SILVER_POWDER
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Cascoon
	base_stats 50, 35, 55, 15, 25, 25
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 120 @ catch rate
	.byte 72 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Dustox
	base_stats 60, 50, 70, 65, 50, 90
	.byte TYPE_BUG
	.byte TYPE_POISON
	.byte 45 @ catch rate
	.byte 160 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_SILVER_POWDER
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SHIELD_DUST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Lotad
	base_stats 40, 30, 30, 30, 40, 50
	.byte TYPE_WATER
	.byte TYPE_GRASS
	.byte 255 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_GRASS
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_RAIN_DISH
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Lombre
	base_stats 60, 50, 50, 50, 60, 70
	.byte TYPE_WATER
	.byte TYPE_GRASS
	.byte 120 @ catch rate
	.byte 141 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_GRASS
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_RAIN_DISH
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Ludicolo
	base_stats 80, 70, 70, 70, 90, 100
	.byte TYPE_WATER
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 181 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_GRASS
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_RAIN_DISH
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Seedot
	base_stats 40, 40, 50, 30, 30, 30
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 255 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_EARLY_BIRD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Nuzleaf
	base_stats 70, 70, 40, 60, 60, 40
	.byte TYPE_GRASS
	.byte TYPE_DARK
	.byte 120 @ catch rate
	.byte 141 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_EARLY_BIRD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Shiftry
	base_stats 90, 100, 60, 80, 90, 60
	.byte TYPE_GRASS
	.byte TYPE_DARK
	.byte 45 @ catch rate
	.byte 181 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_EARLY_BIRD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Nincada
	base_stats 31, 45, 90, 40, 30, 30
	.byte TYPE_BUG
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_COMPOUND_EYES
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Ninjask
	base_stats 61, 90, 45, 160, 50, 50
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 120 @ catch rate
	.byte 155 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_SPEED_BOOST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Shedinja
	base_stats 1, 90, 45, 40, 30, 30
	.byte TYPE_BUG
	.byte TYPE_GHOST
	.byte 45 @ catch rate
	.byte 95 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_WONDER_GUARD
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Taillow
	base_stats 40, 55, 30, 85, 30, 30
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 200 @ catch rate
	.byte 59 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Swellow
	base_stats 60, 85, 60, 125, 50, 50
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 162 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_FLYING
	.byte ABILITY_GUTS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Shroomish
	base_stats 60, 40, 60, 35, 40, 60
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 255 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_GRASS
	.byte ABILITY_EFFECT_SPORE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Breloom
	base_stats 60, 130, 80, 70, 60, 60
	.byte TYPE_GRASS
	.byte TYPE_FIGHTING
	.byte 90 @ catch rate
	.byte 165 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_GRASS
	.byte ABILITY_EFFECT_SPORE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Spinda
	base_stats 60, 60, 60, 60, 60, 60
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 85 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_CHESTO_BERRY
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_OWN_TEMPO
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Wingull
	base_stats 40, 30, 30, 85, 55, 30
	.byte TYPE_WATER
	.byte TYPE_FLYING
	.byte 190 @ catch rate
	.byte 64 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Pelipper
	base_stats 60, 50, 100, 65, 85, 70
	.byte TYPE_WATER
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 164 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FLYING
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Surskit
	base_stats 40, 30, 32, 65, 50, 52
	.byte TYPE_BUG
	.byte TYPE_WATER
	.byte 200 @ catch rate
	.byte 63 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_BUG
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Masquerain
	base_stats 70, 60, 62, 60, 80, 82
	.byte TYPE_BUG
	.byte TYPE_FLYING
	.byte 75 @ catch rate
	.byte 128 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 1
	.2byte ITEM_NONE
	.2byte ITEM_SILVER_POWDER
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_BUG
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Wailmer
	base_stats 130, 70, 35, 60, 70, 35
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 125 @ catch rate
	.byte 137 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_WATER_VEIL
	.byte ABILITY_OBLIVIOUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Wailord
	base_stats 170, 90, 45, 60, 90, 45
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 60 @ catch rate
	.byte 206 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_WATER_VEIL
	.byte ABILITY_OBLIVIOUS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Skitty
	base_stats 50, 45, 45, 50, 35, 35
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 65 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_LEPPA_BERRY
	.byte 191 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Delcatty
	base_stats 70, 65, 65, 70, 55, 55
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 60 @ catch rate
	.byte 138 @ base exp. yield
	ev_yield 1, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_LEPPA_BERRY
	.byte 191 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Kecleon
	base_stats 60, 90, 70, 40, 60, 120
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 200 @ catch rate
	.byte 132 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_PERSIM_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_COLOR_CHANGE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Baltoy
	base_stats 40, 40, 55, 55, 40, 70
	.byte TYPE_GROUND
	.byte TYPE_PSYCHIC
	.byte 255 @ catch rate
	.byte 58 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Claydol
	base_stats 60, 70, 105, 75, 70, 120
	.byte TYPE_GROUND
	.byte TYPE_PSYCHIC
	.byte 90 @ catch rate
	.byte 189 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Nosepass
	base_stats 30, 45, 135, 30, 45, 90
	.byte TYPE_ROCK
	.byte TYPE_ROCK
	.byte 255 @ catch rate
	.byte 108 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_STURDY
	.byte ABILITY_MAGNET_PULL
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Torkoal
	base_stats 70, 85, 140, 20, 85, 70
	.byte TYPE_FIRE
	.byte TYPE_FIRE
	.byte 90 @ catch rate
	.byte 161 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_WHITE_SMOKE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Sableye
	base_stats 50, 75, 75, 50, 65, 65
	.byte TYPE_DARK
	.byte TYPE_GHOST
	.byte 45 @ catch rate
	.byte 98 @ base exp. yield
	ev_yield 0, 1, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_KEEN_EYE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Barboach
	base_stats 50, 48, 43, 60, 46, 41
	.byte TYPE_WATER
	.byte TYPE_GROUND
	.byte 190 @ catch rate
	.byte 92 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Whiscash
	base_stats 110, 78, 73, 60, 76, 71
	.byte TYPE_WATER
	.byte TYPE_GROUND
	.byte 75 @ catch rate
	.byte 158 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Luvdisc
	base_stats 43, 30, 55, 97, 40, 65
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 225 @ catch rate
	.byte 110 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Corphish
	base_stats 43, 80, 65, 35, 50, 35
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 205 @ catch rate
	.byte 111 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Crawdaunt
	base_stats 63, 120, 85, 55, 90, 55
	.byte TYPE_WATER
	.byte TYPE_DARK
	.byte 155 @ catch rate
	.byte 161 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_SHELL_ARMOR
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Feebas
	base_stats 20, 15, 20, 80, 10, 55
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 255 @ catch rate
	.byte 61 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Milotic
	base_stats 95, 60, 79, 81, 100, 125
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 60 @ catch rate
	.byte 213 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_MARVEL_SCALE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Carvanha
	base_stats 45, 90, 20, 65, 65, 20
	.byte TYPE_WATER
	.byte TYPE_DARK
	.byte 225 @ catch rate
	.byte 88 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_ROUGH_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Sharpedo
	base_stats 70, 120, 40, 95, 95, 40
	.byte TYPE_WATER
	.byte TYPE_DARK
	.byte 60 @ catch rate
	.byte 175 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_2
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_ROUGH_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Trapinch
	base_stats 45, 100, 45, 10, 45, 45
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 73 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SOFT_SAND
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_ARENA_TRAP
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Vibrava
	base_stats 50, 70, 50, 70, 50, 50
	.byte TYPE_GROUND
	.byte TYPE_DRAGON
	.byte 120 @ catch rate
	.byte 126 @ base exp. yield
	ev_yield 0, 1, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_LEVITATE
	.byte ABILITY_LEVITATE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Flygon
	base_stats 80, 100, 80, 100, 80, 80
	.byte TYPE_GROUND
	.byte TYPE_DRAGON
	.byte 45 @ catch rate
	.byte 197 @ base exp. yield
	ev_yield 0, 1, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_BUG
	.byte ABILITY_LEVITATE
	.byte ABILITY_LEVITATE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Makuhita
	base_stats 72, 60, 30, 25, 20, 30
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 180 @ catch rate
	.byte 87 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_THICK_FAT
	.byte ABILITY_GUTS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Hariyama
	base_stats 144, 120, 60, 50, 40, 60
	.byte TYPE_FIGHTING
	.byte TYPE_FIGHTING
	.byte 200 @ catch rate
	.byte 184 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_KINGS_ROCK
	.byte 63 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_THICK_FAT
	.byte ABILITY_GUTS
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Electrike
	base_stats 40, 45, 40, 65, 65, 40
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 120 @ catch rate
	.byte 104 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_STATIC
	.byte ABILITY_LIGHTNING_ROD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Manectric
	base_stats 70, 75, 60, 105, 105, 60
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 45 @ catch rate
	.byte 168 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_STATIC
	.byte ABILITY_LIGHTNING_ROD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Numel
	base_stats 60, 60, 40, 35, 65, 45
	.byte TYPE_FIRE
	.byte TYPE_GROUND
	.byte 255 @ catch rate
	.byte 88 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Camerupt
	base_stats 70, 100, 70, 40, 105, 75
	.byte TYPE_FIRE
	.byte TYPE_GROUND
	.byte 150 @ catch rate
	.byte 175 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 0
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_RAWST_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_MAGMA_ARMOR
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Spheal
	base_stats 70, 40, 50, 25, 55, 50
	.byte TYPE_ICE
	.byte TYPE_WATER
	.byte 255 @ catch rate
	.byte 75 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Sealeo
	base_stats 90, 60, 70, 45, 75, 70
	.byte TYPE_ICE
	.byte TYPE_WATER
	.byte 120 @ catch rate
	.byte 128 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Walrein
	base_stats 110, 80, 90, 65, 95, 90
	.byte TYPE_ICE
	.byte TYPE_WATER
	.byte 45 @ catch rate
	.byte 192 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Cacnea
	base_stats 50, 85, 40, 35, 85, 40
	.byte TYPE_GRASS
	.byte TYPE_GRASS
	.byte 190 @ catch rate
	.byte 97 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_POISON_BARB
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Cacturne
	base_stats 70, 115, 60, 55, 115, 60
	.byte TYPE_GRASS
	.byte TYPE_DARK
	.byte 60 @ catch rate
	.byte 177 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_POISON_BARB
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_GRASS
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Snorunt
	base_stats 50, 50, 50, 50, 50, 50
	.byte TYPE_ICE
	.byte TYPE_ICE
	.byte 190 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Glalie
	base_stats 80, 80, 80, 80, 80, 80
	.byte TYPE_ICE
	.byte TYPE_ICE
	.byte 75 @ catch rate
	.byte 187 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NEVER_MELT_ICE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_INNER_FOCUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Lunatone
	base_stats 70, 55, 65, 70, 95, 85
	.byte TYPE_ROCK
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 150 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_MOON_STONE
	.byte 255 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Solrock
	base_stats 70, 95, 85, 70, 55, 65
	.byte TYPE_ROCK
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 150 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SUN_STONE
	.byte 255 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Azurill
	base_stats 50, 20, 40, 20, 20, 40
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 150 @ catch rate
	.byte 33 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 191 @ gender
	.byte 10 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_THICK_FAT
	.byte ABILITY_HUGE_POWER
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Spoink
	base_stats 60, 25, 35, 60, 70, 80
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 255 @ catch rate
	.byte 89 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_OWN_TEMPO
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Grumpig
	base_stats 80, 45, 65, 80, 90, 110
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 60 @ catch rate
	.byte 164 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_THICK_FAT
	.byte ABILITY_OWN_TEMPO
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Plusle
	base_stats 60, 50, 40, 95, 85, 75
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 200 @ catch rate
	.byte 120 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_PLUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Minun
	base_stats 60, 40, 50, 95, 75, 85
	.byte TYPE_ELECTRIC
	.byte TYPE_ELECTRIC
	.byte 200 @ catch rate
	.byte 120 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_MINUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Mawile
	base_stats 50, 85, 85, 50, 55, 55
	.byte TYPE_STEEL
	.byte TYPE_STEEL
	.byte 45 @ catch rate
	.byte 98 @ base exp. yield
	ev_yield 0, 1, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FAIRY
	.byte ABILITY_HYPER_CUTTER
	.byte ABILITY_INTIMIDATE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Meditite
	base_stats 30, 40, 55, 60, 40, 55
	.byte TYPE_FIGHTING
	.byte TYPE_PSYCHIC
	.byte 180 @ catch rate
	.byte 91 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_PURE_POWER
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Medicham
	base_stats 60, 60, 75, 80, 60, 75
	.byte TYPE_FIGHTING
	.byte TYPE_PSYCHIC
	.byte 90 @ catch rate
	.byte 153 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_HUMAN_LIKE
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_PURE_POWER
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Swablu
	base_stats 45, 40, 60, 50, 40, 75
	.byte TYPE_NORMAL
	.byte TYPE_FLYING
	.byte 255 @ catch rate
	.byte 74 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_NATURAL_CURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Altaria
	base_stats 75, 70, 90, 80, 70, 105
	.byte TYPE_DRAGON
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 188 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_FLYING
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_NATURAL_CURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Wynaut
	base_stats 95, 23, 48, 23, 23, 48
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 125 @ catch rate
	.byte 44 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_SHADOW_TAG
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Duskull
	base_stats 20, 40, 90, 25, 30, 90
	.byte TYPE_GHOST
	.byte TYPE_GHOST
	.byte 190 @ catch rate
	.byte 97 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_SPELL_TAG
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Dusclops
	base_stats 40, 70, 130, 25, 60, 130
	.byte TYPE_GHOST
	.byte TYPE_GHOST
	.byte 90 @ catch rate
	.byte 179 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_SPELL_TAG
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Roselia
	base_stats 50, 60, 45, 65, 100, 80
	.byte TYPE_GRASS
	.byte TYPE_POISON
	.byte 150 @ catch rate
	.byte 152 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_POISON_BARB
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_GRASS
	.byte ABILITY_NATURAL_CURE
	.byte ABILITY_POISON_POINT
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Slakoth
	base_stats 60, 60, 60, 30, 35, 35
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 255 @ catch rate
	.byte 83 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_TRUANT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Vigoroth
	base_stats 80, 80, 80, 90, 55, 55
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 120 @ catch rate
	.byte 126 @ base exp. yield
	ev_yield 0, 0, 0, 2, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_VITAL_SPIRIT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Slaking
	base_stats 150, 160, 100, 100, 95, 65
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 210 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_TRUANT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Gulpin
	base_stats 70, 43, 53, 40, 43, 53
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 225 @ catch rate
	.byte 75 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_BIG_PEARL
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LIQUID_OOZE
	.byte ABILITY_STICKY_HOLD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Swalot
	base_stats 100, 73, 83, 55, 73, 83
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 75 @ catch rate
	.byte 168 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_BIG_PEARL
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LIQUID_OOZE
	.byte ABILITY_STICKY_HOLD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Tropius
	base_stats 99, 68, 83, 51, 72, 87
	.byte TYPE_GRASS
	.byte TYPE_FLYING
	.byte 200 @ catch rate
	.byte 169 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_GRASS
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Whismur
	base_stats 64, 51, 23, 28, 51, 23
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 190 @ catch rate
	.byte 68 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_CHESTO_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SOUNDPROOF
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Loudred
	base_stats 84, 71, 43, 48, 71, 43
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 120 @ catch rate
	.byte 126 @ base exp. yield
	ev_yield 2, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_CHESTO_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SOUNDPROOF
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Exploud
	base_stats 104, 91, 63, 68, 91, 63
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 184 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_CHESTO_BERRY
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_FIELD
	.byte ABILITY_SOUNDPROOF
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Clamperl
	base_stats 35, 64, 85, 32, 74, 55
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 255 @ catch rate
	.byte 142 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_BLUE_SHARD
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_SHELL_ARMOR
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Huntail
	base_stats 55, 104, 105, 52, 94, 75
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 60 @ catch rate
	.byte 178 @ base exp. yield
	ev_yield 0, 1, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Gorebyss
	base_stats 55, 84, 105, 52, 114, 75
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 60 @ catch rate
	.byte 178 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_1
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PINK
	.2byte 0 @ padding

@ Absol
	base_stats 65, 130, 60, 75, 75, 60
	.byte TYPE_DARK
	.byte TYPE_DARK
	.byte 30 @ catch rate
	.byte 174 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_MEDIUM_SLOW
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Shuppet
	base_stats 44, 75, 35, 45, 63, 33
	.byte TYPE_GHOST
	.byte TYPE_GHOST
	.byte 225 @ catch rate
	.byte 97 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SPELL_TAG
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_INSOMNIA
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Banette
	base_stats 64, 115, 65, 65, 83, 63
	.byte TYPE_GHOST
	.byte TYPE_GHOST
	.byte 45 @ catch rate
	.byte 179 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_SPELL_TAG
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_INSOMNIA
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Seviper
	base_stats 73, 100, 60, 65, 100, 60
	.byte TYPE_POISON
	.byte TYPE_POISON
	.byte 90 @ catch rate
	.byte 165 @ base exp. yield
	ev_yield 0, 1, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_BLACK
	.2byte 0 @ padding

@ Zangoose
	base_stats 73, 115, 60, 90, 60, 60
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 90 @ catch rate
	.byte 165 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_FIELD
	.byte EGG_GROUP_FIELD
	.byte ABILITY_IMMUNITY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Relicanth
	base_stats 100, 90, 130, 55, 45, 65
	.byte TYPE_WATER
	.byte TYPE_ROCK
	.byte 25 @ catch rate
	.byte 198 @ base exp. yield
	ev_yield 1, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_GREEN_SHARD
	.byte 31 @ gender
	.byte 40 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_WATER_1
	.byte EGG_GROUP_WATER_2
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_ROCK_HEAD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Aron
	base_stats 50, 70, 100, 30, 40, 40
	.byte TYPE_STEEL
	.byte TYPE_ROCK
	.byte 180 @ catch rate
	.byte 96 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_HARD_STONE
	.byte 127 @ gender
	.byte 35 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_STURDY
	.byte ABILITY_ROCK_HEAD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Lairon
	base_stats 60, 90, 140, 40, 50, 50
	.byte TYPE_STEEL
	.byte TYPE_ROCK
	.byte 90 @ catch rate
	.byte 152 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_HARD_STONE
	.byte 127 @ gender
	.byte 35 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_STURDY
	.byte ABILITY_ROCK_HEAD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Aggron
	base_stats 70, 110, 180, 50, 60, 60
	.byte TYPE_STEEL
	.byte TYPE_ROCK
	.byte 45 @ catch rate
	.byte 205 @ base exp. yield
	ev_yield 0, 0, 3, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_HARD_STONE
	.byte 127 @ gender
	.byte 35 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MONSTER
	.byte EGG_GROUP_MONSTER
	.byte ABILITY_STURDY
	.byte ABILITY_ROCK_HEAD
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Castform
	base_stats 70, 70, 70, 70, 70, 70
	.byte TYPE_NORMAL
	.byte TYPE_NORMAL
	.byte 45 @ catch rate
	.byte 145 @ base exp. yield
	ev_yield 1, 0, 0, 0, 0, 0
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MYSTIC_WATER
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_MEDIUM_FAST
	.byte EGG_GROUP_FAIRY
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_FORECAST
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Volbeat
	base_stats 65, 73, 55, 85, 47, 75
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 150 @ catch rate
	.byte 146 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_ILLUMINATE
	.byte ABILITY_SWARM
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Illumise
	base_stats 65, 47, 55, 85, 73, 75
	.byte TYPE_BUG
	.byte TYPE_BUG
	.byte 150 @ catch rate
	.byte 146 @ base exp. yield
	ev_yield 0, 0, 0, 1, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 254 @ gender
	.byte 15 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FLUCTUATING
	.byte EGG_GROUP_BUG
	.byte EGG_GROUP_HUMAN_LIKE
	.byte ABILITY_OBLIVIOUS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Lileep
	base_stats 66, 41, 77, 23, 61, 87
	.byte TYPE_ROCK
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 121 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SUCTION_CUPS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_PURPLE
	.2byte 0 @ padding

@ Cradily
	base_stats 86, 81, 97, 43, 81, 107
	.byte TYPE_ROCK
	.byte TYPE_GRASS
	.byte 45 @ catch rate
	.byte 201 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 2
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_SUCTION_CUPS
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Anorith
	base_stats 45, 95, 50, 75, 40, 50
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte 45 @ catch rate
	.byte 119 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_BATTLE_ARMOR
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Armaldo
	base_stats 75, 125, 100, 45, 70, 80
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte 45 @ catch rate
	.byte 200 @ base exp. yield
	ev_yield 0, 2, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 31 @ gender
	.byte 30 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_ERRATIC
	.byte EGG_GROUP_WATER_3
	.byte EGG_GROUP_WATER_3
	.byte ABILITY_BATTLE_ARMOR
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Ralts
	base_stats 28, 25, 25, 40, 45, 35
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 235 @ catch rate
	.byte 70 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_TRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Kirlia
	base_stats 38, 35, 35, 50, 65, 55
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 120 @ catch rate
	.byte 140 @ base exp. yield
	ev_yield 0, 0, 0, 0, 2, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_TRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Gardevoir
	base_stats 68, 65, 65, 80, 125, 115
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 208 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 20 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_SYNCHRONIZE
	.byte ABILITY_TRACE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Bagon
	base_stats 45, 75, 60, 50, 40, 30
	.byte TYPE_DRAGON
	.byte TYPE_DRAGON
	.byte 45 @ catch rate
	.byte 89 @ base exp. yield
	ev_yield 0, 1, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_DRAGON
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Shelgon
	base_stats 65, 95, 100, 50, 60, 50
	.byte TYPE_DRAGON
	.byte TYPE_DRAGON
	.byte 45 @ catch rate
	.byte 144 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_DRAGON
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_ROCK_HEAD
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_WHITE
	.2byte 0 @ padding

@ Salamence
	base_stats 95, 135, 80, 100, 110, 80
	.byte TYPE_DRAGON
	.byte TYPE_FLYING
	.byte 45 @ catch rate
	.byte 218 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_DRAGON_SCALE
	.byte 127 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_DRAGON
	.byte EGG_GROUP_DRAGON
	.byte ABILITY_INTIMIDATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Beldum
	base_stats 40, 55, 80, 30, 35, 60
	.byte TYPE_STEEL
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 103 @ base exp. yield
	ev_yield 0, 0, 1, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_COAT
	.byte 255 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Metang
	base_stats 60, 75, 100, 50, 55, 80
	.byte TYPE_STEEL
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 153 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_COAT
	.byte 255 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Metagross
	base_stats 80, 135, 130, 70, 95, 90
	.byte TYPE_STEEL
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 210 @ base exp. yield
	ev_yield 0, 0, 3, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_METAL_COAT
	.byte 255 @ gender
	.byte 40 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_MINERAL
	.byte EGG_GROUP_MINERAL
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Regirock
	base_stats 80, 100, 200, 50, 50, 100
	.byte TYPE_ROCK
	.byte TYPE_ROCK
	.byte 3 @ catch rate
	.byte 217 @ base exp. yield
	ev_yield 0, 0, 3, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BROWN
	.2byte 0 @ padding

@ Regice
	base_stats 80, 50, 100, 50, 100, 200
	.byte TYPE_ICE
	.byte TYPE_ICE
	.byte 3 @ catch rate
	.byte 216 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Registeel
	base_stats 80, 75, 150, 50, 75, 150
	.byte TYPE_STEEL
	.byte TYPE_STEEL
	.byte 3 @ catch rate
	.byte 215 @ base exp. yield
	ev_yield 0, 0, 2, 0, 0, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 80 @ egg cycles
	.byte 35 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_CLEAR_BODY
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GRAY
	.2byte 0 @ padding

@ Kyogre
	base_stats 100, 100, 90, 90, 150, 140
	.byte TYPE_WATER
	.byte TYPE_WATER
	.byte 5 @ catch rate
	.byte 218 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_DRIZZLE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Groudon
	base_stats 100, 150, 140, 90, 100, 90
	.byte TYPE_GROUND
	.byte TYPE_GROUND
	.byte 5 @ catch rate
	.byte 218 @ base exp. yield
	ev_yield 0, 3, 0, 0, 0, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_DROUGHT
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Rayquaza
	base_stats 105, 150, 90, 95, 150, 90
	.byte TYPE_DRAGON
	.byte TYPE_FLYING
	.byte 3 @ catch rate
	.byte 220 @ base exp. yield
	ev_yield 0, 2, 0, 0, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_AIR_LOCK
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_GREEN
	.2byte 0 @ padding

@ Latias
	base_stats 80, 80, 90, 110, 110, 130
	.byte TYPE_DRAGON
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 211 @ base exp. yield
	ev_yield 0, 0, 0, 0, 0, 3
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 254 @ gender
	.byte 120 @ egg cycles
	.byte 90 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_RED
	.2byte 0 @ padding

@ Latios
	base_stats 80, 90, 80, 110, 130, 110
	.byte TYPE_DRAGON
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 211 @ base exp. yield
	ev_yield 0, 0, 0, 0, 3, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 0 @ gender
	.byte 120 @ egg cycles
	.byte 90 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding

@ Jirachi
	base_stats 100, 100, 100, 100, 100, 100
	.byte TYPE_STEEL
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 215 @ base exp. yield
	ev_yield 3, 0, 0, 0, 0, 0
	.2byte ITEM_STAR_PIECE
	.2byte ITEM_STAR_PIECE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 100 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_SERENE_GRACE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_YELLOW
	.2byte 0 @ padding

@ Deoxys
	base_stats 50, 150, 50, 150, 150, 50
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 3 @ catch rate
	.byte 215 @ base exp. yield
	ev_yield 0, 1, 0, 1, 1, 0
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 255 @ gender
	.byte 120 @ egg cycles
	.byte 0 @ base friendship
	.byte GROWTH_SLOW
	.byte EGG_GROUP_UNDISCOVERED
	.byte EGG_GROUP_UNDISCOVERED
	.byte ABILITY_PRESSURE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte F_SUMMARY_SCREEN_FLIP_SPRITE | BODY_COLOR_RED
	.2byte 0 @ padding

@ Chimecho
	base_stats 65, 50, 70, 65, 95, 80
	.byte TYPE_PSYCHIC
	.byte TYPE_PSYCHIC
	.byte 45 @ catch rate
	.byte 147 @ base exp. yield
	ev_yield 0, 0, 0, 0, 1, 1
	.2byte ITEM_NONE
	.2byte ITEM_NONE
	.byte 127 @ gender
	.byte 25 @ egg cycles
	.byte 70 @ base friendship
	.byte GROWTH_FAST
	.byte EGG_GROUP_AMORPHOUS
	.byte EGG_GROUP_AMORPHOUS
	.byte ABILITY_LEVITATE
	.byte ABILITY_NONE
	.byte 0 @ Safari Zone flee rate
	.byte BODY_COLOR_BLUE
	.2byte 0 @ padding
