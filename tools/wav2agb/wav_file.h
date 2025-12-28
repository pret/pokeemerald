#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <cstdint>

#define WAV_INVALID_VAL 0xFFFFFFFFu

// Structure for WAV chunk utilities
struct WavChunk {
    std::string id;
    std::vector<uint8_t> data;
};

void write_wav_with_agbl_chunk(const std::string& output_path,
                                std::vector<WavChunk>& chunks,
                                uint32_t loop_end_value);

class wav_file {
public:
    wav_file(const std::string& path);
    ~wav_file();

    void readData(size_t location, double *data, size_t len);
private:
    std::ifstream ifs;
    std::streampos dataChunkPos;
    std::streampos dataChunkEndPos;
    size_t loadedChunk = WAV_INVALID_VAL;

    std::vector<double> loadBuffer;
    size_t loadBufferBlock = std::numeric_limits<size_t>::max();
    enum class format_type {
        u8, s16, s24, s32,
        f32, f64,
    } fmt;
    uint32_t fmt_size() const;
public:
    uint32_t loopStart = 0; // samples
    uint32_t loopEnd = std::numeric_limits<uint32_t>::max();   // samples
    bool loopEnabled = false;
    double tuning = 0.0;    // cents
    uint8_t midiKey = 60;
    uint32_t sampleRate;
    uint32_t numSamples = 0; // total number of samples in the file
    uint32_t agbPitch = 0; // optional: exact GBA pitch value from 'agbp' chunk (0 = not present)
    uint32_t agbLoopEnd = 0; // optional: exact loop end from 'agbl' chunk (0 = not present)
    std::vector<WavChunk> chunks; // raw chunks from the WAV file (for re-writing with modifications)
};
