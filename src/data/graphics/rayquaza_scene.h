// Scene 1 (RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE)
const u32 gRaySceneGroudon_Gfx[]         = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon.4bpp.lz");
const u32 gRaySceneGroudonShoulder_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon_shoulder.4bpp.lz");
const u32 gRaySceneGroudonClaw_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon_claw.4bpp.lz");
const u32 gRaySceneKyogre_Gfx[]          = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre.4bpp.lz");
const u32 gRaySceneKyogre2_Gfx[]         = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre_shoulder.4bpp.lz");
const u32 gRaySceneKyogre3_Gfx[]         = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre_fin.4bpp.lz");
const u32 gRaySceneGroudon_Pal[]         = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon.gbapal.lz");
const u32 gRaySceneKyogre_Pal[]          = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre.gbapal.lz");
const u32 gRaySceneClouds_Gfx[]          = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds.4bpp.lz");
const u32 gRaySceneClouds_Pal[]          = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds.gbapal.lz"); // pal 1 clouds, pal 2 rain
const u32 gRaySceneClouds1_Tilemap[]     = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds1.bin.lz");
const u32 gRaySceneClouds2_Tilemap[]     = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds2.bin.lz");
const u32 gRaySceneClouds3_Tilemap[]     = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds3.bin.lz");

// Scene 2 (RAY_ANIM_TAKES_FLIGHT)
const u32 gRaySceneSmoke_Gfx[]        = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.4bpp.lz");
const u32 gRaySceneSmoke_Pal[]        = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.gbapal.lz");
const u32 gRaySceneRayquaza_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.8bpp.lz");
const u32 gRaySceneRayquaza_Pal[]     = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.gbapal.lz");
const u32 gRaySceneRayquaza_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.bin.lz");
const u32 gRaySceneOvercast_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_2/bg.4bpp.lz"); // uses pal 2 of gRaySceneRayquaza_Pal
const u32 gRaySceneOvercast_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/bg.bin.lz");

// Scene 3 (RAY_ANIM_DESCENDS)
const u32 gRaySceneRayquazaFly1_Gfx[]      = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza.4bpp.lz");
// for some reason there are an extra 0xC bytes at the end of the original 4bpp, so in order to produce the correct lz, 
// we have to cat the bytes at the end with a make rule. not sure why those bytes are there, it may have been a bug in Game Freak's software.
const u32 gRaySceneRayquazaTail_Gfx[]      = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza_tail_fix.4bpp.lz");
const u32 gRaySceneOvercast2_Gfx[]         = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.4bpp.lz");
const u32 gRaySceneRayquazaLight_Gfx[]     = INCBIN_U32("graphics/rayquaza_scene/scene_3/light.4bpp.lz"); // uses pal 2 of gRaySceneOvercast2_Pal
const u32 gRaySceneOvercast2_Pal[]         = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.gbapal.lz");
const u32 gRaySceneOvercast2_Tilemap[]     = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.bin.lz");
const u32 gRaySceneRayquazaLight_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/light.bin.lz");

// Scene 4 (RAY_ANIM_CHARGES)
const u32 gRaySceneChaseBg_Gfx[]            = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.4bpp.lz");
const u32 gRaySceneChaseBg_Tilemap[]        = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.bin.lz");
const u32 gRaySceneChaseStreaks_Gfx[]       = INCBIN_U32("graphics/rayquaza_scene/scene_4/streaks.4bpp.lz");
const u32 gRaySceneChaseStreaks_Tilemap[]   = INCBIN_U32("graphics/rayquaza_scene/scene_4/streaks.bin.lz");
const u32 gRaySceneRayquazaChase_Gfx[]      = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza.4bpp.lz");
const u32 gRayChaseRayquazaChase_Tilemap[]  = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza.bin.lz");
const u32 gRayChaseRayquazaChase2_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza2.bin.lz");
const u32 gRaySceneChase_Pal[]              = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.gbapal.lz");

// Scene 5 (RAY_ANIM_CHASES_AWAY)
const u32 gRaySceneGroudonLeft_Gfx[]   = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon.4bpp.lz");
const u32 gRaySceneGroudonTail_Gfx[]   = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon_tail.4bpp.lz");
const u32 gRaySceneKyogreRight_Gfx[]   = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre.4bpp.lz");
const u32 gRaySceneRayquazaHover_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza.4bpp.lz");
const u32 gRaySceneRayquazaFlyIn_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza_tail.4bpp.lz");
const u32 gRaySceneSplash_Gfx[]        = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.4bpp.lz");
const u32 gRaySceneGroudonLeft_Pal[]   = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon.gbapal.lz");
const u32 gRaySceneKyogreRight_Pal[]   = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre.gbapal.lz");
const u32 gRaySceneRayquazaHover_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza.gbapal.lz");
const u32 gRaySceneSplash_Pal[]        = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.gbapal.lz");
const u32 gRaySceneHushBg_Gfx[]        = INCBIN_U32("graphics/rayquaza_scene/scene_5/bg.4bpp.lz");
const u32 gRaySceneHushRing_Gfx[]      = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring.8bpp.lz");
const u32 gRaySceneHushBg_Tilemap[]    = INCBIN_U32("graphics/rayquaza_scene/scene_5/bg.bin.lz");
const u32 gRaySceneHushRing_Tilemap[]  = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring.bin.lz");
const u32 gRaySceneHushRing_Map[]      = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring_map.bin.lz");
const u32 gRaySceneHushBg_Pal[]        = INCBIN_U32("graphics/rayquaza_scene/scene_5/bg.gbapal.lz");
