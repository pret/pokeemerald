#ifndef GUARD_CONFIG_BATTLE_H
#define GUARD_CONFIG_BATTLE_H

// Calculation settings
#define B_CRIT_CHANCE               GEN_LATEST // Chances of landing a critical hit. See CalcCritChanceStage. Gen6+ chances guarantee a crit at 3 or more stages. Gen1 chances are based on half of the user's base Speed.
#define B_CRIT_MULTIPLIER           GEN_LATEST // In Gen6+, critical hits increase damage by 1.5x instead of 2x.
#define B_PARALYSIS_SPEED           GEN_LATEST // In Gen7+, paralysis decreases Speed by 50% instead of 75%.
#define B_CONFUSION_SELF_DMG_CHANCE GEN_LATEST // In Gen7+, a Pokémon will hurt itself in confusion 1/3 of the time instead of half.
#define B_MULTI_HIT_CHANCE          GEN_LATEST // In Gen5+, multistrike moves have different chances for the number of times they hit. See SetRandomMultiHitCounter for values.
#define B_WHITEOUT_MONEY            GEN_LATEST // In Gen4+, the amount of money dropped after losing a battle is determined by the number of Badges obtained. Previously, half of the player's money would be dropped. (While this change was also in FRLG, for the sake of simplicity, setting this to GEN_3 will result in RSE behavior.)
#define B_LIGHT_BALL_ATTACK_BOOST   GEN_LATEST // In Gen4+, Light Ball doubles Attack in addition to Sp. Atk.
#define B_PARALYSIS_CHANCE          GEN_LATEST // In Champions, paralysis has a 12.5% chance of not moving, instead of 25%.

// Experience settings
#define B_EXP_CATCH                 GEN_LATEST // In Gen6+, the party gains experience when the player catches another Pokémon.
#define B_TRAINER_EXP_MULTIPLIER    GEN_LATEST // In Gen7+, Trainer battles no longer increase total experience by 1.5x.
#define B_SPLIT_EXP                 GEN_LATEST // In Gen6+, all Pokémon that participate in a battle gain full experience. In Gen5 and earlier, the total experience would be evenly split across them.
#define B_SCALED_EXP                GEN_LATEST // In Gen5 and Gen7+, experience gain is weighted by the difference between the levels of the player's Pokémon and the target.
#define B_UNEVOLVED_EXP_MULTIPLIER  GEN_LATEST // In Gen6+, if a Pokémon is at or past the level where it would be able to evolve, but it has not, it gains ~1.2x experience. This only applies to species with the EVO_LEVEL method.
#define B_LEVEL_UP_NOTIFICATION     GEN_LATEST // In Gen9+, if a Pokémon gains enough experience to level up multiple times, a message is only displayed once.

// Stat settings
#define B_BADGE_BOOST               GEN_LATEST // In Gen4+, Gym Badges no longer boost a Pokémon's stats. (Setting this to GEN_2 does not include the additional boost to the type matching the Gym the Badge is from.)
#define B_FRIENDSHIP_BOOST          FALSE      // In LGPE only, all stats except HP are boosted by up to 10% depending on on friendship. Unlike B_BADGE_BOOST, these boosts are accounted for when calculating base stats.
#define B_MAX_LEVEL_EV_GAINS        GEN_LATEST // In Gen5+, level 100 Pokémon can obtain Effort Values from battles.
#define B_RECALCULATE_STATS         GEN_LATEST // In Gen5+, the stats of Pokémon that participate in battle are recalculated at the end of battle, rather than upon level up or being deposited in the PC.

// Damage settings
#define B_BURN_DAMAGE               GEN_LATEST // In Gen1 and Gen7+, burn damage is 1/16 of max HP instead of 1/8. This also applies to Frostbite.
#define B_BURN_FACADE_DMG           GEN_LATEST // In Gen6+, burn's Attack halving effect no longer applies to Facade.
#define B_BINDING_DAMAGE            GEN_LATEST // In Gen6+, binding damage is 1/8 of max HP instead of 1/16. If the user is holding a Binding Band, it is 1/6 instead of 1/8.
#define B_PSYWAVE_DMG               GEN_LATEST // Psywave's damage formula. See DoFixedDamageMoveCalc for details.
#define B_PAYBACK_SWITCH_BOOST      GEN_LATEST // In Gen5+, Payback's base power no longer doubles if the opponent switches out.
#define B_HIDDEN_POWER_DMG          GEN_LATEST // In Gen6+, Hidden Power's base power is 60. Previously, it was determined by the Pokémon's IVs.
#define B_ROUGH_SKIN_DMG            GEN_LATEST // In Gen4+, Rough Skin's contact damage is 1/8 of max HP instead of 1/16. This also applies to Iron Barbs.
#define B_KNOCK_OFF_DMG             GEN_LATEST // In Gen6+, Knock Off deals 50% more damage if the target is holding an item that can be knocked off.
#define B_SPORT_DMG_REDUCTION       GEN_LATEST // In Gen5+, Water/Mud Sport reduce Fire-/Electric-type damage by 67% instead of 50%.
#define B_EXPLOSION_DEFENSE         GEN_LATEST // In Gen5+, Self-Destruct and Explosion no longer halve the targets' Defense.
#define B_PARENTAL_BOND_DMG         GEN_LATEST // In Gen7+, Parental Bond's second hit does 25% of the initial hit's damage instead of 50%.
#define B_MULTIPLE_TARGETS_DMG      GEN_LATEST // In Gen4+, damage dealt by moves that hit multiple targets at once is reduced to 75%. Previously, it was 50%, unless the move hit the entire field, in which case there was no reduction.

// Type settings
#define B_GHOSTS_ESCAPE             GEN_LATEST // In Gen6+, escape prevention fails on Ghost-types. Additionally, attempting to escape from a wild battle is always sucessful.
#define B_PARALYZE_ELECTRIC         GEN_LATEST // In Gen6+, Electric-types can no longer be paralyzed.
#define B_POWDER_GRASS              GEN_LATEST // In Gen6+, Grass-types are immune to powder and spore moves.
#define B_UPDATED_TYPE_MATCHUPS     GEN_LATEST // Changes type matchups. src/data/types_info.h for details.
#define B_PRANKSTER_DARK_TYPES      GEN_LATEST // In Gen7+, Prankster-elevated status moves do not affect Dark-types.
#define B_SHEER_COLD_IMMUNITY       GEN_LATEST // In Gen7+, Ice-types are immune to Sheer Cold.
#define B_ROOST_PURE_FLYING         GEN_LATEST // In Gen5+, Roost turns pure Flying-types into Normal-types.
#define B_STATUS_TYPE_IMMUNITY      GEN_LATEST // In Gen1, Pokémon were immune to additional effects of attacking moves if they shared a type with the move.

