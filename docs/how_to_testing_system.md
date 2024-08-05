# How to use the Testing System

## Running Tests
To run all the tests use:  
`make check -j`  
To run specific tests, e.g. Spikes ones, use:  
`make check TESTS='Spikes'`  
To build a ROM (pokemerald-test.elf) that can be opened in mgba to view specific tests, e.g. Spikes ones, use:  
`make pokeemerald-test.elf TESTS='Spikes'`

## How to Write Tests
Manually testing a battle mechanic often follows this pattern:
1. Create a party which can activate the mechanic.
2. Start a battle and play a few turns which activate the mechanic.
3. Look at the UI outputs to decide if the mechanic works.

Automated testing follows the same pattern:
1. Initialize the party in `GIVEN`.
2. Play the turns in `WHEN`.
3. Check the UI outputs in `SCENE`.

### Example 1
As a concrete example, to manually test `EFFECT_PARALYZE`, e.g. the
effect of Stun Spore you might:
1. Put a Wobbuffet that knows Stun Spore in your party.
2. Battle a wild Wobbuffet.
3. Use Stun Spore.
4. Check that the Wobbuffet is paralyzed.

This can be translated to an automated test as follows:

```
ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_STUN_SPORE].effect == EFFECT_PARALYZE);
}

SINGLE_BATTLE_TEST("Stun Spore inflicts paralysis")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET); // 1.
        OPPONENT(SPECIES_WOBBUFFET); // 2.
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); } // 3.
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
        MESSAGE("Foe Wobbuffet is paralyzed! It may be unable to move!"); // 4
        STATUS_ICON(opponent, paralysis: TRUE); // 4.
    }
}
```  

The `ASSUMPTIONS` block documents that Stun Spore has `EFFECT_PARALYZE`.  
If Stun Spore did not have that effect it would cause the tests in the file to be skipped. We write our tests like this so that hackers can change the effects of moves without causing tests to fail.  

`SINGLE_BATTLE_TEST` defines the name of the test. Related tests should start with the same prefix, e.g. Stun Spore tests should start with "Stun Spore", this allows just the Stun Spore-related tests to be run with:  
`make check TESTS='Stun Spore'`  

`GIVEN` initializes the parties, `PLAYER` and `OPPONENT` add a Pokémon to their respective parties. They can both accept a block which further customizes the Pokémon's stats, moves, item, ability, etc.  

`WHEN` describes the turns, and `TURN` describes the choices made in a single turn. `MOVE` causes the player to use Stun Spore and adds the move to the Pokémon's moveset if an explicit Moves was not specified.  
Pokémon that are not mentioned in a `TURN` use Celebrate.  
The test runner rigs the RNG so that unless otherwise specified, moves always hit, never critical hit, always activate their secondary effects, and always roll the same damage modifier.  

`SCENE` describes the player-visible output of the battle. In this case `ANIMATION` checks that the Stun Spore animation played, `MESSAGE` checks the paralysis message was shown, and `STATUS_ICON` checks that the opponent's HP bar shows a PRZ icon.  

### Example 2
As a second example, to manually test that Stun Spore does not effect Grass-types you might:
1. Put a Wobbuffet that knows Stun Spore in your party.
2. Battle a wild Oddish.
3. Use Stun Spore.
4. Check that the move animation does not play.
5. Check that a "It doesn't affect Foe Oddish…" message is shown.

This can again be translated as follows:

