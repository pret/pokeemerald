#ifndef GUARD_RECORD_MIXING_H
#define GUARD_RECORD_MIXING_H

struct PlayerHallRecords
{
    struct RankingHall1P onePlayer[9][2];
    struct RankingHall2P twoPlayers[2];
};

void RecordMixingPlayerSpotTriggered(void);
void GetPlayerHallRecords(struct PlayerHallRecords *dst);

#endif //GUARD_RECORD_MIXING_H
