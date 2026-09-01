#!/usr/bin/env python3

"""
Converts .bin audio files (GBA format) to .wav files.
Reads the binary format created by aif2pcm and generates WAV files
that will produce identical binaries when processed by wav2agb -b.
"""

import struct
import sys
import os
from typing import Optional

# Delta encoding table used for compression/decompression
# Matches the table in tools/aif2pcm/main.c
DELTA_ENCODING_TABLE = [
    0, 1, 4, 9, 16, 25, 36, 49,
    -64, -49, -36, -25, -16, -9, -4, -1,
]


def delta_decompress(compressed_data: bytes, expected_length: int) -> bytes:
    """
    Decompress delta-encoded audio data.

    Delta compression format (from tools/aif2pcm/main.c):
    - Data is organized in blocks of up to 64 samples each
    - Each block starts with a base sample value (1 byte)
    - Followed by a delta index (4 bits) for the second sample
    - Then 31 pairs of delta indices (4 bits each, packed into bytes)
    - Delta indices reference DELTA_ENCODING_TABLE to get the actual delta value

    Args:
        compressed_data: The compressed audio data
        expected_length: Expected length of decompressed data

    Returns:
        Decompressed audio data as bytes
    """
    pcm = bytearray(expected_length + 0x40)  # Extra buffer space

    i = 0  # Input position
    j = 0  # Output position

    while i < len(compressed_data) and j < expected_length:
        # Read base sample for this block
        base = compressed_data[i]
        # Convert to signed int8 for calculations
        base_signed = base if base < 128 else base - 256
        pcm[j] = base
        i += 1
        j += 1

        if i >= len(compressed_data) or j >= expected_length:
            break

        # Read second sample using low nibble delta
        lo = compressed_data[i] & 0xf
        base_signed += DELTA_ENCODING_TABLE[lo]
        pcm[j] = base_signed & 0xff
        i += 1
        j += 1

        if i >= len(compressed_data) or j >= expected_length:
            break

        # Process up to 31 pairs of samples (62 samples total)
        for k in range(31):
            # High nibble
            hi = (compressed_data[i] >> 4) & 0xf
            base_signed += DELTA_ENCODING_TABLE[hi]
            pcm[j] = base_signed & 0xff
            j += 1

            if j >= expected_length:
                break

            # Low nibble
            lo = compressed_data[i] & 0xf
            base_signed += DELTA_ENCODING_TABLE[lo]
            pcm[j] = base_signed & 0xff
            j += 1
            i += 1

            if i >= len(compressed_data):
                break
            if j >= expected_length:
                break

        if j >= expected_length:
            break

    return bytes(pcm[:j])


def read_bin(bin_path: str) -> tuple:
    """
    Read a GBA audio .bin file and extract all data.

    Binary format (little-endian):
    - Bytes 0-3: flags (bit 0 = compression, bit 30 = loop enabled)
    - Bytes 4-7: pitch value = sample_rate * 1024
    - Bytes 8-11: loop start position
    - Bytes 12-15: loop end position (stored as actual_end - 1)
    - Remaining bytes: audio samples (8-bit signed)
    """
    with open(bin_path, 'rb') as f:
        bin_data = f.read()

    if len(bin_data) < 16:
        raise ValueError(f"File too small: {len(bin_data)} bytes")

    # Read header
    flags = struct.unpack('<I', bin_data[0:4])[0]
    pitch_value = struct.unpack('<I', bin_data[4:8])[0]
    loop_start = struct.unpack('<I', bin_data[8:12])[0]
    loop_end_stored = struct.unpack('<I', bin_data[12:16])[0]

    # Extract flags
    is_compressed = (flags & 0x01) != 0
    is_looped = (flags & 0x40000000) != 0

    # Calculate sample rate from pitch value
    sample_rate = pitch_value / 1024.0

    # Loop end is stored as (actual_end - 1) in binary format
    # For the expected number of samples, we add 1
    expected_num_samples = loop_end_stored + 1

    # Read sample data (8-bit signed)
    compressed_data = bin_data[16:]

    if is_compressed:
        # Decompress the data
        # Note: delta_decompress may return fewer samples than expected if
        # the compressed data is shorter (this matches aif2pcm behavior)
        samples = delta_decompress(compressed_data, expected_num_samples)

        # Pad samples to expected length if needed (matching aif2pcm behavior)
        # This can happen when the compressed data is slightly short
        if len(samples) < expected_num_samples:
            # Pad with the last sample value
            last_sample = samples[-1] if len(samples) > 0 else 0
            padding = bytes([last_sample] * (expected_num_samples - len(samples)))
            samples = samples + padding
    else:
        # For uncompressed data, only read expected_num_samples
        # (ignore any trailing alignment padding in the .bin file)
        samples = compressed_data[:expected_num_samples]

    # For loop_end, use the expected number from the header
    # This matches aif2pcm's behavior where the COMM chunk has the expected count
    # even if the actual SSND data is shorter
    loop_end = expected_num_samples if is_looped else 0

    return sample_rate, is_looped, loop_start, loop_end, samples


