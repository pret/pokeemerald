#include "global.h"
#include "agb_flash.h"
#include "gba/flash_internal.h"
#include "fieldmap.h"
#include "save.h"
#include "task.h"
#include "decompress.h"
#include "load_save.h"
#include "overworld.h"
#include "pokemon_storage_system.h"
#include "main.h"
#include "trainer_hill.h"
#include "link.h"
#include "constants/game_stat.h"

static u16 CalculateChecksum(void *data, u16 size);
static bool8 DoReadFlashWholeSection(u8 sector, struct SaveSection *section);
static u8 GetSaveValidStatus(const struct SaveSectionLocation *location);
static u8 sub_8152E10(u16 a1, const struct SaveSectionLocation *location);
static u8 ClearSaveData_2(u16 a1, const struct SaveSectionLocation *location);
static u8 TryWriteSector(u8 sector, u8 *data);
static u8 HandleWriteSector(u16 a1, const struct SaveSectionLocation *location);

// Divide save blocks into individual chunks to be written to flash sectors

// Each 4 KiB flash sector contains 3968 bytes of actual data followed by a 128 byte footer
#define SECTOR_DATA_SIZE 3968
#define SECTOR_FOOTER_SIZE 128

/*
 * Sector Layout:
 *
 * Sectors 0 - 13:      Save Slot 1
 * Sectors 14 - 27:     Save Slot 2
 * Sectors 28 - 29:     Hall of Fame
 * Sector 30:           Trainer Hill
 * Sector 31:           Recorded Battle
 *
 * There are two save slots for saving the player's game data. We alternate between
 * them each time the game is saved, so that if the current save slot is corrupt,
 * we can load the previous one. We also rotate the sectors in each save slot
 * so that the same data is not always being written to the same sector. This
 * might be done to reduce wear on the flash memory, but I'm not sure, since all
 * 14 sectors get written anyway.
 */

// (u8 *)structure was removed from the first statement of the macro in Emerald.
// This is because malloc is used to allocate addresses so storing the raw
// addresses should not be done in the offsets information.
#define SAVEBLOCK_CHUNK(structure, chunkNum)                                \
{                                                                           \
    chunkNum * SECTOR_DATA_SIZE,                                            \
    min(sizeof(structure) - chunkNum * SECTOR_DATA_SIZE, SECTOR_DATA_SIZE)  \
}                                                                           \

