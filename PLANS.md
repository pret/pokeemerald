# 1. Product Requirements Document (PRD)

## Feature: TMs are not spent

## Approved Branch

- Dedicated feature branch: `feature/tms-are-not-spent`
- All planning and implementation work for this feature must remain isolated to this branch.

## Player-Facing Setting

- Add an opt-in settings menu entry labeled `Infinite TMs`.
- The setting must offer `ON` and `OFF` options matching the style of existing settings.
- The setting must default to `OFF`.
- The feature must remain disabled by default for new saves.
- Existing vanilla saves that do not contain this setting must load successfully and treat `Infinite TMs` as `OFF`.
- Once the player saves in this hack, the save data must include and persist the new `Infinite TMs` setting.

## Functional Requirements

- When `Infinite TMs` is `OFF`, normal vanilla TM behavior must be preserved: TMs are consumed after successful teaching.
- When `Infinite TMs` is `ON`, all TMs used through the normal Bag TM-use flow must be reusable and must not decrement from the Bag after successfully teaching a move.
- The feature applies only to the normal Bag TM-use flow.
- HMs must remain unchanged.
- Non-TM items must remain unchanged.
- Duplicate TM stacks must remain unchanged when the setting is `ON`; for example, a stack of 3 copies must still show 3 copies after teaching the move.
- Successful TM teaching must preserve all vanilla side effects, including the existing friendship increase.

## UI and Message Requirements

- Existing TM-use messages must remain unchanged.
- The only visible gameplay behavior change while `Infinite TMs` is `ON` is that the TM quantity does not decrease.

## Verification Requirements

- Verify `Infinite TMs` defaults to `OFF`.
- Verify current vanilla saves load successfully and read the missing setting as `OFF`.
- Verify saving in this hack persists the setting.
- Verify `OFF` behavior consumes TMs normally and preserves vanilla gameplay.
- Verify `ON` behavior prevents TM quantity decrement after successful teaching through the normal Bag flow.
- Verify HMs and non-TM items remain unaffected.
- Verify the existing TM teaching messages remain unchanged.

# 2. Technical Implementation Plan

## Approved Technical Approach

- User approved this plan on the `feature/tms-are-not-spent` branch.
- All implementation work must remain isolated to `feature/tms-are-not-spent`.

## Files and Responsibilities

- `include/global.h`
  - Add `optionsInfiniteTMs:1` to the existing `SaveBlock2` options bitfield after `optionsModernExpShare`.
  - Use one spare bit in the existing `u16` bitfield so `sizeof(struct SaveBlock2)` remains unchanged.
  - This keeps save-sector sizes stable and supports loading current vanilla saves.

- `src/new_game.c`
  - Initialize `gSaveBlock2Ptr->optionsInfiniteTMs = FALSE` in `SetDefaultOptions`.
  - This makes `Infinite TMs` default to `OFF` for new saves.

- `src/option_menu.c`
  - Add a new menu item labeled `Infinite TMs`.
  - Place it after `Modern Exp Share` and before `Cancel`.
  - Add option-list scrolling, like the Bag item list, so moving past the visible area scrolls the menu instead of pushing entries off-screen.
  - Add a task-data slot for the staged menu value.
  - Load the saved value from `gSaveBlock2Ptr->optionsInfiniteTMs`.
  - Save the staged value back to `gSaveBlock2Ptr->optionsInfiniteTMs` when leaving the options menu.
  - Display `OFF` on the left and `ON` on the right, with `0 = OFF` and `1 = ON`.
  - Use the same left/right toggle behavior and visual style as existing binary settings.

- `src/strings.c`
  - Add text constants for `INFINITE TMS`, `OFF`, and `ON`.

- `include/strings.h`
  - Add extern declarations for the new option-menu strings.

- `src/party_menu.c`
  - Update `Task_LearnedMove` so successful TM teaching only calls `RemoveBagItem(item, 1)` when `gSaveBlock2Ptr->optionsInfiniteTMs` is `FALSE`.
  - Keep the existing `item < ITEM_HM01` HM guard.
  - Keep `AdjustFriendship(mon, FRIENDSHIP_EVENT_LEARN_TMHM)` and all existing messages unchanged.
  - Preserve non-TM, HM, tutor, and level-up learning behavior.

## Runtime Guard

- Guard location: `Task_LearnedMove` in `src/party_menu.c`.
- Required condition: remove a TM only when:
  - the learning flow is the normal TM/HM item flow (`move[1] == 0`),
  - the item is a TM (`item < ITEM_HM01`),
  - and `Infinite TMs` is `OFF` (`!gSaveBlock2Ptr->optionsInfiniteTMs`).
