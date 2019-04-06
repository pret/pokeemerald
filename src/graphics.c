#include "global.h"

const u32 gBattleTextboxTiles[] = INCBIN_U32("graphics/battle_interface/textbox.4bpp.lz");
const u32 gBattleTextboxPalette[] = INCBIN_U32("graphics/battle_interface/textbox.gbapal.lz");
const u32 gBattleTextboxTilemap[] = INCBIN_U32("graphics/battle_interface/textbox_map.bin.lz");

const u32 gMonStillFrontPic_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/circled_question_mark/front.4bpp.lz");
const u32 gMonBackPic_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/circled_question_mark/back.4bpp.lz");
const u32 gMonPalette_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/circled_question_mark/normal.gbapal.lz");
const u32 gMonShinyPalette_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/circled_question_mark/shiny.gbapal.lz");

const u32 gUnusedGfx_OldCharmap[] = INCBIN_U32("graphics/unused/old_charmap.4bpp.lz"); // japanese table and bunch of stuff
const u32 gUnusedTimemap_OldCharmap[] = INCBIN_U32("graphics/unused/old_charmap.bin.lz");
const u32 gUnusedPal_OldCharmap[] = INCBIN_U32("graphics/unused/old_charmap.gbapal.lz");

const u32 gSmokescreenImpactTiles[] = INCBIN_U32("graphics/battle_anims/sprites/smokescreen_impact.4bpp.lz");
const u32 gSmokescreenImpactPalette[] = INCBIN_U32("graphics/battle_anims/sprites/smokescreen_impact.gbapal.lz");

#include "data/graphics/interface_pokeballs.h"

const u32 gBlankGfxCompressed[] = INCBIN_U32("graphics/interface/blank.4bpp.lz");

