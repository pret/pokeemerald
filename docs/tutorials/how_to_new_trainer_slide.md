# Adding New Trainer Slides
## Define Slides Per Trainer

We are going to add a Trainer Slide to Wally's first Victory Road battle, before he Mega Evolves his Gallade. This battle takes place outside a Battle Facility, so `sTrainerSlides` must be edited.

### `src/trainer_slide.c`
```diff
+ const u8 gText_ThatsTheWay[] = _("That's the way, Gallade! Go!{PAUSE_UNTIL_PRESS}");

static const u8* const sTrainerSlides[DIFFICULTY_COUNT][TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
+        [TRAINER_WALLY_VR_1] = // use the Trainer's Id from include/constants/opponents.h
+        {
+            [TRAINER_SLIDE_ENEMY_MEGA_EVOLUTION] = COMPOUND_STRING("That's the way, Gallade! Go!{PAUSE_UNTIL_PRESS}"), // find the id for the slide to be used.
+            //[TRAINER_SLIDE_ENEMY_MEGA_EVOLUTION] = gText_ThatsTheWay, // You can use globals or COMPOUND_STRING to define text here.
+        }
    },
};
```

If we were to edit a Trainer that appears in a Battle Facility, `sFrontierTrainerSlides` would be edited instead. Here, we'll give Anabel a line before she uses a Z-Move.

### `src/trainer_slide.c`
```diff
static const u8* const sFrontierTrainerSlides[DIFFICULTY_COUNT][FRONTIER_TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
+        [TRAINER_ANABEL] =
+        {
+            [TRAINER_SLIDE_ENEMY_Z_MOVE] = COMPOUND_STRING("Victory...is ours!"), //{PAUSE_UNTIL_PRESS} is omitted, so the battle will continue as soon as the next is finished printing.
+        }
    },
};
```

