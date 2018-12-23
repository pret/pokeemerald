#ifndef GUARD_CONSTANTS_BATTLE_CONFIG_H
#define GUARD_CONSTANTS_BATTLE_CONFIG_H

#define GEN_3 0
#define GEN_4 1
#define GEN_5 2
#define GEN_6 3
#define GEN_7 4

#define B_CRIT_CHANCE               GEN_6 // Chances of a critical hit landing. See atk04_critcalc.
#define B_FELL_STINGER_STAT_RAISE   GEN_6 // Gen6 Atk+2, Gen7 Atk+3.
#define B_ABILITY_WEATHER           GEN_6 // Up to gen5 - weather induced by abilities such as Drought or Drizzle lasted till the battle's end or weather change by a move. From Gen6 onwards, weather caused by abilities lasts the same amount of turns as induced from a move.
#define B_GALE_WINGS                GEN_6 // Gen7 requires full hp.
#define B_SOUND_SUBSTITUTE          GEN_6 // Starting from gen6 sound moves bypass Substitute.
#define B_EXP_CATCH                 GEN_6 // Starting from gen6, pokemon get experience from catching.
#define B_ABILITY_POP_UP            GEN_6 // Starting from gen5, the pokemon abilities are displayed in a pop-up, when they activate in battle.

#define B_FAST_INTRO                TRUE // If set to TRUE, battle intro texts print at the same time as animation of a pokemon, as opposing to waiting for the animation to end.

#endif // GUARD_CONSTANTS_BATTLE_CONFIG_H
