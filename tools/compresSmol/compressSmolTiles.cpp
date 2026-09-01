#include "compressSmolTiles.h"
#include <vector>

std::vector<unsigned short> readFileAsUS(std::string filePath)
{
    std::ifstream iStream;
    iStream.open(filePath.c_str(), std::ios::binary);
    if (!iStream.is_open())
    {
        fprintf(stderr, "Error: Couldn't open %s for reading bytes\n", filePath.c_str());
        return std::vector<unsigned short>(0);
    }
    iStream.ignore( std::numeric_limits<std::streamsize>::max() );
    std::streamsize size = iStream.gcount();
    iStream.clear();
    iStream.seekg( 0, std::ios_base::beg );
    std::vector<unsigned char> ucVec(size);
    iStream.read((char*)(&ucVec[0]), size);
    iStream.close();
    unsigned short *pUInt = reinterpret_cast<unsigned short *>(ucVec.data());
    std::vector<unsigned short> returnVec;
    for (size_t i = 0; i < ucVec.size()/2; i++)
        returnVec.push_back(pUInt[i]);
    return returnVec;
}

void deltaEncodeTileNums(std::vector<unsigned short> *pTileNums)
{
    unsigned short prevVal = 0;
    for (size_t i = 0; i < pTileNums->size(); i++)
    {
        unsigned short current = (*pTileNums)[i];
        (*pTileNums)[i] = (current - prevVal);
        prevVal = current;
    }
}

CompressionResult compressTileset(std::string fileName)
{
    CompressionResult result;
    result.tilemapSize = 0;
    std::vector<unsigned short> tiles = readFileAsUS(fileName);
    std::vector<unsigned short> origTiles = tiles;
    if (tiles.size() == 0)
        return result;
    result.tilemapSize = tiles.size()*2;
    deltaEncodeTileNums(&tiles);
    result.vecs = compressVector(&tiles);
    result.header = getHeader(result);
    result.writeVec = getWriteVecs(result);
    if (!verifyTileCompression(result.writeVec, origTiles))
    {
        fprintf(stderr, "Tilemap verification failed for %s\n", fileName.c_str());
        result.failed = true;
    }
    return result;
}

void deltaDecodeTileNums(std::vector<unsigned short> *pTileNums)
{
    unsigned short prevVal = 0;
    for (size_t i = 0; i < pTileNums->size(); i++)
    {
        unsigned short delta = (*pTileNums)[i];
        (*pTileNums)[i] = (delta + prevVal);
        prevVal = (*pTileNums)[i];
    }
}

std::vector<unsigned short> decompressVector(std::vector<unsigned short> *pVec)
{
    std::vector<unsigned short> returnVec;
    for (size_t i = 0; i < pVec->size(); i+=3)
    {
        unsigned short length = (*pVec)[i];
        unsigned short offset = (*pVec)[i + 1];
        if (length != 0)
        {
            returnVec.push_back((*pVec)[i + 2]);
            for (size_t j = 0; j < length; j++)
                returnVec.push_back(returnVec[returnVec.size() - offset]);
        }
        else
        {
            returnVec.push_back((*pVec)[i + 2]);
        }
    }
    return returnVec;
}

CompressVectors compressVector(std::vector<unsigned short> *pVec)
{
    CompressVectors vecs;
    std::vector<ShortCopy> shortCopies;
    getShortCopies(pVec, 2, &shortCopies);
    if (!verifyShortCopies(&shortCopies, pVec))
    {
        fprintf(stderr, "Error getting tile-number compression\n");
        return vecs;
    }
    std::vector<ShortCompressionInstruction> shortInstructions;
    getShortInstructions(&shortCopies, &shortInstructions, pVec);
    std::vector<unsigned char> loVec;
    getLosFromInstructions(&shortInstructions, &loVec);
    std::vector<unsigned short> symVec;
    getSymsFromInstructions(&shortInstructions, &symVec);

    if (!verifyBytesShort(&loVec, &symVec, pVec))
    {
        fprintf(stderr, "Error verifying tile-number compression\n");
        return vecs;
    }
    vecs.loVec = loVec;
    vecs.symVec = symVec;

    return vecs;
}

size_t getTotalSize(std::vector<CompressVectors> *input)
{
    size_t totalSize = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if ((*input)[i].loVec.size() == 0)
            return 0;
        if ((*input)[i].symVec.size() == 0)
            return 0;
        totalSize += (*input)[i].loVec.size();
        totalSize += (*input)[i].symVec.size();
    }
    return totalSize;
}

