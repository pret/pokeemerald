#ifndef GUARD_EVOLUTION_GRAPHICS_H
#define GUARD_EVOLUTION_GRAPHICS_H

void LoadEvoSparkleSpriteAndPal(void);

u8 EvolutionSparkles_SpiralUpward(u16 palNum);
u8 EvolutionSparkles_ArcDown(void);
u8 EvolutionSparkles_CircleInward(void);
u8 EvolutionSparkles_SprayAndFlash(u16 species);
u8 EvolutionSparkles_SprayAndFlash_Trade(u16 species);
u8 CycleEvolutionMonSprite(u8 preEvoSpriteId, u8 postEvoSpriteId);

#endif // GUARD_EVOLUTION_GRAPHICS_H
