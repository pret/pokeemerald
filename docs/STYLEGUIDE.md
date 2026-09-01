# Styleguide and Principles

## Naming Conventions

Function names and struct names should be formatted in `PascalCase`.

```c
void ThisIsCorrect(void);

struct MyStruct
{
    u8 firstField;
    u16 secondField;
    ...
};
```

Variables and struct fields should be formatted in `camelCase`.

```c
int thisIsCorrect = 0;
```

Global variables should be prefixed with `g`, and static variables should be
prefixed with `s`.

```c
extern s32 gMyGlobalVariable;

static u8 sMyStaticVariable = 0;
```

Macros and constants should use `CAPS_WITH_UNDERSCORES`.

```c
#define MAX_LEVEL 100

enum
{
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
};

#define ADD_FIVE(x) ((x) + 5)
```

## Coding Style

### Comments

Ideally, contributions have descriptive variable, function and constant names so as to explain functionality without comments. When a comment is used, the content of the comment should explain _WHY_ a specific system or component works the way it does.

When describing a system/component in-depth, use block comment syntax.

```c
/*
 * This is an in-depth description of the save block format. Its format is as follows:
 *
 * Sectors  0 - 13: Save Slot 1
 * Sectors 14 - 27: Save Slot 2
 * ...
 */
```

When briefly describing a function or block of code, use a single-line comments
placed on its own line.
There should be a single space directly to the right of `//`.

```c
// This is supplemental information for the function. If there is a bunch of info, it should
// carry on to the next line.
void ProcessSingleTask(void)
{
   // Short comment describing some noteworthy aspect of the code immediately following.
   ...
   // Comments should be capitalized and end in a period.
}
```

When tagging a data structure that corresponds to an `enum` or some noteworthy
value, place the comment on the same line as the code.
```c
const u8 gPlantlikeMons[] =
{
    FALSE, // SPECIES_BULBASAUR
    FALSE, // SPECIES_IVYSAUR
    TRUE,  // SPECIES_VENUSAUR
    FALSE, // SPECIES_CHARMANDER
    ...
};
```

### Whitespace

