#ifndef GUARD_CONSTANTS_TV_H
#define GUARD_CONSTANTS_TV_H

#define POKENEWS_NONE         0
#define POKENEWS_SLATEPORT    1
#define POKENEWS_GAME_CORNER  2
#define POKENEWS_LILYCOVE     3
#define POKENEWS_BLENDMASTER  4
#define NUM_POKENEWS_TYPES    4 // Excludes NONE

#define POKENEWS_STATE_INACTIVE 0
#define POKENEWS_STATE_UPCOMING 1
#define POKENEWS_STATE_ACTIVE   2

// Number of days to count down until the news event occurs.
// Nothing is aired on TV the first day
#define POKENEWS_COUNTDOWN 4

// TV shows are categorized as being in one of 3 groups
// - TVGROUP_NORMAL, TV shows that can appear without Record Mixing
// - TVGROUP_RECORD_MIX, TV shows that can only appear via Record Mixing
// - TVGROUP_OUTBREAK, just contains TVSHOW_MASS_OUTBREAK
// Each group was allotted 20 spaces arbitrarily, though none use all 20

#define TVSHOW_OFF_AIR                              0

// TVGROUP_NORMAL
#define TVGROUP_NORMAL_START                        1
#define TVSHOW_FAN_CLUB_LETTER                      1
#define TVSHOW_RECENT_HAPPENINGS                    2
#define TVSHOW_PKMN_FAN_CLUB_OPINIONS               3
#define TVSHOW_DUMMY                                4
#define TVSHOW_NAME_RATER_SHOW                      5
#define TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE        6
#define TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE   7
#define TVSHOW_CONTEST_LIVE_UPDATES                 8
#define TVSHOW_3_CHEERS_FOR_POKEBLOCKS              9
#define TVSHOW_BATTLE_UPDATE                        10
#define TVSHOW_FAN_CLUB_SPECIAL                     11
#define TVSHOW_LILYCOVE_CONTEST_LADY                12
//
#define TVGROUP_NORMAL_END                          20

// TVGROUP_RECORD_MIX
#define TVGROUP_RECORD_MIX_START                    21
#define TVSHOW_POKEMON_TODAY_CAUGHT                 21
#define TVSHOW_SMART_SHOPPER                        22
#define TVSHOW_POKEMON_TODAY_FAILED                 23
#define TVSHOW_FISHING_ADVICE                       24
#define TVSHOW_WORLD_OF_MASTERS                     25
#define TVSHOW_TODAYS_RIVAL_TRAINER                 26
#define TVSHOW_TREND_WATCHER                        27
#define TVSHOW_TREASURE_INVESTIGATORS               28
#define TVSHOW_FIND_THAT_GAMER                      29
#define TVSHOW_BREAKING_NEWS                        30
#define TVSHOW_SECRET_BASE_VISIT                    31
#define TVSHOW_LOTTO_WINNER                         32
#define TVSHOW_BATTLE_SEMINAR                       33
#define TVSHOW_TRAINER_FAN_CLUB                     34
#define TVSHOW_CUTIES                               35
#define TVSHOW_FRONTIER                             36
#define TVSHOW_NUMBER_ONE                           37
#define TVSHOW_SECRET_BASE_SECRETS                  38
#define TVSHOW_SAFARI_FAN_CLUB                      39
#define TVGROUP_RECORD_MIX_END                      40

// TVGROUP_OUTBREAK
#define TVGROUP_OUTBREAK_START                      41
#define TVSHOW_MASS_OUTBREAK                        41
//
#define TVGROUP_OUTBREAK_END                        60

// The first 5 elements of gSaveBlock1Ptr->tvShows are reserved
// for TV shows from TVGROUP_NORMAL. The remainder are for TV
// shows from TVGROUP_RECORD_MIX.
#define NUM_NORMAL_TVSHOW_SLOTS 5

#define PLAYERS_HOUSE_TV_NONE  0
#define PLAYERS_HOUSE_TV_LATI  1
#define PLAYERS_HOUSE_TV_MOVIE 2

// Number of ribbons to put Spot the Cuties on air
#define NUM_CUTIES_RIBBONS  4

