#ifndef GUARD_LILYCOVE_LADY_H
#define GUARD_LILYCOVE_LADY_H

u8 GetLilycoveLadyId(void);
void InitLilycoveLady(void);
void ResetLilycoveLadyForRecordMix(void);
void FieldCallback_FavorLadyEnableScriptContexts(void);
void FieldCallback_QuizLadyEnableScriptContexts(void);
void QuizLadyClearQuestionForRecordMix(const LilycoveLady *lilycoveLady);
bool8 GivePokeblockToContestLady(struct Pokeblock *pokeblock);
void BufferContestLadyMonName(u8 *category, u8 *nickname);
void BufferContestLadyPlayerName(u8 *dest);
void BufferContestLadyLanguage(u8 *dest);
void BufferContestName(u8 *dest, u8 category);
u8 GetContestLadyPokeblockState(void);

#endif //GUARD_LILYCOVE_LADY_H
