# Release Schedule and Process

## Version Lifecycle

### Minor Release (90 days to next Minor Release)
`upcoming` and `master` are synchronized. Minor Release should occur once every three months. Maintainers can vote to do extra Minor Releases for special cases, but this should be considered highly irregular.

### Patch Release (60 / 30 days to the next Minor Release)
Releases that focus primarily on bugfixes or improvements to the test system. Patch Releases should occur AT LEAST once a month, but can be more frequent than that.

### Big Feature Freeze (30 days to the next Minor Release)
PRs with the Github label [`type: big feature`](https://github.com/rh-hideout/pokeemerald-expansion/issues?q=sort%3Aupdated-desc+is%3Aopen+label%3A%22type%3A+big+feature%22) will NOT be merged until after the next Minor Release.

### Merge Freeze (14 days to the next Minor Release)
Pull Requests that **DO NOT** have one of the following Github labels:
- [`bugfix`](https://github.com/rh-hideout/pokeemerald-expansion/issues?q=sort%3Aupdated-desc+label%3Abugfix)
- [`type: cleanup`](https://github.com/rh-hideout/pokeemerald-expansion/issues?q=sort%3Aupdated-desc+label%3A%22type%3A+cleanup%22+)
- [`type: credits`](https://github.com/rh-hideout/pokeemerald-expansion/issues?q=sort%3Aupdated-desc+label%3A%22type%3A+credits%22+)
- [`type: documentation`](https://github.com/rh-hideout/pokeemerald-expansion/issues?q=sort%3Aupdated-desc+label%3A%22type%3A+documentation%22+)
- [`category: battle-tests`](https://github.com/rh-hideout/pokeemerald-expansion/issues?q=sort%3Aupdated-desc+is%3Aopen+label%3A%22category%3A+battle-tests%22)
will NOT be merged until after the next Minor Release.

### Sample Schedule
| Major | Minor | Patch | Type               | Goal Date   |
| ----- | ----- | ----- | ------------------ | ----------- |
| 2     | 1     | 0     | Minor              | Dec 1 2025  |
| 2     | 1     | 1     | Patch              | Dec 31 2025 |
| 2     | 1     | 2     | Patch              | Jan 30 2026 |
| 2     | 1     | 2     | Big Feature Freeze | Jan 30 2026 |
| 2     | 1     | 2     | Merge Freeze       | Feb 15 2026 |
| 2     | 1     | 3     | Patch              | Mar 1 2026  |
| 2     | 2     | 0     | Minor              | Mar 1 2026  |

---

## What is a "Big Feature"?
* If any maintainer thinks a PR is a Big Feature, then it is, no question asked
* If there is disagreement, it can be discussed in a PR thread, and can ultimately be resolved with a Maintainer vote. 
* If you believe your PR should have this feature, please let a maintainer know.

### How To Identify a Big Feature
* **Big diffs**: It's easy for something to go unnoticed in review when it's a tiny part of a massive diff.
* **High-impact**: High-impact changes are harder to review because they often have consequences that aren't obvious to the reviewer. We catch these consequences from users who use upcoming reporting them.
* **Subjective**: Subjective changes are more likely to have differences of opinions between senate members.
* **Pervasive**: The PR touches several different parts of the codebase or is involved in several different parts of the codebase, even if those elements are small.

---

## Release Blocking and Milestones
When an issue or PR is assigned to a [milestone on Github](https://github.com/rh-hideout/pokeemerald-expansion/milestones) by a Maintainer, that means it is "Blocking". If another Maintainer agrees with this, then that version cannot be released until that issue is resolved or PR is merged.

This designation should be reserved for instances where an existing feature on `upcoming` or `master` is broken and causing problems for users or players.

Blocking issues or PRs can be deferred to future releases but should be discussed with the Maintainers that assigned the designation in the first place.

If a version's milestone does not have any issues or PRs assigned to it, that version should be [released](expansion_versions.md) as close to the goal date as possible.
