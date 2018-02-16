#ifndef GUARD_INTRO_CREDITS_GRAPHICS_H
#define GUARD_INTRO_CREDITS_GRAPHICS_H

extern u16 gUnknown_0203BD24;
extern u16 gUnknown_0203BD26;
extern u16 gUnknown_0203BD28;

extern const struct CompressedSpriteSheet gIntro2BrendanSpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2MaySpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2BicycleSpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2FlygonSpriteSheet[];
extern const struct SpritePalette gUnknown_085F530C[];

void load_intro_part2_graphics(u8 a);
void sub_817B150(u8 a);
u8 sub_817B3DC(u8 a, u16 b, u16 c, u16 d);
void sub_817B540(u8);
u8 intro_create_brendan_sprite(s16 a, s16 b);
u8 intro_create_may_sprite(s16 a, s16 b);
u8 intro_create_flygon_sprite(s16 a, s16 b);

#endif // GUARD_INTRO_CREDITS_GRAPHICS_H
