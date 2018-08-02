#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
	.include "asm/macros/battle_anim_script.inc"

	.section script_data, "aw", %progbits

.align 2
gUnknown_082C8D64:: @ 82C8D64
	.2byte 0x2F, 0xC3, 0x140, 0xFFFF

.align 2
gBattleAnims_Moves:: @ 82C8D6C
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
	.4byte Move_MIRROR_MOVE @ doesn't have an actual animation
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
	.4byte Move_COUNT @ cannot be reached, because last move is Psycho Boost

.align 2
gBattleAnims_Statuses:: @ 82C92FC
	.4byte Status_Poison
	.4byte Status_Confusion
	.4byte Status_Burn
	.4byte Status_Infatuation
	.4byte Status_Sleep
	.4byte Status_Paralysis
	.4byte Status_Freeze
	.4byte Status_Curse
	.4byte Status_Nightmare

.align 2
gBattleAnims_VariousTable:: @ 82C9320
	.4byte Anim_CastformTransform
	.4byte Anim_StatChange
	.4byte Anim_SubsituteOff
	.4byte Anim_SubsituteOn
	.4byte Anim_Table_4
	.4byte Anim_ItemKnockOff
	.4byte Status_Wrap
	.4byte Anim_ItemEffect
	.4byte Anim_SmokeBallEscape
	.4byte Anim_HangedOn
	.4byte Anim_Rain
	.4byte Anim_Sun
	.4byte Anim_Sandstorm
	.4byte Anim_Hail
	.4byte Status_LeechSeed
	.4byte Anim_Hit
	.4byte Anim_ItemSteal
	.4byte Anim_SnatchMove
	.4byte Anim_FutureSightHit
	.4byte Anim_DoomDesireHit
	.4byte Anim_Table_x14
	.4byte Status_Ingrain
	.4byte Anim_WishHeal

.align 2
gBattleAnims_Special:: @ 82C937C
	.4byte Anim_LevelUp
	.4byte Anim_SwitchOutPlayer
	.4byte Anim_SwitchOutOpponent
	.4byte Anim_BallThrow
	.4byte Anim_SafariBallThrow
	.4byte Anim_SubstituteToMon
	.4byte Anim_MonToSubstitute

Move_NONE:
Move_MIRROR_MOVE:
Move_POUND:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W003, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DOUBLE_SLAP:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	choosetwoturnanim AnimScript_82C93F4, AnimScript_82C9408

AnimScript_82C93DA:
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W003, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82C93F4:
	createsprite gUnknown_08597358, 0x2, -8, 0, 1, 2
	goto AnimScript_82C93DA

AnimScript_82C9408:
	createsprite gUnknown_08597358, 0x2, 8, 0, 1, 2
	goto AnimScript_82C93DA

Move_POISON_POWDER:
	loadspritegfx 0x2751
	loadspritegfx 0x27A6
	loopsewithpan SE_W077, +63, 0xA, 0x6
	createsprite gUnknown_08592148, 0x82, -30, -22, 117, 80, 5, 1
	createsprite gUnknown_08592148, 0x82, 10, -22, 117, 80, -5, 1
	createsprite gUnknown_08592148, 0x82, -25, -22, 117, 112, 5, 3
	delay 0xF
	createsprite gUnknown_08592148, 0x82, -5, -22, 117, 80, -5, 1
	createsprite gUnknown_08592148, 0x82, 5, -22, 117, 96, 5, 1
	createsprite gUnknown_08592148, 0x82, 0, -22, 117, 69, -5, 1
	createsprite gUnknown_08592148, 0x82, -15, -22, 117, 112, 5, 2
	delay 0x1E
	createsprite gUnknown_08592148, 0x82, -15, -22, 117, 112, 5, 2
	createsprite gUnknown_08592148, 0x82, 15, -22, 117, 80, -5, 1
	createsprite gUnknown_08592148, 0x82, -10, -22, 117, 96, 7, 2
	createsprite gUnknown_08592148, 0x82, -5, -22, 117, 90, -8, 0
	delay 0x14
	createsprite gUnknown_08592148, 0x82, -10, -22, 117, 80, -5, 1
	createsprite gUnknown_08592148, 0x82, 0, -22, 117, 89, 5, 2
	createsprite gUnknown_08592148, 0x82, 20, -22, 117, 112, -8, 2
	createsprite gUnknown_08592148, 0x82, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_STUN_SPORE:
	loadspritegfx 0x2754
	loopsewithpan SE_W077, +63, 0xA, 0x6
	createsprite gUnknown_08592130, 0x82, -30, -22, 117, 80, 5, 1
	createsprite gUnknown_08592130, 0x82, 10, -22, 117, 80, -5, 1
	createsprite gUnknown_08592130, 0x82, -25, -22, 117, 112, 5, 3
	delay 0xF
	createsprite gUnknown_08592130, 0x82, -5, -22, 117, 80, -5, 1
	createsprite gUnknown_08592130, 0x82, 5, -22, 117, 96, 5, 1
	createsprite gUnknown_08592130, 0x82, 0, -22, 117, 69, -5, 1
	createsprite gUnknown_08592130, 0x82, -15, -22, 117, 112, 5, 2
	delay 0x1E
	createsprite gUnknown_08592130, 0x82, -15, -22, 117, 112, 5, 2
	createsprite gUnknown_08592130, 0x82, 15, -22, 117, 80, -5, 1
	createsprite gUnknown_08592130, 0x82, -10, -22, 117, 96, 7, 2
	createsprite gUnknown_08592130, 0x82, -5, -22, 117, 90, -8, 0
	delay 0x14
	createsprite gUnknown_08592130, 0x82, -10, -22, 117, 80, -5, 1
	createsprite gUnknown_08592130, 0x82, 0, -22, 117, 89, 5, 2
	createsprite gUnknown_08592130, 0x82, 20, -22, 117, 112, -8, 2
	createsprite gUnknown_08592130, 0x82, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_SLEEP_POWDER:
	loadspritegfx 0x2753
	loopsewithpan SE_W077, +63, 0xA, 0x6
	createsprite gUnknown_08592118, 0x82, -30, -22, 117, 80, 5, 1
	createsprite gUnknown_08592118, 0x82, 10, -22, 117, 80, -5, 1
	createsprite gUnknown_08592118, 0x82, -25, -22, 117, 112, 5, 3
	delay 0xF
	createsprite gUnknown_08592118, 0x82, -5, -22, 117, 80, -5, 1
	createsprite gUnknown_08592118, 0x82, 5, -22, 117, 96, 5, 1
	createsprite gUnknown_08592118, 0x82, 0, -22, 117, 69, -5, 1
	createsprite gUnknown_08592118, 0x82, -15, -22, 117, 112, 5, 2
	delay 0x1E
	createsprite gUnknown_08592118, 0x82, -15, -22, 117, 112, 5, 2
	createsprite gUnknown_08592118, 0x82, 15, -22, 117, 80, -5, 1
	createsprite gUnknown_08592118, 0x82, -10, -22, 117, 96, 7, 2
	createsprite gUnknown_08592118, 0x82, -5, -22, 117, 90, -8, 0
	delay 0x14
	createsprite gUnknown_08592118, 0x82, -10, -22, 117, 80, -5, 1
	createsprite gUnknown_08592118, 0x82, 0, -22, 117, 89, 5, 2
	createsprite gUnknown_08592118, 0x82, 20, -22, 117, 112, -8, 2
	createsprite gUnknown_08592118, 0x82, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_SWIFT:
	loadspritegfx 0x27BE
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592404, 0x83, 20, -10, 20, 0, 22, 20, 1
	delay 0x5
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592404, 0x83, 20, -10, 20, 5, 22, -18, 1
	delay 0x5
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592404, 0x83, 20, -10, 20, -10, 22, 15, 1
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 18, 1
	createvisualtask sub_80D52D0, 0x2, 3, 2, 0, 18, 1
	delay 0x5
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592404, 0x83, 20, -10, 20, 0, 22, -20, 1
	delay 0x5
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592404, 0x83, 20, -10, 20, 0, 22, 12, 1
	delay 0x5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRENGTH:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W036, -64
	createvisualtask sub_80D5644, 0x5, 0, 2, 0, 96, 30
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 4
	createvisualtask sub_80D5830, 0x2, 1, 18, 6, 2, 4
	delay 0x4
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x3, 16, 12, 1, 1
	delay 0x4
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x3, -16, -12, 1, 1
	delay 0x4
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x3, 3, 4, 1, 1
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TACKLE:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x6
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_BODY_SLAM:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W036, -64
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	waitforvisualfinish
	delay 0xB
	createsprite gUnknown_0857FE70, 0x2, 0, 26, 0, 0, 5
	delay 0x6
	createsprite gUnknown_08597358, 0x4, -10, 0, 1, 0
	loopsewithpan SE_W025B, +63, 0xA, 0x2
	delay 0x1
	createsprite gUnknown_0857FE70, 0x2, 1, -28, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 1, 4, 0, 12, 1
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 6
	delay 0x5
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUPERSONIC:
	loadspritegfx 0x27B3
	monbg ANIM_ATK_PARTNER
	monbgprio_2A ANIM_ATTACKER
	setalpha 0x80C
	createvisualtask sub_80D52D0, 0x2, 0, 2, 0, 8, 1
	call AnimScript_82C99FF
	call AnimScript_82C99FF
	call AnimScript_82C99FF
	call AnimScript_82C99FF
	call AnimScript_82C99FF
	call AnimScript_82C99FF
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

AnimScript_82C99FF:
	playsewithpan SE_W048, -64
	createsprite gUnknown_08593428, 0x82, 16, 0, 0, 0, 30, 0
	delay 0x2
	return

Move_SCREECH:
	loadspritegfx 0x27B4
	createvisualtask sub_80D52D0, 0x2, 0, 3, 0, 2, 1
	call AnimScript_82C9A4C
	call AnimScript_82C9A4C
	delay 0x10
	createvisualtask sub_80D5EB8, 0x5, 0, 6, 2048, 2, 1
	waitforvisualfinish
	end

AnimScript_82C9A4C:
	playsewithpan SE_W103, -64
	createsprite gUnknown_08593440, 0x82, 16, 0, 0, 0, 30, 0
	delay 0x2
	return

Move_FLAME_WHEEL:
	loadspritegfx 0x272D
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 0
	playsewithpan SE_W172, -64
	delay 0x2
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 4
	playsewithpan SE_W172, -64
	delay 0x2
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 8
	playsewithpan SE_W172, -64
	delay 0x2
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 12
	playsewithpan SE_W172, -64
	delay 0x2
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 16
	playsewithpan SE_W172, -64
	delay 0x2
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 20
	playsewithpan SE_W172, -64
	delay 0x2
	createsprite gUnknown_08595584, 0x3, 0, 0, 56, 24
	playsewithpan SE_W172, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 24, 0, 0, 6
	delay 0x4
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 8, 1
	createvisualtask sub_80A7B98, 0x3, 1, RGB_RED, 12, 1, 1
	playsewithpan SE_W172B, +63
	call AnimScript_82D2D18
	delay 0x7
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 9
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82C9B50:
	createsprite gUnknown_08595584, 0x3, 0, 0, 50
	delay 0x4
	return

Move_PIN_MISSILE:
	loadspritegfx 0x27B1
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W026, -64
	createsprite gUnknown_08596A5C, 0x2, 20, -8, -8, -8, 20, -32
	delay 0xF
	createsprite gUnknown_08596A5C, 0x2, 20, -8, 8, 8, 20, -40
	delay 0x4
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x3, -8, -8, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 2, 1
	delay 0x9
	createsprite gUnknown_08596A5C, 0x2, 20, -8, 0, 0, 20, -32
	delay 0x4
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x3, 8, 8, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 2, 1
	delay 0xE
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_ICICLE_SPEAR:
	loadspritegfx 0x2816
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W196, -64
	createsprite gUnknown_08596A74, 0x2, 20, -8, -8, -8, 20, -32
	delay 0xF
	createsprite gUnknown_08596A74, 0x2, 20, -8, 8, 8, 20, -40
	delay 0x4
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x3, -8, -8, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 2, 1
	delay 0x9
	createsprite gUnknown_08596A74, 0x2, 20, -8, 0, 0, 20, -32
	delay 0x4
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x3, 8, 8, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 2, 1
	delay 0xE
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAKE_DOWN:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_80D5C50, 0x5, 0, -24, 8, 23, 10, 40, 10
	delay 0x23
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0, 10, 0, 0
	createsprite gUnknown_08597358, 0x4, -10, 0, 1, 0
	playsewithpan SE_W025B, +63
	delay 0x1
	createsprite gUnknown_0857FE70, 0x2, 1, -16, 0, 0, 4
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 1, 4, 0, 12, 1
	waitforvisualfinish
	delay 0x2
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 5
	delay 0x3
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_EDGE:
	loadspritegfx 0x2797
	playsewithpan SE_W129, -64
	createsprite gUnknown_0859728C, 0x2, 2, 4, 2, 0x7FFF, 10, 0, 0
	waitforvisualfinish
	delay 0xA
	playsewithpan SE_W207, -64
	waitplaysewithpan SE_W207, -64, 0x8
	createvisualtask sub_80D5830, 0x2, 0, 18, 6, 2, 4
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 0, 16, 16, RGB_WHITE
	createsprite gUnknown_0857FE70, 0x2, 0, 20, 0, 0, 4
	delay 0x3
	waitforvisualfinish
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x84, -10, 0, 1, 0
	createsprite gUnknown_0857FE70, 0x2, 1, -32, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 0x2, 8, -256, 0, 0
	createvisualtask sub_80D6134, 0x2, 8, -256, 1, 0
	createvisualtask sub_80D5484, 0x2, 0, 4, 0, 12, 1
	createvisualtask sub_80D5484, 0x2, 1, 4, 0, 12, 1
	createsprite gUnknown_08597274, 0x2, 1, 2, 16, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_80D6134, 0x2, 8, -256, 0, 1
	createvisualtask sub_80D6134, 0x2, 8, -256, 1, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 5
	delay 0x3
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 7
	waitforvisualfinish
	end

Move_POISON_STING:
	loadspritegfx 0x27B1
	loadspritegfx 0x2797
	loadspritegfx 0x27A6
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W013B, -64
	createsprite gUnknown_08596A44, 0x82, 20, 0, -8, 0, 20
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 5, 1
	playsewithpan SE_W030, +63
	waitforvisualfinish
	call AnimScript_82D7A71
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TWINEEDLE:
	loadspritegfx 0x27B1
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	loopsewithpan SE_W013B, -64, 0x6, 0x2
	createsprite gUnknown_08596A44, 0x82, 10, -4, 0, -4, 20
	createsprite gUnknown_08596A44, 0x82, 20, 12, 10, 12, 20
	delay 0x14
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 5, 1
	createsprite gUnknown_08597370, 0x3, 0, -4, 1, 3
	loopsewithpan SE_W030, +63, 0x5, 0x2
	delay 0x1
	createsprite gUnknown_08597370, 0x3, 10, 12, 1, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_FIRE_BLAST:
	loadspritegfx 0x272D
	createsoundtask sub_8158B30, 144, 145
	call AnimScript_82C9FE9
	call AnimScript_82C9FE9
	call AnimScript_82C9FE9
	delay 0x18
	createvisualtask sub_8116620, 0xA, 1, 3, 0, 8, 0
	waitforvisualfinish
	delay 0x13
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 20, 1
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	delay 0x3
	call AnimScript_82CA02D
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1, 2, 8, 0, 0
	waitforvisualfinish
	end

AnimScript_82C9FE9:
	createsprite gUnknown_0859551C, 0x82, 0, 0, 0
	createsprite gUnknown_0859551C, 0x82, 0, 0, 51
	createsprite gUnknown_0859551C, 0x82, 0, 0, 102
	createsprite gUnknown_0859551C, 0x82, 0, 0, 153
	createsprite gUnknown_0859551C, 0x82, 0, 0, 204
	delay 0x5
	return

AnimScript_82CA02D:
	createsprite gUnknown_0859556C, 0x82, 0, 0, 10, 0, -2
	createsprite gUnknown_0859556C, 0x82, 0, 0, 13, -2, 0
	createsprite gUnknown_0859556C, 0x82, 0, 0, 13, 2, 0
	createsprite gUnknown_0859556C, 0x82, 0, 0, 15, -2, 2
	createsprite gUnknown_0859556C, 0x82, 0, 0, 15, 2, 2
	return

Move_LEECH_SEED:
	loadspritegfx 0x2716
	playsewithpan SE_W077, -64
	createsprite gUnknown_085922BC, 0x82, 15, 0, 0, 24, 35, -32
	delay 0x8
	playsewithpan SE_W077, -64
	createsprite gUnknown_085922BC, 0x82, 15, 0, -16, 24, 35, -40
	delay 0x8
	playsewithpan SE_W077, -64
	createsprite gUnknown_085922BC, 0x82, 15, 0, 16, 24, 35, -37
	delay 0xC
	loopsewithpan SE_W039, +63, 0xA, 0x8
	waitforvisualfinish
	end

Move_EMBER:
	loadspritegfx 0x272D
	loopsewithpan SE_W052, -64, 0x5, 0x2
	createsprite gUnknown_085954D4, 0x82, 20, 0, -16, 24, 20, 1
	delay 0x4
	createsprite gUnknown_085954D4, 0x82, 20, 0, 0, 24, 20, 1
	delay 0x4
	createsprite gUnknown_085954D4, 0x82, 20, 0, 16, 24, 20, 1
	delay 0x10
	playsewithpan SE_W172, +63
	call AnimScript_82CA135
	call AnimScript_82CA135
	call AnimScript_82CA135
	end

AnimScript_82CA135:
	createsprite gUnknown_085954EC, 0x82, -24, 24, 24, 24, 20, 1, 1
	delay 0x4
	return

Move_MEGA_PUNCH:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_TARGET
	delay 0x2
	createsprite gUnknown_08597274, 0x2, 1, 0, 0, 16, RGB_BLACK
	setalpha 0x80C
	playsewithpan SE_W025, +63
	createsprite gUnknown_08595F48, 0x3, 0, 0, 0, 50
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 7, 0x7FFF
	delay 0x32
	call AnimScript_82CA1E9
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 0
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 22, 1
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 0, 0x7FFF
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0, 8, 0, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x2
	restorebg
	waitbgfadein
	end

AnimScript_82CA1E9:
	delay 0x2
	createvisualtask sub_8117E60, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82CA220
	createvisualtask sub_815A8C8, 0x2
	jumpargeq 0x7, 0x0, AnimScript_82CA212
	jumpargeq 0x7, 0x1, AnimScript_82CA219

AnimScript_82CA211:
	return

AnimScript_82CA212:
	changebg BG_IMPACT_OPPONENT
	goto AnimScript_82CA211

AnimScript_82CA219:
	changebg BG_IMPACT_PLAYER
	goto AnimScript_82CA211

AnimScript_82CA220:
	changebg BG_IMPACT_CONTESTS
	goto AnimScript_82CA211

Move_MEGA_KICK:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_TARGET
	delay 0x2
	createsprite gUnknown_08597274, 0x2, 1, 0, 0, 16, RGB_BLACK
	setalpha 0x80C
	playsewithpan SE_W025, +63
	createsprite gUnknown_08595F48, 0x3, 0, 0, 1, 50
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 7, 0x7FFF
	delay 0x32
	playsewithpan SE_W025B, +63
	call AnimScript_82CA1E9
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 0
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 22, 1
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 0, 0x7FFF
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0, 8, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x2
	restorebg
	waitbgfadein
	end

Move_COMET_PUNCH:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_TARGET
	setalpha 0x80C
	choosetwoturnanim AnimScript_82CA2F1, AnimScript_82CA316

AnimScript_82CA2D7:
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82CA2F1:
	createsprite gUnknown_08597358, 0x2, -8, -8, 1, 2
	createsprite gUnknown_08595E98, 0x3, -8, 0, 8, 1, 0
	goto AnimScript_82CA2D7

AnimScript_82CA316:
	createsprite gUnknown_08597358, 0x2, 8, -8, 1, 2
	createsprite gUnknown_08595E98, 0x3, 8, 0, 8, 1, 0
	goto AnimScript_82CA2D7

Move_SONIC_BOOM:
	loadspritegfx 0x2713
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	call AnimScript_82CA372
	call AnimScript_82CA372
	call AnimScript_82CA372
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 10, 1
	call AnimScript_82CA38A
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82CA372:
	playsewithpan SE_W013B, -64
	createsprite gUnknown_08593398, 0x82, 16, 0, 0, 0, 15
	delay 0x4
	return

AnimScript_82CA38A:
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 2
	delay 0x4
	return

Move_THUNDER_SHOCK:
	loadspritegfx 0x2711
	loadspritegfx 0x271B
	createvisualtask sub_8116620, 0xA, 1, 0, 0, 6, 0
	waitforvisualfinish
	delay 0xA
	createvisualtask sub_810A7DC, 0x5, 0, -44, 0
	playsewithpan SE_W085, +63
	delay 0x9
	createvisualtask sub_8116620, 0xA, 4, 0, 0, 13, 0
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 4, 0, 13, 0, 0
	waitforvisualfinish
	delay 0x14
	call AnimScript_82D7BEA
	waitforvisualfinish
	delay 0x14
	createvisualtask sub_8116620, 0xA, 1, 0, 6, 0, 0
	waitforvisualfinish
	end

Move_THUNDERBOLT:
	loadspritegfx 0x2711
	loadspritegfx 0x282A
	loadspritegfx 0x271B
	createvisualtask sub_8116620, 0xA, 1, 0, 0, 6, 0
	waitforvisualfinish
	delay 0xA
	createvisualtask sub_810A7DC, 0x5, 24, -52, 0
	playsewithpan SE_W085, +63
	delay 0x7
	createvisualtask sub_810A7DC, 0x5, -24, -52, 0
	playsewithpan SE_W085, +63
	delay 0x7
	createvisualtask sub_810A7DC, 0x5, 0, -60, 1
	playsewithpan SE_W085, +63
	delay 0x9
	createvisualtask sub_8116620, 0xA, 4, 0, 0, 13, 0
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 4, 0, 13, 0, 0
	waitforvisualfinish
	delay 0x14
	createsprite gUnknown_085957E0, 0x83, 44, 0, 0, 3
	createsprite gUnknown_085957F8, 0x84, 0, 0, 32, 44, 0, 40, 0, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 32, 44, 64, 40, 1, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 32, 44, 128, 40, 0, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 32, 44, 192, 40, 2, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 16, 44, 32, 40, 0, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 16, 44, 96, 40, 1, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 16, 44, 160, 40, 0, -32765
	createsprite gUnknown_085957F8, 0x84, 0, 0, 16, 44, 224, 40, 2, -32765
	playsewithpan SE_W063, +63
	delay 0x0
	createvisualtask sub_8116620, 0xA, 1, 0, 2, 2, 0
	delay 0x6
	createvisualtask sub_8116620, 0xA, 1, 0, 6, 6, 0
	delay 0x6
	createvisualtask sub_8116620, 0xA, 1, 0, 2, 2, 0
	delay 0x6
	createvisualtask sub_8116620, 0xA, 1, 0, 6, 6, 0
	waitforvisualfinish
	delay 0x14
	waitplaysewithpan SE_W085B, +63, 0x13
	call AnimScript_82D7BEA
	waitforvisualfinish
	delay 0x14
	createvisualtask sub_8116620, 0xA, 1, 0, 6, 0, 0
	waitforvisualfinish
	end

Move_THUNDER_WAVE:
	loadspritegfx 0x2711
	loadspritegfx 0x271B
	loadspritegfx 0x27BD
	createvisualtask sub_8116620, 0xA, 1, 0, 0, 6, 0
	waitforvisualfinish
	delay 0xA
	createvisualtask sub_810A7DC, 0x5, 0, -48, 0
	playsewithpan SE_W086, +63
	delay 0x14
	loopsewithpan SE_W085B, +63, 0xA, 0x4
	createsprite gUnknown_08595840, 0x82, -16, -16
	delay 0x4
	createsprite gUnknown_08595840, 0x82, -16, 0
	delay 0x4
	createsprite gUnknown_08595840, 0x82, -16, 16
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1, 0, 6, 0, 0
	waitforvisualfinish
	end

Move_BEAT_UP:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_TARGET
	setalpha 0x80C
	choosetwoturnanim AnimScript_82CA648, AnimScript_82CA6B9

AnimScript_82CA643:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82CA648:
	createsprite gUnknown_08597358, 0x82, -20, -20, 1, 2
	createsprite gUnknown_08595E98, 0x83, -20, -12, 8, 1, 0
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	delay 0x8
	createsprite gUnknown_08597358, 0x82, 8, 0, 1, 2
	createsprite gUnknown_08595E98, 0x83, 8, 8, 8, 1, 0
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	goto AnimScript_82CA643

AnimScript_82CA6B9:
	createsprite gUnknown_08597358, 0x82, 12, -20, 1, 2
	createsprite gUnknown_08595E98, 0x83, 12, -12, 8, 1, 0
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	delay 0x8
	createsprite gUnknown_08597358, 0x82, -12, 0, 1, 2
	createsprite gUnknown_08595E98, 0x83, -12, 8, 8, 1, 0
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	goto AnimScript_82CA643

Move_STOMP:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W104, +63
	createsprite gUnknown_08595F60, 0x3, 0, -32, 15
	delay 0x13
	createsprite gUnknown_08597358, 0x2, 0, -8, 1, 1
	createvisualtask sub_80D51AC, 0x2, 1, 0, 4, 9, 1
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAIL_WHIP:
	loopsewithpan SE_W039, -64, 0x18, 0x3
	createvisualtask sub_80D5830, 0x2, 0, 12, 4, 2, 3
	waitforvisualfinish
	end

Move_CUT:
	loadspritegfx 0x279A
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W015, +63
	createsprite gUnknown_08592A1C, 0x2, 40, -32, 0
	delay 0x5
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_HIDDEN_POWER:
	loadspritegfx 0x27E9
	playsewithpan SE_W036, -64
	createvisualtask sub_80D6064, 0x5, -7, -7, 11, 0, 0
	waitforvisualfinish
	delay 0x1E
	createvisualtask sub_80A7B98, 0x5, 0, RGB(31, 31, 19), 12, 5, 1
	delay 0x4
	createvisualtask sub_80D6064, 0x5, -7, -7, 11, 0, 0
	playsewithpan SE_W179, -64
	createsprite gUnknown_08593A04, 0x2, 26, 0
	createsprite gUnknown_08593A04, 0x2, 26, 42
	createsprite gUnknown_08593A04, 0x2, 26, 84
	createsprite gUnknown_08593A04, 0x2, 26, 126
	createsprite gUnknown_08593A04, 0x2, 26, 168
	createsprite gUnknown_08593A04, 0x2, 26, 210
	delay 0x34
	setarg 0x7, 0xFFFF
	playsewithpan SE_W115, -64
	createvisualtask sub_80D6064, 0x5, -7, -7, 11, 0, 0
	createsprite gUnknown_08593A1C, 0x82, 0
	createsprite gUnknown_08593A1C, 0x82, 32
	createsprite gUnknown_08593A1C, 0x82, 64
	createsprite gUnknown_08593A1C, 0x82, 96
	createsprite gUnknown_08593A1C, 0x82, 128
	createsprite gUnknown_08593A1C, 0x82, 160
	createsprite gUnknown_08593A1C, 0x82, 192
	createsprite gUnknown_08593A1C, 0x82, 224
	end

Move_REVERSAL:
	loadspritegfx 0x27FC
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	playsewithpan SE_W197, -64
	createsprite gUnknown_0859728C, 0x2, 31, 3, 3, 0x7FFF, 8, 0, 0
	waitforvisualfinish
	delay 0x1E
	createvisualtask sub_8115A04, 0x2, 31, 3, 2, 0, 10, 0x7FFF
	delay 0xA
	playsewithpan SE_W179, -64
	createsprite gUnknown_085CE5D8, 0x2, 26, 0
	createsprite gUnknown_085CE5D8, 0x2, 26, 42
	createsprite gUnknown_085CE5D8, 0x2, 26, 84
	createsprite gUnknown_085CE5D8, 0x2, 26, 126
	createsprite gUnknown_085CE5D8, 0x2, 26, 168
	createsprite gUnknown_085CE5D8, 0x2, 26, 210
	waitforvisualfinish
	delay 0x14
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x8
	playsewithpan SE_W233B, +63
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0x7FFF, 8, 0, 0
	createsprite gUnknown_08595E98, 0x84, 0, 0, 10, 1, 0
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	createvisualtask sub_80D6388, 0x5, 0, 1, 8, 1, 0
	end

Move_PURSUIT:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	delay 0x0
	setalpha 0x80C
	choosetwoturnanim AnimScript_82CA99F, AnimScript_82CA9C8

AnimScript_82CA996:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x0
	restorebg
	waitbgfadein
	end

AnimScript_82CA99F:
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_80D6388, 0x5, 0, 1, 6, 1, 0
	goto AnimScript_82CA996

AnimScript_82CA9C8:
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	createvisualtask sub_80D6388, 0x5, 0, 1, 6, 1, 0
	goto AnimScript_82CA996

Move_SPIKE_CANNON:
	loadspritegfx 0x27B1
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D5C50, 0x5, 0, -4, 0, 4, 6, 8, 4
	waitforvisualfinish
	loopsewithpan SE_W013B, -64, 0x5, 0x3
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 5
	createsprite gUnknown_08596A44, 0x2, 10, -8, -8, -8, 20
	createsprite gUnknown_08596A44, 0x2, 18, 0, 0, 0, 20
	createsprite gUnknown_08596A44, 0x2, 26, 8, 8, 8, 20
	waitforvisualfinish
	createsprite gUnknown_08597370, 0x3, -8, -8, 1, 2
	createsprite gUnknown_08597370, 0x3, 0, 0, 1, 2
	createsprite gUnknown_08597370, 0x3, 8, 8, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 7, 1
	loopsewithpan SE_W030, +63, 0x5, 0x3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SWORDS_DANCE:
	loadspritegfx 0x2715
	monbg ANIM_ATTACKER
	setalpha 0x80C
	playsewithpan SE_W014, -64
	createvisualtask sub_80D5830, 0x2, 0, 16, 6, 1, 4
	createsprite gUnknown_08593380, 0x2, 0, 0
	delay 0x16
	createvisualtask sub_8115D94, 0x2, 10005, 2, 2, 32754, 16, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 0x1
	end

Move_PSYCH_UP:
	loadspritegfx 0x27D4
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8115B0C, 0x2, 1, 2, 6, 1, 11, 0
	setalpha 0x80C
	loopsewithpan SE_W060B, -64, 0x5, 0xA
	createsprite gUnknown_08596548, 0x2, 0, 0, 0, 0
	createvisualtask sub_80D5EB8, 0x5, 0, 5, 2560, 8, 0
	delay 0x7F
	delay 0x4
	playsewithpan SE_W060, -64
	createvisualtask sub_80D6064, 0x5, -5, -5, 10, 0, 1
	createvisualtask sub_8116620, 0x9, 2, 2, 10, 0, 1023
	delay 0x1E
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_DIZZY_PUNCH:
	loadspritegfx 0x2759
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	call AnimScript_82CAC77
	createsprite gUnknown_08595E98, 0x85, 16, 8, 20, 1, 0
	createsprite gUnknown_08597358, 0x84, 16, 0, 1, 1
	playsewithpan SE_W004, +63
	createsprite gUnknown_08595F78, 0x83, 16, 8, 160, -32
	createsprite gUnknown_08595F78, 0x83, 16, 8, -256, -40
	createsprite gUnknown_08595F78, 0x83, 16, 8, 128, -16
	createsprite gUnknown_08595F78, 0x83, 16, 8, 416, -38
	createsprite gUnknown_08595F78, 0x83, 16, 8, -128, -22
	createsprite gUnknown_08595F78, 0x83, 16, 8, -384, -31
	delay 0xA
	call AnimScript_82CAC77
	createsprite gUnknown_08595E98, 0x85, -16, -8, 20, 1, 0
	createsprite gUnknown_08597358, 0x84, -16, -16, 1, 1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08595F78, 0x83, -16, -8, 160, -32
	createsprite gUnknown_08595F78, 0x83, -16, -8, -256, -40
	createsprite gUnknown_08595F78, 0x83, -16, -8, 128, -16
	createsprite gUnknown_08595F78, 0x83, -16, -8, 416, -38
	createsprite gUnknown_08595F78, 0x83, -16, -8, -128, -22
	createsprite gUnknown_08595F78, 0x83, -16, -8, -384, -31
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82CAC77:
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x6
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 7, 1
	return

Move_FIRE_SPIN:
	loadspritegfx 0x272D
	playsewithpan SE_W221B, +63
	createvisualtask sub_80D51AC, 0x5, 1, 0, 2, 47, 1
	call AnimScript_82CACBF
	call AnimScript_82CACBF
	call AnimScript_82CACBF
	waitforvisualfinish
	end

AnimScript_82CACBF:
	createsprite gUnknown_08596B88, 0x82, 0, 28, 528, 30, 13, 50, 1
	delay 0x2
	createsprite gUnknown_08596B88, 0x82, 0, 32, 480, 20, 16, -46, 1
	delay 0x2
	createsprite gUnknown_08596B88, 0x82, 0, 33, 576, 20, 8, 42, 1
	delay 0x2
	createsprite gUnknown_08596B88, 0x82, 0, 31, 400, 25, 11, -42, 1
	delay 0x2
	createsprite gUnknown_08596B88, 0x82, 0, 28, 512, 25, 16, 46, 1
	delay 0x2
	createsprite gUnknown_08596B88, 0x82, 0, 33, 464, 30, 15, -50, 1
	delay 0x2
	return

Move_FURY_CUTTER:
	loadspritegfx 0x279A
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W013, +63
	createvisualtask sub_8107144, 0x2
	jumpargeq 0x7, 0x0, AnimScript_82CADA7
	goto AnimScript_82CADB9

AnimScript_82CAD6A:
	createvisualtask sub_8107168, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82CAD8E
	jumpargeq 0x7, 0x2, AnimScript_82CADCB
	jumpargeq 0x7, 0x3, AnimScript_82CADE5
	goto AnimScript_82CADFF

AnimScript_82CAD8E:
	delay 0x5
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

AnimScript_82CADA7:
	createsprite gUnknown_08592A1C, 0x2, 40, -32, 0
	goto AnimScript_82CAD6A

AnimScript_82CADB9:
	createsprite gUnknown_08592A1C, 0x2, 40, -32, 1
	goto AnimScript_82CAD6A

AnimScript_82CADCB:
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 10505, 4, 0, 0
	goto AnimScript_82CAD8E

AnimScript_82CADE5:
	createsprite gUnknown_0859728C, 0x2, 31, 3, 3, 10505, 4, 0, 0
	goto AnimScript_82CAD8E

AnimScript_82CADFF:
	createsprite gUnknown_0859728C, 0x2, 31, 3, 3, 10505, 4, 0, 0
	goto AnimScript_82CAD8E

Move_SELF_DESTRUCT:
	loadspritegfx 0x27D6
	createvisualtask sub_8116620, 0xA, 2, 1, 0, 9, 31
	createvisualtask sub_80D52D0, 0x5, 4, 6, 0, 38, 1
	createvisualtask sub_80D52D0, 0x5, 5, 6, 0, 38, 1
	createvisualtask sub_80D52D0, 0x5, 6, 6, 0, 38, 1
	createvisualtask sub_80D52D0, 0x5, 7, 6, 0, 38, 1
	createvisualtask sub_80D52D0, 0x5, 8, 6, 0, 38, 1
	call AnimScript_82CAE9F
	call AnimScript_82CAE9F
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 2, 1, 9, 0, 31
	end

AnimScript_82CAE9F:
	playsewithpan SE_W120, -64
	createsprite gUnknown_0859371C, 0x3, 0, 0, 0, 1
	delay 0x6
	playsewithpan SE_W120, -64
	createsprite gUnknown_0859371C, 0x3, 24, -24, 0, 1
	delay 0x6
	playsewithpan SE_W120, -64
	createsprite gUnknown_0859371C, 0x3, -16, 16, 0, 1
	delay 0x6
	playsewithpan SE_W120, -64
	createsprite gUnknown_0859371C, 0x3, -24, -12, 0, 1
	delay 0x6
	playsewithpan SE_W120, -64
	createsprite gUnknown_0859371C, 0x3, 16, 16, 0, 1
	delay 0x6
	return

Move_SLAM:
	loadspritegfx 0x2748
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W004, -64
	createsprite gUnknown_0857FE70, 0x2, 0, 20, 3, 0, 4
	delay 0x1
	createsprite gUnknown_085928D0, 0x2, 0, 0
	delay 0x3
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	createsprite gUnknown_0857FE70, 0x2, 1, -12, 10, 0, 3
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 5
	delay 0x3
	createvisualtask sub_80D5484, 0x2, 1, 0, 3, 6, 1
	waitforvisualfinish
	delay 0x5
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_VINE_WHIP:
	loadspritegfx 0x282F
	playsewithpan SE_W026, -64
	createsprite gUnknown_0857FE28, 0x2, 4, 6
	delay 0x6
	playsewithpan SE_W010, +63
	createsprite gUnknown_085928E8, 0x82, 0, 0
	delay 0x6
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 6, 1
	end

Move_DRILL_PECK:
	loadspritegfx 0x2797
	loadspritegfx 0x27B2
	createsprite gUnknown_08592CD8, 0x2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 0x2
	createsprite gUnknown_08592CD8, 0x2, 1
	delay 0x2
	loopsewithpan SE_W030, +63, 0x4, 0x8
	createvisualtask sub_810EB88, 0x5
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 18, 1
	waitforvisualfinish
	createsprite gUnknown_08592CD8, 0x2, 2
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 6
	waitforvisualfinish
	end

Move_WATERFALL:
	loadspritegfx 0x27A4
	loadspritegfx 0x27AB
	loadspritegfx 0x279D
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 23, 1
	delay 0x5
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, 10, 10, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, -15, 0, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, 20, 10, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, 0, -10, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, -10, 15, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, 25, 20, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, -20, 20, 25, 0
	delay 0x4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 0x2, 12, 0, 25, 0
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_0857FE28, 0x2, 6, 5
	delay 0x6
	call AnimScript_82CB102
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82CB102:
	playsewithpan SE_W127, +63
	createvisualtask sub_80D52D0, 0x5, 1, 4, 0, 17, 1
	createsprite gUnknown_08597388, 0x3, 0, 20, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, 20
	createsprite gUnknown_08595250, 0x4, 0, 20
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, 15, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, 15
	createsprite gUnknown_08595250, 0x4, 0, 15
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, 10, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, 10
	createsprite gUnknown_08595250, 0x4, 0, 10
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, 5, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, 5
	createsprite gUnknown_08595250, 0x4, 0, 5
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, 0, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, 0
	createsprite gUnknown_08595250, 0x4, 0, 0
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, -5, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, -5
	createsprite gUnknown_08595250, 0x4, 0, -5
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, -10, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, -10
	createsprite gUnknown_08595250, 0x4, 0, -10
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, -15, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, -15
	createsprite gUnknown_08595250, 0x4, 0, -15
	delay 0x2
	createsprite gUnknown_08597388, 0x3, 0, -20, 1, 1
	createsprite gUnknown_08595250, 0x4, 0, -20
	createsprite gUnknown_08595250, 0x4, 0, -20
	return

