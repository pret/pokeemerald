#include "global.h"
#include "gba/m4a_internal.h"

extern const u8 gCgb3Vol[];

#define BSS_CODE __attribute__((section(".bss.code")))

BSS_CODE ALIGNED(4) char SoundMainRAM_Buffer[0x800] = {0};

COMMON_DATA struct SoundInfo gSoundInfo = {0};
COMMON_DATA struct PokemonCrySong gPokemonCrySongs[MAX_POKEMON_CRIES] = {0};
COMMON_DATA struct MusicPlayerInfo gPokemonCryMusicPlayers[MAX_POKEMON_CRIES] = {0};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_BGM = {0};
COMMON_DATA MPlayFunc gMPlayJumpTable[MPLYJMPTBLSIZ] = {0};
COMMON_DATA struct CgbChannel gCgbChans[4] = {0};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_SE1 = {0};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_SE2 = {0};
COMMON_DATA struct MusicPlayerTrack gPokemonCryTracks[MAX_POKEMON_CRIES][2] = {0};
COMMON_DATA struct PokemonCrySong gPokemonCrySong = {0};
COMMON_DATA u8 gMPlayMemAccArea[0x10] = {0};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_SE3 = {0};

u32 MidiKeyToFreq(struct WaveData *wav, u8 key, u8 fineAdjust)
{
    u32 val1;
    u32 val2;
    u32 fineAdjustShifted = (u32)fineAdjust << 24;

    if (key > 178)
    {
        key = 178;
        fineAdjustShifted = 0xFF000000;
    }

    val1 = gScaleTable[key];
    val1 = gFreqTable[val1 & 0xF] >> (val1 >> 4);

    val2 = gScaleTable[key + 1];
    val2 = gFreqTable[val2 & 0xF] >> (val2 >> 4);

    return umul3232H32(wav->freq, val1 + umul3232H32(val2 - val1, fineAdjustShifted));
}

void UnusedDummyFunc(void)
{
}

void MPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
    mplayInfo->ident = ID_NUMBER;
}

void MPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->fadeOI = mplayInfo->fadeOC = speed;
    mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
    mplayInfo->ident = ID_NUMBER;
}

void m4aSoundInit(void)
{
    s32 i;

    CpuCopy32((void *)((u32)SoundMainRAM & ~1), SoundMainRAM_Buffer, sizeof(SoundMainRAM_Buffer));

    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(SOUND_MODE_DA_BIT_8
               | SOUND_MODE_FREQ_13379
               | (12 << SOUND_MODE_MASVOL_SHIFT)
               | (5 << SOUND_MODE_MAXCHN_SHIFT));

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
    {
        struct MusicPlayerInfo *mplayInfo = gMPlayTable[i].info;
        MPlayOpen(mplayInfo, gMPlayTable[i].track, gMPlayTable[i].numTracks);
        mplayInfo->usePriority = gMPlayTable[i].usePriority;
        mplayInfo->memAccArea = gMPlayMemAccArea;
    }

    memcpy(&gPokemonCrySong, &gPokemonCrySongTemplate, sizeof(struct PokemonCrySong));

    for (i = 0; i < MAX_POKEMON_CRIES; i++)
    {
        MPlayOpen(&gPokemonCryMusicPlayers[i], gPokemonCryTracks[i], 2);
        gPokemonCryTracks[i]->chan = 0;
    }
}

void m4aSoundMain(void)
{
    SoundMain();
}

void m4aSongNumStart(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    MPlayStart(mplay->info, song->header);
}

void m4aSongNumStartOrChange(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader != song->header)
    {
        MPlayStart(mplay->info, song->header);
    }
    else
    {
        if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0
         || (mplay->info->status & MUSICPLAYER_STATUS_PAUSE))
        {
            MPlayStart(mplay->info, song->header);
        }
    }
}

void m4aSongNumStartOrContinue(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader != song->header)
        MPlayStart(mplay->info, song->header);
    else if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0)
        MPlayStart(mplay->info, song->header);
    else if (mplay->info->status & MUSICPLAYER_STATUS_PAUSE)
        MPlayContinue(mplay->info);
}

void m4aSongNumStop(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader == song->header)
        m4aMPlayStop(mplay->info);
}

void m4aSongNumContinue(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader == song->header)
        MPlayContinue(mplay->info);
}

void m4aMPlayAllStop(void)
{
    s32 i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        m4aMPlayStop(gMPlayTable[i].info);

    for (i = 0; i < MAX_POKEMON_CRIES; i++)
        m4aMPlayStop(&gPokemonCryMusicPlayers[i]);
}

void m4aMPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    MPlayContinue(mplayInfo);
}

void m4aMPlayAllContinue(void)
{
    s32 i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        MPlayContinue(gMPlayTable[i].info);

    for (i = 0; i < MAX_POKEMON_CRIES; i++)
        MPlayContinue(&gPokemonCryMusicPlayers[i]);
}

void m4aMPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    MPlayFadeOut(mplayInfo, speed);
}

