#include "global.h"
#include "main.h"
#include "gba/flash_internal.h"
#include "gba/m4a_internal.h"

extern u16 GetGpuReg(u8);
extern void SetGpuReg(u8, u16);
extern void LinkVSync(void);
extern void sub_800E174(void);
extern void sub_800B9B8(void);

extern struct SoundInfo gSoundInfo;
extern u32 gFlashMemoryPresent;
extern u32 IntrMain[];
extern u8 gHeap[];
extern struct SaveBlock2 gUnknown_02024A54;
extern char *gUnknown_03005D94;
extern char gUnknown_02029808[];
extern u16 gIntrCheck;
extern u32 gBattleTypeFlags;
extern u8 gUnknown_03002748;
//extern u32 gUnknown_0203CF5C;

void Timer3Intr(void);
bool8 HandleLinkConnection(void);
void c2_copyright_1(void);

static void VBlankIntr(void);
static void HBlankIntr(void);
static void VCountIntr(void);
static void SerialIntr(void);
static void IntrDummy(void);

const u8 gGameVersion = VERSION_EMERALD;

const u8 gGameLanguage = GAME_LANGUAGE; // English

const char BuildDateTime[] = "2005 02 21 11:10";

const IntrFunc gIntrTableTemplate[] =
{
    VCountIntr, // V-count interrupt
    SerialIntr, // Serial interrupt
    Timer3Intr, // Timer 3 interrupt
    HBlankIntr, // H-blank interrupt
    VBlankIntr, // V-blank interrupt
    IntrDummy,  // Timer 0 interrupt
    IntrDummy,  // Timer 1 interrupt
    IntrDummy,  // Timer 2 interrupt
    IntrDummy,  // DMA 0 interrupt
    IntrDummy,  // DMA 1 interrupt
    IntrDummy,  // DMA 2 interrupt
    IntrDummy,  // DMA 3 interrupt
    IntrDummy,  // Key interrupt
    IntrDummy,  // Game Pak interrupt
};

#define INTR_COUNT ((int)(sizeof(gIntrTableTemplate)/sizeof(IntrFunc)))

extern u16 gUnknown_03000000;

extern u16 gKeyRepeatStartDelay;
extern u8 gUnknown_030022B4;
extern struct Main gMain;
extern u16 gKeyRepeatContinueDelay;
extern u8 gSoftResetDisabled;
extern IntrFunc gIntrTable[INTR_COUNT];
extern bool8 gLinkVSyncDisabled;
extern u32 IntrMain_Buffer[0x200];
extern u8 gPcmDmaCounter;

extern u16 gTrainerId;

EWRAM_DATA void (**gFlashTimerIntrFunc)(void) = NULL;

static void UpdateLinkAndCallCallbacks(void);
static void InitMainCallbacks(void);
static void CallCallbacks(void);
static void SeedRngWithRtc(void);
static void ReadKeys(void);
void InitIntrHandlers(void);
static void WaitForVBlank(void);

#define B_START_SELECT (B_BUTTON | START_BUTTON | SELECT_BUTTON)

void AgbMain()
{
    RegisterRamReset(RESET_ALL);
    *(vu16 *)BG_PLTT = 0x7FFF;
    InitGpuRegManager();
    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;
    InitKeys();
    InitIntrHandlers();
    m4aSoundInit();
    EnableVCountIntrAtLine150();
    sub_800E6D0();
    RtcInit();
    CheckForFlashMemory();
    InitMainCallbacks();
    InitMapMusic();
    ClearDma3Requests();
    ResetBgs();
    SetDefaultFontsPointer();
    InitHeap(gHeap, 0x1C000);

    gSoftResetDisabled = FALSE;

    if (gFlashMemoryPresent != TRUE)
        SetMainCallback2(NULL);

    gUnknown_030022B4 = 0;
    gUnknown_03000000 = 0xFC0;

    for (;;)
    {
        ReadKeys();

        if (gSoftResetDisabled == FALSE
         && (gMain.heldKeysRaw & A_BUTTON)
         && (gMain.heldKeysRaw & B_START_SELECT) == B_START_SELECT)
        {
            rfu_REQ_stopMode();
            rfu_waitREQComplete();
            DoSoftReset();
        }

        if (sub_8087634() == 1)
        {
            gUnknown_030022B4 = 1;
            UpdateLinkAndCallCallbacks();
            gUnknown_030022B4 = 0;
        }
        else
        {
            gUnknown_030022B4 = 0;
            UpdateLinkAndCallCallbacks();

            if (sub_80875C8() == 1)
            {
                gMain.newKeys = 0;
                ClearObjectCopyRequests();
                gUnknown_030022B4 = 1;
                UpdateLinkAndCallCallbacks();
                gUnknown_030022B4 = 0;
            }
        }

        PlayTimeCounter_Update();
        MapMusicMain();
        WaitForVBlank();
    }
}

static void UpdateLinkAndCallCallbacks(void)
{
    if (!HandleLinkConnection())
        CallCallbacks();
}