def write_wav(wav_path: str, sample_rate: float, is_looped: bool,
              loop_start: int, loop_end: int, samples: bytes):
    """
    Write a .wav file with smpl chunk.
    """
    # WAV uses unsigned 8-bit, GBA bin uses signed 8-bit
    # Convert signed (-128 to +127) to unsigned (0 to 255)
    samples_unsigned = bytes((b + 128) & 0xFF for b in samples)

    # For WAV fmt chunk, use integer sample rate
    sample_rate_int = int(sample_rate)
    num_channels = 1
    bytes_per_sample = 1
    bits_per_sample = 8
    byte_rate = sample_rate_int * num_channels * bytes_per_sample
    block_align = num_channels * bytes_per_sample

    # Build fmt chunk
    fmt_chunk = struct.pack('<HHIIHH',
        1,                  # Audio format (1 = PCM)
        num_channels,       # Number of channels
        sample_rate_int,    # Sample rate (integer)
        byte_rate,          # Byte rate
        block_align,        # Block align
        bits_per_sample     # Bits per sample
    )

    # Build smpl chunk
    sample_period = int(1000000000.0 / sample_rate)

    # MIDI note: default to 60 (C4) since we don't have this info in the bin
    midi_note = 60

    smpl_chunk = struct.pack('<IIIIIIII',
        0,                      # Manufacturer
        0,                      # Product
        sample_period,          # Sample period (nanoseconds)
        midi_note,              # MIDI unity note
        0,                      # MIDI pitch fraction
        0,                      # SMPTE format
        0,                      # SMPTE offset
        1 if is_looped else 0   # Num sample loops
    )
    smpl_chunk += struct.pack('<I', 0)  # Sampler data

    # Add loop structure if loop exists
    if is_looped:
        # Loop end in binary is stored as (end - 1), so we already added 1 above
        loop_end_inclusive = loop_end - 1
        smpl_chunk += struct.pack('<IIIIII',
            0,                      # Cue point ID
            0,                      # Type (0 = forward loop)
            loop_start,             # Start
            loop_end_inclusive,     # End (inclusive)
            0,                      # Fraction
            0                       # Play count (0 = infinite)
        )

    # Build custom 'agbp' (AGB Pitch) chunk to store exact pitch value
    # This avoids precision loss from period-based round-trip
    # pitch_value = sample_rate * 1024 (GBA format)
    pitch_value_int = int(sample_rate * 1024.0)
    agbp_chunk = struct.pack('<I', pitch_value_int)

    # Calculate sizes
    data_chunk_size = len(samples_unsigned)
    fmt_chunk_size = len(fmt_chunk)
    smpl_chunk_size = len(smpl_chunk)
    agbp_chunk_size = len(agbp_chunk)

    # RIFF chunk size
    riff_size = 4 + 8 + fmt_chunk_size + 8 + smpl_chunk_size + 8 + agbp_chunk_size + 8 + data_chunk_size

    # Write WAV file
    with open(wav_path, 'wb') as f:
        # RIFF header
        f.write(b'RIFF')
        f.write(struct.pack('<I', riff_size))
        f.write(b'WAVE')

        # fmt chunk
        f.write(b'fmt ')
        f.write(struct.pack('<I', fmt_chunk_size))
        f.write(fmt_chunk)

        # smpl chunk
        f.write(b'smpl')
        f.write(struct.pack('<I', smpl_chunk_size))
        f.write(smpl_chunk)

        # agbp chunk (custom chunk for exact GBA pitch value)
        f.write(b'agbp')
        f.write(struct.pack('<I', agbp_chunk_size))
        f.write(agbp_chunk)

        # data chunk
        f.write(b'data')
        f.write(struct.pack('<I', data_chunk_size))
        f.write(samples_unsigned)


def convert_bin_to_wav(bin_path: str, wav_path: Optional[str] = None):
    """Convert a single .bin file to .wav format"""
    if wav_path is None:
        wav_path = os.path.splitext(bin_path)[0] + '.wav'

    print(f"Converting {bin_path} -> {wav_path}")

    sample_rate, is_looped, loop_start, loop_end, samples = read_bin(bin_path)

    print(f"  Sample rate: {sample_rate} Hz")
    print(f"  Num samples: {len(samples)}")
    if is_looped:
        print(f"  Loop: {loop_start} -> {loop_end}")
    else:
        print(f"  Loop: None")

    write_wav(wav_path, sample_rate, is_looped, loop_start, loop_end, samples)
    print(f"  Done!")


def main():
    if len(sys.argv) < 2:
        print("Usage: bin_to_wav.py <input.bin> [output.wav]")
        print("   or: bin_to_wav.py <directory>  (converts all .bin files in directory)")
        sys.exit(1)

    input_path = sys.argv[1]

    if os.path.isdir(input_path):
        # Convert all .bin files in directory
        for filename in sorted(os.listdir(input_path)):
            if filename.lower().endswith('.bin'):
                bin_path = os.path.join(input_path, filename)
                convert_bin_to_wav(bin_path)
    else:
        # Convert single file
        output_path = sys.argv[2] if len(sys.argv) > 2 else None
        convert_bin_to_wav(input_path, output_path)


if __name__ == '__main__':
    main()
