#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_z_move.h"
#include "battle_scripts.h"
#include "graphics.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "item.h"
#include "strings.h"
#include "sound.h"
#include "constants/songs.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "safari_zone.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "battle_debug.h"
#include "data.h"
#include "pokemon_summary_screen.h"
#include "constants/songs.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/hold_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_move_effects.h"
#include "constants/abilities.h"
#include "constants/moves.h"

#define STAT_STAGE(battler, stat) (gBattleMons[battler].statStages[stat - 1])

// Function Declarations
static void SpriteCB_ZMoveTrigger(struct Sprite *sprite);
static u16 GetSignatureZMove(u16 move, u16 species, u16 item);
static void ZMoveSelectionDisplayPpNumber(u32 battler);
static void ZMoveSelectionDisplayPower(u16 move, u16 zMove);
static void ShowZMoveTriggerSprite(u8 battleId);
static bool32 AreStatsMaxed(u8 battler, u8 n);
static void ZMoveSelectionDisplayMoveType(u16 zMove, u32 battler);

// Const Data
static const struct SignatureZMove sSignatureZMoves[] =
{
    {SPECIES_PIKACHU_COSPLAY,         ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_ROCK_STAR,       ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_BELLE,           ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_POP_STAR,        ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_PH_D,            ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_LIBRE,           ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},

    {SPECIES_RAICHU_ALOLAN,           ITEM_ALORAICHIUM_Z,        MOVE_THUNDERBOLT,         MOVE_STOKED_SPARKSURFER},
    {SPECIES_DECIDUEYE,               ITEM_DECIDIUM_Z,           MOVE_SPIRIT_SHACKLE,      MOVE_SINISTER_ARROW_RAID},
    {SPECIES_INCINEROAR,              ITEM_INCINIUM_Z,           MOVE_DARKEST_LARIAT,      MOVE_MALICIOUS_MOONSAULT},
    {SPECIES_KOMMO_O,                 ITEM_KOMMONIUM_Z,          MOVE_CLANGING_SCALES,     MOVE_CLANGOROUS_SOULBLAZE},
    {SPECIES_LUNALA,                  ITEM_LUNALIUM_Z,           MOVE_MOONGEIST_BEAM,      MOVE_MENACING_MOONRAZE_MAELSTROM},
    {SPECIES_NECROZMA_DAWN_WINGS,     ITEM_LUNALIUM_Z,           MOVE_MOONGEIST_BEAM,      MOVE_MENACING_MOONRAZE_MAELSTROM},
    {SPECIES_LYCANROC_MIDDAY,         ITEM_LYCANIUM_Z,           MOVE_STONE_EDGE,          MOVE_SPLINTERED_STORMSHARDS},
    {SPECIES_LYCANROC_MIDNIGHT,       ITEM_LYCANIUM_Z,           MOVE_STONE_EDGE,          MOVE_SPLINTERED_STORMSHARDS},
    {SPECIES_LYCANROC_DUSK,           ITEM_LYCANIUM_Z,           MOVE_STONE_EDGE,          MOVE_SPLINTERED_STORMSHARDS},
    {SPECIES_MARSHADOW,               ITEM_MARSHADIUM_Z,         MOVE_SPECTRAL_THIEF,      MOVE_SOUL_STEALING_7_STAR_STRIKE},
    {SPECIES_MIMIKYU_DISGUISED,       ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_MIMIKYU_BUSTED,          ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_MIMIKYU_TOTEM_DISGUISED, ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_MIMIKYU_TOTEM_BUSTED,    ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_PIKACHU_ORIGINAL_CAP,    ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_HOENN_CAP,       ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_SINNOH_CAP,      ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_UNOVA_CAP,       ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_KALOS_CAP,       ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_ALOLA_CAP,       ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_PARTNER_CAP,     ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_WORLD_CAP,       ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PRIMARINA,               ITEM_PRIMARIUM_Z,          MOVE_SPARKLING_ARIA,      MOVE_OCEANIC_OPERETTA},
    {SPECIES_SOLGALEO,                ITEM_SOLGANIUM_Z,          MOVE_SUNSTEEL_STRIKE,     MOVE_SEARING_SUNRAZE_SMASH},
    {SPECIES_NECROZMA_DUSK_MANE,      ITEM_SOLGANIUM_Z,          MOVE_SUNSTEEL_STRIKE,     MOVE_SEARING_SUNRAZE_SMASH},
    {SPECIES_TAPU_KOKO,               ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_TAPU_BULU,               ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_TAPU_LELE,               ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_TAPU_FINI,               ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_NECROZMA_ULTRA,          ITEM_ULTRANECROZIUM_Z,     MOVE_PHOTON_GEYSER,       MOVE_LIGHT_THAT_BURNS_THE_SKY},
    {SPECIES_MEW,                     ITEM_MEWNIUM_Z,            MOVE_PSYCHIC,             MOVE_GENESIS_SUPERNOVA},
    {SPECIES_PIKACHU,                 ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_EEVEE,                   ITEM_EEVIUM_Z,             MOVE_LAST_RESORT,         MOVE_EXTREME_EVOBOOST},
    {SPECIES_SNORLAX,                 ITEM_SNORLIUM_Z,           MOVE_GIGA_IMPACT,         MOVE_PULVERIZING_PANCAKE},
};

