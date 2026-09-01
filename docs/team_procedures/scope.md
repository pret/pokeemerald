# Document Purpose

This document is a guide for contributors and Senate to decide if a feature is within "scope" for pokeemerald-expansion. "Scope" in this case comprises a list of features and concepts that could be merged if an appropriate implementation is submitted. If a feature is not in scope, then it should not be merged. 

⚠️ Even if an opened PR is within scope, this does not mean it will be merged, as pull requests will need to pass the pass the [merge checklist](merge_checklist.md), which includes our  [config phiilosophy](../STYLEGUIDE.md#config-philosophy), [saves philosophy](../STYLEGUIDE.md#save-philosophy), and [styleguide](../STYLEGUIDE.md).

# Definitions
## Base Expansion Version
A .gba file built from an unmodified `master` or `upcoming` branch of `pokeemerald-expansion`.

## Vanilla Emerald Version
A .gba file built from an unmodified `master` branch of pret's `pokeemerald`.

## Traditional Pokémon Titles
Traditional Pokémon titles must adhere to ALL of the following conditions. An exhaustive list can be found in the [appendix](#Traditional_Pokémon_Titles) of this document. 
1. They are a [core series game](https://bulbapedia.bulbagarden.net/wiki/Core_series#List_of_core_series_games) Pokémon title.
1. Their metagames have been played as part of an official Pokémon tournament.
1. They feature turn based battle system.

### Notable Addendunm
### Inclusions
* While [Let's Go, Pikachu!](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon:_Let%27s_Go,_Pikachu!_and_Let%27s_Go,_Eevee!) and [Let's Go, Eevee!](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon:_Let%27s_Go,_Pikachu!_and_Let%27s_Go,_Eevee!) have not had metagames as part of an official Pokémon tournament, they have been granted a special exception and are deemed "Traditional".
# Exclusions
* [Champions](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Champions) is not a core series game and is not included. Some specific categories allow for content from Champions, detailed below.
* [Legends: Arceus](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Legends:_Arceus), [Legends: Z-A](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Legends:_Z-A) and [Mega Dimension](https://bulbapedia.bulbagarden.net/wiki/Mega_Dimension) have not had metagames as part of an official Pokémon tournament, and therefore, are not traditional.

# Scope Guidelines
A pull request meets the scope criteria if:
* The pull request does not belong to a category considered “not in scope” AND
* The feature belongs to a category considered “in scope”

## In Scope Categories
### Pokémon, Items, and Battle Data
**Species** that appear in a Traditional Pokémon Title **or Pokémon Champions**.
  - This includes follower sprites for all species, including battle-only ones species like Mega Pyroar.

**Items** that meet ALL the following requirements are in scope:
  - The item appears in a Traditional Pokémon Title **or Pokémon Champions**.
  - The item is used in battle OR is mechanically or functionally unqiue from an existing item.
  - The item does not only exist for story related purposes, such as the Jade Orb.

**Moves**, **Move Animations**, **Abilities**, **Learnsets**, **Battle Mechanics**, **Weather Types**, **Status Conditions** that appear in a Traditional Pokémon Title **or Pokémon Champions**.
  
### Battle Quality of Life
Quality of Life improvements that appear in a Traditional Pokémon Title **or Pokémon Champions** AND reveal more battle information or improve battle experience. These include improved Battle Messages, Type Effectiveness Indicators, Simutaneous HP Drops, or Enemy HP Percentage.

### Menu Features
Add menu changes / additions from Traditional Pokémon Title **or Pokémon Champions**, such as changes to PC functions.

### Gimmicks / Special Battle Types
Gimmicks or Special Battle Types that appear in a Traditional Pokémon Title, such as Dynamax or Triple Battles.

### Overworld Features
Add overworld changes / additions from Traditional Pokémon titles, such as followers, sideways stairs, etc.

### Novel Experience
Adds a novel experience included in a Traditional Pokémon titles, such as Poffins, Fishing minigames, or Mining.

### Battle AI Behavior
Improvements towards the capability of a human competitive player, and unique or interesting behaviours otherwise.

### Base Link Compatibility
The ability for two Base Expansion Version's to connect, trade, and battle one another.

### Speed Up
Optimize code to run more efficiently, take up less space, and work better overall to improves the developer and / or player experience.

### Compression
Reduces the size of graphic or sound assets, including automatic compression.

### Helper Features
Eases the addition or inclusion of any of the aforementioned, or facilitates developer ease of use.

### Special Exceptions
The following have been explicitly voted to be within scope.
* [Pokémon Colosseum](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Colosseum) and [Pokémon XD: Gale of Darkness](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_XD:_Gale_of_Darkness) are not core series games, but **[Shadow Pokémon](https://bulbapedia.bulbagarden.net/wiki/Shadow_Pok%C3%A9mon)** and their related accessories (Shadow moves, purification) have been granted a special exception.
* [Champions](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Champions) is not a core series game, but the Power Point and Individual Values changes have been granted a special exception.

## Explictly Not In Scope Categories
### Pokémon, Items, and Battle Data
**Species**, **Items**, **Moves**, **Move Animations**, **Abilities**, **Learnsets**, **Battle Mechanics**, **Weather Types**, **Status Conditions** that **DO NOT** appear in a Traditional Pokémon Title **or Pokémon Champions**.

### Stat Points / Effort Value Cap
Stat Points functionality or Effort Values Caps and Changes from Champions.

### Duplicate User Interfaces
Adds additional user interface that covers the same functionality of an existing feature, such as the HeartGold / SoulSilver Pokédex or Black / White Summary Screen.

### Vanilla Link Compatability
The ability for Base Expansion Version and Vanilla Emerald Version to connect, trade, and battle one another.

### Maps
Adds overworld maps.

## Discussion Required Categories
Pull Requests that fall into this category are not in scope by default and should be brought up to maintainers, who will discuss and vote as to whether or not the feature is considered in scope. Considerations for acceptance may include invasiveness of implementation, popularity, ease of maintenance, etc.

### Developer Ease of Use
Lowers barrier of entry for developers to use existing behavior or functionality.

### Fangame Features
Adds a popular feature from other fangames or Pokémon experiences.

### Popular Non-Traditional Features
Exceptions can be made for uniquely popular or requested features, such as Legends: Arceus' [Drowsy](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Drowsy), or XD: Gale of Darkness's Shadow Pokémon.

### External Program
External programs like poryscript.

### Intergenerational Feature Compatibility
Addresses limitations and issues resulting from including all generational behaviours in a GBA native title, and extrapolation of features no longer supported by Game Freak.

## Workflow for Proposed Feature Scope Discussion
### Contributors
1. Make a thread for the feature on Discord
1. Describe how the feature fits into this scope document, and why you feel it should be considered
1. Optionally include either a draft PR or describe in some detail the proposed implementation. 
    - Non-mandatory, but implementation invasiveness, maintenance cost, etc. are major considerations, so use your judgement. Maintainers may ask for this information during discussion.

### Maintainers
1. Make a senate thread for the discussion
1. Make and pin a two-week voting poll
1. Discuss, conclude, and cast votes before the two-week deadline
1. Inform contributor as to the results and reasons in their thread
1. Amend this scope document if necessary

# Appendix
## Traditional Pokémon Titles
* Red
* Green
* Blue
* Yellow: Special Pikachu Edition
* Gold
* Silver
* Crystal
* Ruby
* Sapphire
* Emerald
* FireRed
* LeafGreen
* Diamond
* Pearl
* Platinum
* HeartGold
* SoulSilver
* Black
* White
* Black 2
* White 2
* X
* Y
* Omega Ruby
* Alpha Sapphire
* Sun
* Moon
* Ultra Sun
* Ultra Moon
* Let's Go, Pikachu!
* Let's Go, Eevee!
* Sword
* Shield
* The Isle of Armor
* The Crown Tundra
* Brilliant Diamond
* Shining Pearl
* Scarlet
* Violet
* The Teal Mask
* The Indigo Disk
