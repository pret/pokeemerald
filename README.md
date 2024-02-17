# Pokémon Emerald

This is a fork of the [matching decompilation](https://github.com/pret/pokeemerald) at [PRET](https://github.com/pret).

This fork tries to maintain vanilla compatibility whenever possible. It doesn't increase the size of any save data structure or the object event structure.

There are several branches, each with one main feature (and sometimes some extra stuff):

**followers** branch:
* [HGSS-style pokémon followers](https://bulbapedia.bulbagarden.net/wiki/Walking_Pok%C3%A9mon#Pok.C3.A9mon_HeartGold_and_SoulSilver) for all 386 pokémon (including forms & shinies)
* Includes follower emotes and a majority of the HGSS messages
* Custom pokeball sprites for Gen 1-7 pokéballs
* Followers can use field moves in the overworld
* Overworld form changes for Ditto, Mew, Castform, etc.
* Asymmetrical & 64x64 OW support
* Dynamic Overworld Palette System (DOWP) & reflections compatible with berry trees, etc.

> Note: Unless you have a specific need for it, you should probably use `followers-expanded-id` over this.

![Pokeball](https://i.imgur.com/OMbS67Q.gif)
![Messages](https://i.imgur.com/sTbGVEY.gif)
![Forms](https://i.imgur.com/wDhFNf4.gif)
![HM](https://i.imgur.com/lnXJGHd.gif)

**icons** branch:
* Everything from the **followers** branch.
* All pokemon icons updated to Gen 6, based on [this repo](https://github.com/msikma/pokesprite/tree/master/icons/pokemon/regular)
* This includes compatibility with the PC, trade, contests, mail, Battle Dome. Examples:
![PC](https://i.imgur.com/wzwJfd1.png)
![Party](https://i.imgur.com/8hbE88t.png)
![Contest](https://i.imgur.com/S9mCEFL.png)
* Icons share palettes with front sprites, meaning that shiny pokemon will also have shiny icons!

**lighting** branch:
* Everything from the **followers** branch.
* Day/night shading compatible with weather.
* GSC-style window lights.
* WIP interframe-blended lamp lights at night, i.e in Rustboro.
* HGSS-style alpha-blended shadows for object events.

**just-lighting** branch:
* `lighting-expanded-id` but with following pokémon code & assets completely removed. (This allows for more than 255 OW graphics)
* Saves with following pokémon can still safely be loaded.

**followers-expanded-id** branch:
* Like `followers`, but includes expands OW graphicsIds to 16-bits
in a backwards compatible way
* Includes support for compressed OW graphics

Additional branches to mention:

* `lighting-expanded-id` - like the above but for `lighting`.

To set up the repository, see [INSTALL.md](INSTALL.md).

**guillotine** branch:
* ~~Decapitates~~ Decapitalizes **all** text at runtime, with some exceptions (see the [FAQ](#guillotine-q-how-can-i-keep-my-strings-from-being-decapped))
* Future-proof, does not require mass-replacing strings

To set up the repository, see [INSTALL.md](INSTALL.md).

## FAQ
### `(followers*)` Q: Where are the config settings?
A: Configuration for the follower system is mostly in [event_objects.h](include/constants/event_objects.h):
```c
// If true, follower pokemon will bob up and down
// during their idle & walking animations
#define OW_MON_BOBBING  TRUE

// If true, adds a small amount of overhead
// to OW code so that large (48x48, 64x64) OWs
// will display correctly under bridges, etc.
#define LARGE_OW_SUPPORT TRUE

// Followers will emerge from the pokeball they are stored in,
// instead of a normal pokeball
#define OW_MON_POKEBALLS TRUE
```

### `(lighting)` Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name.

In this file you can enter color indices [0,15]
on separate lines to mark those colors as being light-blended, i.e:

`06.pla:`
```
# A comment
0 # if color 0 is listed, uses it to blend with instead of the default!
1
9
10
```

You might have to `make mostlyclean` or change the `.pal` file to pick up the changes.

### `(guillotine)` Q: How can I keep my string(s) from being decapped?
A: There are a number of ways to make a string "fixed case" so that it will not be decapitalized when displayed:

C strings: Replace the `_` with `_C`:
```c
// _C = fixed (C)ase string!
const u8 gText_IDNumber[] = _C("IDNo.");
```
ASM strings: Replace `.string` with `.fixstr`:
```arm
gText_SavingDontTurnOff::
    @ Lasts until the string terminator '$'
	.fixstr "SAVING…\n"
	.string "DON'T TURN OFF THE POWER.$"
```
You can fix-case/unfix parts of a string like so:
```arm
	.string "{FIXED_CASE}WARNING!{UNFIX_CASE}\p"
```
For a placeholder (only the placeholder will be fixed-case):
```arm
	.string "{STR_VAR_2_FIXED} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
```
See also the configuration in [text.h](gflib/text.h).

There's also special handling for "separated bigrams"; basically, two letter words.
This includes: `"TM01", "PC", "EV"`, any two uppercase characters surrounded by digits, whitespace, or the start/end of a string. These will not be decapped.

## See also

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
