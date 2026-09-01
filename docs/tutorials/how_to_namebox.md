# How to Use Namebox

_New implementation made by mudskipper13, originally made by Tustin2121._

## Overview

![Npc Trainers](/docs/tutorials/img/namebox/npc_trainers.gif)
![Pokenav](/docs/tutorials/img/namebox/pokenav.gif)
![Messagebox](/docs/tutorials/img/namebox/msgbox.gif)

This is a broad and self-contained implementation of Tustin2121's namebox feature branch [here](https://github.com/tustin2121/pokeemerald/tree/feature/namebox), which includes the following:
- Cleaner implementation of namebox onto both the field message box _and_ the field PokéNav textbox.
- New configs:
  - `OW_NAME_BOX_USE_DYNAMIC_WIDTH` lets the namebox use dynamic window width depending on the speaker's string length.
    - When disabled and/or the speaker name is too long, `OW_NAME_BOX_DEFAULT_WIDTH` will be used as the maximum width.
  - `OW_NAME_BOX_NPC_TRAINER` lets any approaching NPC trainers shows a namebox in their dialogue automagically.
  - `OW_NAME_BOX_DEFAULT_WIDTH` and `OW_NAME_BOX_DEFAULT_HEIGHT` sets the default width and height.
  - `OW_NAME_BOX_FOREGROUND_COLOR` and `OW_NAME_BOX_SHADOW_COLOR` sets the default text colors, the background color is handled by the engine.
  - `OW_FLAG_SUPPRESS_NAME_BOX` lets you enable/disable the namebox globally, assign a flag from [`include/constants/flags.h`](/include/constants/flags.h) onto this config to be able to use it.
- Added a Speaker Name table, frequently-used names can be stored into `gSpeakerNamesTable` in [`src/data/speaker_names.h`](/src/data/speaker_names.h) and they can accessed by using a `SP_NAME_*` constant defined in [`include/constants/speaker_names.h`](/include/constants/speaker_names.h).
- Added a new scripting macro `setspeaker ([textPointer]/[SP_NAME_*])`.
  - Besides a text pointer, it is possible to use the Speaker Name table to set the textPointer with the `gSpeakerNamesTable` array instead.
  - Feed it either `NULL` or `SP_NAME_NONE` will remove the namebox instead.
  - `release`, `releaseall`, and `closemessage` will automatically remove the namebox, together with the messagebox.
- Added a new text control code/inline text `{SPEAKER NAME_*}`.
  - Unlike the `setspeaker` macro, you can only use the `SP_NAME_*` constants for this. It is partly due to the text engine's limitation itself.
  - You'll need to add the constants into `charmap.txt` to be able to use them for the same reason as above.
  - Feed it `SP_NAME_NONE` to remove the namebox manually.
  - Similarly, `release`, `releaseall`, and `closemessage` will automatically remove the namebox, together with the message box.

## Usage

### `setspeaker`
#### Using a text pointer
First, define your speaker's string.
```
Speaker_Jeremy:
    .string "Jeremy$"
```

And then in your script, add the `setspeaker` with the speaker's name earlier.
```
...
    setspeaker Speaker_Jeremy
...
```

If you are using poryscript, you can also include the string right there with the `setspeaker` aka inline.
```
...
    setspeaker("Jeremy")
...
```
#### Using a `SP_NAME_*` constant
Add the `setspeaker` with your constant.
```
    setspeaker SP_NAME_JEREMY
```
For instruction on how to add a new Speaker Name, continue [here](#adding-a-new-speaker-name).

### `SPEAKER` inline
The usage is identical to using `setspeaker` with `SP_NAME_*` constant, but instead it's within your _text_ script and uses the constant you added to `charmap.txt`.
```
    "{SPEAKER NAME_JEREMY}Yo wassup!"
```
For instruction on how to add a new Speaker Name, continue [here](#adding-a-new-speaker-name).

### Adding a new Speaker Name
1. Add a new constant to [`include/constants/speaker_names.h`](/include/constants/speaker_names.h) just after `SP_NAME_NONE` _and_ before `SP_NAME_COUNT`.
```diff
 enum SpeakerNames {
     SP_NAME_NONE = 0,
     SP_NAME_MOM,
     SP_NAME_PLAYER,
+    SP_NAME_JEREMY,
     SP_NAME_COUNT
 };

```

2. Add an entry to `gSpeakerNamesTable` in [`src/data/speaker_names.h`](/src/data/speaker_names.h) with your newly added constant as the array index.
```diff
 const u8 *const gSpeakerNamesTable[SP_NAME_COUNT] =
 {
     [SP_NAME_MOM]    = COMPOUND_STRING("MOM"),
     [SP_NAME_PLAYER] = COMPOUND_STRING("{PLAYER}"),
+    [SP_NAME_JEREMY] = COMPOUND_STRING("JEREMY"),
 };
```

3. In order for this constant to be usable for `{SPEAKER}` inline, you'll need to add your constant onto [`charmap.txt`](/charmap.txt). **Do note that the order here MUST match with the one in [`include/constants/speaker_names.h`](/include/constants/speaker_names.h)!**
```diff
 @ Speaker names, the order must be matching with include/constants/speaker_names.h
 NAME_NONE = 00
 NAME_MOM = 01
 NAME_PLAYER = 02
-NAME_COUNT = 03
+NAME_JEREMY = 03
+NAME_COUNT = 04
```
