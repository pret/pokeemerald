// Scene 1 (RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE)
const u32 gRaySceneDuoFight_Groudon_Gfx[]           = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon.4bpp.lz");
const u32 gRaySceneDuoFight_GroudonShoulder_Gfx[]   = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon_shoulder.4bpp.lz");
const u32 gRaySceneDuoFight_GroudonClaw_Gfx[]       = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon_claw.4bpp.lz");
const u32 gRaySceneDuoFight_Kyogre_Gfx[]            = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre.4bpp.lz");
const u32 gRaySceneDuoFight_KyogrePectoralFin_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre_pectoral_fin.4bpp.lz");
const u32 gRaySceneDuoFight_KyogreDorsalFin_Gfx[]   = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre_dorsal_fin.4bpp.lz");
const u32 gRaySceneDuoFight_Groudon_Pal[]           = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon.gbapal.lz");
const u32 gRaySceneDuoFight_Kyogre_Pal[]            = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre.gbapal.lz");
const u32 gRaySceneDuoFight_Clouds_Gfx[]            = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds.4bpp.lz");
const u32 gRaySceneDuoFight_Clouds_Pal[]            = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds.gbapal.lz"); // pal 1 clouds, pal 2 rain
const u32 gRaySceneDuoFight_Clouds1_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds1.bin.lz");
const u32 gRaySceneDuoFight_Clouds2_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds2.bin.lz");
const u32 gRaySceneDuoFight_Clouds3_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds3.bin.lz");

// Scene 2 (RAY_ANIM_TAKES_FLIGHT)
const u32 gRaySceneTakesFlight_Smoke_Gfx[]        = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.4bpp.lz");
const u32 gRaySceneTakesFlight_Smoke_Pal[]        = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.gbapal.lz");
const u32 gRaySceneTakesFlight_Rayquaza_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.8bpp.lz");
const u32 gRaySceneTakesFlight_Rayquaza_Pal[]     = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.gbapal.lz");
const u32 gRaySceneTakesFlight_Rayquaza_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.bin.lz");
const u32 gRaySceneTakesFlight_Bg_Gfx[]           = INCBIN_U32("graphics/rayquaza_scene/scene_2/bg.4bpp.lz"); // uses pal 2 of gRaySceneTakesFlight_Rayquaza_Pal
const u32 gRaySceneTakesFlight_Bg_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_2/bg.bin.lz");

// Scene 3 (RAY_ANIM_DESCENDS)
const u32 gRaySceneDescends_Rayquaza_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza.4bpp.lz");
const u32 gRaySceneDescends_RayquazaTail_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza_tail.4bpp.lz");
const u32 gRaySceneDescends_Bg_Gfx[]           = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.4bpp.lz");
const u32 gRaySceneDescends_Light_Gfx[]        = INCBIN_U32("graphics/rayquaza_scene/scene_3/light.4bpp.lz"); // uses pal 2 of gRaySceneDescends_Bg_Pal
const u32 gRaySceneDescends_Bg_Pal[]           = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.gbapal.lz");
const u32 gRaySceneDescends_Bg_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.bin.lz");
const u32 gRaySceneDescends_Light_Tilemap[]    = INCBIN_U32("graphics/rayquaza_scene/scene_3/light.bin.lz");

// Scene 4 (RAY_ANIM_CHARGES)
const u32 gRaySceneCharges_Bg_Gfx[]           = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.4bpp.lz");
const u32 gRaySceneCharges_Bg_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.bin.lz");
const u32 gRaySceneCharges_Streaks_Gfx[]      = INCBIN_U32("graphics/rayquaza_scene/scene_4/streaks.4bpp.lz");
const u32 gRaySceneCharges_Streaks_Tilemap[]  = INCBIN_U32("graphics/rayquaza_scene/scene_4/streaks.bin.lz");
const u32 gRaySceneCharges_Rayquaza_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza.4bpp.lz");
const u32 gRaySceneCharges_Rayquaza_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza.bin.lz");
const u32 gRaySceneCharges_Orbs_Tilemap[]     = INCBIN_U32("graphics/rayquaza_scene/scene_4/orbs.bin.lz");
const u32 gRaySceneCharges_Bg_Pal[]           = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.gbapal.lz");

// Scene 5 (RAY_ANIM_CHASES_AWAY)
const u32 gRaySceneChasesAway_Groudon_Gfx[]      = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon.4bpp.lz");
const u32 gRaySceneChasesAway_GroudonTail_Gfx[]  = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon_tail.4bpp.lz");
const u32 gRaySceneChasesAway_Kyogre_Gfx[]       = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre.4bpp.lz");
const u32 gRaySceneChasesAway_Rayquaza_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza.4bpp.lz");
const u32 gRaySceneChasesAway_RayquazaTail_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza_tail.4bpp.lz");
const u32 gRaySceneChasesAway_KyogreSplash_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.4bpp.lz");
const u32 gRaySceneChasesAway_Groudon_Pal[]      = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon.gbapal.lz");
const u32 gRaySceneChasesAway_Kyogre_Pal[]       = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre.gbapal.lz");
const u32 gRaySceneChasesAway_Rayquaza_Pal[]     = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza.gbapal.lz");
const u32 gRaySceneChasesAway_KyogreSplash_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.gbapal.lz");
const u32 gRaySceneChasesAway_Light_Gfx[]        = INCBIN_U32("graphics/rayquaza_scene/scene_5/light.4bpp.lz");
const u32 gRaySceneChasesAway_Ring_Gfx[]         = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring.8bpp.lz");
const u32 gRaySceneChasesAway_Light_Tilemap[]    = INCBIN_U32("graphics/rayquaza_scene/scene_5/light.bin.lz");
const u32 gRaySceneChasesAway_Bg_Tilemap[]       = INCBIN_U32("graphics/rayquaza_scene/scene_5/bg.bin.lz");
const u32 gRaySceneChasesAway_Ring_Tilemap[]     = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring.bin.lz");
const u32 gRaySceneChasesAway_Bg_Pal[]           = INCBIN_U32("graphics/rayquaza_scene/scene_5/bg.gbapal.lz");
