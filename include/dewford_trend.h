#ifndef GUARD_DEWFORDTREND_H
#define GUARD_DEWFORDTREND_H

void InitDewfordTrend(void);
void UpdateDewfordTrendPerDay(u16);
void UpdateDewfordTrendPerDay(u16 days);
bool8 sub_81226D8(u16 *a);
void ReceiveEasyChatPairsData(struct EasyChatPair *a, size_t b, u8 unused);


#endif // GUARD_DEWFORDTREND_H
