#include "global.h"
#include "battle.h"
#include "pokemon.h"
#include "pokemon_animation.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/species.h"

struct UnkAnimStruct
{
    u16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
    s16 field_8;
};

// this file's functions
static void pokemonanimfunc_00(struct Sprite *sprite);
static void pokemonanimfunc_01(struct Sprite *sprite);
static void pokemonanimfunc_02(struct Sprite *sprite);
static void pokemonanimfunc_03(struct Sprite *sprite);
static void pokemonanimfunc_04(struct Sprite *sprite);
static void pokemonanimfunc_05(struct Sprite *sprite);
static void pokemonanimfunc_06(struct Sprite *sprite);
static void pokemonanimfunc_07(struct Sprite *sprite);
static void pokemonanimfunc_08(struct Sprite *sprite);
static void pokemonanimfunc_09(struct Sprite *sprite);
static void pokemonanimfunc_0A(struct Sprite *sprite);
static void pokemonanimfunc_0B(struct Sprite *sprite);
static void pokemonanimfunc_0C(struct Sprite *sprite);
static void pokemonanimfunc_0D(struct Sprite *sprite);
static void pokemonanimfunc_0E(struct Sprite *sprite);
static void pokemonanimfunc_0F(struct Sprite *sprite);
static void pokemonanimfunc_10(struct Sprite *sprite);
static void pokemonanimfunc_11(struct Sprite *sprite);
static void pokemonanimfunc_12(struct Sprite *sprite);
static void pokemonanimfunc_13(struct Sprite *sprite);
static void pokemonanimfunc_14(struct Sprite *sprite);
static void pokemonanimfunc_15(struct Sprite *sprite);
static void pokemonanimfunc_16(struct Sprite *sprite);
static void pokemonanimfunc_17(struct Sprite *sprite);
static void pokemonanimfunc_18(struct Sprite *sprite);
static void pokemonanimfunc_19(struct Sprite *sprite);
static void pokemonanimfunc_1A(struct Sprite *sprite);
static void pokemonanimfunc_1B(struct Sprite *sprite);
static void pokemonanimfunc_1C(struct Sprite *sprite);
static void pokemonanimfunc_1D(struct Sprite *sprite);
static void pokemonanimfunc_1E(struct Sprite *sprite);
static void pokemonanimfunc_1F(struct Sprite *sprite);
static void pokemonanimfunc_20(struct Sprite *sprite);
static void pokemonanimfunc_21(struct Sprite *sprite);
static void pokemonanimfunc_22(struct Sprite *sprite);
static void pokemonanimfunc_23(struct Sprite *sprite);
static void pokemonanimfunc_24(struct Sprite *sprite);
static void pokemonanimfunc_25(struct Sprite *sprite);
static void pokemonanimfunc_26(struct Sprite *sprite);
static void pokemonanimfunc_27(struct Sprite *sprite);
static void pokemonanimfunc_28(struct Sprite *sprite);
static void pokemonanimfunc_29(struct Sprite *sprite);
static void pokemonanimfunc_2A(struct Sprite *sprite);
static void pokemonanimfunc_2B(struct Sprite *sprite);
static void pokemonanimfunc_2C(struct Sprite *sprite);
static void pokemonanimfunc_2D(struct Sprite *sprite);
static void pokemonanimfunc_2E(struct Sprite *sprite);
static void pokemonanimfunc_2F(struct Sprite *sprite);
static void pokemonanimfunc_30(struct Sprite *sprite);
static void pokemonanimfunc_31(struct Sprite *sprite);
static void pokemonanimfunc_32(struct Sprite *sprite);
static void pokemonanimfunc_33(struct Sprite *sprite);
static void pokemonanimfunc_34(struct Sprite *sprite);
static void pokemonanimfunc_35(struct Sprite *sprite);
static void pokemonanimfunc_36(struct Sprite *sprite);
static void pokemonanimfunc_37(struct Sprite *sprite);
static void pokemonanimfunc_38(struct Sprite *sprite);
static void pokemonanimfunc_39(struct Sprite *sprite);
static void pokemonanimfunc_3A(struct Sprite *sprite);
static void pokemonanimfunc_3B(struct Sprite *sprite);
static void pokemonanimfunc_3C(struct Sprite *sprite);
static void pokemonanimfunc_3D(struct Sprite *sprite);
static void pokemonanimfunc_3E(struct Sprite *sprite);
static void pokemonanimfunc_3F(struct Sprite *sprite);
static void pokemonanimfunc_40(struct Sprite *sprite);
static void pokemonanimfunc_41(struct Sprite *sprite);
static void pokemonanimfunc_42(struct Sprite *sprite);
static void pokemonanimfunc_43(struct Sprite *sprite);
static void pokemonanimfunc_44(struct Sprite *sprite);
static void pokemonanimfunc_45(struct Sprite *sprite);
static void pokemonanimfunc_46(struct Sprite *sprite);
static void pokemonanimfunc_47(struct Sprite *sprite);
static void pokemonanimfunc_48(struct Sprite *sprite);
static void pokemonanimfunc_49(struct Sprite *sprite);
static void pokemonanimfunc_4A(struct Sprite *sprite);
static void pokemonanimfunc_4B(struct Sprite *sprite);
static void pokemonanimfunc_4C(struct Sprite *sprite);
static void pokemonanimfunc_4D(struct Sprite *sprite);
static void pokemonanimfunc_4E(struct Sprite *sprite);
static void pokemonanimfunc_4F(struct Sprite *sprite);
static void pokemonanimfunc_50(struct Sprite *sprite);
static void pokemonanimfunc_51(struct Sprite *sprite);
static void pokemonanimfunc_52(struct Sprite *sprite);
static void pokemonanimfunc_53(struct Sprite *sprite);
static void pokemonanimfunc_54(struct Sprite *sprite);
static void pokemonanimfunc_55(struct Sprite *sprite);
static void pokemonanimfunc_56(struct Sprite *sprite);
static void pokemonanimfunc_57(struct Sprite *sprite);
static void pokemonanimfunc_58(struct Sprite *sprite);
static void pokemonanimfunc_59(struct Sprite *sprite);
static void pokemonanimfunc_5A(struct Sprite *sprite);
static void pokemonanimfunc_5B(struct Sprite *sprite);
static void pokemonanimfunc_5C(struct Sprite *sprite);
static void pokemonanimfunc_5D(struct Sprite *sprite);
static void pokemonanimfunc_5E(struct Sprite *sprite);
static void pokemonanimfunc_5F(struct Sprite *sprite);
static void pokemonanimfunc_60(struct Sprite *sprite);
static void pokemonanimfunc_61(struct Sprite *sprite);
static void pokemonanimfunc_62(struct Sprite *sprite);
static void pokemonanimfunc_63(struct Sprite *sprite);
static void pokemonanimfunc_64(struct Sprite *sprite);
static void pokemonanimfunc_65(struct Sprite *sprite);
static void pokemonanimfunc_66(struct Sprite *sprite);
static void pokemonanimfunc_67(struct Sprite *sprite);
static void pokemonanimfunc_68(struct Sprite *sprite);
static void pokemonanimfunc_69(struct Sprite *sprite);
static void pokemonanimfunc_6A(struct Sprite *sprite);
static void pokemonanimfunc_6B(struct Sprite *sprite);
static void pokemonanimfunc_6C(struct Sprite *sprite);
static void pokemonanimfunc_6D(struct Sprite *sprite);
static void pokemonanimfunc_6E(struct Sprite *sprite);
static void pokemonanimfunc_6F(struct Sprite *sprite);
static void pokemonanimfunc_70(struct Sprite *sprite);
static void pokemonanimfunc_71(struct Sprite *sprite);
static void pokemonanimfunc_72(struct Sprite *sprite);
static void pokemonanimfunc_73(struct Sprite *sprite);
static void pokemonanimfunc_74(struct Sprite *sprite);
static void pokemonanimfunc_75(struct Sprite *sprite);
static void pokemonanimfunc_76(struct Sprite *sprite);
static void pokemonanimfunc_77(struct Sprite *sprite);
static void pokemonanimfunc_78(struct Sprite *sprite);
static void pokemonanimfunc_79(struct Sprite *sprite);
static void pokemonanimfunc_7A(struct Sprite *sprite);
static void pokemonanimfunc_7B(struct Sprite *sprite);
static void pokemonanimfunc_7C(struct Sprite *sprite);
static void pokemonanimfunc_7D(struct Sprite *sprite);
static void pokemonanimfunc_7E(struct Sprite *sprite);
static void pokemonanimfunc_7F(struct Sprite *sprite);
static void pokemonanimfunc_80(struct Sprite *sprite);
static void pokemonanimfunc_81(struct Sprite *sprite);
static void pokemonanimfunc_82(struct Sprite *sprite);
static void pokemonanimfunc_83(struct Sprite *sprite);
static void pokemonanimfunc_84(struct Sprite *sprite);
static void pokemonanimfunc_85(struct Sprite *sprite);
static void pokemonanimfunc_86(struct Sprite *sprite);
static void pokemonanimfunc_87(struct Sprite *sprite);
static void pokemonanimfunc_88(struct Sprite *sprite);
static void pokemonanimfunc_89(struct Sprite *sprite);
static void pokemonanimfunc_8A(struct Sprite *sprite);
static void pokemonanimfunc_8B(struct Sprite *sprite);
static void pokemonanimfunc_8C(struct Sprite *sprite);
static void pokemonanimfunc_8D(struct Sprite *sprite);
static void pokemonanimfunc_8E(struct Sprite *sprite);
static void pokemonanimfunc_8F(struct Sprite *sprite);
static void pokemonanimfunc_90(struct Sprite *sprite);
static void pokemonanimfunc_91(struct Sprite *sprite);
static void pokemonanimfunc_92(struct Sprite *sprite);
static void pokemonanimfunc_93(struct Sprite *sprite);
static void pokemonanimfunc_94(struct Sprite *sprite);
static void pokemonanimfunc_95(struct Sprite *sprite);
static void pokemonanimfunc_96(struct Sprite *sprite);

static void SpriteCB_SetDummyOnAnimEnd(struct Sprite *sprite);

#define STRUCT_COUNT 4

// IWRAM bss
static struct UnkAnimStruct sUnknown_03001240[STRUCT_COUNT];
static u8 sUnknown_03001270;
static bool32 sUnknown_03001274;

