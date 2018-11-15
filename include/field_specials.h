#ifndef GUARD_FIELD_SPECIALS_H
#define GUARD_FIELD_SPECIALS_H

#include <gba/gba.h>

u8 GetLeadMonIndex(void);
u8 sub_813B260(void);
u16 get_unknown_box_id(void);
bool8 InMultiBattleRoom(void);
void sub_813BF10(void);
void increment_var_x4026_on_birth_island_modulo_100(void);
bool8 sub_813B3B0(void);
bool8 ShouldDoBrailleRegicePuzzle(void);
bool32 is_tile_that_overrides_player_control(void);
bool32 sub_8138120(void);
bool32 sub_8138168(void);
bool32 sub_81381B0(void);
bool32 sub_81381F8(void);
bool32 CountSSTidalStep(u16 delta);
void sub_813A128(void);
void sub_813A878(u8 a0);

#endif // GUARD_FIELD_SPECIALS_H