static const struct SaveSectionOffsets sSaveSectionOffsets[] =
{
    SAVEBLOCK_CHUNK(gSaveblock2, 0),

    SAVEBLOCK_CHUNK(gSaveblock1, 0),
    SAVEBLOCK_CHUNK(gSaveblock1, 1),
    SAVEBLOCK_CHUNK(gSaveblock1, 2),
    SAVEBLOCK_CHUNK(gSaveblock1, 3),

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

// iwram common
u16 gLastWrittenSector;
u32 gLastSaveCounter;
u16 gLastKnownGoodSector;
u32 gDamagedSaveSectors;
u32 gSaveCounter;
struct SaveSection *gFastSaveSection;
u16 gUnknown_03006208;
u16 gSaveUnusedVar;
u16 gSaveFileStatus;
void (*gGameContinueCallback)(void);
struct SaveSectionLocation gRamSaveSectionLocations[SECTOR_SAVE_SLOT_LENGTH];
u16 gSaveUnusedVar2;
u16 gSaveAttemptStatus;

EWRAM_DATA struct SaveSection gSaveDataBuffer = {0};
EWRAM_DATA static u8 sUnusedVar = 0;

void ClearSaveData(void)
{
    u16 i;

    for (i = 0; i < NUM_SECTORS_PER_SLOT; i++)
    {
        EraseFlashSector(i);
        EraseFlashSector(i + NUM_SECTORS_PER_SLOT); // clear slot 2.
    }
}

void Save_ResetSaveCounters(void)
{
    gSaveCounter = 0;
    gLastWrittenSector = 0;
    gDamagedSaveSectors = 0;
}

static bool32 SetDamagedSectorBits(u8 op, u8 bit)
{
    bool32 retVal = FALSE;

    switch (op)
    {
    case ENABLE:
        gDamagedSaveSectors |= (1 << bit);
        break;
    case DISABLE:
        gDamagedSaveSectors &= ~(1 << bit);
        break;
    case CHECK: // unused
        if (gDamagedSaveSectors & (1 << bit))
            retVal = TRUE;
        break;
    }

    return retVal;
}

static u8 SaveWriteToFlash(u16 a1, const struct SaveSectionLocation *location)
{
    u32 status;
    u16 i;

    gFastSaveSection = &gSaveDataBuffer;

    if (a1 != 0xFFFF) // for link
    {
        status = HandleWriteSector(a1, location);
    }
    else
    {
        gLastKnownGoodSector = gLastWrittenSector; // backup the current written sector before attempting to write.
        gLastSaveCounter = gSaveCounter;
        gLastWrittenSector++;
        gLastWrittenSector = gLastWrittenSector % SECTOR_SAVE_SLOT_LENGTH; // array count save sector locations
        gSaveCounter++;
        status = SAVE_STATUS_OK;

        for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
            HandleWriteSector(i, location);

        if (gDamagedSaveSectors != 0) // skip the damaged sector.
        {
            status = SAVE_STATUS_ERROR;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }

    return status;
}

static u8 HandleWriteSector(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;

    sector = sectorId + gLastWrittenSector;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);

    data = location[sectorId].data;
    size = location[sectorId].size;

    // clear save section.
    for (i = 0; i < sizeof(struct SaveSection); i++)
        ((char *)gFastSaveSection)[i] = 0;

    gFastSaveSection->id = sectorId;
    gFastSaveSection->security = UNKNOWN_CHECK_VALUE;
    gFastSaveSection->counter = gSaveCounter;

    for (i = 0; i < size; i++)
        gFastSaveSection->data[i] = data[i];

    gFastSaveSection->checksum = CalculateChecksum(data, size);
    return TryWriteSector(sector, gFastSaveSection->data);
}

static u8 HandleWriteSectorNBytes(u8 sector, u8 *data, u16 size)
{
    u16 i;
    struct SaveSection *section = &gSaveDataBuffer;

    for (i = 0; i < sizeof(struct SaveSection); i++)
        ((char *)section)[i] = 0;

    section->security = UNKNOWN_CHECK_VALUE;

    for (i = 0; i < size; i++)
        section->data[i] = data[i];

    section->id = CalculateChecksum(data, size); // though this appears to be incorrect, it might be some sector checksum instead of a whole save checksum and only appears to be relevent to HOF data, if used.
    return TryWriteSector(sector, section->data);
}

static u8 TryWriteSector(u8 sector, u8 *data)
{
    if (ProgramFlashSectorAndVerify(sector, data) != 0) // is damaged?
    {
        SetDamagedSectorBits(ENABLE, sector); // set damaged sector bits.
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector); // unset damaged sector bits. it's safe now.
        return SAVE_STATUS_OK;
    }
}

static u32 RestoreSaveBackupVarsAndIncrement(const struct SaveSectionLocation *location) // location is unused
{
    gFastSaveSection = &gSaveDataBuffer;
    gLastKnownGoodSector = gLastWrittenSector;
    gLastSaveCounter = gSaveCounter;
    gLastWrittenSector++;
    gLastWrittenSector %= SECTOR_SAVE_SLOT_LENGTH;
    gSaveCounter++;
    gUnknown_03006208 = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

static u32 RestoreSaveBackupVars(const struct SaveSectionLocation *location) // only ever called once, and gSaveBlock2 is passed to this function. location is unused
{
    gFastSaveSection = &gSaveDataBuffer;
    gLastKnownGoodSector = gLastWrittenSector;
    gLastSaveCounter = gSaveCounter;
    gUnknown_03006208 = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

static u8 sub_81529D4(u16 sectorId, const struct SaveSectionLocation *location)
{
    u8 status;

    if (gUnknown_03006208 < sectorId - 1)
    {
        status = SAVE_STATUS_OK;
        HandleWriteSector(gUnknown_03006208, location);
        gUnknown_03006208++;
        if (gDamagedSaveSectors)
        {
            status = SAVE_STATUS_ERROR;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }
    else
    {
        status = SAVE_STATUS_ERROR;
    }

    return status;
}

static u8 sub_8152A34(u16 sectorId, const struct SaveSectionLocation *location)
{
    u8 status = SAVE_STATUS_OK;

    ClearSaveData_2(sectorId - 1, location);

    if (gDamagedSaveSectors)
    {
        status = SAVE_STATUS_ERROR;
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
    }
    return status;
}

static u8 ClearSaveData_2(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;
    u8 status;

    sector = sectorId + gLastWrittenSector;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);

    data = location[sectorId].data;
    size = location[sectorId].size;

    // clear temp save section.
    for (i = 0; i < sizeof(struct SaveSection); i++)
        ((char *)gFastSaveSection)[i] = 0;

    gFastSaveSection->id = sectorId;
    gFastSaveSection->security = UNKNOWN_CHECK_VALUE;
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
        if (ProgramFlashByte(sector, i, ((u8 *)gFastSaveSection)[i]))
        {
            status = SAVE_STATUS_ERROR;
            break;
        }
    }

    if (status == SAVE_STATUS_ERROR)
    {
        SetDamagedSectorBits(ENABLE, sector);
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
            SetDamagedSectorBits(ENABLE, sector);
            return SAVE_STATUS_ERROR;
        }
        else
        {
            SetDamagedSectorBits(DISABLE, sector);
            return SAVE_STATUS_OK;
        }
    }
}

