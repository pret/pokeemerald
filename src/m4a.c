#include <string.h>
#include "gba/m4a_internal.h"

extern const u8 gCgb3Vol[];

#define BSS_CODE __attribute__((section(".bss.code")))

BSS_CODE ALIGNED(4) char SoundMainRAM_Buffer[0x800] = {0};

struct SoundInfo gSoundInfo;
struct PokemonCrySong gPokemonCrySongs[MAX_POKEMON_CRIES];
struct MusicPlayerInfo gPokemonCryMusicPlayers[MAX_POKEMON_CRIES];
MPlayFunc gMPlayJumpTable[36];
struct CgbChannel gCgbChans[4];
struct MusicPlayerTrack gPokemonCryTracks[MAX_POKEMON_CRIES * 2];
struct PokemonCrySong gPokemonCrySong;
struct MusicPlayerInfo gMPlayInfo_BGM;
struct MusicPlayerInfo gMPlayInfo_SE1;
struct MusicPlayerInfo gMPlayInfo_SE2;
struct MusicPlayerInfo gMPlayInfo_SE3;
u8 gMPlayMemAccArea[0x10];

u32 MidiKeyToFreq(struct WaveData *wav, u8 key, u8 fineAdjust)
{
    u32 val1;
    u32 val2;
    u32 fineAdjustShifted = fineAdjust << 24;

    if (key > 178)
    {
        key = 178;
        fineAdjustShifted = 255 << 24;
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
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ID_NUMBER;
    }
}

void MPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aSoundInit(void)
{
    s32 i;

    CpuCopy32((void *)((s32)SoundMainRAM & ~1), SoundMainRAM_Buffer, sizeof(SoundMainRAM_Buffer));

    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(SOUND_MODE_DA_BIT_8
               | SOUND_MODE_FREQ_13379
               | (12 << SOUND_MODE_MASVOL_SHIFT)
               | (5 << SOUND_MODE_MAXCHN_SHIFT));

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
    {
        struct MusicPlayerInfo *mplayInfo = gMPlayTable[i].info;
        MPlayOpen(mplayInfo, gMPlayTable[i].track, gMPlayTable[i].unk_8);
        mplayInfo->unk_B = gMPlayTable[i].unk_A;
        mplayInfo->memAccArea = gMPlayMemAccArea;
    }

    memcpy(&gPokemonCrySong, &gPokemonCrySongTemplate, sizeof(struct PokemonCrySong));

    for (i = 0; i < MAX_POKEMON_CRIES; i++)
    {
        struct MusicPlayerInfo *mplayInfo = &gPokemonCryMusicPlayers[i];
        struct MusicPlayerTrack *track = &gPokemonCryTracks[i * 2];
        MPlayOpen(mplayInfo, track, 2);
        track->chan = 0;
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
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT) | TEMPORARY_FADE;
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (0 << FADE_VOL_SHIFT) | FADE_IN;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayImmInit(struct MusicPlayerInfo *mplayInfo)
{
    s32 trackCount = mplayInfo->trackCount;
    struct MusicPlayerTrack *track = mplayInfo->tracks;

    while (trackCount > 0)
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

        trackCount--;
        track++;
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

    gMPlayJumpTable[8] = ply_memacc;
    gMPlayJumpTable[17] = ply_lfos;
    gMPlayJumpTable[19] = ply_mod;
    gMPlayJumpTable[28] = ply_xcmd;
    gMPlayJumpTable[29] = ply_endtie;
    gMPlayJumpTable[30] = SampleFreqSet;
    gMPlayJumpTable[31] = TrackStop;
    gMPlayJumpTable[32] = FadeOutBody;
    gMPlayJumpTable[33] = TrkVolPitSet;

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
    void (*func)(void *) = *(&gMPlayJumpTable[34]);
    func(x);
}

void Clear64byte(void *x)
{
    void (*func)(void *) = *(&gMPlayJumpTable[35]);
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

    REG_DMA1SAD = (s32)soundInfo->pcmBuffer;
    REG_DMA1DAD = (s32)&REG_FIFO_A;
    REG_DMA2SAD = (s32)soundInfo->pcmBuffer + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = (s32)&REG_FIFO_B;

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

    freq = (freq & 0xF0000) >> 16;
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

    temp = mode & (SOUND_MODE_REVERB_SET | SOUND_MODE_REVERB_VAL);

    if (temp)
        soundInfo->reverb = temp & SOUND_MODE_REVERB_VAL;

    temp = mode & SOUND_MODE_MAXCHN;

    if (temp)
    {
        struct SoundChannel *chan;

        soundInfo->maxChans = temp >> SOUND_MODE_MAXCHN_SHIFT;

        temp = MAX_DIRECTSOUND_CHANNELS;
        chan = &soundInfo->chans[0];

        while (temp != 0)
        {
            chan->statusFlags = 0;
            temp--;
            chan++;
        }
    }

    temp = mode & SOUND_MODE_MASVOL;

    if (temp)
        soundInfo->masterVolume = temp >> SOUND_MODE_MASVOL_SHIFT;

    temp = mode & SOUND_MODE_DA_BIT;

    if (temp)
    {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }

    temp = mode & SOUND_MODE_FREQ;

    if (temp)
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
    void *chan;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    i = MAX_DIRECTSOUND_CHANNELS;
    chan = &soundInfo->chans[0];

    while (i > 0)
    {
        ((struct SoundChannel *)chan)->statusFlags = 0;
        i--;
        chan = (void *)((s32)chan + sizeof(struct SoundChannel));
    }

    chan = soundInfo->cgbChans;

    if (chan)
    {
        i = 1;

        while (i <= 4)
        {
            soundInfo->CgbOscOff(i);
            ((struct CgbChannel *)chan)->statusFlags = 0;
            i++;
            chan = (void *)((s32)chan + sizeof(struct CgbChannel));
        }
    }

    soundInfo->ident = ID_NUMBER;
}

void m4aSoundVSyncOff(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    if (soundInfo->ident >= ID_NUMBER && soundInfo->ident <= ID_NUMBER + 1)
    {
        soundInfo->ident += 10;

        if (REG_DMA1CNT & (DMA_REPEAT << 16))
            REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

        if (REG_DMA2CNT & (DMA_REPEAT << 16))
            REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

        REG_DMA1CNT_H = DMA_32BIT;
        REG_DMA2CNT_H = DMA_32BIT;

        CpuFill32(0, soundInfo->pcmBuffer, sizeof(soundInfo->pcmBuffer));
    }
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

    while (trackCount != 0)
    {
        tracks->flags = 0;
        trackCount--;
        tracks++;
    }

    // append music player and MPlayMain to linked list

    if (soundInfo->MPlayMainHead != NULL)
    {
        mplayInfo->MPlayMainNext = soundInfo->MPlayMainHead;
        mplayInfo->musicPlayerNext = soundInfo->musicPlayerHead;
        // NULL assignment semantically useless, but required for match
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
    u8 unk_B;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    unk_B = mplayInfo->unk_B;

    if (!unk_B
        || ((!mplayInfo->songHeader || !(mplayInfo->tracks[0].flags & MPT_FLG_START))
            && ((mplayInfo->status & MUSICPLAYER_STATUS_TRACK) == 0
                || (mplayInfo->status & MUSICPLAYER_STATUS_PAUSE)))
        || (mplayInfo->priority <= songHeader->priority))
    {
        mplayInfo->ident++;
        mplayInfo->status = 0;
        mplayInfo->songHeader = songHeader;
        mplayInfo->tone = songHeader->tone;
        mplayInfo->priority = songHeader->priority;
        mplayInfo->clock = 0;
        mplayInfo->tempoD = 150;
        mplayInfo->tempoI = 150;
        mplayInfo->tempoU = 0x100;
        mplayInfo->tempoC = 0;
        mplayInfo->fadeOI = 0;

        i = 0;
        track = mplayInfo->tracks;

        while (i < songHeader->trackCount && i < mplayInfo->trackCount)
        {
            TrackStop(mplayInfo, track);
            track->flags = MPT_FLG_EXIST | MPT_FLG_START;
            track->chan = 0;
            track->cmdPtr = songHeader->part[i];
            i++;
            track++;
        }

        while (i < mplayInfo->trackCount)
        {
            TrackStop(mplayInfo, track);
            track->flags = 0;
            i++;
            track++;
        }

        if (songHeader->reverb & SOUND_MODE_REVERB_SET)
            m4aSoundMode(songHeader->reverb);

        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;
    mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;

    while (i > 0)
    {
        TrackStop(mplayInfo, track);
        i--;
        track++;
    }

    mplayInfo->ident = ID_NUMBER;
}

void FadeOutBody(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u16 fadeOV;

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
            i = mplayInfo->trackCount;
            track = mplayInfo->tracks;

            while (i > 0)
            {
                u32 val;

                TrackStop(mplayInfo, track);

                val = TEMPORARY_FADE;
                fadeOV = mplayInfo->fadeOV;
                val &= fadeOV;

                if (!val)
                    track->flags = 0;

                i--;
                track++;
            }

            if (mplayInfo->fadeOV & TEMPORARY_FADE)
                mplayInfo->status |= MUSICPLAYER_STATUS_PAUSE;
            else
                mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;

            mplayInfo->fadeOI = 0;
            return;
        }
    }

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;

    while (i > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            fadeOV = mplayInfo->fadeOV;

            track->volX = (fadeOV >> FADE_VOL_SHIFT);
            track->flags |= MPT_FLG_VOLCHG;
        }

        i--;
        track++;
    }
}