struct gUnknown_0203CF5C_Struct
{
    u32 value;
};

extern struct gUnknown_0203CF5C_Struct gUnknown_0203CF5C;

static void InitMainCallbacks(void)
{
    gMain.vblankCounter1 = 0;
    gUnknown_0203CF5C.value = 0;
    gMain.vblankCounter2 = 0;
    gMain.callback1 = NULL;
    SetMainCallback2(c2_copyright_1);
    gSaveBlock2Ptr = &gUnknown_02024A54;
    gUnknown_03005D94 = gUnknown_02029808;
}

static void CallCallbacks(void)
{
    if (gMain.callback1)
        gMain.callback1();

    if (gMain.callback2)
        gMain.callback2();
}

void SetMainCallback2(MainCallback callback)
{
    gMain.callback2 = callback;
    gMain.state = 0;
}

void StartTimer1(void)
{
    REG_TM1CNT_H = 0x80;
}

void SeedRngAndSetTrainerId(void)
{
    u16 val = REG_TM1CNT_L;
    SeedRng(val);
    REG_TM1CNT_H = 0;
    gTrainerId = val;
}

u16 GetTrainerId(void)
{
    return gTrainerId;
}

void EnableVCountIntrAtLine150(void)
{
    u16 gpuReg = GetGpuReg(0x4) & 0xFF | 0x9600;

    SetGpuReg(4, gpuReg | 0x20);
    EnableInterrupts(0x4); // please use IRQ_MASK_VCOUNT
}

void InitKeys(void)
{
    gKeyRepeatContinueDelay = 5;
    gKeyRepeatStartDelay = 40;
    
    gMain.heldKeys = 0;
    gMain.newKeys = 0;
    gMain.newAndRepeatedKeys = 0;
    gMain.heldKeysRaw = 0;
    gMain.newKeysRaw = 0;
}

static void ReadKeys(void)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    gMain.newKeysRaw = keyInput & ~gMain.heldKeysRaw;
    gMain.newKeys = gMain.newKeysRaw;
    gMain.newAndRepeatedKeys = gMain.newKeysRaw;

    // BUG: Key repeat won't work when pressing L using L=A button mode
    // because it compares the raw key input with the remapped held keys.
    // Note that newAndRepeatedKeys is never remapped either.

    if (keyInput != 0 && gMain.heldKeys == keyInput)
    {
        gMain.keyRepeatCounter--;

        if (gMain.keyRepeatCounter == 0)
        {
            gMain.newAndRepeatedKeys = keyInput;
            gMain.keyRepeatCounter = gKeyRepeatContinueDelay;
        }
    }
    else
    {
        // If there is no input or the input has changed, reset the counter.
        gMain.keyRepeatCounter = gKeyRepeatStartDelay;
    }

    gMain.heldKeysRaw = keyInput;
    gMain.heldKeys = gMain.heldKeysRaw;

    // Remap L to A if the L=A option is enabled.
    if (gSaveBlock2Ptr->optionsButtonMode == 2)
    {
        if (gMain.newKeys & L_BUTTON)
            gMain.newKeys |= A_BUTTON;

        if (gMain.heldKeys & L_BUTTON)
            gMain.heldKeys |= A_BUTTON;
    }

    if (gMain.newKeys & gMain.watchedKeysMask)
        gMain.watchedKeysPressed = TRUE;
}

void InitIntrHandlers(void)
{
    int i;

    for (i = 0; i < INTR_COUNT; i++)
        gIntrTable[i] = gIntrTableTemplate[i];

    DmaCopy32(3, IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer));

    INTR_VECTOR = IntrMain_Buffer;

    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetSerialCallback(NULL);

    REG_IME = 1;
    
    EnableInterrupts(0x1);
}

void SetVBlankCallback(IntrCallback callback)
{
    gMain.vblankCallback = callback;
}

void SetHBlankCallback(IntrCallback callback)
{
    gMain.hblankCallback = callback;
}

void SetVCountCallback(IntrCallback callback)
{
    gMain.vcountCallback = callback;
}

void RestoreSerialTimer3IntrHandlers(void)
{
    gIntrTable[1] = SerialIntr;
    gIntrTable[2] = Timer3Intr;
}

void SetSerialCallback(IntrCallback callback)
{
    gMain.serialCallback = callback;
}

extern void CopyBufferedValuesToGpuRegs(void);
extern void ProcessDma3Requests(void);

