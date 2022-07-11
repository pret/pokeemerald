# Styleguide for pokeemerald

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
extern int gMyGlobalVariable;

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

    return foo; // incorrect
}

int MyFunction(int bar)
{
    int foo = 0;
    if (bar)
        foo++;
    return foo; // incorrect
}
```

A chain of `if-else` statements in which any block is more than one line of
code should use braces. If all blocks are single-line, then no braces are necessary.

```c
if (foo) // correct
{
    return 1;
}
else
{
    MyFunction();
    return 0;
}

if (foo) // incorrect
    return 1;
else
{
    MyFunction();
    return 0;
}
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
End all `switch` cases with `break`, unless omitting `break` is necessary for
matching the original program flow.
```c
void MyFunction(void)
{
    switch (color)
    {
    ...
    case RED:
        ...
        break; // correct
    }

    return;
}

void MyFunction(void)
{
    switch (color)
    {
    ...
    case RED:
        ... // incorrect
    }

    return;
}
```

When writing a `for` or `while` loop with no body, use a semicolon `;` on the
same line, rather than empty braces.

```c
for (i = 0; gParty[i].species != SPECIES_NONE; i++); // correct

for (i = 0; gParty[i].species != SPECIES_NONE; i++) // incorrect
{ }
```

## Use dedicated initializers where possible

In C, dedicated initializers help remove ambiguity with struct and array
declarations.

For arrays, you can specify the index of an element in the array by typing
"[*index*] = " before the element. You can also use preprocessor constants to
index an array, or an ellipsis to specify a range. For example:

```C
#define INDEX_8 8
static const u8 sMyArray[] = 
{
    [9] = 9,
    [0 ... 4] = 1,
    [INDEX_8] = 8,
};
```

will create the 10-element array `[1, 1, 1, 1, 1, 0, 0, 0, 8, 9]`.

For structs, you can initialize specific fields using ".field = " before the
value. For example:

```C
struct MyStruct
{
    u8 myFirstField;
    u8 mySecondField;
    u8 myThirdField;
    u8 myFourthField;
};

static const struct MyStruct sMyLocalStruct = 
{
    .mySecondField = 100,
    .myFourthField = 200,
};
```


