#ifndef GUARD_FIELD_SCREEN_EFFECT_H
#define GUARD_FIELD_SCREEN_EFFECT_H

void pal_fill_for_maplights(void);
void pal_fill_black(void);
void WarpFadeScreen(void);
void sub_80AF128(void);
void FieldCallback_ReturnToEventScript2(void);
void sub_80AF188(void);
void sub_80AF214(void);
void sub_80AF2B4(u8 taskId);
void sub_80AF314(void);
void mapldr_default(void);
void sub_80AF3B0(void);
void sub_80AF3C8(void);
void sub_80AF3E8(void);
void sub_80AF40C(void);
void sub_80AF688(void);
bool8 sub_80AF6A4(void);
void sub_80AF6D4(void);
void sub_80AF6F0(void);
void DoWarp(void);
void DoDiveWarp(void);
void sub_80AF79C(void);
void DoDoorWarp(void);
void DoFallWarp(void);
void sub_80AF80C(u8 metatileBehavior);
void sub_80AF828(void);
void sub_80AF838(void);
void sub_80AF848(void);
void DoMossdeepGymWarp(void);
void sub_80AF8B8(void);
void sub_80AF948(void);
void sub_80AF9F8(void);
void DoContestHallWarp(void);
void AnimateFlash(u8 flashLevel);
void WriteBattlePyramidViewScanlineEffectBuffer(void);
void sub_80B0244(void);
void sub_80B0268(void);
void DoOrbEffect(void);
void FadeOutOrbEffect(void);
void sub_80B05B4(void);
void WriteFlashScanlineEffectBuffer(u8 flashLevel);
bool8 walkrun_is_standing_still(void);

#endif // GUARD_FIELD_SCREEN_EFFECT_H