## Add New Slides
* [Example Commit](<https://github.com/rh-hideout/pokeemerald-expansion/commit/d6424688007cbd923c861cfd35272e5ebfaa4016>)
* [Patch](<https://github.com/rh-hideout/pokeemerald-expansion/commit/d6424688007cbd923c861cfd35272e5ebfaa4016.patch>)
* [Diff](<https://github.com/rh-hideout/pokeemerald-expansion/commit/d6424688007cbd923c861cfd35272e5ebfaa4016.diff>)

### `include/constants/trainer_slide.h`
```diff
enum TrainerSlideType
{
    TRAINER_SLIDE_BEFORE_FIRST_TURN,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT,
+   TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT, // Each Trainer Slide has a unqiue id.
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN,
    TRAINER_SLIDE_ENEMY_MON_UNAFFECTED,
    TRAINER_SLIDE_ENEMY_LAST_SWITCHIN,
    TRAINER_SLIDE_ENEMY_LAST_HALF_HP,
    TRAINER_SLIDE_ENEMY_LAST_LOW_HP,
    TRAINER_SLIDE_ENEMY_MEGA_EVOLUTION,
    TRAINER_SLIDE_ENEMY_Z_MOVE,
    TRAINER_SLIDE_ENEMY_DYNAMAX,
    TRAINER_SLIDE_ENEMY_TERA,
    TRAINER_SLIDE_ENEMY_LANDS_FIRST_SUPER_EFFECTIVE_HIT,
    TRAINER_SLIDE_ENEMY_LANDS_FIRST_STAB_MOVE,
    TRAINER_SLIDE_ENEMY_LANDS_FIRST_DOWN,
    TRAINER_SLIDE_PLAYER_MON_UNAFFECTED,
    TRAINER_SLIDE_PLAYER_LAST_SWITCHIN,
    TRAINER_SLIDE_PLAYER_LAST_HALF_HP,
    TRAINER_SLIDE_PLAYER_LAST_LOW_HP,
    TRAINER_SLIDE_PLAYER_MEGA_EVOLUTION,
    TRAINER_SLIDE_PLAYER_Z_MOVE,
    TRAINER_SLIDE_PLAYER_DYNAMAX,
    TRAINER_SLIDE_PLAYER_TERA,
    TRAINER_SLIDE_PLAYER_USES_MON_AND_MOVE,
    TRAINER_SLIDE_ENEMY_USES_MON_AND_MOVE,
    TRAINER_SLIDE_PLAYER_SWITCHES_CERTAIN_MON,
    TRAINER_SLIDE_ENEMY_SWITCHES_CERTAIN_MON,
    TRAINER_SLIDE_PLAYER_CERTAIN_MON_FORM_CHANGE,
    TRAINER_SLIDE_ENEMY_CERTAIN_MON_FORM_CHANGE,
    TRAINER_SLIDE_COUNT,
};
```

Each Trainer Slide has a unique id and needs to be added to this list.

### `include/trainer_slide.h`

If your new Trainer Slide needs to check for beforen initalized, a function is declared here to be used externally. Critical hits are used to initalize this Trainer Slide but the slide doesn't play instantly, so we will create an function to initialize it.

```diff
void SetTrainerSlideMessage(enum DifficultyLevel, u32, u32);
void TryInitializeFirstSTABMoveTrainerSlide(u32, u32, u32);
void TryInitializeTrainerSlidePlayerLandsFirstCriticalHit(u32);
+ void TryInitializeTrainerSlideEnemyLandsFirstCriticalHit(u32);
void TryInitializeTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32);
void TryInitializeTrainerSlideEnemyMonUnaffected(u32);
bool32 IsTrainerSlideInitialized(enum TrainerSlideType);
```
### `src/trainer_slide.c`

```diff
     return IsTrainerSlideInitialized(slideId);
 }

+static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum TrainerSlideType slideId)
+{
+    return IsTrainerSlideInitialized(slideId);
+}
+
 static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 battler, enum TrainerSlideType slideId)
 {
     if (!IsTrainerSlideInitialized(slideId))
```

```diff
         case TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT:
             shouldRun = ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(slideId);
             break;
+        case TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT:
+            shouldRun = ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(slideId);
+            break;
         case TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT:
             shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(battler, slideId);
             break;
```

The function that determines if a Slide should play has different function for most Slides. We need to check if this Slide was initialized by a critical hit previously, so a function is created here. This function and the Id and then added to the switch statement in `ShouldDoTrainerSlide`.

```diff
     InitalizeTrainerSlide(slideId);
 }

+void TryInitializeTrainerSlideEnemyLandsFirstCriticalHit(u32 target)
+{
+    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT;
+
+    if (IsSlideInitalizedOrPlayed(slideId))
+        return;
+
+    if (!IsOnPlayerSide(target))
+        return;
+
+    InitalizeTrainerSlide(slideId);
+}
+
```

The function to check if this slide SHOULD be initalized is added to the bottom of this file.

### `src/battle_main.c`

```diff
         BattleScriptExecute(i == 1 ? BattleScript_TrainerASlideMsgEnd : BattleScript_TrainerBSlideMsgEnd);
     else if ((i = ShouldDoTrainerSlide(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT)))
         BattleScriptExecute(i == 1 ? BattleScript_TrainerASlideMsgEnd : BattleScript_TrainerBSlideMsgEnd);
+    else if ((i = ShouldDoTrainerSlide(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT)))
+        BattleScriptExecute(i == 1 ? BattleScript_TrainerASlideMsgEnd : BattleScript_TrainerBSlideMsgEnd);
     else if ((i = ShouldDoTrainerSlide(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT)))
         BattleScriptExecute(i == 1 ? BattleScript_TrainerASlideMsgEnd : BattleScript_TrainerBSlideMsgEnd);
     else if ((i = ShouldDoTrainerSlide(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE)))
diff --git a/src/battle_script_commands.c b/src/battle_script_commands.c
```

In `BattleTurnPassed`, most Trainer Slides are checked to see if they should run, so our new call is added here.

### `src/battle_script_commands.c`

```diff
         {
             PrepareStringBattleWithWait(STRINGID_CRITICALHIT, gBattlerAttacker);

+            TryInitializeTrainerSlideEnemyLandsFirstCriticalHit(gBattlerTarget);
             TryInitializeTrainerSlidePlayerLandsFirstCriticalHit(gBattlerTarget);
```

The actual usage of `TryInitializeTrainerSlideEnemyLandsFirstCriticalHit` is added and is checked whenever a critical hit is scored.

### `test/battle/trainer_slides.c`
```diff
     }
 }

+SINGLE_BATTLE_TEST("Trainer Slide: Enemy Lands First Critical Hit")
+{
+    gBattleTestRunnerState->data.recordedBattle.opponentA = TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT;
+
+    GIVEN {
+        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
+        PLAYER(SPECIES_WOBBUFFET);
+        OPPONENT(SPECIES_WOBBUFFET);
+    } WHEN {
+        TURN { MOVE(opponent, MOVE_LASER_FOCUS); }
+        TURN { MOVE(opponent, MOVE_TACKLE); }
+    } SCENE {
+        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, opponent);
+        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
+        MESSAGE("A critical hit!");
+        MESSAGE("This message plays after the enemy lands their first critical hit.{PAUSE_UNTIL_PRESS}");
+    }
+}
+
 SINGLE_BATTLE_TEST("Trainer Slide: Player Lands First STAB Hit")
 {
     gBattleTestRunnerState->data.recordedBattle.opponentA = TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE;
diff --git a/test/battle/trainer_slides.h b/test/battle/trainer_slides.h
```

### `test/battle/trainer_slides.h`
```diff

         [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("This message plays after the player lands their first critical hit.{PAUSE_UNTIL_PRESS}"),
     },
+    [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] =
+    {
+        [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("This message plays after the enemy lands their first critical hit.{PAUSE_UNTIL_PRESS}"),
+    },
     [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] =
     {
         [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("This message plays after the player lands their first super effective hit.{PAUSE_UNTIL_PRESS}"),
```

Tests are added to make sure the new Trainer Slide works. A test is added to the c file, and the trainer to run the entry in the test is added to `sTestTrainerSlides`.