// const rom data
static const u8 sSpeciesToBackAnimSet[] =
{
    [SPECIES_BULBASAUR] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_IVYSAUR] = BACK_ANIM_H_SLIDE,
    [SPECIES_VENUSAUR] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_CHARMANDER] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_CHARMELEON] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_CHARIZARD] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_SQUIRTLE] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_WARTORTLE] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_BLASTOISE] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_CATERPIE] = BACK_ANIM_H_SLIDE,
    [SPECIES_METAPOD] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_BUTTERFREE] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_WEEDLE] = BACK_ANIM_H_SLIDE,
    [SPECIES_KAKUNA] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_BEEDRILL] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_PIDGEY] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_PIDGEOTTO] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_PIDGEOT] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_RATTATA] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_RATICATE] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_SPEAROW] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_FEAROW] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_EKANS] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_ARBOK] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_PIKACHU] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_RAICHU] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_SANDSHREW] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_SANDSLASH] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_NIDORAN_F] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_NIDORINA] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_NIDOQUEEN] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_NIDORAN_M] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_NIDORINO] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_NIDOKING] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_CLEFAIRY] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_CLEFABLE] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_VULPIX] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_NINETALES] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_JIGGLYPUFF] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_WIGGLYTUFF] = BACK_ANIM_GROW_1,
    [SPECIES_ZUBAT] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_GOLBAT] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_ODDISH] = BACK_ANIM_H_SLIDE,
    [SPECIES_GLOOM] = BACK_ANIM_H_SLIDE,
    [SPECIES_VILEPLUME] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_PARAS] = BACK_ANIM_H_SLIDE,
    [SPECIES_PARASECT] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_VENONAT] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_VENOMOTH] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_DIGLETT] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_DUGTRIO] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_MEOWTH] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_PERSIAN] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_PSYDUCK] = BACK_ANIM_H_SLIDE,
    [SPECIES_GOLDUCK] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_MANKEY] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_PRIMEAPE] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_GROWLITHE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_ARCANINE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_POLIWAG] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_POLIWHIRL] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_POLIWRATH] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_ABRA] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_KADABRA] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_ALAKAZAM] = BACK_ANIM_GROW_2,
    [SPECIES_MACHOP] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_MACHOKE] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_MACHAMP] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_BELLSPROUT] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_WEEPINBELL] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_VICTREEBEL] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_TENTACOOL] = BACK_ANIM_H_SLIDE,
    [SPECIES_TENTACRUEL] = BACK_ANIM_H_SLIDE,
    [SPECIES_GEODUDE] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_GRAVELER] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_GOLEM] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_PONYTA] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_RAPIDASH] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SLOWPOKE] = BACK_ANIM_H_SLIDE,
    [SPECIES_SLOWBRO] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_MAGNEMITE] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_MAGNETON] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_FARFETCHD] = BACK_ANIM_H_SLIDE,
    [SPECIES_DODUO] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_DODRIO] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SEEL] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_DEWGONG] = BACK_ANIM_H_SLIDE,
    [SPECIES_GRIMER] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_MUK] = BACK_ANIM_HORIZONTAL_STRETCH,
    [SPECIES_SHELLDER] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_CLOYSTER] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_GASTLY] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_HAUNTER] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_GENGAR] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_ONIX] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_DROWZEE] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_HYPNO] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_KRABBY] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_KINGLER] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_VOLTORB] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_ELECTRODE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_EXEGGCUTE] = BACK_ANIM_H_SLIDE,
    [SPECIES_EXEGGUTOR] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_CUBONE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_MAROWAK] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_HITMONLEE] = BACK_ANIM_H_SLIDE,
    [SPECIES_HITMONCHAN] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_LICKITUNG] = BACK_ANIM_H_SLIDE,
    [SPECIES_KOFFING] = BACK_ANIM_GROW_1,
    [SPECIES_WEEZING] = BACK_ANIM_GROW_1,
    [SPECIES_RHYHORN] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_RHYDON] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_CHANSEY] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_TANGELA] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_KANGASKHAN] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_HORSEA] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_SEADRA] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_GOLDEEN] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_SEAKING] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_STARYU] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_STARMIE] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_MR_MIME] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_SCYTHER] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_JYNX] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_ELECTABUZZ] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_MAGMAR] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_PINSIR] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_TAUROS] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_MAGIKARP] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_GYARADOS] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_LAPRAS] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_DITTO] = BACK_ANIM_SHRINK_GROW_1,
    [SPECIES_EEVEE] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_VAPOREON] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_JOLTEON] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_FLAREON] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_PORYGON] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_OMANYTE] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_OMASTAR] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_KABUTO] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_KABUTOPS] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_AERODACTYL] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SNORLAX] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_ARTICUNO] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_ZAPDOS] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_MOLTRES] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_DRATINI] = BACK_ANIM_H_SLIDE,
    [SPECIES_DRAGONAIR] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_DRAGONITE] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_MEWTWO] = BACK_ANIM_GROW_2,
    [SPECIES_MEW] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_CHIKORITA] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_BAYLEEF] = BACK_ANIM_H_SLIDE,
    [SPECIES_MEGANIUM] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_CYNDAQUIL] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_QUILAVA] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_TYPHLOSION] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_TOTODILE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_CROCONAW] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_FERALIGATR] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_SENTRET] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_FURRET] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_HOOTHOOT] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_NOCTOWL] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_LEDYBA] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_LEDIAN] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_SPINARAK] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_ARIADOS] = BACK_ANIM_H_SLIDE,
    [SPECIES_CROBAT] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_CHINCHOU] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_LANTURN] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_PICHU] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_CLEFFA] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_IGGLYBUFF] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_TOGEPI] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_TOGETIC] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_NATU] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_XATU] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_MAREEP] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_FLAAFFY] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_AMPHAROS] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_BELLOSSOM] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_MARILL] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_AZUMARILL] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_SUDOWOODO] = BACK_ANIM_H_SLIDE,
    [SPECIES_POLITOED] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_HOPPIP] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_SKIPLOOM] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_JUMPLUFF] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_AIPOM] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_SUNKERN] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_SUNFLORA] = BACK_ANIM_H_SLIDE,
    [SPECIES_YANMA] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_WOOPER] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_QUAGSIRE] = BACK_ANIM_H_SLIDE,
    [SPECIES_ESPEON] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_UMBREON] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_MURKROW] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_SLOWKING] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_MISDREAVUS] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_UNOWN] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_WOBBUFFET] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_GIRAFARIG] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_PINECO] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_FORRETRESS] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_DUNSPARCE] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_GLIGAR] = BACK_ANIM_SHRINK_GROW_1,
    [SPECIES_STEELIX] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_SNUBBULL] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_GRANBULL] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_QWILFISH] = BACK_ANIM_GROW_2,
    [SPECIES_SCIZOR] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SHUCKLE] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_HERACROSS] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SNEASEL] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_TEDDIURSA] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_URSARING] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_SLUGMA] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_MAGCARGO] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_SWINUB] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_PILOSWINE] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_CORSOLA] = BACK_ANIM_H_SLIDE,
    [SPECIES_REMORAID] = BACK_ANIM_H_SLIDE,
    [SPECIES_OCTILLERY] = BACK_ANIM_SHRINK_GROW_1,
    [SPECIES_DELIBIRD] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_MANTINE] = BACK_ANIM_H_SLIDE,
    [SPECIES_SKARMORY] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_HOUNDOUR] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_HOUNDOOM] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_KINGDRA] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_PHANPY] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_DONPHAN] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_PORYGON2] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_STANTLER] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_SMEARGLE] = BACK_ANIM_H_SLIDE,
    [SPECIES_TYROGUE] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_HITMONTOP] = BACK_ANIM_CIRCLE_MOVE_COUNTERCLOCKWISE,
    [SPECIES_SMOOCHUM] = BACK_ANIM_H_SLIDE,
    [SPECIES_ELEKID] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_MAGBY] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_MILTANK] = BACK_ANIM_H_SLIDE,
    [SPECIES_BLISSEY] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_RAIKOU] = BACK_ANIM_FLASH_YELLOW_WITH_SHAKE,
    [SPECIES_ENTEI] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_SUICUNE] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_LARVITAR] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_PUPITAR] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_TYRANITAR] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_LUGIA] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_HO_OH] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_CELEBI] = BACK_ANIM_FADE_GREEN_WITH_SHAKE,
    [SPECIES_TREECKO] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_GROVYLE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SCEPTILE] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_TORCHIC] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_COMBUSKEN] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_BLAZIKEN] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_MUDKIP] = BACK_ANIM_H_SLIDE,
    [SPECIES_MARSHTOMP] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_SWAMPERT] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_POOCHYENA] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_MIGHTYENA] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_ZIGZAGOON] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_LINOONE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_WURMPLE] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_SILCOON] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_BEAUTIFLY] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_CASCOON] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_DUSTOX] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_LOTAD] = BACK_ANIM_H_SLIDE,
    [SPECIES_LOMBRE] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_LUDICOLO] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_SEEDOT] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_NUZLEAF] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_SHIFTRY] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_NINCADA] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_NINJASK] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_SHEDINJA] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_TAILLOW] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_SWELLOW] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SHROOMISH] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_BRELOOM] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_SPINDA] = BACK_ANIM_CIRCLE_MOVE_COUNTERCLOCKWISE,
    [SPECIES_WINGULL] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_PELIPPER] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_SURSKIT] = BACK_ANIM_H_SLIDE_WITH_V_COMPRESS_1,
    [SPECIES_MASQUERAIN] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_WAILMER] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_WAILORD] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_SKITTY] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_DELCATTY] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_KECLEON] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_BALTOY] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_CLAYDOL] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_NOSEPASS] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_TORKOAL] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_SABLEYE] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_BARBOACH] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_WHISCASH] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_LUVDISC] = BACK_ANIM_H_SLIDE_WITH_V_COMPRESS_2,
    [SPECIES_CORPHISH] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_CRAWDAUNT] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_FEEBAS] = BACK_ANIM_H_SLIDE_WITH_V_COMPRESS_1,
    [SPECIES_MILOTIC] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_CARVANHA] = BACK_ANIM_H_SLIDE_WITH_V_COMPRESS_2,
    [SPECIES_SHARPEDO] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_TRAPINCH] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_VIBRAVA] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_FLYGON] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_MAKUHITA] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_HARIYAMA] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_ELECTRIKE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_MANECTRIC] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_NUMEL] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_CAMERUPT] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_SPHEAL] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_SEALEO] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_WALREIN] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_CACNEA] = BACK_ANIM_V_SHAKE_WITH_H_SLIDE,
    [SPECIES_CACTURNE] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_SNORUNT] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_GLALIE] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_LUNATONE] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_SOLROCK] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_AZURILL] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_SPOINK] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_GRUMPIG] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_PLUSLE] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_MINUN] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_MAWILE] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_MEDITITE] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_MEDICHAM] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_SWABLU] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_ALTARIA] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_WYNAUT] = BACK_ANIM_CONCAVE_UP_ARC_SWAY_LARGE,
    [SPECIES_DUSKULL] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_DUSCLOPS] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_ROSELIA] = BACK_ANIM_FADE_GREEN_WITH_SHAKE,
    [SPECIES_SLAKOTH] = BACK_ANIM_H_SLIDE,
    [SPECIES_VIGOROTH] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_SMALL,
    [SPECIES_SLAKING] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_GULPIN] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_SWALOT] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_TROPIUS] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_WHISMUR] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_LOUDRED] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_EXPLOUD] = BACK_ANIM_GROW_2,
    [SPECIES_CLAMPERL] = BACK_ANIM_DIP_RIGHT_SIDE,
    [SPECIES_HUNTAIL] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_GOREBYSS] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_ABSOL] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_SHUPPET] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_BANETTE] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_SEVIPER] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_ZANGOOSE] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_RELICANTH] = BACK_ANIM_H_SLIDE,
    [SPECIES_ARON] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_LAIRON] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_AGGRON] = BACK_ANIM_V_SHAKE_WITH_PAUSE,
    [SPECIES_CASTFORM] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_VOLBEAT] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_ILLUMISE] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_LILEEP] = BACK_ANIM_HORIZONTAL_STRETCH,
    [SPECIES_CRADILY] = BACK_ANIM_VERTICAL_STRETCH,
    [SPECIES_ANORITH] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_ARMALDO] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_RALTS] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_KIRLIA] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_GARDEVOIR] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_BAGON] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_SHELGON] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_SALAMENCE] = BACK_ANIM_HORIZONTAL_SHAKE,
    [SPECIES_BELDUM] = BACK_ANIM_CIRCLE_MOVE_CLOCKWISE,
    [SPECIES_METANG] = BACK_ANIM_JOLT_RIGHT,
    [SPECIES_METAGROSS] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_REGIROCK] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_REGICE] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_REGISTEEL] = BACK_ANIM_VERTICAL_SHAKE,
    [SPECIES_KYOGRE] = BACK_ANIM_FADE_BLUE_WITH_SHAKE,
    [SPECIES_GROUDON] = BACK_ANIM_FADE_RED_WITH_SHAKE,
    [SPECIES_RAYQUAZA] = BACK_ANIM_GROW_2,
    [SPECIES_LATIAS] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_LATIOS] = BACK_ANIM_H_SLIDE_QUICK,
    [SPECIES_JIRACHI] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
    [SPECIES_DEOXYS] = BACK_ANIM_SHRINK_GROW_2,
    [SPECIES_CHIMECHO] = BACK_ANIM_CONCAVE_DOWN_ARC_SWAY_LARGE,
};

static const u8 sUnknown_0860AA64[][2] =
{
    {0, 5},
    {1, 1},
    {0, 15},
    {1, 4},
    {0, 2},
    {1, 2},
    {0, 2},
    {1, 2},
    {0, 2},
    {1, 2},
    {0, 2},
    {1, 2},
    {0, 2},
    {0, 0xFF}
};

static const u8 sUnknown_0860AA80[][2] =
{
    {6,     30},
    {0xFE,  15},
    {6,     30},
    {0xFF,  0}
};

static void (* const sMonAnimFunctions[])(struct Sprite *sprite) =
{
    pokemonanimfunc_00,
    pokemonanimfunc_01,
    pokemonanimfunc_02,
    pokemonanimfunc_03,
    pokemonanimfunc_04,
    pokemonanimfunc_05,
    pokemonanimfunc_06,
    pokemonanimfunc_07,
    pokemonanimfunc_08,
    pokemonanimfunc_09,
    pokemonanimfunc_0A,
    pokemonanimfunc_0B,
    pokemonanimfunc_0C,
    pokemonanimfunc_0D,
    pokemonanimfunc_0E,
    pokemonanimfunc_0F,
    pokemonanimfunc_10,
    pokemonanimfunc_11,
    pokemonanimfunc_12,
    pokemonanimfunc_13,
    pokemonanimfunc_14,
    pokemonanimfunc_15,
    pokemonanimfunc_16,
    pokemonanimfunc_17,
    pokemonanimfunc_18,
    pokemonanimfunc_19,
    pokemonanimfunc_1A,
    pokemonanimfunc_1B,
    pokemonanimfunc_1C,
    pokemonanimfunc_1D,
    pokemonanimfunc_1E,
    pokemonanimfunc_1F,
    pokemonanimfunc_20,
    pokemonanimfunc_21,
    pokemonanimfunc_22,
    pokemonanimfunc_23,
    pokemonanimfunc_24,
    pokemonanimfunc_25,
    pokemonanimfunc_26,
    pokemonanimfunc_27,
    pokemonanimfunc_28,
    pokemonanimfunc_29,
    pokemonanimfunc_2A,
    pokemonanimfunc_2B,
    pokemonanimfunc_2C,
    pokemonanimfunc_2D,
    pokemonanimfunc_2E,
    pokemonanimfunc_2F,
    pokemonanimfunc_30,
    pokemonanimfunc_31,
    pokemonanimfunc_32,
    pokemonanimfunc_33,
    pokemonanimfunc_34,
    pokemonanimfunc_35,
    pokemonanimfunc_36,
    pokemonanimfunc_37,
    pokemonanimfunc_38,
    pokemonanimfunc_39,
    pokemonanimfunc_3A,
    pokemonanimfunc_3B,
    pokemonanimfunc_3C,
    pokemonanimfunc_3D,
    pokemonanimfunc_3E,
    pokemonanimfunc_3F,
    pokemonanimfunc_40,
    pokemonanimfunc_41,
    pokemonanimfunc_42,
    pokemonanimfunc_43,
    pokemonanimfunc_44,
    pokemonanimfunc_45,
    pokemonanimfunc_46,
    pokemonanimfunc_47,
    pokemonanimfunc_48,
    pokemonanimfunc_49,
    pokemonanimfunc_4A,
    pokemonanimfunc_4B,
    pokemonanimfunc_4C,
    pokemonanimfunc_4D,
    pokemonanimfunc_4E,
    pokemonanimfunc_4F,
    pokemonanimfunc_50,
    pokemonanimfunc_51,
    pokemonanimfunc_52,
    pokemonanimfunc_53,
    pokemonanimfunc_54,
    pokemonanimfunc_55,
    pokemonanimfunc_56,
    pokemonanimfunc_57,
    pokemonanimfunc_58,
    pokemonanimfunc_59,
    pokemonanimfunc_5A,
    pokemonanimfunc_5B,
    pokemonanimfunc_5C,
    pokemonanimfunc_5D,
    pokemonanimfunc_5E,
    pokemonanimfunc_5F,
    pokemonanimfunc_60,
    pokemonanimfunc_61,
    pokemonanimfunc_62,
    pokemonanimfunc_63,
    pokemonanimfunc_64,
    pokemonanimfunc_65,
    pokemonanimfunc_66,
    pokemonanimfunc_67,
    pokemonanimfunc_68,
    pokemonanimfunc_69,
    pokemonanimfunc_6A,
    pokemonanimfunc_6B,
    pokemonanimfunc_6C,
    pokemonanimfunc_6D,
    pokemonanimfunc_6E,
    pokemonanimfunc_6F,
    pokemonanimfunc_70,
    pokemonanimfunc_71,
    pokemonanimfunc_72,
    pokemonanimfunc_73,
    pokemonanimfunc_74,
    pokemonanimfunc_75,
    pokemonanimfunc_76,
    pokemonanimfunc_77,
    pokemonanimfunc_78,
    pokemonanimfunc_79,
    pokemonanimfunc_7A,
    pokemonanimfunc_7B,
    pokemonanimfunc_7C,
    pokemonanimfunc_7D,
    pokemonanimfunc_7E,
    pokemonanimfunc_7F,
    pokemonanimfunc_80,
    pokemonanimfunc_81,
    pokemonanimfunc_82,
    pokemonanimfunc_83,
    pokemonanimfunc_84,
    pokemonanimfunc_85,
    pokemonanimfunc_86,
    pokemonanimfunc_87,
    pokemonanimfunc_88,
    pokemonanimfunc_89,
    pokemonanimfunc_8A,
    pokemonanimfunc_8B,
    pokemonanimfunc_8C,
    pokemonanimfunc_8D,
    pokemonanimfunc_8E,
    pokemonanimfunc_8F,
    pokemonanimfunc_90,
    pokemonanimfunc_91,
    pokemonanimfunc_92,
    pokemonanimfunc_93,
    pokemonanimfunc_94,
    pokemonanimfunc_95,
    pokemonanimfunc_96
};

