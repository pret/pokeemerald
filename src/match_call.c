
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"

#define NELEMS(a) (s32)( sizeof (a) / sizeof (*(a)) )

extern const u8 gTrainerClassNames[][13];

// Static type declarations

typedef struct MatchCallSusbtruct0 {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_sub0_t;

struct MatchCallStructCommon {
    u8 type;
    u8 v1;
    u16 flag;
};

struct MatchCallStruct0 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
    const match_call_sub0_t *vC;
};

struct MatchCallStruct1 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *v8;
    const u8 *vC;
    const match_call_sub0_t *v10;
};

struct MatchCallSubstruct2 {
    u16 v0;
    u8 v2;
};

struct MatchCallStruct2 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *v8;
    const match_call_sub0_t *vC;
    const struct MatchCallSubstruct2 *v10;
};

struct MatchCallStruct3 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
};

struct MatchCallStruct4 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
    const match_call_sub0_t *vC;
};

struct MatchCallStruct5 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *v8;
    const u8 *vC;
    const match_call_sub0_t *v10;
};

#define MATCHCALLDEF(name, type_, ...) \
const struct MatchCallStruct##type_ name = { \
    .type = type_, \
    __VA_ARGS__ \
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStruct0 *type0;
    const struct MatchCallStruct1 *type1;
    const struct MatchCallStruct2 *type2;
    const struct MatchCallStruct3 *type3;
    const struct MatchCallStruct4 *type4;
    const struct MatchCallStruct5 *type5;
} match_call_t;

struct UnkStruct_08625388 {
    u16 idx;
    u16 v2;
    u16 v4;
    const u8 *v8[4];
};

// Static RAM declarations

// Static ROM declarations

bool32 sub_81D1628(match_call_t);
bool32 sub_81D164C(match_call_t);
bool32 sub_81D1670(match_call_t);
bool32 sub_81D1694(match_call_t);
bool32 sub_81D16CC(match_call_t);

u8 sub_81D1714(match_call_t);
u8 sub_81D1718(match_call_t);
u8 sub_81D171C(match_call_t);
u8 sub_81D1750(match_call_t);
u8 sub_81D1754(match_call_t);

bool32 sub_81D178C(match_call_t);
bool32 sub_81D1790(match_call_t);
bool32 sub_81D17C0(match_call_t);
bool32 sub_81D17E0(match_call_t);
bool32 sub_81D17E4(match_call_t);

bool32 sub_81D1840(match_call_t);
bool32 sub_81D1844(match_call_t);
bool32 sub_81D1848(match_call_t);
bool32 sub_81D184C(match_call_t);
bool32 sub_81D1850(match_call_t);

u32 sub_81D1888(match_call_t);
u32 sub_81D188C(match_call_t);
u32 sub_81D1890(match_call_t);
u32 sub_81D1894(match_call_t);
u32 sub_81D1898(match_call_t);

void sub_81D18D0(match_call_t, u8 *);
void sub_81D18DC(match_call_t, u8 *);
void sub_81D18FC(match_call_t, u8 *);
void sub_81D1908(match_call_t, u8 *);
void sub_81D1914(match_call_t, u8 *);

void sub_81D1AB0(match_call_t, const u8 **, const u8 **);
void sub_81D1ABC(match_call_t, const u8 **, const u8 **);
void sub_81D1ADC(match_call_t, const u8 **, const u8 **);
void sub_81D1AF4(match_call_t, const u8 **, const u8 **);
void sub_81D1B00(match_call_t, const u8 **, const u8 **);

void sub_81D1920(const match_call_sub0_t *, u8 *);
void sub_81D199C(const match_call_sub0_t *, u16, u8 *);
void sub_8197080(u8 *);
void sub_81D1B0C(u32, const u8 **, const u8 **);

extern const u8 gText_MrStone_Pokenav_2B60C0[];
extern const u8 gText_MrStone_Pokenav_2B61E6[];
extern const u8 gText_MrStone_Pokenav_2B6302[];
extern const u8 gText_MrStone_Pokenav_2B63A0[];
extern const u8 gText_MrStone_Pokenav_2B64A2[];
extern const u8 gText_MrStone_Pokenav_2B6526[];
extern const u8 gText_MrStone_Pokenav_2B65BB[];
extern const u8 gText_MrStone_Pokenav_2B6664[];
extern const u8 gText_MrStone_Pokenav_2B66B1[];
extern const u8 gText_MrStone_Pokenav_2B6703[];
extern const u8 gText_MrStone_Pokenav_2B67ED[];

extern const u8 gUnknown_085EFAEF[];
extern const u8 gUnknown_085EFAFA[];

extern const u8 gText_Norman_Pokenav_2B5719[];
extern const u8 gText_Norman_Pokenav_2B5795[];
extern const u8 gText_Norman_Pokenav_2B584D[];
extern const u8 gText_Norman_Pokenav_2B58E3[];
extern const u8 gText_Norman_Pokenav_2B5979[];
extern const u8 gText_Norman_Pokenav_2B5A07[];
extern const u8 gText_Norman_Pokenav_2B5A69[];
extern const u8 gText_Norman_Pokenav_2B5ACF[];
extern const u8 gText_Norman_Pokenav_2B5B5E[];

