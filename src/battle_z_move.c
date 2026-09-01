#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_ai_record.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_z_move.h"
#include "battle_scripts.h"
#include "battle_stat_change.h"
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
#include "constants/battle_string_ids.h"
#include "constants/battle_move_effects.h"
#include "constants/abilities.h"
#include "constants/moves.h"

#define STAT_STAGE(battler, stat) (gBattleMons[battler].statStages[stat - 1])

// Function Declarations
static void ZMoveSelectionDisplayPpNumber(enum BattlerId battler);
static void ZMoveSelectionDisplayPower(enum Move move, enum Move zMove);
static void ZMoveSelectionDisplayMoveType(enum Move zMove, enum BattlerId battler);

// Const Data
static const struct SignatureZMove sSignatureZMoves[] =
{
    {SPECIES_PIKACHU_COSPLAY,         ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_ROCK_STAR,       ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_BELLE,           ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_POP_STAR,        ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_PHD,             ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},
    {SPECIES_PIKACHU_LIBRE,           ITEM_PIKANIUM_Z,           MOVE_VOLT_TACKLE,         MOVE_CATASTROPIKA},

    {SPECIES_RAICHU_ALOLA,            ITEM_ALORAICHIUM_Z,        MOVE_THUNDERBOLT,         MOVE_STOKED_SPARKSURFER},
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
    {SPECIES_MIMIKYU_BUSTED_TOTEM,    ITEM_MIMIKIUM_Z,           MOVE_PLAY_ROUGH,          MOVE_LETS_SNUGGLE_FOREVER},
    {SPECIES_PIKACHU_ORIGINAL,        ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_HOENN,           ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_SINNOH,          ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_UNOVA,           ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_KALOS,           ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_ALOLA,           ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_PARTNER,         ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
    {SPECIES_PIKACHU_WORLD,           ITEM_PIKASHUNIUM_Z,        MOVE_THUNDERBOLT,         MOVE_10000000_VOLT_THUNDERBOLT},
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
static const u8 sText_NoAdditionalEffect[] = _("No Additional Effect");

// Functions
bool32 IsZMove(enum Move move)
{
    return move >= FIRST_Z_MOVE && move <= LAST_Z_MOVE;
}

bool32 CanUseZMove(enum BattlerId battler)
{
    enum HoldEffect holdEffect = GetBattlerHoldEffectIgnoreNegation(battler);
    enum BattlerPosition position = GetBattlerPosition(battler);

    // Check if Player has Z-Power Ring.
    if (!TESTING && (position == B_POSITION_PLAYER_LEFT
        || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && position == B_POSITION_PLAYER_RIGHT))
        && !CheckBagHasItem(ITEM_Z_POWER_RING, 1))
        return FALSE;

    // Add '| BATTLE_TYPE_FRONTIER' to below if issues occur
    if (gBattleTypeFlags & (BATTLE_TYPE_SAFARI | BATTLE_TYPE_CATCH_TUTORIAL))
        return FALSE;

    // Check if Trainer has already used a Z-Move.
    if (HasTrainerUsedGimmick(battler, GIMMICK_Z_MOVE))
        return FALSE;

    // Check if battler has another gimmick active.
    if (GetActiveGimmick(battler) != GIMMICK_NONE && GetActiveGimmick(battler) != GIMMICK_ULTRA_BURST)
        return FALSE;

    // Check if battler isn't holding a Z-Crystal.
    if (holdEffect != HOLD_EFFECT_Z_CRYSTAL)
        return FALSE;

    // All checks passed!
    return TRUE;
}

enum Move GetUsableZMove(enum BattlerId battler, enum Move move)
{
    enum Item item = gBattleMons[battler].item;
    enum HoldEffect holdEffect = GetBattlerHoldEffectIgnoreNegation(battler);

    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
    {
        enum Move zMove = GetSignatureZMove(move, gBattleMons[battler].species, item);
        if (zMove != MOVE_NONE)
            return zMove;  // Signature z move exists

        if (move != MOVE_NONE && zMove != MOVE_Z_STATUS && GetMoveType(move) == GetItemSecondaryId(item))
            return GetTypeBasedZMove(move);
    }

    return MOVE_NONE;
}

void ActivateZMove(enum BattlerId battler)
{
    SetActiveGimmick(battler, GIMMICK_Z_MOVE);
}

bool32 IsViableZMove(enum BattlerId battler, enum Move move)
{
    enum Item item;
    enum HoldEffect holdEffect = GetBattlerHoldEffectIgnoreNegation(battler);
    int moveSlotIndex;

    item = gBattleMons[battler].item;

    if (gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_Z_MOVE)
        return FALSE;

    for (moveSlotIndex = 0; moveSlotIndex < MAX_MON_MOVES; moveSlotIndex++)
    {
        if (gBattleMons[battler].moves[moveSlotIndex] == move && gBattleMons[battler].pp[moveSlotIndex] == 0)
            return FALSE;
    }

    enum BattlerPosition position = GetBattlerPosition(battler);
    // Check if Player has Z-Power Ring.
    if ((position == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && position == B_POSITION_PLAYER_RIGHT))
        && !CheckBagHasItem(ITEM_Z_POWER_RING, 1))
    {
        return FALSE;
    }

    // Check for signature Z-Move or type-based Z-Move.
    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
    {
        enum Move zMove = GetSignatureZMove(move, gBattleMons[battler].species, item);
        if (zMove != MOVE_NONE)
            return TRUE;

        if (move != MOVE_NONE && GetMoveType(move) == GetItemSecondaryId(item))
            return TRUE;
    }

    return FALSE;
}