// Turn settings
#define B_BINDING_TURNS             GEN_LATEST // In Gen5+, binding moves last for 4-5 turns instead of 2-5. If the user is holding a Grip Claw, they last for 7 turns instead of 5.
#define B_UPROAR_TURNS              GEN_LATEST // In Gen5+, Uproar lasts for 3 turns instead of 2-5.
#define B_UPROAR_IGNORE_SOUNDPROOF  GEN_LATEST // In Gen5+, Uproar's effects ignore Soundproof.
#define B_DISABLE_TURNS             GEN_LATEST // Disable's turns. See Cmd_disablelastusedattack.
#define B_TAILWIND_TURNS            GEN_LATEST // In Gen5+, Tailwind lasts 4 turns instead of 3.
#define B_SLEEP_TURNS               GEN_LATEST // In Gen5+, sleep prevents movement for 1-3 turns. In Gens3-4, it was 1-4 turns. In Gen2, it was 1-7 turns.
#define B_TAUNT_TURNS               GEN_LATEST // In Gen5+, Taunt lasts 3 turns if the user acts before the target, or 4 turns if the target acted before the user. In Gen4, it lasted 2-4/3-5 turns. In Gen3, it lasted 2/3 turns.
#define B_ENCORE_TURNS              GEN_LATEST // In Gen5+, Encore lasts 3 turns if the target hasn't yet moved this turn, or 4 turns if it has. In Gen4, it lasts 3-7 turns. In Gen2-3, 2-6 turns.
#define B_SPORT_TURNS               GEN_LATEST // In Gen6+, Water/Mud Sport last 5 turns, even if the user switches out. In Gen5 and earlier, they lasted until the user switched out.
#define B_MEGA_EVO_TURN_ORDER       GEN_LATEST // In Gen7, a Pokémon's Speed after Mega Evolution is used to determine turn order, rather than its previous Speed.
#define B_RECALC_TURN_AFTER_ACTIONS GEN_LATEST // In Gen8+, switching or using a move affects the current turn's order of actions, better known as dynamic Speed.
#define B_FAINT_SWITCH_IN           GEN_LATEST // In Gen4+, sending out a new Pokémon after the previous one fainted happens at the end of the turn. Previously, it would happen after each action.
#define B_MEGA_EVO_SPEED_SWAP       GEN_LATEST // In Champions, Mega Evolution does not overwrite the speed stat swapped via Speed Swap.
#define B_FREEZE_TURNS              GEN_LATEST // Prior to Champions, freeze has a 20% chance of being thawed out.
                                               // As of Champions, freeze has a 25% chance of being thawed out with a hard cap of 3 turns.

// Move data settings
#define B_UPDATED_MOVE_DATA         GEN_LATEST // Updates move data in gMovesInfo, including Power, Accuracy, PP, category, range, and additional effects.
#define B_UPDATED_MOVE_TYPES        GEN_LATEST // Updates move types in gMovesInfo.
#define B_UPDATED_MOVE_FLAGS        GEN_LATEST // Updates move flags in gMovesInfo.
#define B_PHYSICAL_SPECIAL_SPLIT    GEN_LATEST // In Gens1-3, a move's type determines if it will do physical or special damage. The category icon in the summary will reflect this.
#define B_RECOIL_IF_MISS_DMG        GEN_LATEST // Crash damage's formula. See EFFECT_RECOIL_IF_MISS.
#define B_KLUTZ_FLING_INTERACTION   GEN_LATEST // In Gen5+, Pokémon with the Klutz Ability can no longer use Fling.
#define B_UPDATED_CONVERSION        GEN_LATEST // In Gen6+, Conversion changes the user's type to match that of their first move. In Gen5 and earlier, it would choose a move at random.
#define B_UPDATED_CONVERSION_2      GEN_LATEST // In Gen5+, Conversion 2 changes the user's type to a type that resists the last move used by the selected target. In Gen4 and earlier, it would consider the last move the user was successfully hit by. Additionally, Struggle was considered Normal-type.
#define B_PP_REDUCED_BY_SPITE       GEN_LATEST // In Gen4+, Spite reduces the PP of the target's last move by 4 instead of 2-5.
#define B_EXTRAPOLATED_MOVE_FLAGS   TRUE       // Adds flags to moves that they don't officially have, but would likely have if they were in the latest core series game.
#define B_HIDDEN_POWER_COUNTER      GEN_LATEST // In Gen3 and earlier, Counter and Mirror Coat treat Hidden Power as physical regardless of type.
#define B_MODERN_TRICK_CHOICE_LOCK  GEN_LATEST // In Gen5+, if a choice item is swapped for another choice item, the Trick/Switcheroo user can choose another move before being locked into it.
#define B_PROTECT_FAILURE_RATE      GEN_LATEST // In Gen5+, protection moves fail 1/3 of the time instead of 1/2.

// Ability data settings
#define B_UPDATED_ABILITY_DATA      GEN_LATEST // Affects flags.

// Move accuracy settings
#define B_TOXIC_NEVER_MISS          GEN_LATEST // In Gen6+, Toxic bypasses accuracy checks when used by Poison-types.
#define B_MINIMIZE_DMG_ACC          GEN_LATEST // In Gen6+, moves that deal double damage to minimized Pokémon will bypass accuracy checks.
#define B_BLIZZARD_HAIL             GEN_LATEST // In Gen4+, Blizzard bypasses accuracy checks if it's hailing.
#define B_SHEER_COLD_ACC            GEN_LATEST // In Gen7+, Sheer Cold's accuracy is reduced to 20% if the user isn't an Ice-type.

// Move stat change settings
#define B_FELL_STINGER_STAT_RAISE   GEN_LATEST // In Gen7+, if Fell Stinger causes the target to faint, the user's Attack raises by 3 stages instead of 2.
#define B_KINGS_SHIELD_LOWER_ATK    GEN_LATEST // In Gen8+, King's Shield lowers the Attack of Pokémon that hit it by 1 stage instead of 2.
#define B_SPEED_BUFFING_RAPID_SPIN  GEN_LATEST // In Gen8+, Rapid Spin raises the user's Speed by 1 stage if it hits.
#define B_CHARGE_SPDEF_RAISE        GEN_LATEST // In Gen5+, Charge raises the user's Sp. Def by 1 stage.
#define B_MINIMIZE_EVASION          GEN_LATEST // In Gen5+, Minimize raises the user's evasion by 2 stages instead of 1.
#define B_GROWTH_STAT_RAISE         GEN_LATEST // In Gen5+, Growth raises the user's Attack in addition to its Sp. Atk. They are each raised by 1 stage normally, and by 2 stages if it's sunny.
#define B_FOCUS_ENERGY_CRIT_RATIO   GEN_LATEST // In Gen3+, Focus Energy raises the critical-hit ratio of the user's moves by 2 stages instead of 1.
#define B_PSYCH_UP_CRIT_RATIO       GEN_LATEST // In Gen6+, Psych Up also copies the target's critical hit ratio.

// Other move settings
#define B_INCINERATE_GEMS               GEN_LATEST // In Gen6+, Incinerate can destroy Gems.
#define B_CAN_SPITE_FAIL                GEN_LATEST // In Gen4+, Spite no longer fails if the target's last move has only 1 PP remaining.
#define B_CRASH_IF_TARGET_IMMUNE        GEN_LATEST // In Gen4+, moves with crash damage will crash if the user attacks a target that is immune due to their typing.
#define B_MEMENTO_FAIL                  GEN_LATEST // In Gen4+, Memento no longer fails if the target already has -6 Attack and Sp. Atk. Additionally, in Gen5+, it fails if there is no target, or if the target is protected or behind a Substitute.
#define B_PARTING_SHOT_SWITCH           GEN_LATEST // In Gen7+, the user won't switch out if Parting Shot fails to lower the target's stats.
#define B_BATON_PASS_TRAPPING           GEN_LATEST // In Gen5+, Baton Pass does not keep trapping effects on other battlers when the user switches out.
#define B_GLARE_GHOST                   GEN_LATEST // In Gen4+, Glare can hit Ghost-type Pokémon.
#define B_SKILL_SWAP                    GEN_LATEST // In Gen4+, Skill Swap triggers switch-in Abilities after use.
#define B_BRICK_BREAK                   GEN_LATEST // In Gen4+, you can destroy your own side's screens. Additionally, in Gen5+, screens are no longer destroyed if the target is immune due to their typing.
#define B_WISH_HP_SOURCE                GEN_LATEST // In Gen5+, Wish heals by half of the user's max HP instead of the recipient's.
#define B_RAMPAGE_CONFUSION             GEN_LATEST // In Gen5+, Rampage is canceled after the move (as opposed to End Turn) and a failed rampage move will cancel the counter, unless it is the last turn.
#define B_HEAL_BLOCKING                 GEN_LATEST // In Gen5+, Heal Block prevents healing by Black Sludge, Leftovers, and Shell Bell. Affected Pokémon will not consume held HP-restoring Berries or Berry Juice. Abilities will not heal but will prevent damage.
                                                   // In Gen6+, Heal Block prevents the use of HP-draining moves, as long as they aren't Z-Moves.
