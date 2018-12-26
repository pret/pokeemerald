#ifndef GUARD_CONSTANTS_BATTLE_ANIM_H
#define GUARD_CONSTANTS_BATTLE_ANIM_H

// Sprites start at 10000 and thus must be subtracted of 10000 to account for the true index.
#define GET_TRUE_SPRITE_INDEX(i) ((i - ANIM_SPRITES_START))

// Particle ids.
#define ANIM_SPRITES_START 10000

#define ANIM_TAG_BONE                       (ANIM_SPRITES_START + 0)
#define ANIM_TAG_SPARK                      (ANIM_SPRITES_START + 1)
#define ANIM_TAG_PENCIL                     (ANIM_SPRITES_START + 2)
#define ANIM_TAG_AIR_WAVE                   (ANIM_SPRITES_START + 3)
#define ANIM_TAG_UNUSED_ORB                 (ANIM_SPRITES_START + 4)
#define ANIM_TAG_SWORD                      (ANIM_SPRITES_START + 5)
#define ANIM_TAG_SEED                       (ANIM_SPRITES_START + 6)
#define ANIM_TAG_UNUSED_EXPLOSION           (ANIM_SPRITES_START + 7)
#define ANIM_TAG_UNUSED_PINK_ORB            (ANIM_SPRITES_START + 8)
#define ANIM_TAG_GUST                       (ANIM_SPRITES_START + 9)
#define ANIM_TAG_ICE_CUBE                   (ANIM_SPRITES_START + 10)
#define ANIM_TAG_SPARK_2                    (ANIM_SPRITES_START + 11)
#define ANIM_TAG_UNUSED_ORANGE              (ANIM_SPRITES_START + 12)
#define ANIM_TAG_YELLOW_BALL                (ANIM_SPRITES_START + 13)
#define ANIM_TAG_LOCK_ON                    (ANIM_SPRITES_START + 14)
#define ANIM_TAG_TIED_BAG                   (ANIM_SPRITES_START + 15)
#define ANIM_TAG_BLACK_SMOKE                (ANIM_SPRITES_START + 16)
#define ANIM_TAG_BLACK_BALL                 (ANIM_SPRITES_START + 17)
#define ANIM_TAG_CONVERSION                 (ANIM_SPRITES_START + 18)
#define ANIM_TAG_UNUSED_GLASS               (ANIM_SPRITES_START + 19)
#define ANIM_TAG_HORN_HIT                   (ANIM_SPRITES_START + 20)
#define ANIM_TAG_UNUSED_HIT                 (ANIM_SPRITES_START + 21)
#define ANIM_TAG_UNUSED_HIT_2               (ANIM_SPRITES_START + 22)
#define ANIM_TAG_UNUSED_BLUE_SHARDS         (ANIM_SPRITES_START + 23)
#define ANIM_TAG_UNUSED_CLOSING_EYE         (ANIM_SPRITES_START + 24)
#define ANIM_TAG_UNUSED_WAVING_HAND         (ANIM_SPRITES_START + 25)
#define ANIM_TAG_UNUSED_HIT_DUPLICATE       (ANIM_SPRITES_START + 26)
#define ANIM_TAG_LEER                       (ANIM_SPRITES_START + 27)
#define ANIM_TAG_UNUSED_BLUE_BURST          (ANIM_SPRITES_START + 28)
#define ANIM_TAG_SMALL_EMBER                (ANIM_SPRITES_START + 29)
#define ANIM_TAG_GRAY_SMOKE                 (ANIM_SPRITES_START + 30)
#define ANIM_TAG_BLUE_STAR                  (ANIM_SPRITES_START + 31)
#define ANIM_TAG_UNUSED_BUBBLE_BURST        (ANIM_SPRITES_START + 32)
#define ANIM_TAG_FIRE                       (ANIM_SPRITES_START + 33)
#define ANIM_TAG_UNUSED_SPINNING_FIRE       (ANIM_SPRITES_START + 34)
#define ANIM_TAG_FIRE_PLUME                 (ANIM_SPRITES_START + 35)
#define ANIM_TAG_UNUSED_LIGHTNING           (ANIM_SPRITES_START + 36)
#define ANIM_TAG_LIGHTNING                  (ANIM_SPRITES_START + 37)
#define ANIM_TAG_UNUSED_CLAW_SLASH          (ANIM_SPRITES_START + 38)
#define ANIM_TAG_CLAW_SLASH                 (ANIM_SPRITES_START + 39)
#define ANIM_TAG_UNUSED_SCRATCH             (ANIM_SPRITES_START + 40)
#define ANIM_TAG_UNUSED_SCRATCH_2           (ANIM_SPRITES_START + 41)
#define ANIM_TAG_UNUSED_BUBBLE_BURST_2      (ANIM_SPRITES_START + 42)
#define ANIM_TAG_ICE_CHUNK                  (ANIM_SPRITES_START + 43)
#define ANIM_TAG_UNUSED_GLASS_2             (ANIM_SPRITES_START + 44)
#define ANIM_TAG_UNUSED_PINK_HEART          (ANIM_SPRITES_START + 45)
#define ANIM_TAG_UNUSED_SAP_DRIP            (ANIM_SPRITES_START + 46)
#define ANIM_TAG_UNUSED_SAP_DRIP_2          (ANIM_SPRITES_START + 47)
#define ANIM_TAG_SPARKLE_1                  (ANIM_SPRITES_START + 48)
#define ANIM_TAG_SPARKLE_2                  (ANIM_SPRITES_START + 49)
#define ANIM_TAG_HUMANOID_FOOT              (ANIM_SPRITES_START + 50)
#define ANIM_TAG_UNUSED_MONSTER_FOOT        (ANIM_SPRITES_START + 51)
#define ANIM_TAG_UNUSED_HUMANOID_HAND       (ANIM_SPRITES_START + 52)
#define ANIM_TAG_NOISE_LINE                 (ANIM_SPRITES_START + 53)
#define ANIM_TAG_UNUSED_YELLOW_UNK          (ANIM_SPRITES_START + 54)
#define ANIM_TAG_UNUSED_RED_FIST            (ANIM_SPRITES_START + 55)
#define ANIM_TAG_SLAM_HIT                   (ANIM_SPRITES_START + 56)
#define ANIM_TAG_UNUSED_RING                (ANIM_SPRITES_START + 57)
#define ANIM_TAG_ROCKS                      (ANIM_SPRITES_START + 58)
#define ANIM_TAG_UNUSED_Z                   (ANIM_SPRITES_START + 59)
#define ANIM_TAG_UNUSED_YELLOW_UNK_2        (ANIM_SPRITES_START + 60)
#define ANIM_TAG_UNUSED_AIR_SLASH           (ANIM_SPRITES_START + 61)
#define ANIM_TAG_UNUSED_SPINNING_GREEN_ORBS (ANIM_SPRITES_START + 62)
#define ANIM_TAG_LEAF                       (ANIM_SPRITES_START + 63)
#define ANIM_TAG_FINGER                     (ANIM_SPRITES_START + 64)
#define ANIM_TAG_POISON_POWDER              (ANIM_SPRITES_START + 65)
#define ANIM_TAG_UNUSED_BROWN_TRIANGLE      (ANIM_SPRITES_START + 66)
#define ANIM_TAG_SLEEP_POWDER               (ANIM_SPRITES_START + 67)
#define ANIM_TAG_STUN_SPORE                 (ANIM_SPRITES_START + 68)
#define ANIM_TAG_UNUSED_POWDER              (ANIM_SPRITES_START + 69)
#define ANIM_TAG_SPARKLE_3                  (ANIM_SPRITES_START + 70)
#define ANIM_TAG_SPARKLE_4                  (ANIM_SPRITES_START + 71)
#define ANIM_TAG_MUSIC_NOTES                (ANIM_SPRITES_START + 72)
#define ANIM_TAG_DUCK                       (ANIM_SPRITES_START + 73)
#define ANIM_TAG_MUD_SAND                   (ANIM_SPRITES_START + 74)
#define ANIM_TAG_ALERT                      (ANIM_SPRITES_START + 75)
#define ANIM_TAG_UNUSED_BLUE_FLAMES         (ANIM_SPRITES_START + 76)
#define ANIM_TAG_UNUSED_BLUE_FLAMES_2       (ANIM_SPRITES_START + 77)
#define ANIM_TAG_UNUSED_SHOCK               (ANIM_SPRITES_START + 78)
#define ANIM_TAG_SHOCK                      (ANIM_SPRITES_START + 79)
#define ANIM_TAG_UNUSED_BELL                (ANIM_SPRITES_START + 80)
#define ANIM_TAG_UNUSED_PINK_GLOVE          (ANIM_SPRITES_START + 81)
#define ANIM_TAG_UNUSED_BLUE_LINES          (ANIM_SPRITES_START + 82)
#define ANIM_TAG_UNUSED_IMPACT              (ANIM_SPRITES_START + 83)
#define ANIM_TAG_UNUSED_IMPACT_2            (ANIM_SPRITES_START + 84)
#define ANIM_TAG_UNUSED_RETICLE             (ANIM_SPRITES_START + 85)
#define ANIM_TAG_BREATH                     (ANIM_SPRITES_START + 86)
#define ANIM_TAG_ANGER                      (ANIM_SPRITES_START + 87)
#define ANIM_TAG_UNUSED_SNOWBALL            (ANIM_SPRITES_START + 88)
#define ANIM_TAG_UNUSED_VINE                (ANIM_SPRITES_START + 89)
#define ANIM_TAG_UNUSED_SWORD               (ANIM_SPRITES_START + 90)
#define ANIM_TAG_UNUSED_CLAPPING            (ANIM_SPRITES_START + 91)
#define ANIM_TAG_UNUSED_RED_TUBE            (ANIM_SPRITES_START + 92)
#define ANIM_TAG_AMNESIA                    (ANIM_SPRITES_START + 93)
#define ANIM_TAG_UNUSED_STRING              (ANIM_SPRITES_START + 94)
#define ANIM_TAG_UNUSED_PENCIL              (ANIM_SPRITES_START + 95)
#define ANIM_TAG_UNUSED_PETAL               (ANIM_SPRITES_START + 96)
#define ANIM_TAG_BENT_SPOON                 (ANIM_SPRITES_START + 97)
#define ANIM_TAG_UNUSED_WEB                 (ANIM_SPRITES_START + 98)
#define ANIM_TAG_MILK_BOTTLE                (ANIM_SPRITES_START + 99)
#define ANIM_TAG_COIN                       (ANIM_SPRITES_START + 100)
#define ANIM_TAG_UNUSED_CRACKED_EGG         (ANIM_SPRITES_START + 101)
#define ANIM_TAG_UNUSED_HATCHED_EGG         (ANIM_SPRITES_START + 102)
#define ANIM_TAG_UNUSED_FRESH_EGG           (ANIM_SPRITES_START + 103)
#define ANIM_TAG_UNUSED_FANGS               (ANIM_SPRITES_START + 104)
#define ANIM_TAG_UNUSED_EXPLOSION_2         (ANIM_SPRITES_START + 105)
#define ANIM_TAG_UNUSED_EXPLOSION_3         (ANIM_SPRITES_START + 106)
#define ANIM_TAG_UNUSED_WATER_DROPLET       (ANIM_SPRITES_START + 107)
#define ANIM_TAG_UNUSED_WATER_DROPLET_2     (ANIM_SPRITES_START + 108)
#define ANIM_TAG_UNUSED_SEED                (ANIM_SPRITES_START + 109)
#define ANIM_TAG_UNUSED_SPROUT              (ANIM_SPRITES_START + 110)
#define ANIM_TAG_UNUSED_RED_WAND            (ANIM_SPRITES_START + 111)
#define ANIM_TAG_UNUSED_PURPLE_GREEN_UNK    (ANIM_SPRITES_START + 112)
#define ANIM_TAG_UNUSED_WATER_COLUMN        (ANIM_SPRITES_START + 113)
#define ANIM_TAG_UNUSED_MUD_UNK             (ANIM_SPRITES_START + 114)
#define ANIM_TAG_RAIN_DROPS                 (ANIM_SPRITES_START + 115)
#define ANIM_TAG_UNUSED_FURY_SWIPES         (ANIM_SPRITES_START + 116)
#define ANIM_TAG_UNUSED_VINE_2              (ANIM_SPRITES_START + 117)
#define ANIM_TAG_UNUSED_TEETH               (ANIM_SPRITES_START + 118)
#define ANIM_TAG_UNUSED_BONE                (ANIM_SPRITES_START + 119)
#define ANIM_TAG_UNUSED_WHITE_BAG           (ANIM_SPRITES_START + 120)
#define ANIM_TAG_UNUSED_UNKNOWN             (ANIM_SPRITES_START + 121)
#define ANIM_TAG_UNUSED_PURPLE_CORAL        (ANIM_SPRITES_START + 122)
#define ANIM_TAG_UNUSED_PURPLE_DROPLET      (ANIM_SPRITES_START + 123)
#define ANIM_TAG_UNUSED_SHOCK_2             (ANIM_SPRITES_START + 124)
#define ANIM_TAG_UNUSED_CLOSING_EYE_2       (ANIM_SPRITES_START + 125)
#define ANIM_TAG_UNUSED_METAL_BALL          (ANIM_SPRITES_START + 126)
#define ANIM_TAG_UNUSED_MONSTER_DOLL        (ANIM_SPRITES_START + 127)
#define ANIM_TAG_UNUSED_WHIRLWIND           (ANIM_SPRITES_START + 128)
#define ANIM_TAG_UNUSED_WHIRLWIND_2         (ANIM_SPRITES_START + 129)
#define ANIM_TAG_UNUSED_EXPLOSION_4         (ANIM_SPRITES_START + 130)
#define ANIM_TAG_UNUSED_EXPLOSION_5         (ANIM_SPRITES_START + 131)
#define ANIM_TAG_UNUSED_TONGUE              (ANIM_SPRITES_START + 132)
#define ANIM_TAG_UNUSED_SMOKE               (ANIM_SPRITES_START + 133)
#define ANIM_TAG_UNUSED_SMOKE_2             (ANIM_SPRITES_START + 134)
#define ANIM_TAG_IMPACT                     (ANIM_SPRITES_START + 135)
#define ANIM_TAG_CIRCLE_IMPACT              (ANIM_SPRITES_START + 136)
#define ANIM_TAG_SCRATCH                    (ANIM_SPRITES_START + 137)
#define ANIM_TAG_CUT                        (ANIM_SPRITES_START + 138)
#define ANIM_TAG_SHARP_TEETH                (ANIM_SPRITES_START + 139)
#define ANIM_TAG_RAINBOW_RINGS              (ANIM_SPRITES_START + 140)
#define ANIM_TAG_ICE_CRYSTALS               (ANIM_SPRITES_START + 141)
#define ANIM_TAG_ICE_SPIKES                 (ANIM_SPRITES_START + 142)
#define ANIM_TAG_HANDS_AND_FEET             (ANIM_SPRITES_START + 143)
#define ANIM_TAG_MIST_CLOUD                 (ANIM_SPRITES_START + 144)
#define ANIM_TAG_CLAMP                      (ANIM_SPRITES_START + 145)
#define ANIM_TAG_BUBBLE                     (ANIM_SPRITES_START + 146)
#define ANIM_TAG_ORBS                       (ANIM_SPRITES_START + 147)
#define ANIM_TAG_WATER_IMPACT               (ANIM_SPRITES_START + 148)
#define ANIM_TAG_WATER_ORB                  (ANIM_SPRITES_START + 149)
#define ANIM_TAG_POISON_BUBBLE              (ANIM_SPRITES_START + 150)
#define ANIM_TAG_TOXIC_BUBBLE               (ANIM_SPRITES_START + 151)
#define ANIM_TAG_SPIKES                     (ANIM_SPRITES_START + 152)
#define ANIM_TAG_HORN_HIT_2                 (ANIM_SPRITES_START + 153)
#define ANIM_TAG_AIR_WAVE_2                 (ANIM_SPRITES_START + 154)
#define ANIM_TAG_SMALL_BUBBLES              (ANIM_SPRITES_START + 155)
#define ANIM_TAG_ROUND_SHADOW               (ANIM_SPRITES_START + 156)
#define ANIM_TAG_SUNLIGHT                   (ANIM_SPRITES_START + 157)
#define ANIM_TAG_SPORE                      (ANIM_SPRITES_START + 158)
#define ANIM_TAG_FLOWER                     (ANIM_SPRITES_START + 159)
#define ANIM_TAG_RAZOR_LEAF                 (ANIM_SPRITES_START + 160)
#define ANIM_TAG_NEEDLE                     (ANIM_SPRITES_START + 161)
#define ANIM_TAG_WHIRLWIND_LINES            (ANIM_SPRITES_START + 162)
#define ANIM_TAG_GOLD_RING                  (ANIM_SPRITES_START + 163)
#define ANIM_TAG_PURPLE_RING                (ANIM_SPRITES_START + 164)
#define ANIM_TAG_BLUE_RING                  (ANIM_SPRITES_START + 165)
#define ANIM_TAG_GREEN_LIGHT_WALL           (ANIM_SPRITES_START + 166)
#define ANIM_TAG_BLUE_LIGHT_WALL            (ANIM_SPRITES_START + 167)
#define ANIM_TAG_RED_LIGHT_WALL             (ANIM_SPRITES_START + 168)
#define ANIM_TAG_GRAY_LIGHT_WALL            (ANIM_SPRITES_START + 169)
#define ANIM_TAG_ORANGE_LIGHT_WALL          (ANIM_SPRITES_START + 170)
#define ANIM_TAG_BLACK_BALL_2               (ANIM_SPRITES_START + 171)
#define ANIM_TAG_PURPLE_GAS_CLOUD           (ANIM_SPRITES_START + 172)
#define ANIM_TAG_SPARK_H                    (ANIM_SPRITES_START + 173)
#define ANIM_TAG_YELLOW_STAR                (ANIM_SPRITES_START + 174)
#define ANIM_TAG_LARGE_FRESH_EGG            (ANIM_SPRITES_START + 175)
#define ANIM_TAG_SHADOW_BALL                (ANIM_SPRITES_START + 176)
#define ANIM_TAG_LICK                       (ANIM_SPRITES_START + 177)
#define ANIM_TAG_UNUSED_VOID_LINES          (ANIM_SPRITES_START + 178)
#define ANIM_TAG_STRING                     (ANIM_SPRITES_START + 179)
#define ANIM_TAG_WEB_THREAD                 (ANIM_SPRITES_START + 180)
#define ANIM_TAG_SPIDER_WEB                 (ANIM_SPRITES_START + 181)
#define ANIM_TAG_UNUSED_LIGHTBULB           (ANIM_SPRITES_START + 182)
#define ANIM_TAG_SLASH                      (ANIM_SPRITES_START + 183)
#define ANIM_TAG_FOCUS_ENERGY               (ANIM_SPRITES_START + 184)
#define ANIM_TAG_SPHERE_TO_CUBE             (ANIM_SPRITES_START + 185)
#define ANIM_TAG_TENDRILS                   (ANIM_SPRITES_START + 186)
#define ANIM_TAG_EYE                        (ANIM_SPRITES_START + 187)
#define ANIM_TAG_WHITE_SHADOW               (ANIM_SPRITES_START + 188)
#define ANIM_TAG_TEAL_ALERT                 (ANIM_SPRITES_START + 189)
#define ANIM_TAG_OPENING_EYE                (ANIM_SPRITES_START + 190)
#define ANIM_TAG_ROUND_WHITE_HALO           (ANIM_SPRITES_START + 191)
#define ANIM_TAG_FANG_ATTACK                (ANIM_SPRITES_START + 192)
#define ANIM_TAG_PURPLE_HAND_OUTLINE        (ANIM_SPRITES_START + 193)
#define ANIM_TAG_MOON                       (ANIM_SPRITES_START + 194)
#define ANIM_TAG_GREEN_SPARKLE              (ANIM_SPRITES_START + 195)
#define ANIM_TAG_SPIRAL                     (ANIM_SPRITES_START + 196)
#define ANIM_TAG_SNORE_Z                    (ANIM_SPRITES_START + 197)
#define ANIM_TAG_EXPLOSION                  (ANIM_SPRITES_START + 198)
#define ANIM_TAG_NAIL                       (ANIM_SPRITES_START + 199)
#define ANIM_TAG_GHOSTLY_SPIRIT             (ANIM_SPRITES_START + 200)
#define ANIM_TAG_WARM_ROCK                  (ANIM_SPRITES_START + 201)
#define ANIM_TAG_BREAKING_EGG               (ANIM_SPRITES_START + 202)
#define ANIM_TAG_THIN_RING                  (ANIM_SPRITES_START + 203)
#define ANIM_TAG_UNUSED_PUNCH_IMPACT        (ANIM_SPRITES_START + 204)
#define ANIM_TAG_BELL                       (ANIM_SPRITES_START + 205)
#define ANIM_TAG_MUSIC_NOTES_2              (ANIM_SPRITES_START + 206)
#define ANIM_TAG_SPEED_DUST                 (ANIM_SPRITES_START + 207)
#define ANIM_TAG_TORN_METAL                 (ANIM_SPRITES_START + 208)
#define ANIM_TAG_THOUGHT_BUBBLE             (ANIM_SPRITES_START + 209)
#define ANIM_TAG_MAGENTA_HEART              (ANIM_SPRITES_START + 210)
#define ANIM_TAG_ELECTRIC_ORBS              (ANIM_SPRITES_START + 211)
#define ANIM_TAG_CIRCLE_OF_LIGHT            (ANIM_SPRITES_START + 212)
#define ANIM_TAG_ELECTRICITY                (ANIM_SPRITES_START + 213)
#define ANIM_TAG_FINGER_2                   (ANIM_SPRITES_START + 214)
#define ANIM_TAG_MOVEMENT_WAVES             (ANIM_SPRITES_START + 215)
#define ANIM_TAG_RED_HEART                  (ANIM_SPRITES_START + 216)
#define ANIM_TAG_RED_ORB                    (ANIM_SPRITES_START + 217)
#define ANIM_TAG_EYE_SPARKLE                (ANIM_SPRITES_START + 218)
#define ANIM_TAG_PINK_HEART                 (ANIM_SPRITES_START + 219)
#define ANIM_TAG_ANGEL                      (ANIM_SPRITES_START + 220)
#define ANIM_TAG_DEVIL                      (ANIM_SPRITES_START + 221)
#define ANIM_TAG_SWIPE                      (ANIM_SPRITES_START + 222)
#define ANIM_TAG_ROOTS                      (ANIM_SPRITES_START + 223)
#define ANIM_TAG_ITEM_BAG                   (ANIM_SPRITES_START + 224)
#define ANIM_TAG_JAGGED_MUSIC_NOTE          (ANIM_SPRITES_START + 225)
#define ANIM_TAG_POKEBALL                   (ANIM_SPRITES_START + 226)
#define ANIM_TAG_SPOTLIGHT                  (ANIM_SPRITES_START + 227)
#define ANIM_TAG_LETTER_Z                   (ANIM_SPRITES_START + 228)
#define ANIM_TAG_RAPID_SPIN                 (ANIM_SPRITES_START + 229)
#define ANIM_TAG_TRI_FORCE_TRIANGLE         (ANIM_SPRITES_START + 230)
#define ANIM_TAG_WISP_ORB                   (ANIM_SPRITES_START + 231)
#define ANIM_TAG_WISP_FIRE                  (ANIM_SPRITES_START + 232)
#define ANIM_TAG_GOLD_STARS                 (ANIM_SPRITES_START + 233)
#define ANIM_TAG_ECLIPSING_ORB              (ANIM_SPRITES_START + 234)
#define ANIM_TAG_GRAY_ORB                   (ANIM_SPRITES_START + 235)
#define ANIM_TAG_BLUE_ORB                   (ANIM_SPRITES_START + 236)
#define ANIM_TAG_RED_ORB_2                  (ANIM_SPRITES_START + 237)
#define ANIM_TAG_PINK_PETAL                 (ANIM_SPRITES_START + 238)
#define ANIM_TAG_PAIN_SPLIT                 (ANIM_SPRITES_START + 239)
#define ANIM_TAG_CONFETTI                   (ANIM_SPRITES_START + 240)
#define ANIM_TAG_GREEN_STAR                 (ANIM_SPRITES_START + 241)
#define ANIM_TAG_PINK_CLOUD                 (ANIM_SPRITES_START + 242)
#define ANIM_TAG_SWEAT_DROP                 (ANIM_SPRITES_START + 243)
#define ANIM_TAG_GUARD_RING                 (ANIM_SPRITES_START + 244)
#define ANIM_TAG_PURPLE_SCRATCH             (ANIM_SPRITES_START + 245)
#define ANIM_TAG_PURPLE_SWIPE               (ANIM_SPRITES_START + 246)
#define ANIM_TAG_TAG_HAND                   (ANIM_SPRITES_START + 247)
#define ANIM_TAG_SMALL_RED_EYE              (ANIM_SPRITES_START + 248)
#define ANIM_TAG_HOLLOW_ORB                 (ANIM_SPRITES_START + 249)
#define ANIM_TAG_X_SIGN                     (ANIM_SPRITES_START + 250)
#define ANIM_TAG_BLUEGREEN_ORB              (ANIM_SPRITES_START + 251)
#define ANIM_TAG_PAW_PRINT                  (ANIM_SPRITES_START + 252)
#define ANIM_TAG_PURPLE_FLAME               (ANIM_SPRITES_START + 253)
#define ANIM_TAG_RED_BALL                   (ANIM_SPRITES_START + 254)
#define ANIM_TAG_SMELLINGSALT_EFFECT        (ANIM_SPRITES_START + 255)
#define ANIM_TAG_METEOR                     (ANIM_SPRITES_START + 256)
#define ANIM_TAG_FLAT_ROCK                  (ANIM_SPRITES_START + 257)
#define ANIM_TAG_MAGNIFYING_GLASS           (ANIM_SPRITES_START + 258)
#define ANIM_TAG_BROWN_ORB                  (ANIM_SPRITES_START + 259)
#define ANIM_TAG_METAL_SOUND_WAVES          (ANIM_SPRITES_START + 260)
#define ANIM_TAG_FLYING_DIRT                (ANIM_SPRITES_START + 261)
#define ANIM_TAG_ICICLE_SPEAR               (ANIM_SPRITES_START + 262)
#define ANIM_TAG_HAIL                       (ANIM_SPRITES_START + 263)
#define ANIM_TAG_GLOWY_RED_ORB              (ANIM_SPRITES_START + 264)
#define ANIM_TAG_GLOWY_GREEN_ORB            (ANIM_SPRITES_START + 265)
#define ANIM_TAG_GREEN_SPIKE                (ANIM_SPRITES_START + 266)
#define ANIM_TAG_WHITE_CIRCLE_OF_LIGHT      (ANIM_SPRITES_START + 267)
#define ANIM_TAG_GLOWY_BLUE_ORB             (ANIM_SPRITES_START + 268)
#define ANIM_TAG_UNUSED_RED_BRICK           (ANIM_SPRITES_START + 269)
#define ANIM_TAG_WHITE_FEATHER              (ANIM_SPRITES_START + 270)
#define ANIM_TAG_SPARKLE_6                  (ANIM_SPRITES_START + 271)
#define ANIM_TAG_SPLASH                     (ANIM_SPRITES_START + 272)
#define ANIM_TAG_SWEAT_BEAD                 (ANIM_SPRITES_START + 273)
#define ANIM_TAG_UNUSED_GEM_1               (ANIM_SPRITES_START + 274)
#define ANIM_TAG_UNUSED_GEM_2               (ANIM_SPRITES_START + 275)
#define ANIM_TAG_UNUSED_GEM_3               (ANIM_SPRITES_START + 276)
#define ANIM_TAG_SLAM_HIT_2                 (ANIM_SPRITES_START + 277)
#define ANIM_TAG_RECYCLE                    (ANIM_SPRITES_START + 278)
#define ANIM_TAG_UNUSED_RED_PARTICLES       (ANIM_SPRITES_START + 279)
#define ANIM_TAG_PROTECT                    (ANIM_SPRITES_START + 280)
#define ANIM_TAG_DIRT_MOUND                 (ANIM_SPRITES_START + 281)
#define ANIM_TAG_SHOCK_3                    (ANIM_SPRITES_START + 282)
#define ANIM_TAG_WEATHER_BALL               (ANIM_SPRITES_START + 283)
#define ANIM_TAG_BIRD                       (ANIM_SPRITES_START + 284)
#define ANIM_TAG_CROSS_IMPACT               (ANIM_SPRITES_START + 285)
#define ANIM_TAG_SLASH_2                    (ANIM_SPRITES_START + 286)
#define ANIM_TAG_WHIP_HIT                   (ANIM_SPRITES_START + 287)
#define ANIM_TAG_BLUE_RING_2                (ANIM_SPRITES_START + 288)
#define ANIM_TAG_WHITE_STREAK               (ANIM_SPRITES_START + 289)
#define ANIM_TAG_PURPLE_JAB                 (ANIM_SPRITES_START + 290)