```
SINGLE_BATTLE_TEST("Stun Spore does not affect Grass-types")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STUN_SPORE].powderMove);
        ASSUME(gSpeciesInfo[SPECIES_ODDISH].types[0] == TYPE_GRASS);
        PLAYER(SPECIES_ODDISH); // 1.
        OPPONENT(SPECIES_ODDISH); // 2.
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); } // 3.
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player); // 4.
        MESSAGE("It doesn't affect Foe Oddish…"); // 5.
    }
}
```
The `ASSUME` commands are documenting the reasons why Stun Spore does not affect Oddish, namely that Stun Spore is a powder move, and Oddish is a Grass-type. These `ASSUME` statements function similarly to the ones in `ASSUMPTIONS` but apply only to the one test.  
NOT inverts the meaning of a `SCENE` check, so applying it to `ANIMATION` requires that the Stun Spore animation does not play. `MESSAGE` checks that the message was shown.  
The checks in `SCENE` are ordered, so together this says "The doesn't affect message is shown, and the Stun Spore animation does not play at any time before that". Normally you would only test one or the other, or even better, just `NOT STATUS_ICON(opponent, paralysis: TRUE);` to say that Oddish was not paralyzed without specifying the exact outputs which led to that.

### Example 3
As a final example, to test that Meditate works you might:
1. Put a Wobbuffet that knows Meditate and Tackle in your party.
2. Battle a wild Wobbuffet.
3. Use Tackle and note the amount the HP bar reduced.
4. Battle a wild Wobbuffet.
5. Use Meditate and that the stat change animation and message play.
6. Use Tackle and check that the HP bar reduced by more than in 3.

This can be translated to an automated test as follows:
```
SINGLE_BATTLE_TEST("Meditate raises Attack", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_MEDITATE); } // 5.
        TURN { MOVE(player, MOVE_TACKLE); } // 3 & 6.
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MEDITATE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); // 5.
            MESSAGE("Wobbuffet's attack rose!"); // 5.
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage); // 3 & 6.
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage); // 6.
    }
}
```

`PARAMETRIZE` causes a test to run multiple times, once per `PARAMETRIZE` block (e.g. once with `raiseAttack = FALSE` and once with `raiseAttack = TRUE`).  
The `HP_BAR` command's `captureDamage` causes the change in HP to be stored in a variable, and the variable chosen is `results[i].damage`.  
`results[i]` contains all the variables defined at the end of `SINGLE_BATTLE_TEST`, `i` is the current `PARAMETRIZE` index.  
`FINALLY` runs after the last parameter has finished, and uses `EXPECT_MUL_EQ` to check that the second battle deals 1.5× the damage of the first battle (with a small tolerance to account for rounding).

You might notice that all the tests check the outputs the player could see rather than the internal battle state. e.g. the Meditate test could have used `gBattleMons[B_POSITION_OPPONENT_LEFT].hp` instead of using `HP_BAR` to capture the damage. This is a deliberate choice, by checking what the player can observe the tests are more robust to refactoring, e.g. if `gBattleMons` got moved into `gBattleStruct` then any test that used it would need to be updated.

### Note on Overworld Tests
The overworld is not available, so it is only possible to test commands which don't affect the overworld itself, e.g. `givemon` can be tested because it only alters `gPlayerParty`, but `addobject` cannot because it affects object events (which aren't loaded).

## REFERENCE

### `ASSUME`
`ASSUME(cond)`  
Causes the test to be skipped if `cond` is false. Used to document any prerequisites of the test, e.g. to test Burn reducing the Attack of a Pokémon we can observe the damage of a physical attack with and without the burn. To document that this test assumes the attack is physical we can use:  
`ASSUME(gMovesInfo[MOVE_WHATEVER].category == DAMAGE_CATEGORY_PHYSICAL);`

### `ASSUMPTIONS`
```
ASSUMPTIONS
{
    ...
}
```
Should be placed immediately after any `#includes` and contain any `ASSUME` statements which should apply to the whole file, e.g. to test `EFFECT_POISON_HIT` we need to choose a move with that effect, if we chose to use Poison Sting in every test then the top of `move_effect_poison_hit.c` should be:
```
ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_POISON_STING].effect == EFFECT_POISON_HIT);
}
```

