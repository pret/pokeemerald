#include "gba/gba.h"
#include "gba/flash_internal.h"
#include "constants/vars.h"
#include "global.h"
#include "main.h"
#include "flash.h"
#include "rtc.h"

struct SaveBlockChunk
{
    u8 * data;
    u16 size;
};

u8 WriteSaveBlockChunks(u16 a0, const struct SaveBlockChunk * a1);
u8 WriteSingleChunk(u16 a0, const struct SaveBlockChunk * a1);
u8 TryWriteSector(u8, u8 *);
u8 EraseCurrentChunk(u16 a0, const struct SaveBlockChunk * a1);
u8 TryReadAllSaveSectorsCurrentSlot(u16 a0, const struct SaveBlockChunk * a1);
u8 ReadAllSaveSectorsCurrentSlot(u16 a0, const struct SaveBlockChunk * a1);
u8 GetSaveValidStatus(const struct SaveBlockChunk * a1);
u32 DoReadFlashWholeSection(u8 a0, struct SaveSector * a1);
u16 CalculateChecksum(const void *, u16);

u16 gFirstSaveSector;
u32 gPrevSaveCounter;
u16 gLastKnownGoodSector;
u32 gDamagedSaveSectors;
u32 gSaveCounter;
struct SaveSector * gFastSaveSection;
u16 gCurSaveChunk;
bool32 gFlashIdentIsValid;

EWRAM_DATA struct SaveBlock2 gSaveBlock2 = {};
EWRAM_DATA struct SaveBlock1 gSaveBlock1 = {};
EWRAM_DATA struct PokemonStorage gPokemonStorage = {};

// Each 4 KiB flash sector contains 3968 bytes of actual data followed by a 128 byte footer
#define SECTOR_DATA_SIZE 3968
#define SECTOR_FOOTER_SIZE 128

#define SAVEBLOCK_CHUNK(structure, chunkNum)                                \
{                                                                           \
    (u8 *)&structure + chunkNum * SECTOR_DATA_SIZE,                         \
    min(sizeof(structure) - chunkNum * SECTOR_DATA_SIZE, SECTOR_DATA_SIZE)  \
}                                                                           \

static const struct SaveBlockChunk sSaveBlockChunks[] =
{
    SAVEBLOCK_CHUNK(gSaveBlock2, 0),

    SAVEBLOCK_CHUNK(gSaveBlock1, 0),
    SAVEBLOCK_CHUNK(gSaveBlock1, 1),
    SAVEBLOCK_CHUNK(gSaveBlock1, 2),
    SAVEBLOCK_CHUNK(gSaveBlock1, 3),

    SAVEBLOCK_CHUNK(gPokemonStorage, 0),
    SAVEBLOCK_CHUNK(gPokemonStorage, 1),
    SAVEBLOCK_CHUNK(gPokemonStorage, 2),
    SAVEBLOCK_CHUNK(gPokemonStorage, 3),
    SAVEBLOCK_CHUNK(gPokemonStorage, 4),
    SAVEBLOCK_CHUNK(gPokemonStorage, 5),
    SAVEBLOCK_CHUNK(gPokemonStorage, 6),
    SAVEBLOCK_CHUNK(gPokemonStorage, 7),
    SAVEBLOCK_CHUNK(gPokemonStorage, 8),
};

const u16 gInfoMessagesPal[] = INCBIN_U16("graphics/msg_box.gbapal");
const u8 gInfoMessagesTilemap[] = INCBIN_U8("graphics/msg_box.tilemap.lz");
const u8 gInfoMessagesGfx[] = INCBIN_U8("graphics/msg_box.4bpp.lz");

bool32 flash_maincb_ident_is_valid(void)
{
    gFlashIdentIsValid = TRUE;
    if (!IdentifyFlash())
    {
        SetFlashTimerIntr(0, &((IntrFunc *)gIntrFuncPointers)[9]);
        return TRUE;
    }
    gFlashIdentIsValid = FALSE;
    return FALSE;
}

void Call_ReadFlash(u16 sectorNum, ptrdiff_t offset, void * dest, size_t size)
{
    ReadFlash(sectorNum, offset, dest, size);
}