// battlers
#define ANIM_ATTACKER    0
#define ANIM_TARGET      1
#define ANIM_ATK_PARTNER 2
#define ANIM_DEF_PARTNER 3

// stereo panning constants [0-255]
//
//          0
//         .  .
//      .        .
// 192 .          . 63
//     .          .
//      .        .
//         .  .
//          127
//  
#define SOUND_PAN_ATTACKER -64
#define SOUND_PAN_TARGET    63

// move background ids
#define BG_DARK_ 0 // the same as BG_DARK but is unused
#define BG_DARK 1
#define BG_GHOST 2
#define BG_PSYCHIC 3
#define BG_IMPACT_OPPONENT 4
#define BG_IMPACT_PLAYER 5
#define BG_IMPACT_CONTESTS 6
#define BG_DRILL 7
#define BG_DRILL_CONTESTS 8
#define BG_HIGHSPEED_OPPONENT 9
#define BG_HIGHSPEED_PLAYER 10
#define BG_THUNDER 11
#define BG_GUILLOTINE_OPPONENT 12
#define BG_GUILLOTINE_PLAYER 13
#define BG_GUILLOTINE_CONTESTS 14
#define BG_ICE 15
#define BG_COSMIC 16
#define BG_SEISMICTOSS_SKUUPPERCUT 17
#define BG_FLYING 18
#define BG_FLYING_CONTESTS 19
#define BG_AURORABEAM 20
#define BG_FISSURE 21
#define BG_BUG_OPPONENT 22
#define BG_BUG_PLAYER 23
#define BG_SOLARBEAM_OPPONENT 24
#define BG_SOLARBEAM_PLAYER 25
#define BG_SOLARBEAM_CONTESTS 26

