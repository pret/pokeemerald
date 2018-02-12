#ifndef GUARD_MAIL_H
#define GUARD_MAIL_H

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

// mail.h
void ReadMail(struct MailStruct *mail, void (*callback)(void), bool8 flag);

// mail_data.h
void ClearMailData(void);
void ClearMailStruct(struct MailStruct *mail);
bool8 MonHasMail(struct Pokemon *mon);
u8 GiveMailToMon(struct Pokemon *mon, u16 itemId);
u16 SpeciesToMailSpecies(u16 species, u32 personality);
u16 MailSpeciesToSpecies(u16 mailSpecies, u16 *buffer);
u8 GiveMailToMon2(struct Pokemon *mon, struct MailStruct *mail);
void TakeMailFromMon(struct Pokemon *mon);
void ClearMailItemId(u8 mailId);
u8 TakeMailFromMon2(struct Pokemon *mon);
bool8 ItemIsMail(u16 itemId);

#endif // GUARD_MAIL_H