u8 Call_WriteSaveBlockChunks(u16 a0, const struct SaveBlockChunk * a1)
{
    return WriteSaveBlockChunks(a0, a1);
}

u8 Call_TryReadAllSaveSectorsCurrentSlot(u16 a0, const struct SaveBlockChunk * a1)
{
    return TryReadAllSaveSectorsCurrentSlot(a0, a1);
}

u32 * GetDamagedSaveSectorsPtr(void)
{
    return &gDamagedSaveSectors;
}

s32 flash_write_save_block_chunks(u8 a0)
{
    u8 i;

    switch (a0)
    {
        case 0:
        default:
            Call_WriteSaveBlockChunks(0xFFFF, sSaveBlockChunks);
            break;
        case 1:
            for (i = 0; i < 5; i++)
            {
                Call_WriteSaveBlockChunks(i, sSaveBlockChunks);
            }
            break;
        case 2:
            Call_WriteSaveBlockChunks(0, sSaveBlockChunks);
            break;
    }

    return 0;
}

u8 flash_write_save_block_chunks_check_damage(u8 a0)
{
    flash_write_save_block_chunks(a0);
    if (*GetDamagedSaveSectorsPtr() == 0)
        return 1;
    return 0xFF;
}

u8 flash_maincb_read_save(u32 unused)
{
    return Call_TryReadAllSaveSectorsCurrentSlot(0xFFFF, sSaveBlockChunks);
}

void msg_load_gfx(void)
{
    REG_DISPCNT = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BLDCNT = 0;
    LZ77UnCompVram(gInfoMessagesGfx, (void *)BG_VRAM);
    LZ77UnCompVram(gInfoMessagesTilemap, (void *)BG_SCREEN_ADDR(28));
    CpuCopy16(gInfoMessagesPal, (void *)BG_PLTT, 0x200);
    REG_BG0CNT = BGCNT_SCREENBASE(28) | BGCNT_TXT512x512;
    REG_DISPCNT = DISPCNT_BG0_ON;
}

void msg_display(enum MsgBoxUpdateMessage a0)
{
    switch (a0)
    {
        case MSGBOX_WILL_NOW_UPDATE:
            REG_BG0HOFS = 0;
            REG_BG0VOFS = 0;
            break;
        case MSGBOX_HAS_BEEN_UPDATED:
            REG_BG0HOFS = 0x100;
            REG_BG0VOFS = 0;
            break;
        case MSGBOX_UNABLE_TO_UPDATE:
            REG_BG0HOFS = 0x100;
            REG_BG0VOFS = 0xB0;
            break;
        case MSGBOX_NO_NEED_TO_UPDATE:
            REG_BG0HOFS = 0;
            REG_BG0VOFS = 0xB0;
            break;
        case MSGBOX_UPDATING:
            REG_BG0HOFS = 0;
            REG_BG0VOFS = 0x160;
            break;
    }
}

void Save_EraseAllData(void)
{
    u16 i;
    for (i = 0; i < 32; i++)
        EraseFlashSector(i);
}

void Save_ResetSaveCounters(void)
{
    gSaveCounter = 0;
    gFirstSaveSector = 0;
    gDamagedSaveSectors = 0;
}

bool32 SetSectorDamagedStatus(u8 op, u8 sectorNum)
{
    bool32 retVal = FALSE;

    switch (op)
    {
        case SECTOR_DAMAGED:
            gDamagedSaveSectors |= (1 << sectorNum);
            break;
        case SECTOR_OK:
            gDamagedSaveSectors &= ~(1 << sectorNum);
            break;
        case SECTOR_CHECK: // unused
            if (gDamagedSaveSectors & (1 << sectorNum))
                retVal = TRUE;
            break;
    }

    return retVal;
}

