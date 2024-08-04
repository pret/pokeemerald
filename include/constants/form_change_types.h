#ifndef GUARD_CONSTANTS_FORM_CHANGE_TYPES_H
#define GUARD_CONSTANTS_FORM_CHANGE_TYPES_H

// FORM_CHANGE_BATTLE_HP_PERCENT param2 arguments
#define HP_HIGHER_THAN      1
#define HP_LOWER_EQ_THAN    2
// FORM_CHANGE_MOVE param2 Arguments
#define WHEN_LEARNED    0
#define WHEN_FORGOTTEN  1
// FORM_CHANGE_ITEM_USE param2 Arguments
#define DAY    1
#define NIGHT  2

#define FUSION_TERMINATOR                       0xFF
#define FORM_CHANGE_TERMINATOR                  0

// Form change that activates when the specified item is given to or taken from the selected Pokémon.
// param1: item to hold.
// param2: ability to check for, optional.
#define FORM_CHANGE_ITEM_HOLD                   1

// Form change that activates when the item is used on the selected Pokémon.
// param1: item to use
// param2: time of day to check, optional.
// - DAY if Form change that activates in the daytime.
// - NIGHT if Form change that activates at nighttime.
// - 0 if irrelevant, but param3 is necessary.
// param3: illegal statuses to have, optional.
#define FORM_CHANGE_ITEM_USE                    2

// TODO: Form change that activates when the Pokémon learns or forgets the move.
// param1: move to check for
// param2:
// - WHEN_LEARNED if Form change that activates when move is forgotten
// - WHEN_FORGOTTEN if Form change that activates when move is learned
#define FORM_CHANGE_MOVE                        3

// Form change that activates when the Pokémon is withdrawn from the PC or Daycare.
// Daycare withdraw done, PC withdraw TODO.
// - No parameters.
#define FORM_CHANGE_WITHDRAW                    4

// Form change that activates when the Pokémon faints, either in battle or in the overworld by poison.
// If species is not specified and it's on the player's side, it will try to use the value
// saved in gBattleStruct->changedSpecies from a previous form change.
// - No parameters.
#define FORM_CHANGE_FAINT                       5

// Form change that activates when the Pokémon is sent out at the beginning of a battle
// param1: item to hold, optional
// param2: a move that will be replaced, optional
// param3: a new move to replace it with, optional
#define FORM_CHANGE_BEGIN_BATTLE                6

// Form change that activates at the end of a battle. If species is not specified and it's on the player's side, it will try to use the value saved in gBattleStruct->changedSpecies from a previous form change.
// param1: item to hold, optional
// param2: a move that will be replaced, optional
// param3: a new move to replace it with, optional
#define FORM_CHANGE_END_BATTLE                  7

// Form change that activates at the end of a battle based on the terrain if it participated in the battle and hasn't fainted. Takes priority over FORM_CHANGE_END_BATTLE.
// param1: battle terrain to check.
#define FORM_CHANGE_END_BATTLE_TERRAIN          8

// Form change that activates when the Pokémon is switched out in battle.
// param1: ability to check, optional
#define FORM_CHANGE_BATTLE_SWITCH               9

// Form change that activates when the Pokémon's HP % passes a certain threshold.
// param1: Ability to check.
// param2: HP comparer
// - HP_HIGHER_THAN if the form triggers when the current HP is higher than the specified threshold.
// - HP_LOWER_EQ_THAN if the form triggers when the current HP is lower or equal than the specified threshold.
// param3: HP percentage threshold.
#define FORM_CHANGE_BATTLE_HP_PERCENT           10

// Form change that activates when the mon has the defined item.
// If it's on the player's side, it also requires ITEM_MEGA_RING in the user's bag and for the player to trigger it by pressing START before selecting a move.
// param1: item to hold.
#define FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM  11

// Form change that activates when the mon has the defined move.
// If it's on the player's side, it also requires ITEM_MEGA_RING in the user's bag and for the player to trigger it by pressing START before selecting a move.
// param1: move to have.
#define FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE  12

// Form change that activates automatically when entering battle with the specified item.
// If the item is a Red Orb, it uses the Omega Symbol for the animation and icon. Otherwise, it defaults to the Alpha symbol.
// The battle indicator icon is based on the species, with Primal Groudon's as Omega and otherwise being Alpha.
// param1: item to hold.
#define FORM_CHANGE_BATTLE_PRIMAL_REVERSION     13

// Form change that activates when a specific weather is set during battle.
// param1: weather to check
// param2: (optional) revert if specified ability is lost
#define FORM_CHANGE_BATTLE_WEATHER              14

// Form change that activates automatically when the turn ends.
// param1: ability to check.
#define FORM_CHANGE_BATTLE_TURN_END             15

// Form change that activates when the mon has the defined item.
// If it's on the player's side, it also requires for the player to trigger it by pressing START before selecting a move.
// param1: item to hold.
#define FORM_CHANGE_BATTLE_ULTRA_BURST          16

// Form change that activates when the mon Dynamaxes (TODO: with Gigantamax factor).
// - No parameters
#define FORM_CHANGE_BATTLE_GIGANTAMAX           17

// Form change that activates at a certain time of day in the overworld automatically.
// param1: time of day to check.
// - DAY if Form change that activates in the daytime.
// - NIGHT if Form change that activates at nighttime.
#define FORM_CHANGE_TIME_OF_DAY                 18

// Form change that depends on a multichoice (e.g. Rotom Catalog).
// param1: multichoice list (starting at 0).
#define FORM_CHANGE_ITEM_USE_MULTICHOICE        19

// Form change that activates when inflicted with a specific status
// param1: status
#define FORM_CHANGE_STATUS                      20

// Form change that activates after move is used. Currently only used for activating Gulp Missile.
#define FORM_CHANGE_HIT_BY_MOVE                 21

// Form change that activates when terastallized as as a specific type
// param1: tera type
#define FORM_CHANGE_BATTLE_TERASTALLIZATION     22

// Form change that activates at midnight after a certain amount of days has passed.
// Adding this form change will automatically make the countdown start as soon the Pokémon changes into a species other than the one specified for this form change.
// param1: amount of days
#define FORM_CHANGE_DAYS_PASSED                 23

#endif // GUARD_CONSTANTS_FORM_CHANGE_TYPES_H
