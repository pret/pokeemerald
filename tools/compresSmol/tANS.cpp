#include "tANS.h"
#include <stdio.h>

std::vector<DecodeCol> createDecodingTable(std::vector<unsigned char> symbols, std::vector<int> frequencies)
{
    std::vector<DecodeCol> table(TANS_TABLE_SIZE);
    size_t currCol = 0;
    for (size_t i = 0; i < 16; i++)
    {
        for (size_t j = 0; j < frequencies[i]; j++)
        {
            //printf("%zu %zu\n", table.size(), currCol);
            table[currCol].state = TANS_TABLE_SIZE + currCol;
            table[currCol].symbol = symbols[i];
            table[currCol].y = frequencies[i] + j;
            int currK = 0;
            while ((table[currCol].y << currK) < TANS_TABLE_SIZE)
                currK++;
            table[currCol].k = currK;
            currCol++;
        }
    }
    return table;
}

std::vector<EncodeCol> createEncodingTable(std::vector<DecodeCol> decodeTable, std::vector<unsigned char> symbols)
{
    std::vector<EncodeCol> encodeTable(decodeTable.size());
    for (int i = 0; i < decodeTable.size(); i++)
    {
        encodeTable[i].state = decodeTable.size() + i;
    }
    std::vector<EncodeHelper> encodeHelpers;

    //  Build the encoding helper tables, one per symbol
    for (unsigned char symbol : symbols)
    {
        EncodeHelper newHelper;
        newHelper.symbol = symbol;
        encodeHelpers.push_back(newHelper);
    }

    for (DecodeCol dCol : decodeTable)
    {
        unsigned char currSymbol = dCol.symbol;
        int symbolIndex = 0;
        while (encodeHelpers[symbolIndex].symbol != currSymbol)
        {
            symbolIndex++;
        }
        encodeHelpers[symbolIndex].states.push_back(dCol.state);
        encodeHelpers[symbolIndex].yVals.push_back(dCol.y);
        encodeHelpers[symbolIndex].kVals.push_back(dCol.k);
        encodeHelpers[symbolIndex].yPrimVals.push_back(dCol.y << dCol.k);
    }
    //  Build the encoding table, one column per state in decoding table
    for (int helperNum = 0; helperNum < encodeHelpers.size(); helperNum++)
    {
        for (int i = 0; i < encodeHelpers[helperNum].states.size(); i++)
        {
            EncodeSymbolData currSymbol;
            currSymbol.symbol = encodeHelpers[helperNum].symbol;
            currSymbol.streamValue = 0;
            currSymbol.numBits = encodeHelpers[helperNum].kVals[i];
            currSymbol.nextState = encodeHelpers[helperNum].states[i];
            int currIndex = encodeHelpers[helperNum].yPrimVals[i]-encodeTable.size();
            encodeTable[currIndex].symbols.push_back(currSymbol);
            int limit = std::pow(2, currSymbol.numBits);
            for (int j = 1; j < limit; j++)
            {
                currSymbol.streamValue++;
                encodeTable[currIndex + j].symbols.push_back(currSymbol);
            }
        }
    }

    return encodeTable;
}

EncodedData encodeData(std::vector<unsigned char> input, std::vector<EncodeCol> encodingTable)
{
    EncodedData data;
    int state;
    //  Reverse the input, since ANS operates in FILO mode
    std::vector<unsigned char> reverseInput(input.size());
    for (int i = 0; i < input.size(); i++)
    {
        reverseInput[input.size() - 1 - i] = input[i];
    }
    //  Encode the string
    int currentOffsetState = 0;
    for (int i = 0; i < reverseInput.size(); i++)
    {
        unsigned char currChar = reverseInput[i];
        //  Find correct encoding instruction for the symbol
        for (EncodeSymbolData eSymbols : encodingTable[currentOffsetState].symbols)
        {
            if (eSymbols.symbol == currChar)
            {
                //  Encode the symbol
                state = eSymbols.nextState;
                if (i == 0)
                    break;
                int streamValue = eSymbols.streamValue;
                int compVal = 1;
                for (int numBit = eSymbols.numBits-1; numBit >= 0; numBit--)
                {
                    unsigned char currBit = (streamValue >> numBit) & compVal;
                    data.bitStream.push_back(currBit);
                }
                break;
            }
        }
        currentOffsetState = state - encodingTable.size();
    }
    data.initialState = state;

    return data;
}

int encodeSingleSymbol(EncodeCol currEncodeCol, unsigned char symbol, std::vector<unsigned int> *bitstream)
{
    int newState;
    for (EncodeSymbolData eSymbols : currEncodeCol.symbols)
    {
        if (eSymbols.symbol == symbol)
        {
            newState = eSymbols.nextState;
            int streamValue = eSymbols.streamValue;
            int compVal = 1;
            for (int numBit = eSymbols.numBits-1; numBit >= 0; numBit--)
            {
                unsigned char currBit = (streamValue >> numBit) & compVal;
                bitstream->push_back(currBit);
            }
            break;
        }
    }
    return newState;
}

