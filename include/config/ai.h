#ifndef GUARD_CONFIG_AI_H
#define GUARD_CONFIG_AI_H

// For the details on what specific factors the switching functions are considering, go read the corresponding function inside ShouldSwitch in src/battle_ai_switch_items.c
// These configuration options control how likely the AI is to switch if it determines that a switch meets all of its criteria
// Think of them almost like success rates; if the AI has determined that it needs to switch out to hit Wonder Guard, how often do you want it to actually take that course of action? Etc.

// AI switch chances; if you want more complex behaviour, modify GetSwitchChance
#define SHOULD_SWITCH_WONDER_GUARD_PERCENTAGE                   100
#define SHOULD_SWITCH_TRUANT_PERCENTAGE                         100
#define SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE                  100
#define STAY_IN_STATS_RAISED                                    2  // Number of stat stages that must be raised across any stats before the AI won't switch mon out in certain cases

// AI smart switching chances; if you want more complex behaviour, modify GetSwitchChance
#define SHOULD_SWITCH_ABSORBS_MOVE_PERCENTAGE                       100
#define SHOULD_SWITCH_ABSORBS_HIDDEN_POWER_PERCENTAGE               50
#define SHOULD_SWITCH_TRAPPER_PERCENTAGE                            100
#define SHOULD_SWITCH_FREE_TURN_PERCENTAGE                          50
#define STAY_IN_ABSORBING_PERCENTAGE                                66  // Chance to stay in if outgoing mon has super effective move against player, will prevent switching out for an absorber with this likelihood
#define SHOULD_SWITCH_HASBADODDS_PERCENTAGE                         50
#define SHOULD_SWITCH_ENCORE_STATUS_PERCENTAGE                      100
#define SHOULD_SWITCH_ENCORE_DAMAGE_PERCENTAGE                      50
#define SHOULD_SWITCH_CHOICE_LOCKED_PERCENTAGE                      100 // Only if locked into status move
#define SHOULD_SWITCH_ATTACKING_STAT_MINUS_TWO_PERCENTAGE           50
#define SHOULD_SWITCH_ATTACKING_STAT_MINUS_THREE_PLUS_PERCENTAGE    100
#define SHOULD_SWITCH_ALL_SCORES_BAD_PERCENTAGE                     100
#define SHOULD_SWITCH_DYN_FUNC_PERCENTAGE                           50 // Dynamic switching function switch chance
#define SHOULD_SWITCH_LOSES_1V1_PERCENTAGE                          0 // Keeping this disabled by default makes evaluating and testing switching behaviour when developing much easier

// AI smart switching chances for bad statuses
#define SHOULD_SWITCH_PERISH_SONG_PERCENTAGE                    100
#define SHOULD_SWITCH_YAWN_PERCENTAGE                           100
#define SHOULD_SWITCH_BADLY_POISONED_PERCENTAGE                 50
#define SHOULD_SWITCH_BADLY_POISONED_STATS_RAISED_PERCENTAGE    20
#define SHOULD_SWITCH_CURSED_PERCENTAGE                         50
#define SHOULD_SWITCH_CURSED_STATS_RAISED_PERCENTAGE            20
#define SHOULD_SWITCH_NIGHTMARE_PERCENTAGE                      33
#define SHOULD_SWITCH_NIGHTMARE_STATS_RAISED_PERCENTAGE         15
#define SHOULD_SWITCH_SEEDED_PERCENTAGE                         25
#define SHOULD_SWITCH_SEEDED_STATS_RAISED_PERCENTAGE            10
#define SHOULD_SWITCH_INFATUATION_PERCENTAGE                    100

