#ifndef GUARD_CONSTANTS_SPRITE_TAGS_H
#define GUARD_CONSTANTS_SPRITE_TAGS_H

#define TAG_BERRY_CRUSH_CRUSHER_BASE  1
#define TAG_PAL_BERRY_CRUSH_EFFECT    2
#define TAG_GFX_BERRY_CRUSH_IMPACT    2
#define TAG_GFX_BERRY_CRUSH_SPARKLE   3
#define TAG_BERRY_CRUSH_TIMER_DIGITS  4
#define TAG_BERRY_CRUSH_PLAYER1_BERRY 5
#define TAG_BERRY_CRUSH_PLAYER2_BERRY 6
#define TAG_BERRY_CRUSH_PLAYER3_BERRY 7
#define TAG_BERRY_CRUSH_PLAYER4_BERRY 8
#define TAG_BERRY_CRUSH_PLAYER5_BERRY 9

#define TAG_FACTORY_BALL_GRAY                   100
#define TAG_GFX_FACTORY_ARROW                   101
#define TAG_PAL_FACTORY_BALL_SELECTED           101
#define TAG_GFX_FACTORY_MENU_HIGHLIGHT_LEFT     102
#define TAG_PAL_FACTORY_INTERFACE               102
#define TAG_GFX_FACTORY_MENU_HIGHLIGHT_RIGHT    103
#define TAG_PAL_FACTORY_MON_PIC_BG              103
#define TAG_GFX_FACTORY_ACTION_BOX_LEFT         104
#define TAG_GFX_FACTORY_ACTION_BOX_RIGHT        105
#define TAG_GFX_FACTORY_ACTION_HIGHLIGHT_LEFT   106
#define TAG_GFX_FACTORY_ACTION_HIGHLIGHT_MIDDLE 107
#define TAG_GFX_FACTORY_ACTION_HIGHLIGHT_RIGHT  108
#define TAG_GFX_FACTORY_MON_PIC_BG_ANIM         109

#define TAG_JUDGEMENT_ICON                         1000

#define TAG_PYRAMID_BAG_SCROLL_ARROW               2910

#define TAG_BERRY_CRUSH_COUNTDOWN                  4096
#define TAG_PAL_FLDEFF_CUT_GRASS                   4096
#define TAG_PAL_FLDEFF_RECORD_MIX_LIGHTS           4096
#define TAG_PAL_FLDEFF_SECRET_POWER_TREE           4099
#define TAG_PAL_FLDEFF_GENERAL_0                   4100
#define TAG_PAL_FLDEFF_GENERAL_1                   4101
#define TAG_PAL_NEW_GAME_BIRCH                     4102
#define TAG_PAL_FLDEFF_POKEBALL_GLOW               4103
#define TAG_PAL_FLDEFF_SECRET_POWER_PLANT          4104
#define TAG_PAL_FLDEFF_POKEBALL                    4105
#define TAG_UNUSED_RIVAL_TRANSITION                4106
#define TAG_PAL_FLDEFF_ASH                         4109
#define TAG_PAL_FLDEFF_SAND_PILLAR                 4110
#define TAG_PAL_FLDEFF_SMALL_SPARKLE               4111
#define TAG_PAL_FLDEFF_HOF_MONITOR                 4112
#define TAG_PAL_FLDEFF_UNKNOWN                     4113

#define TAG_PYRAMID_BAG                            4132
#define TAG_PYRAMID_BAG_ITEM_ICON                  4133
#define TAG_PYRAMID_BAG_ITEM_ICON_ALT              4134

#define TAG_VS_LETTERS                             10000