#define B_ROOTED_GROUNDING              GEN_LATEST // In Gen4+, Ingrain causes the user to become grounded.
#define B_METRONOME_MOVES               GEN_LATEST // Determines up to and including which generation Metronome will call moves from.
#define B_TELEPORT_BEHAVIOR             GEN_LATEST // In LGPE onwards (Gen8+ here), Teleport switches the user out instead of fleeing.
#define B_BEAT_UP                       GEN_LATEST // In Gen5+, Beat Up uses a different formula to calculate its damage, and deals Dark-type damage. In Gen4 and earlier, each hit announces the party member's name.
#define B_DARK_VOID_FAIL                GEN_LATEST // In Gen7+, only Darkrai can use Dark Void.
#define B_HIT_THAW                      GEN_LATEST // In Gen6+, damaging moves that thaw the user will thaw the target. In Gen 3+, Fire-type moves thaw the target. In Gen 1-2, damaging moves that can burn will thaw the target, regardless if they can be burned or not.
#define B_HEALING_WISH_SWITCH           GEN_LATEST // In Gen5+, the Pokémon receiving Healing Wish/Lunar Dance is sent out at the end of the turn. Additionally, in Gen8+, the effect will be stored until the user switches into a statused or hurt Pokémon.
#define B_DEFOG_EFFECT_CLEARING         GEN_LATEST // In Gen5+, Defog does not lower the evasion of a target behind a Subsitute. In Gen6+, Defog also clears hazards from the user's side. In Gen8+, Defog also clears active Terrain.
#define B_STOCKPILE_RAISES_DEFS         GEN_LATEST // In Gen4+, Stockpile also raises Defense and Sp. Def stats. Once Spit Up/Swallow is used, these stat changes are lost.
#define B_TRANSFORM_SEMI_INV_FAIL       GEN_LATEST // In Gen2+, Transform fails if the target is semi-invulnerable.
#define B_TRANSFORM_TARGET_FAIL         GEN_LATEST // In Gen2+, Transform fails if the target is already transformed.
#define B_TRANSFORM_USER_FAIL           GEN_LATEST // In Gen5+, Transform fails if the user is already transformed.
#define B_TRANSFORM_SUBSTITUTE_FAIL     GEN_LATEST // In Gen5+, Transform fails if the target is behind a Substitute.
#define B_TRANSFORM_SHINY               GEN_LATEST // In Gen4+, Transform will copy the Shininess of the opponent instead of maintaining its own Shininess.
#define B_TRANSFORM_BATTLE_REWARDS      GEN_LATEST // In Gen3 and Gen 4, a Transform'ed Pokemon will give the xp and ev yield of its copied species whereas it gives the xp and ev yield of the original species in other gens
#define B_TRANSFORM_CATCH_RATE          GEN_LATEST // In Gen3 and Geb 4, Transform'ed will have the catch rate of the tranformed species but they will keep their original catch rate in other generations
#define B_TRANSFORM_FORM_CHANGES        GEN_LATEST // In Gen5+, Transformed Pokémon can no longer change forms.
#define B_WIDE_GUARD                    GEN_LATEST // In Gen5 only, Wide Guard has a chance to fail if used consecutively.
#define B_QUICK_GUARD                   GEN_LATEST // In Gen5 only, Quick Guard has a chance to fail if used consecutively.
#define B_IMPRISON                      GEN_LATEST // In Gen5+, Imprison does not fail if opposing Pokémon don't have any moves the user knows.
#define B_TAUNT_ME_FIRST                GEN_LATEST // In Gen5+, Taunt does not block Me First.
#define B_ALLY_SWITCH_FAIL_CHANCE       GEN_LATEST // In Gen9+, Ally Switch has a chance to fail if used consecutively.
#define B_SKETCH_BANS                   GEN_LATEST // In Gen9+, Sketch is able to copy less moves than in previous generations.
#define B_KNOCK_OFF_REMOVAL             GEN_LATEST // In Gen5+, Knock Off removes the foe's item instead of rendering it unusable.
                                                   // In Champions, Knock Off no longer checks if the target's item is able to change the user's form (i.e. Mega Evolution / Primal Reversion).
#define B_HEAL_BELL_SOUNDPROOF          GEN_LATEST // In Gen6+, Heal Bell affects inactive party members with Soundproof. In Gen5 only, it affects all party members, including active ones. In Gen4 and earlier, it does not affect any Pokémon with Soundproof.
#define B_CHARGE                        GEN_LATEST // In Gen7 and earlier, Charge status is lost regardless of the typing of the next move.
#define B_POWDER_STATUS_HEAVY_RAIN      GEN_LATEST // In Gen7+, Powder no longer damages the user of a Fire-type move in heavy rain.
#define B_AFTER_YOU_TURN_ORDER          GEN_LATEST // In Gen8+, After You no longer fails if the turn order wouldn't change after use.
#define B_QUASH_TURN_ORDER              GEN_LATEST // In Gen8+, Quash-affected battlers move according to Speed order. In Gen7 and earlier, Quash-affected battlers move in the order they were affected by Quash.
#define B_DESTINY_BOND_FAIL             GEN_LATEST // In Gen7+, Destiny Bond fails if used repeatedly.
#define B_FORESIGHT_FAIL                GEN_LATEST // In Gen2 and Gen5+, Foresight fails if used against a target already under its effect.
#define B_MIRACLE_EYE_FAIL              GEN_LATEST // In Gen5+, Miracle Eye fails if used against a target already under its effect.
#define B_PURSUIT_TARGET                GEN_LATEST // In Gen4+, Pursuit automatically targets and attacks any switching opponent. Previously, it only attacked a switching opponent if they were chose as the target.
#define B_SKIP_RECHARGE                 GEN_LATEST // In Gen1 only, moves with recharge turns do not need to recharge if they knock out the target.
#define B_ENCORE_TARGET                 GEN_LATEST // In Gen5+, an encored Pokémon can select the target of its move.
#define B_TIME_OF_DAY_HEALING_MOVES     GEN_LATEST // In Gen2 only, the amount of HP restored by Morning Sun, Synthesis, and Moonlight doubles during the morning, day, and night, respectively.
                                                   // If OW_TIMES_OF_DAY is set to GEN_3, Morning Sun is boosted during the day instead of the morning. If it is set to GEN_4 or higher, Moonlight is also boosted in the evening.
