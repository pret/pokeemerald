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
#include "constants/battle_config.h"
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
static u16 GetTypeBasedZMove(u16 move, u8 battler);
static void ZMoveSelectionDisplayPpNumber(void);
static void ZMoveSelectionDisplayPower(u16 move, u16 zMove);
static void ShowZMoveTriggerSprite(void);
static bool32 AreStatsMaxed(u8 battlerId, u8 n);
static u8 GetZMoveScore(u8 battlerAtk, u8 battlerDef, u16 baseMove, u16 zMove);

// Const Data
static const struct SignatureZMove sSignatureZMoves[] =
{
    #ifdef POKEMON_EXPANSION
    {SPECIES_PIKACHU_COSPLAY,       ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_ROCK_STAR,     ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_BELLE,         ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_POP_STAR,      ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_PH_D,          ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_LIBRE,         ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},

    {SPECIES_RAICHU_ALOLAN,         ITEM_ALORAICHIUM_Z,        MOVE_THUNDERBOLT,         MOVE_STOKED_SPARKSURFER},
    {SPECIES_DECIDUEYE,             ITEM_DECIDIUM_Z,           MOVE_SPIRIT_SHACKLE,      MOVE_SINISTER_ARROW_RAID},
    {SPECIES_INCINEROAR,            ITEM_INCINIUM_Z,           MOVE_DARKEST_LARIAT,      MOVE_MALICIOUS_MOONSAULT},
    {SPECIES_KOMMO_O,               ITEM_KOMMONIUM_Z,          MOVE_CLANGING_SCALES,     MOVE_CLANGOROUS_SOULBLAZE},
    {SPECIES_LUNALA,                ITEM_LUNALIUM_Z,           MOVE_MOONGEIST_BEAM,      MOVE_MENACING_MOONRAZE_MAELSTROM},
    {SPECIES_NECROZMA_DAWN_WINGS,   ITEM_LUNALIUM_Z,           MOVE_MOONGEIST_BEAM,      MOVE_MENACING_MOONRAZE_MAELSTROM},
    {SPECIES_LYCANROC,              ITEM_LYCANIUM_Z,           MOVE_STONE_EDGE,          MOVE_SPLINTERED_STORMSHARDS},
    {SPECIES_LYCANROC_MIDNIGHT,     ITEM_LYCANIUM_Z,           MOVE_STONE_EDGE,          MOVE_SPLINTERED_STORMSHARDS},

    {SPECIES_LYCANROC_DUSK,         ITEM_LYCANIUM_Z,           MOVE_STONE_EDGE,          MOVE_SPLINTERED_STORMSHARDS},
    {SPECIES_MARSHADOW,             ITEM_MARSHADIUM_Z,         MOVE_SPECTRAL_THIEF,      MOVE_SOUL_STEALING_7_STAR_STRIKE},
    {SPECIES_MIMIKYU,               ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_MIMIKYU_BUSTED,        ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_PIKACHU_ORIGINAL_CAP,  ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_HOENN_CAP,     ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_SINNOH_CAP,    ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_UNOVA_CAP,     ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_KALOS_CAP,     ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_ALOLA_CAP,     ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_PARTNER_CAP,   ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_WORLD_CAP,     ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PRIMARINA,             ITEM_PRIMARIUM_Z,          MOVE_SPARKLING_ARIA,      MOVE_OCEANIC_OPERETTA},
    {SPECIES_SOLGALEO,              ITEM_SOLGANIUM_Z,          MOVE_SUNSTEEL_STRIKE,     MOVE_SEARING_SUNRAZE_SMASH},
    {SPECIES_NECROZMA_DUSK_MANE,    ITEM_SOLGANIUM_Z,          MOVE_SUNSTEEL_STRIKE,     MOVE_SEARING_SUNRAZE_SMASH},
    {SPECIES_TAPU_KOKO,             ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_TAPU_BULU,             ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_TAPU_LELE,             ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_TAPU_FINI,             ITEM_TAPUNIUM_Z,           MOVE_NATURES_MADNESS,     MOVE_GUARDIAN_OF_ALOLA},
    {SPECIES_NECROZMA_ULTRA,        ITEM_ULTRANECROZIUM_Z,     MOVE_PHOTON_GEYSER,       MOVE_LIGHT_THAT_BURNS_THE_SKY},
    #endif
    {SPECIES_MEW,                   ITEM_MEWNIUM_Z,            MOVE_PSYCHIC,             MOVE_GENESIS_SUPERNOVA},
    {SPECIES_PIKACHU,               ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_EEVEE,                 ITEM_EEVIUM_Z,             MOVE_LAST_RESORT,         MOVE_EXTREME_EVOBOOST},
    {SPECIES_SNORLAX,               ITEM_SNORLIUM_Z,           MOVE_GIGA_IMPACT,         MOVE_PULVERIZING_PANCAKE},
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

void QueueZMove(u8 battlerId, u16 baseMove)
{
    gBattleStruct->zmove.toBeUsed[battlerId] = gBattleStruct->zmove.chosenZMove;
    gBattleStruct->zmove.baseMoves[battlerId] = baseMove;
    if (gBattleStruct->zmove.chosenZMove == MOVE_LIGHT_THAT_BURNS_THE_SKY)
        gBattleStruct->zmove.splits[battlerId] = GetSplitBasedOnStats(battlerId);
    else
        gBattleStruct->zmove.splits[battlerId] = gBattleMoves[baseMove].split;
}

bool32 IsViableZMove(u8 battlerId, u16 move)
{
    struct Pokemon *mon;
    struct MegaEvolutionData *mega = &(((struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]))->mega);
    u8 battlerPosition = GetBattlerPosition(battlerId);
    u8 partnerPosition = GetBattlerPosition(BATTLE_PARTNER(battlerId));
    u32 item;
    u16 holdEffect;
    u16 species;
    
    if (gBattleStruct->zmove.used[battlerId])
        return FALSE;
    
    species = gBattleMons[battlerId].species;
    item = gBattleMons[battlerId].item;
    if (gBattleTypeFlags & (BATTLE_TYPE_SAFARI | BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_FRONTIER))
        return FALSE;
    
    #ifdef ITEM_Z_RING
    if ((GetBattlerPosition(battlerId) == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && GetBattlerPosition(battlerId) == B_POSITION_PLAYER_RIGHT)) && !CheckBagHasItem(ITEM_Z_RING, 1))
        return FALSE;
    #endif
    
    if (mega->alreadyEvolved[battlerPosition])
        return FALSE;   // Trainer has mega evolved
    
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (IsPartnerMonFromSameTrainer(battlerId) && (mega->alreadyEvolved[partnerPosition] || (mega->toEvolve & gBitTable[BATTLE_PARTNER(battlerId)])))
            return FALSE;   // Partner has mega evolved or is about to mega evolve
    }
    
    if (B_ENABLE_DEBUG && gBattleStruct->debugHoldEffects[battlerId])
        holdEffect = gBattleStruct->debugHoldEffects[battlerId];
    else if (item == ITEM_ENIGMA_BERRY)
        return FALSE;   // HoldEffect = gEnigmaBerries[battlerId].holdEffect; 
    else
        holdEffect = ItemId_GetHoldEffect(item);
    
    #ifdef ITEM_ULTRANECROZIUM_Z
    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL || item == ITEM_ULTRANECROZIUM_Z)
    #else
    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
    #endif
    {
        u16 zMove = GetSignatureZMove(move, gBattleMons[battlerId].species, item);
        if (zMove != MOVE_NONE)
        {
            gBattleStruct->zmove.chosenZMove = zMove;  // Signature z move exists
            return TRUE;
        }
        
        if (move != MOVE_NONE && zMove != MOVE_Z_STATUS && gBattleMoves[move].type == ItemId_GetSecondaryId(item))
        {
            if (IS_MOVE_STATUS(gBattleMoves[move].split))
                gBattleStruct->zmove.chosenZMove = move;
            else
                gBattleStruct->zmove.chosenZMove = GetTypeBasedZMove(move, battlerId);
            
            return TRUE;
        }
    }
    
    return FALSE;
}

