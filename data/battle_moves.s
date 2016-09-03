	.align 2, 0

gBattleMoves:: @ 831C898
@ -
	.byte 0x00 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 0 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Pound
	.byte 0x00 @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Karate Chop
	.byte 0x2b @ effect
	.byte 50 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Double Slap
	.byte 0x1d @ effect
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Comet Punch
	.byte 0x1d @ effect
	.byte 18 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Mega Punch
	.byte 0x00 @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Pay Day
	.byte 0x22 @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fire Punch
	.byte 0x04 @ effect
	.byte 75 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Ice Punch
	.byte 0x05 @ effect
	.byte 75 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Thunder Punch
	.byte 0x06 @ effect
	.byte 75 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Scratch
	.byte 0x00 @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Vice Grip
	.byte 0x00 @ effect
	.byte 55 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Guillotine
	.byte 0x26 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Razor Wind
	.byte 0x27 @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Swords Dance
	.byte 0x32 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Cut
	.byte 0x00 @ effect
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Gust
	.byte 0x95 @ effect
	.byte 40 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Wing Attack
	.byte 0x00 @ effect
	.byte 60 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Whirlwind
	.byte 0x1c @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -6 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fly
	.byte 0x9b @ effect
	.byte 70 @ power
	.byte TYPE_FLYING
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Bind
	.byte 0x2a @ effect
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 20 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Slam
	.byte 0x00 @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Vine Whip
	.byte 0x00 @ effect
	.byte 35 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Stomp
	.byte 0x96 @ effect
	.byte 65 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Double Kick
	.byte 0x2c @ effect
	.byte 30 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Mega Kick
	.byte 0x00 @ effect
	.byte 120 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Jump Kick
	.byte 0x2d @ effect
	.byte 70 @ power
	.byte TYPE_FIGHTING
	.byte 95 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Rolling Kick
	.byte 0x1f @ effect
	.byte 60 @ power
	.byte TYPE_FIGHTING
	.byte 85 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Sand-Attack
	.byte 0x17 @ effect
	.byte 0 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Headbutt
	.byte 0x1f @ effect
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Horn Attack
	.byte 0x00 @ effect
	.byte 65 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Fury Attack
	.byte 0x1d @ effect
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Horn Drill
	.byte 0x26 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Tackle
	.byte 0x00 @ effect
	.byte 35 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Body Slam
	.byte 0x06 @ effect
	.byte 85 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Wrap
	.byte 0x2a @ effect
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Take Down
	.byte 0x30 @ effect
	.byte 90 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Thrash
	.byte 0x1b @ effect
	.byte 90 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 100 @ side effect chance
	.byte F_TARGET_RANDOM
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Double-Edge
	.byte 0xc6 @ effect
	.byte 120 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Tail Whip
	.byte 0x13 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Poison Sting
	.byte 0x02 @ effect
	.byte 15 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Twineedle
	.byte 0x4d @ effect
	.byte 25 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Pin Missile
	.byte 0x1d @ effect
	.byte 14 @ power
	.byte TYPE_BUG
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Leer
	.byte 0x13 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Bite
	.byte 0x1f @ effect
	.byte 60 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Growl
	.byte 0x12 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Roar
	.byte 0x1c @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -6 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sing
	.byte 0x01 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 55 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Supersonic
	.byte 0x31 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 55 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sonic Boom
	.byte 0x82 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Disable
	.byte 0x56 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 55 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Acid
	.byte 0x45 @ effect
	.byte 40 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Ember
	.byte 0x04 @ effect
	.byte 40 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Flamethrower
	.byte 0x04 @ effect
	.byte 95 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Mist
	.byte 0x2e @ effect
	.byte 0 @ power
	.byte TYPE_ICE
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Water Gun
	.byte 0x00 @ effect
	.byte 40 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Hydro Pump
	.byte 0x00 @ effect
	.byte 120 @ power
	.byte TYPE_WATER
	.byte 80 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Surf
	.byte 0x00 @ effect
	.byte 95 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Ice Beam
	.byte 0x05 @ effect
	.byte 95 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Blizzard
	.byte 0x05 @ effect
	.byte 120 @ power
	.byte TYPE_ICE
	.byte 70 @ accuracy
	.byte 5 @ PP
	.byte 10 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Psybeam
	.byte 0x4c @ effect
	.byte 65 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Bubble Beam
	.byte 0x46 @ effect
	.byte 65 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Aurora Beam
	.byte 0x44 @ effect
	.byte 65 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Hyper Beam
	.byte 0x50 @ effect
	.byte 150 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Peck
	.byte 0x00 @ effect
	.byte 35 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Drill Peck
	.byte 0x00 @ effect
	.byte 80 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Submission
	.byte 0x30 @ effect
	.byte 80 @ power
	.byte TYPE_FIGHTING
	.byte 80 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Low Kick
	.byte 0xc4 @ effect
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Counter
	.byte 0x59 @ effect
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte -5 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_MAKES_CONTACT @ misc. flags

