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
- [ ] Pokemon Base Stat Changes
- [ ] Move Changes
- [ ] Tweaks to berry growing system
- [ ] Changes to Pokemon lvl up movesets
- [ ] Changes to rival trainer teams
- [ ] Changes to Pokemon Availability
- [ ] Added shops for items & TMs
- [ ] Move Tutors are reusable
- [ ] Light tweaks to battle system around weather (hail & sandstorm)

---

## 🧩 Branch Plan
Each major feature will get its own branch:

- `Pokemon Rebalance` - base stat changes, moveset changes, move changes
- `Gym Challenge Rebalance` - gym leader, E4, champ, and rival team rebalances
- `Evil Team Rebalance` - admins, grunts, & leaders of A&M rebalanced
- `Ordinary Trainer Rebalance` team tweaks for regular trainers throughout the game
- `Pokemon Availability` changes to wild Pokemon locations and when Pokemon can be obtained
- `Move QoL` - shops to sell TMs throughout the game and tutors reteach moves
- `Berry tweaks` - shops to sell berries and also improve berry growing system
- `Catch-all Item QoL` - other shops added and items placed to change game balance

---

## 🧠 Notes
- Keep track of all file edits here before making commits.
- Try to make each feature modular and isolated on its own branch.
- Always test builds before merging back into `master`.