void AssignUsableZMoves(enum BattlerId battler, enum Move *moves)
{
    u32 i;
    gBattleStruct->zmove.possibleZMoves[battler] = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && IsViableZMove(battler, moves[i]))
            gBattleStruct->zmove.possibleZMoves[battler] |= 1u << i;
    }
}

bool32 TryChangeZTrigger(enum BattlerId battler, u32 moveIndex)
{
    bool32 viableZMove = (gBattleStruct->zmove.possibleZMoves[battler] & (1u << moveIndex)) != 0;

    if (gBattleStruct->zmove.viable && !viableZMove)
        HideGimmickTriggerSprite();   // Was a viable z move, now is not -> slide out
    else if (!gBattleStruct->zmove.viable && viableZMove)
        CreateGimmickTriggerSprite(battler);   // Was not a viable z move, now is -> slide back in

    gBattleStruct->zmove.viable = viableZMove;

    return viableZMove;
}

enum Move GetSignatureZMove(enum Move move, enum Species species, enum Item item)
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

enum Move GetTypeBasedZMove(enum Move move)
{
    enum Type moveType = GetMoveType(move);

    if (moveType >= NUMBER_OF_MON_TYPES)
        moveType = TYPE_MYSTERY;

    // Z-Weather Ball changes types, however Revelation Dance, -ate ability affected moves, and Hidden Power do not
    if (gBattleStruct->dynamicMoveType && GetMoveEffect(move) == EFFECT_WEATHER_BALL)
        moveType = gBattleStruct->dynamicMoveType;

    // Get Z-Move from type
    if (gTypesInfo[moveType].zMove == MOVE_NONE) // failsafe
        return gTypesInfo[0].zMove;
    return gTypesInfo[moveType].zMove;
}

