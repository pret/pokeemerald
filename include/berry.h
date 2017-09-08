//
// Created by Scott Norton on 9/8/17.
//

#ifndef POKEEMERALD_BERRY_H
#define POKEEMERALD_BERRY_H

#define NUM_BERRIES 44

extern const u8 *const gBerryTreeFieldObjectGraphicsIdTablePointers[NUM_BERRIES];
extern const struct SpriteFrameImage *const gBerryTreePicTablePointers[NUM_BERRIES];
extern const u8 *const gBerryTreePaletteSlotTablePointers[NUM_BERRIES];

u8 GetStageByBerryTreeId(u8);
u8 GetBerryTypeByBerryTreeId(u8);

#endif //POKEEMERALD_BERRY_H