static const u8 sText_ResetStats[] = _("Reset Lowered Stats");
static const u8 sText_StatsPlus[] = _("+ All Stats");
static const u8 sText_StatsPlus2[] = _("++ All Stats");
static const u8 sText_CritHitsPlus[] = _("+ Critical Hit Chance");
static const u8 sText_FollowMe[] = _("Follow Me");
static const u8 sText_RecoverHP[] = _("Recover HP");
static const u8 sText_HealAllyHP[] = _("Heal Replacement HP");
static const u8 sText_PowerColon[] = _("Power: ");

static const u32 sZMoveTriggerGfx[] = INCBIN_U32("graphics/battle_interface/z_move_trigger.4bpp.lz");
static const u16 sZMoveTriggerPal[] = INCBIN_U16("graphics/battle_interface/z_move_trigger.gbapal");

static const struct CompressedSpriteSheet sSpriteSheet_ZMoveTrigger = {
    sZMoveTriggerGfx, (32 * 32) / 2, TAG_ZMOVE_TRIGGER_TILE
};

static const struct SpritePalette sSpritePalette_ZMoveTrigger = {
    sZMoveTriggerPal, TAG_ZMOVE_TRIGGER_PAL
};

static const struct OamData sOamData_ZMoveTrigger =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct SpriteTemplate sSpriteTemplate_ZMoveTrigger =
{
    .tileTag = TAG_ZMOVE_TRIGGER_TILE,
    .paletteTag = TAG_ZMOVE_TRIGGER_PAL,
    .oam = &sOamData_ZMoveTrigger,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ZMoveTrigger
};

// Functions
bool8 IsZMove(u16 move)
{
    return move >= FIRST_Z_MOVE && move <= LAST_Z_MOVE;
}

void QueueZMove(u8 battler, u16 baseMove)
{
    gBattleStruct->zmove.toBeUsed[battler] = gBattleStruct->zmove.chosenZMove;
    gBattleStruct->zmove.baseMoves[battler] = baseMove;
    if (gBattleStruct->zmove.chosenZMove == MOVE_LIGHT_THAT_BURNS_THE_SKY)
        gBattleStruct->zmove.categories[battler] = GetCategoryBasedOnStats(battler);
    else
        gBattleStruct->zmove.categories[battler] = gMovesInfo[baseMove].category;
}

