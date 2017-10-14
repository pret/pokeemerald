#ifndef GUARD_BATTLE_ANIM_H
#define GUARD_BATTLE_ANIM_H

enum
{
    ANIM_BANK_ATTACKER,
    ANIM_BANK_TARGET,
    ANIM_BANK_ATK_PARTNER,
    ANIM_BANK_DEF_PARTNER,
};

enum
{
    BG_ANIM_SCREEN_SIZE,
    BG_ANIM_AREA_OVERFLOW_MODE,
    BG_ANIM2,
    BG_ANIM3,
    BG_ANIM_PRIORITY,
    BG_ANIM_5,
    BG_ANIM_6
};

struct UnknownAnimStruct2
{
    void *unk0;
    u16 *unk4;
    u8 unk8;
    u8 unk9;
    u16 unkA;
    u16 unkC;
};

void ClearBattleAnimationVars(void);
void DoMoveAnim(u16 move);
void DoBattleAnim(const u8 *const animsTable[], u16 tableId, bool8 isMoveAnim);
void DestroyAnimSprite(struct Sprite *sprite);
void DestroyAnimVisualTask(u8 taskId);
void DestroyAnimSoundTask(u8 taskId);
bool8 IsAnimBankSpriteVisible(u8 bank);
void sub_80A438C(u8 bank, bool8 toBG_2, bool8 setSpriteInvisible);

bool8 IsContest(void);

// battle_anim_80FE840.s
void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value);
void sub_8118FBC(u8 arg0, u8 arg1, u8 arg2, u8 bankIdentity, u8 arg4, void *arg5, u16 *arg6, u16 arg7);

#endif // GUARD_BATTLE_ANIM_H
