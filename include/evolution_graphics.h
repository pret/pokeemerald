#ifndef GUARD_EVOLUTION_GRAPHICS_H
#define GUARD_EVOLUTION_GRAPHICS_H

void LoadEvoSparkleSpriteAndPal(void);

u8 LaunchTask_PreEvoSparklesSet1(u16 arg0);
u8 LaunchTask_PreEvoSparklesSet2(void);
u8 LaunchTask_PostEvoSparklesSet1(void);
u8 LaunchTask_PostEvoSparklesSet2AndFlash(u16 species);
u8 LaunchTask_PostEvoSparklesSet2AndFlash_Trade(u16 species);
u8 sub_817C3A0(u8 preEvoSpriteID, u8 postEvoSpriteID);

#define EvoGraphicsTaskEvoStop  data[8]

#endif // GUARD_EVOLUTION_GRAPHICS_H
