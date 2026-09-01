#ifndef GUARD_CONSTANTS_FORM_CHANGE_TYPES_H
#define GUARD_CONSTANTS_FORM_CHANGE_TYPES_H

// FORM_CHANGE_BATTLE_HP_PERCENT_TURN_END / FORM_CHANGE_BATTLE_HP_PERCENT_SEND_OUT param2 arguments
enum FormChangeBattleHPPercentArguments
{
    HP_HIGHER_THAN = 1,
    HP_LOWER_EQ_THAN,
};
// FORM_CHANGE_MOVE param2 Arguments
enum FormChangeMoveArguments
{
    WHEN_LEARNED,
    WHEN_FORGOTTEN,
};
// FORM_CHANGE_ITEM_USE param2 Arguments
enum FormChangeItemUseArguments
{
    DAY = 1,
    NIGHT,
};

#define FUSION_TERMINATOR                       0xFF

enum FormChanges
{
    FORM_CHANGE_TERMINATOR,
    // Form change that activates when the specified item is given to or taken from the selected Pokémon.
    // param1: item to hold.
    // param2: ability to check for, optional.
    FORM_CHANGE_ITEM_HOLD,
    // Form change that activates when the item is used on the selected Pokémon.
    // param1: item to use
    // param2: time of day to check, optional.
    // - DAY if Form change that activates in the daytime.
    // - NIGHT if Form change that activates at nighttime.
    // - 0 if irrelevant, but param3 is necessary.
    // param3: illegal statuses to have, optional.
    FORM_CHANGE_ITEM_USE,
    // TODO: Form change that activates when the Pokémon learns or forgets the move.
    // param1: move to check for
    // param2:
    // - WHEN_LEARNED if Form change that activates when move is forgotten
    // - WHEN_FORGOTTEN if Form change that activates when move is learned
    FORM_CHANGE_MOVE,
    // Form change that activates when the Pokémon is withdrawn from the PC or Daycare.
    // - No parameters.
    FORM_CHANGE_WITHDRAW,
    // Form change that activates when the Pokémon faints, either in battle or in the overworld by poison.
    // - No parameters.
    FORM_CHANGE_FAINT,
    // Form change that activates when the Pokémon is sent out at the beginning of a battle
    // param1: item to hold, optional
    // param2: a move that will be replaced, optional
    // param3: a new move to replace it with, optional
    FORM_CHANGE_BEGIN_BATTLE,
    // Form change that activates at the end of a battle. If species is not specified and it's on the player's side, it will try to use the value saved in gBattleStruct->partyState[x][y].changedSpecies from a previous form change.
    // param1: item to hold, optional
    // param2: a move that will be replaced, optional
    // param3: a new move to replace it with, optional
    FORM_CHANGE_END_BATTLE,
    // Form change that activates at the end of a battle based on the environment if it participated in the battle and hasn't fainted. Takes priority over FORM_CHANGE_END_BATTLE.
    // param1: battle environment to check.
    FORM_CHANGE_END_BATTLE_ENVIRONMENT,
    // Form change that activates when the Pokémon is switched out in battle.
    // param1: (optional) ability to check
    FORM_CHANGE_BATTLE_SWITCH_OUT,
    // Form change that activates when the Pokémon is switched-in in battle.
    // This form change happens before other abilities like Neutralizing Gas.
    // param1: ability to check
    FORM_CHANGE_BATTLE_SWITCH_IN,
    // Form change that activates when the Pokémon's HP % passes a certain threshold.
    // param1: Ability to check.
    // param2: HP comparer
    // - HP_HIGHER_THAN if the form triggers when the current HP is higher than the specified threshold.
    // - HP_LOWER_EQ_THAN if the form triggers when the current HP is lower or equal than the specified threshold.
    // param3: HP percentage threshold.
    // param4: (optional) Minimum level to do form change
    FORM_CHANGE_BATTLE_HP_PERCENT_TURN_END,
    // Form change that activates when the Pokémon's HP % passes a certain threshold when sent out into battle.
    // param1: Ability to check.
    // param2: HP comparer
    // - HP_HIGHER_THAN if the form triggers when the current HP is higher than the specified threshold.
    // - HP_LOWER_EQ_THAN if the form triggers when the current HP is lower or equal than the specified threshold.
    // param3: HP percentage threshold.
    // param4: (optional) Minimum level to do form change
    FORM_CHANGE_BATTLE_HP_PERCENT_SEND_OUT,
    // Form change that activates when the Pokémon's HP % passes a certain threshold when using a move.
    // param1: Ability to check.
    // param2: HP comparer
    // - HP_HIGHER_THAN if the form triggers when the current HP is higher than the specified threshold.
    // - HP_LOWER_EQ_THAN if the form triggers when the current HP is lower or equal than the specified threshold.
    // param3: HP percentage threshold.
    // param4: Move used.
    FORM_CHANGE_BATTLE_HP_PERCENT_DURING_MOVE,
    // Form change that activates when the mon has the defined item.
    // If it's on the player's side, it also requires ITEM_MEGA_RING in the user's bag and for the player to trigger it by pressing START before selecting a move.
    // param1: item to hold.
    FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM,
    // Form change that activates when the mon has the defined move.
    // If it's on the player's side, it also requires ITEM_MEGA_RING in the user's bag and for the player to trigger it by pressing START before selecting a move.
    // param1: move to have.
    FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE,
    // Form change that activates automatically when entering battle with the specified item.
    // If the item is a Red Orb, it uses the Omega Symbol for the animation and icon. Otherwise, it defaults to the Alpha symbol.
    // The battle indicator icon is based on the species, with Primal Groudon's as Omega and otherwise being Alpha.
    // param1: item to hold.
    FORM_CHANGE_BATTLE_PRIMAL_REVERSION,
    // Form change that activates when a specific weather is set during battle.
    // param1: weather to check
    // param2: (optional) revert if specified ability is lost
    FORM_CHANGE_BATTLE_WEATHER,
    // Form change that activates automatically when the turn ends.
    // param1: ability to check.
    FORM_CHANGE_BATTLE_TURN_END,
    // Form change that activates when the mon has the defined item.
    // If it's on the player's side, it also requires for the player to trigger it by pressing START before selecting a move.
    // param1: item to hold.
    FORM_CHANGE_BATTLE_ULTRA_BURST,
    // Form change that activates when the mon Dynamaxes.
    // - No parameters
    FORM_CHANGE_BATTLE_GIGANTAMAX,
    // Form change that activates at a certain time of day in the overworld automatically.
    // param1: time of day to check.
    // - DAY if Form change that activates in the daytime.
    // - NIGHT if Form change that activates at nighttime.
    FORM_CHANGE_TIME_OF_DAY,
    // Form change that depends on a multichoice (e.g. Rotom Catalog).
    // param1: multichoice list (starting at 0).
    FORM_CHANGE_ITEM_USE_MULTICHOICE,
    // Form change that activates when inflicted with a specific status
    // param1: status
    FORM_CHANGE_STATUS,
    // Form change that activates after receiving an attack.
    // param1: ability
    // param2: move category to check
    FORM_CHANGE_BATTLE_HIT_BY_MOVE_CATEGORY,
    // Form change that activates after hitting itself in confusion.
    // param1: ability
    FORM_CHANGE_BATTLE_HIT_BY_CONFUSION_SELF_DMG,
    // Form change that activates when terastallized as as a specific type
    // param1: tera type
    FORM_CHANGE_BATTLE_TERASTALLIZATION,
    // Form change that activates at midnight after a certain amount of days has passed.
    // Adding this form change will automatically make the countdown start as soon the Pokémon changes into a species other than the one specified for this form change.
    // param1: amount of days
    FORM_CHANGE_DAYS_PASSED,
    // Form change that activates before using a move.
    // param1: move to check
    // param2: ability to check, optional
    FORM_CHANGE_BATTLE_BEFORE_MOVE,
    // Form change that activates after using a move.
    // param1: move to check
    FORM_CHANGE_BATTLE_AFTER_MOVE,
    // Form change that activates when Battle Bond is triggered.
    // param1: ability to check
    FORM_CHANGE_BATTLE_BOND,
    // Form change that activates before using a specific move category.
    // param1: move category to check
    // param2: ability to check, optional
    FORM_CHANGE_BATTLE_BEFORE_MOVE_CATEGORY,
    // Form change that activates when overworld weather changes.
    // param1: weather to check.
    FORM_CHANGE_OVERWORLD_WEATHER,
    // Form change that activates when the Pokémon is deposited into the PC or Daycare.
    FORM_CHANGE_DEPOSIT,
    // Form change for Minior, which appears unchanged when encountered in the wild
    FORM_CHANGE_BEGIN_WILD_ENCOUNTER,
};

#endif // GUARD_CONSTANTS_FORM_CHANGE_TYPES_H