Move_EXPLOSION:
	loadspritegfx 0x27D6
	createsprite gUnknown_0859728C, 0x2, 1, 8, 9, 8474, 8, 0, 8
	createvisualtask sub_80D52D0, 0x5, 4, 8, 0, 40, 1
	createvisualtask sub_80D52D0, 0x5, 5, 8, 0, 40, 1
	createvisualtask sub_80D52D0, 0x5, 6, 8, 0, 40, 1
	createvisualtask sub_80D52D0, 0x5, 7, 8, 0, 40, 1
	createvisualtask sub_80D52D0, 0x5, 8, 8, 0, 40, 1
	call AnimScript_82CB312
	call AnimScript_82CB312
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1, 1, 16, 16, 0x7FFF
	delay 0x32
	createvisualtask sub_8116620, 0xA, 1, 3, 16, 0, 0x7FFF
	end

AnimScript_82CB312:
	playsewithpan SE_W153, -64
	createsprite gUnknown_0859371C, 0x3, 0, 0, 0, 1
	delay 0x6
	playsewithpan SE_W153, -64
	createsprite gUnknown_0859371C, 0x3, 24, -24, 0, 1
	delay 0x6
	playsewithpan SE_W153, -64
	createsprite gUnknown_0859371C, 0x3, -16, 16, 0, 1
	delay 0x6
	playsewithpan SE_W153, -64
	createsprite gUnknown_0859371C, 0x3, -24, -12, 0, 1
	delay 0x6
	playsewithpan SE_W153, -64
	createsprite gUnknown_0859371C, 0x3, 16, 16, 0, 1
	delay 0x6
	return

Move_DEFENSE_CURL:
	loadspritegfx 0x27FA
	loopsewithpan SE_W161, -64, 0x12, 0x3
	createvisualtask sub_811489C, 0x5, 0, 0
	createvisualtask sub_815B338, 0x5
	waitforvisualfinish
	createsprite gUnknown_085CE338, 0x2, 0, 6, 0, 1
	waitforvisualfinish
	createvisualtask sub_811489C, 0x5, 0, 1
	waitforvisualfinish
	end

Move_PROTECT:
	loadspritegfx 0x2828
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	waitplaysewithpan SE_W115, -64, 0x10
	createsprite gUnknown_08592ADC, 0x2, 24, 0, 90
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_DETECT:
	loadspritegfx 0x2757
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 2, 1, 0, 9, 0x7FFF
	delay 0x12
	playsewithpan SE_W197, -64
	createsprite gUnknown_0853EE84, 0xD, 20, -20
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_08597274, 0x2, 1, 2, 9, 0, RGB_BLACK
	createvisualtask sub_8116620, 0xA, 2, 2, 9, 0, 0x7FFF
	waitforvisualfinish
	end

Move_FRUSTRATION:
	loadspritegfx 0x2797
	loadspritegfx 0x2767
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_80A8140, 0x1
	jumpargeq 0x7, 0x0, AnimScript_82CB464
	jumpargeq 0x7, 0x1, AnimScript_82CB56A
	jumpargeq 0x7, 0x2, AnimScript_82CB637
	goto AnimScript_82CB6B3

AnimScript_82CB45F:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82CB464:
	playsewithpan SE_W082, -64
	createvisualtask sub_80D52D0, 0x5, 0, 1, 0, 15, 1
	createvisualtask sub_8116620, 0xA, 2, 3, 0, 9, 31
	waitforvisualfinish
	delay 0x14
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 0x2, 0, 20, -28
	waitforvisualfinish
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 0x2, 0, 20, -28
	waitforvisualfinish
	delay 0xA
	createvisualtask sub_80D5EB8, 0x5, 0, 16, 6144, 8, 0
	delay 0x5
	createvisualtask sub_80D52D0, 0x5, 1, 4, 0, 30, 1
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 0
	playsewithpan SE_W004, +63
	delay 0x5
	createsprite gUnknown_08597358, 0x3, 24, 8, 1, 0
	playsewithpan SE_W004, +63
	delay 0x5
	createsprite gUnknown_08597358, 0x3, -24, -16, 1, 0
	playsewithpan SE_W004, +63
	delay 0x5
	createsprite gUnknown_08597358, 0x3, 8, 4, 1, 0
	playsewithpan SE_W004, +63
	delay 0x5
	createsprite gUnknown_08597358, 0x3, -16, 19, 1, 0
	playsewithpan SE_W004, +63
	delay 0x5
	createsprite gUnknown_08597358, 0x3, 18, -18, 1, 0
	playsewithpan SE_W004, +63
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 2, 3, 9, 0, 31
	goto AnimScript_82CB45F

AnimScript_82CB56A:
	playsewithpan SE_W082, -64
	createvisualtask sub_80D52D0, 0x5, 0, 1, 0, 15, 1
	createvisualtask sub_8116620, 0xA, 2, 3, 0, 9, 31
	waitforvisualfinish
	delay 0x14
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 0x2, 0, 20, -28
	waitforvisualfinish
	delay 0x5
	createvisualtask sub_815C3A8, 0x5
	delay 0x7
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x3, 0, 8, 1, 1
	createvisualtask sub_80D52D0, 0x5, 1, 4, 0, 6, 1
	delay 0xE
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x3, 12, -6, 1, 1
	createvisualtask sub_80D52D0, 0x5, 1, 4, 0, 6, 1
	delay 0xE
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x3, -12, -6, 1, 1
	createvisualtask sub_80D52D0, 0x5, 1, 4, 0, 6, 1
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 2, 3, 9, 0, 31
	goto AnimScript_82CB45F

AnimScript_82CB637:
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 0x2, 0, 20, -28
	waitforvisualfinish
	delay 0x5
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x6
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x2, 10, 4, 1, 1
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x6
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x2, -10, -4, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 6, 1
	goto AnimScript_82CB45F

AnimScript_82CB6B3:
	createsprite gUnknown_085CE4D0, 0x2, 20, -28
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_0857FE28, 0x2, 10, 2
	delay 0xC
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 6, 1
	goto AnimScript_82CB45F

Move_SAFEGUARD:
	loadspritegfx 0x2804
	monbg ANIM_ATK_PARTNER
	setalpha 0x808
	playsewithpan SE_W208, -64
	createsprite gUnknown_08593C64, 0x2
	delay 0x4
	createsprite gUnknown_08593C64, 0x2
	delay 0x4
	createsprite gUnknown_08593C64, 0x2
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createvisualtask sub_8115A04, 0x2, 10, 0, 2, 0, 10, 0x7FFF
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_PAIN_SPLIT:
	loadspritegfx 0x27FF
	createsprite gUnknown_085CE590, 0x2, -8, -42, 0
	createsprite gUnknown_085CE590, 0x82, -8, -42, 1
	delay 0xA
	playsewithpan SE_W207B, 0
	createvisualtask sub_815CA20, 0x2, 0, 0
	createvisualtask sub_815CA20, 0x2, 1, 0
	waitforvisualfinish
	createsprite gUnknown_085CE590, 0x2, -24, -42, 0
	createsprite gUnknown_085CE590, 0x82, -24, -42, 1
	delay 0xA
	playsewithpan SE_W207B, 0
	createvisualtask sub_815CA20, 0x2, 0, 1
	createvisualtask sub_815CA20, 0x2, 1, 1
	waitforvisualfinish
	createsprite gUnknown_085CE590, 0x2, 8, -42, 0
	createsprite gUnknown_085CE590, 0x82, 8, -42, 1
	delay 0xA
	playsewithpan SE_W207B, 0
	createvisualtask sub_815CA20, 0x2, 0, 2
	createvisualtask sub_815CA20, 0x2, 1, 2
	end

Move_VICE_GRIP:
	loadspritegfx 0x279A
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W011, +63
	createsprite gUnknown_08593590, 0x2, 0
	createsprite gUnknown_08593590, 0x2, 1
	delay 0x9
	createsprite gUnknown_08597358, 0x1, 0, 0, 1, 2
	createvisualtask sub_80D52D0, 0x5, 1, 2, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_GUILLOTINE:
	loadspritegfx 0x279A
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	fadetobgfromset BG_GUILLOTINE_OPPONENT, BG_GUILLOTINE_PLAYER, BG_GUILLOTINE_CONTESTS
	waitbgfadein
	playsewithpan SE_W011, +63
	createsprite gUnknown_085935D0, 0x2, 0
	createsprite gUnknown_085935D0, 0x2, 1
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 16, 0
	delay 0x9
	createvisualtask sub_80D52D0, 0x5, 1, 2, 0, 23, 1
	delay 0x2E
	createvisualtask sub_80D52D0, 0x5, 1, 4, 0, 8, 1
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 0
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0, 8, 0, 0
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_PAY_DAY:
	loadspritegfx 0x2774
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085934D8, 0x2, 20, 0, 0, 0, 1152
	waitforvisualfinish
	playsewithpan SE_W006, +63
	createsprite gUnknown_08597358, 0x1, 0, 0, 1, 2
	createsprite gUnknown_085934F0, 0x2
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_OUTRAGE:
	loadspritegfx 0x272D
	loopsewithpan SE_W082, -64, 0x8, 0x3
	createvisualtask sub_8115A04, 0x2, 7, 2, 5, 3, 8, 430
	createvisualtask sub_80D5830, 0x2, 0, 12, 6, 5, 4
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 1280, 0, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, -1280, 0, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 0, 1280, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 0, -1280, 3
	delay 0x0
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 40, 1
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 1280, 768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, -1280, 768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 1280, -768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, -1280, -768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 1280, 0, 3
	call AnimScript_82CBA0F
	call AnimScript_82CBA0F
	waitforvisualfinish
	end

AnimScript_82CBA0F:
	delay 0x3
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, -1280, 0, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 0, 1280, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 0, -1280, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 1280, 768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, -1280, 768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, 1280, -768, 3
	delay 0x0
	createsprite gUnknown_08596E7C, 0x82, 0, 0, 30, -1280, -768, 3
	return

Move_SPARK:
	loadspritegfx 0x2797
	loadspritegfx 0x271B
	delay 0x0
	createvisualtask sub_8115A04, 0x2, 3, -31, 1, 5, 5, 23551
	playsewithpan SE_W085B, -64
	createsprite gUnknown_0859574C, 0x0, 32, 24, 190, 12, 0, 1, 0
	delay 0x0
	createsprite gUnknown_0859574C, 0x0, 80, 24, 22, 12, 0, 1, 0
	createsprite gUnknown_0859574C, 0x0, 156, 24, 121, 13, 0, 1, 1
	delay 0x0
	createvisualtask sub_8115A04, 0x2, 3, -31, 1, 0, 0, 23551
	delay 0xA
	createvisualtask sub_8115A04, 0x2, 3, -31, 1, 5, 5, 23551
	playsewithpan SE_W085B, -64
	createsprite gUnknown_0859574C, 0x0, 100, 24, 60, 10, 0, 1, 0
	createsprite gUnknown_0859574C, 0x0, 170, 24, 42, 11, 0, 1, 1
	delay 0x0
	createsprite gUnknown_0859574C, 0x0, 238, 24, 165, 10, 0, 1, 1
	delay 0x0
	createvisualtask sub_8115A04, 0x2, 3, -31, 1, 0, 0, 23551
	delay 0x14
	createvisualtask sub_8115A04, 0x2, 3, -31, 1, 7, 7, 23551
	playsewithpan SE_W085B, -64
	createsprite gUnknown_085957F8, 0x4, 0, 0, 32, 12, 0, 20, 0, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 32, 12, 64, 20, 1, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 32, 12, 128, 20, 0, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 32, 12, 192, 20, 2, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 16, 12, 32, 20, 0, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 16, 12, 96, 20, 1, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 16, 12, 160, 20, 0, 0
	createsprite gUnknown_085957F8, 0x4, 0, 0, 16, 12, 224, 20, 2, 0
	delay 0x4
	waitforvisualfinish
	createvisualtask sub_8115A04, 0x2, 3, -31, 1, 0, 0, 23551
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x4
	playsewithpan SE_W063, +63
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	createvisualtask sub_8115A04, 0x2, 4, -31, 2, 0, 6, 23551
	call AnimScript_82D7BEA
	waitforvisualfinish
	end

Move_ATTRACT:
	loadspritegfx 0x27E8
	loopsewithpan SE_W204, -64, 0xC, 0x3
	createvisualtask sub_80D5EB8, 0x5, 0, 12, 4096, 4, 0
	delay 0xF
	createsprite gUnknown_085939A0, 0x83, 20, -8
	waitforvisualfinish
	playsewithpan SE_W213, +63
	createsprite gUnknown_085939B8, 0x83, 160, -32
	createsprite gUnknown_085939B8, 0x83, -256, -40
	createsprite gUnknown_085939B8, 0x83, 128, -16
	createsprite gUnknown_085939B8, 0x83, 416, -38
	createsprite gUnknown_085939B8, 0x83, -128, -22
	createsprite gUnknown_085939B8, 0x83, -384, -31
	waitforvisualfinish
	waitplaysewithpan SE_W213B, 0, 0xF
	createvisualtask sub_81062E8, 0x5
	createsprite gUnknown_085939D0, 0x28, 16, 256, 0
	createsprite gUnknown_085939D0, 0x28, 224, 240, 15
	createsprite gUnknown_085939D0, 0x28, 126, 272, 30
	createsprite gUnknown_085939D0, 0x28, 80, 224, 45
	createsprite gUnknown_085939D0, 0x28, 170, 272, 60
	createsprite gUnknown_085939D0, 0x28, 40, 256, 75
	createsprite gUnknown_085939D0, 0x28, 112, 256, 90
	createsprite gUnknown_085939D0, 0x28, 200, 272, 90
	delay 0x4B
	createvisualtask sub_8115A04, 0x2, 4, 4, 4, 0, 10, 28479
	end

Move_GROWTH:
	call AnimScript_82CBDC0
	waitforvisualfinish
	call AnimScript_82CBDC0
	waitforvisualfinish
	end

AnimScript_82CBDC0:
	createvisualtask sub_8115A04, 0x2, 2, 0, 2, 0, 8, 0x7FFF
	playsewithpan SE_W036, -64
	createvisualtask sub_80D6064, 0x5, -3, -3, 16, 0, 0
	return

Move_WHIRLWIND:
	loadspritegfx 0x27B2
	createsprite gUnknown_085963D4, 0x2, 0, -8, 1, 60, 0
	createsprite gUnknown_085963D4, 0x2, 0, 0, 1, 60, 1
	createsprite gUnknown_085963D4, 0x2, 0, 8, 1, 60, 2
	createsprite gUnknown_085963D4, 0x2, 0, 16, 1, 60, 3
	createsprite gUnknown_085963D4, 0x2, 0, 24, 1, 60, 4
	createsprite gUnknown_085963D4, 0x2, 0, 32, 1, 60, 0
	delay 0x5
	loopsewithpan SE_W104, +63, 0xA, 0x4
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 15, 1
	delay 0x1D
	createvisualtask sub_80D5830, 0x2, 1, 12, 6, 1, 5
	delay 0x7
	playsewithpan SE_W081, +63
	createvisualtask sub_80D5DB0, 0x5, 1, 8
	waitforvisualfinish
	end

Move_CONFUSE_RAY:
	loadspritegfx 0x271D
	monbg ANIM_DEF_PARTNER
	fadetobg BG_GHOST
	waitbgfadein
	createvisualtask sub_8159278, 0x2, -64, 63, 2, 0
	createvisualtask sub_8115C80, 0x2, 10013, 0, 6, 0, 14, 351
	createsprite gUnknown_08596D14, 0x82, 28, 0, 288
	waitforvisualfinish
	setalpha 0x808
	playsewithpan SE_W081B, +63
	createsprite gUnknown_08596D2C, 0x82, 0, -16
	waitforvisualfinish
	delay 0x0
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end

Move_LOCK_ON:
	loadspritegfx 0x271E
	createsprite gUnknown_08592CA0, 0x28
	createsprite gUnknown_08592CB8, 0x28, 1
	createsprite gUnknown_08592CB8, 0x28, 2
	createsprite gUnknown_08592CB8, 0x28, 3
	createsprite gUnknown_08592CB8, 0x28, 4
	delay 0x78
	setarg 0x7, 0xFFFF
	waitforvisualfinish
	end

Move_MEAN_LOOK:
	loadspritegfx 0x27CB
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W060, -64
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 16, RGB_BLACK
	loopsewithpan SE_W109, +63, 0xF, 0x4
	waitplaysewithpan SE_W043, +63, 0x55
	createsprite gUnknown_085CE104, 0x2
	delay 0x78
	createsprite gUnknown_08597274, 0x2, 1, 2, 16, 0, RGB_BLACK
	delay 0x1E
	clearmonbg ANIM_DEF_PARTNER
	waitforvisualfinish
	end

Move_ROCK_THROW:
	loadspritegfx 0x274A
	createsprite gUnknown_085972D8, 0x82, 6, 1, 15, 1
	createsprite gUnknown_08596B04, 0x82, 0, 1, 0, 0
	playsewithpan SE_W088, +63
	delay 0x6
	createsprite gUnknown_08596B04, 0x82, 19, 1, 10, 0
	playsewithpan SE_W088, +63
	delay 0x6
	createsprite gUnknown_08596B04, 0x82, -23, 2, -10, 0
	playsewithpan SE_W088, +63
	createvisualtask sub_80D51AC, 0x2, 1, 0, 5, 20, 1
	delay 0x6
	createsprite gUnknown_08596B04, 0x82, -15, 1, -10, 0
	playsewithpan SE_W088, +63
	delay 0x6
	createsprite gUnknown_08596B04, 0x82, 23, 2, 10, 0
	playsewithpan SE_W088, +63
	waitforvisualfinish
	end

Move_ROCK_SLIDE:
	loadspritegfx 0x274A
	monbg ANIM_DEF_PARTNER
	createsprite gUnknown_085972D8, 0x2, 7, 1, 11, 1
	createsprite gUnknown_08596B04, 0x82, -5, 1, -5, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, 5, 0, 6, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, 19, 1, 10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, -23, 2, -10, 1
	playsewithpan SE_W088, +63
	createvisualtask sub_80D51AC, 0x2, 1, 0, 5, 50, 1
	createvisualtask sub_80D51AC, 0x2, 3, 0, 5, 50, 1
	delay 0x2
	call AnimScript_82CC083
	call AnimScript_82CC083
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82CC083:
	createsprite gUnknown_08596B04, 0x82, -20, 0, -10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, 28, 1, 10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, -10, 1, -5, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, 10, 0, 6, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, 24, 1, 10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, -32, 2, -10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, -20, 0, -10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	createsprite gUnknown_08596B04, 0x82, 30, 2, 10, 1
	playsewithpan SE_W088, +63
	delay 0x2
	return

Move_THIEF:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	delay 0x1
	fadetobg BG_DARK
	waitbgfadein
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x6
	playsewithpan SE_W233, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 8, 1
	waitforvisualfinish
	delay 0x14
	clearmonbg ANIM_TARGET
	blendoff
	restorebg
	waitbgfadein
	end

Move_BUBBLE_BEAM:
	loadspritegfx 0x27A2
	loadspritegfx 0x27AB
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	delay 0x1
	call AnimScript_82CC1AD
	createvisualtask sub_80D5EB8, 0x5, 0, 3, 3072, 8, 1
	call AnimScript_82CC1AD
	call AnimScript_82CC1AD
	waitforvisualfinish
	call AnimScript_82D7AE2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82CC1AD:
	createsprite gUnknown_08595068, 0x2, 18, 0, 35, 70, 0, 256, 50
	playsewithpan SE_W145, -64
	delay 0x3
	createsprite gUnknown_08595068, 0x2, 18, 0, 20, 40, -10, 256, 50
	playsewithpan SE_W145, -64
	delay 0x3
	createsprite gUnknown_08595068, 0x2, 18, 0, 10, -60, 0, 256, 50
	playsewithpan SE_W145, -64
	delay 0x3
	createsprite gUnknown_08595068, 0x2, 18, 0, 15, -15, 10, 256, 50
	playsewithpan SE_W145, -64
	delay 0x3
	createsprite gUnknown_08595068, 0x2, 18, 0, 30, 10, -10, 256, 50
	playsewithpan SE_W145, -64
	delay 0x3
	createsprite gUnknown_08595068, 0x2, 18, 0, 25, -30, 10, 256, 50
	playsewithpan SE_W145, -64
	delay 0x3
	return

Move_ICY_WIND:
	loadspritegfx 0x279D
	loadspritegfx 0x279E
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8116620, 0xA, 11, 4, 0, 4, 0
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_W196, 0
	waitbgfadein
	waitforvisualfinish
	panse_1B SE_W016, -64, +63, +2, 0x0
	call AnimScript_82CC2A8
	delay 0x5
	call AnimScript_82CC2A8
	playsewithpan SE_W016B, +63
	delay 0x37
	call AnimScript_82D78F8
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadeout
	createvisualtask sub_8116620, 0xA, 11, 4, 4, 0, 0
	waitbgfadein
	end

AnimScript_82CC2A8:
	createsprite gUnknown_08595B98, 0xA8, 0, 0, 0, 0, 72, 1
	delay 0x5
	createsprite gUnknown_08595B98, 0xA8, 0, 10, 0, 10, 72, 1
	delay 0x5
	createsprite gUnknown_08595B98, 0xA8, 0, -10, 0, -10, 72, 1
	delay 0x5
	createsprite gUnknown_08595B98, 0xA8, 0, 15, 0, 15, 72, 1
	delay 0x5
	createsprite gUnknown_08595B98, 0xA8, 0, -5, 0, -5, 72, 1
	return

Move_SMOKESCREEN:
	loadspritegfx 0x2720
	loadspritegfx 0x2721
	playsewithpan SE_W104, -64
	createsprite gUnknown_085CE050, 0x82, 20, 0, 0, 0, 35, -25
	waitforvisualfinish
	createvisualtask sub_815A160, 0x2
	delay 0x2
	playsewithpan SE_W028, +63
	createsprite gUnknown_085CE038, 0x84, 0, -12, 104, 0, 75
	createsprite gUnknown_085CE038, 0x84, 0, -12, 72, 1, 75
	createsprite gUnknown_085CE038, 0x84, 0, -6, 56, 1, 75
	createsprite gUnknown_085CE038, 0x84, 0, -6, 88, 0, 75
	createsprite gUnknown_085CE038, 0x84, 0, 0, 56, 0, 75
	createsprite gUnknown_085CE038, 0x84, 0, 0, 88, 1, 75
	createsprite gUnknown_085CE038, 0x84, 0, 6, 72, 0, 75
	createsprite gUnknown_085CE038, 0x84, 0, 6, 104, 1, 75
	createsprite gUnknown_085CE038, 0x84, 0, 12, 72, 0, 75
	createsprite gUnknown_085CE038, 0x84, 0, 12, 56, 1, 75
	createsprite gUnknown_085CE038, 0x84, 0, 18, 80, 0, 75
	createsprite gUnknown_085CE038, 0x84, 0, 18, 72, 1, 75
	waitforvisualfinish
	end

Move_CONVERSION:
	loadspritegfx 0x2722
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x10
	delay 0x0
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 0x2, -24, -24
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, -8, -24
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 8, -24
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 24, -24
	delay 0x3
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 0x2, -24, -8
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, -8, -8
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 8, -8
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 24, -8
	delay 0x3
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 0x2, -24, 8
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, -8, 8
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 8, 8
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 24, 8
	delay 0x3
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 0x2, -24, 24
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, -8, 24
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 8, 24
	delay 0x3
	createsprite gUnknown_08592E74, 0x2, 24, 24
	delay 0x14
	playsewithpan SE_W112, -64
	createvisualtask sub_8115D94, 0x2, 10018, 1, 1, 14335, 12, 0, 0
	delay 0x6
	createvisualtask sub_81022D4, 0x5
	waitforvisualfinish
	delay 0x1
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_CONVERSION_2:
	loadspritegfx 0x2722
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0x1000
	delay 0x0
	playsewithpan SE_W112, +63
	createsprite gUnknown_08592EA4, 0x2, -24, -24, 60
	createsprite gUnknown_08592EA4, 0x2, -8, -24, 65
	createsprite gUnknown_08592EA4, 0x2, 8, -24, 70
	createsprite gUnknown_08592EA4, 0x2, 24, -24, 75
	createsprite gUnknown_08592EA4, 0x2, -24, -8, 80
	createsprite gUnknown_08592EA4, 0x2, -8, -8, 85
	createsprite gUnknown_08592EA4, 0x2, 8, -8, 90
	createsprite gUnknown_08592EA4, 0x2, 24, -8, 95
	createsprite gUnknown_08592EA4, 0x2, -24, 8, 100
	createsprite gUnknown_08592EA4, 0x2, -8, 8, 105
	createsprite gUnknown_08592EA4, 0x2, 8, 8, 110
	createsprite gUnknown_08592EA4, 0x2, 24, 8, 115
	createsprite gUnknown_08592EA4, 0x2, -24, 24, 120
	createsprite gUnknown_08592EA4, 0x2, -8, 24, 125
	createsprite gUnknown_08592EA4, 0x2, 8, 24, 130
	createsprite gUnknown_08592EA4, 0x2, 24, 24, 135
	createvisualtask sub_81023E0, 0x5
	delay 0x3C
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	delay 0xA
	playsewithpan SE_W129, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROLLING_KICK:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D5830, 0x2, 0, 18, 6, 1, 4
	playsewithpan SE_W104, -64
	delay 0x6
	playsewithpan SE_W104, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 20, 0, 0, 4
	createsprite gUnknown_08595EE0, 0x2, -24, 0, 48, 10, 160, 0
	delay 0x5
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x2, -8, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 1, 8
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HEADBUTT:
	loadspritegfx 0x2797
	createsprite gUnknown_08592CD8, 0x2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 0x2
	createsprite gUnknown_08592CD8, 0x2, 1
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 0, 2, 0, 4, 1
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	createsprite gUnknown_08592CD8, 0x2, 2
	createsprite gUnknown_085973E8, 0x83, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	end

Move_HORN_ATTACK:
	loadspritegfx 0x2797
	loadspritegfx 0x2724
	createsprite gUnknown_08592CD8, 0x2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 0x2
	createsprite gUnknown_08592CD8, 0x2, 1
	createsprite gUnknown_08592F44, 0x84, 0, 0, 10
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 0, 2, 0, 4, 1
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	createsprite gUnknown_08592CD8, 0x2, 2
	createsprite gUnknown_085973E8, 0x83, 0, 0, 1, 1
	playsewithpan SE_W030, +63
	waitforvisualfinish
	end

Move_FURY_ATTACK:
	loadspritegfx 0x2797
	loadspritegfx 0x2724
	createvisualtask sub_80D6134, 0x2, 4, 256, 0, 2
	choosetwoturnanim AnimScript_82CC7B8, AnimScript_82CC7DE

AnimScript_82CC7A5:
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	waitforvisualfinish
	end

AnimScript_82CC7B8:
	createsprite gUnknown_08592F44, 0x84, 8, 8, 10
	waitforvisualfinish
	createsprite gUnknown_085973E8, 0x83, 0, 0, 1, 1
	playsewithpan SE_W030, +63
	goto AnimScript_82CC7A5

AnimScript_82CC7DE:
	createsprite gUnknown_08592F44, 0x84, -8, -8, 10
	waitforvisualfinish
	createsprite gUnknown_085973E8, 0x83, 0, 0, 1, 1
	playsewithpan SE_W030, +63
	goto AnimScript_82CC7A5

Move_HORN_DRILL:
	loadspritegfx 0x2797
	loadspritegfx 0x2724
	jumpifcontest AnimScript_82CC96A
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -2304, 768, 1, -1

AnimScript_82CC821:
	waitbgfadein
	setalpha 0x80C
	createsprite gUnknown_08592CD8, 0x2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 0x2
	createsprite gUnknown_08592CD8, 0x2, 1
	createsprite gUnknown_08592F44, 0x84, 0, 0, 12
	waitforvisualfinish
	playse SE_BAN
	createvisualtask sub_80D5484, 0x2, 0, 2, 0, 40, 1
	createvisualtask sub_80D5484, 0x2, 1, 10, 0, 40, 1
	createsprite gUnknown_085973E8, 0x83, 0, 0, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, 0, 2, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, -4, 3, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, -8, -5, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, 4, -12, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, 16, 0, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, 5, 18, 1, 3
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, -17, 12, 1, 2
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, -21, -15, 1, 2
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, 8, -27, 1, 2
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_085973E8, 0x83, 32, 0, 1, 2
	playsewithpan SE_W030, +63
	delay 0x4
	createsprite gUnknown_08592CD8, 0x2, 2
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

AnimScript_82CC96A:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, 2304, 768, 0, -1
	goto AnimScript_82CC821

Move_THRASH:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	createvisualtask sub_8104C38, 0x2
	createvisualtask sub_8104CA4, 0x2
	createsprite gUnknown_08595EB0, 0x83, 1, 10, 0
	createvisualtask sub_80D5484, 0x2, 1, 4, 0, 7, 1
	playsewithpan SE_W004, +63
	delay 0x1C
	createsprite gUnknown_08595EB0, 0x83, 1, 10, 1
	createvisualtask sub_80D5484, 0x2, 1, 4, 0, 7, 1
	playsewithpan SE_W233B, +63
	delay 0x1C
	createsprite gUnknown_08595EB0, 0x83, 1, 10, 3
	createvisualtask sub_80D5484, 0x2, 1, 8, 0, 16, 1
	playsewithpan SE_W025B, +63
	end

Move_SING:
	loadspritegfx 0x2758
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8102BE8, 0x2
	waitforvisualfinish
	panse_1B SE_W047, -64, +63, +2, 0x0
	createsprite gUnknown_08593008, 0x82, 7, 0, 12
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 6, 1, 12
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 1, 2, 12
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 2, 3, 12
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 3, 0, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 2, 1, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 5, 2, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 6, 3, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 2, 0, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 2, 1, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 1, 2, 12
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 5, 3, 12
	delay 0x4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	createvisualtask sub_8102CA0, 0x2
	waitforvisualfinish
	end

Move_LOW_KICK:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	createsprite gUnknown_0857FE70, 0x2, 0, 20, 0, 0, 4
	createsprite gUnknown_08595EE0, 0x82, -24, 28, 40, 8, 160, 0
	delay 0x4
	createsprite gUnknown_08597358, 0x82, -8, 8, 1, 2
	createvisualtask sub_80D6134, 0x2, 6, 384, 1, 2
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 1, 4
	end

Move_EARTHQUAKE:
	createvisualtask sub_81152DC, 0x5, 5, 10, 50
	createvisualtask sub_81152DC, 0x5, 4, 10, 50
	playsewithpan SE_W089, 0
	delay 0xA
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 0x10
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	end

Move_FISSURE:
	loadspritegfx 0x275A
	createvisualtask sub_81152DC, 0x3, 5, 10, 50
	createvisualtask sub_81152DC, 0x3, 1, 10, 50
	playsewithpan SE_W089, +63
	delay 0x8
	call AnimScript_82CCBFF
	delay 0xF
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 0xF
	call AnimScript_82CCC50
	delay 0xF
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 0xF
	call AnimScript_82CCBFF
	delay 0x32
	fadetobg BG_FISSURE
	waitbgfadeout
	createvisualtask sub_8115628, 0x5, 1, 5, -1
	waitbgfadein
	delay 0x28
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

AnimScript_82CCBFF:
	createsprite gUnknown_085971FC, 0x82, 1, 0, 12, -48, -16, 24
	createsprite gUnknown_085971FC, 0x82, 1, 0, 16, -16, -10, 24
	createsprite gUnknown_085971FC, 0x82, 1, 1, 14, -52, -18, 24
	createsprite gUnknown_085971FC, 0x82, 1, 1, 12, -32, -16, 24
	playsewithpan SE_W091, +63
	return

AnimScript_82CCC50:
	createsprite gUnknown_085971FC, 0x82, 1, 0, 12, -24, -16, 24
	createsprite gUnknown_085971FC, 0x82, 1, 0, 16, -38, -10, 24
	createsprite gUnknown_085971FC, 0x82, 1, 1, 14, -20, -18, 24
	createsprite gUnknown_085971FC, 0x82, 1, 1, 12, -36, -16, 24
	playsewithpan SE_W091, +63
	return

Move_DIG:
	choosetwoturnanim AnimScript_82CCCAB, AnimScript_82CCD06

AnimScript_82CCCAA:
	end

AnimScript_82CCCAB:
	loadspritegfx 0x275A
	loadspritegfx 0x2829
	createsprite gUnknown_08597214, 0x1, 0, 0, 180
	createsprite gUnknown_08597214, 0x1, 0, 1, 180
	monbg_22 ANIM_ATTACKER
	delay 0x1
	createvisualtask sub_8114CBC, 0x2, 0
	delay 0x6
	call AnimScript_82CCD6A
	call AnimScript_82CCD6A
	call AnimScript_82CCD6A
	call AnimScript_82CCD6A
	call AnimScript_82CCD6A
	waitforvisualfinish
	clearmonbg_23 ANIM_ATTACKER
	delay 0x1
	createvisualtask sub_8114CBC, 0x2, 1
	goto AnimScript_82CCCAA

AnimScript_82CCD06:
	loadspritegfx 0x2797
	loadspritegfx 0x2829
	createvisualtask sub_8114F14, 0x2, 0
	waitforvisualfinish
	monbg ANIM_ATTACKER
	createsprite gUnknown_08597214, 0x1, 0, 0, 48
	createsprite gUnknown_08597214, 0x1, 0, 1, 48
	delay 0x1
	createvisualtask sub_8114F14, 0x2, 1
	delay 0x10
	createsprite gUnknown_08597358, 0x2, -8, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	playsewithpan SE_W025B, -64
	clearmonbg ANIM_ATTACKER
	goto AnimScript_82CCCAA

AnimScript_82CCD6A:
	createsprite gUnknown_085971FC, 0x2, 0, 0, 12, 4, -16, 18
	createsprite gUnknown_085971FC, 0x2, 0, 0, 16, 4, -10, 18
	createsprite gUnknown_085971FC, 0x2, 0, 1, 14, 4, -18, 18
	createsprite gUnknown_085971FC, 0x2, 0, 1, 12, 4, -16, 18
	playsewithpan SE_W091, -64
	delay 0x20
	return

Move_MEDITATE:
	call AnimScript_82D7CD1
	createvisualtask sub_810F7D4, 0x2
	playsewithpan SE_W029, -64
	delay 0x10
	playsewithpan SE_W036, -64
	waitforvisualfinish
	call AnimScript_82D7CDD
	end

Move_AGILITY:
	monbg ANIM_ATK_PARTNER
	setalpha 0x80C
	createvisualtask sub_80D5830, 0x2, 0, 24, 6, 4, 4
	createvisualtask sub_81169C0, 0x2, 0, 4, 7, 10
	playsewithpan SE_W104, -64
	delay 0xC
	playsewithpan SE_W104, -64
	delay 0xC
	playsewithpan SE_W104, -64
	delay 0xC
	playsewithpan SE_W104, -64
	delay 0xC
	playsewithpan SE_W104, -64
	delay 0xC
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 0x1
	end

Move_QUICK_ATTACK:
	loadspritegfx 0x2797
	monbg ANIM_ATK_PARTNER
	setalpha 0x80C
	createvisualtask sub_80D5830, 0x2, 0, 24, 6, 1, 5
	createvisualtask sub_81169C0, 0x2, 0, 4, 7, 3
	playsewithpan SE_W026, -64
	delay 0x4
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	createsprite gUnknown_08597358, 0x84, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_RAGE:
	loadspritegfx 0x2797
	loadspritegfx 0x2767
	monbg ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80A7B98, 0x3, 0, RGB_RED, 10, 0, 2
	createsprite gUnknown_0859368C, 0x2, 0, -20, -28
	playsewithpan SE_W207B, -64
	delay 0x14
	createsprite gUnknown_0859368C, 0x2, 0, 20, -28
	playsewithpan SE_W207B, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE28, 0x2, 4, 6
	delay 0x4
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D6388, 0x2, 1, 1, 10, 1, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_TELEPORT:
	call AnimScript_82D7CD1
	createvisualtask sub_810F83C, 0x2
	playsewithpan SE_W100, -64
	delay 0xF
	call AnimScript_82D7CDD
	waitforvisualfinish
	end

Move_DOUBLE_TEAM:
	createvisualtask sub_81029B4, 0x2
	setalpha 0x80C
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W104, -64
	delay 0x20
	playsewithpan SE_W104, -64
	delay 0x18
	playsewithpan SE_W104, -64
	delay 0x10
	playsewithpan SE_W104, -64
	delay 0x8
	playsewithpan SE_W104, -64
	delay 0x8
	playsewithpan SE_W104, -64
	delay 0x8
	playsewithpan SE_W104, -64
	delay 0x8
	playsewithpan SE_W104, -64
	delay 0x8
	playsewithpan SE_W104, -64
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 0x1
	end

Move_MINIMIZE:
	setalpha 0x80A
	createvisualtask sub_8104674, 0x2
	loopsewithpan SE_W107, -64, 0x22, 0x3
	waitforvisualfinish
	blendoff
	end

Move_METRONOME:
	loadspritegfx 0x2750
	loadspritegfx 0x27E1
	createsprite gUnknown_08593114, 0xB, 0, 100
	playsewithpan SE_W118, -64
	delay 0x6
	createsprite gUnknown_085931BC, 0xC, 0
	delay 0x18
	loopsewithpan SE_W039, -64, 0x16, 0x3
	waitforvisualfinish
	end

Move_SKULL_BASH:
	choosetwoturnanim AnimScript_82CCF99, AnimScript_82CCFE6

AnimScript_82CCF98:
	end

AnimScript_82CCF99:
	call AnimScript_82CCFA9
	call AnimScript_82CCFA9
	waitforvisualfinish
	goto AnimScript_82CCF98

AnimScript_82CCFA9:
	createsprite gUnknown_0857FE88, 0x2, 0, -24, 0, 0, 10, 0
	playsewithpan SE_W036, -64
	waitforvisualfinish
	createvisualtask sub_80D6134, 0x2, 16, 96, 0, 2
	waitforvisualfinish
	createsprite gUnknown_0857FE88, 0x2, 0, 24, 0, 0, 10, 1
	waitforvisualfinish
	return

AnimScript_82CCFE6:
	loadspritegfx 0x2797
	createvisualtask sub_8101C94, 0x2, 0
	playsewithpan SE_W036, -64
	waitforvisualfinish
	playse SE_BAN
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	createvisualtask sub_80D5484, 0x2, 0, 2, 0, 40, 1
	createvisualtask sub_80D5484, 0x2, 1, 10, 0, 40, 1
	createsprite gUnknown_085973E8, 0x84, 0, 0, 1, 0
	loopsewithpan SE_W025B, +63, 0x8, 0x3
	waitforvisualfinish
	createvisualtask sub_8101C94, 0x2, 1
	goto AnimScript_82CCF98

Move_AMNESIA:
	loadspritegfx 0x276D
	call AnimScript_82D7CD1
	delay 0x8
	createsprite gUnknown_08596744, 0x14
	playsewithpan SE_W118, -64
	delay 0x36
	loopsewithpan SE_W118, -64, 0x10, 0x3
	waitforvisualfinish
	call AnimScript_82D7CDD
	end

Move_KINESIS:
	loadspritegfx 0x275B
	loadspritegfx 0x2771
	playsewithpan SE_W060, -64
	call AnimScript_82D7CD1
	createsprite gUnknown_085966DC, 0x14
	createsprite gUnknown_08593344, 0x13, 32, -8, 0
	createsprite gUnknown_08593344, 0x13, 32, 16, 1
	loopsewithpan SE_W109, -64, 0x15, 0x2
	delay 0x3C
	playsewithpan SE_W146, -64
	delay 0x1E
	loopsewithpan SE_W146, -64, 0x14, 0x2
	delay 0x46
	playsewithpan SE_W207B, -64
	waitforvisualfinish
	call AnimScript_82D7CDD
	end