### `SINGLE_BATTLE_TEST`
`SINGLE_BATTLE_TEST(name, results...)` and `DOUBLE_BATTLE_TEST(name, results...)`  
Define single- and double- battles. The names should start with the name of the mechanic being tested so that it is easier to run all the related tests. `results` contains variable declarations to be placed into the `results` array which is available in tests using `PARAMETRIZE` commands.  
The main differences for doubles are:
 - Move targets sometimes need to be explicit.
 - Instead of `player` and `opponent` there is `playerLeft`, `playerRight`, `opponentLeft`, and `opponentRight`.

### `AI_SINGLE_BATTLE_TEST`
`AI_SINGLE_BATTLE_TEST(name, results...)` and `AI_DOUBLE_BATTLE_TEST(name, results...)`  
Define battles where opponent mons are controlled by AI, the same that runs
when battling regular Trainers. The flags for AI should be specified by the `AI_FLAGS` command.  
The rules remain the same as with the `SINGLE` and `DOUBLE` battle tests with some differences:
 - opponent's action is specified by the `EXPECT_MOVE` / `EXPECT_SEND_OUT` / `EXPECT_SWITCH` commands
 - we don't control what opponent actually does, instead we make sure the opponent does what we expect it to do
 - we still control the player's action the same way
 - apart from the `EXPECTED` commands, there's also a new `SCORE_` and `SCORE__VAL` commands

### `KNOWN_FAILING`
`KNOWN_FAILING;`
Marks a test as not passing due to a bug. If there is an issue number associated with the bug it should be included in a comment. If the test passes the developer will be notified to remove `KNOWN_FAILING`.  
For example:
```
SINGLE_BATTLE_TEST("Jump Kick has no recoil if no target")
{
    KNOWN_FAILING; // #2596.
    ...
}
```
### `PARAMETRIZE`
`PARAMETERIZE { parameter; }`  
Runs a test multiple times. `i` will be set to which parameter is running, and `results` will contain an entry for each parameter, e.g.:
```
SINGLE_BATTLE_TEST("Blaze boosts Fire-type moves in a pinch", s16 damage)
{
    u16 hp;
    PARAMETRIZE { hp = 99; }
    PARAMETRIZE { hp = 33; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EMBER].type == TYPE_FIRE);
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); MaxHP(99); HP(hp); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT(results[1].damage > results[0].damage);
    }
}
```
### `PASSES_RANDOMLY`
`PASSES_RANDOMLY(successes, trials, [tag])`
Checks that the test passes successes/trials. If `tag` is provided, the test is run for each value that the tag can produce. For example, to check that Paralysis causes the turn to be skipped 25/100 times, we can write the following test that passes only if the Pokémon is fully paralyzed and specify that we expect it to pass 25/100 times when `RNG_PARALYSIS` varies:
```
SINGLE_BATTLE_TEST("Paralysis has a 25% chance of skipping the turn")
{
    PASSES_RANDOMLY(25, 100, RNG_PARALYSIS);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet is paralyzed! It can't move!");
    }
}
```
All `BattleRandom` calls involving tag will return the same number, so this cannot be used to have two moves independently hit or miss, for example.

If the tag is not provided, runs the test 50 times and computes an approximate pass ratio.
`PASSES_RANDOMLY(gMovesInfo[move].accuracy, 100);`
Note that this mode of PASSES_RANDOMLY makes the tests run very slowly and should be avoided where possible. If the mechanic you are testing is missing its tag, you should add it.

### `GIVEN`
```
Given {
    ...
}
```
Contains the initial state of the parties before the battle.

## `RNGSeed`
`RNGSeed(seed)`
Explicitly sets the RNG seed. Try to avoid using this because it is a very fragile tool.  
Example:
```
GIVEN {
    RNGSeed(0xC0DEIDEA);
    ...
}
```

