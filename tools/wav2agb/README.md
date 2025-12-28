# wav2agb
"wav2agb" is a tool to convert standard .wav files to GBA compatible .s or .bin files.  Intended to convert .wav files for the use with the mp2k/m4a sound driver.

This copy has been slightly modified from [ipatix's original implementation](https://github.com/ipatix/wav2agb) in the following ways:
1. Support outputting `.bin` files with a command line option `-b, --binary`. (The original only supports outputting `.s` assembly files.)
2. Support reading an override "pitch" value from a custom `agbp` RIFF chunk.
   - This is needed to properly match some samples, due to float-point rounding errors when attempting to infer the pitch/sample rate from the .wav file's sample rate.
   - If the custom `agbp` chunk isn't present, it will simply use the .wav's sample rate to calculate this "pitch" value.
3. Support reading an override "loop end" value from a custom `agbl` RIFF chunk.
   - This is needed to properly match vanilla samples, due their their inherent off-by-one error (the last sample is mistakenly ignored).
   - This `agbl` chunk can be added to existing .wav files with the `--set-agbl` option (described below).
4. Optionally omits trailing padding from compressed output.

Usage:
```
Usage: wav2agb [options] <input.wav> [<output>]

Options:
-s, --symbol <sym>       | symbol name for wave header (default: file name)
-l, --lookahead <amount> | DPCM compression lookahead 1..8 (default: 3)
-c, --compress           | compress output with DPCM
-f, --fast-compress      | compress output with DPCM fast
--no-pad                 | omit trailing padding in compressed output
-b, --binary             | output raw binary instead of assembly
--loop-start <pos>       | override loop start (integer)
--loop-end <pos>         | override loop end (integer)
--tune <cents>           | override tuning (float)
--key <key>              | override midi key (int)
--rate <rate>            | override base samplerate (int)
--set-agbl <loop-end>    | adds the custom agbl chunk to the given input .wav file
```

Flag -c enables compression (only supported by Pokemon Games)

## Adding agbl Chunk to WAV Files

The `--set-agbl` option allows you to add or update the custom `agbl` chunk in a WAV file. When this option is used, `wav2agb` will output a WAV file with the agbl chunk added, rather than converting to `.s` or `.bin` format.

The loop-end value can be specified as either:
- **Positive value**: Used as an absolute sample position
- **Negative value**: Treated as an offset from the end of the file

This is useful for correcting the off-by-one loop-end error in vanilla samples. The typical fix is `--set-agbl -1`, which sets the loop-end to `(total_samples - 1)`.

Example:
```bash
# Set agbl to (total_samples - 1), the most common case for fixing the off-by-one error
wav2agb --set-agbl -1 input.wav

# Set agbl chunk to specific sample position 12345
wav2agb --set-agbl 12345 input.wav output.wav

# If no output file is specified, the input file is modified in place
wav2agb --set-agbl -1 input.wav
```
