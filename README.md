# Pokémon Emerald

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

To set up the repository, see [INSTALL.md](INSTALL.md).

## FAQ
### Q: How do I mark certain colors in a palette as light-blended?
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

You can find PRET on [Discord](https://discord.gg/d5dubZ3) and [IRC](https://web.libera.chat/?#pret).