#ifdef NONMATCHING
static void VBlankIntr(void)
{
    if (gLinkVSyncDisabled != FALSE)
        LinkVSync();
    else if(gUnknown_03002748 == FALSE)
        sub_800B9B8();

    gMain.vblankCounter1++; // in the original asm, gMain is put into r0 for this addition and then preserved in r4 after it. the compiler wants to skip that and put it in either r4 or r1.

    if(gUnknown_0203CF5C.value > 0)
        if(gUnknown_0203CF5C.value < 0xFFFFFFFF)
            gUnknown_0203CF5C.value++;
    
    if (gMain.vblankCallback)
        gMain.vblankCallback();

    gMain.vblankCounter2++;
    
    CopyBufferedValuesToGpuRegs();
    ProcessDma3Requests();

    gPcmDmaCounter = gSoundInfo.pcmDmaCounter;

    m4aSoundMain();
    sub_8033648();

    if(!gMain.inBattle || (gBattleTypeFlags & 0x013F0102) == 0)
        Random();

    sub_800E174();

    gIntrCheck |= INTR_FLAG_VBLANK;
    gMain.intrCheck |= INTR_FLAG_VBLANK;
}
#else
__attribute__((naked))
static void VBlankIntr(void)
{
    asm(".syntax unified\n\
    push {r4,lr}\n\
    ldr r0, =gLinkVSyncDisabled\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    beq _0800074C\n\
    bl LinkVSync\n\
    b _08000758\n\
    .pool\n\
_0800074C:\n\
    ldr r0, =gUnknown_03002748\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    bne _08000758\n\
    bl sub_800B9B8\n\
_08000758:\n\
    ldr r0, =gMain\n\
    ldr r1, [r0, 0x20]\n\
    adds r1, 0x1\n\
    str r1, [r0, 0x20]\n\
    ldr r1, =gUnknown_0203CF5C\n\
    ldr r1, [r1]\n\
    adds r4, r0, 0\n\
    cmp r1, 0\n\
    beq _08000778\n\
    ldr r2, [r1]\n\
    movs r0, 0x2\n\
    negs r0, r0\n\
    cmp r2, r0\n\
    bhi _08000778\n\
    adds r0, r2, 0x1\n\
    str r0, [r1]\n\
_08000778:\n\
    ldr r0, [r4, 0xC]\n\
    cmp r0, 0\n\
    beq _08000782\n\
    bl _call_via_r0\n\
_08000782:\n\
    ldr r0, [r4, 0x24]\n\
    adds r0, 0x1\n\
    str r0, [r4, 0x24]\n\
    bl CopyBufferedValuesToGpuRegs\n\
    bl ProcessDma3Requests\n\
    ldr r1, =gPcmDmaCounter\n\
    ldr r0, =gSoundInfo\n\
    ldrb r0, [r0, 0x4]\n\
    strb r0, [r1]\n\
    bl m4aSoundMain\n\
    bl sub_8033648\n\
    ldr r1, =0x00000439\n\
    adds r0, r4, r1\n\
    ldrb r1, [r0]\n\
    movs r0, 0x2\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _080007BA\n\
    ldr r0, =gBattleTypeFlags\n\
    ldr r0, [r0]\n\
    ldr r1, =0x013f0102\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _080007BE\n\
_080007BA:\n\
    bl Random\n\
_080007BE:\n\
    bl sub_800E174\n\
    ldr r2, =gIntrCheck\n\
    ldrh r0, [r2]\n\
    movs r1, 0x1\n\
    orrs r0, r1\n\
    strh r0, [r2]\n\
    ldr r0, =gMain\n\
    ldrh r2, [r0, 0x1C]\n\
    ldrh r3, [r0, 0x1C]\n\
    orrs r1, r2\n\
    strh r1, [r0, 0x1C]\n\
    pop {r4}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif

void StartFlashMemoryTimer(void)
{
    SetFlashTimerIntr(2, gIntrTable + 0x7);
}

static void HBlankIntr(void)
{
    if (gMain.hblankCallback)
        gMain.hblankCallback();

    INTR_CHECK |= INTR_FLAG_HBLANK;
    gMain.intrCheck |= INTR_FLAG_HBLANK;
}

static void VCountIntr(void)
{
    if (gMain.vcountCallback)
        gMain.vcountCallback();

    m4aSoundVSync();
    gIntrCheck |= INTR_FLAG_VCOUNT;
    gMain.intrCheck |= INTR_FLAG_VCOUNT;
}

static void SerialIntr(void)
{
    if (gMain.serialCallback)
        gMain.serialCallback();

    gIntrCheck |= INTR_FLAG_SERIAL;
    gMain.intrCheck |= INTR_FLAG_SERIAL;
}

static void IntrDummy(void)
{}

static void WaitForVBlank(void)
{
    gMain.intrCheck &= ~INTR_FLAG_VBLANK;
    
    while(!(gMain.intrCheck & 0x1))
        ;
}

void sub_80008DC(u32 var)
{
    gUnknown_0203CF5C.value = var;
}

void sub_80008E8(void)
{
    gUnknown_0203CF5C.value = 0;
}

void DoSoftReset(void)
{
    REG_IME = 0;
    m4aSoundVSyncOff();
    remove_some_task();
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);
    SiiRtcProtect();
    SoftReset(RESET_ALL);
}

void ClearPokemonCrySongs(void)
{
    CpuFill16(0, gPokemonCrySongs, MAX_POKEMON_CRIES * sizeof(struct PokemonCrySong));
}