extern const u8 gUnknown_085EFB25[];
extern const u8 gUnknown_085EFB47[];

extern const u8 gUnknown_085EFBC9[];
extern const u8 gUnknown_085E8270[];

extern const u8 gText_Mom_Pokenav_2B227B[];
extern const u8 gText_Mom_Pokenav_2B2310[];
extern const u8 gText_Mom_Pokenav_2B23F3[];

extern const u8 gUnknown_085EFB32[];
extern const u8 gUnknown_085EFB4B[];

extern const u8 gText_Steven_Pokenav_2B5B95[];
extern const u8 gText_Steven_Pokenav_2B5C53[];
extern const u8 gText_Steven_Pokenav_2B5CC9[];
extern const u8 gText_Steven_Pokenav_2B5DB4[];
extern const u8 gText_Steven_Pokenav_2B5E26[];
extern const u8 gText_Steven_Pokenav_2B5EA2[];
extern const u8 gText_Steven_Pokenav_2B5ED9[];

extern const u8 gUnknown_085EFB04[];
extern const u8 gUnknown_085EFB11[];

extern const u8 gText_May_Pokenav_2B3AB3[];
extern const u8 gText_May_Pokenav_2B3B3F[];
extern const u8 gText_May_Pokenav_2B3C13[];
extern const u8 gText_May_Pokenav_2B3CF3[];
extern const u8 gText_May_Pokenav_2B3D4B[];
extern const u8 gText_May_Pokenav_2B3DD1[];
extern const u8 gText_May_Pokenav_2B3E69[];
extern const u8 gText_May_Pokenav_2B3ECD[];
extern const u8 gText_May_Pokenav_2B3F2B[];
extern const u8 gText_May_Pokenav_2B3FFB[];
extern const u8 gText_May_Pokenav_2B402B[];
extern const u8 gText_May_Pokenav_2B414B[];
extern const u8 gText_May_Pokenav_2B4228[];
extern const u8 gText_May_Pokenav_2B42E0[];
extern const u8 gText_May_Pokenav_2B4350[];
extern const u8 gUnknown_085EFB18[];
extern const u8 gExpandedPlaceholder_May[];
extern const u8 gText_Brendan_Pokenav_2B43EF[];
extern const u8 gText_Brendan_Pokenav_2B4486[];
extern const u8 gText_Brendan_Pokenav_2B4560[];
extern const u8 gText_Brendan_Pokenav_2B463F[];
extern const u8 gText_Brendan_Pokenav_2B46B7[];
extern const u8 gText_Brendan_Pokenav_2B4761[];
extern const u8 gText_Brendan_Pokenav_2B47F4[];
extern const u8 gText_Brendan_Pokenav_2B4882[];
extern const u8 gText_Brendan_Pokenav_2B4909[];
extern const u8 gText_Brendan_Pokenav_2B49C4[];
extern const u8 gText_Brendan_Pokenav_2B4A44[];
extern const u8 gText_Brendan_Pokenav_2B4B28[];
extern const u8 gText_Brendan_Pokenav_2B4C15[];
extern const u8 gText_Brendan_Pokenav_2B4CD8[];
extern const u8 gText_Brendan_Pokenav_2B4D46[];
extern const u8 gExpandedPlaceholder_Brendan[];
extern const u8 gText_Wally_Pokenav_2B4DE2[];
extern const u8 gText_Wally_Pokenav_2B4E57[];
extern const u8 gText_Wally_Pokenav_2B4EA5[];
extern const u8 gText_Wally_Pokenav_2B4F41[];
extern const u8 gText_Wally_Pokenav_2B4FF3[];
extern const u8 gText_Wally_Pokenav_2B50B1[];
extern const u8 gText_Wally_Pokenav_2B5100[];
extern const u8 gUnknown_085EFB3E[];
extern const u8 gText_Scott_Pokenav_2B5184[];
extern const u8 gText_Scott_Pokenav_2B5275[];
extern const u8 gText_Scott_Pokenav_2B5323[];
extern const u8 gText_Scott_Pokenav_2B53DB[];
extern const u8 gText_Scott_Pokenav_2B54A5[];
extern const u8 gText_Scott_Pokenav_2B5541[];
extern const u8 gText_Scott_Pokenav_2B56CA[];
extern const u8 gUnknown_085EFB4F[];
extern const u8 gUnknown_085EFB5C[];
extern const u8 gText_Roxanne_Pokenav_2B2456[];
extern const u8 gText_Roxanne_Pokenav_2B250E[];
extern const u8 gText_Roxanne_Pokenav_2B25C1[];
extern const u8 gText_Roxanne_Pokenav_2B2607[];
extern const u8 gUnknown_085EFB62[];
extern const u8 gText_Brawly_Pokenav_2B2659[];
extern const u8 gText_Brawly_Pokenav_2B275D[];
extern const u8 gText_Brawly_Pokenav_2B286F[];
extern const u8 gText_Brawly_Pokenav_2B28D1[];
extern const u8 gUnknown_085EFB6F[];
extern const u8 gText_Wattson_Pokenav_2B2912[];
extern const u8 gText_Wattson_Pokenav_2B29CA[];
extern const u8 gText_Wattson_Pokenav_2B2AB6[];
extern const u8 gText_Wattson_Pokenav_2B2B01[];
extern const u8 gUnknown_085EFB7B[];
extern const u8 gText_Flannery_Pokenav_2B2B4D[];
extern const u8 gText_Flannery_Pokenav_2B2C0E[];
extern const u8 gText_Flannery_Pokenav_2B2CF1[];
extern const u8 gText_Flannery_Pokenav_2B2D54[];
extern const u8 gUnknown_085EFB87[];
extern const u8 gText_Winona_Pokenav_2B2DA4[];
extern const u8 gText_Winona_Pokenav_2B2E2B[];
extern const u8 gText_Winona_Pokenav_2B2EC2[];
extern const u8 gText_Winona_Pokenav_2B2F16[];
extern const u8 gUnknown_085EFB94[];
extern const u8 gText_TateLiza_Pokenav_2B2F97[];
extern const u8 gText_TateLiza_Pokenav_2B306E[];
extern const u8 gText_TateLiza_Pokenav_2B3158[];
extern const u8 gText_TateLiza_Pokenav_2B31CD[];
extern const u8 gUnknown_085EFB9E[];
extern const u8 gText_Juan_Pokenav_2B3249[];
extern const u8 gText_Juan_Pokenav_2B32EC[];
extern const u8 gText_Juan_Pokenav_2B33AA[];
extern const u8 gText_Juan_Pokenav_2B341E[];
extern const u8 gUnknown_085EFBA9[];
extern const u8 gText_Sidney_Pokenav_2B34CC[];
extern const u8 gUnknown_085EFBB5[];
extern const u8 gText_Phoebe_Pokenav_2B3561[];
extern const u8 gText_Glacia_Pokenav_2B35E4[];
extern const u8 gText_Drake_Pokenav_2B368B[];
extern const u8 gText_Wallace_Pokenav_2B3790[];
extern const u8 gUnknown_085EFBC0[];
extern const u8 gUnknown_085ED453[];
extern const u8 gUnknown_085ED46B[];
extern const u8 gUnknown_085ED483[];
extern const u8 gUnknown_085ED49D[];
extern const u8 gUnknown_085ED4B3[];
extern const u8 gUnknown_085ED4CE[];
extern const u8 gUnknown_085ED4E3[];
extern const u8 gUnknown_085ED4FA[];
extern const u8 gUnknown_085ED516[];
extern const u8 gUnknown_085ED52F[];
extern const u8 gUnknown_085ED547[];
extern const u8 gUnknown_085ED563[];
extern const u8 gUnknown_085ED579[];
extern const u8 gUnknown_085ED58F[];
// .rodata

