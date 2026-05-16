#include "global.h"
#include "graphics.h"

const u32 gBattleTextboxTiles[] = INCGFX_U32("graphics/battle_interface/textbox.png", ".4bpp.lz");
const u32 gBattleTextboxPalette[] = INCGFX_U32("graphics/battle_interface/textbox.gbapal", ".lz");
const u32 gBattleTextboxTilemap[] = INCGFX_U32("graphics/battle_interface/textbox_map.bin", ".lz");

const u32 gMonStillFrontPic_CircledQuestionMark[] = INCGFX_U32("graphics/pokemon/question_mark/circled/front.png", ".4bpp.lz");
const u32 gMonBackPic_CircledQuestionMark[] = INCGFX_U32("graphics/pokemon/question_mark/circled/back.png", ".4bpp.lz");
const u32 gMonPalette_CircledQuestionMark[] = INCGFX_U32("graphics/pokemon/question_mark/circled/normal.pal", ".gbapal.lz");
const u32 gMonShinyPalette_CircledQuestionMark[] = INCGFX_U32("graphics/pokemon/question_mark/circled/shiny.pal", ".gbapal.lz");

const u32 gUnusedGfx_OldCharmap[] = INCGFX_U32("graphics/unused/old_charmap.png", ".4bpp.lz"); // japanese table and bunch of stuff
const u32 gUnusedTimemap_OldCharmap[] = INCGFX_U32("graphics/unused/old_charmap.bin", ".lz");
const u32 gUnusedPal_OldCharmap[] = INCGFX_U32("graphics/unused/old_charmap.png", ".gbapal.lz");

const u32 gSmokescreenImpactTiles[] = INCGFX_U32("graphics/battle_anims/sprites/smokescreen_impact.png", ".4bpp.lz");
const u32 gSmokescreenImpactPalette[] = INCGFX_U32("graphics/battle_anims/sprites/smokescreen_impact.png", ".gbapal.lz");

#include "data/graphics/pokeballs.h"

const u32 gBlankGfxCompressed[] = INCGFX_U32("graphics/interface/blank.png", ".4bpp.lz");