void m4aMPlayFadeOutTemporarily(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident++;
    mplayInfo->fadeOC = speed;
    mplayInfo->fadeOI = speed;
    mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT) | TEMPORARY_FADE;
    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->fadeOC = speed;
    mplayInfo->fadeOI = speed;
    mplayInfo->fadeOV = (0 << FADE_VOL_SHIFT) | FADE_IN;
    mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayImmInit(struct MusicPlayerInfo *mplayInfo)
{
    s32 trackCount;
    struct MusicPlayerTrack *track;

    for (trackCount = mplayInfo->trackCount, track = mplayInfo->tracks; trackCount > 0; trackCount--, track++)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 64;
                track->lfoSpeed = 22;
                track->tone.type = 1;
            }
        }
    }
}

void MPlayExtender(struct CgbChannel *cgbChans)
{
    struct SoundInfo *soundInfo;
    u32 ident;

    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE
                   | SOUND_4_ON
                   | SOUND_3_ON
                   | SOUND_2_ON
                   | SOUND_1_ON;
    REG_SOUNDCNT_L = 0; // set master volume to zero
    REG_NR12 = 0x8;
    REG_NR22 = 0x8;
    REG_NR42 = 0x8;
    REG_NR14 = 0x80;
    REG_NR24 = 0x80;
    REG_NR44 = 0x80;
    REG_NR30 = 0;
    REG_NR50 = 0x77;

    soundInfo = SOUND_INFO_PTR;

    ident = soundInfo->ident;

    if (ident != ID_NUMBER)
        return;

    soundInfo->ident++;

#if __STDC_VERSION__ < 202311L
    gMPlayJumpTable[8] = ply_memacc;
    gMPlayJumpTable[17] = ply_lfos;
    gMPlayJumpTable[19] = ply_mod;
    gMPlayJumpTable[28] = ply_xcmd;
    gMPlayJumpTable[29] = ply_endtie;
    gMPlayJumpTable[30] = SampleFreqSet;
    gMPlayJumpTable[31] = TrackStop;
    gMPlayJumpTable[32] = FadeOutBody;
    gMPlayJumpTable[33] = TrkVolPitSet;
#else
    gMPlayJumpTable[8] = (void (*)(...))ply_memacc;
    gMPlayJumpTable[17] = (void (*)(...))ply_lfos;
    gMPlayJumpTable[19] = (void (*)(...))ply_mod;
    gMPlayJumpTable[28] = (void (*)(...))ply_xcmd;
    gMPlayJumpTable[29] = (void (*)(...))ply_endtie;
    gMPlayJumpTable[30] = (void (*)(...))SampleFreqSet;
    gMPlayJumpTable[31] = (void (*)(...))TrackStop;
    gMPlayJumpTable[32] = (void (*)(...))FadeOutBody;
    gMPlayJumpTable[33] = (void (*)(...))TrkVolPitSet;
#endif

    soundInfo->cgbChans = cgbChans;
    soundInfo->CgbSound = CgbSound;
    soundInfo->CgbOscOff = CgbOscOff;
    soundInfo->MidiKeyToCgbFreq = MidiKeyToCgbFreq;
    soundInfo->maxLines = MAX_LINES;

    CpuFill32(0, cgbChans, sizeof(struct CgbChannel) * 4);

    cgbChans[0].type = 1;
    cgbChans[0].panMask = 0x11;
    cgbChans[1].type = 2;
    cgbChans[1].panMask = 0x22;
    cgbChans[2].type = 3;
    cgbChans[2].panMask = 0x44;
    cgbChans[3].type = 4;
    cgbChans[3].panMask = 0x88;

    soundInfo->ident = ident;
}

void MusicPlayerJumpTableCopy(void)
{
    asm("swi 0x2A");
}

void ClearChain(void *x)
{
#if __STDC_VERSION__ < 202311L
    void (*func)(void *) = *(gMPlayJumpTable + 34);
#else
    void (*func)(...) = *(gMPlayJumpTable + 34);
#endif
    func(x);
}

void Clear64byte(void *x)
{
#if __STDC_VERSION__ < 202311L
    void (*func)(void *) = *(gMPlayJumpTable + 35);
#else
    void (*func)(...) = *(gMPlayJumpTable + 35);
#endif
    func(x);
}

void SoundInit(struct SoundInfo *soundInfo)
{
    soundInfo->ident = 0;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE
                   | SOUND_4_ON
                   | SOUND_3_ON
                   | SOUND_2_ON
                   | SOUND_1_ON;
    REG_SOUNDCNT_H = SOUND_B_FIFO_RESET | SOUND_B_TIMER_0 | SOUND_B_LEFT_OUTPUT
                   | SOUND_A_FIFO_RESET | SOUND_A_TIMER_0 | SOUND_A_RIGHT_OUTPUT
                   | SOUND_ALL_MIX_FULL;
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;

    REG_DMA1SAD = (u32)soundInfo->pcmBuffer;
    REG_DMA1DAD = (u32)&REG_FIFO_A;
    REG_DMA2SAD = (u32)soundInfo->pcmBuffer + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = (u32)&REG_FIFO_B;

    SOUND_INFO_PTR = soundInfo;
    CpuFill32(0, soundInfo, sizeof(struct SoundInfo));

    soundInfo->maxChans = 8;
    soundInfo->masterVolume = 15;
    soundInfo->plynote = ply_note;
    soundInfo->CgbSound = DummyFunc;
    soundInfo->CgbOscOff = (CgbOscOffFunc)DummyFunc;
    soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)DummyFunc;
    soundInfo->ExtVolPit = (ExtVolPitFunc)DummyFunc;

    MPlayJumpTableCopy(gMPlayJumpTable);

    soundInfo->MPlayJumpTable = gMPlayJumpTable;

    SampleFreqSet(SOUND_MODE_FREQ_13379);

    soundInfo->ident = ID_NUMBER;
}