void GetUsableZMoves(u8 battlerId, u16 *moves)
{
    u32 i;
    gBattleStruct->zmove.possibleZMoves[battlerId] = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && IsViableZMove(battlerId, moves[i]))
            gBattleStruct->zmove.possibleZMoves[battlerId] |= (1 << i);
    }
}

bool32 IsZMoveUsable(u8 battlerId, u16 moveIndex)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && IsPartnerMonFromSameTrainer(battlerId) && gBattleStruct->zmove.toBeUsed[BATTLE_PARTNER(battlerId)] != MOVE_NONE)
        return FALSE;   // Player's other mon has a z move queued up already
    if (gBattleStruct->zmove.possibleZMoves[battlerId] & (1 << moveIndex))
        return TRUE;
    return FALSE;
}

bool32 TryChangeZIndicator(u8 battlerId, u8 moveIndex)
{
    bool32 viableZMove = IsZMoveUsable(battlerId, moveIndex);
    
    if (gBattleStruct->zmove.viable && !viableZMove)
        HideZMoveTriggerSprite();   // Was a viable z move, now is not -> slide out
    else if (!gBattleStruct->zmove.viable && viableZMove)
        ShowZMoveTriggerSprite();   // Was not a viable z move, now is -> slide back in
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

void CreateZMoveTriggerSprite(u8 battlerId, bool8 viable)
{
    s16 x, y;
    
    LoadSpritePalette(&sSpritePalette_ZMoveTrigger);
    if (GetSpriteTileStartByTag(TAG_ZMOVE_TRIGGER_TILE) == 0xFFFF)
        LoadCompressedSpriteSheetUsingHeap(&sSpriteSheet_ZMoveTrigger);
    
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        x = gSprites[gHealthboxSpriteIds[battlerId]].x - DOUBLES_Z_TRIGGER_POS_X_SLIDE;
        y = gSprites[gHealthboxSpriteIds[battlerId]].y - DOUBLES_Z_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        x = gSprites[gHealthboxSpriteIds[battlerId]].x - SINGLES_Z_TRIGGER_POS_X_SLIDE;
        y = gSprites[gHealthboxSpriteIds[battlerId]].y - SINGLES_Z_TRIGGER_POS_Y_DIFF, 0;
    }
    
    if (gBattleStruct->zmove.triggerSpriteId == 0xFF)
        gBattleStruct->zmove.triggerSpriteId = CreateSprite(&sSpriteTemplate_ZMoveTrigger, x, y, 0);
    
    gSprites[gBattleStruct->zmove.triggerSpriteId].tBattler = battlerId;
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
    struct Sprite *sprite = &gSprites[gBattleStruct->zmove.triggerSpriteId];
    sprite->tHide = TRUE;
    gBattleStruct->zmove.viable = FALSE;
}

