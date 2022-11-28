#ifndef GUARD_LILYCOVE_LADY_CONSTANTS_H
#define GUARD_LILYCOVE_LADY_CONSTANTS_H

#define LILYCOVE_LADY_QUIZ      0
#define LILYCOVE_LADY_FAVOR     1
#define LILYCOVE_LADY_CONTEST   2
#define LILYCOVE_LADY_COUNT     3

#define LILYCOVE_LADY_STATE_READY       0
#define LILYCOVE_LADY_STATE_COMPLETED   1
#define LILYCOVE_LADY_STATE_PRIZE       2

#define LILYCOVE_LADY_GIFT_THRESHOLD    5

#define QUIZ_AUTHOR_PLAYER           0
#define QUIZ_AUTHOR_OTHER_PLAYER     1
#define QUIZ_AUTHOR_LADY             2

// Would be redundant with the above set if GF hadn't mixed the order
#define QUIZ_AUTHOR_NAME_LADY            0
#define QUIZ_AUTHOR_NAME_PLAYER          1
#define QUIZ_AUTHOR_NAME_OTHER_PLAYER    2

// Constants for how many good Pokéblocks the Contest Lady was given
// This determines how her performance is described when her TV show comes on
#define CONTEST_LADY_NORMAL 0
#define CONTEST_LADY_GOOD   1
#define CONTEST_LADY_BAD    2

#endif // GUARD_LILYCOVE_LADY_CONSTANTS_H