@ Seismic Toss
	.byte 0x57 @ effect
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Strength
	.byte 0x00 @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Absorb
	.byte 0x03 @ effect
	.byte 20 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Mega Drain
	.byte 0x03 @ effect
	.byte 40 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Leech Seed
	.byte 0x54 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Growth
	.byte 0x0d @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Razor Leaf
	.byte 0x2b @ effect
	.byte 55 @ power
	.byte TYPE_GRASS
	.byte 95 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Solar Beam
	.byte 0x97 @ effect
	.byte 120 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Poison Powder
	.byte 0x42 @ effect
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 75 @ accuracy
	.byte 35 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Stun Spore
	.byte 0x43 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 75 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sleep Powder
	.byte 0x01 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 75 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Petal Dance
	.byte 0x1b @ effect
	.byte 70 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 100 @ side effect chance
	.byte F_TARGET_RANDOM
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ String Shot
	.byte 0x14 @ effect
	.byte 0 @ power
	.byte TYPE_BUG
	.byte 95 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Dragon Rage
	.byte 0x29 @ effect
	.byte 1 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fire Spin
	.byte 0x2a @ effect
	.byte 15 @ power
	.byte TYPE_FIRE
	.byte 70 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Thunder Shock
	.byte 0x06 @ effect
	.byte 40 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Thunderbolt
	.byte 0x06 @ effect
	.byte 95 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Thunder Wave
	.byte 0x43 @ effect
	.byte 0 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Thunder
	.byte 0x98 @ effect
	.byte 120 @ power
	.byte TYPE_ELECTRIC
	.byte 70 @ accuracy
	.byte 10 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Rock Throw
	.byte 0x00 @ effect
	.byte 50 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Earthquake
	.byte 0x93 @ effect
	.byte 100 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fissure
	.byte 0x26 @ effect
	.byte 1 @ power
	.byte TYPE_GROUND
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Dig
	.byte 0x9b @ effect
	.byte 60 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Toxic
	.byte 0x21 @ effect
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Confusion
	.byte 0x4c @ effect
	.byte 50 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Psychic
	.byte 0x48 @ effect
	.byte 90 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Hypnosis
	.byte 0x01 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 60 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Meditate
	.byte 0x0a @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Agility
	.byte 0x34 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Quick Attack
	.byte 0x67 @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 1 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Rage
	.byte 0x51 @ effect
	.byte 20 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Teleport
	.byte 0x99 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Night Shade
	.byte 0x57 @ effect
	.byte 1 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Mimic
	.byte 0x52 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Screech
	.byte 0x3b @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Double Team
	.byte 0x10 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Recover
	.byte 0x20 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Harden
	.byte 0x0b @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Minimize
	.byte 0x6c @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Smokescreen
	.byte 0x17 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Confuse Ray
	.byte 0x31 @ effect
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Withdraw
	.byte 0x0b @ effect
	.byte 0 @ power
	.byte TYPE_WATER
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Defense Curl
	.byte 0x9c @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Barrier
	.byte 0x33 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Light Screen
	.byte 0x23 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Haze
	.byte 0x19 @ effect
	.byte 0 @ power
	.byte TYPE_ICE
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Reflect
	.byte 0x41 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Focus Energy
	.byte 0x2f @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Bide
	.byte 0x1a @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Metronome
	.byte 0x53 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Mirror Move
	.byte 0x09 @ effect
	.byte 0 @ power
	.byte TYPE_FLYING
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Self-Destruct
	.byte 0x07 @ effect
	.byte 200 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Egg Bomb
	.byte 0x00 @ effect
	.byte 100 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Lick
	.byte 0x06 @ effect
	.byte 20 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Smog
	.byte 0x02 @ effect
	.byte 20 @ power
	.byte TYPE_POISON
	.byte 70 @ accuracy
	.byte 20 @ PP
	.byte 40 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sludge
	.byte 0x02 @ effect
	.byte 65 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Bone Club
	.byte 0x1f @ effect
	.byte 65 @ power
	.byte TYPE_GROUND
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fire Blast
	.byte 0x04 @ effect
	.byte 120 @ power
	.byte TYPE_FIRE
	.byte 85 @ accuracy
	.byte 5 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Waterfall
	.byte 0x00 @ effect
	.byte 80 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Clamp
	.byte 0x2a @ effect
	.byte 35 @ power
	.byte TYPE_WATER
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Swift
	.byte 0x11 @ effect
	.byte 60 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Skull Bash
	.byte 0x91 @ effect
	.byte 100 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Spike Cannon
	.byte 0x1d @ effect
	.byte 20 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Constrict
	.byte 0x46 @ effect
	.byte 10 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 35 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Amnesia
	.byte 0x36 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Kinesis
	.byte 0x17 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 80 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Soft-Boiled
	.byte 0x9d @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_SNATCH @ misc. flags