void SampleFreqSet(u32 freq)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    freq = (freq & SOUND_MODE_FREQ) >> SOUND_MODE_FREQ_SHIFT;

    soundInfo->freq = freq;
    soundInfo->pcmSamplesPerVBlank = gPcmSamplesPerVBlankTable[freq - 1];
    soundInfo->pcmDmaPeriod = PCM_DMA_BUF_SIZE / soundInfo->pcmSamplesPerVBlank;

    // LCD refresh rate 59.7275Hz
    soundInfo->pcmFreq = (597275 * soundInfo->pcmSamplesPerVBlank + 5000) / 10000;

    // CPU frequency 16.78Mhz
    soundInfo->divFreq = (16777216 / soundInfo->pcmFreq + 1) >> 1;

    // Turn off timer 0.
    REG_TM0CNT_H = 0;

    // cycles per LCD fresh 280896
    REG_TM0CNT_L = -(280896 / soundInfo->pcmSamplesPerVBlank);

    m4aSoundVSyncOn();

    while (*(vu8 *)REG_ADDR_VCOUNT == 159)
        ;

    while (*(vu8 *)REG_ADDR_VCOUNT != 159)
        ;

    REG_TM0CNT_H = TIMER_ENABLE | TIMER_1CLK;
}

void m4aSoundMode(u32 mode)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u32 temp;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    if ((temp = mode & (SOUND_MODE_REVERB_SET | SOUND_MODE_REVERB_VAL)) != 0)
        soundInfo->reverb = temp & SOUND_MODE_REVERB_VAL;

    if ((temp = mode & SOUND_MODE_MAXCHN) != 0)
    {
        struct SoundChannel *chan;

        soundInfo->maxChans = (u8)(temp >> SOUND_MODE_MAXCHN_SHIFT);
        for (temp = MAX_DIRECTSOUND_CHANNELS, chan = soundInfo->chans; temp > 0; temp--, chan++)
            chan->statusFlags = 0;
    }

    if ((temp = mode & SOUND_MODE_MASVOL) != 0)
        soundInfo->masterVolume = (u8)(temp >> SOUND_MODE_MASVOL_SHIFT);

    if ((temp = mode & SOUND_MODE_DA_BIT) != 0)
    {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }

    if ((temp = mode & SOUND_MODE_FREQ) != 0)
    {
        m4aSoundVSyncOff();
        SampleFreqSet(temp);
    }

    soundInfo->ident = ID_NUMBER;
}

void SoundClear(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    s32 i;
    union {
        struct SoundChannel *ds;
        struct CgbChannel *cgb;
    } chan;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    for (i = MAX_DIRECTSOUND_CHANNELS, chan.ds = soundInfo->chans; i > 0; i--, chan.ds++)
        chan.ds->statusFlags = 0;

    chan.cgb = soundInfo->cgbChans;

    if (chan.cgb != NULL)
    {
        for (i = 1; i <= 4; i++, chan.cgb++)
        {
            soundInfo->CgbOscOff(i);
            chan.cgb->statusFlags = 0;
        }
    }

    soundInfo->ident = ID_NUMBER;
}

void m4aSoundVSyncOff(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    if (soundInfo->ident < ID_NUMBER || soundInfo->ident > ID_NUMBER + 1)
        return;

    soundInfo->ident += 10;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT =
            ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT =
            ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;

    CpuFill32(0, soundInfo->pcmBuffer, sizeof(soundInfo->pcmBuffer));
}

void m4aSoundVSyncOn(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u32 ident = soundInfo->ident;

    if (ident == ID_NUMBER)
        return;

    REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
    REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;

    soundInfo->pcmDmaCounter = 0;
    soundInfo->ident = ident - 10;
}

void MPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks, u8 trackCount)
{
    struct SoundInfo *soundInfo;

    if (trackCount == 0)
        return;

    if (trackCount > MAX_MUSICPLAYER_TRACKS)
        trackCount = MAX_MUSICPLAYER_TRACKS;

    soundInfo = SOUND_INFO_PTR;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    Clear64byte(mplayInfo);

    mplayInfo->tracks = tracks;
    mplayInfo->trackCount = trackCount;
    mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;

    for (; trackCount != 0; trackCount--, tracks++)
        tracks->flags = 0;

    // append music player and MPlayMain to linked list
    if (soundInfo->MPlayMainHead != NULL)
    {
        mplayInfo->MPlayMainNext = soundInfo->MPlayMainHead;
        mplayInfo->musicPlayerNext = soundInfo->musicPlayerHead;
        // Clear the previous callback before installing the new list head.
        soundInfo->MPlayMainHead = NULL;
    }

    soundInfo->musicPlayerHead = mplayInfo;
    soundInfo->MPlayMainHead = MPlayMain;
    soundInfo->ident = ID_NUMBER;
    mplayInfo->ident = ID_NUMBER;
}

void MPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader)
{
    s32 i;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    // The SE1/SE2 players don't cut off a song that's still
    // playing for one of lower priority.
    if (mplayInfo->usePriority)
    {
        if ((mplayInfo->songHeader && (mplayInfo->tracks[0].flags & MPT_FLG_START))
         || ((mplayInfo->status & MUSICPLAYER_STATUS_TRACK) && !(mplayInfo->status & MUSICPLAYER_STATUS_PAUSE)))
        {
            if (mplayInfo->priority > songHeader->priority)
                return;
        }
    }

    mplayInfo->ident++;
    mplayInfo->status = 0;
    mplayInfo->songHeader = songHeader;
    mplayInfo->tone = songHeader->tone;
    mplayInfo->priority = songHeader->priority;
    mplayInfo->clock = 0;
    mplayInfo->tempoI = mplayInfo->tempoD = TEMPOBASE;
    mplayInfo->tempoU = 0x100;
    mplayInfo->tempoC = 0;
    mplayInfo->fadeOI = 0;

    for (i = 0, track = mplayInfo->tracks; i < songHeader->trackCount && i < mplayInfo->trackCount; i++, track++)
    {
        TrackStop(mplayInfo, track);
        track->flags = MPT_FLG_EXIST | MPT_FLG_START;
        track->chan = 0;
        track->cmdPtr = songHeader->part[i];
    }

    for (; i < mplayInfo->trackCount; i++, track++)
    {
        TrackStop(mplayInfo, track);
        track->flags = 0;
    }

    if (songHeader->reverb & SOUND_MODE_REVERB_SET)
        m4aSoundMode(songHeader->reverb);

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks; i > 0; i--, track++)
        TrackStop(mplayInfo, track);

    mplayInfo->ident = ID_NUMBER;
}

void FadeOutBody(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    struct MusicPlayerTrack *track;

    if (mplayInfo->fadeOI == 0)
        return;
    if (--mplayInfo->fadeOC != 0)
        return;

    mplayInfo->fadeOC = mplayInfo->fadeOI;

    if (mplayInfo->fadeOV & FADE_IN)
    {
        if ((u16)(mplayInfo->fadeOV += (4 << FADE_VOL_SHIFT)) >= (64 << FADE_VOL_SHIFT))
        {
            mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
            mplayInfo->fadeOI = 0;
        }
    }
    else
    {
        if ((s16)(mplayInfo->fadeOV -= (4 << FADE_VOL_SHIFT)) <= 0)
        {
            for (i = mplayInfo->trackCount, track = mplayInfo->tracks; i > 0; i--, track++)
            {
                TrackStop(mplayInfo, track);

                if (!(mplayInfo->fadeOV & TEMPORARY_FADE))
                    track->flags = 0;
            }

            if (mplayInfo->fadeOV & TEMPORARY_FADE)
                mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;
            else
                mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;

            mplayInfo->fadeOI = 0;
            return;
        }
    }

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks; i > 0; i--, track++)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            track->volX = (mplayInfo->fadeOV >> FADE_VOL_SHIFT);
            track->flags |= MPT_FLG_VOLCHG;
        }
    }
}

void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    s32 bend;
    u32 x;
    if (track->flags & MPT_FLG_VOLSET)
    {
        x = ((u32)track->vol * track->volX) >> 5;

        if (track->modT == MOD_TRE)
            x = (x * (track->modM + 128)) >> 7;

        bend = (track->pan << 1) + track->panX;

        if (track->modT == MOD_PAN)
            bend += track->modM;

        if (bend < -128)
            bend = -128;
        else if (bend > 127)
            bend = 127;

        track->volMR = (x * (bend + 128)) >> 8;
        track->volML = (x * (127 - bend)) >> 8;
    }

    if (track->flags & MPT_FLG_PITSET)
    {
        bend = ((track->bend * track->bendRange) << 2)
             + (track->tune << 2) + (track->keyShift << 8)
             + (track->keyShiftX << 8) + track->pitX;

        if (track->modT == MOD_VIB)
            bend += track->modM << 4;

        track->keyM = bend >> 8;
        track->pitM = (u8)bend;
    }

    track->flags &= ~(MPT_FLG_PITSET | MPT_FLG_VOLSET);
}

u32 MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust)
{
    s32 val1, val2;
    if (chanNum == 4)
    {
        if (key <= 20)
        {
            key = 0;
        }
        else
        {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return gNoiseTable[key];
    }

    if (key <= 35)
    {
        fineAdjust = 0;
        key = 0;
    }
    else
    {
        key -= 36;
        if (key > 130)
        {
            key = 130;
            fineAdjust = 255;
        }
    }

    val1 = gCgbScaleTable[key];
    val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);

    val2 = gCgbScaleTable[key + 1];
    val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);

    return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
}