// TV Show states for Secret Base Secrets
#define SBSECRETS_STATE_INTRO                   0
#define SBSECRETS_STATE_DO_NEXT1                1
#define SBSECRETS_STATE_DO_NEXT2                2
#define SBSECRETS_STATE_TOOK_X_STEPS            3
#define SBSECRETS_STATE_BASE_INTEREST_LOW       4
#define SBSECRETS_STATE_BASE_INTEREST_MED       5
#define SBSECRETS_STATE_BASE_INTEREST_HIGH      6
#define SBSECRETS_STATE_OUTRO                   7
#define SBSECRETS_STATE_NOTHING_USED1           8
#define SBSECRETS_STATE_NOTHING_USED2           9
#define SBSECRETS_STATE_USED_CHAIR              10
#define SBSECRETS_STATE_USED_BALLOON            11
#define SBSECRETS_STATE_USED_TENT               12
#define SBSECRETS_STATE_USED_PLANT              13
#define SBSECRETS_STATE_USED_GOLD_SHIELD        14
#define SBSECRETS_STATE_USED_SILVER_SHIELD      15
#define SBSECRETS_STATE_USED_GLASS_ORNAMENT     16
#define SBSECRETS_STATE_USED_TV                 17
#define SBSECRETS_STATE_USED_MUD_BALL           18
#define SBSECRETS_STATE_USED_BAG                19
#define SBSECRETS_STATE_USED_CUSHION            20
#define SBSECRETS_STATE_HIT_CUSHION             21
#define SBSECRETS_STATE_HUGGED_CUSHION          22
#define SBSECRETS_STATE_BATTLED_WON             23
#define SBSECRETS_STATE_BATTLED_LOST            24
#define SBSECRETS_STATE_DECLINED_BATTLE         25
#define SBSECRETS_STATE_USED_POSTER             26
#define SBSECRETS_STATE_USED_NOTE_MAT           27
#define SBSECRETS_STATE_BATTLED_DRAW            28
#define SBSECRETS_STATE_USED_SPIN_MAT           29
#define SBSECRETS_STATE_USED_SAND_ORNAMENT      30
#define SBSECRETS_STATE_USED_DESK               31
#define SBSECRETS_STATE_USED_BRICK              32
#define SBSECRETS_STATE_USED_SOLID_BOARD        33
#define SBSECRETS_STATE_USED_FENCE              34
#define SBSECRETS_STATE_USED_GLITTER_MAT        35
#define SBSECRETS_STATE_USED_TIRE               36
#define SBSECRETS_STATE_USED_STAND              37
#define SBSECRETS_STATE_USED_BREAKABLE_DOOR     38
#define SBSECRETS_STATE_USED_DOLL               39
#define SBSECRETS_STATE_USED_SLIDE              40
#define SBSECRETS_STATE_DECLINED_SLIDE          41
#define SBSECRETS_STATE_USED_JUMP_MAT           42
#define SBSECRETS_NUM_STATES                    43

// The below flags are set when interacting with objects in a friends secret base
// Theyre set as bits in a var, and with 32 flags they're spread across 2 vars

// VAR_SECRET_BASE_LOW_TV_FLAGS
#define SECRET_BASE_USED_CHAIR          (1 << 0)
#define SECRET_BASE_USED_BALLOON        (1 << 1)
#define SECRET_BASE_USED_TENT           (1 << 2)
#define SECRET_BASE_USED_PLANT          (1 << 3)
#define SECRET_BASE_USED_GOLD_SHIELD    (1 << 4)
#define SECRET_BASE_USED_SILVER_SHIELD  (1 << 5)
#define SECRET_BASE_USED_GLASS_ORNAMENT (1 << 6)
#define SECRET_BASE_USED_TV             (1 << 7)
#define SECRET_BASE_USED_MUD_BALL       (1 << 8)
#define SECRET_BASE_USED_BAG            (1 << 9)
#define SECRET_BASE_USED_CUSHION        (1 << 10)
#define SECRET_BASE_BATTLED_WON         (1 << 11)
#define SECRET_BASE_BATTLED_LOST        (1 << 12)
#define SECRET_BASE_DECLINED_BATTLE     (1 << 13)
#define SECRET_BASE_USED_POSTER         (1 << 14)
#define SECRET_BASE_USED_NOTE_MAT       (1 << 15)