@ Hi Jump Kick
	.byte 0x2d @ effect
	.byte 85 @ power
	.byte TYPE_FIGHTING
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Glare
	.byte 0x43 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Dream Eater
	.byte 0x08 @ effect
	.byte 100 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Poison Gas
	.byte 0x42 @ effect
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 55 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Barrage
	.byte 0x1d @ effect
	.byte 15 @ power
	.byte TYPE_NORMAL
	.byte 85 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Leech Life
	.byte 0x03 @ effect
	.byte 20 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Lovely Kiss
	.byte 0x01 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sky Attack
	.byte 0x4b @ effect
	.byte 140 @ power
	.byte TYPE_FLYING
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Transform
	.byte 0x39 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Bubble
	.byte 0x46 @ effect
	.byte 20 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Dizzy Punch
	.byte 0x4c @ effect
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Spore
	.byte 0x01 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Flash
	.byte 0x17 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 70 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Psywave
	.byte 0x58 @ effect
	.byte 1 @ power
	.byte TYPE_PSYCHIC
	.byte 80 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Splash
	.byte 0x55 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Acid Armor
	.byte 0x33 @ effect
	.byte 0 @ power
	.byte TYPE_POISON
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Crabhammer
	.byte 0x2b @ effect
	.byte 90 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Explosion
	.byte 0x07 @ effect
	.byte 250 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fury Swipes
	.byte 0x1d @ effect
	.byte 18 @ power
	.byte TYPE_NORMAL
	.byte 80 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Bonemerang
	.byte 0x2c @ effect
	.byte 50 @ power
	.byte TYPE_GROUND
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Rest
	.byte 0x25 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Rock Slide
	.byte 0x1f @ effect
	.byte 75 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 30 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Hyper Fang
	.byte 0x1f @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Sharpen
	.byte 0x0a @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Conversion
	.byte 0x1e @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Tri Attack
	.byte 0x24 @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Super Fang
	.byte 0x28 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Slash
	.byte 0x2b @ effect
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Substitute
	.byte 0x4f @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Struggle
	.byte 0x30 @ effect
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 1 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Sketch
	.byte 0x5f @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 1 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Triple Kick
	.byte 0x68 @ effect
	.byte 10 @ power
	.byte TYPE_FIGHTING
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Thief
	.byte 0x69 @ effect
	.byte 40 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Spider Web
	.byte 0x6a @ effect
	.byte 0 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Mind Reader
	.byte 0x5e @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Nightmare
	.byte 0x6b @ effect
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Flame Wheel
	.byte 0x7d @ effect
	.byte 60 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Snore
	.byte 0x5c @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Curse
	.byte 0x6d @ effect
	.byte 0 @ power
	.byte TYPE_UNKNOWN
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Flail
	.byte 0x63 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Conversion 2
	.byte 0x5d @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Aeroblast
	.byte 0x2b @ effect
	.byte 100 @ power
	.byte TYPE_FLYING
	.byte 95 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Cotton Spore
	.byte 0x3c @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 85 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Reversal
	.byte 0x63 @ effect
	.byte 1 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Spite
	.byte 0x64 @ effect
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Powder Snow
	.byte 0x05 @ effect
	.byte 40 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Protect
	.byte 0x6f @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 3 @ priority
	.4byte 0 @ misc. flags