### `FLAG_SET`
`FLAG_SET(flagId)`  
Sets the specified flag. Can currently only set one flag at a time.  
Cleared between parameters and at the end of the test.  
Example:  
```
GIVEN {
    FLAG_SET(FLAG_SYS_EXAMPLE_FLAG);
    ...
}
```

### `PLAYER` and `OPPONENT`
`PLAYER(species)` and `OPPONENT(species`  
Adds the species to the player's or opponent's party respectively.  
The Pokémon can be further customized with the following functions:
 - `Gender(MON_MALE | MON_FEMALE)`
 - `Nature(nature)`
 - `Ability(ability)`
 - `Level(level)`
 - `MaxHP(n)`, `HP(n)`, `Attack(n)`, `Defense(n)`, `SpAttack(n)`, `SpDefense(n)`, `Speed(n)`
 - `Item(item)`
 - `Moves(moves...)`
 - `Friendship(friendship)`
 - `Status1(status1)`
For example to create a level 42 Wobbuffet that is poisoned:  
`PLAYER(SPECIES_WOBBUFFET) { Level(42); Status1(STATUS1_POISON); }`  
**Note if Speed is specified for any Pokémon then it must be specified for all Pokémon.**  
**Note if Moves is specified then MOVE will not automatically add moves to the moveset.**

### `AI_FLAGS`
`AI_FLAGS(flags)`  
Specifies which AI flags are run during the test. Has use only for AI tests.  
The most common combination is `AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT)` which is the general 'smart' AI.

### `WHEN`
```
    ...
} WHEN {
    ...
}
```
Contains the choices that battlers make during the battle.

### `TURN`
`TURN { ... }`  
Groups the choices made by the battlers on a single turn. If Speeds have not been explicitly specified then the order of the `MOVE` commands in the `TURN` will be used to infer the Speeds of the Pokémon, e.g.:  
```
     // player's speed will be greater than opponent's speed.
     TURN { MOVE(player, MOVE_SPLASH); MOVE(opponent, MOVE_SPLASH); }
     // opponent's speed will be greater than player's speed.
     TURN { MOVE(opponent, MOVE_SPLASH); MOVE(player, MOVE_SPLASH); }
```
The inference process is naive, if your test contains anything that modifies the speed of a battler you should specify them explicitly.

