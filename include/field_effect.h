#ifndef GUARD_FIELD_EFFECTS_H
#define GUARD_FIELD_EFFECTS_H

#include "task.h"

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[2];
extern const struct SpritePalette gNewGameBirchObjectPaletteInfo;
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[2];
extern const struct SpriteTemplate gNewGameBirchObjectTemplate;
extern const struct OamData gNewGameBirchOamAttributes;

enum FieldEffectScriptIdx
{
    FLDEFF_EXCLAMATION_MARK_ICON,
    FLDEFF_USE_CUT_ON_GRASS,
    FLDEFF_USE_CUT_ON_TREE,
    FLDEFF_SHADOW,
    FLDEFF_TALL_GRASS,
    FLDEFF_RIPPLE,
    FLDEFF_FIELD_MOVE_SHOW_MON,
    FLDEFF_ASH,
    FLDEFF_SURF_BLOB,
    FLDEFF_USE_SURF,
    FLDEFF_DUST,
    FLDEFF_USE_SECRET_POWER_CAVE,
    FLDEFF_JUMP_TALL_GRASS,
    FLDEFF_SAND_FOOTPRINTS,
    FLDEFF_JUMP_BIG_SPLASH,
    FLDEFF_SPLASH,
    FLDEFF_JUMP_SMALL_SPLASH,
    FLDEFF_LONG_GRASS,
    FLDEFF_JUMP_LONG_GRASS,
    FLDEFF_UNKNOWN_19,
    FLDEFF_UNKNOWN_20,
    FLDEFF_UNKNOWN_21,
    FLDEFF_UNKNOWN_22,
    FLDEFF_BERRY_TREE_GROWTH_SPARKLE,
    FLDEFF_DEEP_SAND_FOOTPRINTS,
    FLDEFF_POKECENTER_HEAL,
    FLDEFF_USE_SECRET_POWER_TREE,
    FLDEFF_USE_SECRET_POWER_SHRUB,
    FLDEFF_TREE_DISGUISE,
    FLDEFF_MOUNTAIN_DISGUISE,
    FLDEFF_NPCFLY_OUT,
    FLDEFF_USE_FLY,
    FLDEFF_FLY_IN,
    FLDEFF_QUESTION_MARK_ICON,
    FLDEFF_FEET_IN_FLOWING_WATER,
    FLDEFF_BIKE_TIRE_TRACKS,
    FLDEFF_SAND_DISGUISE,
    FLDEFF_USE_ROCK_SMASH,
    FLDEFF_USE_DIG,
    FLDEFF_SAND_PILE,
    FLDEFF_USE_STRENGTH,
    FLDEFF_SHORT_GRASS,
    FLDEFF_HOT_SPRINGS_WATER,
    FLDEFF_USE_WATERFALL,
    FLDEFF_USE_DIVE,
    FLDEFF_POKEBALL,
    FLDEFF_HEART_ICON,
    FLDEFF_NOP_47,
    FLDEFF_NOP_48,
    FLDEFF_POP_OUT_OF_ASH,
    FLDEFF_LAVARIDGE_GYM_WARP,
    FLDEFF_SWEET_SCENT,
    FLDEFF_SAND_PILLAR,
    FLDEFF_BUBBLES,
    FLDEFF_SPARKLE,
    FLDEFF_SECRET_POWER_CAVE,
    FLDEFF_SECRET_POWER_TREE,
    FLDEFF_SECRET_POWER_SHRUB,
    FLDEFF_CUT_GRASS,
    FLDEFF_FIELD_MOVE_SHOW_MON_INIT,
    FLDEFF_USE_FLY_ANCIENT_TOMB,
    FLDEFF_PCTURN_ON,
    FLDEFF_HALL_OF_FAME_RECORD,
    FLDEFF_USE_TELEPORT,
    FLDEFF_64,
    FLDEFF_65,
    FLDEFF_66,
};

extern s32 gFieldEffectArguments[8];
extern void (*gPostMenuFieldCallback)(void);
extern bool8 (*gFieldCallback2)(void);