// counting from Id 1, because 0 in sSpeciesToBackAnimSet is used for mons with no back animation
static const u8 sBackAnimationIds[] =
{
    0x60, 0x5f, 0x02, // 1
    0x5e, 0x03, 0x46, // 2
    0x6d, 0x3e, 0x6e, // 3
    0x6f, 0x70, 0x3f, // 4
    0x71, 0x13, 0x72, // 5
    0x6c, 0x6b, 0x3a, // 6
    0x64, 0x14, 0x4f, // 7
    0x5d, 0x0f, 0x4c, // 8
    0x61, 0x57, 0x58, // 9
    0x67, 0x66, 0x59, // 0xA
    0x74, 0x73, 0x5a, // 0xB
    0x75, 0x76, 0x5b, // 0xC
    0x77, 0x78, 0x65, // 0xD
    0x63, 0x5c, 0x62, // 0xE
    0x6a, 0x69, 0x68, // 0xF
    0x7b, 0x7a, 0x79, // 0x10
    0x7e, 0x7d, 0x7c, // 0x11
    0x81, 0x80, 0x7f, // 0x12
    0x84, 0x82, 0x83, // 0x13
    0x85, 0x86, 0x87, // 0x14
    0x88, 0x89, 0x8a, // 0x15
    0x8b, 0x8c, 0x8d, // 0x16
    0x8e, 0x8f, 0x90, // 0x17
    0x91, 0x92, 0x93, // 0x18
    0x94, 0x95, 0x96, // 0x19
};

static const u8 sBackAnimNatureModTable[] =
{
    [NATURE_HARDY] = 0x00,
    [NATURE_LONELY] = 0x02,
    [NATURE_BRAVE] = 0x00,
    [NATURE_ADAMANT] = 0x00,
    [NATURE_NAUGHTY] = 0x00,
    [NATURE_BOLD] = 0x01,
    [NATURE_DOCILE] = 0x01,
    [NATURE_RELAXED] = 0x01,
    [NATURE_IMPISH] = 0x00,
    [NATURE_LAX] = 0x01,
    [NATURE_TIMID] = 0x02,
    [NATURE_HASTY] = 0x00,
    [NATURE_SERIOUS] = 0x01,
    [NATURE_JOLLY] = 0x00,
    [NATURE_NAIVE] = 0x00,
    [NATURE_MODEST] = 0x02,
    [NATURE_MILD] = 0x02,
    [NATURE_QUIET] = 0x02,
    [NATURE_BASHFUL] = 0x02,
    [NATURE_RASH] = 0x01,
    [NATURE_CALM] = 0x01,
    [NATURE_GENTLE] = 0x02,
    [NATURE_SASSY] = 0x01,
    [NATURE_CAREFUL] = 0x02,
    [NATURE_QUIRKY] = 0x01,
};

static const union AffineAnimCmd sSpriteAffineAnim_860AD48[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMDTYPE_END
};

static const union AffineAnimCmd sSpriteAffineAnim_860AD58[] =
{
    AFFINEANIMCMD_FRAME(-256, 256, 0, 0),
    AFFINEANIMCMDTYPE_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_860AD68[] =
{
    sSpriteAffineAnim_860AD48,
    sSpriteAffineAnim_860AD58
};

// code
static void MonAnimDummySpriteCallback(struct Sprite *sprite)
{
}

static void sub_817F3F0(struct Sprite *sprite, u16 index, s16 amplitudeX, s16 amplitudeY)
{
    s16 xAdder, yAdder;

    amplitudeX *= -1;
    amplitudeY *= -1;

    xAdder = Cos(index, amplitudeX) - Sin(index, amplitudeY);
    yAdder = Cos(index, amplitudeY) + Sin(index, amplitudeX);

    amplitudeX *= -1;
    amplitudeY *= -1;

    sprite->pos2.x = xAdder + amplitudeX;
    sprite->pos2.y = yAdder + amplitudeY;
}

u8 GetSpeciesBackAnimSet(u16 species)
{
    if (sSpeciesToBackAnimSet[species] != 0)
        return sSpeciesToBackAnimSet[species] - 1;
    else
        return 0;
}

#define tState  data[0]
#define tPtrHi  data[1]
#define tPtrLo  data[2]
#define tAnimId data[3]
#define tSaved0 data[4]
#define tSaved2 data[5]

// BUG: In vanilla, tPtrLo is read as an s16, so if bit 15 of the
// address were to be set it would cause the pointer to be read
// as 0xFFFFXXXX instead of the desired 0x02YYXXXX.
// By dumb luck, this is not an issue in vanilla. However,
// changing the link order revealed this bug.
#if MODERN
#define ANIM_SPRITE(taskId)   ((struct Sprite *)((gTasks[taskId].tPtrHi << 16) | ((u16)gTasks[taskId].tPtrLo)))
#else
#define ANIM_SPRITE(taskId)   ((struct Sprite *)((gTasks[taskId].tPtrHi << 16) | (gTasks[taskId].tPtrLo)))
#endif //MODERN

static void Task_HandleMonAnimation(u8 taskId)
{
    u32 i;
    struct Sprite *sprite = ANIM_SPRITE(taskId);

    if (gTasks[taskId].tState == 0)
    {
        gTasks[taskId].tSaved0 = sprite->data[0];
        gTasks[taskId].tSaved2 = sprite->data[2];
        sprite->data[1] = 1;
        sprite->data[0] = 0;

        for (i = 2; i < ARRAY_COUNT(sprite->data); i++)
            sprite->data[i] = 0;

        sprite->callback = sMonAnimFunctions[gTasks[taskId].tAnimId];
        sUnknown_03001274 = FALSE;

        gTasks[taskId].tState++;
    }
    if (sprite->callback == SpriteCallbackDummy)
    {
        sprite->data[0] = gTasks[taskId].tSaved0;
        sprite->data[2] = gTasks[taskId].tSaved2;
        sprite->data[1] = 0;

        DestroyTask(taskId);
    }
}

void LaunchAnimationTaskForFrontSprite(struct Sprite *sprite, u8 frontAnimId)
{
    u8 taskId = CreateTask(Task_HandleMonAnimation, 128);
    gTasks[taskId].tPtrHi = (u32)(sprite) >> 0x10;
    gTasks[taskId].tPtrLo = (u32)(sprite);
    gTasks[taskId].tAnimId = frontAnimId;
}

void StartMonSummaryAnimation(struct Sprite *sprite, u8 frontAnimId)
{
    sUnknown_03001274 = TRUE;
    sprite->callback = sMonAnimFunctions[frontAnimId];
}

void LaunchAnimationTaskForBackSprite(struct Sprite *sprite, u8 backAnimSet)
{
    u8 nature, taskId, animId, battlerId;

    taskId = CreateTask(Task_HandleMonAnimation, 128);
    gTasks[taskId].tPtrHi = (u32)(sprite) >> 0x10;
    gTasks[taskId].tPtrLo = (u32)(sprite);

    battlerId = sprite->data[0];
    nature = GetNature(&gPlayerParty[gBattlerPartyIndexes[battlerId]]);

    animId = 3 * backAnimSet + sBackAnimNatureModTable[nature];
    gTasks[taskId].tAnimId = sBackAnimationIds[animId];
}

#undef tState
#undef tPtrHi
#undef tPtrLo
#undef tAnimId
#undef tSaved0
#undef tSaved2

void SetSpriteCB_MonAnimDummy(struct Sprite *sprite)
{
    sprite->callback = MonAnimDummySpriteCallback;
}

static void SetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    u8 matrixNum;
    struct ObjAffineSrcData affineSrcData;
    struct OamMatrix dest;

    affineSrcData.xScale = xScale;
    affineSrcData.yScale = yScale;
    affineSrcData.rotation = rotation;

    matrixNum = sprite->oam.matrixNum;

    ObjAffineSet(&affineSrcData, &dest, 1, 2);
    gOamMatrices[matrixNum].a = dest.a;
    gOamMatrices[matrixNum].b = dest.b;
    gOamMatrices[matrixNum].c = dest.c;
    gOamMatrices[matrixNum].d = dest.d;
}

static void HandleStartAffineAnim(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    sprite->affineAnims = sSpriteAffineAnimTable_860AD68;

    if (sUnknown_03001274 == TRUE)
        InitSpriteAffineAnim(sprite);

    if (!sprite->data[1])
        StartSpriteAffineAnim(sprite, 1);
    else
        StartSpriteAffineAnim(sprite, 0);

    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    sprite->affineAnimPaused = 1;
}

static void HandleSetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    if (!sprite->data[1])
    {
        xScale *= -1;
        rotation *= -1;
    }

    SetAffineData(sprite, xScale, yScale, rotation);
}

static void sub_817F70C(struct Sprite *sprite)
{
    if (!sprite->data[1])
        sprite->pos2.x *= -1;
}

static bool32 sub_817F724(u8 id)
{
    if (id >= STRUCT_COUNT)
    {
        return FALSE;
    }
    else
    {
        sUnknown_03001240[id].field_6 = 0;
        sUnknown_03001240[id].field_0 = 0;
        sUnknown_03001240[id].field_4 = 1;
        sUnknown_03001240[id].field_2 = 0;
        sUnknown_03001240[id].field_8 = 0;
        return TRUE;
    }
}

static u8 sub_817F758(void)
{
    sUnknown_03001270 = (sUnknown_03001270 + 1) % STRUCT_COUNT;
    sub_817F724(sUnknown_03001270);
    return sUnknown_03001270;
}

static void sub_817F77C(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);

    if (sUnknown_03001274 == TRUE)
    {
        if (!sprite->data[1])
            sprite->hFlip = 1;
        else
            sprite->hFlip = 0;

        FreeOamMatrix(sprite->oam.matrixNum);
        sprite->oam.matrixNum |= (sprite->hFlip << 3);
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    }
}

static void pokemonanimfunc_01(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 var = (sprite->data[2] * 512 / 40) % 256;

        sprite->data[4] = Sin(var, 32) + 256;
        sprite->data[5] = Cos(var, 32) + 256;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_02(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->pos2.x = Sin((sprite->data[2] * 128 / 40) % 256, 6) * sign;
    }

    sprite->data[2]++;
}

static void sub_817F8FC(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        sprite->pos2.x = Sin((sprite->data[2] * 384 / sprite->data[0]) % 256, 6);
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_03(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sub_817F8FC(sprite);
    sprite->callback = sub_817F8FC;
}

static void sub_817F978(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = -(Sin((sprite->data[2] * 384 / sprite->data[0]) % 256, 6));
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_04(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sub_817F978(sprite);
    sprite->callback = sub_817F978;
}

static void sub_817F9F4(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    if (counter > 384)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s16 divCounter = counter / 128;
        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->pos2.y = -(Sin(counter % 128, sprite->data[0] * 2));
            break;
        case 2:
        case 3:
            counter -= 256;
            sprite->pos2.y = -(Sin(counter, sprite->data[0] * 3));
            break;
        }
    }

    sprite->data[2] += 12;
}

static void pokemonanimfunc_1E(struct Sprite *sprite)
{
    sprite->data[0] = 4;
    sub_817F9F4(sprite);
    sprite->callback = sub_817F9F4;
}

