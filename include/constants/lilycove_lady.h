#ifndef GUARD_LILYCOVE_LADY_CONSTANTS_H
#define GUARD_LILYCOVE_LADY_CONSTANTS_H

#define LILYCOVE_LADY_QUIZ      0
#define LILYCOVE_LADY_FAVOR     1
#define LILYCOVE_LADY_CONTEST   2
#define LILYCOVE_LADY_COUNT     3

#define LILYCOVE_LADY_STATE_READY       0
#define LILYCOVE_LADY_STATE_COMPLETED   1
#define LILYCOVE_LADY_STATE_PRIZE       2

#define QUIZ_AUTHOR_PLAYER           0
#define QUIZ_AUTHOR_OTHER_PLAYER     1
#define QUIZ_AUTHOR_LADY             2

// Would be redundant with the above set if GF hadn't mixed the order
#define QUIZ_AUTHOR_NAME_LADY            0
#define QUIZ_AUTHOR_NAME_PLAYER          1
#define QUIZ_AUTHOR_NAME_OTHER_PLAYER    2

// TODO use array count macro?    
#define QUIZ_QUESTION_LEN 9       //ARRAY_COUNT(sQuizLadyQuestion#)
#define NUM_QUIZ_QUESTIONS 16     //ARRAY_COUNT(sQuizLadyQuizQuestions)
#define FAVOR_DESCRIPTION_NUM 6   //ARRAY_COUNT(sFavorLadyDescriptions)

#define LILYCOVE_LADY_GIFT_THRESHOLD 5  


#endif
