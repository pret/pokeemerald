#ifndef GUARD_SLOT_MACHINE_H
#define GUARD_SLOT_MACHINE_H

#define REEL_NUM_TAGS 21

// Lucky Flags
#define LUCKY_BIAS_REPLAY     0x0001
#define LUCKY_BIAS_CHERRY     0x0002
#define LUCKY_BIAS_LOTAD      0x0004
#define LUCKY_BIAS_AZURRILL   0x0008
#define LUCKY_BIAS_POWER      0x0010
#define LUCKY_BIAS_REELTIME   0x0020
#define LUCKY_BIAS_MIXED_777  0x0040
#define LUCKY_BIAS_777        0x0080

// Rows
#define SLOT_TOP_ROW          0x0001
#define SLOT_MIDDLE_ROW       0x0002
#define SLOT_BOTTOM_ROW       0x0003



void PlaySlotMachine(u8, void (callback)(void));

#endif // GUARD_SLOT_MACHINE_H