static void pokemonanimfunc_06(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 768)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s16 divCounter = counter / 128;

        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->pos2.x = 0;
            break;
        case 2:
            counter = 0;
            break;
        case 3:
            sprite->pos2.x = -(counter % 128 * 8) / 128;
            break;
        case 4:
            sprite->pos2.x = (counter % 128) / 8 - 8;
            break;
        case 5:
            sprite->pos2.x = -(counter % 128 * 8) / 128 + 8;
            break;
        }

        sprite->pos2.y = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
}

static void pokemonanimfunc_09(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256 / 40) % 256;

        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
        }

        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static const s8 sUnknown_0860AD70[][3] =
{
    {-1, -1, 6},
    {2,   0, 6},
    {-2,  2, 6},
    {2,   0, 6},
    {-2, -2, 6},
    {2,   0, 6},
    {-2,  2, 6},
    {2,   0, 6},
    {-1, -1, 6},
    {0,   0, 0},
};

static void sub_817FC20(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (sUnknown_0860AD70[sprite->data[3]][2] == sprite->data[2])
    {
        if (sUnknown_0860AD70[sprite->data[3]][2] == 0)
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[3]++;
            sprite->data[2] = 0;
        }
    }

    if (sUnknown_0860AD70[sprite->data[3]][2] == 0)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->pos2.x += sUnknown_0860AD70[sprite->data[3]][0];
        sprite->pos2.y += sUnknown_0860AD70[sprite->data[3]][1];
        sprite->data[2]++;
        sub_817F70C(sprite);
    }
}

static void pokemonanimfunc_0A(struct Sprite *sprite)
{
    sub_817FC20(sprite);
    sprite->callback = sub_817FC20;
}

static void sub_817FCDC(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        sprite->pos2.x = Sin(counter % 256, sprite->data[7]);
    }

    sprite->data[2] += sprite->data[0];
}

static void pokemonanimfunc_0F(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    sub_817FCDC(sprite);
    sprite->callback = sub_817FCDC;
}

static void sub_817FD44(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = Sin(counter % 256, 3);
    }

    sprite->data[2] += sprite->data[0];
}

static void pokemonanimfunc_10(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sub_817FD44(sprite);
    sprite->callback = sub_817FD44;
}

static void pokemonanimfunc_11(struct Sprite *sprite)
{
    if (sprite->data[2] > 512)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s8 sign;
        s32 index, amplitude;

        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        amplitude = Sin(sprite->data[2] / 4, 8);
        index = sprite->data[2] % 256;

        sprite->pos2.y = Sin(index, amplitude) * sign;
        sprite->pos2.x = Cos(index, amplitude) * sign;
    }

    sprite->data[2] += 9;
}

static void sub_817FE30(struct Sprite *sprite)
{
    s16 id = sprite->data[0];

    if (sUnknown_03001240[id].field_0 != 0)
    {
        sUnknown_03001240[id].field_0--;
    }
    else
    {
        if (sprite->data[2] == 0 && sUnknown_03001240[id].field_8 == 0)
        {
            HandleStartAffineAnim(sprite);
            sUnknown_03001240[id].field_8++;
        }

        if (sprite->data[2] > sUnknown_03001240[id].field_6)
        {
            HandleSetAffineData(sprite, 256, 256, 0);

            if (sUnknown_03001240[id].field_4 > 1)
            {
                sUnknown_03001240[id].field_4--;
                sUnknown_03001240[id].field_0 = 10;
                sprite->data[2] = 0;
            }
            else
            {
                sub_817F77C(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            }
        }
        else
        {
            sprite->data[6] = Sin(sprite->data[2] % 256, 4096);
            HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
        }

        sprite->data[2] += 16;
    }
}

static void pokemonanimfunc_12(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 512;
    sUnknown_03001240[id].field_0 = 0;
    sub_817FE30(sprite);
    sprite->callback = sub_817FE30;
}

static void sub_817FF3C(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > sUnknown_03001240[id].field_0)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = (65536 / sUnknown_03001240[id].field_8) * sprite->data[2];
        HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_1F(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_0 = 60;
    sUnknown_03001240[id].field_8 = 20;
    sub_817FF3C(sprite);
    sprite->callback = sub_817FF3C;
}

static void sub_817FFF0(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    sub_817F70C(sprite);

    if (sprite->data[2] > sUnknown_03001240[id].field_6)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] + 192) % 256;

        sprite->pos2.x = -(Cos(index, sUnknown_03001240[id].field_8 * 2));
        sprite->pos2.y = Sin(index, sUnknown_03001240[id].field_8) + sUnknown_03001240[id].field_8;
    }

    sprite->data[2] += sUnknown_03001240[id].field_2;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_14(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 512;
    sUnknown_03001240[id].field_8 = 6;
    sUnknown_03001240[id].field_2 = 24;
    sub_817FFF0(sprite);
    sprite->callback = sub_817FFF0;
}

static void pokemonanimfunc_15(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB_BLACK);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 16);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], RGB_BLACK);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_16(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;

        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (sprite->data[1] == 0)
            sprite->data[4] = (Sin(index2, 40) - 256) + Sin(index1, 16);
        else
            sprite->data[4] = (256 - Sin(index2, 40)) - Sin(index1, 16);

        sprite->data[5] = Sin(index2, 16) + 256;
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_17(struct Sprite *sprite)
{
    s16 posY = 0, index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = posY;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;

        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (sprite->data[1] == 0)
            sprite->data[4] = -(Sin(index2, 16)) - 256;
        else
            sprite->data[4] = Sin(index2, 16) + 256;

        sprite->data[5] = (256 - Sin(index2, 40)) - Sin(index1, 8);

        if (sprite->data[5] != 256)
            posY = (256 - sprite->data[5]) / 8;

        sprite->pos2.y = -(posY);
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void sub_818031C(struct Sprite *sprite)
{
    u8 index = sprite->data[2];
    u8 var7 = sprite->data[6];
    u8 var5 = sUnknown_0860AA80[sprite->data[5]][0];
    u8 var6 = sUnknown_0860AA80[sprite->data[5]][1];
    u8 amplitude = 0;

    if (var5 != 0xFE)
        amplitude = (var6 - var7) * var5 / var6;
    else
        amplitude = 0;

    if (var5 == 0xFF)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = Sin(index, amplitude);

        if (var7 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

static void pokemonanimfunc_19(struct Sprite *sprite)
{
    sprite->data[0] = 48;
    sub_818031C(sprite);
    sprite->callback = sub_818031C;
}

static void pokemonanimfunc_1A(struct Sprite *sprite)
{
    u8 counter = 0;

    sub_817F70C(sprite);
    counter = sprite->data[2];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 35)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s16 index = ((counter - 10) * 128) / 20;

        if (counter < 10)
            HandleSetAffineData(sprite, 256, 256, counter / 2 * 512);
        else if (counter >= 10 && counter <= 29)
            sprite->pos2.x = -(Sin(index, 5));
        else
            HandleSetAffineData(sprite, 256, 256, (35 - counter) / 2 * 1024);
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_1B(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / 100;
        sprite->pos2.y = Sin(index, 10);
        HandleSetAffineData(sprite, 256, 256, Sin(index, 3276));
    }

    sprite->data[2]++;
}

static void sub_81804F8(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->pos2.y = Sin(index, sprite->data[0]);
        HandleSetAffineData(sprite, 256, 256, Sin(var, 3276));
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_1C(struct Sprite *sprite)
{
    sprite->data[0] = 10;
    sub_81804F8(sprite);
    sprite->callback = sub_81804F8;
}

static void sub_81805B0(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->pos2.y = -(Sin(index / 2, sprite->data[0] * 2));
        HandleSetAffineData(sprite, 256, 256, Sin(var, 3276));
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_18(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    sub_81805B0(sprite);
    sprite->callback = sub_81805B0;
}

static void pokemonanimfunc_1D(struct Sprite *sprite)
{
    s32 var;
    s16 index = 0;

    sub_817F70C(sprite);
    var = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 toDiv = 100;

        index = (sprite->data[2] * 256) / toDiv;
        var = (sprite->data[2] * 512) / toDiv;
        var &= 0xFF;
        sprite->pos2.x = Sin(index, 8);
        HandleSetAffineData(sprite, 256, 256, Sin(var, 3276));
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void sub_8180714(struct Sprite *sprite)
{
    s16 posY = 0;

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[3] = 0;
    }

    sub_817F70C(sprite);

    if (sprite->data[2] > sprite->data[0] * 3)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale = Sin(sprite->data[4], 32) + 256;

        if (sprite->data[2] > sprite->data[0] && sprite->data[2] < sprite->data[0] * 2)
            sprite->data[3] += (128 / sprite->data[0]);
        if (yScale > 256)
            posY = (256 - yScale) / 8;

        sprite->pos2.y = -(Sin(sprite->data[3], 10)) - posY;
        HandleSetAffineData(sprite, 256 - Sin(sprite->data[4], 32), yScale, 0);
        sprite->data[2]++;
        sprite->data[4] = (sprite->data[4] + 128 / sprite->data[0]) & 0xFF;
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_00(struct Sprite *sprite)
{
    sprite->data[0] = 16;
    sub_8180714(sprite);
    sprite->callback = sub_8180714;
}

static void sub_8180828(struct Sprite *sprite)
{
    s16 posY = 0;

    if (sprite->data[2] > (128 / sprite->data[6]) * sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale = Sin(sprite->data[4], 32) + 256;

        if (yScale > 256)
            posY = (256 - yScale) / 8;

        sprite->pos2.y = -(posY);
        HandleSetAffineData(sprite, Sin(sprite->data[4], 48) + 256, yScale, 0);
        sprite->data[2]++;
        sprite->data[4] = (sprite->data[4] + sprite->data[6]) & 0xFF;
    }
}

static void pokemonanimfunc_13(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 3;
        sprite->data[6] = 8;
    }

    sub_8180828(sprite);
}

static const s8 sUnknown_0860AD8E[][8][3] =
{
    {
        {0,  8, 8},
        {8, -8, 12},
        {-8, 8, 12},
        {8, -8, 12},
        {-8, 8, 12},
        {8, -8, 12},
        {-8, 0, 12},
        {0,  0, 0}
    },
    {
        {0,  8, 16},
        {8, -8, 24},
        {-8, 8, 24},
        {8, -8, 24},
        {-8, 8, 24},
        {8, -8, 24},
        {-8, 0, 24},
        {0,  0, 0}
    },
};

static void sub_8180900(struct Sprite *sprite)
{
    s16 var;
    u8 structId;
    s8 r9;
    s16 r10;
    s16 r7;
    u32 arrId;

    sub_817F70C(sprite);
    structId = sprite->data[0];
    var = sUnknown_03001240[structId].field_6;
    r9 = sUnknown_0860AD8E[sUnknown_03001240[structId].field_8][sprite->data[4]][0];
    r10 = sUnknown_0860AD8E[sUnknown_03001240[structId].field_8][sprite->data[4]][1] - r9;
    arrId = sUnknown_03001240[structId].field_8;
    r7 = sprite->data[3];

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    if (sUnknown_0860AD8E[arrId][sprite->data[4]][2] == 0)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        u16 rotation;

        sprite->pos2.y = -(Sin(r7 * 128 / sUnknown_0860AD8E[arrId][sprite->data[4]][2], 10));
        sprite->pos2.x = (r10 * r7 / sUnknown_0860AD8E[arrId][sprite->data[4]][2]) + r9;

        rotation = -(var * sprite->pos2.x) / 8;
        HandleSetAffineData(sprite, 256, 256, rotation);

        if (r7 == sUnknown_0860AD8E[arrId][sprite->data[4]][2])
        {
            sprite->data[4]++;
            sprite->data[3] = 0;
        }
        else
        {
            sprite->data[3]++;
        }
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_05(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_6 = 4096;
    sUnknown_03001240[id].field_8 = sprite->data[6];
    sub_8180900(sprite);
    sprite->callback = sub_8180900;
}

static void pokemonanimfunc_20(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB(31, 22, 0));
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], RGB(31, 22, 0));
    }

    sprite->data[2] += 2;
}

static void pokemonanimfunc_21(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB_RED);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], RGB_RED);
    }

    sprite->data[2] += 2;
}

static void pokemonanimfunc_22(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB_BLUE);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], RGB_BLUE);
    }

    sprite->data[2] += 2;
}

static void pokemonanimfunc_23(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB_YELLOW);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], RGB_YELLOW);
    }

    sprite->data[2] += 2;
}

static void pokemonanimfunc_24(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB(24, 0, 24));
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], RGB(24, 0, 24));
    }

    sprite->data[2] += 2;
}

static void sub_8180CB4(struct Sprite *sprite);
static void sub_8180CE8(struct Sprite *sprite);
static void sub_8180D44(struct Sprite *sprite);
static void sub_8180DC0(struct Sprite *sprite);
static void sub_8180E28(struct Sprite *sprite);

static void pokemonanimfunc_25(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = sub_8180CB4;
}

static void sub_8180CB4(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (++sprite->pos2.x > 7)
    {
        sprite->pos2.x = 8;
        sprite->data[7] = 2;
        sprite->callback = sub_8180CE8;
    }
    sub_817F70C(sprite);
}

static void sub_8180CE8(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    sprite->pos2.x -= sprite->data[7];
    sprite->data[7]++;
    if (sprite->pos2.x <= 0)
    {
        s16 subResult;
        u8 var = sprite->data[7];
        sprite->data[6] = 0;
        subResult = sprite->pos2.x;

        do
        {
            subResult -= var;
            sprite->data[6]++;
            var++;
        }
        while (subResult > -8);

        sprite->data[5] = 1;
        sprite->callback = sub_8180D44;
    }

    sub_817F70C(sprite);
}