// Battle anims
const u32 gBattleAnimSpriteSheet_Bubble[] = INCBIN_U32("graphics/battle_anims/sprites/bubble.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Bone[] = INCBIN_U32("graphics/battle_anims/sprites/bone.4bpp.lz");
const u32 gBattleAnimSpriteSheet_AirWave[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Orb[] = INCBIN_U32("graphics/battle_anims/sprites/orb.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Sword[] = INCBIN_U32("graphics/battle_anims/sprites/sword.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Seed[] = INCBIN_U32("graphics/battle_anims/sprites/seed.4bpp.lz");

const u32 gBattleAnimSpritePalette_RainDrops[] = INCBIN_U32("graphics/battle_anims/sprites/rain_drops.gbapal.lz");
const u32 gBattleAnimSpritePalette_Bone[] = INCBIN_U32("graphics/battle_anims/sprites/bone.gbapal.lz");
const u32 gBattleAnimSpritePalette_AirWave[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave.gbapal.lz");
const u32 gBattleAnimSpritePalette_Orb[] = INCBIN_U32("graphics/battle_anims/sprites/orb.gbapal.lz");
const u32 gBattleAnimSpritePalette_Sword[] = INCBIN_U32("graphics/battle_anims/sprites/sword.gbapal.lz");
const u32 gBattleAnimSpritePalette_Seed[] = INCBIN_U32("graphics/battle_anims/sprites/seed.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Needle[] = INCBIN_U32("graphics/battle_anims/sprites/needle.4bpp.lz");
const u32 gBattleAnimSpritePalette_Needle[] = INCBIN_U32("graphics/battle_anims/sprites/needle.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Explosion6[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_6.4bpp.lz");
const u32 gBattleAnimSpritePalette_Explosion6[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_6.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PinkOrb[] = INCBIN_U32("graphics/battle_anims/sprites/pink_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_PinkOrb[] = INCBIN_U32("graphics/battle_anims/sprites/pink_orb.gbapal.lz");

const u32 gBattleAnimSpritePalette_IceCube[] = INCBIN_U32("graphics/battle_anims/sprites/ice_cube.gbapal.lz");
const u32 gBattleAnimSpriteSheet_IceCube[] = INCBIN_U32("graphics/battle_anims/sprites/ice_cube.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Gust[] = INCBIN_U32("graphics/battle_anims/sprites/gust.4bpp.lz");
const u32 gBattleAnimSpritePalette_Gust[] = INCBIN_U32("graphics/battle_anims/sprites/gust.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Spark2[] = INCBIN_U32("graphics/battle_anims/sprites/spark_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Spark2[] = INCBIN_U32("graphics/battle_anims/sprites/spark_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Orange[] = INCBIN_U32("graphics/battle_anims/sprites/orange.4bpp.lz");
const u32 gBattleAnimSpritePalette_Orange[] = INCBIN_U32("graphics/battle_anims/sprites/orange.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Spikes[] = INCBIN_U32("graphics/battle_anims/sprites/spikes.4bpp.lz");
const u32 gBattleAnimSpritePalette_Spikes[] = INCBIN_U32("graphics/battle_anims/sprites/spikes.gbapal.lz");

const u32 gBattleAnimSpriteSheet_YellowBall[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_ball.4bpp.lz");
const u32 gBattleAnimSpritePalette_YellowBall[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_ball.gbapal.lz");

const u32 gBattleAnimSpriteSheet_TiedBag[] = INCBIN_U32("graphics/battle_anims/sprites/tied_bag.4bpp.lz");
const u32 gBattleAnimSpritePalette_TiedBag[] = INCBIN_U32("graphics/battle_anims/sprites/tied_bag.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BlackSmoke[] = INCBIN_U32("graphics/battle_anims/sprites/black_smoke.4bpp.lz");
const u32 gBattleAnimSpritePalette_BlackSmoke[] = INCBIN_U32("graphics/battle_anims/sprites/black_smoke.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BlackBall[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball.4bpp.lz");

const u32 gUnknownGfx_C035B8[] = INCBIN_U32("graphics/unknown/unknown_C035B8.4bpp.lz");

const u32 gBattleAnimSpritePalette_Glass[] = INCBIN_U32("graphics/battle_anims/sprites/glass.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Glass[] = INCBIN_U32("graphics/battle_anims/sprites/glass.4bpp.lz");

const u32 gBattleAnimSpriteSheet_HornHit[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit.4bpp.lz");
const u32 gBattleAnimSpritePalette_HornHit[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit.gbapal.lz");

const u32 gBattleAnimSpritePalette_BlueShards[] = INCBIN_U32("graphics/battle_anims/sprites/blue_shards.gbapal.lz");
const u32 gBattleAnimSpriteSheet_BlueShards[] = INCBIN_U32("graphics/battle_anims/sprites/blue_shards.4bpp.lz");

const u32 gUnused_BattleSpritePalette_023[] = INCBIN_U32("graphics/unused/battle_anim_023.gbapal.lz");

const u32 gUnusedGfx_MusicNotes[] = INCBIN_U32("graphics/unused/music_notes.4bpp.lz");

const u32 gBattleAnimSpritePalette_Hit[] = INCBIN_U32("graphics/battle_anims/sprites/hit.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Hit[] = INCBIN_U32("graphics/battle_anims/sprites/hit.4bpp.lz");

const u32 gBattleAnimSpritePalette_Hit2[] = INCBIN_U32("graphics/battle_anims/sprites/hit_2.gbapal.lz");

const u32 gBattleAnimSpritePalette_WavingHand[] = INCBIN_U32("graphics/battle_anims/sprites/waving_hand.gbapal.lz");
const u32 gBattleAnimSpriteSheet_WavingHand[] = INCBIN_U32("graphics/battle_anims/sprites/waving_hand.4bpp.lz");

const u32 gBattleAnimSpriteSheet_ClosingEye[] = INCBIN_U32("graphics/battle_anims/sprites/closing_eye.4bpp.lz");
const u32 gBattleAnimSpritePalette_ClosingEye[] = INCBIN_U32("graphics/battle_anims/sprites/closing_eye.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BlueStar[] = INCBIN_U32("graphics/battle_anims/sprites/blue_star.4bpp.lz");
const u32 gBattleAnimSpritePalette_BlueStar[] = INCBIN_U32("graphics/battle_anims/sprites/blue_star.gbapal.lz");

const u32 gBattleAnimSpritePalette_BubbleBurst[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst.gbapal.lz");
const u32 gBattleAnimSpriteSheet_BubbleBurst[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst.4bpp.lz");

const u32 gBattleAnimSpriteSheet_HitDuplicate[] = INCBIN_U32("graphics/battle_anims/sprites/hit_duplicate.4bpp.lz");
const u32 gBattleAnimSpritePalette_HitDuplicate[] = INCBIN_U32("graphics/battle_anims/sprites/hit_duplicate.gbapal.lz");

const u32 gBattleAnimSpritePalette_Leer[] = INCBIN_U32("graphics/battle_anims/sprites/leer.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Leer[] = INCBIN_U32("graphics/battle_anims/sprites/leer.4bpp.lz");

const u32 gBattleAnimSpritePalette_BlueBurst[] = INCBIN_U32("graphics/battle_anims/sprites/blue_burst.gbapal.lz");
const u32 gBattleAnimSpriteSheet_BlueBurst[] = INCBIN_U32("graphics/battle_anims/sprites/blue_burst.4bpp.lz");

const u32 gBattleAnimSpriteSheet_SmallEmber[] = INCBIN_U32("graphics/battle_anims/sprites/small_ember.4bpp.lz");
const u32 gBattleAnimSpritePalette_SmallEmber[] = INCBIN_U32("graphics/battle_anims/sprites/small_ember.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GraySmoke[] = INCBIN_U32("graphics/battle_anims/sprites/gray_smoke.4bpp.lz");
const u32 gBattleAnimSpritePalette_GraySmoke[] = INCBIN_U32("graphics/battle_anims/sprites/gray_smoke.gbapal.lz");

const u32 gBattleAnimSpritePalette_Fire[] = INCBIN_U32("graphics/battle_anims/sprites/fire.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Fire[] = INCBIN_U32("graphics/battle_anims/sprites/fire.4bpp.lz");

const u32 gBattleAnimSpriteSheet_SpinningFire[] = INCBIN_U32("graphics/battle_anims/sprites/spinning_fire.4bpp.lz");
const u32 gBattleAnimSpriteSheet_FirePlume[] = INCBIN_U32("graphics/battle_anims/sprites/fire_plume.4bpp.lz");

const u32 gBattleAnimSpritePalette_Lightning2[] = INCBIN_U32("graphics/battle_anims/sprites/lightning_2.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Lightning2[] = INCBIN_U32("graphics/battle_anims/sprites/lightning_2.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Lightning[] = INCBIN_U32("graphics/battle_anims/sprites/lightning.4bpp.lz");

const u32 gUnknownGfx_C06D98[] = INCBIN_U32("graphics/unknown/unknown_C06D98.4bpp.lz");
const u32 gUnknownPal_C06D98[] = INCBIN_U32("graphics/unknown/unknown_C06D98.gbapal.lz");
const u32 gUnknownPal_C06D98_2[] = INCBIN_U32("graphics/unknown/unknown_C06D98_2.gbapal.lz");

// old battle interface data, unused

const u32 gOldBattleInterfaceGfx[] = INCBIN_U32("graphics/unused/obi1.4bpp.lz");
const u32 gOldBattleInterfacePal_1_2_3[] = INCBIN_U32("graphics/unused/obi_palpak1.gbapal.lz"); // palettes 1-3
const u32 gOldBattleInterfacePal4[] = INCBIN_U32("graphics/unused/old_pal4.gbapal.lz"); // 4 is by itself
const u32 gOldBattleInterfacePal_5_6_7[] = INCBIN_U32("graphics/unused/obi_palpak3.gbapal.lz"); // palettes 5-7
const u32 gOldBattleInterfaceGfx2[] = INCBIN_U32("graphics/unused/obi2.4bpp.lz");
const u32 gOldBattleInterfaceTilemap[] = INCBIN_U32("graphics/unused/old_battle_interface_tilemap.bin.lz");

const u32 gBattleAnimSpritePalette_ClawSlash2[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash_2.gbapal.lz");
const u32 gBattleAnimSpritePalette_ClawSlash[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash.gbapal.lz");

const u32 gBattleAnimSpriteSheet_ClawSlash2[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash_2.4bpp.lz");
const u32 gBattleAnimSpriteSheet_ClawSlash[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Scratch3[] = INCBIN_U32("graphics/battle_anims/sprites/scratch_3.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Scratch2[] = INCBIN_U32("graphics/battle_anims/sprites/scratch_2.4bpp.lz");

const u32 gPartyMenuHpBar_Gfx[] = INCBIN_U32("graphics/interface/party_menu_hpbar.4bpp.lz");

const u32 gBattleAnimSpriteSheet_BubbleBurst2[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst_2.4bpp.lz");

const u32 gBattleAnimSpritePalette_BubbleBurst2[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_IceChunk[] = INCBIN_U32("graphics/battle_anims/sprites/ice_chunk.4bpp.lz");
const u32 gBattleAnimSpritePalette_IceChunk[] = INCBIN_U32("graphics/battle_anims/sprites/ice_chunk.gbapal.lz");

const u32 gBattleAnimSpritePalette_Glass2[] = INCBIN_U32("graphics/battle_anims/sprites/glass_2.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Glass2[] = INCBIN_U32("graphics/battle_anims/sprites/glass_2.4bpp.lz");

const u32 gBattleAnimSpritePalette_PinkHeart2[] = INCBIN_U32("graphics/battle_anims/sprites/pink_heart_2.gbapal.lz");
const u32 gBattleAnimSpriteSheet_PinkHeart2[] = INCBIN_U32("graphics/battle_anims/sprites/pink_heart_2.4bpp.lz");

const u32 gUnknown_08C08F0C[] = INCBIN_U32("graphics/battle_interface/unused_window.4bpp.lz");
const u32 gUnknown_08C093C8[] = INCBIN_U32("graphics/battle_interface/unused_window.gbapal.lz");

const u32 gUnknown_08C093F0[] = INCBIN_U32("graphics/interface/hp_numbers.4bpp.lz");

const u32 gBattleAnimSpriteSheet_SapDrip[] = INCBIN_U32("graphics/battle_anims/sprites/sap_drip.4bpp.lz");
const u32 gBattleAnimSpritePalette_SapDrip[] = INCBIN_U32("graphics/battle_anims/sprites/sap_drip.gbapal.lz");

const u32 gBattleAnimSpritePalette_SapDrip2[] = INCBIN_U32("graphics/battle_anims/sprites/sap_drip_2.gbapal.lz");

const u32 gUnusedGfx_Window2[] = INCBIN_U32("graphics/battle_interface/unused_window2.4bpp.lz");
const u32 gUnusedGfx_Window2Bar[] = INCBIN_U32("graphics/battle_interface/unused_window2bar.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Sparkle1[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_1.4bpp.lz");
const u32 gBattleAnimSpritePalette_Sparkle1[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_1.gbapal.lz");

const u32 gBattleAnimSpritePalette_Sparkle2[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_2.gbapal.lz");
const u32 gBattleAnimSpritePalette_HumanoidFoot[] = INCBIN_U32("graphics/battle_anims/sprites/humanoid_foot.gbapal.lz");

const u32 gBattleAnimSpriteSheet_HumanoidFoot[] = INCBIN_U32("graphics/battle_anims/sprites/humanoid_foot.4bpp.lz");
const u32 gBattleAnimSpriteSheet_MonsterFoot[] = INCBIN_U32("graphics/battle_anims/sprites/monster_foot.4bpp.lz");
const u32 gBattleAnimSpriteSheet_HumanoidHand[] = INCBIN_U32("graphics/battle_anims/sprites/humanoid_hand.4bpp.lz");

const u32 gUnusedGfx_LineSketch[] = INCBIN_U32("graphics/unused/line_sketch.4bpp.lz");
const u32 gUnusedPal_LineSketch[] = INCBIN_U32("graphics/unused/line_sketch.gbapal.lz");

const u32 gBattleAnimSpriteSheet_YellowUnk[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_unk.4bpp.lz");
const u32 gBattleAnimSpritePalette_YellowUnk[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_unk.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SlamHit[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit.4bpp.lz");
const u32 gBattleAnimSpritePalette_SlamHit[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RedFist[] = INCBIN_U32("graphics/battle_anims/sprites/red_fist.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Ring[] = INCBIN_U32("graphics/battle_anims/sprites/ring.4bpp.lz");
const u32 gBattleAnimSpritePalette_Ring[] = INCBIN_U32("graphics/battle_anims/sprites/ring.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Rocks[] = INCBIN_U32("graphics/battle_anims/sprites/rocks.4bpp.lz");
const u32 gBattleAnimSpritePalette_Rocks[] = INCBIN_U32("graphics/battle_anims/sprites/rocks.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Z[] = INCBIN_U32("graphics/battle_anims/sprites/z.4bpp.lz");
const u32 gBattleAnimSpritePalette_Z[] = INCBIN_U32("graphics/battle_anims/sprites/z.gbapal.lz");

const u32 gBattleAnimSpriteSheet_YellowUnk2[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_unk_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_YellowUnk2[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_unk_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_AirSlash[] = INCBIN_U32("graphics/battle_anims/sprites/air_slash.4bpp.lz");
const u32 gBattleAnimSpritePalette_AirSlash[] = INCBIN_U32("graphics/battle_anims/sprites/air_slash.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SpinningGreenOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/spinning_green_orbs.4bpp.lz");
const u32 gBattleAnimSpritePalette_SpinningGreenOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/spinning_green_orbs.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Leaf[] = INCBIN_U32("graphics/battle_anims/sprites/leaf.4bpp.lz");
const u32 gBattleAnimSpritePalette_Leaf[] = INCBIN_U32("graphics/battle_anims/sprites/leaf.gbapal.lz");

const u32 gUnusedGfx_Metronome[] = INCBIN_U32("graphics/unused/metronome_hand_small.4bpp.lz"); // unused, was for metronome at one point

const u32 gBattleAnimSpritePalette_Clapping[] = INCBIN_U32("graphics/battle_anims/sprites/clapping.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PoisonPowder[] = INCBIN_U32("graphics/battle_anims/sprites/poison_powder.4bpp.lz");
const u32 gBattleAnimSpritePalette_PoisonPowder[] = INCBIN_U32("graphics/battle_anims/sprites/poison_powder.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BrownTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/brown_triangle.4bpp.lz");
const u32 gBattleAnimSpritePalette_BrownTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/brown_triangle.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Sparkle3[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_3.4bpp.lz");
const u32 gBattleAnimSpritePalette_Sparkle3[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_3.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Sparkle4[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_4.4bpp.lz");

const u32 gBattleAnimSpriteSheet_MusicNotes[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes.4bpp.lz");
const u32 gBattleAnimSpritePalette_MusicNotes[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Duck[] = INCBIN_U32("graphics/battle_anims/sprites/duck.4bpp.lz");
const u32 gBattleAnimSpritePalette_Duck[] = INCBIN_U32("graphics/battle_anims/sprites/duck.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Alert[] = INCBIN_U32("graphics/battle_anims/sprites/alert.4bpp.lz");
const u32 gBattleAnimSpritePalette_Alert[] = INCBIN_U32("graphics/battle_anims/sprites/alert.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Shock4[] = INCBIN_U32("graphics/battle_anims/sprites/shock_4.4bpp.lz");
const u32 gBattleAnimSpritePalette_Shock4[] = INCBIN_U32("graphics/battle_anims/sprites/shock_4.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Shock[] = INCBIN_U32("graphics/battle_anims/sprites/shock.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Bell2[] = INCBIN_U32("graphics/battle_anims/sprites/bell_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Bell2[] = INCBIN_U32("graphics/battle_anims/sprites/bell_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PinkGlove[] = INCBIN_U32("graphics/battle_anims/sprites/pink_glove.4bpp.lz");
const u32 gBattleAnimSpritePalette_PinkGlove[] = INCBIN_U32("graphics/battle_anims/sprites/pink_glove.gbapal.lz");

const u16 gUnknown_C0CA1C[] = INCBIN_U16("graphics/unknown/unknown_C0CA1C.bin");
const u16 gUnknown_C0CA40[] = INCBIN_U16("graphics/unknown/unknown_C0CA40.bin");
const u16 gUnknown_C0CA64[] = INCBIN_U16("graphics/unknown/unknown_C0CA64.bin");
const u32 gUnusedGfx8bpp_LineSketch2[] = INCBIN_U32("graphics/unused/line_sketch_2.8bpp.lz");
const u16 gUnknown_C0CAE0[] = INCBIN_U16("graphics/unknown/unknown_C0CAE0.bin");
const u32 gUnusedTilemap_LineSketch2[] = INCBIN_U32("graphics/unused/line_sketch_2.bin.lz");

const u32 gBattleAnimSpriteSheet_BlueLines[] = INCBIN_U32("graphics/battle_anims/sprites/blue_lines.4bpp.lz");
const u32 gBattleAnimSpritePalette_BlueLines[] = INCBIN_U32("graphics/battle_anims/sprites/blue_lines.gbapal.lz");

const u32 gBattleAnimSpritePalette_Impact3[] = INCBIN_U32("graphics/battle_anims/sprites/impact_3.gbapal.lz");
const u32 gBattleAnimSpritePalette_Impact2[] = INCBIN_U32("graphics/battle_anims/sprites/impact_2.gbapal.lz");
const u32 gBattleAnimSpritePalette_Reticle[] = INCBIN_U32("graphics/battle_anims/sprites/reticle.gbapal.lz");
const u32 gBattleAnimSpritePalette_Breath[] = INCBIN_U32("graphics/battle_anims/sprites/breath.gbapal.lz");
const u32 gBattleAnimSpritePalette_Snowball[] = INCBIN_U32("graphics/battle_anims/sprites/snowball.gbapal.lz");
const u32 gBattleAnimSpritePalette_Vine[] = INCBIN_U32("graphics/battle_anims/sprites/vine.gbapal.lz");
const u32 gBattleAnimSpritePalette_Sword2[] = INCBIN_U32("graphics/battle_anims/sprites/sword_2.gbapal.lz");
const u32 gBattleAnimSpritePalette_RedTube[] = INCBIN_U32("graphics/battle_anims/sprites/red_tube.gbapal.lz");
const u32 gBattleAnimSpritePalette_Amnesia[] = INCBIN_U32("graphics/battle_anims/sprites/amnesia.gbapal.lz");
const u32 gBattleAnimSpritePalette_String2[] = INCBIN_U32("graphics/battle_anims/sprites/string_2.gbapal.lz");

const u32 gUnknown_D0D2B4[] = INCBIN_U32("graphics/unknown/unknown_D0D2B4.bin.lz");

const u32 gBattleAnimSpritePalette_Pencil2[] = INCBIN_U32("graphics/battle_anims/sprites/pencil_2.gbapal.lz");
const u32 gBattleAnimSpritePalette_Petal[] = INCBIN_U32("graphics/battle_anims/sprites/petal.gbapal.lz");
const u32 gBattleAnimSpritePalette_BentSpoon[] = INCBIN_U32("graphics/battle_anims/sprites/bent_spoon.gbapal.lz");
const u32 gBattleAnimSpritePalette_Coin[] = INCBIN_U32("graphics/battle_anims/sprites/coin.gbapal.lz");
const u32 gBattleAnimSpritePalette_CrackedEgg[] = INCBIN_U32("graphics/battle_anims/sprites/cracked_egg.gbapal.lz");
const u32 gBattleAnimSpritePalette_FreshEgg[] = INCBIN_U32("graphics/battle_anims/sprites/fresh_egg.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Impact3[] = INCBIN_U32("graphics/battle_anims/sprites/impact_3.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Impact2[] = INCBIN_U32("graphics/battle_anims/sprites/impact_2.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Reticle[] = INCBIN_U32("graphics/battle_anims/sprites/reticle.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Breath[] = INCBIN_U32("graphics/battle_anims/sprites/breath.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Snowball[] = INCBIN_U32("graphics/battle_anims/sprites/snowball.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Vine[] = INCBIN_U32("graphics/battle_anims/sprites/vine.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Sword2[] = INCBIN_U32("graphics/battle_anims/sprites/sword_2.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Clapping[] = INCBIN_U32("graphics/battle_anims/sprites/clapping.4bpp.lz");
const u32 gBattleAnimSpriteSheet_RedTube[] = INCBIN_U32("graphics/battle_anims/sprites/red_tube.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Amnesia[] = INCBIN_U32("graphics/battle_anims/sprites/amnesia.4bpp.lz");
const u32 gBattleAnimSpriteSheet_String2[] = INCBIN_U32("graphics/battle_anims/sprites/string_2.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Pencil2[] = INCBIN_U32("graphics/battle_anims/sprites/pencil_2.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Petal[] = INCBIN_U32("graphics/battle_anims/sprites/petal.4bpp.lz");
const u32 gBattleAnimSpriteSheet_BentSpoon[] = INCBIN_U32("graphics/battle_anims/sprites/bent_spoon.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Web[] = INCBIN_U32("graphics/battle_anims/sprites/web.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Coin[] = INCBIN_U32("graphics/battle_anims/sprites/coin.4bpp.lz");
const u32 gBattleAnimSpriteSheet_CrackedEgg[] = INCBIN_U32("graphics/battle_anims/sprites/cracked_egg.4bpp.lz");
const u32 gBattleAnimSpriteSheet_HatchedEgg[] = INCBIN_U32("graphics/battle_anims/sprites/hatched_egg.4bpp.lz");
const u32 gBattleAnimSpriteSheet_FreshEgg[] = INCBIN_U32("graphics/battle_anims/sprites/fresh_egg.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Fangs[] = INCBIN_U32("graphics/battle_anims/sprites/fangs.4bpp.lz");
const u32 gBattleAnimSpritePalette_Fangs[] = INCBIN_U32("graphics/battle_anims/sprites/fangs.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Explosion2[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Explosion2[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Explosion3[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_3.4bpp.lz");

const u32 gBattleAnimSpriteSheet_WaterDroplet[] = INCBIN_U32("graphics/battle_anims/sprites/water_droplet.4bpp.lz");
const u32 gBattleAnimSpritePalette_WaterDroplet[] = INCBIN_U32("graphics/battle_anims/sprites/water_droplet.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WaterDroplet2[] = INCBIN_U32("graphics/battle_anims/sprites/water_droplet_2.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Seed2[] = INCBIN_U32("graphics/battle_anims/sprites/seed_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Seed2[] = INCBIN_U32("graphics/battle_anims/sprites/seed_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Sprout[] = INCBIN_U32("graphics/battle_anims/sprites/sprout.4bpp.lz");

const u32 gBattleAnimSpriteSheet_RedWand[] = INCBIN_U32("graphics/battle_anims/sprites/red_wand.4bpp.lz");
const u32 gBattleAnimSpritePalette_RedWand[] = INCBIN_U32("graphics/battle_anims/sprites/red_wand.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PurpleGreenUnk[] = INCBIN_U32("graphics/battle_anims/sprites/purple_green_unk.4bpp.lz");
const u32 gBattleAnimSpritePalette_PurpleGreenUnk[] = INCBIN_U32("graphics/battle_anims/sprites/purple_green_unk.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WaterColumn[] = INCBIN_U32("graphics/battle_anims/sprites/water_column.4bpp.lz");
const u32 gBattleAnimSpritePalette_WaterColumn[] = INCBIN_U32("graphics/battle_anims/sprites/water_column.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MudUnk[] = INCBIN_U32("graphics/battle_anims/sprites/mud_unk.4bpp.lz");
const u32 gBattleAnimSpritePalette_MudUnk[] = INCBIN_U32("graphics/battle_anims/sprites/mud_unk.gbapal.lz");

const u32 gUnusedTilemap_BlueFrame[] = INCBIN_U32("graphics/unused/blue_frame.bin.lz"); // P1, P2, P3 and P4 tilemaps?
const u32 gUnusedTilemap_RedYellowGreenFrame[] = INCBIN_U32("graphics/unused/redyellowgreen_frame.bin.lz");
const u32 gUnusedGfx_ColorFrames[] = INCBIN_U32("graphics/unused/color_frames.4bpp.lz");
const u32 gUnusedPal_ColorFrames[] = INCBIN_U32("graphics/unused/color_frames.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RainDrops[] = INCBIN_U32("graphics/battle_anims/sprites/rain_drops.4bpp.lz");

const u32 gUnusedGfx8bpp_WaterSplash [] = INCBIN_U32("graphics/unused/water_splash.8bpp.lz");
const u32 gUnusedTilemap_WaterSplash[] = INCBIN_U32("graphics/unused/water_splash.bin.lz");
const u32 gUnusedPalette_WaterSplash[] = INCBIN_U32("graphics/unused/water_splash.gbapal.lz");

const u32 gUnusedGfx_BasicFrame[] = INCBIN_U32("graphics/unused/basic_frame.4bpp.lz");
const u32 gUnusedPal_BasicFrame[] = INCBIN_U32("graphics/unused/basic_frame.gbapal.lz");
const u32 gUnusedTilemap_BasicFrame[] = INCBIN_U32("graphics/unused/basic_frame.bin.lz");

// Battle Interface

const u16 gBattleInterface_BallStatusBarPal[] = INCBIN_U16("graphics/battle_interface/ball_status_bar.gbapal");

const u16 gBattleInterface_BallDisplayPal[] = INCBIN_U16("graphics/battle_interface/ball_display.gbapal");

//Originally an array?
const u8 gHealthboxElementsGfxTable[] = INCBIN_U8("graphics/battle_interface/hpbar.4bpp");
const u8 gHealthboxElementsGfxTable_ExpBar[] = INCBIN_U8("graphics/battle_interface/expbar.4bpp");
const u8 gHealthboxElementsGfxTable_StatusPsn[] = INCBIN_U8("graphics/battle_interface/status_psn.4bpp");
const u8 gHealthboxElementsGfxTable_StatusPar[] = INCBIN_U8("graphics/battle_interface/status_par.4bpp");
const u8 gHealthboxElementsGfxTable_StatusSlp[] = INCBIN_U8("graphics/battle_interface/status_slp.4bpp");
const u8 gHealthboxElementsGfxTable_StatusFrz[] = INCBIN_U8("graphics/battle_interface/status_frz.4bpp");
const u8 gHealthboxElementsGfxTable_StatusBrn[] = INCBIN_U8("graphics/battle_interface/status_brn.4bpp");
const u8 gHealthboxElementsGfxTable_Misc[] = INCBIN_U8("graphics/battle_interface/misc.4bpp");
const u8 gHealthboxElementsGfxTable_HpBarAnim[] = INCBIN_U8("graphics/battle_interface/hpbar_anim.4bpp");
const u8 gHealthboxElementsGfxTable_MiscFrameEnd[] = INCBIN_U8("graphics/battle_interface/misc_frameend.4bpp");

const u8 gBattleInterface_BallDisplayGfx[] = INCBIN_U8("graphics/battle_interface/ball_display.4bpp");

//Originally an array?
const u8 gUnknown_08C1249C[] = INCBIN_U8("graphics/battle_interface/ball_display_unused_extra.4bpp");
const u8 gBattleInterfaceGfx_Status2[] = INCBIN_U8("graphics/battle_interface/status2.4bpp"); // these three duplicate sets of graphics are for the opponent pokemon
const u8 gBattleInterfaceGfx_Status3[] = INCBIN_U8("graphics/battle_interface/status3.4bpp"); // and are also for use in double battles. they use dynamic palettes so
const u8 gBattleInterfaceGfx_Status4[] = INCBIN_U8("graphics/battle_interface/status4.4bpp"); // coloring them is an extreme headache and wont be done for now
const u8 gUnknown_D12FEC[] = INCBIN_U8("graphics/unknown/unknown_D12FEC.4bpp");
const u8 gUnknown_D1300C[] = INCBIN_U8("graphics/unknown/unknown_D1300C.4bpp");
const u32 gBattleInterfaceGfx_UnusedWindow3[] = INCBIN_U32("graphics/battle_interface/unused_window3.4bpp.lz");
const u32 gBattleInterfaceGfx_UnusedWindow4[] = INCBIN_U32("graphics/battle_interface/unused_window4.4bpp.lz");

const u32 gBattleAnimSpriteSheet_FurySwipes[] = INCBIN_U32("graphics/battle_anims/sprites/fury_swipes.4bpp.lz");
const u32 gBattleAnimSpritePalette_FurySwipes[] = INCBIN_U32("graphics/battle_anims/sprites/fury_swipes.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Vine2[] = INCBIN_U32("graphics/battle_anims/sprites/vine_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Vine2[] = INCBIN_U32("graphics/battle_anims/sprites/vine_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Teeth[] = INCBIN_U32("graphics/battle_anims/sprites/teeth.4bpp.lz");
const u32 gBattleAnimSpritePalette_Teeth[] = INCBIN_U32("graphics/battle_anims/sprites/teeth.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Bone2[] = INCBIN_U32("graphics/battle_anims/sprites/bone_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Bone2[] = INCBIN_U32("graphics/battle_anims/sprites/bone_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WhiteBag[] = INCBIN_U32("graphics/battle_anims/sprites/white_bag.4bpp.lz");
const u32 gBattleAnimSpritePalette_WhiteBag[] = INCBIN_U32("graphics/battle_anims/sprites/white_bag.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Unknown[] = INCBIN_U32("graphics/battle_anims/sprites/unknown.4bpp.lz");
const u32 gBattleAnimSpritePalette_Unknown[] = INCBIN_U32("graphics/battle_anims/sprites/unknown.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PurpleCoral[] = INCBIN_U32("graphics/battle_anims/sprites/purple_coral.4bpp.lz");
const u32 gBattleAnimSpritePalette_PurpleCoral[] = INCBIN_U32("graphics/battle_anims/sprites/purple_coral.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PurpleDroplet[] = INCBIN_U32("graphics/battle_anims/sprites/purple_droplet.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Shock2[] = INCBIN_U32("graphics/battle_anims/sprites/shock_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_Shock2[] = INCBIN_U32("graphics/battle_anims/sprites/shock_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_ClosingEye2[] = INCBIN_U32("graphics/battle_anims/sprites/closing_eye_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_ClosingEye2[] = INCBIN_U32("graphics/battle_anims/sprites/closing_eye_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MetalBall[] = INCBIN_U32("graphics/battle_anims/sprites/metal_ball.4bpp.lz");
const u32 gBattleAnimSpritePalette_MetalBall[] = INCBIN_U32("graphics/battle_anims/sprites/metal_ball.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MonsterDoll[] = INCBIN_U32("graphics/battle_anims/sprites/monster_doll.4bpp.lz");
const u32 gBattleAnimSpritePalette_MonsterDoll[] = INCBIN_U32("graphics/battle_anims/sprites/monster_doll.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Whirlwind[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind.4bpp.lz");
const u32 gBattleAnimSpritePalette_Whirlwind[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Whirlwind2[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind_2.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Explosion4[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_4.4bpp.lz");
const u32 gBattleAnimSpritePalette_Explosion4[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_4.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Explosion5[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_5.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Tongue[] = INCBIN_U32("graphics/battle_anims/sprites/tongue.4bpp.lz");
const u32 gBattleAnimSpritePalette_Tongue[] = INCBIN_U32("graphics/battle_anims/sprites/tongue.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Smoke[] = INCBIN_U32("graphics/battle_anims/sprites/smoke.4bpp.lz");
const u32 gBattleAnimSpritePalette_Smoke[] = INCBIN_U32("graphics/battle_anims/sprites/smoke.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Smoke2[] = INCBIN_U32("graphics/battle_anims/sprites/smoke_2.4bpp.lz");

const u32 gBattleAnimSpriteSheet_BlueFlames[] = INCBIN_U32("graphics/battle_anims/sprites/blue_flames.4bpp.lz");
const u32 gBattleAnimSpritePalette_BlueFlames[] = INCBIN_U32("graphics/battle_anims/sprites/blue_flames.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BlueFlames2[] = INCBIN_U32("graphics/battle_anims/sprites/blue_flames_2.4bpp.lz");

// Contest

const u32 gUnusedGfx_OldContest[] = INCBIN_U32("graphics/unused/old_contest.4bpp.lz");
const u32 gUnusedPal_OldContest[] = INCBIN_U32("graphics/unused/old_contest.gbapal.lz");
const u32 gUnusedTilemap_OldContest[] = INCBIN_U32("graphics/unused/old_contest.bin.lz");

const u32 gUnknownTilemap_C15BC0[] = INCBIN_U32("graphics/unknown/unknown_C15BC0.bin.lz");

const u32 gUnusedGfx_OldContest2[] = INCBIN_U32("graphics/unused/old_contest_2.4bpp.lz");
const u32 gUnknown_08C16E90[] = INCBIN_U32("graphics/unused/old_contest_2.gbapal.lz");
const u32 gUnknown_08C16FA8[] = INCBIN_U32("graphics/unused/old_contest_2.bin.lz");

const u32 gUnknown_08C17170[] = INCBIN_U32("graphics/unknown/unknown_C17170.bin.lz");

const u32 gUnknown_08C17410[] = INCBIN_U32("graphics/unknown/unknown_C17410.bin.lz");

const u32 gUnknown_08C1751C[] = INCBIN_U32("graphics/unknown/unknown_C1751C.bin.lz");

const u32 gUnknown_08C17980[] = INCBIN_U32("graphics/unknown/unknown_C17980.bin.lz");

const u32 gContestMiscGfx[] = INCBIN_U32("graphics/contest/misc.4bpp.lz");

const u32 gContestAudienceGfx[] = INCBIN_U32("graphics/contest/audience.4bpp.lz");

const u32 gUnknown_08C19168[] = INCBIN_U32("graphics/contest/faces.4bpp.lz");

const u32 gContestJudgeSymbolsGfx[] = INCBIN_U32("graphics/contest/judge_symbols.4bpp.lz");
const u32 gContest3Pal[] = INCBIN_U32("graphics/contest/judge_symbols.gbapal.lz");

const u8 gTiles_8C19450[] = INCBIN_U8("graphics/contest/heart.4bpp");

const u32 gUnknownGfx_C19470[] = INCBIN_U32("graphics/unknown/unknown_C19470.4bpp.lz");
const u32 gUnknownPal_C19470[] = INCBIN_U32("graphics/unknown/unknown_C19470.gbapal.lz");

const u32 gUnknown_08C19588[] = INCBIN_U32("graphics/contest/misc_2.4bpp.lz");

const u32 gUnknown_08C19EEC[] = INCBIN_U32("graphics/contest/misc_2_tilemap_1.bin.lz");
const u32 gUnknown_08C1A000[] = INCBIN_U32("graphics/contest/misc_2_tilemap_2.bin.lz");
const u32 gUnknown_08C1A12C[] = INCBIN_U32("graphics/contest/misc_2_tilemap_3.bin.lz");

const u32 gUnknown_08C1A2B4[] = INCBIN_U32("graphics/contest/misc_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Impact[] = INCBIN_U32("graphics/battle_anims/sprites/impact.4bpp.lz");
const u32 gBattleAnimSpritePalette_Impact[] = INCBIN_U32("graphics/battle_anims/sprites/impact.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Particles[] = INCBIN_U32("graphics/battle_anims/sprites/particles.4bpp.lz");

const u32 gBattleAnimSpriteSheet_CircleImpact[] = INCBIN_U32("graphics/battle_anims/sprites/circle_impact.4bpp.lz");
const u32 gBattleAnimSpritePalette_CircleImpact[] = INCBIN_U32("graphics/battle_anims/sprites/circle_impact.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Scratch[] = INCBIN_U32("graphics/battle_anims/sprites/scratch.4bpp.lz");

const u32 gBattleAnimSpriteSheet_SharpTeeth[] = INCBIN_U32("graphics/battle_anims/sprites/sharp_teeth.4bpp.lz");
const u32 gBattleAnimSpritePalette_SharpTeeth[] = INCBIN_U32("graphics/battle_anims/sprites/sharp_teeth.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Clamp[] = INCBIN_U32("graphics/battle_anims/sprites/clamp.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Cut[] = INCBIN_U32("graphics/battle_anims/sprites/cut.4bpp.lz");

const u32 gBattleAnimSpriteSheet_RainbowRings[] = INCBIN_U32("graphics/battle_anims/sprites/rainbow_rings.4bpp.lz");
const u32 gBattleAnimSpritePalette_RainbowRings[] = INCBIN_U32("graphics/battle_anims/sprites/rainbow_rings.gbapal.lz");

const u32 gBattleAnimSpriteSheet_IceCrystals[] = INCBIN_U32("graphics/battle_anims/sprites/ice_crystals.4bpp.lz");
const u32 gBattleAnimSpritePalette_IceCrystals[] = INCBIN_U32("graphics/battle_anims/sprites/ice_crystals.gbapal.lz");

const u32 gBattleAnimSpriteSheet_IceSpikes[] = INCBIN_U32("graphics/battle_anims/sprites/ice_spikes.4bpp.lz");

const u32 gUnusedGfx_OldBeatUp[] = INCBIN_U32("graphics/unused/old_beatup.4bpp.lz");
const u32 gUnusedPal_OldBeatUp[] = INCBIN_U32("graphics/unused/old_beatup.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Orbs[] = INCBIN_U32("graphics/battle_anims/sprites/orbs.4bpp.lz");
const u32 gBattleAnimSpritePalette_Orbs[] = INCBIN_U32("graphics/battle_anims/sprites/orbs.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WaterOrb[] = INCBIN_U32("graphics/battle_anims/sprites/water_orb.4bpp.lz");

const u32 gBattleAnimSpriteSheet_WaterImpact[] = INCBIN_U32("graphics/battle_anims/sprites/water_impact.4bpp.lz");
const u32 gBattleAnimSpritePalette_WaterImpact[] = INCBIN_U32("graphics/battle_anims/sprites/water_impact.gbapal.lz");

const u32 gBattleAnimSpritePalette_BrownOrb[] = INCBIN_U32("graphics/battle_anims/sprites/brown_orb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MudSand[] = INCBIN_U32("graphics/battle_anims/sprites/mud_sand.4bpp.lz");
const u32 gBattleAnimSpritePalette_MudSand[] = INCBIN_U32("graphics/battle_anims/sprites/mud_sand.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PoisonBubble[] = INCBIN_U32("graphics/battle_anims/sprites/poison_bubble.4bpp.lz");
const u32 gBattleAnimSpritePalette_PoisonBubble[] = INCBIN_U32("graphics/battle_anims/sprites/poison_bubble.gbapal.lz");

const u32 gBattleAnimSpriteSheet_ToxicBubble[] = INCBIN_U32("graphics/battle_anims/sprites/toxic_bubble.4bpp.lz");

const u32 gBattleAnimSpriteSheet_HornHit2[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_HornHit2[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_AirWave2[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_AirWave2[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SmallBubbles[] = INCBIN_U32("graphics/battle_anims/sprites/small_bubbles.4bpp.lz");
const u32 gBattleAnimSpritePalette_SmallBubbles[] = INCBIN_U32("graphics/battle_anims/sprites/small_bubbles.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RoundShadow[] = INCBIN_U32("graphics/battle_anims/sprites/round_shadow.4bpp.lz");
const u32 gBattleAnimSpritePalette_RoundShadow[] = INCBIN_U32("graphics/battle_anims/sprites/round_shadow.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Sunlight[] = INCBIN_U32("graphics/battle_anims/sprites/sunlight.4bpp.lz");
const u32 gBattleAnimSpritePalette_Sunlight[] = INCBIN_U32("graphics/battle_anims/sprites/sunlight.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Spore[] = INCBIN_U32("graphics/battle_anims/sprites/spore.4bpp.lz");

const u32 gBattleAnimSpritePalette_Spore[] = INCBIN_U32("graphics/battle_anims/sprites/spore.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Flower[] = INCBIN_U32("graphics/battle_anims/sprites/flower.4bpp.lz");
const u32 gBattleAnimSpritePalette_Flower[] = INCBIN_U32("graphics/battle_anims/sprites/flower.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RazorLeaf[] = INCBIN_U32("graphics/battle_anims/sprites/razor_leaf.4bpp.lz");
const u32 gBattleAnimSpritePalette_RazorLeaf[] = INCBIN_U32("graphics/battle_anims/sprites/razor_leaf.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MistCloud[] = INCBIN_U32("graphics/battle_anims/sprites/mist_cloud.4bpp.lz");
const u32 gBattleAnimSpritePalette_MistCloud[] = INCBIN_U32("graphics/battle_anims/sprites/mist_cloud.gbapal.lz");

const u32 gUnknownGfx_D1C060[] = INCBIN_U32("graphics/unknown/unknown_D1C060.4bpp.lz");
const u32 gUnknownPal_D1C060[] = INCBIN_U32("graphics/unknown/unknown_D1C060.gbapal.lz");
const u32 gUnknownTilemap_D1C060[] = INCBIN_U32("graphics/unknown/unknown_D1C060.bin.lz");

const u32 gBattleAnimSpriteSheet_WhirlwindLines[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind_lines.4bpp.lz");
const u32 gBattleAnimSpritePalette_WhirlwindLines[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind_lines.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GoldRing[] = INCBIN_U32("graphics/battle_anims/sprites/gold_ring.4bpp.lz");
const u32 gBattleAnimSpritePalette_GoldRing[] = INCBIN_U32("graphics/battle_anims/sprites/gold_ring.gbapal.lz");

const u32 gBattleAnimSpritePalette_BlueRing2[] = INCBIN_U32("graphics/battle_anims/sprites/blue_ring_2.gbapal.lz");
const u32 gBattleAnimSpritePalette_PurpleRing[] = INCBIN_U32("graphics/battle_anims/sprites/purple_ring.gbapal.lz");
const u32 gBattleAnimSpritePalette_BlueRing[] = INCBIN_U32("graphics/battle_anims/sprites/blue_ring.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GreenLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/green_light_wall.4bpp.lz");
const u32 gBattleAnimSpritePalette_GreenLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/green_light_wall.gbapal.lz");

const u32 gBattleAnimSpritePalette_BlueLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/blue_light_wall.gbapal.lz");
const u32 gBattleAnimSpritePalette_RedLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/red_light_wall.gbapal.lz");
const u32 gBattleAnimSpritePalette_GrayLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/gray_light_wall.gbapal.lz");
const u32 gBattleAnimSpritePalette_OrangeLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/orange_light_wall.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BlackBall2[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_BlackBall2[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball_2.gbapal.lz");

const u32 gBattleAnimSpritePalette_PurpleGasCloud[] = INCBIN_U32("graphics/battle_anims/sprites/purple_gas_cloud.gbapal.lz");

const u32 gContestJudgeGfx[] = INCBIN_U32("graphics/contest/judge.4bpp.lz");
const u32 gContest2Pal[] = INCBIN_U32("graphics/contest/judge.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Spark[] = INCBIN_U32("graphics/battle_anims/sprites/spark.4bpp.lz");
const u32 gBattleAnimSpritePalette_Spark[] = INCBIN_U32("graphics/battle_anims/sprites/spark.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SparkH[] = INCBIN_U32("graphics/battle_anims/sprites/spark_h.4bpp.lz");

const u32 gBattleAnimBackgroundImage_00[] = INCBIN_U32("graphics/battle_anims/backgrounds/00.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_00[] = INCBIN_U32("graphics/battle_anims/backgrounds/00.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_00[] = INCBIN_U32("graphics/battle_anims/backgrounds/00.bin.lz");

const u32 gMetalShineGfx[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.4bpp.lz");
const u32 gMetalShinePalette[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.gbapal.lz");
const u32 gMetalShineTilemap[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.bin.lz");

const u32 gUnusedGfx_Goosuto[] = INCBIN_U32("graphics/unused/goosuto.4bpp.lz"); // ghost
const u32 gUnusedPal_Goosuto[] = INCBIN_U32("graphics/unused/goosuto.gbapal.lz");
const u32 gUnusedTilemap_Goosuto[] = INCBIN_U32("graphics/unused/goosuto.bin.lz");

const u32 gBattleAnimSpriteSheet_YellowStar[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_star.4bpp.lz");
const u32 gBattleAnimSpritePalette_YellowStar[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_star.gbapal.lz");

const u32 gBattleAnimSpriteSheet_LargeFreshEgg[] = INCBIN_U32("graphics/battle_anims/sprites/large_fresh_egg.4bpp.lz");
const u32 gBattleAnimSpritePalette_LargeFreshEgg[] = INCBIN_U32("graphics/battle_anims/sprites/large_fresh_egg.gbapal.lz");

const u32 gBattleAnimSpriteSheet_ShadowBall[] = INCBIN_U32("graphics/battle_anims/sprites/shadow_ball.4bpp.lz");
const u32 gBattleAnimSpritePalette_ShadowBall[] = INCBIN_U32("graphics/battle_anims/sprites/shadow_ball.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Lick[] = INCBIN_U32("graphics/battle_anims/sprites/lick.4bpp.lz");
const u32 gBattleAnimSpritePalette_Lick[] = INCBIN_U32("graphics/battle_anims/sprites/lick.gbapal.lz");

const u32 gBattleAnimSpriteSheet_VoidLines[] = INCBIN_U32("graphics/battle_anims/sprites/void_lines.4bpp.lz");
const u32 gBattleAnimSpritePalette_VoidLines[] = INCBIN_U32("graphics/battle_anims/sprites/void_lines.gbapal.lz");

const u32 gBattleAnimSpritePalette_String[] = INCBIN_U32("graphics/battle_anims/sprites/string.gbapal.lz");
const u32 gBattleAnimSpriteSheet_String[] = INCBIN_U32("graphics/battle_anims/sprites/string.4bpp.lz");

const u32 gBattleAnimSpriteSheet_WebThread[] = INCBIN_U32("graphics/battle_anims/sprites/web_thread.4bpp.lz");
const u32 gBattleAnimSpriteSheet_SpiderWeb[] = INCBIN_U32("graphics/battle_anims/sprites/spider_web.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Lightbulb[] = INCBIN_U32("graphics/battle_anims/sprites/lightbulb.4bpp.lz");
const u32 gBattleAnimSpritePalette_Lightbulb[] = INCBIN_U32("graphics/battle_anims/sprites/lightbulb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Slash[] = INCBIN_U32("graphics/battle_anims/sprites/slash.4bpp.lz");
const u32 gBattleAnimSpritePalette_Slash[] = INCBIN_U32("graphics/battle_anims/sprites/slash.gbapal.lz");

const u32 gBattleAnimSpriteSheet_FocusEnergy[] = INCBIN_U32("graphics/battle_anims/sprites/focus_energy.4bpp.lz");
const u32 gBattleAnimSpritePalette_FocusEnergy[] = INCBIN_U32("graphics/battle_anims/sprites/focus_energy.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SphereToCube[] = INCBIN_U32("graphics/battle_anims/sprites/sphere_to_cube.4bpp.lz");
const u32 gBattleAnimSpritePalette_SphereToCube[] = INCBIN_U32("graphics/battle_anims/sprites/sphere_to_cube.gbapal.lz");

const u32 gBattleAnimBackgroundImage_03[] = INCBIN_U32("graphics/battle_anims/backgrounds/03.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_03[] = INCBIN_U32("graphics/battle_anims/backgrounds/03.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_03[] = INCBIN_U32("graphics/battle_anims/backgrounds/03.bin.lz");

const u32 gBattleAnimSpriteSheet_Eye[] = INCBIN_U32("graphics/battle_anims/sprites/eye.4bpp.lz");
const u32 gBattleAnimSpritePalette_Eye[] = INCBIN_U32("graphics/battle_anims/sprites/eye.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Tendrils[] = INCBIN_U32("graphics/battle_anims/sprites/tendrils.4bpp.lz");
const u32 gBattleAnimSpritePalette_Tendrils[] = INCBIN_U32("graphics/battle_anims/sprites/tendrils.gbapal.lz");

const u32 gHealthboxSinglesPlayerGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_player.4bpp.lz");
const u32 gHealthboxSinglesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_opponent.4bpp.lz");
const u32 gHealthboxDoublesPlayerGfx[] = INCBIN_U32( "graphics/battle_interface/healthbox_doubles_player.4bpp.lz");
const u32 gHealthboxDoublesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_doubles_opponent.4bpp.lz");
const u32 gHealthboxSafariGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_safari.4bpp.lz");

const u32 gUnusedGfx_Shadow[] = INCBIN_U32("graphics/unused/shadow.4bpp.lz");
const u32 gUnusedPal_Shadow[] = INCBIN_U32("graphics/unused/shadow.gbapal.lz");

const u32 gBattleAnimSpriteSheet_LockOn[] = INCBIN_U32("graphics/battle_anims/sprites/lock_on.4bpp.lz");
const u32 gBattleAnimSpritePalette_LockOn[] = INCBIN_U32("graphics/battle_anims/sprites/lock_on.gbapal.lz");

const u32 gBattleAnimSpriteSheet_OpeningEye[] = INCBIN_U32("graphics/battle_anims/sprites/opening_eye.4bpp.lz");
const u32 gBattleAnimSpritePalette_OpeningEye[] = INCBIN_U32("graphics/battle_anims/sprites/opening_eye.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RoundWhiteHalo[] = INCBIN_U32("graphics/battle_anims/sprites/round_white_halo.4bpp.lz");
const u32 gBattleAnimSpritePalette_RoundWhiteHalo[] = INCBIN_U32("graphics/battle_anims/sprites/round_white_halo.gbapal.lz");

const u32 gBattleAnimSpriteSheet_TealAlert[] = INCBIN_U32("graphics/battle_anims/sprites/teal_alert.4bpp.lz");
const u32 gBattleAnimSpritePalette_TealAlert[] = INCBIN_U32("graphics/battle_anims/sprites/teal_alert.gbapal.lz");

const u32 gBattleAnimSpriteSheet_FangAttack[] = INCBIN_U32("graphics/battle_anims/sprites/fang_attack.4bpp.lz");
const u32 gBattleAnimSpritePalette_FangAttack[] = INCBIN_U32("graphics/battle_anims/sprites/fang_attack.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PurpleHandOutline[] = INCBIN_U32("graphics/battle_anims/sprites/purple_hand_outline.4bpp.lz");
const u32 gBattleAnimSpritePalette_PurpleHandOutline[] = INCBIN_U32("graphics/battle_anims/sprites/purple_hand_outline.gbapal.lz");

const u32 gUnknown_08C20668[] = INCBIN_U32("graphics/battle_anims/masks/curse.4bpp.lz");
const u32 gUnknown_08C20684[] = INCBIN_U32("graphics/battle_anims/masks/curse.bin.lz");

const u32 gBattleAnimSpriteSheet_Pencil[] = INCBIN_U32("graphics/battle_anims/sprites/pencil.4bpp.lz");
const u32 gBattleAnimSpritePalette_Pencil[] = INCBIN_U32("graphics/battle_anims/sprites/pencil.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Spiral[] = INCBIN_U32("graphics/battle_anims/sprites/spiral.4bpp.lz");
const u32 gBattleAnimSpritePalette_Spiral[] = INCBIN_U32("graphics/battle_anims/sprites/spiral.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Moon[] = INCBIN_U32("graphics/battle_anims/sprites/moon.4bpp.lz");
const u32 gBattleAnimSpritePalette_Moon[] = INCBIN_U32("graphics/battle_anims/sprites/moon.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GreenSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/green_sparkle.4bpp.lz");
const u32 gBattleAnimSpritePalette_GreenSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/green_sparkle.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SnoreZ[] = INCBIN_U32("graphics/battle_anims/sprites/snore_z.4bpp.lz");
const u32 gBattleAnimSpritePalette_SnoreZ[] = INCBIN_U32("graphics/battle_anims/sprites/snore_z.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Explosion[] = INCBIN_U32("graphics/battle_anims/sprites/explosion.4bpp.lz");
const u32 gBattleAnimSpritePalette_Explosion[] = INCBIN_U32("graphics/battle_anims/sprites/explosion.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Nail[] = INCBIN_U32("graphics/battle_anims/sprites/nail.4bpp.lz");
const u32 gBattleAnimSpritePalette_Nail[] = INCBIN_U32("graphics/battle_anims/sprites/nail.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GhostlySpirit[] = INCBIN_U32("graphics/battle_anims/sprites/ghostly_spirit.4bpp.lz");
const u32 gBattleAnimSpritePalette_GhostlySpirit[] = INCBIN_U32("graphics/battle_anims/sprites/ghostly_spirit.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WarmRock[] = INCBIN_U32("graphics/battle_anims/sprites/warm_rock.4bpp.lz");
const u32 gBattleAnimSpritePalette_WarmRock[] = INCBIN_U32("graphics/battle_anims/sprites/warm_rock.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PunchImpact[] = INCBIN_U32("graphics/battle_anims/sprites/punch_impact.4bpp.lz");
const u32 gBattleAnimSpritePalette_PunchImpact[] = INCBIN_U32("graphics/battle_anims/sprites/punch_impact.gbapal.lz");

const u32 gBattleAnimSpriteSheet_BreakingEgg[] = INCBIN_U32("graphics/battle_anims/sprites/breaking_egg.4bpp.lz");
const u32 gBattleAnimSpritePalette_BreakingEgg[] = INCBIN_U32("graphics/battle_anims/sprites/breaking_egg.gbapal.lz");

const u32 gBattleAnimSpriteSheet_ThinRing[] = INCBIN_U32("graphics/battle_anims/sprites/thin_ring.4bpp.lz");
const u32 gBattleAnimSpritePalette_ThinRing[] = INCBIN_U32("graphics/battle_anims/sprites/thin_ring.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MusicNotes2[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes_2.4bpp.lz");
const u32 gBattleAnimSpritePalette_MusicNotes2[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Bell[] = INCBIN_U32("graphics/battle_anims/sprites/bell.4bpp.lz");
const u32 gBattleAnimSpritePalette_Bell[] = INCBIN_U32("graphics/battle_anims/sprites/bell.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SpeedDust[] = INCBIN_U32("graphics/battle_anims/sprites/speed_dust.4bpp.lz");
const u32 gBattleAnimSpritePalette_SpeedDust[] = INCBIN_U32("graphics/battle_anims/sprites/speed_dust.gbapal.lz");

const u32 gBattleAnimSpriteSheet_TornMetal[] = INCBIN_U32("graphics/battle_anims/sprites/torn_metal.4bpp.lz");

const u32 gBattleAnimSpriteSheet_ThoughtBubble[] = INCBIN_U32("graphics/battle_anims/sprites/thought_bubble.4bpp.lz");
const u32 gBattleAnimSpritePalette_ThoughtBubble[] = INCBIN_U32("graphics/battle_anims/sprites/thought_bubble.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Finger[] = INCBIN_U32("graphics/battle_anims/sprites/finger.4bpp.lz");
const u32 gBattleAnimSpritePalette_Finger[] = INCBIN_U32("graphics/battle_anims/sprites/finger.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MagentaHeart[] = INCBIN_U32("graphics/battle_anims/sprites/magenta_heart.4bpp.lz");

const u32 gBattleAnimSpritePalette_PinkHeart[] = INCBIN_U32("graphics/battle_anims/sprites/pink_heart.gbapal.lz");
const u32 gBattleAnimSpritePalette_MagentaHeart[] = INCBIN_U32("graphics/battle_anims/sprites/magenta_heart.gbapal.lz");
const u32 gBattleAnimSpritePalette_RedHeart[] = INCBIN_U32("graphics/battle_anims/sprites/red_heart.gbapal.lz");

const u32 gUnknown_08C232E0[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.4bpp.lz");
const u32 gUnknown_08C23D50[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.gbapal.lz");
const u32 gUnknown_08C23D78[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.bin.lz");

const u32 gBattleAnimSpriteSheet_RedOrb[] = INCBIN_U32("graphics/battle_anims/sprites/red_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_RedOrb[] = INCBIN_U32("graphics/battle_anims/sprites/red_orb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_CircleOfLight[] = INCBIN_U32("graphics/battle_anims/sprites/circle_of_light.4bpp.lz");
const u32 gBattleAnimSpriteSheet_ElectricOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/electric_orbs.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Electricity[] = INCBIN_U32("graphics/battle_anims/sprites/electricity.4bpp.lz");

const u32 gBattleAnimSpritePalette_ElectricOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/electric_orbs.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Finger2[] = INCBIN_U32("graphics/battle_anims/sprites/finger_2.4bpp.lz");

const u32 gBattleAnimSpriteSheet_MovementWaves[] = INCBIN_U32("graphics/battle_anims/sprites/movement_waves.4bpp.lz");
const u32 gBattleAnimSpritePalette_MovementWaves[] = INCBIN_U32("graphics/battle_anims/sprites/movement_waves.gbapal.lz");

const u32 gUnknown_08C249D0[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.gbapal.lz");
const u32 gUnknown_08C249F8[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.4bpp.lz");

const u32 gBattleAnimSpritePalette_EyeSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/eye_sparkle.gbapal.lz");
const u32 gBattleAnimSpriteSheet_EyeSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/eye_sparkle.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Anger[] = INCBIN_U32("graphics/battle_anims/sprites/anger.4bpp.lz");
const u32 gBattleAnimSpritePalette_Anger[] = INCBIN_U32("graphics/battle_anims/sprites/anger.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Conversion[] = INCBIN_U32("graphics/battle_anims/sprites/conversion.4bpp.lz");
const u32 gBattleAnimSpritePalette_Conversion[] = INCBIN_U32("graphics/battle_anims/sprites/conversion.gbapal.lz");

const u32 gBattleAnimSpritePalette_Angel[] = INCBIN_U32("graphics/battle_anims/sprites/angel.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Angel[] = INCBIN_U32("graphics/battle_anims/sprites/angel.4bpp.lz");

const u32 gBattleAnimSpritePalette_Devil[] = INCBIN_U32("graphics/battle_anims/sprites/devil.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Devil[] = INCBIN_U32("graphics/battle_anims/sprites/devil.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Swipe[] = INCBIN_U32("graphics/battle_anims/sprites/swipe.4bpp.lz");
const u32 gBattleAnimSpritePalette_Swipe[] = INCBIN_U32("graphics/battle_anims/sprites/swipe.gbapal.lz");

const u32 gBattleAnimSpritePalette_Roots[] = INCBIN_U32("graphics/battle_anims/sprites/roots.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Roots[] = INCBIN_U32("graphics/battle_anims/sprites/roots.4bpp.lz");

const u32 gBattleAnimSpritePalette_ItemBag[] = INCBIN_U32("graphics/battle_anims/sprites/item_bag.gbapal.lz");
const u32 gBattleAnimSpriteSheet_ItemBag[] = INCBIN_U32("graphics/battle_anims/sprites/item_bag.4bpp.lz");

const u32 gBattleAnimSpritePalette_TriForceTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/tri_force_triangle.gbapal.lz");
const u32 gBattleAnimSpriteSheet_TriForceTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/tri_force_triangle.4bpp.lz");

const u32 gBattleAnimSpritePalette_LetterZ[] = INCBIN_U32("graphics/battle_anims/sprites/letter_z.gbapal.lz");
const u32 gBattleAnimSpriteSheet_LetterZ[] = INCBIN_U32("graphics/battle_anims/sprites/letter_z.4bpp.lz");

const u32 gBattleAnimBackgroundPalette_04[] = INCBIN_U32("graphics/battle_anims/backgrounds/04.gbapal.lz");
const u32 gBattleAnimBackgroundImage_04[] = INCBIN_U32("graphics/battle_anims/backgrounds/04.4bpp.lz");
const u32 gBattleAnimBackgroundTilemap_04[] = INCBIN_U32("graphics/battle_anims/backgrounds/04.bin.lz");

const u32 gBattleAnimBackgroundTilemap_05[] = INCBIN_U32("graphics/battle_anims/backgrounds/05.bin.lz");
const u32 gBattleAnimBackgroundTilemap_06[] = INCBIN_U32("graphics/battle_anims/backgrounds/06.bin.lz");

const u32 gBattleAnimSpriteSheet_JaggedMusicNote[] = INCBIN_U32("graphics/battle_anims/sprites/jagged_music_note.4bpp.lz");
const u32 gBattleAnimSpritePalette_JaggedMusicNote[] = INCBIN_U32("graphics/battle_anims/sprites/jagged_music_note.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Spotlight[] = INCBIN_U32("graphics/battle_anims/sprites/spotlight.4bpp.lz");

const u32 gBattleAnimSpriteSheet_Pokeball[] = INCBIN_U32("graphics/battle_anims/sprites/pokeball.4bpp.lz");
const u32 gBattleAnimSpritePalette_Pokeball[] = INCBIN_U32("graphics/battle_anims/sprites/pokeball.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RapidSpin[] = INCBIN_U32("graphics/battle_anims/sprites/rapid_spin.4bpp.lz");
const u32 gBattleAnimSpritePalette_RapidSpin[] = INCBIN_U32("graphics/battle_anims/sprites/rapid_spin.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MilkBottle[] = INCBIN_U32("graphics/battle_anims/sprites/milk_bottle.4bpp.lz");
const u32 gBattleAnimSpritePalette_MilkBottle[] = INCBIN_U32("graphics/battle_anims/sprites/milk_bottle.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WispFire[] = INCBIN_U32("graphics/battle_anims/sprites/wisp_fire.4bpp.lz");

const u32 gBattleAnimSpritePalette_WispOrb[] = INCBIN_U32("graphics/battle_anims/sprites/wisp_orb.gbapal.lz");
const u32 gBattleAnimSpriteSheet_WispOrb[] = INCBIN_U32("graphics/battle_anims/sprites/wisp_orb.4bpp.lz");

const u32 gBattleAnimSpriteSheet_GoldStars[] = INCBIN_U32("graphics/battle_anims/sprites/gold_stars.4bpp.lz");
const u32 gBattleAnimSpritePalette_GoldStars[] = INCBIN_U32("graphics/battle_anims/sprites/gold_stars.gbapal.lz");

const u32 gBattleAnimSpriteSheet_EclipsingOrb[] = INCBIN_U32("graphics/battle_anims/sprites/eclipsing_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_EclipsingOrb[] = INCBIN_U32("graphics/battle_anims/sprites/eclipsing_orb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PinkPetal[] = INCBIN_U32("graphics/battle_anims/sprites/pink_petal.4bpp.lz");
const u32 gBattleAnimSpritePalette_PinkPetal[] = INCBIN_U32("graphics/battle_anims/sprites/pink_petal.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GrayOrb[] = INCBIN_U32("graphics/battle_anims/sprites/gray_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_GrayOrb[] = INCBIN_U32("graphics/battle_anims/sprites/gray_orb.gbapal.lz");

const u32 gBattleAnimSpritePalette_BlueOrb[] = INCBIN_U32("graphics/battle_anims/sprites/blue_orb.gbapal.lz");
const u32 gBattleAnimSpritePalette_RedOrb2[] = INCBIN_U32("graphics/battle_anims/sprites/red_orb_2.gbapal.lz");

const u32 gBattleAnimBackgroundImage_07[] = INCBIN_U32("graphics/battle_anims/backgrounds/07.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_07[] = INCBIN_U32("graphics/battle_anims/backgrounds/07.gbapal.lz");

const u32 gBattleAnimBackgroundPalette_18[] = INCBIN_U32("graphics/battle_anims/backgrounds/18.gbapal.lz");

const u32 gBattleAnimBackgroundTilemap_07[] = INCBIN_U32("graphics/battle_anims/backgrounds/07.bin.lz");
const u32 gBattleAnimBackgroundTilemap_08[] = INCBIN_U32("graphics/battle_anims/backgrounds/08.bin.lz");

const u32 gBattleAnimBackgroundImage_20[] = INCBIN_U32("graphics/battle_anims/backgrounds/20.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_20[] = INCBIN_U32("graphics/battle_anims/backgrounds/20.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_20[] = INCBIN_U32("graphics/battle_anims/backgrounds/20.bin.lz");

const u32 gBattleAnimBackgroundTilemap_09[] = INCBIN_U32("graphics/battle_anims/backgrounds/09.bin.lz");
const u32 gBattleAnimBackgroundPalette_09[] = INCBIN_U32("graphics/battle_anims/backgrounds/09.gbapal.lz");

const u32 gBattleAnimBackgroundPalette_22[] = INCBIN_U32("graphics/battle_anims/backgrounds/22.gbapal.lz");

const u32 gBattleAnimBackgroundImage_09[] = INCBIN_U32("graphics/battle_anims/backgrounds/09.4bpp.lz");
const u32 gBattleAnimBackgroundTilemap_10[] = INCBIN_U32("graphics/battle_anims/backgrounds/10.bin.lz");

const u32 gUnknown_08C2A634[] = INCBIN_U32("graphics/battle_anims/masks/morning_sun.4bpp.lz");
const u32 gUnknown_08C2A6D4[] = INCBIN_U32("graphics/battle_anims/masks/morning_sun.gbapal.lz");
const u32 gUnknown_08C2A6EC[] = INCBIN_U32("graphics/battle_anims/masks/morning_sun.bin.lz");

const u32 gBattleAnimBackgroundTilemap_12[] = INCBIN_U32("graphics/battle_anims/backgrounds/12.bin.lz");
const u32 gBattleAnimBackgroundTilemap_13[] = INCBIN_U32("graphics/battle_anims/backgrounds/13.bin.lz");
const u32 gBattleAnimBackgroundTilemap_14[] = INCBIN_U32("graphics/battle_anims/backgrounds/14.bin.lz");

const u32 gBattleAnimBackgroundImage_12[] = INCBIN_U32("graphics/battle_anims/backgrounds/12.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_12[] = INCBIN_U32("graphics/battle_anims/backgrounds/12.gbapal.lz");

const u32 gBattleAnimBackgroundImage_11[] = INCBIN_U32("graphics/battle_anims/backgrounds/11.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_11[] = INCBIN_U32("graphics/battle_anims/backgrounds/11.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_11[] = INCBIN_U32("graphics/battle_anims/backgrounds/11.bin.lz");

const u32 gBattleAnimSpriteSheet_PainSplit[] = INCBIN_U32("graphics/battle_anims/sprites/pain_split.4bpp.lz");
const u32 gBattleAnimSpritePalette_PainSplit[] = INCBIN_U32("graphics/battle_anims/sprites/pain_split.gbapal.lz");

const u32 gBattleAnimSpriteSheet_HandsAndFeet[] = INCBIN_U32("graphics/battle_anims/sprites/hands_and_feet.4bpp.lz");
const u32 gBattleAnimSpritePalette_HandsAndFeet[] = INCBIN_U32("graphics/battle_anims/sprites/hands_and_feet.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Confetti[] = INCBIN_U32("graphics/battle_anims/sprites/confetti.4bpp.lz");
const u32 gBattleAnimSpritePalette_Confetti[] = INCBIN_U32("graphics/battle_anims/sprites/confetti.gbapal.lz");

const u32 gSubstituteDollPal[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.gbapal.lz");
const u32 gSubstituteDollGfx[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.4bpp.lz");
const u32 gSubstituteDollTilemap[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.bin.lz");

const u32 gBattleAnimSpriteSheet_GreenStar[] = INCBIN_U32("graphics/battle_anims/sprites/green_star.4bpp.lz");
const u32 gBattleAnimSpritePalette_GreenStar[] = INCBIN_U32("graphics/battle_anims/sprites/green_star.gbapal.lz");

const u32 gContestConfetti_Gfx[] = INCBIN_U32("graphics/misc/confetti.4bpp.lz");
const u32 gContestConfetti_Pal[] = INCBIN_U32("graphics/misc/confetti.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PinkCloud[] = INCBIN_U32("graphics/battle_anims/sprites/pink_cloud.4bpp.lz");
const u32 gBattleAnimSpritePalette_PinkCloud[] = INCBIN_U32("graphics/battle_anims/sprites/pink_cloud.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SweatDrop[] = INCBIN_U32("graphics/battle_anims/sprites/sweat_drop.4bpp.lz");
const u32 gBattleAnimSpritePalette_SweatDrop[] = INCBIN_U32("graphics/battle_anims/sprites/sweat_drop.gbapal.lz");

const u32 gBattleStatMask_Gfx[] = INCBIN_U32("graphics/battle_anims/masks/stat.4bpp.lz");
const u32 gBattleStatMask1_Tilemap[] = INCBIN_U32("graphics/battle_anims/masks/stat_tilemap_1.bin.lz");
const u32 gBattleStatMask2_Tilemap[] = INCBIN_U32("graphics/battle_anims/masks/stat_tilemap_2.bin.lz");

const u32 gBattleStatMask1_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat1.gbapal.lz");
const u32 gBattleStatMask2_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat2.gbapal.lz");
const u32 gBattleStatMask3_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat3.gbapal.lz");
const u32 gBattleStatMask4_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat4.gbapal.lz");
const u32 gBattleStatMask5_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat5.gbapal.lz");
const u32 gBattleStatMask6_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat6.gbapal.lz");
const u32 gBattleStatMask7_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat7.gbapal.lz");
const u32 gBattleStatMask8_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat8.gbapal.lz");

const u32 gCureBubblesGfx[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.4bpp.lz");
const u32 gCureBubblesPal[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.gbapal.lz");
const u32 gCureBubblesTilemap[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.bin.lz");

const u32 gBattleAnimSpritePalette_PurpleScratch[] = INCBIN_U32("graphics/battle_anims/sprites/purple_scratch.gbapal.lz");
const u32 gBattleAnimSpriteSheet_PurpleScratch[] = INCBIN_U32("graphics/battle_anims/sprites/purple_scratch.4bpp.lz");

const u32 gBattleAnimSpriteSheet_PurpleSwipe[] = INCBIN_U32("graphics/battle_anims/sprites/purple_swipe.4bpp.lz");

const u32 gBattleAnimSpriteSheet_GuardRing[] = INCBIN_U32("graphics/battle_anims/sprites/guard_ring.4bpp.lz");
const u32 gBattleAnimSpritePalette_GuardRing[] = INCBIN_U32("graphics/battle_anims/sprites/guard_ring.gbapal.lz");

const u32 gBattleAnimSpriteSheet_TagHand[] = INCBIN_U32("graphics/battle_anims/sprites/tag_hand.4bpp.lz");

const u32 gBattleAnimSpriteSheet_NoiseLine[] = INCBIN_U32("graphics/battle_anims/sprites/noise_line.4bpp.lz");

const u32 gUnknown_08C2EA50[] = INCBIN_U32("graphics/battle_anims/masks/unknown_C2EA50.4bpp.lz");
const u32 gUnknown_08C2EA9C[] = INCBIN_U32("graphics/battle_anims/masks/unknown_C2EA50.bin.lz");

const u32 gBattleAnimSpriteSheet_SmallRedEye[] = INCBIN_U32("graphics/battle_anims/sprites/small_red_eye.4bpp.lz");
const u32 gBattleAnimSpritePalette_SmallRedEye[] = INCBIN_U32("graphics/battle_anims/sprites/small_red_eye.gbapal.lz");

const u32 gBattleAnimSpriteSheet_HollowOrb[] = INCBIN_U32("graphics/battle_anims/sprites/hollow_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_HollowOrb[] = INCBIN_U32("graphics/battle_anims/sprites/hollow_orb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_XSign[] = INCBIN_U32("graphics/battle_anims/sprites/x_sign.4bpp.lz");

const u32 gBattleAnimSpriteSheet_BluegreenOrb[] = INCBIN_U32("graphics/battle_anims/sprites/bluegreen_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_BluegreenOrb[] = INCBIN_U32("graphics/battle_anims/sprites/bluegreen_orb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PawPrint[] = INCBIN_U32("graphics/battle_anims/sprites/paw_print.4bpp.lz");
const u32 gBattleAnimSpritePalette_PawPrint[] = INCBIN_U32("graphics/battle_anims/sprites/paw_print.gbapal.lz");

const u32 gBattleAnimSpriteSheet_PurpleFlame[] = INCBIN_U32("graphics/battle_anims/sprites/purple_flame.4bpp.lz");
const u32 gBattleAnimSpritePalette_PurpleFlame[] = INCBIN_U32("graphics/battle_anims/sprites/purple_flame.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RedBall[] = INCBIN_U32("graphics/battle_anims/sprites/red_ball.4bpp.lz");
const u32 gBattleAnimSpritePalette_RedBall[] = INCBIN_U32("graphics/battle_anims/sprites/red_ball.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SmellingsaltEffect[] = INCBIN_U32("graphics/battle_anims/sprites/smellingsalt_effect.4bpp.lz");
const u32 gBattleAnimSpritePalette_SmellingsaltEffect[] = INCBIN_U32("graphics/battle_anims/sprites/smellingsalt_effect.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MagnifyingGlass[] = INCBIN_U32("graphics/battle_anims/sprites/magnifying_glass.4bpp.lz");
const u32 gBattleAnimSpritePalette_MagnifyingGlass[] = INCBIN_U32("graphics/battle_anims/sprites/magnifying_glass.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Meteor[] = INCBIN_U32("graphics/battle_anims/sprites/meteor.4bpp.lz");
const u32 gBattleAnimSpritePalette_Meteor[] = INCBIN_U32("graphics/battle_anims/sprites/meteor.gbapal.lz");

const u32 gBattleAnimSpriteSheet_FlatRock[] = INCBIN_U32("graphics/battle_anims/sprites/flat_rock.4bpp.lz");
const u32 gBattleAnimSpritePalette_FlatRock[] = INCBIN_U32("graphics/battle_anims/sprites/flat_rock.gbapal.lz");

const u32 gUnknownPal_C2F9E0[] = INCBIN_U32("graphics/unknown/unknown_C2F9E0.gbapal.lz");

#include "data/graphics/pokemon.h"
#include "data/graphics/trainers.h"

const u8 gMonIcon_QuestionMark[] = INCBIN_U8("graphics/pokemon/question_mark/icon.4bpp");
const u8 gMonFootprint_QuestionMark[] = INCBIN_U8("graphics/pokemon/question_mark/footprint.1bpp");

const u32 gUnknown_08D778F0[] = INCBIN_U32("graphics/battle_transitions/vs_frame.4bpp.lz");
const u32 gUnknown_08D779D8[] = INCBIN_U32("graphics/battle_transitions/vs_frame.bin.lz");
const u32 gUnknown_08D77AE4[] = INCBIN_U32("graphics/battle_transitions/vs_frame.gbapal.lz");

const u32 gUnknown_08D77B0C[] = INCBIN_U32("graphics/battle_transitions/vs.4bpp.lz");

#include "data/graphics/battle_terrain.h"

const u32 gUnknown_08D82F10[] = INCBIN_U32("graphics/battle_frontier/tourney_bg.4bpp.lz");
const u32 gUnknown_08D834FC[] = INCBIN_U32("graphics/battle_frontier/tourney_line.4bpp.lz"); // the red glow mask for the tourney advancement lines

const u32 gUnknown_08D83900[] = INCBIN_U32("graphics/unknown/unknown_D83900.bin.lz"); // tilemaps likely

const u32 gUnknown_08D83B2C[] = INCBIN_U32("graphics/unknown/unknown_D83B2C.bin.lz");

const u32 gUnknown_08D83C3C[] = INCBIN_U32("graphics/unknown/unknown_D83C3C.bin.lz");

const u32 gUnknown_08D83D50[] = INCBIN_U32("graphics/battle_frontier/misc1.4bpp.lz");

const u32 gUnknown_08D84970[] = INCBIN_U32("graphics/unknown/unknown_D84970.bin.lz");

const u32 gUnknown_08D84F00[] = INCBIN_U32("graphics/unknown/unknown_D84F00.bin.lz");

const u32 gBattleFrontierGfx_DomeOptions[] = INCBIN_U32("graphics/battle_frontier/options.4bpp.lz");
const u32 gUnknown_08D85358[] = INCBIN_U32("graphics/battle_frontier/options_pal1.gbapal.lz");
const u32 gUnknown_08D85444[] = INCBIN_U32("graphics/battle_frontier/options_pal2.gbapal.lz"); // pokeball pal
const u32 gUnknown_08D854C8[] = INCBIN_U32("graphics/battle_frontier/options_pal3.gbapal.lz"); // arrow pal

const u32 gBattleArenaJudgementSymbolsGfx[] = INCBIN_U32("graphics/battle_frontier/arena_judgement_symbols.4bpp.lz");
const u32 gBattleArenaJudgementSymbolsPalette[] = INCBIN_U32("graphics/battle_frontier/arena_judgement_symbols.gbapal.lz");

const u32 gUnknown_08D85600[] = INCBIN_U32("graphics/battle_frontier/text.gbapal.lz");
const u16 gUnknown_08D85620[] = INCBIN_U16("graphics/battle_frontier/text_pp.gbapal");

const u16 gTilesetAnims_BattleDomePals0_0[] = INCBIN_U16("graphics/battle_frontier/dome_anim1.gbapal");
const u16 gTilesetAnims_BattleDomePals0_1[] = INCBIN_U16("graphics/battle_frontier/dome_anim2.gbapal");
const u16 gTilesetAnims_BattleDomePals0_2[] = INCBIN_U16("graphics/battle_frontier/dome_anim3.gbapal");
const u16 gTilesetAnims_BattleDomePals0_3[] = INCBIN_U16("graphics/battle_frontier/dome_anim4.gbapal");

// 8D856C0
asm(".2byte 0x013F, 0x0119, 0x0113, 0x010E"); // unused?

const u16 gUnknown_08D856C8[] = INCBIN_U16("graphics/battle_frontier/pyramid_light.gbapal"); // unfaded pal for the player light in battle pyramid

const u32 gUnknown_08D857A8[] = INCBIN_U32("graphics/battle_frontier/battle_tilemap1.bin.lz");
const u32 gUnknown_08D85A1C[] = INCBIN_U32("graphics/battle_frontier/battle_tilemap2.bin.lz");

#include "data/graphics/intro_scene.h"

const u32 gBattleAnimSpriteSheet_FlyingDirt[] = INCBIN_U32("graphics/battle_anims/sprites/flying_dirt.4bpp.lz");

const u32 gUnknown_08D8D410[] = INCBIN_U32("graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz");
const u32 gUnknown_08D8D58C[] = INCBIN_U32("graphics/battle_anims/backgrounds/sandstorm_brew.4bpp.lz");

const u32 gBattleAnimSpritePalette_FlyingDirt[] = INCBIN_U32("graphics/battle_anims/sprites/flying_dirt.gbapal.lz");

const u32 gBattleAnimSpriteSheet_MetalSoundWaves[] = INCBIN_U32("graphics/battle_anims/sprites/metal_sound_waves.4bpp.lz");
const u32 gBattleAnimSpritePalette_MetalSoundWaves[] = INCBIN_U32("graphics/battle_anims/sprites/metal_sound_waves.gbapal.lz");

const u32 gBattleAnimBackgroundImage_15[] = INCBIN_U32("graphics/battle_anims/backgrounds/15.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_15[] = INCBIN_U32("graphics/battle_anims/backgrounds/15.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_15[] = INCBIN_U32("graphics/battle_anims/backgrounds/15.bin.lz");

const u32 gBattleAnimSpriteSheet_IcicleSpear[] = INCBIN_U32("graphics/battle_anims/sprites/icicle_spear.4bpp.lz");
const u32 gBattleAnimSpritePalette_IcicleSpear[] = INCBIN_U32("graphics/battle_anims/sprites/icicle_spear.gbapal.lz");

const u32 gContestNextTurnGfx[] = INCBIN_U32("graphics/contest/nextturn.4bpp.lz");
const u8 gContestNextTurnNumbersGfx[] = INCBIN_U8("graphics/contest/nextturn_numbers.4bpp");
const u8 gContestNextTurnRandomGfx[] = INCBIN_U8("graphics/contest/nextturn_random.4bpp");

const u32 gBattleAnimSpriteSheet_GlowyRedOrb[] = INCBIN_U32("graphics/battle_anims/sprites/glowy_red_orb.4bpp.lz");
const u32 gBattleAnimSpritePalette_GlowyRedOrb[] = INCBIN_U32("graphics/battle_anims/sprites/glowy_red_orb.gbapal.lz");
const u32 gBattleAnimSpritePalette_GlowyGreenOrb[] = INCBIN_U32("graphics/battle_anims/sprites/glowy_green_orb.gbapal.lz");
const u32 gBattleAnimSpritePalette_SleepPowder[] = INCBIN_U32("graphics/battle_anims/sprites/sleep_powder.gbapal.lz");
const u32 gBattleAnimSpritePalette_StunSpore[] = INCBIN_U32("graphics/battle_anims/sprites/stun_spore.gbapal.lz");

const u32 gContestApplauseGfx[] = INCBIN_U32("graphics/contest/applause.4bpp.lz");
const u8 gContestApplauseMeterGfx[] = INCBIN_U8("graphics/contest/applause_meter.4bpp");

const u16 gContestPal[] = INCBIN_U16("graphics/contest/nextturn.gbapal");

const u32 gBattleAnimSpriteSheet_Splash[] = INCBIN_U32("graphics/battle_anims/sprites/splash.4bpp.lz");
const u32 gBattleAnimSpritePalette_Splash[] = INCBIN_U32("graphics/battle_anims/sprites/splash.gbapal.lz");

const u32 gBattleAnimSpriteSheet_SweatBead[] = INCBIN_U32("graphics/battle_anims/sprites/sweat_bead.4bpp.lz");

const u32 gBattleAnimSpriteSheet_RedBrick[] = INCBIN_U32("graphics/battle_anims/sprites/red_brick.4bpp.lz");
const u32 gBattleAnimSpritePalette_RedBrick[] = INCBIN_U32("graphics/battle_anims/sprites/red_brick.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Gem1[] = INCBIN_U32("graphics/battle_anims/sprites/gem_1.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Gem2[] = INCBIN_U32("graphics/battle_anims/sprites/gem_2.4bpp.lz");
const u32 gBattleAnimSpriteSheet_Gem3[] = INCBIN_U32("graphics/battle_anims/sprites/gem_3.4bpp.lz");

const u32 gBattleAnimSpritePalette_Gem1[] = INCBIN_U32("graphics/battle_anims/sprites/gem_1.gbapal.lz");

const u32 gBattleAnimBackgroundImage_17[] = INCBIN_U32("graphics/battle_anims/backgrounds/17.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_17[] = INCBIN_U32("graphics/battle_anims/backgrounds/17.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_17[] = INCBIN_U32("graphics/battle_anims/backgrounds/17.bin.lz");

const u32 gBattleAnimSpriteSheet_Protect[] = INCBIN_U32("graphics/battle_anims/sprites/protect.4bpp.lz");
const u32 gBattleAnimSpritePalette_Protect[] = INCBIN_U32("graphics/battle_anims/sprites/protect.gbapal.lz");

const u32 gBattleAnimBackgroundImageMuddyWater_Pal[] = INCBIN_U32("graphics/battle_anims/backgrounds/water_muddy.gbapal.lz");

const u32 gEnemyMonShadow_Gfx[] = INCBIN_U32("graphics/battle_interface/enemy_mon_shadow.4bpp.lz");

const u32 gBattleInterface_BallStatusBarGfx[] = INCBIN_U32("graphics/battle_interface/ball_status_bar.4bpp.lz");

const u8 gMonIcon_Egg[] = INCBIN_U8("graphics/pokemon/egg/icon.4bpp");

const u32 gBattleAnimBackgroundImage_02[] = INCBIN_U32("graphics/battle_anims/backgrounds/02.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_02[] = INCBIN_U32("graphics/battle_anims/backgrounds/02.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_02[] = INCBIN_U32("graphics/battle_anims/backgrounds/02.bin.lz");

const u32 gBattleAnimSpritePalette_WhipHit[] = INCBIN_U32("graphics/battle_anims/sprites/whip_hit.gbapal.lz");

const u32 gBattleAnimBackgroundPalette_24[] = INCBIN_U32("graphics/battle_anims/backgrounds/24.gbapal.lz");

const u32 gUnknown_E6BC04[] = INCBIN_U32("graphics/unknown/unknown_E6BC04.bin.lz");

const u32 sBlenderCenterGfx[] = INCBIN_U32("graphics/berry_blender/center.8bpp.lz");

const u32 gUnknown_08D91DB8[] = INCBIN_U32("graphics/berry_blender/outer.4bpp.lz");
const u32 gUnknown_08D927EC[] = INCBIN_U32("graphics/berry_blender/outer_map.bin.lz");

const u32 gBattleAnimBackgroundPalette_16[] = INCBIN_U32("graphics/battle_anims/backgrounds/16.gbapal.lz");
const u32 gBattleAnimBackgroundImage_16[] = INCBIN_U32("graphics/battle_anims/backgrounds/16.4bpp.lz");
const u32 gBattleAnimBackgroundTilemap_16[] = INCBIN_U32("graphics/battle_anims/backgrounds/16.bin.lz");

const u32 gBattleAnimSpritePalette_SlamHit2[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit_2.gbapal.lz");
const u32 gBattleAnimSpriteSheet_SlamHit2[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit_2.4bpp.lz");

const u32 gBattleAnimFogTilemap[] = INCBIN_U32("graphics/battle_anims/backgrounds/fog.bin.lz");

const u32 gBattleAnimSpritePalette_WeatherBall[] = INCBIN_U32("graphics/battle_anims/sprites/weather_ball.gbapal.lz");
const u32 gBattleAnimSpriteSheet_WeatherBall[] = INCBIN_U32("graphics/battle_anims/sprites/weather_ball.4bpp.lz");

const u32 gBattleAnimBackgroundTilemap_ScaryFacePlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_player.bin.lz");
const u32 gBattleAnimBackgroundTilemap_ScaryFaceOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz");
const u32 gBattleAnimBackgroundTilemap_ScaryFaceContest[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_contest.bin.lz");

const u32 gBattleAnimSpriteSheet_Hail[] = INCBIN_U32("graphics/battle_anims/sprites/hail.4bpp.lz");
const u32 gBattleAnimSpritePalette_Hail[] = INCBIN_U32("graphics/battle_anims/sprites/hail.gbapal.lz");

const u32 gBattleAnimSpriteSheet_GreenSpike[] = INCBIN_U32("graphics/battle_anims/sprites/green_spike.4bpp.lz");
const u32 gBattleAnimSpritePalette_GreenSpike[] = INCBIN_U32("graphics/battle_anims/sprites/green_spike.gbapal.lz");
const u32 gBattleAnimSpritePalette_WhiteCircleOfLight[] = INCBIN_U32("graphics/battle_anims/sprites/white_circle_of_light.gbapal.lz");
const u32 gBattleAnimSpritePalette_GlowyBlueOrb[] = INCBIN_U32("graphics/battle_anims/sprites/glowy_blue_orb.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Recycle[] = INCBIN_U32("graphics/battle_anims/sprites/recycle.4bpp.lz");
const u32 gBattleAnimSpritePalette_Recycle[] = INCBIN_U32("graphics/battle_anims/sprites/recycle.gbapal.lz");

const u32 gBattleAnimSpriteSheet_RedParticles[] = INCBIN_U32("graphics/battle_anims/sprites/red_particles.4bpp.lz");
const u32 gBattleAnimSpritePalette_RedParticles[] = INCBIN_U32("graphics/battle_anims/sprites/red_particles.gbapal.lz");

const u32 gBattleAnimSpriteSheet_DirtMound[] = INCBIN_U32("graphics/battle_anims/sprites/dirt_mound.4bpp.lz");
const u32 gBattleAnimSpritePalette_DirtMound[] = INCBIN_U32("graphics/battle_anims/sprites/dirt_mound.gbapal.lz");

const u32 gBattleAnimBackgroundImage_21[] = INCBIN_U32("graphics/battle_anims/backgrounds/21.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_21[] = INCBIN_U32("graphics/battle_anims/backgrounds/21.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_21[] = INCBIN_U32("graphics/battle_anims/backgrounds/21.bin.lz");

const u32 gBattleAnimSpriteSheet_Bird[] = INCBIN_U32("graphics/battle_anims/sprites/bird.4bpp.lz");
const u32 gBattleAnimSpritePalette_Bird[] = INCBIN_U32("graphics/battle_anims/sprites/bird.gbapal.lz");

const u32 gBattleAnimSpriteSheet_CrossImpact[] = INCBIN_U32("graphics/battle_anims/sprites/cross_impact.4bpp.lz");
const u32 gBattleAnimSpritePalette_CrossImpact[] = INCBIN_U32("graphics/battle_anims/sprites/cross_impact.gbapal.lz");

const u32 gBattleAnimBackgroundImage_Surf[] = INCBIN_U32("graphics/battle_anims/backgrounds/water.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_Surf[] = INCBIN_U32("graphics/battle_anims/backgrounds/water.gbapal.lz");

const u32 gUnknown_08D95E00[] = INCBIN_U32("graphics/unknown/unknown_D95E00.bin.lz");

const u32 gUnknown_08D960D0[] = INCBIN_U32("graphics/unknown/unknown_D960D0.bin.lz");

const u32 gUnknown_08D963A4[] = INCBIN_U32("graphics/unknown/unknown_D963A4.bin.lz");

const u32 gBattleAnimSpritePalette_Slash2[] = INCBIN_U32("graphics/battle_anims/sprites/slash_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_WhiteShadow[] = INCBIN_U32("graphics/battle_anims/sprites/white_shadow.4bpp.lz");
const u32 gBattleAnimSpritePalette_WhiteShadow[] = INCBIN_U32("graphics/battle_anims/sprites/white_shadow.gbapal.lz");

const u32 gPartyMenuMisc_Gfx[] = INCBIN_U32("graphics/interface/party_menu_misc.4bpp.lz");
const u32 gPartyMenuMisc_Pal[] = INCBIN_U32("graphics/interface/party_menu_misc.gbapal.lz");
const u32 gPartyMenuMisc_Tilemap[] = INCBIN_U32("graphics/interface/party_menu_misc.bin.lz");

const u32 gPartyMenuPokeball_Gfx[] = INCBIN_U32("graphics/interface/party_menu_pokeball.4bpp.lz");
const u32 gPartyMenuPokeballSmall_Gfx[] = INCBIN_U32("graphics/interface/party_menu_pokeball_small.4bpp.lz"); //unused
const u32 gPartyMenuPokeball_Pal[] = INCBIN_U32("graphics/interface/party_menu_pokeball.gbapal.lz");

const u32 gStatusGfx_Icons[] = INCBIN_U32("graphics/interface/status_icons.4bpp.lz");
const u32 gStatusPal_Icons[] = INCBIN_U32("graphics/interface/status_icons.gbapal.lz");

const u32 gMoveTypes_Gfx[] = INCBIN_U32("graphics/types/move_types.4bpp.lz");
const u32 gMoveTypes_Pal[] = INCBIN_U32("graphics/types/move_types.gbapal.lz");

const u32 gMoveSelectorBitmap[] = INCBIN_U32("graphics/interface/summary_frames.4bpp.lz");
const u32 gUnknown_08D97CF4[] = INCBIN_U32("graphics/interface/summary_frames.gbapal.lz");

const u32 gStatusScreenBitmap[] = INCBIN_U32("graphics/interface/status_screen.4bpp.lz");
const u32 gStatusScreenPalette[] = INCBIN_U32("graphics/interface/status_screen.gbapal.lz");
const u32 gPageInfoTilemap[] = INCBIN_U32("graphics/interface/status_screen.bin.lz");

const u32 gPageSkillsTilemap[] = INCBIN_U32("graphics/interface/status_tilemap1.bin.lz");
const u32 gPageBattleMovesTilemap[] = INCBIN_U32("graphics/interface/status_tilemap2.bin.lz");
const u32 gPageContestMovesTilemap[] = INCBIN_U32("graphics/interface/status_tilemap3.bin.lz");
const u32 gUnknown_08D98CC8[] = INCBIN_U32("graphics/interface/status_tilemap0.bin.lz");

const u32 gBagMaleTiles[] = INCBIN_U32("graphics/misc/bag_male.4bpp.lz");
const u32 gBagFemaleTiles[] = INCBIN_U32("graphics/misc/bag_female.4bpp.lz");
const u32 gBagPalette[] = INCBIN_U32("graphics/misc/bag.gbapal.lz");

const u32 gBagScreenMale_Pal[] = INCBIN_U32("graphics/interface/bag_screen_male.gbapal.lz");
const u32 gBagScreenFemale_Pal[] = INCBIN_U32("graphics/interface/bag_screen_female.gbapal.lz");

const u32 gBagScreen_Gfx[] = INCBIN_U32("graphics/interface/bag_screen.4bpp.lz");

const u32 gUnknown_08D9A88C[] = INCBIN_U32("graphics/unknown/unknown_D9A88C.bin.lz");

const u32 gBattleFrontierGfx_PyramidBag[] = INCBIN_U32("graphics/interface/bag_pyramid.4bpp.lz");
const u32 gUnknown_08D9ADD0[] = INCBIN_U32("graphics/interface/bag_pyramid.gbapal.lz"); // female palette is first and male is second.

const u32 gUnknown_08D9AE04[] = INCBIN_U32("graphics/unknown/unknown_D9AE04.bin.lz");

const u32 gUnknown_08D9AF44[] = INCBIN_U32("graphics/unknown/unknown_D9AF44.gbapal.lz");

const u32 gBagSwapLineGfx[] = INCBIN_U32("graphics/interface/bag_swap.4bpp.lz");
const u32 gBagSwapLinePal[] = INCBIN_U32("graphics/interface/bag_swap.gbapal.lz");

const u32 gBuyMenuFrame_Gfx[] = INCBIN_U32("graphics/interface/mart_frame.4bpp.lz");
const u32 gMenuMoneyPal[] = INCBIN_U32("graphics/interface/mart_frame.gbapal.lz");
const u32 gBuyMenuFrame_Tilemap[] = INCBIN_U32("graphics/interface/mart_frame.bin.lz");

const u32 gMenuMoneyGfx[] = INCBIN_U32("graphics/interface/money.4bpp.lz");

// Pokeblock

const u32 gMenuPokeblock_Gfx[] = INCBIN_U32("graphics/interface/pokeblock_case_frame.4bpp.lz");
const u32 gMenuPokeblock_Pal[] = INCBIN_U32("graphics/interface/pokeblock_case_frame.gbapal.lz");

const u32 gMenuPokeblockDevice_Gfx[] = INCBIN_U32("graphics/interface/pokeblock_device.4bpp.lz");
const u32 gMenuPokeblockDevice_Pal[] = INCBIN_U32("graphics/interface/pokeblock_device.gbapal.lz");

const u32 gMenuPokeblock_Tilemap[] = INCBIN_U32("graphics/interface/pokeblock.bin.lz");
const u32 gPokeblock_Gfx[] = INCBIN_U32("graphics/pokeblock/pokeblock.4bpp.lz");
const u32 gPokeblockRed_Pal[] = INCBIN_U32("graphics/pokeblock/red.gbapal.lz");
const u32 gPokeblockBlue_Pal[] = INCBIN_U32("graphics/pokeblock/blue.gbapal.lz");
const u32 gPokeblockPink_Pal[] = INCBIN_U32("graphics/pokeblock/pink.gbapal.lz");
const u32 gPokeblockGreen_Pal[] = INCBIN_U32("graphics/pokeblock/green.gbapal.lz");
const u32 gPokeblockYellow_Pal[] = INCBIN_U32("graphics/pokeblock/yellow.gbapal.lz");
const u32 gPokeblockPurple_Pal[] = INCBIN_U32("graphics/pokeblock/purple.gbapal.lz");
const u32 gPokeblockIndigo_Pal[] = INCBIN_U32("graphics/pokeblock/indigo.gbapal.lz");
const u32 gPokeblockBrown_Pal[] = INCBIN_U32("graphics/pokeblock/brown.gbapal.lz");
const u32 gPokeblockLiteBlue_Pal[] = INCBIN_U32("graphics/pokeblock/liteblue.gbapal.lz");
const u32 gPokeblockOlive_Pal[] = INCBIN_U32("graphics/pokeblock/olive.gbapal.lz");
const u32 gPokeblockGray_Pal[] = INCBIN_U32("graphics/pokeblock/gray.gbapal.lz");
const u32 gPokeblockBlack_Pal[] = INCBIN_U32("graphics/pokeblock/black.gbapal.lz");
const u32 gPokeblockWhite_Pal[] = INCBIN_U32("graphics/pokeblock/white.gbapal.lz");
const u32 gPokeblockGold_Pal[] = INCBIN_U32("graphics/pokeblock/gold.gbapal.lz");

const u32 gUnknown_08D9BA44[] = INCBIN_U32("graphics/interface/pokeblock_feeding_bg_map.bin.lz");

#include "data/graphics/berries.h"
#include "data/graphics/rayquaza_scene.h"
#include "data/graphics/items.h"
#include "data/graphics/decorations.h"

const u32 gBattleAnimSpritePalette_Shock3[] = INCBIN_U32("graphics/battle_anims/sprites/shock_3.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Shock3[] = INCBIN_U32("graphics/battle_anims/sprites/shock_3.4bpp.lz");

const u32 gBattleAnimSpritePalette_WhiteFeather[] = INCBIN_U32("graphics/battle_anims/sprites/white_feather.gbapal.lz");
const u32 gBattleAnimSpriteSheet_WhiteFeather[] = INCBIN_U32("graphics/battle_anims/sprites/white_feather.4bpp.lz");

const u32 gBattleAnimSpritePalette_Sparkle6[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_6.gbapal.lz");
const u32 gBattleAnimSpriteSheet_Sparkle6[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_6.4bpp.lz");

const u16 gUnknown_08DBA518[] = INCBIN_U16("graphics/misc/cable_car_bg.gbapal");
const u16 gCableCar_Pal[] = INCBIN_U16("graphics/misc/cable_car.gbapal");

const u32 gUnknown_08DBA5B8[] = INCBIN_U32("graphics/misc/cable_car_bg.4bpp.lz");
const u32 gCableCar_Gfx[] = INCBIN_U32("graphics/misc/cable_car.4bpp.lz");
const u32 gCableCarDoor_Gfx[] = INCBIN_U32("graphics/misc/cable_car_door.4bpp.lz");
const u32 gCableCarCord_Gfx[] = INCBIN_U32("graphics/misc/cable_car_cord.4bpp.lz");

const u32 gRouletteMenuTiles[] = INCBIN_U32("graphics/roulette/window.4bpp.lz");
const u32 gRouletteWheelTiles[] = INCBIN_U32("graphics/roulette/wheel.8bpp.lz");
const u32 gRouletteCenter_Gfx[] = INCBIN_U32("graphics/roulette/center.4bpp.lz");
const u32 gRouletteHeadersTiles[] = INCBIN_U32("graphics/roulette/headers.4bpp.lz");
const u32 gRouletteCreditTiles[] = INCBIN_U32("graphics/roulette/credit.4bpp.lz");
const u32 gRouletteNumbersTiles[] = INCBIN_U32("graphics/roulette/numbers.4bpp.lz");
const u32 gRouletteMultiplierTiles[] = INCBIN_U32("graphics/roulette/multiplier.4bpp.lz");

#include "data/graphics/mail.h"

const u16 gFrontierFactorySelectMenu_Pal[] = INCBIN_U16("graphics/battle_frontier/factory_menu1.gbapal");
const u16 gFrontierFactorySelectMenu_Pal2[] = INCBIN_U16("graphics/battle_frontier/factory_menu2.gbapal");

const u8 gFrontierFactorySelectMenu_Gfx[] = INCBIN_U8("graphics/battle_frontier/factory_menu1.4bpp");
const u8 gFrontierFactorySelectMenu_Gfx2[] = INCBIN_U8("graphics/battle_frontier/factory_menu2.4bpp");

const u16 gFrontierFactorySelectMenu_Tilemap[] = INCBIN_U16("graphics/battle_frontier/factory_menu.bin");

const u32 gFrontierPassMedals_Gfx[] = INCBIN_U32("graphics/frontier_pass/medals.4bpp.lz");

const u16 gFrontierPassCursor_Pal[] = INCBIN_U16("graphics/frontier_pass/cursor.gbapal");

const u16 gFrontierPassMapCursor_Pal[] = INCBIN_U16("graphics/frontier_pass/map_cursor.gbapal");

const u16 gFrontierPassMedalsSilver_Pal[] = INCBIN_U16("graphics/frontier_pass/silver.gbapal");
const u16 gFrontierPassMedalsGold_Pal[] = INCBIN_U16("graphics/frontier_pass/gold.gbapal");

const u16 gPokedexText_Pal[] = INCBIN_U16("graphics/pokedex/text.gbapal");

const u16 gPokedexCaughtScreenFade_Pal[] = INCBIN_U16("graphics/pokedex/fade.gbapal");

const u16 gPokedexHoennBg_Pal[] = INCBIN_U16("graphics/pokedex/hoenn_bg.gbapal");
const u16 gPokedexNationalBg_Pal[] = INCBIN_U16("graphics/pokedex/national_bg.gbapal");

const u32 gPokedexMenu_Gfx[] = INCBIN_U32("graphics/pokedex/menu.4bpp.lz");
const u32 gPokedexMenu2_Gfx[] = INCBIN_U32("graphics/pokedex/menu2.4bpp.lz");

const u32 gUnused_PokedexNoBall[] = INCBIN_U32("graphics/pokedex/noball_unused.4bpp.lz");

const u32 gPokedexTilemap_StartMenu1[] = INCBIN_U32("graphics/pokedex/tilemap1.bin.lz");
const u32 gPokedexTilemap_StartMenu2[] = INCBIN_U32("graphics/pokedex/tilemap2.bin.lz");
const u32 gPokedexTilemap_Main[] = INCBIN_U32("graphics/pokedex/tilemap3.bin.lz");
const u32 gPokedexTilemap_MainUnderlay[] = INCBIN_U32("graphics/pokedex/tilemap4.bin.lz");
const u32 gPokedexTilemap_SizeScreen[] = INCBIN_U32("graphics/pokedex/tilemap5.bin.lz");
const u32 gPokedexTilemap_ScreenSelectBar1[] = INCBIN_U32("graphics/pokedex/tilemap6.bin.lz");
const u32 gPokedexTilemap_ScreenSelectBar2[] = INCBIN_U32("graphics/pokedex/tilemap7.bin.lz");
const u32 gPokedexTilemap_DescriptionScreen[] = INCBIN_U32("graphics/pokedex/tilemap8.bin.lz");
const u32 gPokedexTilemap_CryScreen[] = INCBIN_U32("graphics/pokedex/tilemap9.bin.lz");

const u16 gPokedexSearchMenu_Pal[] = INCBIN_U16("graphics/pokedex/search_menu.gbapal");
const u32 gPokedexSearchMenu_Gfx[] = INCBIN_U32("graphics/pokedex/search_menu.4bpp.lz");
const u32 gPokedexSearch1_Tilemap[] = INCBIN_U32("graphics/pokedex/search1.bin.lz");
const u32 gPokedexSearch2_Tilemap[] = INCBIN_U32("graphics/pokedex/search2.bin.lz");

const u16 gSummaryScreenPowAcc_Tilemap[] = INCBIN_U16("graphics/interface/powacc_tilemap.bin");

const u16 gUnknown_08DC3C34[] = INCBIN_U16("graphics/interface/unk_tilemap.bin"); // probably trade summary screen related?

const u16 gSummaryScreenWindow_Tilemap[] = INCBIN_U16("graphics/interface/summary.bin");

const u16 gIntroCopyright_Pal[] = INCBIN_U16("graphics/intro/copyright.gbapal");
const u32 gIntroCopyright_Gfx[] = INCBIN_U32("graphics/intro/copyright.4bpp.lz");
const u32 gIntroCopyright_Tilemap[] = INCBIN_U32("graphics/intro/copyright.bin.lz");

const u16 gPokedexAreaScreenAreaUnknown_Pal[] = INCBIN_U16("graphics/pokedex/area_unknown.gbapal");
const u32 gPokedexAreaScreenAreaUnknown_Gfx[] = INCBIN_U32("graphics/pokedex/area_unknown.4bpp.lz");

// seems to be fire red leftovers, but the menu elements is reused in the item menu for TM descriptions.

const u16 gFireRedMenuElements1_Pal[] = INCBIN_U16("graphics/interface_fr/menu1.gbapal");
const u16 gFireRedMenuElements2_Pal[] = INCBIN_U16("graphics/interface_fr/menu2.gbapal");
const u16 gFireRedMenuElements3_Pal[] = INCBIN_U16("graphics/interface_fr/menu3.gbapal");
const u8 gFireRedMenuElements_Gfx[] = INCBIN_U8("graphics/interface_fr/menu.4bpp"); //the types are reused for item menu

const u8 gBagMenuHMIcon_Gfx[] = INCBIN_U8("graphics/interface/hm.4bpp");

// contest link stuff, appears to be a set of tilemaps

const u16 gUnknown_08DC63F8[] = INCBIN_U16("graphics/contest/clink_tilemap1.bin");
const u16 gUnknown_08DC6420[] = INCBIN_U16("graphics/contest/clink_tilemap2.bin");
const u16 gUnknown_08DC6448[] = INCBIN_U16("graphics/contest/clink_tilemap3.bin");
const u16 gUnknown_08DC6470[] = INCBIN_U16("graphics/contest/clink_tilemap4.bin");
const u16 gUnknown_08DC6498[] = INCBIN_U16("graphics/contest/clink_tilemap5.bin");
const u16 gUnknown_08DC64AC[] = INCBIN_U16("graphics/contest/clink_tilemap6.bin");
const u16 gUnknown_08DC64C0[] = INCBIN_U16("graphics/contest/clink_tilemap7.bin");
const u16 gUnknown_08DC64D4[] = INCBIN_U16("graphics/contest/clink_tilemap8.bin");
const u16 gUnknown_08DC64E8[] = INCBIN_U16("graphics/contest/clink_tilemap9.bin");
const u16 gUnknown_08DC64FC[] = INCBIN_U16("graphics/contest/clink_tilemap10.bin");
const u16 gUnknown_08DC6510[] = INCBIN_U16("graphics/contest/clink_tilemap11.bin");

// pokenav

const u16 gPokenavCondition_Pal[] = INCBIN_U16("graphics/pokenav/condition.gbapal");

const u32 gPokenavCondition_Gfx[] = INCBIN_U32("graphics/pokenav/condition.4bpp.lz");
const u32 gPokenavCondition_Tilemap[] = INCBIN_U32("graphics/pokenav/condition.bin.lz");

const u16 gPokenavOptions_Tilemap[] = INCBIN_U16("graphics/pokenav/options/options.bin");
const u32 gPokenavOptions_Gfx[] = INCBIN_U32("graphics/pokenav/options/options.4bpp.lz");
const u16 gPokenavOptions_Pal[] = INCBIN_U16("graphics/pokenav/options/options.gbapal");

const u16 gPokenavHeader_Pal[] = INCBIN_U16("graphics/pokenav/header.gbapal");
const u32 gPokenavHeader_Gfx[] = INCBIN_U32("graphics/pokenav/header.4bpp.lz"); // TODO: use width 9 and makefile rule for cleanliness, make wasnt behaving, didnt want to apply num_tiles to this
const u32 gPokenavHeader_Tilemap[] = INCBIN_U32("graphics/pokenav/header.bin.lz");

const u16 gPokenavLeftHeader_Pal[] = INCBIN_U16("graphics/pokenav/left_headers/palette.gbapal");
const u32 gPokenavLeftHeaderBeauty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/beauty.4bpp.lz");
const u32 gPokenavLeftHeaderSmart_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/smart.4bpp.lz");
const u32 gPokenavLeftHeaderCondition_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/condition.4bpp.lz");
const u32 gPokenavLeftHeaderCute_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cute.4bpp.lz");
const u32 gPokenavLeftHeaderMatchCall_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/match_call.4bpp.lz");
const u32 gPokenavLeftHeaderMainMenu_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/main_menu.4bpp.lz");
const u32 gPokenavLeftHeaderHoennMap_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/hoenn_map.4bpp.lz");
const u32 gPokenavLeftHeaderRibbons_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/ribbons.4bpp.lz");
const u32 gPokenavLeftHeaderSearch_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/search.4bpp.lz");
const u32 gPokenavLeftHeaderTough_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/tough.4bpp.lz");
const u32 gPokenavLeftHeaderCool_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cool.4bpp.lz");
const u32 gPokenavLeftHeaderParty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/party.4bpp.lz");

const u16 gPokenavMessageBox_Pal[] = INCBIN_U16("graphics/pokenav/message.gbapal");
const u32 gPokenavMessageBox_Gfx[] = INCBIN_U32("graphics/pokenav/message.4bpp.lz");
const u32 gPokenavMessageBox_Tilemap[] = INCBIN_U32("graphics/pokenav/message.bin.lz");

const u16 gHoennMapZoomIcons_Pal[] = INCBIN_U16("graphics/pokenav/zoom.gbapal");
const u32 gHoennMapZoomIcons_Gfx[] = INCBIN_U32("graphics/pokenav/zoom.4bpp.lz");

const u16 gPokenavConditionCancel_Pal[] = INCBIN_U16("graphics/pokenav/cancel.gbapal");
const u8 gPokenavConditionCancel_Gfx[] = INCBIN_U8("graphics/pokenav/cancel.4bpp");

const u16 gPokenavConditionMarker_Pal[] = INCBIN_U16("graphics/pokenav/marker.gbapal");
const u8 gPokenavConditionMarker_Gfx[] = INCBIN_U8("graphics/pokenav/marker.4bpp");

const u16 gBerryBlenderMiscPalette[] = INCBIN_U16("graphics/berry_blender/misc.gbapal");

const u16 gBerryBlenderArrowPalette[] = INCBIN_U16("graphics/berry_blender/arrow.gbapal");

const u8 gBerryBlenderBetaArrow_Gfx[] = INCBIN_U8("graphics/berry_blender/arrow_old.4bpp"); //unused

const u8 gBerryBlenderMarubatsuTiles[] = INCBIN_U8("graphics/berry_blender/marubatsu.4bpp");

const u8 gBerryBlenderParticlesTiles[] = INCBIN_U8("graphics/berry_blender/particles.4bpp");

asm(".space 0x120");

const u8 gBerryBlenderCountdownNumbersTiles[] = INCBIN_U8("graphics/berry_blender/countdown_numbers.4bpp");

const u8 gBerryBlenderStartTiles[] = INCBIN_U8("graphics/berry_blender/start.4bpp");

asm(".space 0x200");

const u8 gBerryBlenderArrowTiles[] = INCBIN_U8("graphics/berry_blender/arrow.4bpp");

asm(".space 0x2C0");

const u16 gEasyChatCursor_Pal[] = INCBIN_U16("graphics/easy_chat/cursor.gbapal");
const u32 gEasyChatCursor_Gfx[] = INCBIN_U32("graphics/easy_chat/cursor.4bpp.lz");

const u16 gEasyChatRightWindow_Pal[] = INCBIN_U16("graphics/easy_chat/rwindow.gbapal");
const u32 gEasyChatRightWindow_Gfx[] = INCBIN_U32("graphics/easy_chat/rwindow.4bpp.lz");

const u32 gEasyChatMode_Gfx[] = INCBIN_U32("graphics/easy_chat/mode.4bpp.lz");
const u16 gEasyChatMode_Pal[] = INCBIN_U16("graphics/easy_chat/mode.gbapal");

const u32 gEasyChatWindow_Gfx[] = INCBIN_U32("graphics/easy_chat/window.4bpp.lz"); // uses mode pal
const u32 gEasyChatWindow_Tilemap[] = INCBIN_U32("graphics/easy_chat/window.bin.lz");

const u16 gWallclockMale_Pal[] = INCBIN_U16("graphics/interface/wallclock_male.gbapal");
const u16 gWallclockFemale_Pal[] = INCBIN_U16("graphics/interface/wallclock_female.gbapal");
const u32 gWallclock_Gfx[] = INCBIN_U32("graphics/interface/wallclock.4bpp.lz");
const u32 gUnknown_08DCC648[] = INCBIN_U32("graphics/interface/wallclock1.bin.lz");
const u32 gUnknown_08DCC908[] = INCBIN_U32("graphics/interface/wallclock2.bin.lz");

const u16 gUsePokeblockCondition_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/condition.gbapal");
const u32 gUsePokeblockCondition_Gfx[] = INCBIN_U32("graphics/pokeblock/use_screen/condition.4bpp.lz");

const u16 gUsePokeblockUpDown_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/updown.gbapal");
const u8 gUsePokeblockUpDown_Gfx[] = INCBIN_U8("graphics/pokeblock/use_screen/updown.4bpp");

const u16 gUsePokeblockGraph_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/graph.gbapal");
const u32 gUsePokeblockGraph_Gfx[] = INCBIN_U32("graphics/pokeblock/use_screen/graph.4bpp.lz");

const u32 gUsePokeblockGraph_Tilemap[] = INCBIN_U32("graphics/pokeblock/use_screen/graph.bin.lz");
const u16 gUsePokeblockNatureWin_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/nature.gbapal");

#include "data/graphics/slot_machine.h"

const u16 gUnknown_08DD19F8[] = INCBIN_U16("graphics/unknown/unknown_DD19F8.bin");

const u8 gUnknown_08DD1A18[] = INCBIN_U8("graphics/unknown/unknown_DD1A18.4bpp");

// trainer card

const u16 gEmeraldTrainerCard0Star_Pal[] = INCBIN_U16("graphics/trainer_card/0star.gbapal");
const u32 gEmeraldTrainerCard_Gfx[] = INCBIN_U32("graphics/trainer_card/card.4bpp.lz");

const u32 gUnknown_08DD1F78[] = INCBIN_U32("graphics/unknown/unknown_DD1F78.bin.lz");
const u32 gUnknown_08DD2010[] = INCBIN_U32("graphics/unknown/unknown_DD2010.bin.lz");
const u32 gUnknown_08DD21B0[] = INCBIN_U32("graphics/unknown/unknown_DD21B0.bin.lz");
const u32 gUnknown_08DD228C[] = INCBIN_U32("graphics/unknown/unknown_DD228C.bin.lz");

const u16 gFireRedTrainerCard0Star_Pal[] = INCBIN_U16("graphics/trainer_card/0star_fr.gbapal");
const u32 gFireRedTrainerCard_Gfx[] = INCBIN_U32("graphics/trainer_card/card_fr.4bpp.lz");

const u32 gUnknown_08DD2AE0[] = INCBIN_U32("graphics/unknown/unknown_DD2AE0.bin.lz");
const u32 gUnknown_08DD2B78[] = INCBIN_U32("graphics/unknown/unknown_DD2B78.bin.lz");
const u32 gUnknown_08DD2D30[] = INCBIN_U32("graphics/unknown/unknown_DD2D30.bin.lz");
const u32 gUnknown_08DD2E5C[] = INCBIN_U32("graphics/unknown/unknown_DD2E5C.bin.lz");

// pokemon storage system

const u32 gPSSMenu_Gfx[] = INCBIN_U32("graphics/pokemon_storage/menu.4bpp.lz");
const u16 gPSSMenu_Pal[] = INCBIN_U16("graphics/pokemon_storage/menu.gbapal");
const u32 gUnknown_08DD36C8[] = INCBIN_U32("graphics/unknown/unknown_DD36C8.bin.lz");

// naming screen

const u16 gNamingScreenMenu_Pal[] = INCBIN_U16("graphics/naming_screen/menu.gbapal");
const u32 gNamingScreenMenu_Gfx[] = INCBIN_U32("graphics/naming_screen/menu.4bpp.lz");
const u8 gNamingScreenRWindow_Gfx[] = INCBIN_U8("graphics/naming_screen/rwindow.4bpp");
const u8 gNamingScreenROptions_Gfx[] = INCBIN_U8("graphics/naming_screen/roptions.4bpp");
const u8 gNamingScreenCursor_Gfx[] = INCBIN_U8("graphics/naming_screen/cursor.4bpp");
const u8 gNamingScreenKeyboardButton_Gfx[] = INCBIN_U8("graphics/naming_screen/keyboard_button.4bpp");

const u8 gNamingScreenRightPointingTriangleTiles[] = INCBIN_U8("graphics/naming_screen/right_pointing_triangle.4bpp");
const u8 gNamingScreenUnderscoreTiles[] = INCBIN_U8("graphics/naming_screen/underscore.4bpp");

const u32 gUnknown_08DD4544[] = INCBIN_U32("graphics/unknown/unknown_DD4544.bin.lz");
const u32 gUnknown_08DD4620[] = INCBIN_U32("graphics/unknown/unknown_DD4620.bin.lz");
const u32 gUnknown_08DD46E0[] = INCBIN_U32("graphics/unknown/unknown_DD46E0.bin.lz");
const u32 gUnknown_08DD47A0[] = INCBIN_U32("graphics/unknown/unknown_DD47A0.bin.lz");

// link

const u16 gLinkMiscMenu_Pal[] = INCBIN_U16("graphics/link/misc.gbapal");
const u32 gLinkMiscMenu_Gfx[] = INCBIN_U32("graphics/link/misc.4bpp.lz");
const u32 gLinkMiscMenu_Tilemap[] = INCBIN_U32("graphics/link/misc.bin.lz");

const u16 gUnknown_08DD4BB0[] = INCBIN_U16("graphics/link/link1.gbapal");
const u16 gUnknown_08DD4BD0[] = INCBIN_U16("graphics/link/link2.gbapal");

const u32 gUnknown_08DD4BF0[] = INCBIN_U32("graphics/link/link_winedge.4bpp.lz");
const u32 gUnknown_08DD4C4C[] = INCBIN_U32("graphics/link/link_winedge.bin.lz");

const u32 gUnknown_08DD4CF8[] = INCBIN_U32("graphics/interface/unk_change_case.4bpp.lz");

const u16 gTilesetPalettes_General[][16] =
{
    INCBIN_U16("data/tilesets/primary/general/palettes/00.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/01.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/02.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/03.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/04.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/05.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/06.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/07.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/08.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/09.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/10.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/11.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/12.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/13.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/14.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/15.gbapal"),
};

const u32 gTilesetTiles_General[] = INCBIN_U32("data/tilesets/primary/general/tiles.4bpp.lz");

// trade/egg hatch

const u16 gTradeGba_Pal[] = INCBIN_U16("graphics/link/gba.gbapal");
const u16 gTradeGba2_Pal[] = INCBIN_U16("graphics/link/gba_pal2.gbapal");
const u8 gTradeGba_Gfx[] = INCBIN_U8("graphics/link/gba.4bpp");

// 8DD8760
asm(".space 0x20"); //blank palette??

#include "data/graphics/berry_fix.h"

// more trade stuff?

const u16 gUnknown_08DDB3E4[] = INCBIN_U16("graphics/trade/menu.gbapal");

const u16 gUnknown_08DDB444[] = INCBIN_U16("graphics/unknown/unknown_DDB444.gbapal");

const u8 gUnknown_08DDB464[] = INCBIN_U8("graphics/trade/menu.4bpp");

const u8 gUnknown_08DDC6E4[] = INCBIN_U8("graphics/trade/buttons.4bpp");

const u16 gUnused_DDCEE4[] = INCBIN_U16("graphics/unused/unused_DDCEE4.bin");

const u16 gUnknown_08DDCF04[] = INCBIN_U16("graphics/unknown/unknown_DDCF04.bin");

const u16 gUnknown_08DDD704[] = INCBIN_U16("graphics/unknown/unknown_DDD704.bin"); // textbox tilemap??

const u16 gMessageBox_Pal[] = INCBIN_U16("graphics/text_window/message_box.gbapal");
const u8 gMessageBox_Gfx[] = INCBIN_U8("graphics/text_window/message_box.4bpp");

const u32 gWallpaperIcon_Cross[] = INCBIN_U32("graphics/pokemon_storage/cross_icon.4bpp.lz");
const u32 gWallpaperIcon_Bolt[] = INCBIN_U32("graphics/pokemon_storage/bolt_icon.4bpp.lz");
const u32 gWallpaperIcon_Plusle[] = INCBIN_U32("graphics/pokemon_storage/plusle_icon.4bpp.lz");

const u16 gWallpaperPalettes_Horizontal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/horizontal_bg.gbapal"),
};

const u32 gWallpaperTiles_Horizontal[] = INCBIN_U32("graphics/pokemon_storage/horizontal.4bpp.lz");
const u32 gWallpaperTilemap_Horizontal[] = INCBIN_U32("graphics/pokemon_storage/horizontal.bin.lz");

const u16 gWallpaperPalettes_Ribbon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/ribbon_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/ribbon_bg.gbapal"),
};

const u32 gWallpaperTiles_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/ribbon.4bpp.lz");
const u32 gWallpaperTilemap_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/ribbon.bin.lz");

// pokenav

const u16 gUnknown_08DDE010[] = INCBIN_U16("graphics/pokenav/ribbons.gbapal");
const u32 gUnknown_08DDE030[] = INCBIN_U32("graphics/pokenav/ribbons.4bpp.lz");
const u32 gUnknown_08DDE12C[] = INCBIN_U32("graphics/pokenav/ribbons.bin.lz");

const u16 gMonIconPalettes[][16] =
{
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_0.gbapal"),
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_1.gbapal"),
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_2.gbapal"),
};

const u16 gTitleScreenBgPalettes[] = INCBIN_U16("graphics/title_screen/pokemon_logo.gbapal");
const u16 gTitleScreenBgPalettes2[] = INCBIN_U16("graphics/title_screen/rayquaza_and_clouds.gbapal");

const u16 gTitleScreenEmeraldVersionPal[] = INCBIN_U16("graphics/title_screen/emerald_version.gbapal");

const u32 gUnknown_08DDE458[] = INCBIN_U32("graphics/title_screen/title_screen1.bin.lz");

const u32 gTitleScreenPokemonLogoGfx[] = INCBIN_U32("graphics/title_screen/pokemon_logo.8bpp.lz");

const u32 gTitleScreenEmeraldVersionGfx[] = INCBIN_U32("graphics/title_screen/emerald_version.8bpp.lz");

const u16 gTitleScreenPressStartPal[] = INCBIN_U16("graphics/title_screen/press_start.gbapal");
const u32 gTitleScreenPressStartGfx[] = INCBIN_U32("graphics/title_screen/press_start.4bpp.lz");

const u32 gUnknown_08DE0644[] = INCBIN_U32("graphics/title_screen/title_screen2.bin.lz");

// more trainer card stuff

const u16 gUnknown_08DE07C8[][16] = INCBIN_U16("graphics/frontier_pass/tiles.gbapal");// size in LoadPalette calls is reported as 0xD0 << 1, which is 0x1A0, but palette is only 0x100 bytes long so it loads garbage as well
const u32 gUnknown_08DE08C8[] = INCBIN_U32("graphics/frontier_pass/tiles.4bpp.lz");
const u32 gUnknown_08DE2084[] = INCBIN_U32("graphics/frontier_pass/tiles2.8bpp.lz");
const u32 gUnknown_08DE3060[] = INCBIN_U32("graphics/frontier_pass/tiles.bin.lz");
const u16 gUnknown_08DE3350[] = INCBIN_U16("graphics/frontier_pass/tilemap1.bin");
const u16 gUnknown_08DE3374[] = INCBIN_U16("graphics/frontier_pass/tilemap2.bin");

// berry crusher

const u16 gUnknown_08DE3398[] = INCBIN_U16("graphics/berry_crusher/tiles.gbapal");
const u32 gUnknown_08DE34B8[] = INCBIN_U32("graphics/berry_crusher/tiles.4bpp.lz");
const u32 gUnknown_08DE3FD4[] = INCBIN_U32("graphics/berry_crusher/tiles.bin.lz");

// random garbage at the end.
asm(".space 0x54BAC \n\
     .byte 0x0D, 0x00, 0x58, 0x02 \n\
     .space 0x1145 \n\
     .byte 0x02 \n\
     .space 0x3242 \n\
     .byte 0x40 \n\
     .space 0x13");
