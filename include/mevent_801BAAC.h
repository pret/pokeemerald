#ifndef GUARD_MEVENT_801BAAC_H
#define GUARD_MEVENT_801BAAC_H

bool32 InitWonderCardResources(struct WonderCard * r5, struct MEventBuffer_3430_Sub * r6);
bool32 InitWonderNewsResources(const struct WonderNews * a0);
s32 FadeToWonderCardMenu(void);
s32 FadeToWonderNewsMenu(void);
s32 FadeOutFromWonderCard(bool32 flag);
void DestroyWonderCardResources(void);
s32 FadeOutFromWonderNews(bool32 flag);
void DestroyWonderNewsResources(void);
u32 MENews_GetInput(u16 input);
void MENews_AddScrollIndicatorArrowPair(void);
void MENews_RemoveScrollIndicatorArrowPair(void);

#endif //GUARD_MEVENT_801BAAC_H
