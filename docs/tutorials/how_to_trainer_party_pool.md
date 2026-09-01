# How to use Trainer Party Pools
Trainer Party Pools (TPP) is a way to introduce a bit of unpredictability to trainer battles by allowing trainer to generate parties from pools defined by the user.

The maximum number of mons that can be in a single trainer's pool is 255.

## Turning on TPP with `trainers.party`
To use TPP with `trainers.party`, all that's needed is to define a `Party Size` that's smaller than than the number of defined mons for the trainer.

## Turning on TPP with `trainers.h`
To use TPP with `trainers.h`, the trainer need to have the `.poolSize` field set to a value that's larger than the `.partySize` and equal to the number of mons defined in the trainer.

## How the pool works
When generating a party for a trainer with a pool, the party is picked from the pool randomly according to rules set for the pool and tags assigned to individual mons in the pool.

### Pool Rules
Pool rules are defined in `src/data/battle_pool_rules.h`. To begin with some default pools are defined, `defaultPoolRules` which any trainer that doesn't otherwise have a specified pool ruleset uses, and some custom rules for common scenarios.

- `POOL_RULESET_BASIC`, a ruleset that will pick a mon from the pool with the tag `MON_POOL_TAG_LEAD` if possible to put in the first slot and `MON_POOL_TAG_ACE` in the last slot, and not pick mons with those tags for any other position.
- `POOL_RULESET_DOUBLES`, a ruleset that will pick up to two mons from the pool with the tag `MON_POOL_TAG_LEAD` if possible to put in the first two slots and `MON_POOL_TAG_ACE` in the last two slots, and not pick mons with those tags for any other position.
- `POOL_RULESET_WEATHER_SINGLES`, a ruleset that will pick at most one mon with the tag `MON_POOL_TAG_WEATHER_SETTER` if possible, and at least one mon with the tag `MON_POOL_TAG_WEATHER_ABUSER` if possible, in addition to the same conditions as `POOL_RULESET_BASIC`.
- `POOL_RULESET_WEATHER_DOUBLES`, a ruleset that will pick at most one mon with the tag `MON_POOL_TAG_WEATHER_SETTER` if possible, and at least one mon with the tag `MON_POOL_TAG_WEATHER_ABUSER` if possible, in addition to the same conditions as `POOL_RULESET_DOUBLES`.
- `POOL_RULESET_SUPPORT_DOUBLES`, a ruleset that will pick at most one mon with the tag `MON_POOL_TAG_SUPPORT` if possible, in addition to the same conditions as `POOL_RULESET_DOUBLES`.

All these pools also have the options `.speciesClause`, `.excludeForms`, `.itemClause` and `.itemClauseExclusions` set to the values defined in `include/config/battle.h` under `B_POOL_RULE_<rule>`.

- `.speciesClause` if set to `TRUE` means that the same exact species as defined by `.species` can't be picked twice for the party from the pool.
- `.excludeForms` if set to `FALSE` means that the same exact species as defined by NetDex number can't be picked twice for the party from the pool.
- `.itemClause` if set to `TRUE` means that pokemon with the same held item can't be picked twice for the party from the pool.
- `.itemClauseExclusions` if set to `TRUE` means that multiple pokemon with the same item can be picked for the party if the item is listed in `poolItemClauseExclusions`. By default `ITEM_ORAN_BERRY` and `ITEM_SITRUS_BERRY` are the only items in the list of exclusions.

Individual tags can have rules which change how they're included.
By setting the `.tagMaxMembers[POOL_TAG_<tag>]` field to a number, only that many mons with that tag will at max be part of the party, or if set to `POOL_MEMBER_COUNT_NONE` no mons with this tag will be included, and if set to `POOL_MEMBER_COUNT_UNLIMITED` no restrictions on the number of mons with the tag will apply.