// VAR_SECRET_BASE_HIGH_TV_FLAGS
#define SECRET_BASE_BATTLED_DRAW        (1 << 0)
#define SECRET_BASE_USED_SPIN_MAT       (1 << 1)
#define SECRET_BASE_USED_SAND_ORNAMENT  (1 << 2)
#define SECRET_BASE_USED_DESK           (1 << 3)
#define SECRET_BASE_USED_BRICK          (1 << 4)
#define SECRET_BASE_USED_SOLID_BOARD    (1 << 5)
#define SECRET_BASE_USED_FENCE          (1 << 6)
#define SECRET_BASE_USED_GLITTER_MAT    (1 << 7)
#define SECRET_BASE_USED_TIRE           (1 << 8)
#define SECRET_BASE_USED_STAND          (1 << 9)
#define SECRET_BASE_USED_BREAKABLE_DOOR (1 << 10)
#define SECRET_BASE_USED_DOLL           (1 << 11)
#define SECRET_BASE_USED_SLIDE          (1 << 12)
#define SECRET_BASE_DECLINED_SLIDE      (1 << 13)
#define SECRET_BASE_USED_JUMP_MAT       (1 << 14)
#define SECRET_BASE_UNUSED_FLAG         (1 << 15)

#define NUM_SECRET_BASE_FLAGS  32  // by definition, bitfield of 2 u16s

// TV Show states for Pokemon Contest Live Updates
#define CONTESTLIVE_STATE_INTRO                 0
#define CONTESTLIVE_STATE_WON_BOTH_ROUNDS       1
#define CONTESTLIVE_STATE_BETTER_ROUND2         2
#define CONTESTLIVE_STATE_EQUAL_ROUNDS          3
#define CONTESTLIVE_STATE_BETTER_ROUND1         4
#define CONTESTLIVE_STATE_GOT_NERVOUS           5
#define CONTESTLIVE_STATE_STARTLED_OTHER        6
#define CONTESTLIVE_STATE_USED_COMBO            7
#define CONTESTLIVE_STATE_EXCITING_APPEAL       8
#define CONTESTLIVE_STATE_COOL                  9
#define CONTESTLIVE_STATE_BEAUTIFUL             10
#define CONTESTLIVE_STATE_CUTE                  11
#define CONTESTLIVE_STATE_SMART                 12
#define CONTESTLIVE_STATE_TOUGH                 13
#define CONTESTLIVE_STATE_VERY_EXCITING_APPEAL  14
#define CONTESTLIVE_STATE_VERY_COOL             15
#define CONTESTLIVE_STATE_VERY_BEAUTIFUL        16
#define CONTESTLIVE_STATE_VERY_CUTE             17
#define CONTESTLIVE_STATE_VERY_SMART            18
#define CONTESTLIVE_STATE_VERY_TOUGH            19
#define CONTESTLIVE_STATE_TOOK_BREAK            20
#define CONTESTLIVE_STATE_GOT_STARTLED          21
#define CONTESTLIVE_STATE_USED_MOVE             22
#define CONTESTLIVE_STATE_TALK_ABOUT_LOSER      23
#define CONTESTLIVE_STATE_NO_APPEALS            24
#define CONTESTLIVE_STATE_LAST_BOTH             25
#define CONTESTLIVE_STATE_NOT_EXCITING_ENOUGH   26
#define CONTESTLIVE_STATE_LOST_AFTER_ROUND1_WIN 27
#define CONTESTLIVE_STATE_NO_EXCITING_APPEALS   28
#define CONTESTLIVE_STATE_LOST_SMALL_MARGIN     29
#define CONTESTLIVE_STATE_REPEATED_APPEALS      30
#define CONTESTLIVE_STATE_LOST                  31
#define CONTESTLIVE_STATE_OUTRO                 32

// Flags used to comment on winner
#define CONTESTLIVE_FLAG_EXCITING_APPEAL   (1 << 0)
#define CONTESTLIVE_FLAG_GOT_NERVOUS       (1 << 1)
#define CONTESTLIVE_FLAG_MAXED_EXCITEMENT  (1 << 2)
#define CONTESTLIVE_FLAG_USED_COMBO        (1 << 3)
#define CONTESTLIVE_FLAG_STARTLED_OTHER    (1 << 4)
#define CONTESTLIVE_FLAG_SKIPPED_TURN      (1 << 5)
#define CONTESTLIVE_FLAG_GOT_STARTLED      (1 << 6)
#define CONTESTLIVE_FLAG_MADE_APPEAL       (1 << 7)

// Flags used to comment on loser
#define CONTESTLIVE_FLAG_LOST              (1 << 0)
#define CONTESTLIVE_FLAG_REPEATED_MOVE     (1 << 1)
#define CONTESTLIVE_FLAG_LOST_SMALL_MARGIN (1 << 2)
#define CONTESTLIVE_FLAG_NO_EXCITEMENT     (1 << 3)
#define CONTESTLIVE_FLAG_BLEW_LEAD         (1 << 4)
#define CONTESTLIVE_FLAG_MISSED_EXCITEMENT (1 << 5)
#define CONTESTLIVE_FLAG_LAST_BOTH_ROUNDS  (1 << 6)
#define CONTESTLIVE_FLAG_NO_APPEALS        (1 << 7)