static u8 sav12_xor_get(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 sector;

    sector = sectorId + gLastWrittenSector; // no sub 1?
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), 0x25))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 sub_8152CAC(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 sector;

    sector = sectorId + gLastWrittenSector - 1;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), ((u8 *)gFastSaveSection)[sizeof(struct UnkSaveSection)]))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 sub_8152D44(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 sector;

    sector = sectorId + gLastWrittenSector - 1; // no sub 1?
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);

    if (ProgramFlashByte(sector, sizeof(struct UnkSaveSection), 0x25))
    {
        // sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 sub_8152DD0(u16 a1, const struct SaveSectionLocation *location)
{
    u8 status;
    gFastSaveSection = &gSaveDataBuffer;
    if (a1 != 0xFFFF)
    {
        status = SAVE_STATUS_ERROR;
    }
    else
    {
        status = GetSaveValidStatus(location);
        sub_8152E10(0xFFFF, location);
    }

    return status;
}

static u8 sub_8152E10(u16 a1, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 checksum;
    u16 v3 = SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);
    u16 id;

    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i + v3, gFastSaveSection);
        id = gFastSaveSection->id;
        if (id == 0)
            gLastWrittenSector = i;
        checksum = CalculateChecksum(gFastSaveSection->data, location[id].size);
        if (gFastSaveSection->security == UNKNOWN_CHECK_VALUE
         && gFastSaveSection->checksum == checksum)
        {
            u16 j;
            for (j = 0; j < location[id].size; j++)
                ((u8 *)location[id].data)[j] = gFastSaveSection->data[j];
        }
    }

    return SAVE_STATUS_OK;
}

static u8 GetSaveValidStatus(const struct SaveSectionLocation *location)
{
    u16 i;
    u16 checksum;
    u32 saveSlot1Counter = 0;
    u32 saveSlot2Counter = 0;
    u32 slotCheckField = 0;
    bool8 securityPassed = FALSE;
    u8 saveSlot1Status;
    u8 saveSlot2Status;

    // check save slot 1.
    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i, gFastSaveSection);
        if (gFastSaveSection->security == UNKNOWN_CHECK_VALUE)
        {
            securityPassed = TRUE;
            checksum = CalculateChecksum(gFastSaveSection->data, location[gFastSaveSection->id].size);
            if (gFastSaveSection->checksum == checksum)
            {
                saveSlot1Counter = gFastSaveSection->counter;
                slotCheckField |= 1 << gFastSaveSection->id;
            }
        }
    }

    if (securityPassed)
    {
        if (slotCheckField == 0x3FFF)
            saveSlot1Status = SAVE_STATUS_OK;
        else
            saveSlot1Status = SAVE_STATUS_ERROR;
    }
    else
    {
        saveSlot1Status = SAVE_STATUS_EMPTY;
    }

    slotCheckField = 0;
    securityPassed = FALSE;

    // check save slot 2.
    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i + SECTOR_SAVE_SLOT_LENGTH, gFastSaveSection);
        if (gFastSaveSection->security == UNKNOWN_CHECK_VALUE)
        {
            securityPassed = TRUE;
            checksum = CalculateChecksum(gFastSaveSection->data, location[gFastSaveSection->id].size);
            if (gFastSaveSection->checksum == checksum)
            {
                saveSlot2Counter = gFastSaveSection->counter;
                slotCheckField |= 1 << gFastSaveSection->id;
            }
        }
    }

    if (securityPassed)
    {
        if (slotCheckField == 0x3FFF)
            saveSlot2Status = SAVE_STATUS_OK;
        else
            saveSlot2Status = SAVE_STATUS_ERROR;
    }
    else
    {
        saveSlot2Status = SAVE_STATUS_EMPTY;
    }

    if (saveSlot1Status == SAVE_STATUS_OK && saveSlot2Status == SAVE_STATUS_OK)
    {
        if ((saveSlot1Counter == -1 && saveSlot2Counter == 0) || (saveSlot1Counter == 0 && saveSlot2Counter == -1))
        {
            if ((unsigned)(saveSlot1Counter + 1) < (unsigned)(saveSlot2Counter + 1))
                gSaveCounter = saveSlot2Counter;
            else
                gSaveCounter = saveSlot1Counter;
        }
        else
        {
            if (saveSlot1Counter < saveSlot2Counter)
                gSaveCounter = saveSlot2Counter;
            else
                gSaveCounter = saveSlot1Counter;
        }
        return SAVE_STATUS_OK;
    }

    if (saveSlot1Status == SAVE_STATUS_OK)
    {
        gSaveCounter = saveSlot1Counter;
        if (saveSlot2Status == SAVE_STATUS_ERROR)
            return SAVE_STATUS_ERROR;
        return SAVE_STATUS_OK;
    }

    if (saveSlot2Status == SAVE_STATUS_OK)
    {
        gSaveCounter = saveSlot2Counter;
        if (saveSlot1Status == SAVE_STATUS_ERROR)
            return SAVE_STATUS_ERROR;
        return SAVE_STATUS_OK;
    }

    if (saveSlot1Status == SAVE_STATUS_EMPTY && saveSlot2Status == SAVE_STATUS_EMPTY)
    {
        gSaveCounter = 0;
        gLastWrittenSector = 0;
        return SAVE_STATUS_EMPTY;
    }

    gSaveCounter = 0;
    gLastWrittenSector = 0;
    return SAVE_STATUS_CORRUPT;
}