bool32 IsViableZMove(u8 battler, u16 move)
{
    u32 item;
    u16 holdEffect;
    int moveSlotIndex;

    item = gBattleMons[battler].item;

    for (moveSlotIndex = 0; moveSlotIndex < MAX_MON_MOVES; moveSlotIndex++)
    {
        if (gBattleMons[battler].moves[moveSlotIndex] == move && gBattleMons[battler].pp[moveSlotIndex] == 0)
            return FALSE;
    }

    if (gBattleStruct->zmove.used[battler])
        return FALSE;

    // Add '| BATTLE_TYPE_FRONTIER' to below if issues occur
    if (gBattleTypeFlags & (BATTLE_TYPE_SAFARI | BATTLE_TYPE_WALLY_TUTORIAL))
        return FALSE;

    if ((GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT)) && !CheckBagHasItem(ITEM_Z_POWER_RING, 1))
        return FALSE;

    if (item == ITEM_ENIGMA_BERRY_E_READER)
        return FALSE;   // HoldEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(item);

    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
    {
        u16 zMove = GetSignatureZMove(move, gBattleMons[battler].species, item);
        if (zMove != MOVE_NONE)
        {
            gBattleStruct->zmove.chosenZMove = zMove;  // Signature z move exists
            return TRUE;
        }

        if (move != MOVE_NONE && zMove != MOVE_Z_STATUS && gMovesInfo[move].type == ItemId_GetSecondaryId(item))
        {
            gBattleStruct->zmove.chosenZMove = GetTypeBasedZMove(move, battler);
            return TRUE;
        }
    }

    return FALSE;
}

void GetUsableZMoves(u8 battler, u16 *moves)
{
    u32 i;
    gBattleStruct->zmove.possibleZMoves[battler] = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && IsViableZMove(battler, moves[i]))
            gBattleStruct->zmove.possibleZMoves[battler] |= (1 << i);
    }
}

bool32 IsZMoveUsable(u8 battler, u16 moveIndex)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && IsPartnerMonFromSameTrainer(battler) && gBattleStruct->zmove.toBeUsed[BATTLE_PARTNER(battler)] != MOVE_NONE)
        return FALSE;   // Player's other mon has a z move queued up already
    if (gBattleStruct->zmove.possibleZMoves[battler] & (1 << moveIndex))
        return TRUE;
    return FALSE;
}

bool32 TryChangeZIndicator(u8 battler, u8 moveIndex)
{
    bool32 viableZMove = IsZMoveUsable(battler, moveIndex);

    if (gBattleStruct->zmove.viable && !viableZMove)
        HideZMoveTriggerSprite();   // Was a viable z move, now is not -> slide out
    else if (!gBattleStruct->zmove.viable && viableZMove)
        ShowZMoveTriggerSprite(battler);   // Was not a viable z move, now is -> slide back in

    return viableZMove;
}

#define SINGLES_Z_TRIGGER_POS_X_OPTIMAL     (29)
#define SINGLES_Z_TRIGGER_POS_X_PRIORITY    (29)
#define SINGLES_Z_TRIGGER_POS_X_SLIDE       (15)
#define SINGLES_Z_TRIGGER_POS_Y_DIFF        (-10)

#define DOUBLES_Z_TRIGGER_POS_X_OPTIMAL     SINGLES_Z_TRIGGER_POS_X_OPTIMAL
#define DOUBLES_Z_TRIGGER_POS_X_PRIORITY    SINGLES_Z_TRIGGER_POS_X_PRIORITY
#define DOUBLES_Z_TRIGGER_POS_X_SLIDE       SINGLES_Z_TRIGGER_POS_X_SLIDE
#define DOUBLES_Z_TRIGGER_POS_Y_DIFF        (-4)

#define tBattler    data[0]
#define tHide       data[1]

void CreateZMoveTriggerSprite(u8 battler, bool8 viable)
{
    s16 x, y;

    LoadSpritePalette(&sSpritePalette_ZMoveTrigger);
    if (GetSpriteTileStartByTag(TAG_ZMOVE_TRIGGER_TILE) == 0xFFFF)
        LoadCompressedSpriteSheetUsingHeap(&sSpriteSheet_ZMoveTrigger);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        x = gSprites[gHealthboxSpriteIds[battler]].x - DOUBLES_Z_TRIGGER_POS_X_SLIDE;
        y = gSprites[gHealthboxSpriteIds[battler]].y - DOUBLES_Z_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        x = gSprites[gHealthboxSpriteIds[battler]].x - SINGLES_Z_TRIGGER_POS_X_SLIDE;
        y = gSprites[gHealthboxSpriteIds[battler]].y - SINGLES_Z_TRIGGER_POS_Y_DIFF;
    }

    if (gBattleStruct->zmove.triggerSpriteId == 0xFF)
        gBattleStruct->zmove.triggerSpriteId = CreateSprite(&sSpriteTemplate_ZMoveTrigger, x, y, 0);

    gSprites[gBattleStruct->zmove.triggerSpriteId].tBattler = battler;
    gSprites[gBattleStruct->zmove.triggerSpriteId].tHide = (viable == TRUE) ? FALSE : TRUE;
}

