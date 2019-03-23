#ifndef GUARD_INTRO_CREDITS_GRAPHICS_H
#define GUARD_INTRO_CREDITS_GRAPHICS_H

extern u16 gUnknown_0203BD24;
extern s16 gUnknown_0203BD26;
extern s16 gUnknown_0203BD28;

extern const struct CompressedSpriteSheet gIntro2BrendanSpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2MaySpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2BicycleSpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2FlygonSpriteSheet[];
extern const struct SpritePalette gIntroBikeAndFlygonPalette[];
extern const struct CompressedSpriteSheet gUnknown_085F5334[];
extern const struct CompressedSpriteSheet gUnknown_085F5344[];
extern const struct CompressedSpriteSheet gUnknown_085F5354[];
extern const struct CompressedSpriteSheet gUnknown_085F53AC[];
extern const struct CompressedSpriteSheet gUnknown_085F53BC[];
extern const struct SpritePalette gUnknown_085F5384[];

void load_intro_part2_graphics(u8 a);
void sub_817B150(u8 a);
void sub_817B1C8(u8);
void sub_817B3A8(u8);
u8 CreateBicycleAnimationTask(u8 a, u16 b, u16 c, u16 d);
void sub_817B540(u8);
u8 intro_create_brendan_sprite(s16 a, s16 b);
u8 intro_create_may_sprite(s16 a, s16 b);
u8 intro_create_flygon_sprite(s16 a, s16 b);

#endif // GUARD_INTRO_CREDITS_GRAPHICS_H