bool32 MoveSelectionDisplayZMove(enum Move zmove, enum BattlerId battler)
{
    u32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    enum Move move = moveInfo->moves[gMoveSelectionCursor[battler]];

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

        if (IsBattleMoveStatus(move))
        {
            enum ZEffect zEffect = GetMoveZEffect(move);

            gDisplayedStringBattle[0] = EOS;

            if (zEffect == Z_EFFECT_CURSE)
            {
                if (moveInfo->monTypes[0] == TYPE_GHOST || moveInfo->monTypes[1] == TYPE_GHOST || moveInfo->monTypes[2] == TYPE_GHOST)
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
            default:
                if (B_SHOW_USELESS_Z_MOVE_INFO == TRUE)
                    StringCopy(gDisplayedStringBattle, sText_NoAdditionalEffect);
                break;
            }

            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_NAME_3);
            gDisplayedStringBattle[0] = CHAR_Z;
            gDisplayedStringBattle[1] = CHAR_HYPHEN;
            StringCopy(gDisplayedStringBattle + 2, GetMoveName(move));
        }
        else if (GetMoveEffect(zmove) == EFFECT_EXTREME_EVOBOOST)
        {
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

static void ZMoveSelectionDisplayPower(enum Move move, enum Move zMove)
{
    u8 *txtPtr;
    u16 power = GetZMovePower(move);

    if (zMove >= MOVE_CATASTROPIKA)
        power = GetMovePower(zMove);

    if (GetMoveCategory(move) != DAMAGE_CATEGORY_STATUS)
    {
        txtPtr = StringCopy(gDisplayedStringBattle, sText_PowerColon);
        ConvertIntToDecimalStringN(txtPtr, power, STR_CONV_MODE_LEFT_ALIGN, 3);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_NAME_3);
    }
}

static void ZMoveSelectionDisplayPpNumber(enum BattlerId battler)
{
    u8 *txtPtr;

    if (gBattleResources->bufferA[battler][2] == TRUE) // Check if we didn't want to display pp number
        return;

    SetPPNumbersPaletteInMoveSelection(battler);
    txtPtr = ConvertIntToDecimalStringN(gDisplayedStringBattle, 1, STR_CONV_MODE_RIGHT_ALIGN, 2);
    *(txtPtr)++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, 1, STR_CONV_MODE_RIGHT_ALIGN, 2);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP_REMAINING);
}

static void ZMoveSelectionDisplayMoveType(enum Move zMove, enum BattlerId battler)
{
    u8 *txtPtr, *end;
    enum Type zMoveType = GetBattleMoveType(zMove);

    txtPtr = StringCopy(gDisplayedStringBattle, gText_MoveInterfaceType);
    *(txtPtr)++ = EXT_CTRL_CODE_BEGIN;
    *(txtPtr)++ = EXT_CTRL_CODE_FONT;
    *(txtPtr)++ = FONT_NORMAL;

    end = StringCopy(txtPtr, gTypesInfo[zMoveType].name);
    PrependFontIdToFit(txtPtr, end, FONT_NORMAL, WindowWidthPx(B_WIN_MOVE_TYPE) - 25);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_TYPE);
}