u8 WriteSaveBlockChunks(u16 chunkId, const struct SaveBlockChunk *chunks)
{
    u32 retVal;
    u16 i;

    gFastSaveSection = eSaveSection;

    if (chunkId != 0xFFFF)  // write single chunk
    {
        retVal = WriteSingleChunk(chunkId, chunks);
    }
    else  // write all chunks
    {
        gLastKnownGoodSector = gFirstSaveSector;
        gPrevSaveCounter = gSaveCounter;
        gFirstSaveSector++;
        gFirstSaveSector %= NUM_SECTORS_PER_SAVE_SLOT;
        gSaveCounter++;
        retVal = SAVE_STATUS_OK;

        for (i = 0; i < NUM_SECTORS_PER_SAVE_SLOT; i++)
            WriteSingleChunk(i, chunks);

        // Check for any bad sectors
        if (gDamagedSaveSectors != 0) // skip the damaged sector.
        {
            retVal = SAVE_STATUS_ERROR;
            gFirstSaveSector = gLastKnownGoodSector;
            gSaveCounter = gPrevSaveCounter;
        }
    }

    return retVal;
}

u8 WriteSingleChunk(u16 chunkId, const struct SaveBlockChunk * chunks)
{
    u16 i;
    u16 sectorNum;
    u8 *chunkData;
    u16 chunkSize;

    // select sector number
    sectorNum = chunkId + gFirstSaveSector;
    sectorNum %= NUM_SECTORS_PER_SAVE_SLOT;
    // select save slot
    sectorNum += NUM_SECTORS_PER_SAVE_SLOT * (gSaveCounter % 2);

    chunkData = chunks[chunkId].data;
    chunkSize = chunks[chunkId].size;

    // clear save section.
    for (i = 0; i < sizeof(struct SaveSector); i++)
        ((u8 *)gFastSaveSection)[i] = 0;

    gFastSaveSection->id = chunkId;
    gFastSaveSection->signature = FILE_SIGNATURE;
    gFastSaveSection->counter = gSaveCounter;
    for (i = 0; i < chunkSize; i++)
        gFastSaveSection->data[i] = chunkData[i];
    gFastSaveSection->checksum = CalculateChecksum(chunkData, chunkSize);

    return TryWriteSector(sectorNum, gFastSaveSection->data);
}

u8 HandleWriteSectorNBytes(u8 sectorNum, u8 *data, u16 size)
{
    u16 i;
    struct SaveSector *section = eSaveSection;

    for (i = 0; i < sizeof(struct SaveSector); i++)
        ((char *)section)[i] = 0;

    section->signature = FILE_SIGNATURE;
    for (i = 0; i < size; i++)
        section->data[i] = data[i];
    section->id = CalculateChecksum(data, size); // though this appears to be incorrect, it might be some sector checksum instead of a whole save checksum and only appears to be relevent to HOF data, if used.

    return TryWriteSector(sectorNum, section->data);
}

u8 TryWriteSector(u8 sectorNum, u8 *data)
{
    if (ProgramFlashSectorAndVerify(sectorNum, data) != 0) // is damaged?
    {
        SetSectorDamagedStatus(SECTOR_DAMAGED, sectorNum); // set damaged sector bits.
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetSectorDamagedStatus(SECTOR_OK, sectorNum); // unset damaged sector bits. it's safe now.
        return SAVE_STATUS_OK;
    }
}