const match_call_sub0_t gUnknown_08624D1C[] = {
    { gText_MrStone_Pokenav_2B60C0, 0xFFFF,              FLAG_0x158 },
    { gText_MrStone_Pokenav_2B61E6, FLAG_0x158,          0xFFFF },
    { gText_MrStone_Pokenav_2B6302, FLAG_0x0BD,          0xFFFF },
    { gText_MrStone_Pokenav_2B63A0, FLAG_0x110,          0xFFFF },
    { gText_MrStone_Pokenav_2B64A2, FLAG_0x06A,          0xFFFF },
    { gText_MrStone_Pokenav_2B6526, FLAG_0x4F4,          0xFFFF },
    { gText_MrStone_Pokenav_2B65BB, FLAG_0x097,          0xFFFF },
    { gText_MrStone_Pokenav_2B6664, FLAG_0x06F,          0xFFFF },
    { gText_MrStone_Pokenav_2B66B1, FLAG_0x070,          0xFFFF },
    { gText_MrStone_Pokenav_2B6703, FLAG_0x4F7,          0xFFFF },
    { gText_MrStone_Pokenav_2B67ED, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

MATCHCALLDEF(gUnknown_08624D7C, 0, 10, 0xffff, gUnknown_085EFAEF, gUnknown_085EFAFA, gUnknown_08624D1C);

const match_call_sub0_t gUnknown_08624D8C[] = {
    { gText_Norman_Pokenav_2B5719, FLAG_0x132,           0xFFFF },
    { gText_Norman_Pokenav_2B5795, FLAG_0x4F1,           0xFFFF },
    { gText_Norman_Pokenav_2B584D, FLAG_0x4F3,           0xFFFF },
    { gText_Norman_Pokenav_2B58E3, FLAG_0x4F4,           0xFFFF },
    { gText_Norman_Pokenav_2B5979, FLAG_0x0D4,           0xFFFF },
    { gText_Norman_Pokenav_2B5A07, 0xFFFE,               0xFFFF },
    { gText_Norman_Pokenav_2B5A69, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { gText_Norman_Pokenav_2B5ACF, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { gText_Norman_Pokenav_2B5B5E, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { NULL,                        0xFFFF,               0xFFFF }
};

MATCHCALLDEF(gUnknown_08624DDC, 5, 7, FLAG_0x132, 0x45, gUnknown_085EFB25, gUnknown_085EFB47, gUnknown_08624D8C);

MATCHCALLDEF(gUnknown_08624DF0, 3, 0, FLAG_0x119, gUnknown_085EFBC9, gUnknown_085E8270)

const match_call_sub0_t gUnknown_08624DFC[] = {
    { gText_Mom_Pokenav_2B227B, 0xffff,              0xffff },
    { gText_Mom_Pokenav_2B2310, FLAG_0x4F4,          0xffff },
    { gText_Mom_Pokenav_2B23F3, FLAG_SYS_GAME_CLEAR, 0xffff },
    { NULL,                     0xffff,              0xffff }
};

MATCHCALLDEF(gUnknown_08624E1C, 0, 0, FLAG_0x0D8, gUnknown_085EFB32, gUnknown_085EFB4B, gUnknown_08624DFC);

const match_call_sub0_t gUnknown_08624E2C[] = {
    { gText_Steven_Pokenav_2B5B95, 0xffff,              0xffff },
    { gText_Steven_Pokenav_2B5C53, FLAG_0x0C7,          0xffff },
    { gText_Steven_Pokenav_2B5CC9, FLAG_0x0D4,          0xffff },
    { gText_Steven_Pokenav_2B5DB4, FLAG_0x070,          0xffff },
    { gText_Steven_Pokenav_2B5E26, FLAG_0x4F6,          0xffff },
    { gText_Steven_Pokenav_2B5EA2, FLAG_0x081,          0xffff },
    { gText_Steven_Pokenav_2B5ED9, FLAG_SYS_GAME_CLEAR, 0xffff },
    { NULL,                        0xffff,              0xffff },
};

MATCHCALLDEF(gUnknown_08624E6C, 0, 0xd5, FLAG_0x131, gUnknown_085EFB04, gUnknown_085EFB11, gUnknown_08624E2C);

const match_call_sub0_t gUnknown_08624E7C[] = {
    { gText_May_Pokenav_2B3AB3, 0xFFFF, 0xFFFF },
    { gText_May_Pokenav_2B3B3F, 0x4F1, 0xFFFF },
    { gText_May_Pokenav_2B3C13, 0x095, 0xFFFF },
    { gText_May_Pokenav_2B3CF3, 0x324, 0xFFFF },
    { gText_May_Pokenav_2B3D4B, 0x06A, 0xFFFF },
    { gText_May_Pokenav_2B3DD1, 0x4F3, 0xFFFF },
    { gText_May_Pokenav_2B3E69, 0x4F4, 0xFFFF },
    { gText_May_Pokenav_2B3ECD, 0x097, 0xFFFF },
    { gText_May_Pokenav_2B3F2B, 0x0D4, 0xFFFF },
    { gText_May_Pokenav_2B3FFB, 0x06F, 0xFFFF },
    { gText_May_Pokenav_2B402B, 0x061, 0xFFFF },
    { gText_May_Pokenav_2B414B, 0x070, 0xFFFF },
    { gText_May_Pokenav_2B4228, 0x081, 0xFFFF },
    { gText_May_Pokenav_2B42E0, 0x4F7, 0xFFFF },
    { gText_May_Pokenav_2B4350, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08624EFC, 4, 0, 0x0FD, gUnknown_085EFB18, gExpandedPlaceholder_May, gUnknown_08624E7C);

const match_call_sub0_t gUnknown_08624F0C[] = {
    { gText_Brendan_Pokenav_2B43EF, 0xFFFF, 0xFFFF },
    { gText_Brendan_Pokenav_2B4486, 0x4F1, 0xFFFF },
    { gText_Brendan_Pokenav_2B4560, 0x095, 0xFFFF },
    { gText_Brendan_Pokenav_2B463F, 0x324, 0xFFFF },
    { gText_Brendan_Pokenav_2B46B7, 0x06A, 0xFFFF },
    { gText_Brendan_Pokenav_2B4761, 0x4F3, 0xFFFF },
    { gText_Brendan_Pokenav_2B47F4, 0x4F4, 0xFFFF },
    { gText_Brendan_Pokenav_2B4882, 0x097, 0xFFFF },
    { gText_Brendan_Pokenav_2B4909, 0x0D4, 0xFFFF },
    { gText_Brendan_Pokenav_2B49C4, 0x06F, 0xFFFF },
    { gText_Brendan_Pokenav_2B4A44, 0x061, 0xFFFF },
    { gText_Brendan_Pokenav_2B4B28, 0x070, 0xFFFF },
    { gText_Brendan_Pokenav_2B4C15, 0x081, 0xFFFF },
    { gText_Brendan_Pokenav_2B4CD8, 0x4F7, 0xFFFF },
    { gText_Brendan_Pokenav_2B4D46, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08624F8C, 4, 1, 0x0FD, gUnknown_085EFB18, gExpandedPlaceholder_Brendan, gUnknown_08624F0C);

const match_call_sub0_t gUnknown_08624F9C[] = {
    { gText_Wally_Pokenav_2B4DE2, 0xFFFF, 0xFFFF },
    { gText_Wally_Pokenav_2B4E57, 0x0C7, 0xFFFF },
    { gText_Wally_Pokenav_2B4EA5, 0x4F3, 0xFFFF },
    { gText_Wally_Pokenav_2B4F41, 0x097, 0xFFFF },
    { gText_Wally_Pokenav_2B4FF3, 0x06F, 0xFFFF },
    { gText_Wally_Pokenav_2B50B1, 0x081, 0xFFFF },
    { gText_Wally_Pokenav_2B5100, 0x07E, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

const struct MatchCallSubstruct2 gUnknown_08624FDC[] = {
    { 0x0324, 0x05 },
    { 0x006F, 0xD5 },
    { 0x035A, 0x46 },
    { 0xFFFF, 0xD5 }
};

MATCHCALLDEF(gUnknown_08624FEC, 2, 0, 0x0D6, 0x40, gUnknown_085EFB3E, gUnknown_08624F9C, gUnknown_08624FDC);

const match_call_sub0_t gUnknown_08624500[] = {
    { gText_Scott_Pokenav_2B5184, 0xFFFF, 0xFFFF },
    { gText_Scott_Pokenav_2B5275, 0x08B, 0xFFFF },
    { gText_Scott_Pokenav_2B5323, 0x097, 0xFFFF },
    { gText_Scott_Pokenav_2B53DB, 0x0D4, 0xFFFF },
    { gText_Scott_Pokenav_2B54A5, 0x070, 0xFFFF },
    { gText_Scott_Pokenav_2B5541, 0x4F7, 0xFFFF },
    { gText_Scott_Pokenav_2B56CA, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};


MATCHCALLDEF(gUnknown_08625040, 0, 0xD5, 0x0D7, gUnknown_085EFB4F, gUnknown_085EFB5C, gUnknown_08624500);

const match_call_sub0_t gUnknown_08625050[] = {
    { gText_Roxanne_Pokenav_2B2456, 0xFFFE, 0xFFFF },
    { gText_Roxanne_Pokenav_2B250E, 0xFFFF, 0xFFFF },
    { gText_Roxanne_Pokenav_2B25C1, 0xFFFF, 0xFFFF },
    { gText_Roxanne_Pokenav_2B2607, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08625078, 5, 10, 0x1D3, 0x41, gUnknown_085EFB62, NULL, gUnknown_08625050);

const match_call_sub0_t gUnknown_0862508C[] = {
    { gText_Brawly_Pokenav_2B2659, 0xFFFE, 0xFFFF },
    { gText_Brawly_Pokenav_2B275D, 0xFFFF, 0xFFFF },
    { gText_Brawly_Pokenav_2B286F, 0xFFFF, 0xFFFF },
    { gText_Brawly_Pokenav_2B28D1, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_086250B4, 5, 2, 0x1D4, 0x42, gUnknown_085EFB6F, NULL, gUnknown_0862508C);

const match_call_sub0_t gUnknown_086250C8[] = {
    { gText_Wattson_Pokenav_2B2912, 0xFFFE, 0xFFFF },
    { gText_Wattson_Pokenav_2B29CA, 0xFFFF, 0xFFFF },
    { gText_Wattson_Pokenav_2B2AB6, 0xFFFF, 0xFFFF },
    { gText_Wattson_Pokenav_2B2B01, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_086250F0, 5, 9, 0x1D5, 0x43, gUnknown_085EFB7B, NULL, gUnknown_086250C8);

const match_call_sub0_t gUnknown_08625104[] = {
    { gText_Flannery_Pokenav_2B2B4D, 0xFFFE, 0xFFFF },
    { gText_Flannery_Pokenav_2B2C0E, 0xFFFF, 0xFFFF },
    { gText_Flannery_Pokenav_2B2CF1, 0xFFFF, 0xFFFF },
    { gText_Flannery_Pokenav_2B2D54, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_0862512C, 5, 3, 0x1D6, 0x44, gUnknown_085EFB87, NULL, gUnknown_08625104);

const match_call_sub0_t gUnknown_08625140[] = {
    { gText_Winona_Pokenav_2B2DA4, 0xFFFE, 0xFFFF },
    { gText_Winona_Pokenav_2B2E2B, 0xFFFF, 0xFFFF },
    { gText_Winona_Pokenav_2B2EC2, 0xFFFF, 0xFFFF },
    { gText_Winona_Pokenav_2B2F16, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08625168, 5, 11, 0x1D7, 0x46, gUnknown_085EFB94, NULL, gUnknown_08625140);

const match_call_sub0_t gUnknown_0862517C[] = {
    { gText_TateLiza_Pokenav_2B2F97, 0xFFFE, 0xFFFF },
    { gText_TateLiza_Pokenav_2B306E, 0xFFFF, 0xFFFF },
    { gText_TateLiza_Pokenav_2B3158, 0xFFFF, 0xFFFF },
    { gText_TateLiza_Pokenav_2B31CD, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_086251A4, 5, 13, 0x1D8, 0x47, gUnknown_085EFB9E, NULL, gUnknown_0862517C);

const match_call_sub0_t gUnknown_086251B8[] = {
    { gText_Juan_Pokenav_2B3249, 0xFFFE, 0xFFFF },
    { gText_Juan_Pokenav_2B32EC, 0xFFFF, 0xFFFF },
    { gText_Juan_Pokenav_2B33AA, 0xFFFF, 0xFFFF },
    { gText_Juan_Pokenav_2B341E, 0x864, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_086251E0, 5, 14, 0x1D9, 0x48, gUnknown_085EFBA9, NULL, gUnknown_086251B8);

const match_call_sub0_t gUnknown_086251F4[] = {
    { gText_Sidney_Pokenav_2B34CC, 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08625204, 5, 15, 0x1A5, 0x49, gUnknown_085EFBB5, NULL, gUnknown_086251F4);

const match_call_sub0_t gUnknown_08625218[] = {
    { gText_Phoebe_Pokenav_2B3561, 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08625228, 5, 15, 0x1A6, 0x4A, gUnknown_085EFBB5, NULL, gUnknown_08625218);

const match_call_sub0_t gUnknown_0862523C[] = {
    { gText_Glacia_Pokenav_2B35E4, 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_0862524C, 5, 15, 0x1A7, 0x4B, gUnknown_085EFBB5, NULL, gUnknown_0862523C);

const match_call_sub0_t gUnknown_08625260[] = {
    { gText_Drake_Pokenav_2B368B, 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08625270, 5, 15, 0x1A8, 0x4C, gUnknown_085EFBB5, NULL, gUnknown_08625260);

const match_call_sub0_t gUnknown_08625284[] = {
    { gText_Wallace_Pokenav_2B3790, 0xFFFF, 0xFFFF },
    { NULL, 0xFFFF, 0xFFFF }
};

MATCHCALLDEF(gUnknown_08625294, 5, 15, 0x1A9, 0x4D, gUnknown_085EFBC0, NULL, gUnknown_08625284);

const match_call_t gUnknown_086252A8[] = {
    {.type0 = &gUnknown_08624D7C},
    {.type3 = &gUnknown_08624DF0},
    {.type4 = &gUnknown_08624F8C},
    {.type4 = &gUnknown_08624EFC},
    {.type2 = &gUnknown_08624FEC},
    {.type5 = &gUnknown_08624DDC},
    {.type0 = &gUnknown_08624E1C},
    {.type0 = &gUnknown_08624E6C},
    {.type0 = &gUnknown_08625040},
    {.type5 = &gUnknown_08625078},
    {.type5 = &gUnknown_086250B4},
    {.type5 = &gUnknown_086250F0},
    {.type5 = &gUnknown_0862512C},
    {.type5 = &gUnknown_08625168},
    {.type5 = &gUnknown_086251A4},
    {.type5 = &gUnknown_086251E0},
    {.type5 = &gUnknown_08625204},
    {.type5 = &gUnknown_08625228},
    {.type5 = &gUnknown_0862524C},
    {.type5 = &gUnknown_08625270},
    {.type5 = &gUnknown_08625294}
};

bool32 (*const gUnknown_086252FC[])(match_call_t) = {
    sub_81D1628,
    sub_81D164C,
    sub_81D1670,
    sub_81D1694,
    sub_81D16CC
};

u8 (*const gUnknown_08625310[])(match_call_t) = {
    sub_81D1714,
    sub_81D1718,
    sub_81D171C,
    sub_81D1750,
    sub_81D1754
};

bool32 (*const gUnknown_08625324[])(match_call_t) = {
    sub_81D178C,
    sub_81D1790,
    sub_81D17C0,
    sub_81D17E0,
    sub_81D17E4
};

bool32 (*const gUnknown_08625338[])(match_call_t) = {
    sub_81D1840,
    sub_81D1844,
    sub_81D1848,
    sub_81D184C,
    sub_81D1850
};

u32 (*const gUnknown_0862534C[])(match_call_t) = {
    sub_81D1888,
    sub_81D188C,
    sub_81D1890,
    sub_81D1894,
    sub_81D1898
};

void (*const gUnknown_08625360[])(match_call_t, u8 *) = {
    sub_81D18D0,
    sub_81D18DC,
    sub_81D18FC,
    sub_81D1908,
    sub_81D1914
};

void (*const gUnknown_08625374[])(match_call_t, const u8 **, const u8 **) = {
    sub_81D1AB0,
    sub_81D1ABC,
    sub_81D1ADC,
    sub_81D1AF4,
    sub_81D1B00
};

const struct UnkStruct_08625388 gUnknown_08625388[] = {
    { 7, 0x4B, 0xffff, { gUnknown_085ED453, gUnknown_085ED46B, gUnknown_085ED483, gUnknown_085ED49D } },
    { 7, 0x4B, 0x4F6, { gUnknown_085ED453, gUnknown_085ED46B, gUnknown_085ED4B3, gUnknown_085ED4CE } },
    { 2, 0x3c, 0xffff, { gUnknown_085ED4E3, gUnknown_085ED4FA, gUnknown_085ED516, gUnknown_085ED52F } },
    { 3, 0x3f, 0xffff, { gUnknown_085ED547, gUnknown_085ED563, gUnknown_085ED579, gUnknown_085ED58F } }
};

// .text

u32 sub_81D1574(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        case 0:
        default:
            return 0;
        case 1:
        case 5:
            return 1;
        case 2:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
    }
}

u32 sub_81D15BC(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 sub_81D15CC(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < NELEMS(gRematchTable); rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 sub_81D15F4(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_086252FC[i](matchCall);
}

bool32 sub_81D1628(match_call_t matchCall)
{
    if (matchCall.type0->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type0->flag);
}

bool32 sub_81D164C(match_call_t matchCall)
{
    if (matchCall.type1->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type1->flag);
}

bool32 sub_81D1670(match_call_t matchCall)
{
    if (matchCall.type2->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type2->flag);
}

bool32 sub_81D1694(match_call_t matchCall)
{
    if (matchCall.type4->v1 != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.type4->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type4->flag);
}

bool32 sub_81D16CC(match_call_t matchCall)
{
    return FlagGet(matchCall.type3->flag);
}

u8 sub_81D16DC(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_08625310[i](matchCall);
}

u8 sub_81D1714(match_call_t matchCall)
{
    return matchCall.type0->v1;
}

u8 sub_81D1718(match_call_t matchCall)
{
    return matchCall.type1->v1;
}

u8 sub_81D171C(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.type2->v10[i].v0 != 0xffff; i++)
    {
        if (!FlagGet(matchCall.type2->v10[i].v0))
            break;
    }
    return matchCall.type2->v10[i].v2;
}

u8 sub_81D1750(match_call_t matchCall)
{
    return 0xd5;
}

u8 sub_81D1754(match_call_t matchCall)
{
    return 0xd5;
}

bool32 sub_81D1758(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return 0;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_08625324[i](matchCall);
}

bool32 sub_81D178C(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1790(match_call_t matchCall)
{
    if (matchCall.type1->v4 >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.type1->v4] ? TRUE : FALSE;
}

bool32 sub_81D17C0(match_call_t matchCall)
{
    return gSaveBlock1Ptr->trainerRematches[matchCall.type2->v4] ? TRUE : FALSE;
}

bool32 sub_81D17E0(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D17E4(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D17E8(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    if (gUnknown_08625338[i](matchCall))
        return TRUE;
    for (i = 0; i < 4; i++)
    {
        if (gUnknown_08625388[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

bool32 sub_81D1840(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1844(match_call_t matchCall)
{
    return TRUE;
}

bool32 sub_81D1848(match_call_t matchCall)
{
    return TRUE;
}

bool32 sub_81D184C(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1850(match_call_t matchCall)
{
    return FALSE;
}

u32 sub_81D1854(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return REMATCH_TABLE_ENTRIES;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_0862534C[i](matchCall);
}

u32 sub_81D1888(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

u32 sub_81D188C(match_call_t matchCall)
{
    return matchCall.type1->v4;
}

u32 sub_81D1890(match_call_t matchCall)
{
    return matchCall.type2->v4;
}

u32 sub_81D1894(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

u32 sub_81D1898(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void sub_81D189C(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    gUnknown_08625360[i](matchCall, dest);
}

void sub_81D18D0(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type0->vC, dest);
}

void sub_81D18DC(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != 5)
        sub_81D1920(matchCall.type5->v10, dest);
    else
        sub_81D199C(matchCall.type1->v10, matchCall.type1->v4, dest);
}

void sub_81D18FC(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type2->vC, dest);
}

void sub_81D1908(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type4->vC, dest);
}

void sub_81D1914(match_call_t matchCall, u8 *dest)
{
    sub_8197080(dest);
}

void sub_81D1920(const match_call_sub0_t *sub0, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (sub0[i].flag != 0xffff && FlagGet(sub0[i].flag) == TRUE)
            break;
        i--;
    }
    if (sub0[i].flag2 != 0xffff)
        FlagSet(sub0[i].flag2);
    StringExpandPlaceholders(dest, sub0[i].text);
}

#ifdef NONMATCHING
// There's some weird upmerge going on that I cannot replicate at this time.
void sub_81D199C(const match_call_sub0_t *sub0, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
    {
        if (sub0[i].flag == 0xfffe)
            break;
        if (sub0[i].flag == 0xffff && !FlagGet(sub0[i].flag))
            break;
    }
    if (sub0[i].flag != 0xfffe)
    {
        if (i)
            i--;
        if (sub0[i].flag2 != 0xffff)
            FlagSet(sub0[i].flag2);
        StringExpandPlaceholders(dest, sub0[i].text);
    }
    else
    {
        if (!FlagGet(FLAG_SYS_GAME_CLEAR))
            ;
        else if (gSaveBlock1Ptr->trainerRematches[idx])
            i += 2;
        else if (CountBattledRematchTeams(idx) >= 2)
            i += 3;
        else
            i++;
        StringExpandPlaceholders(dest, sub0[i].text);
    }
}
#else
ASM_DIRECT void sub_81D199C(const match_call_sub0_t *sub0, u16 idx, u8 *dest)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmov r10, r2\n"
                    "\tlsls r1, 16\n"
                    "\tlsrs r7, r1, 16\n"
                    "\tmovs r5, 0\n"
                    "\tldr r0, [r6]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r6, 0x4]\n"
                    "\tldr r1, =0x0000fffe\n"
                    "\tcmp r0, r1\n"
                    "\tbeq _081D1A24\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tmov r9, r0\n"
                    "\tmov r8, r1\n"
                    "\tadds r4, r6, 0\n"
                    "_081D19C6:\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r9\n"
                    "\tbeq _081D19D6\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "_081D19D6:\n"
                    "\tadds r4, 0x8\n"
                    "\tadds r5, 0x1\n"
                    "\tldr r0, [r4]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r8\n"
                    "\tbne _081D19C6\n"
                    "_081D19E6:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldrh r1, [r0, 0x4]\n"
                    "\tldr r0, =0x0000fffe\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A24\n"
                    "\tcmp r5, 0\n"
                    "\tbeq _081D19F8\n"
                    "\tsubs r5, 0x1\n"
                    "_081D19F8:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r4, r0, r6\n"
                    "\tldrh r1, [r4, 0x6]\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A0A\n"
                    "\tadds r0, r1, 0\n"
                    "\tbl FlagSet\n"
                    "_081D1A0A:\n"
                    "\tldr r1, [r4]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "\tb _081D1A5C\n"
                    "\t.pool\n"
                    "_081D1A1C:\n"
                    "\tadds r5, 0x2\n"
                    "\tb _081D1A50\n"
                    "_081D1A20:\n"
                    "\tadds r5, 0x3\n"
                    "\tb _081D1A50\n"
                    "_081D1A24:\n"
                    "\tldr r0, =0x00000864\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1A50\n"
                    "\tldr r0, =gSaveBlock1Ptr\n"
                    "\tldr r0, [r0]\n"
                    "\tldr r1, =0x000009ca\n"
                    "\tadds r0, r1\n"
                    "\tadds r0, r7\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _081D1A1C\n"
                    "\tadds r0, r7, 0\n"
                    "\tbl CountBattledRematchTeams\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tcmp r0, 0x1\n"
                    "\tbhi _081D1A20\n"
                    "\tadds r5, 0x1\n"
                    "_081D1A50:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldr r1, [r0]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "_081D1A5C:\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif

void sub_81D1A78(u32 idx, const u8 **a1, const u8 **a2)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    gUnknown_08625374[i](matchCall, a1, a2);
}

void sub_81D1AB0(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    *a1 = matchCall.type0->v4;
    *a2 = matchCall.type0->v8;
}

void sub_81D1ABC(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.type1->vC == NULL)
        sub_81D1B0C(_matchCall.type1->v4, a1, a2);
    else
        *a2 = _matchCall.type1->vC;
    *a1 = _matchCall.type1->v8;
}

void sub_81D1ADC(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    sub_81D1B0C(matchCall.type2->v4, a1, a2);
    *a1 = matchCall.type2->v8;
}

void sub_81D1AF4(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    *a1 = matchCall.type0->v4;
    *a2 = matchCall.type0->v8;
}

void sub_81D1B00(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    *a1 = matchCall.type0->v4;
    *a2 = matchCall.type0->v8;
}

void sub_81D1B0C(u32 idx, const u8 **a1, const u8 **a2)
{
    const struct Trainer *trainer = gTrainers + sub_81D15BC(idx);
    *a1 = gTrainerClassNames[trainer->trainerClass];
    *a2 = trainer->trainerName;
}

#ifdef NONMATCHING
const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_08625388[i].idx == idx)
        {
            for (; i + 1 < 4 && gUnknown_08625388[i + 1].idx == idx; i++)
            {
                if (!FlagGet(gUnknown_08625388[i + 1].v4))
                    break;
            }
            return gUnknown_08625388[i].v8[offset];
        }
    }
    return NULL;
}
#else
ASM_DIRECT const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r9\n"
                    "\tmov r6, r8\n"
                    "\tpush {r6,r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmovs r5, 0\n"
                    "\tldr r2, =gUnknown_08625388\n"
                    "\tmovs r0, 0x8\n"
                    "\tadds r0, r2\n"
                    "\tmov r9, r0\n"
                    "_081D1B54:\n"
                    "\tlsls r0, r5, 1\n"
                    "\tadds r0, r5\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r2\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbne _081D1BBC\n"
                    "\tadds r4, r5, 0x1\n"
                    "\tlsls r1, 2\n"
                    "\tmov r8, r1\n"
                    "\tcmp r4, 0x3\n"
                    "\tbhi _081D1BA8\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r2\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbne _081D1BA8\n"
                    "\tldr r7, =gUnknown_08625388\n"
                    "_081D1B7C:\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r1, r7, 0x4\n"
                    "\tadds r0, r1\n"
                    "\tldrh r0, [r0]\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1BA8\n"
                    "\tadds r5, r4, 0\n"
                    "\tadds r4, r5, 0x1\n"
                    "\tcmp r4, 0x3\n"
                    "\tbhi _081D1BA8\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r7\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbeq _081D1B7C\n"
                    "_081D1BA8:\n"
                    "\tlsls r0, r5, 1\n"
                    "\tadds r0, r5\n"
                    "\tlsls r0, 3\n"
                    "\tadd r0, r8\n"
                    "\tadd r0, r9\n"
                    "\tldr r0, [r0]\n"
                    "\tb _081D1BC4\n"
                    "\t.pool\n"
                    "_081D1BBC:\n"
                    "\tadds r5, 0x1\n"
                    "\tcmp r5, 0x3\n"
                    "\tbls _081D1B54\n"
                    "\tmovs r0, 0\n"
                    "_081D1BC4:\n"
                    "\tpop {r3,r4}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r1}\n"
                    "\tbx r1");
}
#endif

s32 sub_81D1BD0(u32 idx)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_08625388[i].idx == idx)
            return gUnknown_08625388[i].v2;
    }
    return -1;
}

bool32 sub_81D1BF8(u32 idx)
{
    s32 i;

    for (i = 0; i < 21; i++)
    {
        u32 r0 = sub_81D1854(i);
        if (r0 != REMATCH_TABLE_ENTRIES && r0 == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    s32 r0 = sub_81D15CC(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(FLAG_MATCH_CALL_REGISTERED + r0);
}