Move_GLARE:
	loadspritegfx 0x2808
	loadspritegfx 0x27EA
	createvisualtask sub_815E114, 0x5, 0
	playsewithpan SE_W060B, -64
	waitforvisualfinish
	createvisualtask sub_8116620, 0x5, 1, 0, 0, 16, 0
	waitforvisualfinish
	createsprite gUnknown_08593A84, 0x0, -16, -8
	createsprite gUnknown_08593A84, 0x0, 16, -8
	createvisualtask sub_81064F8, 0x5
	playsewithpan SE_W043, -64
	delay 0x2
	createvisualtask sub_810A094, 0x3, 20, 1, 0
	waitforvisualfinish
	createvisualtask sub_8116620, 0x5, 1, 0, 16, 0, 0
	end

Move_BARRAGE:
	loadspritegfx 0x280E
	createvisualtask sub_815E47C, 0x3
	playsewithpan SE_W207, -64
	delay 0x18
	createsprite gUnknown_085972D8, 0x2, 8, 1, 40, 1
	createvisualtask sub_80D51AC, 0x3, 1, 0, 4, 20, 1
	createvisualtask sub_80D51AC, 0x3, 3, 0, 4, 20, 1
	loopsewithpan SE_W070, +63, 0x8, 0x2
	end

Move_SKY_ATTACK:
	choosetwoturnanim AnimScript_82CD185, AnimScript_82CD28E

AnimScript_82CD184:
	end

AnimScript_82CD185:
	monbg ANIM_DEF_PARTNER
	setalpha 0xB0C
	createvisualtask sub_81177AC, 0x5, 7
	jumpargeq 0x7, 0x0, AnimScript_82CD1A0
	goto AnimScript_82CD217

AnimScript_82CD1A0:
	createvisualtask sub_8116620, 0xA, 27, 1, 0, 12, 0
	waitforvisualfinish
	delay 0xC
	createvisualtask sub_8116620, 0xA, 2, 1, 8, 0, 0
	createvisualtask sub_81152DC, 0x5, 0, 2, 16
	loopsewithpan SE_W287, -64, 0x4, 0x8
	createvisualtask sub_8116620, 0xA, 2, 1, 0, 15, 0x7FFF
	delay 0x14
	createvisualtask sub_8116620, 0xA, 2, 1, 15, 0, 0x7FFF
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 25, 1, 8, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto AnimScript_82CD184

AnimScript_82CD217:
	createvisualtask sub_8116664, 0xA, 1, 1, 0, 12, 0
	waitforvisualfinish
	delay 0xC
	createvisualtask sub_8116620, 0xA, 2, 1, 8, 0, 0
	createvisualtask sub_81152DC, 0x5, 0, 2, 16
	playsewithpan SE_W287, -64
	delay 0x8
	createvisualtask sub_8116620, 0xA, 2, 1, 0, 15, 0x7FFF
	delay 0x14
	createvisualtask sub_8116620, 0xA, 2, 1, 15, 0, 0x7FFF
	waitforvisualfinish
	createvisualtask sub_8116664, 0xA, 4, 1, 8, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto AnimScript_82CD184

AnimScript_82CD28E:
	loadspritegfx 0x2797
	loadspritegfx 0x282C
	call AnimScript_82D7CE5
	monbg ANIM_ATTACKER
	createvisualtask sub_8116620, 0xA, 2, 0, 0, 16, 0x7FFF
	delay 0x4
	createvisualtask sub_81136E8, 0x5, 0
	waitforvisualfinish
	createvisualtask sub_8159244, 0x5, 238, -64
	createsprite gUnknown_08596514, 0x82
	delay 0xE
	createvisualtask sub_80D52D0, 0x2, 1, 10, 0, 18, 1
	createvisualtask sub_8159210, 0x5, 141, 63
	delay 0x14
	createvisualtask sub_81137E4, 0x5, 1
	delay 0x2
	createvisualtask sub_8116620, 0xA, 2, 0, 15, 0, 0x7FFF
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	call AnimScript_82D7D15
	goto AnimScript_82CD184

Move_FLASH:
	playsewithpan SE_W043, -64
	createvisualtask sub_8117494, 0x2
	waitforvisualfinish
	end

Move_SPLASH:
	createvisualtask sub_8104938, 0x2, 0, 3
	delay 0x8
	loopsewithpan SE_W039, -64, 0x26, 0x3
	waitforvisualfinish
	end

Move_ACID_ARMOR:
	monbg ANIM_ATTACKER
	setalpha 0xF
	createvisualtask sub_815D240, 0x2, 0
	playsewithpan SE_W151, -64
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 0x1
	end

Move_SHARPEN:
	loadspritegfx 0x27C9
	createsprite gUnknown_08592DE4, 0x2
	waitforvisualfinish
	end

Move_SUPER_FANG:
	loadspritegfx 0x27D0
	createvisualtask sub_80D5484, 0x2, 0, 1, 0, 20, 1
	playsewithpan SE_W082, -64
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 0, 3, 0, 48, 1
	createvisualtask sub_80A7B98, 0x2, 0, RGB(31, 6, 1), 12, 4, 1
	waitforvisualfinish
	delay 0x14
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x4
	createsprite gUnknown_08592F74, 0x82
	playsewithpan SE_W044, +63
	delay 0x8
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 2143, 14, 0x7FFF, 14
	createvisualtask sub_80D51AC, 0x2, 1, 0, 7, 12, 1
	waitforvisualfinish
	blendoff
	end

Move_SLASH:
	loadspritegfx 0x27C7
	createsprite gUnknown_08592D2C, 0x82, 1, -8, 0
	playsewithpan SE_W013, +63
	delay 0x4
	createsprite gUnknown_08592D2C, 0x82, 1, 8, 0
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 18, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	end

Move_STRUGGLE:
	loadspritegfx 0x2797
	loadspritegfx 0x27E7
	monbg ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D5484, 0x2, 0, 3, 0, 12, 4
	createsprite gUnknown_08593B80, 0x2, 0, 0, 2
	createsprite gUnknown_08593B80, 0x2, 0, 1, 2
	loopsewithpan SE_W029, -64, 0xC, 0x4
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_80D5484, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SKETCH:
	loadspritegfx 0x2712
	monbg ANIM_TARGET
	createvisualtask sub_8104E74, 0x2
	createsprite gUnknown_085936D4, 0x82
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	createvisualtask sub_8104938, 0x2, 0, 2
	loopsewithpan SE_W039, -64, 0x26, 0x2
	end

Move_NIGHTMARE:
	fadetobg BG_GHOST
	waitbgfadein
	jumpifcontest AnimScript_82CD4CF
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8111C50, 0x2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 40, 1
	playsewithpan SE_W171, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end

AnimScript_82CD4CF:
	createvisualtask sub_80A7B98, 0x2, 0, RGB_WHITE, 10, 2, 1
	createvisualtask sub_80D51AC, 0x2, 0, 3, 0, 32, 1
	playsewithpan SE_W171, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_FLAIL:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_815C770, 0x2, 0
	loopsewithpan SE_W029, -64, 0x8, 0x2
	waitforvisualfinish
	createsprite gUnknown_085973A0, 0x83, 1, 3
	createvisualtask sub_80D6388, 0x2, 0, 1, 30, 1, 0
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SPITE:
	fadetobg BG_GHOST
	playsewithpan SE_W060, -64
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8115A04, 0x2, 2, 2, 6, 0, 8, 0x7FFF
	createvisualtask sub_8111E50, 0x2
	loopsewithpan SE_W060, +63, 0x14, 0x3
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_TARGET
	end

Move_MACH_PUNCH:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8117754, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82CD5E6
	fadetobg BG_HIGHSPEED_OPPONENT

AnimScript_82CD57E:
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -2304, 0, 1, -1
	waitbgfadein
	delay 0x0
	setalpha 0x809
	createvisualtask sub_80A8BC4, 0x2, 28968, 10
	playsewithpan SE_W026, -64
	delay 0x6
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	createsprite gUnknown_08595E98, 0x84, 0, 0, 8, 1, 0
	playsewithpan SE_W004, +63
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

AnimScript_82CD5E6:
	fadetobg BG_HIGHSPEED_PLAYER
	goto AnimScript_82CD57E

Move_FORESIGHT:
	loadspritegfx 0x2812
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x10
	createsprite gUnknown_085CE8C4, 0x82, 1
	delay 0x11
	loopsewithpan SE_W166, +63, 0x10, 0x4
	delay 0x30
	delay 0x18
	playsewithpan SE_W166, +63
	delay 0xA
	createvisualtask sub_80A7B98, 0x5, 1, RGB_WHITE, 12, 2, 1
	playsewithpan SE_W197, +63
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	end

Move_DESTINY_BOND:
	loadspritegfx 0x27CC
	fadetobg BG_GHOST
	playsewithpan SE_W060, -64
	waitbgfadein
	createvisualtask sub_81123C4, 0x5, 0, 48
	playsewithpan SE_W109, -64
	delay 0x30
	createvisualtask sub_80D5484, 0x2, 0, 2, 0, 24, 1
	createvisualtask sub_8116664, 0x2, 6, 1, 0, 12, 30653
	delay 0x18
	createvisualtask sub_8116664, 0x2, 6, 1, 12, 0, 30653
	playsewithpan SE_W171, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	blendoff
	clearmonbg 5
	end

Move_ENDURE:
	loadspritegfx 0x27C8
	playsewithpan SE_W082, -64
	call AnimScript_82CD6C7
	delay 0x8
	createvisualtask sub_8115A04, 0x2, 2, 2, 2, 0, 11, 31
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 32, 1
	call AnimScript_82CD6C7
	delay 0x8
	call AnimScript_82CD6C7
	waitforvisualfinish
	end

AnimScript_82CD6C7:
	createsprite gUnknown_08592D8C, 0x2, 0, -24, 26, 2
	delay 0x4
	createsprite gUnknown_08592D8C, 0x2, 0, 14, 28, 1
	delay 0x4
	createsprite gUnknown_08592D8C, 0x2, 0, -5, 10, 2
	delay 0x4
	createsprite gUnknown_08592D8C, 0x2, 0, 28, 26, 3
	delay 0x4
	createsprite gUnknown_08592D8C, 0x2, 0, -12, 0, 1
	return

Move_CHARM:
	loadspritegfx 0x27E2
	createvisualtask sub_815C478, 0x5, 0, 2, 0
	createsprite gUnknown_08593970, 0x3, 0, 20
	playsewithpan SE_W204, -64
	delay 0xF
	createsprite gUnknown_08593970, 0x3, -20, 20
	playsewithpan SE_W204, -64
	delay 0xF
	createsprite gUnknown_08593970, 0x3, 20, 20
	playsewithpan SE_W204, -64
	waitforvisualfinish
	end

Move_ROLLOUT:
	loadspritegfx 0x2797
	loadspritegfx 0x275A
	loadspritegfx 0x274A
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_8110F74, 0x2
	waitforvisualfinish
	createvisualtask sub_80D6388, 0x2, 0, 1, 30, 1, 0
	createsprite gUnknown_08597358, 0x4, 0, 0, 1, 2
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_FALSE_SWIPE:
	loadspritegfx 0x282E
	loadspritegfx 0x2797
	createsprite gUnknown_08592D44, 0x82
	playsewithpan SE_W233, +63
	delay 0x10
	createsprite gUnknown_08592D5C, 0x82, 0
	playsewithpan SE_W104, +63
	delay 0x2
	createsprite gUnknown_08592D5C, 0x82, 16
	delay 0x2
	createsprite gUnknown_08592D5C, 0x82, 32
	playsewithpan SE_W104, +63
	delay 0x2
	createsprite gUnknown_08592D5C, 0x82, 48
	delay 0x2
	createsprite gUnknown_08592D5C, 0x82, 64
	playsewithpan SE_W104, +63
	delay 0x2
	createsprite gUnknown_08592D5C, 0x82, 80
	delay 0x2
	waitforvisualfinish
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 6, 1
	createsprite gUnknown_08597358, 0x84, 0, 0, 1, 3
	playsewithpan SE_W004, +63
	end

Move_SWAGGER:
	loadspritegfx 0x2766
	loadspritegfx 0x2767
	createvisualtask sub_8104AB4, 0x2
	playsewithpan SE_W207, -64
	waitforvisualfinish
	createsprite gUnknown_08593658, 0x2
	loopsewithpan SE_W207, -64, 0x4, 0x2
	waitforvisualfinish
	delay 0x18
	createsprite gUnknown_0859368C, 0x82, 1, -20, -28
	playsewithpan SE_W207B, +63
	delay 0xC
	createsprite gUnknown_0859368C, 0x82, 1, 20, -28
	playsewithpan SE_W207B, +63
	waitforvisualfinish
	end

Move_MILK_DRINK:
	loadspritegfx 0x2773
	loadspritegfx 0x27DB
	loadspritegfx 0x272F
	monbg ANIM_TARGET
	createsprite gUnknown_08592B3C, 0x2
	delay 0x28
	playsewithpan SE_W152, -64
	delay 0xC
	playsewithpan SE_W152, -64
	delay 0x14
	playsewithpan SE_W152, -64
	waitforvisualfinish
	createsprite gUnknown_0859381C, 0x3, 0, 0, 1, 0
	playsewithpan SE_W208, -64
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	call AnimScript_82D7A28
	waitforvisualfinish
	end

Move_MAGNITUDE:
	createvisualtask sub_8115600, 0x2
	waitforvisualfinish
	jumpargeq 0xF, 0x0, AnimScript_82CD8C9
	jumpargeq 0xF, 0x1, AnimScript_82CD8EE

AnimScript_82CD8C8:
	end

AnimScript_82CD8C9:
	createvisualtask sub_81152DC, 0x5, 5, 0, 50
	createvisualtask sub_81152DC, 0x5, 4, 0, 50
	loopsewithpan SE_W070, +63, 0x8, 0xA
	goto AnimScript_82CD8C8

AnimScript_82CD8EE:
	createvisualtask sub_81152DC, 0x5, 5, 0, 50
	createvisualtask sub_81152DC, 0x5, 4, 0, 50
	loopsewithpan SE_W070, +63, 0x8, 0xA
	delay 0xA
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 0x10
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, 0, 14, 0x7FFF, 14
	goto AnimScript_82CD8C8

Move_RAPID_SPIN:
	loadspritegfx 0x2797
	loadspritegfx 0x27F5
	monbg ANIM_ATTACKER
	createsprite gUnknown_085CE288, 0x2, 0, 0, 32, -32, 40, -2
	createvisualtask sub_815ADB0, 0x2, 0, 2, 0
	loopsewithpan SE_W013B, -64, 0x8, 0x4
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 2
	createvisualtask sub_80D6388, 0x2, 0, 1, 10, 1, 0
	playsewithpan SE_W003, +63
	waitforvisualfinish
	delay 0x8
	createvisualtask sub_815ADB0, 0x2, 0, 2, 1
	loopsewithpan SE_W013B, -64, 0x8, 0x4
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MOONLIGHT:
	loadspritegfx 0x27D2
	loadspritegfx 0x27D3
	loadspritegfx 0x272F
	setalpha 0x1000
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08592EBC, 0x2, 120, 56
	createvisualtask sub_80A7A74, 0x3, 0, 16, 16, 0, 1
	playsewithpan SE_W236, 0
	delay 0x1E
	createsprite gUnknown_08592EEC, 0x28, -12, 0
	delay 0x1E
	createsprite gUnknown_08592EEC, 0x28, -24, 0
	delay 0x1E
	createsprite gUnknown_08592EEC, 0x28, 21, 0
	delay 0x1E
	createsprite gUnknown_08592EEC, 0x28, 0, 0
	delay 0x1E
	createsprite gUnknown_08592EEC, 0x28, 10, 0
	delay 0x14
	createvisualtask sub_81025C0, 0x2
	waitforvisualfinish
	call AnimScript_82D79DF
	waitforvisualfinish
	end

Move_EXTREME_SPEED:
	loadspritegfx 0x27DF
	loadspritegfx 0x2797
	createvisualtask sub_8117754, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82CDAF5
	fadetobg BG_HIGHSPEED_OPPONENT

AnimScript_82CDA55:
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -2304, 0, 1, -1
	waitbgfadein
	createvisualtask sub_810577C, 0x2
	loopsewithpan SE_W013B, -64, 0x8, 0x3
	waitforvisualfinish
	delay 0x1
	createvisualtask sub_8117F60, 0x2
	monbg ANIM_TARGET
	setalpha 0x80C
	delay 0x12
	createvisualtask sub_8105810, 0x2
	delay 0x2
	playsewithpan SE_W004, +63
	createsprite gUnknown_085973B8, 0x82, 1, 0, -12, 3
	delay 0xA
	playsewithpan SE_W004, +63
	createsprite gUnknown_085973B8, 0x82, 1, 0, 12, 3
	delay 0xA
	playsewithpan SE_W233B, +63
	createsprite gUnknown_085973B8, 0x82, 1, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_8105AAC, 0x2
	delay 0xA
	createvisualtask sub_810599C, 0x2
	loopsewithpan SE_W104, -64, 0x8, 0x4
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x1
	setarg 0x7, 0x1000
	delay 0x1
	end

AnimScript_82CDAF5:
	fadetobg BG_HIGHSPEED_PLAYER
	goto AnimScript_82CDA55

Move_UPROAR:
	loadspritegfx 0x27F1
	loadspritegfx 0x27DB
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8106D90, 0x2, 0
	createsprite gUnknown_08593898, 0x3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, -64
	createsprite gUnknown_08593BB8, 0x2, 0, 29, -12, 0
	createsprite gUnknown_08593BB8, 0x2, 0, -12, -29, 1
	delay 0x10
	createvisualtask sub_8106D90, 0x2, 0
	createsprite gUnknown_08593898, 0x3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, -64
	createsprite gUnknown_08593BB8, 0x2, 0, 12, -29, 1
	createsprite gUnknown_08593BB8, 0x2, 0, -29, -12, 0
	delay 0x10
	createvisualtask sub_8106D90, 0x2, 0
	createsprite gUnknown_08593898, 0x3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, -64
	createsprite gUnknown_08593BB8, 0x2, 0, 24, -24, 1
	createsprite gUnknown_08593BB8, 0x2, 0, -24, -24, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_HEAT_WAVE:
	loadspritegfx 0x2815
	createvisualtask sub_8116848, 0x5, 10261, 0, 6, 6, RGB_RED
	createvisualtask sub_8110BCC, 0x5, 1
	createvisualtask sub_810A060, 0x6, 6, 31
	panse_1B SE_W257, -64, +63, +2, 0x0
	delay 0x4
	createvisualtask sub_8109DBC, 0x5
	delay 0xC
	createsprite gUnknown_08596BA0, 0x28, 10, 2304, 96, 1
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 90, 2048, 96, 1
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 50, 2560, 96, 1
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 20, 2304, 96, 1
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 70, 1984, 96, 1
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 0, 2816, 96, 1
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 60, 2560, 96, 1
	end

Move_HAIL:
	loadspritegfx 0x2817
	loadspritegfx 0x279D
	createvisualtask sub_8116620, 0xA, 1, 3, 0, 6, 0
	waitforvisualfinish
	createvisualtask sub_810C918, 0x5
	loopsewithpan SE_W258, 0, 0x8, 0xA
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1, 3, 6, 0, 0
	end

Move_TORMENT:
	loadspritegfx 0x2767
	loadspritegfx 0x27E1
	createvisualtask sub_815AFF0, 0x2
	waitforvisualfinish
	createvisualtask sub_80A7B98, 0x2, 1, RGB_RED, 10, 1, 1
	createsprite gUnknown_0859368C, 0x82, 1, -20, -28
	playsewithpan SE_W207B, +63
	delay 0x14
	createsprite gUnknown_0859368C, 0x82, 1, 20, -28
	playsewithpan SE_W207B, +63
	end

Move_MEMENTO:
	setalpha 0x1000
	delay 0x1
	createvisualtask sub_81143C0, 0x2
	delay 0x1
	createvisualtask sub_8113BAC, 0x5
	playsewithpan SE_W060, -64
	delay 0x30
	playsewithpan SE_W060B, -64
	waitforvisualfinish
	createvisualtask sub_8114470, 0x2
	delay 0xC
	setalpha 0x1000
	delay 0x1
	monbg_22 ANIM_TARGET
	createvisualtask sub_8113E78, 0x5
	playsewithpan SE_W060, +63
	waitforvisualfinish
	clearmonbg_23 ANIM_TARGET
	delay 0x1
	blendoff
	delay 0x1
	end

Move_FACADE:
	loadspritegfx 0x2803
	createvisualtask sub_815DCA4, 0x2, 0, 3
	createvisualtask sub_815DF0C, 0x2, 0, 72
	loopsewithpan SE_W207, -64, 0x18, 0x3
	end

Move_SMELLING_SALT:
	loadspritegfx 0x2807
	loadspritegfx 0x280F
	createsprite gUnknown_085CE864, 0x82, 1, 0, 2
	createsprite gUnknown_085CE864, 0x82, 1, 1, 2
	delay 0x20
	createvisualtask sub_815E840, 0x3, 1, 2
	loopsewithpan SE_W003, +63, 0xC, 0x2
	waitforvisualfinish
	delay 0x4
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 6, 2
	createsprite gUnknown_085CE894, 0x82, 1, 8, 3
	loopsewithpan SE_W207B, +63, 0x10, 0x3
	end

Move_FOLLOW_ME:
	loadspritegfx 0x2750
	createsprite gUnknown_085931D4, 0x2, 0
	playsewithpan SE_W039, -64
	delay 0x12
	playsewithpan SE_W213, -64
	delay 0x47
	loopsewithpan SE_W039, -64, 0x16, 0x3
	end

Move_CHARGE:
	loadspritegfx 0x27E3
	loadspritegfx 0x27E4
	loadspritegfx 0x27E5
	monbg ANIM_ATTACKER
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810AAFC, 0x2, 0, 60, 2, 12
	playsewithpan SE_W268, -64
	delay 0x1E
	playsewithpan SE_W268, -64
	delay 0x1E
	playsewithpan SE_W268, -64
	createsprite gUnknown_0859595C, 0x2, 0
	delay 0x19
	playsewithpan SE_W268, -64
	delay 0x14
	playsewithpan SE_W268, -64
	delay 0xF
	playsewithpan SE_W268, -64
	delay 0xA
	delay 0x6
	loopsewithpan SE_W268, -64, 0x6, 0x5
	waitforvisualfinish
	createsprite gUnknown_0859598C, 0x2, 0, 16, 16
	delay 0x2
	createsprite gUnknown_0859598C, 0x2, 0, -16, -16
	playsewithpan SE_W085B, -64
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 4, 4, 0, RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_TAUNT:
	loadspritegfx 0x27E6
	loadspritegfx 0x27E1
	loadspritegfx 0x2767
	createsprite gUnknown_08593114, 0xB, 0, 45
	playsewithpan SE_W118, -64
	delay 0x6
	createsprite gUnknown_0859324C, 0xC, 0
	delay 0x4
	loopsewithpan SE_W039, -64, 0x10, 0x2
	waitforvisualfinish
	delay 0x8
	createsprite gUnknown_0859368C, 0x82, 1, -20, -28
	playsewithpan SE_W207B, +63
	waitforvisualfinish
	delay 0xC
	createsprite gUnknown_0859368C, 0x82, 1, 20, -28
	playsewithpan SE_W207B, +63
	end

Move_HELPING_HAND:
	loadspritegfx 0x2807
	createvisualtask sub_815EC48, 0x5
	createsprite gUnknown_085CE8AC, 0x28, 0
	createsprite gUnknown_085CE8AC, 0x28, 1
	delay 0x13
	playsewithpan SE_W227, 0
	createvisualtask sub_80D52D0, 0x2, 2, 2, 0, 5, 1
	delay 0xE
	playsewithpan SE_W227, 0
	createvisualtask sub_80D52D0, 0x2, 2, 2, 0, 5, 1
	delay 0x14
	playsewithpan SE_W227, 0
	createvisualtask sub_80D52D0, 0x2, 2, 3, 0, 10, 1
	createvisualtask sub_80A7B98, 0x2, 2, RGB_YELLOW, 12, 1, 1
	end

Move_ASSIST:
	loadspritegfx 0x280C
	createsprite gUnknown_085CE804, 0x32, 112, -16, 140, 128, 36
	delay 0x2
	createsprite gUnknown_085CE804, 0x32, 208, 128, -16, 48, 36
	playsewithpan SE_W010, 0
	delay 0x2
	createsprite gUnknown_085CE804, 0x32, -16, 112, 256, -16, 36
	playsewithpan SE_W010, 0
	delay 0x2
	createsprite gUnknown_085CE804, 0x32, 108, 128, 84, -16, 36
	playsewithpan SE_W010, 0
	delay 0x2
	createsprite gUnknown_085CE804, 0x32, -16, 56, 256, 56, 36
	playsewithpan SE_W010, 0
	end

Move_SUPERPOWER:
	loadspritegfx 0x27E4
	loadspritegfx 0x2810
	loadspritegfx 0x2811
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x80C
	createsprite gUnknown_08595FEC, 0x82, 0
	playsewithpan SE_W025, -64
	delay 0x14
	createsprite gUnknown_085972D8, 0x2, 4, 1, 180, 1
	createvisualtask sub_8159244, 0x5, 234, 0
	delay 0x28
	createsprite gUnknown_08596004, 0x29, 200, 96, 1, 120
	delay 0x8
	createsprite gUnknown_08596004, 0x29, 20, 248, 4, 112
	delay 0x8
	createsprite gUnknown_08596004, 0x29, 130, 160, 2, 104
	delay 0x8
	createsprite gUnknown_08596004, 0x29, 160, 192, 0, 96
	delay 0x8
	createsprite gUnknown_08596004, 0x29, 60, 288, 3, 88
	delay 0x4A
	createsprite gUnknown_0859601C, 0x83, 0
	playsewithpan SE_W207, -64
	delay 0x10
	createvisualtask sub_80D52D0, 0x2, 1, 8, 0, 16, 1
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 0x1
	end

Move_RECYCLE:
	loadspritegfx 0x2826
	monbg ANIM_ATTACKER
	setalpha 0x1000
	delay 0x1
	createsprite gUnknown_085CE9B0, 0x2
	loopsewithpan SE_W036, -64, 0x18, 0x3
	waitforvisualfinish
	createvisualtask sub_80A7B98, 0x5, 0, RGB_WHITE, 12, 2, 1
	playsewithpan SE_W036, -64
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 0x1
	end

Move_BRICK_BREAK:
	loadspritegfx 0x27B7
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	loadspritegfx 0x27E0
	choosetwoturnanim AnimScript_82CE0A7, AnimScript_82CE154

AnimScript_82CE0A7:
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 3, 8
	delay 0x4
	delay 0x1
	createsprite gUnknown_08597358, 0x3, -18, -18, 1, 1
	playsewithpan SE_W233, +63
	delay 0x14
	createsprite gUnknown_0857FE28, 0x2, 3, 8
	delay 0x5
	createsprite gUnknown_08597358, 0x3, 18, 18, 1, 1
	playsewithpan SE_W233, +63
	delay 0x14
	createvisualtask sub_80D5C50, 0x2, 0, -24, 0, 24, 10, 24, 3
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 6, RGB_BLACK
	delay 0x25
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	createsprite gUnknown_08595E98, 0x4, 0, 0, 10, 1, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 2, 6, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

AnimScript_82CE154:
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 3, 8
	delay 0x4
	createsprite gUnknown_08595F90, 0x3, 1, 0, 0, 90, 10
	delay 0x1
	createsprite gUnknown_08597358, 0x3, -18, -18, 1, 1
	playsewithpan SE_W233, +63
	delay 0x14
	createsprite gUnknown_0857FE28, 0x2, 3, 8
	delay 0x5
	createsprite gUnknown_08597358, 0x3, 18, 18, 1, 1
	playsewithpan SE_W233, +63
	delay 0x14
	createvisualtask sub_80D5C50, 0x2, 0, -24, 0, 24, 10, 24, 3
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 6, RGB_BLACK
	delay 0x25
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	createsprite gUnknown_08595E98, 0x4, 0, 0, 10, 1, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createsprite gUnknown_08595FA8, 0x2, 1, 0, -8, -12
	createsprite gUnknown_08595FA8, 0x2, 1, 1, 8, -12
	createsprite gUnknown_08595FA8, 0x2, 1, 2, -8, 12
	createsprite gUnknown_08595FA8, 0x2, 1, 3, 8, 12
	playsewithpan SE_W280, +63
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 2, 6, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_YAWN:
	loadspritegfx 0x2802
	createvisualtask sub_815D64C, 0x2, 0
	playsewithpan SE_W281, -64
	waitforvisualfinish
	createsprite gUnknown_085CE68C, 0x85, 2
	playsewithpan SE_W255, -64
	delay 0x4
	createsprite gUnknown_085CE68C, 0x85, 1
	delay 0x4
	createsprite gUnknown_085CE68C, 0x85, 0
	waitforvisualfinish
	createvisualtask sub_815D64C, 0x2, 1
	playsewithpan SE_W281, +63
	end

Move_ENDEAVOR:
	loadspritegfx 0x2803
	loadspritegfx 0x2797
	createvisualtask sub_815DCA4, 0x2, 0, 2
	loopsewithpan SE_W039, -64, 0x18, 0x2
	createvisualtask sub_80A7B98, 0x5, 0, RGB(31, 21, 0), 12, 1, 2
	delay 0x6
	createvisualtask sub_80D6388, 0x5, 0, 1, 8, 1, 0
	createsprite gUnknown_08597358, 0x82, 12, -12, 1, 2
	playsewithpan SE_W003, +63
	delay 0x18
	createvisualtask sub_80D6388, 0x5, 0, 1, 8, 1, 0
	createsprite gUnknown_08597358, 0x82, -12, 12, 1, 2
	playsewithpan SE_W004, +63
	end

Move_ERUPTION:
	loadspritegfx 0x27D9
	createsprite gUnknown_08597274, 0x2, 31, 2, 0, 4, RGB_RED
	waitforvisualfinish
	createvisualtask sub_8109460, 0x2
	waitplaysewithpan SE_W153, -64, 0x3C
	waitforvisualfinish
	createvisualtask sub_8109460, 0x2
	waitplaysewithpan SE_W153, -64, 0x3C
	waitforvisualfinish
	delay 0x1E
	createsprite gUnknown_085955E8, 0x28, 200, -32, 0, 100, 0
	createsprite gUnknown_085955E8, 0x28, 30, -32, 16, 90, 1
	createsprite gUnknown_085955E8, 0x28, 150, -32, 32, 60, 2
	createsprite gUnknown_085955E8, 0x28, 90, -32, 48, 80, 3
	createsprite gUnknown_085955E8, 0x28, 110, -32, 64, 50, 0
	createsprite gUnknown_085955E8, 0x28, 60, -32, 80, 70, 1
	delay 0x16
	createvisualtask sub_81152DC, 0x5, 5, 8, 60
	createvisualtask sub_81152DC, 0x5, 4, 8, 60
	loopsewithpan SE_W088, +63, 0x10, 0xC
	delay 0x50
	createsprite gUnknown_08597274, 0x28, 31, 4, 4, 0, RGB_RED
	end

Move_SKILL_SWAP:
	loadspritegfx 0x280B
	call AnimScript_82D7CD1
	createvisualtask sub_810FBF0, 0x3, 1
	createvisualtask sub_80A7B98, 0x5, 1, RGB_WHITE, 12, 3, 1
	loopsewithpan SE_W179, -64, 0x18, 0x3
	delay 0x10
	createvisualtask sub_810FBF0, 0x3, 0
	createvisualtask sub_80A7B98, 0x5, 0, RGB_WHITE, 12, 3, 1
	waitforvisualfinish
	call AnimScript_82D7CDD
	end

Move_IMPRISON:
	loadspritegfx 0x2809
	loadspritegfx 0x280A
	call AnimScript_82D7CD1
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_810F940, 0x5
	delay 0x8
	loopsewithpan SE_W030, -64, 0x8, 0x5
	waitforvisualfinish
	delay 0x4
	createsprite gUnknown_085967AC, 0x5, 0, 40
	createvisualtask sub_81152DC, 0x5, 4, 1, 10
	playsewithpan SE_W063, -64
	clearmonbg ANIM_DEF_PARTNER
	call AnimScript_82D7CDD
	end

Move_GRUDGE:
	loadspritegfx 0x280D
	monbg ANIM_ATTACKER
	monbgprio_29
	fadetobg BG_GHOST
	playsewithpan SE_W060, -64
	waitbgfadein
	createvisualtask sub_8112C6C, 0x3
	loopsewithpan SE_W052, -64, 0x10, 0x4
	delay 0xA
	delay 0x50
	playsewithpan SE_W171, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_ATTACKER
	end

Move_CAMOUFLAGE:
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x10
	createvisualtask sub_811675C, 0x5, 2, 3, 0, 14
	delay 0x10
	createvisualtask sub_81136E8, 0x2, 4
	playsewithpan SE_W185, -64
	waitforvisualfinish
	delay 0x8
	createvisualtask sub_811675C, 0x5, 2, 0, 0, 0
	waitforvisualfinish
	createvisualtask sub_81137E4, 0x2, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATK_PARTNER
	end

Move_TAIL_GLOW:
	loadspritegfx 0x27E4
	monbg ANIM_ATTACKER
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08596AC8, 0x42, 0
	delay 0x12
	loopsewithpan SE_W234, -64, 0x10, 0x6
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 4, 4, 0, RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 0x1
	end

Move_LUSTER_PURGE:
	loadspritegfx 0x281B
	loadspritegfx 0x2797
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A5C8, 0x5
	waitbgfadein
	monbg ANIM_ATTACKER
	setalpha 0x80C
	playsewithpan SE_W076, -64
	createsprite gUnknown_08596898, 0x29, 0, 0, 0, 0
	delay 0x14
	createvisualtask sub_8116664, 0x5, 5, 2, 0, 16, -1
	createvisualtask sub_8116848, 0x5, 10267, 2, 0, 16, -1
	waitforvisualfinish
	createvisualtask sub_8116848, 0x5, 10135, 0, 12, 12, 23552
	waitforvisualfinish
	createsprite gUnknown_085973A0, 0x83, 1, 2
	createvisualtask sub_8159210, 0x5, 215, 63
	delay 0x3
	createsprite gUnknown_085973A0, 0x83, 1, 2
	createvisualtask sub_8159210, 0x5, 215, 63
	delay 0x3
	createsprite gUnknown_085973A0, 0x83, 1, 2
	createvisualtask sub_8159210, 0x5, 215, 63
	delay 0x3
	createsprite gUnknown_085973A0, 0x83, 1, 2
	createvisualtask sub_8159210, 0x5, 215, 63
	delay 0x3
	createsprite gUnknown_085973A0, 0x83, 1, 2
	createvisualtask sub_8159210, 0x5, 215, 63
	delay 0x3
	createsprite gUnknown_085973A0, 0x83, 1, 2
	createvisualtask sub_8159210, 0x5, 215, 63
	waitforvisualfinish
	createvisualtask sub_8116664, 0x5, 5, 2, 16, 0, -1
	createvisualtask sub_81152DC, 0x5, 1, 5, 14
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	call AnimScript_82D7CDD
	end

Move_MIST_BALL:
	loadspritegfx 0x27AB
	loadspritegfx 0x281E
	delay 0x0
	playsewithpan SE_W081, -64
	createsprite gUnknown_08595C70, 0x80, 0, 0, 0, 0, 30, 0
	waitforvisualfinish
	playsewithpan SE_W028, +63
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 10, 0
	createsprite gUnknown_0859728C, 0x0, 1, 1, 1, 32279, 16, 0x7FFF, 16
	delay 0x0
	playsewithpan SE_W114, 0
	createvisualtask sub_810C324, 0x5
	createvisualtask sub_8116620, 0xA, 4, 3, 0, 16, 0x7FFF
	delay 0x8
	createvisualtask sub_80D51AC, 0x2, 1, 4, 0, 70, 0
	delay 0x46
	createvisualtask sub_8116620, 0xA, 4, 2, 16, 0, 0x7FFF
	end

Move_FEATHER_DANCE:
	loadspritegfx 0x281E
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	playsewithpan SE_W080, +63
	delay 0x0
	createsprite gUnknown_08596388, 0x80, 0, -16, 64, 2, 104, 11304, 32, 1
	delay 0x6
	createsprite gUnknown_08596388, 0x80, 0, -16, 32, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, 0x80, 0, -16, 0, 2, 104, 11304, 32, 1
	delay 0x6
	createsprite gUnknown_08596388, 0x80, 0, -16, 224, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, 0x80, 0, -16, 128, 2, 104, 11304, 32, 1
	delay 0x6
	createsprite gUnknown_08596388, 0x80, 0, -16, 192, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, 0x80, 0, -16, 160, 2, 104, 11304, 32, 1
	delay 0x6
	createsprite gUnknown_08596388, 0x80, 0, -16, 96, 2, 104, 11304, 32, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_TEETER_DANCE:
	loadspritegfx 0x2758
	loadspritegfx 0x2759
	createvisualtask sub_8160164, 0x5
	createsprite gUnknown_08593050, 0x2, 0, 16, -2
	playsewithpan SE_W298, -64
	delay 0x18
	createsprite gUnknown_08593050, 0x2, 0, 0, -2
	playsewithpan SE_W298, -64
	delay 0x18
	createsprite gUnknown_08593050, 0x2, 0, -16, -2
	playsewithpan SE_W298, -64
	delay 0x18
	createsprite gUnknown_08593050, 0x2, 1, -8, -2
	playsewithpan SE_W298, -64
	delay 0x18
	createsprite gUnknown_08593050, 0x2, 2, 8, -2
	playsewithpan SE_W298, -64
	end

Move_MUD_SPORT:
	loadspritegfx 0x275A
	createvisualtask sub_8104938, 0x2, 0, 6
	delay 0x18
	createsprite gUnknown_085971E4, 0x82, 0, -4, -16
	createsprite gUnknown_085971E4, 0x82, 0, 4, -12
	playsewithpan SE_W091, -64
	delay 0x20
	createsprite gUnknown_085971E4, 0x82, 0, -3, -12
	createsprite gUnknown_085971E4, 0x82, 0, 5, -14
	playsewithpan SE_W091, -64
	delay 0x20
	createsprite gUnknown_085971E4, 0x82, 0, -5, -18
	createsprite gUnknown_085971E4, 0x82, 0, 3, -14
	playsewithpan SE_W091, -64
	delay 0x10
	createsprite gUnknown_085971E4, 0x82, 1, 220, 60
	waitplaysewithpan SE_W145B, 0, 0xF
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 60, 100
	waitplaysewithpan SE_W145B, 0, 0x19
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 140, 55
	waitplaysewithpan SE_W145B, 0, 0xE
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 180, 50
	waitplaysewithpan SE_W145B, 0, 0xA
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 20, 90
	waitplaysewithpan SE_W145B, 0, 0x16
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 90, 90
	waitplaysewithpan SE_W145B, 0, 0x16
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 160, 60
	waitplaysewithpan SE_W145B, 0, 0xF
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 30, 90
	waitplaysewithpan SE_W145B, 0, 0x16
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 120, 60
	waitplaysewithpan SE_W145B, 0, 0xF
	delay 0x2
	createsprite gUnknown_085971E4, 0x82, 1, 200, 40
	waitplaysewithpan SE_W145B, 0, 0xA
	end

