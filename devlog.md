# Pokémon Emerald ROM Hack Devlog

## 📅 Project Overview
**Working Title:** Pokemon Emerald Plus 
**Base:** Pokémon Emerald (pret/pokeemerald)  
**Goal:** Develop an enhanced version of vanilla Pokemon Emerald including balance tweaks, quality of life, and a completable Hoenn Dex.

---

## 🧭 Development Log

### 2025-10-04 — Project Setup
- Forked pret/pokeemerald
- Set up WSL1 and Ubuntu
- Installed build tools and agbcc
- Successfully built base ROM
- Created this `devlog.md` for organization

---

## 🧱 Planned Features
- [ ] Rebalanced Moves and Pokemon
- [ ] Modified rival trainer teams
- [ ] Quality of Life additions
- [ ] Completable Hoenn Dex

---

## 🗂️ To-Do List (General)
- [X] Pokemon Base Stat Changes
- [X] Move Changes
- [ ] Tweaks to berry growing system
- [X] Changes to Pokemon lvl up movesets
- [ ] Changes to rival trainer teams
- [ ] Changes to Pokemon Availability
- [ ] Added shops for items & TMs
- [ ] Move Tutors are reusable
- [X] Light tweaks to battle system around weather (hail & sandstorm)

---

## 🧩 Branch Plan
Each major feature will get its own branch:

- `Pokemon Rebalance` - base stat changes, moveset changes, stat screen colors, move changes, ghost is special & dark is physical, buffs to sandstorm & hail, hold item tweaks
- `Trainer Rebalance` - gym leader, E4, champ, and rival team rebalances, evil teams, general trainers
- `Pokemon Availability` changes to wild Pokemon locations and when Pokemon can be obtained
- `QoL` - shops to sell TMs throughout the game and tutors reteach moves, shops to sell berries and also improve berry growing system, other shops added and items placed to change game balance

---

## 🧠 Notes
- Keep track of all file edits here before making commits.
- Try to make each feature modular and isolated on its own branch.
- Always test builds before merging back into `master`.