// TV Show states for Spot the Cuties
#define SPOTCUTIES_STATE_INTRO            0
#define SPOTCUTIES_STATE_RIBBONS_LOW      1
#define SPOTCUTIES_STATE_RIBBONS_MID      2
#define SPOTCUTIES_STATE_RIBBONS_HIGH     3
#define SPOTCUTIES_STATE_RIBBON_INTRO     4
#define SPOTCUTIES_STATE_RIBBON_CHAMPION  5
#define SPOTCUTIES_STATE_RIBBON_COOL      6
#define SPOTCUTIES_STATE_RIBBON_BEAUTY    7
#define SPOTCUTIES_STATE_RIBBON_CUTE      8
#define SPOTCUTIES_STATE_RIBBON_SMART     9
#define SPOTCUTIES_STATE_RIBBON_TOUGH    10
#define SPOTCUTIES_STATE_RIBBON_WINNING  11
#define SPOTCUTIES_STATE_RIBBON_VICTORY  12
#define SPOTCUTIES_STATE_RIBBON_ARTIST   13
#define SPOTCUTIES_STATE_RIBBON_EFFORT   14
#define SPOTCUTIES_STATE_OUTRO           15

// TV Show states for Trend Watcher
#define TRENDWATCHER_STATE_INTRO           0
#define TRENDWATCHER_STATE_TAUGHT_MALE     1
#define TRENDWATCHER_STATE_TAUGHT_FEMALE   2
#define TRENDWATCHER_STATE_PHRASE_HOPELESS 3
#define TRENDWATCHER_STATE_BIGGER_MALE     4
#define TRENDWATCHER_STATE_BIGGER_FEMALE   5
#define TRENDWATCHER_STATE_OUTRO           6

// TV Show states for the Contest Lady's Live Updates show
#define CONTESTLADYLIVE_STATE_INTRO      0
#define CONTESTLADYLIVE_STATE_WON        1
#define CONTESTLADYLIVE_STATE_LOST       2
#define CONTESTLADYLIVE_STATE_LOST_BADLY 3

// TV Show states for Smart Shopper
#define SMARTSHOPPER_STATE_INTRO           0
#define SMARTSHOPPER_STATE_CLERK_NORMAL    1
#define SMARTSHOPPER_STATE_RAND_COMMENT_1  2
#define SMARTSHOPPER_STATE_RAND_COMMENT_2  3
#define SMARTSHOPPER_STATE_RAND_COMMENT_3  4
#define SMARTSHOPPER_STATE_RAND_COMMENT_4  5
#define SMARTSHOPPER_STATE_SECOND_ITEM     6
#define SMARTSHOPPER_STATE_THIRD_ITEM      7
#define SMARTSHOPPER_STATE_DURING_SALE     8
#define SMARTSHOPPER_STATE_OUTRO_NORMAL    9
#define SMARTSHOPPER_STATE_IS_VIP         10
#define SMARTSHOPPER_STATE_CLERK_MAX      11
#define SMARTSHOPPER_STATE_OUTRO_MAX      12

#define SMARTSHOPPER_NUM_ITEMS 3

// TV Show states for Bravo Trainer's Battle Tower interview
#define BRAVOTOWER_STATE_INTRO                 0
#define BRAVOTOWER_STATE_NEW_RECORD            1
#define BRAVOTOWER_STATE_LOST                  2
#define BRAVOTOWER_STATE_WON                   3
#define BRAVOTOWER_STATE_LOST_FINAL            4
#define BRAVOTOWER_STATE_SATISFIED             5
#define BRAVOTOWER_STATE_UNSATISFIED           6
#define BRAVOTOWER_STATE_UNUSED_1              7
#define BRAVOTOWER_STATE_UNUSED_2              8
#define BRAVOTOWER_STATE_UNUSED_3              9
#define BRAVOTOWER_STATE_UNUSED_4             10
#define BRAVOTOWER_STATE_RESPONSE             11
#define BRAVOTOWER_STATE_RESPONSE_SATISFIED   12
#define BRAVOTOWER_STATE_RESPONSE_UNSATISFIED 13
#define BRAVOTOWER_STATE_OUTRO                14

#endif //GUARD_CONSTANTS_TV_H
