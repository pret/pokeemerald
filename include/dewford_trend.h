#ifndef GUARD_DEWFORDTREND_H
#define GUARD_DEWFORDTREND_H

void InitDewfordTrend(void);
void UpdateDewfordTrendPerDay(u16 days);
bool8 TrySetTrendyPhrase(u16 *phrase);
void ReceiveDewfordTrendData(struct DewfordTrend *linkedTrends, size_t size, u8 unused);


#endif // GUARD_DEWFORDTREND_H
