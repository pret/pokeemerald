# wav2agb
"wav2agb" is a tool to convert standard .wav files to GBA compatible .s or .bin files.  Intended to convert .wav files for the use with the mp2k/m4a sound driver.

This copy has been slightly modified from [ipatix's original implementation](https://github.com/ipatix/wav2agb) in the following ways:
1. Support outputting `.bin` files with a command line option `-b, --binary`. (The original only supports outputting `.s` assembly files.)
2. Support reading an override "pitch" value from a custom `agbp` RIFF chunk.
   - This is needed to properly match some samples, due to float-point rounding errors when attempting to infer the pitch/sample rate from the .wav file's sample rate.
   - If the custom `agbp` chunk isn't present, it will simply use the .wav's sample rate to calculate this "pitch" value.
3. Optionally omits trailing padding from compressed output.

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
```

Flag -c enables compression (only supported by Pokemon Games)