static void sub_8180D44(struct Sprite *sprite)
{
    u8 rotation;

    sub_817F70C(sprite);
    sprite->pos2.x -= sprite->data[7];
    sprite->data[7]++;
    rotation = (sprite->data[5] * 6) / sprite->data[6];

    if (++sprite->data[5] > sprite->data[6])
        sprite->data[5] = sprite->data[6];

    HandleSetAffineData(sprite, 256, 256, rotation * 256);

    if (sprite->pos2.x < -8)
    {
        sprite->pos2.x = -8;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[2] = rotation;
        sprite->callback = sub_8180DC0;
    }

    sub_817F70C(sprite);
}

static void sub_8180DC0(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[3] > 11)
    {
        sprite->data[2] -= 2;
        if (sprite->data[2] < 0)
            sprite->data[2] = 0;

        HandleSetAffineData(sprite, 256, 256, sprite->data[2] << 8);
        if (sprite->data[2] == 0)
            sprite->callback = sub_8180E28;
    }
    else
    {
        sprite->pos2.x += sprite->data[4];
        sprite->data[4] *= -1;
        sprite->data[3]++;
    }

    sub_817F70C(sprite);
}

static void sub_8180E28(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    sprite->pos2.x += 2;
    if (sprite->pos2.x > 0)
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    sub_817F70C(sprite);
}

static void sub_8180E78(struct Sprite *sprite);
static void sub_8180ED0(struct Sprite *sprite);
static void sub_8180F2C(struct Sprite *sprite);

static void pokemonanimfunc_26(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    sprite->callback = sub_8180E78;
}

static void sub_8180E78(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x++;
    sprite->pos2.y--;

    if (sprite->pos2.x % 2 == 0 && sprite->data[3] <= 0)
        sprite->data[3] = 10;
    if (sprite->pos2.x > 7)
    {
        sprite->pos2.x = 8;
        sprite->pos2.y = -8;
        sprite->data[4] = 0;
        sprite->callback = sub_8180ED0;
    }

    sub_817F70C(sprite);
}

static void sub_8180ED0(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x = Cos(sprite->data[4], 16) - 8;
    sprite->pos2.y = Sin(sprite->data[4], 16) - 8;

    if (sprite->data[4] > 63)
    {
        sprite->data[2] = 160;
        sprite->data[3] = 10;
        sprite->callback = sub_8180F2C;
    }
    sprite->data[4] += 8;
    if (sprite->data[4] > 64)
        sprite->data[4] = 64;

    sub_817F70C(sprite);
}

static void sub_8180F2C(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
    }
    else
    {
        u32 rotation;

        sprite->pos2.x = Cos(sprite->data[2], 5) - 4;
        sprite->pos2.y = -(Sin(sprite->data[2], 5)) + 4;
        sprite->data[2] -= 4;
        rotation = sprite->data[2] - 32;
        HandleSetAffineData(sprite, 256, 256, rotation * 512);

        if (sprite->data[2] <= 32)
        {
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_27(struct Sprite *sprite)
{
    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
    }
    else
    {
        sprite->data[4] = (sprite->data[4] == 0) ? 1 : 0;
        sprite->invisible = sprite->data[4];
        if (++sprite->data[2] > 19)
        {
            sprite->invisible = FALSE;
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        sprite->data[3] = 2;
    }
}

static void sub_8181024(struct Sprite *sprite);
static void sub_8181068(struct Sprite *sprite);
static void sub_81810C4(struct Sprite *sprite);

static void pokemonanimfunc_28(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = sub_8181024;
}

static void sub_8181024(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x--;
    sprite->pos2.y++;

    if (sprite->pos2.x <= -16)
    {
        sprite->pos2.x = -16;
        sprite->pos2.y = 16;
        sprite->callback = sub_8181068;
        sprite->data[2] = 160;
    }

    sub_817F70C(sprite);
}

static void sub_8181068(struct Sprite *sprite)
{
    u32 rotation;

    sub_817F70C(sprite);
    sprite->data[2] -= 4;
    sprite->pos2.x = Cos(sprite->data[2], 22);
    sprite->pos2.y = -(Sin(sprite->data[2], 22));
    rotation = sprite->data[2] - 32;
    HandleSetAffineData(sprite, 256, 256, rotation * 512);

    if (sprite->data[2] <= 32)
        sprite->callback = sub_81810C4;

    sub_817F70C(sprite);
}

static void sub_81810C4(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x--;
    sprite->pos2.y++;

    if (sprite->pos2.x <= 0)
    {
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    sub_817F70C(sprite);
}

static void sub_8181110(struct Sprite *sprite);
static void sub_8181144(struct Sprite *sprite);
static void sub_81811A4(struct Sprite *sprite);

static void pokemonanimfunc_29(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = sub_8181110;
}

static void sub_8181110(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x++;
    sprite->pos2.y--;

    if (sprite->pos2.x > 15)
    {
        sprite->data[2] = 0;
        sprite->callback = sub_8181144;
    }

    sub_817F70C(sprite);
}

static void sub_8181144(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->data[2] += 16;

    if (sprite->pos2.x <= -16)
    {
        sprite->pos2.x = -16;
        sprite->pos2.y = 16;
        sprite->data[2] = 0;
        sprite->callback = sub_81811A4;
    }
    else
    {
        sprite->pos2.x -= 2;
        sprite->pos2.y += 2;
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[2] << 8);
    sub_817F70C(sprite);
}

static void sub_81811A4(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x++;
    sprite->pos2.y--;;

    if (sprite->pos2.x >= 0)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    sub_817F70C(sprite);
}

static void sub_8181214(struct Sprite *sprite);

static void pokemonanimfunc_2A(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_2 = 2;
    sub_8181214(sprite);
    sprite->callback = sub_8181214;
}

static void sub_8181214(struct Sprite *sprite)
{
    if (sUnknown_03001240[sprite->data[0]].field_0 != 0)
    {
        sUnknown_03001240[sprite->data[0]].field_0--;
    }
    else
    {
        sub_817F70C(sprite);
        if (sprite->data[2] == 0)
        {
            sprite->data[2]++;
            HandleStartAffineAnim(sprite);
            sprite->data[7] = sUnknown_03001240[sprite->data[0]].field_2;
            sprite->data[3] = -1;
            sprite->data[4] = -1;
            sprite->data[5] = 0;
            sprite->data[6] = 0;
        }

        sprite->pos2.x += (sprite->data[7] * 2 * sprite->data[3]);
        sprite->pos2.y += (sprite->data[7] * sprite->data[4]);
        sprite->data[6] += 8;
        if (sprite->pos2.x <= -16 || sprite->pos2.x >= 16)
        {
            sprite->pos2.x = sprite->data[3] * 16;
            sprite->data[3] *= -1;
            sprite->data[5]++;
        }
        else if (sprite->pos2.y <= -16 || sprite->pos2.y >= 16)
        {
            sprite->pos2.y = sprite->data[4] * 16;
            sprite->data[4] *= -1;
            sprite->data[5]++;
        }

        if (sprite->data[5] > 5 && sprite->pos2.x <= 0)
        {
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            if (sUnknown_03001240[sprite->data[0]].field_4 > 1)
            {
                sUnknown_03001240[sprite->data[0]].field_4--;
                sprite->data[5] = 0;
                sprite->data[6] = 0;
                sUnknown_03001240[sprite->data[0]].field_0 = 10;
            }
            else
            {
                sub_817F77C(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            }
        }

        HandleSetAffineData(sprite, 256, 256, sprite->data[6] << 8);
        sub_817F70C(sprite);
    }
}

static void sub_8181370(struct Sprite *sprite);

static void pokemonanimfunc_2B(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[6] = 0;
    sprite->data[7] = 0;
    sprite->callback = sub_8181370;
}

static void sub_8181370(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->data[6] += 4;
    sprite->pos2.x = -(Sin(sprite->data[6], 16));
    sprite->pos2.y = -(Sin((sprite->data[6] * 2) & 0xFF, 8));
    if (sprite->data[6] > 192 && sprite->data[7] == 1)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->data[7]++;
    }
    else if (sprite->data[6] > 64 && sprite->data[7] == 0)
    {
        HandleSetAffineData(sprite, -256, 256, 0);
        sprite->data[7]++;
    }

    if (sprite->data[6] > 255)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    sub_817F70C(sprite);
}

static void pokemonanimfunc_2C(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
    }

    if (sUnknown_0860AA64[sprite->data[6]][1] == 0xFF)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        if (sprite->data[4] == 1)
        {
            if (sUnknown_0860AA64[sprite->data[6]][0] != 0)
                BlendPalette(sprite->data[7], 0x10, 0x10, RGB_YELLOW);
            else
                BlendPalette(sprite->data[7], 0x10, 0, RGB_YELLOW);

            sprite->data[4] = 0;
        }

        if (sUnknown_0860AA64[sprite->data[6]][1] == sprite->data[5])
        {
            sprite->data[4] = 1;
            sprite->data[5] = 0;
            sprite->data[6]++;
        }
        else
        {
            sprite->data[5]++;
        }
    }
}

static void sub_81814D4(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    sub_817F70C(sprite);
    if (sprite->data[2] > sUnknown_03001240[sprite->data[0]].field_8)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        if (sUnknown_03001240[sprite->data[0]].field_4 > 1)
        {
            sUnknown_03001240[sprite->data[0]].field_4--;
            sprite->data[2] = 0;
        }
        else
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / sUnknown_03001240[sprite->data[0]].field_8;
        sprite->pos2.x = -(Sin(index, 10));
        HandleSetAffineData(sprite, 256, 256, Sin(index, 3276));
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_2D(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_8 = 50;
    sub_81814D4(sprite);
    sprite->callback = sub_81814D4;
}

static void sub_81815D4(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    sub_817F70C(sprite);
    if (sprite->data[2] > sUnknown_03001240[sprite->data[0]].field_8)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        if (sUnknown_03001240[sprite->data[0]].field_4 > 1)
        {
            sUnknown_03001240[sprite->data[0]].field_4--;
            sprite->data[2] = 0;
        }
        else
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / sUnknown_03001240[sprite->data[0]].field_8;
        sprite->pos2.x = -(Sin(index, 10));
        HandleSetAffineData(sprite, 256, 256, -(Sin(index, 3276)));
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_2E(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_8 = 50;
    sub_81815D4(sprite);
    sprite->callback = sub_81815D4;
}

static void sub_8181708(struct Sprite *sprite);
static void sub_8181770(struct Sprite *sprite);
static void sub_8181794(struct Sprite *sprite);

static void pokemonanimfunc_2F(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[6] = -(14 * sprite->centerToCornerVecX / 10);
    sprite->data[7] = 128;
    sprite->callback = sub_8181708;
}

static void sub_8181708(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->data[7]--;
    sprite->pos2.x = Cos(sprite->data[7], sprite->data[6]) + sprite->data[6];

    sprite->pos2.y = -(Sin(sprite->data[7], sprite->data[6] += 0)); // dummy += 0 is needed to match

    HandleSetAffineData(sprite, 256, 256, (sprite->data[7] - 128) << 8);
    if (sprite->data[7] <= 120)
    {
        sprite->data[7] = 120;
        sprite->data[3] = 0;
        sprite->callback = sub_8181770;
    }

    sub_817F70C(sprite);
}

static void sub_8181770(struct Sprite *sprite)
{
    if (sprite->data[3] == 20)
    {
        sprite->callback = sub_8181794;
        sprite->data[3] = 0;
    }

    sprite->data[3]++;
}

static void sub_8181794(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->data[7] += 2;
    sprite->pos2.x = Cos(sprite->data[7], sprite->data[6]) + sprite->data[6];

    sprite->pos2.y = -(Sin(sprite->data[7], sprite->data[6] += 0)); // dummy += 0 is needed to match

    HandleSetAffineData(sprite, 256, 256, (sprite->data[7] - 128) << 8);
    if (sprite->data[7] >= 128)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->data[2] = 0;
        sub_817F77C(sprite);
        sprite->callback = pokemonanimfunc_10;
    }

    sub_817F70C(sprite);
}

static void sub_8181810(struct Sprite *sprite)
{
    if (sUnknown_03001240[sprite->data[0]].field_0 != 0)
    {
        sUnknown_03001240[sprite->data[0]].field_0--;
    }
    else
    {
        if (sprite->data[2] == 0)
        {
            HandleStartAffineAnim(sprite);
            sprite->data[4] = 0;
            sprite->data[5] = 0;
            sprite->data[2] = 1;
        }

        if (sprite->data[5] == 0)
        {
            sprite->data[7] = Sin(sprite->data[4], 256);
            sprite->pos2.y = Sin(sprite->data[4], 16);
            sprite->data[6] = Sin(sprite->data[4], 32);
            HandleSetAffineData(sprite, 256 - sprite->data[6], 256 + sprite->data[7], 0);
            if (sprite->data[4] == 128)
            {
                sprite->data[4] = 0;
                sprite->data[5] = 1;
            }
        }
        else if (sprite->data[5] == 1)
        {
            sprite->data[7] = Sin(sprite->data[4], 32);
            sprite->pos2.y = -(Sin(sprite->data[4], 8));
            sprite->data[6] = Sin(sprite->data[4], 128);
            HandleSetAffineData(sprite, 256 + sprite->data[6], 256 - sprite->data[7], 0);
            if (sprite->data[4] == 128)
            {
                if (sUnknown_03001240[sprite->data[0]].field_4 > 1)
                {
                    sUnknown_03001240[sprite->data[0]].field_4--;
                    sUnknown_03001240[sprite->data[0]].field_0 = 10;
                    sprite->data[4] = 0;
                    sprite->data[5] = 0;
                }
                else
                {
                    HandleSetAffineData(sprite, 256, 256, 0);
                    sub_817F77C(sprite);
                    sprite->callback = SpriteCB_SetDummyOnAnimEnd;
                }
            }
        }

        sprite->data[4] += sUnknown_03001240[sprite->data[0]].field_6;
    }
}

static void pokemonanimfunc_30(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_6 = 4;
    sub_8181810(sprite);
    sprite->callback = sub_8181810;
}

static void pokemonanimfunc_31(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    sub_817F70C(sprite);
    if (counter > 512)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        switch (sprite->data[2] / 128)
        {
        case 0:
            sprite->pos2.x = -(counter % 128 * 8) / 128;
            break;
        case 1:
            sprite->pos2.x = (counter % 128 / 16) - 8;
            break;
        case 2:
            sprite->pos2.x = (counter % 128 / 16);
            break;
        case 3:
            sprite->pos2.x = -(counter % 128 * 8) / 128 + 8;
            break;
        }

        sprite->pos2.y = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
    sub_817F70C(sprite);
}

static void sub_8181ABC(struct Sprite *sprite);
static void sub_8181B4C(struct Sprite *sprite);
static void sub_8181C2C(struct Sprite *sprite);

static void pokemonanimfunc_32(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_8 = -1;
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    sub_8181ABC(sprite);
    sprite->callback = sub_8181ABC;
}

static void sub_8181ABC(struct Sprite *sprite)
{
    if (sUnknown_03001240[sprite->data[0]].field_0 != 0)
    {
        sUnknown_03001240[sprite->data[0]].field_0--;
    }
    else
    {
        s32 counter;

        sub_817F70C(sprite);
        counter = sprite->data[2];
        if (sprite->data[2] > 128)
        {
            sprite->data[2] = 0;
            sprite->callback = sub_8181B4C;
        }
        else
        {
            s32 var = 8 * sUnknown_03001240[sprite->data[0]].field_8;
            sprite->pos2.x = var * (counter % 128) / 128;
            sprite->pos2.y = -(Sin(counter % 128, 8));
            sprite->data[2] += 12;
        }

        sub_817F70C(sprite);
    }
}

static void sub_8181B4C(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 48)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.y = 0;
        sprite->data[2] = 0;
        sprite->callback = sub_8181C2C;
    }
    else
    {
        s16 yDelta;
        s16 yScale = Sin(sprite->data[4], 64) + 256;
        if (sprite->data[2] >= 16 && sprite->data[2] <= 31)
        {
            sprite->data[3] += 8;
            sprite->pos2.x -= sUnknown_03001240[sprite->data[0]].field_8;
        }

        yDelta = 0;
        if (yScale > 256)
            yDelta = (256 - yScale) / 8;

        sprite->pos2.y = -(Sin(sprite->data[3], 20)) - yDelta;
        HandleSetAffineData(sprite, 256 - Sin(sprite->data[4], 32), yScale, 0);
        sprite->data[2]++;
        sprite->data[4] += 8;
        sprite->data[4] &= 0xFF;
    }

    sub_817F70C(sprite);
}

