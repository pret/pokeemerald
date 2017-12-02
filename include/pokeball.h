#ifndef GUARD_POKEBALL_H
#define GUARD_POKEBALL_H

#define POKEBALL_COUNT 12

#define POKEBALL_PLAYER_SENDOUT     0xFF
#define POKEBALL_OPPONENT_SENDOUT   0xFE

u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow);
void LoadBallGfx(u8 ballId);
void FreeBallGfx(u8 ballId);
void sub_8076918(u8 bank);
void DoHitAnimHealthboxEffect(u8 bank);

#endif // GUARD_POKEBALL_H
