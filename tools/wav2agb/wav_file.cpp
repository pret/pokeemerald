#include "wav_file.h"

#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <algorithm>

static uint32_t read_u32(std::ifstream& ifs)
{
    uint8_t lenBytes[4];
    ifs.read(reinterpret_cast<char *>(lenBytes), sizeof(lenBytes));
    uint32_t retval = lenBytes[0] | (lenBytes[1] << 8) | (lenBytes[2] << 16) | (lenBytes[3] << 24);
    return retval;
}

//static uint16_t read_u16(std::ifstream& ifs)
//{
//    uint8_t lenBytes[2];
//    ifs.read(reinterpret_cast<char *>(lenBytes), sizeof(lenBytes));
//    uint16_t retval = uint16_t(lenBytes[0] | (lenBytes[1] << 8));
//    return retval;
//}

static std::string read_str(std::ifstream& ifs, size_t len)
{
    std::vector<char> buf(len);
    ifs.read(buf.data(), buf.size());
    return std::string(buf.data(), buf.size());
}

static std::vector<uint8_t> read_arr(std::ifstream& ifs, size_t len)
{
    std::vector<uint8_t> buf(len);
    ifs.read(reinterpret_cast<char *>(buf.data()), buf.size());
    return buf;
}

static uint16_t arr_u16(const std::vector<uint8_t>& arr, size_t pos)
{
    uint16_t val = uint16_t(arr.at(pos) | (arr.at(pos + 1) << 8));
    return val;
}

static uint32_t arr_u32(const std::vector<uint8_t>& arr, size_t pos)
{
    uint32_t val = uint32_t(arr.at(pos) | (arr.at(pos + 1) << 8) |
            (arr.at(pos + 2) << 16) | (arr.at(pos + 3) << 24));
    return val;
}

static const size_t loadChunkSize = 2048;

uint32_t wav_file::fmt_size() const
{
    if (fmt == format_type::u8)
        return 1;
    else if (fmt == format_type::s16)
        return 2;
    else if (fmt == format_type::s24)
        return 3;
    else if (fmt == format_type::s32)
        return 4;
    else if (fmt == format_type::f32)
        return 4;
    else if (fmt == format_type::f64)
        return 8;
    else
        throw std::runtime_error("INTERNAL ERROR: invalid format type");
}