Move_NEEDLE_ARM:
	loadspritegfx 0x281A
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	loopsewithpan SE_W030, +63, 0x2, 0x10
	createsprite gUnknown_08592888, 0x82, 1, 0, 0, -32, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 22, -22, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 30, 0, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 20, 20, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 0, 28, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, -19, 19, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, -27, 0, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, -18, -18, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 0, -25, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 17, -17, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 23, 0, 16
	delay 0x2
	createsprite gUnknown_08592888, 0x82, 1, 0, 16, 16, 16
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 18, 1
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	createsprite gUnknown_08595E98, 0x84, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08592888, 0x82, 1, 1, 0, -24, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, 17, -17, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, 24, 0, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, 17, 17, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, 0, 24, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, -17, 17, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, -24, 0, 10
	createsprite gUnknown_08592888, 0x82, 1, 1, -17, -17, 10
	end

Move_SLACK_OFF:
	loadspritegfx 0x272F
	createvisualtask sub_8160544, 0x2, 0
	playsewithpan SE_W281, -64
	waitforvisualfinish
	call AnimScript_82D79DF
	waitforvisualfinish
	end

Move_CRUSH_CLAW:
	loadspritegfx 0x27B7
	loadspritegfx 0x2737
	loadspritegfx 0x27E0
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x4
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 18, 1
	createsprite gUnknown_08597138, 0x82, -10, -10, 0
	createsprite gUnknown_08597138, 0x82, -10, 10, 0
	playsewithpan SE_W013, +63
	delay 0xC
	createsprite gUnknown_08597138, 0x82, 10, -10, 1
	createsprite gUnknown_08597138, 0x82, 10, 10, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_TARGET
	end

Move_AROMATHERAPY:
	playsewithpan SE_W080, 0
	loadspritegfx 0x27AF
	loadspritegfx 0x27DB
	loadspritegfx 0x2741
	createsprite gUnknown_08597274, 0x0, 1, 0, 0, 7, RGB(13, 31, 12)
	delay 0x1
	monbg ANIM_ATTACKER
	delay 0x1
	createsprite gUnknown_085927AC, 0x0, 24, 16, 0, 2, 2, 0, 0
	createsprite gUnknown_085927AC, 0x42, 64, 24, 0, 3, 1, 1, 0
	createsprite gUnknown_085927C4, 0x0, 16, 24, 0, 2, 1, 0, 0
	delay 0x14
	createsprite gUnknown_085927AC, 0x42, 48, 12, 0, 4, 3, 1, 0
	createsprite gUnknown_085927AC, 0x0, 100, 16, 0, 3, 2, 0, 0
	createsprite gUnknown_085927AC, 0x0, 74, 24, 180, 3, 2, 0, 0
	delay 0xA
	createsprite gUnknown_085927AC, 0x42, 80, 30, 0, 4, 1, 1, 0
	createsprite gUnknown_085927AC, 0x0, 128, 12, 0, 3, 3, 0, 0
	createsprite gUnknown_085927C4, 0x0, 90, 16, 0, 2, 1, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 0x1
	createsprite gUnknown_08597274, 0x0, 1, 0, 7, 0, RGB(13, 31, 12)
	delay 0x1
	playsewithpan SE_W287, -64
	createvisualtask sub_815DFCC, 0x2, 1
	waitforvisualfinish
	playsewithpan SE_W234, -64
	createsprite gUnknown_08592B94, 0x10, -15, 0, 0, 0, 32, 60, 1
	delay 0x8
	createsprite gUnknown_08592B94, 0x10, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createsprite gUnknown_08597274, 0x0, 43, 3, 10, 0, RGB(13, 31, 12)
	createsprite gUnknown_08593868, 0x10, 0, 0, 0, 1
	waitforvisualfinish
	end

Move_FAKE_TEARS:
	loadspritegfx 0x27AB
	loadspritegfx 0x27E1
	loadspritegfx 0x2758
	createvisualtask sub_8116848, 0x5, 10155, 0, 4, 4, RGB(12, 11, 31)
	waitforvisualfinish
	createvisualtask sub_815C478, 0x5, 0, 2, 1
	loopsewithpan SE_W039, -64, 0xC, 0x4
	delay 0x8
	createsprite gUnknown_085970E8, 0x2, 0, 0
	createsprite gUnknown_085970E8, 0x2, 0, 1
	delay 0x8
	createsprite gUnknown_085970E8, 0x2, 0, 2
	createsprite gUnknown_085970E8, 0x2, 0, 3
	delay 0x8
	createsprite gUnknown_085970E8, 0x2, 0, 0
	createsprite gUnknown_085970E8, 0x2, 0, 1
	delay 0x8
	createsprite gUnknown_085970E8, 0x2, 0, 2
	createsprite gUnknown_085970E8, 0x2, 0, 3
	waitforvisualfinish
	end

Move_AIR_CUTTER:
	loadspritegfx 0x2713
	loadspritegfx 0x279A
	loadspritegfx 0x2797
	delay 0x0
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	delay 0x0
	createvisualtask sub_8103CF0, 0x2, 32, -24, 1536, 2, 128
	waitforvisualfinish
	playsewithpan SE_W015, +63
	createsprite gUnknown_08592A34, 0x2, 40, -32, 0, 2
	delay 0x5
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	createvisualtask sub_80D52D0, 0x2, 3, 2, 0, 8, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0x0
	end

Move_ODOR_SLEUTH:
	monbg ANIM_TARGET
	createvisualtask sub_815F620, 0x5
	delay 0x18
	createsprite gUnknown_0857FE28, 0x2, 3, 4
	playsewithpan SE_W207, -64
	delay 0x6
	createsprite gUnknown_0857FE28, 0x2, 3, 4
	playsewithpan SE_W207, -64
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	delay 0x1
	createsprite gUnknown_0859728C, 0x2, 1, 3, 1, -1, 16, -1, 0
	playsewithpan SE_W043, -64
	end

Move_GRASS_WHISTLE:
	loadspritegfx 0x2758
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 4, RGB(18, 31, 12)
	waitforvisualfinish
	createvisualtask sub_8102BE8, 0x2
	waitforvisualfinish
	panse_1B SE_W320, -64, +63, +2, 0x0
	createsprite gUnknown_08593008, 0x82, 7, 1, 0
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 6, 1, 0
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 1, 1, 0
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 2, 1, 0
	delay 0x5
	createsprite gUnknown_08593008, 0x82, 3, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 2, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 5, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 6, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 2, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 2, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 1, 1, 0
	delay 0x4
	createsprite gUnknown_08593008, 0x82, 5, 1, 0
	delay 0x4
	waitforvisualfinish
	createvisualtask sub_8102CA0, 0x2
	createsprite gUnknown_08597274, 0x2, 1, 4, 4, 0, RGB(18, 31, 12)
	waitforvisualfinish
	end

Move_TICKLE:
	loadspritegfx 0x27EA
	createsprite gUnknown_08597274, 0x2, 2, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08593A84, 0x0, -16, -8
	createsprite gUnknown_08593A84, 0x0, 16, -8
	playsewithpan SE_W197, -64
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 2, 0, 16, 0, RGB_BLACK
	waitforvisualfinish
	delay 0x14
	createvisualtask sub_80D5EB8, 0x3, 0, 6, 1280, 3, 0
	delay 0xC
	createvisualtask sub_815C478, 0x3, 1, 6, 2
	loopsewithpan SE_W039, +63, 0x8, 0x8
	waitforvisualfinish
	end

Move_WATER_SPOUT:
	loadspritegfx 0x281C
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_81080E4, 0x5
	playsewithpan SE_W029, -64
	delay 0x2C
	playsewithpan SE_W291, -64
	waitforvisualfinish
	delay 0x10
	createvisualtask sub_81085C8, 0x5
	playsewithpan SE_W057, +63
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SHADOW_PUNCH:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	fadetobg BG_GHOST
	waitbgfadein
	monbg ANIM_ATK_PARTNER
	setalpha 0x809
	createvisualtask sub_80A8BC4, 0x2, 0, 13
	playsewithpan SE_W026, -64
	delay 0x6
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	createsprite gUnknown_08595E98, 0x84, 0, 0, 8, 1, 0
	playsewithpan SE_W004, +63
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_EXTRASENSORY:
	call AnimScript_82D7CD1
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_80A7B98, 0x5, 0, RGB(27, 27, 0), 12, 1, 1
	createvisualtask sub_810FE14, 0x5, 0
	playsewithpan SE_W020, +63
	waitforvisualfinish
	createvisualtask sub_80A7B98, 0x5, 0, RGB(27, 27, 0), 12, 1, 1
	createvisualtask sub_810FE14, 0x5, 1
	playsewithpan SE_W020, +63
	waitforvisualfinish
	createvisualtask sub_8110034, 0x5, 0
	createvisualtask sub_810FE14, 0x5, 2
	playsewithpan SE_W043, -64
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	call AnimScript_82D7CDD
	end

Move_AERIAL_ACE:
	loadspritegfx 0x279A
	monbg ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D5830, 0x2, 0, 24, 6, 1, 5
	createvisualtask sub_81169C0, 0x2, 0, 4, 7, 3
	createsprite gUnknown_08592A1C, 0x2, 40, -32, 0
	playsewithpan SE_W013B, -64
	delay 0x5
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 10, 1
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0, 10, 0, 0
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_IRON_DEFENSE:
	loopsewithpan SE_REAPOKE, -64, 0x1C, 0x2
	createvisualtask sub_81144F8, 0x5, 0, 0, 0
	createsprite gUnknown_0859728C, 0x2, 1, 8, 2, -1, 14, -1, 0
	waitforvisualfinish
	end

Move_BLOCK:
	loadspritegfx 0x280A
	createsprite gUnknown_085CE90C, 0xC2
	playsewithpan SE_W207, +63
	end

Move_HOWL:
	loadspritegfx 0x2745
	createvisualtask sub_815D64C, 0x2, 0
	delay 0xC
	call AnimScript_82CFECB
	createvisualtask sub_8158D8C, 0x2, 0, 3
	waitforvisualfinish
	delay 0x1E
	end

Move_BULK_UP:
	loadspritegfx 0x2766
	createvisualtask sub_8104AB4, 0x2
	playsewithpan SE_W207, -64
	waitforvisualfinish
	createsprite gUnknown_08593658, 0x2
	loopsewithpan SE_W207, -64, 0x4, 0x2
	waitforvisualfinish
	end

Move_COVET:
	loadspritegfx 0x27E2
	loadspritegfx 0x27F0
	createvisualtask sub_815C478, 0x5, 0, 2, 0
	createsprite gUnknown_08593970, 0x3, 0, 20
	playsewithpan SE_W204, -64
	delay 0xF
	createsprite gUnknown_08593970, 0x3, -20, 20
	playsewithpan SE_W204, -64
	delay 0xF
	createsprite gUnknown_08593970, 0x3, 20, 20
	playsewithpan SE_W204, -64
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	loopsewithpan SE_W146, +63, 0x4, 0x3
	end

Move_VOLT_TACKLE:
	loadspritegfx 0x2711
	loadspritegfx 0x27E4
	loadspritegfx 0x27E5
	monbg ANIM_ATTACKER
	setalpha 0x80C
	createvisualtask sub_8116620, 0xA, 1, 0, 0, 8, 0
	waitforvisualfinish
	createsprite gUnknown_085959A4, 0x1
	playsewithpan SE_W268, -64
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 0x8
	createvisualtask sub_810AFCC, 0x5, 0
	playsewithpan SE_W085, -64
	waitforvisualfinish
	createvisualtask sub_810AFCC, 0x5, 1
	playsewithpan SE_W085, +63
	waitforvisualfinish
	createvisualtask sub_810AFCC, 0x5, 2
	playsewithpan SE_W085, -64
	waitforvisualfinish
	createvisualtask sub_810AFCC, 0x5, 3
	playsewithpan SE_W085, +63
	waitforvisualfinish
	createvisualtask sub_810AFCC, 0x5, 4
	playsewithpan SE_W085, -64
	delay 0x8
	createvisualtask sub_80D52D0, 0x2, 1, 10, 0, 18, 1
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859598C, 0x2, 1, 16, 16
	delay 0x2
	createsprite gUnknown_0859598C, 0x2, 1, -16, -16
	delay 0x8
	createvisualtask sub_810AE5C, 0x5
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 0, 3, 0, 9, 1
	playsewithpan SE_W085B, -64
	createsprite gUnknown_0859598C, 0x2, 0, 16, 16
	delay 0x2
	createsprite gUnknown_0859598C, 0x2, 0, -16, -16
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1, 0, 8, 0, 0
	waitforvisualfinish
	end

Move_WATER_SPORT:
	loadspritegfx 0x281C
	createvisualtask sub_81088E4, 0x5
	delay 0x8
	playsewithpan SE_W057, -64
	delay 0x2C
	playsewithpan SE_W057, -64
	delay 0x2C
	playsewithpan SE_W057, -64
	delay 0x2C
	panse_1B SE_W057, -64, +63, +2, 0x0
	end

Move_CALM_MIND:
	loadspritegfx 0x27DB
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8116664, 0x5, 0, 0, 0, 16, 0
	waitforvisualfinish
	createvisualtask sub_81177E4, 0x5, 1
	waitforvisualfinish
	createsprite gUnknown_08593850, 0x28, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 0xE
	createsprite gUnknown_08593850, 0x28, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 0xE
	createsprite gUnknown_08593850, 0x28, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	waitforvisualfinish
	createvisualtask sub_81177E4, 0x5, 0
	waitforvisualfinish
	createvisualtask sub_8116664, 0x5, 0, 0, 16, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_LEAF_BLADE:
	loadspritegfx 0x274F
	loadspritegfx 0x282D
	createvisualtask sub_80FFFC0, 0x5
	delay 0x2
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	playsewithpan SE_W015, +63
	delay 0x32
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	playsewithpan SE_W015, +63
	delay 0x32
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	playsewithpan SE_W015, +63
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 0x80C
	delay 0xC
	createvisualtask sub_80D52D0, 0x2, 1, 8, 0, 18, 1
	createsprite gUnknown_085973D0, 0x82, 0, 0, 1, 36
	playsewithpan SE_W043, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DRAGON_DANCE:
	loadspritegfx 0x2809
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	delay 0x1
	createvisualtask sub_81133E8, 0x5
	playsewithpan SE_W100, -64
	delay 0x8
	createvisualtask sub_80A7CB4, 0x5, 10249, 19456, 14, 0, 3
	createsprite gUnknown_08596F98, 0x2, 0
	createsprite gUnknown_08596F98, 0x2, 43
	createsprite gUnknown_08596F98, 0x2, 85
	createsprite gUnknown_08596F98, 0x2, 128
	createsprite gUnknown_08596F98, 0x2, 170
	createsprite gUnknown_08596F98, 0x2, 213
	delay 0x1E
	playsewithpan SE_W100, -64
	delay 0x1E
	playsewithpan SE_W100, -64
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 0x1
	end

Move_SHOCK_WAVE:
	loadspritegfx 0x27E3
	loadspritegfx 0x27E4
	loadspritegfx 0x2711
	loadspritegfx 0x2735
	monbg ANIM_ATTACKER
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810AAFC, 0x2, 0, 20, 0, 2
	playsewithpan SE_W268, -64
	delay 0xC
	createsprite gUnknown_08595A18, 0x2
	delay 0x1E
	createvisualtask sub_810B29C, 0x5
	delay 0xC
	waitforvisualfinish
	createvisualtask sub_810B55C, 0x5
	playsewithpan SE_W161B, +63
	waitforvisualfinish
	createvisualtask sub_80D51AC, 0x2, 1, 0, 6, 18, 1
	createvisualtask sub_8116620, 0x5, 1, 3, 16, 0, 0x7FFF
	createvisualtask sub_8116620, 0x5, 4, 0, 16, 16, 0
	delay 0x4
	createvisualtask sub_8116620, 0x5, 4, 0, 0, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_HARDEN:
	loopsewithpan SE_W231, -64, 0x1C, 0x2
	createvisualtask sub_81144F8, 0x5, 0, 0, 0
	waitforvisualfinish
	end

Move_BELLY_DRUM:
	loadspritegfx 0x2758
	loadspritegfx 0x27D1
	createvisualtask sub_8102BE8, 0x2
	waitforvisualfinish
	call AnimScript_82CF5A6
	createsprite gUnknown_0859309C, 0x2, 0, 0, 0, 0
	playsewithpan SE_W187, -64
	delay 0xF
	call AnimScript_82CF58B
	createsprite gUnknown_0859309C, 0x2, 1, 1, 1, 0
	playsewithpan SE_W187, -64
	delay 0xF
	call AnimScript_82CF5A6
	createsprite gUnknown_0859309C, 0x2, 0, 3, 3, 128
	playsewithpan SE_W187, -64
	delay 0x7
	call AnimScript_82CF58B
	createsprite gUnknown_0859309C, 0x2, 1, 2, 0, 128
	playsewithpan SE_W187, -64
	delay 0x7
	call AnimScript_82CF5A6
	createsprite gUnknown_0859309C, 0x2, 0, 1, 1, 0
	playsewithpan SE_W187, -64
	delay 0x7
	call AnimScript_82CF58B
	createsprite gUnknown_0859309C, 0x2, 1, 0, 3, 0
	playsewithpan SE_W187, -64
	waitforvisualfinish
	createvisualtask sub_8102CA0, 0x2
	waitforvisualfinish
	end

AnimScript_82CF58B:
	createsprite gUnknown_08593068, 0x3, 0
	createvisualtask sub_80D51AC, 0x2, 0, 0, 8, 2, 1
	return

AnimScript_82CF5A6:
	createsprite gUnknown_08593068, 0x3, 1
	createvisualtask sub_80D51AC, 0x2, 0, 0, 8, 2, 1
	return

Move_MIND_READER:
	loadspritegfx 0x27CD
	loadspritegfx 0x27CE
	loadspritegfx 0x27CF
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W109, +63
	createsprite gUnknown_085CE07C, 0x5, 0, 0, 1, 0
	createsprite gUnknown_085CE094, 0x5
	delay 0x28
	playsewithpan SE_W043, +63
	createvisualtask sub_8115A04, 0x2, 1, 1, 2, 0, 10, 0
	call AnimScript_82CF608
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82CF608:
	createsprite gUnknown_085CE0AC, 0x4, 70, 0, 6
	createsprite gUnknown_085CE0AC, 0x4, 40, 40, 6
	createsprite gUnknown_085CE0AC, 0x4, 10, -60, 6
	createsprite gUnknown_085CE0AC, 0x4, -50, -40, 6
	createsprite gUnknown_085CE0AC, 0x4, -40, 40, 6
	createsprite gUnknown_085CE0AC, 0x4, 50, -50, 6
	delay 0x2
	createsprite gUnknown_085CE0AC, 0x4, 50, -30, 6
	createsprite gUnknown_085CE0AC, 0x4, 60, 10, 6
	createsprite gUnknown_085CE0AC, 0x4, 0, 60, 6
	createsprite gUnknown_085CE0AC, 0x4, 0, -40, 6
	createsprite gUnknown_085CE0AC, 0x4, -60, 20, 6
	createsprite gUnknown_085CE0AC, 0x4, -60, -30, 6
	delay 0x2
	createsprite gUnknown_085CE0AC, 0x4, -50, 50, 6
	createsprite gUnknown_085CE0AC, 0x4, -60, 20, 6
	createsprite gUnknown_085CE0AC, 0x4, -40, -40, 6
	createsprite gUnknown_085CE0AC, 0x4, 20, -60, 6
	createsprite gUnknown_085CE0AC, 0x4, 50, -50, 6
	createsprite gUnknown_085CE0AC, 0x4, 35, 40, 6
	delay 0x2
	return

Move_ICE_PUNCH:
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	loadspritegfx 0x279D
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 7, RGB_BLACK
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 9, 32588
	delay 0x14
	playsewithpan SE_W081, +63
	createsprite gUnknown_08595AE8, 0x2, 0
	createsprite gUnknown_08595AE8, 0x2, 64
	createsprite gUnknown_08595AE8, 0x2, 128
	createsprite gUnknown_08595AE8, 0x2, 192
	delay 0x5
	createsprite gUnknown_08595AD0, 0x2, 32
	createsprite gUnknown_08595AD0, 0x2, 96
	createsprite gUnknown_08595AD0, 0x2, 160
	createsprite gUnknown_08595AD0, 0x2, 224
	delay 0x11
	createsprite gUnknown_08595E98, 0x4, 0, -10, 8, 1, 0
	createsprite gUnknown_08597358, 0x3, 0, -10, 1, 1
	playsewithpan SE_W004, +63
	delay 0x2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 3, 1
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D7720
	delay 0x5
	createvisualtask sub_8116620, 0xA, 4, 2, 9, 0, 32588
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_REST:
	playsewithpan SE_W173, -64
	loadspritegfx 0x27F4
	createsprite gUnknown_08592C88, 0x2, 4, -10, 16, 0, 0
	delay 0x14
	createsprite gUnknown_08592C88, 0x2, 4, -10, 16, 0, 0
	delay 0x14
	createsprite gUnknown_08592C88, 0x2, 4, -10, 16, 0, 0
	waitforvisualfinish
	end

Move_CONFUSION:
	monbg ANIM_DEF_PARTNER
	call AnimScript_82D7CD1
	setalpha 0x808
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 10, 1
	createvisualtask sub_8115A04, 0x2, 2, 0, 2, 0, 8, 0x7FFF
	waitforvisualfinish
	playsewithpan SE_W048, +63
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 15, 1
	createvisualtask sub_80D6064, 0x5, -4, -4, 15, 1, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 0x1
	call AnimScript_82D7CDD
	end

Move_PSYCHIC:
	monbg ANIM_DEF_PARTNER
	call AnimScript_82D7CD1
	setalpha 0x808
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 10, 1
	createvisualtask sub_8115A04, 0x2, 2, 0, 2, 0, 8, 767
	waitforvisualfinish
	loopsewithpan SE_W048, +63, 0xA, 0x3
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 15, 1
	createvisualtask sub_80D6064, 0x5, -6, -6, 15, 1, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 0x1
	call AnimScript_82D7CDD
	end

Move_FUTURE_SIGHT:
	goto AnimScript_82CF8F6

AnimScript_82CF8ED:
	waitforvisualfinish
	delay 0x1
	call AnimScript_82D7CDD
	end

AnimScript_82CF8F6:
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W060, -64
	call AnimScript_82D7CD1
	setalpha 0x808
	playsewithpan SE_W048, -64
	createvisualtask sub_8115A04, 0x2, 2, 0, 2, 0, 8, 0x7FFF
	createvisualtask sub_80D6064, 0x5, -4, -4, 15, 0, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	goto AnimScript_82CF8ED

Move_THUNDER:
	loadspritegfx 0x2735
	fadetobg BG_THUNDER
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -256, 0, 1, -1
	waitbgfadein
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 16, RGB_BLACK
	delay 0x10
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	playsewithpan SE_W086, +63
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 16, -36
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 16, -20
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 16, 12
	delay 0x14
	createsprite gUnknown_085956C0, 0x86, -16, -32
	playsewithpan SE_W086, +63
	delay 0x1
	createsprite gUnknown_085956C0, 0x86, -16, -16
	delay 0x1
	createsprite gUnknown_085956C0, 0x86, -16, 16
	playsewithpan SE_W086, +63
	delay 0x5
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 24, -32
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 24, -16
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 24, 16
	delay 0x1E
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x5
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 0, -32
	playsewithpan SE_W161B, +63
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 0, -16
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 0, 16
	delay 0xA
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	createvisualtask sub_810A094, 0x2, 30, 3, 1, 0
	delay 0x2
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	createsprite gUnknown_08597274, 0x82, 1, 2, 16, 0, RGB_BLACK
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

Move_THUNDER_PUNCH:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	loadspritegfx 0x2735
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 16, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W004, +63
	createsprite gUnknown_08595E98, 0x84, 0, 0, 8, 1, 0
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	delay 0x1
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 0, -48
	delay 0x1
	createsprite gUnknown_085956C0, 0x2, 0, -16
	delay 0x1
	createsprite gUnknown_085956C0, 0x2, 0, 16
	delay 0x1
	playsewithpan SE_W161B, +63
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x2
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 15, 1
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	delay 0x1
	createsprite gUnknown_08597274, 0x2, 1, 2, 16, 0, RGB_BLACK
	delay 0x14
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SACRED_FIRE:
	loadspritegfx 0x2731
	loadspritegfx 0x2733
	loopsewithpan SE_W221, -64, 0x7, 0x5
	createsprite gUnknown_08595428, 0x2, -32, 0, 50, 5, -2, 0
	delay 0x1
	createsprite gUnknown_08595428, 0x42, -20, -10, 50, 5, -1, -1
	delay 0x1
	createsprite gUnknown_08595428, 0x42, 0, -16, 50, 5, 0, -1
	delay 0x1
	createsprite gUnknown_08595428, 0x42, 20, -10, 50, 5, 1, -1
	delay 0x1
	createsprite gUnknown_08595428, 0x2, 32, 0, 50, 5, 2, 0
	delay 0x1
	createsprite gUnknown_08595428, 0x2, 20, 10, 50, 5, 1, 1
	delay 0x1
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	createsprite gUnknown_08595428, 0x2, 0, 16, 50, 5, 0, 1
	delay 0x1
	createsprite gUnknown_08595428, 0x2, -20, 10, 50, 5, -1, 1
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	waitforvisualfinish
	playsewithpan SE_W221B, +63
	createsprite gUnknown_085953F8, 0x82, -16, 0, 70, 16, 0, 1
	delay 0xA
	playsewithpan SE_W221B, +63
	createsprite gUnknown_085953F8, 0x82, 0, 0, 70, 16, 0, 1
	delay 0xA
	playsewithpan SE_W221B, +63
	createsprite gUnknown_085953F8, 0x82, 16, 0, 80, 16, 0, 1
	delay 0x1
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	waitforvisualfinish
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1
	playsewithpan SE_W172B, +63
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, -1, 0
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 0, 1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, -1, -1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 2, 1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 1, -1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, -1, 1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 1, -2
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 3, 1
	waitforvisualfinish
	end

Move_SCRATCH:
	loadspritegfx 0x2799
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W010, +63
	createsprite gUnknown_085CE020, 0x2, 0, 0, 1, 0
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_DRAGON_BREATH:
	loadspritegfx 0x272D
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W172, -64, 0x7, 0x7
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createvisualtask sub_8116620, 0xA, 4, 1, 0, 9, 31
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 21, 1
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	delay 0x2
	createsprite gUnknown_08596EF4, 0x82, 0, 0, 0, 0, 20
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 4, 1, 9, 0, 31
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_ROAR:
	loadspritegfx 0x2745
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x808
	createvisualtask sub_8158E9C, 0x2, 0, 2
	createvisualtask sub_80D6064, 0x5, -5, -5, 10, 0, 1
	call AnimScript_82CFECB
	delay 0x14
	createvisualtask sub_80D5DB0, 0x5, 1, 2
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	waitforvisualfinish
	createvisualtask sub_8159078, 0x5
	waitforvisualfinish
	end

AnimScript_82CFECB:
	createsprite gUnknown_085CE7D4, 0x2, 24, -8, 0
	createsprite gUnknown_085CE7D4, 0x2, 24, 0, 2
	createsprite gUnknown_085CE7D4, 0x2, 24, 8, 1
	delay 0xF
	createsprite gUnknown_085CE7D4, 0x2, 24, -8, 0
	createsprite gUnknown_085CE7D4, 0x2, 24, 0, 2
	createsprite gUnknown_085CE7D4, 0x2, 24, 8, 1
	return

Move_GROWL:
	loadspritegfx 0x2745
	createvisualtask sub_8158E9C, 0x2, 0, 255
	call AnimScript_82CFECB
	delay 0xA
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 9, 1
	createvisualtask sub_80D52D0, 0x2, 3, 1, 0, 9, 1
	waitforvisualfinish
	createvisualtask sub_8159078, 0x5
	waitforvisualfinish
	end

Move_SNORE:
	loadspritegfx 0x27D5
	monbg ANIM_ATK_PARTNER
	setalpha 0x808
	call AnimScript_82CFF76
	delay 0x1E
	call AnimScript_82CFF76
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

AnimScript_82CFF76:
	playsewithpan SE_W173, -64
	createvisualtask sub_80D6064, 0x5, -7, -7, 7, 0, 1
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 7, 1
	createsprite gUnknown_085972D8, 0x2, 6, 1, 14, 0, 0
	createsprite gUnknown_085936EC, 0x2, 0, 0, -42, -38, 24, 0, 0
	createsprite gUnknown_085936EC, 0x2, 0, 0, 0, -42, 24, 0, 0
	createsprite gUnknown_085936EC, 0x2, 0, 0, 42, -38, 24, 0, 0
	return

Move_LIGHT_SCREEN:
	loadspritegfx 0x2756
	loadspritegfx 0x27B6
	setalpha 0x1000
	waitplaysewithpan SE_W115, -64, 0xF
	createsprite gUnknown_08596560, 0x1, 40, 0, 10166
	delay 0xA
	call AnimScript_82D0014
	waitforvisualfinish
	delay 0x1
	blendoff
	end

AnimScript_82D0014:
	createsprite gUnknown_08596624, 0x2, 23, 0, 0, 1
	delay 0x6
	createsprite gUnknown_08596624, 0x2, 31, -8, 0, 1
	delay 0x5
	createsprite gUnknown_08596624, 0x2, 30, 20, 0, 1
	delay 0x7
	createsprite gUnknown_08596624, 0x2, 10, -15, 0, 1
	delay 0x6
	createsprite gUnknown_08596624, 0x2, 20, 10, 0, 1
	delay 0x6
	createsprite gUnknown_08596624, 0x2, 10, 18, 0, 1
	return

Move_MIRROR_COAT:
	loadspritegfx 0x2756
	loadspritegfx 0x27B8
	setalpha 0x1000
	createsprite gUnknown_08596590, 0x1, 40, 0, 10168
	delay 0xA
	playsewithpan SE_W115, -64
	call AnimScript_82D0014
	waitforvisualfinish
	delay 0x1
	blendoff
	end

Move_REFLECT:
	loadspritegfx 0x2757
	loadspritegfx 0x27B7
	setalpha 0x1000
	waitplaysewithpan SE_W115, -64, 0xF
	createsprite gUnknown_08596578, 0x1, 40, 0, 10167
	delay 0x14
	createsprite gUnknown_085965F4, 0x2, 30, 0, 0, 1
	delay 0x7
	createsprite gUnknown_085965F4, 0x2, 19, -12, 0, 1
	delay 0x7
	createsprite gUnknown_085965F4, 0x2, 10, 20, 0, 1
	waitforvisualfinish
	delay 0x1
	blendoff
	end

Move_BARRIER:
	loadspritegfx 0x27B9
	setalpha 0x1000
	waitplaysewithpan SE_W112, -64, 0xF
	createsprite gUnknown_085965A8, 0x3, 40, 0, 10169
	waitforvisualfinish
	delay 0x1
	blendoff
	end

Move_BUBBLE:
	loadspritegfx 0x27A2
	loadspritegfx 0x27AB
	monbg ANIM_TARGET
	setalpha 0x80C
	delay 0x1
	createsprite gUnknown_08595068, 0x2, 18, 0, 15, -15, 10, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 0x6
	createsprite gUnknown_08595068, 0x2, 18, 0, 35, 37, 40, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 0x6
	createsprite gUnknown_08595068, 0x2, 18, 0, 10, -37, 30, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 0x6
	createsprite gUnknown_08595068, 0x2, 18, 0, 30, 10, 15, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 0x6
	createsprite gUnknown_08595068, 0x2, 18, 0, 20, 33, 20, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 0x6
	createsprite gUnknown_08595068, 0x2, 18, 0, 25, -30, 10, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	waitforvisualfinish
	call AnimScript_82D7B53
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SMOG:
	loadspritegfx 0x27BC
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	setalpha 0x80C
	loopsewithpan SE_W054, +63, 0x11, 0xA
	call AnimScript_82D024A
	call AnimScript_82D024A
	call AnimScript_82D024A
	call AnimScript_82D024A
	call AnimScript_82D024A
	call AnimScript_82D024A
	call AnimScript_82D024A
	delay 0x78
	loopsewithpan SE_W092, +63, 0x12, 0x2
	createvisualtask sub_8115A04, 0x2, 4, 2, 2, 0, 12, 26650
	delay 0xA
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 15, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D024A:
	createsprite gUnknown_08595C44, 0x2, 0, -24, 48, 240, 1, 0
	delay 0x7
	return

Move_FAINT_ATTACK:
	loadspritegfx 0x2797
	monbg ANIM_ATTACKER
	fadetobg BG_DARK
	waitbgfadein
	delay 0x0
	playsewithpan SE_W185, -64
	createvisualtask sub_80D5830, 0x2, 0, 18, 6, 1, 3
	createvisualtask sub_81136E8, 0x2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	invisible ANIM_ATTACKER
	delay 0x1
	createvisualtask sub_8117F60, 0x2
	setalpha 0x80C
	monbg ANIM_TARGET
	delay 0x1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 1
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x1
	setarg 0x7, 0x1000
	delay 0x20
	createvisualtask sub_8113888, 0x2
	monbg ANIM_ATTACKER
	createvisualtask sub_81137E4, 0x2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 0x1
	restorebg
	waitbgfadein
	end

Move_SAND_ATTACK:
	loadspritegfx 0x275A
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x80C
	playsewithpan SE_W028, -64
	createsprite gUnknown_0857FE70, 0x2, 0, -10, 0, 0, 3
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 2
	call AnimScript_82D0337
	call AnimScript_82D0337
	call AnimScript_82D0337
	call AnimScript_82D0337
	call AnimScript_82D0337
	call AnimScript_82D0337
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

AnimScript_82D0337:
	createsprite gUnknown_085971A8, 0x82, 15, 15, 20, 0, 0
	createsprite gUnknown_085971A8, 0x82, 15, 15, 20, 10, 10
	createsprite gUnknown_085971A8, 0x82, 15, 15, 20, -10, -10
	createsprite gUnknown_085971A8, 0x82, 15, 15, 20, 20, 5
	createsprite gUnknown_085971A8, 0x82, 15, 15, 20, -20, -5
	delay 0x2
	return

Move_MUD_SLAP:
	loadspritegfx 0x275A
	playsewithpan SE_W028, -64
	createsprite gUnknown_0857FE70, 0x2, 0, -10, 0, 0, 3
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 2
	call AnimScript_82D03D5
	call AnimScript_82D03D5
	call AnimScript_82D03D5
	call AnimScript_82D03D5
	call AnimScript_82D03D5
	call AnimScript_82D03D5
	waitforvisualfinish
	end

AnimScript_82D03D5:
	createsprite gUnknown_085971CC, 0x82, 15, 15, 20, 0, 0
	createsprite gUnknown_085971CC, 0x82, 15, 15, 20, 10, 5
	createsprite gUnknown_085971CC, 0x82, 15, 15, 20, -10, -5
	createsprite gUnknown_085971CC, 0x82, 15, 15, 20, 20, 10
	createsprite gUnknown_085971CC, 0x82, 15, 15, 20, -20, -10
	delay 0x2
	return

Move_DRAGON_RAGE:
	loadspritegfx 0x272D
	loadspritegfx 0x2733
	playsewithpan SE_W082, -64
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 40, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x82, 0, 15, 0, 0, 4
	waitforvisualfinish
	createsprite gUnknown_08596F80, 0x82, 30, 15, 0, 10, 10
	waitforvisualfinish
	loopsewithpan SE_W172B, +63, 0xB, 0x3
	createvisualtask sub_80D51AC, 0x5, 1, 0, 3, 25, 1
	createsprite gUnknown_08596F28, 0xC2, 1, 5, 0
	delay 0x1
	createsprite gUnknown_08596F28, 0xC2, 1, -10, -15
	delay 0x1
	createsprite gUnknown_08596F28, 0x82, 1, 0, 25
	delay 0x1
	createsprite gUnknown_08596F28, 0xC2, 1, 15, 5
	delay 0x1
	createsprite gUnknown_08596F28, 0xC2, 1, -25, 0
	delay 0x1
	createsprite gUnknown_08596F28, 0x82, 1, 30, 30
	delay 0x1
	createsprite gUnknown_08596F28, 0x82, 1, -27, 25
	delay 0x1
	createsprite gUnknown_08596F28, 0xC2, 1, 0, 8
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0xC2, 0, 0, 4
	waitforvisualfinish
	end

Move_RAIN_DANCE:
	loadspritegfx 0x2783
	playsewithpan SE_W240, -64
	createvisualtask sub_8116620, 0xA, 1921, 2, 0, 4, 0
	waitforvisualfinish
	createvisualtask sub_8107188, 0x2, 0, 3, 120
	createvisualtask sub_8107188, 0x2, 0, 3, 120
	delay 0x78
	delay 0x1E
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1921, 2, 4, 0, 0
	waitforvisualfinish
	end

Move_BITE:
	loadspritegfx 0x279B
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W044, +63
	createsprite gUnknown_08597080, 0x2, 0, -32, 0, 0, 819, 10
	createsprite gUnknown_08597080, 0x2, 0, 32, 4, 0, -819, 10
	delay 0xA
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 4, 7, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x1
	end

Move_CRUNCH:
	loadspritegfx 0x279B
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	setalpha 0x80C
	playsewithpan SE_W044, +63
	createsprite gUnknown_08597080, 0x2, -32, -32, 1, 819, 819, 10
	createsprite gUnknown_08597080, 0x2, 32, 32, 5, -819, -819, 10
	delay 0xA
	createsprite gUnknown_08597358, 0x2, -8, 0, 1, 1
	createvisualtask sub_80D51AC, 0x5, 1, 0, 7, 5, 2
	waitforvisualfinish
	playsewithpan SE_W044, +63
	createsprite gUnknown_08597080, 0x2, 32, -32, 7, -819, 819, 10
	createsprite gUnknown_08597080, 0x2, -32, 32, 3, 819, -819, 10
	delay 0xA
	createsprite gUnknown_08597358, 0x2, 8, 0, 1, 1
	createvisualtask sub_80D51AC, 0x5, 1, 0, 8, 4, 2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0x1
	restorebg
	waitbgfadein
	end

Move_CLAMP:
	loadspritegfx 0x27A1
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W011, +63
	createsprite gUnknown_08597098, 0x2, -32, 0, 2, 819, 0, 10
	createsprite gUnknown_08597098, 0x2, 32, 0, 6, -819, 0, 10
	delay 0xA
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_ICE_BEAM:
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	loadspritegfx 0x279D
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 7, RGB_BLACK
	waitforvisualfinish
	createsoundtask sub_8158C58, 183, -64, 63, 4, 4, 0, 10
	createsprite gUnknown_08595B2C, 0x2, 20, 12, 0, 12, 20
	createsprite gUnknown_08595B2C, 0x2, 20, -12, 0, -12, 20
	delay 0x1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	createsprite gUnknown_08597274, 0x2, 4, -31, 0, 7, RGB(0, 20, 31)
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 25, 1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	call AnimScript_82D07C1
	createsprite gUnknown_08595B14, 0x2, 20, 0, 0, 0, 11
	delay 0x1
	createsprite gUnknown_08595B14, 0x2, 20, 0, 0, 0, 11
	waitforvisualfinish
	delay 0x14
	call AnimScript_82D7720
	createsprite gUnknown_08597274, 0x2, 4, 5, 7, 0, RGB(0, 20, 31)
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82D07C1:
	createsprite gUnknown_08595B2C, 0x2, 20, 12, 0, 12, 20
	createsprite gUnknown_08595B2C, 0x2, 20, -12, 0, -12, 20
	createsprite gUnknown_08595B14, 0x2, 20, 0, 0, 0, 11
	delay 0x1
	return