static void ShowZMoveTriggerSprite(void)
{
    struct Sprite *sprite = &gSprites[gBattleStruct->zmove.triggerSpriteId];
    gBattleStruct->zmove.viable = TRUE;
    CreateZMoveTriggerSprite(sprite->tBattler, TRUE);
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

static u16 GetTypeBasedZMove(u16 move, u8 battler)
{
    u8 moveType = gBattleMoves[move].type;
    
    // Get z move from type
    if (moveType < TYPE_FIRE)
        return MOVE_BREAKNECK_BLITZ + moveType;
    else if (moveType >= TYPE_FAIRY)
        return MOVE_TWINKLE_TACKLE + (moveType - TYPE_FAIRY);
    else
        return MOVE_BREAKNECK_BLITZ + (moveType - 1);
}

bool32 MoveSelectionDisplayZMove(u16 zmove)
{
    u32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]);
    u16 move = moveInfo->moves[gMoveSelectionCursor[gActiveBattler]];
    
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
            u8 zEffect = gBattleMoves[move].zMoveEffect;
            
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
            
            BattlePutTextOnWindow(gDisplayedStringBattle, 5); // Slot of Move 3
            gDisplayedStringBattle[0] = CHAR_Z;
            gDisplayedStringBattle[1] = CHAR_HYPHEN;
            StringCopy(gDisplayedStringBattle + 2, gMoveNames[move]);
        }
        else if (zmove == MOVE_EXTREME_EVOBOOST)
        {
            // Damaging move -> status z move
            StringCopy(gDisplayedStringBattle, sText_StatsPlus2);
            BattlePutTextOnWindow(gDisplayedStringBattle, 5); // Slot of Move 3
            StringCopy(gDisplayedStringBattle, GetZMoveName(zmove));
        }
        else
        {
            ZMoveSelectionDisplayPower(move, zmove);
            StringCopy(gDisplayedStringBattle, GetZMoveName(zmove));
        }
        BattlePutTextOnWindow(gDisplayedStringBattle, 3);   // First move slot

        ZMoveSelectionDisplayPpNumber();
        MoveSelectionCreateCursorAt(0, 0);
        return TRUE;
    }

    return FALSE;
}