u32 RestoreSaveBackupVarsAndIncrement(const struct SaveBlockChunk *chunk) // chunk is unused
{
    gFastSaveSection = eSaveSection;
    gLastKnownGoodSector = gFirstSaveSector;
    gPrevSaveCounter = gSaveCounter;
    gFirstSaveSector++;
    gFirstSaveSector %= NUM_SECTORS_PER_SAVE_SLOT;
    gSaveCounter++;
    gCurSaveChunk = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

u32 RestoreSaveBackupVars(const struct SaveBlockChunk *chunk)
{
    gFastSaveSection = eSaveSection;
    gLastKnownGoodSector = gFirstSaveSector;
    gPrevSaveCounter = gSaveCounter;
    gCurSaveChunk = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

u8 WriteSingleChunkAndIncrement(u16 a1, const struct SaveBlockChunk * chunk)
{
    u8 retVal;

    if (gCurSaveChunk < a1 - 1)
    {
        retVal = SAVE_STATUS_OK;
        WriteSingleChunk(gCurSaveChunk, chunk);
        gCurSaveChunk++;
        if (gDamagedSaveSectors)
        {
            retVal = SAVE_STATUS_ERROR;
            gFirstSaveSector = gLastKnownGoodSector;
            gSaveCounter = gPrevSaveCounter;
        }
    }
    else
    {
        retVal = SAVE_STATUS_ERROR;
    }

    return retVal;
}

u8 ErasePreviousChunk(u16 a1, const struct SaveBlockChunk *chunk)
{
    u8 retVal = SAVE_STATUS_OK;

    EraseCurrentChunk(a1 - 1, chunk);

    if (gDamagedSaveSectors)
    {
        retVal = SAVE_STATUS_ERROR;
        gFirstSaveSector = gLastKnownGoodSector;
        gSaveCounter = gPrevSaveCounter;
    }
    return retVal;
}

u8 EraseCurrentChunk(u16 chunkId, const struct SaveBlockChunk *chunks)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;
    u8 status;

    // select sector number
    sector = chunkId + gFirstSaveSector;
    sector %= NUM_SECTORS_PER_SAVE_SLOT;
    // select save slot
    sector += NUM_SECTORS_PER_SAVE_SLOT * (gSaveCounter % 2);

    data = chunks[chunkId].data;
    size = chunks[chunkId].size;

    // clear temp save section.
    for (i = 0; i < sizeof(struct SaveSector); i++)
        ((char *)gFastSaveSection)[i] = 0;

    gFastSaveSection->id = chunkId;
    gFastSaveSection->signature = FILE_SIGNATURE;
    gFastSaveSection->counter = gSaveCounter;

    // set temp section's data.
    for (i = 0; i < size; i++)
        gFastSaveSection->data[i] = data[i];

    // calculate checksum.
    gFastSaveSection->checksum = CalculateChecksum(data, size);

    EraseFlashSector(sector);

    status = SAVE_STATUS_OK;

    for (i = 0; i < sizeof(struct UnkSaveSection); i++)
    {
        if (ProgramFlashByte(sector, i, gFastSaveSection->data[i]))
        {
            status = SAVE_STATUS_ERROR;
            break;
        }
    }

    if (status == SAVE_STATUS_ERROR)
    {
        SetSectorDamagedStatus(SECTOR_DAMAGED, sector);
        return SAVE_STATUS_ERROR;
    }
    else
    {
        status = SAVE_STATUS_OK;

        for (i = 0; i < 7; i++)
        {
            if (ProgramFlashByte(sector, 0xFF9 + i, ((u8 *)gFastSaveSection)[0xFF9 + i]))
            {
                status = SAVE_STATUS_ERROR;
                break;
            }
        }

        if (status == SAVE_STATUS_ERROR)
        {
            SetSectorDamagedStatus(SECTOR_DAMAGED, sector);
            return SAVE_STATUS_ERROR;
        }
        else
        {
            SetSectorDamagedStatus(SECTOR_OK, sector);
            return SAVE_STATUS_OK;
        }
    }
}

u8 WriteSomeFlashByteToPrevSector(u16 a1, const struct SaveBlockChunk *chunk)
{
    u16 sector;

    // select sector number
    sector = a1 + gFirstSaveSector - 1;
    sector %= NUM_SECTORS_PER_SAVE_SLOT;
    // select save slot
    sector += NUM_SECTORS_PER_SAVE_SLOT * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), ((u8 *)gFastSaveSection)[sizeof(struct UnkSaveSection)]))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetSectorDamagedStatus(SECTOR_DAMAGED, sector);
        gFirstSaveSector = gLastKnownGoodSector;
        gSaveCounter = gPrevSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetSectorDamagedStatus(SECTOR_OK, sector);
        return SAVE_STATUS_OK;
    }
}

u8 WriteSomeFlashByte0x25ToPrevSector(u16 a1, const struct SaveBlockChunk *chunk)
{
    u16 sector;

    sector = a1 + gFirstSaveSector - 1;
    sector %= NUM_SECTORS_PER_SAVE_SLOT;
    sector += NUM_SECTORS_PER_SAVE_SLOT * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), 0x25))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetSectorDamagedStatus(SECTOR_DAMAGED, sector);
        gFirstSaveSector = gLastKnownGoodSector;
        gSaveCounter = gPrevSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetSectorDamagedStatus(SECTOR_OK, sector);
        return SAVE_STATUS_OK;
    }
}