static void SpriteCB_ZMoveTrigger(struct Sprite *sprite)
{
    s32 xSlide, xPriority, xOptimal;
    s32 yDiff;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        xSlide = DOUBLES_Z_TRIGGER_POS_X_SLIDE;
        xPriority = DOUBLES_Z_TRIGGER_POS_X_PRIORITY;
        xOptimal = DOUBLES_Z_TRIGGER_POS_X_OPTIMAL;
        yDiff = DOUBLES_Z_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        xSlide = SINGLES_Z_TRIGGER_POS_X_SLIDE;
        xPriority = SINGLES_Z_TRIGGER_POS_X_PRIORITY;
        xOptimal = SINGLES_Z_TRIGGER_POS_X_OPTIMAL;
        yDiff = SINGLES_Z_TRIGGER_POS_Y_DIFF;
    }

    if (sprite->tHide)
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            sprite->x++;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
        if (sprite->x == gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            DestroyZMoveTriggerSprite();
    }
    else
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xOptimal)
        {
            sprite->x--;
            sprite->oam.priority = 2;
        }
        else
        {
            sprite->oam.priority = 1;
        }
        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
    }
}

bool32 IsZMoveTriggerSpriteActive(void)
{
    if (GetSpriteTileStartByTag(TAG_ZMOVE_TRIGGER_TILE) == 0xFFFF)
        return FALSE;
    else if (IndexOfSpritePaletteTag(TAG_ZMOVE_TRIGGER_PAL) != 0xFF)
        return TRUE;
    else
        return FALSE;
}

void HideZMoveTriggerSprite(void)
{
    struct Sprite *sprite;
    gBattleStruct->zmove.viable = FALSE;
    if (gBattleStruct->zmove.triggerSpriteId >= MAX_SPRITES)
        return;
    sprite = &gSprites[gBattleStruct->zmove.triggerSpriteId];
    sprite->tHide = TRUE;
}

static void ShowZMoveTriggerSprite(u8 battler)
{
    gBattleStruct->zmove.viable = TRUE;
    CreateZMoveTriggerSprite(battler, TRUE);
}

void DestroyZMoveTriggerSprite(void)
{
    FreeSpritePaletteByTag(TAG_ZMOVE_TRIGGER_PAL);
    FreeSpriteTilesByTag(TAG_ZMOVE_TRIGGER_TILE);
    if (gBattleStruct->zmove.triggerSpriteId != 0xFF)
        DestroySprite(&gSprites[gBattleStruct->zmove.triggerSpriteId]);

    gBattleStruct->zmove.triggerSpriteId = 0xFF;
}

static u16 GetSignatureZMove(u16 move, u16 species, u16 item)
{
    u32 i;

    // Check signature z move
    for (i = 0; i < ARRAY_COUNT(sSignatureZMoves); ++i)
    {
        if (sSignatureZMoves[i].item == item && sSignatureZMoves[i].species == species &&  sSignatureZMoves[i].move == move)
            return sSignatureZMoves[i].zmove;
    }

    return MOVE_NONE;
}

u16 GetTypeBasedZMove(u16 move, u8 battler)
{
    u8 moveType = gMovesInfo[move].type;

    if (moveType >= NUMBER_OF_MON_TYPES)
        moveType = TYPE_MYSTERY;

    // Get Z-Move from type
    if (gTypesInfo[moveType].zMove == MOVE_NONE) // failsafe
        return gTypesInfo[0].zMove;
    return gTypesInfo[moveType].zMove;
}