Move_WITHDRAW:
	playsewithpan SE_W029, -64
	createvisualtask sub_81036A0, 0x5
	waitforvisualfinish
	end

Move_AURORA_BEAM:
	loadspritegfx 0x279C
	fadetobg BG_AURORABEAM
	waitbgfadein
	playsewithpan SE_W062, -64
	setarg 0x7, 0x0
	createvisualtask sub_8107528, 0xA, 130
	call AnimScript_82D088B
	createvisualtask sub_80D52D0, 0x5, 1, 1, 0, 17, 1
	call AnimScript_82D088B
	call AnimScript_82D088B
	call AnimScript_82D088B
	setarg 0x7, 0xFFFF
	createsoundtask sub_8158C58, 183, -64, 63, 3, 6, 0, 10
	createvisualtask sub_80D52D0, 0x5, 1, 2, 0, 40, 1
	call AnimScript_82D088B
	call AnimScript_82D088B
	call AnimScript_82D088B
	call AnimScript_82D088B
	call AnimScript_82D088B
	call AnimScript_82D088B
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

AnimScript_82D088B:
	createsprite gUnknown_085950B4, 0x82, 20, 0, 0, 0, 17
	delay 0x1
	createsprite gUnknown_085950B4, 0x82, 20, 0, 0, 0, 17
	delay 0x1
	createsprite gUnknown_085950B4, 0x82, 20, 0, 0, 0, 17
	delay 0x1
	createsprite gUnknown_085950B4, 0x82, 20, 0, 0, 0, 17
	delay 0x1
	return

Move_SOLAR_BEAM:
	loadspritegfx 0x27A3
	choosetwoturnanim AnimScript_82D08E6, AnimScript_82D09E3

AnimScript_82D08E4:
	waitforvisualfinish
	end

AnimScript_82D08E6:
	monbg ANIM_ATK_PARTNER
	setalpha 0x80C
	createvisualtask sub_8115A04, 0x2, 2, 1, 4, 0, 11, 12287
	playsewithpan SE_W025, -64
	call AnimScript_82D0910
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	goto AnimScript_82D08E4

AnimScript_82D0910:
	createsprite gUnknown_085921E0, 0x2, 40, 40, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, -40, -40, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 0, 40, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 0, -40, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 40, -20, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 40, 20, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, -40, -20, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, -40, 20, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, -20, 30, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 20, -30, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, -20, -30, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 20, 30, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, -40, 0, 16
	delay 0x2
	createsprite gUnknown_085921E0, 0x2, 40, 0, 16
	delay 0x2
	return

AnimScript_82D09E3:
	call AnimScript_82D7D1D
	panse_1B SE_W076, -64, +63, +2, 0x0
	createvisualtask sub_80FEA58, 0x5
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 0
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 1
	delay 0x4
	createvisualtask sub_8116620, 0xA, 4, 1, 0, 10, 1017
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 2
	delay 0x4
	createvisualtask sub_80D52D0, 0x5, 1, 2, 0, 65, 1
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 3
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 4
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 5
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 6
	delay 0x4
	call AnimScript_82D0AB5
	call AnimScript_82D0AB5
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 4, 1, 10, 0, 1017
	call AnimScript_82D7D57
	goto AnimScript_82D08E4

AnimScript_82D0AB5:
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 0
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 1
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 2
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 3
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 4
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 5
	delay 0x4
	createsprite gUnknown_085921F8, 0x83, 15, 0, 20, 6
	delay 0x4
	return

Move_BLIZZARD:
	loadspritegfx 0x279D
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8117754, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D0CB2
	fadetobg BG_HIGHSPEED_OPPONENT

AnimScript_82D0B43:
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -2304, 0, 1, -1
	waitbgfadein
	waitforvisualfinish
	panse_1B SE_W059, -64, +63, +2, 0x0
	call AnimScript_82D0B7D
	call AnimScript_82D0B7D
	playsewithpan SE_W059B, +63
	waitforvisualfinish
	call AnimScript_82D77A4
	waitforvisualfinish
	delay 0x14
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82D0B7D:
	createsprite gUnknown_08595B98, 0x28, 0, -10, 0, -10, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 0, 0, 0, 80, 0, 0, 1
	delay 0x3
	createsprite gUnknown_08595B98, 0x28, 0, -15, 0, -15, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, -10, 0, -10, 80, 0, 0, 1
	delay 0x3
	createsprite gUnknown_08595B98, 0x28, 0, -5, 0, -5, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 10, 0, 10, 80, 0, 0, 1
	delay 0x3
	createsprite gUnknown_08595B98, 0x28, 0, -10, 0, -10, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, -20, 0, -20, 80, 0, 0, 1
	delay 0x3
	createsprite gUnknown_08595B98, 0x28, 0, -20, 0, -20, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 15, 0, 15, 80, 0, 0, 1
	delay 0x3
	createsprite gUnknown_08595B98, 0x28, 0, -15, 0, -15, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, -20, 0, -20, 80, 0, 0, 1
	delay 0x3
	createsprite gUnknown_08595B98, 0x28, 0, -25, 0, -25, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 20, 0, 20, 80, 0, 0, 1
	delay 0x3
	return

AnimScript_82D0CB2:
	fadetobg BG_HIGHSPEED_PLAYER
	goto AnimScript_82D0B43

Move_POWDER_SNOW:
	loadspritegfx 0x279D
	monbg ANIM_DEF_PARTNER
	createsprite gUnknown_08597274, 0x2, 31, 1, 0, 3, RGB_BLACK
	waitforvisualfinish
	panse_1B SE_W016, -64, +63, +2, 0x0
	call AnimScript_82D0D03
	call AnimScript_82D0D03
	playsewithpan SE_W016B, +63
	waitforvisualfinish
	waitsound
	call AnimScript_82D77A4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 0x14
	createsprite gUnknown_08597274, 0x2, 31, 1, 3, 0, RGB_BLACK
	end

AnimScript_82D0D03:
	createsprite gUnknown_08595BC8, 0x28, 0, 0, 0, 0, 56, 4, 4, 1
	delay 0x3
	createsprite gUnknown_08595BC8, 0x28, 0, -10, 0, -10, 56, 4, 4, 1
	delay 0x3
	createsprite gUnknown_08595BC8, 0x28, 0, 10, 0, 10, 56, -4, 3, 1
	delay 0x3
	createsprite gUnknown_08595BC8, 0x28, 0, -20, 0, -20, 56, -4, 5, 1
	delay 0x3
	createsprite gUnknown_08595BC8, 0x28, 0, 15, 0, 15, 56, 4, 4, 1
	delay 0x3
	createsprite gUnknown_08595BC8, 0x28, 0, -20, 0, -20, 56, 4, 4, 1
	delay 0x3
	createsprite gUnknown_08595BC8, 0x28, 0, 20, 0, 20, 56, 4, 4, 1
	delay 0x3
	return

Move_HYDRO_PUMP:
	loadspritegfx 0x27A5
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 40, 1
	delay 0x6
	panse_1B SE_W056, -64, +63, +2, 0x0
	createvisualtask sub_81076C8, 0x5, 100
	call AnimScript_82D0E52
	call AnimScript_82D0E52
	call AnimScript_82D0E52
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 37, 1
	call AnimScript_82D0E93
	call AnimScript_82D0E52
	call AnimScript_82D0E52
	call AnimScript_82D0E93
	call AnimScript_82D0E52
	call AnimScript_82D0E52
	call AnimScript_82D0E93
	call AnimScript_82D0E52
	call AnimScript_82D0E52
	call AnimScript_82D0E93
	call AnimScript_82D0E52
	call AnimScript_82D0E52
	call AnimScript_82D0E93
	delay 0x1
	delay 0x1
	call AnimScript_82D0E93
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D0E52:
	createsprite gUnknown_085950E4, 0x3, 10, 10, 0, 16
	createsprite gUnknown_085950E4, 0x3, 10, 10, 0, -16
	delay 0x1
	createsprite gUnknown_085950E4, 0x3, 10, 10, 0, 16
	createsprite gUnknown_085950E4, 0x3, 10, 10, 0, -16
	delay 0x1
	return

AnimScript_82D0E93:
	createsprite gUnknown_08597388, 0x4, 0, 15, 1, 1
	createsprite gUnknown_08597388, 0x4, 0, -15, 1, 1
	return

Move_SIGNAL_BEAM:
	loadspritegfx 0x2818
	loadspritegfx 0x2819
	loadspritegfx 0x2759
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 25, 1
	delay 0x6
	panse_1B SE_W062, -64, +63, +1, 0x0
	createvisualtask sub_81076C8, 0x5, 100
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 25, 1
	createsprite gUnknown_0859728C, 0x2, 4, 8, 5, 31, 8, 961, 8
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	call AnimScript_82D0F79
	waitforvisualfinish
	end

AnimScript_82D0F79:
	createsprite gUnknown_08595114, 0x83, 10, 10, 0, 16
	createsprite gUnknown_0859512C, 0x83, 10, 10, 0, -16
	delay 0x1
	return

Move_ABSORB:
	loadspritegfx 0x27A3
	loadspritegfx 0x272F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 4, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	delay 0x2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 5, 1
	waitforvisualfinish
	delay 0x3
	call AnimScript_82D1009
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D79DF
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 4, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D1009:
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	delay 0x4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 0x3, 5, -18, -20, 35
	delay 0x4
	return

Move_MEGA_DRAIN:
	loadspritegfx 0x27A3
	loadspritegfx 0x272F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 8, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 1
	delay 0x2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 5, 1
	waitforvisualfinish
	delay 0x3
	call AnimScript_82D1121
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D79DF
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 8, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D1121:
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 5, -18, -20, 35
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	delay 0x4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 5, -18, -20, 35
	delay 0x4
	return

Move_GIGA_DRAIN:
	loadspritegfx 0x27A3
	loadspritegfx 0x272F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 12, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 0
	delay 0x2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 5, 1
	waitforvisualfinish
	delay 0x3
	call AnimScript_82D12B1
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D79DF
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 12, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D12B1:
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 5, -18, -40, 35
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 28, 26
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -10, 20, 40, 39
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -32, 26
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -40, 26
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, -5, 15, 36, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	delay 0x4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 5, -18, -20, 35
	delay 0x4
	return

Move_LEECH_LIFE:
	loadspritegfx 0x27B1
	loadspritegfx 0x27A3
	delay 0x1
	loadspritegfx 0x272F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0x80C
	delay 0x1
	createsprite gUnknown_085969C8, 0x2, -20, 15, 12
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	playsewithpan SE_W071, +63
	delay 0x2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 5, 1
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 7, 0
	waitforvisualfinish
	call AnimScript_82D1009
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D79DF
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 7, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SYNTHESIS:
	loadspritegfx 0x2741
	createvisualtask sub_8115A04, 0x2, 2, 2, 2, 0, 16, 19451
	playsewithpan SE_W025, -64
	call AnimScript_82D79B4
	waitforvisualfinish
	unloadspritegfx 0x2741
	delay 0x1
	loadspritegfx 0x272F
	call AnimScript_82D79DF
	waitforvisualfinish
	end

Move_TOXIC:
	loadspritegfx 0x27A7
	loadspritegfx 0x27A6
	call AnimScript_82D1515
	call AnimScript_82D1515
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D7A71
	waitforvisualfinish
	end

AnimScript_82D1515:
	createsprite gUnknown_08596134, 0x82, -24, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 0xF
	createsprite gUnknown_08596134, 0x82, 8, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 0xF
	createsprite gUnknown_08596134, 0x82, -8, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 0xF
	createsprite gUnknown_08596134, 0x82, 24, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 0xF
	return

Move_SLUDGE:
	loadspritegfx 0x27A6
	playsewithpan SE_W145C, -64
	createsprite gUnknown_085961A8, 0x82, 20, 0, 40, 0
	waitforvisualfinish
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 5, 1
	createvisualtask sub_8115A04, 0x2, 4, 1, 2, 0, 12, 31774
	call AnimScript_82D7A71
	waitforvisualfinish
	end

Move_SLUDGE_BOMB:
	loadspritegfx 0x27A6
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	call AnimScript_82D16BC
	createvisualtask sub_80D52D0, 0x5, 1, 3, 0, 15, 1
	createvisualtask sub_8115A04, 0x2, 4, 1, 2, 0, 12, 31774
	createsprite gUnknown_085961D8, 0x82, 42, 27, 20
	createsprite gUnknown_085961D8, 0x82, -27, 44, 20
	createsprite gUnknown_085961D8, 0x82, 39, -28, 20
	createsprite gUnknown_085961D8, 0x82, -42, -42, 20
	playsewithpan SE_W091, +63
	delay 0x5
	createsprite gUnknown_085961D8, 0x82, 0, 40, 20
	createsprite gUnknown_085961D8, 0x82, -8, -44, 20
	createsprite gUnknown_085961D8, 0x82, -46, -28, 20
	createsprite gUnknown_085961D8, 0x82, 46, 9, 20
	playsewithpan SE_W091, +63
	delay 0x5
	createsprite gUnknown_085961D8, 0x82, 42, 0, 20
	createsprite gUnknown_085961D8, 0x82, -43, -12, 20
	createsprite gUnknown_085961D8, 0x82, 16, -46, 20
	createsprite gUnknown_085961D8, 0x82, -16, 44, 20
	playsewithpan SE_W091, +63
	delay 0x0
	waitsound
	waitforvisualfinish
	call AnimScript_82D7A71
	waitforvisualfinish
	end

AnimScript_82D16BC:
	playsewithpan SE_W145C, -64
	createsprite gUnknown_085961A8, 0x82, 20, 0, 40, 0
	delay 0x3
	return

Move_ACID:
	loadspritegfx 0x27A6
	monbg ANIM_DEF_PARTNER
	createsprite gUnknown_085961C0, 0x82, 20, 0, 40, 1, 0, 0
	playsewithpan SE_W145C, -64
	delay 0x5
	createsprite gUnknown_085961C0, 0x82, 20, 0, 40, 1, 24, 0
	playsewithpan SE_W145C, -64
	delay 0x5
	createsprite gUnknown_085961C0, 0x82, 20, 0, 40, 1, -24, 0
	playsewithpan SE_W145C, -64
	delay 0xF
	createvisualtask sub_80D52D0, 0x5, 1, 2, 0, 10, 1
	createvisualtask sub_80D52D0, 0x5, 3, 2, 0, 10, 1
	createvisualtask sub_8115A04, 0x2, 20, 2, 2, 0, 12, 31774
	createsprite gUnknown_0859620C, 0x82, 0, -22, 0, 15, 55
	playsewithpan SE_W145, +63
	delay 0xA
	createsprite gUnknown_0859620C, 0x82, -26, -24, 0, 15, 55
	playsewithpan SE_W145, +63
	delay 0xA
	createsprite gUnknown_0859620C, 0x82, 15, -27, 0, 15, 50
	playsewithpan SE_W145, +63
	delay 0xA
	createsprite gUnknown_0859620C, 0x82, -15, -17, 0, 10, 45
	playsewithpan SE_W145, +63
	delay 0xA
	createsprite gUnknown_0859620C, 0x82, 27, -22, 0, 15, 50
	playsewithpan SE_W145, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_BONEMERANG:
	loadspritegfx 0x2710
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W155, -64
	createsprite gUnknown_08597178, 0x2
	delay 0x14
	playsewithpan SE_W030, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 1
	createvisualtask sub_80D51AC, 0x5, 1, 5, 0, 5, 1
	delay 0x11
	playsewithpan SE_W233, -64
	createsprite gUnknown_0857FE28, 0x2, 6, -4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_BONE_CLUB:
	loadspritegfx 0x2710
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W155, +63
	createsprite gUnknown_08597190, 0x2, -42, -25, 0, 0, 15
	delay 0xC
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 1
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 5, 1
	createsprite gUnknown_0859728C, 0x2, 7, 5, 1, 0, 10, 0, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_BONE_RUSH:
	loadspritegfx 0x2710
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W155, +63
	createsprite gUnknown_08597190, 0x2, -42, -25, 0, 0, 15
	delay 0xC
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 0, 3, 5, 1
	playsewithpan SE_W030, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SPIKES:
	loadspritegfx 0x27A8
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W026, -64
	waitplaysewithpan SE_W030, +63, 0x1C
	createsprite gUnknown_085CE11C, 0x82, 20, 0, 0, 24, 30
	delay 0xA
	playsewithpan SE_W026, -64
	waitplaysewithpan SE_W030, +63, 0x1C
	createsprite gUnknown_085CE11C, 0x82, 20, 0, -24, 24, 30
	delay 0xA
	waitplaysewithpan SE_W030, +63, 0x1C
	createsprite gUnknown_085CE11C, 0x82, 20, 0, 24, 24, 30
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_MEGAHORN:
	loadspritegfx 0x27A9
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W082, -64
	jumpifcontest AnimScript_82D19FA
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -2304, 768, 1, -1

AnimScript_82D1947:
	waitbgfadein
	setalpha 0x80C
	createvisualtask sub_80D51AC, 0x5, 0, 2, 0, 15, 1
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_0857FE70, 0x2, 0, 24, 0, 0, 6
	delay 0x3
	createsprite gUnknown_08596974, 0x3, -42, 25, 0, 0, 6
	delay 0x4
	playsewithpan SE_W011, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 0
	createsprite gUnknown_0857FE70, 0x2, 1, -16, 4, 1, 4
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 1, -4, 1, 12, 1
	createsprite gUnknown_0859728C, 0x2, 7, 5, 1, 0x7FFF, 10, 0, 0
	delay 0xA
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 11
	delay 0x3
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

AnimScript_82D19FA:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, 2304, 768, 0, -1
	goto AnimScript_82D1947

Move_GUST:
	loadspritegfx 0x2719
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W016, +63
	createsprite gUnknown_08596270, 0x2, 0, -16
	createvisualtask sub_810DED8, 0x5, 1, 70
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x5, 1, 1, 0, 7, 1
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	playsewithpan SE_W016B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_WING_ATTACK:
	loadspritegfx 0x2719
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	loopsewithpan SE_W017, -64, 0x14, 0x2
	createvisualtask sub_80D5738, 0x2, 0, 12, 4, 1, 4
	createvisualtask sub_810DED8, 0x5, 1, 70
	createsprite gUnknown_085962A4, 0x2, -25, 0, 0, 0, 20
	createsprite gUnknown_085962A4, 0x2, 25, 0, 0, 0, 20
	delay 0x18
	createsprite gUnknown_0857FE70, 0x2, 0, 24, 0, 0, 9
	delay 0x11
	createsprite gUnknown_08597358, 0x2, 16, 0, 1, 1
	createsprite gUnknown_08597358, 0x2, -16, 0, 1, 1
	loopsewithpan SE_W003, +63, 0x5, 0x2
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_PECK:
	loadspritegfx 0x2797
	playsewithpan SE_W030, +63
	createvisualtask sub_80D622C, 0x2, 3, -768, 1, 2
	createsprite gUnknown_085973E8, 0x83, -12, 0, 1, 3
	waitforvisualfinish
	end

Move_AEROBLAST:
	loadspritegfx 0x27AA
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	call AnimScript_82D7CE5
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	call AnimScript_82D1B82
	createvisualtask sub_80D51AC, 0x5, 1, 5, 0, 50, 1
	call AnimScript_82D1B82
	call AnimScript_82D1B82
	call AnimScript_82D1B82
	call AnimScript_82D1B82
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 0
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 0x0
	call AnimScript_82D7D15
	end

AnimScript_82D1B82:
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 0x2, 14, -12, 0, -12, 15, 0, 0
	createsprite gUnknown_085962D4, 0x2, 26, 8, 12, 8, 15, 0, 0
	delay 0x3
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 0x2, 14, -12, 0, -12, 15, 1, 0
	createsprite gUnknown_085962D4, 0x2, 26, 8, 12, 8, 15, 1, 0
	delay 0x3
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 0x2, 14, -12, 0, -12, 15, 2, 0
	createsprite gUnknown_085962D4, 0x2, 26, 8, 12, 8, 15, 2, 0
	delay 0x3
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 0x2, 14, -12, 0, -12, 15, 3, 0
	createsprite gUnknown_085962D4, 0x2, 26, 8, 12, 8, 15, 3, 0
	delay 0x3
	return

Move_WATER_GUN:
	loadspritegfx 0x27AB
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_08595208, 0x2, 20, 0, 0, 0, 40, -25
	playsewithpan SE_W145, -64
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x5, 1, 1, 0, 8, 1
	createsprite gUnknown_08597388, 0x4, 0, 0, 1, 2
	createsprite gUnknown_08595220, 0x2, 0, -15, 0, 15, 55
	playsewithpan SE_W152, +63
	delay 0xA
	createsprite gUnknown_08595220, 0x2, 15, -20, 0, 15, 50
	playsewithpan SE_W152, +63
	delay 0xA
	createsprite gUnknown_08595220, 0x2, -15, -10, 0, 10, 45
	playsewithpan SE_W152, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_CRABHAMMER:
	loadspritegfx 0x279D
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createsprite gUnknown_08597388, 0x4, 0, 0, 1, 0
	playsewithpan SE_W233B, +63
	delay 0x1
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 32429, 10, 0, 0
	createsprite gUnknown_0857FE70, 0x2, 1, -24, 0, 0, 4
	waitforvisualfinish
	delay 0x8
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 4
	waitforvisualfinish
	loopsewithpan SE_W152, +63, 0x14, 0x3
	createvisualtask sub_80D51AC, 0x5, 1, 0, 4, 8, 1
	createsprite gUnknown_08595238, 0x2, 10, 10, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, 20, -20, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, -15, 15, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, 0, 0, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, -10, -20, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, 16, -8, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, 5, 8, 20, 1
	delay 0x4
	createsprite gUnknown_08595238, 0x2, -16, 0, 20, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SURF:
	createvisualtask sub_8107954, 0x2, 0
	delay 0x18
	panse_1B SE_W057, -64, +63, +2, 0x0
	waitforvisualfinish
	end

Move_FLAMETHROWER:
	loadspritegfx 0x272D
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 46, 1
	delay 0x6
	createvisualtask sub_81076C8, 0x5, 100
	panse_1B SE_W053, -64, +63, +2, 0x0
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 43, 1
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	call AnimScript_82D1E58
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D1E58:
	createsprite gUnknown_08595158, 0x3, 10, 10, 0, 16
	delay 0x2
	createsprite gUnknown_08595158, 0x3, 10, 10, 0, 16
	delay 0x2
	return

Move_SANDSTORM:
	loadspritegfx 0x2815
	playsewithpan SE_W201, 0
	createvisualtask sub_8110BCC, 0x5, 0
	delay 0x10
	createsprite gUnknown_08596BA0, 0x28, 10, 2304, 96, 0
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 90, 2048, 96, 0
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 50, 2560, 96, 0
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 20, 2304, 96, 0
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 70, 1984, 96, 0
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 0, 2816, 96, 0
	delay 0xA
	createsprite gUnknown_08596BA0, 0x28, 60, 2560, 96, 0
	end

Move_WHIRLPOOL:
	loadspritegfx 0x27A5
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	delay 0x0
	createsprite gUnknown_08597274, 0x0, 4, 2, 0, 7, RGB(0, 13, 23)
	playsewithpan SE_W250, +63
	createvisualtask sub_80D51AC, 0x5, 1, 0, 2, 50, 1
	call AnimScript_82D1F5B
	call AnimScript_82D1F5B
	call AnimScript_82D1F5B
	delay 0xC
	createsprite gUnknown_08597274, 0x0, 4, 2, 7, 0, RGB(0, 13, 23)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82D1F5B:
	createsprite gUnknown_08596B70, 0x82, 0, 28, 384, 50, 8, 50, 1
	delay 0x2
	createsprite gUnknown_08596B70, 0x82, 0, 32, 240, 40, 11, -46, 1
	delay 0x2
	createsprite gUnknown_08596B70, 0x82, 0, 33, 416, 40, 4, 42, 1
	delay 0x2
	createsprite gUnknown_08596B70, 0x82, 0, 31, 288, 45, 6, -42, 1
	delay 0x2
	createsprite gUnknown_08596B70, 0x82, 0, 28, 448, 45, 11, 46, 1
	delay 0x2
	createsprite gUnknown_08596B70, 0x82, 0, 33, 464, 50, 10, -50, 1
	delay 0x2
	return

Move_FLY:
	loadspritegfx 0x27AC
	loadspritegfx 0x2797
	choosetwoturnanim AnimScript_82D1FF7, AnimScript_82D200F

AnimScript_82D1FF5:
	waitforvisualfinish
	end

AnimScript_82D1FF7:
	playsewithpan SE_W019, -64
	createsprite gUnknown_08596340, 0x2, 0, 0, 13, 336
	goto AnimScript_82D1FF5

AnimScript_82D200F:
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W104, -64
	createsprite gUnknown_08596358, 0x2, 20
	delay 0x14
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 0
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto AnimScript_82D1FF5

Move_BOUNCE:
	loadspritegfx 0x27AC
	loadspritegfx 0x2797
	choosetwoturnanim AnimScript_82D2060, AnimScript_82D2074

AnimScript_82D205F:
	end

AnimScript_82D2060:
	playsewithpan SE_W100, -64
	createsprite gUnknown_08596420, 0x2, 0, 0
	goto AnimScript_82D205F

AnimScript_82D2074:
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W207, +63
	createsprite gUnknown_0859644C, 0x83
	delay 0x7
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 0
	createvisualtask sub_80D51AC, 0x5, 1, 0, 5, 11, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto AnimScript_82D205F

Move_KARATE_CHOP:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W104, +63
	createsprite gUnknown_08595E68, 0x2, -16, 0, 0, 0, 10, 1, 3, 0
	waitforvisualfinish
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 4, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_CROSS_CHOP:
	loadspritegfx 0x279F
	loadspritegfx 0x282D
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W025, +63
	createsprite gUnknown_08595EC8, 0x2, 0, 0, 0
	createsprite gUnknown_08595EC8, 0x2, 0, 0, 1
	delay 0x28
	playsewithpan SE_W013, +63
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0x7FFF, 10, 0, 10
	createsprite gUnknown_085973D0, 0x3, 0, 0, 1, 20
	createvisualtask sub_80D51AC, 0x5, 1, 7, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_JUMP_KICK:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x3
	createsprite gUnknown_08595E80, 0x2, -16, 8, 0, 0, 10, 1, 1, 1
	playsewithpan SE_W026, +63
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x1, 0, 0, 1, 1
	createvisualtask sub_80D51AC, 0x5, 1, 5, 0, 7, 1
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_HI_JUMP_KICK:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createsprite gUnknown_0857FE70, 0x2, 0, -24, 0, 0, 8
	waitforvisualfinish
	delay 0xA
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 3
	delay 0x2
	createsprite gUnknown_08595E80, 0x2, -16, 8, 0, 0, 10, 1, 1, 1
	playsewithpan SE_W026, +63
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_0857FE70, 0x2, 1, -28, 0, 0, 3
	delay 0x3
	createvisualtask sub_80D5484, 0x2, 1, 3, 0, 11, 1
	waitforvisualfinish
	delay 0x5
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_KICK:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createsprite gUnknown_08595EB0, 0x3, 1, 20, 1
	createvisualtask sub_80D51AC, 0x5, 1, 4, 0, 6, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TRIPLE_KICK:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W233B, +63
	jumpifmoveturn 0x0, AnimScript_82D22B8
	jumpifmoveturn 0x1, AnimScript_82D22EE
	goto AnimScript_82D2324

AnimScript_82D22B3:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D22B8:
	createsprite gUnknown_08595E98, 0x84, -16, -8, 20, 1, 1
	createsprite gUnknown_08597358, 0x83, -16, -16, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 4, 0, 6, 1
	goto AnimScript_82D22B3

AnimScript_82D22EE:
	createsprite gUnknown_08595E98, 0x84, 8, 8, 20, 1, 1
	createsprite gUnknown_08597358, 0x83, 8, 0, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 4, 0, 6, 1
	goto AnimScript_82D22B3

AnimScript_82D2324:
	createsprite gUnknown_08595E98, 0x84, 0, 0, 20, 1, 1
	createsprite gUnknown_08597358, 0x83, 0, -8, 1, 1
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	goto AnimScript_82D22B3

Move_DYNAMIC_PUNCH:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	loadspritegfx 0x27D6
	loadspritegfx 0x2717
	delay 0x1
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08595E98, 0x83, 0, 0, 20, 1, 0
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 0
	createvisualtask sub_80D51AC, 0x5, 1, 5, 0, 7, 1
	delay 0x1
	waitsound
	playsewithpan SE_W120, +63
	createvisualtask sub_80D52D0, 0x5, 1, 5, 0, 28, 1
	createsprite gUnknown_0859371C, 0x3, 0, 0, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, 24, -24, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, -16, 16, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, -24, -12, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, 16, 16, 1, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_COUNTER:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_80D5830, 0x2, 0, 18, 6, 1, 4
	playsewithpan SE_W233, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 20, 0, 0, 4
	delay 0x4
	createsprite gUnknown_08597358, 0x2, -15, 18, 1, 0
	playsewithpan SE_W233B, +63
	delay 0x1
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 25, 1
	createsprite gUnknown_08595E98, 0x3, -15, 18, 8, 1, 0
	delay 0x3
	createsprite gUnknown_08597358, 0x2, 0, -4, 1, 0
	playsewithpan SE_W233B, +63
	delay 0x1
	createsprite gUnknown_08595E98, 0x3, 0, -4, 8, 1, 0
	delay 0x3
	createsprite gUnknown_08597358, 0x2, 15, 9, 1, 0
	playsewithpan SE_W233B, +63
	delay 0x1
	createsprite gUnknown_08595E98, 0x3, 15, 9, 8, 1, 0
	delay 0x5
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_VITAL_THROW:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W233, -64
	createvisualtask sub_80D5830, 0x2, 0, 12, 4, 1, 2
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 20, 0, 0, 4
	delay 0x2
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	delay 0x1
	createsprite gUnknown_0857FE70, 0x2, 1, -24, 0, 0, 4
	waitforvisualfinish
	delay 0x3
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 7
	delay 0xB
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 10
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROCK_SMASH:
	loadspritegfx 0x274A
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	delay 0x1
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	createsprite gUnknown_08595E98, 0x2, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, +63
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 5, 1
	waitforvisualfinish
	playsewithpan SE_W088, +63
	createsprite gUnknown_08596B1C, 0x2, 0, 0, 20, 24, 14, 2
	createsprite gUnknown_08596B1C, 0x2, 5, 0, -20, 24, 14, 1
	createsprite gUnknown_08596B1C, 0x2, 0, 5, 20, -24, 14, 2
	createsprite gUnknown_08596B1C, 0x2, -5, 0, -20, -24, 14, 2
	createsprite gUnknown_08596B1C, 0x2, 0, -5, 30, 18, 8, 2
	createsprite gUnknown_08596B1C, 0x2, 0, 0, 30, -18, 8, 2
	createsprite gUnknown_08596B1C, 0x2, 0, 0, -30, 18, 8, 2
	createsprite gUnknown_08596B1C, 0x2, 0, 0, -30, -18, 8, 2
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 7, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUBMISSION:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W104, -64
	waitplaysewithpan SE_W004, +63, 0xA
	waitplaysewithpan SE_W104, -64, 0x14
	waitplaysewithpan SE_W004, +63, 0x1E
	waitplaysewithpan SE_W104, -64, 0x28
	waitplaysewithpan SE_W004, +63, 0x32
	waitplaysewithpan SE_W104, -64, 0x3C
	waitplaysewithpan SE_W004, +63, 0x46
	waitplaysewithpan SE_W104, -64, 0x50
	waitplaysewithpan SE_W004, +63, 0x5A
	createvisualtask sub_80D5738, 0x2, 0, -18, 6, 6, 4
	createvisualtask sub_80D5738, 0x2, 1, 18, 6, 6, 4
	call AnimScript_82D26D3
	call AnimScript_82D26D3
	call AnimScript_82D26D3
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D26D3:
	createsprite gUnknown_08597358, 0x3, 0, -12, 1, 1
	delay 0x8
	createsprite gUnknown_08597358, 0x3, -12, 8, 1, 1
	delay 0x8
	createsprite gUnknown_08597358, 0x3, 12, 0, 1, 1
	delay 0x8
	return

Move_SUNNY_DAY:
	loadspritegfx 0x27AD
	monbg ANIM_ATK_PARTNER
	setalpha 0x30D
	createvisualtask sub_8116620, 0xA, 1921, 1, 0, 6, 0x7FFF
	waitforvisualfinish
	panse_26 SE_W080, -64, +63, +1, 0x0
	call AnimScript_82D2753
	call AnimScript_82D2753
	call AnimScript_82D2753
	call AnimScript_82D2753
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1921, 1, 6, 0, 0x7FFF
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

AnimScript_82D2753:
	createsprite gUnknown_085954A0, 0x28
	delay 0x6
	return

Move_COTTON_SPORE:
	loadspritegfx 0x27AE
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W077, +63, 0x12, 0xA
	call AnimScript_82D277D
	call AnimScript_82D277D
	call AnimScript_82D277D
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82D277D:
	createsprite gUnknown_085922EC, 0x2, 0, -20, 85, 80, 0
	delay 0xC
	createsprite gUnknown_085922EC, 0x2, 0, -10, 170, 80, 0
	delay 0xC
	createsprite gUnknown_085922EC, 0x2, 0, -15, 0, 80, 0
	delay 0xC
	return

Move_SPORE:
	loadspritegfx 0x27AE
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_80FEE1C, 0x2
	loopsewithpan SE_W077, +63, 0x10, 0xB
	call AnimScript_82D27E2
	call AnimScript_82D27E2
	call AnimScript_82D27E2
	waitforvisualfinish
	delay 0x1
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D27E2:
	createsprite gUnknown_085922EC, 0x82, 0, -20, 85, 80, 1
	delay 0xC
	createsprite gUnknown_085922EC, 0x82, 0, -10, 170, 80, 1
	delay 0xC
	createsprite gUnknown_085922EC, 0x82, 0, -15, 0, 80, 1
	delay 0xC
	return

Move_PETAL_DANCE:
	loadspritegfx 0x27AF
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W080, -64
	createvisualtask sub_80D5830, 0x2, 0, 12, 6, 6, 3
	createsprite gUnknown_0859231C, 0x2, 0, -24, 8, 140
	createsprite gUnknown_08592334, 0x2, 16, -24, 8, 100
	createsprite gUnknown_08592334, 0x2, -16, -24, 8, 100
	delay 0xF
	createsprite gUnknown_0859231C, 0x2, 0, -24, 8, 140
	createsprite gUnknown_08592334, 0x2, 32, -24, 8, 100
	createsprite gUnknown_08592334, 0x2, -32, -24, 8, 100
	delay 0xF
	createsprite gUnknown_0859231C, 0x2, 0, -24, 8, 140
	createsprite gUnknown_08592334, 0x2, 24, -24, 8, 100
	createsprite gUnknown_08592334, 0x2, -24, -24, 8, 100
	delay 0x1E
	createsprite gUnknown_08592334, 0x2, 16, -24, 0, 100
	createsprite gUnknown_08592334, 0x2, -16, -24, 0, 100
	delay 0x1E
	createsprite gUnknown_08592334, 0x2, 20, -16, 14, 80
	createsprite gUnknown_08592334, 0x2, -20, -14, 16, 80
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 24, 0, 0, 5
	delay 0x3
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 0
	createvisualtask sub_80D51AC, 0x2, 1, 6, 0, 8, 1
	waitforvisualfinish
	delay 0x8
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_RAZOR_LEAF:
	loadspritegfx 0x274F
	loadspritegfx 0x27B0
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	delay 0x1
	loopsewithpan SE_W077, -64, 0xA, 0x5
	createsprite gUnknown_08592390, 0x2, -3, -2, 10
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -1, -1, 15
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -4, -4, 7
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 3, -3, 11
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -1, -6, 8
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 2, -1, 12
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -3, -4, 13
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 4, -5, 7
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 2, -6, 11
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -3, -5, 8
	delay 0x3C
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085923D8, 0x83, 20, -10, 20, 0, 22, 20, 1
	createsprite gUnknown_085923D8, 0x83, 20, -10, 20, 0, 22, -20, 1
	delay 0x14
	playsewithpan SE_W013, +63
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	createvisualtask sub_80D52D0, 0x2, 3, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_NATURE_POWER:
Move_ANCIENT_POWER:
	loadspritegfx 0x274A
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createsprite gUnknown_085972D8, 0x2, 4, 1, 10, 1
	createsprite gUnknown_08596C10, 0x2, 20, 32, -48, 50, 2
	createsprite gUnknown_08596C10, 0x2, 0, 32, -38, 25, 5
	createsprite gUnknown_08596C10, 0x2, 32, 32, -28, 40, 3
	createsprite gUnknown_08596C10, 0x2, -20, 32, -48, 50, 2
	createsprite gUnknown_08596C10, 0x2, 20, 32, -28, 60, 1
	createsprite gUnknown_08596C10, 0x2, 0, 32, -28, 30, 4
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 30, 1
	playsewithpan SE_W082, -64
	delay 0xA
	createsprite gUnknown_08596C10, 0x2, 15, 32, -48, 25, 5
	createsprite gUnknown_08596C10, 0x2, -10, 32, -42, 30, 4
	delay 0xA
	createsprite gUnknown_08596C10, 0x2, 0, 32, -42, 25, 5
	createsprite gUnknown_08596C10, 0x2, -25, 32, -48, 30, 4
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 16, 0, 0, 4
	delay 0x3
	playsewithpan SE_W120, +63
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 1
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_OCTAZOOKA:
	loadspritegfx 0x272E
	loadspritegfx 0x2721
	playsewithpan SE_W025B, -64
	createsprite gUnknown_08592DFC, 0x82, 20, 0, 0, 0, 20, 0
	waitforvisualfinish
	playsewithpan SE_W120, +63
	createsprite gUnknown_08592E30, 0x82, 8, 8, 1, 0
	delay 0x2
	createsprite gUnknown_08592E30, 0x82, -8, -8, 1, 0
	delay 0x2
	createsprite gUnknown_08592E30, 0x82, 8, -8, 1, 0
	delay 0x2
	createsprite gUnknown_08592E30, 0x82, -8, 8, 1, 0
	waitforvisualfinish
	end

Move_MIST:
	loadspritegfx 0x27A0
	monbg ANIM_ATK_PARTNER
	setalpha 0x80C
	loopsewithpan SE_W054, -64, 0x14, 0xF
	call AnimScript_82D2C34
	call AnimScript_82D2C34
	call AnimScript_82D2C34
	call AnimScript_82D2C34
	call AnimScript_82D2C34
	call AnimScript_82D2C34
	call AnimScript_82D2C34
	delay 0x20
	createvisualtask sub_8115A04, 0x2, 10, 8, 2, 0, 14, 0x7FFF
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

AnimScript_82D2C34:
	createsprite gUnknown_08595C2C, 0x2, 0, -24, 48, 240, 0, 1
	delay 0x7
	return

Move_HAZE:
	waitforvisualfinish
	playsewithpan SE_W114, 0
	createvisualtask sub_810C0A0, 0x5
	delay 0x1E
	createvisualtask sub_8116620, 0xA, 1920, 2, 0, 16, 0
	delay 0x5A
	createvisualtask sub_8116620, 0xA, 1920, 1, 16, 0, 0
	end

