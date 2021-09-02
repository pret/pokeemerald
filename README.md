# Pokémon Emerald

This is a fork of the [matching decompilation](https://github.com/pret/pokeemerald) at [PRET](https://github.com/pret).

The general philosophy of this fork is to maintain vanilla behavior & compatibility where possible, especially in terms of data structures. For that reason, this fork does not increase the size of the save data structure or the object event structure, nor does it add a `nature` field to the Pokémon structure.

There are several branches, each with additional features compared to vanilla:

**romhack** branch:
* [HGSS-style pokémon followers](https://bulbapedia.bulbagarden.net/wiki/Walking_Pok%C3%A9mon#Pok.C3.A9mon_HeartGold_and_SoulSilver) for all 386 pokémon, including emotes, the 28 Unown forms and a majority of follower messages.
* Dynamic overworld palettes & reflections compatible with vanilla berry trees.
* HGSS-style alpha-blended shadows for object events.
* A way to change a pokemon's nature while mangling its PID as little as possible.
* Function to detect newer emulators/new GBA hardware.

**icons** branch:
* Everything from the **romhack** branch.
* All pokemon icons updated to nicer looking Gen 6 style, based on [this repo](https://github.com/msikma/pokesprite/tree/master/icons/pokemon/regular)
* This includes compatibility with the PC, trade, contests, mail, Battle Dome. Examples:
![PC](https://i.imgur.com/wzwJfd1.png)
![Party](https://i.imgur.com/8hbE88t.png)
![Contest](https://i.imgur.com/S9mCEFL.png)
* Icons share palettes with front sprites, meaning that shiny pokemon will also have shiny icons!

**lighting** branch:
* Everything from the **romhack** branch.
* Day/night shading compatible with weather.
* GSC-style window lights.
* WIP interframe-blended lamp lights at night, i.e in Rustboro.

To set up the repository, see [INSTALL.md](INSTALL.md).

## See also

Other disassembly and/or decompilation projects:
* [**Pokémon Red and Blue**](https://github.com/pret/pokered)
* [**Pokémon Gold and Silver (Space World '97 demo)**](https://github.com/pret/pokegold-spaceworld)
* [**Pokémon Yellow**](https://github.com/pret/pokeyellow)
* [**Pokémon Trading Card Game**](https://github.com/pret/poketcg)
* [**Pokémon Pinball**](https://github.com/pret/pokepinball)
* [**Pokémon Stadium**](https://github.com/pret/pokestadium)
* [**Pokémon Gold and Silver**](https://github.com/pret/pokegold)
* [**Pokémon Crystal**](https://github.com/pret/pokecrystal)
* [**Pokémon Ruby and Sapphire**](https://github.com/pret/pokeruby)
* [**Pokémon Pinball: Ruby & Sapphire**](https://github.com/pret/pokepinballrs)
* [**Pokémon FireRed and LeafGreen**](https://github.com/pret/pokefirered)
* [**Pokémon Mystery Dungeon: Red Rescue Team**](https://github.com/pret/pmd-red)


## Contacts

You can find PRET on [Discord](https://discord.gg/d5dubZ3) and [IRC](https://kiwiirc.com/client/irc.freenode.net/?#pret).