#define B_DREAM_EATER_LIQUID_OOZE       GEN_LATEST // In Gen5+, Dream Eater is affected by Liquid Ooze.
#define B_DREAM_EATER_SUBSTITUTE        GEN_LATEST // In Gen5+, Dream Eater can successfully hit and drain from a Substitute.
#define B_SNATCH                        GEN_LATEST // In Gen5+, Snatch no longer steals moves that were already stolen by another Pokémon's Snatch on the same turn.
#define B_FOCUS_PUNCH_FAILURE           GEN_LATEST // To determine if focus is lost: In Gen7+, check if the current move and the selected move are Focus Punch. In Gens5-6, check if the selected move is Focus Punch. In Gen4 and earlier, check if the current move is Focus Punch.
                                                   // In Gen5+, the check for Focus Punch fail will occur before effects like PP consumption and flinching. In Gen4 and earlier, it was after.
#define B_COUNTER_MIRROR_COAT_ALLY      GEN_LATEST // In Gen5+, an ally's attack does not count for uses of Counter/Mirror Coat/Metal Burst. In Gen4 and earlier, if the last attack taken was from an ally, Counter/Mirror Coat/Metal Burst would fail.
#define B_COUNTER_TRY_HIT_PARTNER       GEN_LATEST // In Gen5+, if the user of the last attack is not on the field, it will be redirected to the partner. In Gen4 and earlier, Counter/Mirror Coat/Metal Burst would fail.
#define B_RAGE_BUILDS                   GEN_LATEST // In Gen4+, Rage's effect only sets in when it successfully hits. In Gen3, Rage's effect sets in regardless of whether it hits, misses or fails.
#define B_CHECK_USER_FAILURE            GEN_LATEST // In Gen5+, The user of a move no longer checks for its own failure, e.g. Soundproof will not block its own Perish Song.
#define B_ABSORB_MESSAGE                GEN_LATEST // In Gen5+, no absorb message is shown if user is already at full HP.
#define B_UPROAR                        GEN_LATEST // In Gen5+, Uproar awakens all battlers on the first turn if successful. In Gen3-4, Uproar allows every battler to awaken before their action or at the end of a turn.
#define B_FIRST_TURN_MOVE               GEN_LATEST // In Champions, Fake Out and First Impression cannot be selected past the user's first turn.
#define B_SALT_CURE_DAMAGE              GEN_LATEST // In Gen9, Salt Cure deals 1/8 max HP (1/4 max HP to Steel and Water)
                                                   // In Champions, Salt Cure deals 1/16 max HP (1/8 max HP to Steel and Water)
#define B_BELCH_SELECTABLE              GEN_LATEST // In Gen6-9, Belch cannot be selected unless the user has eaten a Berry
                                                   // In Champions, Belch can be selected regardless of the user eating the Berry
#define B_STUFF_CHEEKS_SELECTABLE       GEN_LATEST // In Gen8-9, Stuff Cheeks cannot be selected unless the user is holding a Berry
                                                   // In Champions, Stuff Cheeks can be selected regardless of the user holding the Berry
#define B_SPIT_UP_SELECTABLE            GEN_LATEST // In Champions, Spit Up cannot be selected unless the user has Stockpile stacks
#define B_MOVES_THAT_REMOVE_TYPE        GEN_LATEST // In Champions, Burn Up cannot be selected if the user is not Fire-type
#define B_LAST_RESORT_SELECTABLE        GEN_LATEST // In Champions, Last Resort cannot be selected if the user hasn't used all its other moves
#define B_FAINT_MOVE_EFFECT_TIMING      GEN_LATEST // In Champions, some move effects now apply even if the user faints from Rough Skin, Iron Barbs, etc.
                                                   // Effects include: Knock Off, Thief, Rapid Spin, Mortal Spin, Ice Spinner
                                                   // This does not include: Ceaseless Edge, Stone Axe
#define B_SHEER_FORCE_AGAINST_ABILITIES GEN_LATEST // As of Champions, Sheer Force no longer prevents the activation of Berserk and Pickpocket
                                                   // Currently does nothing, as there is not enough info to confirm event orders for cases like Eject Pack and Eject Button
#define B_ENCORE_PRIORITY               GEN_LATEST // In Champions, Encore uses the priority of the Encored move instead of the selected move
                                                   // In Gen9-, Encore allows the target to use the Encored move using the priority of the selected move
#define B_RAGE_FIST                     GEN_LATEST // In Champions, Rage Fist stacks reset upon switching out or fainting
#define B_MOVE_EFFECTS_BEFORE_MOVES     GEN_LATEST // In Champions, Beak Blast will work when Encored into from a different move
                                                   // Additionally, the charging animation will occur 

// Ability settings
#define B_GALE_WINGS                    GEN_LATEST // In Gen7+, Gale Wings requires full HP to trigger.
#define B_STANCE_CHANGE_FAIL            GEN_LATEST // In Gen7+, Stance Change fails if the Pokémon is unable to use a move due to confusion, paralysis, etc.
#define B_SHADOW_TAG_ESCAPE             GEN_LATEST // In Gen4+, if both sides have a Pokémon with Shadow Tag, all battlers can escape. Previously, neither side could escape this situation.
#define B_MOODY_ACC_EVASION             GEN_LATEST // In Gen8+, Moody can no longer raise accuracy and evasion.
#define B_FLASH_FIRE_FROZEN             GEN_LATEST // In Gen5+, Flash Fire activates even when frozen.
#define B_SYNCHRONIZE_TOXIC             GEN_LATEST // In Gen5+, if a Pokémon with Synchronize is badly poisoned, the opponent will also become badly poisoned. Previously, the opponent would be inflicted with regular poison.
#define B_UPDATED_INTIMIDATE            GEN_LATEST // In Gen8+, Intimidate no longer works on opponents with the Inner Focus, Scrappy, Own Tempo or Oblivious Abilities. It also activates Rattled.
#define B_OBLIVIOUS_TAUNT               GEN_LATEST // In Gen6+, Pokémon with Oblivious can no longer be taunted.
#define B_STURDY                        GEN_LATEST // In Gen5+, Sturdy causes a Pokémon to have 1 HP remaining if another Pokémon's attack or confusion damage would have knocked it out from full HP.
#define B_PLUS_MINUS_INTERACTION        GEN_LATEST // In Gen5+, Plus and Minus can be activated by themselves in addition to the opposite Ability.
#define B_WEATHER_FORMS                 GEN_LATEST // In Gen5+, Castform and Cherrim revert to their base form upon losing their respective Ability. Cherrim needs Flower Gift to change forms.
#define B_SYMBIOSIS_GEMS                GEN_LATEST // In Gen7+, Symbiosis passes an item after a Gem-boosted attack. Previously, items were passed before the Gem-boosted attack hit, making the item's effect apply.
#define B_REDIRECT_ABILITY_IMMUNITY     GEN_LATEST // In Gen5+, Pokémon with Lightning Rod/Storm Drain are immune to Electric-/Water-type moves and raises their Sp. Atk by 1 stage ontop of the redirecting effect.
#define B_REDIRECT_ABILITY_ALLIES       GEN_LATEST // In Gen4+, Lightning Rod and Storm Drain also redirect ally's moves.
#define B_LEAF_GUARD_PREVENTS_REST      GEN_LATEST // In Gen5+, Leaf Guard prevents the use of Rest in the sun.
#define B_TRANSISTOR_BOOST              GEN_LATEST // In Gen9+, Transistor increases the power of Electric-type moves by 1.3x instead of 1.5x.
#define B_ILLUMINATE_EFFECT             GEN_LATEST // In Gen9+, Illuminate prevents accuracy from being lowered and ignores the target's evasion. Previously, it had no in-battle effect.
#define B_WEAK_ARMOR_SPEED              GEN_LATEST // In Gen7+, when hit by a physical move, Weak Armor raises Speed by 2 stages instead of 1.
#define B_PROTEAN_LIBERO                GEN_LATEST // In Gen9+, Protean and Libero trigger only once per Battle.
#define B_INTREPID_SWORD                GEN_LATEST // In Gen9+, Intrepid Sword triggers only once per battle.
#define B_DAUNTLESS_SHIELD              GEN_LATEST // In Gen9+, Dauntless Shield triggers only once per battle.
#define B_DISGUISE_HP_LOSS              GEN_LATEST // In Gen8+, when a disguised Mimikyu's Disguise is busted, upon changing to its Busted Form, it loses 1/8 of its max HP.
#define B_ABILITY_TRIGGER_CHANCE        GEN_LATEST // In Gen4+, Shed Skin, Cute Charm, Flame Body, Static, and Poison Point have a 30% chance to trigger. Previously, it was 1/3.
                                                   // In Gen5+, Effect Spore has an 11% chance to sleep, a 9% chance to poison and a 10% chance to paralyze. In Gen4, Effect Spore has a 30% chance to sleep, poison, or paralyze, each with an equal chance. In Gen3, it's 10%.