static void sub_8181C2C(struct Sprite *sprite)
{
    s32 counter;

    sub_817F70C(sprite);
    counter = sprite->data[2];
    if (counter > 128)
    {
        if (sUnknown_03001240[sprite->data[0]].field_4 > 1)
        {
            sUnknown_03001240[sprite->data[0]].field_4--;
            sUnknown_03001240[sprite->data[0]].field_0 = 10;
            sprite->data[3] = 0;
            sprite->data[2] = 0;
            sprite->data[4] = 0;
            sprite->callback = sub_8181ABC;
        }
        else
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }

        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        register s32 var asm("r4") = sUnknown_03001240[sprite->data[0]].field_8;

        sprite->pos2.x = (var << 3) * (counter % 128) / 128 - (sUnknown_03001240[sprite->data[0]].field_8 * 8);
        sprite->pos2.y = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
    sub_817F70C(sprite);
}

static void sub_8181CE8(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    sub_817F70C(sprite);
    if (sprite->data[7] > 254)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sUnknown_03001240[sprite->data[0]].field_4 > 1)
        {
            sUnknown_03001240[sprite->data[0]].field_4--;
            sprite->data[2] = 0;
            sprite->data[7] = 0;
        }
        else
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }

        sub_817F70C(sprite);
    }
    else
    {
        u16 rotation;

        sprite->pos2.x = -(Sin(sprite->data[7], 16));
        rotation = Sin(sprite->data[7], 32);
        HandleSetAffineData(sprite, 256, 256, rotation << 8);
        sprite->data[7] += sUnknown_03001240[sprite->data[0]].field_6;
        sub_817F70C(sprite);
    }
}

static void pokemonanimfunc_33(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();
    sUnknown_03001240[id].field_6 = 4;
    sub_8181CE8(sprite);
    sprite->callback = sub_8181CE8;
}

static void pokemonanimfunc_34(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    sub_817F70C(sprite);
    if (sprite->data[7] > 254)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sub_817F70C(sprite);
    }
    else
    {
        u16 rotation;

        sprite->pos2.x = -(Sin(sprite->data[7], 16));
        sprite->pos2.y = -(Sin(sprite->data[7] % 128, 16));
        rotation = Sin(sprite->data[7], 32);
        HandleSetAffineData(sprite, 256, 256, rotation << 8);
        sprite->data[7] += 8;
        sub_817F70C(sprite);
    }
}

static void pokemonanimfunc_35(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 0;

    if (sprite->data[2] == sprite->data[7])
    {
        sprite->data[7] = 0;
        sprite->data[2]++;
        sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[7]++;
        sprite->invisible = TRUE;
    }

    if (sprite->data[2] > 10)
    {
        sprite->invisible = FALSE;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
}

static void sub_8181F14(struct Sprite *sprite);
static void sub_8181F50(struct Sprite *sprite);
static void sub_8181FC0(struct Sprite *sprite);

static void pokemonanimfunc_36(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->callback = sub_8181F14;
}

static void sub_8181F14(struct Sprite *sprite)
{
    if (sprite->data[7] > 31)
    {
        sprite->data[7] = 32;
        sprite->data[2] = 0;
        sprite->callback = sub_8181F50;
    }
    else
    {
        sprite->data[7] += 4;
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[7] << 8);
}

static void sub_8181F50(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 512)
    {
        sprite->callback = sub_8181FC0;
        sprite->data[6] = 0;
    }
    else
    {
        sprite->pos2.x = -(sprite->data[2] * 16) / 512;
        sprite->pos2.y = -(Sin(sprite->data[2] % 128, 4));
        sprite->data[2] += 12;
    }

    sub_817F70C(sprite);
}

static void sub_8181FC0(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->data[7] -= 2;
    if (sprite->data[7] < 0)
    {
        sprite->data[7] = 0;
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->pos2.x = -(Sin(sprite->data[7] * 2, 16));
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[7] << 8);
    sub_817F70C(sprite);
}

static void pokemonanimfunc_37(struct Sprite *sprite)
{
    u16 rotation;

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    sub_817F70C(sprite);
    if (sprite->data[7] > 255)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->data[7] = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[7] += 16;
        sprite->pos2.x = -(Sin(sprite->data[7] % 128, 8));
        sprite->pos2.y = -(Sin(sprite->data[7] % 128, 8));
    }

    rotation = Sin(sprite->data[7] % 128, 16);
    HandleSetAffineData(sprite, 256, 256, rotation << 8);
    sub_817F70C(sprite);
}

static void sub_81820FC(struct Sprite *sprite);
static void sub_818216C(struct Sprite *sprite);
static void sub_81821CC(struct Sprite *sprite);
static void sub_8182248(struct Sprite *sprite);

static void pokemonanimfunc_38(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->data[4] = 0;
    sprite->callback = sub_81820FC;
}

static void sub_81820FC(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[7] > 24)
    {
        if (++sprite->data[4] > 4)
        {
            sprite->data[4] = 0;
            sprite->callback = sub_818216C;
        }
    }
    else
    {
        sprite->data[7] += 2;
        sprite->pos2.x = Sin(sprite->data[7], 8);
        sprite->pos2.y = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    sub_817F70C(sprite);
}

static void sub_818216C(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[7] > 32)
    {
        sprite->data[6] = 1;
        sprite->callback = sub_81821CC;
    }
    else
    {
        sprite->data[7] += 2;
        sprite->pos2.x = Sin(sprite->data[7], 8);
        sprite->pos2.y = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    sub_817F70C(sprite);
}

static void sub_81821CC(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->data[7] += (sprite->data[6] * 4);
    if (sprite->data[5] > 9)
    {
        sprite->data[7] = 32;
        sprite->callback = sub_8182248;
    }

    sprite->pos2.x = Sin(sprite->data[7], 8);
    sprite->pos2.y = -(Sin(sprite->data[7], 8));
    if (sprite->data[7] <= 28 || sprite->data[7] >= 36)
    {
        sprite->data[6] *= -1;
        sprite->data[5]++;
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    sub_817F70C(sprite);
}

static void sub_8182248(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[7] <= 0)
    {
        sprite->data[7] = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[7] -= 2;
        sprite->pos2.x = Sin(sprite->data[7], 8);
        sprite->pos2.y = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    sub_817F70C(sprite);
}

static void pokemonanimfunc_39(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        if ((sprite->data[2] % 4) / 2 == 0)
        {
            sprite->pos2.x = Sin((sprite->data[2] * 128 / 40) % 256, 16) * sign;
            sprite->pos2.y = -(sprite->pos2.x);
        }
        else
        {
            sprite->pos2.x = -(Sin((sprite->data[2] * 128 / 40) % 256, 16)) * sign;
            sprite->pos2.y = sprite->pos2.x;
        }
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

static void pokemonanimfunc_3A(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[5] = 0;
        sprite->data[6] = 0;
        sprite->data[7] = 0;
        sprite->data[2]++;
    }

    if (sprite->data[6] > 0)
    {
        sprite->data[6]--;
        if (sprite->data[5] != 3)
        {
            s16 scale = (8 * sprite->data[6]) / 20;
            scale = Sin(sprite->data[7] - scale, 64);
            HandleSetAffineData(sprite, 256 - scale, 256 - scale, 0);
        }
    }
    else
    {
        s16 var;

        if (sprite->data[5] == 3)
        {
            if (sprite->data[7] > 63)
            {
                sprite->data[7] = 64;
                HandleSetAffineData(sprite, 256, 256, 0);
                sub_817F77C(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            }
            var = Cos(sprite->data[7], 64);
        }
        else
        {
            var = Sin(sprite->data[7], 64);
            if (sprite->data[7] > 63)
            {
                sprite->data[5] = 3;
                sprite->data[6] = 10;
                sprite->data[7] = 0;
            }
            else
            {
                if (var > 48 && sprite->data[5] == 1)
                {
                    sprite->data[5] = 2;
                    sprite->data[6] = 20;
                }
                else if (var > 16 && sprite->data[5] == 0)
                {
                    sprite->data[5] = 1;
                    sprite->data[6] = 20;
                }
            }
        }

        sprite->data[7] += 2;
        HandleSetAffineData(sprite, 256 - var, 256 - var, 0);
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_3B(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale;

        sprite->pos2.y = Sin(sprite->data[7] % 256, 8);
        sprite->data[7] += 8;
        yScale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256, yScale + 256, 0);
    }
}

static void pokemonanimfunc_3C(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 256)
    {
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale;

        sprite->pos2.y = Sin(sprite->data[7], 16);
        sprite->data[7] += 4;
        yScale = Sin((sprite->data[7] % 64) * 2, 128);
        HandleSetAffineData(sprite, 256, yScale + 256, 0);
    }
}

static void sub_81825F8(struct Sprite *sprite);
static void sub_8182648(struct Sprite *sprite);
static void sub_81826F8(struct Sprite *sprite);

static void pokemonanimfunc_3D(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = sub_81825F8;
    sprite->data[7] = 0;
}

static void sub_81825F8(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 8;
    if (sprite->data[7] > 63)
    {
        sprite->data[7] = 0;
        sprite->data[6] = 0;
        sprite->callback = sub_8182648;
        yScale = Sin(64, 128); // 128 * 1 = 128
    }
    else
    {
        yScale = Sin(sprite->data[7], 128);
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
}

static void sub_8182648(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 4;
    if (sprite->data[7] > 95)
    {
        yScale = Cos(0, 128); // 128 * (-1) = -128
        sprite->data[7] = 0;
        sprite->data[6]++;
    }
    else
    {
        s16 sign, index;

        sprite->pos2.y = -(sprite->data[6] * 4) - Sin(sprite->data[7], 8);
        if (sprite->data[7] > 63)
        {
            sign = -1;
            index = sprite->data[7] - 64;
        }
        else
        {
            sign = 1;
            index = 0;
        }

        yScale = Cos((index * 2) + sprite->data[7], 128) * sign;
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
    if (sprite->data[6] == 3)
    {
        sprite->data[7] = 0;
        sprite->callback = sub_81826F8;
    }
}

static void sub_81826F8(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 8;
    yScale = Cos(sprite->data[7], 128);
    sprite->pos2.y = -(Cos(sprite->data[7], 12));
    if (sprite->data[7] > 63)
    {
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
}

static void sub_8182764(struct Sprite *sprite)
{
    if (sprite->data[7] > sprite->data[5])
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        HandleSetAffineData(sprite, 256, 256, 0);
    }
    else
    {
        s16 xScale;

        sprite->pos2.x = Sin(sprite->data[7] % 256, sprite->data[4]);
        sprite->data[7] += sprite->data[6];
        xScale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256 + xScale, 256, 0);
    }
}

static void pokemonanimfunc_3E(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 8;
    }

    sub_8182764(sprite);
}

static void sub_8182830(struct Sprite *sprite)
{
    if (sprite->data[7] > sprite->data[5])
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        HandleSetAffineData(sprite, 256, 256, 0);
    }
    else
    {
        s16 xScale;

        sprite->pos2.x = Sin(sprite->data[7] % 256, sprite->data[4]);
        sprite->data[7] += sprite->data[6];
        xScale = Sin((sprite->data[7] % 64) * 2, 128);
        HandleSetAffineData(sprite, 256 + xScale, 256, 0);
    }
}