static u8 sub_81530DC(u8 sectorId, u8 *data, u16 size)
{
    u16 i;
    struct SaveSection *section = &gSaveDataBuffer;
    DoReadFlashWholeSection(sectorId, section);
    if (section->security == UNKNOWN_CHECK_VALUE)
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
            return SAVE_STATUS_CORRUPT;
        }
    }
    else
    {
        return SAVE_STATUS_EMPTY;
    }
}

// Return value always ignored
static bool8 DoReadFlashWholeSection(u8 sector, struct SaveSection *section)
{
    ReadFlash(sector, 0, section->data, sizeof(struct SaveSection));
    return TRUE;
}

static u16 CalculateChecksum(void *data, u16 size)
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

static void UpdateSaveAddresses(void)
{
    int i = 0;

    gRamSaveSectionLocations[i].data = (void*)(gSaveBlock2Ptr) + sSaveSectionOffsets[i].toAdd;
    gRamSaveSectionLocations[i].size = sSaveSectionOffsets[i].size;

    for (i = SECTOR_ID_SAVEBLOCK1_START; i <= SECTOR_ID_SAVEBLOCK1_END; i++)
    {
        gRamSaveSectionLocations[i].data = (void*)(gSaveBlock1Ptr) + sSaveSectionOffsets[i].toAdd;
        gRamSaveSectionLocations[i].size = sSaveSectionOffsets[i].size;
    }

    for (; i <= SECTOR_ID_PKMN_STORAGE_END; i++) //setting i to SECTOR_ID_PKMN_STORAGE_START does not match
    {
        gRamSaveSectionLocations[i].data = (void*)(gPokemonStoragePtr) + sSaveSectionOffsets[i].toAdd;
        gRamSaveSectionLocations[i].size = sSaveSectionOffsets[i].size;
    }
}