#define B_PICKUP_WILD                   GEN_LATEST // In Gen9+, Pickup allows its user to pick up its own used item at the end of the turn in wild battles.
#define B_MAGIC_GUARD                   GEN_LATEST // In Gen4 only, Magic Guard ignores immobilization caused by paralysis.
#define B_BATTLE_BOND                   GEN_LATEST // In Gen9+, Battle Bond raises Attack, Sp. Atk, and Speed by 1 stage, once per battle. Previously, the Pokémon would change into Ash-Greninja.
#define B_ATE_MULTIPLIER                GEN_LATEST // In Gen7+, -ate Abilities (Aerilate, Galvanize, Normalize, Pixilate, Refrigerate) increase damage by 1.2x. In Gen6 and earlier, it was 1.3x, except Normalize, which had no multiplier.
#define B_DEFIANT_STICKY_WEB            GEN_LATEST // In Gen9+, Defiant triggers on Sticky Web regardless of who set it up. In Gen8, it does not trigger on a Sticky Web set up by an ally after Court Change swaps its side.
#define B_MIRROR_ARMOR_STICKY_WEB       GEN_LATEST // In Gen9+, Mirror Armor does not reflect the Sticky Web stat change even if the original Sticky Web user is still on the field
#define B_POWDER_OVERCOAT               GEN_LATEST // In Gen6+, Overcoat blocks powder and spore moves.
#define B_INFILTRATOR_SUBSTITUTE        GEN_LATEST // In Gen6+, Infiltrator bypasses Substitute when using a move, excluding Transform and Sky Drop.
#define B_DANCER_ORDER                  GEN_LATEST // In Gen8+, Dancer activations are based on Speed order including modifiers. In Gen7, Dancer activates from the slowest to fastest battler based on the battler's unmodified Speed stat.
#define B_UNSEEN_FIST_PIERCING_DRILL    GEN_LATEST // In Gen8-9, Unseen Fist/Piercing Drill deals 100% of the damage dealt to protected targets while also bypassing the contact effects of protect moves.
                                                   // In Champions, Unseen Fist/Piercing Drill nerfs damage dealt against protected targets to 25%. It also no longer bypasses the contact effects of protect moves.

// Various volatile timers
#define B_CONFUSION_TURNS    5
#define B_UPROAR_TURN_COUNT  5
#define B_RAMPAGE_TURNS      3
#define B_DISABLE_TIMER      4
#define B_ENCORE_TIMER       4
#define B_PERISH_SONG_TIMER  3
#define B_TAUNT_TIMER        5
#define B_SLOW_START_TIMER   5
#define B_EMBARGO_TIMER      5
#define B_MAGNET_RISE_TIMER  5
#define B_TELEKINESIS_TIMER  3
#define B_HEAL_BLOCK_TIMER   5
#define B_LASER_FOCUS_TIMER  2
#define B_THROAT_CHOP_TIMER  2
#define B_WRAP_TURNS         7 // Max number of turns with a Grip Claw.
#define B_SYRUP_BOMB_TIMER   3
#define B_TORMENT_TIMER      3

// Item settings
#define B_CONFUSE_BERRIES_HEAL      GEN_LATEST // In Gen8+, Figy and similar Berries heal 1/3 of max HP and activate at 25% HP. In Gen7, they restore half HP and activate at 25% HP. In Gen6 and earlier, they restore 1/8 of max HP and activate at half HP.
#define B_X_ITEMS_BUFF              GEN_LATEST // In Gen7+, X items raise a stat by 2 stages instead of 1.
#define B_X_ITEMS_CROSSUSE          TRUE       // In Gen3, you can only use X items on the current battler, but in Gen7 you can use an X item on any friendly battler in double battles (we are not sure in which gen the change occured)
#define B_MENTAL_HERB               GEN_LATEST // In Gen5+, Mental Herb cures Taunt, Encore, Torment, Heal Block, and Disable in addition to Infatuation from before.
#define B_TRAINERS_KNOCK_OFF_ITEMS  TRUE       // If TRUE, Trainers can steal/swap your items (non-berries are restored after battle). In vanilla games, Trainers cannot steal items outside of facilities.
#define B_RETURN_STOLEN_NPC_ITEMS   GEN_LATEST // In Gen5+, Thief and Covet no longer permanently steal items from NPCs.
#define B_STEAL_WILD_ITEMS          GEN_LATEST // In Gen9+, Thief and Covet steal a wild Pokémon's item and send it to the Bag. In Gen8 and earlier, the stolen item would be held by the Thief/Covet user.
#define B_RESTORE_HELD_BATTLE_ITEMS GEN_LATEST // In Gen9+, all non-Berry items are restored after battle.
#define B_SOUL_DEW_BOOST            GEN_LATEST // In Gen7+, Soul Dew increases the power of the Latis' Psychic- and Dragon-type moves by ~20%. In Gen6 and earlier, it increased their Sp. Atk and Sp. Def by 50% each.
#define B_NET_BALL_MODIFIER         GEN_LATEST // In Gen7+, Net Ball's catch multiplier is 5x instead of 3x.
#define B_DIVE_BALL_MODIFIER        GEN_LATEST // In Gen4+, Dive Ball's effectiveness increases when Surfing or Fishing in addition to Diving.
#define B_NEST_BALL_MODIFIER        GEN_LATEST // Nest Ball's formula varies depending on the generation. See Cmd_handleballthrow.
#define B_REPEAT_BALL_MODIFIER      GEN_LATEST // In Gen7+, Repeat Ball's catch multiplier is 3.5x instead of 3x.
#define B_TIMER_BALL_MODIFIER       GEN_LATEST // In Gen5+, Timer Ball's effectiveness increases by 0.3x per turn instead of 0.1x.
#define B_DUSK_BALL_MODIFIER        GEN_LATEST // In Gen7+, Dusk Ball's catch multiplier is 3x instead of 3.5x.
#define B_QUICK_BALL_MODIFIER       GEN_LATEST // In Gen5+, Quick Ball's catch multiplier is 5x instead of 4x.
#define B_LURE_BALL_MODIFIER        GEN_LATEST // In Gen8+, Lure Ball's catch multiplier is 4x. In Gen7, it's 5x. In Gen6 and earlier, it's 3x.
#define B_HEAVY_BALL_MODIFIER       GEN_LATEST // Heavy Ball's ranges. See Cmd_handleballthrow.
#define B_DREAM_BALL_MODIFIER       GEN_LATEST // In Gen8+, Dream Ball's catch multiplier is 4x when the target is asleep or has the Ability Comatose.
#define B_SPORT_BALL_MODIFIER       GEN_LATEST // In Gen8+, Sport Ball's catch multiplier was reduced from 1.5x to 1x.
#define B_SAFARI_BALL_MODIFIER      GEN_LATEST // In Gen8+, Safari Ball's catch multiplier is 1x. In Gens2-6, it's 1.5x. In Gen1, it's 2x.
#define B_FRIEND_BALL_MODIFIER      GEN_LATEST // In Gen8+, the initial friendship of Pokémon caught in a Friend Ball friendship was reduced from 200 to 150.
#define B_SERENE_GRACE_BOOST        GEN_LATEST // In Gen5+, Serene Grace boosts the added flinch chance of King's Rock and Razor Fang.
#define B_IRON_BALL                 GEN_LATEST // In Gen5+, Flying-type Pokémon holding an Iron Ball take neutral damage from Ground-type moves regardless of their other types, except during Inverse Battles or if the Pokémon is grounded by any other effect.