bool32 MoveSelectionDisplayZMove(u16 zmove, u32 battler)
{
    u32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    u16 move = moveInfo->moves[gMoveSelectionCursor[battler]];

    PlaySE(SE_SELECT);
    gBattleStruct->zmove.viewing = TRUE;
    if (zmove != MOVE_NONE)
    {
        // Clear move slots
        for (i = 0; i < MAX_MON_MOVES; ++i)
        {
            MoveSelectionDestroyCursorAt(i);
            StringCopy(gDisplayedStringBattle, gText_EmptyString2);
            BattlePutTextOnWindow(gDisplayedStringBattle, i + 3);
        }

        if (IS_MOVE_STATUS(move))
        {
            u8 zEffect = gMovesInfo[move].zMove.effect;

            gDisplayedStringBattle[0] = EOS;

            if (zEffect == Z_EFFECT_CURSE)
            {
                if (moveInfo->monType1 == TYPE_GHOST || moveInfo->monType2 == TYPE_GHOST || moveInfo->monType3 == TYPE_GHOST)
                    zEffect = Z_EFFECT_RECOVER_HP;
                else
                    zEffect = Z_EFFECT_ATK_UP_1;
            }

            switch (zEffect)
            {
            case Z_EFFECT_RESET_STATS:
                StringCopy(gDisplayedStringBattle, sText_ResetStats);
                break;
            case Z_EFFECT_ALL_STATS_UP_1:
                StringCopy(gDisplayedStringBattle, sText_StatsPlus);
                break;
            case Z_EFFECT_BOOST_CRITS:
                StringCopy(gDisplayedStringBattle, sText_CritHitsPlus);
                break;
            case Z_EFFECT_FOLLOW_ME:
                StringCopy(gDisplayedStringBattle, sText_FollowMe);
                break;
            case Z_EFFECT_RECOVER_HP:
                StringCopy(gDisplayedStringBattle, sText_RecoverHP);
                break;
            case Z_EFFECT_RESTORE_REPLACEMENT_HP:
                StringCopy(gDisplayedStringBattle, sText_HealAllyHP);
                break;
            case Z_EFFECT_ATK_UP_1:
            case Z_EFFECT_DEF_UP_1:
            case Z_EFFECT_SPD_UP_1:
            case Z_EFFECT_SPATK_UP_1:
            case Z_EFFECT_SPDEF_UP_1:
            case Z_EFFECT_ACC_UP_1:
            case Z_EFFECT_EVSN_UP_1:
                gDisplayedStringBattle[0] = CHAR_PLUS;
                gDisplayedStringBattle[1] = 0;
                gDisplayedStringBattle[2] = EOS;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, zEffect - Z_EFFECT_ATK_UP_1 + 1);
                ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gDisplayedStringBattle + 2);
                break;
            case Z_EFFECT_ATK_UP_2:
            case Z_EFFECT_DEF_UP_2:
            case Z_EFFECT_SPD_UP_2:
            case Z_EFFECT_SPATK_UP_2:
            case Z_EFFECT_SPDEF_UP_2:
            case Z_EFFECT_ACC_UP_2:
            case Z_EFFECT_EVSN_UP_2:
                gDisplayedStringBattle[0] = CHAR_PLUS;
                gDisplayedStringBattle[1] = CHAR_PLUS;
                gDisplayedStringBattle[2] = 0;
                gDisplayedStringBattle[3] = EOS;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, zEffect - Z_EFFECT_ATK_UP_2 + 1);
                ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gDisplayedStringBattle + 3);
                break;
            case Z_EFFECT_ATK_UP_3:
            case Z_EFFECT_DEF_UP_3:
            case Z_EFFECT_SPD_UP_3:
            case Z_EFFECT_SPATK_UP_3:
            case Z_EFFECT_SPDEF_UP_3:
            case Z_EFFECT_ACC_UP_3:
            case Z_EFFECT_EVSN_UP_3:
                gDisplayedStringBattle[0] = CHAR_PLUS;
                gDisplayedStringBattle[1] = CHAR_PLUS;
                gDisplayedStringBattle[2] = CHAR_PLUS;
                gDisplayedStringBattle[3] = 0;
                gDisplayedStringBattle[4] = EOS;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, zEffect - Z_EFFECT_ATK_UP_3 + 1);
                ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gDisplayedStringBattle + 4);
                break;
            }

            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_NAME_3);
            gDisplayedStringBattle[0] = CHAR_Z;
            gDisplayedStringBattle[1] = CHAR_HYPHEN;
            StringCopy(gDisplayedStringBattle + 2, GetMoveName(move));
        }
        else if (zmove == MOVE_EXTREME_EVOBOOST)
        {
            // Damaging move -> status z move
            StringCopy(gDisplayedStringBattle, sText_StatsPlus2);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_NAME_3);
            StringCopy(gDisplayedStringBattle, GetMoveName(zmove));
        }
        else
        {
            ZMoveSelectionDisplayPower(move, zmove);
            StringCopy(gDisplayedStringBattle, GetMoveName(zmove));
        }
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_NAME_1);

        ZMoveSelectionDisplayPpNumber(battler);
        ZMoveSelectionDisplayMoveType(zmove, battler);
        MoveSelectionCreateCursorAt(0, 0);
        return TRUE;
    }

    return FALSE;
}

