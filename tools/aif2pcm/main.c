// Copyright(c) 2016 huderlem
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/* extended.c */
void ieee754_write_extended (double, uint8_t*);
double ieee754_read_extended (uint8_t*);

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)           \
do                                         \
{                                          \
	fprintf(stderr, format, __VA_ARGS__);  \
	exit(1);                               \
} while (0)

#else

#define FATAL_ERROR(format, ...)            \
do                                          \
{                                           \
	fprintf(stderr, format, ##__VA_ARGS__); \
	exit(1);                                \
} while (0)

#endif // _MSC_VER

typedef struct {
	unsigned long num_samples;
	union {
		uint8_t *samples8;
		uint16_t *samples16;
	};
	uint8_t midi_note;
	uint8_t sample_size;
	bool has_loop;
	unsigned long loop_offset;
	double sample_rate;
	unsigned long real_num_samples;
} AifData;

struct Bytes {
	unsigned long length;
	uint8_t *data;
};

struct Marker {
	unsigned short id;
	unsigned long position;
	// don't care about the name
};

struct Bytes *read_bytearray(const char *filename)
{
	struct Bytes *bytes = malloc(sizeof(struct Bytes));
	FILE *f = fopen(filename, "rb");
	if (!f)
	{
		FATAL_ERROR("Failed to open '%s' for reading!\n", filename);
	}
	fseek(f, 0, SEEK_END);
	bytes->length = ftell(f);
	fseek(f, 0, SEEK_SET);
	bytes->data = malloc(bytes->length);
	unsigned long read = fread(bytes->data, bytes->length, 1, f);
	fclose(f);
	if (read <= 0)
	{
		FATAL_ERROR("Failed to read data from '%s'!\n", filename);
	}
	return bytes;
}

void write_bytearray(const char *filename, struct Bytes *bytes)
{
	FILE *f = fopen(filename, "wb");
	if (!f)
	{
		FATAL_ERROR("Failed to open '%s' for writing!\n", filename);
	}
	fwrite(bytes->data, bytes->length, 1, f);
	fclose(f);
}

void free_bytearray(struct Bytes *bytes)
{
	free(bytes->data);
	free(bytes);
}

char *get_file_extension(char *filename)
{
	char *index = strrchr(filename, '.');
	if (!index || index == filename)
	{
		return NULL;
	}
	return index + 1;
}

char *new_file_extension(char *filename, char *ext)
{
	char *index = strrchr(filename, '.');
	if (!index || index == filename)
	{
		index = filename + strlen(filename);
	}
	int length = index - filename;
	char *new_filename = malloc(length + 1 + strlen(ext) + 1);
	if (new_filename)
	{
		strcpy(new_filename, filename);
		new_filename[length] = '.';
		strcpy(new_filename + length + 1, ext);
	}
	return new_filename;
}

void read_aif(struct Bytes *aif, AifData *aif_data)
{
	aif_data->has_loop = false;
	aif_data->num_samples = 0;

	unsigned long pos = 0;
	char chunk_name[5]; chunk_name[4] = '\0';
	char chunk_type[5]; chunk_type[4] = '\0';

	// Check for FORM Chunk
	memcpy(chunk_name, &aif->data[pos], 4);
	pos += 4;
	if (strcmp(chunk_name, "FORM") != 0)
	{
		FATAL_ERROR("Input .aif file has invalid header Chunk '%s'!\n", chunk_name);
	}

	// Read size of whole file.
	unsigned long whole_chunk_size = aif->data[pos++] << 24;
	whole_chunk_size |= (aif->data[pos++] << 16);
	whole_chunk_size |= (aif->data[pos++] <<  8);
	whole_chunk_size |= (uint8_t)aif->data[pos++];

	unsigned long expected_whole_chunk_size = aif->length - 8;
	if (whole_chunk_size != expected_whole_chunk_size)
	{
		FATAL_ERROR("FORM Chunk ckSize '%lu' doesn't match actual size '%lu'!\n", whole_chunk_size, expected_whole_chunk_size);
	}

	// Check for AIFF Form Type
	memcpy(chunk_type, &aif->data[pos], 4);
	pos += 4;
	if (strcmp(chunk_type, "AIFF") != 0)
	{
		FATAL_ERROR("FORM Type is '%s', but it must be AIFF!", chunk_type);
	}

	struct Marker *markers = NULL;
	unsigned short num_markers = 0, loop_start = 0, loop_end = 0;
	unsigned long num_sample_frames = 0;

	// Read all the Chunks to populate the AifData struct.
	while ((pos + 8) < aif->length)
	{
		// Read Chunk id
		memcpy(chunk_name, &aif->data[pos], 4);
		pos += 4;

		unsigned long chunk_size = (aif->data[pos++] << 24);
		chunk_size |= (aif->data[pos++] << 16);
		chunk_size |= (aif->data[pos++] <<  8);
		chunk_size |=  aif->data[pos++];

		if ((pos + chunk_size) > aif->length)
		{
			FATAL_ERROR("%s chunk at 0x%lx reached end of file before finishing\n", chunk_name, pos);
		}

		if (strcmp(chunk_name, "COMM") == 0)
		{
			short num_channels = (aif->data[pos++] << 8);
			num_channels |= (uint8_t)aif->data[pos++];
			if (num_channels != 1)
			{
				FATAL_ERROR("numChannels (%d) in the COMM Chunk must be 1!\n", num_channels);
			}

			num_sample_frames =  (aif->data[pos++] << 24);
			num_sample_frames |= (aif->data[pos++] << 16);
			num_sample_frames |= (aif->data[pos++] <<  8);
			num_sample_frames |=  (uint8_t)aif->data[pos++];

			aif_data->sample_size = (aif->data[pos++] << 8);
			aif_data->sample_size |= (uint8_t)aif->data[pos++];
			if (aif_data->sample_size != 8 && aif_data->sample_size != 16)
			{
				FATAL_ERROR("sampleSize (%d) in the COMM Chunk must be 8 or 16!\n", aif_data->sample_size);
			}

			double sample_rate = ieee754_read_extended((uint8_t*)(aif->data + pos));
			pos += 10;

			aif_data->sample_rate = sample_rate;

			if (aif_data->num_samples == 0)
			{
				aif_data->num_samples = num_sample_frames;
			}
		}
		else if (strcmp(chunk_name, "MARK") == 0)
		{
			num_markers = (aif->data[pos++] << 8);
			num_markers |= (uint8_t)aif->data[pos++];

			if (markers)
			{
				FATAL_ERROR("More than one MARK Chunk in file!\n");
			}

			markers = calloc(num_markers, sizeof(struct Marker));

			// Read each marker.
			for (int i = 0; i < num_markers; i++)
			{
				unsigned short marker_id = (aif->data[pos++] << 8);
				marker_id |= (uint8_t)aif->data[pos++];

				unsigned long marker_position = (aif->data[pos++] << 24);
				marker_position |= (aif->data[pos++] << 16);
				marker_position |= (aif->data[pos++] << 8);
				marker_position |=  (uint8_t)aif->data[pos++];

				// Marker name is a Pascal-style string.
				uint8_t marker_name_size = aif->data[pos++];
				// We don't actually need the marker name for anything anymore.
				/*char *marker_name = (char *)malloc((marker_name_size + 1) * sizeof(char));
				memcpy(marker_name, &aif->data[pos], marker_name_size);
				marker_name[marker_name_size] = '\0';*/
				pos += marker_name_size + !(marker_name_size & 1);

				markers[i].id = marker_id;
				markers[i].position = marker_position;
			}
		}
		else if (strcmp(chunk_name, "INST") == 0)
		{
			uint8_t midi_note = (uint8_t)aif->data[pos++];

			aif_data->midi_note = midi_note;

			// Skip over data we don't need.
			pos += 7;

			unsigned short loop_type = (aif->data[pos++] << 8);
			loop_type |= (uint8_t)aif->data[pos++];

			if (loop_type)
			{
				loop_start = (aif->data[pos++] << 8);
				loop_start |= (uint8_t)aif->data[pos++];

				loop_end = (aif->data[pos++] << 8);
				loop_end |= (uint8_t)aif->data[pos++];
			}
			else
			{
				// Skip NoLooping sustain loop.
				pos += 4;
			}

			// Skip release loop, we don't need it.
			pos += 6;
		}
		else if (strcmp(chunk_name, "SSND") == 0)
		{
			// Skip offset and blockSize
			pos += 8;

			unsigned long num_samples = chunk_size - 8;
			if (aif_data->sample_size == 8)
			{
				uint8_t *sample_data = (uint8_t *)malloc(num_samples * sizeof(uint8_t));
				memcpy(sample_data, &aif->data[pos], num_samples);

				aif_data->samples8 = sample_data;
				aif_data->real_num_samples = num_samples;
			}
			else
			{
				uint16_t *sample_data = (uint16_t *)malloc(num_samples * sizeof(uint16_t));
				uint16_t *sample_data_swapped = (uint16_t *)malloc(num_samples * sizeof(uint16_t));
				memcpy(sample_data, &aif->data[pos], num_samples);
				for (long unsigned i = 0; i < num_samples; i++)
				{
					sample_data_swapped[i] = __builtin_bswap16(sample_data[i]);
				}

				aif_data->samples16 = sample_data_swapped;
				aif_data->real_num_samples = num_samples;
				free(sample_data);
			}
			pos += chunk_size - 8;
		}
		else
		{
			// Skip over unsupported chunks.
			pos += chunk_size;
		}
	}

	if (markers)
	{
		// Resolve loop points.
		struct Marker *cur_marker = markers;

		// Grab loop start point.
		for (int i = 0; i < num_markers; i++, cur_marker++)
		{
			if (cur_marker->id == loop_start)
			{
				aif_data->loop_offset = cur_marker->position;
				aif_data->has_loop = true;
				break;
			}
		}

		cur_marker = markers;

		// Grab loop end point.
		for (int i = 0; i < num_markers; i++, cur_marker++)
		{
			if (cur_marker->id == loop_end)
			{
				if (cur_marker->position < aif_data->loop_offset) {
					aif_data->loop_offset = cur_marker->position;
					aif_data->has_loop = true;
				}
				aif_data->num_samples = cur_marker->position;
				break;
			}
		}

		free(markers);
	}
}

// This is a table of deltas between sample values in compressed PCM data.
const int gDeltaEncodingTable[] = {
	0, 1, 4, 9, 16, 25, 36, 49,
	-64, -49, -36, -25, -16, -9, -4, -1,
};

#define POSITIVE_DELTAS_START 0
#define POSITIVE_DELTAS_END 8

#define NEGATIVE_DELTAS_START 8
#define NEGATIVE_DELTAS_END 16

struct Bytes *delta_decompress(struct Bytes *delta, unsigned int expected_length)
{
	struct Bytes *pcm = malloc(sizeof(struct Bytes));
	pcm->length = expected_length;
	pcm->data = malloc(pcm->length + 0x40);

	uint8_t hi, lo;
	unsigned int i = 0;
	unsigned int j = 0;
	int k;
	int8_t base;
	while (i < delta->length)
	{
		base = (int8_t)delta->data[i++];
		pcm->data[j++] = (uint8_t)base;
		if (i >= delta->length)
		{
			break;
		}
		if (j >= pcm->length)
		{
			break;
		}
		lo = delta->data[i] & 0xf;
		base += gDeltaEncodingTable[lo];
		pcm->data[j++] = base;
		i++;
		if (i >= delta->length)
		{
			break;
		}
		if (j >= pcm->length)
		{
			break;
		}
		for (k = 0; k < 31; k++)
		{
			hi = (delta->data[i] >> 4) & 0xf;
			base += gDeltaEncodingTable[hi];
			pcm->data[j++] = base;
			if (j >= pcm->length)
			{
				break;
			}
			lo = delta->data[i] & 0xf;
			base += gDeltaEncodingTable[lo];
			pcm->data[j++] = base;
			i++;
			if (i >= delta->length)
			{
				break;
			}
			if (j >= pcm->length)
			{
				break;
			}
		}
		if (j >= pcm->length)
		{
			break;
		}
	}

	pcm->length = j;
	return pcm;
}

#define U8_TO_S8(value) ((value) < 128 ? (value) : (value) - 256)
#define ABS(value) ((value) >= 0 ? (value) : -(value))

int get_delta_index(uint8_t sample, uint8_t prev_sample)
{
	int best_error = INT_MAX;
	int best_index = -1;
	int delta_table_start_index;
	int delta_table_end_index;
	int sample_signed = U8_TO_S8(sample);
	int prev_sample_signed = U8_TO_S8(prev_sample);

    // if we're going up (or equal), only choose positive deltas
	if (prev_sample_signed <= sample_signed) {
		delta_table_start_index = POSITIVE_DELTAS_START;
		delta_table_end_index = POSITIVE_DELTAS_END;
	} else {
		delta_table_start_index = NEGATIVE_DELTAS_START;
		delta_table_end_index = NEGATIVE_DELTAS_END;
	}

	for (int i = delta_table_start_index; i < delta_table_end_index; i++)
	{
		uint8_t new_sample = prev_sample + gDeltaEncodingTable[i];
		int new_sample_signed = U8_TO_S8(new_sample);
		int error = ABS(new_sample_signed - sample_signed);

		if (error < best_error)
		{
			best_error = error;
			best_index = i;
		}
	}

	return best_index;
}

struct Bytes *delta_compress(struct Bytes *pcm)
{
	struct Bytes *delta = malloc(sizeof(struct Bytes));
	// estimate the length so we can malloc
	int num_blocks = pcm->length / 64;
	delta->length = num_blocks * 33;

	int extra = pcm->length % 64;
	if (extra)
	{
		delta->length += 1;
		extra -= 1;
	}
	if (extra)
	{
		delta->length += 1;
		extra -= 1;
	}
	if (extra)
	{
		delta->length += (extra + 1) / 2;
	}

	delta->data = malloc(delta->length + 33);

	unsigned int i = 0;
	unsigned int j = 0;
	int k;
	uint8_t base;
	int delta_index;

	while (i < pcm->length)
	{
		base = pcm->data[i++];
		delta->data[j++] = base;

		if (i >= pcm->length)
		{
			break;
		}
		delta_index = get_delta_index(pcm->data[i++], base);
		base += gDeltaEncodingTable[delta_index];
		delta->data[j++] = delta_index;

		for (k = 0; k < 31; k++)
		{
			if (i >= pcm->length)
			{
				break;
			}
			delta_index = get_delta_index(pcm->data[i++], base);
			base += gDeltaEncodingTable[delta_index];
			delta->data[j] = (delta_index << 4);

			if (i >= pcm->length)
			{
				break;
			}
			delta_index = get_delta_index(pcm->data[i++], base);
			base += gDeltaEncodingTable[delta_index];
			delta->data[j++] |= delta_index;
		}
	}

	delta->length = j;

	return delta;
}

#define STORE_U32_LE(dest, value) \
do { \
	*(dest) = (value) & 0xff; \
	*((dest) + 1) = ((value) >> 8) & 0xff; \
	*((dest) + 2) = ((value) >> 16) & 0xff; \
	*((dest) + 3) = ((value) >> 24) & 0xff; \
} while (0)

#define LOAD_U32_LE(var, src) \
do { \
	(var) = *(src); \
	(var) |= (*((src) + 1) << 8); \
	(var) |= (*((src) + 2) << 16); \
	(var) |= (*((src) + 3) << 24); \
} while (0)

// Reads an .aif file and produces a .pcm file containing an array of 8-bit samples.
void aif2pcm(const char *aif_filename, const char *pcm_filename, bool compress)
{
	struct Bytes *aif = read_bytearray(aif_filename);
	AifData aif_data = {0};
	read_aif(aif, &aif_data);

	// Convert 16-bit to 8-bit if necessary
	if (aif_data.sample_size == 16)
	{
		aif_data.real_num_samples /= 2;
		uint8_t *converted_samples = malloc(aif_data.real_num_samples * sizeof(uint8_t));
		for (unsigned long i = 0; i < aif_data.real_num_samples; i++)
		{
			converted_samples[i] = aif_data.samples16[i] >> 8;
		}
		free(aif_data.samples16);
		aif_data.samples8 = converted_samples;
	}

	int header_size = 0x10;
	struct Bytes *pcm;
	struct Bytes output = {0,0};

	if (compress)
	{
		struct Bytes *input = malloc(sizeof(struct Bytes));
		input->data = aif_data.samples8;
		input->length = aif_data.real_num_samples;
		pcm = delta_compress(input);
		free(input);
	}
	else
	{
		pcm = malloc(sizeof(struct Bytes));
		pcm->data = aif_data.samples8;
		pcm->length = aif_data.real_num_samples;
	}
	output.length = header_size + pcm->length;
	output.data = malloc(output.length);

	uint32_t pitch_adjust = (uint32_t)(aif_data.sample_rate * 1024);
	uint32_t loop_offset = (uint32_t)(aif_data.loop_offset);
	uint32_t adjusted_num_samples = (uint32_t)(aif_data.num_samples - 1);
	uint32_t flags = 0;
	if (aif_data.has_loop) flags |= 0x40000000;
	if (compress) flags |= 1;
	STORE_U32_LE(output.data + 0, flags);
	STORE_U32_LE(output.data + 4, pitch_adjust);
	STORE_U32_LE(output.data + 8, loop_offset);
	STORE_U32_LE(output.data + 12, adjusted_num_samples);
	memcpy(&output.data[header_size], pcm->data, pcm->length);
	write_bytearray(pcm_filename, &output);

	free(aif->data);
	free(aif);
	free(pcm);
	free(output.data);
	free(aif_data.samples8);
}

// Reads a .pcm file containing an array of 8-bit samples and produces an .aif file.
// See http://www-mmsp.ece.mcgill.ca/documents/audioformats/aiff/Docs/AIFF-1.3.pdf for .aif file specification.
void pcm2aif(const char *pcm_filename, const char *aif_filename, uint32_t base_note)
{
	struct Bytes *pcm = read_bytearray(pcm_filename);

	AifData *aif_data = malloc(sizeof(AifData));

	uint32_t flags;
	LOAD_U32_LE(flags, pcm->data + 0);
	aif_data->has_loop = flags & 0x40000000;
	bool compressed = flags & 1;

	uint32_t pitch_adjust;
	LOAD_U32_LE(pitch_adjust, pcm->data + 4);
	aif_data->sample_rate = pitch_adjust / 1024.0;

	LOAD_U32_LE(aif_data->loop_offset, pcm->data + 8);
	LOAD_U32_LE(aif_data->num_samples, pcm->data + 12);
	aif_data->num_samples += 1;

	if (compressed)
	{
		struct Bytes *delta = pcm;
		uint8_t *pcm_data = pcm->data;
		delta->length -= 0x10;
		delta->data += 0x10;
		pcm = delta_decompress(delta, aif_data->num_samples);
		free(pcm_data);
		free(delta);
	}
	else
	{
		pcm->length -= 0x10;
		pcm->data += 0x10;
	}

	aif_data->samples8 = malloc(pcm->length);
	memcpy(aif_data->samples8, pcm->data, pcm->length);

	struct Bytes *aif = malloc(sizeof(struct Bytes));
	aif->length = 54 + 60 + pcm->length;
	aif->data = malloc(aif->length);

	long pos = 0;

	// First, write the FORM header chunk.
	// FORM Chunk ckID
	aif->data[pos++] = 'F';
	aif->data[pos++] = 'O';
	aif->data[pos++] = 'R';
	aif->data[pos++] = 'M';

	// FORM Chunk ckSize
	unsigned long form_size = pos;
	unsigned long data_size = aif->length - 8;
	aif->data[pos++] = ((data_size >> 24) & 0xFF);
	aif->data[pos++] = ((data_size >> 16) & 0xFF);
	aif->data[pos++] = ((data_size >>  8) & 0xFF);
	aif->data[pos++] = (data_size & 0xFF);

	// FORM Chunk formType
	aif->data[pos++] = 'A';
	aif->data[pos++] = 'I';
	aif->data[pos++] = 'F';
	aif->data[pos++] = 'F';

	// Next, write the Common Chunk
	// Common Chunk ckID
	aif->data[pos++] = 'C';
	aif->data[pos++] = 'O';
	aif->data[pos++] = 'M';
	aif->data[pos++] = 'M';

	// Common Chunk ckSize
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 18;

	// Common Chunk numChannels
	aif->data[pos++] = 0;
	aif->data[pos++] = 1;  // 1 channel

	// Common Chunk numSampleFrames
	aif->data[pos++] = ((aif_data->num_samples >> 24) & 0xFF);
	aif->data[pos++] = ((aif_data->num_samples >> 16) & 0xFF);
	aif->data[pos++] = ((aif_data->num_samples >> 8)  & 0xFF);
	aif->data[pos++] = (aif_data->num_samples & 0xFF);

	// Common Chunk sampleSize
	aif->data[pos++] = 0;
	aif->data[pos++] = 8;  // 8 bits per sample

	// Common Chunk sampleRate
	//double sample_rate = pitch_adjust / 1024.0;
	uint8_t sample_rate_buffer[10];
	ieee754_write_extended(aif_data->sample_rate, sample_rate_buffer);
	for (int i = 0; i < 10; i++)
	{
		aif->data[pos++] = sample_rate_buffer[i];
	}

	if (aif_data->has_loop)
	{

		// Marker Chunk ckID
		aif->data[pos++] = 'M';
		aif->data[pos++] = 'A';
		aif->data[pos++] = 'R';
		aif->data[pos++] = 'K';

		// Marker Chunk ckSize
		aif->data[pos++] = 0;
		aif->data[pos++] = 0;
		aif->data[pos++] = 0;
		aif->data[pos++] = 12 + (aif_data->has_loop ? 12 : 0);

		// Marker Chunk numMarkers
		aif->data[pos++] = 0;
		aif->data[pos++] = (aif_data->has_loop ? 2 : 1);

		// Marker loop start
		aif->data[pos++] = 0;
		aif->data[pos++] = 1;  // id = 1

		long loop_start = aif_data->loop_offset;
		aif->data[pos++] = ((loop_start >> 24) & 0xFF);
		aif->data[pos++] = ((loop_start >> 16) & 0xFF);
		aif->data[pos++] = ((loop_start >> 8)  & 0xFF);
		aif->data[pos++] = (loop_start & 0xFF);  // position

		aif->data[pos++] = 5;  // pascal-style string length
		aif->data[pos++] = 'S';
		aif->data[pos++] = 'T';
		aif->data[pos++] = 'A';
		aif->data[pos++] = 'R';
		aif->data[pos++] = 'T';  // markerName

		// Marker loop end
		aif->data[pos++] = 0;
		aif->data[pos++] = (aif_data->has_loop ? 2 : 1);  // id = 2

		long loop_end = aif_data->num_samples;
		aif->data[pos++] = ((loop_end >> 24) & 0xFF);
		aif->data[pos++] = ((loop_end >> 16) & 0xFF);
		aif->data[pos++] = ((loop_end >> 8)  & 0xFF);
		aif->data[pos++] = (loop_end & 0xFF);  // position

		aif->data[pos++] = 3;  // pascal-style string length
		aif->data[pos++] = 'E';
		aif->data[pos++] = 'N';
		aif->data[pos++] = 'D';
	}

	// Instrument Chunk ckID
	aif->data[pos++] = 'I';
	aif->data[pos++] = 'N';
	aif->data[pos++] = 'S';
	aif->data[pos++] = 'T';

	// Instrument Chunk ckSize
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 20;

	aif->data[pos++] = base_note;  // baseNote
	aif->data[pos++] = 0;          // detune
	aif->data[pos++] = 0;          // lowNote
	aif->data[pos++] = 127;        // highNote
	aif->data[pos++] = 1;          // lowVelocity
	aif->data[pos++] = 127;        // highVelocity
	aif->data[pos++] = 0;          // gain (hi)
	aif->data[pos++] = 0;          // gain (lo)

	// Instrument Chunk sustainLoop
	aif->data[pos++] = 0;
	aif->data[pos++] = 1; // playMode = ForwardLooping

	aif->data[pos++] = 0;
	aif->data[pos++] = 1;  // beginLoop marker id

	aif->data[pos++] = 0;
	aif->data[pos++] = 2;  // endLoop marker id

		// Instrument Chunk releaseLoop
	aif->data[pos++] = 0;
	aif->data[pos++] = 1; // playMode = ForwardLooping

	aif->data[pos++] = 0;
	aif->data[pos++] = 1;  // beginLoop marker id

	aif->data[pos++] = 0;
	aif->data[pos++] = 2;  // endLoop marker id

	// Finally, write the Sound Data Chunk
	// Sound Data Chunk ckID
	aif->data[pos++] = 'S';
	aif->data[pos++] = 'S';
	aif->data[pos++] = 'N';
	aif->data[pos++] = 'D';

	// Sound Data Chunk ckSize
	unsigned long sound_data_size = pcm->length + 8;
	aif->data[pos++] = ((sound_data_size >> 24) & 0xFF);
	aif->data[pos++] = ((sound_data_size >> 16) & 0xFF);
	aif->data[pos++] = ((sound_data_size >> 8)  & 0xFF);
	aif->data[pos++] = (sound_data_size & 0xFF);

	// Sound Data Chunk offset
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;

	// Sound Data Chunk blockSize
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;
	aif->data[pos++] = 0;

	// Sound Data Chunk soundData
	for (unsigned int i = 0; i < aif_data->loop_offset; i++)
	{
		aif->data[pos++] = aif_data->samples8[i];
	}

	int j = 0;
	for (unsigned int i = aif_data->loop_offset; i < pcm->length; i++)
	{
		int pcm_index = aif_data->loop_offset + (j++ % (pcm->length - aif_data->loop_offset));
		aif->data[pos++] = aif_data->samples8[pcm_index];
	}

	aif->length = pos;

	// Go back and rewrite ckSize
	data_size = aif->length - 8;
	aif->data[form_size + 0] = ((data_size >> 24) & 0xFF);
	aif->data[form_size + 1] = ((data_size >> 16) & 0xFF);
	aif->data[form_size + 2] = ((data_size >>  8) & 0xFF);
	aif->data[form_size + 3] = (data_size & 0xFF);

	write_bytearray(aif_filename, aif);

	free(aif->data);
	free(aif);
}

void usage(void)
{
	fprintf(stderr, "Usage: aif2pcm bin_file [aif_file]\n");
	fprintf(stderr, "       aif2pcm aif_file [bin_file] [--compress]\n");
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		usage();
		exit(1);
	}

	char *input_file = argv[1];
	char *extension = get_file_extension(input_file);
	char *output_file;
	bool compressed = false;

	if (argc > 3)
	{
		for (int i = 3; i < argc; i++)
		{
			if (strcmp(argv[i], "--compress") == 0)
			{
				compressed = true;
			}
		}
	}

	if (strcmp(extension, "aif") == 0 || strcmp(extension, "aiff") == 0)
	{
		if (argc >= 3)
		{
			output_file = argv[2];
			aif2pcm(input_file, output_file, compressed);
		}
		else
		{
			output_file = new_file_extension(input_file, "bin");
			aif2pcm(input_file, output_file, compressed);
			free(output_file);
		}
	}
	else if (strcmp(extension, "bin") == 0)
	{
		if (argc >= 3)
		{
			output_file = argv[2];
			pcm2aif(input_file, output_file, 60);
		}
		else
		{
			output_file = new_file_extension(input_file, "aif");
			pcm2aif(input_file, output_file, 60);
			free(output_file);
		}
	}
	else
	{
		FATAL_ERROR("Input file must be .aif or .bin: '%s'\n", input_file);
	}

	return 0;
}
