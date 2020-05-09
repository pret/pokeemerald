
# Bugs and Glitches

These are known bugs and glitches in the original Pokémon Emerald game: code that clearly does not work as intended, or that only works in limited circumstances but has the possibility to fail or crash.

Fixes are written in the `diff` format. If you've used Git before, this should look familiar:

```diff
 this is some code
-delete red - lines
+add green + lines
```

## Contents

- [RNG does not get seeded](#rng-does-not-get-seeded)


## RNG does not get seeded

**Fix:** Add the following function to [src/main.c](https://github.com/pret/pokeemerald/blob/master/src/main.c):
```diff
+static void SeedRngWithRtc(void)
+{
+	u32 seed = RtcGetMinuteCount();
+	seed = (seed >> 16) ^ (seed & 0xFFFF);
+	SeedRng(seed);
+}
```

And edit `AgbMain`:

```diff
	...
	RtcInit();
	CheckForFlashMemory();
	InitMainCallbacks();
	InitMapMusic();
+	SeedRngWithRtc();
	ClearDma3Requests();
	...
```