u8 HandleSavingData(u8 saveType)
{
    u8 i;
    u32 *backupVar = gTrainerHillVBlankCounter;
    u8 *tempAddr;

    gTrainerHillVBlankCounter = NULL;
    UpdateSaveAddresses();
    switch (saveType)
    {
    case SAVE_HALL_OF_FAME_ERASE_BEFORE: // deletes HOF before overwriting HOF completely. unused
        for (i = SECTOR_ID_HOF_1; i < SECTORS_COUNT; i++)
            EraseFlashSector(i);
    case SAVE_HALL_OF_FAME: // hall of fame.
        if (GetGameStat(GAME_STAT_ENTERED_HOF) < 999)
            IncrementGameStat(GAME_STAT_ENTERED_HOF);
        SaveSerializedGame();
        SaveWriteToFlash(0xFFFF, gRamSaveSectionLocations);
        tempAddr = gDecompressionBuffer;
        HandleWriteSectorNBytes(SECTOR_ID_HOF_1, tempAddr, SECTOR_DATA_SIZE);
        HandleWriteSectorNBytes(SECTOR_ID_HOF_2, tempAddr + SECTOR_DATA_SIZE, SECTOR_DATA_SIZE);
        break;
    case SAVE_NORMAL: // normal save. also called by overwriting your own save.
    default:
        SaveSerializedGame();
        SaveWriteToFlash(0xFFFF, gRamSaveSectionLocations);
        break;
    case SAVE_LINK:  // Link and Battle Frontier
    case SAVE_LINK2: // Unused
        SaveSerializedGame();
        for(i = SECTOR_ID_SAVEBLOCK2; i <= SECTOR_ID_SAVEBLOCK1_END; i++)
            ClearSaveData_2(i, gRamSaveSectionLocations);
        for(i = SECTOR_ID_SAVEBLOCK2; i <= SECTOR_ID_SAVEBLOCK1_END; i++)
            sav12_xor_get(i, gRamSaveSectionLocations);
        break;
    // Support for Ereader was removed in Emerald.
    /*
    case EREADER_SAVE: // used in mossdeep "game corner" before/after battling old man e-reader trainer
        SaveSerializedGame();
        SaveWriteToFlash(0, gRamSaveSectionLocations);
        break;
    */
    case SAVE_OVERWRITE_DIFFERENT_FILE:
        for (i = SECTOR_ID_HOF_1; i < SECTORS_COUNT; i++)
            EraseFlashSector(i); // erase HOF.
        SaveSerializedGame();
        SaveWriteToFlash(0xFFFF, gRamSaveSectionLocations);
        break;
    }
    gTrainerHillVBlankCounter = backupVar;
    return 0;
}

u8 TrySavingData(u8 saveType)
{
    if (gFlashMemoryPresent != TRUE)
    {
        gSaveAttemptStatus = SAVE_STATUS_ERROR;
        return SAVE_STATUS_ERROR;
    }

    HandleSavingData(saveType);
    if (!gDamagedSaveSectors)
    {
        gSaveAttemptStatus = SAVE_STATUS_OK;
        return SAVE_STATUS_OK;
    }
    else
    {
        DoSaveFailedScreen(saveType);
        gSaveAttemptStatus = SAVE_STATUS_ERROR;
        return SAVE_STATUS_ERROR;
    }
}

bool8 sub_8153380(void) // trade.c
{
    if (gFlashMemoryPresent != TRUE)
        return TRUE;
    UpdateSaveAddresses();
    SaveSerializedGame();
    RestoreSaveBackupVarsAndIncrement(gRamSaveSectionLocations);
    return FALSE;
}

bool8 sub_81533AC(void) // trade.c
{
    u8 status = sub_81529D4(SECTOR_SAVE_SLOT_LENGTH, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_NORMAL);
    if (status == SAVE_STATUS_ERROR)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_81533E0(void) // trade.c
{
    sub_8152A34(SECTOR_SAVE_SLOT_LENGTH, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_NORMAL);
    return FALSE;
}

bool8 sub_8153408(void) // trade.c
{
    sub_8152CAC(SECTOR_SAVE_SLOT_LENGTH, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_NORMAL);
    return FALSE;
}

u8 FullSaveGame(void)
{
    if (gFlashMemoryPresent != TRUE)
        return TRUE;

    UpdateSaveAddresses();
    SaveSerializedGame();
    RestoreSaveBackupVars(gRamSaveSectionLocations);
    sub_8152A34(gUnknown_03006208 + 1, gRamSaveSectionLocations);
    return FALSE;
}

bool8 CheckSaveFile(void)
{
    u8 retVal = FALSE;
    u16 sectorId = ++gUnknown_03006208;
    if (sectorId <= SECTOR_ID_SAVEBLOCK1_END)
    {
        sub_8152A34(gUnknown_03006208 + 1, gRamSaveSectionLocations);
        sub_8152D44(sectorId, gRamSaveSectionLocations);
    }
    else
    {
        sub_8152D44(sectorId, gRamSaveSectionLocations);
        retVal = TRUE;
    }
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_LINK);
    return retVal;
}