void CgbOscOff(u8 chanNum)
{
    switch (chanNum)
    {
    case 1:
        REG_NR12 = 8;
        REG_NR14 = 0x80;
        break;
    case 2:
        REG_NR22 = 8;
        REG_NR24 = 0x80;
        break;
    case 3:
        REG_NR30 = 0;
        break;
    default:
        REG_NR42 = 8;
        REG_NR44 = 0x80;
    }
}

void CgbModVol(struct CgbChannel *chan)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u32 rightVolume, leftVolume;

    if (!(soundInfo->mode & 1))
    {
        rightVolume = chan->rightVolume;
        leftVolume = chan->leftVolume;
        if ((u8)rightVolume >= (u8)leftVolume)
        {
            if ((u8)rightVolume / 2 >= (u8)leftVolume)
            {
                chan->pan = 0x0F;
                goto hard_pan;
            }
        }
        else if ((u8)leftVolume / 2 >= (u8)rightVolume)
        {
            chan->pan = 0xF0;
            goto hard_pan;
        }
    }

    chan->pan = 0xFF;
    chan->envelopeGoal = chan->leftVolume + chan->rightVolume;
    chan->envelopeGoal /= 16;
    goto sustain_set;

hard_pan:
    chan->envelopeGoal = chan->leftVolume + chan->rightVolume;
    chan->envelopeGoal /= 16;
    if (chan->envelopeGoal > 15)
        chan->envelopeGoal = 15;

sustain_set:
    chan->sustainGoal = (chan->envelopeGoal * chan->sustain + 15) >> 4;
    chan->pan &= chan->panMask;
}