u8 TryReadAllSaveSectorsCurrentSlot(u16 a1, const struct SaveBlockChunk *chunk)
{
    u8 retVal;
    gFastSaveSection = eSaveSection;
    if (a1 != 0xFFFF)
    {
        retVal = SAVE_STATUS_ERROR;
    }
    else
    {
        retVal = GetSaveValidStatus(chunk);
        ReadAllSaveSectorsCurrentSlot(0xFFFF, chunk);
    }

    return retVal;
}

u8 ReadAllSaveSectorsCurrentSlot(u16 a1, const struct SaveBlockChunk *chunks)
{
    u16 i;
    u16 checksum;
    u16 sector = NUM_SECTORS_PER_SAVE_SLOT * (gSaveCounter % 2);
    u16 id;

    for (i = 0; i < NUM_SECTORS_PER_SAVE_SLOT; i++)
    {
        DoReadFlashWholeSection(i + sector, gFastSaveSection);
        id = gFastSaveSection->id;
        if (id == 0)
            gFirstSaveSector = i;
        checksum = CalculateChecksum(gFastSaveSection->data, chunks[id].size);
        if (gFastSaveSection->signature == FILE_SIGNATURE
            && gFastSaveSection->checksum == checksum)
        {
            u16 j;
            for (j = 0; j < chunks[id].size; j++)
                chunks[id].data[j] = gFastSaveSection->data[j];
        }
    }

    return 1;
}

u8 GetSaveValidStatus(const struct SaveBlockChunk *chunks)
{
    u16 sector;
    bool8 signatureValid;
    u16 checksum;
    u32 slot1saveCounter = 0;
    u32 slot2saveCounter = 0;
    u8 slot1Status;
    u8 slot2Status;
    u32 validSectors;
    const u32 ALL_SECTORS = (1 << NUM_SECTORS_PER_SAVE_SLOT) - 1;  // bitmask of all saveblock sectors

    // check save slot 1.
    validSectors = 0;
    signatureValid = FALSE;
    for (sector = 0; sector < NUM_SECTORS_PER_SAVE_SLOT; sector++)
    {
        DoReadFlashWholeSection(sector, gFastSaveSection);
        if (gFastSaveSection->signature == FILE_SIGNATURE)
        {
            signatureValid = TRUE;
            checksum = CalculateChecksum(gFastSaveSection->data, chunks[gFastSaveSection->id].size);
            if (gFastSaveSection->checksum == checksum)
            {
                slot1saveCounter = gFastSaveSection->counter;
                validSectors |= 1 << gFastSaveSection->id;
            }
        }
    }

    if (signatureValid)
    {
        if (validSectors == ALL_SECTORS)
            slot1Status = SAVE_STATUS_OK;
        else
            slot1Status = SAVE_STATUS_ERROR;
    }
    else
    {
        slot1Status = SAVE_STATUS_EMPTY;
    }

    // check save slot 2.
    validSectors = 0;
    signatureValid = FALSE;
    for (sector = 0; sector < NUM_SECTORS_PER_SAVE_SLOT; sector++)
    {
        DoReadFlashWholeSection(NUM_SECTORS_PER_SAVE_SLOT + sector, gFastSaveSection);
        if (gFastSaveSection->signature == FILE_SIGNATURE)
        {
            signatureValid = TRUE;
            checksum = CalculateChecksum(gFastSaveSection->data, chunks[gFastSaveSection->id].size);
            if (gFastSaveSection->checksum == checksum)
            {
                slot2saveCounter = gFastSaveSection->counter;
                validSectors |= 1 << gFastSaveSection->id;
            }
        }
    }

    if (signatureValid)
    {
        if (validSectors == ALL_SECTORS)
            slot2Status = SAVE_STATUS_OK;
        else
            slot2Status = SAVE_STATUS_ERROR;
    }
    else
    {
        slot2Status = SAVE_STATUS_EMPTY;
    }

    if (slot1Status == SAVE_STATUS_OK && slot2Status == SAVE_STATUS_OK)
    {
        // Choose counter of the most recent save file
        if ((slot1saveCounter == -1 && slot2saveCounter == 0) || (slot1saveCounter == 0 && slot2saveCounter == -1))
        {
            if ((unsigned)(slot1saveCounter + 1) < (unsigned)(slot2saveCounter + 1))
                gSaveCounter = slot2saveCounter;
            else
                gSaveCounter = slot1saveCounter;
        }
        else
        {
            if (slot1saveCounter < slot2saveCounter)
                gSaveCounter = slot2saveCounter;
            else
                gSaveCounter = slot1saveCounter;
        }
        return SAVE_STATUS_OK;
    }

    if (slot1Status == SAVE_STATUS_OK)
    {
        gSaveCounter = slot1saveCounter;
        if (slot2Status == SAVE_STATUS_ERROR)
            return SAVE_STATUS_ERROR;
        else
            return SAVE_STATUS_OK;
    }

    if (slot2Status == SAVE_STATUS_OK)
    {
        gSaveCounter = slot2saveCounter;
        if (slot1Status == SAVE_STATUS_ERROR)
            return SAVE_STATUS_ERROR;
        else
            return SAVE_STATUS_OK;
    }

    if (slot1Status == SAVE_STATUS_EMPTY && slot2Status == SAVE_STATUS_EMPTY)
    {
        gSaveCounter = 0;
        gFirstSaveSector = 0;
        return SAVE_STATUS_EMPTY;
    }

    gSaveCounter = 0;
    gFirstSaveSector = 0;
    return 2;
}

