#ifndef GUARD_POKEBALL_H
#define GUARD_POKEBALL_H

#include "constants/pokeball.h"

enum {
    BALL_AFFINE_ANIM_0,
    BALL_ROTATE_RIGHT,
    BALL_ROTATE_LEFT,
    BALL_AFFINE_ANIM_3,
    BALL_AFFINE_ANIM_4
};

struct PokeBallSprite
{
    struct CompressedSpriteSheet pic;
    struct SpritePalette palette;
    struct SpriteTemplate spriteTemplate;
    enum Item itemId;
};

extern const struct PokeBallSprite gPokeBalls[];

#define POKEBALL_PLAYER_SENDOUT     0xFF
#define POKEBALL_OPPONENT_SENDOUT   0xFE
#define POKEBALL_PLAYER_SLIDEIN     0xFD

u8 DoPokeballSendOutAnimation(enum BattlerId battler, s16 pan, u8 kindOfThrow);
void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subpriority, u8 delay, u32 fadePalettes, enum Species species);
u8 CreateTradePokeballSprite(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 delay, u32 fadePalettes);
void StartHealthboxSlideIn(enum BattlerId battler);
void DoHitAnimHealthboxEffect(enum BattlerId battler);
void LoadBallGfx(enum PokeBall ballId);
void FreeBallGfx(enum PokeBall ballId);
enum PokeBall ItemIdToBallId(enum Item ballItem);

#endif // GUARD_POKEBALL_H