u32 FieldEffectStart(u8);
bool8 FieldEffectActiveListContains(u8 id);
void sub_80B69DC(void);
u8 AddNewGameBirchObject(s16, s16, u8);
void FieldEffectStop(struct Sprite *sprite, u8 id);
u8 CreateTrainerSprite(u8 trainerSpriteID, s16 x, s16 y, u8 subpriority, u8 *buffer);
void CreateTeleportFieldEffectTask(void);
void FieldEffectActiveListRemove(u8 id);
void MultiplyInvertedPaletteRGBComponents(u16, u8, u8, u8);
void FieldEffectActiveListAdd(u8 id);
void FieldEffectScript_LoadTiles(u8 **script);
void FieldEffectScript_LoadFadedPalette(u8 **script);
void FieldEffectScript_LoadPalette(u8 **script);
void FieldEffectScript_CallNative(u8 **script, u32 *val);
void FieldEffectFreeTilesIfUnused(u16 tileStart);
void FieldEffectFreePaletteIfUnused(u8 paletteNum);
bool8 FieldEffectCmd_loadtiles(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadfadedpal(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadpal(u8 **script, u32 *val);
bool8 FieldEffectCmd_callnative(u8 **script, u32 *val);
bool8 FieldEffectCmd_end(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadgfx_callnative(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadtiles_callnative(u8 **script, u32 *val);
bool8 FieldEffectCmd_loadfadedpal_callnative(u8 **script, u32 *val);

void PokecenterHealEffect_0(struct Task *);
void PokecenterHealEffect_1(struct Task *);
void PokecenterHealEffect_2(struct Task *);
void PokecenterHealEffect_3(struct Task *);

void HallOfFameRecordEffect_0(struct Task *);
void HallOfFameRecordEffect_1(struct Task *);
void HallOfFameRecordEffect_2(struct Task *);
void HallOfFameRecordEffect_3(struct Task *);

void PokeballGlowEffect_0(struct Sprite *);
void PokeballGlowEffect_1(struct Sprite *);
void PokeballGlowEffect_2(struct Sprite *);
void PokeballGlowEffect_3(struct Sprite *);
void PokeballGlowEffect_4(struct Sprite *);
void PokeballGlowEffect_5(struct Sprite *);
void PokeballGlowEffect_6(struct Sprite *);
void PokeballGlowEffect_7(struct Sprite *);

bool8 sub_80B6BCC(struct Task *);
bool8 sub_80B6C74(struct Task *);
bool8 sub_80B6C90(struct Task *);
bool8 sub_80B6D04(struct Task *);
bool8 sub_80B6DBC(struct Task *);
bool8 sub_80B6DD8(struct Task *);
bool8 sub_80B6E18(struct Task *);

bool8 sub_80B6EC0(struct Task *);
bool8 sub_80B6EE0(struct Task *);
bool8 sub_80B6F50(struct Task *);
bool8 sub_80B6F74(struct Task *);
bool8 sub_80B6F84(struct Task *);
bool8 sub_80B6FA8(struct Task *);

bool8 sub_80B7114(struct Task *);
bool8 sub_80B7190(struct Task *);
bool8 sub_80B71D0(struct Task *);
bool8 sub_80B7230(struct Task *);
bool8 sub_80B7270(struct Task *);
bool8 sub_80B72D0(struct Task *);
bool8 sub_80B72F4(struct Task *);

bool8 sub_80B73D0(struct Task *, struct EventObject *);
bool8 waterfall_1_do_anim_probably(struct Task *, struct EventObject *);
bool8 waterfall_2_wait_anim_finish_probably(struct Task *, struct EventObject *);
bool8 sub_80B7450(struct Task *, struct EventObject *);
bool8 sub_80B7478(struct Task *, struct EventObject *);

bool8 dive_1_lock(struct Task *);
bool8 dive_2_unknown(struct Task *);
bool8 dive_3_unknown(struct Task *);

bool8 sub_80B764C(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7684(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B76B8(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7704(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B77F8(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7814(struct Task *, struct EventObject *, struct Sprite *);

bool8 sub_80B78EC(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B791C(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7968(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B79BC(struct Task *, struct EventObject *, struct Sprite *);

bool8 sub_80B7AE8(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7B18(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7B94(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7BCC(struct Task *, struct EventObject *, struct Sprite *);
bool8 sub_80B7BF4(struct Task *, struct EventObject *, struct Sprite *);

void sub_80B7D14(struct Task *);
void sub_80B7D34(struct Task *);

void sub_80B7EC4(struct Task *);
void sub_80B7EE8(struct Task *);

void sub_80B8280(struct Task *);
void sub_80B830C(struct Task *);
void sub_80B8410(struct Task *);

void sub_80B8584(struct Task *);
void sub_80B85F8(struct Task *);
void sub_80B8660(struct Task *);
void sub_80B86EC(struct Task *);
void sub_80B871C(struct Task *);
void sub_80B8770(struct Task *);
void overworld_bg_setup_2(struct Task *);

void sub_80B88E4(struct Task *);
void sub_80B8920(struct Task *);
void sub_80B898C(struct Task *);
void sub_80B89DC(struct Task *);
void sub_80B8A0C(struct Task *);
void sub_80B8A44(struct Task *);
void sub_80B8A64(struct Task *);

void sub_80B8DB4(struct Task *);
void sub_80B8E14(struct Task *);
void sub_80B8E60(struct Task *);
void sub_80B8EA8(struct Task *);
void sub_80B8F24(struct Task *);

void sub_80B9204(struct Task *);
void sub_80B925C(struct Task *);
void sub_80B92A0(struct Task *);
void sub_80B92F8(struct Task *);
void sub_80B933C(struct Task *);
void sub_80B9390(struct Task *);
void sub_80B9418(struct Task *);
void sub_80B9474(struct Task *);
void sub_80B9494(struct Task *);

void sub_80B9804(struct Task *);
void sub_80B98B8(struct Task *);
void sub_80B9924(struct Task *);
void sub_80B9978(struct Task *);
void sub_80B99F0(struct Task *);
void sub_80B9A28(struct Task *);
void sub_80B9A60(struct Task *);

void sub_80B9C28(s16*, u8);
void sub_80B9C54(s16*, u8);
void sub_80B9CDC(s16*, u8);

void sub_80B7CAC(struct Sprite*);
void sub_80B7A58(struct Sprite*);

void MultiplyPaletteRGBComponents(u16 i, u8 r, u8 g, u8 b);
void FreeResourcesAndDestroySprite(struct Sprite *sprite, u8 spriteId);
u8 CreateMonSprite_PicBox(u16 species, s16 x, s16 y, u8 subpriority);

#endif //GUARD_FIELD_EFFECTS_H
