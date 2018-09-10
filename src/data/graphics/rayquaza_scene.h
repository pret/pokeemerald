const u8 gRaySceneGroudon_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/groudon.4bpp.lz");
const u8 gRaySceneGroudon2_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/groudon_shoulder.4bpp.lz");
const u8 gRaySceneGroudon3_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/groudon_claw.4bpp.lz");

const u8 gRaySceneKyogre_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/kyogre.4bpp.lz");
const u8 gRaySceneKyogre2_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/kyogre_shoulder.4bpp.lz");
const u8 gRaySceneKyogre3_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/kyogre_fin.4bpp.lz");

const u8 gRaySceneGroudon_Pal[] = INCBIN_U8("graphics/rayquaza_scene/groudon.gbapal.lz");
const u8 gRaySceneKyogre_Pal[] = INCBIN_U8("graphics/rayquaza_scene/kyogre.gbapal.lz");

const u8 gRaySceneClouds_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/clouds.4bpp.lz");
const u8 gRaySceneClouds_Pal[] = INCBIN_U8("graphics/rayquaza_scene/clouds.gbapal.lz"); // pal 1 clouds, pal 2 rain
const u16 gRaySceneClouds1_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/clouds1.bin.lz");
const u16 gRaySceneClouds2_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/clouds2.bin.lz");
const u16 gRaySceneClouds3_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/clouds3.bin.lz");

const u8 gRaySceneSmoke_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/smoke.4bpp.lz");
const u8 gRaySceneSmoke_Pal[] = INCBIN_U8("graphics/rayquaza_scene/smoke.gbapal.lz");

const u16 gRaySceneRayquaza_Gfx[] = INCBIN_U16("graphics/rayquaza_scene/rayquaza.8bpp.lz");
const u8 gRaySceneRayquaza_Pal[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza.gbapal.lz");
const u16 gRaySceneRayquaza_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/rayquaza.bin.lz");

const u8 gRaySceneOvercast_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/overcast.4bpp.lz"); // uses pal 2 of gRaySceneRayquaza_Pal
const u16 gRaySceneOvercast_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/overcast.bin.lz");

const u8 gRaySceneRayquazaFly1_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_fly1.4bpp.lz");
const u8 gRaySceneRayquazaTail_Gfx[] = INCBIN_U8( "graphics/rayquaza_scene/rayquaza_tail_fix.4bpp.lz"); // for some reason there are an extra 0xC bytes at the end of the original 4bpp, so in order to produce the correct lz, we have to cat the bytes at the end with a make rule. not sure why those bytes are there, it may have been a bug in Game Freak's software.

const u8 gRaySceneOvercast2_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/overcast2.4bpp.lz");

const u8 gRaySceneRayquazaLight_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_light.4bpp.lz"); // uses pal 2 of gRaySceneOvercast2_Pal

const u8 gRaySceneOvercast2_Pal[] = INCBIN_U8("graphics/rayquaza_scene/overcast2.gbapal.lz");
const u16 gRaySceneOvercast2_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/overcast2.bin.lz");

const u8 gRaySceneRayquazaLight_Tilemap[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_light.bin.lz");

const u8 gRaySceneChaseBg_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/chase_bg.4bpp.lz");
const u16 gRaySceneChaseBg_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/chase_bg.bin.lz");

const u8 gRaySceneChaseStreaks_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/chase_streaks.4bpp.lz");
const u16 gRaySceneChaseStreaks_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/chase_streaks.bin.lz");

const u8 gRaySceneRayquazaChase_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_chase.4bpp.lz");
const u16 gRayChaseRayquazaChase_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/rayquaza_chase.bin.lz");
const u16 gRayChaseRayquazaChase2_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/rayquaza_chase2.bin.lz");

const u8 gRaySceneChase_Pal[] = INCBIN_U8("graphics/rayquaza_scene/chase.gbapal.lz");

const u8 gRaySceneGroudonLeft_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/groudon_left.4bpp.lz");
const u8 gRaySceneGroudonTail_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/groudon_tail.4bpp.lz");

const u8 gRaySceneKyogreRight_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/kyogre_right.4bpp.lz");

const u8 gRaySceneRayquazaHover_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_hover.4bpp.lz");
const u8 gRaySceneRayquazaFlyIn_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_flyin.4bpp.lz");

const u8 gRaySceneSplash_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/splash.4bpp.lz");

const u8 gRaySceneGroudonLeft_Pal[] = INCBIN_U8("graphics/rayquaza_scene/groudon_left.gbapal.lz");
const u8 gRaySceneKyogreRight_Pal[] = INCBIN_U8("graphics/rayquaza_scene/kyogre_right.gbapal.lz");
const u8 gRaySceneRayquazaHover_Pal[] = INCBIN_U8("graphics/rayquaza_scene/rayquaza_hover.gbapal.lz");

const u8 gRaySceneSplash_Pal[] = INCBIN_U8("graphics/rayquaza_scene/splash.gbapal.lz");

const u8 gRaySceneHushBg_Gfx[] = INCBIN_U8("graphics/rayquaza_scene/hush_bg.4bpp.lz");
const u16 gRaySceneHushRing_Gfx[] = INCBIN_U16("graphics/rayquaza_scene/hush_ring.8bpp.lz");
const u16 gRaySceneHushBg_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/hush_bg.bin.lz");
const u16 gRaySceneHushRing_Tilemap[] = INCBIN_U16("graphics/rayquaza_scene/hush_ring.bin.lz");
const u16 gRaySceneHushRing_Map[] = INCBIN_U16("graphics/rayquaza_scene/hush_ring_map.bin.lz");
const u8 gRaySceneHushBg_Pal[] = INCBIN_U8("graphics/rayquaza_scene/hush_bg.gbapal.lz");
