#ifndef GUARD_BATTLE_INTERFACE_H
#define GUARD_BATTLE_INTERFACE_H

enum
{
    HEALTHBOX_ALL,
    HEALTHBOX_CURRENT_HP,
    HEALTHBOX_MAX_HP,
    HEALTHBOX_LEVEL,
    HEALTHBOX_NICK,
    HEALTHBOX_HEALTH_BAR,
    HEALTHBOX_EXP_BAR,
    HEALTHBOX_UNUSED_7,
    HEALTHBOX_UNUSED_8,
    HEALTHBOX_STATUS_ICON,
    HEALTHBOX_SAFARI_ALL_TEXT,
    HEALTHBOX_SAFARI_BALLS_TEXT
};

u8 CreateBankHealthboxSprites(u8 bank);
u8 CreateSafariPlayerHealthboxSprites(void);
void SetBankHealthboxSpritePos(u8 bank);
void SetHealthboxSpriteVisible(u8 healthboxSpriteId);
void SetHealthboxSpriteInvisible(u8 healthboxSpriteId);
void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId);
void nullsub_30(u8 healthboxSpriteId, bool8 isDoubleBattleBankOnly);

#endif // GUARD_BATTLE_INTERFACE_H