// AI smart switching chances for beneficial abilities
#define SHOULD_SWITCH_NATURAL_CURE_STRONG_PERCENTAGE                66
#define SHOULD_SWITCH_NATURAL_CURE_STRONG_STATS_RAISED_PERCENTAGE   10
#define SHOULD_SWITCH_NATURAL_CURE_WEAK_PERCENTAGE                  25
#define SHOULD_SWITCH_NATURAL_CURE_WEAK_STATS_RAISED_PERCENTAGE     10
#define SHOULD_SWITCH_REGENERATOR_PERCENTAGE                        50
#define SHOULD_SWITCH_REGENERATOR_STATS_RAISED_PERCENTAGE           20
#define SHOULD_SWITCH_INTIMIDATE_PERCENTAGE                         25
#define SHOULD_SWITCH_INTIMIDATE_STATS_RAISED_PERCENTAGE            10
#define SHOULD_SWITCH_WISH_PASSING_PERCENTAGE                       50

// AI switchin considerations
#define ALL_MOVES_BAD_STATUS_MOVES_BAD                          FALSE // If the AI has no moves that affect the target, ShouldSwitchIfAllMovesBad can prompt a switch. Enabling this config will ignore status moves that can affect the target when making this decision.
#define AI_BAD_SCORE_THRESHOLD                                  90 // Move scores beneath this threshold are considered "bad" when deciding switching
#define AI_GOOD_SCORE_THRESHOLD                                 100 // Move scores above this threshold are considered "good" when deciding switching
#define ALL_MOVES_BAD_NEEDS_GOOD_SWITCHIN                       FALSE // AI will only trigger ShouldSwitchIfAllMovesBad if they have a good switchin
#define ALL_SCORES_BAD_NEEDS_GOOD_SWITCHIN                      FALSE // AI will only trigger ShouldSwitchIfAllScoresBad if they have a good switchin
#define AI_DEFENSIVE_KO_THRESHOLD                               3 // AI must be able to take more than this many hits before being KO'd before being considered a "defensive mon"
#define AI_TYPE_MATCHUP_THRESHOLD                               UQ_4_12(2.0) // AI must have a better matchup than this to be considered good; 2.0 is the default "Neutral" matchup from GetBattlerTypeMatchup
#define AI_WISH_HEAL_THRESHOLD                                  4 // Fraction of HP AI must restore to be considered a good recipient of Wish, treated as a fraction denominator (ie. 4 = 1/4 = 25% HP)
#define AI_SWITCHIN_DAMAGE_THRESHOLD                            0 // Damage AI must exceed to be considered an acceptable switchin candidate. Keep this *very low*, as it's used as a fallback case before giving up.
#define AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE                   50 // Chance to reverse the order of mons when running AI logic in double battles. For example if both mons want to switch and there's only one mon to switch in, the first mon processed will get to switch; setting this above zero controls the chance of switching which slot is processed first

// AI held item-based move scoring
#define LOW_ACCURACY_THRESHOLD                                  75 // Moves with accuracy equal OR below this value are considered low accuracy

