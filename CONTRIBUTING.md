# Contributing to Emerald Island

Emerald Island is a "DLC" for vanilla Pokémon Emerald, built on top of the
[pret/pokeemerald](https://github.com/pret/pokeemerald) decompilation and
shipped as a BPS patch.

This file is the single source of truth for **how work is done** in this
repository (workflow) and **what the hack is never allowed to break**
(project rules). It is adapted from the issue → branch → pull request workflow
of a team software-engineering project, scaled down for a solo ROM hack.

If a rule here turns out to be wrong, change it through a pull request like
any other change, so the history shows why.

---

## Part 1: Project rules

These are hard constraints. A pull request that breaks one of them is not
ready to merge, no matter how good the feature is.

### R1. Distribution: patch only, never the ROM

- The release artifact is a **BPS patch** that applies to a clean
  **Pokémon Emerald (US), game code `BPEE`, revision 0**.
  The clean ROM's SHA-1 is in [`rom.sha1`](rom.sha1).
- **Never commit or upload a ROM** (`.gba`), a patched ROM, or a save file
  taken from a commercial cartridge to this repository, an issue, a PR, or a
  release. `.gitignore` already excludes `*.gba`; do not override it.
- Release notes must say which base ROM the patch expects.

### R2. Vanilla saves must keep loading

A player must be able to take an existing vanilla Emerald `.sav`, apply the
patch, and continue their game.

- **Never change the save layout.** That includes `SaveBlock1`, `SaveBlock2`,
  `PokemonStorage`, `struct Pokemon` / `BoxPokemon` and their substructs,
  party size, box count and size, bag pocket sizes, PC item storage size, and
  the order or size of any field in them.
- New state goes into space vanilla already reserves and does not use
  (see R6), never into new fields.
- Any PR that touches `include/global.h`, `include/pokemon.h`,
  `include/pokemon_storage_system.h`, `include/save.h`, `src/save.c` or
  `src/load_save.c` must say so in its description and explain why the layout
  is unchanged.

### R3. Stay on vanilla pokeemerald

- The base is **pret/pokeemerald**, not
  [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion).
  Expansion changes the save layout, which breaks R2.
- Expansion code **may be ported selectively** when it does not touch saved
  data (for example, the HGSS-style Pokédex "Forms" screen for multi-form
  species such as Indeedee). A ported feature gets its own issue, and the PR
  credits the source and lists what was removed or adapted.

### R4. Pokédex flags stay at 52 bytes

- `NUM_DEX_FLAG_BYTES` (in `include/global.h`) must be **hard-coded to `52`**
  instead of being derived from `NUM_SPECIES`, so adding species can never grow
  the `owned`/`seen` arrays in the save.
- 52 bytes = 416 bits, which covers National Dex numbers up to **#416**.

### R5. Species and Pokédex budget

| Resource | Budget | Notes |
|---|---|---|
| New National Dex numbers | **30** (#387 to #416) | Hard ceiling from R4. |
| New species IDs | **125** | 25 from the `SPECIES_OLD_UNOWN_B..Z` placeholders (IDs 252 to 276), plus IDs 412 to 511 **if** `SPECIES_EGG` is moved to 512 or above. |
| Hall of Fame | 9 bits per species | `src/hall_of_fame.c` stores `species:9`, so every species that can enter the Hall of Fame must have an ID of **511 or lower**. |

- Forms (alternate species IDs that share a Dex number) spend species IDs but
  not Dex numbers.
- Keep a running tally of allocated Dex numbers and species IDs in the issue
  that adds them, and update it in the PR.

### R6. Story progress uses only unused vanilla flags and vars

- New event flags, trainer flags and script variables must reuse IDs that
  vanilla **never reads or writes** (for example, the `FLAG_UNUSED_*` and
  `VAR_UNUSED_*` entries in `include/constants/flags.h` and
  `include/constants/vars.h`). Do not raise `FLAGS_COUNT` or `VARS_COUNT`.
- When you claim one, rename it in the header to its new purpose in the same
  PR, and note the original name in a comment so it can be audited.
- Before using one, search the code and scripts to confirm vanilla really
  never touches it. "Unused" in the name is not proof.

### R7. CI must keep checking what matters

- The inherited CI (`.github/workflows/build.yml`) builds with `COMPARE=1`,
  which checks the output against `rom.sha1`. That stops being true as soon
  as gameplay changes.
- The first PR that changes the built ROM must also update CI so it still
  proves the build works (for example, build with `COMPARE=0` and produce the
  patch), instead of letting CI go red or turning it off.
- The `symbols` branch steps are pret infrastructure and may be removed when
  CI is reworked.

---

## Part 2: Workflow

### The loop

For any change that affects the game, the build, or these docs:

1. **Issue.** Open (or find) a GitHub issue that describes the need.
2. **Branch.** Create a focused branch from `master` named after the issue.
3. **Implement.** Make the change in small, meaningful commits.
4. **Verify.** Build it and check it in an emulator (see "Verification").
5. **Pull request.** Open a PR using the template, linked with `Closes #N`.
6. **Review.** Read the full diff in GitHub before merging, including any
   change Claude or another tool wrote.
7. **Merge.** Squash-merge into `master` once CI and the checklist pass, then
   delete the branch.

Tiny fixes (a typo in a comment, a broken link) can skip the issue, but still
go through a branch and PR. **Nothing is pushed straight to `master`.**

### Issues

Use the issue templates in `.github/ISSUE_TEMPLATE/`:

- **Task**: a concrete unit of work (add a map, port a screen, fix CI).
- **Feature**: a new or changed piece of content or gameplay, described as
  the player-facing outcome before the implementation.
- **Bug**: something that behaves wrong, with steps to reproduce.

An issue should say why the work matters and what "done" looks like. Large
features (a new route, a new region) get a parent issue with sub-issues for
each piece, so each PR stays reviewable.

#### Labels

| Label | Use for |
|---|---|
| `feature` | New content or gameplay |
| `bug` | Wrong behavior |
| `task` | Engineering work that isn't player-facing |
| `species` | Adds or changes species, forms or Dex entries (check R4, R5) |
| `map` / `script` | New or changed maps, events, dialogue |
| `save-compat` | Anything that could touch saved data (check R2) |
| `ci` / `tooling` | Build, CI, patch generation |
| `docs` | Documentation only |
| `port` | Code ported from pokeemerald-expansion or another project (check R3) |
| `blocked` | Waiting on something else; say what in a comment |

### Branches

Name branches `<type>/<issue-number>-<short-description>`:

- `feature/12-indeedee-forms`
- `fix/27-ferry-softlock`
- `task/5-ci-noncompare-build`
- `docs/3-workflow`
- `port/18-hgss-dex-forms`

Avoid vague names like `changes`, `wip` or `test2`. Keep one branch per issue,
and keep it up to date with `master` before opening the PR.

Branches created by Claude Code sessions use the `claude/...` names the
session assigns; the PR still links its issue.

### Commits

- Describe the outcome in the imperative: `Add Indeedee form table`,
  `Fix softlock when leaving the ferry`, not `update` or `fix stuff`.
- Add a body when the reason isn't obvious from the diff, especially for
  anything near save data or flags.
- Don't mix unrelated changes in one commit.

### Pull requests

Use the PR template in `.github/pull_request_template.md`. A PR should let
future you understand, without re-reading the diff:

- what changed and why;
- which issue it closes;
- how it was verified;
- whether it touches save data, flags/vars, or the species budget;
- what is known to be unfinished or risky.

### Verification

"It compiles" is not verification. Depending on the change:

- **Build**: `make` succeeds locally and in CI.
- **Play-test**: the change is exercised in an emulator (mGBA recommended),
  from a save that reaches the content.
- **Vanilla save test** (required when the `save-compat` label applies, and
  before every release): load a save made on the unmodified game, save again,
  reload, and confirm party, boxes, bag, Pokédex and story progress are intact.
- **Patch test** (releases): generate the BPS from the build, apply it to a
  clean `BPEE` ROM, and confirm the result boots.

Record what you actually did in the PR. If a check was skipped, say so under
"Risks / follow-up" instead of ticking the box.

### Definition of done

An issue can be closed when:

- the change is merged into `master`;
- CI passes;
- the verification above was done and written down in the PR;
- no project rule (Part 1) is broken;
- the species/Dex tally and any claimed flags/vars are updated; and
- known limitations are written in the PR or a follow-up issue.

### Decisions

Choices that shape the project (which forms to add, which unused flags a
story arc claims, how CI produces the patch) are recorded in the issue or PR
where they were made, with the `docs` label if they need their own write-up.
Don't leave a decision only in a chat.

### AI-assisted work

Claude (via Claude Code) may write code, docs and PRs here. The human owner
reviews and is responsible for everything merged. PRs written with AI help say
so in the description, and nothing is merged that hasn't been read and
play-tested where it matters.

### Releases

- Tag releases on `master` as `vX.Y.Z`.
- Attach only the `.bps` patch and release notes to the GitHub release, never
  a ROM (R1).
- Release notes list the base ROM (`BPEE`, rev 0, SHA-1 from `rom.sha1`), what
  changed, and that vanilla saves are supported.
