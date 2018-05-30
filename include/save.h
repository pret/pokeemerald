#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

extern u16 gSaveFileStatus;

struct SaveSectionLocation
{
    void *data;
    u16 size;
};

struct SaveSection
{
    u8 data[0xFF4];
    u16 id;
    u16 checksum;
    u32 security;
    u32 counter;
}; // size is 0x1000

// headless save section?
struct UnkSaveSection
{
    u8 data[0xFF4];
    u32 security;
}; // size is 0xFF8

struct SaveSectionOffsets
{
	u16 toAdd;
	u16 size;
};

// Emerald changes this definition to be the sectors per slot.
#define NUM_SECTORS_PER_SLOT 16 // move to save.h

#define UNKNOWN_CHECK_VALUE 0x8012025

// SetDamagedSectorBits states
enum
{
    ENABLE,
    DISABLE,
    CHECK // unused
};

// Do save types
enum
{
    SAVE_NORMAL,
    SAVE_LINK,
    //EREADER_SAVE, // deprecated in Emerald
	SAVE_LINK2, // unknown 2nd link save
    SAVE_HALL_OF_FAME,
    SAVE_OVERWRITE_DIFFERENT_FILE,
    SAVE_HALL_OF_FAME_ERASE_BEFORE // unused
};

#define SECTION_ID_RECORDED_BATTLE  31

void ClearSaveData(void);
void Save_ResetSaveCounters(void);
bool32 SetDamagedSectorBits(u8 op, u8 bit);
u8 save_write_to_flash(u16 a1, const struct SaveSectionLocation *location);
u8 HandleWriteSector(u16 a1, const struct SaveSectionLocation *location);
u8 HandleWriteSectorNBytes(u8 sector, u8 *data, u16 size);
u8 TryWriteSector(u8 sector, u8 *data);
u32 RestoreSaveBackupVarsAndIncrement(const struct SaveSectionLocation *location);
u32 RestoreSaveBackupVars(const struct SaveSectionLocation *location);
u8 sub_81529D4(u16 a1, const struct SaveSectionLocation *location);
u8 sub_8152A34(u16 a1, const struct SaveSectionLocation *location);
u8 ClearSaveData_2(u16 a1, const struct SaveSectionLocation *location);
u8 sav12_xor_get(u16 a1, const struct SaveSectionLocation *location);
u8 sub_8152CAC(u16 a1, const struct SaveSectionLocation *location);
u8 sub_8152D44(u16 a1, const struct SaveSectionLocation *location);
u8 sub_8152DD0(u16 a1, const struct SaveSectionLocation *location);
u8 sub_8152E10(u16 a1, const struct SaveSectionLocation *location);
u8 GetSaveValidStatus(const struct SaveSectionLocation *location);
u8 sub_81530DC(u8 a1, u8 *data, u16 size);
u8 DoReadFlashWholeSection(u8 sector, struct SaveSection *section);
u16 CalculateChecksum(void *data, u16 size);
void UpdateSaveAddresses(void);
u8 HandleSavingData(u8 saveType);
u8 TrySavingData(u8 saveType);
u8 sub_8153380(void);
bool8 sub_81533AC(void);
u8 sub_81533E0(void);
u8 sub_8153408(void);
u8 sub_8153430(void);
bool8 sub_8153474(void);
u8 Save_LoadGameData(u8 a1);
u16 sub_815355C(void);
u8 sub_81534D0(u8);
u8 sub_8153430(void);
bool8 sub_8153474(void);
u32 TryCopySpecialSaveSection(u8 sector, u8* dst);
u32 sub_8153634(u8 sector, u8* src);
void sub_8153688(u8 taskId);

#endif // GUARD_SAVE_H
