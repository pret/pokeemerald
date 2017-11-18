#ifndef GUARD_MAIL_H
#define GUARD_MAIL_H

#include "items.h"

#define IS_ITEM_MAIL(itemId)((itemId == ITEM_ORANGE_MAIL            \
                              || itemId == ITEM_HARBOR_MAIL         \
                              || itemId == ITEM_GLITTER_MAIL        \
                              || itemId == ITEM_MECH_MAIL           \
                              || itemId == ITEM_WOOD_MAIL           \
                              || itemId == ITEM_WAVE_MAIL           \
                              || itemId == ITEM_BEAD_MAIL           \
                              || itemId == ITEM_SHADOW_MAIL         \
                              || itemId == ITEM_TROPIC_MAIL         \
                              || itemId == ITEM_DREAM_MAIL          \
                              || itemId == ITEM_FAB_MAIL            \
                              || itemId == ITEM_RETRO_MAIL))


bool8 MonHasMail(struct Pokemon *mon);
void TakeMailFromMon(struct Pokemon *mon);
u8 GiveMailToMon2(struct Pokemon *mon, struct MailStruct *mail);
void ClearMailStruct(struct MailStruct *mail);

#endif // GUARD_MAIL_H