All `.c` and `.h` files should use 4 spaces--not tabs.
Assembler files (`.s)` use tabs.
Script files (`.inc)` use tabs.

### Operators

Assignments and comparison operators should have one space on both sides of `=`.

```c
int i = 0; // correct
int i=0;   // incorrect

a > b // correct
a>b   // incorrect
```

The incrementor and decrementor operators should NOT have a space.

```c
i++;  // correct
i ++; // incorrect
```

A control statement should have a space between them and their expressions, and the opening bracket should be on the next line.

```c
for (...)
{
    // correct
}

for(...) {
    // incorrect
}
```

A `switch` statement's cases should left-align with the `switch`'s block.

```c
switch (foo)
{
case 0: // correct
    ...
    break;
}

switch (foo)
{
    case 0: // incorrect
        ...
        break;
}
```

A single empty line should follow a block.

```c
int MyFunction(int bar)
{
    int foo = 0;
    if (bar)
        foo++;

    return foo; // correct
}

int MyFunction(int bar)
{
    int foo = 0;
    if (bar)
        foo++;
    return foo; // incorrect
}
```

A chain of `if-else` statements in which any condition or block is more
than one line of code should use braces. If all blocks *and* conditions
are single-line, then no braces are necessary.

```c
if (foo) // correct
    return 1;

if (foo
 && bar) // correct
{
    return 1;
}

if (foo) // correct
{
    return 1;
}
else
{
    MyFunction();
    return 0;
}

if (foo) // correct
{
    return 1;
}
else if (foo
      && bar)
{
    return 0;
}

if (foo) // incorrect
{
    return 1;
}

if (foo
 && bar) // incorrect
    return 1;

if (foo) // incorrect
    return 1;
else
{
    MyFunction();
    return 0;
}

if (foo) // incorrect
    return 1;
else if (foo
      && bar)
    return 0;
```

The exception is `assertf` which should always use braces if it has a recovery path, even for one line of conditions and one line of code.

```c
assertf(true); // correct

assertf(true) // correct
{
    return NULL;
}

assertf(true) // incorrect
    return NULL;
```

### Control Structures

When comparing whether or not a value equals `0`, don't be explicit unless the
situation calls for it.

```c
if (runTasks) // correct
    RunTasks();

if (runTasks != 0) // incorrect
    RunTasks();

if (!PlayerIsOutside()) // correct
    RemoveSunglasses();

if (PlayerIsOutside() == 0) // incorrect
    RemoveSunglasses();
```

When writing a `for` or `while` loop with no body, use a semicolon `;` on the
same line, rather than empty braces.

```c
for (i = 0; gParty[i].species != SPECIES_NONE; i++); // correct

for (i = 0; gParty[i].species != SPECIES_NONE; i++) // incorrect
{ }
```
### Inline Configs

When adding functionality that is controlled by a config, defines should be checked within the normal control flow of the function unless a data structure requires a change at runtime.
```c
void SetCurrentDifficultyLevel(enum DifficultyLevel desiredDifficulty)
{
#ifdef B_VAR_DIFFICULTY
    return; // Incorrect
#endif

    if (desiredDifficulty > DIFFICULTY_MAX)
        desiredDifficulty = DIFFICULTY_MAX;

    VarSet(B_VAR_DIFFICULTY, desiredDifficulty);
}
```
```c
void SetCurrentDifficultyLevel(enum DifficultyLevel desiredDifficulty)
{
    if (!B_VAR_DIFFICULTY) // Correct
        return;

    if (desiredDifficulty > DIFFICULTY_MAX)
        desiredDifficulty = DIFFICULTY_MAX;

    VarSet(B_VAR_DIFFICULTY, desiredDifficulty);
}
```
```c
    [MOVE_VINE_WHIP] =
    {
        .name = COMPOUND_STRING("Vine Whip"),
        .description = COMPOUND_STRING(
            "Strikes the foe with\n"
            "slender, whiplike vines."),
        #if B_UPDATED_MOVE_DATA >= GEN_6 // Correct
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 45 : 35,
    },
```
### Variable Declarations
Loop iterators should be declared as part of the loop unless there's a very good reason not to.
```C
for (u32 i = 0; i < LOOP_ITERATIONS; i++)
{
    dst1[i] = i;
    dst2[i] = i;
}
```
## Data Type Sizes
When a variable number is used, the data type should generally `u32` (unsigned) or `s32` (signed). There are a few exceptions to this rule, such as:
* Values stored in the saveblock should use the smallest data type possible.
* `EWRAM` variables should use the smallest data type possible.
* Global variables / global struct members use the smallest data type possible.

## Constants, Enums and Type Checking
Avoid using magic numbers when possible - constants help to make clear why a specific value is used.

```c
// Incorrect
        if (gimmick == 5 && mon->teraType != 0)
            return TRUE;
        if (gimmick == 4 && mon->shouldUseDynamax)
            return TRUE;
```

```c
// Correct
#define TYPE_NONE 0
#define GIMMICK_DYNAMAX 4
#define GIMMICK_TERA 5

        if (gimmick == GIMMICK_TERA && mon->teraType != TYPE_NONE)
            return TRUE;
        if (gimmick == GIMMICK_DYNAMAX && mon->shouldUseDynamax)
            return TRUE;
```

When several numbers in sequence are used AND those values are not utilized in the saveblock, an enum is used instead.

```c
//Correct
enum Gimmick
{
    GIMMICK_NONE,
    GIMMICK_MEGA,
    GIMMICK_ULTRA_BURST,
    GIMMICK_Z_MOVE,
    GIMMICK_DYNAMAX,
    GIMMICK_TERA,
    GIMMICKS_COUNT,
};

        if (gimmick == GIMMICK_TERA && mon->teraType != TYPE_NONE)
            return TRUE;
        if (gimmick == GIMMICK_DYNAMAX && mon->shouldUseDynamax)
            return TRUE;
```

When an enum is used, the enum type is used instead of a regular number type to prevent incorrectly set values.

```c
// Incorrect
bool32 CanActivateGimmick(u32 battler, u32 gimmick)
{
    return gGimmicksInfo[gimmick].CanActivate != NULL && gGimmicksInfo[gimmick].CanActivate(battler);
}

u32 GetCurrentDifficultyLevel(void)
{
    if (!B_VAR_DIFFICULTY)
        return DIFFICULTY_NORMAL;

    return VarGet(B_VAR_DIFFICULTY);
}
```

```c
//Correct

bool32 CanActivateGimmick(u32 battler, enum Gimmick gimmick)
{
    return gGimmicksInfo[gimmick].CanActivate != NULL && gGimmicksInfo[gimmick].CanActivate(battler);
}

enum DifficultyLevel GetCurrentDifficultyLevel(void)
{
    if (!B_VAR_DIFFICULTY)
        return DIFFICULTY_NORMAL;

    return VarGet(B_VAR_DIFFICULTY);
}
```

## Data file format

External data files should use JSON.

## Principles

### Minimally Invasive

New functionality must be as minimally invasive to existing files as possible. When a large amount of new code is introduced, it is best to isolate it in its own file.

The [`B_VAR_DIFFICULTY`](https://patch-diff.githubusercontent.com/raw/rh-hideout/pokeemerald-expansion/pull/5337.diff) pull request is a good example of lots of new code being introduced in minimally invasive ways.

### `UNUSED`

If a function or data is introduced but is never called, it is designated as `UNUSED`. `UNUSED` functions should not be introduced unless neccesary.

```c
static void UNUSED PadString(const u8 *src, u8 *dst)
{
    u32 i;

    for (i = 0; i < 17 && src[i] != EOS; i++)
        dst[i] = src[i];

    for (; i < 17; i++)
        dst[i] = CHAR_SPACE;

    dst[i] = EOS;
}
```

### Config Philosophy

If a branch can modifies saves, the functionality that does so must be gated behind a config, and off by default.

If a branch has a config that performs either of the following, it should be on by default:
*  improves the backend / developer quality of life
*  emulates present day, modern day Pokémon

The sole excpetion to this is content who's sole source is Pokémon Champions. Champions content should use the `GEN_CHAMPIONS` config, but `GEN_LATEST` will remain `GEN_9` unless explicitly stated otherwise by a maintainer.

If a branch's behavior is one that Game Freak does not have a consistent stance on, the default behavior of the config should be disussed by the maintainers.

All other configs should be off.

### Save Philosophy

Until [save migration](https://discord.com/channels/419213663107416084/1108733346864963746) is implemented, branches will only merged in if they do not forcefully break existing game saves.

When `pokemeerald-expansion` gets to a point where new functionality will require that we break saves, we will merge as many [save-breaking features](https://discord.com/channels/419213663107416084/1202774957776441427) together as possible, and increment the major version number of the project.

# Attribution
* The majority of the styleguide was written by [garakmon](https://github.com/garakmon) as part of their [PR to pokefirered](<https://github.com/pret/pokefirered/pull/63>).
