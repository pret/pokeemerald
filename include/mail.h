#ifndef GUARD_MAIL_H
#define GUARD_MAIL_H

#include "main.h"

#define IS_ITEM_MAIL(itemId) ((itemId == ITEM_ORANGE_MAIL           \
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

// mail.h
void ReadMail(struct Mail *mail, MainCallback exitCallback, bool8 hasText);

// mail_data.h
void ClearAllMail(void);
void ClearMail(struct Mail *mail);
bool8 MonHasMail(struct Pokemon *mon);
u8 GiveMailToMonByItemId(struct Pokemon *mon, enum Item itemId);
u16 SpeciesToMailSpecies(enum Species species, u32 personality);
enum Species MailSpeciesToSpecies(u16 mailSpecies, u16 *buffer);
u8 GiveMailToMon(struct Pokemon *mon, struct Mail *mail);
void TakeMailFromMon(struct Pokemon *mon);
u8 SaveMailToPC(struct Mail *mail);
u8 TakeMailFromMonAndSave(struct Pokemon *mon);
bool8 ItemIsMail(enum Item itemId);

#endif // GUARD_MAIL_H