By setting `.tagRequired[POOL_TAG_<tag>]` option field to `TRUE`, this tag will be picked before any tags that are not required, after the tag has been picked for the pool it will be set to `FALSE` for that tag.

The tags `Lead` and `Ace` has special handling where they will be picked for the first or last party position respectively.

### Tags
There are currently 8 tags specified in the TPP implementation, `Lead`, `Ace`, `Weather Setter`, `Weather Abuser`, `Support`, `Tag 5`, `Tag 6` and `Tag 7`.

If using `trainers.party`, these tags are applied to mons with the field `Tags: `, separated by `/`. Example `Tags: Lead / Weather Setter`

If using `trainers.h`, these tags are applied to mons with the field `.tags`, separated by `|`. Example: `.tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER`

Pokemon can have up to 32 different tags, but anything beyond the 8 initial tags has to be implemented. The numbered tags can be renamed too to better signify their purpose for developers.

## Trainer options
A few more trainer options are introduced in order to further customize how the pool picking process works.

- `Pool Pick Functions` (`.poolPickIndex`) controls which functons are used to pick mons from the pool, they're split into Lead, Ace, and Other.
By default, only `Default<position>PickFunction` and `PickLowest` are implemented. Must be an `enum` value in `enum PoolPickFunctions`.
- `Pool Prune` (`.poolPruneIndex`) controls if members in the pool should be removed before party members are picked from the pool.
By default, only `POOL_PRUNE_NONE`, which doesn't remove anything from the pool, and `POOL_PRUNE_TEST`, which removes Wobbuffet from the pool, are implemented. Must be an  `enum` value in `enum PoolPruneOptions`.

## Pool copy
The `Copy Pool` option can be used to have the trainer use the party or pool from a different trainer.
If you for example want some other trainer to have the same team/pool as Tiana, you'd use `Copy Pool: TRAINER_TIANA`.
If `Party Size` isn't defined for the current trainer, it will inherit from the copied trainer.

## Example pool
```
=== TRAINER_TIANA ===
Name: TIANA
Class: Lass
Pic: Lass
Gender: Female
Music: Female
Double Battle: Yes
AI: Check Bad Move
Party Size: 4
Pool Rules: Weather Doubles
Pool Pick Functions: Default

Zigzagoon
Level: 4
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe

Shroomish
Level: 4
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe

Psyduck
Level: 4
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe

Shellder
Level: 4
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe

Mew
Level: 4
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe
Tags: Ace

Giratina
Level: 4
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe
Tags: Ace

Vulpix
Ability: Drought
Level: 4
Tags: Lead / Weather Setter

Torkoal
Ability: Drought
Level: 4
Tags: Lead / Weather Setter

Bulbasaur
Ability: Chlorophyll
Level: 4
Tags: Lead / Weather Abuser

Cherrim
Level: 4
Tags: Lead / Weather Abuser
```
Here Tiana has been given a pool that's set up for a double battle with weather. Using the default pool rule `Weather Doubles` it will only pick one of each of the weather setters and abusers which Tiana will lead with. Tiana will also pick either Mew or Giratina as her Ace mon, and the last slot will be filled with one of Zigzagoon, Shroomish, Psyduck or Shellder.

## Pool settings
If no pool rule is specified in the trainer, the default rules will be used, which sets rules according to some defaults from `include/config/battle.h`.
This file also has settings for other pool options.

- `B_POOL_SETTING_CONSISTENT_RNG`, `TRUE` or `FALSE`, the party generated will always be the same on a particular save (RNG dependant on trainerId and encountered trainer).
- `B_POOL_SETTING_USE_FIXED_SEED`, `TRUE` or `FALSE`, the party generated will always be the same on a particular compiled ROM (RNG dependant on a chosen seed and encountered trainer).
- `B_POOL_SETTING_FIXED_SEED`, seed to use for fixed seed, does nothing if `B_POOL_SETTING_USE_FIXED_SEED` is `FALSE`.