void CgbSound(void)
{
    s32 ch;
    struct CgbChannel *channels;
    s32 prevC15;
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *nrx0ptr;
    vu8 *nrx1ptr;
    vu8 *nrx2ptr;
    vu8 *nrx3ptr;
    vu8 *nrx4ptr;
    s32 envelopeStepTimeAndDir;
    u8 envPhase;
    int dac_pwm_rate;

    if (soundInfo->c15)
        soundInfo->c15--;
    else
        soundInfo->c15 = 14;

    for (ch = 1, channels = soundInfo->cgbChans; ch <= 4; ch++, channels++)
    {
        if (!(channels->statusFlags & SOUND_CHANNEL_SF_ON))
            continue;

        /* 1. determine hardware channel registers */
        switch (ch)
        {
        case 1:
            nrx0ptr = (vu8 *)(REG_ADDR_NR10);
            nrx1ptr = (vu8 *)(REG_ADDR_NR11);
            nrx2ptr = (vu8 *)(REG_ADDR_NR12);
            nrx3ptr = (vu8 *)(REG_ADDR_NR13);
            nrx4ptr = (vu8 *)(REG_ADDR_NR14);
            break;
        case 2:
            nrx0ptr = (vu8 *)(REG_ADDR_NR10 + 1);
            nrx1ptr = (vu8 *)(REG_ADDR_NR21);
            nrx2ptr = (vu8 *)(REG_ADDR_NR22);
            nrx3ptr = (vu8 *)(REG_ADDR_NR23);
            nrx4ptr = (vu8 *)(REG_ADDR_NR24);
            break;
        case 3:
            nrx0ptr = (vu8 *)(REG_ADDR_NR30);
            nrx1ptr = (vu8 *)(REG_ADDR_NR31);
            nrx2ptr = (vu8 *)(REG_ADDR_NR32);
            nrx3ptr = (vu8 *)(REG_ADDR_NR33);
            nrx4ptr = (vu8 *)(REG_ADDR_NR34);
            break;
        default:
            nrx0ptr = (vu8 *)(REG_ADDR_NR30 + 1);
            nrx1ptr = (vu8 *)(REG_ADDR_NR41);
            nrx2ptr = (vu8 *)(REG_ADDR_NR42);
            nrx3ptr = (vu8 *)(REG_ADDR_NR43);
            nrx4ptr = (vu8 *)(REG_ADDR_NR44);
            break;
        }

        prevC15 = soundInfo->c15;
        envelopeStepTimeAndDir = *nrx2ptr;

        /* 2. calculate envelope volume */
        if (channels->statusFlags & SOUND_CHANNEL_SF_START)
        {
            if (channels->statusFlags & SOUND_CHANNEL_SF_STOP)
                goto oscillator_off;

            channels->statusFlags = SOUND_CHANNEL_SF_ENV_ATTACK;
            channels->modify = CGB_CHANNEL_MO_PIT | CGB_CHANNEL_MO_VOL;
            CgbModVol(channels);
            switch (ch)
            {
            case 1:
                *nrx0ptr = channels->sweep;
                // fallthrough
            case 2:
                *nrx1ptr = ((u32)channels->wavePointer << 6) + channels->length;
                goto init_env_step_time_dir;
            case 3:
                if (channels->wavePointer != channels->currentPointer)
                {
                    *nrx0ptr = 0x40;
                    REG_WAVE_RAM0 = channels->wavePointer[0];
                    REG_WAVE_RAM1 = channels->wavePointer[1];
                    REG_WAVE_RAM2 = channels->wavePointer[2];
                    REG_WAVE_RAM3 = channels->wavePointer[3];
                    channels->currentPointer = channels->wavePointer;
                }
                *nrx0ptr = 0;
                *nrx1ptr = channels->length;
                if (channels->length)
                    channels->n4 = 0xC0;
                else
                    channels->n4 = 0x80;
                break;
            default:
                *nrx1ptr = channels->length;
                *nrx3ptr = (u32)channels->wavePointer << 3;
            init_env_step_time_dir:
                envelopeStepTimeAndDir = channels->attack + CGB_NRx2_ENV_DIR_INC;
                if (channels->length)
                    channels->n4 = 0x40;
                else
                    channels->n4 = 0x00;
                break;
            }
            if ((channels->envelopeCounter = channels->attack) != 0)
            {
                channels->envelopeVolume = 0;
                goto envelope_step_complete;
            }
            // skip attack phase if attack is instantaneous (=0)
            goto envelope_decay_start;
        }
        if (channels->statusFlags & SOUND_CHANNEL_SF_IEC)
        {
            if ((s8)(--channels->pseudoEchoLength) <= 0)
            {
            oscillator_off:
                CgbOscOff(ch);
                channels->statusFlags = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        }
        if ((channels->statusFlags & SOUND_CHANNEL_SF_STOP) && (channels->statusFlags & SOUND_CHANNEL_SF_ENV))
        {
            channels->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
            if ((channels->envelopeCounter = channels->release) != 0)
            {
                channels->modify |= CGB_CHANNEL_MO_VOL;
                if (ch != 3)
                    envelopeStepTimeAndDir = channels->release | CGB_NRx2_ENV_DIR_DEC;
                goto envelope_step_complete;
            }
            goto envelope_pseudoecho_start;
        }

    envelope_step_repeat:
        if (channels->envelopeCounter == 0)
        {
            if (ch == 3)
                channels->modify |= CGB_CHANNEL_MO_VOL;

            CgbModVol(channels);
            envPhase = channels->statusFlags & SOUND_CHANNEL_SF_ENV;

            if (envPhase == SOUND_CHANNEL_SF_ENV_RELEASE)
            {
                if ((s8)(--channels->envelopeVolume) <= 0)
                {
                envelope_pseudoecho_start:
                    channels->envelopeVolume = ((channels->envelopeGoal * channels->pseudoEchoVolume) + 0xFF) >> 8;
                    if (channels->envelopeVolume)
                    {
                        channels->statusFlags |= SOUND_CHANNEL_SF_IEC;
                        channels->modify |= CGB_CHANNEL_MO_VOL;
                        if (ch != 3)
                            envelopeStepTimeAndDir = CGB_NRx2_ENV_DIR_INC;
                        goto envelope_complete;
                    }
                    goto oscillator_off;
                }
                channels->envelopeCounter = channels->release;
            }
            else if (envPhase == SOUND_CHANNEL_SF_ENV_SUSTAIN)
            {
            envelope_sustain:
                channels->envelopeVolume = channels->sustainGoal;
                channels->envelopeCounter = 7;
            }
            else if (envPhase == SOUND_CHANNEL_SF_ENV_DECAY)
            {
                if ((s8)(--channels->envelopeVolume) <= (s8)channels->sustainGoal)
                {
                envelope_sustain_start:
                    if (channels->sustain == 0)
                    {
                        channels->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
                        goto envelope_pseudoecho_start;
                    }
                    channels->statusFlags--;
                    channels->modify |= CGB_CHANNEL_MO_VOL;
                    if (ch != 3)
                        envelopeStepTimeAndDir = CGB_NRx2_ENV_DIR_INC;
                    goto envelope_sustain;
                }
                channels->envelopeCounter = channels->decay;
            }
            else
            {
                if (++channels->envelopeVolume >= channels->envelopeGoal)
                {
                envelope_decay_start:
                    channels->statusFlags--;
                    if ((channels->envelopeCounter = channels->decay) != 0)
                    {
                        channels->modify |= CGB_CHANNEL_MO_VOL;
                        channels->envelopeVolume = channels->envelopeGoal;
                        if (ch != 3)
                            envelopeStepTimeAndDir = channels->decay | CGB_NRx2_ENV_DIR_DEC;
                    }
                    else
                    {
                        goto envelope_sustain_start;
                    }
                }
                else
                {
                    channels->envelopeCounter = channels->attack;
                }
            }
        }

    envelope_step_complete:
        // every 15 frames, envelope calculation has to be done twice
        // to keep up with the hardware envelope rate (1/64 s)
        channels->envelopeCounter--;
        if (prevC15 == 0)
        {
            prevC15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        /* 3. apply pitch to HW registers */
        if (channels->modify & CGB_CHANNEL_MO_PIT)
        {
            if (ch < 4 && (channels->type & TONEDATA_TYPE_FIX))
            {
                dac_pwm_rate = REG_SOUNDBIAS_H;

                if (dac_pwm_rate < 0x40)        // if PWM rate = 32768 Hz
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)   // if PWM rate = 65536 Hz
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            // High byte of the frequency goes in the low bits of NRx4.
            *nrx4ptr = channels->n4 = (channels->n4 & 0xC0) + ((u8 *)&channels->frequency)[1];
        }

        /* 4. apply envelope & volume to HW registers */
        if (channels->modify & CGB_CHANNEL_MO_VOL)
        {
            REG_NR51 = (REG_NR51 & ~channels->panMask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = gCgb3Vol[channels->envelopeVolume];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= 0x7f;
                }
            }
            else
            {
                *nrx2ptr = (envelopeStepTimeAndDir & 0xF) + (channels->envelopeVolume << 4);
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->modify = 0;
    }
}

void m4aMPlayTempoControl(struct MusicPlayerInfo *mplayInfo, u16 tempo)
{
    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->tempoU = tempo;
    mplayInfo->tempoI = (mplayInfo->tempoD * mplayInfo->tempoU) >> 8;
    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayVolumeControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u16 volume)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit <<= 1)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->volX = volume / 4;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayPitchControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, s16 pitch)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit <<= 1)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->keyShiftX = pitch >> 8;
                track->pitX = pitch;
                track->flags |= MPT_FLG_PITCHG;
            }
        }
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayPanpotControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, s8 pan)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit <<= 1)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->panX = pan;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }
    }

    mplayInfo->ident = ID_NUMBER;
}