- When `Infinite TMs` is `OFF`, the code path must match vanilla behavior.
- When `Infinite TMs` is `ON`, successful Bag TM teaching must leave the TM quantity unchanged.

## Save Compatibility

- The setting is stored in `SaveBlock2` using an existing spare bit in the options bitfield.
- Vanilla saves have that bit unset, so the setting reads as `OFF`.
- Saving in this hack persists the setting as part of `SaveBlock2`.
- The implementation must preserve the size of `struct SaveBlock2` to avoid invalidating vanilla save checksums.

## Verification Plan

- Confirm the current git branch is `feature/tms-are-not-spent` before editing source files.
- Build the ROM after each logical implementation change.
- Verify `sizeof(struct SaveBlock2)` remains unchanged or otherwise confirm the save-sector layout remains compatible.
- Verify the options menu compiles with the new `Infinite TMs` entry.
- Verify `Infinite TMs` defaults to `OFF`.
- Verify `OFF` behavior still consumes TMs after successful normal Bag teaching.
- Verify `ON` behavior does not consume TMs after successful normal Bag teaching.
- Verify HMs remain unaffected.
- Verify messages and friendship behavior remain unchanged.

# 3. Implementation Log & Test Results

## Branch Confirmation

- Confirmed implementation branch before source edits: `feature/tms-are-not-spent`.
- Untracked `AGENTS.md` existed before this work and was left untouched.

## Implementation Log

- Added `optionsInfiniteTMs:1` to the existing `SaveBlock2` options bitfield in `include/global.h`.
  - The bit uses existing spare space in the `u16` options bitfield.
  - The following `pokedex` field remains at offset `0x18`, preserving the existing options bitfield footprint.
- Added default initialization in `src/new_game.c`.
  - `gSaveBlock2Ptr->optionsInfiniteTMs = FALSE`.
- Added `Infinite TMs` option-menu strings in `src/strings.c` and declarations in `include/strings.h`.
  - Label: `Infinite TMs`.
  - Values: `OFF` and `ON`.
- Added `Infinite TMs` to `src/option_menu.c`.
  - Placed after `Modern Exp Share` and before `Cancel`.
  - Loads from `gSaveBlock2Ptr->optionsInfiniteTMs`.
  - Saves back to `gSaveBlock2Ptr->optionsInfiniteTMs` when leaving the menu.
  - Added scrolling to the option list so moving past the visible area scrolls the menu and keeps `Cancel` reachable.
  - Follow-up UI fix: limited the scrolling viewport to seven full rows so `Cancel` does not draw partially off-screen and the menu frame/background remains stationary while only option rows change.
  - Follow-up UI consistency fix: changed `Modern Exp Share` and `Infinite TMs` to match vanilla binary option layout, with `ON` on the left and `OFF` on the right.
  - Follow-up renderer fix: resized the options window and frame to the seven-row viewport so option-window tile graphics no longer overlap the reserved frame tile range.
- Updated `Task_LearnedMove` in `src/party_menu.c`.
  - TM removal now requires `item < ITEM_HM01 && !gSaveBlock2Ptr->optionsInfiniteTMs`.
  - Existing friendship adjustment remains unchanged.
  - Existing TM/HM teaching messages remain unchanged.
  - HMs remain protected by the existing `item < ITEM_HM01` check.

## Build and Check Results

- `make -j4` after save-storage/default change: passed.
- `make -j4` after option-menu/scroller/string changes: passed.
- `make -j4` after TM-consumption guard: passed.
- Final `make -j4`: passed.
  - Final memory output: EWRAM `249700 B / 256 KB`, IWRAM `30892 B / 32 KB`, ROM `14929764 B / 32 MB`.
- Follow-up `make -j4` after scroll viewport correction: passed.
- Follow-up `make -j4` after binary option layout correction: passed.
- Follow-up `make -j4` after options-window/frame resize: passed.
- `git diff --check`: passed.
- Targeted reference scan confirmed all `optionsInfiniteTMs` read/write/guard references are present.

## Verification Notes

- OFF behavior is preserved in code by keeping the original `RemoveBagItem(item, 1)` path active when `optionsInfiniteTMs` is `FALSE`.
- ON behavior is implemented in code by skipping only the TM removal call when `optionsInfiniteTMs` is `TRUE`.
- Save compatibility is preserved by storing the setting in an existing spare `SaveBlock2` bitfield bit rather than adding a new field or changing save-sector size.
- No emulator/manual save-file test was run in this pass, so vanilla-save loading and in-game ON/OFF behavior are code-reviewed and build-verified but not manually played through.
