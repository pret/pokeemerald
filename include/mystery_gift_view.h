#ifndef GUARD_MYSTERY_GIFT_VIEW_H
#define GUARD_MYSTERY_GIFT_VIEW_H

enum {
    NEWS_INPUT_A,
    NEWS_INPUT_B,
    NEWS_INPUT_SCROLL_UP,
    NEWS_INPUT_SCROLL_DOWN,
    NEWS_INPUT_NONE = 0xFF
};

bool32 WonderCard_Init(struct WonderCard * card, struct WonderCardMetadata * metadata);
bool32 WonderNews_Init(const struct WonderNews * news);
s32 WonderCard_Enter(void);
s32 WonderNews_Enter(void);
s32 WonderCard_Exit(bool32 flag);
s32 WonderNews_Exit(bool32 flag);
void WonderCard_Destroy(void);
void WonderNews_Destroy(void);
u32 WonderNews_GetInput(u16 input);
void WonderNews_AddScrollIndicatorArrowPair(void);
void WonderNews_RemoveScrollIndicatorArrowPair(void);

#endif //GUARD_MYSTERY_GIFT_VIEW_H
