# Pokémon Emerald

This is a decompilation of Pokémon Emerald.

It builds the following ROM:

* [**pokeemerald.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1961) `sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

**guillotine** branch:
* ~~Decapitates~~ Decapitalizes **all** text at runtime, with some exceptions (see the [FAQ](#guillotine-q-how-can-i-keep-my-strings-from-being-decapped))
* Future-proof, does not require mass-replacing strings

To set up the repository, see [INSTALL.md](INSTALL.md).

## FAQ
### `(guillotine)` Q: How can I keep my string(s) from being decapped?
A: There are a number of ways to make a string "fixed case" so that it will not be decapitalized when displayed:

C strings: Replace the `_` with `_C`:
```c
// _C = fixed (C)ase string!
const u8 gText_IDNumber[] = _C("IDNo.");
```
ASM strings: Replace `.string` with `.fixstr`:
```arm
gText_SavingDontTurnOff::
    @ Lasts until the string terminator '$'
	.fixstr "SAVING…\n"
	.string "DON'T TURN OFF THE POWER.$"
```
You can fix-case/unfix parts of a string like so:
```arm
	.string "{FIXED_CASE}WARNING!{UNFIX_CASE}\p"
```
For a placeholder (only the placeholder will be fixed-case):
```arm
	.string "{STR_VAR_2_FIXED} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
```
See also the configuration in [text.h](gflib/text.h).

There are also a number of bigram exceptions that will not be decapped: `TV, TM, HP, HM, PC, PP, PM`



## See also

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