// Battle anim sprite tags start at 10000 and must be
// subtracted of 10000 to account for the true index.
#define ANIM_SPRITES_START                         10000
#define GET_TRUE_SPRITE_INDEX(i) ((i - ANIM_SPRITES_START))
#define TAG_BATTLE_ANIM_BONE                       10000
#define TAG_BATTLE_ANIM_SPARK                      10001
#define TAG_BATTLE_ANIM_PENCIL                     10002
#define TAG_BATTLE_ANIM_AIR_WAVE                   10003
#define TAG_BATTLE_ANIM_ORB                        10004
#define TAG_BATTLE_ANIM_SWORD                      10005
#define TAG_BATTLE_ANIM_SEED                       10006
#define TAG_BATTLE_ANIM_EXPLOSION_6                10007
#define TAG_BATTLE_ANIM_PINK_ORB                   10008 // unused
#define TAG_BATTLE_ANIM_GUST                       10009
#define TAG_BATTLE_ANIM_ICE_CUBE                   10010
#define TAG_BATTLE_ANIM_SPARK_2                    10011
#define TAG_BATTLE_ANIM_ORANGE                     10012 // unused
#define TAG_BATTLE_ANIM_YELLOW_BALL                10013
#define TAG_BATTLE_ANIM_LOCK_ON                    10014
#define TAG_BATTLE_ANIM_TIED_BAG                   10015
#define TAG_BATTLE_ANIM_BLACK_SMOKE                10016
#define TAG_BATTLE_ANIM_BLACK_BALL                 10017
#define TAG_BATTLE_ANIM_CONVERSION                 10018
#define TAG_BATTLE_ANIM_GLASS                      10019 // unused
#define TAG_BATTLE_ANIM_HORN_HIT                   10020
#define TAG_BATTLE_ANIM_HIT                        10021
#define TAG_BATTLE_ANIM_HIT_2                      10022
#define TAG_BATTLE_ANIM_BLUE_SHARDS                10023 // unused
#define TAG_BATTLE_ANIM_CLOSING_EYE                10024 // unused
#define TAG_BATTLE_ANIM_WAVING_HAND                10025 // unused
#define TAG_BATTLE_ANIM_HIT_DUPLICATE              10026 // unused
#define TAG_BATTLE_ANIM_LEER                       10027
#define TAG_BATTLE_ANIM_BLUE_BURST                 10028 // unused
#define TAG_BATTLE_ANIM_SMALL_EMBER                10029
#define TAG_BATTLE_ANIM_GRAY_SMOKE                 10030
#define TAG_BATTLE_ANIM_BLUE_STAR                  10031
#define TAG_BATTLE_ANIM_BUBBLE_BURST               10032
#define TAG_BATTLE_ANIM_FIRE                       10033
#define TAG_BATTLE_ANIM_SPINNING_FIRE              10034 // unused
#define TAG_BATTLE_ANIM_FIRE_PLUME                 10035
#define TAG_BATTLE_ANIM_LIGHTNING_2                10036 // unused
#define TAG_BATTLE_ANIM_LIGHTNING                  10037
#define TAG_BATTLE_ANIM_CLAW_SLASH_2               10038 // unused
#define TAG_BATTLE_ANIM_CLAW_SLASH                 10039
#define TAG_BATTLE_ANIM_SCRATCH_3                  10040 // unused
#define TAG_BATTLE_ANIM_SCRATCH_2                  10041 // unused
#define TAG_BATTLE_ANIM_BUBBLE_BURST_2             10042 // unused
#define TAG_BATTLE_ANIM_ICE_CHUNK                  10043
#define TAG_BATTLE_ANIM_GLASS_2                    10044 // unused
#define TAG_BATTLE_ANIM_PINK_HEART_2               10045 // unused
#define TAG_BATTLE_ANIM_SAP_DRIP                   10046 // unused
#define TAG_BATTLE_ANIM_SAP_DRIP_2                 10047 // unused
#define TAG_BATTLE_ANIM_SPARKLE_1                  10048
#define TAG_BATTLE_ANIM_SPARKLE_2                  10049
#define TAG_BATTLE_ANIM_HUMANOID_FOOT              10050
#define TAG_BATTLE_ANIM_MONSTER_FOOT               10051
#define TAG_BATTLE_ANIM_HUMANOID_HAND              10052 // unused
#define TAG_BATTLE_ANIM_NOISE_LINE                 10053
#define TAG_BATTLE_ANIM_YELLOW_UNK                 10054 // unused
#define TAG_BATTLE_ANIM_RED_FIST                   10055 // unused
#define TAG_BATTLE_ANIM_SLAM_HIT                   10056
#define TAG_BATTLE_ANIM_RING                       10057 // unused
#define TAG_BATTLE_ANIM_ROCKS                      10058
#define TAG_BATTLE_ANIM_Z                          10059 // unused
#define TAG_BATTLE_ANIM_YELLOW_UNK_2               10060 // unused
#define TAG_BATTLE_ANIM_AIR_SLASH                  10061 // unused
#define TAG_BATTLE_ANIM_SPINNING_GREEN_ORBS        10062 // unused
#define TAG_BATTLE_ANIM_LEAF                       10063
#define TAG_BATTLE_ANIM_FINGER                     10064
#define TAG_BATTLE_ANIM_POISON_POWDER              10065
#define TAG_BATTLE_ANIM_BROWN_TRIANGLE             10066 // unused
#define TAG_BATTLE_ANIM_SLEEP_POWDER               10067
#define TAG_BATTLE_ANIM_STUN_SPORE                 10068
#define TAG_BATTLE_ANIM_POWDER                     10069 // unused
#define TAG_BATTLE_ANIM_SPARKLE_3                  10070
#define TAG_BATTLE_ANIM_SPARKLE_4                  10071
#define TAG_BATTLE_ANIM_MUSIC_NOTES                10072
#define TAG_BATTLE_ANIM_DUCK                       10073
#define TAG_BATTLE_ANIM_MUD_SAND                   10074
#define TAG_BATTLE_ANIM_ALERT                      10075
#define TAG_BATTLE_ANIM_BLUE_FLAMES                10076 // unused
#define TAG_BATTLE_ANIM_BLUE_FLAMES_2              10077 // unused
#define TAG_BATTLE_ANIM_SHOCK_4                    10078 // unused
#define TAG_BATTLE_ANIM_SHOCK                      10079
#define TAG_BATTLE_ANIM_BELL_2                     10080 // unused
#define TAG_BATTLE_ANIM_PINK_GLOVE                 10081 // unused
#define TAG_BATTLE_ANIM_BLUE_LINES                 10082 // unused
#define TAG_BATTLE_ANIM_IMPACT_3                   10083 // unused
#define TAG_BATTLE_ANIM_IMPACT_2                   10084 // unused
#define TAG_BATTLE_ANIM_RETICLE                    10085 // unused
#define TAG_BATTLE_ANIM_BREATH                     10086
#define TAG_BATTLE_ANIM_ANGER                      10087
#define TAG_BATTLE_ANIM_SNOWBALL                   10088 // unused
#define TAG_BATTLE_ANIM_VINE                       10089 // unused
#define TAG_BATTLE_ANIM_SWORD_2                    10090 // unused
#define TAG_BATTLE_ANIM_CLAPPING                   10091 // unused
#define TAG_BATTLE_ANIM_RED_TUBE                   10092 // unused
#define TAG_BATTLE_ANIM_AMNESIA                    10093
#define TAG_BATTLE_ANIM_STRING_2                   10094 // unused
#define TAG_BATTLE_ANIM_PENCIL_2                   10095 // unused
#define TAG_BATTLE_ANIM_PETAL                      10096 // unused
#define TAG_BATTLE_ANIM_BENT_SPOON                 10097
#define TAG_BATTLE_ANIM_WEB                        10098 // unused
#define TAG_BATTLE_ANIM_MILK_BOTTLE                10099
#define TAG_BATTLE_ANIM_COIN                       10100
#define TAG_BATTLE_ANIM_CRACKED_EGG                10101 // unused
#define TAG_BATTLE_ANIM_HATCHED_EGG                10102 // unused
#define TAG_BATTLE_ANIM_FRESH_EGG                  10103 // unused
#define TAG_BATTLE_ANIM_FANGS                      10104 // unused
#define TAG_BATTLE_ANIM_EXPLOSION_2                10105 // unused
#define TAG_BATTLE_ANIM_EXPLOSION_3                10106 // unused
#define TAG_BATTLE_ANIM_WATER_DROPLET              10107 // unused
#define TAG_BATTLE_ANIM_WATER_DROPLET_2            10108 // unused
#define TAG_BATTLE_ANIM_SEED_2                     10109 // unused
#define TAG_BATTLE_ANIM_SPROUT                     10110 // unused
#define TAG_BATTLE_ANIM_RED_WAND                   10111 // unused
#define TAG_BATTLE_ANIM_PURPLE_GREEN_UNK           10112 // unused
#define TAG_BATTLE_ANIM_WATER_COLUMN               10113 // unused
#define TAG_BATTLE_ANIM_MUD_UNK                    10114 // unused
#define TAG_BATTLE_ANIM_RAIN_DROPS                 10115
#define TAG_BATTLE_ANIM_FURY_SWIPES                10116 // unused
#define TAG_BATTLE_ANIM_VINE_2                     10117 // unused
#define TAG_BATTLE_ANIM_TEETH                      10118 // unused
#define TAG_BATTLE_ANIM_BONE_2                     10119 // unused
#define TAG_BATTLE_ANIM_WHITE_BAG                  10120 // unused
#define TAG_BATTLE_ANIM_UNKNOWN                    10121 // unused
#define TAG_BATTLE_ANIM_PURPLE_CORAL               10122 // unused
#define TAG_BATTLE_ANIM_PURPLE_DROPLET             10123 // unused
#define TAG_BATTLE_ANIM_SHOCK_2                    10124 // unused
#define TAG_BATTLE_ANIM_CLOSING_EYE_2              10125 // unused
#define TAG_BATTLE_ANIM_METAL_BALL                 10126 // unused
#define TAG_BATTLE_ANIM_MONSTER_DOLL               10127 // unused
#define TAG_BATTLE_ANIM_WHIRLWIND                  10128 // unused
#define TAG_BATTLE_ANIM_WHIRLWIND_2                10129 // unused
#define TAG_BATTLE_ANIM_EXPLOSION_4                10130 // unused
#define TAG_BATTLE_ANIM_EXPLOSION_5                10131 // unused
#define TAG_BATTLE_ANIM_TONGUE                     10132 // unused
#define TAG_BATTLE_ANIM_SMOKE                      10133 // unused
#define TAG_BATTLE_ANIM_SMOKE_2                    10134 // unused
#define TAG_BATTLE_ANIM_IMPACT                     10135
#define TAG_BATTLE_ANIM_CIRCLE_IMPACT              10136
#define TAG_BATTLE_ANIM_SCRATCH                    10137
#define TAG_BATTLE_ANIM_CUT                        10138
#define TAG_BATTLE_ANIM_SHARP_TEETH                10139
#define TAG_BATTLE_ANIM_RAINBOW_RINGS              10140
#define TAG_BATTLE_ANIM_ICE_CRYSTALS               10141
#define TAG_BATTLE_ANIM_ICE_SPIKES                 10142
#define TAG_BATTLE_ANIM_HANDS_AND_FEET             10143
#define TAG_BATTLE_ANIM_MIST_CLOUD                 10144
#define TAG_BATTLE_ANIM_CLAMP                      10145
#define TAG_BATTLE_ANIM_BUBBLE                     10146
#define TAG_BATTLE_ANIM_ORBS                       10147
#define TAG_BATTLE_ANIM_WATER_IMPACT               10148
#define TAG_BATTLE_ANIM_WATER_ORB                  10149
#define TAG_BATTLE_ANIM_POISON_BUBBLE              10150
#define TAG_BATTLE_ANIM_TOXIC_BUBBLE               10151
#define TAG_BATTLE_ANIM_SPIKES                     10152
#define TAG_BATTLE_ANIM_HORN_HIT_2                 10153
#define TAG_BATTLE_ANIM_AIR_WAVE_2                 10154
#define TAG_BATTLE_ANIM_SMALL_BUBBLES              10155
#define TAG_BATTLE_ANIM_ROUND_SHADOW               10156
#define TAG_BATTLE_ANIM_SUNLIGHT                   10157
#define TAG_BATTLE_ANIM_SPORE                      10158
#define TAG_BATTLE_ANIM_FLOWER                     10159
#define TAG_BATTLE_ANIM_RAZOR_LEAF                 10160
#define TAG_BATTLE_ANIM_NEEDLE                     10161
#define TAG_BATTLE_ANIM_WHIRLWIND_LINES            10162
#define TAG_BATTLE_ANIM_GOLD_RING                  10163
#define TAG_BATTLE_ANIM_PURPLE_RING                10164
#define TAG_BATTLE_ANIM_BLUE_RING                  10165
#define TAG_BATTLE_ANIM_GREEN_LIGHT_WALL           10166
#define TAG_BATTLE_ANIM_BLUE_LIGHT_WALL            10167
#define TAG_BATTLE_ANIM_RED_LIGHT_WALL             10168
#define TAG_BATTLE_ANIM_GRAY_LIGHT_WALL            10169
#define TAG_BATTLE_ANIM_ORANGE_LIGHT_WALL          10170
#define TAG_BATTLE_ANIM_BLACK_BALL_2               10171
#define TAG_BATTLE_ANIM_PURPLE_GAS_CLOUD           10172
#define TAG_BATTLE_ANIM_SPARK_H                    10173
#define TAG_BATTLE_ANIM_YELLOW_STAR                10174
#define TAG_BATTLE_ANIM_LARGE_FRESH_EGG            10175
#define TAG_BATTLE_ANIM_SHADOW_BALL                10176
#define TAG_BATTLE_ANIM_LICK                       10177
#define TAG_BATTLE_ANIM_VOID_LINES                 10178
#define TAG_BATTLE_ANIM_STRING                     10179
#define TAG_BATTLE_ANIM_WEB_THREAD                 10180
#define TAG_BATTLE_ANIM_SPIDER_WEB                 10181
#define TAG_BATTLE_ANIM_LIGHTBULB                  10182 // unused
#define TAG_BATTLE_ANIM_SLASH                      10183
#define TAG_BATTLE_ANIM_FOCUS_ENERGY               10184
#define TAG_BATTLE_ANIM_SPHERE_TO_CUBE             10185
#define TAG_BATTLE_ANIM_TENDRILS                   10186
#define TAG_BATTLE_ANIM_EYE                        10187
#define TAG_BATTLE_ANIM_WHITE_SHADOW               10188
#define TAG_BATTLE_ANIM_TEAL_ALERT                 10189
#define TAG_BATTLE_ANIM_OPENING_EYE                10190
#define TAG_BATTLE_ANIM_ROUND_WHITE_HALO           10191
#define TAG_BATTLE_ANIM_FANG_ATTACK                10192
#define TAG_BATTLE_ANIM_PURPLE_HAND_OUTLINE        10193
#define TAG_BATTLE_ANIM_MOON                       10194
#define TAG_BATTLE_ANIM_GREEN_SPARKLE              10195
#define TAG_BATTLE_ANIM_SPIRAL                     10196
#define TAG_BATTLE_ANIM_SNORE_Z                    10197
#define TAG_BATTLE_ANIM_EXPLOSION                  10198
#define TAG_BATTLE_ANIM_NAIL                       10199
#define TAG_BATTLE_ANIM_GHOSTLY_SPIRIT             10200
#define TAG_BATTLE_ANIM_WARM_ROCK                  10201
#define TAG_BATTLE_ANIM_BREAKING_EGG               10202
#define TAG_BATTLE_ANIM_THIN_RING                  10203
#define TAG_BATTLE_ANIM_PUNCH_IMPACT               10204 // unused
#define TAG_BATTLE_ANIM_BELL                       10205
#define TAG_BATTLE_ANIM_MUSIC_NOTES_2              10206
#define TAG_BATTLE_ANIM_SPEED_DUST                 10207
#define TAG_BATTLE_ANIM_TORN_METAL                 10208
#define TAG_BATTLE_ANIM_THOUGHT_BUBBLE             10209
#define TAG_BATTLE_ANIM_MAGENTA_HEART              10210
#define TAG_BATTLE_ANIM_ELECTRIC_ORBS              10211
#define TAG_BATTLE_ANIM_CIRCLE_OF_LIGHT            10212
#define TAG_BATTLE_ANIM_ELECTRICITY                10213
#define TAG_BATTLE_ANIM_FINGER_2                   10214
#define TAG_BATTLE_ANIM_MOVEMENT_WAVES             10215
#define TAG_BATTLE_ANIM_RED_HEART                  10216
#define TAG_BATTLE_ANIM_RED_ORB                    10217
#define TAG_BATTLE_ANIM_EYE_SPARKLE                10218
#define TAG_BATTLE_ANIM_PINK_HEART                 10219
#define TAG_BATTLE_ANIM_ANGEL                      10220
#define TAG_BATTLE_ANIM_DEVIL                      10221
#define TAG_BATTLE_ANIM_SWIPE                      10222
#define TAG_BATTLE_ANIM_ROOTS                      10223
#define TAG_BATTLE_ANIM_ITEM_BAG                   10224
#define TAG_BATTLE_ANIM_JAGGED_MUSIC_NOTE          10225
#define TAG_BATTLE_ANIM_POKEBALL                   10226
#define TAG_BATTLE_ANIM_SPOTLIGHT                  10227
#define TAG_BATTLE_ANIM_LETTER_Z                   10228
#define TAG_BATTLE_ANIM_RAPID_SPIN                 10229
#define TAG_BATTLE_ANIM_TRI_ATTACK_TRIANGLE        10230
#define TAG_BATTLE_ANIM_WISP_ORB                   10231
#define TAG_BATTLE_ANIM_WISP_FIRE                  10232
#define TAG_BATTLE_ANIM_GOLD_STARS                 10233
#define TAG_BATTLE_ANIM_ECLIPSING_ORB              10234
#define TAG_BATTLE_ANIM_GRAY_ORB                   10235
#define TAG_BATTLE_ANIM_BLUE_ORB                   10236
#define TAG_BATTLE_ANIM_RED_ORB_2                  10237
#define TAG_BATTLE_ANIM_PINK_PETAL                 10238
#define TAG_BATTLE_ANIM_PAIN_SPLIT                 10239
#define TAG_BATTLE_ANIM_CONFETTI                   10240
#define TAG_BATTLE_ANIM_GREEN_STAR                 10241
#define TAG_BATTLE_ANIM_PINK_CLOUD                 10242
#define TAG_BATTLE_ANIM_SWEAT_DROP                 10243
#define TAG_BATTLE_ANIM_GUARD_RING                 10244
#define TAG_BATTLE_ANIM_PURPLE_SCRATCH             10245
#define TAG_BATTLE_ANIM_PURPLE_SWIPE               10246
#define TAG_BATTLE_ANIM_TAG_HAND                   10247
#define TAG_BATTLE_ANIM_SMALL_RED_EYE              10248
#define TAG_BATTLE_ANIM_HOLLOW_ORB                 10249
#define TAG_BATTLE_ANIM_X_SIGN                     10250
#define TAG_BATTLE_ANIM_BLUEGREEN_ORB              10251
#define TAG_BATTLE_ANIM_PAW_PRINT                  10252
#define TAG_BATTLE_ANIM_PURPLE_FLAME               10253
#define TAG_BATTLE_ANIM_RED_BALL                   10254
#define TAG_BATTLE_ANIM_SMELLINGSALT_EFFECT        10255
#define TAG_BATTLE_ANIM_METEOR                     10256
#define TAG_BATTLE_ANIM_FLAT_ROCK                  10257
#define TAG_BATTLE_ANIM_MAGNIFYING_GLASS           10258
#define TAG_BATTLE_ANIM_BROWN_ORB                  10259
#define TAG_BATTLE_ANIM_METAL_SOUND_WAVES          10260
#define TAG_BATTLE_ANIM_FLYING_DIRT                10261
#define TAG_BATTLE_ANIM_ICICLE_SPEAR               10262
#define TAG_BATTLE_ANIM_HAIL                       10263
#define TAG_BATTLE_ANIM_GLOWY_RED_ORB              10264
#define TAG_BATTLE_ANIM_GLOWY_GREEN_ORB            10265
#define TAG_BATTLE_ANIM_GREEN_SPIKE                10266
#define TAG_BATTLE_ANIM_WHITE_CIRCLE_OF_LIGHT      10267
#define TAG_BATTLE_ANIM_GLOWY_BLUE_ORB             10268
#define TAG_BATTLE_ANIM_POKEBLOCK                  10269
#define TAG_BATTLE_ANIM_WHITE_FEATHER              10270
#define TAG_BATTLE_ANIM_SPARKLE_6                  10271
#define TAG_BATTLE_ANIM_SPLASH                     10272
#define TAG_BATTLE_ANIM_SWEAT_BEAD                 10273
#define TAG_BATTLE_ANIM_GEM_1                      10274 // unused
#define TAG_BATTLE_ANIM_GEM_2                      10275 // unused
#define TAG_BATTLE_ANIM_GEM_3                      10276 // unused
#define TAG_BATTLE_ANIM_SLAM_HIT_2                 10277
#define TAG_BATTLE_ANIM_RECYCLE                    10278
#define TAG_BATTLE_ANIM_RED_PARTICLES              10279 // unused
#define TAG_BATTLE_ANIM_PROTECT                    10280
#define TAG_BATTLE_ANIM_DIRT_MOUND                 10281
#define TAG_BATTLE_ANIM_SHOCK_3                    10282
#define TAG_BATTLE_ANIM_WEATHER_BALL               10283
#define TAG_BATTLE_ANIM_BIRD                       10284
#define TAG_BATTLE_ANIM_CROSS_IMPACT               10285
#define TAG_BATTLE_ANIM_SLASH_2                    10286
#define TAG_BATTLE_ANIM_WHIP_HIT                   10287
#define TAG_BATTLE_ANIM_BLUE_RING_2                10288