std::vector<unsigned char> decodeData(EncodedData *data, std::vector<DecodeCol> decodeTable, int numChars)
{
    unsigned int tableSize = decodeTable.size();
    unsigned int state = data->initialState;
    std::vector<unsigned char> returnVec(numChars);
    returnVec[0] = decodeTable[state-tableSize].symbol;
    for (int i = 1; i < numChars; i++)
    {
        unsigned int currY = decodeTable[state-tableSize].y;
        unsigned int currK = decodeTable[state-tableSize].k;
        unsigned int streamValue = 0;
        //  Horrible way of reading a value from the bitstream
        for (int j = 0; j < currK; j++)
        {
            unsigned int tempVal;
            bool val = data->bitStream.back();
            data->bitStream.pop_back();
            if (val)
                tempVal = 1;
            else
                tempVal = 0;
            streamValue += (tempVal << j);
        }
        //  Calculate the next state and retrieve the symbol for that state
        state = (currY << currK) + streamValue;
        returnVec[i] = decodeTable[state-tableSize].symbol;
    }
    data->initialState = state;
    return returnVec;
}

std::vector<int> normalizeCounts(std::vector<int> counts, int tableSize)
{
    return normalizeCounts(counts, tableSize, false);
}
std::vector<int> normalizeCounts(std::vector<int> counts, int tableSize, bool fillZeros)
{
    int totalCount = 0;
    for (int count : counts)
    {
        totalCount += count;
    }
    if (totalCount < tableSize)
    {
        for (int i = 0; i < counts.size(); i++)
        {
            counts[i] *= (int)ceil((float)tableSize/(float)totalCount);
        }
    }
    if (fillZeros)
        for (int i = 0; i < counts.size(); i++)
            if (counts[i] == 0)
                counts[i] = 1;

    totalCount = 0;
    for (int count : counts)
    {
        totalCount += count;
    }

    bool shouldContinue = true;
    std::vector<int> normCounts(counts.size());
    while (shouldContinue)
    {
        int smallestCount;
        int smallestIndex;
        int firstIndex;
        int largestCount = 0;
        for (int i = 0; i < counts.size(); i++)
        {
            if (counts[i] != 0)
            {
                firstIndex = i;
                smallestIndex = i;
                smallestCount = counts[i];
                break;
            }
        }
        for (int i = firstIndex; i < counts.size(); i++)
        {
            if (counts[i] < smallestCount && counts[i] != 0)
            {
                smallestCount = counts[i];
                smallestIndex = i;
            }
            if (counts[i] > largestCount)
            {
                largestCount = counts[i];
            }
        }
        if (largestCount == 0)
        {
            shouldContinue = false;
        }
        else
        {
            float frac = float(smallestCount)/float(totalCount);
            int newCount = std::round(frac*float(tableSize));
            if (newCount == 0 and counts[smallestIndex] != 0)
            {
                newCount = 1;
            }
            normCounts[smallestIndex] = newCount;
            tableSize -= newCount;
            totalCount -= smallestCount;
            counts[smallestIndex] = 0;
        }
    }
    return normCounts;
}

void printEncodeTable(std::vector<EncodeCol> encodeTable, std::vector<unsigned char> symbols)
{
    printf("    x: ");
    for (int i = 0; i < encodeTable.size(); i++)
    {
        printf("%3zu ", i+encodeTable.size());
    }
    printf("\n");
    for (int i = 0; i < symbols.size(); i++)
    {
        printf("%3hhu s: ", symbols[i]);
        for (int k = 0; k < encodeTable.size(); k++)
        {
            printf("%3i ", encodeTable[k].symbols[i].nextState);
        }
        printf("\n");
        printf("%3hhu b: ", symbols[i]);
        for (int k = 0; k < encodeTable.size(); k++)
        {
            printf("%3i ", encodeTable[k].symbols[i].streamValue);
        }
        printf("\n");
        printf("%3hhu k: ", symbols[i]);
        for (int k = 0; k < encodeTable.size(); k++)
        {
            printf("%3i ", encodeTable[k].symbols[i].numBits);
        }
        printf("\n");
    }
}

void printDecodeTable(std::vector<DecodeCol> decodeTable)
{
    printf("State: ");
    for (DecodeCol currCol : decodeTable)
        printf("%3i ", currCol.state);
    printf("\n");
    printf("  Sym: ");
    for (DecodeCol currCol : decodeTable)
        printf("%3hhu ", currCol.symbol);
    printf("\n");
    printf("    Y: ");
    for (DecodeCol currCol : decodeTable)
        printf("%3i ", currCol.y);
    printf("\n");
    printf("    K: ");
    for (DecodeCol currCol : decodeTable)
        printf("%3i ", currCol.k);
    printf("\n");
}

int getFileSize(std::string filePath)
{
    std::ifstream iStream;
    iStream.open(filePath.c_str(), std::ios::binary);
    if (!iStream.is_open())
    {
        fprintf(stderr, "Error: Couldn't open %s for reading file size\n", filePath.c_str());
        return 0;
    }
    iStream.ignore( std::numeric_limits<std::streamsize>::max() );
    std::streamsize size = iStream.gcount();
    int returnSize = size;
    iStream.clear();
    iStream.seekg( 0, std::ios_base::beg );
    iStream.close();
    return returnSize;
}
