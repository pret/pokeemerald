# Time-Based Encounters Tutorial

## Table of Contents:
- [What is the Time-Based Encounters feature?](#what-is-the-time-based-encounters-feature)
  - [Sounds rad, how do I add it to my romhack?](#sounds-rad-how-do-i-add-it-to-my-romhack)
  - [I've never added one by hand, but I want to!](#ive-never-added-one-by-hand-but-i-want-to)
  - [What are "supported suffixes?"](#what-are-supported-suffixes)
  - [That's a lot of manual editing.](#thats-a-lot-of-manual-editing)
  - [That's *still* a lot of editing.](#thats-still-a-lot-of-editing)
- [So what are the `#define` options in `overworld.h`?](#so-what-are-the-define-options-in-overworldh)
- [Examples](#examples)

## What is the Time-Based Encounters feature?
Time-Based Encounters lets you pick which Pokémon appear based on the in-game clock, per route!
Gen 2 had this feature, and Gen 4 brought it back- for instance, in Sinnoh's Route 201 you have a higher chance of catching a Bidoof than a Starly at night.


### Sounds rad, how do I add it to my romhack?
There are a couple of ways! The system is built to handle your unchanged [`wild_encounters.json`](../../src/data/wild_encounters.json) file by default, so the most basic solution is to add an encounter group by editing that (by hand or [with Porymap](https://huderlem.github.io/porymap/manual/editing-wild-encounters.html)), and then add a [supported suffix](#what-are-supported-suffixes) to the end of whatever name you give it.


> **NOTE**: if you haven't specified or added any encounters, or have the option turned off, Expansion puts them into the `TIME_MORNING` (or whatever your first time enum is set to in the `TimeOfDay` `enum` in [`rtc.h`](../../include/rtc.h)) slot to keep vanilla behavior. This means any map `"base_label"` without a [supported suffix](#what-are-supported-suffixes) is automatically set to the first time slot when `OW_TIME_OF_DAY_ENCOUNTERS` is `TRUE`. When `OW_TIME_OF_DAY_ENCOUNTERS` is `FALSE`, everything regardless of any extant suffixes gets the first time slot suffix (ie `_Morning` for `TIME_MORNING`) so it matches with the 0th index of the [`encounterTypes` array](../../include/wild_encounter.h) in `struct WildMonHeader`.


### I've never added one by hand, but I want to!
Great attitude bestie! It's very simple- all you need is to find your [`wild_encounters.json`](../../src/data/wild_encounters.json) file and open it up in your text/code editor of choice; I recommend VSCodium, but any will work.

To get started, we'll use Route 101 as an example:
```json
{
  "map": "MAP_ROUTE101",
  "base_label": "gRoute101",
  "land_mons": {
    "encounter_rate": 20,
    "mons": [
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      }
    ]
  }
},
```
That's it! That's the entire encounter group for Route 101. In other Routes or maps, you'll likely see other encounters listed; here we have only have `land_mons`, but vanilla emerald supports three more types of encounters, for a total of four:
- `land_mons`, your standard grass or cave or sand encounter.
- `water_mons`, used for surfing
- `rock_smash_mons`, for when you get jumpscared by a Geodude in Route 111 after using Rock Smash.
- `fishing_mons`, for fishing


> **NOTE**: You can also have more of these encounter types- in fact, expansion has a fifth type of encounter for the Dexnav feature called `hidden_mons`, and some people have entries for `honey_mons` and `headbutt_mons` in their personal hacks as well! This system supports those too, you just need to make sure to update your [`WildEncounters` struct](../../include/wild_encounter.h) definition. You need to keep the order consistent, so as a standard, any custom encounter types should go before `hidden_mons` but after `fishing_mons`. To use the earlier examples:

```c
struct WildEncounterTypes
{
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *honeyMonsInfo;
    const struct WildPokemonInfo *headbuttMonsInfo;
    const struct WildPokemonInfo *hiddenMonsInfo;
};
```
> You can see that the two new entries, `honeyMonsInfo` and `headbuttMonsInfo` (corresponding with `honey_mons` and `headbutt_mons`) are slotted in between `fishingMonsInfo` and `hiddenMonsInfo`. Structs in the C programming language rely on consistent placement with their members, so this is the order that every other instance of these encounter types should maintain. In my ~~expert~~ opinion, the easiest way to add these is again [with Porymap](https://huderlem.github.io/porymap/manual/editing-wild-encounters.html). Okay, take a breath, stretch, and we'll get back to the tutorial!


For the sake of simplicity, I'll show you how to add another encounter group here and pop a supported prefix on it. I want my new encounter group to:
- have a fishing table (I'm adding a fishin hole to Route 101)
- let you catch Spiky Eared Pichu, my favorite mon (not really)
- have some rock smash encounters to up the spook factor
- only occur at night

With all of these things in mind, let's craft an encounter! We'll start off by copying the one we have, called `gRoute101`.
```json
{
  "map": "MAP_ROUTE101",
  "base_label": "gRoute101",
  "land_mons": {
    "encounter_rate": 20,
    "mons": [
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      }
    ]
  }
},
{
  "map": "MAP_ROUTE101",
  "base_label": "gRoute101_Night",
  "land_mons": {
    "encounter_rate": 20,
    "mons": [
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      }
    ]
  }
},
```
Okay, we have it duplicated. We leave the value for "map": the same as the original so the game knows that both of these encounters are for Route 101. You can see I changed the name of the copy to `gRoute101_Night`; that's one bullet point down! If we enable `OW_TIME_BASED_ENCOUNTERS` in [`overworld.h`](../../include/config/overworld.h), the game will recognize this encounter group goes in the `Night` slot and will switch which group is used to generate the encounters when the in-game clock changes to `TIME_NIGHT`. Next, let's add Spiky Eared Pichu and our two new encounter tables (`fishing_mons` and `rock_smash_mons`).

```json
{
  "map": "MAP_ROUTE101",
  "base_label": "gRoute101_Night",
  "land_mons": {
    "encounter_rate": 20,
    "mons": [
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_PICHU_SPIKY_EARED"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_WURMPLE"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_POOCHYENA"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      },
      {
        "min_level": 3,
        "max_level": 3,
        "species": "SPECIES_ZIGZAGOON"
      }
    ]
  },
  "fishing_mons": {
    "encounter_rate": 30,
    "mons": [
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_MAGIKARP"
      },
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_MARILL"
      }
    ]
  },
  "rock_smash_mons": {
    "encounter_rate": 20,
    "mons": [
      {
        "min_level": 2,
        "max_level": 2,
        "species": "SPECIES_GEODUDE"
      }
    ]
  }
},
```
And there we go! It has the `_Night` suffix, has Spiky Eared Pichu right up at the top of the list, has a couple of fishing encounters, and will jumpscare us with about a 20% chance every time we break a rock with rock smash. That's what the `encounter_rate` line means, by the way- the overall percentage you have of encountering *any* of the Pokémon listed.
Congrats! You've just created a brand new encounter group, set its time, and adjusted the encounters! I'd highly recommend doing this [with Porymap](https://huderlem.github.io/porymap/manual/editing-wild-encounters.html)- the interface is very useful for editing maps, including wild encounters!

### What are "supported suffixes?"
Vanilla Pokémon games usually work with 4 different times of day:
- `TIME_MORNING`
- `TIME_DAY`
- `TIME_EVENING`
- `TIME_NIGHT`

So, the "supported suffixes" are just:
- `_Morning`
- `_Day`
- `_Evening`
- `_Night`


> **NOTE**: You can add more than just these by changing the `TimeOfDay` `enum` in [`rtc.h`](../../include/rtc.h). If you'd like to do this, I'd recommend making a backup of your [`wild_encounters.json`](../../src/data/wild_encounters.json) somewhere outside your project folder, just so you can have a baseline to return to if something goes wrong. The [migration script](../../migration_scripts/add_time_based_encounters.py) makes a backup of the file ***each time it runs***, so it's essentially a one step undo button- if you plan on or think you might make lots of edits to [`wild_encounters.json`](../../src/data/wild_encounters.json), ***it is a very good idea to make a baseline backup***.


### That's a lot of manual editing.
You're so right bestie! Luckily for you, there's a python script that can help you out!
The script is at [`migration_scripts/add_time_based_encounters.py`](../../migration_scripts/add_time_based_encounters.py). It, in order:
1. Checks to make sure you're running it from the [root folder](../../) of your expansion project (specifically, wherever the project's [`Makefile`](../../Makefile) is)
2. Makes a backup of your [`wild_encounters.json`](../../src/data/wild_encounters.json) file called `wild_encounters.json.bak`
3. Runs through `wild_encounters.json` and adds dummy encounter groups for each time denomination to each group
    - ie, `gRoute101` becomes `gRoute101_Morning`, `gRoute101_Day`, `gRoute101_Evening`, and `gRoute101_Night`

This script works kind of like a "template" feature- when you open it up to edit either in Porymap or a text editor, you will see the encounter groups, but they won't be filled out with encounters. This lets you add Pokémon with your own encounter rates however you want.

### That's *still* a lot of editing.
You're *still* so right bestie! Luckily for you, there's an optional argument you can add when you run the script: `--copy`.
This duplicates the encounter group's encounters as well as their labels/map group values. When you open [`wild_encounters.json`](../../src/data/wild_encounters.json) for editing either in Porymap or a text editor, you'll notice that each group (`gRoute101_Morning`, `gRoute101_Day`, `gRoute101_Evening`, and `gRoute101_Night`) now all have the same encounters as `gRoute101` did. If you only want to add a couple of Pokémon here and there for each time of day, this is probably the easier option.


> **NOTE**: the `--copy` option will use up at least an additional 9kb of ROM space. Obviously that's not much even for a GBA ROM, but it's something to keep in mind.


## So what are the `#define` options in [`overworld.h`](../../include/config/overworld.h)?
Great questie bestie!

Here's a rundown, with more information than what's in the comments at [`overworld.h`](../../include/config/overworld.h) and their default values:
```
OW_TIME_OF_DAY_ENCOUNTERS            FALSE
```
  - **Acceptable values**: `TRUE` or `FALSE`
  - this option enables or disables the feature. You'll notice your used ROM space changing when this is enabled or disabled, as the [json->C header conversion file](../../tools/wild_encounters/wild_encounters_to_header.py) will generate the `encounterTypes` array in [`wild_encounter.h`](../../include/wild_encounter.h) with different sizes based on whether this value is `TRUE` or `FALSE`.
```
OW_TIME_OF_DAY_DISABLE_FALLBACK      FALSE
```
  - **Acceptable values**: `TRUE` or `FALSE`
  - this option controls the behavior of the game when an encounter table isn't populated. If this is set to `TRUE`, whenever the game detects that you're in a time of day (Morning/Day/Evening/Night) on a map without any encounters for that time, you won't encounter any mons. If this is set to `FALSE`, the game will look for encounters at the time specified in the `OW_TIME_OF_DAY_FALLBACK` option below.
```
OW_TIME_OF_DAY_FALLBACK              TIME_MORNING
```
  - **Acceptable values**: any value from the [`TimesOfDay`](../../include/rtc.h) enum, so by default `TIME_MORNING`, `TIME_DAY`, `TIME_EVENING`, and `TIME_NIGHT`.
  - this option controls which time is used when `OW_TIME_OF_DAY_DISABLE_FALLBACK` is `FALSE`. Keep in mind that if you enable `OW_TIME_OF_DAY_ENCOUNTERS` and set this to something other than `TIME_MORNING`, you should make sure that time has encounters, or you won't encounter anything.


## Examples

### Running the [migration script](../../migration_scripts/add_time_based_encounters.py) without the `--copy` option
**Make sure you run this from the [root folder](../../) of your project!**

```
python3 migration_scripts/add_time_based_encounters.py
```

#### Result:
```json
"encounters": [
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Morning",
    "land_mons": {
      "encounter_rate": 20,
      "mons": [
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        }
      ]
    }
  },
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Day"
  },
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Evening"
  },
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Night"
  },
]
```
As you can see, the names change, but the encounters aren't touched, so you're free to add your own, piecemeal style. If you don't have any encounters for a map and time, the game will use `OW_TIME_OF_DAY_FALLBACK` *if* `OW_TIME_OF_DAY_DISABLE_FALLBACK` is `FALSE`; otherwise, you won't encounter anything.

### Running the [migration script](../../migration_scripts/add_time_based_encounters.py) with the `--copy` option
**Make sure you run this from the [root folder](../../) of your project!**

```
python3 migration_scripts/add_time_based_encounters.py --copy
```

#### Result:
```json
"encounters": [
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Morning",
    "land_mons": {
      "encounter_rate": 20,
      "mons": [
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        }
      ]
    }
  },
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Day",
    "land_mons": {
      "encounter_rate": 20,
      "mons": [
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        }
      ]
    }
  },
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Evening",
    "land_mons": {
      "encounter_rate": 20,
      "mons": [
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        }
      ]
    }
  },
  {
    "map": "MAP_ROUTE101",
    "base_label": "gRoute101_Night",
    "land_mons": {
      "encounter_rate": 20,
      "mons": [
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_WURMPLE"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_POOCHYENA"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 2,
          "max_level": 2,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        },
        {
          "min_level": 3,
          "max_level": 3,
          "species": "SPECIES_ZIGZAGOON"
        }
      ]
    }
  },
]
```
As you can see, the group `gRoute101` and all its encounters were copied into groups that correspond with the four vanilla times of day (Morning/Day/Evening/Night).