void ClearModM(struct MusicPlayerTrack *track)
{
    track->lfoSpeedC = 0;
    track->modM = 0;

    if (track->modT == MOD_VIB)
        track->flags |= MPT_FLG_PITCHG;
    else
        track->flags |= MPT_FLG_VOLCHG;
}

void m4aMPlayModDepthSet(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u8 modDepth)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit <<= 1)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                if ((track->mod = modDepth) == 0)
                    ClearModM(track);
            }
        }
    }

    mplayInfo->ident = ID_NUMBER;
}

void m4aMPlayLFOSpeedSet(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u8 lfoSpeed)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit <<= 1)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                if ((track->lfoSpeed = lfoSpeed) == 0)
                    ClearModM(track);
            }
        }
    }

    mplayInfo->ident = ID_NUMBER;
}

void ply_memacc(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 op;
    u8 *addr;
    u8 data;

    op = *track->cmdPtr;
    track->cmdPtr++;

    addr = mplayInfo->memAccArea + *track->cmdPtr;
    track->cmdPtr++;

    data = *track->cmdPtr;
    track->cmdPtr++;

    switch (op)
    {
    case 0:
        *addr = data;
        return;
    case 1:
        *addr += data;
        return;
    case 2:
        *addr -= data;
        return;
    case 3:
        *addr = mplayInfo->memAccArea[data];
        return;
    case 4:
        *addr += mplayInfo->memAccArea[data];
        return;
    case 5:
        *addr -= mplayInfo->memAccArea[data];
        return;
    // Conditional jumps: break out of the switch to take the jump,
    // or go to cond_false to skip over the jump target.
    case 6:
        if (*addr == data)
            break;
        goto cond_false;
    case 7:
        if (*addr != data)
            break;
        goto cond_false;
    case 8:
        if (*addr > data)
            break;
        goto cond_false;
    case 9:
        if (*addr >= data)
            break;
        goto cond_false;
    case 10:
        if (*addr <= data)
            break;
        goto cond_false;
    case 11:
        if (*addr < data)
            break;
        goto cond_false;
    case 12:
        if (*addr == mplayInfo->memAccArea[data])
            break;
        goto cond_false;
    case 13:
        if (*addr != mplayInfo->memAccArea[data])
            break;
        goto cond_false;
    case 14:
        if (*addr > mplayInfo->memAccArea[data])
            break;
        goto cond_false;
    case 15:
        if (*addr >= mplayInfo->memAccArea[data])
            break;
        goto cond_false;
    case 16:
        if (*addr <= mplayInfo->memAccArea[data])
            break;
        goto cond_false;
    case 17:
        if (*addr < mplayInfo->memAccArea[data])
            break;
        goto cond_false;
    default:
        return;
    }

    // Condition met: jump, like ply_goto (jump table entry 1).
    (*(gMPlayJumpTable + 1))(mplayInfo, track);
    return;

cond_false:
    track->cmdPtr += 4;
}

void ply_xcmd(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 n = *track->cmdPtr;
    track->cmdPtr++;

    gXcmdTable[n](mplayInfo, track);
}

void ply_xxx(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    gMPlayJumpTable[0](mplayInfo, track);
}

void ply_xwave(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    union { struct WaveData *w; u8 d[4]; } u;

    u.d[0] = *(track->cmdPtr + 0);
    u.d[1] = *(track->cmdPtr + 1);
    u.d[2] = *(track->cmdPtr + 2);
    u.d[3] = *(track->cmdPtr + 3);

    track->tone.wav = u.w;
    track->cmdPtr += 4;
}