@ Mach Punch
	.byte 0x67 @ effect
	.byte 40 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 1 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Scary Face
	.byte 0x3c @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Faint Attack
	.byte 0x11 @ effect
	.byte 60 @ power
	.byte TYPE_DARK
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sweet Kiss
	.byte 0x31 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 75 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Belly Drum
	.byte 0x8e @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Sludge Bomb
	.byte 0x02 @ effect
	.byte 90 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Mud-Slap
	.byte 0x49 @ effect
	.byte 20 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Octazooka
	.byte 0x49 @ effect
	.byte 65 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 50 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Spikes
	.byte 0x70 @ effect
	.byte 0 @ power
	.byte TYPE_GROUND
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_ENEMY_SIDE
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Zap Cannon
	.byte 0x06 @ effect
	.byte 100 @ power
	.byte TYPE_ELECTRIC
	.byte 50 @ accuracy
	.byte 5 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Foresight
	.byte 0x71 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Destiny Bond
	.byte 0x62 @ effect
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Perish Song
	.byte 0x72 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Icy Wind
	.byte 0x46 @ effect
	.byte 55 @ power
	.byte TYPE_ICE
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Detect
	.byte 0x6f @ effect
	.byte 0 @ power
	.byte TYPE_FIGHTING
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 3 @ priority
	.4byte 0 @ misc. flags

@ Bone Rush
	.byte 0x1d @ effect
	.byte 25 @ power
	.byte TYPE_GROUND
	.byte 80 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Lock-On
	.byte 0x5e @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Outrage
	.byte 0x1b @ effect
	.byte 90 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte F_TARGET_RANDOM
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Sandstorm
	.byte 0x73 @ effect
	.byte 0 @ power
	.byte TYPE_ROCK
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Giga Drain
	.byte 0x03 @ effect
	.byte 60 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Endure
	.byte 0x74 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 3 @ priority
	.4byte 0 @ misc. flags

@ Charm
	.byte 0x3a @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Rollout
	.byte 0x75 @ effect
	.byte 30 @ power
	.byte TYPE_ROCK
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ False Swipe
	.byte 0x65 @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Swagger
	.byte 0x76 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Milk Drink
	.byte 0x9d @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH | F_AFFECTED_BY_PROTECT @ misc. flags

@ Spark
	.byte 0x06 @ effect
	.byte 65 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Fury Cutter
	.byte 0x77 @ effect
	.byte 10 @ power
	.byte TYPE_BUG
	.byte 95 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Steel Wing
	.byte 0x8a @ effect
	.byte 70 @ power
	.byte TYPE_STEEL
	.byte 90 @ accuracy
	.byte 25 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Mean Look
	.byte 0x6a @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Attract
	.byte 0x78 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sleep Talk
	.byte 0x61 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Heal Bell
	.byte 0x66 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Return
	.byte 0x79 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Present
	.byte 0x7a @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Frustration
	.byte 0x7b @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Safeguard
	.byte 0x7c @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Pain Split
	.byte 0x5b @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sacred Fire
	.byte 0x7d @ effect
	.byte 100 @ power
	.byte TYPE_FIRE
	.byte 95 @ accuracy
	.byte 5 @ PP
	.byte 50 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Magnitude
	.byte 0x7e @ effect
	.byte 1 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Dynamic Punch
	.byte 0x4c @ effect
	.byte 100 @ power
	.byte TYPE_FIGHTING
	.byte 50 @ accuracy
	.byte 5 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Megahorn
	.byte 0x00 @ effect
	.byte 120 @ power
	.byte TYPE_BUG
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Dragon Breath
	.byte 0x06 @ effect
	.byte 60 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Baton Pass
	.byte 0x7f @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Encore
	.byte 0x5a @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Pursuit
	.byte 0x80 @ effect
	.byte 40 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Rapid Spin
	.byte 0x81 @ effect
	.byte 20 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Sweet Scent
	.byte 0x18 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Iron Tail
	.byte 0x45 @ effect
	.byte 100 @ power
	.byte TYPE_STEEL
	.byte 75 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Metal Claw
	.byte 0x8b @ effect
	.byte 50 @ power
	.byte TYPE_STEEL
	.byte 95 @ accuracy
	.byte 35 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Vital Throw
	.byte 0x4e @ effect
	.byte 70 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -1 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Morning Sun
	.byte 0x84 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Synthesis
	.byte 0x85 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Moonlight
	.byte 0x86 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Hidden Power
	.byte 0x87 @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Cross Chop
	.byte 0x2b @ effect
	.byte 100 @ power
	.byte TYPE_FIGHTING
	.byte 80 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Twister
	.byte 0x92 @ effect
	.byte 40 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 20 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Rain Dance
	.byte 0x88 @ effect
	.byte 0 @ power
	.byte TYPE_WATER
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Sunny Day
	.byte 0x89 @ effect
	.byte 0 @ power
	.byte TYPE_FIRE
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Crunch
	.byte 0x48 @ effect
	.byte 80 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Mirror Coat
	.byte 0x90 @ effect
	.byte 1 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte -5 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE @ misc. flags