#define TAG_FRONTIER_TRANSITION_CIRCLES    11920

#define TAG_PAL_BERRY_BLENDER_PLAYER_ARROW 12312
#define TAG_GFX_BERRY_BLENDER_COUNTDOWN    12345
#define TAG_GFX_BERRY_BLENDER_START        12346

#define TAG_GFX_BERRY_BLENDER_PARTICLES    23456

#define TAG_GFX_BERRY_BLENDER_PLAYER_ARROW 46545
#define TAG_PAL_BERRY_BLENDER_MISC         46546

#define TAG_GFX_BERRY_BLENDER_SCORE        48888

#define TAG_BATTLE_ANIM_SMOKESCREEN_IMPACT 55019
#define TAG_PARTICLES_POKEBALL    55020
#define TAG_PARTICLES_GREATBALL   55021
#define TAG_PARTICLES_SAFARIBALL  55022
#define TAG_PARTICLES_ULTRABALL   55023
#define TAG_PARTICLES_MASTERBALL  55024
#define TAG_PARTICLES_NETBALL     55025
#define TAG_PARTICLES_DIVEBALL    55026
#define TAG_PARTICLES_NESTBALL    55027
#define TAG_PARTICLES_REPEATBALL  55028
#define TAG_PARTICLES_TIMERBALL   55029
#define TAG_PARTICLES_LUXURYBALL  55030
#define TAG_PARTICLES_PREMIERBALL 55031