void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    if (track->flags & MPT_FLG_VOLSET)
    {
        s32 x;
        s32 y;

        x = (u32)(track->vol * track->volX) >> 5;

        if (track->modT == 1)
            x = (u32)(x * (track->modM + 128)) >> 7;

        y = 2 * track->pan + track->panX;

        if (track->modT == 2)
            y += track->modM;

        if (y < -128)
            y = -128;
        else if (y > 127)
            y = 127;

        track->volMR = (u32)((y + 128) * x) >> 8;
        track->volML = (u32)((127 - y) * x) >> 8;
    }

    if (track->flags & MPT_FLG_PITSET)
    {
        s32 bend = track->bend * track->bendRange;
        s32 x = (track->tune + bend)
              * 4
              + (track->keyShift << 8)
              + (track->keyShiftX << 8)
              + track->pitX;

        if (track->modT == 0)
            x += 16 * track->modM;

        track->keyM = x >> 8;
        track->pitM = x;
    }

    track->flags &= ~(MPT_FLG_PITSET | MPT_FLG_VOLSET);
}

u32 MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust)
{
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
    else
    {
        s32 val1;
        s32 val2;

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

static inline int CgbPan(struct CgbChannel *chan)
{
    u32 rightVolume = chan->rightVolume;
    u32 leftVolume = chan->leftVolume;

    if ((rightVolume = (u8)rightVolume) >= (leftVolume = (u8)leftVolume))
    {
        if (rightVolume / 2 >= leftVolume)
        {
            chan->pan = 0x0F;
            return 1;
        }
    }
    else
    {
        if (leftVolume / 2 >= rightVolume)
        {
            chan->pan = 0xF0;
            return 1;
        }
    }

    return 0;
}

void CgbModVol(struct CgbChannel *chan)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    if ((soundInfo->mode & 1) || !CgbPan(chan))
    {
        chan->pan = 0xFF;
        chan->envelopeGoal = (u32)(chan->rightVolume + chan->leftVolume) >> 4;
    }
    else
    {
        // Force chan->rightVolume and chan->leftVolume to be read from memory again,
        // even though there is no reason to do so.
        // The command line option "-fno-gcse" achieves the same result as this.
        #ifndef NONMATCHING
            asm("" : : : "memory");
        #endif

        chan->envelopeGoal = (u32)(chan->rightVolume + chan->leftVolume) >> 4;
        if (chan->envelopeGoal > 15)
            chan->envelopeGoal = 15;
    }

    chan->sustainGoal = (chan->envelopeGoal * chan->sustain + 15) >> 4;
    chan->pan &= chan->panMask;
}

void CgbSound(void)
{
    s32 ch;
    struct CgbChannel *channels;
    s32 envelopeStepTimeAndDir;
    s32 prevC15;
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *nrx0ptr;
    vu8 *nrx1ptr;
    vu8 *nrx2ptr;
    vu8 *nrx3ptr;
    vu8 *nrx4ptr;

    // Most comparision operations that cast to s8 perform 'and' by 0xFF.
    int mask = 0xff;

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
            nrx0ptr = (vu8 *)(REG_ADDR_NR10+1);
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
            nrx0ptr = (vu8 *)(REG_ADDR_NR30+1);
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
            if (!(channels->statusFlags & SOUND_CHANNEL_SF_STOP))
            {
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
                channels->envelopeCounter = channels->attack;
                if ((s8)(channels->attack & mask))
                {
                    channels->envelopeVolume = 0;
                    goto envelope_step_complete;
                }
                else
                {
                    // skip attack phase if attack is instantaneous (=0)
                    goto envelope_decay_start;
                }
            }
            else
            {
                goto oscillator_off;
            }
        }
        else if (channels->statusFlags & SOUND_CHANNEL_SF_IEC)
        {
            channels->pseudoEchoLength--;
            if ((s8)(channels->pseudoEchoLength & mask) <= 0)
            {
            oscillator_off:
                CgbOscOff(ch);
                channels->statusFlags = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        }
        else if ((channels->statusFlags & SOUND_CHANNEL_SF_STOP) && (channels->statusFlags & SOUND_CHANNEL_SF_ENV))
        {
            channels->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
            channels->envelopeCounter = channels->release;
            if ((s8)(channels->release & mask))
            {
                channels->modify |= CGB_CHANNEL_MO_VOL;
                if (ch != 3)
                    envelopeStepTimeAndDir = channels->release | CGB_NRx2_ENV_DIR_DEC;
                goto envelope_step_complete;
            }
            else
            {
                goto envelope_pseudoecho_start;
            }
        }
        else
        {
        envelope_step_repeat:
            if (channels->envelopeCounter == 0)
            {
                if (ch == 3)
                    channels->modify |= CGB_CHANNEL_MO_VOL;

                CgbModVol(channels);
                if ((channels->statusFlags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_RELEASE)
                {
                    channels->envelopeVolume--;
                    if ((s8)(channels->envelopeVolume & mask) <= 0)
                    {
                    envelope_pseudoecho_start:
                        channels->envelopeVolume = ((channels->envelopeGoal * channels->pseudoEchoVolume) + 0xFF) >> 8;
                        if (channels->envelopeVolume)
                        {
                            channels->statusFlags |= SOUND_CHANNEL_SF_IEC;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelopeStepTimeAndDir = 0 | CGB_NRx2_ENV_DIR_INC;
                            goto envelope_complete;
                        }
                        else
                        {
                            goto oscillator_off;
                        }
                    }
                    else
                    {
                        channels->envelopeCounter = channels->release;
                    }
                }
                else if ((channels->statusFlags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_SUSTAIN)
                {
                envelope_sustain:
                    channels->envelopeVolume = channels->sustainGoal;
                    channels->envelopeCounter = 7;
                }
                else if ((channels->statusFlags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_DECAY)
                {
                    int envelopeVolume, sustainGoal;

                    channels->envelopeVolume--;
                    envelopeVolume = (s8)(channels->envelopeVolume & mask);
                    sustainGoal = (s8)(channels->sustainGoal);
                    if (envelopeVolume <= sustainGoal)
                    {
                    envelope_sustain_start:
                        if (channels->sustain == 0)
                        {
                            channels->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
                            goto envelope_pseudoecho_start;
                        }
                        else
                        {
                            channels->statusFlags--;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelopeStepTimeAndDir = 0 | CGB_NRx2_ENV_DIR_INC;
                            goto envelope_sustain;
                        }
                    }
                    else
                    {
                        channels->envelopeCounter = channels->decay;
                    }
                }
                else
                {
                    channels->envelopeVolume++;
                    if ((u8)(channels->envelopeVolume & mask) >= channels->envelopeGoal)
                    {
                    envelope_decay_start:
                        channels->statusFlags--;
                        channels->envelopeCounter = channels->decay;
                        if ((u8)(channels->envelopeCounter & mask))
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
                int dac_pwm_rate = REG_SOUNDBIAS_H;

                if (dac_pwm_rate < 0x40)        // if PWM rate = 32768 Hz
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)   // if PWM rate = 65536 Hz
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            channels->n4 = (channels->n4 & 0xC0) + (*((u8*)(&channels->frequency) + 1));
            *nrx4ptr = (s8)(channels->n4 & mask);
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
                envelopeStepTimeAndDir &= 0xf;
                *nrx2ptr = (channels->envelopeVolume << 4) + envelopeStepTimeAndDir;
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
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->ident++;
        mplayInfo->tempoU = tempo;
        mplayInfo->tempoI = (mplayInfo->tempoD * mplayInfo->tempoU) >> 8;
        mplayInfo->ident = ID_NUMBER;
    }
}

void m4aMPlayVolumeControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u16 volume)
{
    s32 i;
    u32 bit;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER)
        return;

    mplayInfo->ident++;

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->volX = volume / 4;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
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

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0)
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

        i--;
        track++;
        bit <<= 1;
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

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->panX = pan;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

void ClearModM(struct MusicPlayerTrack *track)
{
    track->lfoSpeedC = 0;
    track->modM = 0;

    if (track->modT == 0)
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

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->mod = modDepth;

                if (!track->mod)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
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

    i = mplayInfo->trackCount;
    track = mplayInfo->tracks;
    bit = 1;

    while (i > 0)
    {
        if (trackBits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->lfoSpeed = lfoSpeed;

                if (!track->lfoSpeed)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    mplayInfo->ident = ID_NUMBER;
}

#define MEMACC_COND_JUMP(cond) \
if (cond)                      \
    goto cond_true;            \
else                           \
    goto cond_false;           \

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
    case 6:
        MEMACC_COND_JUMP(*addr == data)
        return;
    case 7:
        MEMACC_COND_JUMP(*addr != data)
        return;
    case 8:
        MEMACC_COND_JUMP(*addr > data)
        return;
    case 9:
        MEMACC_COND_JUMP(*addr >= data)
        return;
    case 10:
        MEMACC_COND_JUMP(*addr <= data)
        return;
    case 11:
        MEMACC_COND_JUMP(*addr < data)
        return;
    case 12:
        MEMACC_COND_JUMP(*addr == mplayInfo->memAccArea[data])
        return;
    case 13:
        MEMACC_COND_JUMP(*addr != mplayInfo->memAccArea[data])
        return;
    case 14:
        MEMACC_COND_JUMP(*addr > mplayInfo->memAccArea[data])
        return;
    case 15:
        MEMACC_COND_JUMP(*addr >= mplayInfo->memAccArea[data])
        return;
    case 16:
        MEMACC_COND_JUMP(*addr <= mplayInfo->memAccArea[data])
        return;
    case 17:
        MEMACC_COND_JUMP(*addr < mplayInfo->memAccArea[data])
        return;
    default:
        return;
    }

cond_true:
    {
        // *& is required for matching
        (*&gMPlayJumpTable[1])(mplayInfo, track);
        return;
    }

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

#define READ_XCMD_BYTE(var, n)       \
{                                    \
    u32 byte = track->cmdPtr[(n)]; \
    byte <<= n * 8;                  \
    (var) &= ~(0xFF << (n * 8));     \
    (var) |= byte;                   \
}

void ply_xwave(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 wav;

    READ_XCMD_BYTE(wav, 0) // UB: uninitialized variable
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (struct WaveData *)wav;
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

void ply_xcmd_0C(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 unk;

    READ_XCMD_BYTE(unk, 0) // UB: uninitialized variable
    READ_XCMD_BYTE(unk, 1)

    if (track->unk_3A < (u16)unk)
    {
        track->unk_3A++;
        track->cmdPtr -= 2;
        track->wait = 1;
    }
    else
    {
        track->unk_3A = 0;
        track->cmdPtr += 2;
    }
}

void ply_xcmd_0D(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 unk;

    READ_XCMD_BYTE(unk, 0) // UB: uninitialized variable
    READ_XCMD_BYTE(unk, 1)
    READ_XCMD_BYTE(unk, 2)
    READ_XCMD_BYTE(unk, 3)

    track->unk_3C = unk;
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
        struct MusicPlayerTrack *track = &gPokemonCryTracks[i * 2];

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

#define CRY ((s32)&gPokemonCrySongs + i * sizeof(struct PokemonCrySong))
#define CRY_OFS(field) offsetof(struct PokemonCrySong, field)

    memcpy((void *)CRY, &gPokemonCrySong, sizeof(struct PokemonCrySong));

    *(u32 *)(CRY + CRY_OFS(tone)) = (u32)tone;
    *(u32 *)(CRY + CRY_OFS(part)) = CRY + CRY_OFS(part0);
    *(u32 *)(CRY + CRY_OFS(part) + 4) = CRY + CRY_OFS(part1);
    *(u32 *)(CRY + CRY_OFS(gotoTarget)) = CRY + CRY_OFS(cont);

#undef CRY_OFS
#undef CRY

    mplayInfo->ident = ID_NUMBER;

    MPlayStart(mplayInfo, (struct SongHeader *)(&gPokemonCrySongs[i]));

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
    gPokemonCrySong.unkCmd0CParam = val;
}

void SetPokemonCryRelease(u8 val)
{
    gPokemonCrySong.releaseValue = val;
}

void SetPokemonCryProgress(u32 val)
{
    gPokemonCrySong.unkCmd0DParam = val;
}

int IsPokemonCryPlaying(struct MusicPlayerInfo *mplayInfo)
{
    struct MusicPlayerTrack *track = mplayInfo->tracks;

    if (track->chan && track->chan->track == track)
        return 1;
    else
        return 0;
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
