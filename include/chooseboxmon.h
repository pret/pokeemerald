#ifndef GUARD_CHOOSEBOXMON_H
#define GUARD_CHOOSEBOXMON_H

struct MoveLearnUI {
    void (*askConfirmation)(void);
    s32 (*waitConfirmation)(void);
    void (*printMessage)(const u8 *message);
    void (*playFanfare)(u32 songId);
    void (*showMoveList)(u8 taskId);
    void (*endTask)(u8 taskId);
};

u32 IsBoxMonExcluded(struct BoxPokemon *boxmon);
bool32 CanBoxMonBeSelected(struct BoxPokemon *boxmon);
s32 LearnMove(const struct MoveLearnUI *ui, u8 taskId);
s32 GetLearnMoveStartState(void);
s32 GetLearnMoveStartAfterPromptState(void);
s32 GetLearnMoveResumeAfterSummaryScreenState(void);

#endif // GUARD_CHOOSEBOXMON_H