@ Psych Up
	.byte 0x8f @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Extreme Speed
	.byte 0x67 @ effect
	.byte 80 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 1 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Ancient Power
	.byte 0x8c @ effect
	.byte 60 @ power
	.byte TYPE_ROCK
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Shadow Ball
	.byte 0x48 @ effect
	.byte 80 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Future Sight
	.byte 0x94 @ effect
	.byte 80 @ power
	.byte TYPE_PSYCHIC
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Rock Smash
	.byte 0x45 @ effect
	.byte 20 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 50 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Whirlpool
	.byte 0x2a @ effect
	.byte 15 @ power
	.byte TYPE_WATER
	.byte 70 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Beat Up
	.byte 0x9a @ effect
	.byte 10 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Fake Out
	.byte 0x9e @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 1 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Uproar
	.byte 0x9f @ effect
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 100 @ side effect chance
	.byte F_TARGET_RANDOM
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Stockpile
	.byte 0xa0 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Spit Up
	.byte 0xa1 @ effect
	.byte 100 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_AFFECTED_BY_PROTECT @ misc. flags

@ Swallow
	.byte 0xa2 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Heat Wave
	.byte 0x04 @ effect
	.byte 100 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 10 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Hail
	.byte 0xa4 @ effect
	.byte 0 @ power
	.byte TYPE_ICE
	.byte 0 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Torment
	.byte 0xa5 @ effect
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Flatter
	.byte 0xa6 @ effect
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Will-O-Wisp
	.byte 0xa7 @ effect
	.byte 0 @ power
	.byte TYPE_FIRE
	.byte 75 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Memento
	.byte 0xa8 @ effect
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Facade
	.byte 0xa9 @ effect
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Focus Punch
	.byte 0xaa @ effect
	.byte 150 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -3 @ priority
	.4byte F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Smelling Salt
	.byte 0xab @ effect
	.byte 60 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Follow Me
	.byte 0xac @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 3 @ priority
	.4byte 0 @ misc. flags

@ Nature Power
	.byte 0xad @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Charge
	.byte 0xae @ effect
	.byte 0 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Taunt
	.byte 0xaf @ effect
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Helping Hand
	.byte 0xb0 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 5 @ priority
	.4byte 0 @ misc. flags

@ Trick
	.byte 0xb1 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Role Play
	.byte 0xb2 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Wish
	.byte 0xb3 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Assist
	.byte 0xb4 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Ingrain
	.byte 0xb5 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Superpower
	.byte 0xb6 @ effect
	.byte 120 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Magic Coat
	.byte 0xb7 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 4 @ priority
	.4byte 0 @ misc. flags

@ Recycle
	.byte 0xb8 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Revenge
	.byte 0xb9 @ effect
	.byte 60 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte -4 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Brick Break
	.byte 0xba @ effect
	.byte 75 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Yawn
	.byte 0xbb @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Knock Off
	.byte 0xbc @ effect
	.byte 20 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Endeavor
	.byte 0xbd @ effect
	.byte 1 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Eruption
	.byte 0xbe @ effect
	.byte 150 @ power
	.byte TYPE_FIRE
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Skill Swap
	.byte 0xbf @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Imprison
	.byte 0xc0 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Refresh
	.byte 0xc1 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Grudge
	.byte 0xc2 @ effect
	.byte 0 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Snatch
	.byte 0xc3 @ effect
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_SPECIAL
	.byte 4 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE @ misc. flags