static void ZMoveSelectionDisplayPower(u16 move, u16 zMove)
{
    u8 *txtPtr;
    u16 power = GetZMovePower(move);

    if (zMove >= MOVE_CATASTROPIKA)
        power = gMovesInfo[zMove].power;

    if (gMovesInfo[move].category != DAMAGE_CATEGORY_STATUS)
    {
        txtPtr = StringCopy(gDisplayedStringBattle, sText_PowerColon);
        ConvertIntToDecimalStringN(txtPtr, power, STR_CONV_MODE_LEFT_ALIGN, 3);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_NAME_3);
    }
}

static void ZMoveSelectionDisplayPpNumber(u32 battler)
{
    u8 *txtPtr;

    if (gBattleResources->bufferA[battler][2] == TRUE) // Check if we didn't want to display pp number
        return;

    SetPpNumbersPaletteInMoveSelection(battler);
    txtPtr = ConvertIntToDecimalStringN(gDisplayedStringBattle, 1, STR_CONV_MODE_RIGHT_ALIGN, 2);
    *(txtPtr)++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, 1, STR_CONV_MODE_RIGHT_ALIGN, 2);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP_REMAINING);
}

static void ZMoveSelectionDisplayMoveType(u16 zMove, u32 battler)
{
    u8 *txtPtr;
    u8 zMoveType;

    GET_MOVE_TYPE(zMove, zMoveType);

    txtPtr = StringCopy(gDisplayedStringBattle, gText_MoveInterfaceType);
    *(txtPtr)++ = EXT_CTRL_CODE_BEGIN;
    *(txtPtr)++ = EXT_CTRL_CODE_FONT;
    *(txtPtr)++ = FONT_NORMAL;

    StringCopy(txtPtr, gTypesInfo[zMoveType].name);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_TYPE);
}