#define TAG_GFX_HEALTHBOX_PLAYER1    55039
#define TAG_PAL_HEALTHBOX            55039
#define TAG_GFX_HEALTHBOX_PLAYER2    55040
#define TAG_GFX_HEALTHBOX_OPPONENT1  55041
#define TAG_GFX_HEALTHBOX_OPPONENT2  55042

#define TAG_GFX_HEALTHBAR_PLAYER1    55044
#define TAG_PAL_HEALTHBAR            55044
#define TAG_GFX_HEALTHBAR_OPPONENT1  55045
#define TAG_GFX_HEALTHBAR_PLAYER2    55046
#define TAG_GFX_HEALTHBAR_OPPONENT2  55047

#define TAG_GFX_HEALTHBOX_SAFARI     55051
#define TAG_GFX_STATUS_SUMMARY_BAR   55052

#define TAG_PAL_STATUS_SUMMARY_BAR   55056

#define TAG_PAL_STATUS_SUMMARY_BALLS 55058

#define TAG_GFX_STATUS_SUMMARY_BALLS 55060


#define TAG_BATTLE_ANIM_ENEMY_SHADOW_TILES 55129
#define TAG_MON_ICON_LVLUP_BOX             55130

#define TAG_NONE 0xFFFF

#endif //GUARD_CONSTANTS_SPRITE_TAGS_H
