// Copyright (c) 2015 YamaArashi

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"
#include "util.h"
#include "gfx.h"
#include "convert_png.h"
#include "jasc_pal.h"
#include "lz.h"

void ConvertToPng(char *imageFilePath, char *paletteFilePath, bool isObject, int width)
{
	struct Image image;
	int bitDepth = 0;

	char *extension = GetFileExtension(imageFilePath);

	if (extension == NULL)
		FATAL_ERROR("\"%s\" has no file extension.\n", imageFilePath);

	if (strcmp(extension, "1bpp") == 0)
		bitDepth = 1;
	else if (strcmp(extension, "4bpp") == 0)
		bitDepth = 4;
	else if (strcmp(extension, "8bpp") == 0)
		bitDepth = 8;
	else
		FATAL_ERROR("Unexpected file extension \"%s\". Expected \"1bpp\", \"4bpp\", or \"8bpp\".\n", extension);

	if (paletteFilePath != NULL) {
		ReadGbaPalette(paletteFilePath, &image.palette);
		image.hasPalette = true;
	} else {
		image.hasPalette = false;
	}

	ReadImage(imageFilePath, width, bitDepth, &image, !image.hasPalette);

	image.isObject = isObject;

	ChangeFileExtension(imageFilePath, "png");

	WritePng(imageFilePath, &image);

	FreeImage(&image);
}

void ConvertFromPng(char *imageFilePath, int numTiles, int bitDepth)
{
	struct Image image;

	image.bitDepth = bitDepth;

	ExpectFileExtension(imageFilePath, "png");

	ReadPng(imageFilePath, &image);

	char newExtension[5];
	snprintf(newExtension, 5, "%dbpp", bitDepth);
	ChangeFileExtension(imageFilePath, newExtension);

	WriteImage(imageFilePath, numTiles, bitDepth, &image, !image.hasPalette);

	FreeImage(&image);
}

void ConvertToJascPalette(char *paletteFilePath)
{
	struct Palette palette;

	ExpectFileExtension(paletteFilePath, "gbapal");

	ReadGbaPalette(paletteFilePath, &palette);

	ChangeFileExtension(paletteFilePath, "pal");

	WriteJascPalette(paletteFilePath, &palette);
}

void ConvertFromJascPalette(char *paletteFilePath)
{
	struct Palette palette;

	ExpectFileExtension(paletteFilePath, "pal");

	ReadJascPalette(paletteFilePath, &palette);

	ChangeFileExtension(paletteFilePath, "gbapal");

	WriteGbaPalette(paletteFilePath, &palette);
}

void LZCompressFile(char *path)
{
	int fileSize;
	unsigned char *buffer = ReadWholeFile(path, &fileSize);

	int compressedSize;
	unsigned char *compressedData = LZCompress(buffer, fileSize, &compressedSize);

	free(buffer);

	AddFileExtension(path, "lz");

	WriteWholeFile(path, compressedData, compressedSize);

	free(compressedData);
}

void LZDecompressFile(char *path)
{
	ExpectFileExtension(path, "lz");

	int fileSize;
	unsigned char *buffer = ReadWholeFile(path, &fileSize);

	int uncompressedSize;
	unsigned char *uncompressedData = LZDecompress(buffer, fileSize, &uncompressedSize);

	free(buffer);

	RemoveFileExtension(path);

	WriteWholeFile(path, uncompressedData, uncompressedSize);

	free(uncompressedData);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		FATAL_ERROR("No args.\n");

	char *command = argv[1];

	if (strcmp(command, "png") == 0) {
		if (argc < 3)
			FATAL_ERROR("No image file path arg.\n");

		CHECK_PATH_LENGTH(argv[2]);

		char imageFilePath[GBAGFX_MAX_PATH + 1];
		strcpy(imageFilePath, argv[2]);

		char paletteFilePath[GBAGFX_MAX_PATH + 1];
		bool hasPalette = false;
		bool isObject = false;
		int width = 1;

		for (int i = 3; i < argc; i++) {
			char *option = argv[i];

			if (strcmp(option, "-palette") == 0) {
				if (i + 1 >= argc)
					FATAL_ERROR("No palette file path following \"-palette\".\n");

				i++;

				CHECK_PATH_LENGTH(argv[i]);

				strcpy(paletteFilePath, argv[i]);

				hasPalette = true;
			} else if (strcmp(option, "-object") == 0) {
				isObject = true;
			} else if (strcmp(option, "-width") == 0) {
				if (i + 1 >= argc)
					FATAL_ERROR("No width following \"-width\".\n");

				i++;

				if (!ParseNumber(argv[i], NULL, 10, &width))
					FATAL_ERROR("Failed to parse width.\n");

				if (width < 1)
					FATAL_ERROR("Width must be positive.\n");
			} else {
				FATAL_ERROR("Unrecognized option \"%s\".\n", option);
			}
		}

		ConvertToPng(imageFilePath, hasPalette ? paletteFilePath : NULL, isObject, width);
	} else if (strcmp(command, "1bpp") == 0 || strcmp(command, "4bpp") == 0 || strcmp(command, "8bpp") == 0) {
		if (argc < 3)
			FATAL_ERROR("No image file path arg.\n");

		CHECK_PATH_LENGTH(argv[2]);

		char imageFilePath[GBAGFX_MAX_PATH + 1];
		strcpy(imageFilePath, argv[2]);

		int numTiles = 0;
		int bitDepth = command[0] - '0';

		for (int i = 3; i < argc; i++) {
			char *option = argv[i];

			if (strcmp(option, "-num_tiles") == 0) {
				if (i + 1 >= argc)
					FATAL_ERROR("No number of tiles following \"-num_tiles\".\n");

				i++;

				if (!ParseNumber(argv[i], NULL, 10, &numTiles))
					FATAL_ERROR("Failed to parse number of tiles.\n");

				if (numTiles < 1)
					FATAL_ERROR("Number of tiles must be positive.\n");
			} else {
				FATAL_ERROR("Unrecognized option \"%s\".\n", option);
			}
		}

		ConvertFromPng(imageFilePath, numTiles, bitDepth);
	} else if (strcmp(command, "pal") == 0) {
		if (argc < 3)
			FATAL_ERROR("No palette file path arg.\n");

		CHECK_PATH_LENGTH(argv[2]);

		char paletteFilePath[GBAGFX_MAX_PATH + 1];
		strcpy(paletteFilePath, argv[2]);

		ConvertToJascPalette(paletteFilePath);
	} else if (strcmp(command, "gbapal") == 0) {
		if (argc < 3)
			FATAL_ERROR("No palette file path arg.\n");

		CHECK_PATH_LENGTH(argv[2]);

		char paletteFilePath[GBAGFX_MAX_PATH + 1];
		strcpy(paletteFilePath, argv[2]);

		ConvertFromJascPalette(paletteFilePath);
	} else if (strcmp(command, "lz") == 0) {
		if (argc < 3)
			FATAL_ERROR("No file path arg.\n");

		CHECK_PATH_LENGTH(argv[2]);

		char path[GBAGFX_MAX_PATH + 1];
		strcpy(path, argv[2]);

		LZCompressFile(path);
	} else if (strcmp(command, "unlz") == 0) {
		if (argc < 3)
			FATAL_ERROR("No file path arg.\n");

		CHECK_PATH_LENGTH(argv[2]);

		char path[GBAGFX_MAX_PATH + 1];
		strcpy(path, argv[2]);

		LZDecompressFile(path);
	} else {
		FATAL_ERROR("Unrecognized command \"%s\".\n", command);
	}

	return 0;
}
