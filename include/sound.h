#ifndef GUARD_SOUND_H
#define GUARD_SOUND_H

enum {
    FANFARE_LEVEL_UP,
    FANFARE_HEAL,
    FANFARE_OBTAIN_BADGE,
    FANFARE_OBTAIN_ITEM,
    FANFARE_EVOLVED,
    FANFARE_OBTAIN_TMHM,
    FANFARE_EVOLUTION_INTRO,
    FANFARE_MOVE_DELETED,
    FANFARE_OBTAIN_BERRY,
    FANFARE_AWAKEN_LEGEND,
    FANFARE_SLOTS_JACKPOT,
    FANFARE_SLOTS_WIN,
    FANFARE_TOO_BAD,
    FANFARE_RG_JIGGLYPUFF,
    FANFARE_RG_DEX_RATING,
    FANFARE_RG_OBTAIN_KEY_ITEM,
    FANFARE_RG_CAUGHT_INTRO,
    FANFARE_RG_PHOTO,
    FANFARE_RG_POKE_FLUTE,
    FANFARE_OBTAIN_B_POINTS,
    FANFARE_REGISTER_MATCH_CALL,
    FANFARE_OBTAIN_SYMBOL,
    FANFARE_DP_TV_END,
    FANFARE_DP_OBTAIN_ITEM,
    FANFARE_DP_HEAL,
    FANFARE_DP_OBTAIN_KEY_ITEM,
    FANFARE_DP_OBTAIN_TMHM,
    FANFARE_DP_OBTAIN_BADGE,
    FANFARE_DP_LEVEL_UP,
    FANFARE_DP_OBTAIN_BERRY,
    FANFARE_DP_PARTNER,
    FANFARE_DP_EVOLVED,
    FANFARE_DP_POKETCH,
    FANFARE_DP_MOVE_DELETED,
    FANFARE_DP_ACCESSORY,
    FANFARE_PL_TV_END,
    FANFARE_PL_CLEAR_MINIGAME,
    FANFARE_PL_OBTAIN_ARCADE_POINTS,
    FANFARE_PL_OBTAIN_CASTLE_POINTS,
    FANFARE_PL_OBTAIN_B_POINTS,
    FANFARE_HG_OBTAIN_KEY_ITEM,
    FANFARE_HG_LEVEL_UP,
    FANFARE_HG_HEAL,
    FANFARE_HG_DEX_RATING_1,
    FANFARE_HG_DEX_RATING_2,
    FANFARE_HG_DEX_RATING_3,
    FANFARE_HG_DEX_RATING_4,
    FANFARE_HG_DEX_RATING_5,
    FANFARE_HG_DEX_RATING_6,
    FANFARE_HG_RECEIVE_EGG,
    FANFARE_HG_OBTAIN_ITEM,
    FANFARE_HG_EVOLVED,
    FANFARE_HG_OBTAIN_BADGE,
    FANFARE_HG_OBTAIN_TMHM,
    FANFARE_HG_VOLTORB_FLIP_1,
    FANFARE_HG_VOLTORB_FLIP_2,
    FANFARE_HG_ACCESSORY,
    FANFARE_HG_REGISTER_POKEGEAR,
    FANFARE_HG_OBTAIN_BERRY,
    FANFARE_HG_RECEIVE_POKEMON,
    FANFARE_HG_MOVE_DELETED,
    FANFARE_HG_THIRD_PLACE,
    FANFARE_HG_SECOND_PLACE,
    FANFARE_HG_FIRST_PLACE,
    FANFARE_HG_POKEATHLON_NEW,
    FANFARE_HG_WINNING_POKEATHLON,
    FANFARE_HG_OBTAIN_B_POINTS,
    FANFARE_HG_OBTAIN_ARCADE_POINTS,
    FANFARE_HG_OBTAIN_CASTLE_POINTS,
    FANFARE_HG_CLEAR_MINIGAME,
    FANFARE_HG_PARTNER,
};

void InitMapMusic(void);
void MapMusicMain(void);
void ResetMapMusic(void);
u16 GetCurrentMapMusic(void);
void PlayNewMapMusic(u16 songNum);
void StopMapMusic(void);
void FadeOutMapMusic(u8 speed);
void FadeOutAndPlayNewMapMusic(u16 songNum, u8 speed);
void FadeOutAndFadeInNewMapMusic(u16 songNum, u8 fadeOutSpeed, u8 fadeInSpeed);
void FadeInNewMapMusic(u16 songNum, u8 speed);
bool8 IsNotWaitingForBGMStop(void);
void PlayFanfareByFanfareNum(u8 fanfareNum);
bool8 WaitFanfare(bool8 stop);
void StopFanfareByFanfareNum(u8 fanfareNum);
void PlayFanfare(u16 songNum);
bool8 IsFanfareTaskInactive(void);
void FadeInNewBGM(u16 songNum, u8 speed);
void FadeOutBGMTemporarily(u8 speed);
bool8 IsBGMPausedOrStopped(void);
void FadeInBGM(u8 speed);
void FadeOutBGM(u8 speed);
bool8 IsBGMStopped(void);
void PlayCry1(u16 species, s8 pan);
void PlayCry2(u16 species, s8 pan, s8 volume, u8 priority);
void PlayCry3(u16 species, s8 pan, u8 mode);
void PlayCry4(u16 species, s8 pan, u8 mode);
void PlayCry5(u16 species, u8 mode);
void PlayCry6(u16 species, s8 pan, u8 mode);
void PlayCryInternal(u16 species, s8 pan, s8 volume, u8 priority, u8 mode);
bool8 IsCryFinished(void);
void StopCryAndClearCrySongs(void);
void StopCry(void);
bool8 IsCryPlayingOrClearCrySongs(void);
bool8 IsCryPlaying(void);
void PlayBGM(u16 songNum);
void PlaySE(u16 songNum);
void PlaySE12WithPanning(u16 songNum, s8 pan);
void PlaySE1WithPanning(u16 songNum, s8 pan);
void PlaySE2WithPanning(u16 songNum, s8 pan);
void SE12PanpotControl(s8 pan);
bool8 IsSEPlaying(void);
bool8 IsBGMPlaying(void);
bool8 IsSpecialSEPlaying(void);

#endif // GUARD_SOUND_H