u8 Save_LoadGameData(u8 saveType)
{
    u8 status;

    if (gFlashMemoryPresent != TRUE)
    {
        gSaveFileStatus = SAVE_STATUS_NO_FLASH;
        return SAVE_STATUS_ERROR;
    }

    UpdateSaveAddresses();
    switch (saveType)
    {
    case SAVE_NORMAL:
    default:
        status = sub_8152DD0(0xFFFF, gRamSaveSectionLocations);
        LoadSerializedGame();
        gSaveFileStatus = status;
        gGameContinueCallback = 0;
        break;
    case SAVE_HALL_OF_FAME:
        status = sub_81530DC(SECTOR_ID_HOF_1, gDecompressionBuffer, SECTOR_DATA_SIZE);
        if (status == SAVE_STATUS_OK)
            status = sub_81530DC(SECTOR_ID_HOF_2, gDecompressionBuffer + SECTOR_DATA_SIZE, SECTOR_DATA_SIZE);
        break;
    }

    return status;
}

u16 sub_815355C(void)
{
    u16 i, v3;
    struct SaveSection* savSection;

    savSection = gFastSaveSection = &gSaveDataBuffer;
    if (gFlashMemoryPresent != TRUE)
        return SAVE_STATUS_EMPTY;
    UpdateSaveAddresses();
    GetSaveValidStatus(gRamSaveSectionLocations);
    v3 = SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % 2);
    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i + v3, gFastSaveSection);
        if (gFastSaveSection->id == 0)
            return savSection->data[10] +
                   savSection->data[11] +
                   savSection->data[12] +
                   savSection->data[13];
    }
    return SAVE_STATUS_EMPTY;
}

u32 TryReadSpecialSaveSection(u8 sector, u8* dst)
{
    s32 i;
    s32 size;
    u8* savData;

    if (sector != SECTOR_ID_TRAINER_HILL && sector != SECTOR_ID_RECORDED_BATTLE)
        return SAVE_STATUS_ERROR;
    ReadFlash(sector, 0, (u8 *)&gSaveDataBuffer, sizeof(struct SaveSection));
    if (*(u32*)(&gSaveDataBuffer.data[0]) != SPECIAL_SECTION_SENTINEL)
        return SAVE_STATUS_ERROR;
    // copies whole save section except u32 counter
    i = 0;
    size = 0xFFB;
    savData = &gSaveDataBuffer.data[4];
    for (; i <= size; i++)
        dst[i] = savData[i];
    return SAVE_STATUS_OK;
}

u32 TryWriteSpecialSaveSection(u8 sector, u8* src)
{
    s32 i;
    s32 size;
    u8* savData;
    void* savDataBuffer;

    if (sector != SECTOR_ID_TRAINER_HILL && sector != SECTOR_ID_RECORDED_BATTLE)
        return SAVE_STATUS_ERROR;

    savDataBuffer = &gSaveDataBuffer;
    *(u32*)(savDataBuffer) = SPECIAL_SECTION_SENTINEL;

    // copies whole save section except u32 counter
    i = 0;
    size = 0xFFB;
    savData = &gSaveDataBuffer.data[4];
    for (; i <= size; i++)
        savData[i] = src[i];
    if (ProgramFlashSectorAndVerify(sector, savDataBuffer) != 0)
        return SAVE_STATUS_ERROR;
    return SAVE_STATUS_OK;
}

#define tState       data[0]
#define tTimer       data[1]
#define tPartialSave data[2]

void Task_LinkSave(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        gSoftResetDisabled = TRUE;
        tState = 1;
        break;
    case 1:
        SetLinkStandbyCallback();
        tState = 2;
        break;
    case 2:
        if (IsLinkTaskFinished())
        {
            if (!tPartialSave)
                save_serialize_map();
            tState = 3;
        }
        break;
    case 3:
        if (!tPartialSave)
            SetContinueGameWarpStatusToDynamicWarp();
        sub_8153380();
        tState = 4;
        break;
    case 4:
        if (++tTimer == 5)
        {
            tTimer = 0;
            tState = 5;
        }
        break;
    case 5:
        if (sub_81533AC())
            tState = 6;
        else
            tState = 4;
        break;
    case 6:
        sub_81533E0();
        tState = 7;
        break;
    case 7:
        if (!tPartialSave)
            ClearContinueGameWarpStatus2();
        SetLinkStandbyCallback();
        tState = 8;
        break;
    case 8:
        if (IsLinkTaskFinished())
        {
            sub_8153408();
            tState = 9;
        }
        break;
    case 9:
        SetLinkStandbyCallback();
        tState = 10;
        break;
    case 10:
        if (IsLinkTaskFinished())
            tState++;
        break;
    case 11:
        if (++tTimer > 5)
        {
            gSoftResetDisabled = FALSE;
            DestroyTask(taskId);
        }
        break;
    }
}

#undef tState
#undef tTimer
#undef tPartialSave
