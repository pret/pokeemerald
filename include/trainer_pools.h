#ifndef GUARD_TRAINER_POOLS_H
#define GUARD_TRAINER_POOLS_H

#include "pokemon.h"
#include "data.h"
#include "global.h"

#define POOL_SLOT_DISABLED  0xff

//  Unlimited is set to 0 so that the default is unlimited
#define POOL_MEMBER_COUNT_UNLIMITED 0
#define POOL_MEMBER_COUNT_NONE      0xff

enum PoolRulesets {
    POOL_RULESET_BASIC,
    POOL_RULESET_DOUBLES,
    POOL_RULESET_WEATHER_SINGLES,
    POOL_RULESET_WEATHER_DOUBLES,
    POOL_RULESET_SUPPORT_DOUBLES,
};

enum PoolPickFunctions {
    POOL_PICK_DEFAULT,
    POOL_PICK_LOWEST,
};

enum PoolPruneOptions {
    POOL_PRUNE_NONE,
    POOL_PRUNE_TEST,
    POOL_PRUNE_RANDOM_TAG,
};

enum PoolTags {
    //  Lead and Ace has special handling, leave them be
    POOL_TAG_LEAD = 0,
    POOL_TAG_ACE = 1,
    //  No special handling for these
    POOL_TAG_WEATHER_SETTER = 2,
    POOL_TAG_WEATHER_ABUSER = 3,
    POOL_TAG_SUPPORT = 4,
    POOL_TAG_TAG6 = 5,
    POOL_TAG_TAG7 = 6,
    POOL_TAG_TAG8 = 7,
    //  Must be the last element
    POOL_NUM_TAGS = 8
};

#define MON_POOL_TAG_LEAD           1 << POOL_TAG_LEAD
#define MON_POOL_TAG_ACE            1 << POOL_TAG_ACE
#define MON_POOL_TAG_WEATHER_SETTER 1 << POOL_TAG_WEATHER_SETTER
#define MON_POOL_TAG_WEATHER_ABUSER 1 << POOL_TAG_WEATHER_ABUSER
#define MON_POOL_TAG_SUPPORT        1 << POOL_TAG_SUPPORT
#define MON_POOL_TAG_TAG6           1 << POOL_TAG_TAG6
#define MON_POOL_TAG_TAG7           1 << POOL_TAG_TAG7
#define MON_POOL_TAG_TAG8           1 << POOL_TAG_TAG8

struct PoolRules
{
    u8 speciesClause:1;
    u8 excludeForms:1;
    u8 itemClause:1;
    u8 itemClauseExclusions:1;
    u8 megaStoneClause:1;
    u8 zCrystalClause:1;
    u8 tagMaxMembers[POOL_NUM_TAGS];
    bool8 tagRequired[POOL_NUM_TAGS];
};

struct PickFunctions
{
    u32 (*LeadFunction)(const struct Trainer *, u8 *, u32, u32, u32, struct PoolRules *);
    u32 (*AceFunction)(const struct Trainer *, u8 *, u32, u32, u32, struct PoolRules *);
    u32 (*OtherFunction)(const struct Trainer *, u8 *, u32, u32, u32, struct PoolRules *);
};

void DoTrainerPartyPool(const struct Trainer *trainer, u32 *monIndices, u8 monsCount, u32 battleTypeFlags);

#endif
