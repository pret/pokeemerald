#include "constants/battle.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_anim_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gMovesWithQuietBGM::
	.2byte MOVE_SING, MOVE_PERISH_SONG, MOVE_GRASS_WHISTLE, 0xFFFF

	.align 2
gBattleAnims_Moves::
	.4byte Move_NONE
	.4byte Move_POUND
	.4byte Move_KARATE_CHOP
	.4byte Move_DOUBLE_SLAP
	.4byte Move_COMET_PUNCH
	.4byte Move_MEGA_PUNCH
	.4byte Move_PAY_DAY
	.4byte Move_FIRE_PUNCH
	.4byte Move_ICE_PUNCH
	.4byte Move_THUNDER_PUNCH
	.4byte Move_SCRATCH
	.4byte Move_VICE_GRIP
	.4byte Move_GUILLOTINE
	.4byte Move_RAZOR_WIND
	.4byte Move_SWORDS_DANCE
	.4byte Move_CUT
	.4byte Move_GUST
	.4byte Move_WING_ATTACK
	.4byte Move_WHIRLWIND
	.4byte Move_FLY
	.4byte Move_BIND
	.4byte Move_SLAM
	.4byte Move_VINE_WHIP
	.4byte Move_STOMP
	.4byte Move_DOUBLE_KICK
	.4byte Move_MEGA_KICK
	.4byte Move_JUMP_KICK
	.4byte Move_ROLLING_KICK
	.4byte Move_SAND_ATTACK
	.4byte Move_HEADBUTT
	.4byte Move_HORN_ATTACK
	.4byte Move_FURY_ATTACK
	.4byte Move_HORN_DRILL
	.4byte Move_TACKLE
	.4byte Move_BODY_SLAM
	.4byte Move_WRAP
	.4byte Move_TAKE_DOWN
	.4byte Move_THRASH
	.4byte Move_DOUBLE_EDGE
	.4byte Move_TAIL_WHIP
	.4byte Move_POISON_STING
	.4byte Move_TWINEEDLE
	.4byte Move_PIN_MISSILE
	.4byte Move_LEER
	.4byte Move_BITE
	.4byte Move_GROWL
	.4byte Move_ROAR
	.4byte Move_SING
	.4byte Move_SUPERSONIC
	.4byte Move_SONIC_BOOM
	.4byte Move_DISABLE
	.4byte Move_ACID
	.4byte Move_EMBER
	.4byte Move_FLAMETHROWER
	.4byte Move_MIST
	.4byte Move_WATER_GUN
	.4byte Move_HYDRO_PUMP
	.4byte Move_SURF
	.4byte Move_ICE_BEAM
	.4byte Move_BLIZZARD
	.4byte Move_PSYBEAM
	.4byte Move_BUBBLE_BEAM
	.4byte Move_AURORA_BEAM
	.4byte Move_HYPER_BEAM
	.4byte Move_PECK
	.4byte Move_DRILL_PECK
	.4byte Move_SUBMISSION
	.4byte Move_LOW_KICK
	.4byte Move_COUNTER
	.4byte Move_SEISMIC_TOSS
	.4byte Move_STRENGTH
	.4byte Move_ABSORB
	.4byte Move_MEGA_DRAIN
	.4byte Move_LEECH_SEED
	.4byte Move_GROWTH
	.4byte Move_RAZOR_LEAF
	.4byte Move_SOLAR_BEAM
	.4byte Move_POISON_POWDER
	.4byte Move_STUN_SPORE
	.4byte Move_SLEEP_POWDER
	.4byte Move_PETAL_DANCE
	.4byte Move_STRING_SHOT
	.4byte Move_DRAGON_RAGE
	.4byte Move_FIRE_SPIN
	.4byte Move_THUNDER_SHOCK
	.4byte Move_THUNDERBOLT
	.4byte Move_THUNDER_WAVE
	.4byte Move_THUNDER
	.4byte Move_ROCK_THROW
	.4byte Move_EARTHQUAKE
	.4byte Move_FISSURE
	.4byte Move_DIG
	.4byte Move_TOXIC
	.4byte Move_CONFUSION
	.4byte Move_PSYCHIC
	.4byte Move_HYPNOSIS
	.4byte Move_MEDITATE
	.4byte Move_AGILITY
	.4byte Move_QUICK_ATTACK
	.4byte Move_RAGE
	.4byte Move_TELEPORT
	.4byte Move_NIGHT_SHADE
	.4byte Move_MIMIC
	.4byte Move_SCREECH
	.4byte Move_DOUBLE_TEAM
	.4byte Move_RECOVER
	.4byte Move_HARDEN
	.4byte Move_MINIMIZE
	.4byte Move_SMOKESCREEN
	.4byte Move_CONFUSE_RAY
	.4byte Move_WITHDRAW
	.4byte Move_DEFENSE_CURL
	.4byte Move_BARRIER
	.4byte Move_LIGHT_SCREEN
	.4byte Move_HAZE
	.4byte Move_REFLECT
	.4byte Move_FOCUS_ENERGY
	.4byte Move_BIDE
	.4byte Move_METRONOME
	.4byte Move_MIRROR_MOVE @ doesn´t have an actual animation
	.4byte Move_SELF_DESTRUCT
	.4byte Move_EGG_BOMB
	.4byte Move_LICK
	.4byte Move_SMOG
	.4byte Move_SLUDGE
	.4byte Move_BONE_CLUB
	.4byte Move_FIRE_BLAST
	.4byte Move_WATERFALL
	.4byte Move_CLAMP
	.4byte Move_SWIFT
	.4byte Move_SKULL_BASH
	.4byte Move_SPIKE_CANNON
	.4byte Move_CONSTRICT
	.4byte Move_AMNESIA
	.4byte Move_KINESIS
	.4byte Move_SOFT_BOILED
	.4byte Move_HI_JUMP_KICK
	.4byte Move_GLARE
	.4byte Move_DREAM_EATER
	.4byte Move_POISON_GAS
	.4byte Move_BARRAGE
	.4byte Move_LEECH_LIFE
	.4byte Move_LOVELY_KISS
	.4byte Move_SKY_ATTACK
	.4byte Move_TRANSFORM
	.4byte Move_BUBBLE
	.4byte Move_DIZZY_PUNCH
	.4byte Move_SPORE
	.4byte Move_FLASH
	.4byte Move_PSYWAVE
	.4byte Move_SPLASH
	.4byte Move_ACID_ARMOR
	.4byte Move_CRABHAMMER
	.4byte Move_EXPLOSION
	.4byte Move_FURY_SWIPES
	.4byte Move_BONEMERANG
	.4byte Move_REST
	.4byte Move_ROCK_SLIDE
	.4byte Move_HYPER_FANG
	.4byte Move_SHARPEN
	.4byte Move_CONVERSION
	.4byte Move_TRI_ATTACK
	.4byte Move_SUPER_FANG
	.4byte Move_SLASH
	.4byte Move_SUBSTITUTE
	.4byte Move_STRUGGLE
	.4byte Move_SKETCH
	.4byte Move_TRIPLE_KICK
	.4byte Move_THIEF
	.4byte Move_SPIDER_WEB
	.4byte Move_MIND_READER
	.4byte Move_NIGHTMARE
	.4byte Move_FLAME_WHEEL
	.4byte Move_SNORE
	.4byte Move_CURSE
	.4byte Move_FLAIL
	.4byte Move_CONVERSION_2
	.4byte Move_AEROBLAST
	.4byte Move_COTTON_SPORE
	.4byte Move_REVERSAL
	.4byte Move_SPITE
	.4byte Move_POWDER_SNOW
	.4byte Move_PROTECT
	.4byte Move_MACH_PUNCH
	.4byte Move_SCARY_FACE
	.4byte Move_FAINT_ATTACK
	.4byte Move_SWEET_KISS
	.4byte Move_BELLY_DRUM
	.4byte Move_SLUDGE_BOMB
	.4byte Move_MUD_SLAP
	.4byte Move_OCTAZOOKA
	.4byte Move_SPIKES
	.4byte Move_ZAP_CANNON
	.4byte Move_FORESIGHT
	.4byte Move_DESTINY_BOND
	.4byte Move_PERISH_SONG
	.4byte Move_ICY_WIND
	.4byte Move_DETECT
	.4byte Move_BONE_RUSH
	.4byte Move_LOCK_ON
	.4byte Move_OUTRAGE
	.4byte Move_SANDSTORM
	.4byte Move_GIGA_DRAIN
	.4byte Move_ENDURE
	.4byte Move_CHARM
	.4byte Move_ROLLOUT
	.4byte Move_FALSE_SWIPE
	.4byte Move_SWAGGER
	.4byte Move_MILK_DRINK
	.4byte Move_SPARK
	.4byte Move_FURY_CUTTER
	.4byte Move_STEEL_WING
	.4byte Move_MEAN_LOOK
	.4byte Move_ATTRACT
	.4byte Move_SLEEP_TALK
	.4byte Move_HEAL_BELL
	.4byte Move_RETURN
	.4byte Move_PRESENT
	.4byte Move_FRUSTRATION
	.4byte Move_SAFEGUARD
	.4byte Move_PAIN_SPLIT
	.4byte Move_SACRED_FIRE
	.4byte Move_MAGNITUDE
	.4byte Move_DYNAMIC_PUNCH
	.4byte Move_MEGAHORN
	.4byte Move_DRAGON_BREATH
	.4byte Move_BATON_PASS
	.4byte Move_ENCORE
	.4byte Move_PURSUIT
	.4byte Move_RAPID_SPIN
	.4byte Move_SWEET_SCENT
	.4byte Move_IRON_TAIL
	.4byte Move_METAL_CLAW
	.4byte Move_VITAL_THROW
	.4byte Move_MORNING_SUN
	.4byte Move_SYNTHESIS
	.4byte Move_MOONLIGHT
	.4byte Move_HIDDEN_POWER
	.4byte Move_CROSS_CHOP
	.4byte Move_TWISTER
	.4byte Move_RAIN_DANCE
	.4byte Move_SUNNY_DAY
	.4byte Move_CRUNCH
	.4byte Move_MIRROR_COAT
	.4byte Move_PSYCH_UP
	.4byte Move_EXTREME_SPEED
	.4byte Move_ANCIENT_POWER
	.4byte Move_SHADOW_BALL
	.4byte Move_FUTURE_SIGHT
	.4byte Move_ROCK_SMASH
	.4byte Move_WHIRLPOOL
	.4byte Move_BEAT_UP
	.4byte Move_FAKE_OUT
	.4byte Move_UPROAR
	.4byte Move_STOCKPILE
	.4byte Move_SPIT_UP
	.4byte Move_SWALLOW
	.4byte Move_HEAT_WAVE
	.4byte Move_HAIL
	.4byte Move_TORMENT
	.4byte Move_FLATTER
	.4byte Move_WILL_O_WISP
	.4byte Move_MEMENTO
	.4byte Move_FACADE
	.4byte Move_FOCUS_PUNCH
	.4byte Move_SMELLING_SALT
	.4byte Move_FOLLOW_ME
	.4byte Move_NATURE_POWER @ doesnt have an actual animation
	.4byte Move_CHARGE
	.4byte Move_TAUNT
	.4byte Move_HELPING_HAND
	.4byte Move_TRICK
	.4byte Move_ROLE_PLAY
	.4byte Move_WISH
	.4byte Move_ASSIST
	.4byte Move_INGRAIN
	.4byte Move_SUPERPOWER
	.4byte Move_MAGIC_COAT
	.4byte Move_RECYCLE
	.4byte Move_REVENGE
	.4byte Move_BRICK_BREAK
	.4byte Move_YAWN
	.4byte Move_KNOCK_OFF
	.4byte Move_ENDEAVOR
	.4byte Move_ERUPTION
	.4byte Move_SKILL_SWAP
	.4byte Move_IMPRISON
	.4byte Move_REFRESH
	.4byte Move_GRUDGE
	.4byte Move_SNATCH
	.4byte Move_SECRET_POWER
	.4byte Move_DIVE
	.4byte Move_ARM_THRUST
	.4byte Move_CAMOUFLAGE
	.4byte Move_TAIL_GLOW
	.4byte Move_LUSTER_PURGE
	.4byte Move_MIST_BALL
	.4byte Move_FEATHER_DANCE
	.4byte Move_TEETER_DANCE
	.4byte Move_BLAZE_KICK
	.4byte Move_MUD_SPORT
	.4byte Move_ICE_BALL
	.4byte Move_NEEDLE_ARM
	.4byte Move_SLACK_OFF
	.4byte Move_HYPER_VOICE
	.4byte Move_POISON_FANG
	.4byte Move_CRUSH_CLAW
	.4byte Move_BLAST_BURN
	.4byte Move_HYDRO_CANNON
	.4byte Move_METEOR_MASH
	.4byte Move_ASTONISH
	.4byte Move_WEATHER_BALL
	.4byte Move_AROMATHERAPY
	.4byte Move_FAKE_TEARS
	.4byte Move_AIR_CUTTER
	.4byte Move_OVERHEAT
	.4byte Move_ODOR_SLEUTH
	.4byte Move_ROCK_TOMB
	.4byte Move_SILVER_WIND
	.4byte Move_METAL_SOUND
	.4byte Move_GRASS_WHISTLE
	.4byte Move_TICKLE
	.4byte Move_COSMIC_POWER
	.4byte Move_WATER_SPOUT
	.4byte Move_SIGNAL_BEAM
	.4byte Move_SHADOW_PUNCH
	.4byte Move_EXTRASENSORY
	.4byte Move_SKY_UPPERCUT
	.4byte Move_SAND_TOMB
	.4byte Move_SHEER_COLD
	.4byte Move_MUDDY_WATER
	.4byte Move_BULLET_SEED
	.4byte Move_AERIAL_ACE
	.4byte Move_ICICLE_SPEAR
	.4byte Move_IRON_DEFENSE
	.4byte Move_BLOCK
	.4byte Move_HOWL
	.4byte Move_DRAGON_CLAW
	.4byte Move_FRENZY_PLANT
	.4byte Move_BULK_UP
	.4byte Move_BOUNCE
	.4byte Move_MUD_SHOT
	.4byte Move_POISON_TAIL
	.4byte Move_COVET
	.4byte Move_VOLT_TACKLE
	.4byte Move_MAGICAL_LEAF
	.4byte Move_WATER_SPORT
	.4byte Move_CALM_MIND
	.4byte Move_LEAF_BLADE
	.4byte Move_DRAGON_DANCE
	.4byte Move_ROCK_BLAST
	.4byte Move_SHOCK_WAVE
	.4byte Move_WATER_PULSE
	.4byte Move_DOOM_DESIRE
	.4byte Move_PSYCHO_BOOST
	.4byte Move_ROOST
	.4byte Move_GRAVITY
	.4byte Move_MIRACLE_EYE
	.4byte Move_WAKE_UP_SLAP
	.4byte Move_HAMMER_ARM
	.4byte Move_GYRO_BALL
	.4byte Move_HEALING_WISH
	.4byte Move_BRINE
	.4byte Move_NATURAL_GIFT
	.4byte Move_FEINT
	.4byte Move_PLUCK
	.4byte Move_TAILWIND
	.4byte Move_ACUPRESSURE
	.4byte Move_METAL_BURST
	.4byte Move_U_TURN
	.4byte Move_CLOSE_COMBAT
	.4byte Move_PAYBACK
	.4byte Move_ASSURANCE
	.4byte Move_EMBARGO
	.4byte Move_FLING
	.4byte Move_PSYCHO_SHIFT
	.4byte Move_TRUMP_CARD
	.4byte Move_HEAL_BLOCK
	.4byte Move_WRING_OUT
	.4byte Move_POWER_TRICK
	.4byte Move_GASTRO_ACID
	.4byte Move_LUCKY_CHANT
	.4byte Move_ME_FIRST
	.4byte Move_COPYCAT
	.4byte Move_POWER_SWAP
	.4byte Move_GUARD_SWAP
	.4byte Move_PUNISHMENT
	.4byte Move_LAST_RESORT
	.4byte Move_WORRY_SEED
	.4byte Move_SUCKER_PUNCH
	.4byte Move_TOXIC_SPIKES
	.4byte Move_HEART_SWAP
	.4byte Move_AQUA_RING
	.4byte Move_MAGNET_RISE
	.4byte Move_FLARE_BLITZ
	.4byte Move_FORCE_PALM
	.4byte Move_AURA_SPHERE
	.4byte Move_ROCK_POLISH
	.4byte Move_POISON_JAB
	.4byte Move_DARK_PULSE
	.4byte Move_NIGHT_SLASH
	.4byte Move_AQUA_TAIL
	.4byte Move_SEED_BOMB
	.4byte Move_AIR_SLASH
	.4byte Move_XSCISSOR
	.4byte Move_BUG_BUZZ
	.4byte Move_DRAGON_PULSE
	.4byte Move_DRAGON_RUSH
	.4byte Move_POWER_GEM
	.4byte Move_DRAIN_PUNCH
	.4byte Move_VACUUM_WAVE
	.4byte Move_FOCUS_BLAST
	.4byte Move_ENERGY_BALL
	.4byte Move_BRAVE_BIRD
	.4byte Move_EARTH_POWER
	.4byte Move_SWITCHEROO
	.4byte Move_GIGA_IMPACT
	.4byte Move_NASTY_PLOT
	.4byte Move_BULLET_PUNCH
	.4byte Move_AVALANCHE
	.4byte Move_ICE_SHARD
	.4byte Move_SHADOW_CLAW
	.4byte Move_THUNDER_FANG
	.4byte Move_ICE_FANG
	.4byte Move_FIRE_FANG
	.4byte Move_SHADOW_SNEAK
	.4byte Move_MUD_BOMB
	.4byte Move_PSYCHO_CUT
	.4byte Move_ZEN_HEADBUTT
	.4byte Move_MIRROR_SHOT
	.4byte Move_FLASH_CANNON
	.4byte Move_ROCK_CLIMB
	.4byte Move_DEFOG
	.4byte Move_TRICK_ROOM
	.4byte Move_DRACO_METEOR
	.4byte Move_DISCHARGE
	.4byte Move_LAVA_PLUME
	.4byte Move_LEAF_STORM
	.4byte Move_POWER_WHIP
	.4byte Move_ROCK_WRECKER
	.4byte Move_CROSS_POISON
	.4byte Move_GUNK_SHOT
	.4byte Move_IRON_HEAD
	.4byte Move_MAGNET_BOMB
	.4byte Move_STONE_EDGE
	.4byte Move_CAPTIVATE
	.4byte Move_STEALTH_ROCK
	.4byte Move_GRASS_KNOT
	.4byte Move_CHATTER
	.4byte Move_JUDGMENT
	.4byte Move_BUG_BITE
	.4byte Move_CHARGE_BEAM
	.4byte Move_WOOD_HAMMER
	.4byte Move_AQUA_JET
	.4byte Move_ATTACK_ORDER
	.4byte Move_DEFEND_ORDER
	.4byte Move_HEAL_ORDER
	.4byte Move_HEAD_SMASH
	.4byte Move_DOUBLE_HIT
	.4byte Move_ROAR_OF_TIME
	.4byte Move_SPECIAL_REND
	.4byte Move_LUNAR_DANCE
	.4byte Move_CRUSH_GRIP
	.4byte Move_MAGMA_STORM
	.4byte Move_DARK_VOID
	.4byte Move_SEED_FLARE
	.4byte Move_OMINOUS_WIND
	.4byte Move_SHADOW_FORCE
	.4byte Move_HONE_CLAWS
	.4byte Move_WIDE_GUARD
	.4byte Move_GUARD_SPLIT
	.4byte Move_POWER_SPLIT
	.4byte Move_WONDER_ROOM
	.4byte Move_PSYSHOCK
	.4byte Move_VENOSHOCK
	.4byte Move_AUTOTOMIZE
	.4byte Move_RAGE_POWDER
	.4byte Move_TELEKINESIS
	.4byte Move_MAGIC_ROOM
	.4byte Move_SMACK_DOWN
	.4byte Move_STORM_THROW
	.4byte Move_FLAME_BURST
	.4byte Move_SLUDGE_WAVE
	.4byte Move_QUIVER_DANCE
	.4byte Move_HEAVY_SLAM
	.4byte Move_SYCHRONOISE
	.4byte Move_ELECTRO_BALL
	.4byte Move_SOAK
	.4byte Move_FLAME_CHARGE
	.4byte Move_COIL
	.4byte Move_LOW_SWEEP
	.4byte Move_ACID_SPRAY
	.4byte Move_FOUL_PLAY
	.4byte Move_SIMPLE_BEAM
	.4byte Move_ENTRAINMENT
	.4byte Move_AFTER_YOU
	.4byte Move_ROUND
	.4byte Move_ECHOED_VOICE
	.4byte Move_CHIP_AWAY
	.4byte Move_CLEAR_SMOG
	.4byte Move_STORED_POWER
	.4byte Move_QUICK_GUARD
	.4byte Move_ALLY_SWITCH
	.4byte Move_SCALD
	.4byte Move_SHELL_SMASH
	.4byte Move_HEAL_PULSE
	.4byte Move_HEX
	.4byte Move_SKY_DROP
	.4byte Move_SHIFT_GEAR
	.4byte Move_CIRCLE_THROW
	.4byte Move_INCINERATE
	.4byte Move_QUASH
	.4byte Move_ACROBATICS
	.4byte Move_REFLECT_TYPE
	.4byte Move_RETALITATE
	.4byte Move_FINAL_GAMBIT
	.4byte Move_BESTOW
	.4byte Move_INFERNO
	.4byte Move_WATER_PLEDGE
	.4byte Move_FIRE_PLEDGE
	.4byte Move_GRASS_PLEDGE
	.4byte Move_VOLT_SWITCH
	.4byte Move_STRUGGLE_BUG
	.4byte Move_BULLDOZE
	.4byte Move_FROST_BREATH
	.4byte Move_DRAGON_TAIL
	.4byte Move_WORK_UP
	.4byte Move_ELECTROWEB
	.4byte Move_WILD_CHARGE
	.4byte Move_DRILL_RUN
	.4byte Move_DUAL_CHOP
	.4byte Move_HEART_STAMP
	.4byte Move_HORN_LEECH
	.4byte Move_SACRED_SWORD
	.4byte Move_RAZOR_SHELL
	.4byte Move_HEAT_CRASH
	.4byte Move_LEAF_TORNADO
	.4byte Move_STEAMROLLER
	.4byte Move_COTTON_GUARD
	.4byte Move_NIGHT_DAZE
	.4byte Move_PSYSTRIKE
	.4byte Move_TAIL_SLAP
	.4byte Move_HURRICANE
	.4byte Move_HEAD_CHARGE
	.4byte Move_GEAR_GRIND
	.4byte Move_SEARING_SHOT
	.4byte Move_TECHNO_BLAST
	.4byte Move_RELIC_SONG
	.4byte Move_SECRET_SWORD
	.4byte Move_GLACIATE
	.4byte Move_BOLT_STRIKE
	.4byte Move_BLUE_FLARE
	.4byte Move_FIERY_DANCE
	.4byte Move_FREEZE_SHOCK
	.4byte Move_ICE_BURN
	.4byte Move_SNARL
	.4byte Move_ICICLE_CRASH
	.4byte Move_V_CREATE
	.4byte Move_FUSION_FLARE
	.4byte Move_FUSION_BOLT
	.4byte Move_FLYING_PRESS
	.4byte Move_MAT_BLOCK
	.4byte Move_BELCH
	.4byte Move_ROTOTILLER
	.4byte Move_STICKY_WEB
	.4byte Move_FELL_STINGER
	.4byte Move_PHANTOM_FORCE
	.4byte Move_TRICK_OR_TREAT
	.4byte Move_NOBLE_ROAR
	.4byte Move_ION_DELUGE
	.4byte Move_PARABOLIC_CHARGE
	.4byte Move_FORESTS_CURSE
	.4byte Move_PETAL_BLIZZARD
	.4byte Move_FREEZE_DRY
	.4byte Move_DISARMING_VOICE
	.4byte Move_PARTING_SHOT
	.4byte Move_TOPSY_TURVY
	.4byte Move_DRAINING_KISS
	.4byte Move_CRAFTY_SHIELD
	.4byte Move_FLOWER_SHIELD
	.4byte Move_GRASSY_TERRAIN
	.4byte Move_MISTY_TERRAIN
	.4byte Move_ELECTRIFY
	.4byte Move_PLAY_ROUGH
	.4byte Move_FAIRY_WIND
	.4byte Move_MOONBLAST
	.4byte Move_BOOMBURST
	.4byte Move_FAIRY_LOCK
	.4byte Move_KINGS_SHIELD
	.4byte Move_PLAY_NICE
	.4byte Move_CONFIDE
	.4byte Move_DIAMOND_STORM
	.4byte Move_STEAM_ERUPTION
	.4byte Move_HYPERSPACE_HOLE
	.4byte Move_WATER_SHURIKEN
	.4byte Move_MYSTICAL_FIRE
	.4byte Move_SPIKY_SHIELD
	.4byte Move_AROMATIC_MIST
	.4byte Move_EERIE_IMPULSE
	.4byte Move_VENOM_DRENCH
	.4byte Move_POWDER
	.4byte Move_GEOMANCY
	.4byte Move_MAGNETIC_FLUX
	.4byte Move_HAPPY_HOUR
	.4byte Move_ELECTRIC_TERRAIN
	.4byte Move_DAZZLING_GLEAM
	.4byte Move_CELEBRATE
	.4byte Move_HOLD_HANDS
	.4byte Move_BABY_DOLL_EYES
	.4byte Move_NUZZLE
	.4byte Move_HOLD_BACK
	.4byte Move_INFESTATION
	.4byte Move_POWER_UP_PUNCH
	.4byte Move_OBLIVION_WING
	.4byte Move_THOUSAND_ARROWS
	.4byte Move_THOUSAND_WAVES
	.4byte Move_LANDS_WRATH
	.4byte Move_LIGHT_OF_RUIN
	.4byte Move_ORIGIN_PULSE
	.4byte Move_PRECIPICE_BLADES
	.4byte Move_DRAGON_ASCENT
	.4byte Move_HYPERSPACE_FURY
	.4byte Move_COUNT @ cannot be reached, because last move is Psycho Boost

	.align 2
gBattleAnims_StatusConditions::
	.4byte Status_Poison
	.4byte Status_Confusion
	.4byte Status_Burn
	.4byte Status_Infatuation
	.4byte Status_Sleep
	.4byte Status_Paralysis
	.4byte Status_Freeze
	.4byte Status_Curse
	.4byte Status_Nightmare
	.4byte Status_Powder
	
	.align 2
gBattleAnims_General::
	.4byte General_CastformChange
	.4byte General_StatsChange
	.4byte General_SubstituteFade
	.4byte General_SubstituteAppear
	.4byte General_PokeblockThrow
	.4byte General_ItemKnockoff
	.4byte General_TurnTrap
	.4byte General_ItemEffect
	.4byte General_SmokeballEscape
	.4byte General_HangedOn
	.4byte General_Rain
	.4byte General_Sun
	.4byte General_Sandstorm
	.4byte General_Hail
	.4byte General_LeechSeedDrain
	.4byte General_MonHit
	.4byte General_ItemSteal
	.4byte General_SnatchMove
	.4byte General_FutureSightHit
	.4byte General_DoomDesireHit
	.4byte General_FocusPunchSetUp
	.4byte General_IngrainHeal
	.4byte General_WishHeal
	.4byte General_MegaEvolution
	.4byte General_TerrainMisty
	.4byte General_TerrainGrassy
	.4byte General_TerrainElectric
	.4byte General_TerrainPsychic

	.align 2
gBattleAnims_Special::
	.4byte Special_LevelUp
	.4byte Special_SwitchOutPlayerMon
	.4byte Special_SwitchOutOpponentMon
	.4byte Special_BallThrow
	.4byte Special_SafariBallThrow
	.4byte Special_SubstituteToMon
	.4byte Special_MonToSubstitute

Move_ROOST:
	loadspritegfx ANIM_TAG_WHITE_FEATHER
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_ATTACKER
	monbgprio_29
	playsewithpan SE_W080, SOUND_PAN_TARGET
	delay 0
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 64, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 32, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 0, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 224, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 128, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 192, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 160, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_ATTACKER, 0, 0, -16, 96, 2, 104, 11304, 32, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	call HealingEffect
	waitforvisualfinish
	end
	
Move_GRAVITY:
	fadetobg BG_COSMIC
	waitbgfadein
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_ATTACKER, 2, 0, 96, 30
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_DEF_PARTNER, 2, 0, 96, 30
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_ATK_PARTNER, 2, 0, 96, 30
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_TARGET, 2, 0, 96, 30
	waitforvisualfinish
	restorebg
	waitbgfadeout
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 3, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATK_PARTNER, 3, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_DEF_PARTNER, 3, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 1, 1
	setarg 0x7, 0xffff
	waitbgfadein
	waitforvisualfinish
	end
	
Move_MIRACLE_EYE:
	loadspritegfx ANIM_TAG_TEAL_ALERT
	loadspritegfx ANIM_TAG_OPENING_EYE
	loadspritegfx ANIM_TAG_ROUND_WHITE_HALO
	monbg ANIM_DEF_PARTNER
	call SetPsychicBackground
	playsewithpan SE_W109, SOUND_PAN_TARGET
	createsprite gUnknown_085CE07C, ANIM_ATTACKER, 5, 0, 0, 1, 0
	createsprite gUnknown_085CE094, ANIM_ATTACKER, 5
	delay 40
	playsewithpan SE_W043, SOUND_PAN_TARGET
	createvisualtask sub_8115A04, 2, 1, 1, 2, 0, 10, RGB_BLACK
	call MindReaderEffect
	waitforvisualfinish
	call UnsetPsychicBg
	clearmonbg ANIM_DEF_PARTNER
	end	
	
Move_WAKE_UP_SLAP:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_SMELLINGSALT_EFFECT	
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W104, SOUND_PAN_TARGET
	createsprite gUnknown_08595E68, ANIM_ATTACKER, 2, -16, 0, 0, 0, 10, 1, 3, 0
	waitforvisualfinish
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTCKER, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 2
	waitforvisualfinish
	createsprite gSmellingSaltExclamationSpriteTemplate, ANIM_TARGET, 2, 1, 8, 3
	loopsewithpan SE_W207B, +63, 16, 3
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
	
Move_HAMMER_ARM:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ROCKS
	loadspritegfx ANIM_TAG_SLAM_HIT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W004, SOUND_PAN_ATTACKER
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 3, 0, 4
	delay 1
	createsprite gUnknown_085928D0, ANIM_ATTCKER, 2, 0, 0
	delay 3
	setarg 7, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 10, -8, 1, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -12, 32, 3, 4
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 8, 31, 2, 2
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -4, 28, 2, 3
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 12, 30, 4, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_TARGET, 2, 0, 0, 5
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_GYRO_BALL:
	loadspritegfx ANIM_TAG_IMPACT
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 0, 0, 0
	waitforvisualfinish
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W207, SOUND_PAN_ATTACKER, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 2, 4
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	delay 3
	waitforvisualfinish
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, -10, 0, 1, 0
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -32, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 8, -256, 0, 0
	createvisualtask sub_80D6134, 2, 8, -256, 1, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 4, 0, 12, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 8, -256, 0, 1
	createvisualtask sub_80D6134, 2, 8, -256, 1, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7
	waitforvisualfinish
	end
	
Move_HEALING_WISH:
	loadspritegfx ANIM_TAG_GREEN_SPARKLE
	setalpha 0, 16
	createvisualtask sub_80A7A74, 3, 0, 16, 16, 0, 1
	playsewithpan SE_W236, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, -12, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, -24, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, 21, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, 0, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, 10, 0
	delay 20
	createvisualtask sub_81025C0, 2
	waitforvisualfinish
	end
	
Move_BRINE:
	loadspritegfx ANIM_TAG_GLOWY_BLUE_ORB
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W291, -64
	waitforvisualfinish
	delay 16
	createvisualtask sub_81085C8, 5
	playsewithpan SE_W057, +63
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
	
Move_NATURAL_GIFT:
	loadspritegfx ANIM_TAG_SPARKLE_2
	loadspritegfx ANIM_TAG_HOLLOW_ORB
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 16, RGB(27, 31, 18)
	playsewithpan SE_W025, -64
	call GrantingStarsEffect
	waitforvisualfinish
	delay 1
	createvisualtask sub_81133E8, 5
	playsewithpan SE_W100, -64
	delay 8
	createvisualtask sub_80A7CB4, 5, 10249, 19456, 14, 0, 3
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 0
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 43
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 85
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 128
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 170
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 213
	delay 30
	playsewithpan SE_W100, -64
	delay 30
	playsewithpan SE_W100, -64
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	end
	
Move_FEINT:
	end
	
Move_PLUCK:
	end
	
Move_TAILWIND:
	loadspritegfx ANIM_TAG_FLYING_DIRT
	playsewithpan SE_W016, SOUND_PAN_ATTACKER
	call SetHighSpeedBg
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 4, 4
	createvisualtask sub_81169C0, 2, 0, 4, 7, 10
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 10, 2304, 96, 0
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 90, 2048, 96, 0
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 50, 2560, 96, 0
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 20, 2304, 96, 0
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 70, 1984, 96, 0
	delay 12
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 0, 2816, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 60, 2560, 96, 0
	waitforvisualfinish
	stopsound
	call UnsetHighSpeedBg
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end
	
Move_ACUPRESSURE:
	end
	
Move_METAL_BURST:
	loadspritegfx ANIM_TAG_ECLIPSING_ORB
	loadspritegfx ANIM_TAG_RED_ORB
	loopsewithpan SE_W161, -64, 18, 3
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 0
	createvisualtask sub_815B338, 5
	waitforvisualfinish
	setarg 7, -1
	playsewithpan SE_W115, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 32
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 64
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 96
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 128
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 160
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 20, 192
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 224
	waitforvisualfinish
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 1
	waitforvisualfinish
	end
	
Move_U_TURN:
	loadspritegfx ANIM_TAG_ROUND_SHADOW
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W019, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596340, ANIM_ATTACKER, 2, 0, 0, 13, 336
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596358, ANIM_ATTACKER, 2, 20
	delay 20
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_CLOSE_COMBAT:
	loadspritegfx ANIM_TAG_IMPACT	
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	call SetHighSpeedBg
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W004, +63
	delay 10
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W233B, +63
	delay 10
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W025B, +63
	delay 10
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W004, +63
	delay 10
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W233B, +63
	delay 10
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W025B, +63
	delay 10
	call UnsetHighSpeedBg
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	setarg 7, 0x1000
	delay 1
	end
	
Move_PAYBACK:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 30, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 24, 8, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -24, -16, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 8, 4, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -16, 19, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 18, -18, 1, 0
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	restorebg
	waitbgfadein
	end
	
Move_ASSURANCE:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_PURPLE_HAND_OUTLINE
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	setalpha 12, 8
	createsprite gPalmSpriteTemplate, ANIM_TARGET, 3, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, -64
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0
	restorebg
	waitbgfadein
	end
	
Move_EMBARGO:
	loadspritegfx ANIM_TAG_RED_ORB
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W077, +63, 18, 10
	call EmbargoOrbs1
	call EmbargoOrbs1
	call EmbargoOrbs1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 10, 1
	playsewithpan SE_W171, +63
	clearmonbg ANIM_DEF_PARTNER
	end
EmbargoOrbs1:
	createsprite gPowerOrbs_Float, ANIM_ATTACKER, 2, 0, -20, 85, 80, 0
	delay 12
	createsprite gPowerOrbs_Float, ANIM_ATTACKER, 2, 0, -10, 170, 80, 0
	delay 12
	createsprite gPowerOrbs_Float, ANIM_ATTACKER, 2, 0, -15, 0, 80, 0
	delay 12
	return
	
Move_FLING:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_BLACK_BALL
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createsprite gUnknown_085CE050, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
	playsewithpan SE_W207, -64
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233, +63
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
	
Move_PSYCHO_SHIFT:
	loadspritegfx ANIM_TAG_ELECTRIC_ORBS
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_THIN_RING
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W025, -64
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 0
	delay 30
	waitforvisualfinish
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 1, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 1, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 1, 0
	playsewithpan SE_W048, -64
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end
	clearmonbg ANIM_ATTACKER
	blendoff
	end
	
Move_TRUMP_CARD:
	end
	
Move_HEAL_BLOCK:
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_TARGET
	createsoundtask AnimTask_PlaySeChangingVolume, SE_W071B, SOUND_PAN_TARGET, 256, -16, 0, 2
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, 0, -5, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, -15, 10, 1, 0
	delay 7
	createvisualtask sub_8116620, 10, 1 | 4, 4, 2, 12, 0, RGB_BLACK
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, 0, -5, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, -15, 10, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, -15, -15, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, 10, -5, 1, 0
	delay 7
	waitforvisualfinish
	delay 11
	createvisualtask sub_8116620, 10, 1 | 4, 4, 2, 0, 12, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end
	
Move_WRING_OUT:
	end
	
Move_POWER_TRICK:
	loadspritegfx ANIM_TAG_THIN_RING
	monbg ANIM_ATK_PARTNER
	waitforvisualfinish
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	waitforvisualfinish
	createvisualtask sub_81177E4, 5, 0
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end
	
Move_GASTRO_ACID:
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	monbg ANIM_DEF_PARTNER
	createsprite gGreenPoisonBubble, ANIM_TARGET, 2, 20, 0, 40, 1, 0, 0
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	createsprite gGreenPoisonBubble, ANIM_TARGET, 2, 20, 0, 40, 1, 24, 0
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	createsprite gGreenPoisonBubble, ANIM_TARGET, 2, 20, 0, 40, 1, -24, 0
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 15
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 10, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_DEF_PARTNER, 2, 0, 10, 1
	createvisualtask sub_8115A04, 2, 20, 2, 2, 0, 12, RGB(30, 0, 31)
	createsprite gGreenPoisonDrip, ANIM_TARGET, 2, 0, -22, 0, 15, 55
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gGreenPoisonDrip, ANIM_TARGET, 2, -26, -24, 0, 15, 55
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gGreenPoisonDrip, ANIM_TARGET, 2, 15, -27, 0, 15, 50
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gGreenPoisonDrip, ANIM_TARGET, 2, -15, -17, 0, 10, 45
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gGreenPoisonDrip, ANIM_TARGET, 2, 27, -22, 0, 15, 50
	playsewithpan SE_W145, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end
	
Move_LUCKY_CHANT:
	end
	
Move_ME_FIRST:
	end
	
Move_COPYCAT:
	loadspritegfx ANIM_TAG_GRAY_ORB
	loadspritegfx ANIM_TAG_THIN_RING
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	createvisualtask sub_8115A04, 2, 2, 8, 1, 0, 12, RGB_WHITE
	createvisualtask sub_815B65C, 5
	call Stockpile1
	call Stockpile1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 0, 12, 0, RGB_WHITE
	waitforvisualfinish
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	waitforvisualfinish
	end
	
Move_POWER_SWAP:
	end
	
Move_GUARD_SWAP:
	end
	
Move_PUNISHMENT:
	end
	
Move_LAST_RESORT:
	end
	
Move_WORRY_SEED:
	end
	
Move_SUCKER_PUNCH:
	end
	
Move_TOXIC_SPIKES:
	loadspritegfx ANIM_TAG_TOXIC_SPIKES
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W030, SOUND_PAN_TARGET, 28
	createsprite gToxicSpikesSpriteTemplate, ANIM_TARGET, 2, 20, 0, 0, 24, 30
	delay 10
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W030, SOUND_PAN_TARGET, 28
	createsprite gToxicSpikesSpriteTemplate, ANIM_TARGET, 2, 20, 0, -24, 24, 30
	delay 10
	waitplaysewithpan SE_W030, SOUND_PAN_TARGET, 28
	createsprite gToxicSpikesSpriteTemplate, ANIM_TARGET, 2, 20, 0, 24, 24, 30
	delay 40
	call PoisonBubblesEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end
	
Move_HEART_SWAP:
	end
	
Move_AQUA_RING:
	end
	
Move_MAGNET_RISE:
	end
	
Move_FLARE_BLITZ:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_TARGET
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 0
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 2
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 4
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 6
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 8
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 10
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 12
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	waitforvisualfinish
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 4, 1, 4
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 6
	waitforvisualfinish
	call SetImpactBackground
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1	
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 0
	createsprite gUnknown_08595380, 0x81, 0, 10, 192, 176, 40
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 24, 8, 1, 0
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	createsprite gUnknown_08595380, 0x81, 0, 10, -192, 240, 40
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -24, -16, 1, 0
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	createsprite gUnknown_08595380, 0x81, 0, 10, 192, -160, 40
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 8, 4, 1, 0
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	createsprite gUnknown_08595380, 0x81, 0, 10, -192, -112, 40
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -16, 19, 1, 0
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	createsprite gUnknown_08595380, 0x81, 0, 10, 160, 48, 40
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 18, -18, 1, 0
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	createsprite gUnknown_08595380, 0x81, 0, 10, -224, -32, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 112, -128, 40
	playsewithpan SE_W004, +63		
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_BLACK
	playsewithpan SE_W004, +63	
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 9
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end
	
Move_FORCE_PALM:
	end
	
Move_AURA_SPHERE:
	loadspritegfx ANIM_TAG_METEOR
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 12, 8
	call SetHighSpeedBg
	playsewithpan SE_W327, 0
	delay 60
	createsprite gAuraSphereBlast, ANIM_TARGET, 3, 0
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	delay 16
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	call UnsetHighSpeedBg
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end
	
Move_ROCK_POLISH:
	loadspritegfx ANIM_TAG_WHITE_STREAK
	loadspritegfx ANIM_TAG_SPARKLE_3
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 3, 0, 12, RGB_BLACK
	waitforvisualfinish
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -10, 3
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 24, -19
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -28, -15
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -6, -30
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -20, 6
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 28, 2
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -14, -25
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 9, -2
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -1, 0
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 21, 4
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 28, 20
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -7, 24
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -11, 1
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 12, -18
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -21, -14
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -29, 7
	delay 2
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, 15, 28
	delay 1
	createsprite gRockPolishStreakSpriteTemplate, ANIM_ATTACKER, 2, -21, -16
	delay 2
	waitforvisualfinish
	playsewithpan SE_W213, SOUND_PAN_ATTACKER
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, -20, 9
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, -10, -15
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, 1, 17
	delay 1
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, -23, -16
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, 10, -6
	delay 1
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, -16, -7
	delay 1
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, 22, -7
	delay 1
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, -19, 11
	delay 1
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, 12, 12
	delay 1
	createsprite gRockPolishSparkleSpriteTemplate, ANIM_ATTACKER, 2, 0, -17
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 3, 12, 0, RGB_BLACK
	waitforvisualfinish
	blendoff
	end
	
Move_POISON_JAB:
	loadspritegfx ANIM_TAG_PURPLE_JAB
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	setalpha 12, 8
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, 3, -31, 10
	delay 2
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, -18, -25, 10
	delay 2
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, 27, 17, 10
	delay 2
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, -26, 18, 10
	delay 2
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, 10, 30, 10
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -7, 4, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, -17, -27, 10
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -4, -6, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, 2, 31, 10
	createvisualtask AnimTask_SwayMon, 5, 0, 3, 0x2000, 6, ANIM_TARGET
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB(16, 0, 16), 12, 0, 1
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 6, 4, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, 15, -27, 10
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -6, 8, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, -31, -2, 10
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 12, 6, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gPoisonJabProjectileSpriteTemplate, ANIM_TARGET, 2, -26, -18, 10
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -6, -8, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 8, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -8, 0, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -7, -5, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	blendoff
	end
	
Move_DARK_PULSE:
	end
	
Move_NIGHT_SLASH:
	loadspritegfx ANIM_TAG_SLASH
	createvisualtask AnimTask_BlendNightSlash, 2, ANIM_TARGET, 2, 0, 8, 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 3, 0, 12, RGB_BLACK
	waitforvisualfinish
	createsprite gNightSlashLeftSpriteTemplate, ANIM_TARGET, 2, 1, -8, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	delay 4
	createsprite gNightSlashLeftSpriteTemplate, ANIM_TARGET, 2, 1, 8, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	delay 40
	createsprite gNightSlashRightSpriteTemplate, ANIM_TARGET, 2, 1, -8, 0
	createsprite gNightSlashRightSpriteTemplate, ANIM_TARGET, 2, 1, 8, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 3, 12, 0, RGB_BLACK
	waitforvisualfinish
	end
	
Move_AQUA_TAIL:
	end
	
Move_SEED_BOMB:
	loadspritegfx ANIM_TAG_SEED
	loadspritegfx ANIM_TAG_EXPLOSION
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 30, 1
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 6, 5, 1, 0
	delay 6
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, -16, -15, 1, 0
	delay 6
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 16, -5, 1, 0
	delay 6
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, -12, 18, 1, 0
	delay 6
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 0, 5, 1, 0
	delay 6
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 6, 5, 1, 0
	delay 6
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, -16, -15, 1, 0
	delay 6
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 16, -5, 1, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, -12, 18, 1, 0
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 0, 5, 1, 0
	waitforvisualfinish
	end
	
Move_AIR_SLASH:
	loadspritegfx ANIM_TAG_SLASH
	call SetSkyBg
	createsprite gUnknown_08592D2C, ANIM_TARGET, 2, 1, -8, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08592D2C, ANIM_TARGET, 2, 1, 8, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	call UnsetSkyBg
	end
	
Move_XSCISSOR:
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask sub_81169C0, 2, 0, 4, 7, 3
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 1
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 10, 0, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_BUG_BUZZ:
	loadspritegfx ANIM_TAG_JAGGED_MUSIC_NOTE
	loadspritegfx ANIM_TAG_THIN_RING
	monbg ANIM_DEF_PARTNER
	call SetBugBg
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, 29, -12, 0
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, -12, -29, 1
	delay 16
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, 12, -29, 1
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, -29, -12, 0
	delay 16
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, 24, -24, 1
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, -24, -24, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	call UnsetBugBg
	end
	
Move_DRAGON_PULSE:
	end
	
Move_DRAGON_RUSH:
	end
	
Move_POWER_GEM:
	end
	
Move_DRAIN_PUNCH:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_BLUE_STAR
	loadspritegfx ANIM_TAG_ORBS
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233B, -64
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, 0, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 15, 1
	delay 20
	call MegaDrainEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
	
Move_VACUUM_WAVE:
	end
	
Move_FOCUS_BLAST:
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_METEOR
	loadspritegfx ANIM_TAG_FLAT_ROCK
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	call SetHighSpeedBg
	createsprite gUnknown_08595FEC, ANIM_TARGET, 2, 0
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	call UnsetHighSpeedBg
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	end
	
Move_ENERGY_BALL:
	loadspritegfx ANIM_TAG_ENERGY_BALL
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 8, RGB_BLACK
	waitforvisualfinish
	delay 15
	createsoundtask sub_8158C58, SE_W054, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 5, 5, 0, 5
	createsprite gEnergyBallSpriteTemplate, ANIM_TARGET, 2, 12, 4, 8
	waitforvisualfinish
	playsewithpan SE_W028, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 8, 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 8, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_BRAVE_BIRD:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_BIRD
	call SetSkyBg
	monbg ANIM_ATTACKER
	createvisualtask sub_8116620, 10, 2, 0, 0, 16, RGB_WHITE
	delay 4
	createvisualtask sub_81136E8, 5, 0
	waitforvisualfinish
	createvisualtask sub_8159244, 5, 238, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596514, ANIM_TARGET, 2
	delay 14
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 10, 0, 18, 1
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	delay 20
	createvisualtask sub_81137E4, 5, 1
	delay 2
	createvisualtask sub_8116620, 10, 2, 0, 15, 0, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	call UnsetSkyBg
	end
	
Move_EARTH_POWER:
	end
	
Move_SWITCHEROO:
	end
	
Move_GIGA_IMPACT:
	end
	
Move_NASTY_PLOT:
	end
	
Move_BULLET_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -8, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -8, 0, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -16, 8, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -16, 8, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 8, -16, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -16, 8, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 16, 16, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 16, 8, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 24, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 24, 0, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 24, 16, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 24, 16, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -24, 16, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -24, 16, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -24, -8, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -24, -8, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -24, 8, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -24, 8, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 9, 0, 8, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish

	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_AVALANCHE:
	end
	
Move_ICE_SHARD:
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	fadetobg BG_ICE
	waitbgfadein
	createsoundtask sub_8158C58, SE_W062B, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 4, 4, 0, 10
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, -20, 70,  0, 42, 35
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, -20, 58,  0, 30, 35
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, -20, -12, 0, 22, 40
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, -20, 0,   0, 10, 40
	delay 5
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, -10, -30, 10, -12, 45
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, -10, -42, 10, -24, 45
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, -10, -20, 10, -36, 45
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, -10, -32, 10, -24, 45
	delay 5
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, 0, 10, 20, 22, 45
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, 0, -2, 20, 10, 45
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, 0, 20, 20, -2, 30
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, 0,  8, 20, 10, 30
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 4, -31, 0, 7, RGB(0, 20, 31)
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 25, 1
	waitforvisualfinish
	delay 20
	call FreezeEffect1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 4, 5, 7, 0, RGB(0, 20, 31)
	waitforvisualfinish
	restorebg
	waitbgfadein	
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_SHADOW_CLAW:
	end
	
Move_THUNDER_FANG:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_LIGHTNING
	loadspritegfx ANIM_TAG_SHARP_TEETH
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 16, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, -48
	delay 1
	createsprite gUnknown_085956C0, ANIM_ATTACKER, 2, 0, -16
	delay 1
	createsprite gUnknown_085956C0, ANIM_ATTACKER, 2, 0, 16
	delay 1
	playsewithpan SE_W044, SOUND_PAN_TARGET
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, -32, 0, 0, 819, 10
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, 32, 4, 0, -819, 10
	delay 1
	playsewithpan SE_W161B, SOUND_PAN_TARGET
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 15, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 16, 0, RGB_BLACK
	delay 20
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	end
	
Move_ICE_FANG:
	monbg ANIM_TARGET
	setalpha 12, 8
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	loadspritegfx ANIM_TAG_SHARP_TEETH
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 7, RGB_BLACK
	createvisualtask sub_8116620, 10, 4, 2, 0, 9, RGB(12, 26, 31)
	delay 20
	playsewithpan SE_W081, SOUND_PAN_TARGET
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 0
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 64
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 128
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 192
	delay 5
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 32
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 96
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 160
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 224
	playsewithpan SE_W044, SOUND_PAN_TARGET
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, -32, 0, 0, 819, 10
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, 32, 4, 0, -819, 10
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 4, 7, 1
	delay 15
	call FreezeEffect1
	delay 5
	createvisualtask sub_8116620, 10, 4, 2, 9, 0, RGB(12, 26, 31)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	end
	
Move_FIRE_FANG:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loadspritegfx ANIM_TAG_SHARP_TEETH
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_8116620, 10, 4, 2, 0, 9, RGB_RED
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 0
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 64
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 128
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 196
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, -32, 0, 0, 819, 10
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, 32, 4, 0, -819, 10
	playsewithpan SE_W044, SOUND_PAN_TARGET
	delay 10
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 4, 7, 1
	call FireMoveEffect
	delay 4
	playsewithpan SE_W007, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 9, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	end
	
Move_SHADOW_SNEAK:
    loadspritegfx ANIM_TAG_LICK
    setalpha 0, 16
    delay 1
    createvisualtask sub_81143C0, 2
    delay 1
    createvisualtask sub_8113BAC, 5
    playsewithpan SE_W060, SOUND_PAN_ATTACKER
    delay 48
    playsewithpan SE_W060B, SOUND_PAN_ATTACKER
    waitforvisualfinish
    createvisualtask sub_8114470, 2
    setalpha 0, 16
    delay 1
    playsewithpan SE_W122, SOUND_PAN_TARGET
    createsprite gUnknown_08596D8C, ANIM_TARGET, 2, 0, 0
    createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 16, 1
    waitforvisualfinish
    clearmonbg_23 ANIM_TARGET
    delay 1
    blendoff
    delay 1
    end

Move_MUD_BOMB:
    loadspritegfx ANIM_TAG_MUD_SAND
    playsewithpan SE_W145C, SOUND_PAN_ATTACKER
    createsprite gMudBombToss, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
    delay 5
    playsewithpan SE_W145C, SOUND_PAN_ATTACKER
    createsprite gMudBombToss, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
    delay 5
    playsewithpan SE_W145C, SOUND_PAN_ATTACKER
    createsprite gMudBombToss, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
    delay 5
    playsewithpan SE_W145C, SOUND_PAN_ATTACKER
    createsprite gMudBombToss, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
    delay 11
    createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
    createsprite gMudBombSplash, ANIM_TARGET, 2, 42, 27, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, 42, 27, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -27, 44, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, 39, -28, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -42, -42, 20
    playsewithpan SE_W233B, SOUND_PAN_TARGET
    delay 5
    createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
    createsprite gMudBombSplash, ANIM_TARGET, 2, 0, 40, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -8, -44, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -46, -28, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, 46, 9, 20
    playsewithpan SE_W088, SOUND_PAN_TARGET
    delay 5
    createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
    createsprite gMudBombSplash, ANIM_TARGET, 2, 42, 0, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -43, -12, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, 16, -46, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -16, 44, 20
    playsewithpan SE_W088, SOUND_PAN_TARGET
    delay 5
    createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
    createsprite gMudBombSplash, ANIM_TARGET, 2, 0, 40, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -8, -44, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -46, -28, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, 46, 9, 20
    playsewithpan SE_W088, SOUND_PAN_TARGET
    delay 5
    createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
    createsprite gMudBombSplash, ANIM_TARGET, 2, 42, 0, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -43, -12, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, 16, -46, 20
    createsprite gMudBombSplash, ANIM_TARGET, 2, -16, 44, 20
    waitforvisualfinish
    end

Move_PSYCHO_CUT:
	end
	
Move_ZEN_HEADBUTT:
	end
	
Move_MIRROR_SHOT:
	end
	
Move_FLASH_CANNON:
	end
	
Move_ROCK_CLIMB:
	end
	
Move_DEFOG:
	end
	
Move_TRICK_ROOM:
	end
	
Move_DRACO_METEOR:
	end
	
Move_DISCHARGE:
	end
	
Move_LAVA_PLUME:
	end
	
Move_LEAF_STORM:
	loadspritegfx ANIM_TAG_RAZOR_LEAF
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_LEAF
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 12, RGB(13, 31, 12)
	waitforvisualfinish
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -16, 19, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 12, 19, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -20, 23, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 16, 23, 0, 0
	delay 3
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 50, 1
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -24, 27, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 20, 27, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -24, 27, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 20, 27, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -20, 23, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 16, 23, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -16, 19, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 12, 19, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -8, 11, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -16, 19, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 12, 19, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -20, 23, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 16, 23, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -24, 27, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 20, 27, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -24, 27, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 20, 27, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -20, 23, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 16, 23, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -16, 19, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 12, 19, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -16, 19, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 12, 19, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -20, 23, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 16, 23, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 14, -12, 0, -24, 27, 0, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm, ANIM_ATTACKER, 2, 26, 8, 12, 20, 27, 0, 0
	delay 3
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 0
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 0, -36, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 24, -12, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 24, 12, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 0, 36, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, -24, 12, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, -24, -12, 10
	playsewithpan SE_W013, SOUND_PAN_TARGET
	delay 2
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 36, 0, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 12, -24, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, 12, 24, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, -36, 0, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, -12, 24, 10
	createsprite gBattleAnimSpriteTemplate_LeafStorm2, ANIM_TARGET, 2, 1, 1, -12, -24, 10
	waitforvisualfinish
	blendoff
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 12, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end
	
Move_POWER_WHIP:
	loadspritegfx ANIM_TAG_WHIP_HIT
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 10
	delay 6
	playsewithpan SE_W010, SOUND_PAN_TARGET
	createsprite gVineWhipSpriteTemplate, ANIM_TARGET, 2, 0, 0
	delay 6
	call SetImpactBackground
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	restorebg
	waitbgfadein
	end
	
Move_ROCK_WRECKER:
	end
	
Move_CROSS_POISON:
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	loadspritegfx ANIM_TAG_CROSS_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_WHITE, 10, 0, 10
	createsprite gUnknown_085973D0, ANIM_ATTACKER, 3, 0, 0, 1, 20
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 7, 0, 9, 1
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_GUNK_SHOT:
	end
	
Move_IRON_HEAD:
	loadspritegfx ANIM_TAG_GUST
	loadspritegfx ANIM_TAG_IMPACT
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 1, 0, 0
	waitforvisualfinish
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 0
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 7, 1
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 2
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 0, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 1
	waitforvisualfinish
	end
	
Move_MAGNET_BOMB:
	end
	
Move_STONE_EDGE:
	end
	
Move_CAPTIVATE:
	end
	
Move_STEALTH_ROCK:
	end
	
Move_GRASS_KNOT:
	end
	
Move_CHATTER:
	end
	
Move_JUDGMENT:
	end
	
Move_BUG_BITE:
	end
	
Move_CHARGE_BEAM:
	end
	
Move_WOOD_HAMMER:
	end
	
Move_AQUA_JET:
	end
	
Move_ATTACK_ORDER:
	end
	
Move_DEFEND_ORDER:
	end
	
Move_HEAL_ORDER:
	end
	
Move_HEAD_SMASH:
	end
	
Move_DOUBLE_HIT:
	end
	
Move_ROAR_OF_TIME:
	end
	
Move_SPECIAL_REND:
	end
	
Move_LUNAR_DANCE:
	end
	
Move_CRUSH_GRIP:
	end
	
Move_MAGMA_STORM:
	end
	
Move_DARK_VOID:
	end
	
Move_SEED_FLARE:
	end
	
Move_OMINOUS_WIND:
	end
	
Move_SHADOW_FORCE:
	end
	
Move_HONE_CLAWS:
	end
	
Move_WIDE_GUARD:
	end
	
Move_GUARD_SPLIT:
	end
	
Move_POWER_SPLIT:
	end
	
Move_WONDER_ROOM:
	end
	
Move_PSYSHOCK:
	end
	
Move_VENOSHOCK:
	end
	
Move_AUTOTOMIZE:
	end
	
Move_RAGE_POWDER:
	end
	
Move_TELEKINESIS:
	end
	
Move_MAGIC_ROOM:
	end
	
Move_SMACK_DOWN:
	end
	
Move_STORM_THROW:
	end
	
Move_FLAME_BURST:
	end
	
Move_SLUDGE_WAVE:
	end
	
Move_QUIVER_DANCE:
	end
	
Move_HEAVY_SLAM:
	end
	
Move_SYCHRONOISE:
	end
	
Move_ELECTRO_BALL:
	end
	
Move_SOAK:
	end
	
Move_FLAME_CHARGE:
	end
	
Move_COIL:
	end
	
Move_LOW_SWEEP:
	end
	
Move_ACID_SPRAY:
	end
	
Move_FOUL_PLAY:
	end
	
Move_SIMPLE_BEAM:
	end
	
Move_ENTRAINMENT:
	end
	
Move_AFTER_YOU:
	end
	
Move_ROUND:
	end
	
Move_ECHOED_VOICE:
	end
	
Move_CHIP_AWAY:
	end
	
Move_CLEAR_SMOG:
	end
	
Move_STORED_POWER:
	end
	
Move_QUICK_GUARD:
	end
	
Move_ALLY_SWITCH:
	end
	
Move_SCALD:
	end
	
Move_SHELL_SMASH:
	end
	
Move_HEAL_PULSE:
	end
	
Move_HEX:
	end
	
Move_SKY_DROP:
	end
	
Move_SHIFT_GEAR:
	end
	
Move_CIRCLE_THROW:
	end
	
Move_INCINERATE:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 1	
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_SwayMon, 5, 0, 3, 0xc00, 8, ANIM_TARGET	
	createvisualtask AnimTask_SwayMon, 5, 0, 3, 0xc00, 8, ANIM_DEF_PARTNER	
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 3
	createsprite gIncinerateSpriteTemplate, ANIM_TARGET, 2, 6, 20, 0, -16, 24, 20
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 8, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_DEF_PARTNER, 5, 0, 8, 1
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_RED, 12, 1, 1
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_DEF_PARTNER, RGB_RED, 12, 1, 1
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate,  ANIM_ATTACKER, 2, 3, 0, 0, 9
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_QUASH:
	end
	
Move_ACROBATICS:
	end
	
Move_REFLECT_TYPE:
	end
	
Move_RETALITATE:
	end
	
Move_FINAL_GAMBIT:
	end
	
Move_BESTOW:
	end
	
Move_INFERNO:
	end
	
Move_WATER_PLEDGE:
	end
	
Move_FIRE_PLEDGE:
	end
	
Move_GRASS_PLEDGE:
	end
	
Move_VOLT_SWITCH:
	end
	
Move_STRUGGLE_BUG:
	end
	
Move_BULLDOZE:
	end
	
Move_FROST_BREATH:
	end
	
Move_DRAGON_TAIL:
	end
	
Move_WORK_UP:
	end
	
Move_ELECTROWEB:
	loadspritegfx ANIM_TAG_SPIDER_WEB
	loadspritegfx ANIM_TAG_WEB_THREAD
	loadspritegfx ANIM_TAG_SPARK_2
	monbg ANIM_DEF_PARTNER
	delay 0
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_SPIDER_WEB, 0, 6, 6, RGB(31, 30, 1)
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	monbgprio_28 ANIM_TARGET
	waitforvisualfinish
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gSpiderWebSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, TRUE
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 9, 0, RGB_BLACK
	
	@ ElectricityEffect looks ugly against both opponents, to do later
	jumpifdoublebattle Move_ELECTROWEB_Wait
	
	call ElectricityEffect
Move_ELECTROWEB_Wait:
	waitforvisualfinish
	end
	
Move_WILD_CHARGE:
	end
	
Move_DRILL_RUN:
	end
	
Move_DUAL_CHOP:
	end
	
Move_HEART_STAMP:
	end
	
Move_HORN_LEECH:
	end
	
Move_SACRED_SWORD:
	end
	
Move_RAZOR_SHELL:
	end
	
Move_HEAT_CRASH:
	end
	
Move_LEAF_TORNADO:
	end
	
Move_STEAMROLLER:
	end
	
Move_COTTON_GUARD:
	end
	
Move_NIGHT_DAZE:
	end
	
Move_PSYSTRIKE:
	end
	
Move_TAIL_SLAP:
	end
	
Move_HURRICANE:
	end
	
Move_HEAD_CHARGE:
	end
	
Move_GEAR_GRIND:
	end
	
Move_SEARING_SHOT:
	end
	
Move_TECHNO_BLAST:
	end
	
Move_RELIC_SONG:
	end
	
Move_SECRET_SWORD:
	end
	
Move_GLACIATE:
	end
	
Move_BOLT_STRIKE:
	end
	
Move_BLUE_FLARE:
	end
	
Move_FIERY_DANCE:
	end
	
Move_FREEZE_SHOCK:
	end
	
Move_ICE_BURN:
	end
	
Move_SNARL:
	end
	
Move_ICICLE_CRASH:
	end
	
Move_V_CREATE:
	end
	
Move_FUSION_FLARE:
	end
	
Move_FUSION_BOLT:
	end
	
Move_FLYING_PRESS:
	end
	
Move_MAT_BLOCK:
	end
	
Move_BELCH:
	end
	
Move_ROTOTILLER:
	end
	
Move_STICKY_WEB:
	loadspritegfx ANIM_TAG_SPIDER_WEB
	loadspritegfx ANIM_TAG_WEB_THREAD
	monbg ANIM_DEF_PARTNER
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W081, SOUND_PAN_ATTACKER, 9, 6
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	waitforvisualfinish
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gSpiderWebSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, TRUE
	delay 50
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gSpiderWebSpriteTemplate, ANIM_ATTACKER, 2, -30, 30, TRUE
	delay 50
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gSpiderWebSpriteTemplate, ANIM_ATTACKER, 2, 30, -30, TRUE
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 9, 0, RGB_BLACK
	end
	
Move_FELL_STINGER:
	end
	
Move_PHANTOM_FORCE:
	choosetwoturnanim PhantomForceSetUp, PhantomForceUnleash
PhantomForceEnd:
	end
PhantomForceSetUp:
	invisible ANIM_ATTACKER
	goto PhantomForceEnd
PhantomForceUnleash:
	visible ANIM_ATTACKER
	goto PhantomForceEnd
	
Move_TRICK_OR_TREAT:
	end
	
Move_NOBLE_ROAR:
	end
	
Move_ION_DELUGE:
	end
	
Move_PARABOLIC_CHARGE:
	loadspritegfx ANIM_TAG_ELECTRIC_ORBS
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_LIGHTNING
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 6, RGB(18, 16, 3)
	waitforvisualfinish
	createvisualtask sub_810AAFC, 2, ANIM_ATTACKER, 3, 20, 20
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	delay 12
	createsprite gUnknown_08595A18, ANIM_ATTACKER, 2
	delay 30
	jumpifdoublebattle ParabolicChargeDouble
	createvisualtask sub_810B29C, 5, ANIM_TARGET
	delay 12
	waitforvisualfinish
	createvisualtask sub_810B55C, 5, ANIM_TARGET
	playsewithpan SE_W070, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 6, 18, 1
	createvisualtask sub_8116620, 5, 4, 0, 16, 16, RGB_BLACK
	delay 4
	createvisualtask sub_8116620, 5, 4, 0, 0, 0, RGB_BLACK
ParabolicChargeHeal:
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	waitforvisualfinish
	call HealingEffect
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 6, 0, RGB(18, 16, 3)
	waitforvisualfinish
	blendoff
	end
ParabolicChargeDouble:
	createvisualtask sub_810B29C, 5, ANIM_TARGET
	createvisualtask sub_810B29C, 5, ANIM_DEF_PARTNER
	createvisualtask sub_810B29C, 5, ANIM_ATK_PARTNER
	delay 12
	waitforvisualfinish
	createvisualtask sub_810B55C, 5, ANIM_TARGET
	createvisualtask sub_810B55C, 5, ANIM_DEF_PARTNER
	createvisualtask sub_810B55C, 5, ANIM_ATK_PARTNER
	playsewithpan SE_W070, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 6, 18, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_DEF_PARTNER, 0, 6, 18, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATK_PARTNER, 0, 6, 18, 1
	createvisualtask sub_8116620, 5, 4 | 8 | 0x10, 0, 16, 16, RGB_BLACK
	delay 4
	createvisualtask sub_8116620, 5, 4 | 8 | 0x10, 0, 0, 0, RGB_BLACK
	goto ParabolicChargeHeal;
	
Move_FORESTS_CURSE:
	end
	
Move_PETAL_BLIZZARD:
	end
	
Move_FREEZE_DRY:
	end
	
Move_DISARMING_VOICE:
	end
	
Move_PARTING_SHOT:
	loadspritegfx ANIM_TAG_NOISE_LINE
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	createvisualtask sub_8158E9C, 2, 0, 255
	call RoarEffect
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 9, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 9, 1
	waitforvisualfinish
	createvisualtask sub_8159078, 5
	waitforvisualfinish
	delay 1
	restorebg
	waitbgfadein
	end
	
Move_TOPSY_TURVY:
	end
	
Move_DRAINING_KISS:
	end
	
Move_CRAFTY_SHIELD:
	end
	
Move_FLOWER_SHIELD:
	end
	
Move_GRASSY_TERRAIN:
	end
	
Move_MISTY_TERRAIN:
	end
	
Move_ELECTRIFY:
	end
	
Move_PLAY_ROUGH:
	end
	
Move_FAIRY_WIND:
	end
	
Move_MOONBLAST:
	end
	
Move_BOOMBURST:
	end
	
Move_FAIRY_LOCK:
	end
	
Move_KINGS_SHIELD:
	end
	
Move_PLAY_NICE:
	end
	
Move_CONFIDE:
	end
	
Move_DIAMOND_STORM:
	end
	
Move_STEAM_ERUPTION:
	end
	
Move_HYPERSPACE_HOLE:
	end
	
Move_WATER_SHURIKEN:
	end
	
Move_MYSTICAL_FIRE:
	end
	
Move_SPIKY_SHIELD:
	end
	
Move_AROMATIC_MIST:
	end
	
Move_EERIE_IMPULSE:
	end
	
Move_VENOM_DRENCH:
	end
	
Move_POWDER:
	end
	
Move_GEOMANCY:
	end
	
Move_HAPPY_HOUR:
	end
	
Move_ELECTRIC_TERRAIN:
	end
	
Move_DAZZLING_GLEAM:
	end
	
Move_CELEBRATE:
	end
	
Move_HOLD_HANDS:
	end
	
Move_BABY_DOLL_EYES:
	end
	
Move_NUZZLE:
	end
	
Move_HOLD_BACK:
	end
	
Move_INFESTATION:
	end
	
Move_POWER_UP_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_BREATH
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_GrowAndShrink, 2,
	playsewithpan SE_W118, SOUND_PAN_ATTACKER
	waitforvisualfinish
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
	
Move_OBLIVION_WING:
	end
	
Move_THOUSAND_ARROWS:
	end
	
Move_THOUSAND_WAVES:
	end
	
Move_LANDS_WRATH:
	end
	
Move_LIGHT_OF_RUIN:
	end
	
Move_ORIGIN_PULSE:
	end
	
Move_PRECIPICE_BLADES:
	end
	
Move_DRAGON_ASCENT:
	end
	
Move_HYPERSPACE_FURY:
	end

Move_NONE:
Move_MIRROR_MOVE:
Move_POUND:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DOUBLE_SLAP:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim DoubleSlapLeft, DoubleSlapRight
DoubleSlapContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W003, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
DoubleSlapLeft:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -8, 0, 1, 2
	goto DoubleSlapContinue
DoubleSlapRight:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 8, 0, 1, 2
	goto DoubleSlapContinue

Move_POISON_POWDER:
	loadspritegfx ANIM_TAG_POISON_POWDER
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	loopsewithpan SE_W077, SOUND_PAN_TARGET, 10, 6
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -30, -22, 117, 80, 5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 10, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -25, -22, 117, 112, 5, 3
	delay 15
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -5, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 5, -22, 117, 96, 5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 0, -22, 117, 69, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -15, -22, 117, 112, 5, 2
	delay 30
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -15, -22, 117, 112, 5, 2
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 15, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -10, -22, 117, 96, 7, 2
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -5, -22, 117, 90, -8, 0
	delay 20
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, -10, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 0, -22, 117, 89, 5, 2
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 20, -22, 117, 112, -8, 2
	createsprite gPoisonPowderParticleSpriteTemplate, ANIM_TARGET, 2, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_STUN_SPORE:
	loadspritegfx ANIM_TAG_STUN_SPORE
	loopsewithpan SE_W077, SOUND_PAN_TARGET, 10, 6
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -30, -22, 117, 80, 5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 10, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -25, -22, 117, 112, 5, 3
	delay 15
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -5, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 5, -22, 117, 96, 5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 0, -22, 117, 69, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -15, -22, 117, 112, 5, 2
	delay 30
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -15, -22, 117, 112, 5, 2
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 15, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -10, -22, 117, 96, 7, 2
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -5, -22, 117, 90, -8, 0
	delay 20
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, -10, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 0, -22, 117, 89, 5, 2
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 20, -22, 117, 112, -8, 2
	createsprite gStunSporeParticleSpriteTemplate, ANIM_TARGET, 2, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_SLEEP_POWDER:
	loadspritegfx ANIM_TAG_SLEEP_POWDER
	loopsewithpan SE_W077, SOUND_PAN_TARGET, 10, 6
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -30, -22, 117, 80, 5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 10, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -25, -22, 117, 112, 5, 3
	delay 15
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -5, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 5, -22, 117, 96, 5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 0, -22, 117, 69, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -15, -22, 117, 112, 5, 2
	delay 30
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -15, -22, 117, 112, 5, 2
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 15, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -10, -22, 117, 96, 7, 2
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -5, -22, 117, 90, -8, 0
	delay 20
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, -10, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 0, -22, 117, 89, 5, 2
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 20, -22, 117, 112, -8, 2
	createsprite gSleepPowderParticleSpriteTemplate, ANIM_TARGET, 2, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_SWIFT:
	loadspritegfx ANIM_TAG_YELLOW_STAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gSwiftStarSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 22, 20, 1
	delay 5
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gSwiftStarSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 5, 22, -18, 1
	delay 5
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gSwiftStarSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, -10, 22, 15, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 18, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 18, 1
	delay 5
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gSwiftStarSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 22, -20, 1
	delay 5
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gSwiftStarSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 22, 12, 1
	delay 5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRENGTH:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_ATTACKER, 2, 0, 96, 30
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 4
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_TARGET, 18, 6, 2, 4
	delay 4
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 16, 12, 1, 1
	delay 4
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -16, -12, 1, 1
	delay 4
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 3, 4, 1, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TACKLE:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_BODY_SLAM:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	waitforvisualfinish
	delay 11
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 26, 0, 0, 5
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 4, -10, 0, 1, 0
	loopsewithpan SE_W025B, SOUND_PAN_TARGET, 10, 2
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -28, 0, 0, 3
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 6
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUPERSONIC:
	loadspritegfx ANIM_TAG_GOLD_RING
	monbg ANIM_ATK_PARTNER
	monbgprio_2A ANIM_ATTACKER
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 8, 1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end
Supersonic1:
	playsewithpan SE_W048, SOUND_PAN_ATTACKER
	createsprite gSupersonicWaveSpriteTemplate, ANIM_TARGET, 2, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_SCREECH:
	loadspritegfx ANIM_TAG_PURPLE_RING
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 3, 0, 2, 1
	call Screech1
	call Screech1
	delay 16
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 2048, 2, ANIM_TARGET
	waitforvisualfinish
	end
Screech1:
	playsewithpan SE_W103, SOUND_PAN_ATTACKER
	createsprite gScreechWaveSpriteTemplate, ANIM_TARGET, 2, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_FLAME_WHEEL:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 0
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 4
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 8
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 12
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 16
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 20
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 56, 24
	playsewithpan SE_W172, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 6
	delay 4
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 8, 1
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	playsewithpan SE_W172B, SOUND_PAN_TARGET
	call FireMoveEffect
	delay 7
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 9
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

FlameWheel1: @ Unused
	createsprite gBattleAnimSpriteTemplate_8595584, ANIM_ATTACKER, 3, 0, 0, 50
	delay 4
	return

Move_PIN_MISSILE:
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gPinMissileSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, -8, -8, 20, -32
	delay 15
	createsprite gPinMissileSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, 8, 8, 20, -40
	delay 4
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -8, -8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 9
	createsprite gPinMissileSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, 0, 0, 20, -32
	delay 4
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 8, 8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 14
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_ICICLE_SPEAR:
	loadspritegfx ANIM_TAG_ICICLE_SPEAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W196, SOUND_PAN_ATTACKER
	createsprite gIcicleSpearSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, -8, -8, 20, -32
	delay 15
	createsprite gIcicleSpearSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, 8, 8, 20, -40
	delay 4
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -8, -8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 9
	createsprite gIcicleSpearSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, 0, 0, 20, -32
	delay 4
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 8, 8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 14
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAKE_DOWN:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -24, 8, 23, 10, 40, 10
	delay 35
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 10, 0, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 4, -10, 0, 1, 0
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -16, 0, 0, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	delay 2
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_EDGE:
	loadspritegfx ANIM_TAG_IMPACT
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 4, 2, RGB_WHITE, 10, 0, 0
	waitforvisualfinish
	delay 10
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W207, SOUND_PAN_ATTACKER, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 2, 4
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 16, 16, RGB_WHITE
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	delay 3
	waitforvisualfinish
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, -10, 0, 1, 0
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -32, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 8, -256, 0, 0
	createvisualtask sub_80D6134, 2, 8, -256, 1, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 4, 0, 12, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 16, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 8, -256, 0, 1
	createvisualtask sub_80D6134, 2, 8, -256, 1, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7
	waitforvisualfinish
	end

Move_POISON_STING:
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gLinearStingerSpriteTemplate, ANIM_TARGET, 2, 20, 0, -8, 0, 20
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 5, 1
	playsewithpan SE_W030, SOUND_PAN_TARGET
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TWINEEDLE:
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_W013B, SOUND_PAN_ATTACKER, 6, 2
	createsprite gLinearStingerSpriteTemplate, ANIM_TARGET, 2, 10, -4, 0, -4, 20
	createsprite gLinearStingerSpriteTemplate, ANIM_TARGET, 2, 20, 12, 10, 12, 20
	delay 20
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 5, 1
	createsprite gBattleAnimSpriteTemplate_8597370, ANIM_ATTACKER, 3, 0, -4, 1, 3
	loopsewithpan SE_W030, SOUND_PAN_TARGET, 5, 2
	delay 1
	createsprite gBattleAnimSpriteTemplate_8597370, ANIM_ATTACKER, 3, 10, 12, 1, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_FIRE_BLAST:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	createsoundtask sub_8158B30, 144, 145
	call FireBlast1
	call FireBlast1
	call FireBlast1
	delay 24
	createvisualtask sub_8116620, 10, 1, 3, 0, 8, RGB_BLACK
	waitforvisualfinish
	delay 19
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 20, 1
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 2, 8, 0, RGB_BLACK
	waitforvisualfinish
	end
FireBlast1:
	createsprite gUnknown_0859551C, ANIM_TARGET, 2, 0, 0, 0
	createsprite gUnknown_0859551C, ANIM_TARGET, 2, 0, 0, 51
	createsprite gUnknown_0859551C, ANIM_TARGET, 2, 0, 0, 102
	createsprite gUnknown_0859551C, ANIM_TARGET, 2, 0, 0, 153
	createsprite gUnknown_0859551C, ANIM_TARGET, 2, 0, 0, 204
	delay 5
	return
FireBlast2:
	createsprite gUnknown_0859556C, ANIM_TARGET, 2, 0, 0, 10, 0, -2
	createsprite gUnknown_0859556C, ANIM_TARGET, 2, 0, 0, 13, -2, 0
	createsprite gUnknown_0859556C, ANIM_TARGET, 2, 0, 0, 13, 2, 0
	createsprite gUnknown_0859556C, ANIM_TARGET, 2, 0, 0, 15, -2, 2
	createsprite gUnknown_0859556C, ANIM_TARGET, 2, 0, 0, 15, 2, 2
	return

Move_LEECH_SEED:
	loadspritegfx ANIM_TAG_SEED
	playsewithpan SE_W077, SOUND_PAN_ATTACKER
	createsprite gLeechSeedSpriteTemplate, ANIM_TARGET, 2, 15, 0, 0, 24, 35, -32
	delay 8
	playsewithpan SE_W077, SOUND_PAN_ATTACKER
	createsprite gLeechSeedSpriteTemplate, ANIM_TARGET, 2, 15, 0, -16, 24, 35, -40
	delay 8
	playsewithpan SE_W077, SOUND_PAN_ATTACKER
	createsprite gLeechSeedSpriteTemplate, ANIM_TARGET, 2, 15, 0, 16, 24, 35, -37
	delay 12
	loopsewithpan SE_W039, SOUND_PAN_TARGET, 10, 8
	waitforvisualfinish
	end

Move_EMBER:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loopsewithpan SE_W052, SOUND_PAN_ATTACKER, 5, 2
	createsprite gEmberSpriteTemplate, ANIM_TARGET, 2, 20, 0, -16, 24, 20, 1
	delay 4
	createsprite gEmberSpriteTemplate, ANIM_TARGET, 2, 20, 0, 0, 24, 20, 1
	delay 4
	createsprite gEmberSpriteTemplate, ANIM_TARGET, 2, 20, 0, 16, 24, 20, 1
	delay 16
	playsewithpan SE_W172, SOUND_PAN_TARGET
	call Ember1
	call Ember1
	call Ember1
	end

Ember1:
	createsprite gEmberFlareSpriteTemplate, ANIM_TARGET, 2, -24, 24, 24, 24, 20, 1, 1
	delay 4
	return

SetImpactBackground:
	delay 2
	createvisualtask AnimTask_IsContest, 2
	jumprettrue SetImpactContestsBG
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse SetImpactOpponentBG
	jumprettrue SetImpactPlayerBG
SetImpactBackgroundRet:
	return
SetImpactOpponentBG:
	changebg BG_IMPACT_OPPONENT
	goto SetImpactBackgroundRet
SetImpactPlayerBG:
	changebg BG_IMPACT_PLAYER
	goto SetImpactBackgroundRet
SetImpactContestsBG:
	changebg BG_IMPACT_CONTESTS
	goto SetImpactBackgroundRet

Move_MEGA_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	delay 2
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 0, 16, RGB_BLACK
	setalpha 12, 8
	playsewithpan SE_W025, SOUND_PAN_TARGET
	createsprite gMegaPunchKickSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 50
	createvisualtask sub_8116620, 10, 4, 2, 0, 7, RGB_WHITE
	delay 50
	call SetImpactBackground
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_WHITE
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 8, 0, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end

Move_MEGA_KICK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	delay 2
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 0, 16, RGB_BLACK
	setalpha 12, 8
	playsewithpan SE_W025, SOUND_PAN_TARGET
	createsprite gMegaPunchKickSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 50
	createvisualtask sub_8116620, 10, 4, 2, 0, 7, RGB_WHITE
	delay 50
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	call SetImpactBackground
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_WHITE
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 8, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end

Move_COMET_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim CometPunchLeft, CometPunchRight
CometPunchContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
CometPunchLeft:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -8, -8, 1, 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -8, 0, 8, 1, 0
	goto CometPunchContinue
CometPunchRight:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 8, -8, 1, 2
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 8, 0, 8, 1, 0
	goto CometPunchContinue

Move_SONIC_BOOM:
	loadspritegfx ANIM_TAG_AIR_WAVE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	call SonicBoom1
	call SonicBoom1
	call SonicBoom1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 10, 1
	call SonicBoom2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
SonicBoom1:
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gSonicBoomSpriteTemplate, ANIM_TARGET, 2, 16, 0, 0, 0, 15
	delay 4
	return
SonicBoom2:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 2
	delay 4
	return

Move_THUNDER_SHOCK:
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_SPARK_2
	createvisualtask sub_8116620, 10, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask sub_810A7DC, 5, 0, -44, 0
	playsewithpan SE_W085, SOUND_PAN_TARGET
	delay 9
	createvisualtask sub_8116620, 10, 4, 0, 0, 13, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 13, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	call ElectricityEffect
	waitforvisualfinish
	delay 20
	createvisualtask sub_8116620, 10, 1, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_THUNDERBOLT:
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_SHOCK_3
	loadspritegfx ANIM_TAG_SPARK_2
	createvisualtask sub_8116620, 10, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask sub_810A7DC, 5, 24, -52, 0
	playsewithpan SE_W085, SOUND_PAN_TARGET
	delay 7
	createvisualtask sub_810A7DC, 5, -24, -52, 0
	playsewithpan SE_W085, SOUND_PAN_TARGET
	delay 7
	createvisualtask sub_810A7DC, 5, 0, -60, 1
	playsewithpan SE_W085, SOUND_PAN_TARGET
	delay 9
	createvisualtask sub_8116620, 10, 4, 0, 0, 13, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 13, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	createsprite gBattleAnimSpriteTemplate_85957E0, ANIM_TARGET, 3, 44, 0, 0, 3
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 32, 44, 0, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 32, 44, 64, 40, 1, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 32, 44, 128, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 32, 44, 192, 40, 2, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 16, 44, 32, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 16, 44, 96, 40, 1, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 16, 44, 160, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_TARGET, 4, 0, 0, 16, 44, 224, 40, 2, -32765
	playsewithpan SE_W063, SOUND_PAN_TARGET
	delay 0
	createvisualtask sub_8116620, 10, 1, 0, 2, 2, RGB_BLACK
	delay 6
	createvisualtask sub_8116620, 10, 1, 0, 6, 6, RGB_BLACK
	delay 6
	createvisualtask sub_8116620, 10, 1, 0, 2, 2, RGB_BLACK
	delay 6
	createvisualtask sub_8116620, 10, 1, 0, 6, 6, RGB_BLACK
	waitforvisualfinish
	delay 20
	waitplaysewithpan SE_W085B, SOUND_PAN_TARGET, 19
	call ElectricityEffect
	waitforvisualfinish
	delay 20
	createvisualtask sub_8116620, 10, 1, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_THUNDER_WAVE:
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_SPARK_2
	loadspritegfx ANIM_TAG_SPARK_H
	createvisualtask sub_8116620, 10, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask sub_810A7DC, 5, 0, -48, 0
	playsewithpan SE_W086, SOUND_PAN_TARGET
	delay 20
	loopsewithpan SE_W085B, SOUND_PAN_TARGET, 10, 4
	createsprite gUnknown_08595840, ANIM_TARGET, 2, -16, -16
	delay 4
	createsprite gUnknown_08595840, ANIM_TARGET, 2, -16, 0
	delay 4
	createsprite gUnknown_08595840, ANIM_TARGET, 2, -16, 16
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_BEAT_UP:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim BeatUpLeft, BeatUpRight
BeatUpContinue:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
BeatUpLeft:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -20, -20, 1, 2
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, -20, -12, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 8, 0, 1, 2
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, 8, 8, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	goto BeatUpContinue
BeatUpRight:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 12, -20, 1, 2
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, 12, -12, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -12, 0, 1, 2
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, -12, 8, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	goto BeatUpContinue

Move_STOMP:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W104, SOUND_PAN_TARGET
	createsprite gUnknown_08595F60, ANIM_ATTACKER, 3, 0, -32, 15
	delay 19
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, -8, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 4, 9, 1
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAIL_WHIP:
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 24, 3
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 4, 2, 3
	waitforvisualfinish
	end

Move_CUT:
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W015, SOUND_PAN_TARGET
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_HIDDEN_POWER:
	loadspritegfx ANIM_TAG_RED_ORB
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	waitforvisualfinish
	delay 30
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(31, 31, 19), 12, 5, 1
	delay 4
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	playsewithpan SE_W179, SOUND_PAN_ATTACKER
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 0
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 42
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 84
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 126
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 168
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 210
	delay 52
	setarg 7, -1
	playsewithpan SE_W115, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 32
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 64
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 96
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 128
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 160
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 192
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 224
	end

Move_REVERSAL:
	loadspritegfx ANIM_TAG_BLUE_ORB
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	playsewithpan SE_W197, SOUND_PAN_ATTACKER
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 3, RGB_WHITE, 8, 0, 0
	waitforvisualfinish
	delay 30
	createvisualtask sub_8115A04, 2, 31, 3, 2, 0, 10, RGB_WHITE
	delay 10
	playsewithpan SE_W179, SOUND_PAN_ATTACKER
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 0
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 42
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 84
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 126
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 168
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 210
	waitforvisualfinish
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 8
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_WHITE, 8, 0, 0
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 0, 0, 10, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	createvisualtask sub_80D6388, 5, 0, 1, 8, 1, 0
	end

Move_PURSUIT:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	setalpha 12, 8
	choosetwoturnanim PursuitNormal, PursuitOnSwitchout
PursuitContinue:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0
	restorebg
	waitbgfadein
	end
PursuitNormal:
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask sub_80D6388, 5, 0, 1, 6, 1, 0
	goto PursuitContinue
PursuitOnSwitchout:
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createvisualtask sub_80D6388, 5, 0, 1, 6, 1, 0
	goto PursuitContinue

Move_SPIKE_CANNON:
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -4, 0, 4, 6, 8, 4
	waitforvisualfinish
	loopsewithpan SE_W013B, SOUND_PAN_ATTACKER, 5, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	createsprite gLinearStingerSpriteTemplate, ANIM_ATTACKER, 2, 10, -8, -8, -8, 20
	createsprite gLinearStingerSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 0, 0, 20
	createsprite gLinearStingerSpriteTemplate, ANIM_ATTACKER, 2, 26, 8, 8, 8, 20
	waitforvisualfinish
	createsprite gBattleAnimSpriteTemplate_8597370, ANIM_ATTACKER, 3, -8, -8, 1, 2
	createsprite gBattleAnimSpriteTemplate_8597370, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createsprite gBattleAnimSpriteTemplate_8597370, ANIM_ATTACKER, 3, 8, 8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 7, 1
	loopsewithpan SE_W030, SOUND_PAN_TARGET, 5, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SWORDS_DANCE:
	loadspritegfx ANIM_TAG_SWORD
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W014, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 16, 6, 1, 4
	createsprite gSwordsDanceBladeSpriteTemplate, ANIM_ATTACKER, 2, 0, 0
	delay 22
	createvisualtask sub_8115D94, 2, ANIM_TAG_SWORD, 2, 2, RGB(18, 31, 31), 16, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	end

Move_PSYCH_UP:
	loadspritegfx ANIM_TAG_SPIRAL
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8115B0C, 2, 1, 2, 6, 1, 11, 0
	setalpha 12, 8
	loopsewithpan SE_W060B, SOUND_PAN_ATTACKER, 5, 10
	createsprite gUnknown_08596548, ANIM_ATTACKER, 2, 0, 0, 0, 0
	createvisualtask AnimTask_SwayMon, 5, 0, 5, 2560, 8, ANIM_ATTACKER
	delay 127
	delay 4
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	createvisualtask sub_8116620, 9, 2, 2, 10, 0, RGB_YELLOW
	delay 30
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_DIZZY_PUNCH:
	loadspritegfx ANIM_TAG_DUCK
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	call DizzyPunch1
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 5, 16, 8, 20, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, 16, 0, 1, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, 16, 8, 160, -32
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, 16, 8, -256, -40
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, 16, 8, 128, -16
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, 16, 8, 416, -38
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, 16, 8, -128, -22
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, 16, 8, -384, -31
	delay 10
	call DizzyPunch1
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 5, -16, -8, 20, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, -16, -16, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, -16, -8, 160, -32
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, -16, -8, -256, -40
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, -16, -8, 128, -16
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, -16, -8, 416, -38
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, -16, -8, -128, -22
	createsprite gUnknown_08595F78, ANIM_TARGET, 3, -16, -8, -384, -31
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
DizzyPunch1:
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 7, 1
	return

Move_FIRE_SPIN:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	playsewithpan SE_W221B, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 47, 1
	call FireSpinEffect
	call FireSpinEffect
	call FireSpinEffect
	waitforvisualfinish
	end

FireSpinEffect:
	createsprite gUnknown_08596B88, ANIM_TARGET, 2, 0, 28, 528, 30, 13, 50, 1
	delay 2
	createsprite gUnknown_08596B88, ANIM_TARGET, 2, 0, 32, 480, 20, 16, -46, 1
	delay 2
	createsprite gUnknown_08596B88, ANIM_TARGET, 2, 0, 33, 576, 20, 8, 42, 1
	delay 2
	createsprite gUnknown_08596B88, ANIM_TARGET, 2, 0, 31, 400, 25, 11, -42, 1
	delay 2
	createsprite gUnknown_08596B88, ANIM_TARGET, 2, 0, 28, 512, 25, 16, 46, 1
	delay 2
	createsprite gUnknown_08596B88, ANIM_TARGET, 2, 0, 33, 464, 30, 15, -50, 1
	delay 2
	return

Move_FURY_CUTTER:
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createvisualtask AnimTask_IsFuryCutterHitRight, 2
	jumpretfalse FuryCutterLeft
	goto FuryCutterRight
FuryCutterContinue:
	createvisualtask AnimTask_GetFuryCutterHitCount, 2
	jumpreteq 1, FuryCutterContinue2
	jumpreteq 2, FuryCutterMedium
	jumpreteq 3, FuryCutterStrong
	goto FuryCutterStrongest
FuryCutterContinue2:
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end
FuryCutterLeft:
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	goto FuryCutterContinue
FuryCutterRight:
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 1
	goto FuryCutterContinue
FuryCutterMedium:
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB(9, 8, 10), 4, 0, 0
	goto FuryCutterContinue2
FuryCutterStrong:
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 3, RGB(9, 8, 10), 4, 0, 0
	goto FuryCutterContinue2
FuryCutterStrongest:
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 3, RGB(9, 8, 10), 4, 0, 0
	goto FuryCutterContinue2

Move_SELF_DESTRUCT:
	loadspritegfx ANIM_TAG_EXPLOSION
	createvisualtask sub_8116620, 10, 2, 1, 0, 9, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 5, 4, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 5, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 6, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 7, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 8, 6, 0, 38, 1
	call SelfDestruct1
	call SelfDestruct1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 1, 9, 0, RGB_RED
	end
SelfDestruct1:
	playsewithpan SE_W120, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 0, 0, 0, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 24, -24, 0, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -16, 16, 0, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -24, -12, 0, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 16, 16, 0, 1
	delay 6
	return

Move_SLAM:
	loadspritegfx ANIM_TAG_SLAM_HIT
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W004, SOUND_PAN_ATTACKER
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 3, 0, 4
	delay 1
	createsprite gUnknown_085928D0, ANIM_ATTACKER, 2, 0, 0
	delay 3
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -12, 10, 0, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_VINE_WHIP:
	loadspritegfx ANIM_TAG_WHIP_HIT
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 6
	playsewithpan SE_W010, SOUND_PAN_TARGET
	createsprite gVineWhipSpriteTemplate, ANIM_TARGET, 2, 0, 0
	delay 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 6, 1
	end

Move_DRILL_PECK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_WHIRLWIND_LINES
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 0
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 1
	delay 2
	loopsewithpan SE_W030, SOUND_PAN_TARGET, 4, 8
	createvisualtask sub_810EB88, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	waitforvisualfinish
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 2
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 6
	waitforvisualfinish
	end

Move_WATERFALL:
	loadspritegfx ANIM_TAG_WATER_IMPACT
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 23, 1
	delay 5
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 10, 10, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, -15, 0, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 20, 10, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 0, -10, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, -10, 15, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 25, 20, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, -20, 20, 25, 0
	delay 4
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 12, 0, 25, 0
	waitforvisualfinish
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 5
	delay 6
	call UnderWaterAttack1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

UnderWaterAttack1:
	playsewithpan SE_W127, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 17, 1
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, 20, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 20
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 20
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, 15, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 15
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 15
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, 10, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 10
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 10
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, 5, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 5
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 5
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 0
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, 0
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, -5, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -5
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -5
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, -10, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -10
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -10
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, -15, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -15
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -15
	delay 2
	createsprite gUnknown_08597388, ANIM_ATTACKER, 3, 0, -20, 1, 1
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -20
	createsprite gUnknown_08595250, ANIM_ATTACKER, 4, 0, -20
	return

Move_EXPLOSION:
	loadspritegfx ANIM_TAG_EXPLOSION
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 8, 9, RGB(26, 8, 8), 8, 0, 8
	createvisualtask AnimTask_ShakeMon2, 5, 4, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 5, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 6, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 7, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 8, 8, 0, 40, 1
	call Explosion1
	call Explosion1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 1, 16, 16, RGB_WHITE
	delay 50
	createvisualtask sub_8116620, 10, 1, 3, 16, 0, RGB_WHITE
	end
Explosion1:
	playsewithpan SE_W153, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 0, 0, 0, 1
	delay 6
	playsewithpan SE_W153, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 24, -24, 0, 1
	delay 6
	playsewithpan SE_W153, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -16, 16, 0, 1
	delay 6
	playsewithpan SE_W153, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -24, -12, 0, 1
	delay 6
	playsewithpan SE_W153, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 16, 16, 0, 1
	delay 6
	return

Move_DEFENSE_CURL:
	loadspritegfx ANIM_TAG_ECLIPSING_ORB
	loopsewithpan SE_W161, SOUND_PAN_ATTACKER, 18, 3
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 0
	createvisualtask sub_815B338, 5
	waitforvisualfinish
	createsprite gUnknown_085CE338, ANIM_ATTACKER, 2, 0, 6, 0, 1
	waitforvisualfinish
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 1
	waitforvisualfinish
	end

Move_PROTECT:
	loadspritegfx ANIM_TAG_PROTECT
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	waitplaysewithpan SE_W115, SOUND_PAN_ATTACKER, 16
	createsprite gUnknown_08592ADC, ANIM_ATTACKER, 2, 24, 0, 90
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_DETECT:
	loadspritegfx ANIM_TAG_SPARKLE_4
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 1, 0, 9, RGB_WHITE
	delay 18
	playsewithpan SE_W197, SOUND_PAN_ATTACKER
	createsprite gUnknown_0853EE84, ANIM_ATTACKER, 13, 20, -20
	waitforvisualfinish
	delay 10
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 9, 0, RGB_BLACK
	createvisualtask sub_8116620, 10, 2, 2, 9, 0, RGB_WHITE
	waitforvisualfinish
	end

Move_FRUSTRATION:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ANGER
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_GetFrustrationPowerLevel, 1
	jumpreteq 0, Frustration_Strongest
	jumpreteq 1, Frustration_Strong
	jumpreteq 2, Frustration_Medium
	goto Frustration_Weak
Frustration_Continue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
Frustration_Strongest:
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER, 1, 0, 15, 1
	createvisualtask sub_8116620, 10, 2, 3, 0, 9, 31
	waitforvisualfinish
	delay 20
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_SwayMon, 5, 0, 16, 6144, 8, ANIM_ATTACKER
	delay 5
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 30, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 24, 8, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -24, -16, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 8, 4, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -16, 19, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 18, -18, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 3, 9, 0, 31
	goto Frustration_Continue
Frustration_Strong:
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER, 1, 0, 15, 1
	createvisualtask sub_8116620, 10, 2, 3, 0, 9, 31
	waitforvisualfinish
	delay 20
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	delay 5
	createvisualtask AnimTask_StrongFrustrationGrowAndShrink, 5
	delay 7
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 8, 1, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	delay 14
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 12, -6, 1, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	delay 14
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -12, -6, 1, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 3, 9, 0, 31
	goto Frustration_Continue
Frustration_Medium:
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	delay 5
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, 4, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -4, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	goto Frustration_Continue
Frustration_Weak:
	createsprite gWeakFrustrationAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 20, -28
	waitforvisualfinish
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 10, 2
	delay 12
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	goto Frustration_Continue

Move_SAFEGUARD:
	loadspritegfx ANIM_TAG_GUARD_RING
	monbg ANIM_ATK_PARTNER
	setalpha 8, 8
	playsewithpan SE_W208, SOUND_PAN_ATTACKER
	createsprite gUnknown_08593C64, ANIM_ATTACKER, 2
	delay 4
	createsprite gUnknown_08593C64, ANIM_ATTACKER, 2
	delay 4
	createsprite gUnknown_08593C64, ANIM_ATTACKER, 2
	waitforvisualfinish
	playsewithpan SE_REAPOKE, SOUND_PAN_ATTACKER
	createvisualtask sub_8115A04, 2, 10, 0, 2, 0, 10, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_PAIN_SPLIT:
	loadspritegfx ANIM_TAG_PAIN_SPLIT
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_ATTACKER, 2, -8, -42, ANIM_ATTACKER
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_TARGET, 2, -8, -42, ANIM_TARGET
	delay 10
	playsewithpan SE_W207B, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_ATTACKER, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_TARGET, 0
	waitforvisualfinish
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_ATTACKER, 2, -24, -42, ANIM_ATTACKER
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_TARGET, 2, -24, -42, ANIM_TARGET
	delay 10
	playsewithpan SE_W207B, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_ATTACKER, 1
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_TARGET, 1
	waitforvisualfinish
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_ATTACKER, 2, 8, -42, ANIM_ATTACKER
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_TARGET, 2, 8, -42, ANIM_TARGET
	delay 10
	playsewithpan SE_W207B, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_ATTACKER, 2
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_TARGET, 2
	end

Move_VICE_GRIP:
	loadspritegfx ANIM_TAG_CUT
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W011, SOUND_PAN_TARGET
	createsprite gViceGripSpriteTemplate, ANIM_ATTACKER, 2, 0
	createsprite gViceGripSpriteTemplate, ANIM_ATTACKER, 2, 1
	delay 9
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 1, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_GUILLOTINE:
	loadspritegfx ANIM_TAG_CUT
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	fadetobgfromset BG_GUILLOTINE_OPPONENT, BG_GUILLOTINE_PLAYER, BG_GUILLOTINE_CONTESTS
	waitbgfadein
	playsewithpan SE_W011, SOUND_PAN_TARGET
	createsprite gGuillotineSpriteTemplate, ANIM_ATTACKER, 2, 0
	createsprite gGuillotineSpriteTemplate, ANIM_ATTACKER, 2, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 16, RGB_BLACK
	delay 9
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 23, 1
	delay 0x2E
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 8, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 0
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 8, 0, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_PAY_DAY:
	loadspritegfx ANIM_TAG_COIN
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gUnknown_085934D8, ANIM_ATTACKER, 2, 20, 0, 0, 0, 1152
	waitforvisualfinish
	playsewithpan SE_W006, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 1, 0, 0, 1, 2
	createsprite gUnknown_085934F0, ANIM_ATTACKER, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_OUTRAGE:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loopsewithpan SE_W082, SOUND_PAN_ATTACKER, 8, 3
	createvisualtask sub_8115A04, 2, 7, 2, 5, 3, 8, RGB(14, 13, 0)
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 6, 5, 4
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 1280, 0, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, -1280, 0, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 0, 1280, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 0, -1280, 3
	delay 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 40, 1
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, -1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 1280, -768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, -1280, -768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 1280, 0, 3
	call Outrage1
	call Outrage1
	waitforvisualfinish
	end
Outrage1:
	delay 3
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, -1280, 0, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 0, 1280, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 0, -1280, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, -1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, 1280, -768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, ANIM_TARGET, 2, 0, 0, 30, -1280, -768, 3
	return

Move_SPARK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_SPARK_2
	delay 0
	createvisualtask sub_8115A04, 2, 3, -31, 1, 5, 5, RGB(31, 31, 22)
	playsewithpan SE_W085B, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859574C, ANIM_ATTACKER, 0, 32, 24, 190, 12, 0, 1, 0
	delay 0
	createsprite gBattleAnimSpriteTemplate_859574C, ANIM_ATTACKER, 0, 80, 24, 22, 12, 0, 1, 0
	createsprite gBattleAnimSpriteTemplate_859574C, ANIM_ATTACKER, 0, 156, 24, 121, 13, 0, 1, 1
	delay 0
	createvisualtask sub_8115A04, 2, 3, -31, 1, 0, 0, RGB(31, 31, 22)
	delay 10
	createvisualtask sub_8115A04, 2, 3, -31, 1, 5, 5, RGB(31, 31, 22)
	playsewithpan SE_W085B, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_859574C, ANIM_ATTACKER, 0, 100, 24, 60, 10, 0, 1, 0
	createsprite gBattleAnimSpriteTemplate_859574C, ANIM_ATTACKER, 0, 170, 24, 42, 11, 0, 1, 1
	delay 0
	createsprite gBattleAnimSpriteTemplate_859574C, ANIM_ATTACKER, 0, 238, 24, 165, 10, 0, 1, 1
	delay 0
	createvisualtask sub_8115A04, 2, 3, -31, 1, 0, 0, RGB(31, 31, 22)
	delay 20
	createvisualtask sub_8115A04, 2, 3, -31, 1, 7, 7, RGB(31, 31, 22)
	playsewithpan SE_W085B, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 32, 12, 0, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 32, 12, 64, 20, 1, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 32, 12, 128, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 32, 12, 192, 20, 2, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 16, 12, 32, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 16, 12, 96, 20, 1, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 16, 12, 160, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, ANIM_ATTACKER, 4, 0, 0, 16, 12, 224, 20, 2, 0
	delay 4
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 3, -31, 1, 0, 0, RGB(31, 31, 22)
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 4
	playsewithpan SE_W063, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 4, -31, 2, 0, 6, RGB(31, 31, 22)
	call ElectricityEffect
	waitforvisualfinish
	end

Move_ATTRACT:
	loadspritegfx ANIM_TAG_RED_HEART
	loopsewithpan SE_W204, SOUND_PAN_ATTACKER, 12, 3
	createvisualtask AnimTask_SwayMon, 5, 0, 12, 4096, 4, ANIM_ATTACKER
	delay 15
	createsprite gUnknown_085939A0, ANIM_TARGET, 3, 20, -8
	waitforvisualfinish
	playsewithpan SE_W213, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, 160, -32
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, -256, -40
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, 128, -16
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, 416, -38
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, -128, -22
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, -384, -31
	waitforvisualfinish
	waitplaysewithpan SE_W213B, 0, 15
	createvisualtask AnimTask_HeartsBackground, 5
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 16, 256, 0
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 224, 240, 15
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 126, 272, 30
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 80, 224, 45
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 170, 272, 60
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 40, 256, 75
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 112, 256, 90
	createsprite gUnknown_085939D0, ANIM_ATTACKER, 40, 200, 272, 90
	delay 75
	createvisualtask sub_8115A04, 2, 4, 4, 4, 0, 10, RGB(31, 25, 27)
	end

Move_GROWTH:
	call Growth1
	waitforvisualfinish
	call Growth1
	waitforvisualfinish
	end
Growth1:
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB_WHITE
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -3, -3, 16, ANIM_ATTACKER, 0
	return

Move_WHIRLWIND:
	loadspritegfx ANIM_TAG_WHIRLWIND_LINES
	createsprite gUnknown_085963D4, ANIM_ATTACKER, 2, 0, -8, 1, 60, 0
	createsprite gUnknown_085963D4, ANIM_ATTACKER, 2, 0, 0, 1, 60, 1
	createsprite gUnknown_085963D4, ANIM_ATTACKER, 2, 0, 8, 1, 60, 2
	createsprite gUnknown_085963D4, ANIM_ATTACKER, 2, 0, 16, 1, 60, 3
	createsprite gUnknown_085963D4, ANIM_ATTACKER, 2, 0, 24, 1, 60, 4
	createsprite gUnknown_085963D4, ANIM_ATTACKER, 2, 0, 32, 1, 60, 0
	delay 5
	loopsewithpan SE_W104, SOUND_PAN_TARGET, 10, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 15, 1
	delay 0x1D
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_TARGET, 12, 6, 1, 5
	delay 7
	playsewithpan SE_W081, SOUND_PAN_TARGET
	createvisualtask sub_80D5DB0, 5, 1, 8
	waitforvisualfinish
	end

Move_CONFUSE_RAY:
	loadspritegfx ANIM_TAG_YELLOW_BALL
	monbg ANIM_DEF_PARTNER
	fadetobg BG_GHOST
	waitbgfadein
	createvisualtask sub_8159278, 2, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 2, 0
	createvisualtask sub_8115C80, 2, 10013, 0, 6, 0, 14, 351
	createsprite gUnknown_08596D14, ANIM_TARGET, 2, 28, 0, 288
	waitforvisualfinish
	setalpha 8, 8
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gUnknown_08596D2C, ANIM_TARGET, 2, 0, -16
	waitforvisualfinish
	delay 0
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end

Move_LOCK_ON:
	loadspritegfx ANIM_TAG_LOCK_ON
	createsprite gUnknown_08592CA0, ANIM_ATTACKER, 40
	createsprite gUnknown_08592CB8, ANIM_ATTACKER, 40, 1
	createsprite gUnknown_08592CB8, ANIM_ATTACKER, 40, 2
	createsprite gUnknown_08592CB8, ANIM_ATTACKER, 40, 3
	createsprite gUnknown_08592CB8, ANIM_ATTACKER, 40, 4
	delay 120
	setarg 7, -1
	waitforvisualfinish
	end

Move_MEAN_LOOK:
	loadspritegfx ANIM_TAG_EYE
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 16, RGB_BLACK
	loopsewithpan SE_W109, SOUND_PAN_TARGET, 15, 4
	waitplaysewithpan SE_W043, SOUND_PAN_TARGET, 0x55
	createsprite gUnknown_085CE104, ANIM_ATTACKER, 2
	delay 120
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 16, 0, RGB_BLACK
	delay 30
	clearmonbg ANIM_DEF_PARTNER
	waitforvisualfinish
	end

Move_ROCK_THROW:
	loadspritegfx ANIM_TAG_ROCKS
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_TARGET, 2, 6, 1, 15, 1
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 0, 1, 0, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 6
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 19, 1, 10, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 6
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -23, 2, -10, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 5, 20, 1
	delay 6
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -15, 1, -10, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 6
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 23, 2, 10, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_ROCK_SLIDE:
	loadspritegfx ANIM_TAG_ROCKS
	monbg ANIM_DEF_PARTNER
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, 7, 1, 11, 1
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -5, 1, -5, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 5, 0, 6, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 19, 1, 10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -23, 2, -10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 5, 50, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_DEF_PARTNER, 0, 5, 50, 1
	delay 2
	call RockSlide1
	call RockSlide1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

RockSlide1:
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -20, 0, -10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 28, 1, 10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -10, 1, -5, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 10, 0, 6, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 24, 1, 10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -32, 2, -10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, -20, 0, -10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08596B04, ANIM_TARGET, 2, 30, 2, 10, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 2
	return

Move_THIEF:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	delay 1
	fadetobg BG_DARK
	waitbgfadein
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 6
	playsewithpan SE_W233, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 8, 1
	waitforvisualfinish
	delay 20
	clearmonbg ANIM_TARGET
	blendoff
	restorebg
	waitbgfadein
	end

Move_BUBBLE_BEAM:
	loadspritegfx ANIM_TAG_BUBBLE
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 1
	call Bulbblebeam1
	createvisualtask AnimTask_SwayMon, 5, 0, 3, 3072, 8, ANIM_TARGET
	call Bulbblebeam1
	call Bulbblebeam1
	waitforvisualfinish
	call WaterBubbleEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
Bulbblebeam1:
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 35, 70, 0, 256, 50
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 20, 40, -10, 256, 50
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 10, -60, 0, 256, 50
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 15, -15, 10, 256, 50
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 30, 10, -10, 256, 50
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 25, -30, 10, 256, 50
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	delay 3
	return

Move_ICY_WIND:
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	loadspritegfx ANIM_TAG_ICE_SPIKES
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8116620, 10, 11, 4, 0, 4, RGB_BLACK
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_W196, 0
	waitbgfadein
	waitforvisualfinish
	panse_1B SE_W016, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	call IcyWind1
	delay 5
	call IcyWind1
	playsewithpan SE_W016B, SOUND_PAN_TARGET
	delay 0x37
	call IcyWindEffect2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadeout
	createvisualtask sub_8116620, 10, 11, 4, 4, 0, RGB_BLACK
	waitbgfadein
	end
IcyWind1:
	createsprite gUnknown_08595B98, ANIM_TARGET, 40, 0, 0, 0, 0, 72, 1
	delay 5
	createsprite gUnknown_08595B98, ANIM_TARGET, 40, 0, 10, 0, 10, 72, 1
	delay 5
	createsprite gUnknown_08595B98, ANIM_TARGET, 40, 0, -10, 0, -10, 72, 1
	delay 5
	createsprite gUnknown_08595B98, ANIM_TARGET, 40, 0, 15, 0, 15, 72, 1
	delay 5
	createsprite gUnknown_08595B98, ANIM_TARGET, 40, 0, -5, 0, -5, 72, 1
	return

Move_SMOKESCREEN:
	loadspritegfx ANIM_TAG_BLACK_SMOKE
	loadspritegfx ANIM_TAG_BLACK_BALL
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gUnknown_085CE050, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
	waitforvisualfinish
	createvisualtask sub_815A160, 2
	delay 2
	playsewithpan SE_W028, SOUND_PAN_TARGET
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, -12, 104, 0, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, -12, 72, 1, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, -6, 56, 1, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, -6, 88, 0, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 0, 56, 0, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 0, 88, 1, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 6, 72, 0, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 6, 104, 1, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 12, 72, 0, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 12, 56, 1, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 18, 80, 0, 75
	createsprite gUnknown_085CE038, ANIM_TARGET, 4, 0, 18, 72, 1, 75
	waitforvisualfinish
	end

Move_CONVERSION:
	loadspritegfx ANIM_TAG_CONVERSION
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 16, 0
	delay 0
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -24, -24
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -8, -24
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 8, -24
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 24, -24
	delay 3
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -24, -8
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -8, -8
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 8, -8
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 24, -8
	delay 3
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -24, 8
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -8, 8
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 8, 8
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 24, 8
	delay 3
	playsewithpan SE_W129, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -24, 24
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, -8, 24
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 8, 24
	delay 3
	createsprite gUnknown_08592E74, ANIM_ATTACKER, 2, 24, 24
	delay 20
	playsewithpan SE_W112, SOUND_PAN_ATTACKER
	createvisualtask sub_8115D94, 2, ANIM_TAG_CONVERSION, 1, 1, 14335, 12, 0, 0
	delay 6
	createvisualtask sub_81022D4, 5
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_CONVERSION_2:
	loadspritegfx ANIM_TAG_CONVERSION
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0, 16
	delay 0
	playsewithpan SE_W112, SOUND_PAN_TARGET
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -24, -24, 60
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -8, -24, 65
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 8, -24, 70
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 24, -24, 75
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -24, -8, 80
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -8, -8, 85
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 8, -8, 90
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 24, -8, 95
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -24, 8, 100
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -8, 8, 105
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 8, 8, 110
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 24, 8, 115
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -24, 24, 120
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, -8, 24, 125
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 8, 24, 130
	createsprite gUnknown_08592EA4, ANIM_ATTACKER, 2, 24, 24, 135
	createvisualtask sub_81023E0, 5
	delay 60
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_W129, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROLLING_KICK:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 4
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 6
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	createsprite gUnknown_08595EE0, ANIM_ATTACKER, 2, -24, 0, 48, 10, 160, 0
	delay 5
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -8, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 8
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HEADBUTT:
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 0
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 2
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 0, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_HORN_ATTACK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HORN_HIT
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 0
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 1
	createsprite gUnknown_08592F44, ANIM_TARGET, 4, 0, 0, 10
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 2
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 0, 1, 1
	playsewithpan SE_W030, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_FURY_ATTACK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HORN_HIT
	createvisualtask sub_80D6134, 2, 4, 256, 0, 2
	choosetwoturnanim FuryAttackRight, FuryAttackLeft
FuryAttackContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	waitforvisualfinish
	end

FuryAttackRight:
	createsprite gUnknown_08592F44, ANIM_TARGET, 4, 8, 8, 10
	waitforvisualfinish
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 0, 1, 1
	playsewithpan SE_W030, SOUND_PAN_TARGET
	goto FuryAttackContinue

FuryAttackLeft:
	createsprite gUnknown_08592F44, ANIM_TARGET, 4, -8, -8, 10
	waitforvisualfinish
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 0, 1, 1
	playsewithpan SE_W030, SOUND_PAN_TARGET
	goto FuryAttackContinue

Move_HORN_DRILL:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HORN_HIT
	jumpifcontest HornDrillInContest
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 768, 1, -1
HornDrillContinue:
	waitbgfadein
	setalpha 12, 8
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 0
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 1
	createsprite gUnknown_08592F44, ANIM_TARGET, 4, 0, 0, 12
	waitforvisualfinish
	playse SE_BAN
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 40, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 40, 1
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 0, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 0, 2, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, -4, 3, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, -8, -5, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 4, -12, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 16, 0, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 5, 18, 1, 3
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, -17, 12, 1, 2
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, -21, -15, 1, 2
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 8, -27, 1, 2
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 32, 0, 1, 2
	playsewithpan SE_W030, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08592CD8, ANIM_ATTACKER, 2, 2
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	end

HornDrillInContest:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 5, 2304, 768, 0, -1
	goto HornDrillContinue

Move_THRASH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	createvisualtask sub_8104C38, 2
	createvisualtask sub_8104CA4, 2
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 28
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 28
	createsprite gUnknown_08595EB0, ANIM_TARGET, 3, 1, 10, 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	end

Move_SING:
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8102BE8, 2
	waitforvisualfinish
	panse_1B SE_W047, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 7, 0, 12
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 6, 1, 12
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 1, 2, 12
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 3, 12
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 3, 0, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 1, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 5, 2, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 6, 3, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 0, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 1, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 1, 2, 12
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 5, 3, 12
	delay 4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	createvisualtask sub_8102CA0, 2
	waitforvisualfinish
	end

Move_LOW_KICK:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	createsprite gUnknown_08595EE0, ANIM_TARGET, 2, -24, 28, 40, 8, 160, 0
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -8, 8, 1, 2
	createvisualtask sub_80D6134, 2, 6, 384, 1, 2
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 4
	end

Move_EARTHQUAKE:
	createvisualtask sub_81152DC, 5, 5, 10, 50
	createvisualtask sub_81152DC, 5, 4, 10, 50
	playsewithpan SE_W089, 0
	delay 10
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	delay 16
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	end

Move_FISSURE:
	loadspritegfx ANIM_TAG_MUD_SAND
	createvisualtask sub_81152DC, 3, 5, 10, 50
	createvisualtask sub_81152DC, 3, 1, 10, 50
	playsewithpan SE_W089, SOUND_PAN_TARGET
	delay 8
	call Fissure1
	delay 15
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	delay 15
	call Fissure2
	delay 15
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	delay 15
	call Fissure1
	delay 50
	fadetobg BG_FISSURE
	waitbgfadeout
	createvisualtask sub_8115628, 5, 1, 5, -1
	waitbgfadein
	delay 40
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	end

Fissure1:
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 0, 12, -48, -16, 24
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 0, 16, -16, -10, 24
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 1, 14, -52, -18, 24
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 1, 12, -32, -16, 24
	playsewithpan SE_W091, SOUND_PAN_TARGET
	return

Fissure2:
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 0, 12, -24, -16, 24
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 0, 16, -38, -10, 24
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 1, 14, -20, -18, 24
	createsprite gUnknown_085971FC, ANIM_TARGET, 2, 1, 1, 12, -36, -16, 24
	playsewithpan SE_W091, SOUND_PAN_TARGET
	return

Move_DIG:
	choosetwoturnanim DigSetUp, DigUnleash
DigEnd:
	end
DigSetUp:
	loadspritegfx ANIM_TAG_MUD_SAND
	loadspritegfx ANIM_TAG_DIRT_MOUND
	createsprite gUnknown_08597214, ANIM_ATTACKER, 1, 0, 0, 180
	createsprite gUnknown_08597214, ANIM_ATTACKER, 1, 0, 1, 180
	monbg_22 ANIM_ATTACKER
	delay 1
	createvisualtask sub_8114CBC, 2, 0
	delay 6
	call DigSetUp1
	call DigSetUp1
	call DigSetUp1
	call DigSetUp1
	call DigSetUp1
	waitforvisualfinish
	clearmonbg_23 ANIM_ATTACKER
	delay 1
	createvisualtask sub_8114CBC, 2, 1
	goto DigEnd
DigUnleash:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_DIRT_MOUND
	createvisualtask sub_8114F14, 2, 0
	waitforvisualfinish
	monbg ANIM_ATTACKER
	createsprite gUnknown_08597214, ANIM_ATTACKER, 1, 0, 0, 48
	createsprite gUnknown_08597214, ANIM_ATTACKER, 1, 0, 1, 48
	delay 1
	createvisualtask sub_8114F14, 2, 1
	delay 16
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -8, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	playsewithpan SE_W025B, SOUND_PAN_ATTACKER
	clearmonbg ANIM_ATTACKER
	goto DigEnd
DigSetUp1:
	createsprite gUnknown_085971FC, ANIM_ATTACKER, 2, 0, 0, 12, 4, -16, 18
	createsprite gUnknown_085971FC, ANIM_ATTACKER, 2, 0, 0, 16, 4, -10, 18
	createsprite gUnknown_085971FC, ANIM_ATTACKER, 2, 0, 1, 14, 4, -18, 18
	createsprite gUnknown_085971FC, ANIM_ATTACKER, 2, 0, 1, 12, 4, -16, 18
	playsewithpan SE_W091, SOUND_PAN_ATTACKER
	delay 32
	return

Move_MEDITATE:
	call SetPsychicBackground
	createvisualtask sub_810F7D4, 2
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	delay 16
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	waitforvisualfinish
	call UnsetPsychicBg
	end

Move_AGILITY:
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 4, 4
	createvisualtask sub_81169C0, 2, 0, 4, 7, 10
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 12
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_QUICK_ATTACK:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask sub_81169C0, 2, 0, 4, 7, 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	delay 4
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, 0, 0, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_RAGE:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ANGER
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_ATTACKER, RGB_RED, 10, 0, 2
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, -20, -28
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	delay 20
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask sub_80D6388, 2, 1, 1, 10, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_TELEPORT:
	call SetPsychicBackground
	createvisualtask sub_810F83C, 2
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	delay 15
	call UnsetPsychicBg
	waitforvisualfinish
	end

Move_DOUBLE_TEAM:
	createvisualtask sub_81029B4, 2
	setalpha 12, 8
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 32
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 24
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 16
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_MINIMIZE:
	setalpha 10, 8
	createvisualtask AnimTask_Minimize, 2
	loopsewithpan SE_W107, SOUND_PAN_ATTACKER, 34, 3
	waitforvisualfinish
	blendoff
	end

Move_METRONOME:
	loadspritegfx ANIM_TAG_FINGER
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	createsprite gUnknown_08593114, ANIM_ATTACKER, 11, 0, 100
	playsewithpan SE_W118, SOUND_PAN_ATTACKER
	delay 6
	createsprite gUnknown_085931BC, ANIM_ATTACKER, 12, 0
	delay 24
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 22, 3
	waitforvisualfinish
	end

Move_SKULL_BASH:
	choosetwoturnanim SkullBashSetUp, SkullBashAttack
SkullBashEnd:
	end
SkullBashSetUp:
	call SkullBashSetUp1
	call SkullBashSetUp1
	waitforvisualfinish
	goto SkullBashEnd
SkullBashSetUp1:
	createsprite gUnknown_0857FE88, ANIM_ATTACKER, 2, 0, -24, 0, 0, 10, 0
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 16, 96, 0, 2
	waitforvisualfinish
	createsprite gUnknown_0857FE88, ANIM_ATTACKER, 2, 0, 24, 0, 0, 10, 1
	waitforvisualfinish
	return
SkullBashAttack:
	loadspritegfx ANIM_TAG_IMPACT
	createvisualtask sub_8101C94, 2, 0
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	waitforvisualfinish
	playse SE_BAN
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 40, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 40, 1
	createsprite gUnknown_085973E8, ANIM_TARGET, 4, 0, 0, 1, 0
	loopsewithpan SE_W025B, SOUND_PAN_TARGET, 8, 3
	waitforvisualfinish
	createvisualtask sub_8101C94, 2, 1
	goto SkullBashEnd

Move_AMNESIA:
	loadspritegfx ANIM_TAG_AMNESIA
	call SetPsychicBackground
	delay 8
	createsprite gUnknown_08596744, ANIM_ATTACKER, 20
	playsewithpan SE_W118, SOUND_PAN_ATTACKER
	delay 54
	loopsewithpan SE_W118, SOUND_PAN_ATTACKER, 16, 3
	waitforvisualfinish
	call UnsetPsychicBg
	end

Move_KINESIS:
	loadspritegfx ANIM_TAG_ALERT
	loadspritegfx ANIM_TAG_BENT_SPOON
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	createsprite gUnknown_085966DC, ANIM_ATTACKER, 20
	createsprite gKinesisZapEnergySpriteTemplate, ANIM_ATTACKER, 19, 32, -8, 0
	createsprite gKinesisZapEnergySpriteTemplate, ANIM_ATTACKER, 19, 32, 16, 1
	loopsewithpan SE_W109, SOUND_PAN_ATTACKER, 21, 2
	delay 60
	playsewithpan SE_W146, SOUND_PAN_ATTACKER
	delay 30
	loopsewithpan SE_W146, SOUND_PAN_ATTACKER, 20, 2
	delay 70
	playsewithpan SE_W207B, SOUND_PAN_ATTACKER
	waitforvisualfinish
	call UnsetPsychicBg
	end

Move_GLARE:
	loadspritegfx ANIM_TAG_SMALL_RED_EYE
	loadspritegfx ANIM_TAG_EYE_SPARKLE
	createvisualtask AnimTask_GlareEyeDots, 5, 0
	playsewithpan SE_W060B, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_8116620, 5, 1, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08593A84, ANIM_ATTACKER, 0, -16, -8
	createsprite gUnknown_08593A84, ANIM_ATTACKER, 0, 16, -8
	createvisualtask sub_81064F8, 5
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	delay 2
	createvisualtask sub_810A094, 3, 20, 1, 0
	waitforvisualfinish
	createvisualtask sub_8116620, 5, 1, 0, 16, 0, RGB_BLACK
	end

Move_BARRAGE:
	loadspritegfx ANIM_TAG_RED_BALL
	createvisualtask AnimTask_BarrageBall, 3
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	delay 24
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, 8, 1, 40, 1
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 0, 4, 20, 1
	createvisualtask AnimTask_ShakeMon, 3, ANIM_DEF_PARTNER, 0, 4, 20, 1
	loopsewithpan SE_W070, SOUND_PAN_TARGET, 8, 2
	end

Move_SKY_ATTACK:
	choosetwoturnanim SkyAttackSetUp, SkyAttackUnleash
SkyAttackEnd:
	end
SkyAttackSetUp:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 11
	createvisualtask AnimTask_GetTargetIsAttackerPartner, 5, ARG_RET_ID
	jumpretfalse SkyAttackSetUpAgainstOpponent
	goto SkyAttackSetUpAgainstPartner
SkyAttackSetUpAgainstOpponent:
	createvisualtask sub_8116620, 10, 27, 1, 0, 12, RGB_BLACK
	waitforvisualfinish
	delay 12
	createvisualtask sub_8116620, 10, 2, 1, 8, 0, RGB_BLACK
	createvisualtask sub_81152DC, 5, 0, 2, 16
	loopsewithpan SE_W287, SOUND_PAN_ATTACKER, 4, 8
	createvisualtask sub_8116620, 10, 2, 1, 0, 15, RGB_WHITE
	delay 20
	createvisualtask sub_8116620, 10, 2, 1, 15, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 25, 1, 8, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto SkyAttackEnd
SkyAttackSetUpAgainstPartner:
	createvisualtask sub_8116664, 10, 1, 1, 0, 12, RGB_BLACK
	waitforvisualfinish
	delay 12
	createvisualtask sub_8116620, 10, 2, 1, 8, 0, RGB_BLACK
	createvisualtask sub_81152DC, 5, 0, 2, 16
	playsewithpan SE_W287, SOUND_PAN_ATTACKER
	delay 8
	createvisualtask sub_8116620, 10, 2, 1, 0, 15, RGB_WHITE
	delay 20
	createvisualtask sub_8116620, 10, 2, 1, 15, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_8116664, 10, 4, 1, 8, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto SkyAttackEnd
SkyAttackUnleash:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_BIRD
	call SetSkyBg
	monbg ANIM_ATTACKER
	createvisualtask sub_8116620, 10, 2, 0, 0, 16, RGB_WHITE
	delay 4
	createvisualtask sub_81136E8, 5, 0
	waitforvisualfinish
	createvisualtask sub_8159244, 5, 238, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596514, ANIM_TARGET, 2
	delay 14
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 10, 0, 18, 1
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	delay 20
	createvisualtask sub_81137E4, 5, 1
	delay 2
	createvisualtask sub_8116620, 10, 2, 0, 15, 0, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	call UnsetSkyBg
	goto SkyAttackEnd

Move_FLASH:
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	createvisualtask sub_8117494, 2
	waitforvisualfinish
	end

Move_SPLASH:
	createvisualtask AnimTask_Splash, 2, 0, 3
	delay 8
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 38, 3
	waitforvisualfinish
	end

Move_ACID_ARMOR:
	monbg ANIM_ATTACKER
	setalpha 15, 0
	createvisualtask AnimTask_AcidArmor, 2, ANIM_ATTACKER
	playsewithpan SE_W151, SOUND_PAN_ATTACKER
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_SHARPEN:
	loadspritegfx ANIM_TAG_SPHERE_TO_CUBE
	createsprite gUnknown_08592DE4, ANIM_ATTACKER, 2
	waitforvisualfinish
	end

Move_SUPER_FANG:
	loadspritegfx ANIM_TAG_FANG_ATTACK
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 1, 0, 20, 1
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 3, 0, 48, 1
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATTACKER, RGB(31, 6, 1), 12, 4, 1
	waitforvisualfinish
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 4
	createsprite gUnknown_08592F74, ANIM_TARGET, 2
	playsewithpan SE_W044, SOUND_PAN_TARGET
	delay 8
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB(31, 2, 2), 14, 0x7FFF, 14
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 7, 12, 1
	waitforvisualfinish
	blendoff
	end

Move_SLASH:
	loadspritegfx ANIM_TAG_SLASH
	createsprite gUnknown_08592D2C, ANIM_TARGET, 2, 1, -8, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08592D2C, ANIM_TARGET, 2, 1, 8, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_STRUGGLE:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_MOVEMENT_WAVES
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 3, 0, 12, 4
	createsprite gUnknown_08593B80, ANIM_ATTACKER, 2, 0, 0, 2
	createsprite gUnknown_08593B80, ANIM_ATTACKER, 2, 0, 1, 2
	loopsewithpan SE_W029, SOUND_PAN_ATTACKER, 12, 4
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SKETCH:
	loadspritegfx ANIM_TAG_PENCIL
	monbg ANIM_TARGET
	createvisualtask sub_8104E74, 2
	createsprite gUnknown_085936D4, ANIM_TARGET, 2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	createvisualtask AnimTask_Splash, 2, 0, 2
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 38, 2
	end

Move_NIGHTMARE:
	fadetobg BG_GHOST
	waitbgfadein
	jumpifcontest NightmareInContest
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8111C50, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 40, 1
	playsewithpan SE_W171, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end
NightmareInContest:
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATTACKER, RGB_WHITE, 10, 2, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 3, 0, 32, 1
	playsewithpan SE_W171, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_FLAIL:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_FlailMovement, 2, ANIM_ATTACKER
	loopsewithpan SE_W029, SOUND_PAN_ATTACKER, 8, 2
	waitforvisualfinish
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 3
	createvisualtask sub_80D6388, 2, 0, 1, 30, 1, 0
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SPITE:
	fadetobg BG_GHOST
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8115A04, 2, 2, 2, 6, 0, 8, RGB_WHITE
	createvisualtask sub_8111E50, 2
	loopsewithpan SE_W060, SOUND_PAN_TARGET, 20, 3
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_TARGET
	end
	
SetHighSpeedBg:
	createvisualtask AnimTask_GetAttackerSide, 2
	jumprettrue SetHighSpeedBgPlayer
	fadetobg BG_HIGHSPEED_OPPONENT
	goto SetHighSpeedBgFade
SetHighSpeedBgPlayer:
	fadetobg BG_HIGHSPEED_PLAYER
SetHighSpeedBgFade:
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 0, 1, -1
	waitbgfadein
	return
	
UnsetHighSpeedBg:
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	return

Move_MACH_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_ATK_PARTNER
	call SetHighSpeedBg
	delay 0
	setalpha 9, 8
	createvisualtask sub_80A8BC4, 2, 28968, 10
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 0, 0, 8, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	call UnsetHighSpeedBg
	end

Move_FORESIGHT:
	loadspritegfx ANIM_TAG_MAGNIFYING_GLASS
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 16, 0
	createsprite gForesightMagnifyingGlassSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET
	delay 17
	loopsewithpan SE_W166, SOUND_PAN_TARGET, 16, 4
	delay 48
	delay 24
	playsewithpan SE_W166, SOUND_PAN_TARGET
	delay 10
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_WHITE, 12, 2, 1
	playsewithpan SE_W197, SOUND_PAN_TARGET
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	end

Move_DESTINY_BOND:
	loadspritegfx ANIM_TAG_WHITE_SHADOW
	fadetobg BG_GHOST
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	waitbgfadein
	createvisualtask sub_81123C4, 5, 0, 48
	playsewithpan SE_W109, SOUND_PAN_ATTACKER
	delay 48
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 24, 1
	createvisualtask sub_8116664, 2, 6, 1, 0, 12, RGB(29, 29, 29)
	delay 24
	createvisualtask sub_8116664, 2, 6, 1, 12, 0, RGB(29, 29, 29)
	playsewithpan SE_W171, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	blendoff
	clearmonbg 5
	end

Move_ENDURE:
	loadspritegfx ANIM_TAG_FOCUS_ENERGY
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	call EndureEffect
	delay 8
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

EndureEffect:
	createsprite gUnknown_08592D8C, ANIM_ATTACKER, 2, 0, -24, 26, 2
	delay 4
	createsprite gUnknown_08592D8C, ANIM_ATTACKER, 2, 0, 14, 28, 1
	delay 4
	createsprite gUnknown_08592D8C, ANIM_ATTACKER, 2, 0, -5, 10, 2
	delay 4
	createsprite gUnknown_08592D8C, ANIM_ATTACKER, 2, 0, 28, 26, 3
	delay 4
	createsprite gUnknown_08592D8C, ANIM_ATTACKER, 2, 0, -12, 0, 1
	return

Move_CHARM:
	loadspritegfx ANIM_TAG_MAGENTA_HEART
	createvisualtask AnimTask_RockMonBackAndForth, 5, ANIM_ATTACKER, 2, 0
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 0, 20
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	delay 15
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, -20, 20
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	delay 15
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 20, 20
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	waitforvisualfinish
	end

Move_ROLLOUT:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_MUD_SAND
	loadspritegfx ANIM_TAG_ROCKS
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_8110F74, 2
	waitforvisualfinish
	createvisualtask sub_80D6388, 2, 0, 1, 30, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 1, 2
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_FALSE_SWIPE:
	loadspritegfx ANIM_TAG_SLASH_2
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gUnknown_08592D44, ANIM_TARGET, 2
	playsewithpan SE_W233, SOUND_PAN_TARGET
	delay 16
	createsprite gUnknown_08592D5C, ANIM_TARGET, 2, 0
	playsewithpan SE_W104, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08592D5C, ANIM_TARGET, 2, 16
	delay 2
	createsprite gUnknown_08592D5C, ANIM_TARGET, 2, 32
	playsewithpan SE_W104, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08592D5C, ANIM_TARGET, 2, 48
	delay 2
	createsprite gUnknown_08592D5C, ANIM_TARGET, 2, 64
	playsewithpan SE_W104, SOUND_PAN_TARGET
	delay 2
	createsprite gUnknown_08592D5C, ANIM_TARGET, 2, 80
	delay 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, 0, 0, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	end

Move_SWAGGER:
	loadspritegfx ANIM_TAG_BREATH
	loadspritegfx ANIM_TAG_ANGER
	createvisualtask AnimTask_GrowAndShrink, 2
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gBreathPuffSpriteTemplate, ANIM_ATTACKER, 2
	loopsewithpan SE_W207, SOUND_PAN_ATTACKER, 4, 2
	waitforvisualfinish
	delay 24
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, -20, -28
	playsewithpan SE_W207B, SOUND_PAN_TARGET
	delay 12
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, 20, -28
	playsewithpan SE_W207B, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_MILK_DRINK:
	loadspritegfx ANIM_TAG_MILK_BOTTLE
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_TARGET
	createsprite gUnknown_08592B3C, ANIM_ATTACKER, 2
	delay 40
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	delay 20
	playsewithpan SE_W152, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gUnknown_0859381C, ANIM_ATTACKER, 3, 0, 0, 1, 0
	playsewithpan SE_W208, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	call HealingEffect2
	waitforvisualfinish
	end

Move_MAGNITUDE:
	createvisualtask AnimTask_IsPowerOver99, 2
	waitforvisualfinish
	jumpargeq 15, FALSE, MagnitudeRegular
	jumpargeq 15, TRUE, MagnitudeIntense
MagnitudeEnd:
	end
MagnitudeRegular:
	createvisualtask sub_81152DC, 5, 5, 0, 50
	createvisualtask sub_81152DC, 5, 4, 0, 50
	loopsewithpan SE_W070, SOUND_PAN_TARGET, 8, 10
	goto MagnitudeEnd
MagnitudeIntense:
	createvisualtask sub_81152DC, 5, 5, 0, 50
	createvisualtask sub_81152DC, 5, 4, 0, 50
	loopsewithpan SE_W070, SOUND_PAN_TARGET, 8, 10
	delay 10
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	delay 16
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_BLACK, 14, 0x7FFF, 14
	goto MagnitudeEnd

Move_RAPID_SPIN:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_RAPID_SPIN
	monbg ANIM_ATTACKER
	createsprite gUnknown_085CE288, ANIM_ATTACKER, 2, 0, 0, 32, -32, 40, -2
	createvisualtask sub_815ADB0, 2, 0, 2, 0
	loopsewithpan SE_W013B, SOUND_PAN_ATTACKER, 8, 4
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 2
	createvisualtask sub_80D6388, 2, 0, 1, 10, 1, 0
	playsewithpan SE_W003, SOUND_PAN_TARGET
	waitforvisualfinish
	delay 8
	createvisualtask sub_815ADB0, 2, 0, 2, 1
	loopsewithpan SE_W013B, SOUND_PAN_ATTACKER, 8, 4
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MOONLIGHT:
	loadspritegfx ANIM_TAG_MOON
	loadspritegfx ANIM_TAG_GREEN_SPARKLE
	loadspritegfx ANIM_TAG_BLUE_STAR
	setalpha 0, 16
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08592EBC, ANIM_ATTACKER, 2, 120, 56
	createvisualtask sub_80A7A74, 3, 0, 16, 16, 0, 1
	playsewithpan SE_W236, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, -12, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, -24, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, 21, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, 0, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, ANIM_ATTACKER, 40, 10, 0
	delay 20
	createvisualtask sub_81025C0, 2
	waitforvisualfinish
	call HealingEffect
	waitforvisualfinish
	end

Move_EXTREME_SPEED:
	loadspritegfx ANIM_TAG_SPEED_DUST
	loadspritegfx ANIM_TAG_IMPACT
	call SetHighSpeedBg
	createvisualtask sub_810577C, 2
	loopsewithpan SE_W013B, SOUND_PAN_ATTACKER, 8, 3
	waitforvisualfinish
	delay 1
	createvisualtask sub_8117F60, 2
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 18
	createvisualtask sub_8105810, 2
	delay 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_85973B8, ANIM_TARGET, 2, 1, 0, -12, 3
	delay 10
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_85973B8, ANIM_TARGET, 2, 1, 0, 12, 3
	delay 10
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_85973B8, ANIM_TARGET, 2, 1, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_8105AAC, 2
	delay 10
	createvisualtask sub_810599C, 2
	loopsewithpan SE_W104, SOUND_PAN_ATTACKER, 8, 4
	waitforvisualfinish
	call UnsetHighSpeedBg
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	setarg 7, 0x1000
	delay 1
	end

Move_UPROAR:
	loadspritegfx ANIM_TAG_JAGGED_MUSIC_NOTE
	loadspritegfx ANIM_TAG_THIN_RING
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, 29, -12, 0
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, -12, -29, 1
	delay 16
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, 12, -29, 1
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, -29, -12, 0
	delay 16
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, SOUND_PAN_ATTACKER
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, 24, -24, 1
	createsprite gBattleAnimSpriteTemplate_8593BB8, ANIM_ATTACKER, 2, 0, -24, -24, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_HEAT_WAVE:
	loadspritegfx ANIM_TAG_FLYING_DIRT
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_FLYING_DIRT, 0, 6, 6, RGB_RED
	createvisualtask AnimTask_LoadSandstormBackground, 5, TRUE
	createvisualtask AnimTask_BlendBackground, 6, 6, RGB_RED
	panse_1B SE_W257, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	delay 4
	createvisualtask sub_8109DBC, 5
	delay 12
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 10, 2304, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 90, 2048, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 50, 2560, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 20, 2304, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 70, 1984, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 0, 2816, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 60, 2560, 96, 1
	end

Move_HAIL:
	loadspritegfx ANIM_TAG_HAIL
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	createvisualtask sub_8116620, 10, 1, 3, 0, 6, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_Hail1, 5
	loopsewithpan SE_W258, 0, 8, 10
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 3, 6, 0, RGB_BLACK
	end

Move_TORMENT:
	loadspritegfx ANIM_TAG_ANGER
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	createvisualtask sub_815AFF0, 2
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_TARGET, RGB_RED, 10, 1, 1
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, -20, -28
	playsewithpan SE_W207B, SOUND_PAN_TARGET
	delay 20
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, 20, -28
	playsewithpan SE_W207B, SOUND_PAN_TARGET
	end

Move_MEMENTO:
	setalpha 0, 16
	delay 1
	createvisualtask sub_81143C0, 2
	delay 1
	createvisualtask sub_8113BAC, 5
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	delay 48
	playsewithpan SE_W060B, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_8114470, 2
	delay 12
	setalpha 0, 16
	delay 1
	monbg_22 ANIM_TARGET
	createvisualtask sub_8113E78, 5
	playsewithpan SE_W060, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg_23 ANIM_TARGET
	delay 1
	blendoff
	delay 1
	end

Move_FACADE:
	loadspritegfx ANIM_TAG_SWEAT_DROP
	createvisualtask AnimTask_SquishAndSweatDroplets, 2, ANIM_ATTACKER, 3
	createvisualtask AnimTask_FacadeColorBlend, 2, ANIM_ATTACKER, 72
	loopsewithpan SE_W207, SOUND_PAN_ATTACKER, 24, 3
	end

Move_SMELLING_SALT:
	loadspritegfx ANIM_TAG_TAG_HAND
	loadspritegfx ANIM_TAG_SMELLINGSALT_EFFECT
	createsprite gSmellingSaltsHandSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET, 0, 2
	createsprite gSmellingSaltsHandSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET, 1, 2
	delay 32
	createvisualtask AnimTask_SmellingSaltsSquish, 3, ANIM_TARGET, 2
	loopsewithpan SE_W003, SOUND_PAN_TARGET, 12, 2
	waitforvisualfinish
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 6, 2
	createsprite gSmellingSaltExclamationSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET, 8, 3
	loopsewithpan SE_W207B, SOUND_PAN_TARGET, 16, 3
	end

Move_FOLLOW_ME:
	loadspritegfx ANIM_TAG_FINGER
	createsprite gUnknown_085931D4, ANIM_ATTACKER, 2, 0
	playsewithpan SE_W039, SOUND_PAN_ATTACKER
	delay 18
	playsewithpan SE_W213, SOUND_PAN_ATTACKER
	delay 71
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 22, 3
	end

Move_MAGNETIC_FLUX:
Move_CHARGE:
	loadspritegfx ANIM_TAG_ELECTRIC_ORBS
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_ELECTRICITY
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810AAFC, 2, 0, 60, 2, 12
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	delay 30
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	delay 30
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	createsprite gUnknown_0859595C, ANIM_ATTACKER, 2, 0
	delay 25
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	delay 20
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	delay 15
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	delay 10
	delay 6
	loopsewithpan SE_W268, SOUND_PAN_ATTACKER, 6, 5
	waitforvisualfinish
	createsprite gUnknown_0859598C, ANIM_ATTACKER, 2, 0, 16, 16
	delay 2
	createsprite gUnknown_0859598C, ANIM_ATTACKER, 2, 0, -16, -16
	playsewithpan SE_W085B, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 4, 4, 0, RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_TAUNT:
	loadspritegfx ANIM_TAG_FINGER_2
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	loadspritegfx ANIM_TAG_ANGER
	createsprite gUnknown_08593114, ANIM_ATTACKER, 11, 0, 45
	playsewithpan SE_W118, SOUND_PAN_ATTACKER
	delay 6
	createsprite gUnknown_0859324C, ANIM_ATTACKER, 12, 0
	delay 4
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 16, 2
	waitforvisualfinish
	delay 8
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, -20, -28
	playsewithpan SE_W207B, SOUND_PAN_TARGET
	waitforvisualfinish
	delay 12
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, 20, -28
	playsewithpan SE_W207B, SOUND_PAN_TARGET
	end

Move_HELPING_HAND:
	loadspritegfx ANIM_TAG_TAG_HAND
	createvisualtask AnimTask_HelpingHandAttackerMovement, 5
	createsprite gHelpingHandClapSpriteTemplate, ANIM_ATTACKER, 40, 0
	createsprite gHelpingHandClapSpriteTemplate, ANIM_ATTACKER, 40, 1
	delay 19
	playsewithpan SE_W227, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 2, 0, 5, 1
	delay 14
	playsewithpan SE_W227, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 2, 0, 5, 1
	delay 20
	playsewithpan SE_W227, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 3, 0, 10, 1
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATK_PARTNER, RGB_YELLOW, 12, 1, 1
	end

Move_ASSIST:
	loadspritegfx ANIM_TAG_PAW_PRINT
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, 112, -16, 140, 128, 36
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, 208, 128, -16, 48, 36
	playsewithpan SE_W010, 0
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, -16, 112, 256, -16, 36
	playsewithpan SE_W010, 0
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, 108, 128, 84, -16, 36
	playsewithpan SE_W010, 0
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, -16, 56, 256, 56, 36
	playsewithpan SE_W010, 0
	end

Move_SUPERPOWER:
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_METEOR
	loadspritegfx ANIM_TAG_FLAT_ROCK
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 12, 8
	createsprite gUnknown_08595FEC, ANIM_TARGET, 2, 0
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	delay 20
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, 4, 1, 180, 1
	createvisualtask sub_8159244, 5, 234, 0
	delay 40
	createsprite gUnknown_08596004, ANIM_ATTACKER, 41, 200, 96, 1, 120
	delay 8
	createsprite gUnknown_08596004, ANIM_ATTACKER, 41, 20, 248, 4, 112
	delay 8
	createsprite gUnknown_08596004, ANIM_ATTACKER, 41, 130, 160, 2, 104
	delay 8
	createsprite gUnknown_08596004, ANIM_ATTACKER, 41, 160, 192, 0, 96
	delay 8
	createsprite gUnknown_08596004, ANIM_ATTACKER, 41, 60, 288, 3, 88
	delay 74
	createsprite gUnknown_0859601C, ANIM_TARGET, 3, 0
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	delay 16
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_RECYCLE:
	loadspritegfx ANIM_TAG_RECYCLE
	monbg ANIM_ATTACKER
	setalpha 0, 16
	delay 1
	createsprite gRecycleSpriteTemplate, ANIM_ATTACKER, 2
	loopsewithpan SE_W036, SOUND_PAN_ATTACKER, 24, 3
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB_WHITE, 12, 2, 1
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_BRICK_BREAK:
	loadspritegfx ANIM_TAG_BLUE_LIGHT_WALL
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_TORN_METAL
	choosetwoturnanim BrickBreakNormal, BrickBreakShatteredWall
BrickBreakNormal:
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 4
	delay 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -18, -18, 1, 1
	playsewithpan SE_W233, SOUND_PAN_TARGET
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 18, 18, 1, 1
	playsewithpan SE_W233, SOUND_PAN_TARGET
	delay 20
	createvisualtask AnimTask_WindUpLunge, 2, ANIM_ATTACKER, -24, 0, 24, 10, 24, 3
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 6, RGB_BLACK
	delay 37
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 10, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 6, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end
BrickBreakShatteredWall:
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 4
	createsprite gUnknown_08595F90, ANIM_ATTACKER, 3, 1, 0, 0, 90, 10
	delay 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -18, -18, 1, 1
	playsewithpan SE_W233, SOUND_PAN_TARGET
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 18, 18, 1, 1
	playsewithpan SE_W233, SOUND_PAN_TARGET
	delay 20
	createvisualtask AnimTask_WindUpLunge, 2, ANIM_ATTACKER, -24, 0, 24, 10, 24, 3
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 6, RGB_BLACK
	delay 37
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 10, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gUnknown_08595FA8, ANIM_ATTACKER, 2, 1, 0, -8, -12
	createsprite gUnknown_08595FA8, ANIM_ATTACKER, 2, 1, 1, 8, -12
	createsprite gUnknown_08595FA8, ANIM_ATTACKER, 2, 1, 2, -8, 12
	createsprite gUnknown_08595FA8, ANIM_ATTACKER, 2, 1, 3, 8, 12
	playsewithpan SE_W280, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 6, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_YAWN:
	loadspritegfx ANIM_TAG_PINK_CLOUD
	createvisualtask AnimTask_DeepInhale, 2, ANIM_ATTACKER
	playsewithpan SE_W281, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gYawnCloudSpriteTemplate, ANIM_TARGET, 5, 2
	playsewithpan SE_W255, SOUND_PAN_ATTACKER
	delay 4
	createsprite gYawnCloudSpriteTemplate, ANIM_TARGET, 5, 1
	delay 4
	createsprite gYawnCloudSpriteTemplate, ANIM_TARGET, 5, 0
	waitforvisualfinish
	createvisualtask AnimTask_DeepInhale, 2, ANIM_TARGET
	playsewithpan SE_W281, SOUND_PAN_TARGET
	end

Move_ENDEAVOR:
	loadspritegfx ANIM_TAG_SWEAT_DROP
	loadspritegfx ANIM_TAG_IMPACT
	createvisualtask AnimTask_SquishAndSweatDroplets, 2, ANIM_ATTACKER, 2
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 24, 2
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(31, 21, 0), 12, 1, 2
	delay 6
	createvisualtask sub_80D6388, 5, 0, 1, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 12, -12, 1, 2
	playsewithpan SE_W003, SOUND_PAN_TARGET
	delay 24
	createvisualtask sub_80D6388, 5, 0, 1, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -12, 12, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	end

Move_ERUPTION:
	loadspritegfx ANIM_TAG_WARM_ROCK
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 2, 0, 4, RGB_RED
	waitforvisualfinish
	createvisualtask sub_8109460, 2
	waitplaysewithpan SE_W153, SOUND_PAN_ATTACKER, 60
	waitforvisualfinish
	createvisualtask sub_8109460, 2
	waitplaysewithpan SE_W153, SOUND_PAN_ATTACKER, 60
	waitforvisualfinish
	delay 30
	createsprite gUnknown_085955E8, ANIM_ATTACKER, 40, 200, -32, 0, 100, 0
	createsprite gUnknown_085955E8, ANIM_ATTACKER, 40, 30, -32, 16, 90, 1
	createsprite gUnknown_085955E8, ANIM_ATTACKER, 40, 150, -32, 32, 60, 2
	createsprite gUnknown_085955E8, ANIM_ATTACKER, 40, 90, -32, 48, 80, 3
	createsprite gUnknown_085955E8, ANIM_ATTACKER, 40, 110, -32, 64, 50, 0
	createsprite gUnknown_085955E8, ANIM_ATTACKER, 40, 60, -32, 80, 70, 1
	delay 22
	createvisualtask sub_81152DC, 5, 5, 8, 60
	createvisualtask sub_81152DC, 5, 4, 8, 60
	loopsewithpan SE_W088, SOUND_PAN_TARGET, 16, 12
	delay 80
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 40, 31, 4, 4, 0, RGB_RED
	end

Move_SKILL_SWAP:
	loadspritegfx ANIM_TAG_BLUEGREEN_ORB
	call SetPsychicBackground
	createvisualtask sub_810FBF0, 3, 1
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_WHITE, 12, 3, 1
	loopsewithpan SE_W179, SOUND_PAN_ATTACKER, 24, 3
	delay 16
	createvisualtask sub_810FBF0, 3, 0
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB_WHITE, 12, 3, 1
	waitforvisualfinish
	call UnsetPsychicBg
	end

Move_IMPRISON:
	loadspritegfx ANIM_TAG_HOLLOW_ORB
	loadspritegfx ANIM_TAG_X_SIGN
	call SetPsychicBackground
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_810F940, 5
	delay 8
	loopsewithpan SE_W030, SOUND_PAN_ATTACKER, 8, 5
	waitforvisualfinish
	delay 4
	createsprite gUnknown_085967AC, ANIM_ATTACKER, 5, 0, 40
	createvisualtask sub_81152DC, 5, 4, 1, 10
	playsewithpan SE_W063, SOUND_PAN_ATTACKER
	clearmonbg ANIM_DEF_PARTNER
	call UnsetPsychicBg
	end

Move_GRUDGE:
	loadspritegfx ANIM_TAG_PURPLE_FLAME
	monbg ANIM_ATTACKER
	monbgprio_29
	fadetobg BG_GHOST
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	waitbgfadein
	createvisualtask sub_8112C6C, 3
	loopsewithpan SE_W052, SOUND_PAN_ATTACKER, 16, 4
	delay 10
	delay 80
	playsewithpan SE_W171, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_ATTACKER
	end

Move_CAMOUFLAGE:
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 16, 0
	createvisualtask AnimTask_SetCamouflageBlend, 5, 2, 3, 0, 14
	delay 16
	createvisualtask sub_81136E8, 2, 4
	playsewithpan SE_W185, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 8
	createvisualtask AnimTask_SetCamouflageBlend, 5, 2, 0, 0, 0
	waitforvisualfinish
	createvisualtask sub_81137E4, 2, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATK_PARTNER
	end

Move_TAIL_GLOW:
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08596AC8, ANIM_ATTACKER, 66, 0
	delay 18
	loopsewithpan SE_W234, SOUND_PAN_ATTACKER, 16, 6
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 4, 4, 0, RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	end

Move_LUSTER_PURGE:
	loadspritegfx ANIM_TAG_WHITE_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_IMPACT
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A5C8, 5
	waitbgfadein
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W076, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596898, ANIM_ATTACKER, 41, 0, 0, 0, 0
	delay 20
	createvisualtask sub_8116664, 5, 5, 2, 0, 16, RGB_WHITEALPHA
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT, 2, 0, 16, RGB_WHITEALPHA
	waitforvisualfinish
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_IMPACT, 0, 12, 12, RGB(0, 0, 23)
	waitforvisualfinish
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 2
	createvisualtask sub_8159210, 5, 215, SOUND_PAN_TARGET
	delay 3
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 2
	createvisualtask sub_8159210, 5, 215, SOUND_PAN_TARGET
	delay 3
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 2
	createvisualtask sub_8159210, 5, 215, SOUND_PAN_TARGET
	delay 3
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 2
	createvisualtask sub_8159210, 5, 215, SOUND_PAN_TARGET
	delay 3
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 2
	createvisualtask sub_8159210, 5, 215, SOUND_PAN_TARGET
	delay 3
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 2
	createvisualtask sub_8159210, 5, 215, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_8116664, 5, 5, 2, 16, 0, RGB_WHITEALPHA
	createvisualtask sub_81152DC, 5, 1, 5, 14
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	call UnsetPsychicBg
	end

Move_MIST_BALL:
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_WHITE_FEATHER
	delay 0
	playsewithpan SE_W081, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C70, ANIM_TARGET, 0, 0, 0, 0, 0, 30, 0
	waitforvisualfinish
	playsewithpan SE_W028, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 10, 0
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 1, 1, RGB(23, 16, 31), 16, 0x7FFF, 16
	delay 0
	playsewithpan SE_W114, 0
	createvisualtask AnimTask_LoadMistTiles, 5
	createvisualtask sub_8116620, 10, 4, 3, 0, 16, RGB_WHITE
	delay 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 70, 0
	delay 70
	createvisualtask sub_8116620, 10, 4, 2, 16, 0, RGB_WHITE
	end

Move_FEATHER_DANCE:
	loadspritegfx ANIM_TAG_WHITE_FEATHER
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	playsewithpan SE_W080, SOUND_PAN_TARGET
	delay 0
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 64, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 32, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 0, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 224, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 128, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 192, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 160, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, ANIM_TARGET, 0, 0, -16, 96, 2, 104, 11304, 32, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_TEETER_DANCE:
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	loadspritegfx ANIM_TAG_DUCK
	createvisualtask AnimTask_TeeterDanceMovement, 5
	createsprite gUnknown_08593050, ANIM_ATTACKER, 2, 0, 16, -2
	playsewithpan SE_W298, SOUND_PAN_ATTACKER
	delay 24
	createsprite gUnknown_08593050, ANIM_ATTACKER, 2, 0, 0, -2
	playsewithpan SE_W298, SOUND_PAN_ATTACKER
	delay 24
	createsprite gUnknown_08593050, ANIM_ATTACKER, 2, 0, -16, -2
	playsewithpan SE_W298, SOUND_PAN_ATTACKER
	delay 24
	createsprite gUnknown_08593050, ANIM_ATTACKER, 2, 1, -8, -2
	playsewithpan SE_W298, SOUND_PAN_ATTACKER
	delay 24
	createsprite gUnknown_08593050, ANIM_ATTACKER, 2, 2, 8, -2
	playsewithpan SE_W298, SOUND_PAN_ATTACKER
	end

Move_MUD_SPORT:
	loadspritegfx ANIM_TAG_MUD_SAND
	createvisualtask AnimTask_Splash, 2, 0, 6
	delay 24
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 0, -4, -16
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 0, 4, -12
	playsewithpan SE_W091, SOUND_PAN_ATTACKER
	delay 32
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 0, -3, -12
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 0, 5, -14
	playsewithpan SE_W091, SOUND_PAN_ATTACKER
	delay 32
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 0, -5, -18
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 0, 3, -14
	playsewithpan SE_W091, SOUND_PAN_ATTACKER
	delay 16
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 220, 60
	waitplaysewithpan SE_W145B, 0, 15
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 60, 100
	waitplaysewithpan SE_W145B, 0, 25
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 140, 55
	waitplaysewithpan SE_W145B, 0, 14
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 180, 50
	waitplaysewithpan SE_W145B, 0, 10
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 20, 90
	waitplaysewithpan SE_W145B, 0, 22
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 90, 90
	waitplaysewithpan SE_W145B, 0, 22
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 160, 60
	waitplaysewithpan SE_W145B, 0, 15
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 30, 90
	waitplaysewithpan SE_W145B, 0, 22
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 120, 60
	waitplaysewithpan SE_W145B, 0, 15
	delay 2
	createsprite gUnknown_085971E4, ANIM_TARGET, 2, 1, 200, 40
	waitplaysewithpan SE_W145B, 0, 10
	end

Move_NEEDLE_ARM:
	loadspritegfx ANIM_TAG_GREEN_SPIKE
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loopsewithpan SE_W030, SOUND_PAN_TARGET, 2, 16
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 0, -32, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 22, -22, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 30, 0, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 20, 20, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 0, 28, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, -19, 19, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, -27, 0, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, -18, -18, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 0, -25, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 17, -17, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 23, 0, 16
	delay 2
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 0, 16, 16, 16
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, 0, -24, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, 17, -17, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, 24, 0, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, 17, 17, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, 0, 24, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, -17, 17, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, -24, 0, 10
	createsprite gUnknown_08592888, ANIM_TARGET, 2, 1, 1, -17, -17, 10
	end

Move_SLACK_OFF:
	loadspritegfx ANIM_TAG_BLUE_STAR
	createvisualtask AnimTask_SlackOffSquish, 2, ANIM_ATTACKER
	playsewithpan SE_W281, SOUND_PAN_ATTACKER
	waitforvisualfinish
	call HealingEffect
	waitforvisualfinish
	end

Move_CRUSH_CLAW:
	loadspritegfx ANIM_TAG_BLUE_LIGHT_WALL
	loadspritegfx ANIM_TAG_CLAW_SLASH
	loadspritegfx ANIM_TAG_TORN_METAL
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 18, 1
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, -10, -10, 0
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, -10, 10, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	delay 12
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, 10, -10, 1
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, 10, 10, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_TARGET
	end

Move_AROMATHERAPY:
	playsewithpan SE_W080, 0
	loadspritegfx ANIM_TAG_FLOWER
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_SPARKLE_2
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 0, 0, 7, RGB(13, 31, 12)
	delay 1
	monbg ANIM_ATTACKER
	delay 1
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 0, 24, 16, 0, 2, 2, 0, 0
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 66, 64, 24, 0, 3, 1, 1, 0
	createsprite gUnknown_085927C4, ANIM_ATTACKER, 0, 16, 24, 0, 2, 1, 0, 0
	delay 20
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 66, 48, 12, 0, 4, 3, 1, 0
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 0, 100, 16, 0, 3, 2, 0, 0
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 0, 74, 24, 180, 3, 2, 0, 0
	delay 10
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 66, 80, 30, 0, 4, 1, 1, 0
	createsprite gUnknown_085927AC, ANIM_ATTACKER, 0, 128, 12, 0, 3, 3, 0, 0
	createsprite gUnknown_085927C4, ANIM_ATTACKER, 0, 90, 16, 0, 2, 1, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 0, 7, 0, RGB(13, 31, 12)
	delay 1
	playsewithpan SE_W287, SOUND_PAN_ATTACKER
	createvisualtask sub_815DFCC, 2, 1
	waitforvisualfinish
	playsewithpan SE_W234, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592B94, ANIM_ATTACKER, 16, -15, 0, 0, 0, 32, 60, 1
	delay 8
	createsprite gUnknown_08592B94, ANIM_ATTACKER, 16, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	playsewithpan SE_REAPOKE, SOUND_PAN_ATTACKER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 43, 3, 10, 0, RGB(13, 31, 12)
	createsprite gUnknown_08593868, ANIM_ATTACKER, 16, 0, 0, 0, 1
	waitforvisualfinish
	end

Move_FAKE_TEARS:
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_SMALL_BUBBLES, 0, 4, 4, RGB(12, 11, 31)
	waitforvisualfinish
	createvisualtask AnimTask_RockMonBackAndForth, 5, ANIM_ATTACKER, 2, 1
	loopsewithpan SE_W039, SOUND_PAN_ATTACKER, 12, 4
	delay 8
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 0
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 1
	delay 8
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 2
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 3
	delay 8
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 0
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 1
	delay 8
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 2
	createsprite gUnknown_085970E8, ANIM_ATTACKER, 2, 0, 3
	waitforvisualfinish
	end

Move_AIR_CUTTER:
	loadspritegfx ANIM_TAG_AIR_WAVE
	loadspritegfx ANIM_TAG_CUT
	loadspritegfx ANIM_TAG_IMPACT
	delay 0
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 0
	createvisualtask sub_8103CF0, 2, 32, -24, 1536, 2, 128
	waitforvisualfinish
	playsewithpan SE_W015, SOUND_PAN_TARGET
	createsprite gUnknown_08592A34, ANIM_ATTACKER, 2, 40, -32, 0, 2
	delay 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 8, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	end

Move_ODOR_SLEUTH:
	monbg ANIM_TARGET
	createvisualtask AnimTask_OdorSleuthMovement, 5
	delay 24
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 4
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	delay 6
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 4
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	delay 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 1, RGB_WHITEALPHA, 16, -1, 0
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	end

Move_GRASS_WHISTLE:
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 4, RGB(18, 31, 12)
	waitforvisualfinish
	createvisualtask sub_8102BE8, 2
	waitforvisualfinish
	panse_1B SE_W320, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 7, 1, 0
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 6, 1, 0
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 1, 1, 0
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 1, 0
	delay 5
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 3, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 5, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 6, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 2, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 1, 1, 0
	delay 4
	createsprite gUnknown_08593008, ANIM_TARGET, 2, 5, 1, 0
	delay 4
	waitforvisualfinish
	createvisualtask sub_8102CA0, 2
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 4, 4, 0, RGB(18, 31, 12)
	waitforvisualfinish
	end

Move_TICKLE:
	loadspritegfx ANIM_TAG_EYE_SPARKLE
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08593A84, ANIM_ATTACKER, 0, -16, -8
	createsprite gUnknown_08593A84, ANIM_ATTACKER, 0, 16, -8
	playsewithpan SE_W197, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 0, 16, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	createvisualtask AnimTask_SwayMon, 3, 0, 6, 1280, 3, ANIM_ATTACKER
	delay 12
	createvisualtask AnimTask_RockMonBackAndForth, 3, ANIM_TARGET, 6, 2
	loopsewithpan SE_W039, SOUND_PAN_TARGET, 8, 8
	waitforvisualfinish
	end

Move_WATER_SPOUT:
	loadspritegfx ANIM_TAG_GLOWY_BLUE_ORB
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask sub_81080E4, 5
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	delay 44
	playsewithpan SE_W291, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 16
	createvisualtask sub_81085C8, 5
	playsewithpan SE_W057, SOUND_PAN_TARGET
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SHADOW_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	fadetobg BG_GHOST
	waitbgfadein
	monbg ANIM_ATK_PARTNER
	setalpha 9, 8
	createvisualtask sub_80A8BC4, 2, 0, 13
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 0, 0, 8, 1, 0
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_EXTRASENSORY:
	call SetPsychicBackground
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(27, 27, 0), 12, 1, 1
	createvisualtask sub_810FE14, 5, 0
	playsewithpan SE_W020, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(27, 27, 0), 12, 1, 1
	createvisualtask sub_810FE14, 5, 1
	playsewithpan SE_W020, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_8110034, 5, 0
	createvisualtask sub_810FE14, 5, 2
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	call UnsetPsychicBg
	end

Move_AERIAL_ACE:
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask sub_81169C0, 2, 0, 4, 7, 3
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 10, 0, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_IRON_DEFENSE:
	loopsewithpan SE_REAPOKE, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 0, 0, 0
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 8, 2, RGB_WHITEALPHA, 14, -1, 0
	waitforvisualfinish
	end

Move_BLOCK:
	loadspritegfx ANIM_TAG_X_SIGN
	createsprite gBlockXSpriteTemplate, ANIM_TARGET, 66
	playsewithpan SE_W207, SOUND_PAN_TARGET
	end

Move_HOWL:
	loadspritegfx ANIM_TAG_NOISE_LINE
	createvisualtask AnimTask_DeepInhale, 2, 0
	delay 12
	call RoarEffect
	createvisualtask sub_8158D8C, 2, 0, 3
	waitforvisualfinish
	delay 30
	end

Move_BULK_UP:
	loadspritegfx ANIM_TAG_BREATH
	createvisualtask AnimTask_GrowAndShrink, 2
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gBreathPuffSpriteTemplate, ANIM_ATTACKER, 2
	loopsewithpan SE_W207, SOUND_PAN_ATTACKER, 4, 2
	waitforvisualfinish
	end

Move_COVET:
	loadspritegfx ANIM_TAG_MAGENTA_HEART
	loadspritegfx ANIM_TAG_ITEM_BAG
	createvisualtask AnimTask_RockMonBackAndForth, 5, ANIM_ATTACKER, 2, 0
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 0, 20
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	delay 15
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, -20, 20
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	delay 15
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 20, 20
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	loopsewithpan SE_W146, SOUND_PAN_TARGET, 4, 3
	end

Move_VOLT_TACKLE:
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_ELECTRICITY
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createvisualtask sub_8116620, 10, 1, 0, 0, 8, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_085959A4, ANIM_ATTACKER, 1
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 8
	createvisualtask sub_810AFCC, 5, 0
	playsewithpan SE_W085, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 1
	playsewithpan SE_W085, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 2
	playsewithpan SE_W085, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 3
	playsewithpan SE_W085, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 4
	playsewithpan SE_W085, SOUND_PAN_ATTACKER
	delay 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 10, 0, 18, 1
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gUnknown_0859598C, ANIM_ATTACKER, 2, 1, 16, 16
	delay 2
	createsprite gUnknown_0859598C, ANIM_ATTACKER, 2, 1, -16, -16
	delay 8
	createvisualtask sub_810AE5C, 5
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 3, 0, 9, 1
	playsewithpan SE_W085B, SOUND_PAN_ATTACKER
	createsprite gUnknown_0859598C, ANIM_ATTACKER, 2, 0, 16, 16
	delay 2
	createsprite gUnknown_0859598C, ANIM_ATTACKER, 2, 0, -16, -16
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 0, 8, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_WATER_SPORT:
	loadspritegfx ANIM_TAG_GLOWY_BLUE_ORB
	createvisualtask sub_81088E4, 5
	delay 8
	playsewithpan SE_W057, SOUND_PAN_ATTACKER
	delay 44
	playsewithpan SE_W057, SOUND_PAN_ATTACKER
	delay 44
	playsewithpan SE_W057, SOUND_PAN_ATTACKER
	delay 44
	panse_1B SE_W057, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	end

Move_CALM_MIND:
	loadspritegfx ANIM_TAG_THIN_RING
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8116664, 5, 0, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_81177E4, 5, 1
	waitforvisualfinish
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, SOUND_PAN_ATTACKER
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, SOUND_PAN_ATTACKER
	delay 14
	createsprite gUnknown_08593850, ANIM_ATTACKER, 40, 0, 0, 0, 0
	playsewithpan SE_W048, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_81177E4, 5, 0
	waitforvisualfinish
	createvisualtask sub_8116664, 5, 0, 0, 16, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_LEAF_BLADE:
	loadspritegfx ANIM_TAG_LEAF
	loadspritegfx ANIM_TAG_CROSS_IMPACT
	createvisualtask sub_80FFFC0, 5
	delay 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W015, SOUND_PAN_TARGET
	delay 50
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W015, SOUND_PAN_TARGET
	delay 50
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W015, SOUND_PAN_TARGET
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 12
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 18, 1
	createsprite gUnknown_085973D0, ANIM_TARGET, 2, 0, 0, 1, 36
	playsewithpan SE_W043, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DRAGON_DANCE:
	loadspritegfx ANIM_TAG_HOLLOW_ORB
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	delay 1
	createvisualtask sub_81133E8, 5
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	delay 8
	createvisualtask sub_80A7CB4, 5, 10249, 19456, 14, 0, 3
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 0
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 43
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 85
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 128
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 170
	createsprite gUnknown_08596F98, ANIM_ATTACKER, 2, 213
	delay 30
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	delay 30
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_SHOCK_WAVE:
	loadspritegfx ANIM_TAG_ELECTRIC_ORBS
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_LIGHTNING
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810AAFC, 2, 0, 20, 0, 2
	playsewithpan SE_W268, SOUND_PAN_ATTACKER
	delay 12
	createsprite gUnknown_08595A18, ANIM_ATTACKER, 2
	delay 30
	createvisualtask sub_810B29C, 5, ANIM_TARGET
	delay 12
	waitforvisualfinish
	createvisualtask sub_810B55C, 5, ANIM_TARGET
	playsewithpan SE_W161B, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 6, 18, 1
	createvisualtask sub_8116620, 5, 1, 3, 16, 0, RGB_WHITE
	createvisualtask sub_8116620, 5, 4, 0, 16, 16, RGB_BLACK
	delay 4
	createvisualtask sub_8116620, 5, 4, 0, 0, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_HARDEN:
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 0, 0, 0
	waitforvisualfinish
	end

Move_BELLY_DRUM:
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	loadspritegfx ANIM_TAG_PURPLE_HAND_OUTLINE
	createvisualtask sub_8102BE8, 2
	waitforvisualfinish
	call BellyDrum1
	createsprite gUnknown_0859309C, ANIM_ATTACKER, 2, 0, 0, 0, 0
	playsewithpan SE_W187, SOUND_PAN_ATTACKER
	delay 15
	call BellyDrum2
	createsprite gUnknown_0859309C, ANIM_ATTACKER, 2, 1, 1, 1, 0
	playsewithpan SE_W187, SOUND_PAN_ATTACKER
	delay 15
	call BellyDrum1
	createsprite gUnknown_0859309C, ANIM_ATTACKER, 2, 0, 3, 3, 128
	playsewithpan SE_W187, SOUND_PAN_ATTACKER
	delay 7
	call BellyDrum2
	createsprite gUnknown_0859309C, ANIM_ATTACKER, 2, 1, 2, 0, 128
	playsewithpan SE_W187, SOUND_PAN_ATTACKER
	delay 7
	call BellyDrum1
	createsprite gUnknown_0859309C, ANIM_ATTACKER, 2, 0, 1, 1, 0
	playsewithpan SE_W187, SOUND_PAN_ATTACKER
	delay 7
	call BellyDrum2
	createsprite gUnknown_0859309C, ANIM_ATTACKER, 2, 1, 0, 3, 0
	playsewithpan SE_W187, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask sub_8102CA0, 2
	waitforvisualfinish
	end

BellyDrum2:
	createsprite gUnknown_08593068, ANIM_ATTACKER, 3, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 8, 2, 1
	return

BellyDrum1:
	createsprite gUnknown_08593068, ANIM_ATTACKER, 3, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 8, 2, 1
	return

Move_MIND_READER:
	loadspritegfx ANIM_TAG_TEAL_ALERT
	loadspritegfx ANIM_TAG_OPENING_EYE
	loadspritegfx ANIM_TAG_ROUND_WHITE_HALO
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W109, SOUND_PAN_TARGET
	createsprite gUnknown_085CE07C, ANIM_ATTACKER, 5, 0, 0, 1, 0
	createsprite gUnknown_085CE094, ANIM_ATTACKER, 5
	delay 40
	playsewithpan SE_W043, SOUND_PAN_TARGET
	createvisualtask sub_8115A04, 2, 1, 1, 2, 0, 10, RGB_BLACK
	call MindReaderEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

MindReaderEffect:
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 70, 0, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 40, 40, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 10, -60, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -50, -40, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -40, 40, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 50, -50, 6
	delay 2
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 50, -30, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 60, 10, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 0, 60, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 0, -40, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -60, 20, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -60, -30, 6
	delay 2
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -50, 50, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -60, 20, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, -40, -40, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 20, -60, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 50, -50, 6
	createsprite gUnknown_085CE0AC, ANIM_ATTACKER, 4, 35, 40, 6
	delay 2
	return

Move_ICE_PUNCH:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 7, RGB_BLACK
	createvisualtask sub_8116620, 10, 4, 2, 0, 9, RGB(12, 26, 31)
	delay 20
	playsewithpan SE_W081, SOUND_PAN_TARGET
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 0
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 64
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 128
	createsprite gUnknown_08595AE8, ANIM_ATTACKER, 2, 192
	delay 5
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 32
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 96
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 160
	createsprite gUnknown_08595AD0, ANIM_ATTACKER, 2, 224
	delay 17
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 4, 0, -10, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, -10, 1, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 3, 1
	waitforvisualfinish
	delay 15
	call FreezeEffect1
	delay 5
	createvisualtask sub_8116620, 10, 4, 2, 9, 0, RGB(12, 26, 31)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_REST:
	playsewithpan SE_W173, SOUND_PAN_ATTACKER
	loadspritegfx ANIM_TAG_LETTER_Z
	createsprite gUnknown_08592C88, ANIM_ATTACKER, 2, 4, -10, 16, 0, 0
	delay 20
	createsprite gUnknown_08592C88, ANIM_ATTACKER, 2, 4, -10, 16, 0, 0
	delay 20
	createsprite gUnknown_08592C88, ANIM_ATTACKER, 2, 4, -10, 16, 0, 0
	waitforvisualfinish
	end

Move_CONFUSION:
	monbg ANIM_DEF_PARTNER
	call SetPsychicBackground
	setalpha 8, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 10, 1
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB_WHITE
	waitforvisualfinish
	playsewithpan SE_W048, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -4, -4, 15, ANIM_TARGET, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 1
	call UnsetPsychicBg
	end

Move_PSYCHIC:
	monbg ANIM_DEF_PARTNER
	call SetPsychicBackground
	setalpha 8, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 10, 1
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB(31, 23, 0)
	waitforvisualfinish
	loopsewithpan SE_W048, SOUND_PAN_TARGET, 10, 3
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -6, -6, 15, ANIM_TARGET, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 1
	call UnsetPsychicBg
	end

Move_FUTURE_SIGHT:
	goto FutureSight
FutureSightContinue:
	waitforvisualfinish
	delay 1
	call UnsetPsychicBg
	end
FutureSight:
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	setalpha 8, 8
	playsewithpan SE_W048, SOUND_PAN_ATTACKER
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB_WHITE
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -4, -4, 15, ANIM_ATTACKER, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	goto FutureSightContinue

Move_THUNDER:
	loadspritegfx ANIM_TAG_LIGHTNING
	fadetobg BG_THUNDER
	waitbgfadeout
	createvisualtask sub_8117660, 5, -256, 0, 1, -1
	waitbgfadein
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 16, RGB_BLACK
	delay 16
	createvisualtask sub_8115F10, 2, 257, 257, 257
	playsewithpan SE_W086, SOUND_PAN_TARGET
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 16, -36
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 16, -20
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 16, 12
	delay 20
	createsprite gUnknown_085956C0, ANIM_TARGET, 6, -16, -32
	playsewithpan SE_W086, SOUND_PAN_TARGET
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 6, -16, -16
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 6, -16, 16
	playsewithpan SE_W086, SOUND_PAN_TARGET
	delay 5
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 24, -32
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 24, -16
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 24, 16
	delay 30
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 5
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, -32
	playsewithpan SE_W161B, SOUND_PAN_TARGET
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, -16
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, 16
	delay 10
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createvisualtask sub_810A094, 2, 30, 3, 1, 0
	delay 2
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_TARGET, 2, 1, 2, 16, 0, RGB_BLACK
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	end

Move_THUNDER_PUNCH:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_LIGHTNING
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 16, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 0, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	delay 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, -48
	delay 1
	createsprite gUnknown_085956C0, ANIM_ATTACKER, 2, 0, -16
	delay 1
	createsprite gUnknown_085956C0, ANIM_ATTACKER, 2, 0, 16
	delay 1
	playsewithpan SE_W161B, SOUND_PAN_TARGET
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 15, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 16, 0, RGB_BLACK
	delay 20
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SACRED_FIRE:
	loadspritegfx ANIM_TAG_FIRE
	loadspritegfx ANIM_TAG_FIRE_PLUME
	loopsewithpan SE_W221, SOUND_PAN_ATTACKER, 7, 5
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -32, 0, 50, 5, -2, 0
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, -20, -10, 50, 5, -1, -1
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 0, -16, 50, 5, 0, -1
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 20, -10, 50, 5, 1, -1
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, 32, 0, 50, 5, 2, 0
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, 20, 10, 50, 5, 1, 1
	delay 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, 0, 16, 50, 5, 0, 1
	delay 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -20, 10, 50, 5, -1, 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	waitforvisualfinish
	playsewithpan SE_W221B, SOUND_PAN_TARGET
	createsprite gUnknown_085953F8, ANIM_TARGET, 2, -16, 0, 70, 16, 0, 1
	delay 10
	playsewithpan SE_W221B, SOUND_PAN_TARGET
	createsprite gUnknown_085953F8, ANIM_TARGET, 2, 0, 0, 70, 16, 0, 1
	delay 10
	playsewithpan SE_W221B, SOUND_PAN_TARGET
	createsprite gUnknown_085953F8, ANIM_TARGET, 2, 16, 0, 80, 16, 0, 1
	delay 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	waitforvisualfinish
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	playsewithpan SE_W172B, SOUND_PAN_TARGET
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, -1, 0
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 0, 1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, -1, -1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 2, 1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 1, -1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, -1, 1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 1, -2
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 3, 1
	waitforvisualfinish
	end

Move_SCRATCH:
	loadspritegfx ANIM_TAG_SCRATCH
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W010, SOUND_PAN_TARGET
	createsprite gUnknown_085CE020, ANIM_ATTACKER, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_DRAGON_BREATH:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W172, SOUND_PAN_ATTACKER, 7, 7
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createvisualtask sub_8116620, 10, 4, 1, 0, 9, RGB_RED
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 21, 1
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, ANIM_TARGET, 2, 0, 0, 0, 0, 20
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 1, 9, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_ROAR:
	loadspritegfx ANIM_TAG_NOISE_LINE
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	setalpha 8, 8
	createvisualtask sub_8158E9C, 2, 0, 2
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	call RoarEffect
	delay 20
	createvisualtask sub_80D5DB0, 5, 1, 2
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	waitforvisualfinish
	createvisualtask sub_8159078, 5
	waitforvisualfinish
	end

RoarEffect:
	createsprite gRoarNoiseLineSpriteTemplate, ANIM_ATTACKER, 2, 24, -8, 0
	createsprite gRoarNoiseLineSpriteTemplate, ANIM_ATTACKER, 2, 24, 0, 2
	createsprite gRoarNoiseLineSpriteTemplate, ANIM_ATTACKER, 2, 24, 8, 1
	delay 15
	createsprite gRoarNoiseLineSpriteTemplate, ANIM_ATTACKER, 2, 24, -8, 0
	createsprite gRoarNoiseLineSpriteTemplate, ANIM_ATTACKER, 2, 24, 0, 2
	createsprite gRoarNoiseLineSpriteTemplate, ANIM_ATTACKER, 2, 24, 8, 1
	return

Move_GROWL:
	loadspritegfx ANIM_TAG_NOISE_LINE
	createvisualtask sub_8158E9C, 2, 0, 255
	call RoarEffect
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 9, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 9, 1
	waitforvisualfinish
	createvisualtask sub_8159078, 5
	waitforvisualfinish
	end

Move_SNORE:
	loadspritegfx ANIM_TAG_SNORE_Z
	monbg ANIM_ATK_PARTNER
	setalpha 8, 8
	call Snore1
	delay 30
	call Snore1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end
Snore1:
	playsewithpan SE_W173, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 7, ANIM_ATTACKER, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 7, 1
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, 6, 1, 14, 0, 0
	createsprite gUnknown_085936EC, ANIM_ATTACKER, 2, 0, 0, -42, -38, 24, 0, 0
	createsprite gUnknown_085936EC, ANIM_ATTACKER, 2, 0, 0, 0, -42, 24, 0, 0
	createsprite gUnknown_085936EC, ANIM_ATTACKER, 2, 0, 0, 42, -38, 24, 0, 0
	return

Move_LIGHT_SCREEN:
	loadspritegfx ANIM_TAG_SPARKLE_3
	loadspritegfx ANIM_TAG_GREEN_LIGHT_WALL
	setalpha 0, 16
	waitplaysewithpan SE_W115, SOUND_PAN_ATTACKER, 15
	createsprite gUnknown_08596560, ANIM_ATTACKER, 1, 40, 0, 10166
	delay 10
	call SpecialScreenEffect
	waitforvisualfinish
	delay 1
	blendoff
	end

SpecialScreenEffect:
	createsprite gUnknown_08596624, ANIM_ATTACKER, 2, 23, 0, 0, 1
	delay 6
	createsprite gUnknown_08596624, ANIM_ATTACKER, 2, 31, -8, 0, 1
	delay 5
	createsprite gUnknown_08596624, ANIM_ATTACKER, 2, 30, 20, 0, 1
	delay 7
	createsprite gUnknown_08596624, ANIM_ATTACKER, 2, 10, -15, 0, 1
	delay 6
	createsprite gUnknown_08596624, ANIM_ATTACKER, 2, 20, 10, 0, 1
	delay 6
	createsprite gUnknown_08596624, ANIM_ATTACKER, 2, 10, 18, 0, 1
	return

Move_MIRROR_COAT:
	loadspritegfx ANIM_TAG_SPARKLE_3
	loadspritegfx ANIM_TAG_RED_LIGHT_WALL
	setalpha 0, 16
	createsprite gUnknown_08596590, ANIM_ATTACKER, 1, 40, 0, 10168
	delay 10
	playsewithpan SE_W115, SOUND_PAN_ATTACKER
	call SpecialScreenEffect
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_REFLECT:
	loadspritegfx ANIM_TAG_SPARKLE_4
	loadspritegfx ANIM_TAG_BLUE_LIGHT_WALL
	setalpha 0, 16
	waitplaysewithpan SE_W115, SOUND_PAN_ATTACKER, 15
	createsprite gUnknown_08596578, ANIM_ATTACKER, 1, 40, 0, 10167
	delay 20
	createsprite gUnknown_085965F4, ANIM_ATTACKER, 2, 30, 0, 0, 1
	delay 7
	createsprite gUnknown_085965F4, ANIM_ATTACKER, 2, 19, -12, 0, 1
	delay 7
	createsprite gUnknown_085965F4, ANIM_ATTACKER, 2, 10, 20, 0, 1
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_BARRIER:
	loadspritegfx ANIM_TAG_GRAY_LIGHT_WALL
	setalpha 0, 16
	waitplaysewithpan SE_W112, SOUND_PAN_ATTACKER, 15
	createsprite gUnknown_085965A8, ANIM_ATTACKER, 3, 40, 0, 10169
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_BUBBLE:
	loadspritegfx ANIM_TAG_BUBBLE
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 1
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 15, -15, 10, 128, 100
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W145B, SOUND_PAN_TARGET, 100
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 35, 37, 40, 128, 100
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W145B, SOUND_PAN_TARGET, 100
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 10, -37, 30, 128, 100
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W145B, SOUND_PAN_TARGET, 100
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 30, 10, 15, 128, 100
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W145B, SOUND_PAN_TARGET, 100
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 20, 33, 20, 128, 100
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W145B, SOUND_PAN_TARGET, 100
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, ANIM_ATTACKER, 2, 18, 0, 25, -30, 10, 128, 100
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W145B, SOUND_PAN_TARGET, 100
	waitforvisualfinish
	call WaterBubbleEffect2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SMOG:
	loadspritegfx ANIM_TAG_PURPLE_GAS_CLOUD
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	setalpha 12, 8
	loopsewithpan SE_W054, SOUND_PAN_TARGET, 17, 10
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	delay 120
	loopsewithpan SE_W092, SOUND_PAN_TARGET, 18, 2
	createvisualtask sub_8115A04, 2, 4, 2, 2, 0, 12, RGB(26, 0, 26)
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 15, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
Smog1:
	createsprite gUnknown_08595C44, ANIM_ATTACKER, 2, 0, -24, 48, 240, 1, 0
	delay 7
	return

Move_FAINT_ATTACK:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_ATTACKER
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	playsewithpan SE_W185, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 3
	createvisualtask sub_81136E8, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	invisible ANIM_ATTACKER
	delay 1
	createvisualtask sub_8117F60, 2
	setalpha 12, 8
	monbg ANIM_TARGET
	delay 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	setarg 7, 0x1000
	delay 32
	createvisualtask sub_8113888, 2
	monbg ANIM_ATTACKER
	createvisualtask sub_81137E4, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	restorebg
	waitbgfadein
	end

Move_SAND_ATTACK:
	loadspritegfx ANIM_TAG_MUD_SAND
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W028, SOUND_PAN_ATTACKER
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, -10, 0, 0, 3
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 2
	call SandAttack1
	call SandAttack1
	call SandAttack1
	call SandAttack1
	call SandAttack1
	call SandAttack1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end
SandAttack1:
	createsprite gUnknown_085971A8, ANIM_TARGET, 2, 15, 15, 20, 0, 0
	createsprite gUnknown_085971A8, ANIM_TARGET, 2, 15, 15, 20, 10, 10
	createsprite gUnknown_085971A8, ANIM_TARGET, 2, 15, 15, 20, -10, -10
	createsprite gUnknown_085971A8, ANIM_TARGET, 2, 15, 15, 20, 20, 5
	createsprite gUnknown_085971A8, ANIM_TARGET, 2, 15, 15, 20, -20, -5
	delay 2
	return

Move_MUD_SLAP:
	loadspritegfx ANIM_TAG_MUD_SAND
	playsewithpan SE_W028, SOUND_PAN_ATTACKER
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, -10, 0, 0, 3
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 2
	call MudSlap1
	call MudSlap1
	call MudSlap1
	call MudSlap1
	call MudSlap1
	call MudSlap1
	waitforvisualfinish
	end
MudSlap1:
	createsprite gUnknown_085971CC, ANIM_TARGET, 2, 15, 15, 20, 0, 0
	createsprite gUnknown_085971CC, ANIM_TARGET, 2, 15, 15, 20, 10, 5
	createsprite gUnknown_085971CC, ANIM_TARGET, 2, 15, 15, 20, -10, -5
	createsprite gUnknown_085971CC, ANIM_TARGET, 2, 15, 15, 20, 20, 10
	createsprite gUnknown_085971CC, ANIM_TARGET, 2, 15, 15, 20, -20, -10
	delay 2
	return

Move_DRAGON_RAGE:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loadspritegfx ANIM_TAG_FIRE_PLUME
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 40, 1
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_TARGET, 2, 0, 15, 0, 0, 4
	waitforvisualfinish
	createsprite gUnknown_08596F80, ANIM_TARGET, 2, 30, 15, 0, 10, 10
	waitforvisualfinish
	loopsewithpan SE_W172B, SOUND_PAN_TARGET, 11, 3
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 3, 25, 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 66, 1, 5, 0
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 66, 1, -10, -15
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 2, 1, 0, 25
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 66, 1, 15, 5
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 66, 1, -25, 0
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 2, 1, 30, 30
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 2, 1, -27, 25
	delay 1
	createsprite gUnknown_08596F28, ANIM_TARGET, 66, 1, 0, 8
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_TARGET, 66, 0, 0, 4
	waitforvisualfinish
	end

Move_RAIN_DANCE:
	loadspritegfx ANIM_TAG_RAIN_DROPS
	playsewithpan SE_W240, SOUND_PAN_ATTACKER
	createvisualtask sub_8116620, 10, 0x781, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 120
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 120
	delay 120
	delay 30
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 0x781, 2, 4, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_BITE:
	loadspritegfx ANIM_TAG_SHARP_TEETH
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W044, SOUND_PAN_TARGET
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, -32, 0, 0, 819, 10
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 0, 32, 4, 0, -819, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 4, 7, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	end

Move_CRUNCH:
	loadspritegfx ANIM_TAG_SHARP_TEETH
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	setalpha 12, 8
	playsewithpan SE_W044, SOUND_PAN_TARGET
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, -32, -32, 1, 819, 819, 10
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 32, 32, 5, -819, -819, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -8, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 7, 5, 2
	waitforvisualfinish
	playsewithpan SE_W044, SOUND_PAN_TARGET
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, 32, -32, 7, -819, 819, 10
	createsprite gUnknown_08597080, ANIM_ATTACKER, 2, -32, 32, 3, 819, -819, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 8, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 8, 4, 2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	restorebg
	waitbgfadein
	end

Move_CLAMP:
	loadspritegfx ANIM_TAG_CLAMP
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W011, SOUND_PAN_TARGET
	createsprite gUnknown_08597098, ANIM_ATTACKER, 2, -32, 0, 2, 819, 0, 10
	createsprite gUnknown_08597098, ANIM_ATTACKER, 2, 32, 0, 6, -819, 0, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_ICE_BEAM:
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 7, RGB_BLACK
	waitforvisualfinish
	createsoundtask sub_8158C58, SE_W062B, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 4, 4, 0, 10
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, 20, 12, 0, 12, 20
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, 20, -12, 0, -12, 20
	delay 1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 4, -31, 0, 7, RGB(0, 20, 31)
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 25, 1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, 20, 0, 0, 0, 11
	delay 1
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, 20, 0, 0, 0, 11
	waitforvisualfinish
	delay 20
	call FreezeEffect1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 4, 5, 7, 0, RGB(0, 20, 31)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
IceBeam1:
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, 20, 12, 0, 12, 20
	createsprite gUnknown_08595B2C, ANIM_ATTACKER, 2, 20, -12, 0, -12, 20
	createsprite gUnknown_08595B14, ANIM_ATTACKER, 2, 20, 0, 0, 0, 11
	delay 1
	return

Move_WITHDRAW:
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_Withdraw, 5
	waitforvisualfinish
	end

Move_AURORA_BEAM:
	loadspritegfx ANIM_TAG_RAINBOW_RINGS
	fadetobg BG_AURORA
	waitbgfadein
	playsewithpan SE_W062, SOUND_PAN_ATTACKER
	setarg 7, 0
	createvisualtask sub_8107528, 10, 130
	call AuroraBeam1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 1, 0, 17, 1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	setarg 7, -1
	createsoundtask sub_8158C58, SE_W062B, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 3, 6, 0, 10
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 40, 1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	waitforvisualfinish
	restorebg
	waitbgfadein
	end
AuroraBeam1:
	createsprite gUnknown_085950B4, ANIM_TARGET, 2, 20, 0, 0, 0, 17
	delay 1
	createsprite gUnknown_085950B4, ANIM_TARGET, 2, 20, 0, 0, 0, 17
	delay 1
	createsprite gUnknown_085950B4, ANIM_TARGET, 2, 20, 0, 0, 0, 17
	delay 1
	createsprite gUnknown_085950B4, ANIM_TARGET, 2, 20, 0, 0, 0, 17
	delay 1
	return

Move_SOLAR_BEAM:
	loadspritegfx ANIM_TAG_ORBS
	choosetwoturnanim SolarBeamSetUp, SolarBeamUnleash
SolarBeamEnd:
	waitforvisualfinish
	end
SolarBeamSetUp:
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask sub_8115A04, 2, 2, 1, 4, 0, 11, RGB(31, 31, 11)
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	call SolarBeamSetUp1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	goto SolarBeamEnd
SolarBeamSetUp1:
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 40, 40, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -40, -40, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 0, 40, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 0, -40, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 40, -20, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 40, 20, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -40, -20, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -40, 20, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -20, 30, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 20, -30, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -20, -30, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 20, 30, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -40, 0, 16
	delay 2
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 40, 0, 16
	delay 2
	return
SolarBeamUnleash:
	call SetSolarbeamBg
	panse_1B SE_W076, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createvisualtask AnimTask_CreateSmallSolarbeamOrbs, 5
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 0
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 1
	delay 4
	createvisualtask sub_8116620, 10, 4, 1, 0, 10, RGB(25, 31, 0)
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 2
	delay 4
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 65, 1
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 3
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 4
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 5
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 6
	delay 4
	call SolarBeamUnleash1
	call SolarBeamUnleash1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 1, 10, 0, RGB(25, 31, 0)
	call UnsetSolarbeamBg
	goto SolarBeamEnd
SolarBeamUnleash1:
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 0
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 1
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 2
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 3
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 4
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 5
	delay 4
	createsprite gSolarbeamBigOrbSpriteTemplate, ANIM_TARGET, 3, 15, 0, 20, 6
	delay 4
	return

Move_BLIZZARD:
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	monbg ANIM_DEF_PARTNER
	call SetHighSpeedBg
	waitforvisualfinish
	panse_1B SE_W059, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	call Blizzard1
	call Blizzard1
	playsewithpan SE_W059B, SOUND_PAN_TARGET
	waitforvisualfinish
	call FreezeEffect2
	waitforvisualfinish
	delay 20
	call UnsetHighSpeedBg
	clearmonbg ANIM_DEF_PARTNER
	end
Blizzard1:
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -10, 0, -10, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, 0, 0, 0, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -15, 0, -15, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, -10, 0, -10, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -5, 0, -5, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, 10, 0, 10, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -10, 0, -10, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, -20, 0, -20, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -20, 0, -20, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, 15, 0, 15, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -15, 0, -15, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, -20, 0, -20, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, ANIM_ATTACKER, 40, 0, -25, 0, -25, 72, 1
	createsprite gUnknown_08595BB0, ANIM_ATTACKER, 40, 0, 20, 0, 20, 80, 0, 0, 1
	delay 3
	return

Move_POWDER_SNOW:
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	monbg ANIM_DEF_PARTNER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 1, 0, 3, RGB_BLACK
	waitforvisualfinish
	panse_1B SE_W016, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	call PowderSnow1
	call PowderSnow1
	playsewithpan SE_W016B, SOUND_PAN_TARGET
	waitforvisualfinish
	waitsound
	call FreezeEffect2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 20
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 1, 3, 0, RGB_BLACK
	end
PowderSnow1:
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, 0, 0, 0, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, -10, 0, -10, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, 10, 0, 10, 56, -4, 3, 1
	delay 3
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, -20, 0, -20, 56, -4, 5, 1
	delay 3
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, 15, 0, 15, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, -20, 0, -20, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, ANIM_ATTACKER, 40, 0, 20, 0, 20, 56, 4, 4, 1
	delay 3
	return

Move_HYDRO_PUMP:
	loadspritegfx ANIM_TAG_WATER_ORB
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 40, 1
	delay 6
	panse_1B SE_W056, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createvisualtask sub_81076C8, 5, 100
	call HydroPump1
	call HydroPump1
	call HydroPump1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 37, 1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	delay 1
	delay 1
	call HydroPump2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
HydroPump1:
	createsprite gUnknown_085950E4, ANIM_ATTACKER, 3, 10, 10, 0, 16
	createsprite gUnknown_085950E4, ANIM_ATTACKER, 3, 10, 10, 0, -16
	delay 1
	createsprite gUnknown_085950E4, ANIM_ATTACKER, 3, 10, 10, 0, 16
	createsprite gUnknown_085950E4, ANIM_ATTACKER, 3, 10, 10, 0, -16
	delay 1
	return
HydroPump2:
	createsprite gUnknown_08597388, ANIM_ATTACKER, 4, 0, 15, 1, 1
	createsprite gUnknown_08597388, ANIM_ATTACKER, 4, 0, -15, 1, 1
	return

Move_SIGNAL_BEAM:
	loadspritegfx ANIM_TAG_GLOWY_RED_ORB
	loadspritegfx ANIM_TAG_GLOWY_GREEN_ORB
	loadspritegfx ANIM_TAG_DUCK
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 25, 1
	delay 6
	panse_1B SE_W062, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +1, 0
	createvisualtask sub_81076C8, 5, 100
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 25, 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 4, 8, 5, RGB_RED, 8, 961, 8
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	waitforvisualfinish
	end
SignalBeam1:
	createsprite gUnknown_08595114, ANIM_TARGET, 3, 10, 10, 0, 16
	createsprite gUnknown_0859512C, ANIM_TARGET, 3, 10, 10, 0, -16
	delay 1
	return

Move_ABSORB:
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 4, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	delay 3
	call AbsorbEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 4, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AbsorbEffect:
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W152, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -20, 35
	delay 4
	return

Move_MEGA_DRAIN:
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 8, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 1
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	delay 3
	call MegaDrainEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 8, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

MegaDrainEffect:
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -20, 35
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -20, 35
	delay 4
	return

Move_GIGA_DRAIN:
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 12, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	delay 3
	call GigaDrainEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 12, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

GigaDrainEffect:
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -40, 35
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 28, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 40, 39
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -32, 26
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -40, 26
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 36, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W202, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -20, 35
	delay 4
	return

Move_LEECH_LIFE:
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_ORBS
	delay 1
	loadspritegfx ANIM_TAG_BLUE_STAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	delay 1
	createsprite gUnknown_085969C8, ANIM_ATTACKER, 2, -20, 15, 12
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	playsewithpan SE_W071, SOUND_PAN_TARGET
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 7, RGB_BLACK
	waitforvisualfinish
	call AbsorbEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SYNTHESIS:
	loadspritegfx ANIM_TAG_SPARKLE_2
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 16, RGB(27, 31, 18)
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	call GrantingStarsEffect
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_SPARKLE_2
	delay 1
	loadspritegfx ANIM_TAG_BLUE_STAR
	call HealingEffect
	waitforvisualfinish
	end

Move_TOXIC:
	loadspritegfx ANIM_TAG_TOXIC_BUBBLE
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	call Toxic1
	call Toxic1
	waitforvisualfinish
	delay 15
	call PoisonBubblesEffect
	waitforvisualfinish
	end
Toxic1:
	createsprite gUnknown_08596134, ANIM_TARGET, 2, -24, 16, 1, 1
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 15
	createsprite gUnknown_08596134, ANIM_TARGET, 2, 8, 16, 1, 1
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 15
	createsprite gUnknown_08596134, ANIM_TARGET, 2, -8, 16, 1, 1
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 15
	createsprite gUnknown_08596134, ANIM_TARGET, 2, 24, 16, 1, 1
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 15
	return

Move_SLUDGE:
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	createsprite gUnknown_085961A8, ANIM_TARGET, 2, 20, 0, 40, 0
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
	createvisualtask sub_8115A04, 2, 4, 1, 2, 0, 12, RGB(30, 0, 31)
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Move_SLUDGE_BOMB:
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 3, 0, 15, 1
	createvisualtask sub_8115A04, 2, 4, 1, 2, 0, 12, RGB(30, 0, 31)
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, 42, 27, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, -27, 44, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, 39, -28, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, -42, -42, 20
	playsewithpan SE_W091, SOUND_PAN_TARGET
	delay 5
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, 0, 40, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, -8, -44, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, -46, -28, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, 46, 9, 20
	playsewithpan SE_W091, SOUND_PAN_TARGET
	delay 5
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, 42, 0, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, -43, -12, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, 16, -46, 20
	createsprite gUnknown_085961D8, ANIM_TARGET, 2, -16, 44, 20
	playsewithpan SE_W091, SOUND_PAN_TARGET
	delay 0
	waitsound
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	end
SludgeBomb1:
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	createsprite gUnknown_085961A8, ANIM_TARGET, 2, 20, 0, 40, 0
	delay 3
	return

Move_ACID:
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	monbg ANIM_DEF_PARTNER
	createsprite gUnknown_085961C0, ANIM_TARGET, 2, 20, 0, 40, 1, 0, 0
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	createsprite gUnknown_085961C0, ANIM_TARGET, 2, 20, 0, 40, 1, 24, 0
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	createsprite gUnknown_085961C0, ANIM_TARGET, 2, 20, 0, 40, 1, -24, 0
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 15
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 10, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_DEF_PARTNER, 2, 0, 10, 1
	createvisualtask sub_8115A04, 2, 20, 2, 2, 0, 12, RGB(30, 0, 31)
	createsprite gUnknown_0859620C, ANIM_TARGET, 2, 0, -22, 0, 15, 55
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_0859620C, ANIM_TARGET, 2, -26, -24, 0, 15, 55
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_0859620C, ANIM_TARGET, 2, 15, -27, 0, 15, 50
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_0859620C, ANIM_TARGET, 2, -15, -17, 0, 10, 45
	playsewithpan SE_W145, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_0859620C, ANIM_TARGET, 2, 27, -22, 0, 15, 50
	playsewithpan SE_W145, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_BONEMERANG:
	loadspritegfx ANIM_TAG_BONE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W155, SOUND_PAN_ATTACKER
	createsprite gUnknown_08597178, ANIM_ATTACKER, 2
	delay 20
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 5, 1
	delay 17
	playsewithpan SE_W233, SOUND_PAN_ATTACKER
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, -4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_BONE_CLUB:
	loadspritegfx ANIM_TAG_BONE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W155, SOUND_PAN_TARGET
	createsprite gUnknown_08597190, ANIM_ATTACKER, 2, -42, -25, 0, 0, 15
	delay 12
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 7, 5, 1, RGB_BLACK, 10, 0, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_BONE_RUSH:
	loadspritegfx ANIM_TAG_BONE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W155, SOUND_PAN_TARGET
	createsprite gUnknown_08597190, ANIM_ATTACKER, 2, -42, -25, 0, 0, 15
	delay 12
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 3, 5, 1
	playsewithpan SE_W030, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SPIKES:
	loadspritegfx ANIM_TAG_SPIKES
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W030, SOUND_PAN_TARGET, 28
	createsprite gUnknown_085CE11C, ANIM_TARGET, 2, 20, 0, 0, 24, 30
	delay 10
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W030, SOUND_PAN_TARGET, 28
	createsprite gUnknown_085CE11C, ANIM_TARGET, 2, 20, 0, -24, 24, 30
	delay 10
	waitplaysewithpan SE_W030, SOUND_PAN_TARGET, 28
	createsprite gUnknown_085CE11C, ANIM_TARGET, 2, 20, 0, 24, 24, 30
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_MEGAHORN:
	loadspritegfx ANIM_TAG_HORN_HIT_2
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	jumpifcontest MegahornInContest
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 768, 1, -1
MegahornContinue:
	waitbgfadein
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 2, 0, 15, 1
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 6
	delay 3
	createsprite gUnknown_08596974, ANIM_ATTACKER, 3, -42, 25, 0, 0, 6
	delay 4
	playsewithpan SE_W011, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -16, 4, 1, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, -4, 1, 12, 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 7, 5, 1, RGB_WHITE, 10, 0, 0
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 11
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	end
MegahornInContest:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 5, 2304, 768, 0, -1
	goto MegahornContinue

Move_GUST:
	loadspritegfx ANIM_TAG_GUST
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W016, SOUND_PAN_TARGET
	createsprite gUnknown_08596270, ANIM_ATTACKER, 2, 0, -16
	createvisualtask sub_810DED8, 5, 1, 70
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 1, 0, 7, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	playsewithpan SE_W016B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_WING_ATTACK:
	loadspritegfx ANIM_TAG_GUST
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_W017, SOUND_PAN_ATTACKER, 20, 2
	createvisualtask AnimTask_TranslateMonElliptical, 2, 0, 12, 4, 1, 4
	createvisualtask sub_810DED8, 5, 1, 70
	createsprite gBattleAnimSpriteTemplate_85962A4, ANIM_ATTACKER, 2, -25, 0, 0, 0, 20
	createsprite gBattleAnimSpriteTemplate_85962A4, ANIM_ATTACKER, 2, 25, 0, 0, 0, 20
	delay 24
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 9
	delay 17
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 16, 0, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -16, 0, 1, 1
	loopsewithpan SE_W003, SOUND_PAN_TARGET, 5, 2
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_PECK:
	loadspritegfx ANIM_TAG_IMPACT
	playsewithpan SE_W030, SOUND_PAN_TARGET
	createvisualtask sub_80D622C, 2, 3, -768, 1, 2
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, -12, 0, 1, 3
	waitforvisualfinish
	end

Move_AEROBLAST:
	loadspritegfx ANIM_TAG_AIR_WAVE_2
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	call SetSkyBg
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	call Aeroblast1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 50, 1
	call Aeroblast1
	call Aeroblast1
	call Aeroblast1
	call Aeroblast1
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 0
	call UnsetSkyBg
	end
Aeroblast1:
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 0, 0
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 0, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 1, 0
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 1, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 2, 0
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 2, 0
	delay 3
	playsewithpan SE_W026, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, -12, 0, -12, 15, 3, 0
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 26, 8, 12, 8, 15, 3, 0
	delay 3
	return

Move_WATER_GUN:
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createsprite gUnknown_08595208, ANIM_ATTACKER, 2, 20, 0, 0, 0, 40, -25
	playsewithpan SE_W145, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 1, 0, 8, 1
	createsprite gUnknown_08597388, ANIM_ATTACKER, 4, 0, 0, 1, 2
	createsprite gUnknown_08595220, ANIM_ATTACKER, 2, 0, -15, 0, 15, 55
	playsewithpan SE_W152, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_08595220, ANIM_ATTACKER, 2, 15, -20, 0, 15, 50
	playsewithpan SE_W152, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_08595220, ANIM_ATTACKER, 2, -15, -10, 0, 10, 45
	playsewithpan SE_W152, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_CRABHAMMER:
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gUnknown_08597388, ANIM_ATTACKER, 4, 0, 0, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 1
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB(13, 21, 31), 10, 0, 0
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -24, 0, 0, 4
	waitforvisualfinish
	delay 8
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 4
	waitforvisualfinish
	loopsewithpan SE_W152, SOUND_PAN_TARGET, 20, 3
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 4, 8, 1
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 10, 10, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 20, -20, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, -15, 15, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 0, 0, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, -10, -20, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 16, -8, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, 5, 8, 20, 1
	delay 4
	createsprite gUnknown_08595238, ANIM_ATTACKER, 2, -16, 0, 20, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SURF:
	createvisualtask AnimTask_CreateSurfWave, 2, FALSE
	delay 24
	panse_1B SE_W057, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	waitforvisualfinish
	end

Move_FLAMETHROWER:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 46, 1
	delay 6
	createvisualtask sub_81076C8, 5, 100
	panse_1B SE_W053, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 43, 1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Flamethrower1:
	createsprite gUnknown_08595158, ANIM_ATTACKER, 3, 10, 10, 0, 16
	delay 2
	createsprite gUnknown_08595158, ANIM_ATTACKER, 3, 10, 10, 0, 16
	delay 2
	return

Move_SANDSTORM:
	loadspritegfx ANIM_TAG_FLYING_DIRT
	playsewithpan SE_W201, 0
	createvisualtask AnimTask_LoadSandstormBackground, 5, FALSE
	delay 16
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 10, 2304, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 90, 2048, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 50, 2560, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 20, 2304, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 70, 1984, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 0, 2816, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, ANIM_ATTACKER, 40, 60, 2560, 96, 0
	end

Move_WHIRLPOOL:
	loadspritegfx ANIM_TAG_WATER_ORB
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 0, 7, RGB(0, 13, 23)
	playsewithpan SE_W250, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 50, 1
	call WhirlpoolEffect
	call WhirlpoolEffect
	call WhirlpoolEffect
	delay 12
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 7, 0, RGB(0, 13, 23)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

WhirlpoolEffect:
	createsprite gUnknown_08596B70, ANIM_TARGET, 2, 0, 28, 384, 50, 8, 50, 1
	delay 2
	createsprite gUnknown_08596B70, ANIM_TARGET, 2, 0, 32, 240, 40, 11, -46, 1
	delay 2
	createsprite gUnknown_08596B70, ANIM_TARGET, 2, 0, 33, 416, 40, 4, 42, 1
	delay 2
	createsprite gUnknown_08596B70, ANIM_TARGET, 2, 0, 31, 288, 45, 6, -42, 1
	delay 2
	createsprite gUnknown_08596B70, ANIM_TARGET, 2, 0, 28, 448, 45, 11, 46, 1
	delay 2
	createsprite gUnknown_08596B70, ANIM_TARGET, 2, 0, 33, 464, 50, 10, -50, 1
	delay 2
	return

Move_FLY:
	loadspritegfx ANIM_TAG_ROUND_SHADOW
	loadspritegfx ANIM_TAG_IMPACT
	choosetwoturnanim FlySetUp, FlyUnleash
FlyEnd:
	waitforvisualfinish
	end

FlySetUp:
	playsewithpan SE_W019, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596340, ANIM_ATTACKER, 2, 0, 0, 13, 336
	goto FlyEnd

FlyUnleash:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596358, ANIM_ATTACKER, 2, 20
	delay 20
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto FlyEnd

Move_BOUNCE:
	loadspritegfx ANIM_TAG_ROUND_SHADOW
	loadspritegfx ANIM_TAG_IMPACT
	choosetwoturnanim BounceSetUp, BounceUnleash
BounceEnd:
	end

BounceSetUp:
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596420, ANIM_ATTACKER, 2, 0, 0
	goto BounceEnd

BounceUnleash:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gUnknown_0859644C, ANIM_TARGET, 3
	delay 7
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 11, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto BounceEnd

Move_KARATE_CHOP:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W104, SOUND_PAN_TARGET
	createsprite gUnknown_08595E68, ANIM_ATTACKER, 2, -16, 0, 0, 0, 10, 1, 3, 0
	waitforvisualfinish
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_CROSS_CHOP:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_CROSS_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W025, SOUND_PAN_TARGET
	createsprite gUnknown_08595EC8, ANIM_ATTACKER, 2, 0, 0, 0
	createsprite gUnknown_08595EC8, ANIM_ATTACKER, 2, 0, 0, 1
	delay 40
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_WHITE, 10, 0, 10
	createsprite gUnknown_085973D0, ANIM_ATTACKER, 3, 0, 0, 1, 20
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 7, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_JUMP_KICK:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 3
	createsprite gUnknown_08595E80, ANIM_ATTACKER, 2, -16, 8, 0, 0, 10, 1, 1, 1
	playsewithpan SE_W026, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 1, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 7, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_HI_JUMP_KICK:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, -24, 0, 0, 8
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 3
	delay 2
	createsprite gUnknown_08595E80, ANIM_ATTACKER, 2, -16, 8, 0, 0, 10, 1, 1, 1
	playsewithpan SE_W026, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -28, 0, 0, 3
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 11, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_KICK:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gUnknown_08595EB0, ANIM_ATTACKER, 3, 1, 20, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TRIPLE_KICK:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	jumpifmoveturn 0, TripleKickLeft
	jumpifmoveturn 1, TripleKickRight
	goto TripleKickCenter
TripleKickContinue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

TripleKickLeft:
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, -16, -8, 20, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -16, -16, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	goto TripleKickContinue

TripleKickRight:
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 8, 8, 20, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 8, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	goto TripleKickContinue

TripleKickCenter:
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 4, 0, 0, 20, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, -8, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	goto TripleKickContinue

Move_DYNAMIC_PUNCH:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_EXPLOSION
	loadspritegfx ANIM_TAG_EXPLOSION_6
	delay 1
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, 0, 0, 20, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 7, 1
	delay 1
	waitsound
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 5, 0, 28, 1
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 0, 0, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 24, -24, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -16, 16, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -24, -12, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 16, 16, 1, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_COUNTER:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 4
	playsewithpan SE_W233, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -15, 18, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 25, 1
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, -15, 18, 8, 1, 0
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, -4, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 1
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 0, -4, 8, 1, 0
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 15, 9, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 1
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 3, 15, 9, 8, 1, 0
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_VITAL_THROW:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 4, 1, 2
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -24, 0, 0, 4
	waitforvisualfinish
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 7
	delay 11
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 10
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROCK_SMASH:
	loadspritegfx ANIM_TAG_ROCKS
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 5, 1
	waitforvisualfinish
	playsewithpan SE_W088, SOUND_PAN_TARGET
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 0, 0, 20, 24, 14, 2
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 5, 0, -20, 24, 14, 1
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 0, 5, 20, -24, 14, 2
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, -5, 0, -20, -24, 14, 2
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 0, -5, 30, 18, 8, 2
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 0, 0, 30, -18, 8, 2
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 0, 0, -30, 18, 8, 2
	createsprite gUnknown_08596B1C, ANIM_ATTACKER, 2, 0, 0, -30, -18, 8, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 7, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUBMISSION:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W004, SOUND_PAN_TARGET, 10
	waitplaysewithpan SE_W104, SOUND_PAN_ATTACKER, 20
	waitplaysewithpan SE_W004, SOUND_PAN_TARGET, 30
	waitplaysewithpan SE_W104, SOUND_PAN_ATTACKER, 40
	waitplaysewithpan SE_W004, SOUND_PAN_TARGET, 50
	waitplaysewithpan SE_W104, SOUND_PAN_ATTACKER, 60
	waitplaysewithpan SE_W004, SOUND_PAN_TARGET, 70
	waitplaysewithpan SE_W104, SOUND_PAN_ATTACKER, 80
	waitplaysewithpan SE_W004, SOUND_PAN_TARGET, 0x5A
	createvisualtask AnimTask_TranslateMonElliptical, 2, 0, -18, 6, 6, 4
	createvisualtask AnimTask_TranslateMonElliptical, 2, 1, 18, 6, 6, 4
	call Submission1
	call Submission1
	call Submission1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Submission1:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, -12, 1, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, -12, 8, 1, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 12, 0, 1, 1
	delay 8
	return

Move_SUNNY_DAY:
	loadspritegfx ANIM_TAG_SUNLIGHT
	monbg ANIM_ATK_PARTNER
	setalpha 13, 3
	createvisualtask sub_8116620, 10, 0x781, 1, 0, 6, RGB_WHITE
	waitforvisualfinish
	panse_26 SE_W080, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +1, 0
	call SunnyDay1
	call SunnyDay1
	call SunnyDay1
	call SunnyDay1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 0x781, 1, 6, 0, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

SunnyDay1:
	createsprite gUnknown_085954A0, ANIM_ATTACKER, 40
	delay 6
	return

Move_COTTON_SPORE:
	loadspritegfx ANIM_TAG_SPORE
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W077, SOUND_PAN_TARGET, 18, 10
	call CottonSpore1
	call CottonSpore1
	call CottonSpore1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

CottonSpore1:
	createsprite gSporeParticleSpriteTemplate, ANIM_ATTACKER, 2, 0, -20, 85, 80, 0
	delay 12
	createsprite gSporeParticleSpriteTemplate, ANIM_ATTACKER, 2, 0, -10, 170, 80, 0
	delay 12
	createsprite gSporeParticleSpriteTemplate, ANIM_ATTACKER, 2, 0, -15, 0, 80, 0
	delay 12
	return

Move_SPORE:
	loadspritegfx ANIM_TAG_SPORE
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_SporeDoubleBattle, 2
	loopsewithpan SE_W077, SOUND_PAN_TARGET, 16, 11
	call Spore1
	call Spore1
	call Spore1
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Spore1:
	createsprite gSporeParticleSpriteTemplate, ANIM_TARGET, 2, 0, -20, 85, 80, 1
	delay 12
	createsprite gSporeParticleSpriteTemplate, ANIM_TARGET, 2, 0, -10, 170, 80, 1
	delay 12
	createsprite gSporeParticleSpriteTemplate, ANIM_TARGET, 2, 0, -15, 0, 80, 1
	delay 12
	return

Move_PETAL_DANCE:
	loadspritegfx ANIM_TAG_FLOWER
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W080, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 6, 6, 3
	createsprite gPetalDanceBigFlowerSpriteTemplate, ANIM_ATTACKER, 2, 0, -24, 8, 140
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, 16, -24, 8, 100
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, -16, -24, 8, 100
	delay 15
	createsprite gPetalDanceBigFlowerSpriteTemplate, ANIM_ATTACKER, 2, 0, -24, 8, 140
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, 32, -24, 8, 100
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, -32, -24, 8, 100
	delay 15
	createsprite gPetalDanceBigFlowerSpriteTemplate, ANIM_ATTACKER, 2, 0, -24, 8, 140
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, 24, -24, 8, 100
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, -24, -24, 8, 100
	delay 30
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, 16, -24, 0, 100
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, -16, -24, 0, 100
	delay 30
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, 20, -16, 14, 80
	createsprite gPetalDanceSmallFlowerSpriteTemplate, ANIM_ATTACKER, 2, -20, -14, 16, 80
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 5
	delay 3
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 6, 0, 8, 1
	waitforvisualfinish
	delay 8
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_RAZOR_LEAF:
	loadspritegfx ANIM_TAG_LEAF
	loadspritegfx ANIM_TAG_RAZOR_LEAF
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 1
	loopsewithpan SE_W077, SOUND_PAN_ATTACKER, 10, 5
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -3, -2, 10
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -1, -1, 15
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -4, -4, 7
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 3, -3, 11
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -1, -6, 8
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 2, -1, 12
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -3, -4, 13
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 4, -5, 7
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 2, -6, 11
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -3, -5, 8
	delay 60
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gRazorLeafCutterSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 22, 20, 1
	createsprite gRazorLeafCutterSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 22, -20, 1
	delay 20
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_NATURE_POWER:
Move_ANCIENT_POWER:
	loadspritegfx ANIM_TAG_ROCKS
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, 4, 1, 10, 1
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 20, 32, -48, 50, 2
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 0, 32, -38, 25, 5
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 32, 32, -28, 40, 3
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, -20, 32, -48, 50, 2
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 20, 32, -28, 60, 1
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 0, 32, -28, 30, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 30, 1
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	delay 10
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 15, 32, -48, 25, 5
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, -10, 32, -42, 30, 4
	delay 10
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, 0, 32, -42, 25, 5
	createsprite gUnknown_08596C10, ANIM_ATTACKER, 2, -25, 32, -48, 30, 4
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 16, 0, 0, 4
	delay 3
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_OCTAZOOKA:
	loadspritegfx ANIM_TAG_GRAY_SMOKE
	loadspritegfx ANIM_TAG_BLACK_BALL
	playsewithpan SE_W025B, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592DFC, ANIM_TARGET, 2, 20, 0, 0, 0, 20, 0
	waitforvisualfinish
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gUnknown_08592E30, ANIM_TARGET, 2, 8, 8, 1, 0
	delay 2
	createsprite gUnknown_08592E30, ANIM_TARGET, 2, -8, -8, 1, 0
	delay 2
	createsprite gUnknown_08592E30, ANIM_TARGET, 2, 8, -8, 1, 0
	delay 2
	createsprite gUnknown_08592E30, ANIM_TARGET, 2, -8, 8, 1, 0
	waitforvisualfinish
	end

Move_MIST:
	loadspritegfx ANIM_TAG_MIST_CLOUD
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	loopsewithpan SE_W054, SOUND_PAN_ATTACKER, 20, 15
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	delay 32
	createvisualtask sub_8115A04, 2, 10, 8, 2, 0, 14, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Mist1:
	createsprite gUnknown_08595C2C, ANIM_ATTACKER, 2, 0, -24, 48, 240, 0, 1
	delay 7
	return

Move_HAZE:
	waitforvisualfinish
	playsewithpan SE_W114, 0
	createvisualtask AnimTask_Haze1, 5
	delay 30
	createvisualtask sub_8116620, 10, 0x780, 2, 0, 16, RGB_BLACK
	delay 0x5A
	createvisualtask sub_8116620, 10, 0x780, 1, 16, 0, RGB_BLACK
	end

Move_FIRE_PUNCH:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask sub_8116620, 10, 4, 2, 0, 9, RGB_RED
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 0
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 64
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 128
	createsprite gUnknown_08595368, ANIM_TARGET, 1, 196
	playsewithpan SE_W172, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gFistFootSpriteTemplate, ANIM_TARGET, 3, 0, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 15, 1
	call FireMoveEffect
	delay 4
	playsewithpan SE_W007, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 9, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

FireMoveEffect:
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, 192, 176, 40
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, -192, 240, 40
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, 192, -160, 40
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, -192, -112, 40
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, 160, 48, 40
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, -224, -32, 40
	createsprite gUnknown_08595380, ANIM_TARGET, 1, 0, 10, 112, -128, 40
	return

Move_LEER:
	loadspritegfx ANIM_TAG_LEER
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	setalpha 8, 8
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	createsprite gUnknown_085CE150, ANIM_ATTACKER, 2, 24, -12
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 9, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	waitforvisualfinish
	end

Move_DREAM_EATER:
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	setalpha 8, 8
	playsewithpan SE_W107, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -6, -6, 15, ANIM_TARGET, 1
	waitforvisualfinish
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 2, 25, 1
	call DreamEaterEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 1
	call UnsetPsychicBg
	end
DreamEaterEffect:
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -40, 35
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 28, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 40, 39
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -32, 26
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, -16, 36
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 16, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -40, 26
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -5, 15, 36, 33
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 10, -5, -8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, 8, 26
	createsprite gAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 3, 5, -18, -20, 35
	delay 4
	return

Move_POISON_GAS:
	loadspritegfx ANIM_TAG_PURPLE_GAS_CLOUD
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	delay 0
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	setalpha 12, 8
	delay 0
	playsewithpan SE_W054, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C9C, ANIM_TARGET, 0, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C9C, ANIM_TARGET, 0, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C9C, ANIM_TARGET, 0, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C9C, ANIM_TARGET, 0, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C9C, ANIM_TARGET, 0, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595C9C, ANIM_TARGET, 0, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 40
	loopsewithpan SE_W054, SOUND_PAN_TARGET, 28, 6
	createvisualtask sub_8115A04, 2, 4, 6, 2, 0, 12, RGB(26, 0, 26)
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	end

Move_BIND:
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 3328, 4, ANIM_ATTACKER
	goto BindWrap

BindWrap:
	playsewithpan SE_W020, SOUND_PAN_TARGET
	call BindWrap1
	call BindWrap1
	waitforvisualfinish
	end
BindWrap1:
	createvisualtask AnimTask_ScaleMonAndRestore, 5, 10, -5, 5, ANIM_TARGET, 0
	delay 16
	return

Move_WRAP:
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 6, 4, 2, 4
	goto BindWrap

Move_PSYBEAM:
	loadspritegfx ANIM_TAG_GOLD_RING
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	createsoundtask sub_8158C58, SE_W060B, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 3, 4, 0, 15
	call Psybeam1
	call Psybeam1
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 2048, 4, ANIM_TARGET
	createvisualtask sub_8115A04, 2, 4, 2, 2, 0, 12, RGB(31, 18, 31)
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	waitforvisualfinish
	delay 1
	call UnsetPsychicBg
	end
Psybeam1:
	createsprite gUnknown_0859663C, ANIM_TARGET, 2, 16, 0, 0, 0, 13, 0
	delay 4
	return

Move_HYPNOSIS:
	loadspritegfx ANIM_TAG_GOLD_RING
	call SetPsychicBackground
	call Hypnosis1
	call Hypnosis1
	call Hypnosis1
	createvisualtask sub_8115A04, 2, 4, 2, 2, 0, 12, RGB(31, 18, 31)
	waitforvisualfinish
	delay 1
	call UnsetPsychicBg
	end
Hypnosis1:
	playsewithpan SE_W048, SOUND_PAN_ATTACKER
	createsprite gUnknown_0859663C, ANIM_TARGET, 2, 0, 8, 0, 8, 27, 0
	createsprite gUnknown_0859663C, ANIM_TARGET, 2, 16, -8, 0, -8, 27, 0
	delay 6
	return

Move_PSYWAVE:
	loadspritegfx ANIM_TAG_BLUE_RING
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	createvisualtask sub_81076C8, 5, 100
	createsoundtask sub_8158C58, SE_W100, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 2, 9, 0, 10
	call Psywave1
	call Psywave1
	createvisualtask sub_8115A04, 2, 4, 1, 4, 0, 12, RGB(31, 18, 31)
	call Psywave1
	call Psywave1
	call Psywave1
	call Psywave1
	waitforvisualfinish
	delay 1
	call UnsetPsychicBg
	end
Psywave1:
	createsprite gUnknown_08595170, ANIM_TARGET, 3, 10, 10, 0, 16
	delay 4
	createsprite gUnknown_08595170, ANIM_TARGET, 3, 10, 10, 0, 16
	delay 4
	return

Move_ZAP_CANNON:
	loadspritegfx ANIM_TAG_BLACK_BALL_2
	loadspritegfx ANIM_TAG_SPARK_2
	playsewithpan SE_W086, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595764, ANIM_TARGET, 3, 10, 0, 0, 0, 30, 0
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 16, 30, 0, 40, 0
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 16, 30, 64, 40, 1
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 16, 30, 128, 40, 0
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 16, 30, 192, 40, 2
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 8, 30, 32, 40, 0
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 8, 30, 96, 40, 1
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 8, 30, 160, 40, 0
	createsprite gUnknown_08595790, ANIM_TARGET, 4, 10, 0, 8, 30, 224, 40, 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 5, 1
	delay 15
	waitplaysewithpan SE_W085B, SOUND_PAN_TARGET, 19
	call ElectricityEffect
	waitforvisualfinish
	end

Move_STEEL_WING:
	loadspritegfx ANIM_TAG_GUST
	loadspritegfx ANIM_TAG_IMPACT
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 0, 0, 0
	waitforvisualfinish
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_W017, SOUND_PAN_ATTACKER, 20, 2
	createvisualtask AnimTask_TranslateMonElliptical, 2, 0, 12, 4, 1, 4
	createvisualtask sub_810DED8, 5, 1, 70
	createsprite gBattleAnimSpriteTemplate_85962A4, ANIM_ATTACKER, 2, -25, 0, 0, 0, 20
	createsprite gBattleAnimSpriteTemplate_85962A4, ANIM_ATTACKER, 2, 25, 0, 0, 0, 20
	delay 24
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 9
	delay 17
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 16, 0, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -16, 0, 1, 1
	playsewithpan SE_W013, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_IRON_TAIL:
	loadspritegfx ANIM_TAG_IMPACT
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 1, 0, 0
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 1
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_POISON_TAIL:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 1, 1, RGB(24, 6, 23)
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_ATTACKER, 1
	clearmonbg ANIM_TARGET
	blendoff
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Move_METAL_CLAW:
	loadspritegfx ANIM_TAG_CLAW_SLASH
	loopsewithpan SE_W231, SOUND_PAN_ATTACKER, 28, 2
	createvisualtask AnimTask_MetallicShine, 5, 0, 0, 0
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 2
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, -10, -10, 0
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, -10, 10, 0
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, -4, 1, 10, 3, 1
	delay 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 2
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, 10, -10, 1
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, 10, 10, 1
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, -4, 1, 10, 3, 1
	waitforvisualfinish
	end

Move_NIGHT_SHADE:
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	fadetobg BG_GHOST
	waitbgfadein
	delay 10
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	createvisualtask sub_811188C, 5, 85
	delay 70
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 12, 1
	createvisualtask sub_8115A04, 2, 4, 0, 2, 0, 13, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	restorebg
	waitbgfadein
	end

Move_EGG_BOMB:
	loadspritegfx ANIM_TAG_EXPLOSION
	loadspritegfx ANIM_TAG_LARGE_FRESH_EGG
	playsewithpan SE_W039, SOUND_PAN_ATTACKER
	createsprite gUnknown_08593488, ANIM_TARGET, 2, 10, 0, 0, 0, 25, -32
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 16, 1
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 6, 5, 1, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, -16, -15, 1, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 16, -5, 1, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, -12, 18, 1, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 4, 0, 5, 1, 0
	playsewithpan SE_W120, SOUND_PAN_TARGET
	delay 3
	waitforvisualfinish
	end

Move_SHADOW_BALL:
	loadspritegfx ANIM_TAG_SHADOW_BALL
	fadetobg BG_GHOST
	waitbgfadein
	delay 15
	createsoundtask sub_8158C58, SE_W054, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 5, 5, 0, 5
	createsprite gShadowBallSpriteTemplate, ANIM_TARGET, 2, 16, 16, 8
	waitforvisualfinish
	playsewithpan SE_W028, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 8, 1
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_LICK:
	loadspritegfx ANIM_TAG_LICK
	delay 15
	playsewithpan SE_W122, SOUND_PAN_TARGET
	createsprite gUnknown_08596D8C, ANIM_TARGET, 2, 0, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 16, 1
	waitforvisualfinish
	end

Move_FOCUS_ENERGY:
	loadspritegfx ANIM_TAG_FOCUS_ENERGY
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	call EndureEffect
	delay 8
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_WHITE
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

Move_BIDE:
	choosetwoturnanim BideSetUp, BideUnleash
	end
BideSetUp:
	loopsewithpan SE_W036, SOUND_PAN_ATTACKER, 9, 2
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	waitforvisualfinish
	end

BideUnleash:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	loopsewithpan SE_W036, SOUND_PAN_ATTACKER, 9, 2
	createvisualtask sub_8116620, 10, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 12, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 16, 1
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 1, 18, -8, 1, 1
	delay 5
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 1, -18, 8, 1, 1
	delay 5
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 1, -8, -5, 1, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 7
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 2, 11, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRING_SHOT:
	loadspritegfx ANIM_TAG_STRING
	loadspritegfx ANIM_TAG_WEB_THREAD
	monbg ANIM_DEF_PARTNER
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	loopsewithpan SE_W081, SOUND_PAN_ATTACKER, 9, 6
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	waitforvisualfinish
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gUnknown_085969F8, ANIM_TARGET, 2, 0, 10
	delay 4
	createsprite gUnknown_085969F8, ANIM_TARGET, 2, 0, -2
	delay 4
	createsprite gUnknown_085969F8, ANIM_TARGET, 2, 0, 22
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 9, 0, RGB_BLACK
	end

StringShot1:
	createsprite gWebThreadSpriteTemplate, ANIM_TARGET, 2, 20, 0, 512, 20, 1
	delay 1
	return

Move_SPIDER_WEB:
	loadspritegfx ANIM_TAG_SPIDER_WEB
	loadspritegfx ANIM_TAG_WEB_THREAD
	monbg ANIM_DEF_PARTNER
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W081, SOUND_PAN_ATTACKER, 9, 6
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	waitforvisualfinish
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gSpiderWebSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, FALSE
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 5, 1, 2, 9, 0, RGB_BLACK
	end

SpiderWeb1:
	createsprite gWebThreadSpriteTemplate, ANIM_TARGET, 2, 20, 0, 512, 20, 0
	delay 1
	return

Move_RAZOR_WIND:
	choosetwoturnanim RazorWindSetUp, RazorWindUnleash
RazorWindContinue:
	waitforvisualfinish
	end

RazorWindSetUp:
	loadspritegfx ANIM_TAG_GUST
	playsewithpan SE_W016, SOUND_PAN_ATTACKER
	createsprite gRazorWindTornadoSpriteTemplate, ANIM_ATTACKER, 2, 32, 0, 16, 16, 0, 7, 40
	createsprite gRazorWindTornadoSpriteTemplate, ANIM_ATTACKER, 2, 32, 0, 16, 16, 85, 7, 40
	createsprite gRazorWindTornadoSpriteTemplate, ANIM_ATTACKER, 2, 32, 0, 16, 16, 170, 7, 40
	waitforvisualfinish
	playsewithpan SE_W016B, SOUND_PAN_ATTACKER
	goto RazorWindContinue

RazorWindUnleash:
	loadspritegfx ANIM_TAG_AIR_WAVE_2
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, 8, 0, 0, 22, 2, 1
	delay 2
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, -8, 16, 14, 22, 1, 1
	delay 2
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gUnknown_085962D4, ANIM_ATTACKER, 2, 14, 12, -16, -14, 22, 0, 1
	delay 17
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 10, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	goto RazorWindContinue

Move_DISABLE:
	loadspritegfx ANIM_TAG_SPARKLE_4
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 8, 8
	playsewithpan SE_W197, SOUND_PAN_ATTACKER
	createsprite gUnknown_0853EE84, ANIM_ATTACKER, 13, 24, -16
	waitforvisualfinish
	createvisualtask AnimTask_GrowAndGreyscale, 5
	loopsewithpan SE_W020, SOUND_PAN_TARGET, 15, 4
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_RECOVER:
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	loopsewithpan SE_W025, SOUND_PAN_ATTACKER, 13, 3
	createvisualtask sub_8115A04, 2, 2, 0, 6, 0, 11, RGB(31, 31, 11)
	call Recover1
	call Recover1
	call Recover1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	call HealingEffect
	waitforvisualfinish
	end

Recover1:
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 40, -10, 13
	delay 3
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -35, -10, 13
	delay 3
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 15, -40, 13
	delay 3
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -10, -32, 13
	delay 3
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 25, -20, 13
	delay 3
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -40, -20, 13
	delay 3
	createsprite gPowerAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 5, -40, 13
	delay 3
	return

Move_MIMIC:
	loadspritegfx ANIM_TAG_ORBS
	setalpha 11, 5
	monbg_22 ANIM_DEF_PARTNER
	monbgprio_29
	panse_1B SE_W107, SOUND_PAN_TARGET, SOUND_PAN_ATTACKER, -3, 0
	createvisualtask sub_80FF458, 5, 128, 24
	delay 15
	createsprite gMimicOrbSpriteTemplate, ANIM_TARGET, 2, -12, 24
	delay 10
	setarg 7, -1
	waitforvisualfinish
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 11, RGB_WHITE
	waitforvisualfinish
	clearmonbg_23 ANIM_DEF_PARTNER
	blendoff
	end

Move_CONSTRICT:
	loadspritegfx ANIM_TAG_TENDRILS
	loopsewithpan SE_W010, SOUND_PAN_TARGET, 6, 4
	createsprite gConstrictBindingSpriteTemplate, ANIM_TARGET, 4, 0, 16, 0, 2
	delay 7
	createsprite gConstrictBindingSpriteTemplate, ANIM_TARGET, 3, 0, 0, 0, 2
	createsprite gConstrictBindingSpriteTemplate, ANIM_TARGET, 2, 0, 8, 1, 2
	delay 7
	createsprite gConstrictBindingSpriteTemplate, ANIM_TARGET, 3, 0, -8, 1, 2
	delay 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	delay 20
	playsewithpan SE_W020, SOUND_PAN_TARGET
	setarg 7, -1
	waitforvisualfinish
	end

Move_CURSE:
	choosetwoturnanim CurseGhost, CurseStats
CurseGhost:
	loadspritegfx ANIM_TAG_NAIL
	loadspritegfx ANIM_TAG_GHOSTLY_SPIRIT
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8112758, 5
	waitforvisualfinish
	delay 20
	createsprite gUnknown_08596DD0, ANIM_ATTACKER, 2
	delay 60
	call CurseGhost1
	delay 41
	call CurseGhost1
	delay 41
	call CurseGhost1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	delay 1
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8596DE8, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 14, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 16, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end
CurseGhost1:
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 4, 0, 10, 0
	playsewithpan SE_W020, SOUND_PAN_ATTACKER
	return
CurseStats:
	createvisualtask AnimTask_SwayMon, 5, 0, 10, 1536, 3, ANIM_ATTACKER
	waitforvisualfinish
	delay 10
	call CurseStats1
	waitforvisualfinish
	end
CurseStats1:
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	createvisualtask sub_8116B14, 5
	createvisualtask sub_8115A04, 5, 2, 4, 2, 0, 10, RGB_RED
	return

Move_SOFT_BOILED:
	loadspritegfx ANIM_TAG_BREAKING_EGG
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W039, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 2, 6, 1
	createsprite gUnknown_085937B0, ANIM_ATTACKER, 4, 0, 16, 0
	createsprite gUnknown_085937B0, ANIM_ATTACKER, 4, 0, 16, 1
	delay 120
	delay 7
	playsewithpan SE_W030, SOUND_PAN_ATTACKER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 10, 0, RGB(12, 24, 30)
	createsprite gUnknown_0859381C, ANIM_ATTACKER, 3, 31, 16, 0, 1
	delay 8
	createsprite gUnknown_0859381C, ANIM_ATTACKER, 3, 31, 16, 0, 1
	delay 60
	setarg 7, -1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	call HealingEffect2
	end

Move_HEAL_BELL:
	loadspritegfx ANIM_TAG_BELL
	loadspritegfx ANIM_TAG_MUSIC_NOTES_2
	loadspritegfx ANIM_TAG_THIN_RING
	createvisualtask sub_8116620, 10, 10, 0, 0, 10, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_8105CB4, 5
	createsprite gUnknown_08593938, ANIM_ATTACKER, 2, 0, -24, 0, 1
	delay 12
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, 48, -18, 35, 0, 0
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, -48, 20, 30, 1, 1
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, -38, -29, 30, 2, 2
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, 36, 18, 30, 3, 3
	call HealBell1
	delay 0x21
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, 19, 26, 35, 4, 4
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, -34, -12, 30, 5, 5
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, 41, -20, 34, 6, 2
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, -15, 26, 32, 7, 0
	call HealBell1
	delay 0x21
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, -48, 18, 31, 0, 2
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, 48, -20, 30, 2, 5
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, 38, 29, 33, 4, 3
	createsprite gUnknown_08593958, ANIM_ATTACKER, 40, 0, -24, -36, -18, 30, 6, 1
	call HealBell1
	waitforvisualfinish
	createvisualtask sub_8105D60, 5
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_BELL
	unloadspritegfx ANIM_TAG_MUSIC_NOTES_2
	unloadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_SPARKLE_2
	playsewithpan SE_W234, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592B94, ANIM_ATTACKER, 16, -15, 0, 0, 0, 32, 60, 1
	delay 8
	createsprite gUnknown_08592B94, ANIM_ATTACKER, 16, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_SPARKLE_2
	loadspritegfx ANIM_TAG_THIN_RING
	playsewithpan SE_REAPOKE, SOUND_PAN_ATTACKER
	createvisualtask sub_8116664, 10, 4, 3, 10, 0, RGB(12, 24, 30)
	createvisualtask sub_8116620, 10, 10, 3, 10, 0, RGB_WHITE
	createsprite gUnknown_08593868, ANIM_ATTACKER, 16, 0, 0, 0, 1
	end
HealBell1:
	createvisualtask sub_8116664, 10, 4, 3, 8, 0, RGB(12, 24, 30)
	createvisualtask sub_8116620, 10, 10, 3, 2, 10, RGB_WHITE
	createsprite gUnknown_0859381C, ANIM_ATTACKER, 40, 0, -24, 0, 1
	playsewithpan SE_W215, SOUND_PAN_ATTACKER
	return

Move_FAKE_OUT:
	playsewithpan SE_W260, 0
	createvisualtask sub_8105EB0, 5
	waitforvisualfinish
	playsewithpan SE_W166, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 5, 1
	createvisualtask sub_8106020, 3
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 16, 0, RGB_WHITE
	end

Move_SCARY_FACE:
	loadspritegfx ANIM_TAG_EYE_SPARKLE
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 27, 3, 0, 16, RGB_BLACK
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 10
	playsewithpan SE_W043, SOUND_PAN_ATTACKER
	createvisualtask sub_81064F8, 5
	delay 13
	createsprite gUnknown_08593A84, ANIM_ATTACKER, 0, -16, -8
	createsprite gUnknown_08593A84, ANIM_ATTACKER, 0, 16, -8
	waitforvisualfinish
	createvisualtask sub_810A094, 3, 20, 1, 0
	playsewithpan SE_W081B, SOUND_PAN_TARGET
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 27, 3, 16, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_SWEET_KISS:
	loadspritegfx ANIM_TAG_RED_HEART
	loadspritegfx ANIM_TAG_ANGEL
	createsprite gUnknown_08593AA8, ANIM_TARGET, 2, 16, -48
	playsewithpan SE_W215, SOUND_PAN_TARGET
	delay 23
	playsewithpan SE_W215, SOUND_PAN_TARGET
	delay 23
	playsewithpan SE_W215, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, 160, -30
	playsewithpan SE_W213, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, -256, -42
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, 128, -14
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, 416, -38
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, -128, -22
	createsprite gBattleAnimSpriteTemplate_85939B8, ANIM_TARGET, 3, -384, -31
	end

Move_LOVELY_KISS:
	loadspritegfx ANIM_TAG_PINK_HEART
	loadspritegfx ANIM_TAG_DEVIL
	createsprite gUnknown_08593AF0, ANIM_TARGET, 2, 0, -24
	playsewithpan SE_W060B, SOUND_PAN_TARGET
	waitforvisualfinish
	playsewithpan SE_W213, SOUND_PAN_TARGET
	createsprite gUnknown_08593AC0, ANIM_TARGET, 3, -256, -42
	createsprite gUnknown_08593AC0, ANIM_TARGET, 3, 128, -14
	createsprite gUnknown_08593AC0, ANIM_TARGET, 3, 416, -38
	createsprite gUnknown_08593AC0, ANIM_TARGET, 3, -128, -22
	end

Move_FURY_SWIPES:
	loadspritegfx ANIM_TAG_SWIPE
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 5, 5
	delay 4
	playsewithpan SE_W010, SOUND_PAN_TARGET
	createsprite gUnknown_08593B38, ANIM_TARGET, 2, 16, 0, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 5, 1
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, ANIM_TARGET, 2, 5, 5
	delay 4
	playsewithpan SE_W010, SOUND_PAN_TARGET
	createsprite gUnknown_08593B38, ANIM_TARGET, 2, -16, 0, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 7, 1
	end

Move_INGRAIN:
	loadspritegfx ANIM_TAG_ROOTS
	loadspritegfx ANIM_TAG_ORBS
	createsprite gIngrainRootSpriteTemplate, ANIM_ATTACKER, 2, 16, 26, -1, 2, 150
	playsewithpan SE_W010, SOUND_PAN_ATTACKER
	delay 10
	createsprite gIngrainRootSpriteTemplate, ANIM_ATTACKER, 2, -32, 20, 1, 1, 140
	playsewithpan SE_W010, SOUND_PAN_ATTACKER
	delay 10
	createsprite gIngrainRootSpriteTemplate, ANIM_ATTACKER, 2, 32, 22, 1, 0, 130
	playsewithpan SE_W010, SOUND_PAN_ATTACKER
	delay 10
	createsprite gIngrainRootSpriteTemplate, ANIM_ATTACKER, 2, -16, 25, -1, 3, 120
	playsewithpan SE_W010, SOUND_PAN_ATTACKER
	delay 40
	createsprite gIngrainOrbSpriteTemplate, ANIM_ATTACKER, 3, 32, 26, -1, 3, 30
	delay 5
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	createsprite gIngrainOrbSpriteTemplate, ANIM_ATTACKER, 3, -48, 20, 1, 2, 30
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 5
	createsprite gIngrainOrbSpriteTemplate, ANIM_ATTACKER, 3, 48, 26, -2, 3, 18
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	delay 10
	waitforvisualfinish
	end

Move_PRESENT:
	loadspritegfx ANIM_TAG_ITEM_BAG
	createvisualtask AnimTask_IsHealingMove, 2
	createsprite gPresentSpriteTemplate, ANIM_TARGET, 2, 0, -5, 10, 2, -1
	playsewithpan SE_W039, SOUND_PAN_ATTACKER
	delay 14
	playsewithpan SE_W145B, SOUND_PAN_ATTACKER
	delay 14
	playsewithpan SE_W145B, 0
	delay 20
	playsewithpan SE_W145B, SOUND_PAN_TARGET
	waitforvisualfinish
	jumpretfalse PresentDamage
	jumprettrue PresentHeal
	end

PresentDamage:
	loadspritegfx ANIM_TAG_EXPLOSION
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 3, 0, 0, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 3, 24, -24, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 3, -16, 16, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 3, -24, -12, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_TARGET, 3, 16, 16, 1, 1
	end

PresentHeal:
	loadspritegfx ANIM_TAG_GREEN_SPARKLE
	loadspritegfx ANIM_TAG_BLUE_STAR
	playsewithpan SE_W234, SOUND_PAN_TARGET
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, -16, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, 16, 32, -3, -1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, 32, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, -32, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, 0, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, -8, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, -8, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, 24, 32, -3, 1
	delay 3
	createsprite gPresentHealParticleSpriteTemplate, ANIM_TARGET, 4, -24, 32, -3, 1
	waitforvisualfinish
	waitsound
	call HealingEffect2
	end

Move_BATON_PASS:
	loadspritegfx ANIM_TAG_POKEBALL
	playsewithpan SE_W226, SOUND_PAN_ATTACKER
	createvisualtask sub_8115A04, 2, 31, 1, 2, 0, 11, RGB(31, 22, 30)
	createsprite gUnknown_085CE370, ANIM_ATTACKER, 2
	end

Move_PERISH_SONG:
	loadspritegfx ANIM_TAG_MUSIC_NOTES_2
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 0, 0, 0
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 1, 1, 16
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 2, 1, 32
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 3, 2, 48
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 4, 2, 64
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 5, 0, 80
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 6, 0, 96
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 7, 1, 112
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 8, 2, 128
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 9, 0, 144
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 10, 2, 160
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 11, 0, 176
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 12, 1, 192
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 13, 3, 208
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 14, 3, 224
	createsprite gUnknown_08593C0C, ANIM_ATTACKER, 4, 15, 0, 240
	createsprite gUnknown_08593C24, ANIM_ATTACKER, 4, 15, 0, 0
	delay 20
	panse_1B SE_W195, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	delay 80
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 0, 16, RGB_BLACK
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 4, 0
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 5, 0
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 6, 0
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 7, 0
	delay 100
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 16, 0, RGB_BLACK
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 4, 1
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 5, 1
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 6, 1
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, 7, 1
	waitforvisualfinish
	end

Move_SLEEP_TALK:
	loadspritegfx ANIM_TAG_LETTER_Z
	createvisualtask AnimTask_SwayMon, 5, 0, 4, 4096, 2, ANIM_ATTACKER
	delay 20
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -1
	playsewithpan SE_W173, SOUND_PAN_ATTACKER
	delay 6
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -1
	delay 6
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -1
	delay 20
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -5
	playsewithpan SE_W173, SOUND_PAN_ATTACKER
	delay 6
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -5
	delay 6
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -5
	delay 20
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -3
	playsewithpan SE_W173, SOUND_PAN_ATTACKER
	delay 6
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -3
	delay 6
	createsprite gUnknown_085CE190, ANIM_TARGET, 2, 0, 20, 5, -3
	waitforvisualfinish
	end

Move_HYPER_FANG:
	loadspritegfx ANIM_TAG_FANG_ATTACK
	playsewithpan SE_W044, SOUND_PAN_TARGET
	delay 1
	delay 2
	createvisualtask AnimTask_IsContest, 2
	jumprettrue HyperFangInContest
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse HyperFangOnOpponent
	goto HyperFangOnPlayer
HyperFangContinue:
	waitbgfadeout
	createsprite gUnknown_085CE1DC, ANIM_TARGET, 2
	waitbgfadein
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 0, 10, 10, 1
	playsewithpan SE_W043, SOUND_PAN_TARGET
	delay 20
	restorebg
	waitbgfadein
	waitforvisualfinish
	end
HyperFangOnOpponent:
	fadetobg BG_IMPACT_OPPONENT
	goto HyperFangContinue
HyperFangOnPlayer:
	fadetobg BG_IMPACT_PLAYER
	goto HyperFangContinue
HyperFangInContest:
	fadetobg BG_IMPACT_CONTESTS
	goto HyperFangContinue

Move_TRI_ATTACK:
	loadspritegfx ANIM_TAG_TRI_FORCE_TRIANGLE
	createsprite gUnknown_085CE2F8, ANIM_TARGET, 2, 16, 0
	playsewithpan SE_W161, SOUND_PAN_ATTACKER
	delay 20
	playsewithpan SE_W161, SOUND_PAN_ATTACKER
	delay 20
	createsoundtask sub_8158C58, SE_W161, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 5, 6, 0, 7
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 16, RGB_BLACK
	delay 16
	loadspritegfx ANIM_TAG_FIRE
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, -1, 0
	playsewithpan SE_W172B, SOUND_PAN_TARGET
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 0, 1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, -1, -1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 2, 1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 1, -1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, -1, 1
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 1, -2
	delay 1
	createsprite gUnknown_08595410, ANIM_TARGET, 2, 0, 0, 30, 30, 3, 1
	delay 2
	createvisualtask sub_810A094, 2, 20, 3, 1, 1
	waitforvisualfinish
	loadspritegfx ANIM_TAG_LIGHTNING
	createvisualtask sub_8115F10, 2, 257, 257, 257
	playsewithpan SE_W161B, SOUND_PAN_TARGET
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, -48
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, -16
	delay 1
	createsprite gUnknown_085956C0, ANIM_TARGET, 2, 0, 16
	delay 20
	createvisualtask sub_810A094, 2, 20, 3, 1, 0
	delay 2
	createvisualtask sub_8115F10, 2, 257, 257, 257
	waitforvisualfinish
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	call FreezeEffect1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 16, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_WILL_O_WISP:
	loadspritegfx ANIM_TAG_WISP_FIRE
	loadspritegfx ANIM_TAG_WISP_ORB
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	playsewithpan SE_W052, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W052, SOUND_PAN_ATTACKER, 10
	createvisualtask sub_8159278, 2, SOUND_PAN_ATTACKER, SOUND_PAN_ATTACKER, 1, 0
	createsprite gUnknown_0859563C, ANIM_ATTACKER, 2, 0, 0, 0
	delay 3
	createsprite gUnknown_0859563C, ANIM_ATTACKER, 3, 0, 0, 1
	delay 3
	createsprite gUnknown_0859563C, ANIM_ATTACKER, 4, 0, 0, 2
	delay 3
	createsprite gUnknown_0859563C, ANIM_ATTACKER, 4, 0, 0, 3
	delay 40
	createvisualtask sub_8159278, 2, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 2, 0
	waitforvisualfinish
	monbgprio_29
	playsewithpan SE_W172B, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 13, 1
	createsprite gUnknown_0859566C, ANIM_ATTACKER, 2, 0
	createsprite gUnknown_0859566C, ANIM_ATTACKER, 2, 42
	createsprite gUnknown_0859566C, ANIM_ATTACKER, 2, 84
	createsprite gUnknown_0859566C, ANIM_ATTACKER, 2, 126
	createsprite gUnknown_0859566C, ANIM_ATTACKER, 2, 168
	createsprite gUnknown_0859566C, ANIM_ATTACKER, 2, 210
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_ENCORE:
	loadspritegfx ANIM_TAG_SPOTLIGHT
	loadspritegfx ANIM_TAG_TAG_HAND
	createvisualtask sub_815ABEC, 2
	createvisualtask sub_8116960, 2, 248, 3, 0, 10, 0
	waitforvisualfinish
	createsprite gUnknown_085CE22C, ANIM_TARGET, 2, 0, -8
	createsprite gUnknown_085CE244, ANIM_ATTACKER, 2, -2, 0, 0, 0, 9
	createsprite gUnknown_085CE244, ANIM_ATTACKER, 2, 2, 0, 1, 0, 9
	createsprite gUnknown_085CE25C, ANIM_ATTACKER, 3, -2, 0, 0, 0, 9
	createsprite gUnknown_085CE25C, ANIM_ATTACKER, 3, 2, 0, 1, 0, 9
	delay 16
	createvisualtask sub_8159244, 5, 223, SOUND_PAN_TARGET
	createvisualtask AnimTask_SwayMon, 5, 1, 8, 1536, 5, ANIM_TARGET
	waitforvisualfinish
	createvisualtask sub_8116960, 2, 248, 3, 10, 0, 1
	waitforvisualfinish
	createvisualtask sub_815AC8C, 2
	end

Move_TRICK:
	loadspritegfx ANIM_TAG_ITEM_BAG
	loadspritegfx ANIM_TAG_SPEED_DUST
	createsprite gTrickBagSpriteTemplate, ANIM_ATTACKER, 2, -40, 80
	createsprite gTrickBagSpriteTemplate, ANIM_ATTACKER, 2, -40, 208
	delay 16
	playsewithpan SE_W166, 0
	createvisualtask sub_8106020, 3
	createvisualtask sub_81060B0, 3
	delay 30
	playsewithpan SE_W104, 0
	delay 24
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W213, 0
	createvisualtask AnimTask_ShakeMon, 3, ANIM_ATTACKER, 5, 0, 7, 2
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 5, 0, 7, 2
	waitforvisualfinish
	end

Move_WISH:
	loadspritegfx ANIM_TAG_GOLD_STARS
	loadspritegfx ANIM_TAG_SPARKLE_2
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 0, 10, RGB_BLACK
	waitforvisualfinish
	panse_27 SE_W115, SOUND_PAN_TARGET, SOUND_PAN_ATTACKER, -3, 0
	createsprite gUnknown_085CE388, ANIM_ATTACKER, 40
	waitforvisualfinish
	delay 60
	loopsewithpan SE_W215, SOUND_PAN_ATTACKER, 16, 3
	call GrantingStarsEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 10, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_STOCKPILE:
	loadspritegfx ANIM_TAG_GRAY_ORB
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	createvisualtask sub_8115A04, 2, 2, 8, 1, 0, 12, RGB_WHITE
	createvisualtask sub_815B65C, 5
	call Stockpile1
	call Stockpile1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 0, 12, 0, RGB_WHITE
	end
Stockpile1:
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 55, 55, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -55, -55, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 0, 55, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 0, -55, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 55, -34, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, 55, 34, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -55, -34, 13
	delay 1
	createsprite gStockpileAbsorptionOrbSpriteTemplate, ANIM_ATTACKER, 2, -55, 34, 13
	delay 1
	return

Move_SPIT_UP:
	loadspritegfx ANIM_TAG_RED_ORB_2
	loadspritegfx ANIM_TAG_IMPACT
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask sub_815B6B4, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 8, 2
	delay 45
	playsewithpan SE_W255, SOUND_PAN_ATTACKER
	delay 3
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 0, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 32, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 64, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 96, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 128, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 160, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 192, 12
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 224, 12
	delay 5
	jumpifmoveturn 2, SpitUpStrong
	jumpifmoveturn 3, SpitUpStrongest
SpitUpContinue:
	delay 5
	createvisualtask sub_80D6388, 2, 0, 1, 8, 1, 0
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, -12, 10, 1, 1
	delay 5
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gUnknown_085973E8, ANIM_TARGET, 3, 12, -10, 1, 1
	waitforvisualfinish
	end
SpitUpStrong:
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 16
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 80
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 144
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 208
	goto SpitUpContinue
SpitUpStrongest:
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 16
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 48
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 80
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 112
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 144
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 176
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 208
	createsprite gUnknown_08593A50, ANIM_ATTACKER, 2, 240
	goto SpitUpContinue

Move_SWALLOW:
	loadspritegfx ANIM_TAG_BLUE_ORB
	loadspritegfx ANIM_TAG_BLUE_STAR
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask sub_815B778, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 8, 2
	delay 38
	playsewithpan SE_W255, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 12, 1
	call SwallowEffect
	jumpifmoveturn 2, SwallowGood
	jumpifmoveturn 3, SwallowBest
SwallowContinue:
	waitforvisualfinish
	call HealingEffect
	end
SwallowEffect:
	createsprite gUnknown_085CE418, ANIM_ATTACKER, 2, 0, -8
	delay 1
	createsprite gUnknown_085CE418, ANIM_ATTACKER, 2, -24, -8
	delay 1
	createsprite gUnknown_085CE418, ANIM_ATTACKER, 2, 16, -8
	delay 1
	createsprite gUnknown_085CE418, ANIM_ATTACKER, 2, -16, -8
	delay 1
	createsprite gUnknown_085CE418, ANIM_ATTACKER, 2, 24, -8
	delay 1
	return
SwallowGood:
	call SwallowEffect
	goto SwallowContinue
SwallowBest:
	call SwallowEffect
	call SwallowEffect
	goto SwallowContinue

Move_TRANSFORM:
	monbg ANIM_ATTACKER
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W107, SOUND_PAN_ATTACKER, 48
	createvisualtask sub_815B7D0, 2, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MORNING_SUN:
	loadspritegfx ANIM_TAG_GREEN_STAR
	loadspritegfx ANIM_TAG_BLUE_STAR
	createvisualtask sub_815BB84, 5
	delay 8
	createvisualtask sub_8116620, 10, 0x781, 8, 0, 12, RGB_WHITE
	delay 14
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	createvisualtask sub_8116620, 10, 0x781, 3, 12, 0, RGB_WHITE
	waitforvisualfinish
	waitsound
	call HealingEffect
	end
MorningSun1:
	createsprite gUnknown_085CE48C, ANIM_ATTACKER, 2, 30, 640
	delay 5
	return

Move_SWEET_SCENT:
	loadspritegfx ANIM_TAG_PINK_PETAL
	playsewithpan SE_W230, SOUND_PAN_ATTACKER
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 100, 0, 100
	delay 25
	setpan 0
	call SweetScentEffect
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 55, 0
	setpan SOUND_PAN_TARGET
	createvisualtask sub_8115A04, 2, 20, 1, 5, 5, 13, RGB(31, 21, 21)
	call SweetScentEffect
	waitforvisualfinish
	end
SweetScentEffect:
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 70, 1, 64
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 60, 0, 64
	delay 5
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 80, 1, 64
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 58, 0, 120
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 100, 0, 120
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 90, 0, 64
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 48, 0, 64
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 95, 1, 80
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 100, 0, 120
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 75, 1, 64
	delay 2
	createsprite gSweetScentPetalSpriteTemplate, ANIM_ATTACKER, 2, 85, 0, 120
	delay 2
	return

Move_HYPER_BEAM:
	loadspritegfx ANIM_TAG_ORBS
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 4, 0, 16, RGB_BLACK
	waitforvisualfinish
	delay 10
	playsewithpan SE_W063, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 4, 1
	waitforvisualfinish
	delay 30
	createsoundtask sub_8158C58, SE_W063B, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 1, 15, 0, 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 4, 50, 1
	createvisualtask sub_8115D94, 2, ANIM_TAG_ORBS, 1, 12, 31, 16, 0, 0
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 50, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 11, RGB(25, 25, 25)
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	createvisualtask sub_8116620, 10, 4, 2, 11, 0, RGB(25, 25, 25)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 4, 16, 0, RGB_BLACK
	end
HyperBeam1:
	createsprite gHyperBeamOrbSpriteTemplate, ANIM_TARGET, 2
	createsprite gHyperBeamOrbSpriteTemplate, ANIM_TARGET, 2
	delay 1
	return

Move_FLATTER:
	loadspritegfx ANIM_TAG_SPOTLIGHT
	loadspritegfx ANIM_TAG_CONFETTI
	createvisualtask sub_8159244, 5, 223, SOUND_PAN_TARGET
	createvisualtask sub_815ABEC, 2
	createvisualtask sub_8116960, 2, 248, 3, 0, 10, 0
	waitforvisualfinish
	createsprite gFlatterSpotlightSpriteTemplate, ANIM_TARGET, 2, 0, -8, 80
	delay 0
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 5, 2, ANIM_TARGET
	delay 10
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 5, 2, ANIM_TARGET
	delay 0
	createvisualtask sub_8159210, 5, 229, SOUND_PAN_ATTACKER
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	call CreateFlatterConfetti
	delay 5
	createvisualtask sub_8159210, 5, 229, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask sub_8116960, 2, 248, 3, 10, 0, 1
	waitforvisualfinish
	createvisualtask sub_815AC8C, 2
	end
CreateFlatterConfetti:
	createsprite gFlatterConfettiSpriteTemplate, ANIM_ATTACKER, 40, ANIM_ATTACKER
	createsprite gFlatterConfettiSpriteTemplate, ANIM_ATTACKER, 40, ANIM_TARGET
	return

Move_ROLE_PLAY:
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8116620, 10, 4, 2, 0, 16, RGB_WHITE
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 0, 10, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W161, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W197, SOUND_PAN_ATTACKER, 30
	createvisualtask AnimTask_RolePlaySilhouette, 2
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	createvisualtask sub_8116620, 10, 4, 2, 16, 0, RGB_WHITE
	delay 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 2, 10, 0, RGB_BLACK
	end

Move_REFRESH:
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_SPARKLE_2
	playsewithpan SE_W287, SOUND_PAN_ATTACKER
	createvisualtask sub_815DFCC, 2, 0
	waitforvisualfinish
	playsewithpan SE_W234, SOUND_PAN_ATTACKER
	call GrantingStarsEffect
	waitforvisualfinish
	playsewithpan SE_REAPOKE, SOUND_PAN_ATTACKER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 10, 0, RGB(12, 24, 30)
	createsprite gUnknown_0859381C, ANIM_ATTACKER, 3, 0, 0, 0, 0
	end

Move_BLAZE_KICK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W172, SOUND_PAN_TARGET
	createsprite gUnknown_08595F14, ANIM_TARGET, 3, 0, 0, 1, 30
	createvisualtask sub_8116620, 10, 4, 2, 0, 7, RGB_WHITE
	delay 30
	playsewithpan SE_W007, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 14, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_WHITE
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 1, RGB_BLACK, 8, 0, 0
	call FireMoveEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HYPER_VOICE:
	loadspritegfx ANIM_TAG_THIN_RING
	createvisualtask sub_81590B8, 5, 0
	call HyperVoiceEffect
	waitforvisualfinish
	delay 8
	createvisualtask sub_81590B8, 5, 1
	call HyperVoiceEffect
	waitforvisualfinish
	end
HyperVoiceEffect:
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 3, 8, 0, RGB_YELLOW
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 5, ANIM_ATTACKER, 0
	createsprite gUnknown_08593880, ANIM_ATTACKER, 0, 45, 0, 0, 0, 0, 0, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 6, 1
	createvisualtask sub_81162A4, 2, 1, 0, 6, 1
	createvisualtask sub_8159078, 5
	return

Move_SAND_TOMB:
	loadspritegfx ANIM_TAG_MUD_SAND
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 0, 7, RGB(19, 17, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 43, 1
	playsewithpan SE_W328, SOUND_PAN_TARGET
	call SandTombEffect
	call SandTombEffect
	call SandTombEffect
	delay 22
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 7, 0, RGB(19, 17, 0)
	waitforvisualfinish
	end

SandTombEffect:
	createsprite gUnknown_08596B34, ANIM_TARGET, 2, 0, 32, 528, 30, 10, 50, 1
	delay 2
	createsprite gUnknown_08596B34, ANIM_TARGET, 2, 0, 36, 480, 20, 13, -46, 1
	delay 2
	createsprite gUnknown_08596B34, ANIM_TARGET, 2, 0, 37, 576, 20, 5, 42, 1
	delay 2
	createsprite gUnknown_08596B34, ANIM_TARGET, 2, 0, 35, 400, 25, 8, -42, 1
	delay 2
	createsprite gUnknown_08596B34, ANIM_TARGET, 2, 0, 32, 512, 25, 13, 46, 1
	delay 2
	createsprite gUnknown_08596B34, ANIM_TARGET, 2, 0, 37, 464, 30, 12, -50, 1
	delay 2
	return

Move_SHEER_COLD:
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_W196, 0
	waitbgfadein
	loadspritegfx ANIM_TAG_ICE_CUBE
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_80A9EF4, 2
	waitplaysewithpan SE_W258, SOUND_PAN_TARGET, 17
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_ARM_THRUST:
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_80D6134, 5, 8, 5, 0, 0
	delay 6
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 3
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gUnknown_08596034, ANIM_TARGET, 2, 10, -8, 14, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 5, 8, 5, 0, 1
	playsewithpan SE_W003, SOUND_PAN_TARGET
	choosetwoturnanim ArmThrustRight, ArmThrustLeft
ArmThrustContinue:
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	blendoff
	end
ArmThrustRight:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, 8, 0, 1, 2
	goto ArmThrustContinue
ArmThrustLeft:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -8, 0, 1, 2
	goto ArmThrustContinue

Move_MUDDY_WATER:
	panse_1B SE_W250, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createvisualtask AnimTask_CreateSurfWave, 2, TRUE
	waitforvisualfinish
	end

Move_BULLET_SEED:
	loadspritegfx ANIM_TAG_SEED
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 30, 1
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	delay 5
	createsprite gUnknown_0859351C, ANIM_TARGET, 2, 20, 0
	waitforvisualfinish
	end

Move_DRAGON_CLAW:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loadspritegfx ANIM_TAG_CLAW_SLASH
	playsewithpan SE_W221B, SOUND_PAN_ATTACKER
	createvisualtask sub_8116620, 10, 2, 4, 0, 8, RGB(31, 19, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 15, 1
	call DragonClawEffect
	call DragonClawEffect
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 28, 528, 30, 13, 50, 0
	delay 2
	createvisualtask sub_8159210, 5, 136, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, -10, -10, 0
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, -10, 10, 0
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, -4, 1, 10, 3, 1
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 32, 480, 20, 16, -46, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 33, 576, 20, 8, 42, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 31, 400, 25, 11, -42, 0
	delay 2
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 28, 512, 25, 16, 46, 0
	delay 2
	createvisualtask sub_8159210, 5, 136, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, 10, -10, 1
	createsprite gBattleAnimSpriteTemplate_8597138, ANIM_TARGET, 2, 10, 10, 1
	createsprite gBattleAnimSpriteTemplate_85972D8, ANIM_ATTACKER, 2, -4, 1, 10, 3, 1
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 33, 464, 30, 15, -50, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 28, 528, 30, 13, 50, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 32, 480, 20, 16, -46, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 33, 576, 20, 8, 42, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 31, 400, 25, 11, -42, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 28, 512, 25, 16, 46, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 33, 464, 30, 15, -50, 0
	createvisualtask sub_8116620, 10, 2, 4, 8, 0, RGB(31, 19, 0)
	waitforvisualfinish
	end
DragonClawEffect:
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 28, 528, 30, 13, 50, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 32, 480, 20, 16, -46, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 33, 576, 20, 8, 42, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 31, 400, 25, 11, -42, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 28, 512, 25, 16, 46, 0
	delay 2
	createsprite gUnknown_08596B88, ANIM_ATTACKER, 2, 0, 33, 464, 30, 15, -50, 0
	delay 2
	return

End:
	end

Move_MUD_SHOT:
	loadspritegfx ANIM_TAG_BROWN_ORB
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 46, 1
	delay 6
	createvisualtask sub_81076C8, 5, 100
	panse_1B SE_W250, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +1, 0
	call MudShot1
	call MudShot1
	call MudShot1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 43, 1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
MudShot1:
	createsprite gUnknown_085950FC, ANIM_ATTACKER, 3, 10, 10, 0, 16
	delay 2
	createsprite gUnknown_085950FC, ANIM_ATTACKER, 3, 10, 10, 0, 16
	delay 2
	return

Move_METEOR_MASH:
	loadspritegfx ANIM_TAG_GOLD_STARS
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	panse_1B SE_W112, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +3, 0
	fadetobg BG_COSMIC
	waitbgfadein
	waitforvisualfinish
	createsprite gMeteorMashStarSpriteTemplate, ANIM_TARGET, 3, -48, -64, 72, 32, 30
	delay 10
	createsprite gMeteorMashStarSpriteTemplate, ANIM_TARGET, 3, -112, -64, 8, 32, 30
	delay 40
	createsprite gUnknown_08595F14, ANIM_TARGET, 3, 0, 0, 0, 30
	createsprite gMeteorMashStarSpriteTemplate, ANIM_TARGET, 3, -80, -64, 40, 32, 30
	delay 20
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 5, 0, 20, 1
	waitforvisualfinish
	delay 10
	restorebg
	waitbgfadein
	waitforvisualfinish
	end

Move_REVENGE:
	loadspritegfx ANIM_TAG_PURPLE_SCRATCH
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596088, ANIM_ATTACKER, 2, 10, -10
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 2, 0, 4, 2, 8, RGB_RED
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_PURPLE_SCRATCH
	loadspritegfx ANIM_TAG_PURPLE_SWIPE
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 4
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gUnknown_085960D0, ANIM_TARGET, 2, 10, -10
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_PURPLE_SWIPE
	loadspritegfx ANIM_TAG_IMPACT
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 10, 1
	createsprite gUnknown_08597400, ANIM_TARGET, 3, -10, -8, 1, 1, 8
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 8
	createsprite gUnknown_08597400, ANIM_TARGET, 3, 10, 8, 1, 1, 8
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_POISON_FANG:
	loadspritegfx ANIM_TAG_FANG_ATTACK
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	playsewithpan SE_W044, SOUND_PAN_TARGET
	createsprite gUnknown_085CE1DC, ANIM_TARGET, 2
	delay 10
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 3, 0, 10, 1
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 4, 0, 4, 0, 12, RGB(26, 0, 26)
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Move_SUBSTITUTE:
	playsewithpan SE_W213, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_MonToSubstitute, 2
	end

Move_FRENZY_PLANT:
	loadspritegfx ANIM_TAG_ROOTS
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 2, 0, 5, RGB_BLACK
	waitforvisualfinish
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 10, 8, 2, 0, 0, 100
	playsewithpan SE_W010, SOUND_PAN_ATTACKER
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, -2, 0, 1, 95
	playsewithpan SE_W010, -43
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 30, 8, -4, 0, 0, 90
	playsewithpan SE_W010, -22
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 40, -8, 4, 0, 1, 85
	playsewithpan SE_W010, 0
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 50, 8, 0, 0, 0, 85
	playsewithpan SE_W010, +21
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 60, -8, -2, 0, 1, 85
	playsewithpan SE_W010, +42
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 75, 8, 0, 0, 0, 85
	playsewithpan SE_W010, SOUND_PAN_TARGET
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 85, 16, 6, 0, 3, 80
	playsewithpan SE_W010, SOUND_PAN_TARGET
	delay 5
	createsprite gFrenzyPlantRootSpriteTemplate, ANIM_ATTACKER, 2, 85, -16, -6, 0, 2, 75
	playsewithpan SE_W010, SOUND_PAN_TARGET
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -10, 1, 3
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 8, 0, 20, 1
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, 8, 1, 3
	playsewithpan SE_W003, SOUND_PAN_TARGET
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, -3, 1, 2
	playsewithpan SE_W003, SOUND_PAN_TARGET
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -3, 1, 1, 2
	playsewithpan SE_W003, SOUND_PAN_TARGET
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, 1, 1, 1
	playsewithpan SE_W003, SOUND_PAN_TARGET
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 10, 1, 1
	playsewithpan SE_W003, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 1, 2, 5, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_METAL_SOUND:
	loadspritegfx ANIM_TAG_METAL_SOUND_WAVES
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 8, 1
	call MetalSound1
	call MetalSound1
	call MetalSound1
	call MetalSound1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	waitforvisualfinish
	end
MetalSound1:
	panse_1B SE_W103, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createsprite gUnknown_08593458, ANIM_TARGET, 2, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_FOCUS_PUNCH:
	goto FocusPunch
FocusPunchEnd:
	waitforvisualfinish
	end
FocusPunch:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	delay 1
	createvisualtask AnimTask_IsContest, 2
	jumprettrue FocusPunchInContest
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse FocusPunchOnOpponent
	jumprettrue FocusPunchOnPlayer
FocusPunchContinue:
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W207, SOUND_PAN_TARGET
	createsprite gUnknown_08596104, ANIM_TARGET, 2
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 8, 0, 24, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, 2, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, -6, 1, 0
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 8, 1, 0
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto FocusPunchEnd
FocusPunchOnOpponent:
	fadetobg BG_IMPACT_OPPONENT
	goto FocusPunchContinue
FocusPunchOnPlayer:
	fadetobg BG_IMPACT_PLAYER
	goto FocusPunchContinue
FocusPunchInContest:
	fadetobg BG_IMPACT_CONTESTS
	goto FocusPunchContinue

Move_RETURN:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_GetReturnPowerLevel, 2
	delay 2
	jumpreteq 0, ReturnWeak
	jumpreteq 1, ReturnMedium
	jumpreteq 2, ReturnStrong
	jumpreteq 3, ReturnStrongest
ReturnContinue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
ReturnWeak:
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 16, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 16, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 139, SOUND_PAN_TARGET
	goto ReturnContinue
ReturnMedium:
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 11
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 5, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 2
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	goto ReturnContinue
ReturnStrong:
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, 10, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 3, -5, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -5, 3, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	goto ReturnContinue
ReturnStrongest:
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 16, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 3, -5, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 12, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	waitforvisualfinish
	delay 4
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 8, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	waitforvisualfinish
	delay 2
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 4, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 4, 2, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	waitforvisualfinish
	call ReturnStrongest1
	call ReturnStrongest1
	call ReturnStrongest1
	call ReturnStrongest1
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -10, -8, 1, 0
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 8, 0, 24, 1
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 10, 10, 1, 0
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 3, -5, 1, 0
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, -5, 3, 1, 0
	createvisualtask sub_8159210, 5, 141, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6, 0, RGB_BLACK
	goto ReturnContinue
ReturnStrongest1:
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 4, 3, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, SOUND_PAN_ATTACKER
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask sub_8159210, 5, 123, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	waitforvisualfinish
	return

Move_COSMIC_POWER:
	loadspritegfx ANIM_TAG_SPARKLE_2
	createvisualtask sub_8159244, 5, 243, 0
	playsewithpan SE_W322, 0
	createvisualtask sub_8117610, 2, 0, 0, 15, 0
	waitforvisualfinish
	fadetobg BG_COSMIC
	waitbgfadeout
	createvisualtask sub_8117660, 2, 0, 128, 0, -1
	waitbgfadein
	delay 70
	createvisualtask sub_8159210, 5, 228, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592B7C, ANIM_ATTACKER, 2, -15, 0, 0, 0, 32, 60
	delay 8
	createsprite gUnknown_08592B7C, ANIM_ATTACKER, 2, 12, -5, 0, 0, 32, 60
	delay 40
	createvisualtask sub_8117610, 2, 0, 15, 0, 0
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	waitforvisualfinish
	end

Move_BLAST_BURN:
	loadspritegfx ANIM_TAG_FIRE_PLUME
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W221, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -32, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -20, -10, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 0, -16, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 20, -10, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 32, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 20, 10, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, 0, 16, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -20, 10, 24, 0, 0, 0
	delay 25
	playsewithpan SE_W172B, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -64, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 6, -40, -20, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 70, 0, -32, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 70, 40, -20, 24, 0, 0, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 64, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 40, 20, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, 0, 32, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -40, 20, 24, 0, 0, 0
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 25
	playsewithpan SE_W172B, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -96, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 6, -60, -30, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 70, 0, -48, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 70, 60, -30, 24, 0, 0, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -4, 3, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 12, 0, 20, 1
	createvisualtask sub_81162A4, 2, 2, 0, 10, 1
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 96, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 66, 60, 30, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, 0, 48, 24, 0, 0, 0
	createsprite gUnknown_08595428, ANIM_ATTACKER, 2, -60, 30, 24, 0, 0, 0
	createvisualtask sub_8115F10, 2, 257, 257, 257
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROCK_TOMB:
	loadspritegfx ANIM_TAG_X_SIGN
	loadspritegfx ANIM_TAG_ROCKS
	createvisualtask sub_81162A4, 2, 2, 0, 10, 1
	waitforvisualfinish
	createsprite gUnknown_08596C58, ANIM_TARGET, 2, 20, 12, 64, 114, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, SOUND_PAN_TARGET
	delay 8
	createsprite gUnknown_08596C58, ANIM_TARGET, 2, -20, 12, 64, 98, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, SOUND_PAN_TARGET
	delay 8
	createsprite gUnknown_08596C58, ANIM_TARGET, 66, 3, 6, 64, 82, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, SOUND_PAN_TARGET
	delay 8
	createsprite gUnknown_08596C58, ANIM_TARGET, 2, -3, 13, 64, 66, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, SOUND_PAN_TARGET
	delay 24
	playsewithpan SE_W063, SOUND_PAN_TARGET
	createsprite gUnknown_085967AC, ANIM_TARGET, 5, 1, 50
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 20, 1
	createvisualtask sub_81162A4, 2, 2, 0, 10, 1
	waitforvisualfinish
	end
	
SetBugBg:
	createvisualtask sub_8116664, 10, 1, 0, 0, 4, RGB_BLACK
	createvisualtask AnimTask_GetAttackerSide, 2
	jumprettrue SetBugBgPlayer
	fadetobg BG_BUG_OPPONENT
	waitbgfadeout
	createvisualtask sub_8117660, 5, 1536, 0, 0, -1
	goto SetBugBgFade
SetBugBgPlayer:
	fadetobg BG_BUG_PLAYER
	waitbgfadeout
	createvisualtask sub_8117660, 5, -1536, 0, 0, -1
SetBugBgFade:
	delay 0
	createvisualtask sub_8116620, 10, 1, 0, 4, 4, RGB_BLACK
	waitbgfadein
	return
	
UnsetBugBg:
	restorebg
	waitbgfadeout
	createvisualtask sub_8116664, 10, 1, 0, 4, 0, RGB_BLACK
	setarg 7, -1
	waitbgfadein
	return

Move_SILVER_WIND:
	loadspritegfx ANIM_TAG_SPARKLE_6
	panse_1B SE_W016, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	playsewithpan SE_W234, 0
	delay 0
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	delay 0
	call SetBugBg
	createsprite gUnknown_08592830, ANIM_TARGET, 66, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592830, ANIM_TARGET, 66, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592830, ANIM_ATTACKER, 120, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592830, ANIM_ATTACKER, 120, -40, 14, 128, 4, 1, 2, 1
	delay 0
	createsprite gUnknown_08592848, ANIM_TARGET, 66, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592848, ANIM_TARGET, 66, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592848, ANIM_ATTACKER, 120, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592848, ANIM_ATTACKER, 120, -40, 14, 128, 4, 1, 2, 1
	delay 0
	createsprite gUnknown_08592860, ANIM_TARGET, 66, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592860, ANIM_TARGET, 66, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592860, ANIM_ATTACKER, 120, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592860, ANIM_ATTACKER, 120, -40, 14, 128, 4, 1, 2, 1
	delay 6
	createsprite gUnknown_08592830, ANIM_TARGET, 66, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592830, ANIM_TARGET, 66, -16, 12, 192, 5, 2, 3, 1
	delay 0
	createsprite gUnknown_08592848, ANIM_TARGET, 66, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592848, ANIM_TARGET, 66, -16, 12, 192, 5, 2, 3, 1
	delay 0
	createsprite gUnknown_08592860, ANIM_TARGET, 66, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592860, ANIM_TARGET, 66, -16, 12, 192, 5, 2, 3, 1
	waitforvisualfinish
	playsewithpan SE_W016B, SOUND_PAN_TARGET
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	call UnsetBugBg
	end

Move_SNATCH:
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -12, 4, 10, 10, 12, 6
	end

Move_DIVE:
	loadspritegfx ANIM_TAG_SPLASH
	loadspritegfx ANIM_TAG_SWEAT_BEAD
	choosetwoturnanim DiveSetUp, DiveAttack
DiveSetUp:
	loadspritegfx ANIM_TAG_ROUND_SHADOW
	playsewithpan SE_W029, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596490, ANIM_ATTACKER, 2, 0, 0, 13, 336
	waitforvisualfinish
	playsewithpan SE_W291, SOUND_PAN_ATTACKER
	createsprite gUnknown_085964CC, ANIM_ATTACKER, 3, 0
	call DiveSetUp1
	call DiveSetUp1
	call DiveSetUp1
	call DiveSetUp1
	call DiveSetUp1
	end
DiveSetUp1:
	createsprite gUnknown_085964E4, ANIM_ATTACKER, 5, 0, 0
	createsprite gUnknown_085964E4, ANIM_ATTACKER, 5, 1, 0
	return
DiveAttack:
	loadspritegfx ANIM_TAG_WATER_IMPACT
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W153, SOUND_PAN_TARGET
	createsprite gUnknown_085964CC, ANIM_TARGET, 3, 1
	call DiveAttack1
	call DiveAttack1
	call DiveAttack1
	call DiveAttack1
	call DiveAttack1
	delay 12
	call UnderWaterAttack1
	waitforvisualfinish
	visible ANIM_ATTACKER
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
DiveAttack1:
	createsprite gUnknown_085964E4, ANIM_TARGET, 5, 0, 1
	createsprite gUnknown_085964E4, ANIM_TARGET, 5, 1, 1
	return

Move_ROCK_BLAST:
	loadspritegfx ANIM_TAG_ROCKS
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 3
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596C98, ANIM_TARGET, 2, 16, 0, 0, 0, 25, 257
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	createsprite gUnknown_08596B1C, ANIM_TARGET, 2, 0, 0, 20, 24, 14, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 5, 1
	createsprite gUnknown_08596B1C, ANIM_TARGET, 2, 5, 0, -20, 24, 14, 1
	createsprite gUnknown_08596B1C, ANIM_TARGET, 2, 0, 5, 20, -24, 14, 2
	createsprite gUnknown_08596B1C, ANIM_TARGET, 2, -5, 0, -20, -24, 14, 2
	waitforvisualfinish
	end

Move_OVERHEAT:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 18
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 5, RGB(28, 0, 0)
	waitforvisualfinish
	createvisualtask sub_8117C44, 5
	waitforvisualfinish
	createvisualtask sub_8117CA0, 5, 0, 1
	delay 1
	createvisualtask sub_8117DD8, 5, 0
	delay 1
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	createvisualtask sub_8117CA0, 5, 1, 0
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 1, 0, 13, RGB(28, 0, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 2, 0, 15, 1
	waitforvisualfinish
	playsewithpan SE_W172B, SOUND_PAN_ATTACKER
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 0, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 32, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 64, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 96, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 128, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 160, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 192, 30, 25, -20
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 224, 30, 25, -20
	delay 5
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 0, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 32, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 64, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 96, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 128, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 160, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 192, 30, 25, 0
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 224, 30, 25, 0
	delay 5
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 0, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 32, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 64, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 96, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 2, 1, 128, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 160, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 192, 30, 25, 10
	createsprite gUnknown_08596FB0, ANIM_ATTACKER, 66, 1, 224, 30, 25, 10
	delay 5
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -5, 3, 1, 0
	playsewithpan SE_W007, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 10, 0, 25, 1
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 8, -5, 1, 0
	playsewithpan SE_W007, SOUND_PAN_TARGET
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 10, 10, 1, 0
	playsewithpan SE_W007, SOUND_PAN_TARGET
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 0
	playsewithpan SE_W007, SOUND_PAN_TARGET
	createvisualtask sub_8117DD8, 5, 1
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, -1, 0, 13, RGB(18, 18, 18)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 3, 0, 15, 1
	waitforvisualfinish
	createvisualtask sub_8117D3C, 5, 0, 1
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 5, 0, RGB(28, 0, 0)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	delay 15
	createvisualtask sub_8117D3C, 5, 1, 0
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 0, 13, 0, RGB(18, 18, 18)
	waitforvisualfinish
	createvisualtask sub_8117C70, 5
	waitforvisualfinish
	end

Move_HYDRO_CANNON:
	loadspritegfx ANIM_TAG_WATER_ORB
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W057, SOUND_PAN_ATTACKER
	createsprite gUnknown_085951C0, ANIM_TARGET, 2
	delay 10
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 30
	panse_1B SE_W056, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	call HydroCannon1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 10, 0, 40, 1
	createsprite gUnknown_08597388, ANIM_TARGET, 2, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, ANIM_TARGET, 2, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, ANIM_TARGET, 2, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, ANIM_TARGET, 2, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, ANIM_TARGET, 2, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, ANIM_TARGET, 2, 0, 0, 1, 0
	waitforvisualfinish
	createvisualtask sub_8115F10, 2, 257, 257, 257
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
HydroCannon1:
	createsprite gUnknown_085951D8, ANIM_TARGET, 2, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, ANIM_TARGET, 2, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, ANIM_TARGET, 2, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, ANIM_TARGET, 2, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, ANIM_TARGET, 2, 10, -10, 0, 0, 15, 257
	return

Move_ASTONISH:
	loadspritegfx ANIM_TAG_SWEAT_BEAD
	playsewithpan SE_W227, SOUND_PAN_ATTACKER
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 25
	createsprite gUnknown_085964E4, ANIM_TARGET, 5, 0, 1
	playsewithpan SE_W166, SOUND_PAN_TARGET
	createsprite gUnknown_085964E4, ANIM_TARGET, 5, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 5, 1
	createvisualtask sub_8106020, 3
	waitforvisualfinish
	end

Move_SEISMIC_TOSS:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ROCKS
	setarg 7, 0
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	waitforvisualfinish
	createvisualtask AnimTask_GetSeismicTossDamageLevel, 3
	delay 1
	fadetobg BG_IN_AIR
	waitbgfadeout
	createvisualtask sub_811152C, 3
	playsewithpan SE_W327, 0
	waitbgfadein
	waitforvisualfinish
	createvisualtask sub_8111590, 3
	jumpreteq 0, SeismicTossWeak
	jumpreteq 1, SeismicTossMedium
	jumpreteq 2, SeismicTossStrong
SeismicTossContinue:
	restorebg
	waitbgfadeout
	setarg 7, 0xFFF
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
SeismicTossWeak:
	call SeismicToss1
	delay 16
	call SeismicToss2
	goto SeismicTossContinue
SeismicTossMedium:
	call SeismicToss1
	delay 14
	call SeismicToss2
	delay 14
	call SeismicToss1
	goto SeismicTossContinue
SeismicTossStrong:
	call SeismicToss2
	delay 10
	call SeismicToss1
	delay 10
	call SeismicToss2
	delay 10
	call SeismicToss1
	goto SeismicTossContinue
SeismicToss1:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -10, -8, 1, 1
	playsewithpan SE_W070, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -12, 27, 2, 3
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 8, 28, 3, 4
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -4, 30, 2, 3
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 12, 25, 4, 4
	return
SeismicToss2:
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 10, -8, 1, 1
	playsewithpan SE_W088, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -12, 32, 3, 4
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 8, 31, 2, 2
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -4, 28, 2, 3
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 12, 30, 4, 3
	return

Move_MAGIC_COAT:
	loadspritegfx ANIM_TAG_ORANGE_LIGHT_WALL
	setalpha 0, 16
	waitplaysewithpan SE_W112, SOUND_PAN_ATTACKER, 15
	createsprite gUnknown_085965C0, ANIM_ATTACKER, 3, 40, 0, 10170
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_WATER_PULSE:
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_BLUE_RING_2
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	playsewithpan SE_W145C, SOUND_PAN_ATTACKER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 0, 7, RGB(0, 25, 28)
	delay 10
	createsprite gUnknown_085952F8, ANIM_ATTACKER, 66, 100, 100, 8, 1, 20, 40, 0
	createsprite gUnknown_085952F8, ANIM_ATTACKER, 66, 20, 100, 16, 2, 10, 35, 1
	createsprite gUnknown_085952F8, ANIM_ATTACKER, 66, 200, 80, 8, 1, 40, 20, 0
	createsprite gUnknown_085952F8, ANIM_ATTACKER, 66, 80, 60, 10, 3, 20, 50, 0
	createsprite gUnknown_085952F8, ANIM_ATTACKER, 66, 140, 100, 16, 1, 20, 30, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	waitforvisualfinish
	playsewithpan SE_W202, SOUND_PAN_ATTACKER
	createsprite gUnknown_08593470, ANIM_TARGET, 2, 0, 0, 40, 15
	delay 5
	playsewithpan SE_W202, SOUND_PAN_ATTACKER
	createsprite gUnknown_08593470, ANIM_TARGET, 2, 0, 0, 40, 15
	delay 5
	playsewithpan SE_W202, SOUND_PAN_ATTACKER
	createsprite gUnknown_08593470, ANIM_TARGET, 2, 0, 0, 40, 15
	delay 13
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 8, 18, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 7, 0, RGB(0, 25, 28)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_PSYCHO_BOOST:
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	monbg ANIM_ATK_PARTNER
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A5C8, 5
	waitbgfadein
	delay 6
	createvisualtask sub_8115A04, 2, 1, 2, 8, 0, 10, RGB_BLACK
	delay 0
	monbgprio_28 ANIM_ATTACKER
	setalpha 8, 8
	delay 10
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 3, 0, 240, 0
	loopsewithpan SE_W060B, SOUND_PAN_ATTACKER, 14, 10
	createsprite gUnknown_08596920, ANIM_ATTACKER, 2
	delay 110
	loopsewithpan SE_W060B, SOUND_PAN_ATTACKER, 7, 10
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, -8, 1, 24, 1
	playsewithpan SE_W043, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	call UnsetPsychicBg
	end

Move_KNOCK_OFF:
	loadspritegfx ANIM_TAG_SLAM_HIT_2
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 4
	playsewithpan SE_W233, SOUND_PAN_TARGET
	createsprite gKnockOffStrikeSpriteTemplate, ANIM_TARGET, 2, -16, -16
	delay 8
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 5, 1, RGB_WHITE, 10, 0, 0
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, 0, 1, 2
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -12, 10, 0, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	delay 10
	waitforvisualfinish
	end

Move_DOOM_DESIRE:
	createvisualtask sub_8114960, 2
	delay 1
	monbg ANIM_ATK_PARTNER
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_TARGET, 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 4, RGB_BLACK
	waitforvisualfinish
	setalpha 8, 8
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -4, -4, 15, ANIM_ATTACKER, 1
	waitforvisualfinish
	delay 20
	createvisualtask AnimTask_SetGreyscaleOrOriginalPal, 5, ANIM_TARGET, 1
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 4, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_SKY_UPPERCUT:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	fadetobg BG_IN_AIR
	waitbgfadeout
	playsewithpan SE_W327, SOUND_PAN_ATTACKER
	createvisualtask sub_810DABC, 5, 55
	waitbgfadein
	setalpha 12, 8
	delay 38
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 28, 0, 0, 5
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 6, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -28, 28, 1, 1
	delay 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -15, 8, 1, 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	delay 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -5, -12, 1, 1
	delay 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 0, -32, 1, 1
	delay 1
	playsewithpan SE_W233B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 5, -52, 1, 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -26, 16, 1, 4
	delay 4
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	delay 30
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 6
	delay 4
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	end

Move_SECRET_POWER:
	createvisualtask AnimTask_GetBattleTerrain, 5
	jumpargeq 0, BATTLE_TERRAIN_GRASS, Move_NEEDLE_ARM
	jumpargeq 0, BATTLE_TERRAIN_LONG_GRASS, Move_MAGICAL_LEAF
	jumpargeq 0, BATTLE_TERRAIN_SAND, Move_MUD_SHOT
	jumpargeq 0, BATTLE_TERRAIN_UNDERWATER, Move_WATERFALL
	jumpargeq 0, BATTLE_TERRAIN_WATER, Move_SURF
	jumpargeq 0, BATTLE_TERRAIN_POND, Move_BUBBLE_BEAM
	jumpargeq 0, BATTLE_TERRAIN_MOUNTAIN, Move_ROCK_THROW
	jumpargeq 0, BATTLE_TERRAIN_CAVE, Move_BITE
	jumpargeq 0, BATTLE_TERRAIN_BUILDING, Move_STRENGTH
	goto Move_SLAM

Move_TWISTER:
	loadspritegfx ANIM_TAG_LEAF
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ROCKS
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	playsewithpan SE_W239, SOUND_PAN_TARGET
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 120, 70, 5, 70, 30
	delay 1
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 115, 55, 6, 60, 25
	delay 1
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 115, 60, 7, 60, 30
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 115, 55, 10, 60, 30
	delay 3
	createsprite gUnknown_08596CC8, ANIM_TARGET, 2, 100, 50, 4, 50, 26
	delay 1
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 105, 25, 8, 60, 20
	delay 1
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 115, 40, 10, 48, 30
	delay 3
	createsprite gUnknown_08596CC8, ANIM_TARGET, 2, 120, 30, 6, 45, 25
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 115, 35, 10, 60, 30
	delay 3
	createsprite gUnknown_08596CC8, ANIM_TARGET, 2, 105, 20, 8, 40, 0
	delay 3
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 20, 255, 15, 32, 0
	createsprite gTwisterLeafParticleSpriteTemplate, ANIM_TARGET, 2, 110, 10, 8, 32, 20
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, -32, -16, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 12, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_DEF_PARTNER, 3, 0, 12, 1
	delay 4
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_085973A0, ANIM_TARGET, 3, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 3, 32, 20, 1, 3
	playsewithpan SE_W004, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_MAGICAL_LEAF:
	loadspritegfx ANIM_TAG_LEAF
	loadspritegfx ANIM_TAG_RAZOR_LEAF
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 1
	loopsewithpan SE_W077, SOUND_PAN_ATTACKER, 10, 5
	createvisualtask sub_81007C4, 5
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -3, -2, 10
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -1, -1, 15
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -4, -4, 7
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 3, -3, 11
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -1, -6, 8
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 2, -1, 12
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -3, -4, 13
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 4, -5, 7
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, 2, -6, 11
	delay 2
	createsprite gRazorLeafParticleSpriteTemplate, ANIM_ATTACKER, 2, -3, -5, 8
	delay 60
	playsewithpan SE_W013B, SOUND_PAN_ATTACKER
	createsprite gRazorLeafCutterSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 32, 20, 0
	createsprite gRazorLeafCutterSpriteTemplate, ANIM_TARGET, 3, 20, -10, 20, 0, 32, -20, 0
	delay 30
	playsewithpan SE_W013, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, -10, -4, 1, 2
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, 10, 4, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	delay 20
	setarg 7, -1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ICE_BALL:
	loadspritegfx ANIM_TAG_ICE_CHUNK
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	createvisualtask AnimTask_GetRolloutCounter, 5, 0
	jumpargeq 0, 4, IceBallSetIceBg
IceBallContinue:
	playsewithpan SE_W196, SOUND_PAN_ATTACKER
	createsprite gUnknown_08595DE4, ANIM_TARGET, 2, 15, 0, -12, -16, 30, -40
	delay 28
	playsewithpan SE_W280, SOUND_PAN_TARGET
	createvisualtask AnimTask_GetRolloutCounter, 5, 0
	jumpargeq 0, 0, IceBallWeakest
	jumpargeq 0, 1, IceBallWeak
	jumpargeq 0, 2, IceBallMediun
	jumpargeq 0, 3, IceBallStrong
	jumpargeq 0, 4, IceBallStrongest
IceBallContinue2:
	createvisualtask AnimTask_GetRolloutCounter, 5, 0
	jumpargeq 0, 4, IceBallUnsetIceBg
IceBallEnd:
	end
IceBallSetIceBg:
	fadetobg BG_ICE
	goto IceBallContinue
IceBallUnsetIceBg:
	waitbgfadein
	delay 45
	restorebg
	waitbgfadein
	goto IceBallEnd
IceBallWeakest:
	createvisualtask sub_80D6388, 2, 0, 1, 8, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallWeak:
	createvisualtask sub_80D6388, 2, 0, 1, 10, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallMediun:
	createvisualtask sub_80D6388, 2, 0, 1, 14, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallStrong:
	createvisualtask sub_80D6388, 2, 0, 1, 18, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallStrongest:
	createvisualtask sub_80D6388, 2, 0, 1, 30, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBall1:
	createsprite gUnknown_08595DFC, ANIM_TARGET, 4, -12, -16
	return

Move_WEATHER_BALL:
	loadspritegfx ANIM_TAG_WEATHER_BALL
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 8, 1, ANIM_ATTACKER
	delay 8
	playsewithpan SE_W207, SOUND_PAN_ATTACKER
	createsprite gUnknown_0853EE38, ANIM_ATTACKER, 2
	waitforvisualfinish
	delay 15
	playsewithpan SE_W197, 0
	createsprite gComplexPaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 31, 5, 1, RGB_WHITE, 10, 0, 0
	waitforvisualfinish
	createvisualtask AnimTask_GetWeather, 2
	delay 1
	jumpreteq ANIM_WEATHER_NONE, WeatherBallNormal
	jumpreteq ANIM_WEATHER_SUN, WeatherBallFire
	jumpreteq ANIM_WEATHER_RAIN, WeatherBallWater
	jumpreteq ANIM_WEATHER_SANDSTORM, WeatherBallSandstorm
	jumpreteq ANIM_WEATHER_HAIL, WeatherBallIce
WeatherBallNormal:
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gUnknown_0853EE50, ANIM_TARGET, 2, -30, -100, 25, 1, 0, 0
	waitforvisualfinish
	playsewithpan SE_W025B, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 4, -10, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 8, 1
	waitforvisualfinish
	end
WeatherBallFire:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	createsprite gUnknown_0859559C, ANIM_TARGET, 2, -30, -100, 25, 1, 40, 10
	playsewithpan SE_W172, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_0859559C, ANIM_TARGET, 2, -30, -100, 25, 1, -40, 20
	playsewithpan SE_W172, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_0859559C, ANIM_TARGET, 2, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W172, SOUND_PAN_TARGET
	waitforvisualfinish
	playsewithpan SE_W172B, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 8, 1
	waitforvisualfinish
	end
WeatherBallWater:
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	createsprite gUnknown_08595328, ANIM_TARGET, 2, -30, -100, 25, 1, 50, 10
	playsewithpan SE_W152, SOUND_PAN_TARGET
	delay 8
	createsprite gUnknown_08595328, ANIM_TARGET, 2, -30, -100, 25, 1, -20, 20
	playsewithpan SE_W152, SOUND_PAN_TARGET
	delay 13
	createsprite gUnknown_08595328, ANIM_TARGET, 2, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W152, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 8, 1
	playsewithpan SE_W202, SOUND_PAN_TARGET
	waitforvisualfinish
	end
WeatherBallSandstorm:
	loadspritegfx ANIM_TAG_ROCKS
	createsprite gUnknown_08596CE0, ANIM_TARGET, 2, -30, -100, 25, 1, 30, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 5
	createsprite gUnknown_08596CE0, ANIM_TARGET, 2, -30, -100, 25, 1, -40, 20
	playsewithpan SE_W088, SOUND_PAN_TARGET
	delay 14
	createsprite gUnknown_08596CE0, ANIM_TARGET, 2, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W088, SOUND_PAN_TARGET
	waitforvisualfinish
	playsewithpan SE_W070, SOUND_PAN_TARGET
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -12, 27, 2, 3
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 8, 28, 3, 4
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, -4, 30, 2, 3
	createsprite gUnknown_08596CB0, ANIM_TARGET, 2, 12, 25, 4, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	waitforvisualfinish
	end
WeatherBallIce:
	loadspritegfx ANIM_TAG_HAIL
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	createsprite gUnknown_08595D44, ANIM_TARGET, 2, -30, -100, 25, 25, -40, 20
	playsewithpan SE_W258, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_08595D44, ANIM_TARGET, 2, -30, -100, 25, 25, 40, 0
	playsewithpan SE_W258, SOUND_PAN_TARGET
	delay 10
	createsprite gUnknown_08595D44, ANIM_TARGET, 2, -30, -100, 25, 25, 0, 0
	playsewithpan SE_W258, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	call FreezeEffect1
	waitforvisualfinish
	end

Move_COUNT:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

FreezeEffect1:
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, -10, -10, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 10, 20, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, -5, 10, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 17, -12, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, -15, 15, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 0, 0, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, 20, 2, 0
	playsewithpan SE_W196, SOUND_PAN_TARGET
	return

FreezeEffect2:
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, -10, -10, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 10, 20, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, -29, 0, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 29, -20, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, -5, 10, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 17, -12, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, -20, 0, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, -15, 15, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 26, -5, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B80, ANIM_TARGET, 2, 0, 0, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	delay 4
	createsprite gUnknown_08595B68, ANIM_TARGET, 2, 20, 2, 1
	playsewithpan SE_W196, SOUND_PAN_TARGET
	return

IcyWindEffect1: @ Unused
	loopsewithpan SE_W196, SOUND_PAN_TARGET, 6, 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 0, 24, 0
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 8, 24, 0
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -8, 24, 0
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 16, 24, 0
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -16, 24, 0
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 24, 24, 0
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -24, 24, 0
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 32, 24, 0
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -32, 24, 0
	return

IcyWindEffect2:
	loopsewithpan SE_W196, SOUND_PAN_TARGET, 6, 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 0, 24, 1
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 8, 24, 1
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -8, 24, 1
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 16, 24, 1
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -16, 24, 1
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 24, 24, 1
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -24, 24, 1
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 32, 24, 1
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -32, 24, 1
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 40, 24, 1
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -40, 24, 1
	delay 4
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, 48, 24, 1
	createsprite gUnknown_08595C04, ANIM_TARGET, 2, -48, 24, 1
	return

GrantingStarsEffect:
	createsprite gUnknown_08592B7C, ANIM_ATTACKER, 2, -15, 0, 0, 0, 32, 60
	delay 8
	createsprite gUnknown_08592B7C, ANIM_ATTACKER, 2, 12, -5, 0, 0, 32, 60
	delay 8
	return

HealingEffect:
	playsewithpan SE_W071B, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592F2C, ANIM_ATTACKER, 2, 0, -5, 0, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_ATTACKER, 2, -15, 10, 0, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_ATTACKER, 2, -15, -15, 0, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_ATTACKER, 2, 10, -5, 0, 0
	delay 7
	return

HealingEffect2:
	playsewithpan SE_W071B, SOUND_PAN_TARGET
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, 0, -5, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, -15, 10, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, -15, -15, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, ANIM_TARGET, 2, 10, -5, 1, 0
	delay 7
	return

PoisonBubblesEffect:
	createsprite gPoisonBubbleSpriteTemplate, ANIM_TARGET, 2, 10, 10, 0
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, ANIM_TARGET, 2, 20, -20, 0
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, ANIM_TARGET, 2, -20, 15, 0
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, ANIM_TARGET, 2, 0, 0, 0
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, ANIM_TARGET, 2, -20, -20, 0
	playsewithpan SE_W092, SOUND_PAN_TARGET
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, ANIM_TARGET, 2, 16, -8, 0
	playsewithpan SE_W092, SOUND_PAN_TARGET
	return

WaterBubbleEffect:
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 10, 10, 0
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 20, -20, 0
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, -20, 15, 0
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 0
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, -20, -20, 0
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 16, -8, 0
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	return

WaterBubbleEffect2:
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 10, 10, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, -28, -10, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 20, -20, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, -20, 15, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 27, 8, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, -20, -20, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	delay 6
	createsprite gWaterBubbleSpriteTemplate, ANIM_ATTACKER, 2, 16, -8, 1
	playsewithpan SE_W145C, SOUND_PAN_TARGET
	return

ElectricityEffect:
	playsewithpan SE_W085B, SOUND_PAN_TARGET
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, 5, 0, 5, 0
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, -5, 10, 5, 1
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, 15, 20, 5, 2
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, -15, -10, 5, 0
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, 25, 0, 5, 1
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, -8, 8, 5, 2
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, 2, -8, 5, 0
	delay 2
	createsprite gElectricitySpriteTemplate, ANIM_TARGET, 2, -20, 15, 5, 1
	return

ConfusionEffect:
	loopsewithpan SE_W146, SOUND_PAN_TARGET, 13, 6
	createsprite gConfusionDuckSpriteTemplate, ANIM_TARGET, 2, 0, -15, 0, 3, 90
	createsprite gConfusionDuckSpriteTemplate, ANIM_TARGET, 2, 0, -15, 51, 3, 90
	createsprite gConfusionDuckSpriteTemplate, ANIM_TARGET, 2, 0, -15, 102, 3, 90
	createsprite gConfusionDuckSpriteTemplate, ANIM_TARGET, 2, 0, -15, 153, 3, 90
	createsprite gConfusionDuckSpriteTemplate, ANIM_TARGET, 2, 0, -15, 204, 3, 90
	return

SetPsychicBackground:
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A504, 5
	waitbgfadein
	return

UnsetPsychicBg:
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	return

SetSkyBg:
	jumpifcontest SetSkyBgContest
	fadetobg BG_SKY
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 768, 1, -1
SetSkyBgContinue:
	waitbgfadein
	return
SetSkyBgContest:
	fadetobg BG_SKY_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 5, 2304, 768, 0, -1
	goto SetSkyBgContinue

UnsetSkyBg:
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	return

SetSolarbeamBg:
	createvisualtask AnimTask_IsContest, 2
	jumprettrue SetSolarbeamBgContest
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse SetSolarbeamBgOpponent
	goto SetSolarbeamBgPlayer
SetSolarbeamBgContinue:
	waitbgfadein
	return
SetSolarbeamBgContest:
	fadetobg BG_SOLARBEAM_CONTESTS
	goto SetSolarbeamBgContinue
SetSolarbeamBgPlayer:
	fadetobg BG_SOLARBEAM_PLAYER
	goto SetSolarbeamBgContinue
SetSolarbeamBgOpponent:
	fadetobg BG_SOLARBEAM_OPPONENT
	goto SetSolarbeamBgContinue

UnsetSolarbeamBg:
	restorebg
	waitbgfadein
	return

Status_Poison:
	loopsewithpan SE_W092, SOUND_PAN_TARGET, 13, 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 18, 2
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 12, RGB(30, 0, 31)
	end

Status_Confusion:
	loadspritegfx ANIM_TAG_DUCK
	call ConfusionEffect
	end

Status_Burn:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	playsewithpan SE_W172, SOUND_PAN_TARGET
	call Burn1
	call Burn1
	call Burn1
	waitforvisualfinish
	end
Burn1:
	createsprite gUnknown_08595504, ANIM_TARGET, 2, -24, 24, 24, 24, 20, 1, 1
	delay 4
	return

Status_Infatuation:
	loadspritegfx ANIM_TAG_MAGENTA_HEART
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 0, 20
	delay 15
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, -20, 20
	delay 15
	playsewithpan SE_W204, SOUND_PAN_ATTACKER
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 20, 20
	end

Status_Sleep:
	loadspritegfx ANIM_TAG_LETTER_Z
	playsewithpan SE_W173, SOUND_PAN_ATTACKER
	createsprite gUnknown_08592C88, ANIM_ATTACKER, 2, 4, -10, 16, 0, 0
	delay 30
	createsprite gUnknown_08592C88, ANIM_ATTACKER, 2, 4, -10, 16, 0, 0
	end

Status_Paralysis:
	loadspritegfx ANIM_TAG_SPARK_2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 10, 1
	call ElectricityEffect
	end

Status_Freeze:
	playsewithpan SE_W196, 0
	loadspritegfx ANIM_TAG_ICE_CUBE
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	waitplaysewithpan SE_W258, SOUND_PAN_TARGET, 17
	createvisualtask sub_80A9EF4, 2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Status_Curse:
	loadspritegfx ANIM_TAG_GHOSTLY_SPIRIT
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8596DE8, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 14, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Status_Nightmare:
	loadspritegfx ANIM_TAG_DEVIL
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_8596E00, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 14, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end
	
Status_Powder:
	end

General_CastformChange:
	createvisualtask sub_815BB18, 2
	jumpreteq 1, AnimScript_82D7ECA
	goto AnimScript_82D7EB2
AnimScript_82D7EB2:
	monbg ANIM_ATTACKER
	playsewithpan SE_W100, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_W107, SOUND_PAN_ATTACKER, 48
	createvisualtask sub_815B7D0, 2, 1, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end
AnimScript_82D7ECA:
	createvisualtask sub_815BB58, 2, 1
	end

General_StatsChange:
	createvisualtask AnimTask_StatsChange, 5
	waitforvisualfinish
	end

General_SubstituteFade:
	monbg ANIM_ATTACKER
	createvisualtask sub_8172D98, 5
	createvisualtask sub_8116620, 10, 2, 0, 0, 16, RGB_WHITE
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_ATTACKER
	delay 2
	blendoff
	createvisualtask sub_8116620, 10, 2, 0, 0, 0, RGB_WHITE
	createvisualtask sub_8172BF0, 2, 1
	end

General_SubstituteAppear:
	createvisualtask AnimTask_MonToSubstitute, 2
	end

General_PokeblockThrow:
	createvisualtask sub_817345C, 2, 0
	createvisualtask AnimTask_LoadPokeblockGfx, 2
	delay 0
	waitplaysewithpan SE_W026, SOUND_PAN_ATTACKER, 22
	createsprite gPokeblockSpriteTemplate, ANIM_TARGET, 3, -18, 12, 0, 32
	delay 50
	loopsewithpan SE_W039, SOUND_PAN_TARGET, 19, 2
	createvisualtask AnimTask_SwayMon, 5, 1, 8, 1536, 2, ANIM_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_FreePokeblockGfx, 2
	end

General_ItemKnockoff:
	loadspritegfx ANIM_TAG_ITEM_BAG
	createsprite gKnockOffItemSpriteTemplate, ANIM_TARGET, 2
	end

General_TurnTrap:
	createvisualtask AnimTask_GetTrappedMoveAnimId, 5
	jumpargeq 0, TRAP_ANIM_FIRE_SPIN, Status_FireSpin
	jumpargeq 0, TRAP_ANIM_WHIRLPOOL, Status_Whrilpool
	jumpargeq 0, TRAP_ANIM_CLAMP, Status_Clamp
	jumpargeq 0, TRAP_ANIM_SAND_TOMB, Status_SandTomb
	goto Status_BindWrap
Status_BindWrap:
	loadspritegfx ANIM_TAG_TENDRILS
	loopsewithpan SE_W010, SOUND_PAN_TARGET, 6, 2
	createsprite gConstrictBindingSpriteTemplate, ANIM_TARGET, 4, 0, 16, 0, 1
	delay 7
	createsprite gConstrictBindingSpriteTemplate, ANIM_TARGET, 2, 0, 8, 1, 1
	delay 3
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	delay 20
	setarg 7, -1
	playsewithpan SE_W020, SOUND_PAN_TARGET
	waitforvisualfinish
	end
Status_FireSpin:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	playsewithpan SE_W221B, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 30, 1
	call FireSpinEffect
	call FireSpinEffect
	waitforvisualfinish
	stopsound
	end
Status_Whrilpool:
	loadspritegfx ANIM_TAG_WATER_ORB
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 0, 7, RGB(0, 13, 23)
	playsewithpan SE_W250, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 30, 1
	call WhirlpoolEffect
	call WhirlpoolEffect
	delay 12
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 7, 0, RGB(0, 13, 23)
	waitforvisualfinish
	stopsound
	clearmonbg ANIM_DEF_PARTNER
	end
Status_Clamp:
	loadspritegfx ANIM_TAG_CLAMP
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W011, SOUND_PAN_TARGET
	createsprite gUnknown_08597098, ANIM_ATTACKER, 2, -32, 0, 2, 819, 0, 10
	createsprite gUnknown_08597098, ANIM_ATTACKER, 2, 32, 0, 6, -819, 0, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end
Status_SandTomb:
	loadspritegfx ANIM_TAG_MUD_SAND
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 0, 7, RGB(19, 17, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 30, 1
	playsewithpan SE_W328, SOUND_PAN_TARGET
	call SandTombEffect
	call SandTombEffect
	delay 22
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 4, 2, 7, 0, RGB(19, 17, 0)
	waitforvisualfinish
	stopsound
	end

General_ItemEffect:
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_SPARKLE_2
	delay 0
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask sub_80D622C, 2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask sub_80D622C, 2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W036, SOUND_PAN_ATTACKER
	createvisualtask sub_80D622C, 2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W234, SOUND_PAN_ATTACKER
	call GrantingStarsEffect
	waitforvisualfinish
	playsewithpan SE_REAPOKE, SOUND_PAN_ATTACKER
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 2, 3, 7, 0, RGB(17, 31, 25)
	createsprite gUnknown_0859381C, ANIM_ATTACKER, 3, 0, 0, 0, 0
	waitforvisualfinish
	end

General_SmokeballEscape:
	loadspritegfx ANIM_TAG_PINK_CLOUD
	monbg ANIM_ATTACKER
	setalpha 12, 4
	delay 0
	playsewithpan SE_BOWA2, SOUND_PAN_TARGET
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_TARGET, 0, 0, 32, 28, 30
	delay 4
	playsewithpan SE_BOWA2, SOUND_PAN_TARGET
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 127, 2, 12, 20, 30
	delay 12
	playsewithpan SE_BOWA2, SOUND_PAN_TARGET
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 126, 2, -28, 4, 30
	delay 12
	playsewithpan SE_BOWA2, SOUND_PAN_TARGET
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 124, 2, 14, -20, 30
	delay 4
	playsewithpan SE_BOWA2, SOUND_PAN_TARGET
	createvisualtask sub_81136E8, 2, 2
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 123, 3, 4, 4, 30
	delay 14
	playsewithpan SE_BOWA2, SOUND_PAN_TARGET
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 122, 3, -14, 18, 46
	delay 0
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 121, 3, 14, -14, 46
	delay 0
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 120, 3, -12, -10, 46
	delay 0
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 119, 3, 14, 14, 46
	delay 0
	createsprite gSmokeBallEscapeCloudSpriteTemplate, ANIM_ATTACKER, 118, 3, 0, 0, 46
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	invisible ANIM_ATTACKER
	delay 0
	blendoff
	end

General_HangedOn:
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 2, 7, 0, 9, RGB_RED
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	createvisualtask sub_815DB90, 5, 30, 128, 0, 1, 2, 0, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 0, 2, 4, 9, 0, RGB_RED
	waitforvisualfinish
	delay 6
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 0, 0, 0, 15
	end

General_Rain:
	loadspritegfx ANIM_TAG_RAIN_DROPS
	playsewithpan SE_W240, SOUND_PAN_ATTACKER
	createvisualtask sub_8116620, 10, 0x781, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 60
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 60
	delay 50
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 0x781, 2, 4, 0, RGB_BLACK
	waitforvisualfinish
	end

General_Sun:
	goto Move_SUNNY_DAY

General_Sandstorm:
	goto Move_SANDSTORM

General_Hail:
	goto Move_HAIL

General_LeechSeedDrain:
	createvisualtask AnimTask_GetBattlersFromArg, 5
	delay 0
	goto Move_ABSORB

General_MonHit:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

General_ItemSteal:
	loadspritegfx ANIM_TAG_ITEM_BAG
	createvisualtask sub_8117F30, 2
	createvisualtask AnimTask_TargetToEffectBattler, 2
	delay 1
	createsprite gItemStealSpriteTemplate, ANIM_ATTACKER, 2, 0, -5, 10, 2, -1
	end

General_SnatchMove:
	loadspritegfx ANIM_TAG_ITEM_BAG
	createvisualtask sub_8117E94, 2
	call AnimScript_82D85A3
	delay 1
	createvisualtask AnimTask_SwayMon, 2, 0, 5, 5120, 4, ANIM_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_IsTargetSameSide, 2
	jumpretfalse SnatchOpposingMonMove
	goto SnatchPartnerMonMove
SnatchMoveContinue:
	waitforvisualfinish
	call AnimScript_82D85C3
	end
SnatchOpposingMonMove:
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_SnatchOpposingMonMove, 2
	goto SnatchMoveContinue
SnatchPartnerMonMove:
	playsewithpan SE_W104, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_SnatchPartnerMove, 2
	goto SnatchMoveContinue

General_FutureSightHit:
	createvisualtask sub_8117F10, 2
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W060, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	setalpha 8, 8
	playsewithpan SE_W048, SOUND_PAN_TARGET
	waitplaysewithpan SE_W048, SOUND_PAN_TARGET, 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 15, ANIM_TARGET, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 24, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	delay 1
	call UnsetPsychicBg
	end

General_DoomDesireHit:
	createvisualtask sub_8117F10, 2
	loadspritegfx ANIM_TAG_EXPLOSION
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 0, 16, RGB_WHITE
	waitforvisualfinish
	delay 10
	createvisualtask sub_815C0A4, 5
	delay 9
	playsewithpan SE_W109, SOUND_PAN_ATTACKER
	delay 9
	playsewithpan SE_W109, 0
	delay 9
	playsewithpan SE_W109, SOUND_PAN_TARGET
	delay 25
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 20, 1
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 0, 0, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 24, -24, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -16, 16, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, -24, -12, 1, 1
	delay 6
	playsewithpan SE_W120, SOUND_PAN_TARGET
	createsprite gBattleAnimSpriteTemplate_859371C, ANIM_ATTACKER, 3, 16, 16, 1, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 16, 0, RGB_WHITE
	waitforvisualfinish
	end

General_FocusPunchSetUp:
	loadspritegfx ANIM_TAG_FOCUS_ENERGY
	playsewithpan SE_W082, SOUND_PAN_ATTACKER
	call EndureEffect
	delay 8
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

General_IngrainHeal:
	loadspritegfx ANIM_TAG_ORBS
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 0, 4, RGB(13, 31, 12)
	waitforvisualfinish
	delay 3
	call AbsorbEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 1, 4, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

General_WishHeal:
	loadspritegfx ANIM_TAG_SPARKLE_2
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 0, 10, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W025, SOUND_PAN_ATTACKER
	call GrantingStarsEffect
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_SPARKLE_2
	loadspritegfx ANIM_TAG_BLUE_STAR
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, ANIM_ATTACKER, 2, 1, 3, 10, 0, RGB_BLACK
	end

General_MegaEvolution:
    loadspritegfx ANIM_TAG_MEGA_STONE
    loadspritegfx ANIM_TAG_MEGA_PARTICLES
    loadspritegfx ANIM_TAG_MEGA_SYMBOL
    monbg ANIM_ATTACKER
	setalpha 12, 8
	loopsewithpan SE_W025, SOUND_PAN_ATTACKER, 13, 3
	createvisualtask sub_8115A04, 2, 2, 0, 6, 0, 11, RGB(31, 31, 11)
	call MegaEvolutionParticles
	call MegaEvolutionParticles
	call MegaEvolutionParticles
	waitforvisualfinish
	playsewithpan SE_W076, SOUND_PAN_ATTACKER
	createsprite gMegaStoneSpriteTemplate, ANIM_ATTACKER, 41, 0, 0, 0, 0
	delay 20
	createvisualtask sub_8116664, 5, 5, 2, 0, 16, RGB_WHITEALPHA
	waitforvisualfinish
	createvisualtask sub_815B7D0, 2, 0, 1
	createvisualtask sub_8116664, 5, 5, 2, 16, 0, RGB_WHITEALPHA
	createvisualtask sub_81152DC, 5, 1, 5, 14
	waitforvisualfinish
	createsprite gMegaSymbolSpriteTemplate ANIM_ATTACKER, 2
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
    end
	
MegaEvolutionParticles:
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, 40, -10, 13
	delay 3
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, -35, -10, 13
	delay 3
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, 15, -40, 13
	delay 3
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, -10, -32, 13
	delay 3
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, 25, -20, 13
	delay 3
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, -40, -20, 13
	delay 3
	createsprite gMegaParticlesSpriteTemplate, ANIM_ATTACKER, 2, 5, -40, 13
	delay 3
	return
	
General_TerrainMisty:
	end
	
General_TerrainGrassy:
	end
	
General_TerrainElectric:
	end
	
General_TerrainPsychic:
	end

AnimScript_82D85A3:
	createvisualtask AnimTask_IsAttackerBehindSubstitute, 2
	jumprettrue AnimScript_82D85B4
AnimScript_82D85B2:
	waitforvisualfinish
	return
AnimScript_82D85B4:
	createvisualtask sub_8172BF0, 2, 1
	waitforvisualfinish
	goto AnimScript_82D85B2

AnimScript_82D85C3:
	createvisualtask AnimTask_IsAttackerBehindSubstitute, 2
	jumprettrue AnimScript_82D85D4
AnimScript_82D85D2:
	waitforvisualfinish
	return
AnimScript_82D85D4:
	createvisualtask sub_8172BF0, 2, 0
	waitforvisualfinish
	goto AnimScript_82D85D2

Special_LevelUp:
	playsewithpan SE_EXPMAX, 0
	createvisualtask sub_8170920, 2
	delay 0
	createvisualtask sub_8170A0C, 5, 0, 0
	waitforvisualfinish
	createvisualtask sub_81709EC, 2
	end

Special_SwitchOutPlayerMon:
	createvisualtask sub_8170BB0, 2
	delay 10
	createvisualtask sub_8170B04, 2
	end

Special_SwitchOutOpponentMon:
	createvisualtask sub_8170BB0, 2
	delay 10
	createvisualtask sub_8170B04, 2
	end

Special_BallThrow:
	createvisualtask sub_8170CFC, 2
	delay 0
	playsewithpan SE_NAGERU, 0
	createvisualtask sub_8170E04, 2
	createvisualtask AnimTask_IsBallBlockedByTrainer, 2
	jumpreteq -1, BallThrowTrainerBlock
BallThrowEnd:
	waitforvisualfinish
	createvisualtask sub_8170D24, 2
	end
BallThrowTrainerBlock:
	loadspritegfx ANIM_TAG_IMPACT
	delay 25
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 0
	playsewithpan SE_W003, SOUND_PAN_TARGET
	createsprite gBasicHitSplatSpriteTemplate, ANIM_TARGET, 2, -4, -20, 1, 2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto BallThrowEnd

Special_SafariBallThrow:
	createvisualtask sub_8170CFC, 2
	delay 0
	createvisualtask sub_8170F2C, 2
	waitforvisualfinish
	createvisualtask sub_8170D24, 2
	end

Special_SubstituteToMon:
	createvisualtask sub_8172BF0, 2, 1
	end

Special_MonToSubstitute:
	createvisualtask sub_8172BF0, 2, 0
	end