TileHeader getHeader(CompressionResult compression)
{
    TileHeader header;
    header.mode = IS_TILEMAP;
    header.tilemapSize = compression.tilemapSize;
    header.symbolSize = compression.vecs.symVec.size();
    header.loSize = compression.vecs.loVec.size();
    header.header[0] = header.mode;
    header.header[0] |= header.tilemapSize << 4;
    header.header[0] |= header.symbolSize << 18;
    header.header[1] = header.loSize;
    return header;
}

std::vector<unsigned int> getWriteVecs(CompressionResult compression)
{
    std::vector<unsigned int> returnVec;
    returnVec.push_back(compression.header.header[0]);
    returnVec.push_back(compression.header.header[1]);
    unsigned int tempInt = 0;
    bool containsData = false;
    for (size_t i = 0; i < compression.header.symbolSize; i++)
    {
        unsigned int currData = compression.vecs.symVec[i];
        if (containsData)
            currData = currData << 16;
        tempInt += currData;
        containsData = true;
        if ((i+1) % 2 == 0)
        {
            returnVec.push_back(tempInt);
            tempInt = 0;
            containsData = false;
        }
    }
    if (containsData)
        returnVec.push_back(tempInt);
    containsData = false;
    tempInt = 0;
    size_t totalLOs = compression.header.loSize;
    for (size_t i = 0; i < totalLOs; i++)
    {
        unsigned int currData = compression.vecs.loVec[i] << (8*(i % 4));
        tempInt += currData;
        containsData = true;
        if ((i+1) % 4 == 0)
        {
            returnVec.push_back(tempInt);
            tempInt = 0;
            containsData = false;
        }
    }
    if (containsData)
    {
        returnVec.push_back(tempInt);
    }
    return returnVec;
}

TileHeader readTileHeader(unsigned int *data)
{
    TileHeader header;
    header.mode = (CompressionMode)(data[0] & 0xf);
    header.tilemapSize = (data[0] >> 4) & 0x3fff;
    header.symbolSize = (data[0] >> 18) & 0x3fff;
    header.loSize = data[1];
    return header;
}

bool verifyTileCompression(std::vector<unsigned int> compression, std::vector<unsigned short> input)
{
    TileHeader header = readTileHeader(compression.data());
    std::vector<unsigned short> tileNumbers;
    std::vector<unsigned short> symVec;
    std::vector<unsigned char> loVec;
    for (size_t i = 2; i < compression.size(); i++)
    {
        symVec.push_back(compression[i] & 0xffff);
        symVec.push_back(compression[i] >> 16);
        loVec.push_back(compression[i] & 0xff);
        loVec.push_back((compression[i] >> 8) & 0xff);
        loVec.push_back((compression[i] >> 16) & 0xff);
        loVec.push_back((compression[i] >> 24) & 0xff);
    }
    size_t loCount = 0;
    size_t symIndex = 0;
    size_t loStartIndex = header.symbolSize*2 + (header.symbolSize % 2) * 2;
    while (loCount < header.loSize)
    {
        size_t currLength = loVec[loStartIndex + loCount];
        loCount++;
        if (currLength & LO_CONTINUE_BIT)
        {
            currLength -= LO_CONTINUE_BIT;
            currLength += loVec[loStartIndex + loCount] << 7;
            loCount++;
        }
        size_t currOffset = loVec[loStartIndex + loCount];
        loCount++;
        if (currOffset & LO_CONTINUE_BIT)
        {
            currOffset -= LO_CONTINUE_BIT;
            currOffset += loVec[loStartIndex + loCount] << 7;
            loCount++;
        }
        if (currLength != 0)
        {
            tileNumbers.push_back(symVec[symIndex]);
            symIndex++;
            for (size_t i = 0; i < currLength; i++)
            {
                tileNumbers.push_back(tileNumbers[tileNumbers.size() - currOffset]);
            }
        }
        else
        {
            for (size_t i = 0; i < currOffset; i++)
            {
                tileNumbers.push_back(symVec[symIndex]);
                symIndex++;
            }
        }
    }

    deltaDecodeTileNums(&tileNumbers);
    if (tileNumbers.size() != input.size())
        return false;
    std::vector<unsigned short> fullVec;
    for (size_t i = 0; i < tileNumbers.size(); i++)
        fullVec.push_back(tileNumbers[i]);
    for (size_t i = 0; i < fullVec.size(); i++)
        if (fullVec[i] != input[i])
            return false;
    return true;
}
