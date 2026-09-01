#include "battle_main.h"

const enum Item poolItemClauseExclusions[] =
{
    ITEM_ORAN_BERRY,
    ITEM_SITRUS_BERRY,
};

const struct PoolRules defaultPoolRules =
{
    .speciesClause = B_POOL_RULE_SPECIES_CLAUSE,
    .excludeForms = B_POOL_RULE_EXCLUDE_FORMS,
    .itemClause = B_POOL_RULE_ITEM_CLAUSE,
    .itemClauseExclusions = B_POOL_RULES_USE_ITEM_EXCLUSIONS,
    .megaStoneClause = B_POOL_RULE_MEGA_STONE_CLAUSE,
    .zCrystalClause = B_POOL_RULE_Z_CRYSTAL_CLAUSE,
};

const struct PoolRules gPoolRulesetsList[] = {
    [POOL_RULESET_BASIC] = {
        .speciesClause = B_POOL_RULE_SPECIES_CLAUSE,
        .excludeForms = B_POOL_RULE_EXCLUDE_FORMS,
        .itemClause = B_POOL_RULE_ITEM_CLAUSE,
        .itemClauseExclusions = B_POOL_RULES_USE_ITEM_EXCLUSIONS,
        .megaStoneClause = B_POOL_RULE_MEGA_STONE_CLAUSE,
        .zCrystalClause = B_POOL_RULE_Z_CRYSTAL_CLAUSE,
        .tagMaxMembers[POOL_TAG_LEAD] = 1,
        .tagMaxMembers[POOL_TAG_ACE] = 1,
    },
    [POOL_RULESET_DOUBLES] = {
        .speciesClause = B_POOL_RULE_SPECIES_CLAUSE,
        .excludeForms = B_POOL_RULE_EXCLUDE_FORMS,
        .itemClause = B_POOL_RULE_ITEM_CLAUSE,
        .itemClauseExclusions = B_POOL_RULES_USE_ITEM_EXCLUSIONS,
        .megaStoneClause = B_POOL_RULE_MEGA_STONE_CLAUSE,
        .zCrystalClause = B_POOL_RULE_Z_CRYSTAL_CLAUSE,
        .tagMaxMembers[POOL_TAG_LEAD] = 2,
        .tagMaxMembers[POOL_TAG_ACE] = 2,
    },
    [POOL_RULESET_WEATHER_SINGLES] = {
        .speciesClause = B_POOL_RULE_SPECIES_CLAUSE,
        .excludeForms = B_POOL_RULE_EXCLUDE_FORMS,
        .itemClause = B_POOL_RULE_ITEM_CLAUSE,
        .itemClauseExclusions = B_POOL_RULES_USE_ITEM_EXCLUSIONS,
        .megaStoneClause = B_POOL_RULE_MEGA_STONE_CLAUSE,
        .zCrystalClause = B_POOL_RULE_Z_CRYSTAL_CLAUSE,
        .tagMaxMembers[POOL_TAG_LEAD] = 1,
        .tagMaxMembers[POOL_TAG_ACE] = 1,
        .tagMaxMembers[POOL_TAG_WEATHER_SETTER] = 1,
        .tagRequired[POOL_TAG_WEATHER_SETTER] = TRUE,
        .tagMaxMembers[POOL_TAG_WEATHER_ABUSER] = POOL_MEMBER_COUNT_UNLIMITED,
        .tagRequired[POOL_TAG_WEATHER_ABUSER] = TRUE,
    },
    [POOL_RULESET_WEATHER_DOUBLES] = {
        .speciesClause = B_POOL_RULE_SPECIES_CLAUSE,
        .excludeForms = B_POOL_RULE_EXCLUDE_FORMS,
        .itemClause = B_POOL_RULE_ITEM_CLAUSE,
        .itemClauseExclusions = B_POOL_RULES_USE_ITEM_EXCLUSIONS,
        .megaStoneClause = B_POOL_RULE_MEGA_STONE_CLAUSE,
        .zCrystalClause = B_POOL_RULE_Z_CRYSTAL_CLAUSE,
        .tagMaxMembers[POOL_TAG_LEAD] = 2,
        .tagMaxMembers[POOL_TAG_ACE] = 2,
        .tagMaxMembers[POOL_TAG_WEATHER_SETTER] = 1,
        .tagRequired[POOL_TAG_WEATHER_SETTER] = TRUE,
        .tagMaxMembers[POOL_TAG_WEATHER_ABUSER] = POOL_MEMBER_COUNT_UNLIMITED,
        .tagRequired[POOL_TAG_WEATHER_ABUSER] = TRUE,
    },
    [POOL_RULESET_SUPPORT_DOUBLES] = {
        .speciesClause = B_POOL_RULE_SPECIES_CLAUSE,
        .excludeForms = B_POOL_RULE_EXCLUDE_FORMS,
        .itemClause = B_POOL_RULE_ITEM_CLAUSE,
        .itemClauseExclusions = B_POOL_RULES_USE_ITEM_EXCLUSIONS,
        .megaStoneClause = B_POOL_RULE_MEGA_STONE_CLAUSE,
        .zCrystalClause = B_POOL_RULE_Z_CRYSTAL_CLAUSE,
        .tagMaxMembers[POOL_TAG_LEAD] = 2,
        .tagMaxMembers[POOL_TAG_ACE] = 2,
        .tagMaxMembers[POOL_TAG_SUPPORT] = 1,
        .tagRequired[POOL_TAG_SUPPORT] = TRUE,
    },
};