// table ids for general animations
#define B_ANIM_CASTFORM_CHANGE          0x0
#define B_ANIM_STATS_CHANGE             0x1
#define B_ANIM_SUBSTITUTE_FADE          0x2
#define B_ANIM_SUBSTITUTE_APPEAR        0x3
#define B_ANIM_POKEBLOCK_THROW          0x4
#define B_ANIM_ITEM_KNOCKOFF            0x5
#define B_ANIM_TURN_TRAP                0x6
#define B_ANIM_ITEM_EFFECT              0x7
#define B_ANIM_SMOKEBALL_ESCAPE         0x8
#define B_ANIM_HANGED_ON                0x9
#define B_ANIM_RAIN_CONTINUES           0xA
#define B_ANIM_SUN_CONTINUES            0xB
#define B_ANIM_SANDSTORM_CONTINUES      0xC
#define B_ANIM_HAIL_CONTINUES           0xD
#define B_ANIM_LEECH_SEED_DRAIN         0xE
#define B_ANIM_MON_HIT                  0xF
#define B_ANIM_ITEM_STEAL               0x10
#define B_ANIM_SNATCH_MOVE              0x11
#define B_ANIM_FUTURE_SIGHT_HIT         0x12
#define B_ANIM_DOOM_DESIRE_HIT          0x13
#define B_ANIM_FOCUS_PUNCH_SETUP        0x14
#define B_ANIM_INGRAIN_HEAL             0x15
#define B_ANIM_WISH_HEAL                0x16
#define B_ANIM_MEGA_EVOLUTION           0x17

