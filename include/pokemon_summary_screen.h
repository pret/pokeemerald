#ifndef GUARD_POKEMON_SUMMARY_SCREEN_H
#define GUARD_POKEMON_SUMMARY_SCREEN_H

#include "main.h"
#include "config/summary_screen.h"
#include "constants/move_relearner.h"

extern u8 gLastViewedMonIndex;

extern const struct SpriteTemplate gSpriteTemplate_MoveTypes;
extern const struct CompressedSpriteSheet gSpriteSheet_MoveTypes;
extern const struct CompressedSpriteSheet gSpriteSheet_CategoryIcons;
extern const struct SpritePalette gSpritePal_CategoryIcons;
extern const struct SpriteTemplate gSpriteTemplate_CategoryIcons;
extern MainCallback gInitialSummaryScreenCallback;

enum IncrDecrUpdateValues
{
    TRY_SET_UPDATE,
    TRY_INCREMENT,
    TRY_DECREMENT,
};

// The Pokémon Summary Screen can operate in different modes. Certain features,
// such as move re-ordering, are available in the different modes.
enum PokemonSummaryScreenMode
{
    SUMMARY_MODE_NORMAL,
    SUMMARY_MODE_LOCK_MOVES,
    SUMMARY_MODE_BOX,
    SUMMARY_MODE_BOX_CURSOR, // mon is being moved in PC
    SUMMARY_MODE_SELECT_MOVE,
    SUMMARY_MODE_RELEARNER_BATTLE, // returning from move relearner initiated from battle moves page
    SUMMARY_MODE_RELEARNER_CONTEST, // returning from move relearner initiated from contest moves page
};

enum PokemonSummaryScreenPage
{
    PSS_PAGE_INFO,
    PSS_PAGE_SKILLS,
    PSS_PAGE_BATTLE_MOVES,
    PSS_PAGE_CONTEST_MOVES,
    PSS_PAGE_COUNT,
};

enum PokemonSummarySkillsMode
{
    SUMMARY_SKILLS_MODE_STATS,
    SUMMARY_SKILLS_MODE_IVS,
    SUMMARY_SKILLS_MODE_EVS,
};

void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, void (*callback)(void), u16 newMove);
u8 GetMoveSlotToReplace(void);
void SummaryScreen_SetAnimDelayTaskId(u8 taskId);

#endif // GUARD_POKEMON_SUMMARY_SCREEN_H