Move_FIRE_PUNCH:
	loadspritegfx 0x279F
	loadspritegfx 0x272D
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 9, 31
	createsprite gUnknown_08595368, 0x81, 0
	createsprite gUnknown_08595368, 0x81, 64
	createsprite gUnknown_08595368, 0x81, 128
	createsprite gUnknown_08595368, 0x81, 196
	playsewithpan SE_W172, +63
	waitforvisualfinish
	createsprite gUnknown_08595E98, 0x83, 0, 0, 8, 1, 0
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 1
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 15, 1
	call AnimScript_82D2D18
	delay 0x4
	playsewithpan SE_W007, +63
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 4, 0, 9, 0, 31
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D2D18:
	createsprite gUnknown_08595380, 0x81, 0, 10, 192, 176, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, -192, 240, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 192, -160, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, -192, -112, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 160, 48, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, -224, -32, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 112, -128, 40
	return

Move_LEER:
	loadspritegfx 0x272B
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x808
	playsewithpan SE_W043, -64
	createsprite gUnknown_085CE150, 0x2, 24, -12
	createvisualtask sub_80D6064, 0x5, -5, -5, 10, 0, 1
	waitforvisualfinish
	delay 0xA
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 9, 1
	createvisualtask sub_80D52D0, 0x2, 3, 1, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 0x1
	waitforvisualfinish
	end

Move_DREAM_EATER:
	loadspritegfx 0x27A3
	loadspritegfx 0x272F
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	playsewithpan SE_W060, -64
	call AnimScript_82D7CD1
	setalpha 0x808
	playsewithpan SE_W107, +63
	createvisualtask sub_80D51AC, 0x2, 1, 5, 0, 15, 1
	createvisualtask sub_80D6064, 0x5, -6, -6, 15, 1, 1
	waitforvisualfinish
	setalpha 0x80C
	createvisualtask sub_80D51AC, 0x2, 1, 0, 2, 25, 1
	call AnimScript_82D2E51
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D79DF
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 0x1
	call AnimScript_82D7CDD
	end

AnimScript_82D2E51:
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 5, -18, -40, 35
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 28, 26
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -10, 20, 40, 39
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -32, 26
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -40, 26
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, -5, 15, 36, 33
	createsprite gUnknown_08592270, 0x3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 0x3, -10, 20, 20, 39
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 0x3, 5, -18, -20, 35
	delay 0x4
	return

Move_POISON_GAS:
	loadspritegfx 0x27BC
	loadspritegfx 0x27A6
	delay 0x0
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	setalpha 0x80C
	delay 0x0
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x28
	loopsewithpan SE_W054, +63, 0x1C, 0x6
	createvisualtask sub_8115A04, 0x2, 4, 6, 2, 0, 12, 26650
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0x0
	end

Move_BIND:
	createvisualtask sub_80D5EB8, 0x5, 0, 6, 3328, 4, 0
	goto AnimScript_82D30DE

AnimScript_82D30DE:
	playsewithpan SE_W020, +63
	call AnimScript_82D30EE
	call AnimScript_82D30EE
	waitforvisualfinish
	end

AnimScript_82D30EE:
	createvisualtask sub_80D6064, 0x5, 10, -5, 5, 1, 0
	delay 0x10
	return

Move_WRAP:
	createvisualtask sub_80D5830, 0x2, 0, 6, 4, 2, 4
	goto AnimScript_82D30DE

Move_PSYBEAM:
	loadspritegfx 0x27B3
	playsewithpan SE_W060, -64
	call AnimScript_82D7CD1
	createsoundtask sub_8158C58, 200, -64, 63, 3, 4, 0, 15
	call AnimScript_82D319C
	call AnimScript_82D319C
	createvisualtask sub_80D5EB8, 0x5, 0, 6, 2048, 4, 1
	createvisualtask sub_8115A04, 0x2, 4, 2, 2, 0, 12, 32351
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	call AnimScript_82D319C
	waitforvisualfinish
	delay 0x1
	call AnimScript_82D7CDD
	end

AnimScript_82D319C:
	createsprite gUnknown_0859663C, 0x82, 16, 0, 0, 0, 13, 0
	delay 0x4
	return

Move_HYPNOSIS:
	loadspritegfx 0x27B3
	call AnimScript_82D7CD1
	call AnimScript_82D31E5
	call AnimScript_82D31E5
	call AnimScript_82D31E5
	createvisualtask sub_8115A04, 0x2, 4, 2, 2, 0, 12, 32351
	waitforvisualfinish
	delay 0x1
	call AnimScript_82D7CDD
	end

AnimScript_82D31E5:
	playsewithpan SE_W048, -64
	createsprite gUnknown_0859663C, 0x82, 0, 8, 0, 8, 27, 0
	createsprite gUnknown_0859663C, 0x82, 16, -8, 0, -8, 27, 0
	delay 0x6
	return

Move_PSYWAVE:
	loadspritegfx 0x27B5
	playsewithpan SE_W060, -64
	call AnimScript_82D7CD1
	createvisualtask sub_81076C8, 0x5, 100
	createsoundtask sub_8158C58, 203, -64, 63, 2, 9, 0, 10
	call AnimScript_82D3275
	call AnimScript_82D3275
	createvisualtask sub_8115A04, 0x2, 4, 1, 4, 0, 12, 32351
	call AnimScript_82D3275
	call AnimScript_82D3275
	call AnimScript_82D3275
	call AnimScript_82D3275
	waitforvisualfinish
	delay 0x1
	call AnimScript_82D7CDD
	end

AnimScript_82D3275:
	createsprite gUnknown_08595170, 0x83, 10, 10, 0, 16
	delay 0x4
	createsprite gUnknown_08595170, 0x83, 10, 10, 0, 16
	delay 0x4
	return

Move_ZAP_CANNON:
	loadspritegfx 0x27BB
	loadspritegfx 0x271B
	playsewithpan SE_W086, -64
	createsprite gUnknown_08595764, 0x83, 10, 0, 0, 0, 30, 0
	createsprite gUnknown_08595790, 0x84, 10, 0, 16, 30, 0, 40, 0
	createsprite gUnknown_08595790, 0x84, 10, 0, 16, 30, 64, 40, 1
	createsprite gUnknown_08595790, 0x84, 10, 0, 16, 30, 128, 40, 0
	createsprite gUnknown_08595790, 0x84, 10, 0, 16, 30, 192, 40, 2
	createsprite gUnknown_08595790, 0x84, 10, 0, 8, 30, 32, 40, 0
	createsprite gUnknown_08595790, 0x84, 10, 0, 8, 30, 96, 40, 1
	createsprite gUnknown_08595790, 0x84, 10, 0, 8, 30, 160, 40, 0
	createsprite gUnknown_08595790, 0x84, 10, 0, 8, 30, 224, 40, 2
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 5, 1
	delay 0xF
	waitplaysewithpan SE_W085B, +63, 0x13
	call AnimScript_82D7BEA
	waitforvisualfinish
	end

Move_STEEL_WING:
	loadspritegfx 0x2719
	loadspritegfx 0x2797
	loopsewithpan SE_W231, -64, 0x1C, 0x2
	createvisualtask sub_81144F8, 0x5, 0, 0, 0
	waitforvisualfinish
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	loopsewithpan SE_W017, -64, 0x14, 0x2
	createvisualtask sub_80D5738, 0x2, 0, 12, 4, 1, 4
	createvisualtask sub_810DED8, 0x5, 1, 70
	createsprite gUnknown_085962A4, 0x2, -25, 0, 0, 0, 20
	createsprite gUnknown_085962A4, 0x2, 25, 0, 0, 0, 20
	delay 0x18
	createsprite gUnknown_0857FE70, 0x2, 0, 24, 0, 0, 9
	delay 0x11
	createsprite gUnknown_08597358, 0x2, 16, 0, 1, 1
	createsprite gUnknown_08597358, 0x2, -16, 0, 1, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_IRON_TAIL:
	loadspritegfx 0x2797
	loopsewithpan SE_W231, -64, 0x1C, 0x2
	createvisualtask sub_81144F8, 0x5, 1, 0, 0
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x6
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createvisualtask sub_811489C, 0x5, 0, 1
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_POISON_TAIL:
	loadspritegfx 0x2797
	loadspritegfx 0x27A6
	loopsewithpan SE_W231, -64, 0x1C, 0x2
	createvisualtask sub_81144F8, 0x5, 1, 1, RGB(24, 6, 23)
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_0857FE28, 0x2, 4, 4
	delay 0x6
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createvisualtask sub_811489C, 0x5, 0, 1
	clearmonbg ANIM_TARGET
	blendoff
	call AnimScript_82D7A71
	waitforvisualfinish
	end

Move_METAL_CLAW:
	loadspritegfx 0x2737
	loopsewithpan SE_W231, -64, 0x1C, 0x2
	createvisualtask sub_81144F8, 0x5, 0, 0, 0
	waitforvisualfinish
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x2
	playsewithpan SE_W013, +63
	createsprite gUnknown_08597138, 0x82, -10, -10, 0
	createsprite gUnknown_08597138, 0x82, -10, 10, 0
	createsprite gUnknown_085972D8, 0x2, -4, 1, 10, 3, 1
	delay 0x8
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x2
	playsewithpan SE_W013, +63
	createsprite gUnknown_08597138, 0x82, 10, -10, 1
	createsprite gUnknown_08597138, 0x82, 10, 10, 1
	createsprite gUnknown_085972D8, 0x2, -4, 1, 10, 3, 1
	waitforvisualfinish
	end

Move_NIGHT_SHADE:
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	playsewithpan SE_W060, -64
	fadetobg BG_GHOST
	waitbgfadein
	delay 0xA
	playsewithpan SE_W043, -64
	createvisualtask sub_811188C, 0x5, 85
	delay 0x46
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 12, 1
	createvisualtask sub_8115A04, 0x2, 4, 0, 2, 0, 13, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 0x1
	restorebg
	waitbgfadein
	end

Move_EGG_BOMB:
	loadspritegfx 0x27D6
	loadspritegfx 0x27BF
	playsewithpan SE_W039, -64
	createsprite gUnknown_08593488, 0x82, 10, 0, 0, 0, 25, -32
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 16, 1
	createsprite gUnknown_0859371C, 0x84, 6, 5, 1, 0
	playsewithpan SE_W120, +63
	delay 0x3
	createsprite gUnknown_0859371C, 0x84, -16, -15, 1, 0
	playsewithpan SE_W120, +63
	delay 0x3
	createsprite gUnknown_0859371C, 0x84, 16, -5, 1, 0
	playsewithpan SE_W120, +63
	delay 0x3
	createsprite gUnknown_0859371C, 0x84, -12, 18, 1, 0
	playsewithpan SE_W120, +63
	delay 0x3
	createsprite gUnknown_0859371C, 0x84, 0, 5, 1, 0
	playsewithpan SE_W120, +63
	delay 0x3
	waitforvisualfinish
	end

Move_SHADOW_BALL:
	loadspritegfx 0x27C0
	fadetobg BG_GHOST
	waitbgfadein
	delay 0xF
	createsoundtask sub_8158C58, 168, -64, 63, 5, 5, 0, 5
	createsprite gUnknown_08596D58, 0x82, 16, 16, 8
	waitforvisualfinish
	playsewithpan SE_W028, +63
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 8, 1
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_LICK:
	loadspritegfx 0x27C1
	delay 0xF
	playsewithpan SE_W122, +63
	createsprite gUnknown_08596D8C, 0x82, 0, 0
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 16, 1
	waitforvisualfinish
	end

Move_FOCUS_ENERGY:
	loadspritegfx 0x27C8
	playsewithpan SE_W082, -64
	call AnimScript_82CD6C7
	delay 0x8
	createvisualtask sub_8115A04, 0x2, 2, 2, 2, 0, 11, 0x7FFF
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 32, 1
	call AnimScript_82CD6C7
	delay 0x8
	call AnimScript_82CD6C7
	waitforvisualfinish
	end

Move_BIDE:
	choosetwoturnanim AnimScript_82D3719, AnimScript_82D3745
	end

AnimScript_82D3719:
	loopsewithpan SE_W036, -64, 0x9, 0x2
	createvisualtask sub_8115A04, 0x2, 2, 2, 2, 0, 11, 31
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 32, 1
	waitforvisualfinish
	end

AnimScript_82D3745:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	loopsewithpan SE_W036, -64, 0x9, 0x2
	createvisualtask sub_8116620, 0xA, 2, 2, 0, 11, 31
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 32, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE70, 0x2, 0, 24, 0, 0, 4
	waitforvisualfinish
	createvisualtask sub_80D5484, 0x2, 0, 2, 0, 12, 1
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 16, 1
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x1, 18, -8, 1, 1
	delay 0x5
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x1, -18, 8, 1, 1
	delay 0x5
	playsewithpan SE_W004, +63
	createsprite gUnknown_08597358, 0x1, -8, -5, 1, 1
	waitforvisualfinish
	delay 0x5
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 7
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 2, 2, 11, 0, 31
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRING_SHOT:
	loadspritegfx 0x27C3
	loadspritegfx 0x27C4
	monbg ANIM_DEF_PARTNER
	delay 0x0
	createsprite gUnknown_08597274, 0x5, 1, 2, 0, 9, 0
	waitforvisualfinish
	loopsewithpan SE_W081, -64, 0x9, 0x6
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	call AnimScript_82D38CC
	waitforvisualfinish
	playsewithpan SE_W081B, +63
	createsprite gUnknown_085969F8, 0x82, 0, 10
	delay 0x4
	createsprite gUnknown_085969F8, 0x82, 0, -2
	delay 0x4
	createsprite gUnknown_085969F8, 0x82, 0, 22
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 0x1
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x5, 1, 2, 9, 0, 0
	end

AnimScript_82D38CC:
	createsprite gUnknown_085969E0, 0x82, 20, 0, 512, 20, 1
	delay 0x1
	return

Move_SPIDER_WEB:
	loadspritegfx 0x27C5
	loadspritegfx 0x27C4
	monbg ANIM_DEF_PARTNER
	delay 0x0
	createsprite gUnknown_08597274, 0x5, 1, 2, 0, 9, 0
	waitforvisualfinish
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W081, -64, 0x9, 0x6
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	call AnimScript_82D396D
	waitforvisualfinish
	playsewithpan SE_W081B, +63
	createsprite gUnknown_08596A2C, 0x2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 0x1
	createsprite gUnknown_08597274, 0x5, 1, 2, 9, 0, 0
	end

AnimScript_82D396D:
	createsprite gUnknown_085969E0, 0x82, 20, 0, 512, 20, 0
	delay 0x1
	return

Move_RAZOR_WIND:
	choosetwoturnanim AnimScript_82D398C, AnimScript_82D39DC

AnimScript_82D398A:
	waitforvisualfinish
	end

AnimScript_82D398C:
	loadspritegfx 0x2719
	playsewithpan SE_W016, -64
	createsprite gUnknown_08593550, 0x2, 32, 0, 16, 16, 0, 7, 40
	createsprite gUnknown_08593550, 0x2, 32, 0, 16, 16, 85, 7, 40
	createsprite gUnknown_08593550, 0x2, 32, 0, 16, 16, 170, 7, 40
	waitforvisualfinish
	playsewithpan SE_W016B, -64
	goto AnimScript_82D398A

AnimScript_82D39DC:
	loadspritegfx 0x27AA
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085962D4, 0x2, 14, 8, 0, 0, 22, 2, 1
	delay 0x2
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085962D4, 0x2, 14, -8, 16, 14, 22, 1, 1
	delay 0x2
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085962D4, 0x2, 14, 12, -16, -14, 22, 0, 1
	delay 0x11
	playsewithpan SE_W013, +63
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 10, 1
	createvisualtask sub_80D52D0, 0x2, 3, 2, 0, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	goto AnimScript_82D398A

Move_DISABLE:
	loadspritegfx 0x2757
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x808
	playsewithpan SE_W197, -64
	createsprite gUnknown_0853EE84, 0xD, 24, -16
	waitforvisualfinish
	createvisualtask sub_81045B0, 0x5
	loopsewithpan SE_W020, +63, 0xF, 0x4
	waitforvisualfinish
	delay 0x1
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_RECOVER:
	loadspritegfx 0x27A3
	loadspritegfx 0x272F
	monbg ANIM_ATK_PARTNER
	setalpha 0x80C
	loopsewithpan SE_W025, -64, 0xD, 0x3
	createvisualtask sub_8115A04, 0x2, 2, 0, 6, 0, 11, 12287
	call AnimScript_82D3AD5
	call AnimScript_82D3AD5
	call AnimScript_82D3AD5
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 0x1
	call AnimScript_82D79DF
	waitforvisualfinish
	end

AnimScript_82D3AD5:
	createsprite gUnknown_085921E0, 0x2, 40, -10, 13
	delay 0x3
	createsprite gUnknown_085921E0, 0x2, -35, -10, 13
	delay 0x3
	createsprite gUnknown_085921E0, 0x2, 15, -40, 13
	delay 0x3
	createsprite gUnknown_085921E0, 0x2, -10, -32, 13
	delay 0x3
	createsprite gUnknown_085921E0, 0x2, 25, -20, 13
	delay 0x3
	createsprite gUnknown_085921E0, 0x2, -40, -20, 13
	delay 0x3
	createsprite gUnknown_085921E0, 0x2, 5, -40, 13
	delay 0x3
	return

Move_MIMIC:
	loadspritegfx 0x27A3
	setalpha 0x50B
	monbg_22 ANIM_DEF_PARTNER
	monbgprio_29
	panse_1B SE_W107, +63, -64, -3, 0x0
	createvisualtask sub_80FF458, 0x5, 128, 24
	delay 0xF
	createsprite gUnknown_085924DC, 0x82, -12, 24
	delay 0xA
	setarg 0x7, 0xFFFF
	waitforvisualfinish
	playsewithpan SE_W036, -64
	createvisualtask sub_8115A04, 0x2, 2, 0, 2, 0, 11, 0x7FFF
	waitforvisualfinish
	clearmonbg_23 ANIM_DEF_PARTNER
	blendoff
	end

Move_CONSTRICT:
	loadspritegfx 0x27CA
	loopsewithpan SE_W010, +63, 0x6, 0x4
	createsprite gUnknown_08592494, 0x84, 0, 16, 0, 2
	delay 0x7
	createsprite gUnknown_08592494, 0x83, 0, 0, 0, 2
	createsprite gUnknown_08592494, 0x82, 0, 8, 1, 2
	delay 0x7
	createsprite gUnknown_08592494, 0x83, 0, -8, 1, 2
	delay 0x8
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 6, 1
	delay 0x14
	playsewithpan SE_W020, +63
	setarg 0x7, 0xFFFF
	waitforvisualfinish
	end

Move_CURSE:
	choosetwoturnanim AnimScript_82D3BFB, AnimScript_82D3C78

AnimScript_82D3BFB:
	loadspritegfx 0x27D7
	loadspritegfx 0x27D8
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8112758, 0x5
	waitforvisualfinish
	delay 0x14
	createsprite gUnknown_08596DD0, 0x2
	delay 0x3C
	call AnimScript_82D3C62
	delay 0x29
	call AnimScript_82D3C62
	delay 0x29
	call AnimScript_82D3C62
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	delay 0x1
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, +63
	createsprite gUnknown_08596DE8, 0x82
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 14, 1
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 16, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82D3C62:
	createvisualtask sub_80D52D0, 0x2, 0, 4, 0, 10, 0
	playsewithpan SE_W020, -64
	return

AnimScript_82D3C78:
	createvisualtask sub_80D5EB8, 0x5, 0, 10, 1536, 3, 0
	waitforvisualfinish
	delay 0xA
	call AnimScript_82D3C93
	waitforvisualfinish
	end

AnimScript_82D3C93:
	playsewithpan SE_W082, -64
	createvisualtask sub_8116B14, 0x5
	createvisualtask sub_8115A04, 0x5, 2, 4, 2, 0, 10, 31
	return

Move_SOFT_BOILED:
	loadspritegfx 0x27DA
	loadspritegfx 0x27DB
	loadspritegfx 0x272F
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W039, -64
	createvisualtask sub_80D51AC, 0x2, 0, 0, 2, 6, 1
	createsprite gUnknown_085937B0, 0x4, 0, 16, 0
	createsprite gUnknown_085937B0, 0x4, 0, 16, 1
	delay 0x78
	delay 0x7
	playsewithpan SE_W030, -64
	createsprite gUnknown_08597274, 0x2, 31, 3, 10, 0, RGB(12, 24, 30)
	createsprite gUnknown_0859381C, 0x3, 31, 16, 0, 1
	delay 0x8
	createsprite gUnknown_0859381C, 0x3, 31, 16, 0, 1
	delay 0x3C
	setarg 0x7, 0xFFFF
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	call AnimScript_82D7A28
	end

Move_HEAL_BELL:
	loadspritegfx 0x27DD
	loadspritegfx 0x27DE
	loadspritegfx 0x27DB
	createvisualtask sub_8116620, 0xA, 10, 0, 0, 10, 0x7FFF
	waitforvisualfinish
	createvisualtask sub_8105CB4, 0x5
	createsprite gUnknown_08593938, 0x2, 0, -24, 0, 1
	delay 0xC
	createsprite gUnknown_08593958, 0x28, 0, -24, 48, -18, 35, 0, 0
	createsprite gUnknown_08593958, 0x28, 0, -24, -48, 20, 30, 1, 1
	createsprite gUnknown_08593958, 0x28, 0, -24, -38, -29, 30, 2, 2
	createsprite gUnknown_08593958, 0x28, 0, -24, 36, 18, 30, 3, 3
	call AnimScript_82D3EF8
	delay 0x21
	createsprite gUnknown_08593958, 0x28, 0, -24, 19, 26, 35, 4, 4
	createsprite gUnknown_08593958, 0x28, 0, -24, -34, -12, 30, 5, 5
	createsprite gUnknown_08593958, 0x28, 0, -24, 41, -20, 34, 6, 2
	createsprite gUnknown_08593958, 0x28, 0, -24, -15, 26, 32, 7, 0
	call AnimScript_82D3EF8
	delay 0x21
	createsprite gUnknown_08593958, 0x28, 0, -24, -48, 18, 31, 0, 2
	createsprite gUnknown_08593958, 0x28, 0, -24, 48, -20, 30, 2, 5
	createsprite gUnknown_08593958, 0x28, 0, -24, 38, 29, 33, 4, 3
	createsprite gUnknown_08593958, 0x28, 0, -24, -36, -18, 30, 6, 1
	call AnimScript_82D3EF8
	waitforvisualfinish
	createvisualtask sub_8105D60, 0x5
	waitforvisualfinish
	unloadspritegfx 0x27DD
	unloadspritegfx 0x27DE
	unloadspritegfx 0x27DB
	loadspritegfx 0x2741
	playsewithpan SE_W234, -64
	createsprite gUnknown_08592B94, 0x10, -15, 0, 0, 0, 32, 60, 1
	delay 0x8
	createsprite gUnknown_08592B94, 0x10, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	unloadspritegfx 0x2741
	loadspritegfx 0x27DB
	playsewithpan SE_REAPOKE, -64
	createvisualtask sub_8116664, 0xA, 4, 3, 10, 0, 31500
	createvisualtask sub_8116620, 0xA, 10, 3, 10, 0, 0x7FFF
	createsprite gUnknown_08593868, 0x10, 0, 0, 0, 1
	end

AnimScript_82D3EF8:
	createvisualtask sub_8116664, 0xA, 4, 3, 8, 0, 31500
	createvisualtask sub_8116620, 0xA, 10, 3, 2, 10, 0x7FFF
	createsprite gUnknown_0859381C, 0x28, 0, -24, 0, 1
	playsewithpan SE_W215, -64
	return

Move_FAKE_OUT:
	playsewithpan SE_W260, 0
	createvisualtask sub_8105EB0, 0x5
	waitforvisualfinish
	playsewithpan SE_W166, +63
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 5, 1
	createvisualtask sub_8106020, 0x3
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 3, 16, 0, RGB_WHITE
	end

Move_SCARY_FACE:
	loadspritegfx 0x27EA
	createsprite gUnknown_08597274, 0x2, 27, 3, 0, 16, 0
	playsewithpan SE_W060, -64
	waitforvisualfinish
	delay 0xA
	playsewithpan SE_W043, -64
	createvisualtask sub_81064F8, 0x5
	delay 0xD
	createsprite gUnknown_08593A84, 0x0, -16, -8
	createsprite gUnknown_08593A84, 0x0, 16, -8
	waitforvisualfinish
	createvisualtask sub_810A094, 0x3, 20, 1, 0
	playsewithpan SE_W081B, +63
	createsprite gUnknown_08597274, 0x2, 27, 3, 16, 0, 0
	waitforvisualfinish
	end

Move_SWEET_KISS:
	loadspritegfx 0x27E8
	loadspritegfx 0x27EC
	createsprite gUnknown_08593AA8, 0x82, 16, -48
	playsewithpan SE_W215, +63
	delay 0x17
	playsewithpan SE_W215, +63
	delay 0x17
	playsewithpan SE_W215, +63
	waitforvisualfinish
	createsprite gUnknown_085939B8, 0x83, 160, -30
	playsewithpan SE_W213, +63
	createsprite gUnknown_085939B8, 0x83, -256, -42
	createsprite gUnknown_085939B8, 0x83, 128, -14
	createsprite gUnknown_085939B8, 0x83, 416, -38
	createsprite gUnknown_085939B8, 0x83, -128, -22
	createsprite gUnknown_085939B8, 0x83, -384, -31
	end

Move_LOVELY_KISS:
	loadspritegfx 0x27EB
	loadspritegfx 0x27ED
	createsprite gUnknown_08593AF0, 0x82, 0, -24
	playsewithpan SE_W060B, +63
	waitforvisualfinish
	playsewithpan SE_W213, +63
	createsprite gUnknown_08593AC0, 0x83, -256, -42
	createsprite gUnknown_08593AC0, 0x83, 128, -14
	createsprite gUnknown_08593AC0, 0x83, 416, -38
	createsprite gUnknown_08593AC0, 0x83, -128, -22
	end

Move_FURY_SWIPES:
	loadspritegfx 0x27EE
	createsprite gUnknown_0857FE28, 0x2, 5, 5
	delay 0x4
	playsewithpan SE_W010, +63
	createsprite gUnknown_08593B38, 0x82, 16, 0, 1
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 5, 1
	delay 0xA
	createsprite gUnknown_0857FE28, 0x82, 5, 5
	delay 0x4
	playsewithpan SE_W010, +63
	createsprite gUnknown_08593B38, 0x82, -16, 0, 0
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 7, 1
	end

Move_INGRAIN:
	loadspritegfx 0x27EF
	loadspritegfx 0x27A3
	createsprite gUnknown_0859254C, 0x2, 16, 26, -1, 2, 150
	playsewithpan SE_W010, -64
	delay 0xA
	createsprite gUnknown_0859254C, 0x2, -32, 20, 1, 1, 140
	playsewithpan SE_W010, -64
	delay 0xA
	createsprite gUnknown_0859254C, 0x2, 32, 22, 1, 0, 130
	playsewithpan SE_W010, -64
	delay 0xA
	createsprite gUnknown_0859254C, 0x2, -16, 25, -1, 3, 120
	playsewithpan SE_W010, -64
	delay 0x28
	createsprite gUnknown_0859258C, 0x3, 32, 26, -1, 3, 30
	delay 0x5
	playsewithpan SE_W145C, -64
	delay 0x5
	createsprite gUnknown_0859258C, 0x3, -48, 20, 1, 2, 30
	playsewithpan SE_W145C, -64
	delay 0x5
	playsewithpan SE_W145C, -64
	delay 0x5
	createsprite gUnknown_0859258C, 0x3, 48, 26, -2, 3, 18
	playsewithpan SE_W145C, -64
	delay 0xA
	waitforvisualfinish
	end

Move_PRESENT:
	loadspritegfx 0x27F0
	createvisualtask sub_815A904, 0x2
	createsprite gUnknown_08592610, 0x82, 0, -5, 10, 2, -1
	playsewithpan SE_W039, -64
	delay 0xE
	playsewithpan SE_W145B, -64
	delay 0xE
	playsewithpan SE_W145B, 0
	delay 0x14
	playsewithpan SE_W145B, +63
	waitforvisualfinish
	jumpargeq 0x7, 0x0, AnimScript_82D41D4
	jumpargeq 0x7, 0x1, AnimScript_82D423F
	end

AnimScript_82D41D4:
	loadspritegfx 0x27D6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x83, 0, 0, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x83, 24, -24, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x83, -16, 16, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x83, -24, -12, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x83, 16, 16, 1, 1
	end

AnimScript_82D423F:
	loadspritegfx 0x27D3
	loadspritegfx 0x272F
	playsewithpan SE_W234, +63
	createsprite gUnknown_08592658, 0x84, -16, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, 16, 32, -3, -1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, 32, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, -32, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, 0, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, -8, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, -8, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, 24, 32, -3, 1
	delay 0x3
	createsprite gUnknown_08592658, 0x84, -24, 32, -3, 1
	waitforvisualfinish
	waitsound
	call AnimScript_82D7A28
	end

Move_BATON_PASS:
	loadspritegfx 0x27F2
	playsewithpan SE_W226, -64
	createvisualtask sub_8115A04, 0x2, 31, 1, 2, 0, 11, 31455
	createsprite gUnknown_085CE370, 0x2
	end

Move_PERISH_SONG:
	loadspritegfx 0x27DE
	createsprite gUnknown_08593C0C, 0x4, 0, 0, 0
	createsprite gUnknown_08593C0C, 0x4, 1, 1, 16
	createsprite gUnknown_08593C0C, 0x4, 2, 1, 32
	createsprite gUnknown_08593C0C, 0x4, 3, 2, 48
	createsprite gUnknown_08593C0C, 0x4, 4, 2, 64
	createsprite gUnknown_08593C0C, 0x4, 5, 0, 80
	createsprite gUnknown_08593C0C, 0x4, 6, 0, 96
	createsprite gUnknown_08593C0C, 0x4, 7, 1, 112
	createsprite gUnknown_08593C0C, 0x4, 8, 2, 128
	createsprite gUnknown_08593C0C, 0x4, 9, 0, 144
	createsprite gUnknown_08593C0C, 0x4, 10, 2, 160
	createsprite gUnknown_08593C0C, 0x4, 11, 0, 176
	createsprite gUnknown_08593C0C, 0x4, 12, 1, 192
	createsprite gUnknown_08593C0C, 0x4, 13, 3, 208
	createsprite gUnknown_08593C0C, 0x4, 14, 3, 224
	createsprite gUnknown_08593C0C, 0x4, 15, 0, 240
	createsprite gUnknown_08593C24, 0x4, 15, 0, 0
	delay 0x14
	panse_1B SE_W195, -64, +63, +2, 0x0
	delay 0x50
	createsprite gUnknown_08597274, 0x2, 1, 3, 0, 16, 0
	createvisualtask sub_811489C, 0x5, 4, 0
	createvisualtask sub_811489C, 0x5, 5, 0
	createvisualtask sub_811489C, 0x5, 6, 0
	createvisualtask sub_811489C, 0x5, 7, 0
	delay 0x64
	createsprite gUnknown_08597274, 0x2, 1, 3, 16, 0, 0
	createvisualtask sub_811489C, 0x5, 4, 1
	createvisualtask sub_811489C, 0x5, 5, 1
	createvisualtask sub_811489C, 0x5, 6, 1
	createvisualtask sub_811489C, 0x5, 7, 1
	waitforvisualfinish
	end

Move_SLEEP_TALK:
	loadspritegfx 0x27F4
	createvisualtask sub_80D5EB8, 0x5, 0, 4, 4096, 2, 0
	delay 0x14
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -1
	playsewithpan SE_W173, -64
	delay 0x6
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -1
	delay 0x6
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -1
	delay 0x14
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -5
	playsewithpan SE_W173, -64
	delay 0x6
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -5
	delay 0x6
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -5
	delay 0x14
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -3
	playsewithpan SE_W173, -64
	delay 0x6
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -3
	delay 0x6
	createsprite gUnknown_085CE190, 0x82, 0, 20, 5, -3
	waitforvisualfinish
	end

Move_HYPER_FANG:
	loadspritegfx 0x27D0
	playsewithpan SE_W044, +63
	delay 0x1
	delay 0x2
	createvisualtask sub_8117E60, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D458E
	createvisualtask sub_815A8C8, 0x2
	jumpargeq 0x7, 0x0, AnimScript_82D4580
	goto AnimScript_82D4587

AnimScript_82D455C:
	waitbgfadeout
	createsprite gUnknown_085CE1DC, 0x82
	waitbgfadein
	createvisualtask sub_80D51AC, 0x3, 1, 0, 10, 10, 1
	playsewithpan SE_W043, +63
	delay 0x14
	restorebg
	waitbgfadein
	waitforvisualfinish
	end

AnimScript_82D4580:
	fadetobg BG_IMPACT_OPPONENT
	goto AnimScript_82D455C

AnimScript_82D4587:
	fadetobg BG_IMPACT_PLAYER
	goto AnimScript_82D455C

AnimScript_82D458E:
	fadetobg BG_IMPACT_CONTESTS
	goto AnimScript_82D455C

Move_TRI_ATTACK:
	loadspritegfx 0x27F6
	createsprite gUnknown_085CE2F8, 0x82, 16, 0
	playsewithpan SE_W161, -64
	delay 0x14
	playsewithpan SE_W161, -64
	delay 0x14
	createsoundtask sub_8158C58, 220, -64, 63, 5, 6, 0, 7
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 16, 0
	delay 0x10
	loadspritegfx 0x2731
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, -1, 0
	playsewithpan SE_W172B, +63
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 0, 1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, -1, -1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 2, 1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 1, -1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, -1, 1
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 1, -2
	delay 0x1
	createsprite gUnknown_08595410, 0x82, 0, 0, 30, 30, 3, 1
	delay 0x2
	createvisualtask sub_810A094, 0x2, 20, 3, 1, 1
	waitforvisualfinish
	loadspritegfx 0x2735
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	playsewithpan SE_W161B, +63
	createsprite gUnknown_085956C0, 0x82, 0, -48
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 0, -16
	delay 0x1
	createsprite gUnknown_085956C0, 0x82, 0, 16
	delay 0x14
	createvisualtask sub_810A094, 0x2, 20, 3, 1, 0
	delay 0x2
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	waitforvisualfinish
	loadspritegfx 0x279D
	call AnimScript_82D7720
	createsprite gUnknown_08597274, 0x2, 1, 2, 16, 0, 0
	waitforvisualfinish
	end

Move_WILL_O_WISP:
	loadspritegfx 0x27F8
	loadspritegfx 0x27F7
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	playsewithpan SE_W052, -64
	waitplaysewithpan SE_W052, -64, 0xA
	createvisualtask sub_8159278, 0x2, -64, -64, 1, 0
	createsprite gUnknown_0859563C, 0x2, 0, 0, 0
	delay 0x3
	createsprite gUnknown_0859563C, 0x3, 0, 0, 1
	delay 0x3
	createsprite gUnknown_0859563C, 0x4, 0, 0, 2
	delay 0x3
	createsprite gUnknown_0859563C, 0x4, 0, 0, 3
	delay 0x28
	createvisualtask sub_8159278, 0x2, -64, 63, 2, 0
	waitforvisualfinish
	monbgprio_29
	playsewithpan SE_W172B, +63
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 13, 1
	createsprite gUnknown_0859566C, 0x2, 0
	createsprite gUnknown_0859566C, 0x2, 42
	createsprite gUnknown_0859566C, 0x2, 84
	createsprite gUnknown_0859566C, 0x2, 126
	createsprite gUnknown_0859566C, 0x2, 168
	createsprite gUnknown_0859566C, 0x2, 210
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_ENCORE:
	loadspritegfx 0x27F3
	loadspritegfx 0x2807
	createvisualtask sub_815ABEC, 0x2
	createvisualtask sub_8116960, 0x2, 248, 3, 0, 10, 0
	waitforvisualfinish
	createsprite gUnknown_085CE22C, 0x82, 0, -8
	createsprite gUnknown_085CE244, 0x2, -2, 0, 0, 0, 9
	createsprite gUnknown_085CE244, 0x2, 2, 0, 1, 0, 9
	createsprite gUnknown_085CE25C, 0x3, -2, 0, 0, 0, 9
	createsprite gUnknown_085CE25C, 0x3, 2, 0, 1, 0, 9
	delay 0x10
	createvisualtask sub_8159244, 0x5, 223, 63
	createvisualtask sub_80D5EB8, 0x5, 1, 8, 1536, 5, 1
	waitforvisualfinish
	createvisualtask sub_8116960, 0x2, 248, 3, 10, 0, 1
	waitforvisualfinish
	createvisualtask sub_815AC8C, 0x2
	end

Move_TRICK:
	loadspritegfx 0x27F0
	loadspritegfx 0x27DF
	createsprite gUnknown_085926E8, 0x2, -40, 80
	createsprite gUnknown_085926E8, 0x2, -40, 208
	delay 0x10
	playsewithpan SE_W166, 0
	createvisualtask sub_8106020, 0x3
	createvisualtask sub_81060B0, 0x3
	delay 0x1E
	playsewithpan SE_W104, 0
	delay 0x18
	playsewithpan SE_W104, 0
	delay 0x10
	playsewithpan SE_W104, 0
	delay 0x10
	playsewithpan SE_W104, 0
	delay 0x10
	playsewithpan SE_W104, 0
	delay 0x10
	playsewithpan SE_W104, 0
	delay 0x10
	playsewithpan SE_W213, 0
	createvisualtask sub_80D51AC, 0x3, 0, 5, 0, 7, 2
	createvisualtask sub_80D51AC, 0x3, 1, 5, 0, 7, 2
	waitforvisualfinish
	end

Move_WISH:
	loadspritegfx 0x27F9
	loadspritegfx 0x2741
	createsprite gUnknown_08597274, 0x2, 1, 3, 0, 10, 0
	waitforvisualfinish
	panse_27 SE_W115, +63, -64, -3, 0x0
	createsprite gUnknown_085CE388, 0x28
	waitforvisualfinish
	delay 0x3C
	loopsewithpan SE_W215, -64, 0x10, 0x3
	call AnimScript_82D79B4
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 3, 10, 0, 0
	waitforvisualfinish
	end

Move_STOCKPILE:
	loadspritegfx 0x27FB
	playsewithpan SE_W025, -64
	createvisualtask sub_8115A04, 0x2, 2, 8, 1, 0, 12, 0x7FFF
	createvisualtask sub_815B65C, 0x5
	call AnimScript_82D4972
	call AnimScript_82D4972
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 2, 0, 12, 0, RGB_WHITE
	end

AnimScript_82D4972:
	createsprite gUnknown_08592244, 0x2, 55, 55, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, -55, -55, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, 0, 55, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, 0, -55, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, 55, -34, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, 55, 34, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, -55, -34, 13
	delay 0x1
	createsprite gUnknown_08592244, 0x2, -55, 34, 13
	delay 0x1
	return

Move_SPIT_UP:
	loadspritegfx 0x27FD
	loadspritegfx 0x2797
	playsewithpan SE_W036, -64
	createvisualtask sub_815B6B4, 0x5
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 8, 2
	delay 0x2D
	playsewithpan SE_W255, -64
	delay 0x3
	createsprite gUnknown_08593A50, 0x2, 0, 12
	createsprite gUnknown_08593A50, 0x2, 32, 12
	createsprite gUnknown_08593A50, 0x2, 64, 12
	createsprite gUnknown_08593A50, 0x2, 96, 12
	createsprite gUnknown_08593A50, 0x2, 128, 12
	createsprite gUnknown_08593A50, 0x2, 160, 12
	createsprite gUnknown_08593A50, 0x2, 192, 12
	createsprite gUnknown_08593A50, 0x2, 224, 12
	delay 0x5
	jumpifmoveturn 0x2, AnimScript_82D4AB8
	jumpifmoveturn 0x3, AnimScript_82D4AE1

