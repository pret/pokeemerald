#ifndef GUARD_MEVENT_NEWS_H
#define GUARD_MEVENT_NEWS_H

enum {
    WONDER_NEWS_NONE,
    WONDER_NEWS_RECV_FRIEND,
    WONDER_NEWS_RECV_WIRELESS,
    WONDER_NEWS_SENT,
};


void InitSavedWonderNews(void);
void GenerateRandomWonderNews(u32 newsType);

#endif //GUARD_MEVENT_NEWS_H