### `MOVE`
`MOVE(battler, move | moveSlot:, [megaEvolve:], [hit:], [criticalHit:], [target:], [allowed:], [WITH_RNG(tag, value])`  
Used when the battler chooses Fight. Either the move ID (e.g. `MOVE_TACKLE` or move slot must be specified.
 - `megaEvolve: TRUE` causes the battler to Mega Evolve if able
 - `hit: FALSE` causes the move to miss
 - `criticalHit: TRUE` causes the move to land a critical hit
 - `target:` is used in double battles to choose the target (when necessary)
 - `allowed: FALSE` is used to reject an illegal move e.g. a Disabled one
 - `WITH_RNG` allows the move to specify an explicit outcome for an RNG tag
```
     MOVE(playerLeft, MOVE_TACKLE, target: opponentRight);
```
If the battler does not have an explicit Moves specified the moveset will be populated based on the `MOVE`s it uses.

### `FORCED_MOVE`
`FORCED_MOVE(battler)`  
Used when the battler chooses Fight and then their move is chosen for them, e.g. when affected by Encore.
```
     FORCED_MOVE(player);
```

### `SWITCH`
`SWITCH(battler, partyIndex)`  
Used when the battler chooses Switch.
```
     SWITCH(player, 1);
```

### `SKIP_TURN`
`SKIP_TURN(battler)`  
Used when the battler cannot choose an action, e.g. when locked into Thrash.
```
     SKIP_TURN(player);
```

### `SEND_OUT`
`SEND_OUT(battler, partyIndex)`  
Used when the battler chooses to switch to another Pokémon but not via Switch, e.g. after fainting or due to a U-turn.
```
     SEND_OUT(player, 1);
```

### `USE_ITEM`
`USE_ITEM(battler, itemId, [partyIndex:], [move:])`  
Used when the battler chooses to use an item from the Bag. The item ID (e.g. ITEM_POTION) must be specified, and party index and move slot if applicable, e.g:
```
      USE_ITEM(player, ITEM_X_ATTACK);
      USE_ITEM(player, ITEM_POTION, partyIndex: 0);
      USE_ITEM(player, ITEM_LEPPA_BERRY, partyIndex: 0, move: MOVE_TACKLE);
```

### `SCENE`
```
    ...
} SCENE {
    ...
}
```
Contains an abridged description of the UI during the `THEN`. The order of the description must match too, e.g.
```
} SCENE {
     // ABILITY_POPUP followed by a MESSAGE
     ABILITY_POPUP(player, ABILITY_STURDY);
     MESSAGE("Geodude was protected by Sturdy!");
}
```

### `ABILITY_POPUP`
`ABILITY_POPUP(battler, [ability])`  
Causes the test to fail if the battler's ability pop-up is not shown.  
If specified, ability is the ability shown in the pop-up.
```
     ABILITY_POPUP(opponent, ABILITY_MOLD_BREAKER);
```

### `ANIMATION`
`ANIMATION(type, animId, [battler], [target:])`  
Causes the test to fail if the animation does not play. A common use of this command is to check if a move was successful, e.g.:
```
     ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
```
`target` can only be specified for `ANIM_TYPE_MOVE`.

### `EXPERIENCE_BAR`
`EXPERIENCE_BAR(battler, [exp: | captureGainedExp:])`  
If `exp:` is used, causes the test to fail if that amount of experience is not gained, e.g.:
```
     EXPERIENCE_BAR(player, exp: 0);
```
If `captureGainedExp:` is used, causes the test to fail if the Experience bar does not change, and then writes that change to the pointer, e.g.:
```
     u32 exp;
     EXPERIENCE_BAR(player, captureGainedExp: &exp);
```
If none of the above are used, causes the test to fail if the Exp does not change at all.  
**Please note that due to nature of tests, this command is only usable in `WILD_BATTLE_TEST` and will fail elsewhere.**

### `HP_BAR`
`HP_BAR(battler, [damage: | hp: | captureDamage: | captureHP:])`  
If `hp:` or `damage:` are used, causes the test to fail if that amount of damage is not dealt, e.g.:
```
     HP_BAR(player, hp: 0);
```
If `captureDamage:` or `captureHP:` are used, causes the test to fail if the HP bar does not change, and then writes that change to the
 pointer, e.g.:
```
     s16 damage;
     HP_BAR(player, captureDamage: &damage);
```
If none of the above are used, causes the test to fail if the HP does not change at all.

### MESSAGE
`MESSAGE(pattern)`  
Causes the test to fail if the message in pattern is not displayed.  
Spaces in pattern match newlines (\n, \l, and \p) in the message.  
Often used to check that a battler took its turn but it failed, e.g.:
```
     MESSAGE("Wobbuffet used Dream Eater!");
     MESSAGE("Foe Wobbuffet wasn't affected!");
```

### `STATUS_ICON`
`STATUS_ICON(battler, status1 | none: | sleep: | poison: | burn: | freeze: | paralysis:, badPoison:)`  
Causes the test to fail if the battler's status is not changed to the specified status.
```
     STATUS_ICON(player, badPoison: TRUE);
```
If the expected status icon is parametrized the corresponding `STATUS1` constant can be provided, e.g.:
```
     u32 status1;
     PARAMETRIZE { status1 = STATUS1_NONE; }
     PARAMETRIZE { status1 = STATUS1_BURN; }
     ...
     STATUS_ICON(player, status1);
```

### `NOT`
`NOT sceneCommand`  
Causes the test to fail if the `SCENE` command succeeds before the following command succeeds.
```
     // Our Wobbuffet does not Celebrate before the foe's.
     NOT MESSAGE("Wobbuffet used Celebrate!");
     MESSAGE("Foe Wobbuffet used Celebrate!");
```
**NOTE**: If this condition fails, the viewable ROM freezes at the NOT command.
**WARNING: `NOT` is an alias of `NONE_OF`, so it behaves surprisingly when applied to multiple commands wrapped in braces.**

### `ONE_OF`
```
    ONE_OF {
        ...
    }
```
Causes the test to fail unless one of the `SCENE` commands succeeds.
```
     ONE_OF {
         MESSAGE("Wobbuffet used Celebrate!");
         MESSAGE("Wobbuffet is paralyzed! It can't move!");
     }
```

### `NONE_OF`
```
    NONE_OF {
        ...
    }
```
Causes the test to fail if one of the `SCENE` commands succeeds before the command after the `NONE_OF` succeeds.
```
     // Our Wobbuffet does not move before the foe's.
     NONE_OF {
         MESSAGE("Wobbuffet used Celebrate!");
         MESSAGE("Wobbuffet is paralyzed! It can't move!");
     }
     MESSAGE("Foe Wobbuffet used Celebrate!");
```

### `PLAYER_PARTY`
Refer to the party members defined in `GIVEN`, e.g.:
```
     s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
     HP_BAR(player, damage: maxHP / 2);
```
### `OPPONENT_PARTY`
Refer to the party members defined in `GIVEN`, e.g.:
```
     s32 maxHP = GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP);
     HP_BAR(opponent, damage: maxHP / 2);
```

### `THEN`
```
    ...
} THEN {
    ...
}
```
Contains code to run after the battle has finished. If the test is using `PARAMETRIZE` commands then `EXPECT` commands between the results should go here. Is also occasionally used to check the internal battle state when checking the behavior via a `SCENE` is too difficult, verbose, or error-prone.

### `FINALLY`
```
    ...
} FINALLY {
    ...
}
```
Contains checks to run after all `PARAMETERIZE` commands have run. Prefer to write your checks in `THEN` where possible, because a failure in `THEN` will be tagged with which parameter it corresponds to.

### `EXPECT`
`EXPECT(cond)`  
Causes the test to fail if `cond` is false.

### `EXPECT_XX`
`EXPECT_EQ(a, b)`  
`a == b`  

`EXPECT_NE(a, b)`  
`a != b`  

`EXPECT_LT(a, b)`  
`a < b`  

`EXPECT_LE(a, b)`  
`a <= b`  

`EXPECT_GT(a, b)`  
`a > b`  

`EXPECT_GE(a, b)`  
`a >= b`  

Causes the test to fail if a and b compare incorrectly, e.g.
```
     EXPECT_EQ(results[0].damage, results[1].damage);
```

### `EXPECT_MUL_EQ`
`EXPECT_MUL_EQ(a, m, b)`  
 Causes the test to fail if `a*m != b` (within a threshold), e.g.
```
     // Expect results[0].damage * 1.5 == results[1].damage.
     EXPECT_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
```

## Overworld Command Reference

### `OVERWORLD_SCRIPT`
`OVERWORLD_SCRIPT(instructions...)`  
Returns a pointer to a compiled overworld script. Cannot be used to initialize global `const` data, although the pointer **IS** to `const` data.
Note that each script command must be followed by a ;, e.g.:
```
const u8 *myScript = OVERWORLD_SCRIPT(
    random 2;
    addvar VAR_RESULT, 1;
);
```

### `RUN_OVERWORLD_SCRIPT`
`RUN_OVERWORLD_SCRIPT(instructions...)`  
Runs an overworld script in the immediate script context, which means that commands like `waitstate` are not supported.
```
     RUN_OVERWORLD_SCRIPT(
         setvar VAR_RESULT, 3;
     );
     EXPECT_EQ(GetVar(VAR_RESULT), 3);
```