AnimScript_82D4A7B:
	delay 0x5
	createvisualtask sub_80D6388, 0x2, 0, 1, 8, 1, 0
	playsewithpan SE_W003, +63
	createsprite gUnknown_085973E8, 0x83, -12, 10, 1, 1
	delay 0x5
	playsewithpan SE_W003, +63
	createsprite gUnknown_085973E8, 0x83, 12, -10, 1, 1
	waitforvisualfinish
	end

AnimScript_82D4AB8:
	createsprite gUnknown_08593A50, 0x2, 16
	createsprite gUnknown_08593A50, 0x2, 80
	createsprite gUnknown_08593A50, 0x2, 144
	createsprite gUnknown_08593A50, 0x2, 208
	goto AnimScript_82D4A7B

AnimScript_82D4AE1:
	createsprite gUnknown_08593A50, 0x2, 16
	createsprite gUnknown_08593A50, 0x2, 48
	createsprite gUnknown_08593A50, 0x2, 80
	createsprite gUnknown_08593A50, 0x2, 112
	createsprite gUnknown_08593A50, 0x2, 144
	createsprite gUnknown_08593A50, 0x2, 176
	createsprite gUnknown_08593A50, 0x2, 208
	createsprite gUnknown_08593A50, 0x2, 240
	goto AnimScript_82D4A7B

Move_SWALLOW:
	loadspritegfx 0x27FC
	loadspritegfx 0x272F
	playsewithpan SE_W036, -64
	createvisualtask sub_815B778, 0x5
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 8, 2
	delay 0x26
	playsewithpan SE_W255, -64
	createvisualtask sub_80D52D0, 0x2, 0, 2, 0, 12, 1
	call AnimScript_82D4B7F
	jumpifmoveturn 0x2, AnimScript_82D4BC1
	jumpifmoveturn 0x3, AnimScript_82D4BCB

AnimScript_82D4B78:
	waitforvisualfinish
	call AnimScript_82D79DF
	end

AnimScript_82D4B7F:
	createsprite gUnknown_085CE418, 0x2, 0, -8
	delay 0x1
	createsprite gUnknown_085CE418, 0x2, -24, -8
	delay 0x1
	createsprite gUnknown_085CE418, 0x2, 16, -8
	delay 0x1
	createsprite gUnknown_085CE418, 0x2, -16, -8
	delay 0x1
	createsprite gUnknown_085CE418, 0x2, 24, -8
	delay 0x1
	return

AnimScript_82D4BC1:
	call AnimScript_82D4B7F
	goto AnimScript_82D4B78

AnimScript_82D4BCB:
	call AnimScript_82D4B7F
	call AnimScript_82D4B7F
	goto AnimScript_82D4B78

Move_TRANSFORM:
	monbg ANIM_ATTACKER
	playsewithpan SE_W100, -64
	waitplaysewithpan SE_W107, -64, 0x30
	createvisualtask sub_815B7D0, 0x2, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MORNING_SUN:
	loadspritegfx 0x2801
	loadspritegfx 0x272F
	createvisualtask sub_815BB84, 0x5
	delay 0x8
	createvisualtask sub_8116620, 0xA, 1921, 8, 0, 12, 0x7FFF
	delay 0xE
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	call AnimScript_82D4C78
	createvisualtask sub_8116620, 0xA, 1921, 3, 12, 0, 0x7FFF
	waitforvisualfinish
	waitsound
	call AnimScript_82D79DF
	end

AnimScript_82D4C78:
	createsprite gUnknown_085CE48C, 0x2, 30, 640
	delay 0x5
	return

Move_SWEET_SCENT:
	loadspritegfx 0x27FE
	playsewithpan SE_W230, -64
	createsprite gUnknown_085CE544, 0x2, 100, 0, 100
	delay 0x19
	setpan 0
	call AnimScript_82D4CCA
	createsprite gUnknown_085CE544, 0x2, 55, 0
	setpan +63
	createvisualtask sub_8115A04, 0x2, 20, 1, 5, 5, 13, 22207
	call AnimScript_82D4CCA
	waitforvisualfinish
	end

AnimScript_82D4CCA:
	createsprite gUnknown_085CE544, 0x2, 70, 1, 64
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 60, 0, 64
	delay 0x5
	createsprite gUnknown_085CE544, 0x2, 80, 1, 64
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 58, 0, 120
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 100, 0, 120
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 90, 0, 64
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 48, 0, 64
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 95, 1, 80
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 100, 0, 120
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 75, 1, 64
	delay 0x2
	createsprite gUnknown_085CE544, 0x2, 85, 0, 120
	delay 0x2
	return

Move_HYPER_BEAM:
	loadspritegfx 0x27A3
	createsprite gUnknown_08597274, 0x2, 1, 4, 0, 16, 0
	waitforvisualfinish
	delay 0xA
	playsewithpan SE_W063, -64
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 4, 1
	waitforvisualfinish
	delay 0x1E
	createsoundtask sub_8158C58, 247, -64, 63, 1, 15, 0, 5
	createvisualtask sub_80D51AC, 0x2, 0, 0, 4, 50, 1
	createvisualtask sub_8115D94, 0x2, 10147, 1, 12, 31, 16, 0, 0
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 50, 1
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 11, 26425
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	call AnimScript_82D4EA1
	createvisualtask sub_8116620, 0xA, 4, 2, 11, 0, 26425
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 4, 16, 0, 0
	end

AnimScript_82D4EA1:
	createsprite gUnknown_08592288, 0x82
	createsprite gUnknown_08592288, 0x82
	delay 0x1
	return

Move_FLATTER:
	loadspritegfx 0x27F3
	loadspritegfx 0x2800
	createvisualtask sub_8159244, 0x5, 223, 63
	createvisualtask sub_815ABEC, 0x2
	createvisualtask sub_8116960, 0x2, 248, 3, 0, 10, 0
	waitforvisualfinish
	createsprite gUnknown_085CE5C0, 0x82, 0, -8, 80
	delay 0x0
	createsprite gUnknown_0857FE40, 0x2, 5, 2, 1
	delay 0xA
	createsprite gUnknown_0857FE40, 0x2, 5, 2, 1
	delay 0x0
	createvisualtask sub_8159210, 0x5, 229, -64
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	call AnimScript_82D4F9B
	delay 0x5
	createvisualtask sub_8159210, 0x5, 229, 63
	waitforvisualfinish
	createvisualtask sub_8116960, 0x2, 248, 3, 10, 0, 1
	waitforvisualfinish
	createvisualtask sub_815AC8C, 0x2
	end

AnimScript_82D4F9B:
	createsprite gUnknown_085CE5A8, 0x28, 0
	createsprite gUnknown_085CE5A8, 0x28, 1
	return

Move_ROLE_PLAY:
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 16, 0x7FFF
	createsprite gUnknown_08597274, 0x2, 1, 2, 0, 10, 0
	waitforvisualfinish
	playsewithpan SE_W161, -64
	waitplaysewithpan SE_W197, -64, 0x1E
	createvisualtask sub_815CED8, 0x2
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	createvisualtask sub_8116620, 0xA, 4, 2, 16, 0, 0x7FFF
	delay 0x8
	createsprite gUnknown_08597274, 0x2, 1, 2, 10, 0, 0
	end

Move_REFRESH:
	loadspritegfx 0x27DB
	loadspritegfx 0x2741
	playsewithpan SE_W287, -64
	createvisualtask sub_815DFCC, 0x2, 0
	waitforvisualfinish
	playsewithpan SE_W234, -64
	call AnimScript_82D79B4
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createsprite gUnknown_08597274, 0x2, 31, 3, 10, 0, RGB(12, 24, 30)
	createsprite gUnknown_0859381C, 0x3, 0, 0, 0, 0
	end

Move_BLAZE_KICK:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	loadspritegfx 0x272D
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W172, +63
	createsprite gUnknown_08595F14, 0x83, 0, 0, 1, 30
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 7, 0x7FFF
	delay 0x1E
	playsewithpan SE_W007, +63
	createsprite gUnknown_08597358, 0x82, 0, 0, 1, 0
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 14, 1
	createvisualtask sub_8116620, 0xA, 4, 2, 0, 0, 0x7FFF
	createsprite gUnknown_0859728C, 0x2, 31, 3, 1, 0, 8, 0, 0
	call AnimScript_82D2D18
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HYPER_VOICE:
	loadspritegfx 0x27DB
	createvisualtask sub_81590B8, 0x5, 0
	call AnimScript_82D50FA
	waitforvisualfinish
	delay 0x8
	createvisualtask sub_81590B8, 0x5, 1
	call AnimScript_82D50FA
	waitforvisualfinish
	end

AnimScript_82D50FA:
	createsprite gUnknown_08597274, 0x2, 31, 3, 8, 0, RGB_YELLOW
	createvisualtask sub_80D6064, 0x5, -5, -5, 5, 0, 0
	createsprite gUnknown_08593880, 0x0, 45, 0, 0, 0, 0, 0, 1
	createvisualtask sub_80D52D0, 0x2, 1, 1, 0, 6, 1
	createvisualtask sub_80D52D0, 0x2, 3, 1, 0, 6, 1
	createvisualtask sub_81162A4, 0x2, 1, 0, 6, 1
	createvisualtask sub_8159078, 0x5
	return

Move_SAND_TOMB:
	loadspritegfx 0x275A
	createsprite gUnknown_08597274, 0x0, 4, 2, 0, 7, RGB(19, 17, 0)
	createvisualtask sub_80D51AC, 0x5, 1, 0, 2, 43, 1
	playsewithpan SE_W328, +63
	call AnimScript_82D51B7
	call AnimScript_82D51B7
	call AnimScript_82D51B7
	delay 0x16
	createsprite gUnknown_08597274, 0x0, 4, 2, 7, 0, RGB(19, 17, 0)
	waitforvisualfinish
	end

AnimScript_82D51B7:
	createsprite gUnknown_08596B34, 0x82, 0, 32, 528, 30, 10, 50, 1
	delay 0x2
	createsprite gUnknown_08596B34, 0x82, 0, 36, 480, 20, 13, -46, 1
	delay 0x2
	createsprite gUnknown_08596B34, 0x82, 0, 37, 576, 20, 5, 42, 1
	delay 0x2
	createsprite gUnknown_08596B34, 0x82, 0, 35, 400, 25, 8, -42, 1
	delay 0x2
	createsprite gUnknown_08596B34, 0x82, 0, 32, 512, 25, 13, 46, 1
	delay 0x2
	createsprite gUnknown_08596B34, 0x82, 0, 37, 464, 30, 12, -50, 1
	delay 0x2
	return

Move_SHEER_COLD:
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_W196, 0
	waitbgfadein
	loadspritegfx 0x271A
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80A9EF4, 0x2
	waitplaysewithpan SE_W258, +63, 0x11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_ARM_THRUST:
	loadspritegfx 0x279F
	loadspritegfx 0x2797
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D6134, 0x5, 8, 5, 0, 0
	delay 0x6
	createsprite gUnknown_0857FE28, 0x2, 4, 3
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08596034, 0x82, 10, -8, 14, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 0x5, 8, 5, 0, 1
	playsewithpan SE_W003, +63
	choosetwoturnanim AnimScript_82D52D4, AnimScript_82D52E8

AnimScript_82D52C0:
	createvisualtask sub_80D51AC, 0x5, 1, 4, 0, 6, 1
	waitforvisualfinish
	blendoff
	end

AnimScript_82D52D4:
	createsprite gUnknown_08597358, 0x82, 8, 0, 1, 2
	goto AnimScript_82D52C0

AnimScript_82D52E8:
	createsprite gUnknown_08597358, 0x82, -8, 0, 1, 2
	goto AnimScript_82D52C0

Move_MUDDY_WATER:
	panse_1B SE_W250, -64, +63, +2, 0x0
	createvisualtask sub_8107954, 0x2, 1
	waitforvisualfinish
	end

Move_BULLET_SEED:
	loadspritegfx 0x2716
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 30, 1
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	delay 0x5
	createsprite gUnknown_0859351C, 0x82, 20, 0
	waitforvisualfinish
	end

Move_DRAGON_CLAW:
	loadspritegfx 0x272D
	loadspritegfx 0x2737
	playsewithpan SE_W221B, -64
	createvisualtask sub_8116620, 0xA, 2, 4, 0, 8, 639
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 15, 1
	call AnimScript_82D5581
	call AnimScript_82D5581
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	createsprite gUnknown_08596B88, 0x2, 0, 28, 528, 30, 13, 50, 0
	delay 0x2
	createvisualtask sub_8159210, 0x5, 136, 63
	createsprite gUnknown_08597138, 0x82, -10, -10, 0
	createsprite gUnknown_08597138, 0x82, -10, 10, 0
	createsprite gUnknown_085972D8, 0x2, -4, 1, 10, 3, 1
	createsprite gUnknown_08596B88, 0x2, 0, 32, 480, 20, 16, -46, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 33, 576, 20, 8, 42, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 31, 400, 25, 11, -42, 0
	delay 0x2
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	createsprite gUnknown_08596B88, 0x2, 0, 28, 512, 25, 16, 46, 0
	delay 0x2
	createvisualtask sub_8159210, 0x5, 136, 63
	createsprite gUnknown_08597138, 0x82, 10, -10, 1
	createsprite gUnknown_08597138, 0x82, 10, 10, 1
	createsprite gUnknown_085972D8, 0x2, -4, 1, 10, 3, 1
	createsprite gUnknown_08596B88, 0x2, 0, 33, 464, 30, 15, -50, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 28, 528, 30, 13, 50, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 32, 480, 20, 16, -46, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 33, 576, 20, 8, 42, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 31, 400, 25, 11, -42, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 28, 512, 25, 16, 46, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 33, 464, 30, 15, -50, 0
	createvisualtask sub_8116620, 0xA, 2, 4, 8, 0, 639
	waitforvisualfinish
	end

AnimScript_82D5581:
	createsprite gUnknown_08596B88, 0x2, 0, 28, 528, 30, 13, 50, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 32, 480, 20, 16, -46, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 33, 576, 20, 8, 42, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 31, 400, 25, 11, -42, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 28, 512, 25, 16, 46, 0
	delay 0x2
	createsprite gUnknown_08596B88, 0x2, 0, 33, 464, 30, 15, -50, 0
	delay 0x2
	return

AnimScript_82D560C:
	end

Move_MUD_SHOT:
	loadspritegfx 0x2813
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createvisualtask sub_80D51AC, 0x5, 0, 0, 2, 46, 1
	delay 0x6
	createvisualtask sub_81076C8, 0x5, 100
	panse_1B SE_W250, -64, +63, +1, 0x0
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 43, 1
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	call AnimScript_82D5687
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D5687:
	createsprite gUnknown_085950FC, 0x3, 10, 10, 0, 16
	delay 0x2
	createsprite gUnknown_085950FC, 0x3, 10, 10, 0, 16
	delay 0x2
	return

Move_METEOR_MASH:
	loadspritegfx 0x27F9
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	panse_1B SE_W112, -64, +63, +3, 0x0
	fadetobg BG_COSMIC
	waitbgfadein
	waitforvisualfinish
	createsprite gUnknown_085CE8DC, 0x83, -48, -64, 72, 32, 30
	delay 0xA
	createsprite gUnknown_085CE8DC, 0x83, -112, -64, 8, 32, 30
	delay 0x28
	createsprite gUnknown_08595F14, 0x83, 0, 0, 0, 30
	createsprite gUnknown_085CE8DC, 0x83, -80, -64, 40, 32, 30
	delay 0x14
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	createvisualtask sub_80D52D0, 0x2, 1, 5, 0, 20, 1
	waitforvisualfinish
	delay 0xA
	restorebg
	waitbgfadein
	waitforvisualfinish
	end

Move_REVENGE:
	loadspritegfx 0x2805
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W036, -64
	createsprite gUnknown_08596088, 0x2, 10, -10
	waitforvisualfinish
	createvisualtask sub_8115A04, 0x2, 2, 0, 4, 2, 8, 31
	waitforvisualfinish
	unloadspritegfx 0x2805
	loadspritegfx 0x2806
	createsprite gUnknown_0857FE28, 0x2, 6, 4
	delay 0x4
	playsewithpan SE_W207, +63
	createsprite gUnknown_085960D0, 0x82, 10, -10
	waitforvisualfinish
	unloadspritegfx 0x2806
	loadspritegfx 0x2797
	createvisualtask sub_80D52D0, 0x2, 1, 3, 0, 10, 1
	createsprite gUnknown_08597400, 0x83, -10, -8, 1, 1, 8
	playsewithpan SE_W233B, +63
	delay 0x8
	createsprite gUnknown_08597400, 0x83, 10, 8, 1, 1, 8
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_POISON_FANG:
	loadspritegfx 0x27D0
	loadspritegfx 0x27A6
	playsewithpan SE_W044, +63
	createsprite gUnknown_085CE1DC, 0x82
	delay 0xA
	createvisualtask sub_80D51AC, 0x3, 1, 3, 0, 10, 1
	waitforvisualfinish
	createvisualtask sub_8115A04, 0x2, 4, 0, 4, 0, 12, 26650
	call AnimScript_82D7A71
	waitforvisualfinish
	end

Move_SUBSTITUTE:
	playsewithpan SE_W213, -64
	createvisualtask sub_815F20C, 0x2
	end

Move_FRENZY_PLANT:
	loadspritegfx 0x27EF
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x0, 1, 2, 0, 5, 0
	waitforvisualfinish
	createsprite gUnknown_08592564, 0x2, 10, 8, 2, 0, 0, 100
	playsewithpan SE_W010, -64
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 20, -8, -2, 0, 1, 95
	playsewithpan SE_W010, -43
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 30, 8, -4, 0, 0, 90
	playsewithpan SE_W010, -22
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 40, -8, 4, 0, 1, 85
	playsewithpan SE_W010, 0
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 50, 8, 0, 0, 0, 85
	playsewithpan SE_W010, +21
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 60, -8, -2, 0, 1, 85
	playsewithpan SE_W010, +42
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 75, 8, 0, 0, 0, 85
	playsewithpan SE_W010, +63
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 85, 16, 6, 0, 3, 80
	playsewithpan SE_W010, +63
	delay 0x5
	createsprite gUnknown_08592564, 0x2, 85, -16, -6, 0, 2, 75
	playsewithpan SE_W010, +63
	delay 0x5
	createsprite gUnknown_08597358, 0x2, -10, -10, 1, 3
	playsewithpan SE_W003, +63
	createvisualtask sub_80D51AC, 0x3, 1, 8, 0, 20, 1
	delay 0x3
	createsprite gUnknown_08597358, 0x2, 10, 8, 1, 3
	playsewithpan SE_W003, +63
	delay 0x3
	createsprite gUnknown_08597358, 0x2, 10, -3, 1, 2
	playsewithpan SE_W003, +63
	delay 0x3
	createsprite gUnknown_08597358, 0x2, -3, 1, 1, 2
	playsewithpan SE_W003, +63
	delay 0x2
	createsprite gUnknown_08597358, 0x2, -10, 1, 1, 1
	playsewithpan SE_W003, +63
	delay 0x2
	createsprite gUnknown_08597358, 0x2, 0, 10, 1, 1
	playsewithpan SE_W003, +63
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x0, 1, 2, 5, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_METAL_SOUND:
	loadspritegfx 0x2814
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	createvisualtask sub_80D52D0, 0x2, 0, 2, 0, 8, 1
	call AnimScript_82D59EA
	call AnimScript_82D59EA
	call AnimScript_82D59EA
	call AnimScript_82D59EA
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 0x0
	waitforvisualfinish
	end

AnimScript_82D59EA:
	panse_1B SE_W103, -64, +63, +2, 0x0
	createsprite gUnknown_08593458, 0x82, 16, 0, 0, 0, 30, 0
	delay 0x2
	return

Move_FOCUS_PUNCH:
	goto AnimScript_82D5A0E

AnimScript_82D5A0C:
	waitforvisualfinish
	end

AnimScript_82D5A0E:
	loadspritegfx 0x2797
	loadspritegfx 0x279F
	delay 0x1
	createvisualtask sub_8117E60, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D5AC7
	createvisualtask sub_815A8C8, 0x2
	jumpargeq 0x7, 0x0, AnimScript_82D5AB9
	jumpargeq 0x7, 0x1, AnimScript_82D5AC0

AnimScript_82D5A3C:
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W207, +63
	createsprite gUnknown_08596104, 0x82
	delay 0xA
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 0
	createvisualtask sub_80D51AC, 0x5, 1, 8, 0, 24, 1
	delay 0x8
	createsprite gUnknown_08597358, 0x2, 10, 2, 1, 0
	playsewithpan SE_W233B, +63
	delay 0x8
	createsprite gUnknown_08597358, 0x2, 10, -6, 1, 0
	playsewithpan SE_W233B, +63
	delay 0x8
	createsprite gUnknown_08597358, 0x2, 0, 8, 1, 0
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto AnimScript_82D5A0C

AnimScript_82D5AB9:
	fadetobg BG_IMPACT_OPPONENT
	goto AnimScript_82D5A3C

AnimScript_82D5AC0:
	fadetobg BG_IMPACT_PLAYER
	goto AnimScript_82D5A3C

AnimScript_82D5AC7:
	fadetobg BG_IMPACT_CONTESTS
	goto AnimScript_82D5A3C

Move_RETURN:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createvisualtask sub_815F8A0, 0x2
	delay 0x2
	jumpargeq 0x7, 0x0, AnimScript_82D5B04
	jumpargeq 0x7, 0x1, AnimScript_82D5B56
	jumpargeq 0x7, 0x2, AnimScript_82D5BB6
	jumpargeq 0x7, 0x3, AnimScript_82D5CD1

AnimScript_82D5AFF:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D5B04:
	createsprite gUnknown_0857FE40, 0x2, 16, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 16, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	delay 0x5
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 2
	createvisualtask sub_8159210, 0x5, 139, 63
	goto AnimScript_82D5AFF

AnimScript_82D5B56:
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	delay 0xB
	createsprite gUnknown_0857FE28, 0x2, 5, 4
	delay 0x6
	createsprite gUnknown_08597358, 0x3, 0, 0, 1, 2
	createvisualtask sub_8159210, 0x5, 141, 63
	goto AnimScript_82D5AFF

AnimScript_82D5BB6:
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 6, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	delay 0x8
	createsprite gUnknown_08597358, 0x2, 10, 10, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	delay 0x8
	createsprite gUnknown_08597358, 0x2, 3, -5, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	delay 0x8
	createsprite gUnknown_08597358, 0x2, -5, 3, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	goto AnimScript_82D5AFF

AnimScript_82D5CD1:
	createsprite gUnknown_08597274, 0x2, 1, 0, 0, 6, 0
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 16, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	delay 0x8
	createsprite gUnknown_08597358, 0x2, 3, -5, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 12, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	delay 0x5
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	waitforvisualfinish
	delay 0x4
	createsprite gUnknown_0857FE40, 0x2, 8, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	delay 0x5
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	waitforvisualfinish
	delay 0x2
	createvisualtask sub_81169C0, 0x2, 0, 4, 5, 1
	createsprite gUnknown_0857FE40, 0x2, 4, 1, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	createvisualtask sub_81169C0, 0x2, 0, 4, 5, 1
	waitforvisualfinish
	createsprite gUnknown_0857FE40, 0x2, 4, 2, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	delay 0x5
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	createvisualtask sub_81169C0, 0x2, 0, 4, 5, 1
	waitforvisualfinish
	call AnimScript_82D5F09
	call AnimScript_82D5F09
	call AnimScript_82D5F09
	call AnimScript_82D5F09
	createsprite gUnknown_08597358, 0x2, -10, -8, 1, 0
	createvisualtask sub_8159210, 0x5, 141, 63
	createvisualtask sub_80D51AC, 0x5, 1, 8, 0, 24, 1
	delay 0x6
	createsprite gUnknown_08597358, 0x2, 10, 10, 1, 0
	createvisualtask sub_8159210, 0x5, 141, 63
	delay 0x6
	createsprite gUnknown_08597358, 0x2, 3, -5, 1, 0
	createvisualtask sub_8159210, 0x5, 141, 63
	delay 0x6
	createsprite gUnknown_08597358, 0x2, -5, 3, 1, 0
	createvisualtask sub_8159210, 0x5, 141, 63
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 0, 6, 0, 0
	goto AnimScript_82D5AFF

AnimScript_82D5F09:
	createsprite gUnknown_0857FE40, 0x2, 4, 3, 0
	createvisualtask sub_8159244, 0x5, 167, -64
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_8159210, 0x5, 123, 63
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	createvisualtask sub_81169C0, 0x2, 0, 4, 5, 1
	waitforvisualfinish
	return

Move_COSMIC_POWER:
	loadspritegfx 0x2741
	createvisualtask sub_8159244, 0x5, 243, 0
	playsewithpan SE_W322, 0
	createvisualtask sub_8117610, 0x2, 0, 0, 15, 0
	waitforvisualfinish
	fadetobg BG_COSMIC
	waitbgfadeout
	createvisualtask sub_8117660, 0x2, 0, 128, 0, -1
	waitbgfadein
	delay 0x46
	createvisualtask sub_8159210, 0x5, 228, -64
	createsprite gUnknown_08592B7C, 0x2, -15, 0, 0, 0, 32, 60
	delay 0x8
	createsprite gUnknown_08592B7C, 0x2, 12, -5, 0, 0, 32, 60
	delay 0x28
	createvisualtask sub_8117610, 0x2, 0, 15, 0, 0
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	waitforvisualfinish
	end

Move_BLAST_BURN:
	loadspritegfx 0x2733
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W221, -64
	createsprite gUnknown_08595428, 0x2, -32, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, -20, -10, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x42, 0, -16, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x42, 20, -10, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x42, 32, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x42, 20, 10, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, 0, 16, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, -20, 10, 24, 0, 0, 0
	delay 0x19
	playsewithpan SE_W172B, -64
	createsprite gUnknown_08595428, 0x2, -64, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x6, -40, -20, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x46, 0, -32, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x46, 40, -20, 24, 0, 0, 0
	createvisualtask sub_80D51AC, 0x5, 1, 6, 0, 8, 1
	createsprite gUnknown_08595428, 0x42, 64, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x42, 40, 20, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, 0, 32, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, -40, 20, 24, 0, 0, 0
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x19
	playsewithpan SE_W172B, -64
	createsprite gUnknown_08595428, 0x2, -96, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x6, -60, -30, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x46, 0, -48, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x46, 60, -30, 24, 0, 0, 0
	createsprite gUnknown_08597358, 0x82, -4, 3, 1, 0
	createvisualtask sub_80D51AC, 0x5, 1, 12, 0, 20, 1
	createvisualtask sub_81162A4, 0x2, 2, 0, 10, 1
	createsprite gUnknown_08595428, 0x42, 96, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x42, 60, 30, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, 0, 48, 24, 0, 0, 0
	createsprite gUnknown_08595428, 0x2, -60, 30, 24, 0, 0, 0
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROCK_TOMB:
	loadspritegfx 0x280A
	loadspritegfx 0x274A
	createvisualtask sub_81162A4, 0x2, 2, 0, 10, 1
	waitforvisualfinish
	createsprite gUnknown_08596C58, 0x82, 20, 12, 64, 114, 0
	delay 0x8
	createvisualtask sub_81162A4, 0x2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 0x8
	createsprite gUnknown_08596C58, 0x82, -20, 12, 64, 98, 0
	delay 0x8
	createvisualtask sub_81162A4, 0x2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 0x8
	createsprite gUnknown_08596C58, 0xC2, 3, 6, 64, 82, 0
	delay 0x8
	createvisualtask sub_81162A4, 0x2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 0x8
	createsprite gUnknown_08596C58, 0x82, -3, 13, 64, 66, 0
	delay 0x8
	createvisualtask sub_81162A4, 0x2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 0x18
	playsewithpan SE_W063, +63
	createsprite gUnknown_085967AC, 0x85, 1, 50
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 20, 1
	createvisualtask sub_81162A4, 0x2, 2, 0, 10, 1
	waitforvisualfinish
	end

Move_SILVER_WIND:
	loadspritegfx 0x281F
	panse_1B SE_W016, -64, +63, +2, 0x0
	playsewithpan SE_W234, 0
	delay 0x0
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	delay 0x0
	createvisualtask sub_8116664, 0xA, 1, 0, 0, 4, 0
	createvisualtask sub_8117780, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D650C
	fadetobg BG_BUG_OPPONENT
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, 1536, 0, 0, -1

AnimScript_82D6352:
	delay 0x0
	createvisualtask sub_8116620, 0xA, 1, 0, 4, 4, 0
	waitbgfadein
	createsprite gUnknown_08592830, 0xC2, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592830, 0xC2, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592830, 0x78, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592830, 0x78, -40, 14, 128, 4, 1, 2, 1
	delay 0x0
	createsprite gUnknown_08592848, 0xC2, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592848, 0xC2, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592848, 0x78, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592848, 0x78, -40, 14, 128, 4, 1, 2, 1
	delay 0x0
	createsprite gUnknown_08592860, 0xC2, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592860, 0xC2, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592860, 0x78, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592860, 0x78, -40, 14, 128, 4, 1, 2, 1
	delay 0x6
	createsprite gUnknown_08592830, 0xC2, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592830, 0xC2, -16, 12, 192, 5, 2, 3, 1
	delay 0x0
	createsprite gUnknown_08592848, 0xC2, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592848, 0xC2, -16, 12, 192, 5, 2, 3, 1
	delay 0x0
	createsprite gUnknown_08592860, 0xC2, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592860, 0xC2, -16, 12, 192, 5, 2, 3, 1
	waitforvisualfinish
	playsewithpan SE_W016B, +63
	clearmonbg ANIM_DEF_PARTNER
	delay 0x0
	restorebg
	waitbgfadeout
	createvisualtask sub_8116664, 0xA, 1, 0, 4, 0, 0
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

AnimScript_82D650C:
	fadetobg BG_BUG_PLAYER
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -1536, 0, 0, -1
	goto AnimScript_82D6352

Move_SNATCH:
	playsewithpan SE_W036, -64
	createvisualtask sub_80D5C50, 0x5, 0, -12, 4, 10, 10, 12, 6
	end

Move_DIVE:
	loadspritegfx 0x2820
	loadspritegfx 0x2821
	choosetwoturnanim AnimScript_82D654C, AnimScript_82D65A1

AnimScript_82D654C:
	loadspritegfx 0x27AC
	playsewithpan SE_W029, -64
	createsprite gUnknown_08596490, 0x2, 0, 0, 13, 336
	waitforvisualfinish
	playsewithpan SE_W291, -64
	createsprite gUnknown_085964CC, 0x3, 0
	call AnimScript_82D658A
	call AnimScript_82D658A
	call AnimScript_82D658A
	call AnimScript_82D658A
	call AnimScript_82D658A
	end

AnimScript_82D658A:
	createsprite gUnknown_085964E4, 0x5, 0, 0
	createsprite gUnknown_085964E4, 0x5, 1, 0
	return

AnimScript_82D65A1:
	loadspritegfx 0x27A4
	loadspritegfx 0x27AB
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W153, +63
	createsprite gUnknown_085964CC, 0x83, 1
	call AnimScript_82D65E0
	call AnimScript_82D65E0
	call AnimScript_82D65E0
	call AnimScript_82D65E0
	call AnimScript_82D65E0
	delay 0xC
	call AnimScript_82CB102
	waitforvisualfinish
	visible ANIM_ATTACKER
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D65E0:
	createsprite gUnknown_085964E4, 0x85, 0, 1
	createsprite gUnknown_085964E4, 0x85, 1, 1
	return

Move_ROCK_BLAST:
	loadspritegfx 0x274A
	loadspritegfx 0x2797
	createsprite gUnknown_0857FE28, 0x2, 4, 6
	delay 0x3
	playsewithpan SE_W207, -64
	createsprite gUnknown_08596C98, 0x82, 16, 0, 0, 0, 25, 257
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 1
	playsewithpan SE_W088, +63
	createsprite gUnknown_08596B1C, 0x82, 0, 0, 20, 24, 14, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 5, 1
	createsprite gUnknown_08596B1C, 0x82, 5, 0, -20, 24, 14, 1
	createsprite gUnknown_08596B1C, 0x82, 0, 5, 20, -24, 14, 2
	createsprite gUnknown_08596B1C, 0x82, -5, 0, -20, -24, 14, 2
	waitforvisualfinish
	end

Move_OVERHEAT:
	loadspritegfx 0x272D
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x120C
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 5, RGB(28, 0, 0)
	waitforvisualfinish
	createvisualtask sub_8117C44, 0x5
	waitforvisualfinish
	createvisualtask sub_8117CA0, 0x5, 0, 1
	delay 0x1
	createvisualtask sub_8117DD8, 0x5, 0
	delay 0x1
	playsewithpan SE_W082, -64
	createvisualtask sub_8117CA0, 0x5, 1, 0
	delay 0x1
	createsprite gUnknown_08597274, 0x2, 2, 1, 0, 13, RGB(28, 0, 0)
	createvisualtask sub_80D51AC, 0x5, 0, 2, 0, 15, 1
	waitforvisualfinish
	playsewithpan SE_W172B, -64
	createsprite gUnknown_08596FB0, 0x2, 1, 0, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x2, 1, 32, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x2, 1, 64, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x2, 1, 96, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x2, 1, 128, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x42, 1, 160, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x42, 1, 192, 30, 25, -20
	createsprite gUnknown_08596FB0, 0x42, 1, 224, 30, 25, -20
	delay 0x5
	createsprite gUnknown_08596FB0, 0x2, 1, 0, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x2, 1, 32, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x2, 1, 64, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x2, 1, 96, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x2, 1, 128, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x42, 1, 160, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x42, 1, 192, 30, 25, 0
	createsprite gUnknown_08596FB0, 0x42, 1, 224, 30, 25, 0
	delay 0x5
	createsprite gUnknown_08596FB0, 0x2, 1, 0, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x2, 1, 32, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x2, 1, 64, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x2, 1, 96, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x2, 1, 128, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x42, 1, 160, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x42, 1, 192, 30, 25, 10
	createsprite gUnknown_08596FB0, 0x42, 1, 224, 30, 25, 10
	delay 0x5
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x83, -5, 3, 1, 0
	playsewithpan SE_W007, +63
	createvisualtask sub_80D51AC, 0x2, 1, 10, 0, 25, 1
	delay 0x6
	createsprite gUnknown_08597358, 0x83, 8, -5, 1, 0
	playsewithpan SE_W007, +63
	delay 0x8
	createsprite gUnknown_08597358, 0x83, 10, 10, 1, 0
	playsewithpan SE_W007, +63
	delay 0x8
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 0
	playsewithpan SE_W007, +63
	createvisualtask sub_8117DD8, 0x5, 1
	delay 0x1
	createsprite gUnknown_08597274, 0x2, 2, -1, 0, 13, RGB(18, 18, 18)
	createvisualtask sub_80D51AC, 0x5, 0, 3, 0, 15, 1
	waitforvisualfinish
	createvisualtask sub_8117D3C, 0x5, 0, 1
	delay 0x1
	createsprite gUnknown_08597274, 0x2, 1, 1, 5, 0, RGB(28, 0, 0)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	delay 0xF
	createvisualtask sub_8117D3C, 0x5, 1, 0
	delay 0x1
	createsprite gUnknown_08597274, 0x2, 2, 0, 13, 0, RGB(18, 18, 18)
	waitforvisualfinish
	createvisualtask sub_8117C70, 0x5
	waitforvisualfinish
	end

Move_HYDRO_CANNON:
	loadspritegfx 0x27A5
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	playsewithpan SE_W057, -64
	createsprite gUnknown_085951C0, 0x82
	delay 0xA
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	delay 0x1E
	panse_1B SE_W056, -64, +63, +2, 0x0
	call AnimScript_82D6A50
	createvisualtask sub_80D51AC, 0x5, 1, 10, 0, 40, 1
	createsprite gUnknown_08597388, 0x82, 0, 0, 1, 0
	call AnimScript_82D6A50
	createsprite gUnknown_08597388, 0x82, 0, 0, 1, 0
	call AnimScript_82D6A50
	createsprite gUnknown_08597388, 0x82, 0, 0, 1, 0
	call AnimScript_82D6A50
	createsprite gUnknown_08597388, 0x82, 0, 0, 1, 0
	call AnimScript_82D6A50
	createsprite gUnknown_08597388, 0x82, 0, 0, 1, 0
	call AnimScript_82D6A50
	createsprite gUnknown_08597388, 0x82, 0, 0, 1, 0
	waitforvisualfinish
	createvisualtask sub_8115F10, 0x2, 257, 257, 257
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D6A50:
	createsprite gUnknown_085951D8, 0x82, 10, -10, 0, 0, 15, 257
	delay 0x1
	createsprite gUnknown_085951D8, 0x82, 10, -10, 0, 0, 15, 257
	delay 0x1
	createsprite gUnknown_085951D8, 0x82, 10, -10, 0, 0, 15, 257
	delay 0x1
	createsprite gUnknown_085951D8, 0x82, 10, -10, 0, 0, 15, 257
	delay 0x1
	createsprite gUnknown_085951D8, 0x82, 10, -10, 0, 0, 15, 257
	return

Move_ASTONISH:
	loadspritegfx 0x2821
	playsewithpan SE_W227, -64
	createsprite gUnknown_0857FE28, 0x2, 4, 6
	delay 0x19
	createsprite gUnknown_085964E4, 0x85, 0, 1
	playsewithpan SE_W166, +63
	createsprite gUnknown_085964E4, 0x85, 1, 1
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 5, 1
	createvisualtask sub_8106020, 0x3
	waitforvisualfinish
	end

Move_SEISMIC_TOSS:
	loadspritegfx 0x2797
	loadspritegfx 0x274A
	setarg 0x7, 0x0
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	waitforvisualfinish
	createvisualtask sub_81114EC, 0x3
	delay 0x1
	fadetobg BG_SEISMICTOSS_SKUUPPERCUT
	waitbgfadeout
	createvisualtask sub_811152C, 0x3
	playsewithpan SE_W327, 0
	waitbgfadein
	waitforvisualfinish
	createvisualtask sub_8111590, 0x3
	jumpargeq 0x7, 0x0, AnimScript_82D6B53
	jumpargeq 0x7, 0x1, AnimScript_82D6B64
	jumpargeq 0x7, 0x2, AnimScript_82D6B7C

AnimScript_82D6B48:
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFF
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AnimScript_82D6B53:
	call AnimScript_82D6B9B
	delay 0x10
	call AnimScript_82D6BFC
	goto AnimScript_82D6B48

AnimScript_82D6B64:
	call AnimScript_82D6B9B
	delay 0xE
	call AnimScript_82D6BFC
	delay 0xE
	call AnimScript_82D6B9B
	goto AnimScript_82D6B48

AnimScript_82D6B7C:
	call AnimScript_82D6BFC
	delay 0xA
	call AnimScript_82D6B9B
	delay 0xA
	call AnimScript_82D6BFC
	delay 0xA
	call AnimScript_82D6B9B
	goto AnimScript_82D6B48

AnimScript_82D6B9B:
	createsprite gUnknown_08597358, 0x83, -10, -8, 1, 1
	playsewithpan SE_W070, +63
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, 0x82, -12, 27, 2, 3
	createsprite gUnknown_08596CB0, 0x82, 8, 28, 3, 4
	createsprite gUnknown_08596CB0, 0x82, -4, 30, 2, 3
	createsprite gUnknown_08596CB0, 0x82, 12, 25, 4, 4
	return