wav_file::wav_file(const std::string& path) : loadBuffer(loadChunkSize)
{
    ifs.exceptions(std::ios::badbit | std::ios::eofbit);
    ifs.open(path, std::ios::binary);
    if (!ifs.good())
        throw std::runtime_error("failed to open file: " + path + ", reason: " + strerror(errno));
    if (!ifs.is_open())
        throw std::runtime_error("failed to open file: " + path + ", reason: " + strerror(errno));

    ifs.seekg(0, ifs.end);
    std::streampos len = ifs.tellg();
    ifs.seekg(0, ifs.beg);

    std::string chunkId = read_str(ifs, 4);
    if (chunkId != "RIFF")
        throw std::runtime_error("RIFF ID invalid");
    uint32_t mainChunkLen = read_u32(ifs);
    if (mainChunkLen + 8 != len)
        throw std::runtime_error("RIFF chunk len (=" +
                std::to_string(mainChunkLen) +
                ") doesn't match file len (=" +
                std::to_string(len) +
                ")");
    std::string riffType = read_str(ifs, 4);
    if (riffType != "WAVE")
        throw std::runtime_error("WAVE ID invalid");

    bool dataChunkFound = false;
    bool fmtChunkFound = false;
    // search all chunks
    std::streampos curPos;
    while ((curPos = ifs.tellg()) + std::streampos(8) <= len) {
        chunkId = read_str(ifs, 4);
        uint32_t chunkLen = read_u32(ifs);
        if (curPos + std::streampos(8) + std::streampos(chunkLen) > len)
            throw std::runtime_error("ERROR: chunk goes beyond end of file: offset=" + std::to_string(curPos));

        if (chunkId == "fmt ") {
            fmtChunkFound = true;
            std::vector<uint8_t> fmtChunk = read_arr(ifs, chunkLen);
            uint16_t fmtTag = arr_u16(fmtChunk, 0);
            uint16_t numChannels = arr_u16(fmtChunk, 2);
            if (numChannels != 1)
                throw std::runtime_error("ERROR: input file is NOT mono");
            this->sampleRate = arr_u32(fmtChunk, 4);
            uint16_t block_align = arr_u16(fmtChunk, 12);
            uint16_t bits_per_sample = arr_u16(fmtChunk, 14);
            if (fmtTag == 1) {
                // integer
                if (block_align == 1 && bits_per_sample == 8)
                    this->fmt = format_type::u8;
                else if (block_align == 2 && bits_per_sample == 16)
                    this->fmt = format_type::s16;
                else if (block_align == 3 && bits_per_sample == 24)
                    this->fmt = format_type::s24;
                else if (block_align == 4 && bits_per_sample == 32)
                    this->fmt = format_type::s32;
                else
                    throw std::runtime_error("ERROR: unsupported integer format combination");
            } else if (fmtTag == 3) {
                // float
                if (block_align == 4 && bits_per_sample == 32)
                    this->fmt = format_type::f32;
                else if (block_align == 8 && bits_per_sample == 64)
                    this->fmt = format_type::f64;
                else
                    throw std::runtime_error("ERROR: unsupported float format combination");
            } else {
                throw std::runtime_error("ERROR: unsupported format code: " + std::to_string(fmtTag));
            }
        } else if (chunkId == "data") {
            dataChunkFound = true;
            dataChunkPos = ifs.tellg();
            dataChunkEndPos = dataChunkPos + std::streampos(chunkLen);
            ifs.seekg(chunkLen, ifs.cur);
        } else if (chunkId == "smpl") {
            std::vector<uint8_t> smplChunk = read_arr(ifs, chunkLen);
            uint32_t midiUnityNote = arr_u32(smplChunk, 12);
            this->midiKey = static_cast<uint8_t>(std::min(midiUnityNote, 127u));
            uint32_t midiPitchFraction = arr_u32(smplChunk, 16);
            // the values below convert the uint32_t range to 0.0 to 100.0 range
            this->tuning = static_cast<double>(midiPitchFraction) / (4294967296.0 * 100.0);
            uint32_t numLoops = arr_u32(smplChunk, 28);
            if (numLoops > 1)
                throw std::runtime_error("ERROR: too many loops in smpl chunk");
            if (numLoops == 1) {
                uint32_t loopType = arr_u32(smplChunk, 36 + 4);
                if (loopType != 0)
                    throw std::runtime_error("ERROR: loop type not supported: " + std::to_string(loopType));
                this->loopStart = arr_u32(smplChunk, 36 + 8);
                // sampler chunks tell the last sample to be played (so including rather than excluding), thus +1
                this->loopEnd = arr_u32(smplChunk, 36 + 12) + 1;
                this->loopEnabled = true;
            }
        } else if (chunkId == "agbp") {
            // Custom chunk: exact GBA pitch value (sample_rate * 1024)
            // This allows perfect round-trip conversion without period-based precision loss
            std::vector<uint8_t> agbpChunk = read_arr(ifs, chunkLen);
            if (chunkLen >= 4) {
                this->agbPitch = arr_u32(agbpChunk, 0);
            }
        } else {
            //fprintf(stderr, "WARNING: ignoring unknown chunk type: <%s>\n", chunkId.c_str());
            ifs.seekg(chunkLen, ifs.cur);
        }

        /* https://en.wikipedia.org/wiki/Resource_Interchange_File_Format#Explanation
         * If chunk size is odd, skip the pad byte */
        if ((chunkLen % 2) == 1)
            ifs.seekg(1, ifs.cur);
    }

    if (!fmtChunkFound)
        throw std::runtime_error("ERROR: fmt chunk not found");
    if (!dataChunkFound)
        throw std::runtime_error("ERROR: data chunk not found");

    uint32_t numSamples = static_cast<uint32_t>(dataChunkEndPos - dataChunkPos) / fmt_size();
    this->loopEnd = std::min(this->loopEnd, numSamples);
}

