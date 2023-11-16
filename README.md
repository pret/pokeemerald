# DREW VERSION

# Pokémon Emerald

## What is the pokeemerald Expansion?

The pokeemerald Expansion is a feature branch meant to be integrated into existing Pokémon Emerald hacks based off pret's [pokeemerald](https://github.com/pret/pokeemerald) decompilation project. This is ***NOT*** a standalone romhack, and as such, most features will be unavailable and/or unbalanced if played as is.

## What features are included?
- Configuration files that allows you to choose generation-specific behaviors. Full contents here:
    - [Battle configurations](/include/config/battle.h)
    - [Pokémon configurations](/include/config/pokemon.h)
    - [Item configurations](/include/config/item.h)
    - [Overworld configurations](/include/config/overworld.h)
    - [Debug configurations](/include/config/debug.h)
- Upgraded battle engine.
    - Gen5+ damage calculation.
    - 2v2 Wild battles support.
    - 1v2/2v1 battles support.
    - Fairy Type (configurable).
    - Physical/Special/Status Category Split (configurable).
    - New moves and abilities up to Scarlet and Violet.
        - Custom Contest data up to SwSh, newer moves are WIP. ([source](https://pokemonurpg.com/info/contests/rse-move-list/))
    - [Form change tables](/src/data/pokemon/form_change_tables.h) that allow customizing most form changes.
    - Mega Evolution, Primal Reversion and Ultra Burst.
    - Z-Moves
        - Gen 8+ damaging moves are given power extrapolated from Gen 7.
        - Gen 8+ status moves have no additional effects, like Healing Wish.
    - Initial battle parameters
        - Queueing stat boosts (aka, Totem Boosts)
        - Setting Terrains.
    - Mid-turn speed recalculation.
    - Quick Poké Ball selection in Wild Battles
        - Press `R` to use last selected Poké Ball.
        - Hold `R` to change selection with the D-Pad.
    - Faster battle intro
        - Message and animation/cry happens at the same time.
    - Faster HP drain.
    - Battle Debug menu.
        - Accessed by pressing `Select` on the "Fight/Bag/Pokémon/Run" menu.
    - Option to use AI flags in wild Pokémon battles.
    - FRLG/Gen4+ whiteout money calculation.
    - Configurable experience settings
        - Experience on catch.
        - Splitting experience.
        - Trainer experience.
        - Scaled experience.
        - Unevolved experience boost.
    - Frostbite.
        - Doesn't replace freezing unless a config is enabled, so you can mix and match.
    - Critical capture.
    - Removed badge boosts (configurable).
    - Recalculating stats at the end of every battle.
    - Level 100 Pokémon can earn EVs.
    - Inverse battle support.
    - TONS of other features listed [here](/include/config/battle.h).
- Full Trainer customization
    - Nickname, EVs, IVs, moves, ability, ball, friendship, nature, gender, shininess.
    - Custom tag battle support (teaming up an NPC in a double battle).
    - Sliding trainer messages.
    - Upgraded Trainer AI
        - Considers newer move effects.
        - New flag options to let you customize the intelligence of your trainers.
        - Faster calculations.
    - Specify Poké Balls by Trainer class.
- Pokémon Species from Generations 1-8.
    - Option to disable unwanted generations.
    - Updated sprites to DS style.
    - Updated stats, types, abilities and egg groups (configurable).
    - Updated Hoenn's Regional Dex to match ORAS'.
    - Updated National Dex incorporating the new species.
    - Sprite and animation visualizer.
        - Accesible by pressing `Select` on a Pokémon's Summary screen.
    - Gen4+ evolution methods, with some changes:
        - Mossy Rock, Icy Rock and Magnetic Field locations match ORAS'.
            - Leaf, Ice and Thunder Stones may also be used.
        - Inkay just needs level 30 to evolve.
            - You can't physically have both the RTC and gyroscope, so we skip this requirement.
        - Sylveon uses Gen8+'s evolution method (friendship + Fairy Move).
        - Option to use hold evolution items directly like stones.
    - Hidden Abilities.
        - Available via Ability Patch.
        - Compatible with Ghoul's DexNav branch.
    - All gender differences.
        - Different icons for female Hippopotas and Hippowdon
    - 3 Perfect IVs on Legendaries, Mythicals and Ultra Beasts
- Breeding
    - Incense Baby Pokémon now happen automatically (configurable).
    - Level 1 eggs.
    - Poké Ball inheriting.
    - Egg Move Transfer, including Mirror Herb.
    - Nature inheriting 100% of the time with Everstone
    - Gen6+ Ability inheriting.
- Items from newer Generations. Full list [here](/include/constants/items.h).
    - ***Gen 6+ Exp. Share*** (configurable)
    - Existing item data but missing effects:
        - Mints
        - Dynamax Candy
        - Mulches
        - Rotom Catalog
        - DNA Splicers
        - Zygarde Cube
        - N Solarizer/Lunarizer
        - Reins of Unity
        - Dynamax Band
        - Gimmighoul Coin
        - Booster Energy
        - Tera Shards
        - Tera Orb
- Feature branches incorporated:
    - [RHH intro credits](https://github.com/Xhyzi/pokeemerald/tree/rhh-intro-credits) by Xhyzi.
        - A small signature from all of us to show the collective effort in the project :)
    - [Overworld debug]() by TheXaman
        - Accesible by pressing `R + Start` in the overworld by default.
        - **Additional features**:
            - *Clear Boxes*: cleans every Pokémon from the Boxes.
            - *Hatch an Egg*: lets you choose an Egg in your party and immediatly hatch it.
- Other features
    - Pressing B while holding a Pokémon drops them like in modern games (configurable).
    - Running indoors (configurable).
    - Configurable overworld poison damage.
    - Configurable flags for disabling Wild encounters and Trainer battles.
    - Configurable flags for forcing or disabling Shinies.
    - Reusable TM (configurable).
    - B2W2+ Repel system that also supports LGPE's Lures
    - Gen6+'s EV cap.
    - All bugfixes from pret included.
    - Fixed overworld snow effect.
This is a fork of the [matching decompilation](https://github.com/pret/pokeemerald) at [PRET](https://github.com/pret).

This fork tries to maintain vanilla compatibility whenever possible. It doesn't increase the size of any save data structure or the object event structure.

There are several branches, each with one main feature (and sometimes some extra stuff):

**followers** branch:
* [HGSS-style pokémon followers](https://bulbapedia.bulbagarden.net/wiki/Walking_Pok%C3%A9mon#Pok.C3.A9mon_HeartGold_and_SoulSilver) for all 386 pokémon, including emotes, the 28 Unown forms and a majority of follower messages.
* Dynamic overworld palettes & reflections compatible with vanilla berry trees.
* PID (but not legitimacy) preserving Pokémon nature-changing function
* Function to detect modern emulators/GBA hardware.

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

**key-item-wheel** branch:
- ORAS-style Key Item wheel.
- Allows registering up to **4** Key Items.
- Vanilla-compatible, repurposes some unused rematch slots in the saveblock.
- Only takes up 1 sprite palette slot, and reuses 2 BG palette slots.
- Works in dark caves and with many sprites loaded.

![No Item](https://i.imgur.com/VY26Tww.gif)
![Multiple items](https://i.imgur.com/VKSQCz3.gif)
![Many sprites](https://i.imgur.com/qdNUDxq.gif)
![Flash caves](https://i.imgur.com/mlDA64c.gif)

Additional branches  to mention:

* `followers-expanded-id` - like `followers`, but includes backwards-compatible 16-bit graphics IDs for object events.
* `lighting-expanded-id` - like the above but for `lighting`.

There are some mechanics, moves and abilities that are missing and being developed. Check [the project's milestones](https://github.com/rh-hideout/pokeemerald-expansion/milestones) to see which ones.

## FAQ
### Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name.

### [Documentation on features can be found here](https://github.com/rh-hideout/pokeemerald-expansion/wiki)
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
## See also

## If I already have a project based on regular pokeemerald, can I use the pokeemerald Expansion
Yes! Keep in mind that we keep up with pret's documentation of pokeemerald, which means that if your project a bit old, you might get merge conflicts that you need to solve manually.
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH master`.

With this, you'll get the latest version of the Expansion, plus a couple of bugfixes that haven't been released into the next patch version :)

## **How do I update my version of the pokeemerald Expansion?**
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH expansion/1.6.2`.

### Please consider crediting the entire [list of contributors](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits) in your project, as they have all worked hard to develop this project :)

## There's a bug in the project. How do I let you guys know?
Please submit any issues with the project [here](https://github.com/rh-hideout/pokeemerald-expansion/issues). Make sure that the issue wasn't reported by someone else by searching using the filters.

## Can I contribute even if I'm not a member of ROM Hacking Hideout?

Yes! Contributions are welcome via Pull Requests and they will be reviewed by maintainers. Don't feel discouraged if we take a bit to review your PR, we'll get to it.

## Who maintains the project?

The project was originally started by DizzyEgg alongside other contributors.

The project has now gotten larger and DizzyEgg is now maintaining the project as part of the ROM Hacking Hideout community. Some members of this community are taking on larger roles to help maintain the project.

## What is ROM Hacking Hideout?

A Discord-based ROM hacking community that has many members who hack using the disassembly and decompilation projects for Pokémon. Quite a few contributors to the original feature branches by DizzyEgg were members of ROM Hacking Hideout. You can call it RHH for short!

[Click here to join the RHH Discord Server!](https://discord.gg/6CzjAG6GZk)
You can find PRET on [Discord](https://discord.gg/d5dubZ3) and [IRC](https://web.libera.chat/?#pret).