// special animations table
#define B_ANIM_LVL_UP                   0x0
#define B_ANIM_SWITCH_OUT_PLAYER_MON    0x1
#define B_ANIM_SWITCH_OUT_OPPONENT_MON  0x2
#define B_ANIM_BALL_THROW               0x3
#define B_ANIM_SAFARI_BALL_THROW        0x4
#define B_ANIM_SUBSTITUTE_TO_MON        0x5
#define B_ANIM_MON_TO_SUBSTITUTE        0x6

// status animation table
#define B_ANIM_STATUS_PSN               0x0
#define B_ANIM_STATUS_CONFUSION         0x1
#define B_ANIM_STATUS_BRN               0x2
#define B_ANIM_STATUS_INFATUATION       0x3
#define B_ANIM_STATUS_SLP               0x4
#define B_ANIM_STATUS_PRZ               0x5
#define B_ANIM_STATUS_FRZ               0x6
#define B_ANIM_STATUS_CURSED            0x7
#define B_ANIM_STATUS_NIGHTMARE         0x8
#define B_ANIM_STATUS_WRAPPED           0x9 // does not actually exist

// Most tasks return a value to gBattleAnimArgs[7].
#define ARG_RET_ID 0x7

// Trapping Wrap-like moves end turn animation.
#define TRAP_ANIM_BIND 0
#define TRAP_ANIM_WRAP 0
#define TRAP_ANIM_FIRE_SPIN 1
#define TRAP_ANIM_WHIRLPOOL 2
#define TRAP_ANIM_CLAMP 3
#define TRAP_ANIM_SAND_TOMB 4