// Battle anims
const u32 gBattleAnimSpriteGfx_Bubble[] = INCGFX_U32("graphics/battle_anims/sprites/bubble.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Bone[] = INCGFX_U32("graphics/battle_anims/sprites/bone.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_AirWave[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Orb[] = INCGFX_U32("graphics/battle_anims/sprites/orb.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Sword[] = INCGFX_U32("graphics/battle_anims/sprites/sword.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Seed[] = INCGFX_U32("graphics/battle_anims/sprites/seed.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_RainDrops[] = INCGFX_U32("graphics/battle_anims/sprites/rain_drops.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Bone[] = INCGFX_U32("graphics/battle_anims/sprites/bone.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_AirWave[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Orb[] = INCGFX_U32("graphics/battle_anims/sprites/orb.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Sword[] = INCGFX_U32("graphics/battle_anims/sprites/sword.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Seed[] = INCGFX_U32("graphics/battle_anims/sprites/seed.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Needle[] = INCGFX_U32("graphics/battle_anims/sprites/needle.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Needle[] = INCGFX_U32("graphics/battle_anims/sprites/needle.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Explosion6[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_6.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Explosion6[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_6.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PinkOrb[] = INCGFX_U32("graphics/battle_anims/sprites/pink_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PinkOrb[] = INCGFX_U32("graphics/battle_anims/sprites/pink_orb.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_IceCube[] = INCGFX_U32("graphics/battle_anims/sprites/ice_cube.pal", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_IceCube[] = INCGFX_U32("graphics/battle_anims/sprites/ice_cube.4bpp", ".lz");

const u32 gBattleAnimSpriteGfx_Gust[] = INCGFX_U32("graphics/battle_anims/sprites/gust.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Gust[] = INCGFX_U32("graphics/battle_anims/sprites/gust.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Spark2[] = INCGFX_U32("graphics/battle_anims/sprites/spark_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Spark2[] = INCGFX_U32("graphics/battle_anims/sprites/spark_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Orange[] = INCGFX_U32("graphics/battle_anims/sprites/orange.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Orange[] = INCGFX_U32("graphics/battle_anims/sprites/orange.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Spikes[] = INCGFX_U32("graphics/battle_anims/sprites/spikes.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Spikes[] = INCGFX_U32("graphics/battle_anims/sprites/spikes.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_YellowBall[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_ball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_YellowBall[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_ball.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_TiedBag[] = INCGFX_U32("graphics/battle_anims/sprites/tied_bag.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_TiedBag[] = INCGFX_U32("graphics/battle_anims/sprites/tied_bag.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BlackSmoke[] = INCGFX_U32("graphics/battle_anims/sprites/black_smoke.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BlackSmoke[] = INCGFX_U32("graphics/battle_anims/sprites/black_smoke.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BlackBall[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BlackBall[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball.pal", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Glass[] = INCGFX_U32("graphics/battle_anims/sprites/glass.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Glass[] = INCGFX_U32("graphics/battle_anims/sprites/glass.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_HornHit[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_HornHit[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_BlueShards[] = INCGFX_U32("graphics/battle_anims/sprites/blue_shards.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_BlueShards[] = INCGFX_U32("graphics/battle_anims/sprites/blue_shards.png", ".4bpp.lz");

const u32 gBattleAnimUnusedPal_MusicNotes[] = INCGFX_U32("graphics/battle_anims/unused/music_notes.pal", ".gbapal.lz");
const u32 gBattleAnimUnusedGfx_MusicNotes[] = INCGFX_U32("graphics/battle_anims/unused/music_notes.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Hit[] = INCGFX_U32("graphics/battle_anims/sprites/hit.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Hit[] = INCGFX_U32("graphics/battle_anims/sprites/hit.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Hit2[] = INCGFX_U32("graphics/battle_anims/sprites/hit_2.pal", ".gbapal.lz");

const u32 gBattleAnimSpritePal_WavingHand[] = INCGFX_U32("graphics/battle_anims/sprites/waving_hand.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_WavingHand[] = INCGFX_U32("graphics/battle_anims/sprites/waving_hand.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_ClosingEye[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_ClosingEye[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BlueStar[] = INCGFX_U32("graphics/battle_anims/sprites/blue_star.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BlueStar[] = INCGFX_U32("graphics/battle_anims/sprites/blue_star.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_BubbleBurst[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_BubbleBurst[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_HitDuplicate[] = INCGFX_U32("graphics/battle_anims/sprites/hit_duplicate.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_HitDuplicate[] = INCGFX_U32("graphics/battle_anims/sprites/hit_duplicate.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Leer[] = INCGFX_U32("graphics/battle_anims/sprites/leer.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Leer[] = INCGFX_U32("graphics/battle_anims/sprites/leer.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_BlueBurst[] = INCGFX_U32("graphics/battle_anims/sprites/blue_burst.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_BlueBurst[] = INCGFX_U32("graphics/battle_anims/sprites/blue_burst.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_SmallEmber[] = INCGFX_U32("graphics/battle_anims/sprites/small_ember.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SmallEmber[] = INCGFX_U32("graphics/battle_anims/sprites/small_ember.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GraySmoke[] = INCGFX_U32("graphics/battle_anims/sprites/gray_smoke.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GraySmoke[] = INCGFX_U32("graphics/battle_anims/sprites/gray_smoke.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Fire[] = INCGFX_U32("graphics/battle_anims/sprites/fire.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Fire[] = INCGFX_U32("graphics/battle_anims/sprites/fire.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_SpinningFire[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_fire.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_FirePlume[] = INCGFX_U32("graphics/battle_anims/sprites/fire_plume.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Lightning2[] = INCGFX_U32("graphics/battle_anims/sprites/lightning_2.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Lightning2[] = INCGFX_U32("graphics/battle_anims/sprites/lightning_2.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Lightning[] = INCGFX_U32("graphics/battle_anims/sprites/lightning.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_SpinningBall[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SpinningBall[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_SpinningBall2[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball_2.pal", ".gbapal.lz");

// old battle interface data, unused

const u32 gOldBattleInterfaceGfx[] = INCGFX_U32("graphics/unused/obi1.4bpp", ".lz");
const u32 gOldBattleInterfacePal_1_2_3[] = INCGFX_U32("graphics/unused/obi_palpak1.gbapal", ".lz"); // palettes 1-3
const u32 gOldBattleInterfacePal4[] = INCGFX_U32("graphics/unused/old_pal4.pal", ".gbapal.lz"); // 4 is by itself
const u32 gOldBattleInterfacePal_5_6_7[] = INCGFX_U32("graphics/unused/obi_palpak3.gbapal", ".lz"); // palettes 5-7
const u32 gOldBattleInterfaceGfx2[] = INCGFX_U32("graphics/unused/obi2.4bpp", ".lz");
const u32 gOldBattleInterfaceTilemap[] = INCGFX_U32("graphics/unused/old_battle_interface_tilemap.bin", ".lz");

const u32 gBattleAnimSpritePal_ClawSlash2[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash_2.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_ClawSlash[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_ClawSlash2[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash_2.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_ClawSlash[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Scratch3[] = INCGFX_U32("graphics/battle_anims/sprites/scratch_3.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Scratch2[] = INCGFX_U32("graphics/battle_anims/sprites/scratch_2.png", ".4bpp.lz");

const u32 gUnusedHpBar_Gfx[] = INCGFX_U32("graphics/battle_interface/hpbar_unused.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_BubbleBurst2[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst_2.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_BubbleBurst2[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_IceChunk[] = INCGFX_U32("graphics/battle_anims/sprites/ice_chunk.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_IceChunk[] = INCGFX_U32("graphics/battle_anims/sprites/ice_chunk.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Glass2[] = INCGFX_U32("graphics/battle_anims/sprites/glass_2.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Glass2[] = INCGFX_U32("graphics/battle_anims/sprites/glass_2.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_PinkHeart2[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart_2.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_PinkHeart2[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart_2.png", ".4bpp.lz");

const u32 gBattleInterfaceGfx_UnusedWindow1[] = INCGFX_U32("graphics/battle_interface/unused_window.png", ".4bpp.lz");
const u32 gBattleInterfacePal_UnusedWindow1[] = INCGFX_U32("graphics/battle_interface/unused_window.png", ".gbapal.lz");

const u32 gBattleInterfaceGfx_BattleBar[] = INCGFX_U32("graphics/battle_interface/battle_bar.4bpp", ".lz");

const u32 gBattleAnimSpriteGfx_SapDrip[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SapDrip[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_SapDrip2[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip_2.pal", ".gbapal.lz");

const u32 gBattleInterfaceGfx_UnusedWindow2[] = INCGFX_U32("graphics/battle_interface/unused_window2.png", ".4bpp.lz");
const u32 gBattleInterfaceGfx_UnusedWindow2Bar[] = INCGFX_U32("graphics/battle_interface/unused_window2bar.png", ".4bpp.lz", "-num_tiles 5 -Wnum_tiles");

const u32 gBattleAnimSpriteGfx_Sparkle1[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_1.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Sparkle1[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_1.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Sparkle2[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_2.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_HumanoidFoot[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_foot.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_HumanoidFoot[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_foot.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_MonsterFoot[] = INCGFX_U32("graphics/battle_anims/sprites/monster_foot.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_HumanoidHand[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_hand.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_LineSketch[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_LineSketch[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_YellowUnk[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_YellowUnk[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SlamHit[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SlamHit[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RedFist[] = INCGFX_U32("graphics/battle_anims/sprites/red_fist.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Ring[] = INCGFX_U32("graphics/battle_anims/sprites/ring.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Ring[] = INCGFX_U32("graphics/battle_anims/sprites/ring.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Rocks[] = INCGFX_U32("graphics/battle_anims/sprites/rocks.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Rocks[] = INCGFX_U32("graphics/battle_anims/sprites/rocks.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Z[] = INCGFX_U32("graphics/battle_anims/sprites/z.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Z[] = INCGFX_U32("graphics/battle_anims/sprites/z.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_YellowUnk2[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_YellowUnk2[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_AirSlash[] = INCGFX_U32("graphics/battle_anims/sprites/air_slash.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_AirSlash[] = INCGFX_U32("graphics/battle_anims/sprites/air_slash.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SpinningGreenOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_green_orbs.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SpinningGreenOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_green_orbs.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Leaf[] = INCGFX_U32("graphics/battle_anims/sprites/leaf.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Leaf[] = INCGFX_U32("graphics/battle_anims/sprites/leaf.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MetronomeSmallHand[] = INCGFX_U32("graphics/battle_anims/unused/metronome_hand_small.png", ".4bpp.lz"); // unused, was for metronome at one point

const u32 gBattleAnimSpritePal_Clapping[] = INCGFX_U32("graphics/battle_anims/sprites/clapping.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PoisonPowder[] = INCGFX_U32("graphics/battle_anims/sprites/poison_powder.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PoisonPowder[] = INCGFX_U32("graphics/battle_anims/sprites/poison_powder.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BrownTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/brown_triangle.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BrownTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/brown_triangle.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Sparkle3[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_3.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Sparkle3[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_3.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Sparkle4[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_4.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_MusicNotes[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MusicNotes[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Duck[] = INCGFX_U32("graphics/battle_anims/sprites/duck.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Duck[] = INCGFX_U32("graphics/battle_anims/sprites/duck.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Alert[] = INCGFX_U32("graphics/battle_anims/sprites/alert.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Alert[] = INCGFX_U32("graphics/battle_anims/sprites/alert.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Shock4[] = INCGFX_U32("graphics/battle_anims/sprites/shock_4.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Shock4[] = INCGFX_U32("graphics/battle_anims/sprites/shock_4.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Shock[] = INCGFX_U32("graphics/battle_anims/sprites/shock.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Bell2[] = INCGFX_U32("graphics/battle_anims/sprites/bell_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Bell2[] = INCGFX_U32("graphics/battle_anims/sprites/bell_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PinkGlove[] = INCGFX_U32("graphics/battle_anims/sprites/pink_glove.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PinkGlove[] = INCGFX_U32("graphics/battle_anims/sprites/pink_glove.png", ".gbapal.lz");

const u16 gBattleAnimUnused_Unknown1[] = INCBIN_U16("graphics/battle_anims/unused/unknown_1.bin");
const u16 gBattleAnimUnused_Unknown2[] = INCBIN_U16("graphics/battle_anims/unused/unknown_2.bin");
const u16 gBattleAnimUnused_Unknown3[] = INCBIN_U16("graphics/battle_anims/unused/unknown_3.bin");

const u32 gBattleAnimUnusedGfx_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.png", ".8bpp.lz");
const u32 gBattleAnimUnusedPal_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.pal", ".gbapal.lz");
const u32 gBattleAnimUnusedTilemap_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.bin", ".lz");

const u32 gBattleAnimSpriteGfx_BlueLines[] = INCGFX_U32("graphics/battle_anims/sprites/blue_lines.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BlueLines[] = INCGFX_U32("graphics/battle_anims/sprites/blue_lines.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Impact3[] = INCGFX_U32("graphics/battle_anims/sprites/impact_3.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Impact2[] = INCGFX_U32("graphics/battle_anims/sprites/impact_2.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Reticle[] = INCGFX_U32("graphics/battle_anims/sprites/reticle.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Breath[] = INCGFX_U32("graphics/battle_anims/sprites/breath.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Snowball[] = INCGFX_U32("graphics/battle_anims/sprites/snowball.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Vine[] = INCGFX_U32("graphics/battle_anims/sprites/vine.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Sword2[] = INCGFX_U32("graphics/battle_anims/sprites/sword_2.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_RedTube[] = INCGFX_U32("graphics/battle_anims/sprites/red_tube.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Amnesia[] = INCGFX_U32("graphics/battle_anims/sprites/amnesia.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_String2[] = INCGFX_U32("graphics/battle_anims/sprites/string_2.png", ".gbapal.lz");

const u32 gBattleAnimUnused_Unknown4[] = INCGFX_U32("graphics/battle_anims/unused/unknown_4.bin", ".lz");

const u32 gBattleAnimSpritePal_Pencil2[] = INCGFX_U32("graphics/battle_anims/sprites/pencil_2.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Petal[] = INCGFX_U32("graphics/battle_anims/sprites/petal.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_BentSpoon[] = INCGFX_U32("graphics/battle_anims/sprites/bent_spoon.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_Coin[] = INCGFX_U32("graphics/battle_anims/sprites/coin.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_CrackedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/cracked_egg.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_FreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/fresh_egg.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Impact3[] = INCGFX_U32("graphics/battle_anims/sprites/impact_3.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Impact2[] = INCGFX_U32("graphics/battle_anims/sprites/impact_2.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Reticle[] = INCGFX_U32("graphics/battle_anims/sprites/reticle.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Breath[] = INCGFX_U32("graphics/battle_anims/sprites/breath.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Snowball[] = INCGFX_U32("graphics/battle_anims/sprites/snowball.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Vine[] = INCGFX_U32("graphics/battle_anims/sprites/vine.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Sword2[] = INCGFX_U32("graphics/battle_anims/sprites/sword_2.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Clapping[] = INCGFX_U32("graphics/battle_anims/sprites/clapping.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_RedTube[] = INCGFX_U32("graphics/battle_anims/sprites/red_tube.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Amnesia[] = INCGFX_U32("graphics/battle_anims/sprites/amnesia.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_String2[] = INCGFX_U32("graphics/battle_anims/sprites/string_2.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Pencil2[] = INCGFX_U32("graphics/battle_anims/sprites/pencil_2.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Petal[] = INCGFX_U32("graphics/battle_anims/sprites/petal.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_BentSpoon[] = INCGFX_U32("graphics/battle_anims/sprites/bent_spoon.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Web[] = INCGFX_U32("graphics/battle_anims/sprites/web.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Coin[] = INCGFX_U32("graphics/battle_anims/sprites/coin.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_CrackedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/cracked_egg.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_HatchedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/hatched_egg.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_FreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/fresh_egg.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Fangs[] = INCGFX_U32("graphics/battle_anims/sprites/fangs.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Fangs[] = INCGFX_U32("graphics/battle_anims/sprites/fangs.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Explosion2[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Explosion2[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Explosion3[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_3.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_WaterDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WaterDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WaterDroplet2[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet_2.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Seed2[] = INCGFX_U32("graphics/battle_anims/sprites/seed_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Seed2[] = INCGFX_U32("graphics/battle_anims/sprites/seed_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Sprout[] = INCGFX_U32("graphics/battle_anims/sprites/sprout.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_RedWand[] = INCGFX_U32("graphics/battle_anims/sprites/red_wand.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RedWand[] = INCGFX_U32("graphics/battle_anims/sprites/red_wand.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PurpleGreenUnk[] = INCGFX_U32("graphics/battle_anims/sprites/purple_green_unk.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PurpleGreenUnk[] = INCGFX_U32("graphics/battle_anims/sprites/purple_green_unk.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WaterColumn[] = INCGFX_U32("graphics/battle_anims/sprites/water_column.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WaterColumn[] = INCGFX_U32("graphics/battle_anims/sprites/water_column.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MudUnk[] = INCGFX_U32("graphics/battle_anims/sprites/mud_unk.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MudUnk[] = INCGFX_U32("graphics/battle_anims/sprites/mud_unk.png", ".gbapal.lz");

const u32 gUnusedTilemap_BlueFrame[] = INCGFX_U32("graphics/unused/blue_frame.bin", ".lz"); // P1, P2, P3 and P4 tilemaps?
const u32 gUnusedTilemap_RedYellowGreenFrame[] = INCGFX_U32("graphics/unused/redyellowgreen_frame.bin", ".lz");
const u32 gUnusedGfx_ColorFrames[] = INCGFX_U32("graphics/unused/color_frames.png", ".4bpp.lz", "-num_tiles 353 -Wnum_tiles");
const u32 gUnusedPal_ColorFrames[] = INCGFX_U32("graphics/unused/color_frames.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RainDrops[] = INCGFX_U32("graphics/battle_anims/sprites/rain_drops.png", ".4bpp.lz");

const u32 gBattleAnimUnusedGfx_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.png", ".8bpp.lz");
const u32 gBattleAnimUnusedTilemap_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.bin", ".lz");
const u32 gBattleAnimUnusedPal_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.png", ".gbapal.lz");

const u32 gUnusedGfx_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.png", ".4bpp.lz");
const u32 gUnusedPal_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.png", ".gbapal.lz");
const u32 gUnusedTilemap_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.bin", ".lz");

// Battle Interface

const u16 gBattleInterface_BallStatusBarPal[] = INCGFX_U16("graphics/battle_interface/ball_status_bar.png", ".gbapal");

const u16 gBattleInterface_BallDisplayPal[] = INCGFX_U16("graphics/battle_interface/ball_display.png", ".gbapal");

const u8 gHealthboxElementsGfxTable[][32] = INCBIN_U8("graphics/battle_interface/hpbar.4bpp",
                                                  "graphics/battle_interface/expbar.4bpp",
                                                  "graphics/battle_interface/status.4bpp",
                                                  "graphics/battle_interface/misc.4bpp",
                                                  "graphics/battle_interface/hpbar_anim.4bpp",
                                                  "graphics/battle_interface/misc_frameend.4bpp",
                                                  "graphics/battle_interface/ball_display.4bpp",
                                                  "graphics/battle_interface/ball_caught_indicator.4bpp",
                                                  "graphics/battle_interface/status2.4bpp", // these three duplicate sets of graphics are for the opponent/partner Pokémon
                                                  "graphics/battle_interface/status3.4bpp",
                                                  "graphics/battle_interface/status4.4bpp",
                                                  "graphics/battle_interface/healthbox_doubles_frameend.4bpp",
                                                  "graphics/battle_interface/healthbox_doubles_frameend_bar.4bpp");
const u32 gBattleInterfaceGfx_UnusedWindow3[] = INCGFX_U32("graphics/battle_interface/unused_window3.png", ".4bpp.lz");
const u32 gBattleInterfaceGfx_UnusedWindow4[] = INCGFX_U32("graphics/battle_interface/unused_window4.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_FurySwipes[] = INCGFX_U32("graphics/battle_anims/sprites/fury_swipes.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_FurySwipes[] = INCGFX_U32("graphics/battle_anims/sprites/fury_swipes.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Vine2[] = INCGFX_U32("graphics/battle_anims/sprites/vine_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Vine2[] = INCGFX_U32("graphics/battle_anims/sprites/vine_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Teeth[] = INCGFX_U32("graphics/battle_anims/sprites/teeth.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Teeth[] = INCGFX_U32("graphics/battle_anims/sprites/teeth.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Bone2[] = INCGFX_U32("graphics/battle_anims/sprites/bone_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Bone2[] = INCGFX_U32("graphics/battle_anims/sprites/bone_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WhiteBag[] = INCGFX_U32("graphics/battle_anims/sprites/white_bag.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WhiteBag[] = INCGFX_U32("graphics/battle_anims/sprites/white_bag.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Unknown[] = INCGFX_U32("graphics/battle_anims/sprites/unknown.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Unknown[] = INCGFX_U32("graphics/battle_anims/sprites/unknown.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PurpleCoral[] = INCGFX_U32("graphics/battle_anims/sprites/purple_coral.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PurpleCoral[] = INCGFX_U32("graphics/battle_anims/sprites/purple_coral.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PurpleDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/purple_droplet.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Shock2[] = INCGFX_U32("graphics/battle_anims/sprites/shock_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Shock2[] = INCGFX_U32("graphics/battle_anims/sprites/shock_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_ClosingEye2[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_ClosingEye2[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MetalBall[] = INCGFX_U32("graphics/battle_anims/sprites/metal_ball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MetalBall[] = INCGFX_U32("graphics/battle_anims/sprites/metal_ball.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MonsterDoll[] = INCGFX_U32("graphics/battle_anims/sprites/monster_doll.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MonsterDoll[] = INCGFX_U32("graphics/battle_anims/sprites/monster_doll.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Whirlwind[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Whirlwind[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Whirlwind2[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_2.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Explosion4[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_4.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Explosion4[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_4.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Explosion5[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_5.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Tongue[] = INCGFX_U32("graphics/battle_anims/sprites/tongue.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Tongue[] = INCGFX_U32("graphics/battle_anims/sprites/tongue.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Smoke[] = INCGFX_U32("graphics/battle_anims/sprites/smoke.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Smoke[] = INCGFX_U32("graphics/battle_anims/sprites/smoke.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Smoke2[] = INCGFX_U32("graphics/battle_anims/sprites/smoke_2.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_BlueFlames[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BlueFlames[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BlueFlames2[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames_2.png", ".4bpp.lz");

// Contest
const u32 gJPContestGfx1[] = INCGFX_U32("graphics/contest/japanese/composite_1.4bpp", ".lz");
const u32 gJPContestPal[] = INCGFX_U32("graphics/contest/japanese/palette.pal", ".gbapal.lz");
const u32 gJPContestBgTilemap[] = INCGFX_U32("graphics/contest/japanese/bg.bin", ".lz");
const u32 gJPContestWindowsTilemap[] = INCGFX_U32("graphics/contest/japanese/windows.bin", ".lz");
const u32 gJPContestGfx2[] = INCGFX_U32("graphics/contest/japanese/composite_2.4bpp", ".lz");

const u32 gContestInterfaceAudiencePalette[] = INCGFX_U32("graphics/contest/interface.png", ".gbapal.lz");
const u32 gContestAudienceTilemap[] = INCGFX_U32("graphics/contest/audience.bin", ".lz");
const u32 gContestInterfaceTilemap[] = INCGFX_U32("graphics/contest/interface.bin", ".lz");
const u32 gJPContestInterfaceTilemap[] = INCGFX_U32("graphics/contest/japanese/interface.bin", ".lz");
const u32 gJPContestAudienceTilemap[] = INCGFX_U32("graphics/contest/japanese/audience.bin", ".lz");
const u32 gContestCurtainTilemap[] = INCGFX_U32("graphics/contest/curtain.bin", ".lz");

const u32 gContestInterfaceGfx[] = INCGFX_U32("graphics/contest/interface.png", ".4bpp.lz");
const u32 gContestAudienceGfx[] = INCGFX_U32("graphics/contest/audience.png", ".4bpp.lz");
const u32 gContestFaces_Gfx[] = INCGFX_U32("graphics/contest/faces.png", ".4bpp.lz");
const u32 gContestJudgeSymbolsGfx[] = INCGFX_U32("graphics/contest/judge_symbols.png", ".4bpp.lz");
const u32 gContestJudgeSymbolsPal[] = INCGFX_U32("graphics/contest/judge_symbols.png", ".gbapal.lz");
const u8 gContestSliderHeart_Gfx[] = INCGFX_U8("graphics/contest/slider_heart.png", ".4bpp");

// JP equivalent of the Applause meter
const u32 gJPContestVoltageGfx[] = INCGFX_U32("graphics/contest/japanese/voltage.png", ".4bpp.lz", "-num_tiles 36 -Wnum_tiles");
const u32 gJPContestVoltagePal[] = INCGFX_U32("graphics/contest/japanese/voltage.png", ".gbapal.lz");

// Contest results
const u32 gContestResults_Gfx[]                  = INCGFX_U32("graphics/contest/results_screen/tiles.png", ".4bpp.lz");
const u32 gContestResults_WinnerBanner_Tilemap[] = INCGFX_U32("graphics/contest/results_screen/winner_banner.bin", ".lz");
const u32 gContestResults_Interface_Tilemap[]    = INCGFX_U32("graphics/contest/results_screen/interface.bin", ".lz");
const u32 gContestResults_Bg_Tilemap[]           = INCGFX_U32("graphics/contest/results_screen/bg.bin", ".lz");
const u32 gContestResults_Pal[]                  = INCGFX_U32("graphics/contest/results_screen/tiles.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Impact[] = INCGFX_U32("graphics/battle_anims/sprites/impact.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Impact[] = INCGFX_U32("graphics/battle_anims/sprites/impact.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Particles[] = INCGFX_U32("graphics/battle_anims/sprites/particles.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_CircleImpact[] = INCGFX_U32("graphics/battle_anims/sprites/circle_impact.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_CircleImpact[] = INCGFX_U32("graphics/battle_anims/sprites/circle_impact.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Scratch[] = INCGFX_U32("graphics/battle_anims/sprites/scratch.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_SharpTeeth[] = INCGFX_U32("graphics/battle_anims/sprites/sharp_teeth.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SharpTeeth[] = INCGFX_U32("graphics/battle_anims/sprites/sharp_teeth.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Clamp[] = INCGFX_U32("graphics/battle_anims/sprites/clamp.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Cut[] = INCGFX_U32("graphics/battle_anims/sprites/cut.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_RainbowRings[] = INCGFX_U32("graphics/battle_anims/sprites/rainbow_rings.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RainbowRings[] = INCGFX_U32("graphics/battle_anims/sprites/rainbow_rings.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_IceCrystals[] = INCGFX_U32("graphics/battle_anims/sprites/ice_crystals.4bpp", ".lz");
const u32 gBattleAnimSpritePal_IceCrystals[] = INCGFX_U32("graphics/battle_anims/sprites/ice_crystals.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_IceSpikes[] = INCGFX_U32("graphics/battle_anims/sprites/ice_spikes.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_OldBeatUp[] = INCGFX_U32("graphics/battle_anims/unused/old_beatup.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_OldBeatUp[] = INCGFX_U32("graphics/battle_anims/unused/old_beatup.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Orbs[] = INCGFX_U32("graphics/battle_anims/sprites/orbs.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Orbs[] = INCGFX_U32("graphics/battle_anims/sprites/orbs.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WaterOrb[] = INCGFX_U32("graphics/battle_anims/sprites/water_orb.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_WaterImpact[] = INCGFX_U32("graphics/battle_anims/sprites/water_impact.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WaterImpact[] = INCGFX_U32("graphics/battle_anims/sprites/water_impact.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_BrownOrb[] = INCGFX_U32("graphics/battle_anims/sprites/brown_orb.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MudSand[] = INCGFX_U32("graphics/battle_anims/sprites/mud_sand.4bpp", ".lz");
const u32 gBattleAnimSpritePal_MudSand[] = INCGFX_U32("graphics/battle_anims/sprites/mud_sand.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PoisonBubble[] = INCGFX_U32("graphics/battle_anims/sprites/poison_bubble.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PoisonBubble[] = INCGFX_U32("graphics/battle_anims/sprites/poison_bubble.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_ToxicBubble[] = INCGFX_U32("graphics/battle_anims/sprites/toxic_bubble.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_HornHit2[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_HornHit2[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_AirWave2[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_AirWave2[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave_2.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SmallBubbles[] = INCGFX_U32("graphics/battle_anims/sprites/small_bubbles.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SmallBubbles[] = INCGFX_U32("graphics/battle_anims/sprites/small_bubbles.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RoundShadow[] = INCGFX_U32("graphics/battle_anims/sprites/round_shadow.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RoundShadow[] = INCGFX_U32("graphics/battle_anims/sprites/round_shadow.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Sunlight[] = INCGFX_U32("graphics/battle_anims/sprites/sunlight.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Sunlight[] = INCGFX_U32("graphics/battle_anims/sprites/sunlight.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Spore[] = INCGFX_U32("graphics/battle_anims/sprites/spore.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Spore[] = INCGFX_U32("graphics/battle_anims/sprites/spore.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Flower[] = INCGFX_U32("graphics/battle_anims/sprites/flower.4bpp", ".lz");
const u32 gBattleAnimSpritePal_Flower[] = INCGFX_U32("graphics/battle_anims/sprites/flower.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RazorLeaf[] = INCGFX_U32("graphics/battle_anims/sprites/razor_leaf.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RazorLeaf[] = INCGFX_U32("graphics/battle_anims/sprites/razor_leaf.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MistCloud[] = INCGFX_U32("graphics/battle_anims/sprites/mist_cloud.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MistCloud[] = INCGFX_U32("graphics/battle_anims/sprites/mist_cloud.png", ".gbapal.lz");

const u32 gBattleAnimUnusedGfx_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.png", ".4bpp.lz");
const u32 gBattleAnimUnusedPal_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.png", ".gbapal.lz");
const u32 gBattleAnimUnusedTilemap_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.bin", ".lz");

const u32 gBattleAnimSpriteGfx_WhirlwindLines[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_lines.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WhirlwindLines[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_lines.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GoldRing[] = INCGFX_U32("graphics/battle_anims/sprites/gold_ring.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GoldRing[] = INCGFX_U32("graphics/battle_anims/sprites/gold_ring.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_BlueRing2[] = INCGFX_U32("graphics/battle_anims/sprites/blue_ring_2.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_PurpleRing[] = INCGFX_U32("graphics/battle_anims/sprites/purple_ring.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_BlueRing[] = INCGFX_U32("graphics/battle_anims/sprites/blue_ring.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GreenLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/green_light_wall.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GreenLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/green_light_wall.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_BlueLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/blue_light_wall.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_RedLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/red_light_wall.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_GrayLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/gray_light_wall.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_OrangeLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/orange_light_wall.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BlackBall2[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BlackBall2[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball_2.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_PurpleGasCloud[] = INCGFX_U32("graphics/battle_anims/sprites/purple_gas_cloud.pal", ".gbapal.lz");

const u32 gContestJudgeGfx[] = INCGFX_U32("graphics/contest/judge.png", ".4bpp.lz");
const u32 gContest2Pal[] = INCGFX_U32("graphics/contest/judge.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Spark[] = INCGFX_U32("graphics/battle_anims/sprites/spark.4bpp", ".lz");
const u32 gBattleAnimSpritePal_Spark[] = INCGFX_U32("graphics/battle_anims/sprites/spark.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SparkH[] = INCGFX_U32("graphics/battle_anims/sprites/spark_h.png", ".4bpp.lz");

const u32 gBattleAnimBgImage_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.bin", ".lz");

const u32 gMetalShineGfx[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.png", ".4bpp.lz");
const u32 gMetalShinePalette[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.png", ".gbapal.lz");
const u32 gMetalShineTilemap[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.bin", ".lz");

const u32 gUnusedGfx_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.png", ".4bpp.lz"); // ghost
const u32 gUnusedPal_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.png", ".gbapal.lz");
const u32 gUnusedTilemap_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.bin", ".lz");

const u32 gBattleAnimSpriteGfx_YellowStar[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_star.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_YellowStar[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_star.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_LargeFreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/large_fresh_egg.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_LargeFreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/large_fresh_egg.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_ShadowBall[] = INCGFX_U32("graphics/battle_anims/sprites/shadow_ball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_ShadowBall[] = INCGFX_U32("graphics/battle_anims/sprites/shadow_ball.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Lick[] = INCGFX_U32("graphics/battle_anims/sprites/lick.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Lick[] = INCGFX_U32("graphics/battle_anims/sprites/lick.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_VoidLines[] = INCGFX_U32("graphics/battle_anims/sprites/void_lines.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_VoidLines[] = INCGFX_U32("graphics/battle_anims/sprites/void_lines.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_String[] = INCGFX_U32("graphics/battle_anims/sprites/string.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_String[] = INCGFX_U32("graphics/battle_anims/sprites/string.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_WebThread[] = INCGFX_U32("graphics/battle_anims/sprites/web_thread.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_SpiderWeb[] = INCGFX_U32("graphics/battle_anims/sprites/spider_web.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Lightbulb[] = INCGFX_U32("graphics/battle_anims/sprites/lightbulb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Lightbulb[] = INCGFX_U32("graphics/battle_anims/sprites/lightbulb.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Slash[] = INCGFX_U32("graphics/battle_anims/sprites/slash.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Slash[] = INCGFX_U32("graphics/battle_anims/sprites/slash.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_FocusEnergy[] = INCGFX_U32("graphics/battle_anims/sprites/focus_energy.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_FocusEnergy[] = INCGFX_U32("graphics/battle_anims/sprites/focus_energy.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SphereToCube[] = INCGFX_U32("graphics/battle_anims/sprites/sphere_to_cube.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SphereToCube[] = INCGFX_U32("graphics/battle_anims/sprites/sphere_to_cube.png", ".gbapal.lz");

const u32 gBattleAnimBgImage_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.bin", ".lz");

const u32 gBattleAnimSpriteGfx_Eye[] = INCGFX_U32("graphics/battle_anims/sprites/eye.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Eye[] = INCGFX_U32("graphics/battle_anims/sprites/eye.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Tendrils[] = INCGFX_U32("graphics/battle_anims/sprites/tendrils.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Tendrils[] = INCGFX_U32("graphics/battle_anims/sprites/tendrils.png", ".gbapal.lz");

const u32 gHealthboxSinglesPlayerGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_singles_player.png", ".4bpp.lz", "-mwidth 8 -mheight 8");
const u32 gHealthboxSinglesOpponentGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_singles_opponent.png", ".4bpp.lz", "-mwidth 8 -mheight 4");
const u32 gHealthboxDoublesPlayerGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_doubles_player.png", ".4bpp.lz", "-mwidth 8 -mheight 4");
const u32 gHealthboxDoublesOpponentGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_doubles_opponent.png", ".4bpp.lz", "-mwidth 8 -mheight 4");
const u32 gHealthboxSafariGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_safari.png", ".4bpp.lz", "-mwidth 8 -mheight 8");

const u32 gUnusedGfx_Shadow[] = INCGFX_U32("graphics/unused/shadow.png", ".4bpp.lz");
const u32 gUnusedPal_Shadow[] = INCGFX_U32("graphics/unused/shadow.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_LockOn[] = INCGFX_U32("graphics/battle_anims/sprites/lock_on.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_LockOn[] = INCGFX_U32("graphics/battle_anims/sprites/lock_on.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_OpeningEye[] = INCGFX_U32("graphics/battle_anims/sprites/opening_eye.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_OpeningEye[] = INCGFX_U32("graphics/battle_anims/sprites/opening_eye.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RoundWhiteHalo[] = INCGFX_U32("graphics/battle_anims/sprites/round_white_halo.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RoundWhiteHalo[] = INCGFX_U32("graphics/battle_anims/sprites/round_white_halo.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_TealAlert[] = INCGFX_U32("graphics/battle_anims/sprites/teal_alert.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_TealAlert[] = INCGFX_U32("graphics/battle_anims/sprites/teal_alert.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_FangAttack[] = INCGFX_U32("graphics/battle_anims/sprites/fang_attack.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_FangAttack[] = INCGFX_U32("graphics/battle_anims/sprites/fang_attack.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PurpleHandOutline[] = INCGFX_U32("graphics/battle_anims/sprites/purple_hand_outline.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PurpleHandOutline[] = INCGFX_U32("graphics/battle_anims/sprites/purple_hand_outline.png", ".gbapal.lz");

const u32 gBattleAnimMaskImage_Curse[] = INCGFX_U32("graphics/battle_anims/masks/curse.png", ".4bpp.lz");
const u32 gBattleAnimMaskTilemap_Curse[] = INCGFX_U32("graphics/battle_anims/masks/curse.bin", ".lz");

const u32 gBattleAnimSpriteGfx_Pencil[] = INCGFX_U32("graphics/battle_anims/sprites/pencil.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Pencil[] = INCGFX_U32("graphics/battle_anims/sprites/pencil.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Spiral[] = INCGFX_U32("graphics/battle_anims/sprites/spiral.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Spiral[] = INCGFX_U32("graphics/battle_anims/sprites/spiral.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Moon[] = INCGFX_U32("graphics/battle_anims/sprites/moon.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Moon[] = INCGFX_U32("graphics/battle_anims/sprites/moon.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GreenSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/green_sparkle.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GreenSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/green_sparkle.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SnoreZ[] = INCGFX_U32("graphics/battle_anims/sprites/snore_z.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SnoreZ[] = INCGFX_U32("graphics/battle_anims/sprites/snore_z.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Explosion[] = INCGFX_U32("graphics/battle_anims/sprites/explosion.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Explosion[] = INCGFX_U32("graphics/battle_anims/sprites/explosion.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Nail[] = INCGFX_U32("graphics/battle_anims/sprites/nail.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Nail[] = INCGFX_U32("graphics/battle_anims/sprites/nail.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GhostlySpirit[] = INCGFX_U32("graphics/battle_anims/sprites/ghostly_spirit.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GhostlySpirit[] = INCGFX_U32("graphics/battle_anims/sprites/ghostly_spirit.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WarmRock[] = INCGFX_U32("graphics/battle_anims/sprites/warm_rock.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WarmRock[] = INCGFX_U32("graphics/battle_anims/sprites/warm_rock.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PunchImpact[] = INCGFX_U32("graphics/battle_anims/sprites/punch_impact.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PunchImpact[] = INCGFX_U32("graphics/battle_anims/sprites/punch_impact.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_BreakingEgg[] = INCGFX_U32("graphics/battle_anims/sprites/breaking_egg.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BreakingEgg[] = INCGFX_U32("graphics/battle_anims/sprites/breaking_egg.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_ThinRing[] = INCGFX_U32("graphics/battle_anims/sprites/thin_ring.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_ThinRing[] = INCGFX_U32("graphics/battle_anims/sprites/thin_ring.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MusicNotes2[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes_2.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MusicNotes2[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes_2.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Bell[] = INCGFX_U32("graphics/battle_anims/sprites/bell.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Bell[] = INCGFX_U32("graphics/battle_anims/sprites/bell.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SpeedDust[] = INCGFX_U32("graphics/battle_anims/sprites/speed_dust.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SpeedDust[] = INCGFX_U32("graphics/battle_anims/sprites/speed_dust.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_TornMetal[] = INCGFX_U32("graphics/battle_anims/sprites/torn_metal.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_ThoughtBubble[] = INCGFX_U32("graphics/battle_anims/sprites/thought_bubble.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_ThoughtBubble[] = INCGFX_U32("graphics/battle_anims/sprites/thought_bubble.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Finger[] = INCGFX_U32("graphics/battle_anims/sprites/finger.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Finger[] = INCGFX_U32("graphics/battle_anims/sprites/finger.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MagentaHeart[] = INCGFX_U32("graphics/battle_anims/sprites/magenta_heart.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_PinkHeart[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_MagentaHeart[] = INCGFX_U32("graphics/battle_anims/sprites/magenta_heart.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_RedHeart[] = INCGFX_U32("graphics/battle_anims/sprites/red_heart.pal", ".gbapal.lz");

const u32 gBattleAnimBgImage_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.bin", ".lz");

const u32 gBattleAnimSpriteGfx_RedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_CircleOfLight[] = INCGFX_U32("graphics/battle_anims/sprites/circle_of_light.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_ElectricOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/electric_orbs.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Electricity[] = INCGFX_U32("graphics/battle_anims/sprites/electricity.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_ElectricOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/electric_orbs.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Finger2[] = INCGFX_U32("graphics/battle_anims/sprites/finger_2.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_MovementWaves[] = INCGFX_U32("graphics/battle_anims/sprites/movement_waves.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MovementWaves[] = INCGFX_U32("graphics/battle_anims/sprites/movement_waves.png", ".gbapal.lz");

const u32 gBattleAnimBgPalette_ScaryFace[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face.png", ".gbapal.lz");
const u32 gBattleAnimBgImage_ScaryFace[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_EyeSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/eye_sparkle.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_EyeSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/eye_sparkle.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Anger[] = INCGFX_U32("graphics/battle_anims/sprites/anger.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Anger[] = INCGFX_U32("graphics/battle_anims/sprites/anger.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Conversion[] = INCGFX_U32("graphics/battle_anims/sprites/conversion.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Conversion[] = INCGFX_U32("graphics/battle_anims/sprites/conversion.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Angel[] = INCGFX_U32("graphics/battle_anims/sprites/angel.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Angel[] = INCGFX_U32("graphics/battle_anims/sprites/angel.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Devil[] = INCGFX_U32("graphics/battle_anims/sprites/devil.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Devil[] = INCGFX_U32("graphics/battle_anims/sprites/devil.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Swipe[] = INCGFX_U32("graphics/battle_anims/sprites/swipe.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Swipe[] = INCGFX_U32("graphics/battle_anims/sprites/swipe.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_Roots[] = INCGFX_U32("graphics/battle_anims/sprites/roots.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Roots[] = INCGFX_U32("graphics/battle_anims/sprites/roots.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_ItemBag[] = INCGFX_U32("graphics/battle_anims/sprites/item_bag.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_ItemBag[] = INCGFX_U32("graphics/battle_anims/sprites/item_bag.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_TriAttackTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/tri_attack_triangle.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_TriAttackTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/tri_attack_triangle.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_LetterZ[] = INCGFX_U32("graphics/battle_anims/sprites/letter_z.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_LetterZ[] = INCGFX_U32("graphics/battle_anims/sprites/letter_z.png", ".4bpp.lz");

const u32 gBattleAnimBgPalette_Impact[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact.png", ".gbapal.lz");
const u32 gBattleAnimBgImage_Impact[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact.png", ".4bpp.lz");
const u32 gBattleAnimBgTilemap_ImpactOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_opponent.bin", ".lz");

const u32 gBattleAnimBgTilemap_ImpactPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_player.bin", ".lz");
const u32 gBattleAnimBgTilemap_ImpactContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_contests.bin", ".lz");

const u32 gBattleAnimSpriteGfx_JaggedMusicNote[] = INCGFX_U32("graphics/battle_anims/sprites/jagged_music_note.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_JaggedMusicNote[] = INCGFX_U32("graphics/battle_anims/sprites/jagged_music_note.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Spotlight[] = INCGFX_U32("graphics/battle_anims/sprites/spotlight.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Pokeball[] = INCGFX_U32("graphics/battle_anims/sprites/pokeball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Pokeball[] = INCGFX_U32("graphics/battle_anims/sprites/pokeball.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RapidSpin[] = INCGFX_U32("graphics/battle_anims/sprites/rapid_spin.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RapidSpin[] = INCGFX_U32("graphics/battle_anims/sprites/rapid_spin.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MilkBottle[] = INCGFX_U32("graphics/battle_anims/sprites/milk_bottle.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MilkBottle[] = INCGFX_U32("graphics/battle_anims/sprites/milk_bottle.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WispFire[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_fire.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_WispOrb[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_orb.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_WispOrb[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_orb.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_GoldStars[] = INCGFX_U32("graphics/battle_anims/sprites/gold_stars.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GoldStars[] = INCGFX_U32("graphics/battle_anims/sprites/gold_stars.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_EclipsingOrb[] = INCGFX_U32("graphics/battle_anims/sprites/eclipsing_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_EclipsingOrb[] = INCGFX_U32("graphics/battle_anims/sprites/eclipsing_orb.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PinkPetal[] = INCGFX_U32("graphics/battle_anims/sprites/pink_petal.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PinkPetal[] = INCGFX_U32("graphics/battle_anims/sprites/pink_petal.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GrayOrb[] = INCGFX_U32("graphics/battle_anims/sprites/gray_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GrayOrb[] = INCGFX_U32("graphics/battle_anims/sprites/gray_orb.png", ".gbapal.lz");

const u32 gBattleAnimSpritePal_BlueOrb[] = INCGFX_U32("graphics/battle_anims/sprites/blue_orb.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_RedOrb2[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb_2.pal", ".gbapal.lz");

const u32 gBattleAnimBgImage_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.png", ".gbapal.lz");

const u32 gBattleAnimBgPalette_Sky[] = INCGFX_U32("graphics/battle_anims/backgrounds/sky.pal", ".gbapal.lz");

const u32 gBattleAnimBgTilemap_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.bin", ".lz");
const u32 gBattleAnimBgTilemap_DrillContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill_contests.bin", ".lz");

const u32 gBattleAnimBgImage_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.bin", ".lz");

const u32 gBattleAnimBgTilemap_HighspeedOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed_opponent.bin", ".lz");
const u32 gBattleAnimBgPalette_Highspeed[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed.png", ".gbapal.lz");

const u32 gBattleAnimBgPalette_Bug[] = INCGFX_U32("graphics/battle_anims/backgrounds/bug.pal", ".gbapal.lz");

const u32 gBattleAnimBgImage_Highspeed[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed.png", ".4bpp.lz");
const u32 gBattleAnimBgTilemap_HighspeedPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed_player.bin", ".lz");

const u32 gBattleAnimMaskImage_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.png", ".4bpp.lz");
const u32 gBattleAnimMaskPalette_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.png", ".gbapal.lz");
const u32 gBattleAnimMaskTilemap_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.bin", ".lz");

const u32 gBattleAnimBgTilemap_GuillotineOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_opponent.bin", ".lz");
const u32 gBattleAnimBgTilemap_GuillotinePlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_player.bin", ".lz");
const u32 gBattleAnimBgTilemap_GuillotineContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_contests.bin", ".lz");

const u32 gBattleAnimBgImage_Guillotine[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Guillotine[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine.png", ".gbapal.lz");

const u32 gBattleAnimBgImage_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.bin", ".lz");

const u32 gBattleAnimSpriteGfx_PainSplit[] = INCGFX_U32("graphics/battle_anims/sprites/pain_split.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PainSplit[] = INCGFX_U32("graphics/battle_anims/sprites/pain_split.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_HandsAndFeet[] = INCGFX_U32("graphics/battle_anims/sprites/hands_and_feet.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_HandsAndFeet[] = INCGFX_U32("graphics/battle_anims/sprites/hands_and_feet.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Confetti[] = INCGFX_U32("graphics/battle_anims/sprites/confetti.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Confetti[] = INCGFX_U32("graphics/battle_anims/sprites/confetti.png", ".gbapal.lz");

const u32 gSubstituteDollPal[] = INCGFX_U32("graphics/battle_anims/sprites/substitute.png", ".gbapal.lz");
const u32 gSubstituteDollFrontGfx[] = INCGFX_U32("graphics/battle_anims/sprites/substitute.png", ".4bpp.lz");
const u32 gSubstituteDollBackGfx[] = INCGFX_U32("graphics/battle_anims/sprites/substitute_back.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_GreenStar[] = INCGFX_U32("graphics/battle_anims/sprites/green_star.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GreenStar[] = INCGFX_U32("graphics/battle_anims/sprites/green_star.png", ".gbapal.lz");

const u32 gConfetti_Gfx[] = INCGFX_U32("graphics/misc/confetti.png", ".4bpp.lz");
const u32 gConfetti_Pal[] = INCGFX_U32("graphics/misc/confetti.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PinkCloud[] = INCGFX_U32("graphics/battle_anims/sprites/pink_cloud.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PinkCloud[] = INCGFX_U32("graphics/battle_anims/sprites/pink_cloud.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SweatDrop[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_drop.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SweatDrop[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_drop.png", ".gbapal.lz");

const u32 gStatAnim_Gfx[]              = INCGFX_U32("graphics/battle_anims/stat_change/tiles.png", ".4bpp.lz");
const u32 gStatAnim_Increase_Tilemap[] = INCGFX_U32("graphics/battle_anims/stat_change/increase.bin", ".lz");
const u32 gStatAnim_Decrease_Tilemap[] = INCGFX_U32("graphics/battle_anims/stat_change/decrease.bin", ".lz");
const u32 gStatAnim_Defense_Pal[]      = INCGFX_U32("graphics/battle_anims/stat_change/defense.pal", ".gbapal.lz");
const u32 gStatAnim_Attack_Pal[]       = INCGFX_U32("graphics/battle_anims/stat_change/attack.pal", ".gbapal.lz");
const u32 gStatAnim_Accuracy_Pal[]     = INCGFX_U32("graphics/battle_anims/stat_change/accuracy.pal", ".gbapal.lz");
const u32 gStatAnim_Speed_Pal[]        = INCGFX_U32("graphics/battle_anims/stat_change/speed.pal", ".gbapal.lz");
const u32 gStatAnim_Multiple_Pal[]     = INCGFX_U32("graphics/battle_anims/stat_change/multiple.pal", ".gbapal.lz");
const u32 gStatAnim_Evasion_Pal[]      = INCGFX_U32("graphics/battle_anims/stat_change/evasion.pal", ".gbapal.lz");
const u32 gStatAnim_SpAttack_Pal[]     = INCGFX_U32("graphics/battle_anims/stat_change/sp_attack.pal", ".gbapal.lz");
const u32 gStatAnim_SpDefense_Pal[]    = INCGFX_U32("graphics/battle_anims/stat_change/sp_defense.pal", ".gbapal.lz");

const u32 gCureBubblesGfx[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.png", ".4bpp.lz");
const u32 gCureBubblesPal[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.png", ".gbapal.lz");
const u32 gCureBubblesTilemap[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.bin", ".lz");

const u32 gBattleAnimSpritePal_PurpleScratch[] = INCGFX_U32("graphics/battle_anims/sprites/purple_scratch.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_PurpleScratch[] = INCGFX_U32("graphics/battle_anims/sprites/purple_scratch.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_PurpleSwipe[] = INCGFX_U32("graphics/battle_anims/sprites/purple_swipe.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_GuardRing[] = INCGFX_U32("graphics/battle_anims/sprites/guard_ring.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GuardRing[] = INCGFX_U32("graphics/battle_anims/sprites/guard_ring.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_TagHand[] = INCGFX_U32("graphics/battle_anims/sprites/tag_hand.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_NoiseLine[] = INCGFX_U32("graphics/battle_anims/sprites/noise_line.png", ".4bpp.lz");

const u32 UnusedLevelupAnimationGfx[] = INCGFX_U32("graphics/battle_anims/masks/unused_level_up.png", ".4bpp.lz", "-num_tiles 14 -Wnum_tiles");
const u32 UnusedLevelupAnimationTilemap[] = INCGFX_U32("graphics/battle_anims/masks/unused_level_up.bin", ".lz");

const u32 gBattleAnimSpriteGfx_SmallRedEye[] = INCGFX_U32("graphics/battle_anims/sprites/small_red_eye.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SmallRedEye[] = INCGFX_U32("graphics/battle_anims/sprites/small_red_eye.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_HollowOrb[] = INCGFX_U32("graphics/battle_anims/sprites/hollow_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_HollowOrb[] = INCGFX_U32("graphics/battle_anims/sprites/hollow_orb.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_XSign[] = INCGFX_U32("graphics/battle_anims/sprites/x_sign.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_BluegreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/bluegreen_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_BluegreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/bluegreen_orb.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PawPrint[] = INCGFX_U32("graphics/battle_anims/sprites/paw_print.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PawPrint[] = INCGFX_U32("graphics/battle_anims/sprites/paw_print.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_PurpleFlame[] = INCGFX_U32("graphics/battle_anims/sprites/purple_flame.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_PurpleFlame[] = INCGFX_U32("graphics/battle_anims/sprites/purple_flame.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RedBall[] = INCGFX_U32("graphics/battle_anims/sprites/red_ball.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RedBall[] = INCGFX_U32("graphics/battle_anims/sprites/red_ball.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SmellingsaltEffect[] = INCGFX_U32("graphics/battle_anims/sprites/smellingsalt_effect.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_SmellingsaltEffect[] = INCGFX_U32("graphics/battle_anims/sprites/smellingsalt_effect.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MagnifyingGlass[] = INCGFX_U32("graphics/battle_anims/sprites/magnifying_glass.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MagnifyingGlass[] = INCGFX_U32("graphics/battle_anims/sprites/magnifying_glass.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Meteor[] = INCGFX_U32("graphics/battle_anims/sprites/meteor.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Meteor[] = INCGFX_U32("graphics/battle_anims/sprites/meteor.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_FlatRock[] = INCGFX_U32("graphics/battle_anims/sprites/flat_rock.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_FlatRock[] = INCGFX_U32("graphics/battle_anims/sprites/flat_rock.png", ".gbapal.lz");

const u32 gBattleAnimUnusedPal_Unknown2[] = INCGFX_U32("graphics/battle_anims/unused/unknown_2.pal", ".gbapal.lz");

#include "data/graphics/pokemon.h"
#include "data/graphics/trainers.h"

const u8 gMonIcon_QuestionMark[] = INCGFX_U8("graphics/pokemon/question_mark/icon.png", ".4bpp");
const u8 gMonFootprint_QuestionMark[] = INCGFX_U8("graphics/pokemon/question_mark/footprint.png", ".1bpp");

const u32 gBattleVSFrame_Gfx[] = INCGFX_U32("graphics/battle_transitions/vs_frame.png", ".4bpp.lz", "-num_tiles 16 -Wnum_tiles");
const u32 gBattleVSFrame_Tilemap[] = INCGFX_U32("graphics/battle_transitions/vs_frame.bin", ".lz");
const u32 gBattleVSFrame_Pal[] = INCGFX_U32("graphics/battle_transitions/vs_frame.png", ".gbapal.lz");

const u32 gVsLettersGfx[] = INCGFX_U32("graphics/battle_transitions/vs.png", ".4bpp.lz");

#include "data/graphics/battle_environment.h"

// Battle Dome
const u32 gDomeTourneyTree_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.png", ".4bpp.lz");
const u32 gDomeTourneyLine_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_line.png", ".4bpp.lz"); // the red glow mask for the tourney advancement lines
const u32 gDomeTourneyTree_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.bin", ".lz");
const u32 gDomeTourneyLineDown_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_line_down_map.bin", ".lz");
const u32 gDomeTourneyLineUp_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_line_up_map.bin", ".lz");
const u32 gDomeTourneyInfoCard_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card.png", ".4bpp.lz");
const u32 gDomeTourneyInfoCard_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card_tilemap.bin", ".lz");
const u32 gDomeTourneyInfoCardBg_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card_bg.bin", ".lz");
const u32 gDomeTourneyTreeButtons_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_buttons.png", ".4bpp.lz"); // exit/cancel and Poké Ball buttons
const u32 gDomeTourneyTree_Pal[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.png", ".gbapal.lz");
const u32 gDomeTourneyTreeButtons_Pal[] = INCGFX_U32("graphics/battle_frontier/tourney_buttons.pal", ".gbapal.lz");
const u32 gDomeTourneyMatchCardBg_Pal[] = INCGFX_U32("graphics/battle_frontier/tourney_match_card_bg.pal", ".gbapal.lz");

const u32 gBattleArenaJudgmentSymbolsGfx[] = INCGFX_U32("graphics/battle_frontier/arena_judgment_symbols.png", ".4bpp.lz");
const u32 gBattleArenaJudgmentSymbolsPalette[] = INCGFX_U32("graphics/battle_frontier/arena_judgment_symbols.png", ".gbapal.lz");

const u32 gBattleWindowTextPalette[] = INCGFX_U32("graphics/battle_interface/text.pal", ".gbapal.lz");
const u16 gPPTextPalette[] = INCGFX_U16("graphics/battle_interface/text_pp.pal", ".gbapal");

const u16 gTilesetAnims_BattleDomePals0_0[] = INCGFX_U16("graphics/battle_frontier/dome_anim1.pal", ".gbapal");
const u16 gTilesetAnims_BattleDomePals0_1[] = INCGFX_U16("graphics/battle_frontier/dome_anim2.pal", ".gbapal");
const u16 gTilesetAnims_BattleDomePals0_2[] = INCGFX_U16("graphics/battle_frontier/dome_anim3.pal", ".gbapal");
const u16 gTilesetAnims_BattleDomePals0_3[] = INCGFX_U16("graphics/battle_frontier/dome_anim4.pal", ".gbapal");

static const u16 sUnused0[] = {0x13F, 0x119, 0x113, 0x10E};

const u16 gBattlePyramidFloor_Pal[][16] = INCGFX_U16("graphics/battle_frontier/pyramid_floor.pal", ".gbapal");

const u32 gMultiBattleIntroBg_Opponent_Tilemap[] = INCGFX_U32("graphics/battle_frontier/multi_battle_intro_bg_opponent.bin", ".lz");
const u32 gMultiBattleIntroBg_Player_Tilemap[] = INCGFX_U32("graphics/battle_frontier/multi_battle_intro_bg_player.bin", ".lz");

#include "data/graphics/intro_scene.h"

const u32 gBattleAnimSpriteGfx_FlyingDirt[] = INCGFX_U32("graphics/battle_anims/sprites/flying_dirt.png", ".4bpp.lz");

const u32 gBattleAnimBgTilemap_Sandstorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/sandstorm_brew.bin", ".lz");
const u32 gBattleAnimBgImage_Sandstorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/sandstorm_brew.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_FlyingDirt[] = INCGFX_U32("graphics/battle_anims/sprites/flying_dirt.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_MetalSoundWaves[] = INCGFX_U32("graphics/battle_anims/sprites/metal_sound_waves.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_MetalSoundWaves[] = INCGFX_U32("graphics/battle_anims/sprites/metal_sound_waves.png", ".gbapal.lz");

const u32 gBattleAnimBgImage_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.bin", ".lz");

const u32 gBattleAnimSpriteGfx_IcicleSpear[] = INCGFX_U32("graphics/battle_anims/sprites/icicle_spear.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_IcicleSpear[] = INCGFX_U32("graphics/battle_anims/sprites/icicle_spear.png", ".gbapal.lz");

const u32 gContestNextTurnGfx[] = INCGFX_U32("graphics/contest/nextturn.png", ".4bpp.lz");
const u8 gContestNextTurnNumbersGfx[] = INCGFX_U8("graphics/contest/nextturn_numbers.png", ".4bpp");
const u8 gContestNextTurnRandomGfx[] = INCGFX_U8("graphics/contest/nextturn_random.png", ".4bpp");

const u32 gBattleAnimSpriteGfx_GlowyRedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_red_orb.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GlowyRedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_red_orb.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_GlowyGreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_green_orb.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_SleepPowder[] = INCGFX_U32("graphics/battle_anims/sprites/sleep_powder.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_StunSpore[] = INCGFX_U32("graphics/battle_anims/sprites/stun_spore.pal", ".gbapal.lz");

const u32 gContestApplauseGfx[] = INCGFX_U32("graphics/contest/applause.png", ".4bpp.lz");
const u8 gContestApplauseMeterGfx[] = INCGFX_U8("graphics/contest/applause_meter.png", ".4bpp");

const u16 gContestPal[] = INCGFX_U16("graphics/contest/nextturn.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Splash[] = INCGFX_U32("graphics/battle_anims/sprites/splash.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Splash[] = INCGFX_U32("graphics/battle_anims/sprites/splash.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_SweatBead[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_bead.png", ".4bpp.lz");

const u32 gBattleAnimSpriteGfx_Pokeblock[] = INCGFX_U32("graphics/battle_anims/sprites/pokeblock.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Pokeblock[] = INCGFX_U32("graphics/battle_anims/sprites/pokeblock.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Gem1[] = INCGFX_U32("graphics/battle_anims/sprites/gem_1.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Gem2[] = INCGFX_U32("graphics/battle_anims/sprites/gem_2.png", ".4bpp.lz");
const u32 gBattleAnimSpriteGfx_Gem3[] = INCGFX_U32("graphics/battle_anims/sprites/gem_3.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Gem1[] = INCGFX_U32("graphics/battle_anims/sprites/gem_1.png", ".gbapal.lz");

const u32 gBattleAnimBgImage_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.bin", ".lz");

const u32 gBattleAnimSpriteGfx_Protect[] = INCGFX_U32("graphics/battle_anims/sprites/protect.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Protect[] = INCGFX_U32("graphics/battle_anims/sprites/protect.png", ".gbapal.lz");

const u32 gBattleAnimBackgroundImageMuddyWater_Pal[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_muddy.pal", ".gbapal.lz");

const u32 gEnemyMonShadow_Gfx[] = INCGFX_U32("graphics/battle_interface/enemy_mon_shadow.png", ".4bpp.lz");

const u32 gBattleInterface_BallStatusBarGfx[] = INCGFX_U32("graphics/battle_interface/ball_status_bar.png", ".4bpp.lz");

const u8 gMonIcon_Egg[] = INCGFX_U8("graphics/pokemon/egg/icon.png", ".4bpp");

const u32 gBattleAnimBgImage_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.bin", ".lz");

const u32 gBattleAnimSpritePal_WhipHit[] = INCGFX_U32("graphics/battle_anims/sprites/whip_hit.pal", ".gbapal.lz");

const u32 gBattleAnimBgPalette_SolarBeam[] = INCGFX_U32("graphics/battle_anims/backgrounds/solarbeam.pal", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_SolarBeam[] = INCGFX_U32("graphics/battle_anims/backgrounds/solarbeam.bin", ".lz"); // Unused

const u32 gBerryBlenderCenter_Gfx[] = INCGFX_U32("graphics/berry_blender/center.png", ".8bpp.lz");
const u32 gBerryBlenderOuter_Gfx[] = INCGFX_U32("graphics/berry_blender/outer.png", ".4bpp.lz");
const u32 gBerryBlenderOuter_Tilemap[] = INCGFX_U32("graphics/berry_blender/outer_map.bin", ".lz");

const u32 gBattleAnimBgPalette_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.png", ".gbapal.lz");
const u32 gBattleAnimBgImage_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.png", ".4bpp.lz");
const u32 gBattleAnimBgTilemap_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.bin", ".lz");

const u32 gBattleAnimSpritePal_SlamHit2[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit_2.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_SlamHit2[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit_2.png", ".4bpp.lz");

const u32 gBattleAnimFogTilemap[] = INCGFX_U32("graphics/battle_anims/backgrounds/fog.bin", ".lz");

const u32 gBattleAnimSpritePal_WeatherBall[] = INCGFX_U32("graphics/battle_anims/sprites/weather_ball.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_WeatherBall[] = INCGFX_U32("graphics/battle_anims/sprites/weather_ball.png", ".4bpp.lz");

const u32 gBattleAnimBgTilemap_ScaryFacePlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_player.bin", ".lz");
const u32 gBattleAnimBgTilemap_ScaryFaceOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_opponent.bin", ".lz");
const u32 gBattleAnimBgTilemap_ScaryFaceContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_contest.bin", ".lz");

const u32 gBattleAnimSpriteGfx_Hail[] = INCGFX_U32("graphics/battle_anims/sprites/hail.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Hail[] = INCGFX_U32("graphics/battle_anims/sprites/hail.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_GreenSpike[] = INCGFX_U32("graphics/battle_anims/sprites/green_spike.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_GreenSpike[] = INCGFX_U32("graphics/battle_anims/sprites/green_spike.png", ".gbapal.lz");
const u32 gBattleAnimSpritePal_WhiteCircleOfLight[] = INCGFX_U32("graphics/battle_anims/sprites/white_circle_of_light.pal", ".gbapal.lz");
const u32 gBattleAnimSpritePal_GlowyBlueOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_blue_orb.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_Recycle[] = INCGFX_U32("graphics/battle_anims/sprites/recycle.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Recycle[] = INCGFX_U32("graphics/battle_anims/sprites/recycle.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_RedParticles[] = INCGFX_U32("graphics/battle_anims/sprites/red_particles.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_RedParticles[] = INCGFX_U32("graphics/battle_anims/sprites/red_particles.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_DirtMound[] = INCGFX_U32("graphics/battle_anims/sprites/dirt_mound.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_DirtMound[] = INCGFX_U32("graphics/battle_anims/sprites/dirt_mound.png", ".gbapal.lz");

const u32 gBattleAnimBgImage_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.png", ".gbapal.lz");
const u32 gBattleAnimBgTilemap_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.bin", ".lz");

const u32 gBattleAnimSpriteGfx_Bird[] = INCGFX_U32("graphics/battle_anims/sprites/bird.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_Bird[] = INCGFX_U32("graphics/battle_anims/sprites/bird.png", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_CrossImpact[] = INCGFX_U32("graphics/battle_anims/sprites/cross_impact.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_CrossImpact[] = INCGFX_U32("graphics/battle_anims/sprites/cross_impact.png", ".gbapal.lz");

const u32 gBattleAnimBgImage_Surf[] = INCGFX_U32("graphics/battle_anims/backgrounds/water.png", ".4bpp.lz");
const u32 gBattleAnimBgPalette_Surf[] = INCGFX_U32("graphics/battle_anims/backgrounds/water.png", ".gbapal.lz");

const u32 gBattleAnimBgTilemap_SurfOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_opponent.bin", ".lz");
const u32 gBattleAnimBgTilemap_SurfPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_player.bin", ".lz");
const u32 gBattleAnimBgTilemap_SurfContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_contest.bin", ".lz");

const u32 gBattleAnimSpritePal_Slash2[] = INCGFX_U32("graphics/battle_anims/sprites/slash_2.pal", ".gbapal.lz");

const u32 gBattleAnimSpriteGfx_WhiteShadow[] = INCGFX_U32("graphics/battle_anims/sprites/white_shadow.png", ".4bpp.lz");
const u32 gBattleAnimSpritePal_WhiteShadow[] = INCGFX_U32("graphics/battle_anims/sprites/white_shadow.png", ".gbapal.lz");

const u32 gPartyMenuBg_Gfx[] = INCGFX_U32("graphics/party_menu/bg.png", ".4bpp.lz", "-num_tiles 62 -Wnum_tiles");
const u32 gPartyMenuBg_Pal[] = INCGFX_U32("graphics/party_menu/bg.png", ".gbapal.lz");
const u32 gPartyMenuBg_Tilemap[] = INCGFX_U32("graphics/party_menu/bg.bin", ".lz");

const u32 gPartyMenuPokeball_Gfx[] = INCGFX_U32("graphics/party_menu/pokeball.png", ".4bpp.lz");
const u32 gPartyMenuPokeballSmall_Gfx[] = INCGFX_U32("graphics/party_menu/pokeball_small.png", ".4bpp.lz"); //unused
const u32 gPartyMenuPokeball_Pal[] = INCGFX_U32("graphics/party_menu/pokeball.png", ".gbapal.lz");

const u32 gStatusGfx_Icons[] = INCGFX_U32("graphics/interface/status_icons.png", ".4bpp.lz");
const u32 gStatusPal_Icons[] = INCGFX_U32("graphics/interface/status_icons.png", ".gbapal.lz");

const u32 gMoveTypes_Gfx[] = INCGFX_U32("graphics/types/move_types.4bpp", ".lz");
const u32 gMoveTypes_Pal[] = INCGFX_U32("graphics/types/move_types.gbapal", ".lz");

const u32 gSummaryMoveSelect_Gfx[] = INCGFX_U32("graphics/summary_screen/move_select.png", ".4bpp.lz");
const u32 gSummaryMoveSelect_Pal[] = INCGFX_U32("graphics/summary_screen/move_select.png", ".gbapal.lz");

const u32 gSummaryScreen_Gfx[]                = INCGFX_U32("graphics/summary_screen/tiles.png", ".4bpp.lz");
const u32 gSummaryScreen_Pal[]                = INCGFX_U32("graphics/summary_screen/tiles.png", ".gbapal.lz");
const u32 gSummaryPage_Info_Tilemap[]         = INCGFX_U32("graphics/summary_screen/page_info.bin", ".lz");
const u32 gSummaryPage_Skills_Tilemap[]       = INCGFX_U32("graphics/summary_screen/page_skills.bin", ".lz");
const u32 gSummaryPage_BattleMoves_Tilemap[]  = INCGFX_U32("graphics/summary_screen/page_battle_moves.bin", ".lz");
const u32 gSummaryPage_ContestMoves_Tilemap[] = INCGFX_U32("graphics/summary_screen/page_contest_moves.bin", ".lz");
const u32 gSummaryPage_InfoEgg_Tilemap[]      = INCGFX_U32("graphics/summary_screen/page_info_egg.bin", ".lz");

const u32 gBagMaleTiles[] = INCGFX_U32("graphics/bag/bag_male.png", ".4bpp.lz");
const u32 gBagFemaleTiles[] = INCGFX_U32("graphics/bag/bag_female.png", ".4bpp.lz");
const u32 gBagPalette[] = INCGFX_U32("graphics/bag/bag.pal", ".gbapal.lz");

const u32 gBagScreenMale_Pal[] = INCGFX_U32("graphics/bag/menu_male.pal", ".gbapal.lz");
const u32 gBagScreenFemale_Pal[] = INCGFX_U32("graphics/bag/menu_female.pal", ".gbapal.lz");

const u32 gBagScreen_Gfx[] = INCGFX_U32("graphics/bag/menu.png", ".4bpp.lz", "-num_tiles 53 -Wnum_tiles");
const u32 gBagScreen_GfxTileMap[] = INCGFX_U32("graphics/bag/menu.bin", ".lz");

const u32 gBattlePyramidBag_Gfx[]          = INCGFX_U32("graphics/bag/bag_pyramid.png", ".4bpp.lz");
const u32 gBattlePyramidBag_Pal[]          = INCGFX_U32("graphics/bag/bag_pyramid.pal", ".gbapal.lz"); // female palette is first and male is second.
const u32 gBattlePyramidBagTilemap[]       = INCGFX_U32("graphics/bag/menu_pyramid.bin", ".lz");
const u32 gBattlePyramidBagInterface_Pal[] = INCGFX_U32("graphics/bag/menu_pyramid.pal", ".gbapal.lz");

const u32 gSwapLineGfx[] = INCGFX_U32("graphics/interface/swap_line.png", ".4bpp.lz");
const u32 gSwapLinePal[] = INCGFX_U32("graphics/interface/swap_line.png", ".gbapal.lz");

const u32 gShopMenu_Gfx[] = INCGFX_U32("graphics/shop/menu.png", ".4bpp.lz");
const u32 gShopMenu_Pal[] = INCGFX_U32("graphics/shop/menu.png", ".gbapal.lz");
const u32 gShopMenu_Tilemap[] = INCGFX_U32("graphics/shop/menu.bin", ".lz");
const u32 gShopMenuMoney_Gfx[] = INCGFX_U32("graphics/shop/money.png", ".4bpp.lz");

// Pokeblock

const u32 gMenuPokeblock_Gfx[] = INCGFX_U32("graphics/pokeblock/menu.png", ".4bpp.lz");
const u32 gMenuPokeblock_Pal[] = INCGFX_U32("graphics/pokeblock/menu.pal", ".gbapal.lz");

const u32 gMenuPokeblockDevice_Gfx[] = INCGFX_U32("graphics/pokeblock/device.png", ".4bpp.lz");
const u32 gMenuPokeblockDevice_Pal[] = INCGFX_U32("graphics/pokeblock/device.png", ".gbapal.lz");

const u32 gMenuPokeblock_Tilemap[] = INCGFX_U32("graphics/pokeblock/menu.bin", ".lz");

const u32 gPokeblock_Gfx[] = INCGFX_U32("graphics/pokeblock/pokeblock.png", ".4bpp.lz");
const u32 gPokeblockRed_Pal[] = INCGFX_U32("graphics/pokeblock/red.pal", ".gbapal.lz");
const u32 gPokeblockBlue_Pal[] = INCGFX_U32("graphics/pokeblock/blue.pal", ".gbapal.lz");
const u32 gPokeblockPink_Pal[] = INCGFX_U32("graphics/pokeblock/pink.pal", ".gbapal.lz");
const u32 gPokeblockGreen_Pal[] = INCGFX_U32("graphics/pokeblock/green.pal", ".gbapal.lz");
const u32 gPokeblockYellow_Pal[] = INCGFX_U32("graphics/pokeblock/yellow.pal", ".gbapal.lz");
const u32 gPokeblockPurple_Pal[] = INCGFX_U32("graphics/pokeblock/purple.pal", ".gbapal.lz");
const u32 gPokeblockIndigo_Pal[] = INCGFX_U32("graphics/pokeblock/indigo.pal", ".gbapal.lz");
const u32 gPokeblockBrown_Pal[] = INCGFX_U32("graphics/pokeblock/brown.pal", ".gbapal.lz");
const u32 gPokeblockLiteBlue_Pal[] = INCGFX_U32("graphics/pokeblock/liteblue.pal", ".gbapal.lz");
const u32 gPokeblockOlive_Pal[] = INCGFX_U32("graphics/pokeblock/olive.pal", ".gbapal.lz");
const u32 gPokeblockGray_Pal[] = INCGFX_U32("graphics/pokeblock/gray.pal", ".gbapal.lz");
const u32 gPokeblockBlack_Pal[] = INCGFX_U32("graphics/pokeblock/black.pal", ".gbapal.lz");
const u32 gPokeblockWhite_Pal[] = INCGFX_U32("graphics/pokeblock/white.pal", ".gbapal.lz");
const u32 gPokeblockGold_Pal[] = INCGFX_U32("graphics/pokeblock/gold.pal", ".gbapal.lz");

const u32 gPokeblockFeedBg_Tilemap[] = INCGFX_U32("graphics/pokeblock/feeding_bg.bin", ".lz");

#include "data/graphics/berries.h"
#include "data/graphics/rayquaza_scene.h"
#include "data/graphics/items.h"
#include "data/graphics/decorations.h"

const u32 gBattleAnimSpritePal_Shock3[] = INCGFX_U32("graphics/battle_anims/sprites/shock_3.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Shock3[] = INCGFX_U32("graphics/battle_anims/sprites/shock_3.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_WhiteFeather[] = INCGFX_U32("graphics/battle_anims/sprites/white_feather.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_WhiteFeather[] = INCGFX_U32("graphics/battle_anims/sprites/white_feather.png", ".4bpp.lz");

const u32 gBattleAnimSpritePal_Sparkle6[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_6.png", ".gbapal.lz");
const u32 gBattleAnimSpriteGfx_Sparkle6[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_6.png", ".4bpp.lz");

const u16 gCableCarBg_Pal[]    = INCGFX_U16("graphics/cable_car/bg.png", ".gbapal");
const u16 gCableCar_Pal[]      = INCGFX_U16("graphics/cable_car/cable_car.png", ".gbapal");
const u32 gCableCarBg_Gfx[]    = INCGFX_U32("graphics/cable_car/bg.png", ".4bpp.lz");
const u32 gCableCar_Gfx[]      = INCGFX_U32("graphics/cable_car/cable_car.png", ".4bpp.lz");
const u32 gCableCarDoor_Gfx[]  = INCGFX_U32("graphics/cable_car/door.png", ".4bpp.lz");
const u32 gCableCarCable_Gfx[] = INCGFX_U32("graphics/cable_car/cable.png", ".4bpp.lz");

// Roulette
const u32 gRouletteMenu_Gfx[] = INCGFX_U32("graphics/roulette/window.png", ".4bpp.lz");
const u32 gRouletteWheel_Gfx[] = INCGFX_U32("graphics/roulette/wheel.png", ".8bpp.lz");
const u32 gRouletteCenter_Gfx[] = INCGFX_U32("graphics/roulette/center.png", ".4bpp.lz");
const u32 gRouletteHeaders_Gfx[] = INCGFX_U32("graphics/roulette/headers.png", ".4bpp.lz");
const u32 gRouletteCredit_Gfx[] = INCGFX_U32("graphics/roulette/credit.png", ".4bpp.lz");
const u32 gRouletteNumbers_Gfx[] = INCGFX_U32("graphics/roulette/numbers.png", ".4bpp.lz");
const u32 gRouletteMultiplier_Gfx[] = INCGFX_U32("graphics/roulette/multiplier.png", ".4bpp.lz");

#include "data/graphics/mail.h"

const u16 gFrontierFactoryMenu_Pal[] = INCGFX_U16("graphics/battle_frontier/factory_screen/menu.png", ".gbapal");
const u16 gFrontierFactoryMenu_Gfx[] = INCGFX_U16("graphics/battle_frontier/factory_screen/menu.png", ".4bpp");
const u16 gFrontierFactoryMenu_Tilemap[] = INCBIN_U16("graphics/battle_frontier/factory_screen/menu.bin");

const u32 gFrontierPassMedals_Gfx[] = INCGFX_U32("graphics/frontier_pass/medals.png", ".4bpp.lz");

const u16 gFrontierPassCursor_Pal[] = INCGFX_U16("graphics/frontier_pass/cursor.png", ".gbapal");

const u16 gFrontierPassMapCursor_Pal[] = INCGFX_U16("graphics/frontier_pass/map_cursor.png", ".gbapal");

const u16 gFrontierPassMedalsSilver_Pal[] = INCGFX_U16("graphics/frontier_pass/silver.pal", ".gbapal");
const u16 gFrontierPassMedalsGold_Pal[] = INCGFX_U16("graphics/frontier_pass/gold.pal", ".gbapal");

// Pokédex
const u16 gPokedexBgHoenn_Pal[] = INCGFX_U16("graphics/pokedex/bg_hoenn.pal", ".gbapal");
const u16 gPokedexSearchResults_Pal[] = INCGFX_U16("graphics/pokedex/search_results_bg.pal", ".gbapal");
const u16 gPokedexBgNational_Pal[] = INCGFX_U16("graphics/pokedex/bg_national.pal", ".gbapal");
const u32 gPokedexMenu_Gfx[] = INCGFX_U32("graphics/pokedex/menu.png", ".4bpp.lz");
const u32 gPokedexInterface_Gfx[] = INCGFX_U32("graphics/pokedex/interface.png", ".4bpp.lz");
const u32 gUnused_PokedexNoBall[] = INCGFX_U32("graphics/pokedex/noball_unused.png", ".4bpp.lz");
const u32 gPokedexStartMenuMain_Tilemap[] = INCGFX_U32("graphics/pokedex/start_menu_main.bin", ".lz");
const u32 gPokedexStartMenuSearchResults_Tilemap[] = INCGFX_U32("graphics/pokedex/start_menu_search_results.bin", ".lz");
const u32 gPokedexList_Tilemap[] = INCGFX_U32("graphics/pokedex/list.bin", ".lz");
const u32 gPokedexListUnderlay_Tilemap[] = INCGFX_U32("graphics/pokedex/list_underlay.bin", ".lz");
const u32 gPokedexSizeScreen_Tilemap[] = INCGFX_U32("graphics/pokedex/size_screen.bin", ".lz");
const u32 gPokedexScreenSelectBarMain_Tilemap[] = INCGFX_U32("graphics/pokedex/screen_select_bar_main.bin", ".lz");
const u32 gPokedexScreenSelectBarSubmenu_Tilemap[] = INCGFX_U32("graphics/pokedex/screen_select_bar_submenu.bin", ".lz");
const u32 gPokedexInfoScreen_Tilemap[] = INCGFX_U32("graphics/pokedex/info_screen.bin", ".lz");
const u32 gPokedexCryScreen_Tilemap[] = INCGFX_U32("graphics/pokedex/cry_screen.bin", ".lz");
const u16 gPokedexSearchMenu_Pal[] = INCGFX_U16("graphics/pokedex/search_menu.pal", ".gbapal");
const u32 gPokedexSearchMenu_Gfx[] = INCGFX_U32("graphics/pokedex/search_menu.png", ".4bpp.lz");
const u32 gPokedexSearchMenuNational_Tilemap[] = INCGFX_U32("graphics/pokedex/search_menu_national.bin", ".lz");
const u32 gPokedexSearchMenuHoenn_Tilemap[] = INCGFX_U32("graphics/pokedex/search_menu_hoenn.bin", ".lz");

const u16 gSummaryScreen_MoveEffect_Battle_Tilemap[] = INCBIN_U16("graphics/summary_screen/effect_battle.bin");
const u16 gSummaryScreen_MoveEffect_Contest_Tilemap[] = INCBIN_U16("graphics/summary_screen/effect_contest.bin");
const u16 gSummaryScreen_MoveEffect_Cancel_Tilemap[] = INCBIN_U16("graphics/summary_screen/effect_cancel.bin");

const u16 gIntroCopyright_Pal[] = INCGFX_U16("graphics/intro/copyright.png", ".gbapal");
const u32 gIntroCopyright_Gfx[] = INCGFX_U32("graphics/intro/copyright.png", ".4bpp.lz");
const u32 gIntroCopyright_Tilemap[] = INCGFX_U32("graphics/intro/copyright.bin", ".lz");

const u16 gPokedexAreaScreenAreaUnknown_Pal[] = INCGFX_U16("graphics/pokedex/area_unknown.png", ".gbapal");
const u32 gPokedexAreaScreenAreaUnknown_Gfx[] = INCGFX_U32("graphics/pokedex/area_unknown.png", ".4bpp.lz");

const u16 gMenuInfoElements1_Pal[] = INCGFX_U16("graphics/interface/menu_info1.pal", ".gbapal");
const u16 gMenuInfoElements2_Pal[] = INCGFX_U16("graphics/interface/menu_info2.pal", ".gbapal");
const u16 gMenuInfoElements3_Pal[] = INCGFX_U16("graphics/interface/menu_info3.pal", ".gbapal");
const u8 gMenuInfoElements_Gfx[] = INCGFX_U8("graphics/interface/menu_info.png", ".4bpp");

const u8 gBagMenuHMIcon_Gfx[] = INCGFX_U8("graphics/bag/hm.png", ".4bpp");

// contest results screen

const u16 gContestResultsTitle_Normal_Tilemap[] = INCBIN_U16("graphics/contest/results_screen/title_normal.bin");
const u16 gContestResultsTitle_Super_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_super.bin");
const u16 gContestResultsTitle_Hyper_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_hyper.bin");
const u16 gContestResultsTitle_Master_Tilemap[] = INCBIN_U16("graphics/contest/results_screen/title_master.bin");
const u16 gContestResultsTitle_Link_Tilemap[]   = INCBIN_U16("graphics/contest/results_screen/title_link.bin");
const u16 gContestResultsTitle_Cool_Tilemap[]   = INCBIN_U16("graphics/contest/results_screen/title_cool.bin");
const u16 gContestResultsTitle_Beauty_Tilemap[] = INCBIN_U16("graphics/contest/results_screen/title_beauty.bin");
const u16 gContestResultsTitle_Cute_Tilemap[]   = INCBIN_U16("graphics/contest/results_screen/title_cute.bin");
const u16 gContestResultsTitle_Smart_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_smart.bin");
const u16 gContestResultsTitle_Tough_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_tough.bin");
const u16 gContestResultsTitle_Tilemap[]        = INCBIN_U16("graphics/contest/results_screen/title.bin");

// PokéNav

const u16 gPokenavCondition_Pal[] = INCGFX_U16("graphics/pokenav/condition/graph.png", ".gbapal");
const u32 gPokenavCondition_Gfx[] = INCGFX_U32("graphics/pokenav/condition/graph.png", ".4bpp.lz");
const u32 gPokenavCondition_Tilemap[] = INCGFX_U32("graphics/pokenav/condition/graph.bin", ".lz");

const u16 gPokenavOptions_Tilemap[] = INCBIN_U16("graphics/pokenav/options/options.bin");
const u32 gPokenavOptions_Gfx[] = INCGFX_U32("graphics/pokenav/options/options.4bpp", ".lz");
const u16 gPokenavOptions_Pal[] = INCGFX_U16("graphics/pokenav/options/options.pal", ".gbapal");

const u16 gPokenavHeader_Pal[] = INCGFX_U16("graphics/pokenav/header.png", ".gbapal");
const u32 gPokenavHeader_Gfx[] = INCGFX_U32("graphics/pokenav/header.png", ".4bpp.lz", "-num_tiles 53 -Wnum_tiles"); // TODO: use width 9 and makefile rule for cleanliness, make wasnt behaving, didnt want to apply num_tiles to this
const u32 gPokenavHeader_Tilemap[] = INCGFX_U32("graphics/pokenav/header.bin", ".lz");

const u16 gPokenavLeftHeader_Pal[] = INCGFX_U16("graphics/pokenav/left_headers/palette.pal", ".gbapal");
const u32 gPokenavLeftHeaderBeauty_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/beauty.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderSmart_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/smart.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderCondition_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/condition.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderCute_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/cute.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderMatchCall_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/match_call.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderMainMenu_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/main_menu.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderHoennMap_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/hoenn_map.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderRibbons_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/ribbons.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderSearch_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/search.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderTough_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/tough.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderCool_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/cool.png", ".4bpp.lz");
const u32 gPokenavLeftHeaderParty_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/party.png", ".4bpp.lz");

const u16 gPokenavMessageBox_Pal[] = INCGFX_U16("graphics/pokenav/message.png", ".gbapal");
const u32 gPokenavMessageBox_Gfx[] = INCGFX_U32("graphics/pokenav/message.png", ".4bpp.lz");
const u32 gPokenavMessageBox_Tilemap[] = INCGFX_U32("graphics/pokenav/message.bin", ".lz");

const u16 gRegionMapCityZoomTiles_Pal[] = INCGFX_U16("graphics/pokenav/region_map/zoom_tiles.png", ".gbapal");
const u32 gRegionMapCityZoomText_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/city_zoom_text.png", ".4bpp.lz");

const u16 gPokenavConditionCancel_Pal[] = INCGFX_U16("graphics/pokenav/condition/cancel.pal", ".gbapal");
const u8 gPokenavConditionCancel_Gfx[] = INCGFX_U8("graphics/pokenav/condition/cancel.png", ".4bpp");

const u16 gMonMarkingsMenu_Pal[] = INCGFX_U16("graphics/interface/mon_markings_menu.png", ".gbapal");
const u8 gMonMarkingsMenu_Gfx[] = INCGFX_U8("graphics/interface/mon_markings_menu.png", ".4bpp");

const u16 gBerryBlenderMiscPalette[] = INCGFX_U16("graphics/berry_blender/misc.pal", ".gbapal");
const u16 gBerryBlenderArrowPalette[] = INCGFX_U16("graphics/berry_blender/arrow.png", ".gbapal");
const u8 gBerryBlenderBetaArrow_Gfx[] = INCGFX_U8("graphics/berry_blender/arrow_old.png", ".4bpp"); //unused
const u8 gBerryBlenderScoreSymbols_Gfx[] = INCGFX_U8("graphics/berry_blender/score_symbols.png", ".4bpp");
const u8 gBerryBlenderParticles_Gfx[] = INCGFX_U8("graphics/berry_blender/particles.png", ".4bpp");
static const u8 sEmpty0[0x120] = {0};
const u8 gBerryBlenderCountdownNumbers_Gfx[] = INCGFX_U8("graphics/berry_blender/countdown_numbers.png", ".4bpp");
const u8 gBerryBlenderStart_Gfx[] = INCGFX_U8("graphics/berry_blender/start.png", ".4bpp");
static const u8 sEmpty1[0x200] = {0};
const u8 gBerryBlenderPlayerArrow_Gfx[] = INCGFX_U8("graphics/berry_blender/arrow.png", ".4bpp");
static const u8 sEmpty2[0x2C0] = {0};

const u16 gEasyChatRectangleCursor_Pal[] = INCGFX_U16("graphics/easy_chat/rectangle_cursor.png", ".gbapal");
const u32 gEasyChatRectangleCursor_Gfx[] = INCGFX_U32("graphics/easy_chat/rectangle_cursor.png", ".4bpp.lz");

const u16 gEasyChatButtonWindow_Pal[] = INCGFX_U16("graphics/easy_chat/button_window.png", ".gbapal");
const u32 gEasyChatButtonWindow_Gfx[] = INCGFX_U32("graphics/easy_chat/button_window.png", ".4bpp.lz");

const u32 gEasyChatMode_Gfx[] = INCGFX_U32("graphics/easy_chat/mode.png", ".4bpp.lz");
const u16 gEasyChatMode_Pal[] = INCGFX_U16("graphics/easy_chat/mode.png", ".gbapal");

const u32 gEasyChatWindow_Gfx[] = INCGFX_U32("graphics/easy_chat/window.png", ".4bpp.lz"); // uses mode pal
const u32 gEasyChatWindow_Tilemap[] = INCGFX_U32("graphics/easy_chat/window.bin", ".lz");

const u16 gWallClockMale_Pal[]      = INCGFX_U16("graphics/wallclock/male.pal", ".gbapal");
const u16 gWallClockFemale_Pal[]    = INCGFX_U16("graphics/wallclock/female.pal", ".gbapal");
const u32 gWallClock_Gfx[]          = INCGFX_U32("graphics/wallclock/clock.png", ".4bpp.lz");
const u32 gWallClockStart_Tilemap[] = INCGFX_U32("graphics/wallclock/clock_start.bin", ".lz");
const u32 gWallClockView_Tilemap[]  = INCGFX_U32("graphics/wallclock/clock_view.bin", ".lz");

const u16 gUsePokeblockCondition_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/condition.png", ".gbapal");
const u32 gUsePokeblockCondition_Gfx[] = INCGFX_U32("graphics/pokeblock/use_screen/condition.png", ".4bpp.lz");

const u16 gUsePokeblockUpDown_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/updown.png", ".gbapal");
const u8 gUsePokeblockUpDown_Gfx[] = INCGFX_U8("graphics/pokeblock/use_screen/updown.png", ".4bpp");

const u16 gUsePokeblockGraph_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/graph.png", ".gbapal");
const u32 gUsePokeblockGraph_Gfx[] = INCGFX_U32("graphics/pokeblock/use_screen/graph.png", ".4bpp.lz");

const u32 gUsePokeblockGraph_Tilemap[] = INCGFX_U32("graphics/pokeblock/use_screen/graph.bin", ".lz");
const u16 gUsePokeblockNatureWin_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/nature.pal", ".gbapal");

#include "data/graphics/slot_machine.h"

// trainer card

const u16 gHoennTrainerCardGreen_Pal[] = INCGFX_U16("graphics/trainer_card/green.pal", ".gbapal");
const u32 gHoennTrainerCard_Gfx[] = INCGFX_U32("graphics/trainer_card/tiles.png", ".4bpp.lz");
const u32 gHoennTrainerCardBg_Tilemap[] = INCGFX_U32("graphics/trainer_card/bg.bin", ".lz");
const u32 gHoennTrainerCardFront_Tilemap[] = INCGFX_U32("graphics/trainer_card/front.bin", ".lz");
const u32 gHoennTrainerCardBack_Tilemap[] = INCGFX_U32("graphics/trainer_card/back.bin", ".lz");
const u32 gHoennTrainerCardFrontLink_Tilemap[] = INCGFX_U32("graphics/trainer_card/front_link.bin", ".lz");

const u16 gKantoTrainerCardBlue_Pal[] = INCGFX_U16("graphics/trainer_card/frlg/blue.pal", ".gbapal");
const u32 gKantoTrainerCard_Gfx[] = INCGFX_U32("graphics/trainer_card/frlg/tiles.png", ".4bpp.lz");
const u32 gKantoTrainerCardBg_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/bg.bin", ".lz");
const u32 gKantoTrainerCardFront_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/front.bin", ".lz");
const u32 gKantoTrainerCardBack_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/back.bin", ".lz");
const u32 gKantoTrainerCardFrontLink_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/front_link.bin", ".lz");

// Pokémon storage system

const u32 gStorageSystemMenu_Gfx[] = INCGFX_U32("graphics/pokemon_storage/menu.png", ".4bpp.lz");
const u16 gStorageSystemPartyMenu_Pal[] = INCGFX_U16("graphics/pokemon_storage/party_menu.pal", ".gbapal");
const u32 gStorageSystemPartyMenu_Tilemap[] = INCGFX_U32("graphics/pokemon_storage/party_menu.bin", ".lz");

// naming screen

const u16 gNamingScreenMenu_Pal[6][16] =
{
    INCGFX_U16("graphics/naming_screen/menu.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/page_swap_upper.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/page_swap_lower.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/page_swap_others.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/buttons.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/cursor.pal", ".gbapal"),
};
const u32 gNamingScreenMenu_Gfx[]                = INCGFX_U32("graphics/naming_screen/menu.png", ".4bpp.lz");
const u32 gNamingScreenPageSwapFrame_Gfx[]       = INCGFX_U32("graphics/naming_screen/page_swap_frame.png", ".4bpp");
const u32 gNamingScreenBackButton_Gfx[]          = INCGFX_U32("graphics/naming_screen/back_button.png", ".4bpp");
const u32 gNamingScreenOKButton_Gfx[]            = INCGFX_U32("graphics/naming_screen/ok_button.png", ".4bpp");
const u32 gNamingScreenPageSwapUpper_Gfx[]       = INCGFX_U32("graphics/naming_screen/page_swap_upper.png", ".4bpp");
const u32 gNamingScreenPageSwapLower_Gfx[]       = INCGFX_U32("graphics/naming_screen/page_swap_lower.png", ".4bpp");
const u32 gNamingScreenPageSwapOthers_Gfx[]      = INCGFX_U32("graphics/naming_screen/page_swap_others.png", ".4bpp");
const u32 gNamingScreenCursor_Gfx[]              = INCGFX_U32("graphics/naming_screen/cursor.png", ".4bpp", "-num_tiles 5 -Wnum_tiles");
const u32 gNamingScreenCursorSquished_Gfx[]      = INCGFX_U32("graphics/naming_screen/cursor_squished.png", ".4bpp", "-num_tiles 5 -Wnum_tiles");
const u32 gNamingScreenCursorFilled_Gfx[]        = INCGFX_U32("graphics/naming_screen/cursor_filled.png", ".4bpp", "-num_tiles 5 -Wnum_tiles");
const u32 gNamingScreenPageSwapButton_Gfx[]      = INCGFX_U32("graphics/naming_screen/page_swap_button.png", ".4bpp");
const u32 gNamingScreenInputArrow_Gfx[]          = INCGFX_U32("graphics/naming_screen/input_arrow.png", ".4bpp");
const u32 gNamingScreenUnderscore_Gfx[]          = INCGFX_U32("graphics/naming_screen/underscore.png", ".4bpp");
const u32 gNamingScreenBackground_Tilemap[]      = INCGFX_U32("graphics/naming_screen/background.bin", ".lz");
const u32 gNamingScreenKeyboardUpper_Tilemap[]   = INCGFX_U32("graphics/naming_screen/keyboard_upper.bin", ".lz");
const u32 gNamingScreenKeyboardLower_Tilemap[]   = INCGFX_U32("graphics/naming_screen/keyboard_lower.bin", ".lz");
const u32 gNamingScreenKeyboardSymbols_Tilemap[] = INCGFX_U32("graphics/naming_screen/keyboard_symbols.bin", ".lz");

// union room chat
const u16 gUnionRoomChat_Background_Pal[] = INCGFX_U16("graphics/union_room_chat/background.png", ".gbapal");
const u32 gUnionRoomChat_Background_Gfx[] = INCGFX_U32("graphics/union_room_chat/background.png", ".4bpp.lz");
const u32 gUnionRoomChat_Background_Tilemap[] = INCGFX_U32("graphics/union_room_chat/background.bin", ".lz");
const u16 gUnionRoomChat_InputText_Pal[] = INCGFX_U16("graphics/union_room_chat/input_text.pal", ".gbapal");
const u16 gUnionRoomChat_Keyboard_Pal[] = INCGFX_U16("graphics/union_room_chat/keyboard.png", ".gbapal");
const u32 gUnionRoomChat_Keyboard_Gfx[] = INCGFX_U32("graphics/union_room_chat/keyboard.png", ".4bpp.lz");
const u32 gUnionRoomChat_Keyboard_Tilemap[] = INCGFX_U32("graphics/union_room_chat/keyboard.bin", ".lz");
const u32 gUnionRoomChat_RButtonLabels[] = INCGFX_U32("graphics/union_room_chat/r_button_labels.png", ".4bpp.lz");

const u16 gTilesetPalettes_General[][16] =
{
    INCGFX_U16("data/tilesets/primary/general/palettes/00.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/01.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/02.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/03.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/04.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/05.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/06.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/07.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/08.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/09.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/10.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/11.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/12.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/13.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/14.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/15.pal", ".gbapal"),
};

const u32 gTilesetTiles_General[] = INCGFX_U32("data/tilesets/primary/general/tiles.png", ".4bpp.lz");

// trade/egg hatch

const u16 gTradeGba_Pal[] = INCGFX_U16("graphics/trade/gba.pal", ".gbapal");
const u16 gTradeGba2_Pal[] = INCGFX_U16("graphics/trade/gba_pal2.pal", ".gbapal");
const u8 gTradeGba_Gfx[] = INCGFX_U8("graphics/trade/gba.png", ".4bpp");

static const u16 sEmptyPal[16] = {0};

#include "data/graphics/berry_fix.h"

// Trade
const u16 gTradeMenu_Pal[] = INCGFX_U16("graphics/trade/menu.pal", ".gbapal");
const u16 gTradeCursor_Pal[] = INCGFX_U16("graphics/trade/cursor.pal", ".gbapal");
const u8 gTradeMenu_Gfx[] = INCGFX_U8("graphics/trade/menu.png", ".4bpp");
const u8 gTradeCursor_Gfx[] = INCGFX_U8("graphics/trade/cursor.png", ".4bpp");
const u16 gTradeUnused_Tilemap[] = INCBIN_U16("graphics/trade/unused.bin");
const u16 gTradeMenu_Tilemap[] = INCBIN_U16("graphics/trade/menu.bin");
const u16 gTradeMenuMonBox_Tilemap[] = INCBIN_U16("graphics/trade/menu_mon_box.bin");

const u16 gMessageBox_Pal[] = INCGFX_U16("graphics/text_window/message_box.png", ".gbapal");
const u8 gMessageBox_Gfx[] = INCGFX_U8("graphics/text_window/message_box.png", ".4bpp");

const u32 gWallpaperIcon_Cross[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/cross.png", ".4bpp.lz");
const u32 gWallpaperIcon_Bolt[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/bolt.png", ".4bpp.lz");
const u32 gWallpaperIcon_Plusle[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/plusle.png", ".4bpp.lz");

const u16 gWallpaperPalettes_Horizontal[][16] =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/horizontal/bg.png", ".gbapal"),
};

const u32 gWallpaperTiles_Horizontal[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/horizontal/tiles.4bpp", ".lz");
const u32 gWallpaperTilemap_Horizontal[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/horizontal/tilemap.bin", ".lz");

const u16 gWallpaperPalettes_Ribbon[][16] =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/ribbon/frame.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/ribbon/bg.png", ".gbapal"),
};

const u32 gWallpaperTiles_Ribbon[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/ribbon/tiles.4bpp", ".lz");
const u32 gWallpaperTilemap_Ribbon[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/ribbon/tilemap.bin", ".lz");

const u16 gPokenavRibbonsSummaryBg_Pal[] = INCGFX_U16("graphics/pokenav/ribbons/summary_bg.png", ".gbapal");
const u32 gPokenavRibbonsSummaryBg_Gfx[] = INCGFX_U32("graphics/pokenav/ribbons/summary_bg.png", ".4bpp.lz");
const u32 gPokenavRibbonsSummaryBg_Tilemap[] = INCGFX_U32("graphics/pokenav/ribbons/summary_bg.bin", ".lz");

const u16 gMonIconPalettes[][16] =
{
    INCGFX_U16("graphics/pokemon/icon_palettes/icon_palette_0.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/icon_palette_1.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/icon_palette_2.pal", ".gbapal"),
};

const u16 gTitleScreenBgPalettes[]         = INCBIN_U16("graphics/title_screen/pokemon_logo.gbapal",
                                                        "graphics/title_screen/rayquaza_and_clouds.gbapal");
const u16 gTitleScreenEmeraldVersionPal[]  = INCGFX_U16("graphics/title_screen/emerald_version.png", ".gbapal");
const u32 gTitleScreenCloudsTilemap[]      = INCGFX_U32("graphics/title_screen/clouds.bin", ".lz");
const u32 gTitleScreenPokemonLogoGfx[]     = INCGFX_U32("graphics/title_screen/pokemon_logo.png", ".8bpp.lz");
const u32 gTitleScreenEmeraldVersionGfx[]  = INCGFX_U32("graphics/title_screen/emerald_version.png", ".8bpp.lz", "-mwidth 8 -mheight 4");
const u16 gTitleScreenPressStartPal[]      = INCGFX_U16("graphics/title_screen/press_start.png", ".gbapal");
const u32 gTitleScreenPressStartGfx[]      = INCGFX_U32("graphics/title_screen/press_start.png", ".4bpp.lz");
const u32 gTitleScreenPokemonLogoTilemap[] = INCGFX_U32("graphics/title_screen/pokemon_logo.bin", ".lz");

const u16 gFrontierPassBg_Pal[][16]                      = INCGFX_U16("graphics/frontier_pass/bg.png", ".gbapal"); // 8 x 16
const u32 gFrontierPassBg_Gfx[]                          = INCGFX_U32("graphics/frontier_pass/bg.png", ".4bpp.lz");
const u32 gFrontierPassMapAndCard_Gfx[]                  = INCGFX_U32("graphics/frontier_pass/map_and_card.png", ".8bpp.lz");
const u32 gFrontierPassBg_Tilemap[]                      = INCGFX_U32("graphics/frontier_pass/bg.bin", ".lz");
const u32 gFrontierPassCancelButton_Tilemap[]            = INCBIN_U32("graphics/frontier_pass/cancel.bin");
const u32 gFrontierPassCancelButtonHighlighted_Tilemap[] = INCBIN_U32("graphics/frontier_pass/cancel_highlighted.bin");

// Berry Crush
const u16 gBerryCrush_Crusher_Pal[] = INCGFX_U16("graphics/berry_crush/crusher.png", ".gbapal");
const u32 gBerryCrush_Crusher_Gfx[] = INCGFX_U32("graphics/berry_crush/crusher.png", ".4bpp.lz");
const u32 gBerryCrush_TextWindows_Tilemap[] = INCGFX_U32("graphics/berry_crush/text_windows.bin", ".lz");

// random garbage at the end.
static const u8 sEmpty3[0x54BAC] = {0};
static const u8 sUnused1[]       = {0x0D, 0x00, 0x58, 0x02};
static const u8 sEmpty4[0x1145]  = {0};
static const u8 sUnused2[]       = {0x02};
static const u8 sEmpty5[0x3242]  = {0};
static const u8 sUnused3[]       = {0x40};
static const u8 sEmpty6[0x13]    = {0};