// Flag settings
// To use the following features, change the 0 for a flag present in include/constants/flags.h, preferably an unused one.
// Eg: You may rename FLAG_UNUSED_0x264 to a descriptive name and use it below.

// Badge boost flags
#define B_FLAG_BADGE_BOOST_ATTACK   FLAG_BADGE01_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will increase the Attack of the player's Pokémon.
#define B_FLAG_BADGE_BOOST_DEFENSE  FLAG_BADGE05_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will increase the Defense of the player's Pokémon.
#define B_FLAG_BADGE_BOOST_SPEED    FLAG_BADGE03_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will increase the Speed of the player's Pokémon.
#define B_FLAG_BADGE_BOOST_SPATK    FLAG_BADGE07_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will increase the Sp. Atk of the player's Pokémon.
#define B_FLAG_BADGE_BOOST_SPDEF    FLAG_BADGE07_GET // If this flag is set and B_BADGE_BOOST == GEN_3, it will increase the Sp. Def of the player's Pokémon.
// Other battle flags
#define B_FLAG_INVERSE_BATTLE       0     // If this flag is set, the battle's type chart inverted. For example, Fire is super effective against Water.
#define B_FLAG_AI_VS_AI_BATTLE      0     // If this flag is set, the player's Pokémon will be controlled by the AI in the next battle.
#define B_FLAG_DYNAMAX_BATTLE       0     // If this flag is set, the ability to Dynamax in battle is enabled for all Trainers.
#define B_FLAG_TERA_ORB_CHARGED     0     // If this flag is set, the Tera Orb is charged. It is automatically set upon healing and cleared upon Terastallizing once configured.
#define B_FLAG_TERA_ORB_NO_COST     0     // If this flag is set, the Tera Orb does not use up its charge upon Terastallization. In SV, this occurs after an event with Terapagos.
#define B_FLAG_SLEEP_CLAUSE         0     // If this flag is set, sleep clause is enabled; if a Pokémon on the one side of the field is asleep, another one on that side cannot be put to sleep. AI requires AI_FLAG_CHECK_BAD_MOVE to understand.
#define B_FLAG_NO_WHITEOUT          0     // If this flag is set, the player can not white out against Trainers. Please note that the party is not healed automatically!

// Var Settings
// To use the following features, change the 0 for a var present in include/constants/vars.h, preferably an unused one.
// Eg: You may rename VAR_UNUSED_0x404E to a descriptive name and use it below.
#define B_VAR_WILD_AI_FLAGS         0     // If not 0, you can use this var to add to default wild AI flags. IMPORTANT: NOT usable with flags above (1 << 15)
                                          // This var should never remain non-zero long enough for the player to save.
                                          // For better wild AI handling, edit GetWildAiFlags() in src/battle_ai_main.c

#define B_VAR_DIFFICULTY            0     // If not 0, you can use this var to control which difficulty version of a Trainer is loaded. This should be manually set by the developer using Script_SetDifficulty AFTER NewGameInitData has run.

// No Bag settings
#define NO_BAG_RESTRICTION       0
#define NO_BAG_AGAINST_TRAINER   1
#define NO_BAG_IN_BATTLE         2
#define NO_BAG_INVALID_VALUE     3

#define B_VAR_NO_BAG_USE         0     // If set to 1, the ability to use the Bag is disabled in Trainer battles. If set to 2, it is also disabled in wild battles.

// Sky Battles
#define B_FLAG_SKY_BATTLE                 0     // If this flag has a value, the player will be able to engage in scripted Sky Battles.
#define B_VAR_SKY_BATTLE                  0     // If this var has a value, the game will remember the positions of Pokémon used in Sky Battles.
#define B_SKY_BATTLE_STRICT_ELIGIBILITY   FALSE // If TRUE, Sky Battles will use the eligibility from X and Y. If FALSE, all Flying-types and Pokémon with Levitate are allowed.

// Flag and Var settings
#define B_RESET_FLAGS_VARS_AFTER_WHITEOUT TRUE // If TRUE, Overworld_ResetBattleFlagsAndVars will reset battle-related flags and vars when the player whites out.

// Ingame partner flag
#define B_SHOW_PARTNER_TARGET             FALSE // Shows the battler partner will target.

// Move description menu
#define B_SHOW_MOVE_DESCRIPTION     TRUE       // Shows move information in battler

// Weather settings
// Search for 'rain', 'sunny day', and 'hail' for move-specific or species-specific weather interactions.
#define B_ICE_WEATHER_BOTH              0
#define B_ICE_WEATHER_HAIL              1
#define B_ICE_WEATHER_SNOW              2

#define B_ABILITY_WEATHER               GEN_LATEST // In Gen6+, Ability-induced weather lasts 5 turns. In Gen5 and earlier, it lasted until the battle ended or until it was changed by another weather condition.
#define B_SANDSTORM_SPDEF_BOOST         GEN_LATEST // In Gen4+, sandstorm increases the Sp. Def of Rock-type Pokémon by 1.5x.
#define B_SANDSTORM_SOLAR_BEAM          GEN_LATEST // In Gen3+, sandstorm decreases the power of Solar Beam.
#define B_OVERWORLD_FOG                 GEN_LATEST // In Gen8+, overworld fog summons Misty Terrain in battle. In Gen4 only, overworld fog summons the unique fog weather condition in battle.
#define B_OVERWORLD_SNOW                GEN_LATEST // In Gen9+, overworld snow will summon snow instead of hail in battle.
#define B_SNOW_WARNING                  GEN_LATEST // In Gen9+, Snow Warning will summon snow instead of hail.
#define B_PREFERRED_ICE_WEATHER         B_ICE_WEATHER_BOTH // Toggles hail move effects to snow and vice versa.
#define B_OVERWORLD_WEATHER_OVERRIDE    GEN_LATEST // In Gen9+, overworld weather cannot be overridden.

// Terrain settings
#define B_TERRAIN_BG_CHANGE         TRUE       // If set to TRUE, terrain moves permanently change the default battle background until the effect fades.
#define B_THUNDERSTORM_TERRAIN      TRUE       // If set to TRUE, overworld Thunderstorm summons rain and Electric Terrain as in Gen8.
#define B_TERRAIN_TYPE_BOOST        GEN_LATEST // In Gen8+, terrain increases the power of same-type moves by 30% instead of 50%.
#define B_SECRET_POWER_EFFECT       GEN_LATEST // Secret Power's effects change depending on the terrain and generation. See MOVE_EFFECT_SECRET_POWER's case in `SetMoveEffect`.
#define B_SECRET_POWER_ANIMATION    GEN_LATEST // Secret Power's animations change depending on the terrain and generation.
#define B_NATURE_POWER_MOVES        GEN_LATEST // Nature Power calls different moves depending on the terrain and generation. See gBattleEnvironmentInfo.
#define B_CAMOUFLAGE_TYPES          GEN_LATEST // Camouflage changes the user to different types depending on the terrain and generation. See sTerrainToType.
#define B_NEW_TERRAIN_BACKGROUNDS   FALSE      // If set to TRUE, uses new terrain backgrounds for Electric, Misty, Grassy and Psychic Terrain.

