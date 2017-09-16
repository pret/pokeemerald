//
// Created by Scott Norton on 9/6/17.
//

#ifndef POKEEMERALD_FIELD_PLAYER_AVATAR_H
#define POKEEMERALD_FIELD_PLAYER_AVATAR_H

void ClearPlayerAvatarInfo(void);
void SetPlayerAvatarExtraStateTransition(u8, u8);
u8 GetPlayerAvatarGenderByGraphicsId(u8);
bool8 TestPlayerAvatarFlags(u8);
void PlayerGetDestCoords(s16 *, s16 *);
u8 player_get_direction_lower_nybble(void);
u8 player_get_direction_upper_nybble(void);
u8 player_get_x22(void);

#endif //POKEEMERALD_FIELD_PLAYER_AVATAR_H