static void ZMoveSelectionDisplayPower(u16 move, u16 zMove)
{
    u8 *txtPtr;
    u16 power = gBattleMoves[move].zMovePower;

    if (zMove >= MOVE_CATASTROPIKA)
        power = gBattleMoves[zMove].power;

    if (gBattleMoves[move].split != SPLIT_STATUS)
    {
        txtPtr = StringCopy(gDisplayedStringBattle, sText_PowerColon);
        ConvertIntToDecimalStringN(txtPtr, power, STR_CONV_MODE_LEFT_ALIGN, 3);
        BattlePutTextOnWindow(gDisplayedStringBattle, 5); // Bottom left
    }
}

static void ZMoveSelectionDisplayPpNumber(void)
{
    u8 *txtPtr;
    struct ChooseMoveStruct *moveInfo;

    if (gBattleResources->bufferA[gActiveBattler][2] == TRUE) // Check if we didn't want to display pp number
        return;

    SetPpNumbersPaletteInMoveSelection();
    moveInfo = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]);
    txtPtr = ConvertIntToDecimalStringN(gDisplayedStringBattle, 1, STR_CONV_MODE_RIGHT_ALIGN, 2);
    *(txtPtr)++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, 1, STR_CONV_MODE_RIGHT_ALIGN, 2);
    BattlePutTextOnWindow(gDisplayedStringBattle, 9);
}

const u8* GetZMoveName(u16 move)
{
    if (IsZMove(move))
        return gZMoveNames[move - FIRST_Z_MOVE];
    else
        return gZMoveNames[0];   // Failsafe
}

#define Z_EFFECT_BS_LENGTH  3
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
        break;
    case Z_EFFECT_BOOST_CRITS:
        if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_FOCUS_ENERGY))
        {
            gBattleMons[gBattlerAttacker].status2 |= STATUS2_FOCUS_ENERGY;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_BOOST_CRITS;
            BattleScriptPush(gBattlescriptCurrInstr + Z_EFFECT_BS_LENGTH);
            gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
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
        gBattlescriptCurrInstr += 3;
        break;
    }
    
    gBattleStruct->zmove.zStatusActive = FALSE;
}

static bool32 AreStatsMaxed(u8 battlerId, u8 n)
{
    u32 i;
    for (i = STAT_ATK; i <= n; i++)
    {
        if (STAT_STAGE(battlerId, i) < MAX_STAT_STAGE)
            return FALSE;
    }
    return TRUE;
}

