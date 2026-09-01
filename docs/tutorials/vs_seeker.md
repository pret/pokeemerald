# `pokemerald-expansion` Vs. Seeker

## What is the Vs. Seeker?
The Vs. Seeker is a Key Item that is used to battle Trainers that the player has battled previously.

When used, the Vs. Seeker sends out a signal that allows the player to find other Trainers who want a rematch. This signal affects all Trainers that are on-screen. Once used on Trainers that can be rematched, the device cannot be used again until it is charged. The player does this by walking a specific number of steps. The effect on the Trainers wears off if they are battled, the player leaves the area, or the player walks a specific number of steps. If the player attempts to use the Vs. Seeker when it is not fully charged, the player will be told how many steps remain until it is. After the player uses the Vs. Seeker, some Trainers may have their team changed from their first battle.

## How is the Vs. Seeker enabled?
### Users
Vs. Seeker functionality is enabled by setting `I_VS_SEEKER_CHARGING` to `TRUE`.

### Players
`ITEM_VS_SEEKER` can only be used outside of battle. It can be used from the bag or registered to be used from the field.

Usage of the Vs. Seeker will ALWAYS fail unless all of the conditions are met:
* Player has at least five badges
* There is an NPC on screen that has previously been defeated
* Player is not inside of a building
* The Vs. Seeker is fully recharged

#### Charge
If the player has `ITEM_VS_SEEKER` and at least five badges, the Vs. Seeker will be charged by walking steps. The Vs. Seeker is fully charged once the player has walked `VSSEEKER_RECHARGE_STEPS`, which is `100` by default. The Vs. Seeker's charge is depleted if the player uses the item.

### How does Match Call interact with the Vs. Seeker?
When `I_VS_SEEKER_CHARGING` is enabled, the Match Call does not function at all. Trainers will never be rematch eligible outside of the use of the Vs. Seeker.

## How does the Vs. Seeker choose a Trainer?

When the Vs. Seeker is successfully used, every Trainer on screen is individually queried. There is a 31% chance that the Trainer will want a rematch.
Objects listed in `regularTrainersOnLand` or `regularTrainersInWater` are considered Land/Water objects.

| Status | Is Land/Water Object | Emote | New Movement Type |
| --- | --- | --- | --- |
| Wants Rematch | Yes | `MOVEMENT_ACTION_EMOTE_DOUBLE_EXCL_MARK` | `MOVEMENT_TYPE_COUNTER_CLOCKWISE` |
| Wants Rematch | No | `MOVEMENT_ACTION_EMOTE_DOUBLE_EXCL_MARK` | `MOVEMENT_TYPE_FACE_DOWN` |
| Does Not Want Rematch | - | `MOVEMENT_ACTION_EMOTE_X` | none |
| Has Not Been Fought | - | `MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK` | none |

###  Rematch Table

| Sequence   | Trainer ID       |
| ---------- | ---------------- |
| 1st Battle | `TRAINER_ROSE_1` |
| 2nd Battle | `TRAINER_ROSE_2` |
| 3rd Battle | `TRAINER_ROSE_3` |
| 4th Battle | `TRAINER_ROSE_4` |
| 5th Battle | `TRAINER_ROSE_5` |

The game determines which version of the Trainer you'll fight next by following these rules:

1. Start with the next Trainer in the sequence after the one that has been defeated. If there are no more, the battle is against the last listed Trainer.
2. If that next Trainer hasn't been unlocked yet, the battle is against the latest available unlocked version.
3. If the next Trainer is unlocked but not yet defeated, the battle is against that version.
4. If the next Trainer has already been defeated, check the next one in the sequence.

## How do users implement rematches with the Vs. Seeker?
### Existing `pokemerald` Trainers
No extra work is required. With the exception of Wally, Gym Leaders and Elite Four, all of the rematchable Trainers in Emerald will work with the Vs. Seeker without any changes.
### New Trainers
#### Party / `gRematchTable`
Each of the rematches for the Trainer must be defined as seperate Trainers in `src/data/trainers.party` and `include/constants/opponents`. For example, `TRAINER_CALVIN_1` also has `TRAINER_CALVIN_2`,`TRAINER_CALVIN_3`,`TRAINER_CALVIN_4`, and `TRAINER_CALVIN_5`.

Once all of those constants and parties are defined, a new row must be added to `gRematchTable` (located in in `src/battle_setup.c`). The row header should be a rematch ID, which can be added in `include/constants/rematches.h`. The row contents must be the five constants created for the new parties, with the lat argument being the constant of the map (`include/constants/map_groups.h`) where the Trainer is placed.

If a Trainer is intended to have less than five unique rematch parties, the extra slots can be filled with the last available Trainer ID.

```c
// This Trainer only has two teams.
    [REMATCH_ROSE] = REMATCH(TRAINER_ROSE_1, TRAINER_ROSE_2, TRAINER_ROSE_2, TRAINER_ROSE_2, TRAINER_ROSE_2, MAP_ROUTE118),
```

WARNING: Rematch IDs should be placed BEFORE `REMATCH_WALLY_VR`. Trainers below that are treated as "special Trainers" that are not triggered by the Vs. Seeker.

#### Scripts
The trainer's object needs to have a script that begins with a method to signify what this object's trainer ID is.

#### `trainerbattle`
```
Route103_EventScript_Daisy::
    trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
    msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
    end
```

Daisy is using one of the `trainerbattle` macros, which has the trainer battle macro in the first command of the script. Most trainers in `pokeemerald` use this pattern.

##### `vsseeker_rematchid`
```
Route102_EventScript_Calvin::
    vsseeker_rematchid TRAINER_CALVIN_1
    applymovement LOCALID_CALVIN, CalvinMovementTest
    waitmovement 0
    trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
    setvar VAR_0x8004, TRAINER_CALVIN_1
    specialvar VAR_RESULT, IsTrainerRegistered
    goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
    msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
    release
    end
```

If the trainer has other script commands before the eventual `trainerbattle` macro, the first command in the script needs to be `vsseeker_rematchid`. This macro does nothing but takes a single argument, which should be the same as the first Trainer ID for this trainer.

#### `MOVEMENT_TYPE_COUNTER_CLOCKWISE`
If you want Trainers to spin once they are eligible for a rematch, their overworld graphics object ID (`include/constants/event_objects.h`) must be listed in either `regularTrainersOnLand` or `regularTrainersInWater`.Otherwise they will adopt the movement type `MOVEMENT_TYPE_FACE_DOWN`.

## What can be customized about the Vs. Seeker?
* **Unlock Conditions**: The next "level" of rematches is unlocked when a specific flag is set. The flags that are currently used in `GetGameProgressFlags` can be changed to flags that better suit your game.
* **Recharge Steps**: `VSSEEKER_RECHARGE_STEPS` is initally set to 100, but this value can be changed to any number under 256.
* **Badge Requirement**: `HasAtLeastFiveBadges` is used to check if the Vs. Seeker will successfully work. You can customize the number of badges by changing `REMATCH_BADGE_COUNT` or otherwise alterting the function.

## How do gym leaders rematch work with Vs. Seeker?
They follow vanilla Emerald rules. You need to have set the flag `FLAG_SYS_GAME_CLEAR` by defeating Steven in Ever Grande City for the first rematch to be available. And then you need to have beaten every Gym Leader in a rematch once the second rematch is available. Then you need to beat every Gym Leader in a second rematch for the third rematch to be available, etc, etc ...