void ply_xtype(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.type = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xatta(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.attack = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xdeca(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.decay = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xsust(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.sustain = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xrele(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.release = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xiecv(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->pseudoEchoVolume = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xiecl(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->pseudoEchoLength = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xleng(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.length = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xswee(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.pan_sweep = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xwait(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    union { u16 a; u8 d[2]; } u;

    u.d[0] = *(track->cmdPtr + 0);
    u.d[1] = *(track->cmdPtr + 1);

    if (track->timer < u.a)
    {
        track->timer++;
        track->cmdPtr -= 2;
        track->wait = 1;
    }
    else
    {
        track->timer = 0;
        track->cmdPtr += 2;
    }
}

void ply_xadct(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    union { u32 a; u8 d[4]; } u;

    u.d[0] = *(track->cmdPtr + 0);
    u.d[1] = *(track->cmdPtr + 1);
    u.d[2] = *(track->cmdPtr + 2);
    u.d[3] = *(track->cmdPtr + 3);

    track->sampleOffset = u.a;
    track->cmdPtr += 4;
}

void DummyFunc(void)
{
}

struct MusicPlayerInfo *SetPokemonCryTone(struct ToneData *tone)
{
    u32 maxClock = 0;
    s32 maxClockIndex = 0;
    s32 i;
    struct MusicPlayerInfo *mplayInfo;

    for (i = 0; i < MAX_POKEMON_CRIES; i++)
    {
        struct MusicPlayerTrack *track = &gPokemonCryTracks[i][0];

        if (!track->flags && (!track->chan || track->chan->track != track))
            goto start_song;

        if (maxClock < gPokemonCryMusicPlayers[i].clock)
        {
            maxClock = gPokemonCryMusicPlayers[i].clock;
            maxClockIndex = i;
        }
    }

    i = maxClockIndex;

start_song:
    mplayInfo = &gPokemonCryMusicPlayers[i];
    mplayInfo->ident++;

    gPokemonCrySongs[i] = gPokemonCrySong;

    gPokemonCrySongs[i].tone = tone;
    gPokemonCrySongs[i].part[0] = &gPokemonCrySongs[i].part0;
    gPokemonCrySongs[i].part[1] = &gPokemonCrySongs[i].part1;
    gPokemonCrySongs[i].gotoTarget = (u32)&gPokemonCrySongs[i].cont;

    mplayInfo->ident = ID_NUMBER;

    MPlayStart(mplayInfo, (struct SongHeader *)&gPokemonCrySongs[i]);

    return mplayInfo;
}

void SetPokemonCryVolume(u8 val)
{
    gPokemonCrySong.volumeValue = val & 0x7F;
}

void SetPokemonCryPanpot(s8 val)
{
    gPokemonCrySong.panValue = (val + C_V) & 0x7F;
}

void SetPokemonCryPitch(s16 val)
{
    s16 b = val + 0x80;
    u8 a = gPokemonCrySong.tuneValue2 - gPokemonCrySong.tuneValue;
    gPokemonCrySong.tieKeyValue = (b >> 8) & 0x7F;
    gPokemonCrySong.tuneValue = (b >> 1) & 0x7F;
    gPokemonCrySong.tuneValue2 = (a + ((b >> 1) & 0x7F)) & 0x7F;
}

void SetPokemonCryLength(u16 val)
{
    gPokemonCrySong.length = val;
}

void SetPokemonCryRelease(u8 val)
{
    gPokemonCrySong.releaseValue = val;
}

void SetPokemonCryProgress(u32 val)
{
    gPokemonCrySong.sampleOffsetValue = val;
}

bool32 IsPokemonCryPlaying(struct MusicPlayerInfo *mplayInfo)
{
    struct MusicPlayerTrack *track = mplayInfo->tracks;

    if (track->chan && track->chan->track == track)
        return TRUE;
    else
        return FALSE;
}

void SetPokemonCryChorus(s8 val)
{
    if (val)
    {
        gPokemonCrySong.trackCount = 2;
        gPokemonCrySong.tuneValue2 = (val + gPokemonCrySong.tuneValue) & 0x7F;
    }
    else
    {
        gPokemonCrySong.trackCount = 1;
    }
}

void SetPokemonCryStereo(u32 val)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    if (val)
    {
        REG_SOUNDCNT_H = SOUND_B_TIMER_0 | SOUND_B_LEFT_OUTPUT
                       | SOUND_A_TIMER_0 | SOUND_A_RIGHT_OUTPUT
                       | SOUND_ALL_MIX_FULL;
        soundInfo->mode &= ~1;
    }
    else
    {
        REG_SOUNDCNT_H = SOUND_B_TIMER_0 | SOUND_B_LEFT_OUTPUT | SOUND_B_RIGHT_OUTPUT
                       | SOUND_A_TIMER_0 | SOUND_A_LEFT_OUTPUT | SOUND_A_RIGHT_OUTPUT
                       | SOUND_B_MIX_HALF | SOUND_A_MIX_HALF | SOUND_CGB_MIX_FULL;
        soundInfo->mode |= 1;
    }
}

void SetPokemonCryPriority(u8 val)
{
    gPokemonCrySong.priority = val;
}