static void pokemonanimfunc_3F(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 256;
        sprite->data[4] = 16;
    }

    sub_8182830(sprite);
}

static void pokemonanimfunc_40(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->pos2.x = Sin(sprite->data[7] % 256, 8);
        sprite->data[7] += 8;
        scale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_41(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->pos2.x = -(Sin((sprite->data[7] % 256) / 2, 16));
        sprite->data[7] += 8;
        scale = -(Sin((sprite->data[7] % 256) / 2, 64));
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_42(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->pos2.x = -(Sin(sprite->data[7] % 256 , 8));
        sprite->data[7] += 8;
        scale = Sin((sprite->data[7] % 256) / 2, 96);
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_43(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 caseVar = (sprite->data[2] / 512) % 4;
        switch (caseVar)
        {
        case 0:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->pos2.x = (sprite->data[2] % 512 / 32) - 16;
            break;
        case 2:
            sprite->pos2.x = (sprite->data[2] % 512) / 32;
            break;
        case 3:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        }

        sprite->pos2.y = -(Sin(sprite->data[2] % 128, 4));
        sprite->data[2] += 24;
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_44(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        sprite->data[6] = 0;
        sprite->data[7] = 64;
        sprite->data[2]++;
    }

    sprite->data[7] += 8;
    if (sprite->data[6] == 4)
    {
        if (sprite->data[7] > 63)
        {
            sprite->data[7] = 0;
            sprite->data[6]++;
        }
    }
    else
    {
        if (sprite->data[7] > 127)
        {
            sprite->data[7] = 0;
            sprite->data[6]++;
        }
    }

    switch (sprite->data[6])
    {
    case 1:
        sprite->pos2.x = -(Cos(sprite->data[7], 8));
        sprite->pos2.y = Sin(sprite->data[7], 8) - 8;
        break;
    case 2:
        sprite->pos2.x = Sin(sprite->data[7] + 128, 8) + 8;
        sprite->pos2.y = -(Cos(sprite->data[7], 8));
        break;
    case 3:
        sprite->pos2.x = Cos(sprite->data[7], 8);
        sprite->pos2.y = Sin(sprite->data[7] + 128, 8) + 8;
        break;
    case 0:
    case 4:
        sprite->pos2.x = Sin(sprite->data[7], 8) - 8;
        sprite->pos2.y = Cos(sprite->data[7], 8);
        break;
    default:
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        break;
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_45(struct Sprite *sprite)
{
    sprite->data[0] = 32;
    sub_8180714(sprite);
    sprite->callback = sub_8180714;
}

static void pokemonanimfunc_46(struct Sprite *sprite)
{
    sprite->data[0] = 80;
    sub_817F8FC(sprite);
    sprite->callback = sub_817F8FC;
}

static void pokemonanimfunc_47(struct Sprite *sprite)
{
    sprite->data[0] = 80;
    sub_817F978(sprite);
    sprite->callback = sub_817F978;
}

static void pokemonanimfunc_48(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 2048;
    sUnknown_03001240[id].field_8 = sprite->data[6];
    sub_8180900(sprite);
    sprite->callback = sub_8180900;
}

static void pokemonanimfunc_49(struct Sprite *sprite)
{
    sprite->data[6] = 1;
    pokemonanimfunc_05(sprite);
}

static void pokemonanimfunc_4A(struct Sprite *sprite)
{
    sprite->data[6] = 1;
    pokemonanimfunc_48(sprite);
}

static void pokemonanimfunc_4B(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[0] = 0;

    if (sprite->data[0] <= 0)
    {
        sub_817FC20(sprite);
        sprite->data[0] = 1;
    }
    else
    {
        sprite->data[0]--;
    }
}

static void pokemonanimfunc_4C(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sprite->data[7] = 3;
    sub_817FCDC(sprite);
    sprite->callback = sub_817FCDC;
}

static void pokemonanimfunc_4D(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sub_817FD44(sprite);
    sprite->callback = sub_817FD44;
}

static void pokemonanimfunc_4E(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 1024;
    sUnknown_03001240[id].field_0 = 0;
    sUnknown_03001240[id].field_4 = 2;
    sub_817FE30(sprite);
    sprite->callback = sub_817FE30;
}

static void pokemonanimfunc_4F(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 512;
    sUnknown_03001240[id].field_8 = 3;
    sUnknown_03001240[id].field_2 = 12;
    sub_817FFF0(sprite);
    sprite->callback = sub_817FFF0;
}

static void pokemonanimfunc_50(struct Sprite *sprite)
{
    sprite->data[0] = 24;
    sub_818031C(sprite);
    sprite->callback = sub_818031C;
}

static void pokemonanimfunc_51(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    sub_81804F8(sprite);
    sprite->callback = sub_81804F8;
}

static void pokemonanimfunc_52(struct Sprite *sprite)
{
    sprite->data[0] = 3;
    sub_817F9F4(sprite);
    sprite->callback = sub_817F9F4;
}

static void pokemonanimfunc_53(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_0 = 60;
    sUnknown_03001240[id].field_8 = 30;
    sub_817FF3C(sprite);
    sprite->callback = sub_817FF3C;
}

static void pokemonanimfunc_54(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_2 = 1;
    sUnknown_03001240[id].field_4 = 2;
    sub_8181214(sprite);
    sprite->callback = sub_8181214;
}

static void pokemonanimfunc_55(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 4;
    sUnknown_03001240[id].field_4 = 2;
    sub_8181810(sprite);
    sprite->callback = sub_8181810;
}

static void pokemonanimfunc_56(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_8 = 1;
    sUnknown_03001240[id].field_4 = 2;
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    sub_8181ABC(sprite);
    sprite->callback = sub_8181ABC;
}

static void pokemonanimfunc_07(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 2;
    sub_8181CE8(sprite);
    sprite->callback = sub_8181CE8;
}

static void pokemonanimfunc_08(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 4;
    sUnknown_03001240[id].field_4 = 2;
    sub_8181CE8(sprite);
    sprite->callback = sub_8181CE8;
}

static void pokemonanimfunc_0B(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_8 = 100;
    sub_81814D4(sprite);
    sprite->callback = sub_81814D4;
}

static void pokemonanimfunc_0C(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_8 = 50;
    sUnknown_03001240[id].field_4 = 2;
    sub_81814D4(sprite);
    sprite->callback = sub_81814D4;
}

static void pokemonanimfunc_0D(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_8 = 100;
    sub_81815D4(sprite);
    sprite->callback = sub_81815D4;
}

static void pokemonanimfunc_0E(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_8 = 50;
    sUnknown_03001240[id].field_4 = 2;
    sub_81815D4(sprite);
    sprite->callback = sub_81815D4;
}

static void sub_8183140(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = Sin((counter + 192) % 256, sprite->data[7]) + sprite->data[7];
    }

    sprite->data[2] += sprite->data[0];
}

static void pokemonanimfunc_57(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    sub_8183140(sprite);
    sprite->callback = sub_8183140;
}

static void pokemonanimfunc_58(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sprite->data[7] = 3;
    sub_8183140(sprite);
    sprite->callback = sub_8183140;
}

static void pokemonanimfunc_59(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;
        switch (divCase)
        {
        case 0:
            sprite->pos2.x = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->pos2.x = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->pos2.y = Sin(sprite->data[2] % 128, 4);
        sprite->data[2] += 24;
    }

    sub_817F70C(sprite);
}

static void sub_81832C8(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->pos2.y = 0;
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale, yScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        if (sprite->data[1] == 0)
            xScale = -256 - Sin(index2, 16);
        else
            xScale = 256 + Sin(index2, 16);

        amplitude = sprite->data[3];
        yScale = 256 - Sin(index2, amplitude) - Sin(index1, amplitude / 5);
        SetAffineData(sprite, xScale, yScale, 0);
        sprite->data[5]++;
    }
}

static void pokemonanimfunc_5A(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_81832C8(sprite);
}

static void sub_8183418(struct Sprite *sprite)
{
    s16 index1 = 0, index2;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        amplitude = sprite->data[3];

        if (sprite->data[1] == 0)
            xScale = -256 + Sin(index2, amplitude) + Sin(index1, amplitude / 5 * 2);
        else
            xScale = 256 - Sin(index2, amplitude) - Sin(index1, amplitude / 5 * 2);

        SetAffineData(sprite, xScale, 256, 0);
        sprite->data[5]++;
    }
}

static void pokemonanimfunc_5B(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_8183418(sprite);
}

static void sub_8183574(struct Sprite *sprite)
{
    u8 var6, var7;
    u8 var8 = sprite->data[2];
    u8 var9 = sprite->data[6];
    u8 var5 = sUnknown_0860AA80[sprite->data[5]][0];
    u8 var2 = var5;
    if (var5 != 0xFF)
        var5 = sprite->data[7];
    else
        var5 = 0xFF; // needed to match

    var6 = sUnknown_0860AA80[sprite->data[5]][1];
    var7 = 0;
    if (var2 != 0xFE)
        var7 = (var6 - var9) * var5 / var6;

    if (var5 == 0xFF)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = Sin((var8 + 192) % 256, var7) + var7;
        if (var9 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

static void pokemonanimfunc_5C(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sprite->data[7] = 6;
    sub_8183574(sprite);
    sprite->callback = sub_8183574;
}

static void pokemonanimfunc_5D(struct Sprite *sprite)
{
    sprite->data[0] = 70;
    sprite->data[7] = 6;
    sub_817FCDC(sprite);
    sprite->callback = sub_817FCDC;
}

static void pokemonanimfunc_5E(struct Sprite *sprite)
{
    sprite->data[0] = 20;
    sub_817F8FC(sprite);
    sprite->callback = sub_817F8FC;
}

static void pokemonanimfunc_5F(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->pos2.x = Sin((sprite->data[2] * 128 / 40) % 256, 9) * sign;
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_60(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->pos2.x = Sin((sprite->data[2] * 128 / 40) % 256, 12) * sign;
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_61(struct Sprite *sprite)
{
    sprite->data[0] = 70;
    sprite->data[7] = 6;
    sub_8183140(sprite);
    sprite->callback = sub_8183140;
}

static void pokemonanimfunc_62(struct Sprite *sprite)
{
    sprite->data[0] = 24;
    sprite->data[7] = 6;
    sub_8183574(sprite);
    sprite->callback = sub_8183574;
}

static void pokemonanimfunc_63(struct Sprite *sprite)
{
    sprite->data[0] = 56;
    sprite->data[7] = 9;
    sub_8183574(sprite);
    sprite->callback = sub_8183574;
}

static void pokemonanimfunc_64(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    sUnknown_03001240[id].field_6 = 1024;
    sUnknown_03001240[id].field_8 = 6;
    sUnknown_03001240[id].field_2 = 24;
    sub_817FFF0(sprite);
    sprite->callback = sub_817FFF0;
}

static void sub_81837DC(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;
    if (sprite->data[5] > sprite->data[6])
    {
        sprite->pos2.y = 0;
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale, yScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        amplitude = sprite->data[3];

        if (sprite->data[1] == 0)
            xScale = Sin(index2, amplitude) + (Sin(index1, amplitude / 5 * 2) - 256);
        else
            xScale = 256 - Sin(index1, amplitude / 5 * 2) - Sin(index2, amplitude);

        yScale = 256 - Sin(index1, amplitude / 5) - Sin(index2, amplitude);
        SetAffineData(sprite, xScale, yScale, 0);
        sprite->data[5]++;
    }
}

static void pokemonanimfunc_65(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_81837DC(sprite);
}

static void pokemonanimfunc_66(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;
        switch (divCase)
        {
        case 0:
            sprite->pos2.x = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->pos2.x = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->pos2.y = Sin(sprite->data[2] % 128, 4);
        sprite->data[2] += 48;
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_67(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;
        switch (divCase)
        {
        case 0:
            sprite->pos2.x = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->pos2.x = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->pos2.x = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->pos2.y = Sin(sprite->data[2] % 96, 4);
        sprite->data[2] += 64;
    }

    sub_817F70C(sprite);
}

static const s8 sUnknown_0860ADBE[][3] =
{
//   x    y   timer
    {1,   1, 12},
    {-2,  0, 12},
    {1,  -1, 12},
    {0,  0,  0}
};

static void sub_8183B4C(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (sUnknown_0860ADBE[sprite->data[3]][2] / sprite->data[5] == sprite->data[2])
    {
        sprite->data[3]++;
        sprite->data[2] = 0;
    }

    if (sUnknown_0860ADBE[sprite->data[3]][2] / sprite->data[5] == 0)
    {
        if (--sprite->data[6] == 0)
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        else
            sprite->data[2] = 0;
    }
    else
    {
        s32 amplitude = sprite->data[5];
        sprite->pos2.x += (sUnknown_0860ADBE[sprite->data[3]][0] * amplitude);
        sprite->pos2.y += (sUnknown_0860ADBE[sprite->data[3]][1] * sprite->data[5]); // what's the point of the var if you're not reusing it?
        sprite->data[2]++;
        sub_817F70C(sprite);
    }
}

static void pokemonanimfunc_68(struct Sprite *sprite)
{
    sprite->data[5] = 1;
    sprite->data[6] = 1;
    sub_8183B4C(sprite);
    sprite->callback = sub_8183B4C;
}

static void pokemonanimfunc_69(struct Sprite *sprite)
{
    sprite->data[5] = 2;
    sprite->data[6] = 1;
    sub_8183B4C(sprite);
    sprite->callback = sub_8183B4C;
}

static void pokemonanimfunc_6A(struct Sprite *sprite)
{
    sprite->data[5] = 2;
    sprite->data[6] = 2;
    sub_8183B4C(sprite);
    sprite->callback = sub_8183B4C;
}

static void sub_8183C6C(struct Sprite *sprite)
{
    if (sprite->data[7] > 255)
    {
        if (sprite->data[5] <= 1)
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            HandleSetAffineData(sprite, 256, 256, 0);
        }
        else
        {
            sprite->data[5]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        s16 scale;

        sprite->data[7] += sprite->data[6];
        if (sprite->data[7] > 256)
            sprite->data[7] = 256;

        scale = Sin(sprite->data[7] / 2, 64);
        HandleSetAffineData(sprite, 256 - scale, 256 - scale, 0);
    }
}

static void pokemonanimfunc_6B(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 1;
    }

    sub_8183C6C(sprite);
    sub_817F70C(sprite);
}

static void pokemonanimfunc_6C(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 2;
    }

    sub_8183C6C(sprite);
    sub_817F70C(sprite);
}

static void pokemonanimfunc_6D(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 16;
    }

    sub_8182764(sprite);
}

static void pokemonanimfunc_6E(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 256;
        sprite->data[4] = 16;
    }

    sub_8182764(sprite);
}

static void pokemonanimfunc_6F(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 16;
    }

    sub_8182830(sprite);
}

static void pokemonanimfunc_70(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 8;
    }

    sub_8182830(sprite);
}

static void pokemonanimfunc_71(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 5;
        sprite->data[6] = 8;
    }

    sub_8180828(sprite);
}

static void pokemonanimfunc_72(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 3;
        sprite->data[6] = 4;
    }

    sub_8180828(sprite);
}