// Weather defines for battle animation scripts.
#define ANIM_WEATHER_NONE 0
#define ANIM_WEATHER_SUN 1
#define ANIM_WEATHER_RAIN 2
#define ANIM_WEATHER_SANDSTORM 3
#define ANIM_WEATHER_HAIL 4

// Battle mon back animations.
#define BACK_ANIM_NONE                         0x00 
#define BACK_ANIM_H_SLIDE_QUICK                0x01 
#define BACK_ANIM_H_SLIDE                      0x02 
#define BACK_ANIM_H_SLIDE_WITH_V_COMPRESS_1    0x03 
#define BACK_ANIM_H_SLIDE_WITH_V_COMPRESS_2    0x04 
#define BACK_ANIM_SHRINK_GROW_1                0x05 
#define BACK_ANIM_GROW_1                       0x06 
#define BACK_ANIM_CIRCLE_MOVE_COUNTERCLOCKWISE 0x07 
#define BACK_ANIM_HORIZONTAL_SHAKE             0x08 
#define BACK_ANIM_VERTICAL_SHAKE               0x09 
#define BACK_ANIM_V_SHAKE_WITH_H_SLIDE         0x0a 
#define BACK_ANIM_VERTICAL_STRETCH             0x0b 
#define BACK_ANIM_HORIZONTAL_STRETCH           0x0c 
#define BACK_ANIM_GROW_2                       0x0d 
#define BACK_ANIM_V_SHAKE_WITH_PAUSE           0x0e 
#define BACK_ANIM_CIRCLE_MOVE_CLOCKWISE        0x0f 
#define BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL  0x10 
#define BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE  0x11 
#define BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE    0x12 
#define BACK_ANIM_DIP_RIGHT_SIDE               0x13 
#define BACK_ANIM_SHRINK_GROW_2                0x14 
#define BACK_ANIM_JOLT_RIGHT                   0x15 
#define BACK_ANIM_FLASH_YELLOW_WITH_SHAKE      0x16 
#define BACK_ANIM_FADE_RED_WITH_SHAKE          0x17 
#define BACK_ANIM_FADE_GREEN_WITH_SHAKE        0x18 
#define BACK_ANIM_FADE_BLUE_WITH_SHAKE         0x19 


#endif // GUARD_CONSTANTS_BATTLE_ANIM_H