@ Secret Power
	.byte 0xc5 @ effect
	.byte 70 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Dive
	.byte 0x9b @ effect
	.byte 60 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Arm Thrust
	.byte 0x1d @ effect
	.byte 15 @ power
	.byte TYPE_FIGHTING
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Camouflage
	.byte 0xd5 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Tail Glow
	.byte 0x35 @ effect
	.byte 0 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Luster Purge
	.byte 0x48 @ effect
	.byte 70 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 50 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Mist Ball
	.byte 0x47 @ effect
	.byte 70 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 50 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Feather Dance
	.byte 0x3a @ effect
	.byte 0 @ power
	.byte TYPE_FLYING
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Teeter Dance
	.byte 0xc7 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_ALL_EXCEPT_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_PROTECT @ misc. flags

@ Blaze Kick
	.byte 0xc8 @ effect
	.byte 85 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 10 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Mud Sport
	.byte 0xc9 @ effect
	.byte 0 @ power
	.byte TYPE_GROUND
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Ice Ball
	.byte 0x75 @ effect
	.byte 30 @ power
	.byte TYPE_ICE
	.byte 90 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Needle Arm
	.byte 0x96 @ effect
	.byte 60 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Slack Off
	.byte 0x20 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Hyper Voice
	.byte 0x00 @ effect
	.byte 90 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Poison Fang
	.byte 0xca @ effect
	.byte 50 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Crush Claw
	.byte 0x45 @ effect
	.byte 75 @ power
	.byte TYPE_NORMAL
	.byte 95 @ accuracy
	.byte 10 @ PP
	.byte 50 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Blast Burn
	.byte 0x50 @ effect
	.byte 150 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Hydro Cannon
	.byte 0x50 @ effect
	.byte 150 @ power
	.byte TYPE_WATER
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Meteor Mash
	.byte 0x8b @ effect
	.byte 100 @ power
	.byte TYPE_STEEL
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Astonish
	.byte 0x96 @ effect
	.byte 30 @ power
	.byte TYPE_GHOST
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Weather Ball
	.byte 0xcb @ effect
	.byte 50 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Aromatherapy
	.byte 0x66 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 0 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Fake Tears
	.byte 0x3e @ effect
	.byte 0 @ power
	.byte TYPE_DARK
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Air Cutter
	.byte 0x2b @ effect
	.byte 55 @ power
	.byte TYPE_FLYING
	.byte 95 @ accuracy
	.byte 25 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Overheat
	.byte 0xcc @ effect
	.byte 140 @ power
	.byte TYPE_FIRE
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Odor Sleuth
	.byte 0x71 @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Rock Tomb
	.byte 0x46 @ effect
	.byte 50 @ power
	.byte TYPE_ROCK
	.byte 80 @ accuracy
	.byte 10 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Silver Wind
	.byte 0x8c @ effect
	.byte 60 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Metal Sound
	.byte 0x3e @ effect
	.byte 0 @ power
	.byte TYPE_STEEL
	.byte 85 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Grass Whistle
	.byte 0x01 @ effect
	.byte 0 @ power
	.byte TYPE_GRASS
	.byte 55 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Tickle
	.byte 0xcd @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Cosmic Power
	.byte 0xce @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Water Spout
	.byte 0xbe @ effect
	.byte 150 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Signal Beam
	.byte 0x4c @ effect
	.byte 75 @ power
	.byte TYPE_BUG
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Shadow Punch
	.byte 0x11 @ effect
	.byte 60 @ power
	.byte TYPE_GHOST
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Extrasensory
	.byte 0x96 @ effect
	.byte 80 @ power
	.byte TYPE_PSYCHIC
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sky Uppercut
	.byte 0xcf @ effect
	.byte 85 @ power
	.byte TYPE_FIGHTING
	.byte 90 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Sand Tomb
	.byte 0x2a @ effect
	.byte 15 @ power
	.byte TYPE_GROUND
	.byte 70 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Sheer Cold
	.byte 0x26 @ effect
	.byte 1 @ power
	.byte TYPE_ICE
	.byte 30 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Muddy Water
	.byte 0x49 @ effect
	.byte 95 @ power
	.byte TYPE_WATER
	.byte 85 @ accuracy
	.byte 10 @ PP
	.byte 30 @ side effect chance
	.byte F_TARGET_BOTH_ENEMIES
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Bullet Seed
	.byte 0x1d @ effect
	.byte 10 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Aerial Ace
	.byte 0x11 @ effect
	.byte 60 @ power
	.byte TYPE_FLYING
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Icicle Spear
	.byte 0x1d @ effect
	.byte 10 @ power
	.byte TYPE_ICE
	.byte 100 @ accuracy
	.byte 30 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Iron Defense
	.byte 0x33 @ effect
	.byte 0 @ power
	.byte TYPE_STEEL
	.byte 0 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Block
	.byte 0x6a @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_MAGIC_COAT | F_AFFECTED_BY_PROTECT @ misc. flags