// Interface settings
#define B_FAST_INTRO_PKMN_TEXT              TRUE       // If set to TRUE, battle intro text prints at the same time as the animation of Pokémon, as opposing to waiting for the animation to end.
#define B_FAST_INTRO_NO_SLIDE               FALSE      // If set to TRUE, the slide animation that happens at the beginning of battles is skipped.
#define B_FAST_HP_DRAIN                     TRUE       // If set to TRUE, HP bars will move faster.
#define B_FAST_EXP_GROW                     TRUE       // If set to TRUE, EXP bars will move faster.
#define B_SHOW_TARGETS                      TRUE       // If set to TRUE, all available targets will be shown before selecting a move in Double Battles.
#define B_SHOW_CATEGORY_ICON                TRUE       // If set to TRUE, an icon in the summary and move relearner will show a move's category.
#define B_HIDE_HEALTHBOX_IN_ANIMS           TRUE       // If set to TRUE, healthboxes will be hidden during move animations.
#define B_WAIT_TIME_MULTIPLIER              16         // This determines how long text pauses for in battle. Vanilla is 16. Lower values result in faster battles.
#define B_QUICK_MOVE_CURSOR_TO_RUN          FALSE      // If set to TRUE, pushing B in the battle menu in a wild encounter will move the cursor to the Run option.
#define B_RUN_TRAINER_BATTLE                TRUE       // If set to TRUE, players can run from Trainer battles as in Gen9+. This is treated as a white out.
#define B_MOVE_DESCRIPTION_BUTTON           L_BUTTON   // If set to a button other than B_LAST_USED_BALL_BUTTON, pressing this button will open the move description menu.
#define B_SHOW_USELESS_Z_MOVE_INFO          FALSE      // If set to TRUE, Z-Moves without additional effects, like newer generation status moves, will say "No additional effect."
#define B_ANIMATE_MON_AFTER_KO              TRUE       // If set to TRUE, if a Pokémon on the opposing side faints, the non-fainted Pokémon will play their animations.
#define B_ANIMATE_MON_AFTER_FAILED_POKEBALL TRUE       // If set to TRUE, a wild Pokémon that breaks of a thrown Poké Ball will play its animation.
#define B_SHOW_DYNAMAX_MESSAGE              FALSE      // If set to TRUE, an additional battle message is shown after Dynamaxing or Gigantamaxing.
#define B_HPBAR_COLOR_THRESHOLD             GEN_LATEST // In Gen5+, HP bar color thresholds were changed to be based on the actual HP values instead of the pixel length of the HP bar, leading to more accurate HP bar colors.
#define B_HP_PERCENTAGE_DISPLAY             FALSE      // If set to TRUE, Pokémon on the opposing side's HP will be displayed in percentage alongside the HP bar. In single battles, this extends the healthbox to add the percentage below the HP bar. In double battles, the same input used to toggle your side's HP values will also toggle the opposing side's percentage display.

// Catching settings
#define B_SEMI_INVULNERABLE_CATCH       GEN_LATEST // In Gen4+, you cannot throw a ball against a Pokémon that is in a semi-invulnerable state (Dig/Fly/etc).
#define B_CATCHING_CHARM_BOOST          100        // % increase in critical capture odds if the player has the Catching Charm.
#define B_INCAPACITATED_CATCH_BONUS     GEN_LATEST // In Gen5+, the catch rate bonus for a sleeping or frozen Pokémon is 2.5x instead of 2x.
#define B_LOW_LEVEL_CATCH_BONUS         GEN_LATEST // In Gen9+, a bonus is added to the catch rate when catching a Pokémon lower than level 13. In Gen8, the bonus is applied to Pokémon lower than level 20.
#define B_MISSING_BADGE_CATCH_MALUS     GEN_LATEST // In Gen9+, a penalty is added to the catch rate when trying to catch a Pokémon 5 levels above the current obedience level, based on the number of Badges obtained.
#define B_CRITICAL_CAPTURE              TRUE       // If set to TRUE, Critical Captures will be enabled.
#define B_CRITICAL_CAPTURE_LOCAL_DEX    TRUE       // If set to FALSE, the Critical Capture chance is based off of the National Pokédex, estimated by enabled generations.
#define B_CRITICAL_CAPTURE_IF_OWNED     GEN_LATEST // In Gen9+, a capture will appear critical if the Pokémon you're trying to catch is of a species that you have already caught.
#define B_FLAG_VICTORY_CATCH_RANDOM     0          // If set, you will be prompted to throw a ball after the encounter has been defeated, catch rate is random. You can't capture the encounter in any other way.
#define B_FLAG_VICTORY_CATCH_GUARANTEED 0          // If set, you will be prompted to throw a ball after the encounter has been defeated, guaranteed to catch. You can't capture the encounter in any other way.

#define B_LAST_USED_BALL            TRUE       // If set to TRUE, the "last used Ball" feature from Gen7+ will be implemented
#define B_LAST_USED_BALL_BUTTON     R_BUTTON   // If last used Ball is implemented, this button (or button combination) will trigger throwing the last used Ball.
#define B_LAST_USED_BALL_CYCLE      TRUE       // If set to TRUE, then holding B_LAST_USED_BALL_BUTTON while pressing the D-Pad cycles through the Balls.
#define B_CATCH_SWAP_INTO_PARTY     GEN_LATEST // In Gen7+, the option to swap caught Pokémon into the party will appear, allowing you to send a different Pokémon to the Box.
#define B_CATCH_SWAP_CHECK_HMS      TRUE       // If set to TRUE, the catch swap feature above will prevent returning Pokémon to the Box if they know HMs.

// Other settings
#define B_MULTI_BATTLE_WHITEOUT         GEN_LATEST // In Gen4+, Multi Battles end when the player as well as their partner don't have any Pokémon left.
#define B_EVOLUTION_AFTER_WHITEOUT      GEN_LATEST // In Gen6+, Pokémon that qualify for evolution after battle will evolve even if the player loses.
#define B_AFFECTION_MECHANICS           TRUE       // In Gen6+, there's a stat called affection that can trigger different effects in battle. From LGPE onwards, these effects use friendship instead.
#define B_TRAINER_CLASS_POKE_BALLS      GEN_LATEST // In Gen7+, Trainers will use certain kinds of Poké Balls depending on their Trainer class.
#define B_TRAINER_MON_RANDOM_ABILITY    0          // If this is set to 0, trainers mons with no set ability only use the first ability of a mon. If set to 1 it will roll a random non-hidden ability. If set to 2, it will roll any ability (including hidden ability) with equal chance
#define B_OBEDIENCE_MECHANICS           GEN_LATEST // In PLA onwards (GEN_8 here), obedience restrictions also apply to non-outsider Pokémon, albeit based on their met level rather than their current level.
#define B_USE_FROSTBITE                 FALSE      // In PLA, Frostbite replaces Freeze. Enabling this flag does the same here. Moves can still be cherry-picked to either Freeze or Frostbite. Freeze-Dry, Secret Power & Tri Attack depend on this config.
#define B_TOXIC_REVERSAL                GEN_LATEST // In Gen5+, bad poison will change to regular poison at the end of battles.
#define B_TRY_CATCH_TRAINER_BALL        GEN_LATEST // In Gen4+, trying to catch a Trainer's Pokémon no longers consume the Poké Ball.
#define B_SLEEP_CLAUSE                  FALSE      // Enables Sleep Clause all the time in every case, overriding B_FLAG_SLEEP_CLAUSE. Use that for modularity.
#define B_PARTNER_MONS_MARKED_SEEN      FALSE      // If set to TRUE, if your Double Battle partner sends out a Pokémon you haven't encountered yet, it will be marked as SEEN in your Pokédex.
#define B_MULTI_HALF_TEAMS              FALSE      // If TRUE, trainers will be capped at 3 Pokémon each when there are 2 trainers on one side in a battle. If FALSE, per-battle capping may still be set using `Multi Party: Half` in `trainers.party`
#define B_TERA_ORB_ALWAYS_CHARGED       FALSE      // If TRUE, causes the Tera Orb to always be charged all the time in every case, overriding B_FLAG_TERA_ORB_CHARGED. Use that for modularity.

