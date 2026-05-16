#pragma once

#include <string>
#include <algorithm>
#include <cstdint>

enum class cmp_type {
    none, dpcm
};

enum class out_type {
    assembly, binary
};

void enable_dpcm_verbose();
void enable_dpcm_lookahead_fast();
void disable_dpcm_padding();
void set_dpcm_lookahead(size_t lookahead);
void set_wav_loop_start(uint32_t start);
void set_wav_loop_end(uint32_t end);
void set_wav_tune(double tune);
void set_wav_key(uint8_t key);
void set_wav_rate(uint32_t rate);

void convert(const std::string&, const std::string&,
        const std::string& sym, cmp_type ct, out_type ot);