wav_file::~wav_file()
{
    ifs.close();
}

void wav_file::readData(size_t location, double *data, size_t len)
{
    while (len-- > 0) {
        if (loadedChunk != location - (location % loadChunkSize)) {
            loadedChunk = location - (location % loadChunkSize);

            std::streampos blockpos = this->dataChunkPos + std::streampos(loadedChunk * fmt_size());
            std::streampos endblockpos = this->dataChunkEndPos;
            size_t actualChunkSize = std::min(loadChunkSize, static_cast<size_t>(endblockpos - blockpos) / fmt_size());

            if (actualChunkSize == 0) {
                std::fill(loadBuffer.begin(), loadBuffer.end(), 0.0);
                goto load_sample;
            }

            ifs.seekg(blockpos, ifs.beg);
            std::vector<uint8_t> ld(actualChunkSize * fmt_size());
            ifs.read(reinterpret_cast<char *>(ld.data()), ld.size());

            if (fmt == format_type::u8) {
                for (size_t i = 0; i < actualChunkSize; i++) {
                    loadBuffer[i] = (double(ld[i]) - 128.0) / 128.0;
                }
            } else if (fmt == format_type::s16) {
                for (size_t i = 0; i < actualChunkSize; i++) {
                    int32_t s =
                        (ld[i * fmt_size() + 0] << 0) |
                        (ld[i * fmt_size() + 1] << 8);
                    s <<= 16;
                    s >>= 16;
                    loadBuffer[i] = double(s) / 32768.0;
                }
            } else if (fmt == format_type::s24) {
                for (size_t i = 0; i < actualChunkSize; i++) {
                    int32_t s =
                        (ld[i * fmt_size() + 0] << 0) |
                        (ld[i * fmt_size() + 1] << 8) |
                        (ld[i * fmt_size() + 2] << 16);
                    s <<= 8;
                    s >>= 8;
                    loadBuffer[i] = double(s) / 8388608.0;
                }
            } else if (fmt == format_type::s32) {
                for (size_t i = 0; i < actualChunkSize; i++) {
                    int32_t s =
                        (ld[i * fmt_size() + 0] << 0) |
                        (ld[i * fmt_size() + 1] << 8) |
                        (ld[i * fmt_size() + 2] << 16) |
                        (ld[i * fmt_size() + 3] << 24);
                    loadBuffer[i] = double(s) / 2147483648.0;
                }
            } else if (fmt == format_type::f32) {
                for (size_t i = 0; i < actualChunkSize; i++) {
                    union {
                        uint32_t s;
                        float f;
                    } u;
                    u.s = 
                        (ld[i * fmt_size() + 0] << 0) |
                        (ld[i * fmt_size() + 1] << 8) |
                        (ld[i * fmt_size() + 2] << 16) |
                        (ld[i * fmt_size() + 3] << 24);
                    loadBuffer[i] = u.f;
                }
            } else if (fmt == format_type::f64) {
                for (size_t i = 0; i < actualChunkSize; i++) {
                    union {
                        uint64_t s;
                        double d;
                    } u;
                    u.s = 
                        (uint64_t(ld[i * fmt_size() + 0]) << 0) |
                        (uint64_t(ld[i * fmt_size() + 1]) << 8) |
                        (uint64_t(ld[i * fmt_size() + 2]) << 16) |
                        (uint64_t(ld[i * fmt_size() + 3]) << 24) |
                        (uint64_t(ld[i * fmt_size() + 4]) << 32) |
                        (uint64_t(ld[i * fmt_size() + 5]) << 40) |
                        (uint64_t(ld[i * fmt_size() + 6]) << 48) |
                        (uint64_t(ld[i * fmt_size() + 7]) << 56);
                    loadBuffer[i] = u.d;
                }
            }
            for (size_t i = actualChunkSize; i < loadChunkSize; i++) {
                loadBuffer[i] = 0.0;
            }
        }
load_sample:
        *data++ = loadBuffer[location % loadChunkSize];
        location++;
    }
}
