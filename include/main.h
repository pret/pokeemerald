#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

typedef void (*MainCallback)(void);
typedef void (*IntrCallback)(void);
typedef void (*IntrFunc)(void);

struct Main
{
    MainCallback callback1;
    MainCallback callback2;

    MainCallback savedCallback;

    IntrCallback vblankCallback;
    IntrCallback hblankCallback;
    IntrCallback vcountCallback;
    IntrCallback serialCallback;

    vu16 intrCheck;

    u32 vblankCounter1;
    u32 vblankCounter2;

    u16 heldKeysRaw;           // held keys without L=A remapping
    u16 newKeysRaw;            // newly pressed keys without L=A remapping
    u16 heldKeys;              // held keys with L=A remapping
    u16 newKeys;               // newly pressed keys with L=A remapping
    u16 newAndRepeatedKeys;    // newly pressed keys plus key repeat
    u16 keyRepeatCounter;      // counts down to 0, triggering key repeat
    bool16 watchedKeysPressed; // whether one of the watched keys was pressed
    u16 watchedKeysMask;       // bit mask for watched keys

    struct OamData oamBuffer[128];

    u8 state;

    u8 oamLoadDisabled:1;
    u8 inBattle:1;
    u8 anyLinkBattlerHasFrontierPass:1;
};

#define GAME_CODE_LENGTH 4
extern const u8 gGameVersion;
extern const u8 gGameLanguage;
extern const u8 RomHeaderGameCode[GAME_CODE_LENGTH];
extern const u8 RomHeaderSoftwareVersion;

extern u16 gKeyRepeatStartDelay;
extern bool8 gLinkTransferringData;
extern struct Main gMain;
extern u16 gKeyRepeatContinueDelay;
extern bool8 gSoftResetDisabled;
extern IntrFunc gIntrTable[];
extern u8 gLinkVSyncDisabled;
extern u32 IntrMain_Buffer[];
extern s8 gPcmDmaCounter;

void AgbMain(void);
void SetMainCallback2(MainCallback callback);
void InitKeys(void);
void SetVBlankCallback(IntrCallback callback);
void SetHBlankCallback(IntrCallback callback);
void SetVCountCallback(IntrCallback callback);
void SetSerialCallback(IntrCallback callback);
void InitFlashTimer(void);
void SetTrainerHillVBlankCounter(u32 *counter);
void ClearTrainerHillVBlankCounter(void);
void DoSoftReset(void);
void ClearPokemonCrySongs(void);
void RestoreSerialTimer3IntrHandlers(void);
void StartTimer1(void);
void SeedRngAndSetTrainerId(void);
u16 GetGeneratedTrainerIdLower(void);

#endif // GUARD_MAIN_H