static void pokemonanimfunc_73(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[7] = 0;
    }

    sub_81832C8(sprite);
}

static void pokemonanimfunc_74(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[7] = 0;
    }

    sub_81832C8(sprite);
}

static void pokemonanimfunc_75(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_8183418(sprite);
}

static void pokemonanimfunc_76(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_8183418(sprite);
}

static void pokemonanimfunc_77(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_81837DC(sprite);
}

static void pokemonanimfunc_78(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    sub_81837DC(sprite);
}

static void sub_8183FA8(struct Sprite *sprite)
{
    if (sprite->data[7] > 255)
    {
        if (sprite->data[6] <= 1)
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
        }
        else
        {
            sprite->data[7] %= 256;
            sprite->data[6]--;
        }
    }
    else
    {
        sprite->pos2.x = -(Sin(sprite->data[7], sprite->data[5]));
        sprite->pos2.y = Sin((sprite->data[7] + 192) % 256, sprite->data[4]);
        if (sprite->pos2.y > 0)
            sprite->pos2.y *= -1;

        sprite->pos2.y += sprite->data[4];
        sprite->data[7] += sprite->data[3];
    }
}

static void pokemonanimfunc_79(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 4;
    }

    sub_8183FA8(sprite);
}

static void pokemonanimfunc_7A(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 6;
    }

    sub_8183FA8(sprite);
}

static void pokemonanimfunc_7B(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 8;
    }

    sub_8183FA8(sprite);
}

static void sub_81840C4(struct Sprite *sprite)
{
    if (sprite->data[7] > 256)
    {
        if (sprite->data[6] <= sprite->data[4])
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[4]++;
            sprite->data[7] = 0;
        }

        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s16 posX;

        if (sprite->data[7] > 159)
        {
            if (sprite->data[7] > 256)
                sprite->data[7] = 256;

            sprite->pos2.y = -(Sin(sprite->data[7] % 256, 8));
        }
        else if (sprite->data[7] > 95)
        {
            sprite->pos2.y = Sin(96, 6) - Sin((sprite->data[7] - 96) * 2, 4);
        }
        else
        {
            sprite->pos2.y = Sin(sprite->data[7], 6);
        }

        posX = -(Sin(sprite->data[7] / 2, sprite->data[5]));
        if (sprite->data[4] % 2 == 0)
            posX *= -1;

        sprite->pos2.x = posX;
        sprite->data[7] += sprite->data[3];
    }
}

static void pokemonanimfunc_7C(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 4;
    }

    sub_81840C4(sprite);
}

static void pokemonanimfunc_7D(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 6;
    }

    sub_81840C4(sprite);
}

static void pokemonanimfunc_7E(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 3;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 8;
    }

    sub_81840C4(sprite);
}

static void pokemonanimfunc_7F(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 4;
    }

    sub_8183FA8(sprite);
}

static void pokemonanimfunc_80(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 6;
    }

    sub_8183FA8(sprite);
}

static void pokemonanimfunc_81(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 8;
    }

    sub_8183FA8(sprite);
}

static void sub_8184290(struct Sprite *sprite)
{
    u16 index = Sin((sprite->data[2] * 128) / sprite->data[7], sprite->data[5]);
    sprite->data[6] = -(index << 8);
    sub_817F3F0(sprite, index, sprite->data[4], 0);
    HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
}

static void pokemonanimfunc_82(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 60;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 1;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        sub_8184290(sprite);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_83(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 90;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 1;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        sub_8184290(sprite);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_84(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 30;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 2;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            sub_817F77C(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        sub_8184290(sprite);
    }

    sprite->data[2]++;
}

static void sub_8184468(struct Sprite *sprite)
{
    if (sprite->data[2] > sprite->data[7])
    {
        sprite->pos2.y = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        u8 posY_unsigned;
        s8 posY_signed;
        s32 posY;
        s16 index = (u16)(sprite->data[2] % sprite->data[6] * 256) / sprite->data[6] % 256;
        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
            posY_unsigned = Sin(index, 32);
            posY_signed = posY_unsigned;
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
            posY_unsigned = Sin(index, 8);
            posY_signed = posY_unsigned;
        }

        posY = posY_signed;
        if (posY < 0)
            posY += 7;
        sprite->pos2.y = (u32)(posY) >> 3;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void pokemonanimfunc_85(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->pos2.y += 2;
        sprite->data[6] = 40;
        sprite->data[7] = 80;
    }

    sub_8184468(sprite);
}

static void pokemonanimfunc_86(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->pos2.y += 2;
        sprite->data[6] = 40;
        sprite->data[7] = 40;
    }

    sub_8184468(sprite);
}

static void pokemonanimfunc_87(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->pos2.y += 2;
        sprite->data[6] = 80;
        sprite->data[7] = 80;
    }

    sub_8184468(sprite);
}

static void sub_8184610(struct Sprite *sprite);
static void sub_8184640(struct Sprite *sprite);
static void sub_8184678(struct Sprite *sprite);
static void sub_81846B8(struct Sprite *sprite);

static void sub_81845D4(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x -= sprite->data[2];
    if (sprite->pos2.x <= -sprite->data[6])
    {
        sprite->pos2.x = -sprite->data[6];
        sprite->data[7] = 2;
        sprite->callback = sub_8184610;
    }

    sub_817F70C(sprite);
}

static void sub_8184610(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x += sprite->data[7];
    sprite->data[7]++;
    if (sprite->pos2.x >= 0)
        sprite->callback = sub_8184640;

    sub_817F70C(sprite);
}

static void sub_8184640(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x += sprite->data[7];
    sprite->data[7]++;
    if (sprite->pos2.x > sprite->data[6])
    {
        sprite->pos2.x = sprite->data[6];
        sprite->callback = sub_8184678;
    }

    sub_817F70C(sprite);
}

static void sub_8184678(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    if (sprite->data[3] >= sprite->data[5])
    {
        sprite->callback = sub_81846B8;
    }
    else
    {
        sprite->pos2.x += sprite->data[4];
        sprite->data[4] *= -1;
        sprite->data[3]++;
    }

    sub_817F70C(sprite);
}

static void sub_81846B8(struct Sprite *sprite)
{
    sub_817F70C(sprite);
    sprite->pos2.x -= 2;
    if (sprite->pos2.x <= 0)
    {
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    sub_817F70C(sprite);
}

static void pokemonanimfunc_88(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 4;
    sprite->data[6] = 12;
    sprite->data[5] = 16;
    sprite->data[4] = 4;
    sprite->data[3] = 0;
    sprite->data[2] = 2;
    sprite->callback = sub_81845D4;
}

static void pokemonanimfunc_89(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 2;
    sprite->data[6] = 8;
    sprite->data[5] = 12;
    sprite->data[4] = 2;
    sprite->data[3] = 0;
    sprite->data[2] = 1;
    sprite->callback = sub_81845D4;
}

static void pokemonanimfunc_8A(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->data[6] = 6;
    sprite->data[5] = 6;
    sprite->data[4] = 2;
    sprite->data[3] = 0;
    sprite->data[2] = 1;
    sprite->callback = sub_81845D4;
}

static void sub_8184770(struct Sprite *sprite)
{
    sprite->pos2.x = sprite->data[1];
    if (sprite->data[0] > 1)
    {
        sprite->data[1] *= -1;
        sprite->data[0] = 0;
    }
    else
    {
        sprite->data[0]++;
    }
}

struct YellowBlendStruct
{
    u8 field_0;
    u8 field_1;
};

static const struct YellowBlendStruct sUnknown_0860ADCC[] =
{
    {0, 1},
    {1, 2},
    {0, 15},
    {1, 1},
    {0, 15},
    {1, 1},
    {0, 15},
    {1, 1},
    {0, 1},
    {1, 1},
    {0, 1},
    {1, 1},
    {0, 1},
    {1, 1},
    {0, 1},
    {1, 1},
    {0, 1},
    {1, 1},
    {0, 1},
    {0, 0xFF}
};

static const struct YellowBlendStruct sUnknown_0860AE1C[] =
{
    {0, 5},
    {1, 1},
    {0, 15},
    {1, 4},
    {0, 2},
    {1, 2},
    {0, 2},
    {1, 2},
    {0, 2},
    {1, 2},
    {0, 2},
    {1, 2},
    {0, 2},
    {0, 0xFF}
};

static const struct YellowBlendStruct sUnknown_0860AE54[] =
{
    {0, 1},
    {1, 1},
    {0, 20},
    {1, 1},
    {0, 20},
    {1, 1},
    {0, 20},
    {1, 1},
    {0, 1},
    {0, 0xFF}
};

static const struct YellowBlendStruct *const sUnknown_0860AE7C[] =
{
    sUnknown_0860ADCC,
    sUnknown_0860AE1C,
    sUnknown_0860AE54
};

static void BackAnimBlendYellow(struct Sprite *sprite)
{
    const struct YellowBlendStruct *array = sUnknown_0860AE7C[sprite->data[3]];
    sub_8184770(sprite);
    if (array[sprite->data[6]].field_1 == 0xFF)
    {
        sprite->pos2.x = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        if (sprite->data[4] == 1)
        {
            if (array[sprite->data[6]].field_0 != 0)
                BlendPalette(sprite->data[7], 0x10, 0x10, RGB_YELLOW);
            else
                BlendPalette(sprite->data[7], 0x10, 0, RGB_YELLOW);

            sprite->data[4] = 0;
        }

        if (array[sprite->data[6]].field_1 == sprite->data[5])
        {
            sprite->data[4] = 1;
            sprite->data[5] = 0;
            sprite->data[6]++;
        }
        else
        {
            sprite->data[5]++;
        }
    }
}

static void pokemonanimfunc_8B(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 0;
    }

    BackAnimBlendYellow(sprite);
}

static void pokemonanimfunc_8C(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 1;
    }

    BackAnimBlendYellow(sprite);
}

static void pokemonanimfunc_8D(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 2;
    }

    BackAnimBlendYellow(sprite);
}

static void BackAnimBlend(struct Sprite *sprite)
{
    static const u16 sColors[] =
    {
        RGB_RED, RGB_GREEN, RGB_BLUE, RGB_BLACK
    };

    if (sprite->data[2] > 127)
    {
        BlendPalette(sprite->data[7], 0x10, 0, RGB_RED);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], sColors[sprite->data[1]]);
    }
}

static void sub_8184934(struct Sprite *sprite)
{
    if (sprite->data[3] < sprite->data[4])
    {
        sub_817F70C(sprite);
        if (sprite->data[5] > sprite->data[0])
        {
            if (++sprite->data[3] < sprite->data[4])
                sprite->data[5] = 0;

            sprite->pos2.x = 0;
        }
        else
        {
            s8 sign = 1 - (sprite->data[3] % 2 * 2);
            sprite->pos2.x = sign * Sin((sprite->data[5] * 384 / sprite->data[0]) % 256, 6);
            sprite->data[5]++;
        }

        sub_817F70C(sprite);
    }
}

static void pokemonanimfunc_8E(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = 0;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_8F(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 0;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_90(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 0;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_91(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = 1;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_92(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 1;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_93(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 1;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_94(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = 2;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_95(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 2;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void pokemonanimfunc_96(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 2;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_8184934(sprite);

    sprite->data[2]++;
}

static void SpriteCB_SetDummyOnAnimEnd(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy;
}