AnimScript_82D6BFC:
	createsprite gUnknown_08597358, 0x83, 10, -8, 1, 1
	playsewithpan SE_W088, +63
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, 0x82, -12, 32, 3, 4
	createsprite gUnknown_08596CB0, 0x82, 8, 31, 2, 2
	createsprite gUnknown_08596CB0, 0x82, -4, 28, 2, 3
	createsprite gUnknown_08596CB0, 0x82, 12, 30, 4, 3
	return

Move_MAGIC_COAT:
	loadspritegfx 0x27BA
	setalpha 0x1000
	waitplaysewithpan SE_W112, -64, 0xF
	createsprite gUnknown_085965C0, 0x3, 40, 0, 10170
	waitforvisualfinish
	delay 0x1
	blendoff
	end

Move_WATER_PULSE:
	loadspritegfx 0x27AB
	loadspritegfx 0x2830
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	playsewithpan SE_W145C, -64
	createsprite gUnknown_08597274, 0x2, 1, 0, 0, 7, RGB(0, 25, 28)
	delay 0xA
	createsprite gUnknown_085952F8, 0x42, 100, 100, 8, 1, 20, 40, 0
	createsprite gUnknown_085952F8, 0x42, 20, 100, 16, 2, 10, 35, 1
	createsprite gUnknown_085952F8, 0x42, 200, 80, 8, 1, 40, 20, 0
	createsprite gUnknown_085952F8, 0x42, 80, 60, 10, 3, 20, 50, 0
	createsprite gUnknown_085952F8, 0x42, 140, 100, 16, 1, 20, 30, 1
	playsewithpan SE_W145C, +63
	waitforvisualfinish
	playsewithpan SE_W202, -64
	createsprite gUnknown_08593470, 0x82, 0, 0, 40, 15
	delay 0x5
	playsewithpan SE_W202, -64
	createsprite gUnknown_08593470, 0x82, 0, 0, 40, 15
	delay 0x5
	playsewithpan SE_W202, -64
	createsprite gUnknown_08593470, 0x82, 0, 0, 40, 15
	delay 0xD
	createvisualtask sub_80D51AC, 0x2, 1, 0, 8, 18, 1
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 7, 0, RGB(0, 25, 28)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_PSYCHO_BOOST:
	loadspritegfx 0x27E4
	monbg ANIM_ATK_PARTNER
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A5C8, 0x5
	waitbgfadein
	delay 0x6
	createvisualtask sub_8115A04, 0x2, 1, 2, 8, 0, 10, 0
	delay 0x0
	monbgprio_28 ANIM_ATTACKER
	setalpha 0x808
	delay 0xA
	createvisualtask sub_80D51AC, 0x2, 0, 3, 0, 240, 0
	loopsewithpan SE_W060B, -64, 0xE, 0xA
	createsprite gUnknown_08596920, 0x2
	delay 0x6E
	loopsewithpan SE_W060B, -64, 0x7, 0xA
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, -8, 1, 24, 1
	playsewithpan SE_W043, +63
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	call AnimScript_82D7CDD
	end

Move_KNOCK_OFF:
	loadspritegfx 0x2825
	loadspritegfx 0x2797
	createsprite gUnknown_0857FE28, 0x2, 4, 6
	delay 0x4
	playsewithpan SE_W233, +63
	createsprite gUnknown_085CE984, 0x82, -16, -16
	delay 0x8
	createsprite gUnknown_0859728C, 0x2, 31, 5, 1, 0x7FFF, 10, 0, 0
	createsprite gUnknown_08597358, 0x83, 0, 0, 1, 2
	playsewithpan SE_W004, +63
	createsprite gUnknown_0857FE70, 0x2, 1, -12, 10, 0, 3
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 5
	delay 0x3
	createvisualtask sub_80D5484, 0x2, 1, 0, 3, 6, 1
	delay 0x5
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 6
	delay 0xA
	waitforvisualfinish
	end

Move_DOOM_DESIRE:
	createvisualtask sub_8114960, 0x2
	delay 0x1
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_811489C, 0x5, 1, 0
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 4, 0
	waitforvisualfinish
	setalpha 0x808
	playsewithpan SE_W060, -64
	createvisualtask sub_80D6064, 0x5, -4, -4, 15, 0, 1
	waitforvisualfinish
	delay 0x14
	createvisualtask sub_811489C, 0x5, 1, 1
	createsprite gUnknown_08597274, 0x2, 1, 1, 4, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_SKY_UPPERCUT:
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	fadetobg BG_SEISMICTOSS_SKUUPPERCUT
	waitbgfadeout
	playsewithpan SE_W327, -64
	createvisualtask sub_810DABC, 0x5, 55
	waitbgfadein
	setalpha 0x80C
	delay 0x26
	createsprite gUnknown_0857FE70, 0x2, 0, 28, 0, 0, 5
	delay 0x4
	createvisualtask sub_80D52D0, 0x2, 1, 4, 0, 6, 1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x83, -28, 28, 1, 1
	delay 0x1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x83, -15, 8, 1, 1
	playsewithpan SE_W233B, +63
	delay 0x1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x83, -5, -12, 1, 1
	delay 0x1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x83, 0, -32, 1, 1
	delay 0x1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08597358, 0x83, 5, -52, 1, 1
	createsprite gUnknown_0857FE70, 0x2, 1, -26, 16, 1, 4
	delay 0x4
	createvisualtask sub_80D5484, 0x2, 1, 0, 3, 6, 1
	delay 0x1E
	createsprite gUnknown_0857FE58, 0x2, 0, 0, 6
	delay 0x4
	createsprite gUnknown_0857FE58, 0x2, 1, 0, 6
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	end

Move_SECRET_POWER:
	createvisualtask sub_8117C24, 0x5
	jumpargeq 0x0, 0x0, Move_NEEDLE_ARM
	jumpargeq 0x0, 0x1, Move_MAGICAL_LEAF
	jumpargeq 0x0, 0x2, Move_MUD_SHOT
	jumpargeq 0x0, 0x3, Move_WATERFALL
	jumpargeq 0x0, 0x4, Move_SURF
	jumpargeq 0x0, 0x5, Move_BUBBLE_BEAM
	jumpargeq 0x0, 0x6, Move_ROCK_THROW
	jumpargeq 0x0, 0x7, Move_BITE
	jumpargeq 0x0, 0x8, Move_STRENGTH
	goto Move_SLAM

Move_TWISTER:
	loadspritegfx 0x274F
	loadspritegfx 0x2797
	loadspritegfx 0x274A
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	playsewithpan SE_W239, +63
	createsprite gUnknown_085923A8, 0x82, 120, 70, 5, 70, 30
	delay 0x1
	createsprite gUnknown_085923A8, 0x82, 115, 55, 6, 60, 25
	delay 0x1
	createsprite gUnknown_085923A8, 0x82, 115, 60, 7, 60, 30
	createsprite gUnknown_085923A8, 0x82, 115, 55, 10, 60, 30
	delay 0x3
	createsprite gUnknown_08596CC8, 0x82, 100, 50, 4, 50, 26
	delay 0x1
	createsprite gUnknown_085923A8, 0x82, 105, 25, 8, 60, 20
	delay 0x1
	createsprite gUnknown_085923A8, 0x82, 115, 40, 10, 48, 30
	delay 0x3
	createsprite gUnknown_08596CC8, 0x82, 120, 30, 6, 45, 25
	createsprite gUnknown_085923A8, 0x82, 115, 35, 10, 60, 30
	delay 0x3
	createsprite gUnknown_08596CC8, 0x82, 105, 20, 8, 40, 0
	delay 0x3
	createsprite gUnknown_085923A8, 0x82, 20, 255, 15, 32, 0
	createsprite gUnknown_085923A8, 0x82, 110, 10, 8, 32, 20
	waitforvisualfinish
	createsprite gUnknown_08597358, 0x83, -32, -16, 1, 3
	playsewithpan SE_W004, +63
	createvisualtask sub_80D5484, 0x2, 1, 3, 0, 12, 1
	createvisualtask sub_80D5484, 0x2, 3, 3, 0, 12, 1
	delay 0x4
	createsprite gUnknown_085973A0, 0x83, 1, 3
	playsewithpan SE_W004, +63
	delay 0x4
	createsprite gUnknown_085973A0, 0x83, 1, 3
	playsewithpan SE_W004, +63
	delay 0x4
	createsprite gUnknown_08597358, 0x83, 32, 20, 1, 3
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_MAGICAL_LEAF:
	loadspritegfx 0x274F
	loadspritegfx 0x27B0
	loadspritegfx 0x2797
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	delay 0x1
	loopsewithpan SE_W077, -64, 0xA, 0x5
	createvisualtask sub_81007C4, 0x5
	createsprite gUnknown_08592390, 0x2, -3, -2, 10
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -1, -1, 15
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -4, -4, 7
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 3, -3, 11
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -1, -6, 8
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 2, -1, 12
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -3, -4, 13
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 4, -5, 7
	delay 0x2
	createsprite gUnknown_08592390, 0x2, 2, -6, 11
	delay 0x2
	createsprite gUnknown_08592390, 0x2, -3, -5, 8
	delay 0x3C
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085923D8, 0x83, 20, -10, 20, 0, 32, 20, 0
	createsprite gUnknown_085923D8, 0x83, 20, -10, 20, 0, 32, -20, 0
	delay 0x1E
	playsewithpan SE_W013, +63
	createsprite gUnknown_08597358, 0x84, -10, -4, 1, 2
	createsprite gUnknown_08597358, 0x84, 10, 4, 1, 2
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	delay 0x14
	setarg 0x7, 0xFFFF
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ICE_BALL:
	loadspritegfx 0x273B
	loadspritegfx 0x279D
	createvisualtask sub_810CDFC, 0x5, 0
	jumpargeq 0x0, 0x4, AnimScript_82D731B

AnimScript_82D72BB:
	playsewithpan SE_W196, -64
	createsprite gUnknown_08595DE4, 0x82, 15, 0, -12, -16, 30, -40
	delay 0x1C
	playsewithpan SE_W280, +63
	createvisualtask sub_810CDFC, 0x5, 0
	jumpargeq 0x0, 0x0, AnimScript_82D732C
	jumpargeq 0x0, 0x1, AnimScript_82D735B
	jumpargeq 0x0, 0x2, AnimScript_82D7394
	jumpargeq 0x0, 0x3, AnimScript_82D73D7
	jumpargeq 0x0, 0x4, AnimScript_82D741F

AnimScript_82D7309:
	createvisualtask sub_810CDFC, 0x5, 0
	jumpargeq 0x0, 0x4, AnimScript_82D7322

AnimScript_82D731A:
	end

AnimScript_82D731B:
	fadetobg BG_ICE
	goto AnimScript_82D72BB

AnimScript_82D7322:
	waitbgfadein
	delay 0x2D
	restorebg
	waitbgfadein
	goto AnimScript_82D731A

AnimScript_82D732C:
	createvisualtask sub_80D6388, 0x2, 0, 1, 8, 1, 0
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	goto AnimScript_82D7309

AnimScript_82D735B:
	createvisualtask sub_80D6388, 0x2, 0, 1, 10, 1, 0
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	goto AnimScript_82D7309

AnimScript_82D7394:
	createvisualtask sub_80D6388, 0x2, 0, 1, 14, 1, 0
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	goto AnimScript_82D7309

AnimScript_82D73D7:
	createvisualtask sub_80D6388, 0x2, 0, 1, 18, 1, 0
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	goto AnimScript_82D7309

AnimScript_82D741F:
	createvisualtask sub_80D6388, 0x2, 0, 1, 30, 1, 0
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	call AnimScript_82D7467
	goto AnimScript_82D7309

AnimScript_82D7467:
	createsprite gUnknown_08595DFC, 0x84, -12, -16
	return

Move_WEATHER_BALL:
	loadspritegfx 0x282B
	createsprite gUnknown_0857FE40, 0x2, 8, 1, 0
	delay 0x8
	playsewithpan SE_W207, -64
	createsprite gUnknown_0853EE38, 0x2
	waitforvisualfinish
	delay 0xF
	playsewithpan SE_W197, 0
	createsprite gUnknown_0859728C, 0x2, 31, 5, 1, 0x7FFF, 10, 0, 0
	waitforvisualfinish
	createvisualtask sub_81604F0, 0x2
	delay 0x1
	jumpargeq 0x7, 0x0, AnimScript_82D74DE
	jumpargeq 0x7, 0x1, AnimScript_82D751B
	jumpargeq 0x7, 0x2, AnimScript_82D757F
	jumpargeq 0x7, 0x3, AnimScript_82D75E3
	jumpargeq 0x7, 0x4, AnimScript_82D7683

AnimScript_82D74DE:
	loadspritegfx 0x2797
	createsprite gUnknown_0853EE50, 0x82, -30, -100, 25, 1, 0, 0
	waitforvisualfinish
	playsewithpan SE_W025B, +63
	createsprite gUnknown_08597358, 0x84, -10, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 8, 1
	waitforvisualfinish
	end

AnimScript_82D751B:
	loadspritegfx 0x272D
	createsprite gUnknown_0859559C, 0x82, -30, -100, 25, 1, 40, 10
	playsewithpan SE_W172, +63
	delay 0xA
	createsprite gUnknown_0859559C, 0x82, -30, -100, 25, 1, -40, 20
	playsewithpan SE_W172, +63
	delay 0xA
	createsprite gUnknown_0859559C, 0x82, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W172, +63
	waitforvisualfinish
	playsewithpan SE_W172B, +63
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 8, 1
	waitforvisualfinish
	end

AnimScript_82D757F:
	loadspritegfx 0x27AB
	createsprite gUnknown_08595328, 0x82, -30, -100, 25, 1, 50, 10
	playsewithpan SE_W152, +63
	delay 0x8
	createsprite gUnknown_08595328, 0x82, -30, -100, 25, 1, -20, 20
	playsewithpan SE_W152, +63
	delay 0xD
	createsprite gUnknown_08595328, 0x82, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W152, +63
	waitforvisualfinish
	createvisualtask sub_80D51AC, 0x2, 1, 0, 3, 8, 1
	playsewithpan SE_W202, +63
	waitforvisualfinish
	end

AnimScript_82D75E3:
	loadspritegfx 0x274A
	createsprite gUnknown_08596CE0, 0x82, -30, -100, 25, 1, 30, 0
	playsewithpan SE_W088, +63
	delay 0x5
	createsprite gUnknown_08596CE0, 0x82, -30, -100, 25, 1, -40, 20
	playsewithpan SE_W088, +63
	delay 0xE
	createsprite gUnknown_08596CE0, 0x82, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W088, +63
	waitforvisualfinish
	playsewithpan SE_W070, +63
	createsprite gUnknown_08596CB0, 0x82, -12, 27, 2, 3
	createsprite gUnknown_08596CB0, 0x82, 8, 28, 3, 4
	createsprite gUnknown_08596CB0, 0x82, -4, 30, 2, 3
	createsprite gUnknown_08596CB0, 0x82, 12, 25, 4, 4
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	waitforvisualfinish
	end

AnimScript_82D7683:
	loadspritegfx 0x2817
	loadspritegfx 0x279D
	createsprite gUnknown_08595D44, 0x82, -30, -100, 25, 25, -40, 20
	playsewithpan SE_W258, +63
	delay 0xA
	createsprite gUnknown_08595D44, 0x82, -30, -100, 25, 25, 40, 0
	playsewithpan SE_W258, +63
	delay 0xA
	createsprite gUnknown_08595D44, 0x82, -30, -100, 25, 25, 0, 0
	playsewithpan SE_W258, +63
	waitforvisualfinish
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	playsewithpan SE_W196, +63
	call AnimScript_82D7720
	waitforvisualfinish
	end

Move_COUNT:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W003, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

AnimScript_82D7720:
	createsprite gUnknown_08595B68, 0x82, -10, -10, 0
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 10, 20, 0
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B68, 0x82, -5, 10, 0
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 17, -12, 0
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, -15, 15, 0
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 0, 0, 0
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B68, 0x82, 20, 2, 0
	playsewithpan SE_W196, +63
	return

AnimScript_82D77A4:
	createsprite gUnknown_08595B68, 0x82, -10, -10, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 10, 20, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B68, 0x82, -29, 0, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 29, -20, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B68, 0x82, -5, 10, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 17, -12, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B68, 0x82, -20, 0, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, -15, 15, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 26, -5, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B80, 0x82, 0, 0, 1
	playsewithpan SE_W196, +63
	delay 0x4
	createsprite gUnknown_08595B68, 0x82, 20, 2, 1
	playsewithpan SE_W196, +63
	return

AnimScript_82D7874:
	loopsewithpan SE_W196, +63, 0x6, 0x4
	createsprite gUnknown_08595C04, 0x82, 0, 24, 0
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 8, 24, 0
	createsprite gUnknown_08595C04, 0x82, -8, 24, 0
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 16, 24, 0
	createsprite gUnknown_08595C04, 0x82, -16, 24, 0
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 24, 24, 0
	createsprite gUnknown_08595C04, 0x82, -24, 24, 0
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 32, 24, 0
	createsprite gUnknown_08595C04, 0x82, -32, 24, 0
	return

AnimScript_82D78F8:
	loopsewithpan SE_W196, +63, 0x6, 0x4
	createsprite gUnknown_08595C04, 0x82, 0, 24, 1
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 8, 24, 1
	createsprite gUnknown_08595C04, 0x82, -8, 24, 1
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 16, 24, 1
	createsprite gUnknown_08595C04, 0x82, -16, 24, 1
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 24, 24, 1
	createsprite gUnknown_08595C04, 0x82, -24, 24, 1
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 32, 24, 1
	createsprite gUnknown_08595C04, 0x82, -32, 24, 1
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 40, 24, 1
	createsprite gUnknown_08595C04, 0x82, -40, 24, 1
	delay 0x4
	createsprite gUnknown_08595C04, 0x82, 48, 24, 1
	createsprite gUnknown_08595C04, 0x82, -48, 24, 1
	return

AnimScript_82D79B4:
	createsprite gUnknown_08592B7C, 0x2, -15, 0, 0, 0, 32, 60
	delay 0x8
	createsprite gUnknown_08592B7C, 0x2, 12, -5, 0, 0, 32, 60
	delay 0x8
	return

AnimScript_82D79DF:
	playsewithpan SE_W071B, -64
	createsprite gUnknown_08592F2C, 0x2, 0, -5, 0, 0
	delay 0x7
	createsprite gUnknown_08592F2C, 0x2, -15, 10, 0, 0
	delay 0x7
	createsprite gUnknown_08592F2C, 0x2, -15, -15, 0, 0
	delay 0x7
	createsprite gUnknown_08592F2C, 0x2, 10, -5, 0, 0
	delay 0x7
	return

AnimScript_82D7A28:
	playsewithpan SE_W071B, +63
	createsprite gUnknown_08592F2C, 0x82, 0, -5, 1, 0
	delay 0x7
	createsprite gUnknown_08592F2C, 0x82, -15, 10, 1, 0
	delay 0x7
	createsprite gUnknown_08592F2C, 0x82, -15, -15, 1, 0
	delay 0x7
	createsprite gUnknown_08592F2C, 0x82, 10, -5, 1, 0
	delay 0x7
	return

AnimScript_82D7A71:
	createsprite gUnknown_08596240, 0x82, 10, 10, 0
	playsewithpan SE_W092, +63
	delay 0x6
	createsprite gUnknown_08596240, 0x82, 20, -20, 0
	playsewithpan SE_W092, +63
	delay 0x6
	createsprite gUnknown_08596240, 0x82, -20, 15, 0
	playsewithpan SE_W092, +63
	delay 0x6
	createsprite gUnknown_08596240, 0x82, 0, 0, 0
	playsewithpan SE_W092, +63
	delay 0x6
	createsprite gUnknown_08596240, 0x82, -20, -20, 0
	playsewithpan SE_W092, +63
	delay 0x6
	createsprite gUnknown_08596240, 0x82, 16, -8, 0
	playsewithpan SE_W092, +63
	return

AnimScript_82D7AE2:
	createsprite gUnknown_08596258, 0x2, 10, 10, 0
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 20, -20, 0
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, -20, 15, 0
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 0, 0, 0
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, -20, -20, 0
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 16, -8, 0
	playsewithpan SE_W145C, +63
	return

AnimScript_82D7B53:
	createsprite gUnknown_08596258, 0x2, 10, 10, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, -28, -10, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 20, -20, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, -20, 15, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 0, 0, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 27, 8, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, -20, -20, 1
	playsewithpan SE_W145C, +63
	delay 0x6
	createsprite gUnknown_08596258, 0x2, 16, -8, 1
	playsewithpan SE_W145C, +63
	return

AnimScript_82D7BEA:
	playsewithpan SE_W085B, +63
	createsprite gUnknown_08595810, 0x82, 5, 0, 5, 0
	delay 0x2
	createsprite gUnknown_08595810, 0x82, -5, 10, 5, 1
	delay 0x2
	createsprite gUnknown_08595810, 0x82, 15, 20, 5, 2
	delay 0x2
	createsprite gUnknown_08595810, 0x82, -15, -10, 5, 0
	delay 0x2
	createsprite gUnknown_08595810, 0x82, 25, 0, 5, 1
	delay 0x2
	createsprite gUnknown_08595810, 0x82, -8, 8, 5, 2
	delay 0x2
	createsprite gUnknown_08595810, 0x82, 2, -8, 5, 0
	delay 0x2
	createsprite gUnknown_08595810, 0x82, -20, 15, 5, 1
	return

AnimScript_82D7C75:
	loopsewithpan SE_W146, +63, 0xD, 0x6
	createsprite gUnknown_0859725C, 0x82, 0, -15, 0, 3, 90
	createsprite gUnknown_0859725C, 0x82, 0, -15, 51, 3, 90
	createsprite gUnknown_0859725C, 0x82, 0, -15, 102, 3, 90
	createsprite gUnknown_0859725C, 0x82, 0, -15, 153, 3, 90
	createsprite gUnknown_0859725C, 0x82, 0, -15, 204, 3, 90
	return

AnimScript_82D7CD1:
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A504, 0x5
	waitbgfadein
	return

AnimScript_82D7CDD:
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	return

AnimScript_82D7CE5:
	jumpifcontest AnimScript_82D7CFE
	fadetobg BG_FLYING
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, -2304, 768, 1, -1

AnimScript_82D7CFC:
	waitbgfadein
	return

AnimScript_82D7CFE:
	fadetobg BG_FLYING_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 0x5, 2304, 768, 0, -1
	goto AnimScript_82D7CFC

AnimScript_82D7D15:
	restorebg
	waitbgfadeout
	setarg 0x7, 0xFFFF
	waitbgfadein
	return

AnimScript_82D7D1D:
	createvisualtask sub_8117E60, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D7D42
	createvisualtask sub_815A8C8, 0x2
	jumpargeq 0x7, 0x0, AnimScript_82D7D50
	goto AnimScript_82D7D49

AnimScript_82D7D40:
	waitbgfadein
	return

AnimScript_82D7D42:
	fadetobg BG_SOLARBEAM_CONTESTS
	goto AnimScript_82D7D40

AnimScript_82D7D49:
	fadetobg BG_SOLARBEAM_PLAYER
	goto AnimScript_82D7D40

AnimScript_82D7D50:
	fadetobg BG_SOLARBEAM_OPPONENT
	goto AnimScript_82D7D40

AnimScript_82D7D57:
	restorebg
	waitbgfadein
	return

Status_Poison:
	loopsewithpan SE_W092, +63, 0xD, 0x6
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 18, 2
	createvisualtask sub_8115A04, 0x2, 2, 2, 2, 0, 12, 31774
	end

Status_Confusion:
	loadspritegfx 0x2759
	call AnimScript_82D7C75
	end

Status_Burn:
	loadspritegfx 0x272D
	playsewithpan SE_W172, +63
	call AnimScript_82D7DA6
	call AnimScript_82D7DA6
	call AnimScript_82D7DA6
	waitforvisualfinish
	end

AnimScript_82D7DA6:
	createsprite gUnknown_08595504, 0x82, -24, 24, 24, 24, 20, 1, 1
	delay 0x4
	return

Status_Infatuation:
	loadspritegfx 0x27E2
	playsewithpan SE_W204, -64
	createsprite gUnknown_08593970, 0x3, 0, 20
	delay 0xF
	playsewithpan SE_W204, -64
	createsprite gUnknown_08593970, 0x3, -20, 20
	delay 0xF
	playsewithpan SE_W204, -64
	createsprite gUnknown_08593970, 0x3, 20, 20
	end

Status_Sleep:
	loadspritegfx 0x27F4
	playsewithpan SE_W173, -64
	createsprite gUnknown_08592C88, 0x2, 4, -10, 16, 0, 0
	delay 0x1E
	createsprite gUnknown_08592C88, 0x2, 4, -10, 16, 0, 0
	end

Status_Paralysis:
	loadspritegfx 0x271B
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 10, 1
	call AnimScript_82D7BEA
	end

Status_Freeze:
	playsewithpan SE_W196, 0
	loadspritegfx 0x271A
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	waitplaysewithpan SE_W258, +63, 0x11
	createvisualtask sub_80A9EF4, 0x2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Status_Curse:
	loadspritegfx 0x27D8
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, +63
	createsprite gUnknown_08596DE8, 0x82
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 14, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Status_Nightmare:
	loadspritegfx 0x27ED
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, +63
	createsprite gUnknown_08596E00, 0x82
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 14, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Anim_CastformTransform:
	createvisualtask sub_815BB18, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D7ECA
	goto AnimScript_82D7EB2

AnimScript_82D7EB2:
	monbg ANIM_ATTACKER
	playsewithpan SE_W100, -64
	waitplaysewithpan SE_W107, -64, 0x30
	createvisualtask sub_815B7D0, 0x2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

AnimScript_82D7ECA:
	createvisualtask sub_815BB58, 0x2, 1
	end

Anim_StatChange:
	createvisualtask AnimTask_StatsChange, 0x5
	waitforvisualfinish
	end

Anim_SubsituteOff:
	monbg ANIM_ATTACKER
	createvisualtask sub_8172D98, 0x5
	createvisualtask sub_8116620, 0xA, 2, 0, 0, 16, 0x7FFF
	waitforvisualfinish
	delay 0x1
	clearmonbg ANIM_ATTACKER
	delay 0x2
	blendoff
	createvisualtask sub_8116620, 0xA, 2, 0, 0, 0, 0x7FFF
	createvisualtask sub_8172BF0, 0x2, 1
	end

Anim_SubsituteOn:
	createvisualtask sub_815F20C, 0x2
	end

Anim_Table_4:
	createvisualtask sub_817345C, 0x2, 0
	createvisualtask sub_81732B0, 0x2
	delay 0x0
	waitplaysewithpan SE_W026, -64, 0x16
	createsprite gUnknown_085E5338, 0x83, -18, 12, 0, 32
	delay 0x32
	loopsewithpan SE_W039, +63, 0x13, 0x2
	createvisualtask sub_80D5EB8, 0x5, 1, 8, 1536, 2, 1
	waitforvisualfinish
	createvisualtask sub_81732E4, 0x2
	end

Anim_ItemKnockOff:
	loadspritegfx 0x27F0
	createsprite gUnknown_08592628, 0x82
	end

Status_Wrap:
	createvisualtask sub_81734B4, 0x5
	jumpargeq 0x0, 0x1, AnimScript_82D7FE9
	jumpargeq 0x0, 0x2, AnimScript_82D800E
	jumpargeq 0x0, 0x3, AnimScript_82D8062
	jumpargeq 0x0, 0x4, AnimScript_82D80BF
	goto AnimScript_82D7FA1

AnimScript_82D7FA1:
	loadspritegfx 0x27CA
	loopsewithpan SE_W010, +63, 0x6, 0x2
	createsprite gUnknown_08592494, 0x84, 0, 16, 0, 1
	delay 0x7
	createsprite gUnknown_08592494, 0x82, 0, 8, 1, 1
	delay 0x3
	createvisualtask sub_80D52D0, 0x2, 1, 2, 0, 8, 1
	delay 0x14
	setarg 0x7, 0xFFFF
	playsewithpan SE_W020, +63
	waitforvisualfinish
	end

AnimScript_82D7FE9:
	loadspritegfx 0x272D
	playsewithpan SE_W221B, +63
	createvisualtask sub_80D51AC, 0x5, 1, 0, 2, 30, 1
	call AnimScript_82CACBF
	call AnimScript_82CACBF
	waitforvisualfinish
	stopsound
	end

AnimScript_82D800E:
	loadspritegfx 0x27A5
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 0x80C
	delay 0x0
	createsprite gUnknown_08597274, 0x0, 4, 2, 0, 7, RGB(0, 13, 23)
	playsewithpan SE_W250, +63
	createvisualtask sub_80D51AC, 0x5, 1, 0, 2, 30, 1
	call AnimScript_82D1F5B
	call AnimScript_82D1F5B
	delay 0xC
	createsprite gUnknown_08597274, 0x0, 4, 2, 7, 0, RGB(0, 13, 23)
	waitforvisualfinish
	stopsound
	clearmonbg ANIM_DEF_PARTNER
	end

AnimScript_82D8062:
	loadspritegfx 0x27A1
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W011, +63
	createsprite gUnknown_08597098, 0x2, -32, 0, 2, 819, 0, 10
	createsprite gUnknown_08597098, 0x2, 32, 0, 6, -819, 0, 10
	delay 0xA
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x5, 1, 3, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

AnimScript_82D80BF:
	loadspritegfx 0x275A
	createsprite gUnknown_08597274, 0x0, 4, 2, 0, 7, RGB(19, 17, 0)
	createvisualtask sub_80D51AC, 0x5, 1, 0, 2, 30, 1
	playsewithpan SE_W328, +63
	call AnimScript_82D51B7
	call AnimScript_82D51B7
	delay 0x16
	createsprite gUnknown_08597274, 0x0, 4, 2, 7, 0, RGB(19, 17, 0)
	waitforvisualfinish
	stopsound
	end

Anim_ItemEffect:
	loadspritegfx 0x27DB
	loadspritegfx 0x2741
	delay 0x0
	playsewithpan SE_W036, -64
	createvisualtask sub_80D622C, 0x2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W036, -64
	createvisualtask sub_80D622C, 0x2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W036, -64
	createvisualtask sub_80D622C, 0x2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W234, -64
	call AnimScript_82D79B4
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createsprite gUnknown_08597274, 0x2, 2, 3, 7, 0, RGB(17, 31, 25)
	createsprite gUnknown_0859381C, 0x3, 0, 0, 0, 0
	waitforvisualfinish
	end

Anim_SmokeBallEscape:
	loadspritegfx 0x2802
	monbg ANIM_ATTACKER
	setalpha 0x40C
	delay 0x0
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x80, 0, 32, 28, 30
	delay 0x4
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7F, 2, 12, 20, 30
	delay 0xC
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7E, 2, -28, 4, 30
	delay 0xC
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7C, 2, 14, -20, 30
	delay 0x4
	playsewithpan SE_BOWA2, +63
	createvisualtask sub_81136E8, 0x2, 2
	createsprite gUnknown_085CE734, 0x7B, 3, 4, 4, 30
	delay 0xE
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7A, 3, -14, 18, 46
	delay 0x0
	createsprite gUnknown_085CE734, 0x79, 3, 14, -14, 46
	delay 0x0
	createsprite gUnknown_085CE734, 0x78, 3, -12, -10, 46
	delay 0x0
	createsprite gUnknown_085CE734, 0x77, 3, 14, 14, 46
	delay 0x0
	createsprite gUnknown_085CE734, 0x76, 3, 0, 0, 46
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	invisible ANIM_ATTACKER
	delay 0x0
	blendoff
	end

Anim_HangedOn:
	createsprite gUnknown_08597274, 0x0, 2, 7, 0, 9, RGB_RED
	playsewithpan SE_W082, -64
	createvisualtask sub_815DB90, 0x5, 30, 128, 0, 1, 2, 0, 1
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x0, 2, 4, 9, 0, RGB_RED
	waitforvisualfinish
	delay 0x6
	createsprite gUnknown_0857FE58, 0x0, 0, 0, 15
	end

Anim_Rain:
	loadspritegfx 0x2783
	playsewithpan SE_W240, -64
	createvisualtask sub_8116620, 0xA, 1921, 2, 0, 4, 0
	waitforvisualfinish
	createvisualtask sub_8107188, 0x2, 0, 3, 60
	createvisualtask sub_8107188, 0x2, 0, 3, 60
	delay 0x32
	waitforvisualfinish
	createvisualtask sub_8116620, 0xA, 1921, 2, 4, 0, 0
	waitforvisualfinish
	end

Anim_Sun:
	goto Move_SUNNY_DAY

Anim_Sandstorm:
	goto Move_SANDSTORM

Anim_Hail:
	goto Move_HAIL

Status_LeechSeed:
	createvisualtask sub_817351C, 0x5
	delay 0x0
	goto Move_ABSORB

Anim_Hit:
	loadspritegfx 0x2797
	monbg ANIM_TARGET
	setalpha 0x80C
	playsewithpan SE_W003, +63
	createsprite gUnknown_08597358, 0x2, 0, 0, 1, 2
	createvisualtask sub_80D51AC, 0x2, 1, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Anim_ItemSteal:
	loadspritegfx 0x27F0
	createvisualtask sub_8117F30, 0x2
	createvisualtask sub_8172ED0, 0x2
	delay 0x1
	createsprite gUnknown_08592670, 0x2, 0, -5, 10, 2, -1
	end

Anim_SnatchMove:
	loadspritegfx 0x27F0
	createvisualtask sub_8117E94, 0x2
	call AnimScript_82D85A3
	delay 0x1
	createvisualtask sub_80D5EB8, 0x2, 0, 5, 5120, 4, 1
	waitforvisualfinish
	createvisualtask sub_8117EC4, 0x2
	jumpargeq 0x7, 0x0, AnimScript_82D839F
	goto AnimScript_82D83AF

AnimScript_82D8398:
	waitforvisualfinish
	call AnimScript_82D85C3
	end

AnimScript_82D839F:
	playsewithpan SE_W104, -64
	createvisualtask sub_815F8F4, 0x2
	goto AnimScript_82D8398

AnimScript_82D83AF:
	playsewithpan SE_W104, -64
	createvisualtask sub_815FFC4, 0x2
	goto AnimScript_82D8398

Anim_FutureSightHit:
	createvisualtask sub_8117F10, 0x2
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W060, -64
	call AnimScript_82D7CD1
	setalpha 0x808
	playsewithpan SE_W048, +63
	waitplaysewithpan SE_W048, +63, 0x8
	createvisualtask sub_80D51AC, 0x2, 1, 4, 0, 15, 1
	createvisualtask sub_80D6064, 0x5, -5, -5, 15, 1, 1
	waitforvisualfinish
	createvisualtask sub_80D51AC, 0x2, 1, 4, 0, 24, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	delay 0x1
	call AnimScript_82D7CDD
	end

Anim_DoomDesireHit:
	createvisualtask sub_8117F10, 0x2
	loadspritegfx 0x27D6
	createsprite gUnknown_08597274, 0x2, 1, 3, 0, 16, RGB_WHITE
	waitforvisualfinish
	delay 0xA
	createvisualtask sub_815C0A4, 0x5
	delay 0x9
	playsewithpan SE_W109, -64
	delay 0x9
	playsewithpan SE_W109, 0
	delay 0x9
	playsewithpan SE_W109, +63
	delay 0x19
	createvisualtask sub_80D5484, 0x2, 1, 10, 0, 20, 1
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, 0, 0, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, 24, -24, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, -16, 16, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, -24, -12, 1, 1
	delay 0x6
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859371C, 0x3, 16, 16, 1, 1
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 3, 16, 0, RGB_WHITE
	waitforvisualfinish
	end

Anim_Table_x14:
	loadspritegfx 0x27C8
	playsewithpan SE_W082, -64
	call AnimScript_82CD6C7
	delay 0x8
	createvisualtask sub_8115A04, 0x2, 2, 2, 2, 0, 11, 31
	createvisualtask sub_80D52D0, 0x2, 0, 1, 0, 32, 1
	call AnimScript_82CD6C7
	delay 0x8
	call AnimScript_82CD6C7
	waitforvisualfinish
	end

Status_Ingrain:
	loadspritegfx 0x27A3
	loadspritegfx 0x272F
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	createsprite gUnknown_08597274, 0x2, 1, 1, 0, 4, RGB(13, 31, 12)
	waitforvisualfinish
	delay 0x3
	call AnimScript_82D1009
	waitforvisualfinish
	delay 0xF
	call AnimScript_82D79DF
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 1, 4, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Anim_WishHeal:
	loadspritegfx 0x2741
	createsprite gUnknown_08597274, 0x2, 1, 3, 0, 10, 0
	waitforvisualfinish
	playsewithpan SE_W025, -64
	call AnimScript_82D79B4
	waitforvisualfinish
	unloadspritegfx 0x2741
	loadspritegfx 0x272F
	call AnimScript_82D79DF
	waitforvisualfinish
	createsprite gUnknown_08597274, 0x2, 1, 3, 10, 0, 0
	end

AnimScript_82D85A3:
	createvisualtask sub_8172E9C, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D85B4

AnimScript_82D85B2:
	waitforvisualfinish
	return

AnimScript_82D85B4:
	createvisualtask sub_8172BF0, 0x2, 1
	waitforvisualfinish
	goto AnimScript_82D85B2

AnimScript_82D85C3:
	createvisualtask sub_8172E9C, 0x2
	jumpargeq 0x7, 0x1, AnimScript_82D85D4

AnimScript_82D85D2:
	waitforvisualfinish
	return

AnimScript_82D85D4:
	createvisualtask sub_8172BF0, 0x2, 0
	waitforvisualfinish
	goto AnimScript_82D85D2

Anim_LevelUp:
	playsewithpan SE_EXPMAX, 0
	createvisualtask sub_8170920, 0x2
	delay 0x0
	createvisualtask sub_8170A0C, 0x5, 0, 0
	waitforvisualfinish
	createvisualtask sub_81709EC, 0x2
	end

Anim_SwitchOutPlayer:
	createvisualtask sub_8170BB0, 0x2
	delay 0xA
	createvisualtask sub_8170B04, 0x2
	end

Anim_SwitchOutOpponent:
	createvisualtask sub_8170BB0, 0x2
	delay 0xA
	createvisualtask sub_8170B04, 0x2
	end

Anim_BallThrow:
	createvisualtask sub_8170CFC, 0x2
	delay 0x0
	playsewithpan SE_NAGERU, 0
	createvisualtask sub_8170E04, 0x2
	createvisualtask sub_8170D4C, 0x2
	jumpargeq 0x7, 0xFFFF, AnimScript_82D8652

AnimScript_82D8649:
	waitforvisualfinish
	createvisualtask sub_8170D24, 0x2
	end

AnimScript_82D8652:
	loadspritegfx 0x2797
	delay 0x19
	monbg ANIM_DEF_PARTNER
	setalpha 0x80C
	delay 0x0
	playsewithpan SE_W003, +63
	createsprite gUnknown_08597358, 0x82, -4, -20, 1, 2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto AnimScript_82D8649

Anim_SafariBallThrow:
	createvisualtask sub_8170CFC, 0x2
	delay 0x0
	createvisualtask sub_8170F2C, 0x2
	waitforvisualfinish
	createvisualtask sub_8170D24, 0x2
	end

Anim_SubstituteToMon:
	createvisualtask sub_8172BF0, 0x2, 1
	end

Anim_MonToSubstitute:
	createvisualtask sub_8172BF0, 0x2, 0
	end
