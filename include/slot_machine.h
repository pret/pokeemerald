#ifndef GUARD_SLOT_MACHINE_H
#define GUARD_SLOT_MACHINE_H

#define NUM_REELS         3
#define REEL_NUM_TAGS     21
#define REEL_TAG_HEIGHT   24
#define SLOT_MACHINE_COUNT 12

// Lucky Flags
#define LUCKY_BIAS_REPLAY     (1 << 0)
#define LUCKY_BIAS_CHERRY     (1 << 1)
#define LUCKY_BIAS_LOTAD      (1 << 2)
#define LUCKY_BIAS_AZURILL    (1 << 3)
#define LUCKY_BIAS_POWER      (1 << 4)
#define LUCKY_BIAS_REELTIME   (1 << 5)
#define LUCKY_BIAS_MIXED_777  (1 << 6)
#define LUCKY_BIAS_777        (1 << 7)

void PlaySlotMachine(u8, void (callback)(void));

#endif // GUARD_SLOT_MACHINE_H