// AI move scoring
#define STATUS_MOVE_FOCUS_PUNCH_CHANCE                          50 // Chance the AI will use a status move if the player's best move is Focus Punch
#define BOOST_INTO_HAZE_CHANCE                                  0 // Chance the AI will use a stat boosting move if the player has used Haze
#define SHOULD_RECOVER_CHANCE                                   50 // Chance the AI will give recovery moves score increase if less than ENABLE_RECOVERY_THRESHOLD and in no immediate danger
#define ENABLE_RECOVERY_THRESHOLD                               60 // HP percentage beneath which SHOULD_RECOVER_CHANCE is active
#define SUCKER_PUNCH_CHANCE                                     50 // Chance for the AI to not use Sucker Punch if the player has a status move
#define SUCKER_PUNCH_PREDICTION_CHANCE                          50 // Additional chance for the AI to not use Sucker Punch if actively predicting a status move if SUCKER_PUNCH_CHANCE fails
#define PRIORITIZE_LAST_CHANCE_CHANCE                           50 // Chance the AI will prioritize Last Chance (priority move in the face of being outsped and KO'd) over Slow KO
#define LAST_MON_PREFERS_NOT_SACRIFICE                          FALSE // Whether the AI will be hesitant to use self-sacrificing moves (Explosion, Final Gambit) with their last mon
#define EXPLOSION_LOWER_HP_THRESHOLD                            10 // HP percentage at or beneath which the AI has a 90% chance to explode; otherwise scales between this and higher threshold
#define EXPLOSION_HIGHER_HP_THRESHOLD                           90 // HP percentage at or above which the AI has a 0% chance to explode; otherwise scales between this and lower threshold
#define EXPLOSION_MINIMUM_CHANCE                                0 // Lowest possible percent chance of the AI using explosion based on its current HP
#define EXPLOSION_MAXIMUM_CHANCE                                90 // Highest possible percent chance of the AI using explosion based on its current HP
#define FINAL_GAMBIT_CHANCE                                     50 // Chance for AI to consider using Final Gambit if it outspeeds the player and thinks it has more HP
#define SHOULD_PIVOT_BREAK_SASH_CHANCE                          50 // Chance for ShouldPivot to return true when trying to break Multiscale and Focus Sash type effects while having a good switchin
#define FAKE_OUT_SAVE_ALLY_CHANCE                               50 // Chance for AI to Fake Out to save its ally when ally is fast KO'd by both opponents

// AI damage calc considerations
#define RISKY_AI_CRIT_STAGE_THRESHOLD                           2   // Stat stages at which Risky will assume it gets a crit
#define RISKY_AI_CRIT_THRESHOLD_GEN_1                           128 // "Stat stage" at which Risky will assume it gets a crit with gen 1 mechanics (this translates to an X / 255 % crit threshold)
#define AI_DAMAGES_THROUGH_BERRIES                              TRUE // AI will see through resist berries when considering a certain KO threshold for the purposes damage calcs; this is considered when comparing best moves to KO to still pick the actual OHKO if needed
#define AI_IGNORE_BERRY_KO_THRESHOLD                            2   // KO threshold AI must meet in order to treat it berry though it doesn't exist (ie. 2 means "If the AI can 2HKO with berry resisted attack + not-berry resisted next attack, ignore berry resistence when calcing first attack"). Requires AI_DAMAGES_THROUGH_BERRIES

// AI damage calc roll considerations
#define AI_ROLL_MIN                                             1
#define AI_ROLL_MEDIAN                                          2
#define AI_ROLL_MAX                                             3
#define AI_ROLL_RANDOM                                          4
#define AI_ROLL_TYPE_COUNT                                      5

// Define which roll type to use in each context; overridden by AI_FLAG_RISKY and AI_FLAG_CONSERVATIVE
#define AI_ROLL_ATTACKING                                       AI_ROLL_MAX
#define AI_ROLL_DEFENDING                                       AI_ROLL_MEDIAN
#define AI_ROLL_SWITCHIN_ATTACKING                              AI_ROLL_MEDIAN
#define AI_ROLL_SWITCHIN_DEFENDING                              AI_ROLL_MEDIAN
#define AI_ROLL_SHOULD_SETUP_DEFENDING                          AI_ROLL_MAX
#define AI_ROLL_ATTACKING_PARTNER                               AI_ROLL_MAX

// AI prediction chances
#define PREDICT_SWITCH_CHANCE                                   50
#define PREDICT_MOVE_CHANCE                                     100

// AI Terastalization chances
#define AI_CONSERVE_TERA_CHANCE_PER_MON                         10 // Chance for AI with smart tera flag to decide not to tera before considering defensive benefit is this*(X-1), where X is the number of alive Pokémon that could tera
#define AI_TERA_PREDICT_CHANCE                                  40 // Chance for AI with smart tera flag to tera in the situation where tera would save it from a KO, but could be punished by a KO from a different move.

