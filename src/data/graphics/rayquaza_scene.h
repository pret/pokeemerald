// Scene 1 (RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE)
const u32 gRaySceneDuoFight_Groudon_Gfx[]           = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_GroudonShoulder_Gfx[]   = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon_shoulder.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_GroudonClaw_Gfx[]       = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon_claw.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_Kyogre_Gfx[]            = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_KyogrePectoralFin_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre_pectoral_fin.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_KyogreDorsalFin_Gfx[]   = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre_dorsal_fin.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_Groudon_Pal[]           = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon.png", ".gbapal.lz");
const u32 gRaySceneDuoFight_Kyogre_Pal[]            = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre.png", ".gbapal.lz");
const u32 gRaySceneDuoFight_Clouds_Gfx[]            = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds.png", ".4bpp.lz");
const u32 gRaySceneDuoFight_Clouds_Pal[]            = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds.png", ".gbapal.lz"); // pal 1 clouds, pal 2 rain
const u32 gRaySceneDuoFight_Clouds1_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds1.bin", ".lz");
const u32 gRaySceneDuoFight_Clouds2_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds2.bin", ".lz");
const u32 gRaySceneDuoFight_Clouds3_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds3.bin", ".lz");

// Scene 2 (RAY_ANIM_TAKES_FLIGHT)
const u32 gRaySceneTakesFlight_Smoke_Gfx[]        = INCGFX_U32("graphics/rayquaza_scene/scene_2/smoke.png", ".4bpp.lz");
const u32 gRaySceneTakesFlight_Smoke_Pal[]        = INCGFX_U32("graphics/rayquaza_scene/scene_2/smoke.png", ".gbapal.lz");
const u32 gRaySceneTakesFlight_Rayquaza_Gfx[]     = INCGFX_U32("graphics/rayquaza_scene/scene_2/rayquaza.png", ".8bpp.lz", "-num_tiles 227 -Wnum_tiles");
const u32 gRaySceneTakesFlight_Rayquaza_Pal[]     = INCGFX_U32("graphics/rayquaza_scene/scene_2/rayquaza.png", ".gbapal.lz");
const u32 gRaySceneTakesFlight_Rayquaza_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/rayquaza.bin", ".lz");
const u32 gRaySceneTakesFlight_Bg_Gfx[]           = INCGFX_U32("graphics/rayquaza_scene/scene_2/bg.png", ".4bpp.lz", "-num_tiles 313 -Wnum_tiles"); // uses pal 2 of gRaySceneTakesFlight_Rayquaza_Pal
const u32 gRaySceneTakesFlight_Bg_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_2/bg.bin", ".lz");

// Scene 3 (RAY_ANIM_DESCENDS)
const u32 gRaySceneDescends_Rayquaza_Gfx[]     = INCGFX_U32("graphics/rayquaza_scene/scene_3/rayquaza.png", ".4bpp.lz", "-num_tiles 124 -Wnum_tiles");
// for some reason there are an extra 0xC bytes at the end of the original rayquaza_tail.4bpp, so in order to produce the correct lz,
// we have to cat the bytes at the end with a make rule. not sure why those bytes are there, it may have been a bug in Game Freak's software.
const u32 gRaySceneDescends_RayquazaTail_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/rayquaza_tail_fix.4bpp", ".lz");
const u32 gRaySceneDescends_Bg_Gfx[]           = INCGFX_U32("graphics/rayquaza_scene/scene_3/bg.png", ".4bpp.lz");
const u32 gRaySceneDescends_Light_Gfx[]        = INCGFX_U32("graphics/rayquaza_scene/scene_3/light.png", ".4bpp.lz"); // uses pal 2 of gRaySceneDescends_Bg_Pal
const u32 gRaySceneDescends_Bg_Pal[]           = INCGFX_U32("graphics/rayquaza_scene/scene_3/bg.pal", ".gbapal.lz");
const u32 gRaySceneDescends_Bg_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_3/bg.bin", ".lz");
const u32 gRaySceneDescends_Light_Tilemap[]    = INCGFX_U32("graphics/rayquaza_scene/scene_3/light.bin", ".lz");

// Scene 4 (RAY_ANIM_CHARGES)
const u32 gRaySceneCharges_Bg_Gfx[]           = INCGFX_U32("graphics/rayquaza_scene/scene_4/bg.png", ".4bpp.lz");
const u32 gRaySceneCharges_Bg_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_4/bg.bin", ".lz");
const u32 gRaySceneCharges_Streaks_Gfx[]      = INCGFX_U32("graphics/rayquaza_scene/scene_4/streaks.png", ".4bpp.lz", "-num_tiles 19 -Wnum_tiles");
const u32 gRaySceneCharges_Streaks_Tilemap[]  = INCGFX_U32("graphics/rayquaza_scene/scene_4/streaks.bin", ".lz");
const u32 gRaySceneCharges_Rayquaza_Gfx[]     = INCGFX_U32("graphics/rayquaza_scene/scene_4/rayquaza.png", ".4bpp.lz", "-num_tiles 155 -Wnum_tiles");
const u32 gRaySceneCharges_Rayquaza_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/rayquaza.bin", ".lz");
const u32 gRaySceneCharges_Orbs_Tilemap[]     = INCGFX_U32("graphics/rayquaza_scene/scene_4/orbs.bin", ".lz");
const u32 gRaySceneCharges_Bg_Pal[]           = INCGFX_U32("graphics/rayquaza_scene/scene_4/bg.pal", ".gbapal.lz");

// Scene 5 (RAY_ANIM_CHASES_AWAY)
const u32 gRaySceneChasesAway_Groudon_Gfx[]      = INCGFX_U32("graphics/rayquaza_scene/scene_5/groudon.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_GroudonTail_Gfx[]  = INCGFX_U32("graphics/rayquaza_scene/scene_5/groudon_tail.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_Kyogre_Gfx[]       = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_Rayquaza_Gfx[]     = INCGFX_U32("graphics/rayquaza_scene/scene_5/rayquaza.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_RayquazaTail_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/rayquaza_tail.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_KyogreSplash_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_Groudon_Pal[]      = INCGFX_U32("graphics/rayquaza_scene/scene_5/groudon.png", ".gbapal.lz");
const u32 gRaySceneChasesAway_Kyogre_Pal[]       = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre.png", ".gbapal.lz");
const u32 gRaySceneChasesAway_Rayquaza_Pal[]     = INCGFX_U32("graphics/rayquaza_scene/scene_5/rayquaza.png", ".gbapal.lz");
const u32 gRaySceneChasesAway_KyogreSplash_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.png", ".gbapal.lz");
const u32 gRaySceneChasesAway_Light_Gfx[]        = INCGFX_U32("graphics/rayquaza_scene/scene_5/light.png", ".4bpp.lz");
const u32 gRaySceneChasesAway_Ring_Gfx[]         = INCGFX_U32("graphics/rayquaza_scene/scene_5/ring.png", ".8bpp.lz");
const u32 gRaySceneChasesAway_Light_Tilemap[]    = INCGFX_U32("graphics/rayquaza_scene/scene_5/light.bin", ".lz");
const u32 gRaySceneChasesAway_Bg_Tilemap[]       = INCGFX_U32("graphics/rayquaza_scene/scene_5/bg.bin", ".lz");
const u32 gRaySceneChasesAway_Ring_Tilemap[]     = INCGFX_U32("graphics/rayquaza_scene/scene_5/ring.bin", ".lz");
const u32 gRaySceneChasesAway_Bg_Pal[]           = INCGFX_U32("graphics/rayquaza_scene/scene_5/bg.pal", ".gbapal.lz");
