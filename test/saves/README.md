# Test saves

Vanilla Emerald `.sav` files used for playtesting and for the automated
save-compatibility test (#11). Each save lives in its own folder, named after
the point in the game it was made, so it's always clear which file is which.

| Folder | Progress | Issue |
|---|---|---|
| [`badge3-wattson/`](badge3-wattson/) | Saved right after earning the third badge (Wattson, Mauville Gym) | #8 |

## Rules

- Only saves **you made yourself** by playing in an emulator. Never a ROM,
  and never a save dumped from someone else's cartridge (R1).
- Saves must be made on an unpatched **Pokémon Emerald (US), BPEE rev 0**
  ROM (SHA-1 in `rom.sha1`), or a build of this repo that still matches it,
  so they are real vanilla saves (R2).
- Use the in-game Start menu → Save. Emulator save states are not `.sav`
  files and don't count.
- Each folder holds exactly one `.sav` plus a `README.md` with the values
  below, which #11's data check compares against.
- `.sav` files are normally ignored by git; `.gitignore` has an exception for
  this folder only.

## Adding a new save

1. Make a folder named `<milestone>-<detail>` (e.g. `badge5-norman`).
2. Put the `.sav` in it, named the same as the folder (e.g. `badge5-norman.sav`).
3. Copy the "What to record" section from
   [`badge3-wattson/README.md`](badge3-wattson/README.md) and fill it in.
4. Add a row to the table above and commit through a PR.