// AI_FLAG_PP_STALL_PREVENTION settings
#define PP_STALL_DISREGARD_MOVE_PERCENTAGE                      50 // Detection chance per roll
#define PP_STALL_SCORE_REDUCTION                                20 // Score reduction if any roll for PP stall detection passes

// AI_FLAG_ASSUME_STAB settings
#define ASSUME_STAB_SEES_ABILITY                                FALSE // Flag also gives omniscience for player's ability. Can use AI_FLAG_WEIGH_ABILITY_PREDICTION instead for smarter prediction without omniscience.

// AI_FLAG_ASSUME_STATUS_MOVES settings
#define ASSUME_STATUS_MOVES_HAS_TUNING                  TRUE // Flag has varying rates for different kinds of status move.
                                                             // Setting to false also means it will not alert on Fake Out or Super Fang.
#define ASSUME_STATUS_HIGH_ODDS                         90 // Chance for AI to see extremely likely moves for a Pokémon to have, like Spore
#define ASSUME_STATUS_MEDIUM_ODDS                       70 // Chance for AI to see moderately likely moves for a Pokémon to have, like Protect
#define ASSUME_STATUS_LOW_ODDS                          40 // Chance for AI to see niche moves a Pokémon may have but probably won't, like Entrainment
#define ASSUME_ALL_STATUS_ODDS                          25 // Chance for the AI to see any kind of status move.

// AI_FLAG_SMART_SWITCHING settings
#define SMART_SWITCHING_OMNISCIENT                              FALSE // AI will use omniscience for switching calcs, regardless of omniscience setting otherwise

// AI_FLAG_RANDOMIZE_SWITCHIN settings
#define RANDOMIZE_SWITCHIN_ANY_VALID                            TRUE // If AI has no good candidate mons, it will still choose randomly from all valid options rather than defaulting to the last one in party order

// Configurations specifically for AI_FLAG_DOUBLE_BATTLE.
#define FRIENDLY_FIRE_RISKY_THRESHOLD             2 // AI_FLAG_RISKY acceptable number of hits to KO the partner via friendly fire
#define FRIENDLY_FIRE_NORMAL_THRESHOLD            3 // typical acceptable number of hits to KO the partner via friendly fire
#define FRIENDLY_FIRE_CONSERVATIVE_THRESHOLD      4 // AI_FLAG_CONSERVATIVE acceptable number of hits to KO the partner via friendly fire
// Counterplay on the assumption of opponents Protecting.
#define DOUBLE_TRICK_ROOM_ON_LAST_TURN_CHANCE    35 // both Pokémon use Trick Room on turn Trick Room expires in the hopes both opponents used Protect to stall, getting a free refresh on the timer
#define TAILWIND_IN_TRICK_ROOM_CHANCE            35 // use Tailwind on turn Trick Room expires in the hopes both opponents used Protect to stall

#define AI_FLAG_ATTACKS_PARTNER_FOCUSES_PARTNER  FALSE  // if TRUE, AI_FLAG_ATTACKS_PARTNER prefers attacking the partner over the ally.
                                                        // This is treated as true regardless during wild battles with AI.

// AI's desired stat changes for Guard Split and Power Split, treated as %
#define GUARD_SPLIT_ALLY_PERCENTAGE     200
#define GUARD_SPLIT_ENEMY_PERCENTAGE    50
#define POWER_SPLIT_ALLY_PERCENTAGE     150
#define POWER_SPLIT_ENEMY_PERCENTAGE    50

// HP thresholds to use a status z-move.
#define Z_EFFECT_FOLLOW_ME_THRESHOLD    30
#define Z_EFFECT_RESTORE_HP_LOWER_THRESHOLD   ENABLE_RECOVERY_THRESHOLD // threshold used for moves you could conceivably use more than once
#define Z_EFFECT_RESTORE_HP_HIGHER_THRESHOLD  90                        // these moves are one-time use or drop your HP

#endif // GUARD_CONFIG_AI_H