#define Z_EFFECT_BS_LENGTH  5
// This function kinda cheats by setting a return battle script to after the setzeffect various command
// and then jumping to a z effect script
void SetZEffect(const u8 *nextInstr)
{
    u32 i;
    s32 stage = 0;
    enum ZEffect effect = GetMoveZEffect(gChosenMove);

    if (effect == Z_EFFECT_CURSE)
    {
        if (IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
            effect = Z_EFFECT_RECOVER_HP;
        else
            effect = Z_EFFECT_ATK_UP_1;
    }

    switch (effect)
    {
    case Z_EFFECT_RESET_STATS:
        for (i = 0; i < NUM_BATTLE_STATS - 1; i++)
        {
            if (gBattleMons[gBattlerAttacker].statStages[i] < DEFAULT_STAT_STAGE)
                gBattleMons[gBattlerAttacker].statStages[i] = DEFAULT_STAT_STAGE;
        }
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_RESET_STATS;
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        break;
    case Z_EFFECT_ALL_STATS_UP_1:
    {
        bool32 canBoost = FALSE;
        for (i = STAT_ATK; i < NUM_STATS; i++) // Doesn't increase Acc or Evsn
        {
            if (STAT_STAGE(gBattlerAttacker, i) < 12)
            {
                canBoost = TRUE;
            }
        }
        if (canBoost)
        {
            SetStatChange(gBattlerAttacker, STAT_ATK, 1);
            SetStatChange(gBattlerAttacker, STAT_DEF, 1);
            SetStatChange(gBattlerAttacker, STAT_SPATK, 1);
            SetStatChange(gBattlerAttacker, STAT_SPDEF, 1);
            SetStatChange(gBattlerAttacker, STAT_SPEED, 1);

            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_ALL_STATS_UP;
            BattleScriptPush(nextInstr);
            gBattlescriptCurrInstr = BattleScript_AllStatsUpZMove;
        }
        else
        {
            gBattlescriptCurrInstr += Z_EFFECT_BS_LENGTH;
        }
        break;
    }
    case Z_EFFECT_BOOST_CRITS:
        if (!(gBattleMons[gBattlerAttacker].volatiles.dragonCheer || gBattleMons[gBattlerAttacker].volatiles.focusEnergy))
        {
            gBattleMons[gBattlerAttacker].volatiles.focusEnergy = TRUE;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_BOOST_CRITS;
            BattleScriptPush(nextInstr);
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
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        break;
    case Z_EFFECT_RECOVER_HP:
        if (gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP)
        {
            SetHealAmount(gBattlerAttacker, gBattleMons[gBattlerAttacker].maxHP);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_RECOVER_HP;
            BattleScriptPush(nextInstr);
            gBattlescriptCurrInstr = BattleScript_RecoverHPZMove;
        }
        else
        {
            gBattlescriptCurrInstr += Z_EFFECT_BS_LENGTH;
        }
        break;
    case Z_EFFECT_RESTORE_REPLACEMENT_HP:
        gBattleStruct->zmove.healReplacement |= 1u << gBattlerAttacker;
        BattleScriptPush(nextInstr);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_HP_TRAP;
        gBattlescriptCurrInstr = BattleScript_ZEffectPrintString;
        break;
    case Z_EFFECT_ATK_UP_1:
    case Z_EFFECT_ATK_UP_2:
    case Z_EFFECT_ATK_UP_3:
        stage = effect - Z_EFFECT_ATK_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_ATK, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;
    case Z_EFFECT_DEF_UP_1:
    case Z_EFFECT_DEF_UP_2:
    case Z_EFFECT_DEF_UP_3:
        stage = effect - Z_EFFECT_DEF_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_DEF, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;
    case Z_EFFECT_SPD_UP_1:
    case Z_EFFECT_SPD_UP_2:
    case Z_EFFECT_SPD_UP_3:
        stage = effect - Z_EFFECT_SPD_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_SPEED, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;
    case Z_EFFECT_SPATK_UP_1:
    case Z_EFFECT_SPATK_UP_2:
    case Z_EFFECT_SPATK_UP_3:
        stage = effect - Z_EFFECT_SPATK_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_SPATK, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;
    case Z_EFFECT_SPDEF_UP_1:
    case Z_EFFECT_SPDEF_UP_2:
    case Z_EFFECT_SPDEF_UP_3:
        stage = effect - Z_EFFECT_SPDEF_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_SPDEF, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;

    case Z_EFFECT_ACC_UP_1:
    case Z_EFFECT_ACC_UP_2:
    case Z_EFFECT_ACC_UP_3:
        stage = effect - Z_EFFECT_ACC_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_ACC, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;
    case Z_EFFECT_EVSN_UP_1:
    case Z_EFFECT_EVSN_UP_2:
    case Z_EFFECT_EVSN_UP_3:
        stage = effect - Z_EFFECT_EVSN_UP_1 + 1;
        SetStatChange(gBattlerAttacker, STAT_EVASION, stage);
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        break;
    default:
        gBattlescriptCurrInstr = nextInstr;
        break;
    }
}

u32 GetZMovePower(enum Move move)
{
    if (GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS)
        return 0;
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    if (moveEffect == EFFECT_OHKO)
        return 180;

    u32 power = GetMoveZPowerOverride(move);
    if (power > 0)
        return power;

    power = GetMovePower(move);
    if      (power >= 140) return 200;
    else if (power >= 130) return 195;
    else if (power >= 120) return 190;
    else if (power >= 110) return 185;
    else if (power >= 100) return 180;
    else if (power >= 90)  return 175;
    else if (power >= 80)  return 160;
    else if (power >= 70)  return 140;
    else if (power >= 60)  return 120;
    else                   return 100;
}