u8 ReadSomeUnknownSectorAndVerify(u8 sector, u8 *data, u16 size)
{
    u16 i;
    struct SaveSector *section = eSaveSection;

    DoReadFlashWholeSection(sector, section);
    if (section->signature == FILE_SIGNATURE)
    {
        u16 checksum = CalculateChecksum(section->data, size);
        if (section->id == checksum)
        {
            for (i = 0; i < size; i++)
                data[i] = section->data[i];
            return SAVE_STATUS_OK;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return SAVE_STATUS_EMPTY;
    }
}

u32 DoReadFlashWholeSection(u8 sector, struct SaveSector *section)
{
    ReadFlash(sector, 0, section->data, sizeof(struct SaveSector));
    return 1;
}

u16 CalculateChecksum(const void *data, u16 size)
{
    u16 i;
    u32 checksum = 0;

    for (i = 0; i < (size / 4); i++)
    {
        checksum += *((u32 *)data);
        data += sizeof(u32);
    }

    return ((checksum >> 16) + checksum);
}

void nullsub_0201182C()
{
}

void nullsub_02011830()
{
}

void nullsub_02011834()
{
}

u16 * get_var_addr(u16 a0)
{
    if (a0 < VARS_START)
        return NULL;
    if (a0 < VAR_SPECIAL_0)
        return &gSaveBlock1.vars[a0 - VARS_START];
    return NULL;
}

bool32 flash_maincb_check_need_reset_pacifidlog_tm(void)
{
    u8 sp0;
    u16 * data = get_var_addr(VAR_PACIFIDLOG_TM_RECEIVED_DAY);
    rtc_maincb_is_time_since_last_berry_update_positive(&sp0);
    if (*data <= gRtcUTCTime.days)
        return TRUE;
    else
        return FALSE;
}

bool32 flash_maincb_reset_pacifidlog_tm(void)
{
    u8 sp0;
    if (flash_maincb_check_need_reset_pacifidlog_tm() == TRUE)
        return TRUE;
    rtc_maincb_is_time_since_last_berry_update_positive(&sp0);
    if (gRtcUTCTime.days < 0)
        return FALSE;
    *get_var_addr(VAR_PACIFIDLOG_TM_RECEIVED_DAY) = 1;
    if (flash_write_save_block_chunks_check_damage(0) != TRUE)
        return FALSE;
    return TRUE;
}
