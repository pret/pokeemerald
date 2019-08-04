#ifndef GUARD_LILYCOVE_LADY_H
#define GUARD_LILYCOVE_LADY_H

u8 GetLilycoveLadyId(void);
void SetLilycoveLady(void);
void sub_818DA78(void);
void sub_818DEF4(void);
void sub_818E564(void);
void sub_818E570(const LilycoveLady *lilycoveLady);
bool8 GivePokeblockToContestLady(struct Pokeblock *pokeblock);
void BufferContestLadyMonName(u8 *dest1, u8 *dest2);
void BufferContestLadyPlayerName(u8 *dest);
void BufferContestLadyLanguage(u8 *dest);
void BufferContestName(u8 *dest, u8 category);
u8 sub_818E880(void);

#endif //GUARD_LILYCOVE_LADY_H