#define Z_EFFECT_BS_LENGTH  5
// This function kinda cheats by setting a return battle script to after the setzeffect various command
// and then jumping to a z effect script
void SetZEffect(void)
{
    u32 i;

    gBattleStruct->zmove.zStatusActive = TRUE;
    if (gBattleStruct->zmove.effect == Z_EFFECT_CURSE)
    {
        if (IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
            gBattleStruct->zmove.effect = Z_EFFECT_RECOVER_HP;
        else
            gBattleStruct->zmove.effect = Z_EFFECT_ATK_UP_1;
    }

    gBattleScripting.savedStatChanger = gBattleScripting.statChanger;   // Save used move's stat changer (e.g. for Z-Growl)
    gBattleScripting.battler = gBattlerAttacker;

    switch (gBattleStruct->zmove.effect)
    {
    case Z_EFFECT_RESET_STATS:
        for (i = 0; i < NUM_BATTLE_STATS - 1; i++)
        {
            if (gBattleMons[gBattlerAttacker].statStages[i] < DEFAULT_STAT_STAGE)
                gBattleMons[gBattlerAttacker].statStages[i] = DEFAULT_STAT_STAGE;
        }
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_RESET_STATS;
        BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
        gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        break;
    case Z_EFFECT_ALL_STATS_UP_1:
        if (!AreStatsMaxed(gBattlerAttacker, STAT_SPDEF))
        {
            for (i = 0; i < STAT_ACC - 1; i++) // Doesn't increase Acc or Evsn
            {
                if (gBattleMons[gBattlerAttacker].statStages[i] < 12)
                    ++gBattleMons[gBattlerAttacker].statStages[i];
            }
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_ALL_STATS_UP;
            BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
            gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        }
        else
        {
            gBattlescriptCurrInstr += Z_EFFECT_BS_LENGTH;
        }
        break;
    case Z_EFFECT_BOOST_CRITS:
        if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_FOCUS_ENERGY_ANY))
        {
            gBattleMons[gBattlerAttacker].status2 |= STATUS2_FOCUS_ENERGY;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_BOOST_CRITS;
            BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
            gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        }
        else
        {
            gBattlescriptCurrInstr += Z_EFFECT_BS_LENGTH;
        }
        break;
    case Z_EFFECT_FOLLOW_ME:
        gSideTimers[GetBattlerSide(gBattlerAttacker)].followmeTimer = 1;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].followmeTarget = gBattlerAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_FOLLOW_ME;
        BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
        gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        break;
    case Z_EFFECT_RECOVER_HP:
        if (gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP)
        {
            gBattleMoveDamage = (-1) * gBattleMons[gBattlerAttacker].maxHP;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_RECOVER_HP;
            BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
            gBattlescriptCurrInstr = BattleScript_RecoverHPZMove;
        }
        else
        {
            gBattlescriptCurrInstr += Z_EFFECT_BS_LENGTH;
        }
        break;
    case Z_EFFECT_RESTORE_REPLACEMENT_HP:
        gBattleStruct->zmove.healReplacement = TRUE;
        BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_HP_TRAP;
        gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        break;
    case Z_EFFECT_ATK_UP_1 ... Z_EFFECT_EVSN_UP_1:
        SET_STATCHANGER(gBattleStruct->zmove.effect - Z_EFFECT_ATK_UP_1 + 1, 1, FALSE);
        BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
        gBattlescriptCurrInstr = BattleScript_StatUpZMove;
        break;
    case Z_EFFECT_ATK_UP_2 ... Z_EFFECT_EVSN_UP_2:
        SET_STATCHANGER(gBattleStruct->zmove.effect - Z_EFFECT_ATK_UP_2 + 1, 2, FALSE);
        BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
        gBattlescriptCurrInstr = BattleScript_StatUpZMove;
        break;
    case Z_EFFECT_ATK_UP_3 ... Z_EFFECT_EVSN_UP_3:
        SET_STATCHANGER(gBattleStruct->zmove.effect - Z_EFFECT_ATK_UP_3 + 1, 3, FALSE);
        BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
        gBattlescriptCurrInstr = BattleScript_StatUpZMove;
        break;
    default:
        gBattlescriptCurrInstr += Z_EFFECT_BS_LENGTH;
        break;
    }

    gBattleStruct->zmove.zStatusActive = FALSE;
}

static bool32 AreStatsMaxed(u8 battler, u8 n)
{
    u32 i;
    for (i = STAT_ATK; i <= n; i++)
    {
        if (STAT_STAGE(battler, i) < MAX_STAT_STAGE)
            return FALSE;
    }
    return TRUE;
}

u16 GetZMovePower(u16 move)
{
    if (gMovesInfo[move].category == DAMAGE_CATEGORY_STATUS)
        return 0;
    if (gMovesInfo[move].effect == EFFECT_OHKO)
        return 180;

    if (gMovesInfo[move].zMove.powerOverride > 0)
        return gMovesInfo[move].zMove.powerOverride;
    else
    {
        if (gMovesInfo[move].power >= 140)
            return 200;
        else if (gMovesInfo[move].power >= 130)
            return 195;
        else if (gMovesInfo[move].power >= 120)
            return 190;
        else if (gMovesInfo[move].power >= 110)
            return 185;
        else if (gMovesInfo[move].power >= 100)
            return 180;
        else if (gMovesInfo[move].power >= 90)
            return 175;
        else if (gMovesInfo[move].power >= 80)
            return 160;
        else if (gMovesInfo[move].power >= 70)
            return 140;
        else if (gMovesInfo[move].power >= 60)
            return 120;
        else
            return 100;
    }
}

