#ifndef GUARD_ITEM_CONSTANTS_H
#define GUARD_ITEM_CONSTANTS_H

// These constants are used in gItems
#define POCKET_NONE        0
#define POCKET_ITEMS       1
#define POCKET_POKE_BALLS  2
#define POCKET_TM_HM       3
#define POCKET_BERRIES     4
#define POCKET_KEY_ITEMS   5

#define ITEMS_POCKET       0
#define BALLS_POCKET       1
#define TMHM_POCKET        2
#define BERRIES_POCKET     3
#define KEYITEMS_POCKET    4
#define POCKETS_COUNT      5

// The TM/HM pocket is the largest pocket, so the maximum amount of items
// in a pocket is its count + 1 for the cancel option
#define MAX_POCKET_ITEMS   (BAG_TMHM_COUNT + 1)


#endif // GUARD_ITEM_CONSTANTS_H