@ Howl
	.byte 0x0a @ effect
	.byte 0 @ power
	.byte TYPE_NORMAL
	.byte 0 @ accuracy
	.byte 40 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Dragon Claw
	.byte 0x00 @ effect
	.byte 80 @ power
	.byte TYPE_DRAGON
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Frenzy Plant
	.byte 0x50 @ effect
	.byte 150 @ power
	.byte TYPE_GRASS
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Bulk Up
	.byte 0xd0 @ effect
	.byte 0 @ power
	.byte TYPE_FIGHTING
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Bounce
	.byte 0x9b @ effect
	.byte 85 @ power
	.byte TYPE_FLYING
	.byte 85 @ accuracy
	.byte 5 @ PP
	.byte 30 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Mud Shot
	.byte 0x46 @ effect
	.byte 55 @ power
	.byte TYPE_GROUND
	.byte 95 @ accuracy
	.byte 15 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Poison Tail
	.byte 0xd1 @ effect
	.byte 50 @ power
	.byte TYPE_POISON
	.byte 100 @ accuracy
	.byte 25 @ PP
	.byte 10 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Covet
	.byte 0x69 @ effect
	.byte 40 @ power
	.byte TYPE_NORMAL
	.byte 100 @ accuracy
	.byte 40 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Volt Tackle
	.byte 0xc6 @ effect
	.byte 120 @ power
	.byte TYPE_ELECTRIC
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Magical Leaf
	.byte 0x11 @ effect
	.byte 60 @ power
	.byte TYPE_GRASS
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Water Sport
	.byte 0xd2 @ effect
	.byte 0 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Calm Mind
	.byte 0xd3 @ effect
	.byte 0 @ power
	.byte TYPE_PSYCHIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Leaf Blade
	.byte 0x2b @ effect
	.byte 70 @ power
	.byte TYPE_GRASS
	.byte 100 @ accuracy
	.byte 15 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT | F_MAKES_CONTACT @ misc. flags

@ Dragon Dance
	.byte 0xd4 @ effect
	.byte 0 @ power
	.byte TYPE_DRAGON
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte F_TARGET_USER
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_SNATCH @ misc. flags

@ Rock Blast
	.byte 0x1d @ effect
	.byte 25 @ power
	.byte TYPE_ROCK
	.byte 80 @ accuracy
	.byte 10 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Shock Wave
	.byte 0x11 @ effect
	.byte 60 @ power
	.byte TYPE_ELECTRIC
	.byte 0 @ accuracy
	.byte 20 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Water Pulse
	.byte 0x4c @ effect
	.byte 60 @ power
	.byte TYPE_WATER
	.byte 100 @ accuracy
	.byte 20 @ PP
	.byte 20 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags

@ Doom Desire
	.byte 0x94 @ effect
	.byte 120 @ power
	.byte TYPE_STEEL
	.byte 85 @ accuracy
	.byte 5 @ PP
	.byte 0 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte 0 @ misc. flags

@ Psycho Boost
	.byte 0xcc @ effect
	.byte 140 @ power
	.byte TYPE_PSYCHIC
	.byte 90 @ accuracy
	.byte 5 @ PP
	.byte 100 @ side effect chance
	.byte TARGET_SELECTED_POKEMON
	.byte 0 @ priority
	.4byte F_AFFECTED_BY_KINGS_ROCK | F_MIRROR_MOVE_COMPATIBLE | F_AFFECTED_BY_PROTECT @ misc. flags