#define NUM_BEEPS_GEN_LATEST            4                    // Loops 4 times
#define NUM_BEEPS_GEN_3                 -1                   // Loops infinitely
#define NUM_BEEPS_OFF                   0                    // Does not play at all
#define B_NUM_LOW_HEALTH_BEEPS          NUM_BEEPS_GEN_LATEST // This controls the number of times the "low HP" beep will loop. Setting this value to NUM_BEEPS_OFF will disable the beep, while NUM_BEEPS_GEN_3 will loop infinitely. You can set this to any number you want, the defines listed are just for ease of use.

// Animation Settings
#define B_NEW_SWORD_PARTICLE            FALSE    // If set to TRUE, it updates Swords Dance's particle.
#define B_NEW_LEECH_SEED_PARTICLE       FALSE    // If set to TRUE, it updates Leech Seed's particle.
#define B_NEW_HORN_ATTACK_PARTICLE      FALSE    // If set to TRUE, it updates Horn Attack's horn particle.
#define B_NEW_ROCKS_PARTICLE            FALSE    // If set to TRUE, it updates rock particles.
#define B_NEW_LEAF_PARTICLE             FALSE    // If set to TRUE, it updates the leaf particle.
#define B_NEW_EMBER_PARTICLES           FALSE    // If set to TRUE, it updates Ember's fire particle.
#define B_NEW_MEAN_LOOK_PARTICLE        FALSE    // If set to TRUE, it updates Mean Look's eye particle.
#define B_NEW_TEETH_PARTICLE            FALSE    // If set to TRUE, it updates Bite/Crunch teeth particle.
#define B_NEW_HANDS_FEET_PARTICLE       FALSE    // If set to TRUE, it updates chop/kick/punch particles.
#define B_NEW_SPIKES_PARTICLE           FALSE    // If set to TRUE, it updates Spikes' particle.
#define B_NEW_FLY_BUBBLE_PARTICLE       FALSE    // If set to TRUE, it updates Fly's 'bubble' particle.
#define B_NEW_CURSE_NAIL_PARTICLE       FALSE    // If set to TRUE, it updates Curse's nail particle.
#define B_NEW_BATON_PASS_BALL_PARTICLE  FALSE    // If set to TRUE, it updates Baton Pass' Poké Ball particle.
#define B_NEW_MORNING_SUN_STAR_PARTICLE FALSE    // If set to TRUE, it updates Morning Sun's star particles.
#define B_NEW_IMPACT_PALETTE            FALSE    // If set to TRUE, it updates the basic impact palette.
#define B_NEW_SURF_PARTICLE_PALETTE     FALSE    // If set to TRUE, it updates Surf's wave palette.

// Poké Ball animation and sounds
#define B_ENEMY_THROW_BALLS          GEN_LATEST  // In Gen6+, enemy Trainers throw Poké Balls into battle instead of them just appearing on the ground and opening.
#define B_ENEMY_THROW_BALLS_SOUND    GEN_LATEST  // In Gen5+, enemy Trainer's Poké Balls make a sound when thrown to send out a Pokémon. This can only be used when B_ENEMY_THROW_BALLS is set to GEN_6 or later.
#define B_PLAYER_THROW_BALLS_SOUND   GEN_LATEST  // In Gen5+, the player's Poké Balls make a sound when thrown to send out a Pokémon.

#define SHOW_TYPES_NEVER    0                    // Never show types in battle.
#define SHOW_TYPES_ALWAYS   1                    // Always show types in battle.
#define SHOW_TYPES_CAUGHT   2                    // Only show types if you've caught a Pokémon of that species.
#define SHOW_TYPES_SEEN     3                    // Only show types if you've seen a Pokémon of that species.
#define B_SHOW_TYPES        SHOW_TYPES_NEVER     // When to show type indicators next to Pokémon HP bars, while choosing a move after selecting a target Pokémon.

#define SHOW_EFFECTIVENESS_NEVER    0           // Never show type effectiveness when selecting moves.
#define SHOW_EFFECTIVENESS_ALWAYS   1           // Always show type effectiveness when selecting moves.
#define SHOW_EFFECTIVENESS_CAUGHT   2           // Only show type effectiveness if you've caught a Pokémon of that species.
#define SHOW_EFFECTIVENESS_SEEN     3           // Only show type effectiveness if you've seen a Pokémon of that species.
#define B_SHOW_EFFECTIVENESS        SHOW_EFFECTIVENESS_SEEN // If not SHOW_EFFECTIVENESS_NEVER, the PP string is replaced by a type effectiveness indicator based on the move and the target.

// Pokémon battle sprite settings
#define B_ENEMY_MON_SHADOW_STYLE        GEN_LATEST // In Gen4+, all opposing Pokémon will have a shadow drawn beneath them.

//  Battle UI settings
#define B_MOVE_REARRANGEMENT_IN_BATTLE  GEN_LATEST  //  In Gen4+, move slots can no longer be rearranged in battle.

#define B_POOL_SETTING_CONSISTENT_RNG       FALSE    // If set to TRUE, the same Trainer will always generate the same pool on the same save file.
#define B_POOL_SETTING_USE_FIXED_SEED       FALSE    // If set to TRUE, RNG will use the fixed seed defined in B_POOL_SETTING_FIXED_SEED.
#define B_POOL_SETTING_FIXED_SEED           0x1D4127 // "Random" number. Unless a mistake was made, it's へだら in the Emerald charmap, which should spell he-da-ra.
#define B_POOL_RULE_SPECIES_CLAUSE          FALSE    // Only pick a single Pokémon of a unique National Pokédex number.
#define B_POOL_RULE_EXCLUDE_FORMS           FALSE    // Exclude different forms from Species Clause.
#define B_POOL_RULE_ITEM_CLAUSE             FALSE    // Only allow each item to be picked once.
#define B_POOL_RULES_USE_ITEM_EXCLUSIONS    FALSE    // Exclude items listed in poolItemClauseExclusions.
#define B_POOL_RULE_MEGA_STONE_CLAUSE       FALSE    // Pick only 1 Pokémon with a Mega Stone.
#define B_POOL_RULE_Z_CRYSTAL_CLAUSE        FALSE    // Pick only 1 Pokémon with a Z-Crystal.

#endif // GUARD_CONFIG_BATTLE_H
