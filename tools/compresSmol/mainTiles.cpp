#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <filesystem>
#include "compressSmolTiles.h"

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        std::string inputName = argv[1];
        std::string outputName = argv[2];
        CompressionResult compression = compressTileset(inputName);
        if (compression.failed)
            return 1;
        std::ofstream fileOut(outputName, std::ios::out | std::ios::binary);
        fileOut.write(reinterpret_cast<const char *>(compression.writeVec.data()), compression.writeVec.size()*4);
        fileOut.close();
        return 0;
    }
    /*
    else if (argc == 2)
    {
        std::filesystem::path filePath = argv[1];
        std::string fileName;
        std::vector<std::string> fileList;
        for (const std::filesystem::directory_entry &dirEntry : std::filesystem::recursive_directory_iterator(filePath))
        {
            if (dirEntry.is_regular_file())
            {
                fileName = dirEntry.path().string();
                if (fileName.find(".bin.lz") == std::string::npos)
                    continue;
            }
            else
            {
                continue;
            }
            fileList.push_back(fileName);
        }
        size_t totalSize = 0;
        size_t lzSize = 0;
        size_t rawSize = 0;
        for (std::string fullName : fileList)
        {
            std::string baseName = fullName;
            baseName.pop_back();
            baseName.pop_back();
            baseName.pop_back();
            CompressionResult compressedTilemap = compressTileset(baseName);
            size_t currSize = 0;
            currSize += compressedTilemap.writeVec.size() * 4;
            if (currSize !=0)
            {
                totalSize += currSize;
                lzSize += getFileSize(fullName);
                rawSize += getFileSize(baseName);
            }
            else
            {
                printf("%s\n", baseName.c_str());
            }
        }
        printf("Raw size: %zu\n", rawSize);
        printf("LZ  size: %zu\n", lzSize);
        printf("New size: %zu\n", totalSize);
        return 0;
    }
    */
    else
    {
        return 0;
    }
}
